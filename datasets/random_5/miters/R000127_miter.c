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
struct EventLog_R000127_2713_0
{
  short severity;
  unsigned char signature;
  short facility;
  int buffer[3];
};
struct DeviceConfig_R000127_2713_1
{
  int id;
  int port;
  short timeout;
  int baud_rate;
  int buffer[3];
};
struct FilterState_R000127_2713_2
{
  int damping;
  unsigned char prev_out;
  int gain_db;
  int buffer[3];
};
struct SensorNode_R000127_2713_3
{
  short threshold;
  short offset;
  short gain;
  int buffer[3];
};
union RegisterBank_R000127_2713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000127_2713_1
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
void fn_R000127_2713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st_1 = {0};
  struct DeviceConfig_R000127_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int delta_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_95_1)
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

  switch (delta_95_2)
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

  int mask_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_25_1) & 63;
  aux_2 = (aux_2 + mask_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_97_1 = local_arr_1[aux_1 % 3];
  int damping_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_97_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_95_1 == delta_95_2);
  assert(mask_25_1 == mask_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_97_1 == damping_97_2);
}

int fn_R000127_2713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int delta_95 = (aux + st.buffer[1]) & 3;
  switch (delta_95)
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

  int mask_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_25) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_97 = local_arr[aux % 3];
  acc = (acc + (damping_97 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000127_2713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st_1 = {0};
  struct EventLog_R000127_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int phase_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_76_1)
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

  switch (phase_76_2)
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

  int accumulator_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_71_1 > 25)
  {
    acc_1 = ((acc_1 + (accumulator_71_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_71_2 > 25)
  {
    acc_2 = ((acc_2 + (accumulator_71_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_76_1 == phase_76_2);
  assert(accumulator_71_1 == accumulator_71_2);
}

int fn_R000127_2713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int phase_76 = (aux + st.buffer[1]) & 3;
  switch (phase_76)
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

  int accumulator_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_71 > 25)
  {
    acc = ((acc + (accumulator_71 * 2)) + 5) & 127;
    aux ^= accumulator_71 & 15;
  }
  else
  {
    acc = ((acc - accumulator_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000127_2713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000127_2713_3 st_1 = {0};
  struct SensorNode_R000127_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int factor_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_49_1) & 63;
  aux_2 = (aux_2 + factor_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_87_1)
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

  switch (segment_87_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_49_1 == factor_49_2);
  assert(segment_87_1 == segment_87_2);
}

int fn_R000127_2713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000127_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int factor_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_49) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_87 = (aux + st.buffer[1]) & 3;
  switch (segment_87)
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

void fn_R000127_2713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st_1 = {0};
  struct EventLog_R000127_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_53_1 = local_arr_1[aux_1 % 3];
  int index_reg_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_53_1 == index_reg_53_2);
}

int fn_R000127_2713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_53 = local_arr[aux % 3];
  acc = (acc + (index_reg_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000127_2713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000127_2713_3 st_1 = {0};
  struct SensorNode_R000127_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int weight_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_36_1) & 63;
  aux_2 = (aux_2 + weight_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_36_1 == weight_36_2);
}

int fn_R000127_2713_4(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000127_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int weight_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_36) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000127_2713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st_1 = {0};
  struct FilterState_R000127_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_89_1) & 63;
  aux_2 = (aux_2 + stride_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_48_1)
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

  switch (segment_48_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_89_1 == stride_89_2);
  assert(segment_48_1 == segment_48_2);
}

int fn_R000127_2713_5(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_89) & 63;
  acc ^= aux;
  int segment_48 = (aux + st.buffer[1]) & 3;
  switch (segment_48)
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

void fn_R000127_2713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st_1 = {0};
  struct EventLog_R000127_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int checksum_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_22_1 > 49)
  {
    acc_1 = ((acc_1 + (checksum_22_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_22_2 > 49)
  {
    acc_2 = ((acc_2 + (checksum_22_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_10_1) & 63;
  aux_2 = (aux_2 + scale_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_22_1 == checksum_22_2);
  assert(scale_10_1 == scale_10_2);
}

int fn_R000127_2713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int checksum_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_22 > 49)
  {
    acc = ((acc + (checksum_22 * 2)) + 5) & 127;
    aux ^= checksum_22 & 15;
  }
  else
  {
    acc = ((acc - checksum_22) + 11) & 127;
    aux += 3;
  }
  int scale_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000127_2713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st_1 = {0};
  struct DeviceConfig_R000127_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_98_1 = local_arr_1[aux_1 % 3];
  int accumulator_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_98_2 * 2)) & 127;
  int phase_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_58_1 > 41)
  {
    acc_1 = ((acc_1 + (phase_58_1 * 2)) + 5) & 127;
    aux_1 ^= phase_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_58_2 > 41)
  {
    acc_2 = ((acc_2 + (phase_58_2 * 2)) + 5) & 127;
    aux_2 ^= phase_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_79_1)
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

  switch (anchor_79_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_98_1 == accumulator_98_2);
  assert(phase_58_1 == phase_58_2);
  assert(anchor_79_1 == anchor_79_2);
}

int fn_R000127_2713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_98 = local_arr[aux % 3];
  acc = (acc + (accumulator_98 * 2)) & 127;
  int phase_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_58 > 41)
  {
    acc = ((acc + (phase_58 * 2)) + 5) & 127;
    aux ^= phase_58 & 15;
  }
  else
  {
    acc = ((acc - phase_58) + 11) & 127;
    aux += 3;
  }
  int anchor_79 = (aux + st.buffer[1]) & 3;
  switch (anchor_79)
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

void fn_R000127_2713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st_1 = {0};
  struct FilterState_R000127_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_61_1 = local_arr_1[aux_1 % 3];
  int scale_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_61_2 * 2)) & 127;
  int index_reg_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_71_1 > 37)
  {
    acc_1 = ((acc_1 + (index_reg_71_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_71_2 > 37)
  {
    acc_2 = ((acc_2 + (index_reg_71_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_56_1) & 63;
  aux_2 = (aux_2 + tracker_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_61_1 == scale_61_2);
  assert(index_reg_71_1 == index_reg_71_2);
  assert(tracker_56_1 == tracker_56_2);
}

int fn_R000127_2713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_61 = local_arr[aux % 3];
  acc = (acc + (scale_61 * 2)) & 127;
  int index_reg_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_71 > 37)
  {
    acc = ((acc + (index_reg_71 * 2)) + 5) & 127;
    aux ^= index_reg_71 & 15;
  }
  else
  {
    acc = ((acc - index_reg_71) + 11) & 127;
    aux += 3;
  }
  int tracker_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000127_2713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st_1 = {0};
  struct EventLog_R000127_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int index_reg_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_83_1)
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

  switch (index_reg_83_2)
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
  int weight_75_1 = local_arr_1[aux_1 % 3];
  int weight_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_75_2 * 2)) & 127;
  int scale_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_97_1) & 63;
  aux_2 = (aux_2 + scale_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_83_1 == index_reg_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_75_1 == weight_75_2);
  assert(scale_97_1 == scale_97_2);
}

int fn_R000127_2713_9(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int index_reg_83 = (aux + st.buffer[1]) & 3;
  switch (index_reg_83)
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
  int weight_75 = local_arr[aux % 3];
  acc = (acc + (weight_75 * 2)) & 127;
  int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000127_2713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st_1 = {0};
  struct FilterState_R000127_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_24_1 > 22)
  {
    acc_1 = ((acc_1 + (bound_24_1 * 2)) + 5) & 127;
    aux_1 ^= bound_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_24_2 > 22)
  {
    acc_2 = ((acc_2 + (bound_24_2 * 2)) + 5) & 127;
    aux_2 ^= bound_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_91_1 = local_arr_1[aux_1 % 3];
  int accumulator_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_91_2 * 2)) & 127;
  int phase_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_68_1)
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

  switch (phase_68_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_24_1 == bound_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_91_1 == accumulator_91_2);
  assert(phase_68_1 == phase_68_2);
}

int fn_R000127_2713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_24 > 22)
  {
    acc = ((acc + (bound_24 * 2)) + 5) & 127;
    aux ^= bound_24 & 15;
  }
  else
  {
    acc = ((acc - bound_24) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_91 = local_arr[aux % 3];
  acc = (acc + (accumulator_91 * 2)) & 127;
  int phase_68 = (aux + st.buffer[1]) & 3;
  switch (phase_68)
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

void fn_R000127_2713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st_1 = {0};
  struct DeviceConfig_R000127_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int index_reg_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_10_1) & 63;
  aux_2 = (aux_2 + index_reg_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_73_1 > 39)
  {
    acc_1 = ((acc_1 + (vector_73_1 * 2)) + 5) & 127;
    aux_1 ^= vector_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_73_2 > 39)
  {
    acc_2 = ((acc_2 + (vector_73_2 * 2)) + 5) & 127;
    aux_2 ^= vector_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_10_1 == index_reg_10_2);
  assert(vector_73_1 == vector_73_2);
}

int fn_R000127_2713_11(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int index_reg_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_10) & 63;
  acc ^= aux;
  int vector_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_73 > 39)
  {
    acc = ((acc + (vector_73 * 2)) + 5) & 127;
    aux ^= vector_73 & 15;
  }
  else
  {
    acc = ((acc - vector_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000127_2713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st_1 = {0};
  struct DeviceConfig_R000127_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_67_1)
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

  switch (quotient_67_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_67_1 == quotient_67_2);
}

int fn_R000127_2713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_67 = (aux + st.buffer[1]) & 3;
  switch (quotient_67)
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

void fn_R000127_2713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st_1 = {0};
  struct FilterState_R000127_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int cursor_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_48_1) & 63;
  aux_2 = (aux_2 + cursor_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_95_1)
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

  switch (accumulator_95_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_48_1 == cursor_48_2);
  assert(accumulator_95_1 == accumulator_95_2);
}

int fn_R000127_2713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int cursor_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_48) & 63;
  acc ^= aux;
  int accumulator_95 = (aux + st.buffer[1]) & 3;
  switch (accumulator_95)
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

void fn_R000127_2713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st_1 = {0};
  struct DeviceConfig_R000127_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int window_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_18_1) & 63;
  aux_2 = (aux_2 + window_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_64_1)
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

  switch (residue_64_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_18_1 == window_18_2);
  assert(residue_64_1 == residue_64_2);
}

int fn_R000127_2713_14(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000127_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int window_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_18) & 63;
  acc ^= aux;
  int residue_64 = (aux + st.buffer[1]) & 3;
  switch (residue_64)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000127_2713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st_1 = {0};
  struct EventLog_R000127_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_81_1)
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

  switch (delta_81_2)
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
  int sample_86_1 = local_arr_1[aux_1 % 3];
  int sample_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_81_1 == delta_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_86_1 == sample_86_2);
}

int fn_R000127_2713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_81 = (aux + st.buffer[1]) & 3;
  switch (delta_81)
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
  int sample_86 = local_arr[aux % 3];
  acc = (acc + (sample_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000127_2713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st_1 = {0};
  struct FilterState_R000127_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_33_1 > 46)
  {
    acc_1 = ((acc_1 + (metric_33_1 * 2)) + 5) & 127;
    aux_1 ^= metric_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_33_2 > 46)
  {
    acc_2 = ((acc_2 + (metric_33_2 * 2)) + 5) & 127;
    aux_2 ^= metric_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_90_1 = local_arr_1[aux_1 % 3];
  int quotient_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_90_2 * 2)) & 127;
  int window_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_25_1) & 63;
  aux_2 = (aux_2 + window_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_33_1 == metric_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_90_1 == quotient_90_2);
  assert(window_25_1 == window_25_2);
}

int fn_R000127_2713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_33 > 46)
  {
    acc = ((acc + (metric_33 * 2)) + 5) & 127;
    aux ^= metric_33 & 15;
  }
  else
  {
    acc = ((acc - metric_33) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_90 = local_arr[aux % 3];
  acc = (acc + (quotient_90 * 2)) & 127;
  int window_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000127_2713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st_1 = {0};
  struct EventLog_R000127_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int segment_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_39_1)
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

  switch (segment_39_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_31_1 > 47)
  {
    acc_1 = ((acc_1 + (anchor_31_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_31_2 > 47)
  {
    acc_2 = ((acc_2 + (anchor_31_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_79_1) & 63;
  aux_2 = (aux_2 + anchor_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_39_1 == segment_39_2);
  assert(anchor_31_1 == anchor_31_2);
  assert(anchor_79_1 == anchor_79_2);
}

int fn_R000127_2713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int segment_39 = (aux + st.buffer[1]) & 3;
  switch (segment_39)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_31 > 47)
  {
    acc = ((acc + (anchor_31 * 2)) + 5) & 127;
    aux ^= anchor_31 & 15;
  }
  else
  {
    acc = ((acc - anchor_31) + 11) & 127;
    aux += 3;
  }
  int anchor_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000127_2713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st_1 = {0};
  struct FilterState_R000127_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int factor_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_80_1) & 63;
  aux_2 = (aux_2 + factor_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_40_1 > 45)
  {
    acc_1 = ((acc_1 + (margin_40_1 * 2)) + 5) & 127;
    aux_1 ^= margin_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_40_2 > 45)
  {
    acc_2 = ((acc_2 + (margin_40_2 * 2)) + 5) & 127;
    aux_2 ^= margin_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_80_1 == factor_80_2);
  assert(margin_40_1 == margin_40_2);
}

int fn_R000127_2713_18(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int factor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_80) & 63;
  acc ^= aux;
  int margin_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_40 > 45)
  {
    acc = ((acc + (margin_40 * 2)) + 5) & 127;
    aux ^= margin_40 & 15;
  }
  else
  {
    acc = ((acc - margin_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000127_2713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st_1 = {0};
  struct FilterState_R000127_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_24_1 = local_arr_1[aux_1 % 3];
  int cursor_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_24_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_72_1 > 16)
  {
    acc_1 = ((acc_1 + (tracker_72_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_72_2 > 16)
  {
    acc_2 = ((acc_2 + (tracker_72_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_24_1 == cursor_24_2);
  assert(tracker_72_1 == tracker_72_2);
}

int fn_R000127_2713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int cursor_24 = local_arr[aux % 3];
  acc = (acc + (cursor_24 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_72 > 16)
  {
    acc = ((acc + (tracker_72 * 2)) + 5) & 127;
    aux ^= tracker_72 & 15;
  }
  else
  {
    acc = ((acc - tracker_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000127_2713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st_1 = {0};
  struct FilterState_R000127_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_30_1 = local_arr_1[aux_1 % 3];
  int tally_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_30_2 * 2)) & 127;
  int vector_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_45_1 > 25)
  {
    acc_1 = ((acc_1 + (vector_45_1 * 2)) + 5) & 127;
    aux_1 ^= vector_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_45_2 > 25)
  {
    acc_2 = ((acc_2 + (vector_45_2 * 2)) + 5) & 127;
    aux_2 ^= vector_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_30_1 == tally_30_2);
  assert(vector_45_1 == vector_45_2);
}

int fn_R000127_2713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000127_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_30 = local_arr[aux % 3];
  acc = (acc + (tally_30 * 2)) & 127;
  int vector_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_45 > 25)
  {
    acc = ((acc + (vector_45 * 2)) + 5) & 127;
    aux ^= vector_45 & 15;
  }
  else
  {
    acc = ((acc - vector_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000127_2713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000127_2713_3 st_1 = {0};
  struct SensorNode_R000127_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_24_1 = local_arr_1[aux_1 % 3];
  int damping_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_24_2 * 2)) & 127;
  int bound_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_56_1) & 63;
  aux_2 = (aux_2 + bound_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_24_1 == damping_24_2);
  assert(bound_56_1 == bound_56_2);
}

int fn_R000127_2713_21(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000127_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int damping_24 = local_arr[aux % 3];
  acc = (acc + (damping_24 * 2)) & 127;
  int bound_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000127_2713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st_1 = {0};
  struct EventLog_R000127_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int vector_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_69_1 > 24)
  {
    acc_1 = ((acc_1 + (vector_69_1 * 2)) + 5) & 127;
    aux_1 ^= vector_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_69_2 > 24)
  {
    acc_2 = ((acc_2 + (vector_69_2 * 2)) + 5) & 127;
    aux_2 ^= vector_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_55_1)
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

  switch (damping_55_2)
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

  int segment_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_99_1) & 63;
  aux_2 = (aux_2 + segment_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_69_1 == vector_69_2);
  assert(damping_55_1 == damping_55_2);
  assert(segment_99_1 == segment_99_2);
}

int fn_R000127_2713_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000127_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int vector_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_69 > 24)
  {
    acc = ((acc + (vector_69 * 2)) + 5) & 127;
    aux ^= vector_69 & 15;
  }
  else
  {
    acc = ((acc - vector_69) + 11) & 127;
    aux += 3;
  }
  int damping_55 = (aux + st.buffer[1]) & 3;
  switch (damping_55)
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

  int segment_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000127_0_1;
  int sec_r000127_0_2;
  int sec_r000127_1_1;
  int sec_r000127_1_2;
  int sec_r000127_2_1;
  int sec_r000127_2_2;
  int sec_r000127_3_1;
  int sec_r000127_3_2;
  int sec_r000127_4_1;
  int sec_r000127_4_2;
  int sec_r000127_5_1;
  int sec_r000127_5_2;
  int sec_r000127_6_1;
  int sec_r000127_6_2;
  int sec_r000127_7_1;
  int sec_r000127_7_2;
  int sec_r000127_8_1;
  int sec_r000127_8_2;
  int sec_r000127_9_1;
  int sec_r000127_9_2;
  int sec_r000127_10_1;
  int sec_r000127_10_2;
  int sec_r000127_11_1;
  int sec_r000127_11_2;
  int sec_r000127_12_1;
  int sec_r000127_12_2;
  int sec_r000127_13_1;
  int sec_r000127_13_2;
  int sec_r000127_14_1;
  int sec_r000127_14_2;
  int sec_r000127_15_1;
  int sec_r000127_15_2;
  int sec_r000127_16_1;
  int sec_r000127_16_2;
  int sec_r000127_17_1;
  int sec_r000127_17_2;
  int sec_r000127_18_1;
  int sec_r000127_18_2;
  int sec_r000127_19_1;
  int sec_r000127_19_2;
  int sec_r000127_20_1;
  int sec_r000127_20_2;
  int pub_r000127_0_1;
  int pub_r000127_0_2;
  int pub_r000127_1_1;
  int pub_r000127_1_2;
  int pub_r000127_2_1;
  int pub_r000127_2_2;
  int pub_r000127_3_1;
  int pub_r000127_3_2;
  int pub_r000127_4_1;
  int pub_r000127_4_2;
  int pub_r000127_5_1;
  int pub_r000127_5_2;
  int pub_r000127_6_1;
  int pub_r000127_6_2;
  int pub_r000127_7_1;
  int pub_r000127_7_2;
  int pub_r000127_8_1;
  int pub_r000127_8_2;
  int pub_r000127_9_1;
  int pub_r000127_9_2;
  int pub_r000127_10_1;
  int pub_r000127_10_2;
  int pub_r000127_11_1;
  int pub_r000127_11_2;
  int pub_r000127_12_1;
  int pub_r000127_12_2;
  int pub_r000127_13_1;
  int pub_r000127_13_2;
  int pub_r000127_14_1;
  int pub_r000127_14_2;
  int pub_r000127_15_1;
  int pub_r000127_15_2;
  int pub_r000127_16_1;
  int pub_r000127_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000127_0_1 >= (-100)) && (pub_r000127_0_1 <= 100));
  __CPROVER_assume((pub_r000127_0_2 >= (-100)) && (pub_r000127_0_2 <= 100));
  __CPROVER_assume((pub_r000127_1_1 >= (-100)) && (pub_r000127_1_1 <= 100));
  __CPROVER_assume((pub_r000127_1_2 >= (-100)) && (pub_r000127_1_2 <= 100));
  __CPROVER_assume((pub_r000127_2_1 >= (-100)) && (pub_r000127_2_1 <= 100));
  __CPROVER_assume((pub_r000127_2_2 >= (-100)) && (pub_r000127_2_2 <= 100));
  __CPROVER_assume((pub_r000127_3_1 >= (-100)) && (pub_r000127_3_1 <= 100));
  __CPROVER_assume((pub_r000127_3_2 >= (-100)) && (pub_r000127_3_2 <= 100));
  __CPROVER_assume((pub_r000127_4_1 >= (-100)) && (pub_r000127_4_1 <= 100));
  __CPROVER_assume((pub_r000127_4_2 >= (-100)) && (pub_r000127_4_2 <= 100));
  __CPROVER_assume((pub_r000127_5_1 >= (-100)) && (pub_r000127_5_1 <= 100));
  __CPROVER_assume((pub_r000127_5_2 >= (-100)) && (pub_r000127_5_2 <= 100));
  __CPROVER_assume((pub_r000127_6_1 >= (-100)) && (pub_r000127_6_1 <= 100));
  __CPROVER_assume((pub_r000127_6_2 >= (-100)) && (pub_r000127_6_2 <= 100));
  __CPROVER_assume((pub_r000127_7_1 >= (-100)) && (pub_r000127_7_1 <= 100));
  __CPROVER_assume((pub_r000127_7_2 >= (-100)) && (pub_r000127_7_2 <= 100));
  __CPROVER_assume((pub_r000127_8_1 >= (-100)) && (pub_r000127_8_1 <= 100));
  __CPROVER_assume((pub_r000127_8_2 >= (-100)) && (pub_r000127_8_2 <= 100));
  __CPROVER_assume((pub_r000127_9_1 >= (-100)) && (pub_r000127_9_1 <= 100));
  __CPROVER_assume((pub_r000127_9_2 >= (-100)) && (pub_r000127_9_2 <= 100));
  __CPROVER_assume((pub_r000127_10_1 >= (-100)) && (pub_r000127_10_1 <= 100));
  __CPROVER_assume((pub_r000127_10_2 >= (-100)) && (pub_r000127_10_2 <= 100));
  __CPROVER_assume((pub_r000127_11_1 >= (-100)) && (pub_r000127_11_1 <= 100));
  __CPROVER_assume((pub_r000127_11_2 >= (-100)) && (pub_r000127_11_2 <= 100));
  __CPROVER_assume((pub_r000127_12_1 >= (-100)) && (pub_r000127_12_1 <= 100));
  __CPROVER_assume((pub_r000127_12_2 >= (-100)) && (pub_r000127_12_2 <= 100));
  __CPROVER_assume((pub_r000127_13_1 >= (-100)) && (pub_r000127_13_1 <= 100));
  __CPROVER_assume((pub_r000127_13_2 >= (-100)) && (pub_r000127_13_2 <= 100));
  __CPROVER_assume((pub_r000127_14_1 >= (-100)) && (pub_r000127_14_1 <= 100));
  __CPROVER_assume((pub_r000127_14_2 >= (-100)) && (pub_r000127_14_2 <= 100));
  __CPROVER_assume((pub_r000127_15_1 >= (-100)) && (pub_r000127_15_1 <= 100));
  __CPROVER_assume((pub_r000127_15_2 >= (-100)) && (pub_r000127_15_2 <= 100));
  __CPROVER_assume((pub_r000127_16_1 >= (-100)) && (pub_r000127_16_1 <= 100));
  __CPROVER_assume((pub_r000127_16_2 >= (-100)) && (pub_r000127_16_2 <= 100));
  __CPROVER_assume((sec_r000127_0_1 >= 0) && (sec_r000127_0_1 <= 255));
  __CPROVER_assume((sec_r000127_0_2 >= 0) && (sec_r000127_0_2 <= 255));
  __CPROVER_assume((sec_r000127_1_1 >= 0) && (sec_r000127_1_1 <= 255));
  __CPROVER_assume((sec_r000127_1_2 >= 0) && (sec_r000127_1_2 <= 255));
  __CPROVER_assume((sec_r000127_2_1 >= 0) && (sec_r000127_2_1 <= 255));
  __CPROVER_assume((sec_r000127_2_2 >= 0) && (sec_r000127_2_2 <= 255));
  __CPROVER_assume((sec_r000127_3_1 >= 0) && (sec_r000127_3_1 <= 255));
  __CPROVER_assume((sec_r000127_3_2 >= 0) && (sec_r000127_3_2 <= 255));
  __CPROVER_assume((sec_r000127_4_1 >= 0) && (sec_r000127_4_1 <= 255));
  __CPROVER_assume((sec_r000127_4_2 >= 0) && (sec_r000127_4_2 <= 255));
  __CPROVER_assume((sec_r000127_5_1 >= 0) && (sec_r000127_5_1 <= 255));
  __CPROVER_assume((sec_r000127_5_2 >= 0) && (sec_r000127_5_2 <= 255));
  __CPROVER_assume((sec_r000127_6_1 >= 0) && (sec_r000127_6_1 <= 255));
  __CPROVER_assume((sec_r000127_6_2 >= 0) && (sec_r000127_6_2 <= 255));
  __CPROVER_assume((sec_r000127_7_1 >= 0) && (sec_r000127_7_1 <= 255));
  __CPROVER_assume((sec_r000127_7_2 >= 0) && (sec_r000127_7_2 <= 255));
  __CPROVER_assume((sec_r000127_8_1 >= 0) && (sec_r000127_8_1 <= 255));
  __CPROVER_assume((sec_r000127_8_2 >= 0) && (sec_r000127_8_2 <= 255));
  __CPROVER_assume((sec_r000127_9_1 >= 0) && (sec_r000127_9_1 <= 255));
  __CPROVER_assume((sec_r000127_9_2 >= 0) && (sec_r000127_9_2 <= 255));
  __CPROVER_assume((sec_r000127_10_1 >= 0) && (sec_r000127_10_1 <= 255));
  __CPROVER_assume((sec_r000127_10_2 >= 0) && (sec_r000127_10_2 <= 255));
  __CPROVER_assume((sec_r000127_11_1 >= 0) && (sec_r000127_11_1 <= 255));
  __CPROVER_assume((sec_r000127_11_2 >= 0) && (sec_r000127_11_2 <= 255));
  __CPROVER_assume((sec_r000127_12_1 >= 0) && (sec_r000127_12_1 <= 255));
  __CPROVER_assume((sec_r000127_12_2 >= 0) && (sec_r000127_12_2 <= 255));
  __CPROVER_assume((sec_r000127_13_1 >= 0) && (sec_r000127_13_1 <= 255));
  __CPROVER_assume((sec_r000127_13_2 >= 0) && (sec_r000127_13_2 <= 255));
  __CPROVER_assume((sec_r000127_14_1 >= 0) && (sec_r000127_14_1 <= 255));
  __CPROVER_assume((sec_r000127_14_2 >= 0) && (sec_r000127_14_2 <= 255));
  __CPROVER_assume((sec_r000127_15_1 >= 0) && (sec_r000127_15_1 <= 255));
  __CPROVER_assume((sec_r000127_15_2 >= 0) && (sec_r000127_15_2 <= 255));
  __CPROVER_assume((sec_r000127_16_1 >= 0) && (sec_r000127_16_1 <= 255));
  __CPROVER_assume((sec_r000127_16_2 >= 0) && (sec_r000127_16_2 <= 255));
  __CPROVER_assume((sec_r000127_17_1 >= 0) && (sec_r000127_17_1 <= 255));
  __CPROVER_assume((sec_r000127_17_2 >= 0) && (sec_r000127_17_2 <= 255));
  __CPROVER_assume((sec_r000127_18_1 >= 0) && (sec_r000127_18_1 <= 255));
  __CPROVER_assume((sec_r000127_18_2 >= 0) && (sec_r000127_18_2 <= 255));
  __CPROVER_assume((sec_r000127_19_1 >= 0) && (sec_r000127_19_1 <= 255));
  __CPROVER_assume((sec_r000127_19_2 >= 0) && (sec_r000127_19_2 <= 255));
  __CPROVER_assume((sec_r000127_20_1 >= 0) && (sec_r000127_20_1 <= 255));
  __CPROVER_assume((sec_r000127_20_2 >= 0) && (sec_r000127_20_2 <= 255));
  struct EventLog_R000127_2713_0 st_var_0_1 = {0};
  struct EventLog_R000127_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000127_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000127_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000127_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000127_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000127_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000127_0_2 + 7) & 15;
  struct DeviceConfig_R000127_2713_1 st_var_1_1 = {0};
  struct DeviceConfig_R000127_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000127_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000127_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000127_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000127_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000127_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000127_0_2 + 9) & 15;
  struct FilterState_R000127_2713_2 st_var_2_1 = {0};
  struct FilterState_R000127_2713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000127_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000127_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000127_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000127_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000127_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000127_0_2 + 11) & 15;
  struct SensorNode_R000127_2713_3 st_var_3_1 = {0};
  struct SensorNode_R000127_2713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000127_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000127_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000127_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000127_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000127_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000127_0_2 + 13) & 15;
  union RegisterBank_R000127_2713_0 u_var_1;
  union RegisterBank_R000127_2713_0 u_var_2;
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
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 32)
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
  if (stage_v_4_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 32)
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = ((st_var_2_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_2_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 36)
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
  if (stage_v_6_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 36)
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
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = ((st_var_2_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_2_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 51)
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
  if (stage_v_10_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 51)
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
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = ((st_var_3_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_3_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 33)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 33)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((st_var_2_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_2_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 49)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 49)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_23_1 = (st_var_3_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_3_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 51)
    {
      chk_sum_1 ^= stage_v_24_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_24_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 51)
    {
      chk_sum_2 ^= stage_v_24_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 28)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 28)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 42)
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
  if (stage_v_26_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 42)
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
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 46)
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
  if (stage_v_28_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 46)
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
  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 30)
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
  if (stage_v_33_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 30)
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
  int stage_v_34_1 = (st_var_2_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_2_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 47)
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
  if (stage_v_38_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 47)
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
  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
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
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 47) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
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
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000127_2_1 & 1) != 0)
  {
    if ((sec_r000127_15_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000127_1_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000127_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000127_1_1 + 7) & 127;
  }
  if ((sec_r000127_2_2 & 1) != 0)
  {
    if ((sec_r000127_15_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000127_1_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000127_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000127_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000127_16_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000127_11_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000127_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000127_11_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000127_16_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000127_11_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000127_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000127_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000127_18_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000127_0_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000127_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000127_0_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000127_18_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000127_0_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000127_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000127_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000127_4_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000127_15_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000127_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000127_15_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000127_4_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000127_15_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000127_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000127_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((sec_r000127_12_1 & 1) != 0)
  {
    if ((sec_r000127_3_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000127_12_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000127_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000127_12_1 + 7) & 127;
  }
  if ((sec_r000127_12_2 & 1) != 0)
  {
    if ((sec_r000127_3_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000127_12_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000127_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000127_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000127_15_1 & 1) != 0)
  {
    if ((sec_r000127_2_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000127_6_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000127_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000127_6_1 + 7) & 127;
  }
  if ((sec_r000127_15_2 & 1) != 0)
  {
    if ((sec_r000127_2_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000127_6_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000127_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000127_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000127_1_1 & 1) != 0)
  {
    if ((sec_r000127_17_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000127_9_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000127_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000127_9_1 + 7) & 127;
  }
  if ((sec_r000127_1_2 & 1) != 0)
  {
    if ((sec_r000127_17_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000127_9_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000127_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000127_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000127_1_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000127_9_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000127_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000127_9_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000127_1_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000127_9_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000127_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000127_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000127_20_1 & 1) != 0)
  {
    if ((sec_r000127_2_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000127_15_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000127_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000127_15_1 + 7) & 127;
  }
  if ((sec_r000127_20_2 & 1) != 0)
  {
    if ((sec_r000127_2_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000127_15_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000127_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000127_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000127_3_1 & 1) != 0)
  {
    if ((sec_r000127_0_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000127_1_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000127_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000127_1_1 + 7) & 127;
  }
  if ((sec_r000127_3_2 & 1) != 0)
  {
    if ((sec_r000127_0_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000127_1_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000127_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000127_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000127_6_1 & 1) != 0)
  {
    if ((sec_r000127_13_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000127_5_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000127_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000127_5_1 + 7) & 127;
  }
  if ((sec_r000127_6_2 & 1) != 0)
  {
    if ((sec_r000127_13_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000127_5_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000127_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000127_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000127_2_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000127_9_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000127_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000127_9_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000127_2_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000127_9_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000127_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000127_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000127_17_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000127_13_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000127_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000127_13_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000127_17_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000127_13_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000127_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000127_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000127_12_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000127_1_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000127_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000127_1_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000127_12_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000127_1_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000127_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000127_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((sec_r000127_20_1 & 1) != 0)
  {
    if ((sec_r000127_11_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000127_14_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000127_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000127_14_1 + 7) & 127;
  }
  if ((sec_r000127_20_2 & 1) != 0)
  {
    if ((sec_r000127_11_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000127_14_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000127_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000127_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000127_9_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000127_1_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000127_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000127_1_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000127_9_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000127_1_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000127_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000127_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000127_6_1 & 1) != 0)
  {
    if ((sec_r000127_13_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000127_7_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000127_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000127_7_1 + 7) & 127;
  }
  if ((sec_r000127_6_2 & 1) != 0)
  {
    if ((sec_r000127_13_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000127_7_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000127_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000127_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000127_16_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000127_16_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000127_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000127_16_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000127_16_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000127_16_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000127_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000127_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000127_8_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000127_11_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000127_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000127_11_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000127_8_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000127_11_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000127_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000127_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000127_5_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000127_1_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000127_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000127_1_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000127_5_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000127_1_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000127_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000127_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000127_2_1 & 1) != 0)
  {
    if ((sec_r000127_14_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000127_0_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000127_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000127_0_1 + 7) & 127;
  }
  if ((sec_r000127_2_2 & 1) != 0)
  {
    if ((sec_r000127_14_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000127_0_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000127_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000127_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000127_4_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000127_10_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000127_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000127_10_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000127_4_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000127_10_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000127_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000127_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000127_15_1 & 1) != 0)
  {
    if ((sec_r000127_3_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000127_0_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000127_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000127_0_1 + 7) & 127;
  }
  if ((sec_r000127_15_2 & 1) != 0)
  {
    if ((sec_r000127_3_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000127_0_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000127_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000127_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000127_5_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000127_5_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000127_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000127_5_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000127_5_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000127_5_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000127_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000127_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000127_1_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000127_10_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000127_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000127_10_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000127_1_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000127_10_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000127_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000127_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000127_3_1 & 1) != 0)
  {
    if ((sec_r000127_12_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000127_2_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000127_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000127_2_1 + 7) & 127;
  }
  if ((sec_r000127_3_2 & 1) != 0)
  {
    if ((sec_r000127_12_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000127_2_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000127_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000127_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000127_0_1 & 1) != 0)
  {
    if ((sec_r000127_14_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000127_14_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000127_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000127_14_1 + 7) & 127;
  }
  if ((sec_r000127_0_2 & 1) != 0)
  {
    if ((sec_r000127_14_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000127_14_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000127_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000127_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000127_9_1 & 1) != 0)
  {
    if ((sec_r000127_4_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000127_3_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000127_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000127_3_1 + 7) & 127;
  }
  if ((sec_r000127_9_2 & 1) != 0)
  {
    if ((sec_r000127_4_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000127_3_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000127_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000127_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000127_6_1 & 1) != 0)
  {
    if ((sec_r000127_1_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000127_8_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000127_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000127_8_1 + 7) & 127;
  }
  if ((sec_r000127_6_2 & 1) != 0)
  {
    if ((sec_r000127_1_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000127_8_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000127_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000127_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000127_0_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000127_15_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000127_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000127_15_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000127_0_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000127_15_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000127_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000127_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000127_4_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000127_4_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000127_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000127_4_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000127_4_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000127_4_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000127_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000127_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000127_1_1 & 1) != 0)
  {
    if ((sec_r000127_15_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000127_13_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000127_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000127_13_1 + 7) & 127;
  }
  if ((sec_r000127_1_2 & 1) != 0)
  {
    if ((sec_r000127_15_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000127_13_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000127_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000127_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000127_18_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000127_11_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000127_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000127_11_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000127_18_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000127_11_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000127_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000127_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000127_6_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000127_7_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000127_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000127_7_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000127_6_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000127_7_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000127_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000127_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000127_10_1 & 1) != 0)
  {
    if ((sec_r000127_0_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000127_1_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000127_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000127_1_1 + 7) & 127;
  }
  if ((sec_r000127_10_2 & 1) != 0)
  {
    if ((sec_r000127_0_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000127_1_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000127_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000127_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000127_11_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000127_13_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000127_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000127_13_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000127_11_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000127_13_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000127_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000127_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000127_7_1 & 1) != 0)
  {
    if ((sec_r000127_3_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000127_16_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000127_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000127_16_1 + 7) & 127;
  }
  if ((sec_r000127_7_2 & 1) != 0)
  {
    if ((sec_r000127_3_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000127_16_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000127_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000127_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000127_19_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000127_8_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000127_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000127_8_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000127_19_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000127_8_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000127_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000127_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000127_11_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000127_5_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000127_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000127_5_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000127_11_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000127_5_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000127_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000127_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000127_19_1 & 1) != 0)
  {
    if ((sec_r000127_7_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000127_4_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000127_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000127_4_1 + 7) & 127;
  }
  if ((sec_r000127_19_2 & 1) != 0)
  {
    if ((sec_r000127_7_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000127_4_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000127_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000127_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000127_10_1 & 1) != 0)
  {
    if ((sec_r000127_3_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000127_14_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000127_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000127_14_1 + 7) & 127;
  }
  if ((sec_r000127_10_2 & 1) != 0)
  {
    if ((sec_r000127_3_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000127_14_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000127_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000127_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000127_11_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000127_10_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000127_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000127_10_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000127_11_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000127_10_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000127_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000127_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000127_6_1 & 1) != 0)
  {
    if ((sec_r000127_10_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000127_1_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000127_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000127_1_1 + 7) & 127;
  }
  if ((sec_r000127_6_2 & 1) != 0)
  {
    if ((sec_r000127_10_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000127_1_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000127_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000127_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000127_17_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000127_3_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000127_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000127_3_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000127_17_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000127_3_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000127_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000127_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000127_10_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000127_6_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000127_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000127_6_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000127_10_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000127_6_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000127_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000127_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000127_17_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000127_6_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000127_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000127_6_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000127_17_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000127_6_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000127_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000127_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000127_6_1 & 1) != 0)
  {
    if ((sec_r000127_20_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000127_6_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000127_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000127_6_1 + 7) & 127;
  }
  if ((sec_r000127_6_2 & 1) != 0)
  {
    if ((sec_r000127_20_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000127_6_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000127_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000127_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000127_5_1 & 1) != 0)
  {
    if ((sec_r000127_2_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000127_8_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000127_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000127_8_1 + 7) & 127;
  }
  if ((sec_r000127_5_2 & 1) != 0)
  {
    if ((sec_r000127_2_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000127_8_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000127_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000127_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000127_8_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000127_4_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000127_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000127_4_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000127_8_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000127_4_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000127_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000127_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000127_12_1 & 1) != 0)
  {
    if ((sec_r000127_6_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000127_12_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000127_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000127_12_1 + 7) & 127;
  }
  if ((sec_r000127_12_2 & 1) != 0)
  {
    if ((sec_r000127_6_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000127_12_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000127_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000127_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000127_1_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000127_8_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000127_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000127_8_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000127_1_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000127_8_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000127_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000127_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000127_3_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000127_11_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000127_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000127_11_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000127_3_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000127_11_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000127_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000127_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000127_7_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000127_7_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000127_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000127_7_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000127_7_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000127_7_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000127_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000127_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000127_20_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000127_15_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000127_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000127_15_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000127_20_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000127_15_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000127_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000127_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000127_12_1 & 1) != 0)
  {
    if ((sec_r000127_8_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000127_16_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000127_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000127_16_1 + 7) & 127;
  }
  if ((sec_r000127_12_2 & 1) != 0)
  {
    if ((sec_r000127_8_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000127_16_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000127_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000127_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000127_5_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000127_2_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000127_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000127_2_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000127_5_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000127_2_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000127_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000127_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000127_9_1 & 1) != 0)
  {
    if ((sec_r000127_13_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000127_0_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000127_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000127_0_1 + 7) & 127;
  }
  if ((sec_r000127_9_2 & 1) != 0)
  {
    if ((sec_r000127_13_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000127_0_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000127_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000127_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000127_20_1 & 1) != 0)
  {
    if ((sec_r000127_11_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000127_1_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000127_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000127_1_1 + 7) & 127;
  }
  if ((sec_r000127_20_2 & 1) != 0)
  {
    if ((sec_r000127_11_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000127_1_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000127_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000127_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000127_13_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000127_3_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000127_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000127_3_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000127_13_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000127_3_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000127_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000127_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000127_6_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000127_13_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000127_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000127_13_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000127_6_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000127_13_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000127_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000127_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000127_0_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000127_2_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000127_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000127_2_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000127_0_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000127_2_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000127_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000127_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000127_6_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000127_8_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000127_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000127_8_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000127_6_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000127_8_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000127_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000127_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000127_7_1 & 1) != 0)
  {
    if ((sec_r000127_9_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000127_16_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000127_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000127_16_1 + 7) & 127;
  }
  if ((sec_r000127_7_2 & 1) != 0)
  {
    if ((sec_r000127_9_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000127_16_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000127_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000127_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000127_17_1 & 1) != 0)
  {
    if ((sec_r000127_12_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000127_13_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000127_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000127_13_1 + 7) & 127;
  }
  if ((sec_r000127_17_2 & 1) != 0)
  {
    if ((sec_r000127_12_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000127_13_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000127_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000127_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000127_8_1 & 1) != 0)
  {
    if ((sec_r000127_12_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000127_6_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000127_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000127_6_1 + 7) & 127;
  }
  if ((sec_r000127_8_2 & 1) != 0)
  {
    if ((sec_r000127_12_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000127_6_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000127_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000127_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000127_12_1 & 1) != 0)
  {
    if ((sec_r000127_6_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000127_8_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000127_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000127_8_1 + 7) & 127;
  }
  if ((sec_r000127_12_2 & 1) != 0)
  {
    if ((sec_r000127_6_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000127_8_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000127_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000127_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000127_16_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000127_8_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000127_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000127_8_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000127_16_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000127_8_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000127_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000127_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000127_12_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000127_2_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000127_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000127_2_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000127_12_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000127_2_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000127_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000127_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000127_16_1 & 1) != 0)
  {
    if ((sec_r000127_11_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000127_6_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000127_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000127_6_1 + 7) & 127;
  }
  if ((sec_r000127_16_2 & 1) != 0)
  {
    if ((sec_r000127_11_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000127_6_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000127_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000127_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000127_5_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000127_3_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000127_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000127_3_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000127_5_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000127_3_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000127_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000127_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000127_18_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000127_11_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000127_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000127_11_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000127_18_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000127_11_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000127_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000127_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000127_2_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000127_6_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000127_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000127_6_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000127_2_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000127_6_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000127_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000127_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000127_9_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000127_10_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000127_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000127_10_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000127_9_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000127_10_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000127_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000127_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000127_8_1 & 1) != 0)
  {
    if ((sec_r000127_15_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000127_9_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000127_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000127_9_1 + 7) & 127;
  }
  if ((sec_r000127_8_2 & 1) != 0)
  {
    if ((sec_r000127_15_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000127_9_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000127_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000127_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000127_9_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000127_14_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000127_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000127_14_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000127_9_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000127_14_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000127_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000127_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000127_1_1 & 1) != 0)
  {
    if ((sec_r000127_10_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000127_11_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000127_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000127_11_1 + 7) & 127;
  }
  if ((sec_r000127_1_2 & 1) != 0)
  {
    if ((sec_r000127_10_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000127_11_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000127_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000127_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000127_18_1 & 1) != 0)
  {
    if ((sec_r000127_1_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000127_11_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000127_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000127_11_1 + 7) & 127;
  }
  if ((sec_r000127_18_2 & 1) != 0)
  {
    if ((sec_r000127_1_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000127_11_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000127_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000127_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000127_3_1 & 1) != 0)
  {
    if ((sec_r000127_12_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000127_0_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000127_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000127_0_1 + 7) & 127;
  }
  if ((sec_r000127_3_2 & 1) != 0)
  {
    if ((sec_r000127_12_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000127_0_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000127_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000127_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000127_14_1 & 1) != 0)
  {
    if ((sec_r000127_11_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000127_10_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000127_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000127_10_1 + 7) & 127;
  }
  if ((sec_r000127_14_2 & 1) != 0)
  {
    if ((sec_r000127_11_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000127_10_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000127_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000127_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000127_5_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000127_7_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000127_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000127_7_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000127_5_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000127_7_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000127_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000127_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000127_4_1 & 1) != 0)
  {
    if ((sec_r000127_13_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000127_9_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000127_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000127_9_1 + 7) & 127;
  }
  if ((sec_r000127_4_2 & 1) != 0)
  {
    if ((sec_r000127_13_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000127_9_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000127_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000127_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000127_3_1 & 1) != 0)
  {
    if ((sec_r000127_3_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000127_14_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000127_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000127_14_1 + 7) & 127;
  }
  if ((sec_r000127_3_2 & 1) != 0)
  {
    if ((sec_r000127_3_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000127_14_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000127_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000127_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000127_15_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000127_2_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000127_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000127_2_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000127_15_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000127_2_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000127_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000127_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000127_3_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000127_8_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000127_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000127_8_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000127_3_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000127_8_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000127_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000127_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000127_17_1 & 1) != 0)
  {
    if ((sec_r000127_7_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000127_13_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000127_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000127_13_1 + 7) & 127;
  }
  if ((sec_r000127_17_2 & 1) != 0)
  {
    if ((sec_r000127_7_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000127_13_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000127_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000127_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000127_15_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000127_8_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000127_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000127_8_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000127_15_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000127_8_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000127_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000127_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000127_11_1 != sec_r000127_11_2);
  __CPROVER_assume(sec_r000127_20_1 != sec_r000127_20_2);
  __CPROVER_assume(sec_r000127_13_1 != sec_r000127_13_2);
  __CPROVER_assume(pub_r000127_5_1 == pub_r000127_5_2);
  __CPROVER_assume(pub_r000127_9_1 == pub_r000127_9_2);
  __CPROVER_assume(sec_r000127_1_1 != sec_r000127_1_2);
  __CPROVER_assume(pub_r000127_16_1 == pub_r000127_16_2);
  __CPROVER_assume(sec_r000127_8_1 != sec_r000127_8_2);
  __CPROVER_assume(pub_r000127_12_1 == pub_r000127_12_2);
  __CPROVER_assume(pub_r000127_8_1 == pub_r000127_8_2);
  __CPROVER_assume(pub_r000127_0_1 == pub_r000127_0_2);
  __CPROVER_assume(sec_r000127_6_1 != sec_r000127_6_2);
  __CPROVER_assume(sec_r000127_5_1 != sec_r000127_5_2);
  __CPROVER_assume(sec_r000127_15_1 != sec_r000127_15_2);
  __CPROVER_assume(sec_r000127_16_1 != sec_r000127_16_2);
  __CPROVER_assume(sec_r000127_7_1 != sec_r000127_7_2);
  __CPROVER_assume(sec_r000127_9_1 != sec_r000127_9_2);
  __CPROVER_assume(pub_r000127_7_1 == pub_r000127_7_2);
  __CPROVER_assume(pub_r000127_10_1 == pub_r000127_10_2);
  __CPROVER_assume(sec_r000127_0_1 != sec_r000127_0_2);
  __CPROVER_assume(pub_r000127_15_1 == pub_r000127_15_2);
  __CPROVER_assume(sec_r000127_2_1 != sec_r000127_2_2);
  __CPROVER_assume(sec_r000127_14_1 != sec_r000127_14_2);
  __CPROVER_assume(pub_r000127_11_1 == pub_r000127_11_2);
  __CPROVER_assume(pub_r000127_14_1 == pub_r000127_14_2);
  __CPROVER_assume(sec_r000127_18_1 != sec_r000127_18_2);
  __CPROVER_assume(sec_r000127_12_1 != sec_r000127_12_2);
  __CPROVER_assume(sec_r000127_10_1 != sec_r000127_10_2);
  __CPROVER_assume(pub_r000127_3_1 == pub_r000127_3_2);
  __CPROVER_assume(pub_r000127_1_1 == pub_r000127_1_2);
  __CPROVER_assume(sec_r000127_17_1 != sec_r000127_17_2);
  __CPROVER_assume(sec_r000127_19_1 != sec_r000127_19_2);
  __CPROVER_assume(pub_r000127_6_1 == pub_r000127_6_2);
  __CPROVER_assume(sec_r000127_3_1 != sec_r000127_3_2);
  __CPROVER_assume(pub_r000127_4_1 == pub_r000127_4_2);
  __CPROVER_assume(pub_r000127_2_1 == pub_r000127_2_2);
  __CPROVER_assume(pub_r000127_13_1 == pub_r000127_13_2);
  __CPROVER_assume(sec_r000127_4_1 != sec_r000127_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.threshold == st_var_3_2.threshold);
  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.gain == st_var_3_2.gain);
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
}


