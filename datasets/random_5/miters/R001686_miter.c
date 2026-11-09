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
struct DeviceConfig_R001686_8613_0
{
  int id;
  unsigned char parity;
  int port;
  int baud_rate;
  short timeout;
  unsigned char stop_bits;
  int buffer[3];
};
struct StreamBuffer_R001686_8613_1
{
  short checksum;
  unsigned char watermark;
  int head;
  int capacity;
  unsigned char state;
  int tail;
  int buffer[3];
};
struct SensorNode_R001686_8613_2
{
  short offset;
  int gain;
  short calib;
  unsigned char threshold;
  int reading;
  int buffer[3];
};
union ColorPixel_R001686_8613_0
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
void fn_R001686_8613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st_1 = {0};
  struct StreamBuffer_R001686_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_78_1 = local_arr_1[aux_1 % 3];
  int bound_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_78_2 * 2)) & 127;
  int index_reg_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_53_1) & 63;
  aux_2 = (aux_2 + index_reg_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_56_1 = 0;
  int coefficient_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_56_1 = ((coefficient_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_56_2 = ((coefficient_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_56_1) & 127;
    acc_2 = (acc_2 + coefficient_56_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_78_1 == bound_78_2);
  assert(index_reg_53_1 == index_reg_53_2);
  assert(coefficient_56_1 == coefficient_56_2);
}

int fn_R001686_8613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int bound_78 = local_arr[aux % 3];
  acc = (acc + (bound_78 * 2)) & 127;
  int index_reg_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_53) & 63;
  acc ^= aux;
  int coefficient_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_56 = ((coefficient_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_56) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001686_8613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st_1 = {0};
  struct SensorNode_R001686_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_61_1 = local_arr_1[aux_1 % 3];
  int index_reg_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_61_2 * 2)) & 127;
  int index_reg_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_27_1) & 63;
  aux_2 = (aux_2 + index_reg_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_62_1 = 0;
  int tally_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_62_1 = ((tally_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_62_2 = ((tally_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_62_1) & 127;
    acc_2 = (acc_2 + tally_62_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_61_1 == index_reg_61_2);
  assert(index_reg_27_1 == index_reg_27_2);
  assert(tally_62_1 == tally_62_2);
}

int fn_R001686_8613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int index_reg_61 = local_arr[aux % 3];
  acc = (acc + (index_reg_61 * 2)) & 127;
  int index_reg_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_27) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_62 = ((tally_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_62) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001686_8613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001686_8613_0 st_1 = {0};
  struct DeviceConfig_R001686_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int window_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_20_1 > 18)
  {
    acc_1 = ((acc_1 + (window_20_1 * 2)) + 5) & 127;
    aux_1 ^= window_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_20_2 > 18)
  {
    acc_2 = ((acc_2 + (window_20_2 * 2)) + 5) & 127;
    aux_2 ^= window_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_26_1) & 63;
  aux_2 = (aux_2 + accumulator_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_51_1 = local_arr_1[aux_1 % 3];
  int damping_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_51_2 * 2)) & 127;
  int threshold_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_45_1)
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

  switch (threshold_45_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_20_1 == window_20_2);
  assert(accumulator_26_1 == accumulator_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_51_1 == damping_51_2);
  assert(threshold_45_1 == threshold_45_2);
}

int fn_R001686_8613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001686_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int window_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_20 > 18)
  {
    acc = ((acc + (window_20 * 2)) + 5) & 127;
    aux ^= window_20 & 15;
  }
  else
  {
    acc = ((acc - window_20) + 11) & 127;
    aux += 3;
  }
  int accumulator_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_26) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_51 = local_arr[aux % 3];
  acc = (acc + (damping_51 * 2)) & 127;
  int threshold_45 = (aux + st.buffer[1]) & 3;
  switch (threshold_45)
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

void fn_R001686_8613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st_1 = {0};
  struct SensorNode_R001686_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int index_reg_92_1 = 0;
  int index_reg_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_92_1 = ((index_reg_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_92_2 = ((index_reg_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_92_1) & 127;
    acc_2 = (acc_2 + index_reg_92_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_74_1)
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

  switch (quotient_74_2)
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
  int margin_81_1 = local_arr_1[aux_1 % 3];
  int margin_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_92_1 == index_reg_92_2);
  assert(quotient_74_1 == quotient_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_81_1 == margin_81_2);
}

int fn_R001686_8613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int index_reg_92 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_92 = ((index_reg_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_92) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_74 = (aux + st.buffer[1]) & 3;
  switch (quotient_74)
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
  int margin_81 = local_arr[aux % 3];
  acc = (acc + (margin_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001686_8613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st_1 = {0};
  struct SensorNode_R001686_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int anchor_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_33_1)
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

  switch (anchor_33_2)
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
  int cursor_35_1 = local_arr_1[aux_1 % 3];
  int cursor_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_33_1 == anchor_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_35_1 == cursor_35_2);
}

int fn_R001686_8613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int anchor_33 = (aux + st.buffer[1]) & 3;
  switch (anchor_33)
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
  int cursor_35 = local_arr[aux % 3];
  acc = (acc + (cursor_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001686_8613_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st_1 = {0};
  struct SensorNode_R001686_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int margin_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_56_1 > 38)
  {
    acc_1 = ((acc_1 + (margin_56_1 * 2)) + 5) & 127;
    aux_1 ^= margin_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_56_2 > 38)
  {
    acc_2 = ((acc_2 + (margin_56_2 * 2)) + 5) & 127;
    aux_2 ^= margin_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_56_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_38_1 = local_arr_1[aux_1 % 3];
  int segment_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_38_2 * 2)) & 127;
  int offset_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_84_1) & 63;
  aux_2 = (aux_2 + offset_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_56_1 == margin_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_38_1 == segment_38_2);
  assert(offset_84_1 == offset_84_2);
}

int fn_R001686_8613_5(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int margin_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_56 > 38)
  {
    acc = ((acc + (margin_56 * 2)) + 5) & 127;
    aux ^= margin_56 & 15;
  }
  else
  {
    acc = ((acc - margin_56) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_38 = local_arr[aux % 3];
  acc = (acc + (segment_38 * 2)) & 127;
  int offset_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001686_8613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st_1 = {0};
  struct StreamBuffer_R001686_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int offset_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_71_1) & 63;
  aux_2 = (aux_2 + offset_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_43_1)
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

  switch (segment_43_2)
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

  int cursor_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_98_1 > 47)
  {
    acc_1 = ((acc_1 + (cursor_98_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_98_2 > 47)
  {
    acc_2 = ((acc_2 + (cursor_98_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_71_1 == offset_71_2);
  assert(segment_43_1 == segment_43_2);
  assert(cursor_98_1 == cursor_98_2);
}

int fn_R001686_8613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int offset_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_71) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_43 = (aux + st.buffer[1]) & 3;
  switch (segment_43)
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

  int cursor_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_98 > 47)
  {
    acc = ((acc + (cursor_98 * 2)) + 5) & 127;
    aux ^= cursor_98 & 15;
  }
  else
  {
    acc = ((acc - cursor_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001686_8613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st_1 = {0};
  struct SensorNode_R001686_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int offset_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_11_1 > 50)
  {
    acc_1 = ((acc_1 + (offset_11_1 * 2)) + 5) & 127;
    aux_1 ^= offset_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_11_2 > 50)
  {
    acc_2 = ((acc_2 + (offset_11_2 * 2)) + 5) & 127;
    aux_2 ^= offset_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_11_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_28_1 = local_arr_1[aux_1 % 3];
  int cursor_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_11_1 == offset_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_28_1 == cursor_28_2);
}

int fn_R001686_8613_7(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int offset_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_11 > 50)
  {
    acc = ((acc + (offset_11 * 2)) + 5) & 127;
    aux ^= offset_11 & 15;
  }
  else
  {
    acc = ((acc - offset_11) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_28 = local_arr[aux % 3];
  acc = (acc + (cursor_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001686_8613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001686_8613_0 st_1 = {0};
  struct DeviceConfig_R001686_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_27_1 = local_arr_1[aux_1 % 3];
  int offset_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_27_2 * 2)) & 127;
  int scale_41_1 = 0;
  int scale_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_41_1 = ((scale_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_41_2 = ((scale_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_41_1) & 127;
    acc_2 = (acc_2 + scale_41_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_27_1 == offset_27_2);
  assert(scale_41_1 == scale_41_2);
}

int fn_R001686_8613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001686_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int offset_27 = local_arr[aux % 3];
  acc = (acc + (offset_27 * 2)) & 127;
  int scale_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_41 = ((scale_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_41) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001686_8613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001686_8613_0 st_1 = {0};
  struct DeviceConfig_R001686_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_94_1 = local_arr_1[aux_1 % 3];
  int sample_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_94_2 * 2)) & 127;
  int segment_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_38_1 > 22)
  {
    acc_1 = ((acc_1 + (segment_38_1 * 2)) + 5) & 127;
    aux_1 ^= segment_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_38_2 > 22)
  {
    acc_2 = ((acc_2 + (segment_38_2 * 2)) + 5) & 127;
    aux_2 ^= segment_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_38_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_72_1 = 0;
  int scale_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_72_1 = ((scale_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_72_2 = ((scale_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_72_1) & 127;
    acc_2 = (acc_2 + scale_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_94_1 == sample_94_2);
  assert(segment_38_1 == segment_38_2);
  assert(scale_72_1 == scale_72_2);
}

int fn_R001686_8613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001686_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int sample_94 = local_arr[aux % 3];
  acc = (acc + (sample_94 * 2)) & 127;
  int segment_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_38 > 22)
  {
    acc = ((acc + (segment_38 * 2)) + 5) & 127;
    aux ^= segment_38 & 15;
  }
  else
  {
    acc = ((acc - segment_38) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_72 = ((scale_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_72) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001686_8613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st_1 = {0};
  struct StreamBuffer_R001686_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_79_1)
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

  switch (parity_79_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_79_1 == parity_79_2);
}

int fn_R001686_8613_10(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_79 = (aux + st.buffer[1]) & 3;
  switch (parity_79)
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

void fn_R001686_8613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st_1 = {0};
  struct SensorNode_R001686_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_22_1 = 0;
  int accumulator_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_22_1 = ((accumulator_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_22_2 = ((accumulator_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_22_1) & 127;
    acc_2 = (acc_2 + accumulator_22_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_69_1)
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

  switch (checksum_69_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_22_1 == accumulator_22_2);
  assert(checksum_69_1 == checksum_69_2);
}

int fn_R001686_8613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_22 = ((accumulator_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_22) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_69 = (aux + st.buffer[1]) & 3;
  switch (checksum_69)
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

void fn_R001686_8613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001686_8613_0 st_1 = {0};
  struct DeviceConfig_R001686_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_69_1)
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

  switch (sample_69_2)
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

  int margin_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_97_1) & 63;
  aux_2 = (aux_2 + margin_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_37_1 > 30)
  {
    acc_1 = ((acc_1 + (quotient_37_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_37_2 > 30)
  {
    acc_2 = ((acc_2 + (quotient_37_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_69_1 == sample_69_2);
  assert(margin_97_1 == margin_97_2);
  assert(quotient_37_1 == quotient_37_2);
}

int fn_R001686_8613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001686_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_69 = (aux + st.buffer[1]) & 3;
  switch (sample_69)
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

  int margin_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_97) & 63;
  acc ^= aux;
  int quotient_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_37 > 30)
  {
    acc = ((acc + (quotient_37 * 2)) + 5) & 127;
    aux ^= quotient_37 & 15;
  }
  else
  {
    acc = ((acc - quotient_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001686_8613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st_1 = {0};
  struct StreamBuffer_R001686_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int mask_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_42_1) & 63;
  aux_2 = (aux_2 + mask_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_36_1 = local_arr_1[aux_1 % 3];
  int damping_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_36_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_85_1 > 29)
  {
    acc_1 = ((acc_1 + (stride_85_1 * 2)) + 5) & 127;
    aux_1 ^= stride_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_85_2 > 29)
  {
    acc_2 = ((acc_2 + (stride_85_2 * 2)) + 5) & 127;
    aux_2 ^= stride_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_42_1 == mask_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_36_1 == damping_36_2);
  assert(stride_85_1 == stride_85_2);
}

int fn_R001686_8613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int mask_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_42) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_36 = local_arr[aux % 3];
  acc = (acc + (damping_36 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_85 > 29)
  {
    acc = ((acc + (stride_85 * 2)) + 5) & 127;
    aux ^= stride_85 & 15;
  }
  else
  {
    acc = ((acc - stride_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001686_8613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st_1 = {0};
  struct StreamBuffer_R001686_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_48_1 > 49)
  {
    acc_1 = ((acc_1 + (bound_48_1 * 2)) + 5) & 127;
    aux_1 ^= bound_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_48_2 > 49)
  {
    acc_2 = ((acc_2 + (bound_48_2 * 2)) + 5) & 127;
    aux_2 ^= bound_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_23_1)
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

  switch (parity_23_2)
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

  int tally_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_21_1) & 63;
  aux_2 = (aux_2 + tally_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_48_1 == bound_48_2);
  assert(parity_23_1 == parity_23_2);
  assert(tally_21_1 == tally_21_2);
}

int fn_R001686_8613_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_48 > 49)
  {
    acc = ((acc + (bound_48 * 2)) + 5) & 127;
    aux ^= bound_48 & 15;
  }
  else
  {
    acc = ((acc - bound_48) + 11) & 127;
    aux += 3;
  }
  int parity_23 = (aux + st.buffer[1]) & 3;
  switch (parity_23)
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

  int tally_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001686_8613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st_1 = {0};
  struct StreamBuffer_R001686_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_81_1 = local_arr_1[aux_1 % 3];
  int quantum_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_81_2 * 2)) & 127;
  int coefficient_57_1 = 0;
  int coefficient_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_57_1 = ((coefficient_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_57_2 = ((coefficient_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_57_1) & 127;
    acc_2 = (acc_2 + coefficient_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_81_1 == quantum_81_2);
  assert(coefficient_57_1 == coefficient_57_2);
}

int fn_R001686_8613_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int quantum_81 = local_arr[aux % 3];
  acc = (acc + (quantum_81 * 2)) & 127;
  int coefficient_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_57 = ((coefficient_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001686_8613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st_1 = {0};
  struct SensorNode_R001686_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tracker_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_86_1) & 63;
  aux_2 = (aux_2 + tracker_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_51_1)
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

  switch (quantum_51_2)
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
  int cursor_80_1 = local_arr_1[aux_1 % 3];
  int cursor_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_80_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_86_1 == tracker_86_2);
  assert(quantum_51_1 == quantum_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_80_1 == cursor_80_2);
}

int fn_R001686_8613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001686_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tracker_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_86) & 63;
  acc ^= aux;
  int quantum_51 = (aux + st.buffer[1]) & 3;
  switch (quantum_51)
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
  int cursor_80 = local_arr[aux % 3];
  acc = (acc + (cursor_80 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001686_8613_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st_1 = {0};
  struct StreamBuffer_R001686_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int weight_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_65_1) & 63;
  aux_2 = (aux_2 + weight_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_75_1)
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

  switch (tally_75_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_65_1 == weight_65_2);
  assert(tally_75_1 == tally_75_2);
  assert(threshold_48_1 == threshold_48_2);
}

int fn_R001686_8613_17(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001686_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int weight_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_65) & 63;
  acc ^= aux;
  int tally_75 = (aux + st.buffer[1]) & 3;
  switch (tally_75)
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

  int threshold_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_48 = ((threshold_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_48) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001686_0_1;
  int sec_r001686_0_2;
  int sec_r001686_1_1;
  int sec_r001686_1_2;
  int sec_r001686_2_1;
  int sec_r001686_2_2;
  int sec_r001686_3_1;
  int sec_r001686_3_2;
  int sec_r001686_4_1;
  int sec_r001686_4_2;
  int sec_r001686_5_1;
  int sec_r001686_5_2;
  int sec_r001686_6_1;
  int sec_r001686_6_2;
  int sec_r001686_7_1;
  int sec_r001686_7_2;
  int sec_r001686_8_1;
  int sec_r001686_8_2;
  int sec_r001686_9_1;
  int sec_r001686_9_2;
  int sec_r001686_10_1;
  int sec_r001686_10_2;
  int sec_r001686_11_1;
  int sec_r001686_11_2;
  int sec_r001686_12_1;
  int sec_r001686_12_2;
  int sec_r001686_13_1;
  int sec_r001686_13_2;
  int sec_r001686_14_1;
  int sec_r001686_14_2;
  int sec_r001686_15_1;
  int sec_r001686_15_2;
  int sec_r001686_16_1;
  int sec_r001686_16_2;
  int pub_r001686_0_1;
  int pub_r001686_0_2;
  int pub_r001686_1_1;
  int pub_r001686_1_2;
  int pub_r001686_2_1;
  int pub_r001686_2_2;
  int pub_r001686_3_1;
  int pub_r001686_3_2;
  int pub_r001686_4_1;
  int pub_r001686_4_2;
  int pub_r001686_5_1;
  int pub_r001686_5_2;
  int pub_r001686_6_1;
  int pub_r001686_6_2;
  int pub_r001686_7_1;
  int pub_r001686_7_2;
  int pub_r001686_8_1;
  int pub_r001686_8_2;
  int pub_r001686_9_1;
  int pub_r001686_9_2;
  int pub_r001686_10_1;
  int pub_r001686_10_2;
  int pub_r001686_11_1;
  int pub_r001686_11_2;
  int pub_r001686_12_1;
  int pub_r001686_12_2;
  int pub_r001686_13_1;
  int pub_r001686_13_2;
  int pub_r001686_14_1;
  int pub_r001686_14_2;
  int pub_r001686_15_1;
  int pub_r001686_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001686_0_1 >= (-100)) && (pub_r001686_0_1 <= 100));
  __CPROVER_assume((pub_r001686_0_2 >= (-100)) && (pub_r001686_0_2 <= 100));
  __CPROVER_assume((pub_r001686_1_1 >= (-100)) && (pub_r001686_1_1 <= 100));
  __CPROVER_assume((pub_r001686_1_2 >= (-100)) && (pub_r001686_1_2 <= 100));
  __CPROVER_assume((pub_r001686_2_1 >= (-100)) && (pub_r001686_2_1 <= 100));
  __CPROVER_assume((pub_r001686_2_2 >= (-100)) && (pub_r001686_2_2 <= 100));
  __CPROVER_assume((pub_r001686_3_1 >= (-100)) && (pub_r001686_3_1 <= 100));
  __CPROVER_assume((pub_r001686_3_2 >= (-100)) && (pub_r001686_3_2 <= 100));
  __CPROVER_assume((pub_r001686_4_1 >= (-100)) && (pub_r001686_4_1 <= 100));
  __CPROVER_assume((pub_r001686_4_2 >= (-100)) && (pub_r001686_4_2 <= 100));
  __CPROVER_assume((pub_r001686_5_1 >= (-100)) && (pub_r001686_5_1 <= 100));
  __CPROVER_assume((pub_r001686_5_2 >= (-100)) && (pub_r001686_5_2 <= 100));
  __CPROVER_assume((pub_r001686_6_1 >= (-100)) && (pub_r001686_6_1 <= 100));
  __CPROVER_assume((pub_r001686_6_2 >= (-100)) && (pub_r001686_6_2 <= 100));
  __CPROVER_assume((pub_r001686_7_1 >= (-100)) && (pub_r001686_7_1 <= 100));
  __CPROVER_assume((pub_r001686_7_2 >= (-100)) && (pub_r001686_7_2 <= 100));
  __CPROVER_assume((pub_r001686_8_1 >= (-100)) && (pub_r001686_8_1 <= 100));
  __CPROVER_assume((pub_r001686_8_2 >= (-100)) && (pub_r001686_8_2 <= 100));
  __CPROVER_assume((pub_r001686_9_1 >= (-100)) && (pub_r001686_9_1 <= 100));
  __CPROVER_assume((pub_r001686_9_2 >= (-100)) && (pub_r001686_9_2 <= 100));
  __CPROVER_assume((pub_r001686_10_1 >= (-100)) && (pub_r001686_10_1 <= 100));
  __CPROVER_assume((pub_r001686_10_2 >= (-100)) && (pub_r001686_10_2 <= 100));
  __CPROVER_assume((pub_r001686_11_1 >= (-100)) && (pub_r001686_11_1 <= 100));
  __CPROVER_assume((pub_r001686_11_2 >= (-100)) && (pub_r001686_11_2 <= 100));
  __CPROVER_assume((pub_r001686_12_1 >= (-100)) && (pub_r001686_12_1 <= 100));
  __CPROVER_assume((pub_r001686_12_2 >= (-100)) && (pub_r001686_12_2 <= 100));
  __CPROVER_assume((pub_r001686_13_1 >= (-100)) && (pub_r001686_13_1 <= 100));
  __CPROVER_assume((pub_r001686_13_2 >= (-100)) && (pub_r001686_13_2 <= 100));
  __CPROVER_assume((pub_r001686_14_1 >= (-100)) && (pub_r001686_14_1 <= 100));
  __CPROVER_assume((pub_r001686_14_2 >= (-100)) && (pub_r001686_14_2 <= 100));
  __CPROVER_assume((pub_r001686_15_1 >= (-100)) && (pub_r001686_15_1 <= 100));
  __CPROVER_assume((pub_r001686_15_2 >= (-100)) && (pub_r001686_15_2 <= 100));
  __CPROVER_assume((sec_r001686_0_1 >= 0) && (sec_r001686_0_1 <= 255));
  __CPROVER_assume((sec_r001686_0_2 >= 0) && (sec_r001686_0_2 <= 255));
  __CPROVER_assume((sec_r001686_1_1 >= 0) && (sec_r001686_1_1 <= 255));
  __CPROVER_assume((sec_r001686_1_2 >= 0) && (sec_r001686_1_2 <= 255));
  __CPROVER_assume((sec_r001686_2_1 >= 0) && (sec_r001686_2_1 <= 255));
  __CPROVER_assume((sec_r001686_2_2 >= 0) && (sec_r001686_2_2 <= 255));
  __CPROVER_assume((sec_r001686_3_1 >= 0) && (sec_r001686_3_1 <= 255));
  __CPROVER_assume((sec_r001686_3_2 >= 0) && (sec_r001686_3_2 <= 255));
  __CPROVER_assume((sec_r001686_4_1 >= 0) && (sec_r001686_4_1 <= 255));
  __CPROVER_assume((sec_r001686_4_2 >= 0) && (sec_r001686_4_2 <= 255));
  __CPROVER_assume((sec_r001686_5_1 >= 0) && (sec_r001686_5_1 <= 255));
  __CPROVER_assume((sec_r001686_5_2 >= 0) && (sec_r001686_5_2 <= 255));
  __CPROVER_assume((sec_r001686_6_1 >= 0) && (sec_r001686_6_1 <= 255));
  __CPROVER_assume((sec_r001686_6_2 >= 0) && (sec_r001686_6_2 <= 255));
  __CPROVER_assume((sec_r001686_7_1 >= 0) && (sec_r001686_7_1 <= 255));
  __CPROVER_assume((sec_r001686_7_2 >= 0) && (sec_r001686_7_2 <= 255));
  __CPROVER_assume((sec_r001686_8_1 >= 0) && (sec_r001686_8_1 <= 255));
  __CPROVER_assume((sec_r001686_8_2 >= 0) && (sec_r001686_8_2 <= 255));
  __CPROVER_assume((sec_r001686_9_1 >= 0) && (sec_r001686_9_1 <= 255));
  __CPROVER_assume((sec_r001686_9_2 >= 0) && (sec_r001686_9_2 <= 255));
  __CPROVER_assume((sec_r001686_10_1 >= 0) && (sec_r001686_10_1 <= 255));
  __CPROVER_assume((sec_r001686_10_2 >= 0) && (sec_r001686_10_2 <= 255));
  __CPROVER_assume((sec_r001686_11_1 >= 0) && (sec_r001686_11_1 <= 255));
  __CPROVER_assume((sec_r001686_11_2 >= 0) && (sec_r001686_11_2 <= 255));
  __CPROVER_assume((sec_r001686_12_1 >= 0) && (sec_r001686_12_1 <= 255));
  __CPROVER_assume((sec_r001686_12_2 >= 0) && (sec_r001686_12_2 <= 255));
  __CPROVER_assume((sec_r001686_13_1 >= 0) && (sec_r001686_13_1 <= 255));
  __CPROVER_assume((sec_r001686_13_2 >= 0) && (sec_r001686_13_2 <= 255));
  __CPROVER_assume((sec_r001686_14_1 >= 0) && (sec_r001686_14_1 <= 255));
  __CPROVER_assume((sec_r001686_14_2 >= 0) && (sec_r001686_14_2 <= 255));
  __CPROVER_assume((sec_r001686_15_1 >= 0) && (sec_r001686_15_1 <= 255));
  __CPROVER_assume((sec_r001686_15_2 >= 0) && (sec_r001686_15_2 <= 255));
  __CPROVER_assume((sec_r001686_16_1 >= 0) && (sec_r001686_16_1 <= 255));
  __CPROVER_assume((sec_r001686_16_2 >= 0) && (sec_r001686_16_2 <= 255));
  struct DeviceConfig_R001686_8613_0 st_var_0_1 = {0};
  struct DeviceConfig_R001686_8613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001686_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001686_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001686_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001686_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001686_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001686_0_2 + 7) & 15;
  struct StreamBuffer_R001686_8613_1 st_var_1_1 = {0};
  struct StreamBuffer_R001686_8613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001686_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001686_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001686_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001686_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001686_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001686_0_2 + 9) & 15;
  struct SensorNode_R001686_8613_2 st_var_2_1 = {0};
  struct SensorNode_R001686_8613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001686_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001686_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001686_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001686_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001686_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001686_0_2 + 11) & 15;
  union ColorPixel_R001686_8613_0 u_var_1;
  union ColorPixel_R001686_8613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001686_8613_0(sec_r001686_0_1, sec_r001686_1_1, pub_r001686_2_1, pub_r001686_3_1, pub_r001686_4_1);
  int helper_flow_0_2 = fn_R001686_8613_0(sec_r001686_0_2, sec_r001686_1_2, pub_r001686_2_2, pub_r001686_3_2, pub_r001686_4_2);
  fn_R001686_8613_0_2(sec_r001686_0_1, sec_r001686_1_1, pub_r001686_2_1, pub_r001686_3_1, pub_r001686_4_1, sec_r001686_0_2, sec_r001686_1_2, pub_r001686_2_2, pub_r001686_3_2, pub_r001686_4_2);
  int helper_flow_1_1 = fn_R001686_8613_1(sec_r001686_1_1, pub_r001686_2_1, pub_r001686_3_1, pub_r001686_4_1);
  int helper_flow_1_2 = fn_R001686_8613_1(sec_r001686_1_2, pub_r001686_2_2, pub_r001686_3_2, pub_r001686_4_2);
  fn_R001686_8613_1_2(sec_r001686_1_1, pub_r001686_2_1, pub_r001686_3_1, pub_r001686_4_1, sec_r001686_1_2, pub_r001686_2_2, pub_r001686_3_2, pub_r001686_4_2);
  int helper_flow_2_1 = fn_R001686_8613_2(sec_r001686_2_1, pub_r001686_3_1, pub_r001686_4_1, pub_r001686_5_1);
  int helper_flow_2_2 = fn_R001686_8613_2(sec_r001686_2_2, pub_r001686_3_2, pub_r001686_4_2, pub_r001686_5_2);
  fn_R001686_8613_2_2(sec_r001686_2_1, pub_r001686_3_1, pub_r001686_4_1, pub_r001686_5_1, sec_r001686_2_2, pub_r001686_3_2, pub_r001686_4_2, pub_r001686_5_2);
  int helper_flow_3_1 = fn_R001686_8613_3(sec_r001686_3_1, pub_r001686_4_1, pub_r001686_5_1, pub_r001686_6_1, pub_r001686_7_1);
  int helper_flow_3_2 = fn_R001686_8613_3(sec_r001686_3_2, pub_r001686_4_2, pub_r001686_5_2, pub_r001686_6_2, pub_r001686_7_2);
  fn_R001686_8613_3_2(sec_r001686_3_1, pub_r001686_4_1, pub_r001686_5_1, pub_r001686_6_1, pub_r001686_7_1, sec_r001686_3_2, pub_r001686_4_2, pub_r001686_5_2, pub_r001686_6_2, pub_r001686_7_2);
  int helper_flow_4_1 = fn_R001686_8613_4(sec_r001686_4_1, pub_r001686_5_1, pub_r001686_6_1, pub_r001686_7_1, pub_r001686_8_1);
  int helper_flow_4_2 = fn_R001686_8613_4(sec_r001686_4_2, pub_r001686_5_2, pub_r001686_6_2, pub_r001686_7_2, pub_r001686_8_2);
  fn_R001686_8613_4_2(sec_r001686_4_1, pub_r001686_5_1, pub_r001686_6_1, pub_r001686_7_1, pub_r001686_8_1, sec_r001686_4_2, pub_r001686_5_2, pub_r001686_6_2, pub_r001686_7_2, pub_r001686_8_2);
  int helper_flow_5_1 = fn_R001686_8613_5(sec_r001686_5_1, sec_r001686_6_1, pub_r001686_7_1);
  int helper_flow_5_2 = fn_R001686_8613_5(sec_r001686_5_2, sec_r001686_6_2, pub_r001686_7_2);
  fn_R001686_8613_5_2(sec_r001686_5_1, sec_r001686_6_1, pub_r001686_7_1, sec_r001686_5_2, sec_r001686_6_2, pub_r001686_7_2);
  int helper_flow_6_1 = fn_R001686_8613_6(sec_r001686_6_1, pub_r001686_7_1, pub_r001686_8_1);
  int helper_flow_6_2 = fn_R001686_8613_6(sec_r001686_6_2, pub_r001686_7_2, pub_r001686_8_2);
  fn_R001686_8613_6_2(sec_r001686_6_1, pub_r001686_7_1, pub_r001686_8_1, sec_r001686_6_2, pub_r001686_7_2, pub_r001686_8_2);
  int helper_flow_7_1 = fn_R001686_8613_7(sec_r001686_7_1, pub_r001686_8_1);
  int helper_flow_7_2 = fn_R001686_8613_7(sec_r001686_7_2, pub_r001686_8_2);
  fn_R001686_8613_7_2(sec_r001686_7_1, pub_r001686_8_1, sec_r001686_7_2, pub_r001686_8_2);
  int stage_v_0_1 = ((helper_flow_3_1 + (pub_r001686_2_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_3_2 + (pub_r001686_2_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001686_12_1 + (pub_r001686_10_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001686_12_2 + (pub_r001686_10_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001686_6_1 * 2) + 43) & 63;
  int stage_v_2_2 = ((pub_r001686_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((helper_flow_1_1 + (pub_r001686_5_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((helper_flow_1_2 + (pub_r001686_5_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((stage_v_3_1 + (pub_r001686_0_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((stage_v_3_2 + (pub_r001686_0_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((stage_v_4_1 + (pub_r001686_8_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((stage_v_4_2 + (pub_r001686_8_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001686_3_1 * 2) + 47) & 63;
  int stage_v_6_2 = ((pub_r001686_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((sec_r001686_16_1 + (pub_r001686_3_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001686_16_2 + (pub_r001686_3_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((helper_flow_7_1 + (pub_r001686_6_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((helper_flow_7_2 + (pub_r001686_6_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((sec_r001686_15_1 + (pub_r001686_6_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001686_15_2 + (pub_r001686_6_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((pub_r001686_7_1 * 2) + 27) & 63;
  int stage_v_10_2 = ((pub_r001686_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001686_0_1 * 2) + 16) & 63;
  int stage_v_11_2 = ((pub_r001686_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001686_10_1 + (pub_r001686_0_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001686_10_2 + (pub_r001686_0_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((helper_flow_6_1 + (pub_r001686_3_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((helper_flow_6_2 + (pub_r001686_3_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((helper_flow_3_1 + (pub_r001686_6_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((helper_flow_3_2 + (pub_r001686_6_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((pub_r001686_11_1 * 2) + 38) & 63;
  int stage_v_15_2 = ((pub_r001686_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((stage_v_12_1 + (pub_r001686_14_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((stage_v_12_2 + (pub_r001686_14_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((stage_v_12_1 + (pub_r001686_11_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((stage_v_12_2 + (pub_r001686_11_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((helper_flow_6_1 + (pub_r001686_2_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((helper_flow_6_2 + (pub_r001686_2_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((sec_r001686_11_1 + (pub_r001686_10_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001686_11_2 + (pub_r001686_10_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((pub_r001686_15_1 * 2) + 12) & 63;
  int stage_v_20_2 = ((pub_r001686_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((stage_v_0_1 + (pub_r001686_9_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_0_2 + (pub_r001686_9_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001686_4_1 * 2) + 29) & 63;
  int stage_v_22_2 = ((pub_r001686_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((stage_v_21_1 + (pub_r001686_9_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((stage_v_21_2 + (pub_r001686_9_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((pub_r001686_7_1 * 2) + 29) & 63;
  int stage_v_24_2 = ((pub_r001686_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001686_13_1 * 2) + 25) & 63;
  int stage_v_25_2 = ((pub_r001686_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001686_0_1 * 2) + 18) & 63;
  int stage_v_26_2 = ((pub_r001686_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001686_1_1 * 2) + 15) & 63;
  int stage_v_27_2 = ((pub_r001686_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((sec_r001686_6_1 + (pub_r001686_15_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((sec_r001686_6_2 + (pub_r001686_15_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((stage_v_9_1 + (pub_r001686_5_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_9_2 + (pub_r001686_5_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((sec_r001686_8_1 + (pub_r001686_9_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((sec_r001686_8_2 + (pub_r001686_9_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001686_12_1 * 2) + 23) & 63;
  int stage_v_31_2 = ((pub_r001686_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((stage_v_0_1 + (pub_r001686_14_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_0_2 + (pub_r001686_14_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((helper_flow_4_1 + (pub_r001686_14_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((helper_flow_4_2 + (pub_r001686_14_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((stage_v_13_1 + (pub_r001686_7_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_13_2 + (pub_r001686_7_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001686_6_1 + (pub_r001686_14_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001686_6_2 + (pub_r001686_14_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((stage_v_18_1 + (pub_r001686_14_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_18_2 + (pub_r001686_14_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((stage_v_30_1 + (pub_r001686_7_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_30_2 + (pub_r001686_7_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001686_5_1 * 2) + 14) & 63;
  int stage_v_38_2 = ((pub_r001686_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((helper_flow_3_1 + (pub_r001686_12_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((helper_flow_3_2 + (pub_r001686_12_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((sec_r001686_11_1 + (pub_r001686_14_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((sec_r001686_11_2 + (pub_r001686_14_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001686_6_1 * 2) + 36) & 63;
  int stage_v_41_2 = ((pub_r001686_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((stage_v_9_1 + (pub_r001686_10_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_9_2 + (pub_r001686_10_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((stage_v_29_1 + (pub_r001686_4_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_29_2 + (pub_r001686_4_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((stage_v_21_1 + (pub_r001686_7_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_21_2 + (pub_r001686_7_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((stage_v_39_1 + (pub_r001686_11_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_39_2 + (pub_r001686_11_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_18_1 + (pub_r001686_3_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_18_2 + (pub_r001686_3_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((sec_r001686_3_1 + (pub_r001686_0_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001686_3_2 + (pub_r001686_0_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((stage_v_18_1 + (pub_r001686_15_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_18_2 + (pub_r001686_15_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_0_1 + (pub_r001686_4_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_0_2 + (pub_r001686_4_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001686_10_1 * 2) + 50) & 63;
  int stage_v_50_2 = ((pub_r001686_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((helper_flow_4_1 + (pub_r001686_15_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((helper_flow_4_2 + (pub_r001686_15_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((stage_v_42_1 + (pub_r001686_7_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_42_2 + (pub_r001686_7_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001686_13_1 * 2) + 47) & 63;
  int stage_v_53_2 = ((pub_r001686_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((stage_v_14_1 + (pub_r001686_6_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_14_2 + (pub_r001686_6_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((sec_r001686_15_1 + (pub_r001686_1_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((sec_r001686_15_2 + (pub_r001686_1_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001686_10_1 * 2) + 17) & 63;
  int stage_v_56_2 = ((pub_r001686_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_0_1 + (pub_r001686_7_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_0_2 + (pub_r001686_7_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001686_12_1 * 2) + 40) & 63;
  int stage_v_58_2 = ((pub_r001686_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((stage_v_45_1 + (pub_r001686_4_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_45_2 + (pub_r001686_4_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_5_1 + (pub_r001686_12_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_5_2 + (pub_r001686_12_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_35_1 + (pub_r001686_4_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_35_2 + (pub_r001686_4_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((pub_r001686_13_1 * 2) + 40) & 63;
  int stage_v_62_2 = ((pub_r001686_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001686_1_1 * 2) + 15) & 63;
  int stage_v_63_2 = ((pub_r001686_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((stage_v_39_1 + (pub_r001686_4_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_39_2 + (pub_r001686_4_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((sec_r001686_9_1 + (pub_r001686_5_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((sec_r001686_9_2 + (pub_r001686_5_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((stage_v_3_1 + (pub_r001686_13_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_3_2 + (pub_r001686_13_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_14_1 + (pub_r001686_11_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_14_2 + (pub_r001686_11_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_0_1 + (pub_r001686_7_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_0_2 + (pub_r001686_7_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((pub_r001686_3_1 * 2) + 20) & 63;
  int stage_v_69_2 = ((pub_r001686_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_47_1 + (pub_r001686_9_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_47_2 + (pub_r001686_9_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_66_1 + (pub_r001686_1_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_66_2 + (pub_r001686_1_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_21_1 + (pub_r001686_9_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_21_2 + (pub_r001686_9_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001686_0_1 * 2) + 10) & 63;
  int stage_v_73_2 = ((pub_r001686_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001686_10_1 * 2) + 18) & 63;
  int stage_v_74_2 = ((pub_r001686_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001686_3_1 * 2) + 28) & 63;
  int stage_v_75_2 = ((pub_r001686_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001686_11_1 * 2) + 24) & 63;
  int stage_v_76_2 = ((pub_r001686_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((stage_v_0_1 + (pub_r001686_12_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_0_2 + (pub_r001686_12_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((pub_r001686_0_1 * 2) + 15) & 63;
  int stage_v_78_2 = ((pub_r001686_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((stage_v_65_1 + (pub_r001686_5_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_65_2 + (pub_r001686_5_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((pub_r001686_9_1 * 2) + 37) & 63;
  int stage_v_80_2 = ((pub_r001686_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((stage_v_59_1 + (pub_r001686_15_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_59_2 + (pub_r001686_15_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001686_15_1 * 2) + 38) & 63;
  int stage_v_82_2 = ((pub_r001686_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((stage_v_3_1 + (pub_r001686_1_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_3_2 + (pub_r001686_1_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((helper_flow_5_1 + (pub_r001686_11_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((helper_flow_5_2 + (pub_r001686_11_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_83_1 + (pub_r001686_6_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_83_2 + (pub_r001686_6_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_66_1 + (pub_r001686_7_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_66_2 + (pub_r001686_7_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_29_1 + (pub_r001686_9_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_29_2 + (pub_r001686_9_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_72_1 + (pub_r001686_7_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_72_2 + (pub_r001686_7_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_57_1 + (pub_r001686_10_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_57_2 + (pub_r001686_10_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_72_1 + (pub_r001686_6_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_72_2 + (pub_r001686_6_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((pub_r001686_3_1 * 2) + 35) & 63;
  int stage_v_91_2 = ((pub_r001686_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((sec_r001686_11_1 + (pub_r001686_6_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((sec_r001686_11_2 + (pub_r001686_6_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_9_1 + (pub_r001686_15_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_9_2 + (pub_r001686_15_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_55_1 + (pub_r001686_0_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_55_2 + (pub_r001686_0_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_46_1 + (pub_r001686_3_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_46_2 + (pub_r001686_3_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001686_3_1 * 2) + 12) & 63;
  int stage_v_96_2 = ((pub_r001686_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_8_1 + (pub_r001686_4_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_8_2 + (pub_r001686_4_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_95_1 + (pub_r001686_12_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_95_2 + (pub_r001686_12_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001686_5_1 * 2) + 11) & 63;
  int stage_v_99_2 = ((pub_r001686_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001686_8_1 * 2) + 30) & 63;
  int stage_v_100_2 = ((pub_r001686_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_0_1 + (pub_r001686_8_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_0_2 + (pub_r001686_8_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_8_1 + (pub_r001686_4_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_8_2 + (pub_r001686_4_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_84_1 + (pub_r001686_3_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_84_2 + (pub_r001686_3_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_77_1 + (pub_r001686_10_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_77_2 + (pub_r001686_10_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_83_1 + (pub_r001686_0_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_83_2 + (pub_r001686_0_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((pub_r001686_8_1 * 2) + 39) & 63;
  int stage_v_106_2 = ((pub_r001686_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001686_0_1 * 2) + 10) & 63;
  int stage_v_107_2 = ((pub_r001686_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001686_0_1 * 2) + 33) & 63;
  int stage_v_108_2 = ((pub_r001686_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_89_1 + (pub_r001686_0_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_89_2 + (pub_r001686_0_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001686_14_1 * 2) + 10) & 63;
  int stage_v_110_2 = ((pub_r001686_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_94_1 + (pub_r001686_5_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_94_2 + (pub_r001686_5_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((sec_r001686_2_1 + (pub_r001686_3_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((sec_r001686_2_2 + (pub_r001686_3_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((sec_r001686_6_1 + (pub_r001686_9_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((sec_r001686_6_2 + (pub_r001686_9_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((pub_r001686_4_1 * 2) + 11) & 63;
  int stage_v_114_2 = ((pub_r001686_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_36_1 + (pub_r001686_3_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_36_2 + (pub_r001686_3_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_113_1 + (pub_r001686_6_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_113_2 + (pub_r001686_6_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((sec_r001686_5_1 + (pub_r001686_0_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((sec_r001686_5_2 + (pub_r001686_0_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_8_1 + (pub_r001686_9_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_8_2 + (pub_r001686_9_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_77_1 + (pub_r001686_8_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_77_2 + (pub_r001686_8_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_71_1 + (pub_r001686_5_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_71_2 + (pub_r001686_5_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001686_1_1 * 2) + 27) & 63;
  int stage_v_121_2 = ((pub_r001686_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001686_12_1 * 2) + 39) & 63;
  int stage_v_122_2 = ((pub_r001686_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001686_1_1 * 2) + 10) & 63;
  int stage_v_123_2 = ((pub_r001686_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((stage_v_9_1 + (pub_r001686_15_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_9_2 + (pub_r001686_15_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((stage_v_113_1 + (pub_r001686_10_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_113_2 + (pub_r001686_10_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_9_1 + (pub_r001686_6_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_9_2 + (pub_r001686_6_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((pub_r001686_2_1 * 2) + 27) & 63;
  int stage_v_127_2 = ((pub_r001686_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_85_1 + (pub_r001686_13_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_85_2 + (pub_r001686_13_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((pub_r001686_9_1 * 2) + 37) & 63;
  int stage_v_129_2 = ((pub_r001686_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_71_1 + (pub_r001686_6_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_71_2 + (pub_r001686_6_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_44_1 + (pub_r001686_11_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_44_2 + (pub_r001686_11_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((sec_r001686_7_1 + (pub_r001686_13_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((sec_r001686_7_2 + (pub_r001686_13_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001686_5_1 * 2) + 41) & 63;
  int stage_v_133_2 = ((pub_r001686_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_52_1 + (pub_r001686_5_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_52_2 + (pub_r001686_5_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((pub_r001686_10_1 * 2) + 12) & 63;
  int stage_v_135_2 = ((pub_r001686_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_23_1 + (pub_r001686_10_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_23_2 + (pub_r001686_10_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_98_1 + (pub_r001686_9_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_98_2 + (pub_r001686_9_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((pub_r001686_15_1 * 2) + 41) & 63;
  int stage_v_138_2 = ((pub_r001686_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_77_1 + (pub_r001686_7_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_77_2 + (pub_r001686_7_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((helper_flow_3_1 + (pub_r001686_15_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((helper_flow_3_2 + (pub_r001686_15_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_132_1 + (pub_r001686_7_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_132_2 + (pub_r001686_7_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((sec_r001686_6_1 + (pub_r001686_3_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((sec_r001686_6_2 + (pub_r001686_3_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((pub_r001686_15_1 * 2) + 10) & 63;
  int stage_v_143_2 = ((pub_r001686_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_14_1 + (pub_r001686_12_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_14_2 + (pub_r001686_12_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((pub_r001686_14_1 * 2) + 42) & 63;
  int stage_v_145_2 = ((pub_r001686_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((stage_v_97_1 + (pub_r001686_2_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_97_2 + (pub_r001686_2_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((sec_r001686_9_1 + (pub_r001686_15_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((sec_r001686_9_2 + (pub_r001686_15_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_44_1 + (pub_r001686_0_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_44_2 + (pub_r001686_0_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_124_1 + (pub_r001686_10_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_124_2 + (pub_r001686_10_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((pub_r001686_13_1 * 2) + 18) & 63;
  int stage_v_150_2 = ((pub_r001686_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_84_1 + (pub_r001686_7_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_84_2 + (pub_r001686_7_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((helper_flow_4_1 + (pub_r001686_4_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((helper_flow_4_2 + (pub_r001686_4_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((helper_flow_2_1 + (pub_r001686_6_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((helper_flow_2_2 + (pub_r001686_6_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001686_14_1 * 2) + 15) & 63;
  int stage_v_154_2 = ((pub_r001686_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_144_1 + (pub_r001686_14_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_144_2 + (pub_r001686_14_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_92_1 + (pub_r001686_7_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_92_2 + (pub_r001686_7_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_103_1 + (pub_r001686_4_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_103_2 + (pub_r001686_4_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_124_1 + (pub_r001686_1_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_124_2 + (pub_r001686_1_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_137_1 + (pub_r001686_4_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_137_2 + (pub_r001686_4_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_7_1 + (pub_r001686_9_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_7_2 + (pub_r001686_9_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_16_1 + (pub_r001686_4_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_16_2 + (pub_r001686_4_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((sec_r001686_11_1 + (pub_r001686_4_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((sec_r001686_11_2 + (pub_r001686_4_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((helper_flow_4_1 + (pub_r001686_10_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((helper_flow_4_2 + (pub_r001686_10_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001686_11_1 * 2) + 7) & 63;
  int stage_v_164_2 = ((pub_r001686_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001686_14_1 * 2) + 28) & 63;
  int stage_v_165_2 = ((pub_r001686_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001686_10_1 * 2) + 43) & 63;
  int stage_v_166_2 = ((pub_r001686_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((helper_flow_3_1 + (pub_r001686_0_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((helper_flow_3_2 + (pub_r001686_0_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_92_1 + (pub_r001686_15_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_92_2 + (pub_r001686_15_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((pub_r001686_6_1 * 2) + 24) & 63;
  int stage_v_169_2 = ((pub_r001686_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_17_1 + (pub_r001686_0_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_17_2 + (pub_r001686_0_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((pub_r001686_4_1 * 2) + 28) & 63;
  int stage_v_171_2 = ((pub_r001686_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_36_1 + (pub_r001686_3_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_36_2 + (pub_r001686_3_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((helper_flow_4_1 + (pub_r001686_13_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((helper_flow_4_2 + (pub_r001686_13_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_159_1 + (pub_r001686_6_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_159_2 + (pub_r001686_6_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_137_1 + (pub_r001686_7_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_137_2 + (pub_r001686_7_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001686_8_1 * 2) + 45) & 63;
  int stage_v_176_2 = ((pub_r001686_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001686_3_1 * 2) + 21) & 63;
  int stage_v_177_2 = ((pub_r001686_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001686_10_1 * 2) + 30) & 63;
  int stage_v_178_2 = ((pub_r001686_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001686_4_1 * 2) + 26) & 63;
  int stage_v_179_2 = ((pub_r001686_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_97_1 + (pub_r001686_2_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_97_2 + (pub_r001686_2_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001686_10_1 * 2) + 38) & 63;
  int stage_v_181_2 = ((pub_r001686_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_136_1 + (pub_r001686_7_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_136_2 + (pub_r001686_7_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_153_1 + (pub_r001686_3_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_153_2 + (pub_r001686_3_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((pub_r001686_0_1 * 2) + 32) & 63;
  int stage_v_184_2 = ((pub_r001686_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((helper_flow_7_1 + (pub_r001686_6_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((helper_flow_7_2 + (pub_r001686_6_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001686_8_1 * 2) + 21) & 63;
  int stage_v_186_2 = ((pub_r001686_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001686_15_1 * 2) + 22) & 63;
  int stage_v_187_2 = ((pub_r001686_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((stage_v_67_1 + (pub_r001686_0_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_67_2 + (pub_r001686_0_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((stage_v_32_1 + (pub_r001686_8_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_32_2 + (pub_r001686_8_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_92_1 + (pub_r001686_3_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_92_2 + (pub_r001686_3_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((pub_r001686_10_1 * 2) + 12) & 63;
  int stage_v_191_2 = ((pub_r001686_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_55_1 + (pub_r001686_2_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_55_2 + (pub_r001686_2_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001686_10_1 * 2) + 37) & 63;
  int stage_v_193_2 = ((pub_r001686_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_161_1 + (pub_r001686_1_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_161_2 + (pub_r001686_1_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_170_1 + (pub_r001686_5_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_170_2 + (pub_r001686_5_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_3_1 + (pub_r001686_3_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_3_2 + (pub_r001686_3_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_102_1 + (pub_r001686_3_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_102_2 + (pub_r001686_3_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_103_1 + (pub_r001686_2_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_103_2 + (pub_r001686_2_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_72_1 + (pub_r001686_9_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_72_2 + (pub_r001686_9_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001686_1_1 * 2) + 26) & 63;
  int stage_v_200_2 = ((pub_r001686_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_28_1 + (pub_r001686_15_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_28_2 + (pub_r001686_15_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_86_1 + (pub_r001686_6_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_86_2 + (pub_r001686_6_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_55_1 + (pub_r001686_8_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_55_2 + (pub_r001686_8_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_97_1 + (pub_r001686_11_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_97_2 + (pub_r001686_11_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_188_1 + (pub_r001686_2_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_188_2 + (pub_r001686_2_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001686_12_1 * 2) + 13) & 63;
  int stage_v_206_2 = ((pub_r001686_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001686_7_1 * 2) + 11) & 63;
  int stage_v_207_2 = ((pub_r001686_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001686_6_1 * 2) + 36) & 63;
  int stage_v_208_2 = ((pub_r001686_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((stage_v_202_1 + (pub_r001686_6_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_202_2 + (pub_r001686_6_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_35_1 + (pub_r001686_7_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_35_2 + (pub_r001686_7_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((stage_v_7_1 + (pub_r001686_4_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_7_2 + (pub_r001686_4_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((stage_v_88_1 + (pub_r001686_6_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_88_2 + (pub_r001686_6_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((stage_v_93_1 + (pub_r001686_9_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_93_2 + (pub_r001686_9_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_85_1 + (pub_r001686_11_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_85_2 + (pub_r001686_11_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((helper_flow_2_1 + (pub_r001686_8_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((helper_flow_2_2 + (pub_r001686_8_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((stage_v_84_1 + (pub_r001686_2_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_84_2 + (pub_r001686_2_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((helper_flow_6_1 + (pub_r001686_7_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((helper_flow_6_2 + (pub_r001686_7_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((sec_r001686_8_1 + (pub_r001686_1_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((sec_r001686_8_2 + (pub_r001686_1_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_152_1 + (pub_r001686_6_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_152_2 + (pub_r001686_6_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((pub_r001686_6_1 * 2) + 32) & 63;
  int stage_v_220_2 = ((pub_r001686_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((stage_v_17_1 + (pub_r001686_15_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_17_2 + (pub_r001686_15_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((pub_r001686_3_1 * 2) + 18) & 63;
  int stage_v_222_2 = ((pub_r001686_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((stage_v_175_1 + (pub_r001686_13_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_175_2 + (pub_r001686_13_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((sec_r001686_2_1 + (pub_r001686_15_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((sec_r001686_2_2 + (pub_r001686_15_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_72_1 + (pub_r001686_15_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_72_2 + (pub_r001686_15_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((pub_r001686_3_1 * 2) + 32) & 63;
  int stage_v_226_2 = ((pub_r001686_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_118_1 + (pub_r001686_11_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_118_2 + (pub_r001686_11_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((pub_r001686_5_1 * 2) + 41) & 63;
  int stage_v_228_2 = ((pub_r001686_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001686_2_1 * 2) + 34) & 63;
  int stage_v_229_2 = ((pub_r001686_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_192_1 + (pub_r001686_1_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_192_2 + (pub_r001686_1_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_57_1 + (pub_r001686_9_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_57_2 + (pub_r001686_9_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((pub_r001686_5_1 * 2) + 18) & 63;
  int stage_v_232_2 = ((pub_r001686_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((stage_v_167_1 + (pub_r001686_13_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_167_2 + (pub_r001686_13_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001686_14_1 == pub_r001686_14_2);
  __CPROVER_assume(sec_r001686_10_1 != sec_r001686_10_2);
  __CPROVER_assume(pub_r001686_1_1 == pub_r001686_1_2);
  __CPROVER_assume(pub_r001686_7_1 == pub_r001686_7_2);
  __CPROVER_assume(sec_r001686_13_1 != sec_r001686_13_2);
  __CPROVER_assume(sec_r001686_0_1 != sec_r001686_0_2);
  __CPROVER_assume(pub_r001686_10_1 == pub_r001686_10_2);
  __CPROVER_assume(sec_r001686_4_1 != sec_r001686_4_2);
  __CPROVER_assume(pub_r001686_12_1 == pub_r001686_12_2);
  __CPROVER_assume(pub_r001686_4_1 == pub_r001686_4_2);
  __CPROVER_assume(pub_r001686_5_1 == pub_r001686_5_2);
  __CPROVER_assume(sec_r001686_15_1 != sec_r001686_15_2);
  __CPROVER_assume(sec_r001686_2_1 != sec_r001686_2_2);
  __CPROVER_assume(pub_r001686_15_1 == pub_r001686_15_2);
  __CPROVER_assume(pub_r001686_8_1 == pub_r001686_8_2);
  __CPROVER_assume(pub_r001686_13_1 == pub_r001686_13_2);
  __CPROVER_assume(pub_r001686_6_1 == pub_r001686_6_2);
  __CPROVER_assume(sec_r001686_12_1 != sec_r001686_12_2);
  __CPROVER_assume(sec_r001686_11_1 != sec_r001686_11_2);
  __CPROVER_assume(sec_r001686_16_1 != sec_r001686_16_2);
  __CPROVER_assume(pub_r001686_3_1 == pub_r001686_3_2);
  __CPROVER_assume(sec_r001686_3_1 != sec_r001686_3_2);
  __CPROVER_assume(sec_r001686_6_1 != sec_r001686_6_2);
  __CPROVER_assume(sec_r001686_14_1 != sec_r001686_14_2);
  __CPROVER_assume(pub_r001686_2_1 == pub_r001686_2_2);
  __CPROVER_assume(sec_r001686_7_1 != sec_r001686_7_2);
  __CPROVER_assume(sec_r001686_8_1 != sec_r001686_8_2);
  __CPROVER_assume(pub_r001686_9_1 == pub_r001686_9_2);
  __CPROVER_assume(pub_r001686_0_1 == pub_r001686_0_2);
  __CPROVER_assume(sec_r001686_9_1 != sec_r001686_9_2);
  __CPROVER_assume(sec_r001686_1_1 != sec_r001686_1_2);
  __CPROVER_assume(pub_r001686_11_1 == pub_r001686_11_2);
  __CPROVER_assume(sec_r001686_5_1 != sec_r001686_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.reading == st_var_2_2.reading);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
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
}


