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
struct Vector3D_R000269_6913_0
{
  int pitch;
  short coord_x;
  int heading;
  int buffer[3];
};
struct SensorNode_R000269_6913_1
{
  unsigned char threshold;
  int status;
  short calib;
  int offset;
  unsigned char reading;
  int gain;
  int buffer[3];
};
struct CipherContext_R000269_6913_2
{
  int iv;
  short flags;
  int tag;
  int round_key;
  int buffer[3];
};
struct FilterState_R000269_6913_3
{
  int prev_in;
  int cutoff;
  int damping;
  int buffer[3];
};
union TelemetryField_R000269_6913_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000269_6913_1
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
void fn_R000269_6913_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st_1 = {0};
  struct SensorNode_R000269_6913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_77_1 = local_arr_1[aux_1 % 3];
  int offset_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_77_2 * 2)) & 127;
  int cursor_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_76_1) & 63;
  aux_2 = (aux_2 + cursor_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_64_1 > 31)
  {
    acc_1 = ((acc_1 + (threshold_64_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_64_2 > 31)
  {
    acc_2 = ((acc_2 + (threshold_64_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_77_1 == offset_77_2);
  assert(cursor_76_1 == cursor_76_2);
  assert(threshold_64_1 == threshold_64_2);
}

int fn_R000269_6913_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int offset_77 = local_arr[aux % 3];
  acc = (acc + (offset_77 * 2)) & 127;
  int cursor_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_76) & 63;
  acc ^= aux;
  int threshold_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_64 > 31)
  {
    acc = ((acc + (threshold_64 * 2)) + 5) & 127;
    aux ^= threshold_64 & 15;
  }
  else
  {
    acc = ((acc - threshold_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000269_6913_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000269_6913_3 st_1 = {0};
  struct FilterState_R000269_6913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int pivot_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_22_1)
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

  switch (pivot_22_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_22_1 == pivot_22_2);
}

int fn_R000269_6913_1(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000269_6913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int pivot_22 = (aux + st.buffer[1]) & 3;
  switch (pivot_22)
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
  return (acc + aux) & 255;
}

void fn_R000269_6913_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st_1 = {0};
  struct SensorNode_R000269_6913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_27_1 = local_arr_1[aux_1 % 3];
  int bound_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_27_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_27_1 == bound_27_2);
}

int fn_R000269_6913_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int bound_27 = local_arr[aux % 3];
  acc = (acc + (bound_27 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000269_6913_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st_1 = {0};
  struct SensorNode_R000269_6913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int threshold_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_92_1)
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

  switch (threshold_92_2)
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
  int parity_16_1 = local_arr_1[aux_1 % 3];
  int parity_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_92_1 == threshold_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_16_1 == parity_16_2);
}

int fn_R000269_6913_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int threshold_92 = (aux + st.buffer[1]) & 3;
  switch (threshold_92)
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
  int parity_16 = local_arr[aux % 3];
  acc = (acc + (parity_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000269_6913_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st_1 = {0};
  struct SensorNode_R000269_6913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_75_1 > 35)
  {
    acc_1 = ((acc_1 + (residue_75_1 * 2)) + 5) & 127;
    aux_1 ^= residue_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_75_2 > 35)
  {
    acc_2 = ((acc_2 + (residue_75_2 * 2)) + 5) & 127;
    aux_2 ^= residue_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_60_1) & 63;
  aux_2 = (aux_2 + weight_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_11_1 = local_arr_1[aux_1 % 3];
  int accumulator_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_75_1 == residue_75_2);
  assert(weight_60_1 == weight_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_11_1 == accumulator_11_2);
}

int fn_R000269_6913_4(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_75 > 35)
  {
    acc = ((acc + (residue_75 * 2)) + 5) & 127;
    aux ^= residue_75 & 15;
  }
  else
  {
    acc = ((acc - residue_75) + 11) & 127;
    aux += 3;
  }
  int weight_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_60) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_11 = local_arr[aux % 3];
  acc = (acc + (accumulator_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000269_6913_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000269_6913_0 st_1 = {0};
  struct Vector3D_R000269_6913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_83_1 = local_arr_1[aux_1 % 3];
  int index_reg_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_83_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_83_1 == index_reg_83_2);
}

int fn_R000269_6913_5(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000269_6913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int index_reg_83 = local_arr[aux % 3];
  acc = (acc + (index_reg_83 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000269_6913_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000269_6913_2 st_1 = {0};
  struct CipherContext_R000269_6913_2 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_80_1 = local_arr_1[aux_1 % 3];
  int delta_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_80_2 * 2)) & 127;
  int index_reg_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_13_1 > 10)
  {
    acc_1 = ((acc_1 + (index_reg_13_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_13_2 > 10)
  {
    acc_2 = ((acc_2 + (index_reg_13_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_22_1) & 63;
  aux_2 = (aux_2 + threshold_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_80_1 == delta_80_2);
  assert(index_reg_13_1 == index_reg_13_2);
  assert(threshold_22_1 == threshold_22_2);
}

int fn_R000269_6913_6(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000269_6913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_80 = local_arr[aux % 3];
  acc = (acc + (delta_80 * 2)) & 127;
  int index_reg_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_13 > 10)
  {
    acc = ((acc + (index_reg_13 * 2)) + 5) & 127;
    aux ^= index_reg_13 & 15;
  }
  else
  {
    acc = ((acc - index_reg_13) + 11) & 127;
    aux += 3;
  }
  int threshold_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000269_6913_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st_1 = {0};
  struct SensorNode_R000269_6913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int threshold_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_71_1 > 25)
  {
    acc_1 = ((acc_1 + (threshold_71_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_71_2 > 25)
  {
    acc_2 = ((acc_2 + (threshold_71_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_71_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_89_1 = local_arr_1[aux_1 % 3];
  int scale_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_71_1 == threshold_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_89_1 == scale_89_2);
}

int fn_R000269_6913_7(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000269_6913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int threshold_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_71 > 25)
  {
    acc = ((acc + (threshold_71 * 2)) + 5) & 127;
    aux ^= threshold_71 & 15;
  }
  else
  {
    acc = ((acc - threshold_71) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_89 = local_arr[aux % 3];
  acc = (acc + (scale_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000269_6913_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000269_6913_0 st_1 = {0};
  struct Vector3D_R000269_6913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int sample_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_26_1) & 63;
  aux_2 = (aux_2 + sample_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_33_1 > 11)
  {
    acc_1 = ((acc_1 + (anchor_33_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_33_2 > 11)
  {
    acc_2 = ((acc_2 + (anchor_33_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_33_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_26_1 == sample_26_2);
  assert(anchor_33_1 == anchor_33_2);
}

int fn_R000269_6913_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000269_6913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int sample_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_26) & 63;
  acc ^= aux;
  int anchor_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_33 > 11)
  {
    acc = ((acc + (anchor_33 * 2)) + 5) & 127;
    aux ^= anchor_33 & 15;
  }
  else
  {
    acc = ((acc - anchor_33) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000269_6913_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000269_6913_2 st_1 = {0};
  struct CipherContext_R000269_6913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_30_1 = local_arr_1[aux_1 % 3];
  int offset_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_30_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_82_1) & 63;
  aux_2 = (aux_2 + phase_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_57_1 > 43)
  {
    acc_1 = ((acc_1 + (quantum_57_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_57_2 > 43)
  {
    acc_2 = ((acc_2 + (quantum_57_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_30_1 == offset_30_2);
  assert(phase_82_1 == phase_82_2);
  assert(quantum_57_1 == quantum_57_2);
}

int fn_R000269_6913_9(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000269_6913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int offset_30 = local_arr[aux % 3];
  acc = (acc + (offset_30 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_82) & 63;
  acc ^= aux;
  int quantum_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_57 > 43)
  {
    acc = ((acc + (quantum_57 * 2)) + 5) & 127;
    aux ^= quantum_57 & 15;
  }
  else
  {
    acc = ((acc - quantum_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000269_6913_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000269_6913_0 st_1 = {0};
  struct Vector3D_R000269_6913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int delta_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_91_1) & 63;
  aux_2 = (aux_2 + delta_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_68_1)
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

  switch (sample_68_2)
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

  int window_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_77_1 > 35)
  {
    acc_1 = ((acc_1 + (window_77_1 * 2)) + 5) & 127;
    aux_1 ^= window_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_77_2 > 35)
  {
    acc_2 = ((acc_2 + (window_77_2 * 2)) + 5) & 127;
    aux_2 ^= window_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_91_1 == delta_91_2);
  assert(sample_68_1 == sample_68_2);
  assert(window_77_1 == window_77_2);
}

int fn_R000269_6913_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000269_6913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int delta_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_91) & 63;
  acc ^= aux;
  int sample_68 = (aux + st.buffer[1]) & 3;
  switch (sample_68)
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

  int window_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_77 > 35)
  {
    acc = ((acc + (window_77 * 2)) + 5) & 127;
    aux ^= window_77 & 15;
  }
  else
  {
    acc = ((acc - window_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000269_6913_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000269_6913_0 st_1 = {0};
  struct Vector3D_R000269_6913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int residue_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_51_1) & 63;
  aux_2 = (aux_2 + residue_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_92_1 = local_arr_1[aux_1 % 3];
  int metric_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_92_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_79_1 > 40)
  {
    acc_1 = ((acc_1 + (vector_79_1 * 2)) + 5) & 127;
    aux_1 ^= vector_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_79_2 > 40)
  {
    acc_2 = ((acc_2 + (vector_79_2 * 2)) + 5) & 127;
    aux_2 ^= vector_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_51_1 == residue_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_92_1 == metric_92_2);
  assert(vector_79_1 == vector_79_2);
}

int fn_R000269_6913_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000269_6913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int residue_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_51) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_92 = local_arr[aux % 3];
  acc = (acc + (metric_92 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_79 > 40)
  {
    acc = ((acc + (vector_79 * 2)) + 5) & 127;
    aux ^= vector_79 & 15;
  }
  else
  {
    acc = ((acc - vector_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000269_6913_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000269_6913_3 st_1 = {0};
  struct FilterState_R000269_6913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int margin_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_54_1) & 63;
  aux_2 = (aux_2 + margin_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_57_1)
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

  switch (tally_57_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_81_1 > 17)
  {
    acc_1 = ((acc_1 + (quantum_81_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_81_2 > 17)
  {
    acc_2 = ((acc_2 + (quantum_81_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_54_1 == margin_54_2);
  assert(tally_57_1 == tally_57_2);
  assert(quantum_81_1 == quantum_81_2);
}

int fn_R000269_6913_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000269_6913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int margin_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_54) & 63;
  acc ^= aux;
  int tally_57 = (aux + st.buffer[1]) & 3;
  switch (tally_57)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_81 > 17)
  {
    acc = ((acc + (quantum_81 * 2)) + 5) & 127;
    aux ^= quantum_81 & 15;
  }
  else
  {
    acc = ((acc - quantum_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000269_6913_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000269_6913_2 st_1 = {0};
  struct CipherContext_R000269_6913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int residue_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_39_1) & 63;
  aux_2 = (aux_2 + residue_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_62_1 = local_arr_1[aux_1 % 3];
  int pivot_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_39_1 == residue_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_62_1 == pivot_62_2);
}

int fn_R000269_6913_13(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000269_6913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int residue_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_39) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_62 = local_arr[aux % 3];
  acc = (acc + (pivot_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000269_0_1;
  int sec_r000269_0_2;
  int sec_r000269_1_1;
  int sec_r000269_1_2;
  int sec_r000269_2_1;
  int sec_r000269_2_2;
  int sec_r000269_3_1;
  int sec_r000269_3_2;
  int sec_r000269_4_1;
  int sec_r000269_4_2;
  int sec_r000269_5_1;
  int sec_r000269_5_2;
  int sec_r000269_6_1;
  int sec_r000269_6_2;
  int sec_r000269_7_1;
  int sec_r000269_7_2;
  int sec_r000269_8_1;
  int sec_r000269_8_2;
  int sec_r000269_9_1;
  int sec_r000269_9_2;
  int sec_r000269_10_1;
  int sec_r000269_10_2;
  int sec_r000269_11_1;
  int sec_r000269_11_2;
  int sec_r000269_12_1;
  int sec_r000269_12_2;
  int sec_r000269_13_1;
  int sec_r000269_13_2;
  int sec_r000269_14_1;
  int sec_r000269_14_2;
  int sec_r000269_15_1;
  int sec_r000269_15_2;
  int pub_r000269_0_1;
  int pub_r000269_0_2;
  int pub_r000269_1_1;
  int pub_r000269_1_2;
  int pub_r000269_2_1;
  int pub_r000269_2_2;
  int pub_r000269_3_1;
  int pub_r000269_3_2;
  int pub_r000269_4_1;
  int pub_r000269_4_2;
  int pub_r000269_5_1;
  int pub_r000269_5_2;
  int pub_r000269_6_1;
  int pub_r000269_6_2;
  int pub_r000269_7_1;
  int pub_r000269_7_2;
  int pub_r000269_8_1;
  int pub_r000269_8_2;
  int pub_r000269_9_1;
  int pub_r000269_9_2;
  int pub_r000269_10_1;
  int pub_r000269_10_2;
  int pub_r000269_11_1;
  int pub_r000269_11_2;
  int pub_r000269_12_1;
  int pub_r000269_12_2;
  int pub_r000269_13_1;
  int pub_r000269_13_2;
  int pub_r000269_14_1;
  int pub_r000269_14_2;
  int pub_r000269_15_1;
  int pub_r000269_15_2;
  int pub_r000269_16_1;
  int pub_r000269_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000269_0_1 >= (-100)) && (pub_r000269_0_1 <= 100));
  __CPROVER_assume((pub_r000269_0_2 >= (-100)) && (pub_r000269_0_2 <= 100));
  __CPROVER_assume((pub_r000269_1_1 >= (-100)) && (pub_r000269_1_1 <= 100));
  __CPROVER_assume((pub_r000269_1_2 >= (-100)) && (pub_r000269_1_2 <= 100));
  __CPROVER_assume((pub_r000269_2_1 >= (-100)) && (pub_r000269_2_1 <= 100));
  __CPROVER_assume((pub_r000269_2_2 >= (-100)) && (pub_r000269_2_2 <= 100));
  __CPROVER_assume((pub_r000269_3_1 >= (-100)) && (pub_r000269_3_1 <= 100));
  __CPROVER_assume((pub_r000269_3_2 >= (-100)) && (pub_r000269_3_2 <= 100));
  __CPROVER_assume((pub_r000269_4_1 >= (-100)) && (pub_r000269_4_1 <= 100));
  __CPROVER_assume((pub_r000269_4_2 >= (-100)) && (pub_r000269_4_2 <= 100));
  __CPROVER_assume((pub_r000269_5_1 >= (-100)) && (pub_r000269_5_1 <= 100));
  __CPROVER_assume((pub_r000269_5_2 >= (-100)) && (pub_r000269_5_2 <= 100));
  __CPROVER_assume((pub_r000269_6_1 >= (-100)) && (pub_r000269_6_1 <= 100));
  __CPROVER_assume((pub_r000269_6_2 >= (-100)) && (pub_r000269_6_2 <= 100));
  __CPROVER_assume((pub_r000269_7_1 >= (-100)) && (pub_r000269_7_1 <= 100));
  __CPROVER_assume((pub_r000269_7_2 >= (-100)) && (pub_r000269_7_2 <= 100));
  __CPROVER_assume((pub_r000269_8_1 >= (-100)) && (pub_r000269_8_1 <= 100));
  __CPROVER_assume((pub_r000269_8_2 >= (-100)) && (pub_r000269_8_2 <= 100));
  __CPROVER_assume((pub_r000269_9_1 >= (-100)) && (pub_r000269_9_1 <= 100));
  __CPROVER_assume((pub_r000269_9_2 >= (-100)) && (pub_r000269_9_2 <= 100));
  __CPROVER_assume((pub_r000269_10_1 >= (-100)) && (pub_r000269_10_1 <= 100));
  __CPROVER_assume((pub_r000269_10_2 >= (-100)) && (pub_r000269_10_2 <= 100));
  __CPROVER_assume((pub_r000269_11_1 >= (-100)) && (pub_r000269_11_1 <= 100));
  __CPROVER_assume((pub_r000269_11_2 >= (-100)) && (pub_r000269_11_2 <= 100));
  __CPROVER_assume((pub_r000269_12_1 >= (-100)) && (pub_r000269_12_1 <= 100));
  __CPROVER_assume((pub_r000269_12_2 >= (-100)) && (pub_r000269_12_2 <= 100));
  __CPROVER_assume((pub_r000269_13_1 >= (-100)) && (pub_r000269_13_1 <= 100));
  __CPROVER_assume((pub_r000269_13_2 >= (-100)) && (pub_r000269_13_2 <= 100));
  __CPROVER_assume((pub_r000269_14_1 >= (-100)) && (pub_r000269_14_1 <= 100));
  __CPROVER_assume((pub_r000269_14_2 >= (-100)) && (pub_r000269_14_2 <= 100));
  __CPROVER_assume((pub_r000269_15_1 >= (-100)) && (pub_r000269_15_1 <= 100));
  __CPROVER_assume((pub_r000269_15_2 >= (-100)) && (pub_r000269_15_2 <= 100));
  __CPROVER_assume((pub_r000269_16_1 >= (-100)) && (pub_r000269_16_1 <= 100));
  __CPROVER_assume((pub_r000269_16_2 >= (-100)) && (pub_r000269_16_2 <= 100));
  __CPROVER_assume((sec_r000269_0_1 >= 0) && (sec_r000269_0_1 <= 255));
  __CPROVER_assume((sec_r000269_0_2 >= 0) && (sec_r000269_0_2 <= 255));
  __CPROVER_assume((sec_r000269_1_1 >= 0) && (sec_r000269_1_1 <= 255));
  __CPROVER_assume((sec_r000269_1_2 >= 0) && (sec_r000269_1_2 <= 255));
  __CPROVER_assume((sec_r000269_2_1 >= 0) && (sec_r000269_2_1 <= 255));
  __CPROVER_assume((sec_r000269_2_2 >= 0) && (sec_r000269_2_2 <= 255));
  __CPROVER_assume((sec_r000269_3_1 >= 0) && (sec_r000269_3_1 <= 255));
  __CPROVER_assume((sec_r000269_3_2 >= 0) && (sec_r000269_3_2 <= 255));
  __CPROVER_assume((sec_r000269_4_1 >= 0) && (sec_r000269_4_1 <= 255));
  __CPROVER_assume((sec_r000269_4_2 >= 0) && (sec_r000269_4_2 <= 255));
  __CPROVER_assume((sec_r000269_5_1 >= 0) && (sec_r000269_5_1 <= 255));
  __CPROVER_assume((sec_r000269_5_2 >= 0) && (sec_r000269_5_2 <= 255));
  __CPROVER_assume((sec_r000269_6_1 >= 0) && (sec_r000269_6_1 <= 255));
  __CPROVER_assume((sec_r000269_6_2 >= 0) && (sec_r000269_6_2 <= 255));
  __CPROVER_assume((sec_r000269_7_1 >= 0) && (sec_r000269_7_1 <= 255));
  __CPROVER_assume((sec_r000269_7_2 >= 0) && (sec_r000269_7_2 <= 255));
  __CPROVER_assume((sec_r000269_8_1 >= 0) && (sec_r000269_8_1 <= 255));
  __CPROVER_assume((sec_r000269_8_2 >= 0) && (sec_r000269_8_2 <= 255));
  __CPROVER_assume((sec_r000269_9_1 >= 0) && (sec_r000269_9_1 <= 255));
  __CPROVER_assume((sec_r000269_9_2 >= 0) && (sec_r000269_9_2 <= 255));
  __CPROVER_assume((sec_r000269_10_1 >= 0) && (sec_r000269_10_1 <= 255));
  __CPROVER_assume((sec_r000269_10_2 >= 0) && (sec_r000269_10_2 <= 255));
  __CPROVER_assume((sec_r000269_11_1 >= 0) && (sec_r000269_11_1 <= 255));
  __CPROVER_assume((sec_r000269_11_2 >= 0) && (sec_r000269_11_2 <= 255));
  __CPROVER_assume((sec_r000269_12_1 >= 0) && (sec_r000269_12_1 <= 255));
  __CPROVER_assume((sec_r000269_12_2 >= 0) && (sec_r000269_12_2 <= 255));
  __CPROVER_assume((sec_r000269_13_1 >= 0) && (sec_r000269_13_1 <= 255));
  __CPROVER_assume((sec_r000269_13_2 >= 0) && (sec_r000269_13_2 <= 255));
  __CPROVER_assume((sec_r000269_14_1 >= 0) && (sec_r000269_14_1 <= 255));
  __CPROVER_assume((sec_r000269_14_2 >= 0) && (sec_r000269_14_2 <= 255));
  __CPROVER_assume((sec_r000269_15_1 >= 0) && (sec_r000269_15_1 <= 255));
  __CPROVER_assume((sec_r000269_15_2 >= 0) && (sec_r000269_15_2 <= 255));
  struct Vector3D_R000269_6913_0 st_var_0_1 = {0};
  struct Vector3D_R000269_6913_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000269_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000269_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000269_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000269_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000269_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000269_0_2 + 7) & 15;
  struct SensorNode_R000269_6913_1 st_var_1_1 = {0};
  struct SensorNode_R000269_6913_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000269_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000269_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000269_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000269_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000269_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000269_0_2 + 9) & 15;
  struct CipherContext_R000269_6913_2 st_var_2_1 = {0};
  struct CipherContext_R000269_6913_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000269_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000269_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000269_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000269_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000269_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000269_0_2 + 11) & 15;
  struct FilterState_R000269_6913_3 st_var_3_1 = {0};
  struct FilterState_R000269_6913_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000269_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000269_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000269_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000269_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000269_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000269_0_2 + 13) & 15;
  union TelemetryField_R000269_6913_0 u_var_1;
  union TelemetryField_R000269_6913_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = (st_var_3_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_3_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 48)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 48)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 42)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 42)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = (st_var_3_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_3_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 32) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 45)
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
  if (stage_v_33_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 45)
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 35) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 26)
    {
      chk_sum_1 ^= stage_v_37_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_37_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 26)
    {
      chk_sum_2 ^= stage_v_37_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 55)
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
  if (stage_v_39_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 55)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int s_idx_42_1 = sec_r000269_5_1 & 3;
  int s_idx_42_2 = sec_r000269_5_2 & 3;
  int stage_v_42_1 = (table_1[s_idx_42_1] + pub_r000269_2_1) & 127;
  int stage_v_42_2 = (table_2[s_idx_42_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_42_1] = (stage_v_42_1 + 7) & 63;
  table_2[s_idx_42_2] = (stage_v_42_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int s_idx_43_1 = stage_v_42_1 & 3;
  int s_idx_43_2 = stage_v_42_2 & 3;
  int stage_v_43_1 = (table_1[s_idx_43_1] + pub_r000269_11_1) & 127;
  int stage_v_43_2 = (table_2[s_idx_43_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_43_1] = (stage_v_43_1 + 7) & 63;
  table_2[s_idx_43_2] = (stage_v_43_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int s_idx_44_1 = sec_r000269_13_1 & 3;
  int s_idx_44_2 = sec_r000269_13_2 & 3;
  int stage_v_44_1 = (table_1[s_idx_44_1] + pub_r000269_0_1) & 127;
  int stage_v_44_2 = (table_2[s_idx_44_2] + pub_r000269_0_2) & 127;
  table_1[s_idx_44_1] = (stage_v_44_1 + 7) & 63;
  table_2[s_idx_44_2] = (stage_v_44_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int s_idx_45_1 = sec_r000269_7_1 & 3;
  int s_idx_45_2 = sec_r000269_7_2 & 3;
  int stage_v_45_1 = (table_1[s_idx_45_1] + pub_r000269_13_1) & 127;
  int stage_v_45_2 = (table_2[s_idx_45_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_45_1] = (stage_v_45_1 + 7) & 63;
  table_2[s_idx_45_2] = (stage_v_45_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int s_idx_46_1 = sec_r000269_15_1 & 3;
  int s_idx_46_2 = sec_r000269_15_2 & 3;
  int stage_v_46_1 = (table_1[s_idx_46_1] + pub_r000269_13_1) & 127;
  int stage_v_46_2 = (table_2[s_idx_46_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_46_1] = (stage_v_46_1 + 7) & 63;
  table_2[s_idx_46_2] = (stage_v_46_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int s_idx_47_1 = stage_v_43_1 & 3;
  int s_idx_47_2 = stage_v_43_2 & 3;
  int stage_v_47_1 = (table_1[s_idx_47_1] + pub_r000269_9_1) & 127;
  int stage_v_47_2 = (table_2[s_idx_47_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_47_1] = (stage_v_47_1 + 7) & 63;
  table_2[s_idx_47_2] = (stage_v_47_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int s_idx_48_1 = sec_r000269_10_1 & 3;
  int s_idx_48_2 = sec_r000269_10_2 & 3;
  int stage_v_48_1 = (table_1[s_idx_48_1] + pub_r000269_3_1) & 127;
  int stage_v_48_2 = (table_2[s_idx_48_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_48_1] = (stage_v_48_1 + 7) & 63;
  table_2[s_idx_48_2] = (stage_v_48_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int s_idx_49_1 = stage_v_42_1 & 3;
  int s_idx_49_2 = stage_v_42_2 & 3;
  int stage_v_49_1 = (table_1[s_idx_49_1] + pub_r000269_14_1) & 127;
  int stage_v_49_2 = (table_2[s_idx_49_2] + pub_r000269_14_2) & 127;
  table_1[s_idx_49_1] = (stage_v_49_1 + 7) & 63;
  table_2[s_idx_49_2] = (stage_v_49_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int s_idx_50_1 = stage_v_48_1 & 3;
  int s_idx_50_2 = stage_v_48_2 & 3;
  int stage_v_50_1 = (table_1[s_idx_50_1] + pub_r000269_10_1) & 127;
  int stage_v_50_2 = (table_2[s_idx_50_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_50_1] = (stage_v_50_1 + 7) & 63;
  table_2[s_idx_50_2] = (stage_v_50_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int s_idx_51_1 = sec_r000269_11_1 & 3;
  int s_idx_51_2 = sec_r000269_11_2 & 3;
  int stage_v_51_1 = (table_1[s_idx_51_1] + pub_r000269_7_1) & 127;
  int stage_v_51_2 = (table_2[s_idx_51_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_51_1] = (stage_v_51_1 + 7) & 63;
  table_2[s_idx_51_2] = (stage_v_51_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int s_idx_52_1 = stage_v_50_1 & 3;
  int s_idx_52_2 = stage_v_50_2 & 3;
  int stage_v_52_1 = (table_1[s_idx_52_1] + pub_r000269_6_1) & 127;
  int stage_v_52_2 = (table_2[s_idx_52_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_52_1] = (stage_v_52_1 + 7) & 63;
  table_2[s_idx_52_2] = (stage_v_52_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int s_idx_53_1 = stage_v_48_1 & 3;
  int s_idx_53_2 = stage_v_48_2 & 3;
  int stage_v_53_1 = (table_1[s_idx_53_1] + pub_r000269_15_1) & 127;
  int stage_v_53_2 = (table_2[s_idx_53_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_53_1] = (stage_v_53_1 + 7) & 63;
  table_2[s_idx_53_2] = (stage_v_53_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int s_idx_54_1 = sec_r000269_1_1 & 3;
  int s_idx_54_2 = sec_r000269_1_2 & 3;
  int stage_v_54_1 = (table_1[s_idx_54_1] + pub_r000269_11_1) & 127;
  int stage_v_54_2 = (table_2[s_idx_54_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_54_1] = (stage_v_54_1 + 7) & 63;
  table_2[s_idx_54_2] = (stage_v_54_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int s_idx_55_1 = stage_v_50_1 & 3;
  int s_idx_55_2 = stage_v_50_2 & 3;
  int stage_v_55_1 = (table_1[s_idx_55_1] + pub_r000269_11_1) & 127;
  int stage_v_55_2 = (table_2[s_idx_55_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_55_1] = (stage_v_55_1 + 7) & 63;
  table_2[s_idx_55_2] = (stage_v_55_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int s_idx_56_1 = stage_v_48_1 & 3;
  int s_idx_56_2 = stage_v_48_2 & 3;
  int stage_v_56_1 = (table_1[s_idx_56_1] + pub_r000269_13_1) & 127;
  int stage_v_56_2 = (table_2[s_idx_56_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_56_1] = (stage_v_56_1 + 7) & 63;
  table_2[s_idx_56_2] = (stage_v_56_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int s_idx_57_1 = sec_r000269_1_1 & 3;
  int s_idx_57_2 = sec_r000269_1_2 & 3;
  int stage_v_57_1 = (table_1[s_idx_57_1] + pub_r000269_15_1) & 127;
  int stage_v_57_2 = (table_2[s_idx_57_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_57_1] = (stage_v_57_1 + 7) & 63;
  table_2[s_idx_57_2] = (stage_v_57_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int s_idx_58_1 = sec_r000269_10_1 & 3;
  int s_idx_58_2 = sec_r000269_10_2 & 3;
  int stage_v_58_1 = (table_1[s_idx_58_1] + pub_r000269_6_1) & 127;
  int stage_v_58_2 = (table_2[s_idx_58_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_58_1] = (stage_v_58_1 + 7) & 63;
  table_2[s_idx_58_2] = (stage_v_58_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int s_idx_59_1 = stage_v_48_1 & 3;
  int s_idx_59_2 = stage_v_48_2 & 3;
  int stage_v_59_1 = (table_1[s_idx_59_1] + pub_r000269_3_1) & 127;
  int stage_v_59_2 = (table_2[s_idx_59_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_59_1] = (stage_v_59_1 + 7) & 63;
  table_2[s_idx_59_2] = (stage_v_59_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int s_idx_60_1 = sec_r000269_9_1 & 3;
  int s_idx_60_2 = sec_r000269_9_2 & 3;
  int stage_v_60_1 = (table_1[s_idx_60_1] + pub_r000269_5_1) & 127;
  int stage_v_60_2 = (table_2[s_idx_60_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_60_1] = (stage_v_60_1 + 7) & 63;
  table_2[s_idx_60_2] = (stage_v_60_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int s_idx_61_1 = stage_v_56_1 & 3;
  int s_idx_61_2 = stage_v_56_2 & 3;
  int stage_v_61_1 = (table_1[s_idx_61_1] + pub_r000269_6_1) & 127;
  int stage_v_61_2 = (table_2[s_idx_61_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_61_1] = (stage_v_61_1 + 7) & 63;
  table_2[s_idx_61_2] = (stage_v_61_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int s_idx_62_1 = stage_v_42_1 & 3;
  int s_idx_62_2 = stage_v_42_2 & 3;
  int stage_v_62_1 = (table_1[s_idx_62_1] + pub_r000269_12_1) & 127;
  int stage_v_62_2 = (table_2[s_idx_62_2] + pub_r000269_12_2) & 127;
  table_1[s_idx_62_1] = (stage_v_62_1 + 7) & 63;
  table_2[s_idx_62_2] = (stage_v_62_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int s_idx_63_1 = stage_v_54_1 & 3;
  int s_idx_63_2 = stage_v_54_2 & 3;
  int stage_v_63_1 = (table_1[s_idx_63_1] + pub_r000269_4_1) & 127;
  int stage_v_63_2 = (table_2[s_idx_63_2] + pub_r000269_4_2) & 127;
  table_1[s_idx_63_1] = (stage_v_63_1 + 7) & 63;
  table_2[s_idx_63_2] = (stage_v_63_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int s_idx_64_1 = sec_r000269_9_1 & 3;
  int s_idx_64_2 = sec_r000269_9_2 & 3;
  int stage_v_64_1 = (table_1[s_idx_64_1] + pub_r000269_15_1) & 127;
  int stage_v_64_2 = (table_2[s_idx_64_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_64_1] = (stage_v_64_1 + 7) & 63;
  table_2[s_idx_64_2] = (stage_v_64_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int s_idx_65_1 = stage_v_57_1 & 3;
  int s_idx_65_2 = stage_v_57_2 & 3;
  int stage_v_65_1 = (table_1[s_idx_65_1] + pub_r000269_3_1) & 127;
  int stage_v_65_2 = (table_2[s_idx_65_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_65_1] = (stage_v_65_1 + 7) & 63;
  table_2[s_idx_65_2] = (stage_v_65_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int s_idx_66_1 = sec_r000269_4_1 & 3;
  int s_idx_66_2 = sec_r000269_4_2 & 3;
  int stage_v_66_1 = (table_1[s_idx_66_1] + pub_r000269_6_1) & 127;
  int stage_v_66_2 = (table_2[s_idx_66_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_66_1] = (stage_v_66_1 + 7) & 63;
  table_2[s_idx_66_2] = (stage_v_66_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int s_idx_67_1 = stage_v_48_1 & 3;
  int s_idx_67_2 = stage_v_48_2 & 3;
  int stage_v_67_1 = (table_1[s_idx_67_1] + pub_r000269_4_1) & 127;
  int stage_v_67_2 = (table_2[s_idx_67_2] + pub_r000269_4_2) & 127;
  table_1[s_idx_67_1] = (stage_v_67_1 + 7) & 63;
  table_2[s_idx_67_2] = (stage_v_67_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int s_idx_68_1 = sec_r000269_9_1 & 3;
  int s_idx_68_2 = sec_r000269_9_2 & 3;
  int stage_v_68_1 = (table_1[s_idx_68_1] + pub_r000269_9_1) & 127;
  int stage_v_68_2 = (table_2[s_idx_68_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_68_1] = (stage_v_68_1 + 7) & 63;
  table_2[s_idx_68_2] = (stage_v_68_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int s_idx_69_1 = stage_v_43_1 & 3;
  int s_idx_69_2 = stage_v_43_2 & 3;
  int stage_v_69_1 = (table_1[s_idx_69_1] + pub_r000269_15_1) & 127;
  int stage_v_69_2 = (table_2[s_idx_69_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_69_1] = (stage_v_69_1 + 7) & 63;
  table_2[s_idx_69_2] = (stage_v_69_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int s_idx_70_1 = stage_v_47_1 & 3;
  int s_idx_70_2 = stage_v_47_2 & 3;
  int stage_v_70_1 = (table_1[s_idx_70_1] + pub_r000269_3_1) & 127;
  int stage_v_70_2 = (table_2[s_idx_70_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_70_1] = (stage_v_70_1 + 7) & 63;
  table_2[s_idx_70_2] = (stage_v_70_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int s_idx_71_1 = sec_r000269_1_1 & 3;
  int s_idx_71_2 = sec_r000269_1_2 & 3;
  int stage_v_71_1 = (table_1[s_idx_71_1] + pub_r000269_13_1) & 127;
  int stage_v_71_2 = (table_2[s_idx_71_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_71_1] = (stage_v_71_1 + 7) & 63;
  table_2[s_idx_71_2] = (stage_v_71_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int s_idx_72_1 = stage_v_65_1 & 3;
  int s_idx_72_2 = stage_v_65_2 & 3;
  int stage_v_72_1 = (table_1[s_idx_72_1] + pub_r000269_15_1) & 127;
  int stage_v_72_2 = (table_2[s_idx_72_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_72_1] = (stage_v_72_1 + 7) & 63;
  table_2[s_idx_72_2] = (stage_v_72_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int s_idx_73_1 = stage_v_72_1 & 3;
  int s_idx_73_2 = stage_v_72_2 & 3;
  int stage_v_73_1 = (table_1[s_idx_73_1] + pub_r000269_0_1) & 127;
  int stage_v_73_2 = (table_2[s_idx_73_2] + pub_r000269_0_2) & 127;
  table_1[s_idx_73_1] = (stage_v_73_1 + 7) & 63;
  table_2[s_idx_73_2] = (stage_v_73_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int s_idx_74_1 = sec_r000269_15_1 & 3;
  int s_idx_74_2 = sec_r000269_15_2 & 3;
  int stage_v_74_1 = (table_1[s_idx_74_1] + pub_r000269_7_1) & 127;
  int stage_v_74_2 = (table_2[s_idx_74_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_74_1] = (stage_v_74_1 + 7) & 63;
  table_2[s_idx_74_2] = (stage_v_74_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int s_idx_75_1 = stage_v_64_1 & 3;
  int s_idx_75_2 = stage_v_64_2 & 3;
  int stage_v_75_1 = (table_1[s_idx_75_1] + pub_r000269_6_1) & 127;
  int stage_v_75_2 = (table_2[s_idx_75_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_75_1] = (stage_v_75_1 + 7) & 63;
  table_2[s_idx_75_2] = (stage_v_75_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int s_idx_76_1 = stage_v_57_1 & 3;
  int s_idx_76_2 = stage_v_57_2 & 3;
  int stage_v_76_1 = (table_1[s_idx_76_1] + pub_r000269_5_1) & 127;
  int stage_v_76_2 = (table_2[s_idx_76_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_76_1] = (stage_v_76_1 + 7) & 63;
  table_2[s_idx_76_2] = (stage_v_76_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int s_idx_77_1 = sec_r000269_0_1 & 3;
  int s_idx_77_2 = sec_r000269_0_2 & 3;
  int stage_v_77_1 = (table_1[s_idx_77_1] + pub_r000269_8_1) & 127;
  int stage_v_77_2 = (table_2[s_idx_77_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_77_1] = (stage_v_77_1 + 7) & 63;
  table_2[s_idx_77_2] = (stage_v_77_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int s_idx_78_1 = stage_v_67_1 & 3;
  int s_idx_78_2 = stage_v_67_2 & 3;
  int stage_v_78_1 = (table_1[s_idx_78_1] + pub_r000269_15_1) & 127;
  int stage_v_78_2 = (table_2[s_idx_78_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_78_1] = (stage_v_78_1 + 7) & 63;
  table_2[s_idx_78_2] = (stage_v_78_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int s_idx_79_1 = stage_v_54_1 & 3;
  int s_idx_79_2 = stage_v_54_2 & 3;
  int stage_v_79_1 = (table_1[s_idx_79_1] + pub_r000269_12_1) & 127;
  int stage_v_79_2 = (table_2[s_idx_79_2] + pub_r000269_12_2) & 127;
  table_1[s_idx_79_1] = (stage_v_79_1 + 7) & 63;
  table_2[s_idx_79_2] = (stage_v_79_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int s_idx_80_1 = sec_r000269_7_1 & 3;
  int s_idx_80_2 = sec_r000269_7_2 & 3;
  int stage_v_80_1 = (table_1[s_idx_80_1] + pub_r000269_15_1) & 127;
  int stage_v_80_2 = (table_2[s_idx_80_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_80_1] = (stage_v_80_1 + 7) & 63;
  table_2[s_idx_80_2] = (stage_v_80_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int s_idx_81_1 = stage_v_71_1 & 3;
  int s_idx_81_2 = stage_v_71_2 & 3;
  int stage_v_81_1 = (table_1[s_idx_81_1] + pub_r000269_12_1) & 127;
  int stage_v_81_2 = (table_2[s_idx_81_2] + pub_r000269_12_2) & 127;
  table_1[s_idx_81_1] = (stage_v_81_1 + 7) & 63;
  table_2[s_idx_81_2] = (stage_v_81_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int s_idx_82_1 = sec_r000269_8_1 & 3;
  int s_idx_82_2 = sec_r000269_8_2 & 3;
  int stage_v_82_1 = (table_1[s_idx_82_1] + pub_r000269_7_1) & 127;
  int stage_v_82_2 = (table_2[s_idx_82_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_82_1] = (stage_v_82_1 + 7) & 63;
  table_2[s_idx_82_2] = (stage_v_82_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int s_idx_83_1 = stage_v_49_1 & 3;
  int s_idx_83_2 = stage_v_49_2 & 3;
  int stage_v_83_1 = (table_1[s_idx_83_1] + pub_r000269_5_1) & 127;
  int stage_v_83_2 = (table_2[s_idx_83_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_83_1] = (stage_v_83_1 + 7) & 63;
  table_2[s_idx_83_2] = (stage_v_83_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int s_idx_84_1 = sec_r000269_1_1 & 3;
  int s_idx_84_2 = sec_r000269_1_2 & 3;
  int stage_v_84_1 = (table_1[s_idx_84_1] + pub_r000269_8_1) & 127;
  int stage_v_84_2 = (table_2[s_idx_84_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_84_1] = (stage_v_84_1 + 7) & 63;
  table_2[s_idx_84_2] = (stage_v_84_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int s_idx_85_1 = sec_r000269_3_1 & 3;
  int s_idx_85_2 = sec_r000269_3_2 & 3;
  int stage_v_85_1 = (table_1[s_idx_85_1] + pub_r000269_8_1) & 127;
  int stage_v_85_2 = (table_2[s_idx_85_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_85_1] = (stage_v_85_1 + 7) & 63;
  table_2[s_idx_85_2] = (stage_v_85_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int s_idx_86_1 = stage_v_43_1 & 3;
  int s_idx_86_2 = stage_v_43_2 & 3;
  int stage_v_86_1 = (table_1[s_idx_86_1] + pub_r000269_3_1) & 127;
  int stage_v_86_2 = (table_2[s_idx_86_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_86_1] = (stage_v_86_1 + 7) & 63;
  table_2[s_idx_86_2] = (stage_v_86_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int s_idx_87_1 = stage_v_80_1 & 3;
  int s_idx_87_2 = stage_v_80_2 & 3;
  int stage_v_87_1 = (table_1[s_idx_87_1] + pub_r000269_8_1) & 127;
  int stage_v_87_2 = (table_2[s_idx_87_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_87_1] = (stage_v_87_1 + 7) & 63;
  table_2[s_idx_87_2] = (stage_v_87_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int s_idx_88_1 = sec_r000269_1_1 & 3;
  int s_idx_88_2 = sec_r000269_1_2 & 3;
  int stage_v_88_1 = (table_1[s_idx_88_1] + pub_r000269_3_1) & 127;
  int stage_v_88_2 = (table_2[s_idx_88_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_88_1] = (stage_v_88_1 + 7) & 63;
  table_2[s_idx_88_2] = (stage_v_88_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int s_idx_89_1 = stage_v_52_1 & 3;
  int s_idx_89_2 = stage_v_52_2 & 3;
  int stage_v_89_1 = (table_1[s_idx_89_1] + pub_r000269_7_1) & 127;
  int stage_v_89_2 = (table_2[s_idx_89_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_89_1] = (stage_v_89_1 + 7) & 63;
  table_2[s_idx_89_2] = (stage_v_89_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int s_idx_90_1 = sec_r000269_14_1 & 3;
  int s_idx_90_2 = sec_r000269_14_2 & 3;
  int stage_v_90_1 = (table_1[s_idx_90_1] + pub_r000269_1_1) & 127;
  int stage_v_90_2 = (table_2[s_idx_90_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_90_1] = (stage_v_90_1 + 7) & 63;
  table_2[s_idx_90_2] = (stage_v_90_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int s_idx_91_1 = sec_r000269_7_1 & 3;
  int s_idx_91_2 = sec_r000269_7_2 & 3;
  int stage_v_91_1 = (table_1[s_idx_91_1] + pub_r000269_16_1) & 127;
  int stage_v_91_2 = (table_2[s_idx_91_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_91_1] = (stage_v_91_1 + 7) & 63;
  table_2[s_idx_91_2] = (stage_v_91_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int s_idx_92_1 = sec_r000269_14_1 & 3;
  int s_idx_92_2 = sec_r000269_14_2 & 3;
  int stage_v_92_1 = (table_1[s_idx_92_1] + pub_r000269_2_1) & 127;
  int stage_v_92_2 = (table_2[s_idx_92_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_92_1] = (stage_v_92_1 + 7) & 63;
  table_2[s_idx_92_2] = (stage_v_92_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int s_idx_93_1 = stage_v_49_1 & 3;
  int s_idx_93_2 = stage_v_49_2 & 3;
  int stage_v_93_1 = (table_1[s_idx_93_1] + pub_r000269_13_1) & 127;
  int stage_v_93_2 = (table_2[s_idx_93_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_93_1] = (stage_v_93_1 + 7) & 63;
  table_2[s_idx_93_2] = (stage_v_93_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int s_idx_94_1 = sec_r000269_11_1 & 3;
  int s_idx_94_2 = sec_r000269_11_2 & 3;
  int stage_v_94_1 = (table_1[s_idx_94_1] + pub_r000269_4_1) & 127;
  int stage_v_94_2 = (table_2[s_idx_94_2] + pub_r000269_4_2) & 127;
  table_1[s_idx_94_1] = (stage_v_94_1 + 7) & 63;
  table_2[s_idx_94_2] = (stage_v_94_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int s_idx_95_1 = stage_v_58_1 & 3;
  int s_idx_95_2 = stage_v_58_2 & 3;
  int stage_v_95_1 = (table_1[s_idx_95_1] + pub_r000269_15_1) & 127;
  int stage_v_95_2 = (table_2[s_idx_95_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_95_1] = (stage_v_95_1 + 7) & 63;
  table_2[s_idx_95_2] = (stage_v_95_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int s_idx_96_1 = sec_r000269_10_1 & 3;
  int s_idx_96_2 = sec_r000269_10_2 & 3;
  int stage_v_96_1 = (table_1[s_idx_96_1] + pub_r000269_16_1) & 127;
  int stage_v_96_2 = (table_2[s_idx_96_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_96_1] = (stage_v_96_1 + 7) & 63;
  table_2[s_idx_96_2] = (stage_v_96_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int s_idx_97_1 = stage_v_73_1 & 3;
  int s_idx_97_2 = stage_v_73_2 & 3;
  int stage_v_97_1 = (table_1[s_idx_97_1] + pub_r000269_13_1) & 127;
  int stage_v_97_2 = (table_2[s_idx_97_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_97_1] = (stage_v_97_1 + 7) & 63;
  table_2[s_idx_97_2] = (stage_v_97_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int s_idx_98_1 = stage_v_78_1 & 3;
  int s_idx_98_2 = stage_v_78_2 & 3;
  int stage_v_98_1 = (table_1[s_idx_98_1] + pub_r000269_15_1) & 127;
  int stage_v_98_2 = (table_2[s_idx_98_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_98_1] = (stage_v_98_1 + 7) & 63;
  table_2[s_idx_98_2] = (stage_v_98_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int s_idx_99_1 = stage_v_53_1 & 3;
  int s_idx_99_2 = stage_v_53_2 & 3;
  int stage_v_99_1 = (table_1[s_idx_99_1] + pub_r000269_4_1) & 127;
  int stage_v_99_2 = (table_2[s_idx_99_2] + pub_r000269_4_2) & 127;
  table_1[s_idx_99_1] = (stage_v_99_1 + 7) & 63;
  table_2[s_idx_99_2] = (stage_v_99_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int s_idx_100_1 = stage_v_93_1 & 3;
  int s_idx_100_2 = stage_v_93_2 & 3;
  int stage_v_100_1 = (table_1[s_idx_100_1] + pub_r000269_5_1) & 127;
  int stage_v_100_2 = (table_2[s_idx_100_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_100_1] = (stage_v_100_1 + 7) & 63;
  table_2[s_idx_100_2] = (stage_v_100_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int s_idx_101_1 = sec_r000269_3_1 & 3;
  int s_idx_101_2 = sec_r000269_3_2 & 3;
  int stage_v_101_1 = (table_1[s_idx_101_1] + pub_r000269_10_1) & 127;
  int stage_v_101_2 = (table_2[s_idx_101_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_101_1] = (stage_v_101_1 + 7) & 63;
  table_2[s_idx_101_2] = (stage_v_101_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int s_idx_102_1 = sec_r000269_6_1 & 3;
  int s_idx_102_2 = sec_r000269_6_2 & 3;
  int stage_v_102_1 = (table_1[s_idx_102_1] + pub_r000269_16_1) & 127;
  int stage_v_102_2 = (table_2[s_idx_102_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_102_1] = (stage_v_102_1 + 7) & 63;
  table_2[s_idx_102_2] = (stage_v_102_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int s_idx_103_1 = stage_v_90_1 & 3;
  int s_idx_103_2 = stage_v_90_2 & 3;
  int stage_v_103_1 = (table_1[s_idx_103_1] + pub_r000269_8_1) & 127;
  int stage_v_103_2 = (table_2[s_idx_103_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_103_1] = (stage_v_103_1 + 7) & 63;
  table_2[s_idx_103_2] = (stage_v_103_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int s_idx_104_1 = stage_v_47_1 & 3;
  int s_idx_104_2 = stage_v_47_2 & 3;
  int stage_v_104_1 = (table_1[s_idx_104_1] + pub_r000269_15_1) & 127;
  int stage_v_104_2 = (table_2[s_idx_104_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_104_1] = (stage_v_104_1 + 7) & 63;
  table_2[s_idx_104_2] = (stage_v_104_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int s_idx_105_1 = stage_v_52_1 & 3;
  int s_idx_105_2 = stage_v_52_2 & 3;
  int stage_v_105_1 = (table_1[s_idx_105_1] + pub_r000269_6_1) & 127;
  int stage_v_105_2 = (table_2[s_idx_105_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_105_1] = (stage_v_105_1 + 7) & 63;
  table_2[s_idx_105_2] = (stage_v_105_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int s_idx_106_1 = stage_v_96_1 & 3;
  int s_idx_106_2 = stage_v_96_2 & 3;
  int stage_v_106_1 = (table_1[s_idx_106_1] + pub_r000269_13_1) & 127;
  int stage_v_106_2 = (table_2[s_idx_106_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_106_1] = (stage_v_106_1 + 7) & 63;
  table_2[s_idx_106_2] = (stage_v_106_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int s_idx_107_1 = sec_r000269_1_1 & 3;
  int s_idx_107_2 = sec_r000269_1_2 & 3;
  int stage_v_107_1 = (table_1[s_idx_107_1] + pub_r000269_14_1) & 127;
  int stage_v_107_2 = (table_2[s_idx_107_2] + pub_r000269_14_2) & 127;
  table_1[s_idx_107_1] = (stage_v_107_1 + 7) & 63;
  table_2[s_idx_107_2] = (stage_v_107_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int s_idx_108_1 = sec_r000269_14_1 & 3;
  int s_idx_108_2 = sec_r000269_14_2 & 3;
  int stage_v_108_1 = (table_1[s_idx_108_1] + pub_r000269_16_1) & 127;
  int stage_v_108_2 = (table_2[s_idx_108_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_108_1] = (stage_v_108_1 + 7) & 63;
  table_2[s_idx_108_2] = (stage_v_108_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int s_idx_109_1 = stage_v_89_1 & 3;
  int s_idx_109_2 = stage_v_89_2 & 3;
  int stage_v_109_1 = (table_1[s_idx_109_1] + pub_r000269_2_1) & 127;
  int stage_v_109_2 = (table_2[s_idx_109_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_109_1] = (stage_v_109_1 + 7) & 63;
  table_2[s_idx_109_2] = (stage_v_109_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int s_idx_110_1 = stage_v_98_1 & 3;
  int s_idx_110_2 = stage_v_98_2 & 3;
  int stage_v_110_1 = (table_1[s_idx_110_1] + pub_r000269_11_1) & 127;
  int stage_v_110_2 = (table_2[s_idx_110_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_110_1] = (stage_v_110_1 + 7) & 63;
  table_2[s_idx_110_2] = (stage_v_110_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int s_idx_111_1 = stage_v_55_1 & 3;
  int s_idx_111_2 = stage_v_55_2 & 3;
  int stage_v_111_1 = (table_1[s_idx_111_1] + pub_r000269_6_1) & 127;
  int stage_v_111_2 = (table_2[s_idx_111_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_111_1] = (stage_v_111_1 + 7) & 63;
  table_2[s_idx_111_2] = (stage_v_111_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int s_idx_112_1 = stage_v_87_1 & 3;
  int s_idx_112_2 = stage_v_87_2 & 3;
  int stage_v_112_1 = (table_1[s_idx_112_1] + pub_r000269_15_1) & 127;
  int stage_v_112_2 = (table_2[s_idx_112_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_112_1] = (stage_v_112_1 + 7) & 63;
  table_2[s_idx_112_2] = (stage_v_112_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int s_idx_113_1 = sec_r000269_6_1 & 3;
  int s_idx_113_2 = sec_r000269_6_2 & 3;
  int stage_v_113_1 = (table_1[s_idx_113_1] + pub_r000269_2_1) & 127;
  int stage_v_113_2 = (table_2[s_idx_113_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_113_1] = (stage_v_113_1 + 7) & 63;
  table_2[s_idx_113_2] = (stage_v_113_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int s_idx_114_1 = stage_v_56_1 & 3;
  int s_idx_114_2 = stage_v_56_2 & 3;
  int stage_v_114_1 = (table_1[s_idx_114_1] + pub_r000269_5_1) & 127;
  int stage_v_114_2 = (table_2[s_idx_114_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_114_1] = (stage_v_114_1 + 7) & 63;
  table_2[s_idx_114_2] = (stage_v_114_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int s_idx_115_1 = stage_v_45_1 & 3;
  int s_idx_115_2 = stage_v_45_2 & 3;
  int stage_v_115_1 = (table_1[s_idx_115_1] + pub_r000269_9_1) & 127;
  int stage_v_115_2 = (table_2[s_idx_115_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_115_1] = (stage_v_115_1 + 7) & 63;
  table_2[s_idx_115_2] = (stage_v_115_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int s_idx_116_1 = stage_v_43_1 & 3;
  int s_idx_116_2 = stage_v_43_2 & 3;
  int stage_v_116_1 = (table_1[s_idx_116_1] + pub_r000269_13_1) & 127;
  int stage_v_116_2 = (table_2[s_idx_116_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_116_1] = (stage_v_116_1 + 7) & 63;
  table_2[s_idx_116_2] = (stage_v_116_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int s_idx_117_1 = stage_v_51_1 & 3;
  int s_idx_117_2 = stage_v_51_2 & 3;
  int stage_v_117_1 = (table_1[s_idx_117_1] + pub_r000269_11_1) & 127;
  int stage_v_117_2 = (table_2[s_idx_117_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_117_1] = (stage_v_117_1 + 7) & 63;
  table_2[s_idx_117_2] = (stage_v_117_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int s_idx_118_1 = sec_r000269_15_1 & 3;
  int s_idx_118_2 = sec_r000269_15_2 & 3;
  int stage_v_118_1 = (table_1[s_idx_118_1] + pub_r000269_12_1) & 127;
  int stage_v_118_2 = (table_2[s_idx_118_2] + pub_r000269_12_2) & 127;
  table_1[s_idx_118_1] = (stage_v_118_1 + 7) & 63;
  table_2[s_idx_118_2] = (stage_v_118_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int s_idx_119_1 = stage_v_81_1 & 3;
  int s_idx_119_2 = stage_v_81_2 & 3;
  int stage_v_119_1 = (table_1[s_idx_119_1] + pub_r000269_16_1) & 127;
  int stage_v_119_2 = (table_2[s_idx_119_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_119_1] = (stage_v_119_1 + 7) & 63;
  table_2[s_idx_119_2] = (stage_v_119_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int s_idx_120_1 = sec_r000269_7_1 & 3;
  int s_idx_120_2 = sec_r000269_7_2 & 3;
  int stage_v_120_1 = (table_1[s_idx_120_1] + pub_r000269_8_1) & 127;
  int stage_v_120_2 = (table_2[s_idx_120_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_120_1] = (stage_v_120_1 + 7) & 63;
  table_2[s_idx_120_2] = (stage_v_120_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int s_idx_121_1 = stage_v_65_1 & 3;
  int s_idx_121_2 = stage_v_65_2 & 3;
  int stage_v_121_1 = (table_1[s_idx_121_1] + pub_r000269_8_1) & 127;
  int stage_v_121_2 = (table_2[s_idx_121_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_121_1] = (stage_v_121_1 + 7) & 63;
  table_2[s_idx_121_2] = (stage_v_121_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int s_idx_122_1 = stage_v_94_1 & 3;
  int s_idx_122_2 = stage_v_94_2 & 3;
  int stage_v_122_1 = (table_1[s_idx_122_1] + pub_r000269_3_1) & 127;
  int stage_v_122_2 = (table_2[s_idx_122_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_122_1] = (stage_v_122_1 + 7) & 63;
  table_2[s_idx_122_2] = (stage_v_122_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int s_idx_123_1 = sec_r000269_13_1 & 3;
  int s_idx_123_2 = sec_r000269_13_2 & 3;
  int stage_v_123_1 = (table_1[s_idx_123_1] + pub_r000269_9_1) & 127;
  int stage_v_123_2 = (table_2[s_idx_123_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_123_1] = (stage_v_123_1 + 7) & 63;
  table_2[s_idx_123_2] = (stage_v_123_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int s_idx_124_1 = sec_r000269_5_1 & 3;
  int s_idx_124_2 = sec_r000269_5_2 & 3;
  int stage_v_124_1 = (table_1[s_idx_124_1] + pub_r000269_2_1) & 127;
  int stage_v_124_2 = (table_2[s_idx_124_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_124_1] = (stage_v_124_1 + 7) & 63;
  table_2[s_idx_124_2] = (stage_v_124_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int s_idx_125_1 = sec_r000269_6_1 & 3;
  int s_idx_125_2 = sec_r000269_6_2 & 3;
  int stage_v_125_1 = (table_1[s_idx_125_1] + pub_r000269_13_1) & 127;
  int stage_v_125_2 = (table_2[s_idx_125_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_125_1] = (stage_v_125_1 + 7) & 63;
  table_2[s_idx_125_2] = (stage_v_125_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int s_idx_126_1 = stage_v_99_1 & 3;
  int s_idx_126_2 = stage_v_99_2 & 3;
  int stage_v_126_1 = (table_1[s_idx_126_1] + pub_r000269_16_1) & 127;
  int stage_v_126_2 = (table_2[s_idx_126_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_126_1] = (stage_v_126_1 + 7) & 63;
  table_2[s_idx_126_2] = (stage_v_126_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int s_idx_127_1 = stage_v_70_1 & 3;
  int s_idx_127_2 = stage_v_70_2 & 3;
  int stage_v_127_1 = (table_1[s_idx_127_1] + pub_r000269_1_1) & 127;
  int stage_v_127_2 = (table_2[s_idx_127_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_127_1] = (stage_v_127_1 + 7) & 63;
  table_2[s_idx_127_2] = (stage_v_127_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int s_idx_128_1 = sec_r000269_9_1 & 3;
  int s_idx_128_2 = sec_r000269_9_2 & 3;
  int stage_v_128_1 = (table_1[s_idx_128_1] + pub_r000269_10_1) & 127;
  int stage_v_128_2 = (table_2[s_idx_128_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_128_1] = (stage_v_128_1 + 7) & 63;
  table_2[s_idx_128_2] = (stage_v_128_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int s_idx_129_1 = sec_r000269_2_1 & 3;
  int s_idx_129_2 = sec_r000269_2_2 & 3;
  int stage_v_129_1 = (table_1[s_idx_129_1] + pub_r000269_2_1) & 127;
  int stage_v_129_2 = (table_2[s_idx_129_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_129_1] = (stage_v_129_1 + 7) & 63;
  table_2[s_idx_129_2] = (stage_v_129_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int s_idx_130_1 = stage_v_78_1 & 3;
  int s_idx_130_2 = stage_v_78_2 & 3;
  int stage_v_130_1 = (table_1[s_idx_130_1] + pub_r000269_15_1) & 127;
  int stage_v_130_2 = (table_2[s_idx_130_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_130_1] = (stage_v_130_1 + 7) & 63;
  table_2[s_idx_130_2] = (stage_v_130_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int s_idx_131_1 = sec_r000269_15_1 & 3;
  int s_idx_131_2 = sec_r000269_15_2 & 3;
  int stage_v_131_1 = (table_1[s_idx_131_1] + pub_r000269_7_1) & 127;
  int stage_v_131_2 = (table_2[s_idx_131_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_131_1] = (stage_v_131_1 + 7) & 63;
  table_2[s_idx_131_2] = (stage_v_131_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int s_idx_132_1 = sec_r000269_6_1 & 3;
  int s_idx_132_2 = sec_r000269_6_2 & 3;
  int stage_v_132_1 = (table_1[s_idx_132_1] + pub_r000269_4_1) & 127;
  int stage_v_132_2 = (table_2[s_idx_132_2] + pub_r000269_4_2) & 127;
  table_1[s_idx_132_1] = (stage_v_132_1 + 7) & 63;
  table_2[s_idx_132_2] = (stage_v_132_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int s_idx_133_1 = stage_v_131_1 & 3;
  int s_idx_133_2 = stage_v_131_2 & 3;
  int stage_v_133_1 = (table_1[s_idx_133_1] + pub_r000269_10_1) & 127;
  int stage_v_133_2 = (table_2[s_idx_133_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_133_1] = (stage_v_133_1 + 7) & 63;
  table_2[s_idx_133_2] = (stage_v_133_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int s_idx_134_1 = stage_v_95_1 & 3;
  int s_idx_134_2 = stage_v_95_2 & 3;
  int stage_v_134_1 = (table_1[s_idx_134_1] + pub_r000269_16_1) & 127;
  int stage_v_134_2 = (table_2[s_idx_134_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_134_1] = (stage_v_134_1 + 7) & 63;
  table_2[s_idx_134_2] = (stage_v_134_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int s_idx_135_1 = stage_v_113_1 & 3;
  int s_idx_135_2 = stage_v_113_2 & 3;
  int stage_v_135_1 = (table_1[s_idx_135_1] + pub_r000269_10_1) & 127;
  int stage_v_135_2 = (table_2[s_idx_135_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_135_1] = (stage_v_135_1 + 7) & 63;
  table_2[s_idx_135_2] = (stage_v_135_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int s_idx_136_1 = stage_v_68_1 & 3;
  int s_idx_136_2 = stage_v_68_2 & 3;
  int stage_v_136_1 = (table_1[s_idx_136_1] + pub_r000269_14_1) & 127;
  int stage_v_136_2 = (table_2[s_idx_136_2] + pub_r000269_14_2) & 127;
  table_1[s_idx_136_1] = (stage_v_136_1 + 7) & 63;
  table_2[s_idx_136_2] = (stage_v_136_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int s_idx_137_1 = stage_v_112_1 & 3;
  int s_idx_137_2 = stage_v_112_2 & 3;
  int stage_v_137_1 = (table_1[s_idx_137_1] + pub_r000269_12_1) & 127;
  int stage_v_137_2 = (table_2[s_idx_137_2] + pub_r000269_12_2) & 127;
  table_1[s_idx_137_1] = (stage_v_137_1 + 7) & 63;
  table_2[s_idx_137_2] = (stage_v_137_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int s_idx_138_1 = stage_v_71_1 & 3;
  int s_idx_138_2 = stage_v_71_2 & 3;
  int stage_v_138_1 = (table_1[s_idx_138_1] + pub_r000269_9_1) & 127;
  int stage_v_138_2 = (table_2[s_idx_138_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_138_1] = (stage_v_138_1 + 7) & 63;
  table_2[s_idx_138_2] = (stage_v_138_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int s_idx_139_1 = stage_v_126_1 & 3;
  int s_idx_139_2 = stage_v_126_2 & 3;
  int stage_v_139_1 = (table_1[s_idx_139_1] + pub_r000269_11_1) & 127;
  int stage_v_139_2 = (table_2[s_idx_139_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_139_1] = (stage_v_139_1 + 7) & 63;
  table_2[s_idx_139_2] = (stage_v_139_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int s_idx_140_1 = sec_r000269_1_1 & 3;
  int s_idx_140_2 = sec_r000269_1_2 & 3;
  int stage_v_140_1 = (table_1[s_idx_140_1] + pub_r000269_10_1) & 127;
  int stage_v_140_2 = (table_2[s_idx_140_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_140_1] = (stage_v_140_1 + 7) & 63;
  table_2[s_idx_140_2] = (stage_v_140_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int s_idx_141_1 = stage_v_61_1 & 3;
  int s_idx_141_2 = stage_v_61_2 & 3;
  int stage_v_141_1 = (table_1[s_idx_141_1] + pub_r000269_2_1) & 127;
  int stage_v_141_2 = (table_2[s_idx_141_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_141_1] = (stage_v_141_1 + 7) & 63;
  table_2[s_idx_141_2] = (stage_v_141_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int s_idx_142_1 = sec_r000269_2_1 & 3;
  int s_idx_142_2 = sec_r000269_2_2 & 3;
  int stage_v_142_1 = (table_1[s_idx_142_1] + pub_r000269_0_1) & 127;
  int stage_v_142_2 = (table_2[s_idx_142_2] + pub_r000269_0_2) & 127;
  table_1[s_idx_142_1] = (stage_v_142_1 + 7) & 63;
  table_2[s_idx_142_2] = (stage_v_142_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int s_idx_143_1 = stage_v_48_1 & 3;
  int s_idx_143_2 = stage_v_48_2 & 3;
  int stage_v_143_1 = (table_1[s_idx_143_1] + pub_r000269_1_1) & 127;
  int stage_v_143_2 = (table_2[s_idx_143_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_143_1] = (stage_v_143_1 + 7) & 63;
  table_2[s_idx_143_2] = (stage_v_143_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int s_idx_144_1 = stage_v_53_1 & 3;
  int s_idx_144_2 = stage_v_53_2 & 3;
  int stage_v_144_1 = (table_1[s_idx_144_1] + pub_r000269_10_1) & 127;
  int stage_v_144_2 = (table_2[s_idx_144_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_144_1] = (stage_v_144_1 + 7) & 63;
  table_2[s_idx_144_2] = (stage_v_144_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int s_idx_145_1 = sec_r000269_4_1 & 3;
  int s_idx_145_2 = sec_r000269_4_2 & 3;
  int stage_v_145_1 = (table_1[s_idx_145_1] + pub_r000269_9_1) & 127;
  int stage_v_145_2 = (table_2[s_idx_145_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_145_1] = (stage_v_145_1 + 7) & 63;
  table_2[s_idx_145_2] = (stage_v_145_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int s_idx_146_1 = sec_r000269_7_1 & 3;
  int s_idx_146_2 = sec_r000269_7_2 & 3;
  int stage_v_146_1 = (table_1[s_idx_146_1] + pub_r000269_3_1) & 127;
  int stage_v_146_2 = (table_2[s_idx_146_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_146_1] = (stage_v_146_1 + 7) & 63;
  table_2[s_idx_146_2] = (stage_v_146_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int s_idx_147_1 = sec_r000269_5_1 & 3;
  int s_idx_147_2 = sec_r000269_5_2 & 3;
  int stage_v_147_1 = (table_1[s_idx_147_1] + pub_r000269_5_1) & 127;
  int stage_v_147_2 = (table_2[s_idx_147_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_147_1] = (stage_v_147_1 + 7) & 63;
  table_2[s_idx_147_2] = (stage_v_147_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int s_idx_148_1 = stage_v_116_1 & 3;
  int s_idx_148_2 = stage_v_116_2 & 3;
  int stage_v_148_1 = (table_1[s_idx_148_1] + pub_r000269_5_1) & 127;
  int stage_v_148_2 = (table_2[s_idx_148_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_148_1] = (stage_v_148_1 + 7) & 63;
  table_2[s_idx_148_2] = (stage_v_148_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int s_idx_149_1 = stage_v_147_1 & 3;
  int s_idx_149_2 = stage_v_147_2 & 3;
  int stage_v_149_1 = (table_1[s_idx_149_1] + pub_r000269_5_1) & 127;
  int stage_v_149_2 = (table_2[s_idx_149_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_149_1] = (stage_v_149_1 + 7) & 63;
  table_2[s_idx_149_2] = (stage_v_149_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int s_idx_150_1 = stage_v_110_1 & 3;
  int s_idx_150_2 = stage_v_110_2 & 3;
  int stage_v_150_1 = (table_1[s_idx_150_1] + pub_r000269_6_1) & 127;
  int stage_v_150_2 = (table_2[s_idx_150_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_150_1] = (stage_v_150_1 + 7) & 63;
  table_2[s_idx_150_2] = (stage_v_150_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int s_idx_151_1 = stage_v_53_1 & 3;
  int s_idx_151_2 = stage_v_53_2 & 3;
  int stage_v_151_1 = (table_1[s_idx_151_1] + pub_r000269_1_1) & 127;
  int stage_v_151_2 = (table_2[s_idx_151_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_151_1] = (stage_v_151_1 + 7) & 63;
  table_2[s_idx_151_2] = (stage_v_151_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int s_idx_152_1 = stage_v_143_1 & 3;
  int s_idx_152_2 = stage_v_143_2 & 3;
  int stage_v_152_1 = (table_1[s_idx_152_1] + pub_r000269_16_1) & 127;
  int stage_v_152_2 = (table_2[s_idx_152_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_152_1] = (stage_v_152_1 + 7) & 63;
  table_2[s_idx_152_2] = (stage_v_152_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int s_idx_153_1 = stage_v_62_1 & 3;
  int s_idx_153_2 = stage_v_62_2 & 3;
  int stage_v_153_1 = (table_1[s_idx_153_1] + pub_r000269_6_1) & 127;
  int stage_v_153_2 = (table_2[s_idx_153_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_153_1] = (stage_v_153_1 + 7) & 63;
  table_2[s_idx_153_2] = (stage_v_153_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int s_idx_154_1 = stage_v_132_1 & 3;
  int s_idx_154_2 = stage_v_132_2 & 3;
  int stage_v_154_1 = (table_1[s_idx_154_1] + pub_r000269_8_1) & 127;
  int stage_v_154_2 = (table_2[s_idx_154_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_154_1] = (stage_v_154_1 + 7) & 63;
  table_2[s_idx_154_2] = (stage_v_154_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int s_idx_155_1 = sec_r000269_5_1 & 3;
  int s_idx_155_2 = sec_r000269_5_2 & 3;
  int stage_v_155_1 = (table_1[s_idx_155_1] + pub_r000269_1_1) & 127;
  int stage_v_155_2 = (table_2[s_idx_155_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_155_1] = (stage_v_155_1 + 7) & 63;
  table_2[s_idx_155_2] = (stage_v_155_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int s_idx_156_1 = stage_v_146_1 & 3;
  int s_idx_156_2 = stage_v_146_2 & 3;
  int stage_v_156_1 = (table_1[s_idx_156_1] + pub_r000269_1_1) & 127;
  int stage_v_156_2 = (table_2[s_idx_156_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_156_1] = (stage_v_156_1 + 7) & 63;
  table_2[s_idx_156_2] = (stage_v_156_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int s_idx_157_1 = sec_r000269_1_1 & 3;
  int s_idx_157_2 = sec_r000269_1_2 & 3;
  int stage_v_157_1 = (table_1[s_idx_157_1] + pub_r000269_0_1) & 127;
  int stage_v_157_2 = (table_2[s_idx_157_2] + pub_r000269_0_2) & 127;
  table_1[s_idx_157_1] = (stage_v_157_1 + 7) & 63;
  table_2[s_idx_157_2] = (stage_v_157_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int s_idx_158_1 = stage_v_151_1 & 3;
  int s_idx_158_2 = stage_v_151_2 & 3;
  int stage_v_158_1 = (table_1[s_idx_158_1] + pub_r000269_0_1) & 127;
  int stage_v_158_2 = (table_2[s_idx_158_2] + pub_r000269_0_2) & 127;
  table_1[s_idx_158_1] = (stage_v_158_1 + 7) & 63;
  table_2[s_idx_158_2] = (stage_v_158_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int s_idx_159_1 = stage_v_104_1 & 3;
  int s_idx_159_2 = stage_v_104_2 & 3;
  int stage_v_159_1 = (table_1[s_idx_159_1] + pub_r000269_5_1) & 127;
  int stage_v_159_2 = (table_2[s_idx_159_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_159_1] = (stage_v_159_1 + 7) & 63;
  table_2[s_idx_159_2] = (stage_v_159_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int s_idx_160_1 = sec_r000269_5_1 & 3;
  int s_idx_160_2 = sec_r000269_5_2 & 3;
  int stage_v_160_1 = (table_1[s_idx_160_1] + pub_r000269_9_1) & 127;
  int stage_v_160_2 = (table_2[s_idx_160_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_160_1] = (stage_v_160_1 + 7) & 63;
  table_2[s_idx_160_2] = (stage_v_160_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int s_idx_161_1 = stage_v_97_1 & 3;
  int s_idx_161_2 = stage_v_97_2 & 3;
  int stage_v_161_1 = (table_1[s_idx_161_1] + pub_r000269_9_1) & 127;
  int stage_v_161_2 = (table_2[s_idx_161_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_161_1] = (stage_v_161_1 + 7) & 63;
  table_2[s_idx_161_2] = (stage_v_161_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int s_idx_162_1 = stage_v_111_1 & 3;
  int s_idx_162_2 = stage_v_111_2 & 3;
  int stage_v_162_1 = (table_1[s_idx_162_1] + pub_r000269_10_1) & 127;
  int stage_v_162_2 = (table_2[s_idx_162_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_162_1] = (stage_v_162_1 + 7) & 63;
  table_2[s_idx_162_2] = (stage_v_162_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int s_idx_163_1 = stage_v_125_1 & 3;
  int s_idx_163_2 = stage_v_125_2 & 3;
  int stage_v_163_1 = (table_1[s_idx_163_1] + pub_r000269_1_1) & 127;
  int stage_v_163_2 = (table_2[s_idx_163_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_163_1] = (stage_v_163_1 + 7) & 63;
  table_2[s_idx_163_2] = (stage_v_163_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int s_idx_164_1 = stage_v_81_1 & 3;
  int s_idx_164_2 = stage_v_81_2 & 3;
  int stage_v_164_1 = (table_1[s_idx_164_1] + pub_r000269_12_1) & 127;
  int stage_v_164_2 = (table_2[s_idx_164_2] + pub_r000269_12_2) & 127;
  table_1[s_idx_164_1] = (stage_v_164_1 + 7) & 63;
  table_2[s_idx_164_2] = (stage_v_164_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int s_idx_165_1 = sec_r000269_14_1 & 3;
  int s_idx_165_2 = sec_r000269_14_2 & 3;
  int stage_v_165_1 = (table_1[s_idx_165_1] + pub_r000269_7_1) & 127;
  int stage_v_165_2 = (table_2[s_idx_165_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_165_1] = (stage_v_165_1 + 7) & 63;
  table_2[s_idx_165_2] = (stage_v_165_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int s_idx_166_1 = stage_v_78_1 & 3;
  int s_idx_166_2 = stage_v_78_2 & 3;
  int stage_v_166_1 = (table_1[s_idx_166_1] + pub_r000269_3_1) & 127;
  int stage_v_166_2 = (table_2[s_idx_166_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_166_1] = (stage_v_166_1 + 7) & 63;
  table_2[s_idx_166_2] = (stage_v_166_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int s_idx_167_1 = stage_v_105_1 & 3;
  int s_idx_167_2 = stage_v_105_2 & 3;
  int stage_v_167_1 = (table_1[s_idx_167_1] + pub_r000269_1_1) & 127;
  int stage_v_167_2 = (table_2[s_idx_167_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_167_1] = (stage_v_167_1 + 7) & 63;
  table_2[s_idx_167_2] = (stage_v_167_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int s_idx_168_1 = stage_v_144_1 & 3;
  int s_idx_168_2 = stage_v_144_2 & 3;
  int stage_v_168_1 = (table_1[s_idx_168_1] + pub_r000269_1_1) & 127;
  int stage_v_168_2 = (table_2[s_idx_168_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_168_1] = (stage_v_168_1 + 7) & 63;
  table_2[s_idx_168_2] = (stage_v_168_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int s_idx_169_1 = stage_v_99_1 & 3;
  int s_idx_169_2 = stage_v_99_2 & 3;
  int stage_v_169_1 = (table_1[s_idx_169_1] + pub_r000269_13_1) & 127;
  int stage_v_169_2 = (table_2[s_idx_169_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_169_1] = (stage_v_169_1 + 7) & 63;
  table_2[s_idx_169_2] = (stage_v_169_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int s_idx_170_1 = sec_r000269_15_1 & 3;
  int s_idx_170_2 = sec_r000269_15_2 & 3;
  int stage_v_170_1 = (table_1[s_idx_170_1] + pub_r000269_9_1) & 127;
  int stage_v_170_2 = (table_2[s_idx_170_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_170_1] = (stage_v_170_1 + 7) & 63;
  table_2[s_idx_170_2] = (stage_v_170_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int s_idx_171_1 = stage_v_50_1 & 3;
  int s_idx_171_2 = stage_v_50_2 & 3;
  int stage_v_171_1 = (table_1[s_idx_171_1] + pub_r000269_10_1) & 127;
  int stage_v_171_2 = (table_2[s_idx_171_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_171_1] = (stage_v_171_1 + 7) & 63;
  table_2[s_idx_171_2] = (stage_v_171_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int s_idx_172_1 = sec_r000269_13_1 & 3;
  int s_idx_172_2 = sec_r000269_13_2 & 3;
  int stage_v_172_1 = (table_1[s_idx_172_1] + pub_r000269_16_1) & 127;
  int stage_v_172_2 = (table_2[s_idx_172_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_172_1] = (stage_v_172_1 + 7) & 63;
  table_2[s_idx_172_2] = (stage_v_172_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int s_idx_173_1 = stage_v_137_1 & 3;
  int s_idx_173_2 = stage_v_137_2 & 3;
  int stage_v_173_1 = (table_1[s_idx_173_1] + pub_r000269_8_1) & 127;
  int stage_v_173_2 = (table_2[s_idx_173_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_173_1] = (stage_v_173_1 + 7) & 63;
  table_2[s_idx_173_2] = (stage_v_173_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int s_idx_174_1 = sec_r000269_10_1 & 3;
  int s_idx_174_2 = sec_r000269_10_2 & 3;
  int stage_v_174_1 = (table_1[s_idx_174_1] + pub_r000269_3_1) & 127;
  int stage_v_174_2 = (table_2[s_idx_174_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_174_1] = (stage_v_174_1 + 7) & 63;
  table_2[s_idx_174_2] = (stage_v_174_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int s_idx_175_1 = sec_r000269_14_1 & 3;
  int s_idx_175_2 = sec_r000269_14_2 & 3;
  int stage_v_175_1 = (table_1[s_idx_175_1] + pub_r000269_1_1) & 127;
  int stage_v_175_2 = (table_2[s_idx_175_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_175_1] = (stage_v_175_1 + 7) & 63;
  table_2[s_idx_175_2] = (stage_v_175_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int s_idx_176_1 = sec_r000269_3_1 & 3;
  int s_idx_176_2 = sec_r000269_3_2 & 3;
  int stage_v_176_1 = (table_1[s_idx_176_1] + pub_r000269_1_1) & 127;
  int stage_v_176_2 = (table_2[s_idx_176_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_176_1] = (stage_v_176_1 + 7) & 63;
  table_2[s_idx_176_2] = (stage_v_176_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int s_idx_177_1 = stage_v_82_1 & 3;
  int s_idx_177_2 = stage_v_82_2 & 3;
  int stage_v_177_1 = (table_1[s_idx_177_1] + pub_r000269_14_1) & 127;
  int stage_v_177_2 = (table_2[s_idx_177_2] + pub_r000269_14_2) & 127;
  table_1[s_idx_177_1] = (stage_v_177_1 + 7) & 63;
  table_2[s_idx_177_2] = (stage_v_177_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int s_idx_178_1 = stage_v_75_1 & 3;
  int s_idx_178_2 = stage_v_75_2 & 3;
  int stage_v_178_1 = (table_1[s_idx_178_1] + pub_r000269_8_1) & 127;
  int stage_v_178_2 = (table_2[s_idx_178_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_178_1] = (stage_v_178_1 + 7) & 63;
  table_2[s_idx_178_2] = (stage_v_178_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int s_idx_179_1 = stage_v_156_1 & 3;
  int s_idx_179_2 = stage_v_156_2 & 3;
  int stage_v_179_1 = (table_1[s_idx_179_1] + pub_r000269_2_1) & 127;
  int stage_v_179_2 = (table_2[s_idx_179_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_179_1] = (stage_v_179_1 + 7) & 63;
  table_2[s_idx_179_2] = (stage_v_179_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int s_idx_180_1 = stage_v_84_1 & 3;
  int s_idx_180_2 = stage_v_84_2 & 3;
  int stage_v_180_1 = (table_1[s_idx_180_1] + pub_r000269_13_1) & 127;
  int stage_v_180_2 = (table_2[s_idx_180_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_180_1] = (stage_v_180_1 + 7) & 63;
  table_2[s_idx_180_2] = (stage_v_180_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int s_idx_181_1 = stage_v_142_1 & 3;
  int s_idx_181_2 = stage_v_142_2 & 3;
  int stage_v_181_1 = (table_1[s_idx_181_1] + pub_r000269_6_1) & 127;
  int stage_v_181_2 = (table_2[s_idx_181_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_181_1] = (stage_v_181_1 + 7) & 63;
  table_2[s_idx_181_2] = (stage_v_181_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int s_idx_182_1 = sec_r000269_2_1 & 3;
  int s_idx_182_2 = sec_r000269_2_2 & 3;
  int stage_v_182_1 = (table_1[s_idx_182_1] + pub_r000269_13_1) & 127;
  int stage_v_182_2 = (table_2[s_idx_182_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_182_1] = (stage_v_182_1 + 7) & 63;
  table_2[s_idx_182_2] = (stage_v_182_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int s_idx_183_1 = stage_v_104_1 & 3;
  int s_idx_183_2 = stage_v_104_2 & 3;
  int stage_v_183_1 = (table_1[s_idx_183_1] + pub_r000269_13_1) & 127;
  int stage_v_183_2 = (table_2[s_idx_183_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_183_1] = (stage_v_183_1 + 7) & 63;
  table_2[s_idx_183_2] = (stage_v_183_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int s_idx_184_1 = stage_v_47_1 & 3;
  int s_idx_184_2 = stage_v_47_2 & 3;
  int stage_v_184_1 = (table_1[s_idx_184_1] + pub_r000269_7_1) & 127;
  int stage_v_184_2 = (table_2[s_idx_184_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_184_1] = (stage_v_184_1 + 7) & 63;
  table_2[s_idx_184_2] = (stage_v_184_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int s_idx_185_1 = stage_v_50_1 & 3;
  int s_idx_185_2 = stage_v_50_2 & 3;
  int stage_v_185_1 = (table_1[s_idx_185_1] + pub_r000269_3_1) & 127;
  int stage_v_185_2 = (table_2[s_idx_185_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_185_1] = (stage_v_185_1 + 7) & 63;
  table_2[s_idx_185_2] = (stage_v_185_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int s_idx_186_1 = stage_v_119_1 & 3;
  int s_idx_186_2 = stage_v_119_2 & 3;
  int stage_v_186_1 = (table_1[s_idx_186_1] + pub_r000269_8_1) & 127;
  int stage_v_186_2 = (table_2[s_idx_186_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_186_1] = (stage_v_186_1 + 7) & 63;
  table_2[s_idx_186_2] = (stage_v_186_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int s_idx_187_1 = stage_v_135_1 & 3;
  int s_idx_187_2 = stage_v_135_2 & 3;
  int stage_v_187_1 = (table_1[s_idx_187_1] + pub_r000269_15_1) & 127;
  int stage_v_187_2 = (table_2[s_idx_187_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_187_1] = (stage_v_187_1 + 7) & 63;
  table_2[s_idx_187_2] = (stage_v_187_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int s_idx_188_1 = sec_r000269_6_1 & 3;
  int s_idx_188_2 = sec_r000269_6_2 & 3;
  int stage_v_188_1 = (table_1[s_idx_188_1] + pub_r000269_6_1) & 127;
  int stage_v_188_2 = (table_2[s_idx_188_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_188_1] = (stage_v_188_1 + 7) & 63;
  table_2[s_idx_188_2] = (stage_v_188_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int s_idx_189_1 = stage_v_157_1 & 3;
  int s_idx_189_2 = stage_v_157_2 & 3;
  int stage_v_189_1 = (table_1[s_idx_189_1] + pub_r000269_15_1) & 127;
  int stage_v_189_2 = (table_2[s_idx_189_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_189_1] = (stage_v_189_1 + 7) & 63;
  table_2[s_idx_189_2] = (stage_v_189_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int s_idx_190_1 = sec_r000269_10_1 & 3;
  int s_idx_190_2 = sec_r000269_10_2 & 3;
  int stage_v_190_1 = (table_1[s_idx_190_1] + pub_r000269_10_1) & 127;
  int stage_v_190_2 = (table_2[s_idx_190_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_190_1] = (stage_v_190_1 + 7) & 63;
  table_2[s_idx_190_2] = (stage_v_190_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int s_idx_191_1 = sec_r000269_5_1 & 3;
  int s_idx_191_2 = sec_r000269_5_2 & 3;
  int stage_v_191_1 = (table_1[s_idx_191_1] + pub_r000269_16_1) & 127;
  int stage_v_191_2 = (table_2[s_idx_191_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_191_1] = (stage_v_191_1 + 7) & 63;
  table_2[s_idx_191_2] = (stage_v_191_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int s_idx_192_1 = sec_r000269_4_1 & 3;
  int s_idx_192_2 = sec_r000269_4_2 & 3;
  int stage_v_192_1 = (table_1[s_idx_192_1] + pub_r000269_13_1) & 127;
  int stage_v_192_2 = (table_2[s_idx_192_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_192_1] = (stage_v_192_1 + 7) & 63;
  table_2[s_idx_192_2] = (stage_v_192_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int s_idx_193_1 = sec_r000269_11_1 & 3;
  int s_idx_193_2 = sec_r000269_11_2 & 3;
  int stage_v_193_1 = (table_1[s_idx_193_1] + pub_r000269_10_1) & 127;
  int stage_v_193_2 = (table_2[s_idx_193_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_193_1] = (stage_v_193_1 + 7) & 63;
  table_2[s_idx_193_2] = (stage_v_193_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int s_idx_194_1 = stage_v_145_1 & 3;
  int s_idx_194_2 = stage_v_145_2 & 3;
  int stage_v_194_1 = (table_1[s_idx_194_1] + pub_r000269_15_1) & 127;
  int stage_v_194_2 = (table_2[s_idx_194_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_194_1] = (stage_v_194_1 + 7) & 63;
  table_2[s_idx_194_2] = (stage_v_194_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int s_idx_195_1 = sec_r000269_14_1 & 3;
  int s_idx_195_2 = sec_r000269_14_2 & 3;
  int stage_v_195_1 = (table_1[s_idx_195_1] + pub_r000269_9_1) & 127;
  int stage_v_195_2 = (table_2[s_idx_195_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_195_1] = (stage_v_195_1 + 7) & 63;
  table_2[s_idx_195_2] = (stage_v_195_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int s_idx_196_1 = sec_r000269_1_1 & 3;
  int s_idx_196_2 = sec_r000269_1_2 & 3;
  int stage_v_196_1 = (table_1[s_idx_196_1] + pub_r000269_6_1) & 127;
  int stage_v_196_2 = (table_2[s_idx_196_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_196_1] = (stage_v_196_1 + 7) & 63;
  table_2[s_idx_196_2] = (stage_v_196_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int s_idx_197_1 = stage_v_57_1 & 3;
  int s_idx_197_2 = stage_v_57_2 & 3;
  int stage_v_197_1 = (table_1[s_idx_197_1] + pub_r000269_2_1) & 127;
  int stage_v_197_2 = (table_2[s_idx_197_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_197_1] = (stage_v_197_1 + 7) & 63;
  table_2[s_idx_197_2] = (stage_v_197_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int s_idx_198_1 = stage_v_100_1 & 3;
  int s_idx_198_2 = stage_v_100_2 & 3;
  int stage_v_198_1 = (table_1[s_idx_198_1] + pub_r000269_4_1) & 127;
  int stage_v_198_2 = (table_2[s_idx_198_2] + pub_r000269_4_2) & 127;
  table_1[s_idx_198_1] = (stage_v_198_1 + 7) & 63;
  table_2[s_idx_198_2] = (stage_v_198_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int s_idx_199_1 = stage_v_113_1 & 3;
  int s_idx_199_2 = stage_v_113_2 & 3;
  int stage_v_199_1 = (table_1[s_idx_199_1] + pub_r000269_14_1) & 127;
  int stage_v_199_2 = (table_2[s_idx_199_2] + pub_r000269_14_2) & 127;
  table_1[s_idx_199_1] = (stage_v_199_1 + 7) & 63;
  table_2[s_idx_199_2] = (stage_v_199_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int s_idx_200_1 = stage_v_102_1 & 3;
  int s_idx_200_2 = stage_v_102_2 & 3;
  int stage_v_200_1 = (table_1[s_idx_200_1] + pub_r000269_15_1) & 127;
  int stage_v_200_2 = (table_2[s_idx_200_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_200_1] = (stage_v_200_1 + 7) & 63;
  table_2[s_idx_200_2] = (stage_v_200_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int s_idx_201_1 = sec_r000269_2_1 & 3;
  int s_idx_201_2 = sec_r000269_2_2 & 3;
  int stage_v_201_1 = (table_1[s_idx_201_1] + pub_r000269_11_1) & 127;
  int stage_v_201_2 = (table_2[s_idx_201_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_201_1] = (stage_v_201_1 + 7) & 63;
  table_2[s_idx_201_2] = (stage_v_201_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int s_idx_202_1 = stage_v_80_1 & 3;
  int s_idx_202_2 = stage_v_80_2 & 3;
  int stage_v_202_1 = (table_1[s_idx_202_1] + pub_r000269_7_1) & 127;
  int stage_v_202_2 = (table_2[s_idx_202_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_202_1] = (stage_v_202_1 + 7) & 63;
  table_2[s_idx_202_2] = (stage_v_202_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int s_idx_203_1 = stage_v_107_1 & 3;
  int s_idx_203_2 = stage_v_107_2 & 3;
  int stage_v_203_1 = (table_1[s_idx_203_1] + pub_r000269_0_1) & 127;
  int stage_v_203_2 = (table_2[s_idx_203_2] + pub_r000269_0_2) & 127;
  table_1[s_idx_203_1] = (stage_v_203_1 + 7) & 63;
  table_2[s_idx_203_2] = (stage_v_203_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int s_idx_204_1 = stage_v_61_1 & 3;
  int s_idx_204_2 = stage_v_61_2 & 3;
  int stage_v_204_1 = (table_1[s_idx_204_1] + pub_r000269_9_1) & 127;
  int stage_v_204_2 = (table_2[s_idx_204_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_204_1] = (stage_v_204_1 + 7) & 63;
  table_2[s_idx_204_2] = (stage_v_204_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int s_idx_205_1 = sec_r000269_12_1 & 3;
  int s_idx_205_2 = sec_r000269_12_2 & 3;
  int stage_v_205_1 = (table_1[s_idx_205_1] + pub_r000269_3_1) & 127;
  int stage_v_205_2 = (table_2[s_idx_205_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_205_1] = (stage_v_205_1 + 7) & 63;
  table_2[s_idx_205_2] = (stage_v_205_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int s_idx_206_1 = sec_r000269_15_1 & 3;
  int s_idx_206_2 = sec_r000269_15_2 & 3;
  int stage_v_206_1 = (table_1[s_idx_206_1] + pub_r000269_11_1) & 127;
  int stage_v_206_2 = (table_2[s_idx_206_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_206_1] = (stage_v_206_1 + 7) & 63;
  table_2[s_idx_206_2] = (stage_v_206_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int s_idx_207_1 = stage_v_89_1 & 3;
  int s_idx_207_2 = stage_v_89_2 & 3;
  int stage_v_207_1 = (table_1[s_idx_207_1] + pub_r000269_10_1) & 127;
  int stage_v_207_2 = (table_2[s_idx_207_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_207_1] = (stage_v_207_1 + 7) & 63;
  table_2[s_idx_207_2] = (stage_v_207_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int s_idx_208_1 = sec_r000269_4_1 & 3;
  int s_idx_208_2 = sec_r000269_4_2 & 3;
  int stage_v_208_1 = (table_1[s_idx_208_1] + pub_r000269_15_1) & 127;
  int stage_v_208_2 = (table_2[s_idx_208_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_208_1] = (stage_v_208_1 + 7) & 63;
  table_2[s_idx_208_2] = (stage_v_208_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int s_idx_209_1 = sec_r000269_7_1 & 3;
  int s_idx_209_2 = sec_r000269_7_2 & 3;
  int stage_v_209_1 = (table_1[s_idx_209_1] + pub_r000269_1_1) & 127;
  int stage_v_209_2 = (table_2[s_idx_209_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_209_1] = (stage_v_209_1 + 7) & 63;
  table_2[s_idx_209_2] = (stage_v_209_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int s_idx_210_1 = stage_v_101_1 & 3;
  int s_idx_210_2 = stage_v_101_2 & 3;
  int stage_v_210_1 = (table_1[s_idx_210_1] + pub_r000269_1_1) & 127;
  int stage_v_210_2 = (table_2[s_idx_210_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_210_1] = (stage_v_210_1 + 7) & 63;
  table_2[s_idx_210_2] = (stage_v_210_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int s_idx_211_1 = sec_r000269_11_1 & 3;
  int s_idx_211_2 = sec_r000269_11_2 & 3;
  int stage_v_211_1 = (table_1[s_idx_211_1] + pub_r000269_1_1) & 127;
  int stage_v_211_2 = (table_2[s_idx_211_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_211_1] = (stage_v_211_1 + 7) & 63;
  table_2[s_idx_211_2] = (stage_v_211_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int s_idx_212_1 = sec_r000269_0_1 & 3;
  int s_idx_212_2 = sec_r000269_0_2 & 3;
  int stage_v_212_1 = (table_1[s_idx_212_1] + pub_r000269_13_1) & 127;
  int stage_v_212_2 = (table_2[s_idx_212_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_212_1] = (stage_v_212_1 + 7) & 63;
  table_2[s_idx_212_2] = (stage_v_212_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int s_idx_213_1 = stage_v_69_1 & 3;
  int s_idx_213_2 = stage_v_69_2 & 3;
  int stage_v_213_1 = (table_1[s_idx_213_1] + pub_r000269_15_1) & 127;
  int stage_v_213_2 = (table_2[s_idx_213_2] + pub_r000269_15_2) & 127;
  table_1[s_idx_213_1] = (stage_v_213_1 + 7) & 63;
  table_2[s_idx_213_2] = (stage_v_213_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int s_idx_214_1 = stage_v_195_1 & 3;
  int s_idx_214_2 = stage_v_195_2 & 3;
  int stage_v_214_1 = (table_1[s_idx_214_1] + pub_r000269_2_1) & 127;
  int stage_v_214_2 = (table_2[s_idx_214_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_214_1] = (stage_v_214_1 + 7) & 63;
  table_2[s_idx_214_2] = (stage_v_214_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int s_idx_215_1 = sec_r000269_11_1 & 3;
  int s_idx_215_2 = sec_r000269_11_2 & 3;
  int stage_v_215_1 = (table_1[s_idx_215_1] + pub_r000269_13_1) & 127;
  int stage_v_215_2 = (table_2[s_idx_215_2] + pub_r000269_13_2) & 127;
  table_1[s_idx_215_1] = (stage_v_215_1 + 7) & 63;
  table_2[s_idx_215_2] = (stage_v_215_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int s_idx_216_1 = stage_v_176_1 & 3;
  int s_idx_216_2 = stage_v_176_2 & 3;
  int stage_v_216_1 = (table_1[s_idx_216_1] + pub_r000269_10_1) & 127;
  int stage_v_216_2 = (table_2[s_idx_216_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_216_1] = (stage_v_216_1 + 7) & 63;
  table_2[s_idx_216_2] = (stage_v_216_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int s_idx_217_1 = stage_v_207_1 & 3;
  int s_idx_217_2 = stage_v_207_2 & 3;
  int stage_v_217_1 = (table_1[s_idx_217_1] + pub_r000269_0_1) & 127;
  int stage_v_217_2 = (table_2[s_idx_217_2] + pub_r000269_0_2) & 127;
  table_1[s_idx_217_1] = (stage_v_217_1 + 7) & 63;
  table_2[s_idx_217_2] = (stage_v_217_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int s_idx_218_1 = stage_v_96_1 & 3;
  int s_idx_218_2 = stage_v_96_2 & 3;
  int stage_v_218_1 = (table_1[s_idx_218_1] + pub_r000269_1_1) & 127;
  int stage_v_218_2 = (table_2[s_idx_218_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_218_1] = (stage_v_218_1 + 7) & 63;
  table_2[s_idx_218_2] = (stage_v_218_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int s_idx_219_1 = stage_v_139_1 & 3;
  int s_idx_219_2 = stage_v_139_2 & 3;
  int stage_v_219_1 = (table_1[s_idx_219_1] + pub_r000269_2_1) & 127;
  int stage_v_219_2 = (table_2[s_idx_219_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_219_1] = (stage_v_219_1 + 7) & 63;
  table_2[s_idx_219_2] = (stage_v_219_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int s_idx_220_1 = stage_v_99_1 & 3;
  int s_idx_220_2 = stage_v_99_2 & 3;
  int stage_v_220_1 = (table_1[s_idx_220_1] + pub_r000269_5_1) & 127;
  int stage_v_220_2 = (table_2[s_idx_220_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_220_1] = (stage_v_220_1 + 7) & 63;
  table_2[s_idx_220_2] = (stage_v_220_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int s_idx_221_1 = stage_v_51_1 & 3;
  int s_idx_221_2 = stage_v_51_2 & 3;
  int stage_v_221_1 = (table_1[s_idx_221_1] + pub_r000269_11_1) & 127;
  int stage_v_221_2 = (table_2[s_idx_221_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_221_1] = (stage_v_221_1 + 7) & 63;
  table_2[s_idx_221_2] = (stage_v_221_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int s_idx_222_1 = sec_r000269_15_1 & 3;
  int s_idx_222_2 = sec_r000269_15_2 & 3;
  int stage_v_222_1 = (table_1[s_idx_222_1] + pub_r000269_8_1) & 127;
  int stage_v_222_2 = (table_2[s_idx_222_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_222_1] = (stage_v_222_1 + 7) & 63;
  table_2[s_idx_222_2] = (stage_v_222_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int s_idx_223_1 = sec_r000269_15_1 & 3;
  int s_idx_223_2 = sec_r000269_15_2 & 3;
  int stage_v_223_1 = (table_1[s_idx_223_1] + pub_r000269_12_1) & 127;
  int stage_v_223_2 = (table_2[s_idx_223_2] + pub_r000269_12_2) & 127;
  table_1[s_idx_223_1] = (stage_v_223_1 + 7) & 63;
  table_2[s_idx_223_2] = (stage_v_223_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int s_idx_224_1 = stage_v_222_1 & 3;
  int s_idx_224_2 = stage_v_222_2 & 3;
  int stage_v_224_1 = (table_1[s_idx_224_1] + pub_r000269_11_1) & 127;
  int stage_v_224_2 = (table_2[s_idx_224_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_224_1] = (stage_v_224_1 + 7) & 63;
  table_2[s_idx_224_2] = (stage_v_224_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int s_idx_225_1 = stage_v_189_1 & 3;
  int s_idx_225_2 = stage_v_189_2 & 3;
  int stage_v_225_1 = (table_1[s_idx_225_1] + pub_r000269_4_1) & 127;
  int stage_v_225_2 = (table_2[s_idx_225_2] + pub_r000269_4_2) & 127;
  table_1[s_idx_225_1] = (stage_v_225_1 + 7) & 63;
  table_2[s_idx_225_2] = (stage_v_225_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int s_idx_226_1 = stage_v_58_1 & 3;
  int s_idx_226_2 = stage_v_58_2 & 3;
  int stage_v_226_1 = (table_1[s_idx_226_1] + pub_r000269_3_1) & 127;
  int stage_v_226_2 = (table_2[s_idx_226_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_226_1] = (stage_v_226_1 + 7) & 63;
  table_2[s_idx_226_2] = (stage_v_226_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int s_idx_227_1 = stage_v_116_1 & 3;
  int s_idx_227_2 = stage_v_116_2 & 3;
  int stage_v_227_1 = (table_1[s_idx_227_1] + pub_r000269_7_1) & 127;
  int stage_v_227_2 = (table_2[s_idx_227_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_227_1] = (stage_v_227_1 + 7) & 63;
  table_2[s_idx_227_2] = (stage_v_227_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int s_idx_228_1 = sec_r000269_6_1 & 3;
  int s_idx_228_2 = sec_r000269_6_2 & 3;
  int stage_v_228_1 = (table_1[s_idx_228_1] + pub_r000269_16_1) & 127;
  int stage_v_228_2 = (table_2[s_idx_228_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_228_1] = (stage_v_228_1 + 7) & 63;
  table_2[s_idx_228_2] = (stage_v_228_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int s_idx_229_1 = stage_v_141_1 & 3;
  int s_idx_229_2 = stage_v_141_2 & 3;
  int stage_v_229_1 = (table_1[s_idx_229_1] + pub_r000269_1_1) & 127;
  int stage_v_229_2 = (table_2[s_idx_229_2] + pub_r000269_1_2) & 127;
  table_1[s_idx_229_1] = (stage_v_229_1 + 7) & 63;
  table_2[s_idx_229_2] = (stage_v_229_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int s_idx_230_1 = stage_v_73_1 & 3;
  int s_idx_230_2 = stage_v_73_2 & 3;
  int stage_v_230_1 = (table_1[s_idx_230_1] + pub_r000269_3_1) & 127;
  int stage_v_230_2 = (table_2[s_idx_230_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_230_1] = (stage_v_230_1 + 7) & 63;
  table_2[s_idx_230_2] = (stage_v_230_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int s_idx_231_1 = stage_v_108_1 & 3;
  int s_idx_231_2 = stage_v_108_2 & 3;
  int stage_v_231_1 = (table_1[s_idx_231_1] + pub_r000269_6_1) & 127;
  int stage_v_231_2 = (table_2[s_idx_231_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_231_1] = (stage_v_231_1 + 7) & 63;
  table_2[s_idx_231_2] = (stage_v_231_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int s_idx_232_1 = stage_v_47_1 & 3;
  int s_idx_232_2 = stage_v_47_2 & 3;
  int stage_v_232_1 = (table_1[s_idx_232_1] + pub_r000269_10_1) & 127;
  int stage_v_232_2 = (table_2[s_idx_232_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_232_1] = (stage_v_232_1 + 7) & 63;
  table_2[s_idx_232_2] = (stage_v_232_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int s_idx_233_1 = stage_v_111_1 & 3;
  int s_idx_233_2 = stage_v_111_2 & 3;
  int stage_v_233_1 = (table_1[s_idx_233_1] + pub_r000269_16_1) & 127;
  int stage_v_233_2 = (table_2[s_idx_233_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_233_1] = (stage_v_233_1 + 7) & 63;
  table_2[s_idx_233_2] = (stage_v_233_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int s_idx_234_1 = sec_r000269_2_1 & 3;
  int s_idx_234_2 = sec_r000269_2_2 & 3;
  int stage_v_234_1 = (table_1[s_idx_234_1] + pub_r000269_9_1) & 127;
  int stage_v_234_2 = (table_2[s_idx_234_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_234_1] = (stage_v_234_1 + 7) & 63;
  table_2[s_idx_234_2] = (stage_v_234_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int s_idx_235_1 = sec_r000269_3_1 & 3;
  int s_idx_235_2 = sec_r000269_3_2 & 3;
  int stage_v_235_1 = (table_1[s_idx_235_1] + pub_r000269_7_1) & 127;
  int stage_v_235_2 = (table_2[s_idx_235_2] + pub_r000269_7_2) & 127;
  table_1[s_idx_235_1] = (stage_v_235_1 + 7) & 63;
  table_2[s_idx_235_2] = (stage_v_235_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int s_idx_236_1 = stage_v_173_1 & 3;
  int s_idx_236_2 = stage_v_173_2 & 3;
  int stage_v_236_1 = (table_1[s_idx_236_1] + pub_r000269_14_1) & 127;
  int stage_v_236_2 = (table_2[s_idx_236_2] + pub_r000269_14_2) & 127;
  table_1[s_idx_236_1] = (stage_v_236_1 + 7) & 63;
  table_2[s_idx_236_2] = (stage_v_236_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int s_idx_237_1 = sec_r000269_15_1 & 3;
  int s_idx_237_2 = sec_r000269_15_2 & 3;
  int stage_v_237_1 = (table_1[s_idx_237_1] + pub_r000269_3_1) & 127;
  int stage_v_237_2 = (table_2[s_idx_237_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_237_1] = (stage_v_237_1 + 7) & 63;
  table_2[s_idx_237_2] = (stage_v_237_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int s_idx_238_1 = sec_r000269_13_1 & 3;
  int s_idx_238_2 = sec_r000269_13_2 & 3;
  int stage_v_238_1 = (table_1[s_idx_238_1] + pub_r000269_2_1) & 127;
  int stage_v_238_2 = (table_2[s_idx_238_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_238_1] = (stage_v_238_1 + 7) & 63;
  table_2[s_idx_238_2] = (stage_v_238_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int s_idx_239_1 = sec_r000269_5_1 & 3;
  int s_idx_239_2 = sec_r000269_5_2 & 3;
  int stage_v_239_1 = (table_1[s_idx_239_1] + pub_r000269_6_1) & 127;
  int stage_v_239_2 = (table_2[s_idx_239_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_239_1] = (stage_v_239_1 + 7) & 63;
  table_2[s_idx_239_2] = (stage_v_239_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int s_idx_240_1 = stage_v_71_1 & 3;
  int s_idx_240_2 = stage_v_71_2 & 3;
  int stage_v_240_1 = (table_1[s_idx_240_1] + pub_r000269_10_1) & 127;
  int stage_v_240_2 = (table_2[s_idx_240_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_240_1] = (stage_v_240_1 + 7) & 63;
  table_2[s_idx_240_2] = (stage_v_240_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int s_idx_241_1 = sec_r000269_7_1 & 3;
  int s_idx_241_2 = sec_r000269_7_2 & 3;
  int stage_v_241_1 = (table_1[s_idx_241_1] + pub_r000269_4_1) & 127;
  int stage_v_241_2 = (table_2[s_idx_241_2] + pub_r000269_4_2) & 127;
  table_1[s_idx_241_1] = (stage_v_241_1 + 7) & 63;
  table_2[s_idx_241_2] = (stage_v_241_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int s_idx_242_1 = sec_r000269_10_1 & 3;
  int s_idx_242_2 = sec_r000269_10_2 & 3;
  int stage_v_242_1 = (table_1[s_idx_242_1] + pub_r000269_8_1) & 127;
  int stage_v_242_2 = (table_2[s_idx_242_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_242_1] = (stage_v_242_1 + 7) & 63;
  table_2[s_idx_242_2] = (stage_v_242_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int s_idx_243_1 = stage_v_116_1 & 3;
  int s_idx_243_2 = stage_v_116_2 & 3;
  int stage_v_243_1 = (table_1[s_idx_243_1] + pub_r000269_12_1) & 127;
  int stage_v_243_2 = (table_2[s_idx_243_2] + pub_r000269_12_2) & 127;
  table_1[s_idx_243_1] = (stage_v_243_1 + 7) & 63;
  table_2[s_idx_243_2] = (stage_v_243_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  int s_idx_244_1 = stage_v_64_1 & 3;
  int s_idx_244_2 = stage_v_64_2 & 3;
  int stage_v_244_1 = (table_1[s_idx_244_1] + pub_r000269_2_1) & 127;
  int stage_v_244_2 = (table_2[s_idx_244_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_244_1] = (stage_v_244_1 + 7) & 63;
  table_2[s_idx_244_2] = (stage_v_244_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int s_idx_245_1 = stage_v_74_1 & 3;
  int s_idx_245_2 = stage_v_74_2 & 3;
  int stage_v_245_1 = (table_1[s_idx_245_1] + pub_r000269_0_1) & 127;
  int stage_v_245_2 = (table_2[s_idx_245_2] + pub_r000269_0_2) & 127;
  table_1[s_idx_245_1] = (stage_v_245_1 + 7) & 63;
  table_2[s_idx_245_2] = (stage_v_245_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  int s_idx_246_1 = sec_r000269_3_1 & 3;
  int s_idx_246_2 = sec_r000269_3_2 & 3;
  int stage_v_246_1 = (table_1[s_idx_246_1] + pub_r000269_8_1) & 127;
  int stage_v_246_2 = (table_2[s_idx_246_2] + pub_r000269_8_2) & 127;
  table_1[s_idx_246_1] = (stage_v_246_1 + 7) & 63;
  table_2[s_idx_246_2] = (stage_v_246_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  int s_idx_247_1 = sec_r000269_0_1 & 3;
  int s_idx_247_2 = sec_r000269_0_2 & 3;
  int stage_v_247_1 = (table_1[s_idx_247_1] + pub_r000269_2_1) & 127;
  int stage_v_247_2 = (table_2[s_idx_247_2] + pub_r000269_2_2) & 127;
  table_1[s_idx_247_1] = (stage_v_247_1 + 7) & 63;
  table_2[s_idx_247_2] = (stage_v_247_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  int s_idx_248_1 = stage_v_84_1 & 3;
  int s_idx_248_2 = stage_v_84_2 & 3;
  int stage_v_248_1 = (table_1[s_idx_248_1] + pub_r000269_10_1) & 127;
  int stage_v_248_2 = (table_2[s_idx_248_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_248_1] = (stage_v_248_1 + 7) & 63;
  table_2[s_idx_248_2] = (stage_v_248_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int s_idx_249_1 = stage_v_86_1 & 3;
  int s_idx_249_2 = stage_v_86_2 & 3;
  int stage_v_249_1 = (table_1[s_idx_249_1] + pub_r000269_3_1) & 127;
  int stage_v_249_2 = (table_2[s_idx_249_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_249_1] = (stage_v_249_1 + 7) & 63;
  table_2[s_idx_249_2] = (stage_v_249_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  int s_idx_250_1 = sec_r000269_10_1 & 3;
  int s_idx_250_2 = sec_r000269_10_2 & 3;
  int stage_v_250_1 = (table_1[s_idx_250_1] + pub_r000269_9_1) & 127;
  int stage_v_250_2 = (table_2[s_idx_250_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_250_1] = (stage_v_250_1 + 7) & 63;
  table_2[s_idx_250_2] = (stage_v_250_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  int s_idx_251_1 = stage_v_174_1 & 3;
  int s_idx_251_2 = stage_v_174_2 & 3;
  int stage_v_251_1 = (table_1[s_idx_251_1] + pub_r000269_11_1) & 127;
  int stage_v_251_2 = (table_2[s_idx_251_2] + pub_r000269_11_2) & 127;
  table_1[s_idx_251_1] = (stage_v_251_1 + 7) & 63;
  table_2[s_idx_251_2] = (stage_v_251_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  int s_idx_252_1 = stage_v_148_1 & 3;
  int s_idx_252_2 = stage_v_148_2 & 3;
  int stage_v_252_1 = (table_1[s_idx_252_1] + pub_r000269_5_1) & 127;
  int stage_v_252_2 = (table_2[s_idx_252_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_252_1] = (stage_v_252_1 + 7) & 63;
  table_2[s_idx_252_2] = (stage_v_252_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  int s_idx_253_1 = stage_v_116_1 & 3;
  int s_idx_253_2 = stage_v_116_2 & 3;
  int stage_v_253_1 = (table_1[s_idx_253_1] + pub_r000269_6_1) & 127;
  int stage_v_253_2 = (table_2[s_idx_253_2] + pub_r000269_6_2) & 127;
  table_1[s_idx_253_1] = (stage_v_253_1 + 7) & 63;
  table_2[s_idx_253_2] = (stage_v_253_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  int s_idx_254_1 = stage_v_182_1 & 3;
  int s_idx_254_2 = stage_v_182_2 & 3;
  int stage_v_254_1 = (table_1[s_idx_254_1] + pub_r000269_3_1) & 127;
  int stage_v_254_2 = (table_2[s_idx_254_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_254_1] = (stage_v_254_1 + 7) & 63;
  table_2[s_idx_254_2] = (stage_v_254_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  int s_idx_255_1 = stage_v_81_1 & 3;
  int s_idx_255_2 = stage_v_81_2 & 3;
  int stage_v_255_1 = (table_1[s_idx_255_1] + pub_r000269_16_1) & 127;
  int stage_v_255_2 = (table_2[s_idx_255_2] + pub_r000269_16_2) & 127;
  table_1[s_idx_255_1] = (stage_v_255_1 + 7) & 63;
  table_2[s_idx_255_2] = (stage_v_255_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  int s_idx_256_1 = stage_v_220_1 & 3;
  int s_idx_256_2 = stage_v_220_2 & 3;
  int stage_v_256_1 = (table_1[s_idx_256_1] + pub_r000269_9_1) & 127;
  int stage_v_256_2 = (table_2[s_idx_256_2] + pub_r000269_9_2) & 127;
  table_1[s_idx_256_1] = (stage_v_256_1 + 7) & 63;
  table_2[s_idx_256_2] = (stage_v_256_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  int s_idx_257_1 = stage_v_184_1 & 3;
  int s_idx_257_2 = stage_v_184_2 & 3;
  int stage_v_257_1 = (table_1[s_idx_257_1] + pub_r000269_4_1) & 127;
  int stage_v_257_2 = (table_2[s_idx_257_2] + pub_r000269_4_2) & 127;
  table_1[s_idx_257_1] = (stage_v_257_1 + 7) & 63;
  table_2[s_idx_257_2] = (stage_v_257_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  int s_idx_258_1 = sec_r000269_10_1 & 3;
  int s_idx_258_2 = sec_r000269_10_2 & 3;
  int stage_v_258_1 = (table_1[s_idx_258_1] + pub_r000269_10_1) & 127;
  int stage_v_258_2 = (table_2[s_idx_258_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_258_1] = (stage_v_258_1 + 7) & 63;
  table_2[s_idx_258_2] = (stage_v_258_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  int s_idx_259_1 = stage_v_115_1 & 3;
  int s_idx_259_2 = stage_v_115_2 & 3;
  int stage_v_259_1 = (table_1[s_idx_259_1] + pub_r000269_3_1) & 127;
  int stage_v_259_2 = (table_2[s_idx_259_2] + pub_r000269_3_2) & 127;
  table_1[s_idx_259_1] = (stage_v_259_1 + 7) & 63;
  table_2[s_idx_259_2] = (stage_v_259_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  int s_idx_260_1 = stage_v_245_1 & 3;
  int s_idx_260_2 = stage_v_245_2 & 3;
  int stage_v_260_1 = (table_1[s_idx_260_1] + pub_r000269_14_1) & 127;
  int stage_v_260_2 = (table_2[s_idx_260_2] + pub_r000269_14_2) & 127;
  table_1[s_idx_260_1] = (stage_v_260_1 + 7) & 63;
  table_2[s_idx_260_2] = (stage_v_260_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  int s_idx_261_1 = stage_v_173_1 & 3;
  int s_idx_261_2 = stage_v_173_2 & 3;
  int stage_v_261_1 = (table_1[s_idx_261_1] + pub_r000269_5_1) & 127;
  int stage_v_261_2 = (table_2[s_idx_261_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_261_1] = (stage_v_261_1 + 7) & 63;
  table_2[s_idx_261_2] = (stage_v_261_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  int s_idx_262_1 = stage_v_245_1 & 3;
  int s_idx_262_2 = stage_v_245_2 & 3;
  int stage_v_262_1 = (table_1[s_idx_262_1] + pub_r000269_10_1) & 127;
  int stage_v_262_2 = (table_2[s_idx_262_2] + pub_r000269_10_2) & 127;
  table_1[s_idx_262_1] = (stage_v_262_1 + 7) & 63;
  table_2[s_idx_262_2] = (stage_v_262_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  int s_idx_263_1 = stage_v_167_1 & 3;
  int s_idx_263_2 = stage_v_167_2 & 3;
  int stage_v_263_1 = (table_1[s_idx_263_1] + pub_r000269_5_1) & 127;
  int stage_v_263_2 = (table_2[s_idx_263_2] + pub_r000269_5_2) & 127;
  table_1[s_idx_263_1] = (stage_v_263_1 + 7) & 63;
  table_2[s_idx_263_2] = (stage_v_263_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  int s_idx_264_1 = sec_r000269_13_1 & 3;
  int s_idx_264_2 = sec_r000269_13_2 & 3;
  int stage_v_264_1 = (table_1[s_idx_264_1] + pub_r000269_12_1) & 127;
  int stage_v_264_2 = (table_2[s_idx_264_2] + pub_r000269_12_2) & 127;
  table_1[s_idx_264_1] = (stage_v_264_1 + 7) & 63;
  table_2[s_idx_264_2] = (stage_v_264_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000269_4_1 != sec_r000269_4_2);
  __CPROVER_assume(sec_r000269_13_1 != sec_r000269_13_2);
  __CPROVER_assume(pub_r000269_1_1 == pub_r000269_1_2);
  __CPROVER_assume(pub_r000269_5_1 == pub_r000269_5_2);
  __CPROVER_assume(sec_r000269_0_1 != sec_r000269_0_2);
  __CPROVER_assume(sec_r000269_12_1 != sec_r000269_12_2);
  __CPROVER_assume(sec_r000269_14_1 != sec_r000269_14_2);
  __CPROVER_assume(pub_r000269_2_1 == pub_r000269_2_2);
  __CPROVER_assume(sec_r000269_5_1 != sec_r000269_5_2);
  __CPROVER_assume(pub_r000269_7_1 == pub_r000269_7_2);
  __CPROVER_assume(pub_r000269_3_1 == pub_r000269_3_2);
  __CPROVER_assume(sec_r000269_7_1 != sec_r000269_7_2);
  __CPROVER_assume(pub_r000269_0_1 == pub_r000269_0_2);
  __CPROVER_assume(pub_r000269_6_1 == pub_r000269_6_2);
  __CPROVER_assume(pub_r000269_4_1 == pub_r000269_4_2);
  __CPROVER_assume(pub_r000269_8_1 == pub_r000269_8_2);
  __CPROVER_assume(sec_r000269_3_1 != sec_r000269_3_2);
  __CPROVER_assume(pub_r000269_14_1 == pub_r000269_14_2);
  __CPROVER_assume(pub_r000269_9_1 == pub_r000269_9_2);
  __CPROVER_assume(pub_r000269_15_1 == pub_r000269_15_2);
  __CPROVER_assume(sec_r000269_6_1 != sec_r000269_6_2);
  __CPROVER_assume(sec_r000269_8_1 != sec_r000269_8_2);
  __CPROVER_assume(sec_r000269_11_1 != sec_r000269_11_2);
  __CPROVER_assume(sec_r000269_10_1 != sec_r000269_10_2);
  __CPROVER_assume(sec_r000269_15_1 != sec_r000269_15_2);
  __CPROVER_assume(pub_r000269_13_1 == pub_r000269_13_2);
  __CPROVER_assume(sec_r000269_9_1 != sec_r000269_9_2);
  __CPROVER_assume(sec_r000269_1_1 != sec_r000269_1_2);
  __CPROVER_assume(pub_r000269_16_1 == pub_r000269_16_2);
  __CPROVER_assume(pub_r000269_11_1 == pub_r000269_11_2);
  __CPROVER_assume(sec_r000269_2_1 != sec_r000269_2_2);
  __CPROVER_assume(pub_r000269_12_1 == pub_r000269_12_2);
  __CPROVER_assume(pub_r000269_10_1 == pub_r000269_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.prev_in == st_var_3_2.prev_in);
  assert(st_var_3_1.cutoff == st_var_3_2.cutoff);
  assert(st_var_3_1.damping == st_var_3_2.damping);
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
  assert(s_idx_42_1 == s_idx_42_2);
  assert(stage_v_42_1 == stage_v_42_2);
  assert(s_idx_43_1 == s_idx_43_2);
  assert(stage_v_43_1 == stage_v_43_2);
  assert(s_idx_44_1 == s_idx_44_2);
  assert(stage_v_44_1 == stage_v_44_2);
  assert(s_idx_45_1 == s_idx_45_2);
  assert(stage_v_45_1 == stage_v_45_2);
  assert(s_idx_46_1 == s_idx_46_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(s_idx_47_1 == s_idx_47_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(s_idx_48_1 == s_idx_48_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(s_idx_49_1 == s_idx_49_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(s_idx_50_1 == s_idx_50_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(s_idx_51_1 == s_idx_51_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(s_idx_52_1 == s_idx_52_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(s_idx_53_1 == s_idx_53_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(s_idx_54_1 == s_idx_54_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(s_idx_55_1 == s_idx_55_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(s_idx_56_1 == s_idx_56_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(s_idx_57_1 == s_idx_57_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(s_idx_58_1 == s_idx_58_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(s_idx_59_1 == s_idx_59_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(s_idx_60_1 == s_idx_60_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(s_idx_61_1 == s_idx_61_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(s_idx_62_1 == s_idx_62_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(s_idx_63_1 == s_idx_63_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(s_idx_64_1 == s_idx_64_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(s_idx_65_1 == s_idx_65_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(s_idx_66_1 == s_idx_66_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(s_idx_67_1 == s_idx_67_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(s_idx_68_1 == s_idx_68_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(s_idx_69_1 == s_idx_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(s_idx_70_1 == s_idx_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(s_idx_71_1 == s_idx_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(s_idx_72_1 == s_idx_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(s_idx_73_1 == s_idx_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(s_idx_74_1 == s_idx_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(s_idx_75_1 == s_idx_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(s_idx_76_1 == s_idx_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(s_idx_77_1 == s_idx_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(s_idx_78_1 == s_idx_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(s_idx_79_1 == s_idx_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(s_idx_80_1 == s_idx_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(s_idx_81_1 == s_idx_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(s_idx_82_1 == s_idx_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(s_idx_83_1 == s_idx_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(s_idx_84_1 == s_idx_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(s_idx_85_1 == s_idx_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(s_idx_86_1 == s_idx_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(s_idx_87_1 == s_idx_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(s_idx_88_1 == s_idx_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(s_idx_89_1 == s_idx_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(s_idx_90_1 == s_idx_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(s_idx_91_1 == s_idx_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(s_idx_92_1 == s_idx_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(s_idx_93_1 == s_idx_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(s_idx_94_1 == s_idx_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(s_idx_95_1 == s_idx_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(s_idx_96_1 == s_idx_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(s_idx_97_1 == s_idx_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(s_idx_98_1 == s_idx_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(s_idx_99_1 == s_idx_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(s_idx_100_1 == s_idx_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(s_idx_101_1 == s_idx_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(s_idx_102_1 == s_idx_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(s_idx_103_1 == s_idx_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(s_idx_104_1 == s_idx_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(s_idx_105_1 == s_idx_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(s_idx_106_1 == s_idx_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(s_idx_107_1 == s_idx_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(s_idx_108_1 == s_idx_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(s_idx_109_1 == s_idx_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(s_idx_110_1 == s_idx_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(s_idx_111_1 == s_idx_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(s_idx_112_1 == s_idx_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(s_idx_113_1 == s_idx_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(s_idx_114_1 == s_idx_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(s_idx_115_1 == s_idx_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(s_idx_116_1 == s_idx_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(s_idx_117_1 == s_idx_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(s_idx_118_1 == s_idx_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(s_idx_119_1 == s_idx_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(s_idx_120_1 == s_idx_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(s_idx_121_1 == s_idx_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(s_idx_122_1 == s_idx_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(s_idx_123_1 == s_idx_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(s_idx_124_1 == s_idx_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(s_idx_125_1 == s_idx_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(s_idx_126_1 == s_idx_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(s_idx_127_1 == s_idx_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(s_idx_128_1 == s_idx_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(s_idx_129_1 == s_idx_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(s_idx_130_1 == s_idx_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(s_idx_131_1 == s_idx_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(s_idx_132_1 == s_idx_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(s_idx_133_1 == s_idx_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(s_idx_134_1 == s_idx_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(s_idx_135_1 == s_idx_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(s_idx_136_1 == s_idx_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(s_idx_137_1 == s_idx_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(s_idx_138_1 == s_idx_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(s_idx_139_1 == s_idx_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(s_idx_140_1 == s_idx_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(s_idx_141_1 == s_idx_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(s_idx_142_1 == s_idx_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(s_idx_143_1 == s_idx_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(s_idx_144_1 == s_idx_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(s_idx_145_1 == s_idx_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(s_idx_146_1 == s_idx_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(s_idx_147_1 == s_idx_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(s_idx_148_1 == s_idx_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(s_idx_149_1 == s_idx_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(s_idx_150_1 == s_idx_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(s_idx_151_1 == s_idx_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(s_idx_152_1 == s_idx_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(s_idx_153_1 == s_idx_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(s_idx_154_1 == s_idx_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(s_idx_155_1 == s_idx_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(s_idx_156_1 == s_idx_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(s_idx_157_1 == s_idx_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(s_idx_158_1 == s_idx_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(s_idx_159_1 == s_idx_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(s_idx_160_1 == s_idx_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(s_idx_161_1 == s_idx_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(s_idx_162_1 == s_idx_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(s_idx_163_1 == s_idx_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(s_idx_164_1 == s_idx_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(s_idx_165_1 == s_idx_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(s_idx_166_1 == s_idx_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(s_idx_167_1 == s_idx_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(s_idx_168_1 == s_idx_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(s_idx_169_1 == s_idx_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(s_idx_170_1 == s_idx_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(s_idx_171_1 == s_idx_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(s_idx_172_1 == s_idx_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(s_idx_173_1 == s_idx_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(s_idx_174_1 == s_idx_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(s_idx_175_1 == s_idx_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(s_idx_176_1 == s_idx_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(s_idx_177_1 == s_idx_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(s_idx_178_1 == s_idx_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(s_idx_179_1 == s_idx_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(s_idx_180_1 == s_idx_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(s_idx_181_1 == s_idx_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(s_idx_182_1 == s_idx_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(s_idx_183_1 == s_idx_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(s_idx_184_1 == s_idx_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(s_idx_185_1 == s_idx_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(s_idx_186_1 == s_idx_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(s_idx_187_1 == s_idx_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(s_idx_188_1 == s_idx_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(s_idx_189_1 == s_idx_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(s_idx_190_1 == s_idx_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(s_idx_191_1 == s_idx_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(s_idx_192_1 == s_idx_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(s_idx_193_1 == s_idx_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(s_idx_194_1 == s_idx_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(s_idx_195_1 == s_idx_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(s_idx_196_1 == s_idx_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(s_idx_197_1 == s_idx_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(s_idx_198_1 == s_idx_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(s_idx_199_1 == s_idx_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(s_idx_200_1 == s_idx_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(s_idx_201_1 == s_idx_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(s_idx_202_1 == s_idx_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(s_idx_203_1 == s_idx_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(s_idx_204_1 == s_idx_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(s_idx_205_1 == s_idx_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(s_idx_206_1 == s_idx_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(s_idx_207_1 == s_idx_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(s_idx_208_1 == s_idx_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(s_idx_209_1 == s_idx_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(s_idx_210_1 == s_idx_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(s_idx_211_1 == s_idx_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(s_idx_212_1 == s_idx_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(s_idx_213_1 == s_idx_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(s_idx_214_1 == s_idx_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(s_idx_215_1 == s_idx_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(s_idx_216_1 == s_idx_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(s_idx_217_1 == s_idx_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(s_idx_218_1 == s_idx_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(s_idx_219_1 == s_idx_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(s_idx_220_1 == s_idx_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(s_idx_221_1 == s_idx_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(s_idx_222_1 == s_idx_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(s_idx_223_1 == s_idx_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(s_idx_224_1 == s_idx_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(s_idx_225_1 == s_idx_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(s_idx_226_1 == s_idx_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(s_idx_227_1 == s_idx_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(s_idx_228_1 == s_idx_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(s_idx_229_1 == s_idx_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(s_idx_230_1 == s_idx_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(s_idx_231_1 == s_idx_231_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(s_idx_232_1 == s_idx_232_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(s_idx_233_1 == s_idx_233_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(s_idx_234_1 == s_idx_234_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(s_idx_235_1 == s_idx_235_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(s_idx_236_1 == s_idx_236_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(s_idx_237_1 == s_idx_237_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(s_idx_238_1 == s_idx_238_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(s_idx_239_1 == s_idx_239_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(s_idx_240_1 == s_idx_240_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(s_idx_241_1 == s_idx_241_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(s_idx_242_1 == s_idx_242_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(s_idx_243_1 == s_idx_243_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(s_idx_244_1 == s_idx_244_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(s_idx_245_1 == s_idx_245_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(s_idx_246_1 == s_idx_246_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(s_idx_247_1 == s_idx_247_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(s_idx_248_1 == s_idx_248_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(s_idx_249_1 == s_idx_249_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(s_idx_250_1 == s_idx_250_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(s_idx_251_1 == s_idx_251_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(s_idx_252_1 == s_idx_252_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(s_idx_253_1 == s_idx_253_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(s_idx_254_1 == s_idx_254_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(s_idx_255_1 == s_idx_255_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(s_idx_256_1 == s_idx_256_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(s_idx_257_1 == s_idx_257_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(s_idx_258_1 == s_idx_258_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(s_idx_259_1 == s_idx_259_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(s_idx_260_1 == s_idx_260_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(s_idx_261_1 == s_idx_261_2);
  assert(stage_v_261_1 == stage_v_261_2);
  assert(s_idx_262_1 == s_idx_262_2);
  assert(stage_v_262_1 == stage_v_262_2);
  assert(s_idx_263_1 == s_idx_263_2);
  assert(stage_v_263_1 == stage_v_263_2);
  assert(s_idx_264_1 == s_idx_264_2);
  assert(stage_v_264_1 == stage_v_264_2);
}


