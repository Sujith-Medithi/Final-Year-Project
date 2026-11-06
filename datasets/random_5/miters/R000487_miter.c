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
struct DeviceConfig_R000487_8713_0
{
  unsigned char stop_bits;
  short baud_rate;
  unsigned char port;
  unsigned char id;
  int parity;
  int buffer[3];
};
struct EventLog_R000487_8713_1
{
  int severity;
  int seq;
  short code;
  unsigned char signature;
  int buffer[3];
};
struct SensorNode_R000487_8713_2
{
  unsigned char status;
  unsigned char offset;
  short gain;
  unsigned char reading;
  unsigned char threshold;
  unsigned char calib;
  int buffer[3];
};
union PacketPayload_R000487_8713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000487_8713_1
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
void fn_R000487_8713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st_1 = {0};
  struct SensorNode_R000487_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int anchor_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_37_1 > 14)
  {
    acc_1 = ((acc_1 + (anchor_37_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_37_2 > 14)
  {
    acc_2 = ((acc_2 + (anchor_37_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_10_1)
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

  switch (anchor_10_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_37_1 == anchor_37_2);
  assert(anchor_10_1 == anchor_10_2);
}

int fn_R000487_8713_0(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int anchor_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_37 > 14)
  {
    acc = ((acc + (anchor_37 * 2)) + 5) & 127;
    aux ^= anchor_37 & 15;
  }
  else
  {
    acc = ((acc - anchor_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_10 = (aux + st.buffer[1]) & 3;
  switch (anchor_10)
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

void fn_R000487_8713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st_1 = {0};
  struct SensorNode_R000487_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_57_1) & 63;
  aux_2 = (aux_2 + window_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_67_1)
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

  switch (anchor_67_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_57_1 == window_57_2);
  assert(anchor_67_1 == anchor_67_2);
}

int fn_R000487_8713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_57) & 63;
  acc ^= aux;
  int anchor_67 = (aux + st.buffer[1]) & 3;
  switch (anchor_67)
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

void fn_R000487_8713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st_1 = {0};
  struct SensorNode_R000487_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int accumulator_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_21_1 > 25)
  {
    acc_1 = ((acc_1 + (accumulator_21_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_21_2 > 25)
  {
    acc_2 = ((acc_2 + (accumulator_21_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_30_1)
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

  switch (quantum_30_2)
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

  int delta_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_46_1) & 63;
  aux_2 = (aux_2 + delta_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_21_1 == accumulator_21_2);
  assert(quantum_30_1 == quantum_30_2);
  assert(delta_46_1 == delta_46_2);
}

int fn_R000487_8713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int accumulator_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_21 > 25)
  {
    acc = ((acc + (accumulator_21 * 2)) + 5) & 127;
    aux ^= accumulator_21 & 15;
  }
  else
  {
    acc = ((acc - accumulator_21) + 11) & 127;
    aux += 3;
  }
  int quantum_30 = (aux + st.buffer[1]) & 3;
  switch (quantum_30)
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

  int delta_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000487_8713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st_1 = {0};
  struct DeviceConfig_R000487_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int coefficient_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_39_1)
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

  switch (coefficient_39_2)
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

  int quantum_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_86_1) & 63;
  aux_2 = (aux_2 + quantum_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_15_1 = local_arr_1[aux_1 % 3];
  int tally_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_39_1 == coefficient_39_2);
  assert(quantum_86_1 == quantum_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_15_1 == tally_15_2);
}

int fn_R000487_8713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int coefficient_39 = (aux + st.buffer[1]) & 3;
  switch (coefficient_39)
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

  int quantum_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_86) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_15 = local_arr[aux % 3];
  acc = (acc + (tally_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000487_8713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st_1 = {0};
  struct SensorNode_R000487_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_25_1 = local_arr_1[aux_1 % 3];
  int weight_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_25_2 * 2)) & 127;
  int index_reg_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_68_1 > 27)
  {
    acc_1 = ((acc_1 + (index_reg_68_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_68_2 > 27)
  {
    acc_2 = ((acc_2 + (index_reg_68_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_29_1)
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

  switch (coefficient_29_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_25_1 == weight_25_2);
  assert(index_reg_68_1 == index_reg_68_2);
  assert(coefficient_29_1 == coefficient_29_2);
}

int fn_R000487_8713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_25 = local_arr[aux % 3];
  acc = (acc + (weight_25 * 2)) & 127;
  int index_reg_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_68 > 27)
  {
    acc = ((acc + (index_reg_68 * 2)) + 5) & 127;
    aux ^= index_reg_68 & 15;
  }
  else
  {
    acc = ((acc - index_reg_68) + 11) & 127;
    aux += 3;
  }
  int coefficient_29 = (aux + st.buffer[1]) & 3;
  switch (coefficient_29)
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

void fn_R000487_8713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st_1 = {0};
  struct EventLog_R000487_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_87_1 = local_arr_1[aux_1 % 3];
  int residue_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_87_2 * 2)) & 127;
  int sample_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_41_1 > 18)
  {
    acc_1 = ((acc_1 + (sample_41_1 * 2)) + 5) & 127;
    aux_1 ^= sample_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_41_2 > 18)
  {
    acc_2 = ((acc_2 + (sample_41_2 * 2)) + 5) & 127;
    aux_2 ^= sample_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_87_1 == residue_87_2);
  assert(sample_41_1 == sample_41_2);
}

int fn_R000487_8713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int residue_87 = local_arr[aux % 3];
  acc = (acc + (residue_87 * 2)) & 127;
  int sample_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_41 > 18)
  {
    acc = ((acc + (sample_41 * 2)) + 5) & 127;
    aux ^= sample_41 & 15;
  }
  else
  {
    acc = ((acc - sample_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000487_8713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st_1 = {0};
  struct EventLog_R000487_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int factor_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_14_1 > 13)
  {
    acc_1 = ((acc_1 + (factor_14_1 * 2)) + 5) & 127;
    aux_1 ^= factor_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_14_2 > 13)
  {
    acc_2 = ((acc_2 + (factor_14_2 * 2)) + 5) & 127;
    aux_2 ^= factor_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_54_1 = local_arr_1[aux_1 % 3];
  int anchor_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_14_1 == factor_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_54_1 == anchor_54_2);
}

int fn_R000487_8713_6(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int factor_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_14 > 13)
  {
    acc = ((acc + (factor_14 * 2)) + 5) & 127;
    aux ^= factor_14 & 15;
  }
  else
  {
    acc = ((acc - factor_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_54 = local_arr[aux % 3];
  acc = (acc + (anchor_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000487_8713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st_1 = {0};
  struct DeviceConfig_R000487_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int vector_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_22_1) & 63;
  aux_2 = (aux_2 + vector_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_29_1 > 32)
  {
    acc_1 = ((acc_1 + (accumulator_29_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_29_2 > 32)
  {
    acc_2 = ((acc_2 + (accumulator_29_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_41_1 = local_arr_1[aux_1 % 3];
  int anchor_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_41_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_22_1 == vector_22_2);
  assert(accumulator_29_1 == accumulator_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_41_1 == anchor_41_2);
}

int fn_R000487_8713_7(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int vector_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_22) & 63;
  acc ^= aux;
  int accumulator_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_29 > 32)
  {
    acc = ((acc + (accumulator_29 * 2)) + 5) & 127;
    aux ^= accumulator_29 & 15;
  }
  else
  {
    acc = ((acc - accumulator_29) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_41 = local_arr[aux % 3];
  acc = (acc + (anchor_41 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000487_8713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st_1 = {0};
  struct DeviceConfig_R000487_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int sample_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_58_1 > 28)
  {
    acc_1 = ((acc_1 + (sample_58_1 * 2)) + 5) & 127;
    aux_1 ^= sample_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_58_2 > 28)
  {
    acc_2 = ((acc_2 + (sample_58_2 * 2)) + 5) & 127;
    aux_2 ^= sample_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_58_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_62_1 = local_arr_1[aux_1 % 3];
  int quotient_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_62_2 * 2)) & 127;
  int stride_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_71_1)
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

  switch (stride_71_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_58_1 == sample_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_62_1 == quotient_62_2);
  assert(stride_71_1 == stride_71_2);
}

int fn_R000487_8713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int sample_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_58 > 28)
  {
    acc = ((acc + (sample_58 * 2)) + 5) & 127;
    aux ^= sample_58 & 15;
  }
  else
  {
    acc = ((acc - sample_58) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_62 = local_arr[aux % 3];
  acc = (acc + (quotient_62 * 2)) & 127;
  int stride_71 = (aux + st.buffer[1]) & 3;
  switch (stride_71)
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

void fn_R000487_8713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st_1 = {0};
  struct DeviceConfig_R000487_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int window_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_13_1 > 34)
  {
    acc_1 = ((acc_1 + (window_13_1 * 2)) + 5) & 127;
    aux_1 ^= window_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_13_2 > 34)
  {
    acc_2 = ((acc_2 + (window_13_2 * 2)) + 5) & 127;
    aux_2 ^= window_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_22_1 = local_arr_1[aux_1 % 3];
  int metric_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_13_1 == window_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_22_1 == metric_22_2);
}

int fn_R000487_8713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int window_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_13 > 34)
  {
    acc = ((acc + (window_13 * 2)) + 5) & 127;
    aux ^= window_13 & 15;
  }
  else
  {
    acc = ((acc - window_13) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_22 = local_arr[aux % 3];
  acc = (acc + (metric_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000487_8713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st_1 = {0};
  struct SensorNode_R000487_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int scale_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_29_1 > 37)
  {
    acc_1 = ((acc_1 + (scale_29_1 * 2)) + 5) & 127;
    aux_1 ^= scale_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_29_2 > 37)
  {
    acc_2 = ((acc_2 + (scale_29_2 * 2)) + 5) & 127;
    aux_2 ^= scale_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_12_1)
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

  switch (anchor_12_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_29_1 == scale_29_2);
  assert(anchor_12_1 == anchor_12_2);
}

int fn_R000487_8713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int scale_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_29 > 37)
  {
    acc = ((acc + (scale_29 * 2)) + 5) & 127;
    aux ^= scale_29 & 15;
  }
  else
  {
    acc = ((acc - scale_29) + 11) & 127;
    aux += 3;
  }
  int anchor_12 = (aux + st.buffer[1]) & 3;
  switch (anchor_12)
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

void fn_R000487_8713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st_1 = {0};
  struct DeviceConfig_R000487_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int threshold_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_89_1)
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

  switch (threshold_89_2)
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

  int quantum_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_76_1 > 14)
  {
    acc_1 = ((acc_1 + (quantum_76_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_76_2 > 14)
  {
    acc_2 = ((acc_2 + (quantum_76_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_76_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_89_1 == threshold_89_2);
  assert(quantum_76_1 == quantum_76_2);
}

int fn_R000487_8713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000487_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int threshold_89 = (aux + st.buffer[1]) & 3;
  switch (threshold_89)
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

  int quantum_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_76 > 14)
  {
    acc = ((acc + (quantum_76 * 2)) + 5) & 127;
    aux ^= quantum_76 & 15;
  }
  else
  {
    acc = ((acc - quantum_76) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000487_8713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st_1 = {0};
  struct EventLog_R000487_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int parity_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_90_1)
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

  switch (parity_90_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_33_1) & 63;
  aux_2 = (aux_2 + parity_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_34_1 > 50)
  {
    acc_1 = ((acc_1 + (metric_34_1 * 2)) + 5) & 127;
    aux_1 ^= metric_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_34_2 > 50)
  {
    acc_2 = ((acc_2 + (metric_34_2 * 2)) + 5) & 127;
    aux_2 ^= metric_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_90_1 == parity_90_2);
  assert(parity_33_1 == parity_33_2);
  assert(metric_34_1 == metric_34_2);
}

int fn_R000487_8713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int parity_90 = (aux + st.buffer[1]) & 3;
  switch (parity_90)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_33) & 63;
  acc ^= aux;
  int metric_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_34 > 50)
  {
    acc = ((acc + (metric_34 * 2)) + 5) & 127;
    aux ^= metric_34 & 15;
  }
  else
  {
    acc = ((acc - metric_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000487_8713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st_1 = {0};
  struct SensorNode_R000487_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int anchor_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_76_1) & 63;
  aux_2 = (aux_2 + anchor_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_35_1)
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

  switch (scale_35_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_22_1 > 25)
  {
    acc_1 = ((acc_1 + (parity_22_1 * 2)) + 5) & 127;
    aux_1 ^= parity_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_22_2 > 25)
  {
    acc_2 = ((acc_2 + (parity_22_2 * 2)) + 5) & 127;
    aux_2 ^= parity_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_76_1 == anchor_76_2);
  assert(scale_35_1 == scale_35_2);
  assert(parity_22_1 == parity_22_2);
}

int fn_R000487_8713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int anchor_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_76) & 63;
  acc ^= aux;
  int scale_35 = (aux + st.buffer[1]) & 3;
  switch (scale_35)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_22 > 25)
  {
    acc = ((acc + (parity_22 * 2)) + 5) & 127;
    aux ^= parity_22 & 15;
  }
  else
  {
    acc = ((acc - parity_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000487_8713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st_1 = {0};
  struct EventLog_R000487_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_87_1 = local_arr_1[aux_1 % 3];
  int vector_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_87_2 * 2)) & 127;
  int phase_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_82_1 > 36)
  {
    acc_1 = ((acc_1 + (phase_82_1 * 2)) + 5) & 127;
    aux_1 ^= phase_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_82_2 > 36)
  {
    acc_2 = ((acc_2 + (phase_82_2 * 2)) + 5) & 127;
    aux_2 ^= phase_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_57_1)
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

  switch (margin_57_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_87_1 == vector_87_2);
  assert(phase_82_1 == phase_82_2);
  assert(margin_57_1 == margin_57_2);
}

int fn_R000487_8713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int vector_87 = local_arr[aux % 3];
  acc = (acc + (vector_87 * 2)) & 127;
  int phase_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_82 > 36)
  {
    acc = ((acc + (phase_82 * 2)) + 5) & 127;
    aux ^= phase_82 & 15;
  }
  else
  {
    acc = ((acc - phase_82) + 11) & 127;
    aux += 3;
  }
  int margin_57 = (aux + st.buffer[1]) & 3;
  switch (margin_57)
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

void fn_R000487_8713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st_1 = {0};
  struct EventLog_R000487_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_11_1 = local_arr_1[aux_1 % 3];
  int index_reg_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_11_2 * 2)) & 127;
  int stride_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_73_1)
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

  switch (stride_73_2)
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

  int residue_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_52_1) & 63;
  aux_2 = (aux_2 + residue_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_11_1 == index_reg_11_2);
  assert(stride_73_1 == stride_73_2);
  assert(residue_52_1 == residue_52_2);
}

int fn_R000487_8713_15(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int index_reg_11 = local_arr[aux % 3];
  acc = (acc + (index_reg_11 * 2)) & 127;
  int stride_73 = (aux + st.buffer[1]) & 3;
  switch (stride_73)
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

  int residue_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000487_8713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st_1 = {0};
  struct EventLog_R000487_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int vector_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_78_1 > 48)
  {
    acc_1 = ((acc_1 + (vector_78_1 * 2)) + 5) & 127;
    aux_1 ^= vector_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_78_2 > 48)
  {
    acc_2 = ((acc_2 + (vector_78_2 * 2)) + 5) & 127;
    aux_2 ^= vector_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_73_1 = local_arr_1[aux_1 % 3];
  int offset_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_73_2 * 2)) & 127;
  int quotient_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_81_1) & 63;
  aux_2 = (aux_2 + quotient_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_96_1)
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

  switch (mask_96_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_78_1 == vector_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_73_1 == offset_73_2);
  assert(quotient_81_1 == quotient_81_2);
  assert(mask_96_1 == mask_96_2);
}

int fn_R000487_8713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int vector_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_78 > 48)
  {
    acc = ((acc + (vector_78 * 2)) + 5) & 127;
    aux ^= vector_78 & 15;
  }
  else
  {
    acc = ((acc - vector_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_73 = local_arr[aux % 3];
  acc = (acc + (offset_73 * 2)) & 127;
  int quotient_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_81) & 63;
  acc ^= aux;
  int mask_96 = (aux + st.buffer[1]) & 3;
  switch (mask_96)
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

void fn_R000487_8713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st_1 = {0};
  struct SensorNode_R000487_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int damping_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_17_1 > 35)
  {
    acc_1 = ((acc_1 + (damping_17_1 * 2)) + 5) & 127;
    aux_1 ^= damping_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_17_2 > 35)
  {
    acc_2 = ((acc_2 + (damping_17_2 * 2)) + 5) & 127;
    aux_2 ^= damping_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_92_1 = local_arr_1[aux_1 % 3];
  int metric_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_17_1 == damping_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_92_1 == metric_92_2);
}

int fn_R000487_8713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000487_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int damping_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_17 > 35)
  {
    acc = ((acc + (damping_17 * 2)) + 5) & 127;
    aux ^= damping_17 & 15;
  }
  else
  {
    acc = ((acc - damping_17) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_92 = local_arr[aux % 3];
  acc = (acc + (metric_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000487_8713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st_1 = {0};
  struct EventLog_R000487_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int coefficient_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_78_1)
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

  switch (coefficient_78_2)
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
  int scale_51_1 = local_arr_1[aux_1 % 3];
  int scale_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_51_2 * 2)) & 127;
  int quantum_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_68_1) & 63;
  aux_2 = (aux_2 + quantum_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_78_1 == coefficient_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_51_1 == scale_51_2);
  assert(quantum_68_1 == quantum_68_2);
}

int fn_R000487_8713_18(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int coefficient_78 = (aux + st.buffer[1]) & 3;
  switch (coefficient_78)
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
  int scale_51 = local_arr[aux % 3];
  acc = (acc + (scale_51 * 2)) & 127;
  int quantum_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_68) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000487_8713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st_1 = {0};
  struct EventLog_R000487_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int threshold_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_35_1) & 63;
  aux_2 = (aux_2 + threshold_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_63_1 > 13)
  {
    acc_1 = ((acc_1 + (stride_63_1 * 2)) + 5) & 127;
    aux_1 ^= stride_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_63_2 > 13)
  {
    acc_2 = ((acc_2 + (stride_63_2 * 2)) + 5) & 127;
    aux_2 ^= stride_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_63_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_35_1 == threshold_35_2);
  assert(stride_63_1 == stride_63_2);
}

int fn_R000487_8713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000487_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int threshold_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_35) & 63;
  acc ^= aux;
  int stride_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_63 > 13)
  {
    acc = ((acc + (stride_63 * 2)) + 5) & 127;
    aux ^= stride_63 & 15;
  }
  else
  {
    acc = ((acc - stride_63) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000487_0_1;
  int sec_r000487_0_2;
  int sec_r000487_1_1;
  int sec_r000487_1_2;
  int sec_r000487_2_1;
  int sec_r000487_2_2;
  int sec_r000487_3_1;
  int sec_r000487_3_2;
  int sec_r000487_4_1;
  int sec_r000487_4_2;
  int sec_r000487_5_1;
  int sec_r000487_5_2;
  int sec_r000487_6_1;
  int sec_r000487_6_2;
  int sec_r000487_7_1;
  int sec_r000487_7_2;
  int sec_r000487_8_1;
  int sec_r000487_8_2;
  int sec_r000487_9_1;
  int sec_r000487_9_2;
  int sec_r000487_10_1;
  int sec_r000487_10_2;
  int sec_r000487_11_1;
  int sec_r000487_11_2;
  int sec_r000487_12_1;
  int sec_r000487_12_2;
  int sec_r000487_13_1;
  int sec_r000487_13_2;
  int sec_r000487_14_1;
  int sec_r000487_14_2;
  int sec_r000487_15_1;
  int sec_r000487_15_2;
  int pub_r000487_0_1;
  int pub_r000487_0_2;
  int pub_r000487_1_1;
  int pub_r000487_1_2;
  int pub_r000487_2_1;
  int pub_r000487_2_2;
  int pub_r000487_3_1;
  int pub_r000487_3_2;
  int pub_r000487_4_1;
  int pub_r000487_4_2;
  int pub_r000487_5_1;
  int pub_r000487_5_2;
  int pub_r000487_6_1;
  int pub_r000487_6_2;
  int pub_r000487_7_1;
  int pub_r000487_7_2;
  int pub_r000487_8_1;
  int pub_r000487_8_2;
  int pub_r000487_9_1;
  int pub_r000487_9_2;
  int pub_r000487_10_1;
  int pub_r000487_10_2;
  int pub_r000487_11_1;
  int pub_r000487_11_2;
  int pub_r000487_12_1;
  int pub_r000487_12_2;
  int pub_r000487_13_1;
  int pub_r000487_13_2;
  int pub_r000487_14_1;
  int pub_r000487_14_2;
  int pub_r000487_15_1;
  int pub_r000487_15_2;
  int pub_r000487_16_1;
  int pub_r000487_16_2;
  int pub_r000487_17_1;
  int pub_r000487_17_2;
  int pub_r000487_18_1;
  int pub_r000487_18_2;
  int pub_r000487_19_1;
  int pub_r000487_19_2;
  int pub_r000487_20_1;
  int pub_r000487_20_2;
  int pub_r000487_21_1;
  int pub_r000487_21_2;
  int pub_r000487_22_1;
  int pub_r000487_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000487_0_1 >= (-100)) && (pub_r000487_0_1 <= 100));
  __CPROVER_assume((pub_r000487_0_2 >= (-100)) && (pub_r000487_0_2 <= 100));
  __CPROVER_assume((pub_r000487_1_1 >= (-100)) && (pub_r000487_1_1 <= 100));
  __CPROVER_assume((pub_r000487_1_2 >= (-100)) && (pub_r000487_1_2 <= 100));
  __CPROVER_assume((pub_r000487_2_1 >= (-100)) && (pub_r000487_2_1 <= 100));
  __CPROVER_assume((pub_r000487_2_2 >= (-100)) && (pub_r000487_2_2 <= 100));
  __CPROVER_assume((pub_r000487_3_1 >= (-100)) && (pub_r000487_3_1 <= 100));
  __CPROVER_assume((pub_r000487_3_2 >= (-100)) && (pub_r000487_3_2 <= 100));
  __CPROVER_assume((pub_r000487_4_1 >= (-100)) && (pub_r000487_4_1 <= 100));
  __CPROVER_assume((pub_r000487_4_2 >= (-100)) && (pub_r000487_4_2 <= 100));
  __CPROVER_assume((pub_r000487_5_1 >= (-100)) && (pub_r000487_5_1 <= 100));
  __CPROVER_assume((pub_r000487_5_2 >= (-100)) && (pub_r000487_5_2 <= 100));
  __CPROVER_assume((pub_r000487_6_1 >= (-100)) && (pub_r000487_6_1 <= 100));
  __CPROVER_assume((pub_r000487_6_2 >= (-100)) && (pub_r000487_6_2 <= 100));
  __CPROVER_assume((pub_r000487_7_1 >= (-100)) && (pub_r000487_7_1 <= 100));
  __CPROVER_assume((pub_r000487_7_2 >= (-100)) && (pub_r000487_7_2 <= 100));
  __CPROVER_assume((pub_r000487_8_1 >= (-100)) && (pub_r000487_8_1 <= 100));
  __CPROVER_assume((pub_r000487_8_2 >= (-100)) && (pub_r000487_8_2 <= 100));
  __CPROVER_assume((pub_r000487_9_1 >= (-100)) && (pub_r000487_9_1 <= 100));
  __CPROVER_assume((pub_r000487_9_2 >= (-100)) && (pub_r000487_9_2 <= 100));
  __CPROVER_assume((pub_r000487_10_1 >= (-100)) && (pub_r000487_10_1 <= 100));
  __CPROVER_assume((pub_r000487_10_2 >= (-100)) && (pub_r000487_10_2 <= 100));
  __CPROVER_assume((pub_r000487_11_1 >= (-100)) && (pub_r000487_11_1 <= 100));
  __CPROVER_assume((pub_r000487_11_2 >= (-100)) && (pub_r000487_11_2 <= 100));
  __CPROVER_assume((pub_r000487_12_1 >= (-100)) && (pub_r000487_12_1 <= 100));
  __CPROVER_assume((pub_r000487_12_2 >= (-100)) && (pub_r000487_12_2 <= 100));
  __CPROVER_assume((pub_r000487_13_1 >= (-100)) && (pub_r000487_13_1 <= 100));
  __CPROVER_assume((pub_r000487_13_2 >= (-100)) && (pub_r000487_13_2 <= 100));
  __CPROVER_assume((pub_r000487_14_1 >= (-100)) && (pub_r000487_14_1 <= 100));
  __CPROVER_assume((pub_r000487_14_2 >= (-100)) && (pub_r000487_14_2 <= 100));
  __CPROVER_assume((pub_r000487_15_1 >= (-100)) && (pub_r000487_15_1 <= 100));
  __CPROVER_assume((pub_r000487_15_2 >= (-100)) && (pub_r000487_15_2 <= 100));
  __CPROVER_assume((pub_r000487_16_1 >= (-100)) && (pub_r000487_16_1 <= 100));
  __CPROVER_assume((pub_r000487_16_2 >= (-100)) && (pub_r000487_16_2 <= 100));
  __CPROVER_assume((pub_r000487_17_1 >= (-100)) && (pub_r000487_17_1 <= 100));
  __CPROVER_assume((pub_r000487_17_2 >= (-100)) && (pub_r000487_17_2 <= 100));
  __CPROVER_assume((pub_r000487_18_1 >= (-100)) && (pub_r000487_18_1 <= 100));
  __CPROVER_assume((pub_r000487_18_2 >= (-100)) && (pub_r000487_18_2 <= 100));
  __CPROVER_assume((pub_r000487_19_1 >= (-100)) && (pub_r000487_19_1 <= 100));
  __CPROVER_assume((pub_r000487_19_2 >= (-100)) && (pub_r000487_19_2 <= 100));
  __CPROVER_assume((pub_r000487_20_1 >= (-100)) && (pub_r000487_20_1 <= 100));
  __CPROVER_assume((pub_r000487_20_2 >= (-100)) && (pub_r000487_20_2 <= 100));
  __CPROVER_assume((pub_r000487_21_1 >= (-100)) && (pub_r000487_21_1 <= 100));
  __CPROVER_assume((pub_r000487_21_2 >= (-100)) && (pub_r000487_21_2 <= 100));
  __CPROVER_assume((pub_r000487_22_1 >= (-100)) && (pub_r000487_22_1 <= 100));
  __CPROVER_assume((pub_r000487_22_2 >= (-100)) && (pub_r000487_22_2 <= 100));
  __CPROVER_assume((sec_r000487_0_1 >= 0) && (sec_r000487_0_1 <= 255));
  __CPROVER_assume((sec_r000487_0_2 >= 0) && (sec_r000487_0_2 <= 255));
  __CPROVER_assume((sec_r000487_1_1 >= 0) && (sec_r000487_1_1 <= 255));
  __CPROVER_assume((sec_r000487_1_2 >= 0) && (sec_r000487_1_2 <= 255));
  __CPROVER_assume((sec_r000487_2_1 >= 0) && (sec_r000487_2_1 <= 255));
  __CPROVER_assume((sec_r000487_2_2 >= 0) && (sec_r000487_2_2 <= 255));
  __CPROVER_assume((sec_r000487_3_1 >= 0) && (sec_r000487_3_1 <= 255));
  __CPROVER_assume((sec_r000487_3_2 >= 0) && (sec_r000487_3_2 <= 255));
  __CPROVER_assume((sec_r000487_4_1 >= 0) && (sec_r000487_4_1 <= 255));
  __CPROVER_assume((sec_r000487_4_2 >= 0) && (sec_r000487_4_2 <= 255));
  __CPROVER_assume((sec_r000487_5_1 >= 0) && (sec_r000487_5_1 <= 255));
  __CPROVER_assume((sec_r000487_5_2 >= 0) && (sec_r000487_5_2 <= 255));
  __CPROVER_assume((sec_r000487_6_1 >= 0) && (sec_r000487_6_1 <= 255));
  __CPROVER_assume((sec_r000487_6_2 >= 0) && (sec_r000487_6_2 <= 255));
  __CPROVER_assume((sec_r000487_7_1 >= 0) && (sec_r000487_7_1 <= 255));
  __CPROVER_assume((sec_r000487_7_2 >= 0) && (sec_r000487_7_2 <= 255));
  __CPROVER_assume((sec_r000487_8_1 >= 0) && (sec_r000487_8_1 <= 255));
  __CPROVER_assume((sec_r000487_8_2 >= 0) && (sec_r000487_8_2 <= 255));
  __CPROVER_assume((sec_r000487_9_1 >= 0) && (sec_r000487_9_1 <= 255));
  __CPROVER_assume((sec_r000487_9_2 >= 0) && (sec_r000487_9_2 <= 255));
  __CPROVER_assume((sec_r000487_10_1 >= 0) && (sec_r000487_10_1 <= 255));
  __CPROVER_assume((sec_r000487_10_2 >= 0) && (sec_r000487_10_2 <= 255));
  __CPROVER_assume((sec_r000487_11_1 >= 0) && (sec_r000487_11_1 <= 255));
  __CPROVER_assume((sec_r000487_11_2 >= 0) && (sec_r000487_11_2 <= 255));
  __CPROVER_assume((sec_r000487_12_1 >= 0) && (sec_r000487_12_1 <= 255));
  __CPROVER_assume((sec_r000487_12_2 >= 0) && (sec_r000487_12_2 <= 255));
  __CPROVER_assume((sec_r000487_13_1 >= 0) && (sec_r000487_13_1 <= 255));
  __CPROVER_assume((sec_r000487_13_2 >= 0) && (sec_r000487_13_2 <= 255));
  __CPROVER_assume((sec_r000487_14_1 >= 0) && (sec_r000487_14_1 <= 255));
  __CPROVER_assume((sec_r000487_14_2 >= 0) && (sec_r000487_14_2 <= 255));
  __CPROVER_assume((sec_r000487_15_1 >= 0) && (sec_r000487_15_1 <= 255));
  __CPROVER_assume((sec_r000487_15_2 >= 0) && (sec_r000487_15_2 <= 255));
  struct DeviceConfig_R000487_8713_0 st_var_0_1 = {0};
  struct DeviceConfig_R000487_8713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000487_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000487_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000487_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000487_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000487_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000487_0_2 + 7) & 15;
  struct EventLog_R000487_8713_1 st_var_1_1 = {0};
  struct EventLog_R000487_8713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000487_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000487_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000487_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000487_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000487_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000487_0_2 + 9) & 15;
  struct SensorNode_R000487_8713_2 st_var_2_1 = {0};
  struct SensorNode_R000487_8713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000487_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000487_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000487_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000487_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000487_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000487_0_2 + 11) & 15;
  union PacketPayload_R000487_8713_0 u_var_1;
  union PacketPayload_R000487_8713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 27)
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
  if (stage_v_0_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 27)
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
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
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
  if (stage_v_5_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 28)
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
  if (stage_v_5_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 28)
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
  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 47)
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
  if (stage_v_6_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 47)
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
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 47)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 47)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((st_var_0_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_0_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 30)
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
  if (stage_v_9_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 30)
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
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

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
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = ((st_var_1_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_1_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 39)
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
  if (stage_v_22_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 39)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 55)
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
  if (stage_v_24_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 55)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 33) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 45)
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
  if (stage_v_38_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 45)
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
  int stage_v_39_1 = ((st_var_0_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_0_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 53)
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
  if (stage_v_39_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 53)
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
  int stage_v_40_1 = ((st_var_1_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_1_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 26)
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
  if (stage_v_40_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 26)
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
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_43_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_45_1 = ((st_var_0_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_0_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 51)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 51)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_46_1 = ((st_var_1_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_1_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 52)
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
  if (stage_v_46_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 52)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 48) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 48) & 15;
  int stage_v_47_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_47_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= stage_v_47_1;
  chk_sum_2 ^= stage_v_47_2;
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
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 40)
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
  if (stage_v_50_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 40)
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
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 55) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
  int stage_v_56_1 = table_1[0];
  int stage_v_56_2 = table_2[0];
  table_1[0] = (table_1[1] + 113) & 63;
  table_2[0] = (table_2[1] + 113) & 63;
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
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000487_11_1 & 1) != 0)
  {
    if ((sec_r000487_8_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000487_4_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000487_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000487_4_1 + 7) & 127;
  }
  if ((sec_r000487_11_2 & 1) != 0)
  {
    if ((sec_r000487_8_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000487_4_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000487_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000487_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000487_2_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000487_19_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000487_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000487_19_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000487_2_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000487_19_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000487_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000487_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000487_12_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000487_12_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000487_6_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000487_0_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000487_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000487_0_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000487_6_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000487_0_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000487_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000487_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000487_14_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000487_11_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000487_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000487_11_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000487_14_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000487_11_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000487_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000487_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000487_11_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000487_19_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000487_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000487_19_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000487_11_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000487_19_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000487_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000487_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000487_7_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000487_6_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000487_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000487_6_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000487_7_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000487_6_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000487_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000487_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000487_1_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000487_6_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000487_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000487_6_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000487_1_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000487_6_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000487_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000487_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000487_22_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000487_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000487_22_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000487_22_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000487_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000487_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000487_15_1 & 1) != 0)
  {
    if ((sec_r000487_13_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000487_1_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000487_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000487_1_1 + 7) & 127;
  }
  if ((sec_r000487_15_2 & 1) != 0)
  {
    if ((sec_r000487_13_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000487_1_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000487_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000487_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000487_13_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000487_17_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000487_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000487_17_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000487_13_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000487_17_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000487_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000487_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000487_7_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000487_13_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000487_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000487_13_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000487_7_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000487_13_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000487_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000487_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000487_8_1 & 1) != 0)
  {
    if ((sec_r000487_7_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000487_16_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000487_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000487_16_1 + 7) & 127;
  }
  if ((sec_r000487_8_2 & 1) != 0)
  {
    if ((sec_r000487_7_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000487_16_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000487_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000487_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000487_14_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000487_3_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000487_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000487_3_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000487_14_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000487_3_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000487_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000487_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000487_14_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000487_0_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000487_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000487_0_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000487_14_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000487_0_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000487_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000487_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000487_13_1 & 1) != 0)
  {
    if ((sec_r000487_7_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000487_1_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000487_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000487_1_1 + 7) & 127;
  }
  if ((sec_r000487_13_2 & 1) != 0)
  {
    if ((sec_r000487_7_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000487_1_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000487_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000487_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000487_19_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000487_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000487_19_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000487_19_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000487_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000487_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000487_12_1 & 1) != 0)
  {
    if ((sec_r000487_11_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((sec_r000487_12_2 & 1) != 0)
  {
    if ((sec_r000487_11_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000487_4_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000487_4_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000487_13_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000487_3_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000487_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000487_3_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000487_13_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000487_3_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000487_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000487_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000487_0_1 & 1) != 0)
  {
    if ((sec_r000487_3_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((sec_r000487_0_2 & 1) != 0)
  {
    if ((sec_r000487_3_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000487_0_1 & 1) != 0)
  {
    if ((sec_r000487_14_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000487_5_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000487_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000487_5_1 + 7) & 127;
  }
  if ((sec_r000487_0_2 & 1) != 0)
  {
    if ((sec_r000487_14_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000487_5_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000487_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000487_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000487_14_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000487_2_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000487_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000487_2_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000487_14_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000487_2_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000487_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000487_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000487_9_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000487_21_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000487_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000487_21_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000487_9_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000487_21_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000487_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000487_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000487_1_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000487_1_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000487_15_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000487_22_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000487_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000487_22_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000487_15_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000487_22_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000487_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000487_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000487_4_1 & 1) != 0)
  {
    if ((sec_r000487_4_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000487_13_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000487_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000487_13_1 + 7) & 127;
  }
  if ((sec_r000487_4_2 & 1) != 0)
  {
    if ((sec_r000487_4_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000487_13_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000487_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000487_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000487_13_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000487_11_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000487_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000487_11_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000487_13_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000487_11_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000487_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000487_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000487_2_1 & 1) != 0)
  {
    if ((sec_r000487_4_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000487_22_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000487_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000487_22_1 + 7) & 127;
  }
  if ((sec_r000487_2_2 & 1) != 0)
  {
    if ((sec_r000487_4_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000487_22_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000487_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000487_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000487_14_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000487_20_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000487_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000487_20_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000487_14_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000487_20_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000487_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000487_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000487_7_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000487_5_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000487_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000487_5_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000487_7_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000487_5_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000487_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000487_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000487_7_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000487_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000487_7_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000487_7_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000487_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000487_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000487_4_1 & 1) != 0)
  {
    if ((sec_r000487_1_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000487_3_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000487_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000487_3_1 + 7) & 127;
  }
  if ((sec_r000487_4_2 & 1) != 0)
  {
    if ((sec_r000487_1_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000487_3_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000487_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000487_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000487_15_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000487_1_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000487_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000487_1_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000487_15_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000487_1_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000487_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000487_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000487_8_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000487_19_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000487_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000487_19_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000487_8_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000487_19_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000487_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000487_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000487_22_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000487_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000487_22_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000487_22_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000487_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000487_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000487_1_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000487_2_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000487_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000487_2_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000487_1_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000487_2_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000487_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000487_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000487_5_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000487_9_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000487_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000487_9_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000487_5_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000487_9_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000487_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000487_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000487_13_1 & 1) != 0)
  {
    if ((sec_r000487_2_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((sec_r000487_13_2 & 1) != 0)
  {
    if ((sec_r000487_2_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000487_3_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000487_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000487_3_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000487_3_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000487_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000487_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000487_14_1 & 1) != 0)
  {
    if ((sec_r000487_11_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000487_6_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000487_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000487_6_1 + 7) & 127;
  }
  if ((sec_r000487_14_2 & 1) != 0)
  {
    if ((sec_r000487_11_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000487_6_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000487_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000487_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000487_1_1 & 1) != 0)
  {
    if ((sec_r000487_7_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000487_6_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000487_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000487_6_1 + 7) & 127;
  }
  if ((sec_r000487_1_2 & 1) != 0)
  {
    if ((sec_r000487_7_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000487_6_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000487_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000487_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000487_8_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000487_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000487_8_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000487_8_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000487_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000487_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000487_12_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000487_9_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000487_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000487_9_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000487_12_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000487_9_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000487_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000487_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000487_12_1 & 1) != 0)
  {
    if ((sec_r000487_13_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000487_5_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000487_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000487_5_1 + 7) & 127;
  }
  if ((sec_r000487_12_2 & 1) != 0)
  {
    if ((sec_r000487_13_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000487_5_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000487_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000487_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000487_13_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000487_19_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000487_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000487_19_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000487_13_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000487_19_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000487_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000487_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000487_4_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000487_2_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000487_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000487_2_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000487_4_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000487_2_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000487_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000487_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000487_5_1 & 1) != 0)
  {
    if ((sec_r000487_7_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000487_0_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000487_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000487_0_1 + 7) & 127;
  }
  if ((sec_r000487_5_2 & 1) != 0)
  {
    if ((sec_r000487_7_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000487_0_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000487_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000487_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000487_11_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000487_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000487_11_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000487_11_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000487_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000487_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000487_20_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000487_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000487_20_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000487_20_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000487_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000487_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000487_5_1 & 1) != 0)
  {
    if ((sec_r000487_5_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000487_22_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000487_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000487_22_1 + 7) & 127;
  }
  if ((sec_r000487_5_2 & 1) != 0)
  {
    if ((sec_r000487_5_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000487_22_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000487_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000487_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000487_11_1 & 1) != 0)
  {
    if ((sec_r000487_8_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000487_11_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000487_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000487_11_1 + 7) & 127;
  }
  if ((sec_r000487_11_2 & 1) != 0)
  {
    if ((sec_r000487_8_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000487_11_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000487_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000487_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000487_4_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000487_22_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000487_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000487_22_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000487_4_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000487_22_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000487_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000487_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000487_15_1 & 1) != 0)
  {
    if ((sec_r000487_14_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000487_1_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000487_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000487_1_1 + 7) & 127;
  }
  if ((sec_r000487_15_2 & 1) != 0)
  {
    if ((sec_r000487_14_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000487_1_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000487_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000487_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000487_13_1 & 1) != 0)
  {
    if ((sec_r000487_9_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000487_7_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000487_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000487_7_1 + 7) & 127;
  }
  if ((sec_r000487_13_2 & 1) != 0)
  {
    if ((sec_r000487_9_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000487_7_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000487_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000487_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000487_12_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000487_4_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000487_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000487_4_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000487_12_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000487_4_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000487_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000487_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000487_14_1 & 1) != 0)
  {
    if ((sec_r000487_5_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((sec_r000487_14_2 & 1) != 0)
  {
    if ((sec_r000487_5_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000487_1_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000487_21_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000487_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000487_21_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000487_1_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000487_21_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000487_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000487_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000487_2_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000487_15_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000487_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000487_15_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000487_2_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000487_15_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000487_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000487_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000487_20_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000487_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000487_20_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000487_20_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000487_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000487_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000487_3_1 & 1) != 0)
  {
    if ((sec_r000487_3_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000487_4_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000487_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000487_4_1 + 7) & 127;
  }
  if ((sec_r000487_3_2 & 1) != 0)
  {
    if ((sec_r000487_3_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000487_4_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000487_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000487_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000487_13_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000487_18_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000487_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000487_18_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000487_13_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000487_18_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000487_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000487_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000487_9_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000487_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000487_9_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000487_9_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000487_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000487_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000487_5_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000487_18_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000487_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000487_18_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000487_5_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000487_18_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000487_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000487_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000487_5_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000487_4_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000487_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000487_4_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000487_5_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000487_4_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000487_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000487_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000487_15_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000487_12_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000487_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000487_12_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000487_15_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000487_12_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000487_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000487_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000487_1_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000487_15_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000487_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000487_15_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000487_1_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000487_15_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000487_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000487_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000487_13_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000487_20_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000487_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000487_20_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000487_13_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000487_20_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000487_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000487_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000487_3_1 & 1) != 0)
  {
    if ((sec_r000487_7_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000487_12_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000487_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000487_12_1 + 7) & 127;
  }
  if ((sec_r000487_3_2 & 1) != 0)
  {
    if ((sec_r000487_7_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000487_12_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000487_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000487_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000487_4_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000487_1_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000487_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000487_1_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000487_4_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000487_1_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000487_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000487_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000487_5_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000487_6_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000487_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000487_6_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000487_5_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000487_6_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000487_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000487_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000487_17_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000487_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000487_17_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000487_17_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000487_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000487_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000487_12_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000487_14_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000487_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000487_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000487_12_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000487_14_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000487_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000487_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000487_2_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000487_4_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000487_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000487_4_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000487_2_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000487_4_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000487_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000487_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000487_9_1 & 1) != 0)
  {
    if ((sec_r000487_5_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000487_6_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000487_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000487_6_1 + 7) & 127;
  }
  if ((sec_r000487_9_2 & 1) != 0)
  {
    if ((sec_r000487_5_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000487_6_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000487_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000487_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000487_13_1 & 1) != 0)
  {
    if ((sec_r000487_6_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000487_16_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000487_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000487_16_1 + 7) & 127;
  }
  if ((sec_r000487_13_2 & 1) != 0)
  {
    if ((sec_r000487_6_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000487_16_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000487_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000487_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000487_15_1 & 1) != 0)
  {
    if ((sec_r000487_4_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000487_15_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000487_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000487_15_1 + 7) & 127;
  }
  if ((sec_r000487_15_2 & 1) != 0)
  {
    if ((sec_r000487_4_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000487_15_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000487_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000487_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000487_3_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000487_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000487_3_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000487_3_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000487_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000487_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000487_14_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000487_19_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000487_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000487_19_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000487_14_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000487_19_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000487_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000487_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000487_11_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000487_21_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000487_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000487_21_1 + 7) & 127;
  }
  if ((sec_r000487_11_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000487_21_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000487_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000487_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000487_1_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000487_9_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000487_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000487_9_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000487_1_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000487_9_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000487_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000487_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000487_7_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000487_21_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000487_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000487_21_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000487_7_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000487_21_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000487_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000487_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000487_10_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000487_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000487_10_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000487_10_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000487_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000487_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000487_8_1 & 1) != 0)
  {
    if ((sec_r000487_14_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000487_17_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000487_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000487_17_1 + 7) & 127;
  }
  if ((sec_r000487_8_2 & 1) != 0)
  {
    if ((sec_r000487_14_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000487_17_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000487_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000487_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000487_15_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000487_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000487_15_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000487_15_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000487_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000487_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000487_11_1 & 1) != 0)
  {
    if ((sec_r000487_10_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000487_14_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000487_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000487_14_1 + 7) & 127;
  }
  if ((sec_r000487_11_2 & 1) != 0)
  {
    if ((sec_r000487_10_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000487_14_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000487_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000487_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000487_13_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000487_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000487_13_1 + 7) & 127;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000487_13_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000487_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000487_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000487_1_1 & 1) != 0)
  {
    if ((sec_r000487_5_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000487_17_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000487_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000487_17_1 + 7) & 127;
  }
  if ((sec_r000487_1_2 & 1) != 0)
  {
    if ((sec_r000487_5_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000487_17_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000487_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000487_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000487_0_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000487_11_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000487_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000487_11_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000487_0_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000487_11_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000487_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000487_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000487_5_1 != sec_r000487_5_2);
  __CPROVER_assume(pub_r000487_4_1 == pub_r000487_4_2);
  __CPROVER_assume(pub_r000487_13_1 == pub_r000487_13_2);
  __CPROVER_assume(sec_r000487_10_1 != sec_r000487_10_2);
  __CPROVER_assume(pub_r000487_16_1 == pub_r000487_16_2);
  __CPROVER_assume(pub_r000487_3_1 == pub_r000487_3_2);
  __CPROVER_assume(pub_r000487_15_1 == pub_r000487_15_2);
  __CPROVER_assume(sec_r000487_14_1 != sec_r000487_14_2);
  __CPROVER_assume(sec_r000487_12_1 != sec_r000487_12_2);
  __CPROVER_assume(pub_r000487_6_1 == pub_r000487_6_2);
  __CPROVER_assume(pub_r000487_22_1 == pub_r000487_22_2);
  __CPROVER_assume(sec_r000487_0_1 != sec_r000487_0_2);
  __CPROVER_assume(pub_r000487_9_1 == pub_r000487_9_2);
  __CPROVER_assume(pub_r000487_21_1 == pub_r000487_21_2);
  __CPROVER_assume(pub_r000487_0_1 == pub_r000487_0_2);
  __CPROVER_assume(pub_r000487_5_1 == pub_r000487_5_2);
  __CPROVER_assume(sec_r000487_4_1 != sec_r000487_4_2);
  __CPROVER_assume(pub_r000487_18_1 == pub_r000487_18_2);
  __CPROVER_assume(pub_r000487_20_1 == pub_r000487_20_2);
  __CPROVER_assume(sec_r000487_15_1 != sec_r000487_15_2);
  __CPROVER_assume(pub_r000487_1_1 == pub_r000487_1_2);
  __CPROVER_assume(sec_r000487_9_1 != sec_r000487_9_2);
  __CPROVER_assume(sec_r000487_3_1 != sec_r000487_3_2);
  __CPROVER_assume(sec_r000487_8_1 != sec_r000487_8_2);
  __CPROVER_assume(pub_r000487_14_1 == pub_r000487_14_2);
  __CPROVER_assume(pub_r000487_2_1 == pub_r000487_2_2);
  __CPROVER_assume(pub_r000487_19_1 == pub_r000487_19_2);
  __CPROVER_assume(pub_r000487_8_1 == pub_r000487_8_2);
  __CPROVER_assume(pub_r000487_12_1 == pub_r000487_12_2);
  __CPROVER_assume(sec_r000487_11_1 != sec_r000487_11_2);
  __CPROVER_assume(pub_r000487_7_1 == pub_r000487_7_2);
  __CPROVER_assume(pub_r000487_10_1 == pub_r000487_10_2);
  __CPROVER_assume(pub_r000487_17_1 == pub_r000487_17_2);
  __CPROVER_assume(pub_r000487_11_1 == pub_r000487_11_2);
  __CPROVER_assume(sec_r000487_6_1 != sec_r000487_6_2);
  __CPROVER_assume(sec_r000487_2_1 != sec_r000487_2_2);
  __CPROVER_assume(sec_r000487_7_1 != sec_r000487_7_2);
  __CPROVER_assume(sec_r000487_13_1 != sec_r000487_13_2);
  __CPROVER_assume(sec_r000487_1_1 != sec_r000487_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.calib == st_var_2_2.calib);
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
}


