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
struct SensorNode_R001166_6613_0
{
  unsigned char reading;
  int gain;
  unsigned char threshold;
  int status;
  short calib;
  int offset;
  int buffer[3];
};
struct DeviceConfig_R001166_6613_1
{
  short id;
  int port;
  int timeout;
  unsigned char parity;
  unsigned char stop_bits;
  unsigned char baud_rate;
  int buffer[3];
};
struct MatrixBlock_R001166_6613_2
{
  int dim;
  unsigned char scale;
  int density;
  int buffer[3];
};
struct FilterState_R001166_6613_3
{
  short gain_db;
  int cutoff;
  int prev_in;
  int buffer[3];
};
union PacketPayload_R001166_6613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001166_6613_1
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
void fn_R001166_6613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001166_6613_3 st_1 = {0};
  struct FilterState_R001166_6613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int parity_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_75_1 > 35)
  {
    acc_1 = ((acc_1 + (parity_75_1 * 2)) + 5) & 127;
    aux_1 ^= parity_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_75_2 > 35)
  {
    acc_2 = ((acc_2 + (parity_75_2 * 2)) + 5) & 127;
    aux_2 ^= parity_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_69_1 = local_arr_1[aux_1 % 3];
  int quantum_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_69_2 * 2)) & 127;
  int vector_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_99_1) & 63;
  aux_2 = (aux_2 + vector_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_75_1 == parity_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_69_1 == quantum_69_2);
  assert(vector_99_1 == vector_99_2);
}

int fn_R001166_6613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001166_6613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int parity_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_75 > 35)
  {
    acc = ((acc + (parity_75 * 2)) + 5) & 127;
    aux ^= parity_75 & 15;
  }
  else
  {
    acc = ((acc - parity_75) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_69 = local_arr[aux % 3];
  acc = (acc + (quantum_69 * 2)) & 127;
  int vector_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001166_6613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001166_6613_3 st_1 = {0};
  struct FilterState_R001166_6613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_62_1 = 0;
  int damping_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_62_1 = ((damping_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_62_2 = ((damping_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_62_1) & 127;
    acc_2 = (acc_2 + damping_62_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_13_1 = local_arr_1[aux_1 % 3];
  int anchor_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_62_1 == damping_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_13_1 == anchor_13_2);
}

int fn_R001166_6613_1(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001166_6613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_62 = ((damping_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_62) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_13 = local_arr[aux % 3];
  acc = (acc + (anchor_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001166_6613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st_1 = {0};
  struct DeviceConfig_R001166_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int damping_26_1 = 0;
  int damping_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_26_1 = ((damping_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_26_2 = ((damping_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_26_1) & 127;
    acc_2 = (acc_2 + damping_26_2) & 127;
  }

  int pivot_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_36_1)
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

  switch (pivot_36_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_26_1 == damping_26_2);
  assert(pivot_36_1 == pivot_36_2);
}

int fn_R001166_6613_2(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int damping_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_26 = ((damping_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_26) & 127;
  }

  int pivot_36 = (aux + st.buffer[1]) & 3;
  switch (pivot_36)
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

void fn_R001166_6613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st_1 = {0};
  struct DeviceConfig_R001166_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int mask_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_23_1)
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

  switch (mask_23_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_67_1 = 0;
  int margin_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_67_1 = ((margin_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_67_2 = ((margin_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_67_1) & 127;
    acc_2 = (acc_2 + margin_67_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_23_1 == mask_23_2);
  assert(margin_67_1 == margin_67_2);
}

int fn_R001166_6613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int mask_23 = (aux + st.buffer[1]) & 3;
  switch (mask_23)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_67 = ((margin_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_67) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001166_6613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st_1 = {0};
  struct DeviceConfig_R001166_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int pivot_41_1 = 0;
  int pivot_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_41_1 = ((pivot_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_41_2 = ((pivot_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_41_1) & 127;
    acc_2 = (acc_2 + pivot_41_2) & 127;
  }

  int damping_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_96_1)
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

  switch (damping_96_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_45_1 = local_arr_1[aux_1 % 3];
  int accumulator_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_41_1 == pivot_41_2);
  assert(damping_96_1 == damping_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_45_1 == accumulator_45_2);
}

int fn_R001166_6613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int pivot_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_41 = ((pivot_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_41) & 127;
  }

  int damping_96 = (aux + st.buffer[1]) & 3;
  switch (damping_96)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_45 = local_arr[aux % 3];
  acc = (acc + (accumulator_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001166_6613_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st_1 = {0};
  struct MatrixBlock_R001166_6613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int parity_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_56_1)
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

  switch (parity_56_2)
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
  int cursor_73_1 = local_arr_1[aux_1 % 3];
  int cursor_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_73_2 * 2)) & 127;
  int delta_24_1 = 0;
  int delta_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_24_1 = ((delta_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_24_2 = ((delta_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_24_1) & 127;
    acc_2 = (acc_2 + delta_24_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_56_1 == parity_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_73_1 == cursor_73_2);
  assert(delta_24_1 == delta_24_2);
}

int fn_R001166_6613_5(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int parity_56 = (aux + st.buffer[1]) & 3;
  switch (parity_56)
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
  int cursor_73 = local_arr[aux % 3];
  acc = (acc + (cursor_73 * 2)) & 127;
  int delta_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_24 = ((delta_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_24) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001166_6613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st_1 = {0};
  struct MatrixBlock_R001166_6613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int threshold_57_1 = 0;
  int threshold_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_57_1 = ((threshold_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_57_2 = ((threshold_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_57_1) & 127;
    acc_2 = (acc_2 + threshold_57_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_57_1 == threshold_57_2);
}

int fn_R001166_6613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int threshold_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_57 = ((threshold_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_57) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001166_6613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001166_6613_0 st_1 = {0};
  struct SensorNode_R001166_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_26_1 = local_arr_1[aux_1 % 3];
  int offset_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_26_2 * 2)) & 127;
  int threshold_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_57_1)
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

  switch (threshold_57_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_26_1 == offset_26_2);
  assert(threshold_57_1 == threshold_57_2);
}

int fn_R001166_6613_7(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001166_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int offset_26 = local_arr[aux % 3];
  acc = (acc + (offset_26 * 2)) & 127;
  int threshold_57 = (aux + st.buffer[1]) & 3;
  switch (threshold_57)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001166_6613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st_1 = {0};
  struct DeviceConfig_R001166_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int accumulator_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_10_1) & 63;
  aux_2 = (aux_2 + accumulator_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_28_1 = local_arr_1[aux_1 % 3];
  int scale_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_10_1 == accumulator_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_28_1 == scale_28_2);
}

int fn_R001166_6613_8(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int accumulator_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_28 = local_arr[aux % 3];
  acc = (acc + (scale_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001166_6613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st_1 = {0};
  struct DeviceConfig_R001166_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int bound_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_89_1) & 63;
  aux_2 = (aux_2 + bound_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_89_1 == bound_89_2);
}

int fn_R001166_6613_9(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int bound_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_89) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001166_6613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st_1 = {0};
  struct MatrixBlock_R001166_6613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_89_1) & 63;
  aux_2 = (aux_2 + delta_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_89_1 == delta_89_2);
}

int fn_R001166_6613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001166_6613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st_1 = {0};
  struct MatrixBlock_R001166_6613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int scale_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_51_1 > 50)
  {
    acc_1 = ((acc_1 + (scale_51_1 * 2)) + 5) & 127;
    aux_1 ^= scale_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_51_2 > 50)
  {
    acc_2 = ((acc_2 + (scale_51_2 * 2)) + 5) & 127;
    aux_2 ^= scale_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_99_1 = 0;
  int index_reg_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_99_1 = ((index_reg_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_99_2 = ((index_reg_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_99_1) & 127;
    acc_2 = (acc_2 + index_reg_99_2) & 127;
  }

  int metric_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_44_1) & 63;
  aux_2 = (aux_2 + metric_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_90_1)
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

  switch (mask_90_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_51_1 == scale_51_2);
  assert(index_reg_99_1 == index_reg_99_2);
  assert(metric_44_1 == metric_44_2);
  assert(mask_90_1 == mask_90_2);
}

int fn_R001166_6613_11(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int scale_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_51 > 50)
  {
    acc = ((acc + (scale_51 * 2)) + 5) & 127;
    aux ^= scale_51 & 15;
  }
  else
  {
    acc = ((acc - scale_51) + 11) & 127;
    aux += 3;
  }
  int index_reg_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_99 = ((index_reg_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_99) & 127;
  }

  int metric_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_44) & 63;
  acc ^= aux;
  int mask_90 = (aux + st.buffer[1]) & 3;
  switch (mask_90)
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

void fn_R001166_6613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st_1 = {0};
  struct DeviceConfig_R001166_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int scale_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_57_1 > 20)
  {
    acc_1 = ((acc_1 + (scale_57_1 * 2)) + 5) & 127;
    aux_1 ^= scale_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_57_2 > 20)
  {
    acc_2 = ((acc_2 + (scale_57_2 * 2)) + 5) & 127;
    aux_2 ^= scale_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_56_1) & 63;
  aux_2 = (aux_2 + weight_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_81_1 = local_arr_1[aux_1 % 3];
  int bound_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_57_1 == scale_57_2);
  assert(weight_56_1 == weight_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_81_1 == bound_81_2);
}

int fn_R001166_6613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001166_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int scale_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_57 > 20)
  {
    acc = ((acc + (scale_57 * 2)) + 5) & 127;
    aux ^= scale_57 & 15;
  }
  else
  {
    acc = ((acc - scale_57) + 11) & 127;
    aux += 3;
  }
  int weight_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_56) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_81 = local_arr[aux % 3];
  acc = (acc + (bound_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001166_6613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st_1 = {0};
  struct MatrixBlock_R001166_6613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_86_1 = local_arr_1[aux_1 % 3];
  int quotient_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_86_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_86_1 == quotient_86_2);
}

int fn_R001166_6613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001166_6613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int quotient_86 = local_arr[aux % 3];
  acc = (acc + (quotient_86 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001166_6613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001166_6613_0 st_1 = {0};
  struct SensorNode_R001166_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_13_1 = local_arr_1[aux_1 % 3];
  int coefficient_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_13_2 * 2)) & 127;
  int quantum_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_80_1) & 63;
  aux_2 = (aux_2 + quantum_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_13_1 == coefficient_13_2);
  assert(quantum_80_1 == quantum_80_2);
}

int fn_R001166_6613_14(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001166_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int coefficient_13 = local_arr[aux % 3];
  acc = (acc + (coefficient_13 * 2)) & 127;
  int quantum_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001166_0_1;
  int sec_r001166_0_2;
  int sec_r001166_1_1;
  int sec_r001166_1_2;
  int sec_r001166_2_1;
  int sec_r001166_2_2;
  int sec_r001166_3_1;
  int sec_r001166_3_2;
  int sec_r001166_4_1;
  int sec_r001166_4_2;
  int sec_r001166_5_1;
  int sec_r001166_5_2;
  int sec_r001166_6_1;
  int sec_r001166_6_2;
  int sec_r001166_7_1;
  int sec_r001166_7_2;
  int sec_r001166_8_1;
  int sec_r001166_8_2;
  int sec_r001166_9_1;
  int sec_r001166_9_2;
  int sec_r001166_10_1;
  int sec_r001166_10_2;
  int sec_r001166_11_1;
  int sec_r001166_11_2;
  int sec_r001166_12_1;
  int sec_r001166_12_2;
  int sec_r001166_13_1;
  int sec_r001166_13_2;
  int sec_r001166_14_1;
  int sec_r001166_14_2;
  int sec_r001166_15_1;
  int sec_r001166_15_2;
  int sec_r001166_16_1;
  int sec_r001166_16_2;
  int sec_r001166_17_1;
  int sec_r001166_17_2;
  int sec_r001166_18_1;
  int sec_r001166_18_2;
  int sec_r001166_19_1;
  int sec_r001166_19_2;
  int sec_r001166_20_1;
  int sec_r001166_20_2;
  int pub_r001166_0_1;
  int pub_r001166_0_2;
  int pub_r001166_1_1;
  int pub_r001166_1_2;
  int pub_r001166_2_1;
  int pub_r001166_2_2;
  int pub_r001166_3_1;
  int pub_r001166_3_2;
  int pub_r001166_4_1;
  int pub_r001166_4_2;
  int pub_r001166_5_1;
  int pub_r001166_5_2;
  int pub_r001166_6_1;
  int pub_r001166_6_2;
  int pub_r001166_7_1;
  int pub_r001166_7_2;
  int pub_r001166_8_1;
  int pub_r001166_8_2;
  int pub_r001166_9_1;
  int pub_r001166_9_2;
  int pub_r001166_10_1;
  int pub_r001166_10_2;
  int pub_r001166_11_1;
  int pub_r001166_11_2;
  int pub_r001166_12_1;
  int pub_r001166_12_2;
  int pub_r001166_13_1;
  int pub_r001166_13_2;
  int pub_r001166_14_1;
  int pub_r001166_14_2;
  int pub_r001166_15_1;
  int pub_r001166_15_2;
  int pub_r001166_16_1;
  int pub_r001166_16_2;
  int pub_r001166_17_1;
  int pub_r001166_17_2;
  int pub_r001166_18_1;
  int pub_r001166_18_2;
  int pub_r001166_19_1;
  int pub_r001166_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001166_0_1 >= (-100)) && (pub_r001166_0_1 <= 100));
  __CPROVER_assume((pub_r001166_0_2 >= (-100)) && (pub_r001166_0_2 <= 100));
  __CPROVER_assume((pub_r001166_1_1 >= (-100)) && (pub_r001166_1_1 <= 100));
  __CPROVER_assume((pub_r001166_1_2 >= (-100)) && (pub_r001166_1_2 <= 100));
  __CPROVER_assume((pub_r001166_2_1 >= (-100)) && (pub_r001166_2_1 <= 100));
  __CPROVER_assume((pub_r001166_2_2 >= (-100)) && (pub_r001166_2_2 <= 100));
  __CPROVER_assume((pub_r001166_3_1 >= (-100)) && (pub_r001166_3_1 <= 100));
  __CPROVER_assume((pub_r001166_3_2 >= (-100)) && (pub_r001166_3_2 <= 100));
  __CPROVER_assume((pub_r001166_4_1 >= (-100)) && (pub_r001166_4_1 <= 100));
  __CPROVER_assume((pub_r001166_4_2 >= (-100)) && (pub_r001166_4_2 <= 100));
  __CPROVER_assume((pub_r001166_5_1 >= (-100)) && (pub_r001166_5_1 <= 100));
  __CPROVER_assume((pub_r001166_5_2 >= (-100)) && (pub_r001166_5_2 <= 100));
  __CPROVER_assume((pub_r001166_6_1 >= (-100)) && (pub_r001166_6_1 <= 100));
  __CPROVER_assume((pub_r001166_6_2 >= (-100)) && (pub_r001166_6_2 <= 100));
  __CPROVER_assume((pub_r001166_7_1 >= (-100)) && (pub_r001166_7_1 <= 100));
  __CPROVER_assume((pub_r001166_7_2 >= (-100)) && (pub_r001166_7_2 <= 100));
  __CPROVER_assume((pub_r001166_8_1 >= (-100)) && (pub_r001166_8_1 <= 100));
  __CPROVER_assume((pub_r001166_8_2 >= (-100)) && (pub_r001166_8_2 <= 100));
  __CPROVER_assume((pub_r001166_9_1 >= (-100)) && (pub_r001166_9_1 <= 100));
  __CPROVER_assume((pub_r001166_9_2 >= (-100)) && (pub_r001166_9_2 <= 100));
  __CPROVER_assume((pub_r001166_10_1 >= (-100)) && (pub_r001166_10_1 <= 100));
  __CPROVER_assume((pub_r001166_10_2 >= (-100)) && (pub_r001166_10_2 <= 100));
  __CPROVER_assume((pub_r001166_11_1 >= (-100)) && (pub_r001166_11_1 <= 100));
  __CPROVER_assume((pub_r001166_11_2 >= (-100)) && (pub_r001166_11_2 <= 100));
  __CPROVER_assume((pub_r001166_12_1 >= (-100)) && (pub_r001166_12_1 <= 100));
  __CPROVER_assume((pub_r001166_12_2 >= (-100)) && (pub_r001166_12_2 <= 100));
  __CPROVER_assume((pub_r001166_13_1 >= (-100)) && (pub_r001166_13_1 <= 100));
  __CPROVER_assume((pub_r001166_13_2 >= (-100)) && (pub_r001166_13_2 <= 100));
  __CPROVER_assume((pub_r001166_14_1 >= (-100)) && (pub_r001166_14_1 <= 100));
  __CPROVER_assume((pub_r001166_14_2 >= (-100)) && (pub_r001166_14_2 <= 100));
  __CPROVER_assume((pub_r001166_15_1 >= (-100)) && (pub_r001166_15_1 <= 100));
  __CPROVER_assume((pub_r001166_15_2 >= (-100)) && (pub_r001166_15_2 <= 100));
  __CPROVER_assume((pub_r001166_16_1 >= (-100)) && (pub_r001166_16_1 <= 100));
  __CPROVER_assume((pub_r001166_16_2 >= (-100)) && (pub_r001166_16_2 <= 100));
  __CPROVER_assume((pub_r001166_17_1 >= (-100)) && (pub_r001166_17_1 <= 100));
  __CPROVER_assume((pub_r001166_17_2 >= (-100)) && (pub_r001166_17_2 <= 100));
  __CPROVER_assume((pub_r001166_18_1 >= (-100)) && (pub_r001166_18_1 <= 100));
  __CPROVER_assume((pub_r001166_18_2 >= (-100)) && (pub_r001166_18_2 <= 100));
  __CPROVER_assume((pub_r001166_19_1 >= (-100)) && (pub_r001166_19_1 <= 100));
  __CPROVER_assume((pub_r001166_19_2 >= (-100)) && (pub_r001166_19_2 <= 100));
  __CPROVER_assume((sec_r001166_0_1 >= 0) && (sec_r001166_0_1 <= 255));
  __CPROVER_assume((sec_r001166_0_2 >= 0) && (sec_r001166_0_2 <= 255));
  __CPROVER_assume((sec_r001166_1_1 >= 0) && (sec_r001166_1_1 <= 255));
  __CPROVER_assume((sec_r001166_1_2 >= 0) && (sec_r001166_1_2 <= 255));
  __CPROVER_assume((sec_r001166_2_1 >= 0) && (sec_r001166_2_1 <= 255));
  __CPROVER_assume((sec_r001166_2_2 >= 0) && (sec_r001166_2_2 <= 255));
  __CPROVER_assume((sec_r001166_3_1 >= 0) && (sec_r001166_3_1 <= 255));
  __CPROVER_assume((sec_r001166_3_2 >= 0) && (sec_r001166_3_2 <= 255));
  __CPROVER_assume((sec_r001166_4_1 >= 0) && (sec_r001166_4_1 <= 255));
  __CPROVER_assume((sec_r001166_4_2 >= 0) && (sec_r001166_4_2 <= 255));
  __CPROVER_assume((sec_r001166_5_1 >= 0) && (sec_r001166_5_1 <= 255));
  __CPROVER_assume((sec_r001166_5_2 >= 0) && (sec_r001166_5_2 <= 255));
  __CPROVER_assume((sec_r001166_6_1 >= 0) && (sec_r001166_6_1 <= 255));
  __CPROVER_assume((sec_r001166_6_2 >= 0) && (sec_r001166_6_2 <= 255));
  __CPROVER_assume((sec_r001166_7_1 >= 0) && (sec_r001166_7_1 <= 255));
  __CPROVER_assume((sec_r001166_7_2 >= 0) && (sec_r001166_7_2 <= 255));
  __CPROVER_assume((sec_r001166_8_1 >= 0) && (sec_r001166_8_1 <= 255));
  __CPROVER_assume((sec_r001166_8_2 >= 0) && (sec_r001166_8_2 <= 255));
  __CPROVER_assume((sec_r001166_9_1 >= 0) && (sec_r001166_9_1 <= 255));
  __CPROVER_assume((sec_r001166_9_2 >= 0) && (sec_r001166_9_2 <= 255));
  __CPROVER_assume((sec_r001166_10_1 >= 0) && (sec_r001166_10_1 <= 255));
  __CPROVER_assume((sec_r001166_10_2 >= 0) && (sec_r001166_10_2 <= 255));
  __CPROVER_assume((sec_r001166_11_1 >= 0) && (sec_r001166_11_1 <= 255));
  __CPROVER_assume((sec_r001166_11_2 >= 0) && (sec_r001166_11_2 <= 255));
  __CPROVER_assume((sec_r001166_12_1 >= 0) && (sec_r001166_12_1 <= 255));
  __CPROVER_assume((sec_r001166_12_2 >= 0) && (sec_r001166_12_2 <= 255));
  __CPROVER_assume((sec_r001166_13_1 >= 0) && (sec_r001166_13_1 <= 255));
  __CPROVER_assume((sec_r001166_13_2 >= 0) && (sec_r001166_13_2 <= 255));
  __CPROVER_assume((sec_r001166_14_1 >= 0) && (sec_r001166_14_1 <= 255));
  __CPROVER_assume((sec_r001166_14_2 >= 0) && (sec_r001166_14_2 <= 255));
  __CPROVER_assume((sec_r001166_15_1 >= 0) && (sec_r001166_15_1 <= 255));
  __CPROVER_assume((sec_r001166_15_2 >= 0) && (sec_r001166_15_2 <= 255));
  __CPROVER_assume((sec_r001166_16_1 >= 0) && (sec_r001166_16_1 <= 255));
  __CPROVER_assume((sec_r001166_16_2 >= 0) && (sec_r001166_16_2 <= 255));
  __CPROVER_assume((sec_r001166_17_1 >= 0) && (sec_r001166_17_1 <= 255));
  __CPROVER_assume((sec_r001166_17_2 >= 0) && (sec_r001166_17_2 <= 255));
  __CPROVER_assume((sec_r001166_18_1 >= 0) && (sec_r001166_18_1 <= 255));
  __CPROVER_assume((sec_r001166_18_2 >= 0) && (sec_r001166_18_2 <= 255));
  __CPROVER_assume((sec_r001166_19_1 >= 0) && (sec_r001166_19_1 <= 255));
  __CPROVER_assume((sec_r001166_19_2 >= 0) && (sec_r001166_19_2 <= 255));
  __CPROVER_assume((sec_r001166_20_1 >= 0) && (sec_r001166_20_1 <= 255));
  __CPROVER_assume((sec_r001166_20_2 >= 0) && (sec_r001166_20_2 <= 255));
  struct SensorNode_R001166_6613_0 st_var_0_1 = {0};
  struct SensorNode_R001166_6613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001166_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001166_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001166_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001166_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001166_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001166_0_2 + 7) & 15;
  struct DeviceConfig_R001166_6613_1 st_var_1_1 = {0};
  struct DeviceConfig_R001166_6613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001166_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001166_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001166_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001166_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001166_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001166_0_2 + 9) & 15;
  struct MatrixBlock_R001166_6613_2 st_var_2_1 = {0};
  struct MatrixBlock_R001166_6613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001166_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001166_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001166_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001166_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001166_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001166_0_2 + 11) & 15;
  struct FilterState_R001166_6613_3 st_var_3_1 = {0};
  struct FilterState_R001166_6613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001166_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001166_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001166_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001166_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001166_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001166_0_2 + 13) & 15;
  union PacketPayload_R001166_6613_0 u_var_1;
  union PacketPayload_R001166_6613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001166_6613_0(sec_r001166_0_1, sec_r001166_1_1, pub_r001166_2_1, pub_r001166_3_1, pub_r001166_4_1);
  int helper_flow_0_2 = fn_R001166_6613_0(sec_r001166_0_2, sec_r001166_1_2, pub_r001166_2_2, pub_r001166_3_2, pub_r001166_4_2);
  fn_R001166_6613_0_2(sec_r001166_0_1, sec_r001166_1_1, pub_r001166_2_1, pub_r001166_3_1, pub_r001166_4_1, sec_r001166_0_2, sec_r001166_1_2, pub_r001166_2_2, pub_r001166_3_2, pub_r001166_4_2);
  int helper_flow_1_1 = fn_R001166_6613_1(sec_r001166_1_1, sec_r001166_2_1);
  int helper_flow_1_2 = fn_R001166_6613_1(sec_r001166_1_2, sec_r001166_2_2);
  fn_R001166_6613_1_2(sec_r001166_1_1, sec_r001166_2_1, sec_r001166_1_2, sec_r001166_2_2);
  int helper_flow_2_1 = fn_R001166_6613_2(sec_r001166_2_1, pub_r001166_3_1);
  int helper_flow_2_2 = fn_R001166_6613_2(sec_r001166_2_2, pub_r001166_3_2);
  fn_R001166_6613_2_2(sec_r001166_2_1, pub_r001166_3_1, sec_r001166_2_2, pub_r001166_3_2);
  int helper_flow_3_1 = fn_R001166_6613_3(sec_r001166_3_1, pub_r001166_4_1, pub_r001166_5_1, pub_r001166_6_1);
  int helper_flow_3_2 = fn_R001166_6613_3(sec_r001166_3_2, pub_r001166_4_2, pub_r001166_5_2, pub_r001166_6_2);
  fn_R001166_6613_3_2(sec_r001166_3_1, pub_r001166_4_1, pub_r001166_5_1, pub_r001166_6_1, sec_r001166_3_2, pub_r001166_4_2, pub_r001166_5_2, pub_r001166_6_2);
  int helper_flow_4_1 = fn_R001166_6613_4(sec_r001166_4_1, sec_r001166_5_1, pub_r001166_6_1, pub_r001166_7_1);
  int helper_flow_4_2 = fn_R001166_6613_4(sec_r001166_4_2, sec_r001166_5_2, pub_r001166_6_2, pub_r001166_7_2);
  fn_R001166_6613_4_2(sec_r001166_4_1, sec_r001166_5_1, pub_r001166_6_1, pub_r001166_7_1, sec_r001166_4_2, sec_r001166_5_2, pub_r001166_6_2, pub_r001166_7_2);
  int helper_flow_5_1 = fn_R001166_6613_5(sec_r001166_5_1, pub_r001166_6_1, pub_r001166_7_1);
  int helper_flow_5_2 = fn_R001166_6613_5(sec_r001166_5_2, pub_r001166_6_2, pub_r001166_7_2);
  fn_R001166_6613_5_2(sec_r001166_5_1, pub_r001166_6_1, pub_r001166_7_1, sec_r001166_5_2, pub_r001166_6_2, pub_r001166_7_2);
  int helper_flow_6_1 = fn_R001166_6613_6(sec_r001166_6_1, pub_r001166_7_1, pub_r001166_8_1, pub_r001166_9_1, pub_r001166_10_1);
  int helper_flow_6_2 = fn_R001166_6613_6(sec_r001166_6_2, pub_r001166_7_2, pub_r001166_8_2, pub_r001166_9_2, pub_r001166_10_2);
  fn_R001166_6613_6_2(sec_r001166_6_1, pub_r001166_7_1, pub_r001166_8_1, pub_r001166_9_1, pub_r001166_10_1, sec_r001166_6_2, pub_r001166_7_2, pub_r001166_8_2, pub_r001166_9_2, pub_r001166_10_2);
  int helper_flow_7_1 = fn_R001166_6613_7(sec_r001166_7_1, pub_r001166_8_1);
  int helper_flow_7_2 = fn_R001166_6613_7(sec_r001166_7_2, pub_r001166_8_2);
  fn_R001166_6613_7_2(sec_r001166_7_1, pub_r001166_8_1, sec_r001166_7_2, pub_r001166_8_2);
  int helper_flow_8_1 = fn_R001166_6613_8(sec_r001166_8_1, sec_r001166_9_1);
  int helper_flow_8_2 = fn_R001166_6613_8(sec_r001166_8_2, sec_r001166_9_2);
  fn_R001166_6613_8_2(sec_r001166_8_1, sec_r001166_9_1, sec_r001166_8_2, sec_r001166_9_2);
  int helper_flow_9_1 = fn_R001166_6613_9(sec_r001166_9_1, pub_r001166_10_1);
  int helper_flow_9_2 = fn_R001166_6613_9(sec_r001166_9_2, pub_r001166_10_2);
  fn_R001166_6613_9_2(sec_r001166_9_1, pub_r001166_10_1, sec_r001166_9_2, pub_r001166_10_2);
  int stage_v_0_1 = ((sec_r001166_7_1 + (pub_r001166_3_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001166_7_2 + (pub_r001166_3_2 * 2)) + 5) & 127;
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
  int stage_v_1_1 = ((sec_r001166_13_1 + (pub_r001166_3_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001166_13_2 + (pub_r001166_3_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001166_9_1 * 2) + 18) & 63;
  int stage_v_2_2 = ((pub_r001166_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001166_11_1 + (pub_r001166_12_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001166_11_2 + (pub_r001166_12_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001166_8_1 * 2) + 26) & 63;
  int stage_v_4_2 = ((pub_r001166_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001166_2_1 * 2) + 26) & 63;
  int stage_v_5_2 = ((pub_r001166_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((sec_r001166_12_1 + (pub_r001166_17_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001166_12_2 + (pub_r001166_17_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((sec_r001166_9_1 + (pub_r001166_0_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001166_9_2 + (pub_r001166_0_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((pub_r001166_14_1 * 2) + 49) & 63;
  int stage_v_8_2 = ((pub_r001166_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((stage_v_6_1 + (pub_r001166_12_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((stage_v_6_2 + (pub_r001166_12_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((pub_r001166_4_1 * 2) + 14) & 63;
  int stage_v_10_2 = ((pub_r001166_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001166_11_1 * 2) + 20) & 63;
  int stage_v_11_2 = ((pub_r001166_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001166_0_1 + (pub_r001166_7_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001166_0_2 + (pub_r001166_7_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((pub_r001166_6_1 * 2) + 43) & 63;
  int stage_v_13_2 = ((pub_r001166_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((stage_v_0_1 + (pub_r001166_1_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((stage_v_0_2 + (pub_r001166_1_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((sec_r001166_13_1 + (pub_r001166_0_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001166_13_2 + (pub_r001166_0_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((sec_r001166_8_1 + (pub_r001166_11_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001166_8_2 + (pub_r001166_11_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((helper_flow_5_1 + (pub_r001166_2_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((helper_flow_5_2 + (pub_r001166_2_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001166_15_1 * 2) + 20) & 63;
  int stage_v_18_2 = ((pub_r001166_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((sec_r001166_12_1 + (pub_r001166_6_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001166_12_2 + (pub_r001166_6_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((stage_v_16_1 + (pub_r001166_12_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_16_2 + (pub_r001166_12_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_19_1 + (pub_r001166_13_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_19_2 + (pub_r001166_13_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001166_7_1 * 2) + 37) & 63;
  int stage_v_22_2 = ((pub_r001166_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001166_0_1 * 2) + 37) & 63;
  int stage_v_23_2 = ((pub_r001166_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001166_10_1 + (pub_r001166_9_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001166_10_2 + (pub_r001166_9_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001166_7_1 * 2) + 7) & 63;
  int stage_v_25_2 = ((pub_r001166_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((sec_r001166_0_1 + (pub_r001166_1_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001166_0_2 + (pub_r001166_1_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((pub_r001166_13_1 * 2) + 13) & 63;
  int stage_v_27_2 = ((pub_r001166_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((stage_v_19_1 + (pub_r001166_10_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_19_2 + (pub_r001166_10_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((pub_r001166_18_1 * 2) + 50) & 63;
  int stage_v_29_2 = ((pub_r001166_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001166_8_1 * 2) + 43) & 63;
  int stage_v_30_2 = ((pub_r001166_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001166_10_1 * 2) + 7) & 63;
  int stage_v_31_2 = ((pub_r001166_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((sec_r001166_7_1 + (pub_r001166_10_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((sec_r001166_7_2 + (pub_r001166_10_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((pub_r001166_5_1 * 2) + 33) & 63;
  int stage_v_33_2 = ((pub_r001166_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((sec_r001166_17_1 + (pub_r001166_0_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((sec_r001166_17_2 + (pub_r001166_0_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001166_5_1 + (pub_r001166_10_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001166_5_2 + (pub_r001166_10_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001166_18_1 * 2) + 42) & 63;
  int stage_v_36_2 = ((pub_r001166_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((stage_v_32_1 + (pub_r001166_12_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_32_2 + (pub_r001166_12_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001166_16_1 * 2) + 11) & 63;
  int stage_v_38_2 = ((pub_r001166_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((stage_v_14_1 + (pub_r001166_18_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((stage_v_14_2 + (pub_r001166_18_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((stage_v_15_1 + (pub_r001166_19_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_15_2 + (pub_r001166_19_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001166_12_1 * 2) + 21) & 63;
  int stage_v_41_2 = ((pub_r001166_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001166_11_1 * 2) + 9) & 63;
  int stage_v_42_2 = ((pub_r001166_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((sec_r001166_0_1 + (pub_r001166_2_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((sec_r001166_0_2 + (pub_r001166_2_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((helper_flow_2_1 + (pub_r001166_19_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((helper_flow_2_2 + (pub_r001166_19_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((sec_r001166_3_1 + (pub_r001166_1_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001166_3_2 + (pub_r001166_1_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_28_1 + (pub_r001166_0_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_28_2 + (pub_r001166_0_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001166_19_1 * 2) + 37) & 63;
  int stage_v_47_2 = ((pub_r001166_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((stage_v_34_1 + (pub_r001166_13_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_34_2 + (pub_r001166_13_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((sec_r001166_4_1 + (pub_r001166_17_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((sec_r001166_4_2 + (pub_r001166_17_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001166_8_1 * 2) + 13) & 63;
  int stage_v_50_2 = ((pub_r001166_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((sec_r001166_13_1 + (pub_r001166_3_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((sec_r001166_13_2 + (pub_r001166_3_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001166_3_1 * 2) + 9) & 63;
  int stage_v_52_2 = ((pub_r001166_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((stage_v_32_1 + (pub_r001166_19_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_32_2 + (pub_r001166_19_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((pub_r001166_9_1 * 2) + 35) & 63;
  int stage_v_54_2 = ((pub_r001166_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001166_17_1 * 2) + 33) & 63;
  int stage_v_55_2 = ((pub_r001166_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001166_8_1 * 2) + 34) & 63;
  int stage_v_56_2 = ((pub_r001166_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001166_7_1 * 2) + 13) & 63;
  int stage_v_57_2 = ((pub_r001166_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((sec_r001166_6_1 + (pub_r001166_15_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((sec_r001166_6_2 + (pub_r001166_15_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001166_10_1 * 2) + 37) & 63;
  int stage_v_59_2 = ((pub_r001166_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001166_12_1 * 2) + 28) & 63;
  int stage_v_60_2 = ((pub_r001166_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001166_15_1 * 2) + 41) & 63;
  int stage_v_61_2 = ((pub_r001166_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((helper_flow_8_1 + (pub_r001166_19_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((helper_flow_8_2 + (pub_r001166_19_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((pub_r001166_17_1 * 2) + 39) & 63;
  int stage_v_63_2 = ((pub_r001166_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((sec_r001166_15_1 + (pub_r001166_2_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001166_15_2 + (pub_r001166_2_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_17_1 + (pub_r001166_16_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_17_2 + (pub_r001166_16_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001166_12_1 * 2) + 36) & 63;
  int stage_v_66_2 = ((pub_r001166_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((helper_flow_8_1 + (pub_r001166_3_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((helper_flow_8_2 + (pub_r001166_3_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001166_14_1 * 2) + 49) & 63;
  int stage_v_68_2 = ((pub_r001166_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001166_10_1 * 2) + 44) & 63;
  int stage_v_69_2 = ((pub_r001166_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001166_12_1 * 2) + 15) & 63;
  int stage_v_70_2 = ((pub_r001166_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((sec_r001166_18_1 + (pub_r001166_9_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((sec_r001166_18_2 + (pub_r001166_9_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((sec_r001166_13_1 + (pub_r001166_3_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((sec_r001166_13_2 + (pub_r001166_3_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_12_1 + (pub_r001166_11_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_12_2 + (pub_r001166_11_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((pub_r001166_14_1 * 2) + 5) & 63;
  int stage_v_74_2 = ((pub_r001166_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((sec_r001166_9_1 + (pub_r001166_14_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((sec_r001166_9_2 + (pub_r001166_14_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((sec_r001166_6_1 + (pub_r001166_13_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((sec_r001166_6_2 + (pub_r001166_13_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_46_1 + (pub_r001166_10_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_46_2 + (pub_r001166_10_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_49_1 + (pub_r001166_2_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_49_2 + (pub_r001166_2_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001166_14_1 * 2) + 36) & 63;
  int stage_v_79_2 = ((pub_r001166_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_15_1 + (pub_r001166_12_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_15_2 + (pub_r001166_12_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_0_1 + (pub_r001166_7_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_0_2 + (pub_r001166_7_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((stage_v_20_1 + (pub_r001166_13_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_20_2 + (pub_r001166_13_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_20_1 + (pub_r001166_2_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_20_2 + (pub_r001166_2_2 * 2)) + 254) & 127;
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
  int stage_v_84_1 = ((stage_v_71_1 + (pub_r001166_0_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_71_2 + (pub_r001166_0_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((helper_flow_3_1 + (pub_r001166_16_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((helper_flow_3_2 + (pub_r001166_16_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_20_1 + (pub_r001166_14_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_20_2 + (pub_r001166_14_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((pub_r001166_4_1 * 2) + 30) & 63;
  int stage_v_87_2 = ((pub_r001166_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001166_11_1 * 2) + 11) & 63;
  int stage_v_88_2 = ((pub_r001166_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001166_12_1 * 2) + 33) & 63;
  int stage_v_89_2 = ((pub_r001166_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((stage_v_48_1 + (pub_r001166_14_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_48_2 + (pub_r001166_14_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_76_1 + (pub_r001166_8_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_76_2 + (pub_r001166_8_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((sec_r001166_0_1 + (pub_r001166_14_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((sec_r001166_0_2 + (pub_r001166_14_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((pub_r001166_9_1 * 2) + 18) & 63;
  int stage_v_93_2 = ((pub_r001166_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((helper_flow_9_1 + (pub_r001166_12_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((helper_flow_9_2 + (pub_r001166_12_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_37_1 + (pub_r001166_10_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_37_2 + (pub_r001166_10_2 * 2)) + 290) & 127;
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
  int stage_v_96_1 = ((pub_r001166_6_1 * 2) + 46) & 63;
  int stage_v_96_2 = ((pub_r001166_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((helper_flow_1_1 + (pub_r001166_3_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((helper_flow_1_2 + (pub_r001166_3_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((pub_r001166_5_1 * 2) + 42) & 63;
  int stage_v_98_2 = ((pub_r001166_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001166_2_1 * 2) + 45) & 63;
  int stage_v_99_2 = ((pub_r001166_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((stage_v_64_1 + (pub_r001166_5_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_64_2 + (pub_r001166_5_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((sec_r001166_18_1 + (pub_r001166_1_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((sec_r001166_18_2 + (pub_r001166_1_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_94_1 + (pub_r001166_14_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_94_2 + (pub_r001166_14_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_67_1 + (pub_r001166_1_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_67_2 + (pub_r001166_1_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001166_16_1 * 2) + 17) & 63;
  int stage_v_104_2 = ((pub_r001166_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001166_5_1 * 2) + 49) & 63;
  int stage_v_105_2 = ((pub_r001166_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_28_1 + (pub_r001166_14_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_28_2 + (pub_r001166_14_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_24_1 + (pub_r001166_13_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_24_2 + (pub_r001166_13_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((sec_r001166_2_1 + (pub_r001166_12_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((sec_r001166_2_2 + (pub_r001166_12_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((pub_r001166_1_1 * 2) + 26) & 63;
  int stage_v_109_2 = ((pub_r001166_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001166_18_1 * 2) + 48) & 63;
  int stage_v_110_2 = ((pub_r001166_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001166_15_1 * 2) + 40) & 63;
  int stage_v_111_2 = ((pub_r001166_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001166_12_1 * 2) + 42) & 63;
  int stage_v_112_2 = ((pub_r001166_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001166_16_1 * 2) + 25) & 63;
  int stage_v_113_2 = ((pub_r001166_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((sec_r001166_5_1 + (pub_r001166_10_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((sec_r001166_5_2 + (pub_r001166_10_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((helper_flow_6_1 + (pub_r001166_6_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((helper_flow_6_2 + (pub_r001166_6_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((pub_r001166_7_1 * 2) + 19) & 63;
  int stage_v_116_2 = ((pub_r001166_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001166_10_1 * 2) + 26) & 63;
  int stage_v_117_2 = ((pub_r001166_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001166_18_1 * 2) + 23) & 63;
  int stage_v_118_2 = ((pub_r001166_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001166_4_1 * 2) + 25) & 63;
  int stage_v_119_2 = ((pub_r001166_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001166_16_1 * 2) + 27) & 63;
  int stage_v_120_2 = ((pub_r001166_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_0_1 + (pub_r001166_13_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_0_2 + (pub_r001166_13_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((pub_r001166_0_1 * 2) + 43) & 63;
  int stage_v_122_2 = ((pub_r001166_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((stage_v_51_1 + (pub_r001166_18_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_51_2 + (pub_r001166_18_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((sec_r001166_8_1 + (pub_r001166_6_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((sec_r001166_8_2 + (pub_r001166_6_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((stage_v_14_1 + (pub_r001166_4_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_14_2 + (pub_r001166_4_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_51_1 + (pub_r001166_5_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_51_2 + (pub_r001166_5_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((helper_flow_7_1 + (pub_r001166_1_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((helper_flow_7_2 + (pub_r001166_1_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_81_1 + (pub_r001166_7_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_81_2 + (pub_r001166_7_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_44_1 + (pub_r001166_14_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_44_2 + (pub_r001166_14_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((helper_flow_9_1 + (pub_r001166_8_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((helper_flow_9_2 + (pub_r001166_8_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((sec_r001166_12_1 + (pub_r001166_2_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((sec_r001166_12_2 + (pub_r001166_2_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((stage_v_3_1 + (pub_r001166_14_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_3_2 + (pub_r001166_14_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((helper_flow_3_1 + (pub_r001166_1_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((helper_flow_3_2 + (pub_r001166_1_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001166_1_1 * 2) + 20) & 63;
  int stage_v_134_2 = ((pub_r001166_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001166_2_1 * 2) + 49) & 63;
  int stage_v_135_2 = ((pub_r001166_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001166_18_1 * 2) + 37) & 63;
  int stage_v_136_2 = ((pub_r001166_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001166_8_1 * 2) + 11) & 63;
  int stage_v_137_2 = ((pub_r001166_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_86_1 + (pub_r001166_14_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_86_2 + (pub_r001166_14_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((helper_flow_4_1 + (pub_r001166_7_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((helper_flow_4_2 + (pub_r001166_7_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((sec_r001166_11_1 + (pub_r001166_10_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((sec_r001166_11_2 + (pub_r001166_10_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_51_1 + (pub_r001166_1_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_51_2 + (pub_r001166_1_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((sec_r001166_15_1 + (pub_r001166_6_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((sec_r001166_15_2 + (pub_r001166_6_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_126_1 + (pub_r001166_15_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_126_2 + (pub_r001166_15_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_37_1 + (pub_r001166_16_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_37_2 + (pub_r001166_16_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((pub_r001166_15_1 * 2) + 11) & 63;
  int stage_v_145_2 = ((pub_r001166_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001166_3_1 * 2) + 42) & 63;
  int stage_v_146_2 = ((pub_r001166_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_14_1 + (pub_r001166_10_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_14_2 + (pub_r001166_10_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((pub_r001166_17_1 * 2) + 10) & 63;
  int stage_v_148_2 = ((pub_r001166_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001166_18_1 * 2) + 18) & 63;
  int stage_v_149_2 = ((pub_r001166_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001166_14_1 * 2) + 37) & 63;
  int stage_v_150_2 = ((pub_r001166_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_76_1 + (pub_r001166_5_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_76_2 + (pub_r001166_5_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((pub_r001166_10_1 * 2) + 20) & 63;
  int stage_v_152_2 = ((pub_r001166_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((stage_v_141_1 + (pub_r001166_11_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_141_2 + (pub_r001166_11_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_0_1 + (pub_r001166_3_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_0_2 + (pub_r001166_3_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((stage_v_114_1 + (pub_r001166_12_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_114_2 + (pub_r001166_12_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001166_9_1 * 2) + 47) & 63;
  int stage_v_156_2 = ((pub_r001166_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_0_1 + (pub_r001166_15_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_0_2 + (pub_r001166_15_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((pub_r001166_14_1 * 2) + 19) & 63;
  int stage_v_158_2 = ((pub_r001166_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((stage_v_51_1 + (pub_r001166_1_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_51_2 + (pub_r001166_1_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((pub_r001166_18_1 * 2) + 27) & 63;
  int stage_v_160_2 = ((pub_r001166_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001166_3_1 * 2) + 44) & 63;
  int stage_v_161_2 = ((pub_r001166_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001166_15_1 * 2) + 16) & 63;
  int stage_v_162_2 = ((pub_r001166_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001166_17_1 * 2) + 45) & 63;
  int stage_v_163_2 = ((pub_r001166_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_123_1 + (pub_r001166_14_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_123_2 + (pub_r001166_14_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_0_1 + (pub_r001166_10_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_0_2 + (pub_r001166_10_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((pub_r001166_6_1 * 2) + 31) & 63;
  int stage_v_166_2 = ((pub_r001166_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((sec_r001166_17_1 + (pub_r001166_13_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((sec_r001166_17_2 + (pub_r001166_13_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_153_1 + (pub_r001166_10_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_153_2 + (pub_r001166_10_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((pub_r001166_11_1 * 2) + 23) & 63;
  int stage_v_169_2 = ((pub_r001166_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001166_18_1 * 2) + 45) & 63;
  int stage_v_170_2 = ((pub_r001166_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_35_1 + (pub_r001166_14_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_35_2 + (pub_r001166_14_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_127_1 + (pub_r001166_8_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_127_2 + (pub_r001166_8_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_155_1 + (pub_r001166_15_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_155_2 + (pub_r001166_15_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_128_1 + (pub_r001166_18_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_128_2 + (pub_r001166_18_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((pub_r001166_0_1 * 2) + 44) & 63;
  int stage_v_175_2 = ((pub_r001166_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((stage_v_129_1 + (pub_r001166_19_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_129_2 + (pub_r001166_19_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((sec_r001166_8_1 + (pub_r001166_2_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((sec_r001166_8_2 + (pub_r001166_2_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((sec_r001166_18_1 + (pub_r001166_16_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((sec_r001166_18_2 + (pub_r001166_16_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_81_1 + (pub_r001166_0_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_81_2 + (pub_r001166_0_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_155_1 + (pub_r001166_8_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_155_2 + (pub_r001166_8_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_67_1 + (pub_r001166_19_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_67_2 + (pub_r001166_19_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((helper_flow_5_1 + (pub_r001166_6_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((helper_flow_5_2 + (pub_r001166_6_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_26_1 + (pub_r001166_19_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_26_2 + (pub_r001166_19_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((pub_r001166_16_1 * 2) + 48) & 63;
  int stage_v_184_2 = ((pub_r001166_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001166_19_1 * 2) + 46) & 63;
  int stage_v_185_2 = ((pub_r001166_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_58_1 + (pub_r001166_3_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_58_2 + (pub_r001166_3_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_180_1 + (pub_r001166_7_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_180_2 + (pub_r001166_7_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001166_0_1 * 2) + 45) & 63;
  int stage_v_188_2 = ((pub_r001166_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_128_1 + (pub_r001166_1_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_128_2 + (pub_r001166_1_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001166_4_1 * 2) + 34) & 63;
  int stage_v_190_2 = ((pub_r001166_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((helper_flow_6_1 + (pub_r001166_18_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((helper_flow_6_2 + (pub_r001166_18_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((pub_r001166_0_1 * 2) + 14) & 63;
  int stage_v_192_2 = ((pub_r001166_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_12_1 + (pub_r001166_5_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_12_2 + (pub_r001166_5_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_43_1 + (pub_r001166_7_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_43_2 + (pub_r001166_7_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_92_1 + (pub_r001166_10_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_92_2 + (pub_r001166_10_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001166_8_1 * 2) + 42) & 63;
  int stage_v_196_2 = ((pub_r001166_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_40_1 + (pub_r001166_16_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_40_2 + (pub_r001166_16_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_58_1 + (pub_r001166_5_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_58_2 + (pub_r001166_5_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((pub_r001166_12_1 * 2) + 49) & 63;
  int stage_v_199_2 = ((pub_r001166_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_186_1 + (pub_r001166_17_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_186_2 + (pub_r001166_17_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((pub_r001166_18_1 * 2) + 13) & 63;
  int stage_v_201_2 = ((pub_r001166_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001166_1_1 * 2) + 39) & 63;
  int stage_v_202_2 = ((pub_r001166_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((stage_v_126_1 + (pub_r001166_0_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_126_2 + (pub_r001166_0_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((pub_r001166_7_1 * 2) + 23) & 63;
  int stage_v_204_2 = ((pub_r001166_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001166_13_1 * 2) + 12) & 63;
  int stage_v_205_2 = ((pub_r001166_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((stage_v_20_1 + (pub_r001166_9_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_20_2 + (pub_r001166_9_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((sec_r001166_6_1 + (pub_r001166_4_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((sec_r001166_6_2 + (pub_r001166_4_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((sec_r001166_16_1 + (pub_r001166_19_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((sec_r001166_16_2 + (pub_r001166_19_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_131_1 + (pub_r001166_7_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_131_2 + (pub_r001166_7_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((sec_r001166_2_1 + (pub_r001166_17_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((sec_r001166_2_2 + (pub_r001166_17_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((pub_r001166_16_1 * 2) + 32) & 63;
  int stage_v_211_2 = ((pub_r001166_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001166_1_1 * 2) + 39) & 63;
  int stage_v_212_2 = ((pub_r001166_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001166_16_1 * 2) + 30) & 63;
  int stage_v_213_2 = ((pub_r001166_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001166_13_1 * 2) + 37) & 63;
  int stage_v_214_2 = ((pub_r001166_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001166_11_1 * 2) + 46) & 63;
  int stage_v_215_2 = ((pub_r001166_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_139_1 + (pub_r001166_14_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_139_2 + (pub_r001166_14_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((pub_r001166_10_1 * 2) + 41) & 63;
  int stage_v_217_2 = ((pub_r001166_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_165_1 + (pub_r001166_18_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_165_2 + (pub_r001166_18_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_123_1 + (pub_r001166_8_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_123_2 + (pub_r001166_8_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_186_1 + (pub_r001166_12_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_186_2 + (pub_r001166_12_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((sec_r001166_5_1 + (pub_r001166_10_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((sec_r001166_5_2 + (pub_r001166_10_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((pub_r001166_7_1 * 2) + 31) & 63;
  int stage_v_222_2 = ((pub_r001166_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((stage_v_28_1 + (pub_r001166_19_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_28_2 + (pub_r001166_19_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((pub_r001166_4_1 * 2) + 38) & 63;
  int stage_v_224_2 = ((pub_r001166_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001166_7_1 * 2) + 26) & 63;
  int stage_v_225_2 = ((pub_r001166_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((stage_v_53_1 + (pub_r001166_16_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_53_2 + (pub_r001166_16_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((pub_r001166_17_1 * 2) + 6) & 63;
  int stage_v_227_2 = ((pub_r001166_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((stage_v_86_1 + (pub_r001166_5_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_86_2 + (pub_r001166_5_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((pub_r001166_15_1 * 2) + 38) & 63;
  int stage_v_229_2 = ((pub_r001166_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_207_1 + (pub_r001166_5_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_207_2 + (pub_r001166_5_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_53_1 + (pub_r001166_3_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_53_2 + (pub_r001166_3_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((stage_v_72_1 + (pub_r001166_0_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_72_2 + (pub_r001166_0_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((pub_r001166_17_1 * 2) + 6) & 63;
  int stage_v_233_2 = ((pub_r001166_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001166_4_1 * 2) + 25) & 63;
  int stage_v_234_2 = ((pub_r001166_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((sec_r001166_11_1 + (pub_r001166_8_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((sec_r001166_11_2 + (pub_r001166_8_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((pub_r001166_6_1 * 2) + 20) & 63;
  int stage_v_236_2 = ((pub_r001166_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((stage_v_84_1 + (pub_r001166_15_1 * 2)) + 716) & 127;
  int stage_v_237_2 = ((stage_v_84_2 + (pub_r001166_15_2 * 2)) + 716) & 127;
  if (stage_v_237_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_237_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_237_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_237_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_238_1 = ((stage_v_20_1 + (pub_r001166_5_1 * 2)) + 719) & 127;
  int stage_v_238_2 = ((stage_v_20_2 + (pub_r001166_5_2 * 2)) + 719) & 127;
  if (stage_v_238_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_238_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_238_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_238_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_239_1 = ((stage_v_62_1 + (pub_r001166_0_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((stage_v_62_2 + (pub_r001166_0_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((stage_v_174_1 + (pub_r001166_18_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((stage_v_174_2 + (pub_r001166_18_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((pub_r001166_17_1 * 2) + 42) & 63;
  int stage_v_241_2 = ((pub_r001166_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((stage_v_221_1 + (pub_r001166_1_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((stage_v_221_2 + (pub_r001166_1_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((pub_r001166_10_1 * 2) + 30) & 63;
  int stage_v_243_2 = ((pub_r001166_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001166_13_1 * 2) + 8) & 63;
  int stage_v_244_2 = ((pub_r001166_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((sec_r001166_11_1 + (pub_r001166_5_1 * 2)) + 740) & 127;
  int stage_v_245_2 = ((sec_r001166_11_2 + (pub_r001166_5_2 * 2)) + 740) & 127;
  if (stage_v_245_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_245_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_245_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_245_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_245_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_245_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_245_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_245_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_246_1 = ((pub_r001166_4_1 * 2) + 28) & 63;
  int stage_v_246_2 = ((pub_r001166_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001166_2_1 * 2) + 16) & 63;
  int stage_v_247_2 = ((pub_r001166_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((helper_flow_7_1 + (pub_r001166_5_1 * 2)) + 749) & 127;
  int stage_v_248_2 = ((helper_flow_7_2 + (pub_r001166_5_2 * 2)) + 749) & 127;
  if (stage_v_248_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_248_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_248_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_248_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_249_1 = ((pub_r001166_15_1 * 2) + 30) & 63;
  int stage_v_249_2 = ((pub_r001166_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((stage_v_177_1 + (pub_r001166_19_1 * 2)) + 755) & 127;
  int stage_v_250_2 = ((stage_v_177_2 + (pub_r001166_19_2 * 2)) + 755) & 127;
  if (stage_v_250_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_250_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_250_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_250_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_251_1 = ((stage_v_51_1 + (pub_r001166_4_1 * 2)) + 758) & 127;
  int stage_v_251_2 = ((stage_v_51_2 + (pub_r001166_4_2 * 2)) + 758) & 127;
  if (stage_v_251_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_251_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_251_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_251_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_252_1 = ((stage_v_0_1 + (pub_r001166_0_1 * 2)) + 761) & 127;
  int stage_v_252_2 = ((stage_v_0_2 + (pub_r001166_0_2 * 2)) + 761) & 127;
  if (stage_v_252_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_252_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_252_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_252_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_252_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_252_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_252_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_252_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_253_1 = ((stage_v_180_1 + (pub_r001166_3_1 * 2)) + 764) & 127;
  int stage_v_253_2 = ((stage_v_180_2 + (pub_r001166_3_2 * 2)) + 764) & 127;
  if (stage_v_253_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_253_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_253_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_253_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_253_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_253_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_253_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_253_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_254_1 = ((stage_v_7_1 + (pub_r001166_1_1 * 2)) + 767) & 127;
  int stage_v_254_2 = ((stage_v_7_2 + (pub_r001166_1_2 * 2)) + 767) & 127;
  if (stage_v_254_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_254_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_254_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_254_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_254_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_254_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_254_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_254_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_255_1 = ((stage_v_130_1 + (pub_r001166_5_1 * 2)) + 770) & 127;
  int stage_v_255_2 = ((stage_v_130_2 + (pub_r001166_5_2 * 2)) + 770) & 127;
  if (stage_v_255_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_255_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_255_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_255_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_255_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_255_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_255_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_255_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_256_1 = ((stage_v_200_1 + (pub_r001166_18_1 * 2)) + 773) & 127;
  int stage_v_256_2 = ((stage_v_200_2 + (pub_r001166_18_2 * 2)) + 773) & 127;
  if (stage_v_256_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_256_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_256_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_256_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_256_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_256_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_256_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_256_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_257_1 = ((stage_v_187_1 + (pub_r001166_3_1 * 2)) + 776) & 127;
  int stage_v_257_2 = ((stage_v_187_2 + (pub_r001166_3_2 * 2)) + 776) & 127;
  if (stage_v_257_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_257_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_257_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_257_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_257_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_257_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_257_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_257_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_258_1 = ((helper_flow_4_1 + (pub_r001166_17_1 * 2)) + 779) & 127;
  int stage_v_258_2 = ((helper_flow_4_2 + (pub_r001166_17_2 * 2)) + 779) & 127;
  if (stage_v_258_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_258_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_258_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_258_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_258_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_258_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_258_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_258_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_259_1 = ((pub_r001166_6_1 * 2) + 47) & 63;
  int stage_v_259_2 = ((pub_r001166_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001166_11_1 * 2) + 6) & 63;
  int stage_v_260_2 = ((pub_r001166_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001166_14_1 * 2) + 34) & 63;
  int stage_v_261_2 = ((pub_r001166_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001166_16_1 * 2) + 29) & 63;
  int stage_v_262_2 = ((pub_r001166_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((stage_v_73_1 + (pub_r001166_2_1 * 2)) + 794) & 127;
  int stage_v_263_2 = ((stage_v_73_2 + (pub_r001166_2_2 * 2)) + 794) & 127;
  if (stage_v_263_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_263_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_263_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_263_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_263_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_263_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_263_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_263_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001166_16_1 == pub_r001166_16_2);
  __CPROVER_assume(pub_r001166_2_1 == pub_r001166_2_2);
  __CPROVER_assume(sec_r001166_3_1 != sec_r001166_3_2);
  __CPROVER_assume(sec_r001166_16_1 != sec_r001166_16_2);
  __CPROVER_assume(sec_r001166_13_1 != sec_r001166_13_2);
  __CPROVER_assume(sec_r001166_18_1 != sec_r001166_18_2);
  __CPROVER_assume(pub_r001166_12_1 == pub_r001166_12_2);
  __CPROVER_assume(sec_r001166_10_1 != sec_r001166_10_2);
  __CPROVER_assume(pub_r001166_0_1 == pub_r001166_0_2);
  __CPROVER_assume(sec_r001166_8_1 != sec_r001166_8_2);
  __CPROVER_assume(pub_r001166_15_1 == pub_r001166_15_2);
  __CPROVER_assume(pub_r001166_5_1 == pub_r001166_5_2);
  __CPROVER_assume(sec_r001166_19_1 != sec_r001166_19_2);
  __CPROVER_assume(pub_r001166_3_1 == pub_r001166_3_2);
  __CPROVER_assume(sec_r001166_0_1 != sec_r001166_0_2);
  __CPROVER_assume(pub_r001166_11_1 == pub_r001166_11_2);
  __CPROVER_assume(pub_r001166_17_1 == pub_r001166_17_2);
  __CPROVER_assume(pub_r001166_14_1 == pub_r001166_14_2);
  __CPROVER_assume(pub_r001166_18_1 == pub_r001166_18_2);
  __CPROVER_assume(sec_r001166_1_1 != sec_r001166_1_2);
  __CPROVER_assume(sec_r001166_14_1 != sec_r001166_14_2);
  __CPROVER_assume(pub_r001166_13_1 == pub_r001166_13_2);
  __CPROVER_assume(sec_r001166_4_1 != sec_r001166_4_2);
  __CPROVER_assume(sec_r001166_6_1 != sec_r001166_6_2);
  __CPROVER_assume(sec_r001166_7_1 != sec_r001166_7_2);
  __CPROVER_assume(pub_r001166_1_1 == pub_r001166_1_2);
  __CPROVER_assume(pub_r001166_7_1 == pub_r001166_7_2);
  __CPROVER_assume(pub_r001166_4_1 == pub_r001166_4_2);
  __CPROVER_assume(pub_r001166_9_1 == pub_r001166_9_2);
  __CPROVER_assume(pub_r001166_6_1 == pub_r001166_6_2);
  __CPROVER_assume(sec_r001166_5_1 != sec_r001166_5_2);
  __CPROVER_assume(sec_r001166_11_1 != sec_r001166_11_2);
  __CPROVER_assume(sec_r001166_20_1 != sec_r001166_20_2);
  __CPROVER_assume(pub_r001166_19_1 == pub_r001166_19_2);
  __CPROVER_assume(pub_r001166_10_1 == pub_r001166_10_2);
  __CPROVER_assume(sec_r001166_17_1 != sec_r001166_17_2);
  __CPROVER_assume(sec_r001166_12_1 != sec_r001166_12_2);
  __CPROVER_assume(sec_r001166_2_1 != sec_r001166_2_2);
  __CPROVER_assume(pub_r001166_8_1 == pub_r001166_8_2);
  __CPROVER_assume(sec_r001166_9_1 != sec_r001166_9_2);
  __CPROVER_assume(sec_r001166_15_1 != sec_r001166_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.density == st_var_2_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.gain_db == st_var_3_2.gain_db);
  assert(st_var_3_1.cutoff == st_var_3_2.cutoff);
  assert(st_var_3_1.prev_in == st_var_3_2.prev_in);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
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
}


