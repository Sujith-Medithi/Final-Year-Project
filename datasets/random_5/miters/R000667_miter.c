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
struct StreamBuffer_R000667_6713_0
{
  unsigned char watermark;
  int state;
  int head;
  short tail;
  int buffer[3];
};
struct SensorNode_R000667_6713_1
{
  int offset;
  short status;
  int calib;
  int buffer[3];
};
struct DeviceConfig_R000667_6713_2
{
  int stop_bits;
  short baud_rate;
  short port;
  int buffer[3];
};
union PacketPayload_R000667_6713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000667_6713_1
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
void fn_R000667_6713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000667_6713_1 st_1 = {0};
  struct SensorNode_R000667_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int accumulator_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_18_1 > 16)
  {
    acc_1 = ((acc_1 + (accumulator_18_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_18_2 > 16)
  {
    acc_2 = ((acc_2 + (accumulator_18_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_18_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_18_1 == accumulator_18_2);
}

int fn_R000667_6713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000667_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int accumulator_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_18 > 16)
  {
    acc = ((acc + (accumulator_18 * 2)) + 5) & 127;
    aux ^= accumulator_18 & 15;
  }
  else
  {
    acc = ((acc - accumulator_18) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_56_1 = local_arr_1[aux_1 % 3];
  int phase_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_56_2 * 2)) & 127;
  int checksum_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_95_1) & 63;
  aux_2 = (aux_2 + checksum_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_91_1 > 39)
  {
    acc_1 = ((acc_1 + (quantum_91_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_91_2 > 39)
  {
    acc_2 = ((acc_2 + (quantum_91_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_91_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_56_1 == phase_56_2);
  assert(checksum_95_1 == checksum_95_2);
  assert(quantum_91_1 == quantum_91_2);
}

int fn_R000667_6713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int phase_56 = local_arr[aux % 3];
  acc = (acc + (phase_56 * 2)) & 127;
  int checksum_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_95) & 63;
  acc ^= aux;
  int quantum_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_91 > 39)
  {
    acc = ((acc + (quantum_91 * 2)) + 5) & 127;
    aux ^= quantum_91 & 15;
  }
  else
  {
    acc = ((acc - quantum_91) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000667_6713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int residue_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_73_1) & 63;
  aux_2 = (aux_2 + residue_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_25_1 > 48)
  {
    acc_1 = ((acc_1 + (window_25_1 * 2)) + 5) & 127;
    aux_1 ^= window_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_25_2 > 48)
  {
    acc_2 = ((acc_2 + (window_25_2 * 2)) + 5) & 127;
    aux_2 ^= window_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_73_1 == residue_73_2);
  assert(window_25_1 == window_25_2);
}

int fn_R000667_6713_2(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int residue_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_73) & 63;
  acc ^= aux;
  int window_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_25 > 48)
  {
    acc = ((acc + (window_25 * 2)) + 5) & 127;
    aux ^= window_25 & 15;
  }
  else
  {
    acc = ((acc - window_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000667_6713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000667_6713_1 st_1 = {0};
  struct SensorNode_R000667_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int mask_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_70_1)
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

  switch (mask_70_2)
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
  int mask_14_1 = local_arr_1[aux_1 % 3];
  int mask_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_14_2 * 2)) & 127;
  int margin_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_74_1 > 42)
  {
    acc_1 = ((acc_1 + (margin_74_1 * 2)) + 5) & 127;
    aux_1 ^= margin_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_74_2 > 42)
  {
    acc_2 = ((acc_2 + (margin_74_2 * 2)) + 5) & 127;
    aux_2 ^= margin_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_70_1 == mask_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_14_1 == mask_14_2);
  assert(margin_74_1 == margin_74_2);
}

int fn_R000667_6713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000667_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int mask_70 = (aux + st.buffer[1]) & 3;
  switch (mask_70)
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
  int mask_14 = local_arr[aux % 3];
  acc = (acc + (mask_14 * 2)) & 127;
  int margin_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_74 > 42)
  {
    acc = ((acc + (margin_74 * 2)) + 5) & 127;
    aux ^= margin_74 & 15;
  }
  else
  {
    acc = ((acc - margin_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_72_1 = local_arr_1[aux_1 % 3];
  int damping_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_72_2 * 2)) & 127;
  int tracker_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_62_1 > 45)
  {
    acc_1 = ((acc_1 + (tracker_62_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_62_2 > 45)
  {
    acc_2 = ((acc_2 + (tracker_62_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_59_1)
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

  switch (tracker_59_2)
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

  int pivot_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_96_1) & 63;
  aux_2 = (aux_2 + pivot_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_72_1 == damping_72_2);
  assert(tracker_62_1 == tracker_62_2);
  assert(tracker_59_1 == tracker_59_2);
  assert(pivot_96_1 == pivot_96_2);
}

int fn_R000667_6713_4(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int damping_72 = local_arr[aux % 3];
  acc = (acc + (damping_72 * 2)) & 127;
  int tracker_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_62 > 45)
  {
    acc = ((acc + (tracker_62 * 2)) + 5) & 127;
    aux ^= tracker_62 & 15;
  }
  else
  {
    acc = ((acc - tracker_62) + 11) & 127;
    aux += 3;
  }
  int tracker_59 = (aux + st.buffer[1]) & 3;
  switch (tracker_59)
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

  int pivot_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000667_6713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st_1 = {0};
  struct StreamBuffer_R000667_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_88_1 = local_arr_1[aux_1 % 3];
  int cursor_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_88_2 * 2)) & 127;
  int phase_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_41_1) & 63;
  aux_2 = (aux_2 + phase_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_88_1 == cursor_88_2);
  assert(phase_41_1 == phase_41_2);
}

int fn_R000667_6713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int cursor_88 = local_arr[aux % 3];
  acc = (acc + (cursor_88 * 2)) & 127;
  int phase_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_41) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st_1 = {0};
  struct StreamBuffer_R000667_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int sample_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_79_1) & 63;
  aux_2 = (aux_2 + sample_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_61_1 = local_arr_1[aux_1 % 3];
  int parity_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_79_1 == sample_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_61_1 == parity_61_2);
}

int fn_R000667_6713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int sample_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_79) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_61 = local_arr[aux % 3];
  acc = (acc + (parity_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int segment_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_93_1)
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

  switch (segment_93_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_93_1 == segment_93_2);
}

int fn_R000667_6713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int segment_93 = (aux + st.buffer[1]) & 3;
  switch (segment_93)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_82_1 = local_arr_1[aux_1 % 3];
  int phase_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_82_2 * 2)) & 127;
  int quantum_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_45_1) & 63;
  aux_2 = (aux_2 + quantum_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_92_1)
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

  switch (threshold_92_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_82_1 == phase_82_2);
  assert(quantum_45_1 == quantum_45_2);
  assert(threshold_92_1 == threshold_92_2);
}

int fn_R000667_6713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int phase_82 = local_arr[aux % 3];
  acc = (acc + (phase_82 * 2)) & 127;
  int quantum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_45) & 63;
  acc ^= aux;
  int threshold_92 = (aux + st.buffer[1]) & 3;
  switch (threshold_92)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_25_1 = local_arr_1[aux_1 % 3];
  int offset_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_25_2 * 2)) & 127;
  int parity_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_42_1) & 63;
  aux_2 = (aux_2 + parity_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_87_1 > 35)
  {
    acc_1 = ((acc_1 + (window_87_1 * 2)) + 5) & 127;
    aux_1 ^= window_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_87_2 > 35)
  {
    acc_2 = ((acc_2 + (window_87_2 * 2)) + 5) & 127;
    aux_2 ^= window_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_61_1)
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

  switch (sample_61_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_25_1 == offset_25_2);
  assert(parity_42_1 == parity_42_2);
  assert(window_87_1 == window_87_2);
  assert(sample_61_1 == sample_61_2);
}

int fn_R000667_6713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int offset_25 = local_arr[aux % 3];
  acc = (acc + (offset_25 * 2)) & 127;
  int parity_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_42) & 63;
  acc ^= aux;
  int window_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_87 > 35)
  {
    acc = ((acc + (window_87 * 2)) + 5) & 127;
    aux ^= window_87 & 15;
  }
  else
  {
    acc = ((acc - window_87) + 11) & 127;
    aux += 3;
  }
  int sample_61 = (aux + st.buffer[1]) & 3;
  switch (sample_61)
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

void fn_R000667_6713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st_1 = {0};
  struct StreamBuffer_R000667_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int sample_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_47_1) & 63;
  aux_2 = (aux_2 + sample_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_47_1 == sample_47_2);
}

int fn_R000667_6713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int sample_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_47) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int segment_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_83_1)
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

  switch (segment_83_2)
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

  int cursor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_68_1 > 32)
  {
    acc_1 = ((acc_1 + (cursor_68_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_68_2 > 32)
  {
    acc_2 = ((acc_2 + (cursor_68_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_97_1) & 63;
  aux_2 = (aux_2 + phase_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_83_1 == segment_83_2);
  assert(cursor_68_1 == cursor_68_2);
  assert(phase_97_1 == phase_97_2);
}

int fn_R000667_6713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int segment_83 = (aux + st.buffer[1]) & 3;
  switch (segment_83)
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

  int cursor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_68 > 32)
  {
    acc = ((acc + (cursor_68 * 2)) + 5) & 127;
    aux ^= cursor_68 & 15;
  }
  else
  {
    acc = ((acc - cursor_68) + 11) & 127;
    aux += 3;
  }
  int phase_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000667_6713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int vector_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_14_1 > 17)
  {
    acc_1 = ((acc_1 + (vector_14_1 * 2)) + 5) & 127;
    aux_1 ^= vector_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_14_2 > 17)
  {
    acc_2 = ((acc_2 + (vector_14_2 * 2)) + 5) & 127;
    aux_2 ^= vector_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_14_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_93_1 = local_arr_1[aux_1 % 3];
  int metric_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_93_2 * 2)) & 127;
  int weight_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_89_1) & 63;
  aux_2 = (aux_2 + weight_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_14_1 == vector_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_93_1 == metric_93_2);
  assert(weight_89_1 == weight_89_2);
}

int fn_R000667_6713_12(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int vector_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_14 > 17)
  {
    acc = ((acc + (vector_14 * 2)) + 5) & 127;
    aux ^= vector_14 & 15;
  }
  else
  {
    acc = ((acc - vector_14) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_93 = local_arr[aux % 3];
  acc = (acc + (metric_93 * 2)) & 127;
  int weight_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000667_6713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int checksum_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_43_1) & 63;
  aux_2 = (aux_2 + checksum_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_27_1 = local_arr_1[aux_1 % 3];
  int factor_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_27_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_13_1)
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

  switch (cursor_13_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_43_1 == checksum_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_27_1 == factor_27_2);
  assert(cursor_13_1 == cursor_13_2);
}

int fn_R000667_6713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int checksum_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_43) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_27 = local_arr[aux % 3];
  acc = (acc + (factor_27 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_13 = (aux + st.buffer[1]) & 3;
  switch (cursor_13)
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

void fn_R000667_6713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000667_6713_1 st_1 = {0};
  struct SensorNode_R000667_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tally_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_44_1 > 35)
  {
    acc_1 = ((acc_1 + (tally_44_1 * 2)) + 5) & 127;
    aux_1 ^= tally_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_44_2 > 35)
  {
    acc_2 = ((acc_2 + (tally_44_2 * 2)) + 5) & 127;
    aux_2 ^= tally_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_54_1) & 63;
  aux_2 = (aux_2 + anchor_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_44_1 == tally_44_2);
  assert(anchor_54_1 == anchor_54_2);
}

int fn_R000667_6713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000667_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tally_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_44 > 35)
  {
    acc = ((acc + (tally_44 * 2)) + 5) & 127;
    aux ^= tally_44 & 15;
  }
  else
  {
    acc = ((acc - tally_44) + 11) & 127;
    aux += 3;
  }
  int anchor_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000667_6713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st_1 = {0};
  struct StreamBuffer_R000667_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int accumulator_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_91_1)
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

  switch (accumulator_91_2)
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

  int phase_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_56_1 > 28)
  {
    acc_1 = ((acc_1 + (phase_56_1 * 2)) + 5) & 127;
    aux_1 ^= phase_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_56_2 > 28)
  {
    acc_2 = ((acc_2 + (phase_56_2 * 2)) + 5) & 127;
    aux_2 ^= phase_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_95_1 = local_arr_1[aux_1 % 3];
  int quantum_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_91_1 == accumulator_91_2);
  assert(phase_56_1 == phase_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_95_1 == quantum_95_2);
}

int fn_R000667_6713_15(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int accumulator_91 = (aux + st.buffer[1]) & 3;
  switch (accumulator_91)
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

  int phase_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_56 > 28)
  {
    acc = ((acc + (phase_56 * 2)) + 5) & 127;
    aux ^= phase_56 & 15;
  }
  else
  {
    acc = ((acc - phase_56) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_95 = local_arr[aux % 3];
  acc = (acc + (quantum_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_29_1 = local_arr_1[aux_1 % 3];
  int scale_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_29_2 * 2)) & 127;
  int margin_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_91_1)
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

  switch (margin_91_2)
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

  int stride_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_31_1 > 16)
  {
    acc_1 = ((acc_1 + (stride_31_1 * 2)) + 5) & 127;
    aux_1 ^= stride_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_31_2 > 16)
  {
    acc_2 = ((acc_2 + (stride_31_2 * 2)) + 5) & 127;
    aux_2 ^= stride_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_44_1) & 63;
  aux_2 = (aux_2 + parity_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_29_1 == scale_29_2);
  assert(margin_91_1 == margin_91_2);
  assert(stride_31_1 == stride_31_2);
  assert(parity_44_1 == parity_44_2);
}

int fn_R000667_6713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int scale_29 = local_arr[aux % 3];
  acc = (acc + (scale_29 * 2)) & 127;
  int margin_91 = (aux + st.buffer[1]) & 3;
  switch (margin_91)
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

  int stride_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_31 > 16)
  {
    acc = ((acc + (stride_31 * 2)) + 5) & 127;
    aux ^= stride_31 & 15;
  }
  else
  {
    acc = ((acc - stride_31) + 11) & 127;
    aux += 3;
  }
  int parity_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000667_6713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st_1 = {0};
  struct StreamBuffer_R000667_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int threshold_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_77_1 > 25)
  {
    acc_1 = ((acc_1 + (threshold_77_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_77_2 > 25)
  {
    acc_2 = ((acc_2 + (threshold_77_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_59_1)
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

  switch (bound_59_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_77_1 == threshold_77_2);
  assert(bound_59_1 == bound_59_2);
}

int fn_R000667_6713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int threshold_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_77 > 25)
  {
    acc = ((acc + (threshold_77 * 2)) + 5) & 127;
    aux ^= threshold_77 & 15;
  }
  else
  {
    acc = ((acc - threshold_77) + 11) & 127;
    aux += 3;
  }
  int bound_59 = (aux + st.buffer[1]) & 3;
  switch (bound_59)
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

void fn_R000667_6713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int stride_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_67_1) & 63;
  aux_2 = (aux_2 + stride_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_56_1 = local_arr_1[aux_1 % 3];
  int checksum_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_67_1 == stride_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_56_1 == checksum_56_2);
}

int fn_R000667_6713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int stride_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_67) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_56 = local_arr[aux % 3];
  acc = (acc + (checksum_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int bound_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_62_1) & 63;
  aux_2 = (aux_2 + bound_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_15_1)
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

  switch (anchor_15_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_58_1 = local_arr_1[aux_1 % 3];
  int mask_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_62_1 == bound_62_2);
  assert(anchor_15_1 == anchor_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_58_1 == mask_58_2);
}

int fn_R000667_6713_19(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000667_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int bound_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_62) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_15 = (aux + st.buffer[1]) & 3;
  switch (anchor_15)
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

  int local_arr[3] = {4, 9, 15};
  int mask_58 = local_arr[aux % 3];
  acc = (acc + (mask_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000667_6713_1 st_1 = {0};
  struct SensorNode_R000667_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int pivot_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_68_1)
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

  switch (pivot_68_2)
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

  int vector_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_16_1) & 63;
  aux_2 = (aux_2 + vector_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_98_1 > 10)
  {
    acc_1 = ((acc_1 + (quotient_98_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_98_2 > 10)
  {
    acc_2 = ((acc_2 + (quotient_98_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_98_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_68_1 == pivot_68_2);
  assert(vector_16_1 == vector_16_2);
  assert(quotient_98_1 == quotient_98_2);
}

int fn_R000667_6713_20(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000667_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int pivot_68 = (aux + st.buffer[1]) & 3;
  switch (pivot_68)
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

  int vector_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_16) & 63;
  acc ^= aux;
  int quotient_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_98 > 10)
  {
    acc = ((acc + (quotient_98 * 2)) + 5) & 127;
    aux ^= quotient_98 & 15;
  }
  else
  {
    acc = ((acc - quotient_98) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st_1 = {0};
  struct StreamBuffer_R000667_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_35_1 = local_arr_1[aux_1 % 3];
  int threshold_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_35_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_35_1 == threshold_35_2);
}

int fn_R000667_6713_21(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int threshold_35 = local_arr[aux % 3];
  acc = (acc + (threshold_35 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000667_6713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st_1 = {0};
  struct StreamBuffer_R000667_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int metric_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_29_1)
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

  switch (metric_29_2)
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
  int bound_97_1 = local_arr_1[aux_1 % 3];
  int bound_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_29_1 == metric_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_97_1 == bound_97_2);
}

int fn_R000667_6713_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000667_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int metric_29 = (aux + st.buffer[1]) & 3;
  switch (metric_29)
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
  int bound_97 = local_arr[aux % 3];
  acc = (acc + (bound_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000667_0_1;
  int sec_r000667_0_2;
  int sec_r000667_1_1;
  int sec_r000667_1_2;
  int sec_r000667_2_1;
  int sec_r000667_2_2;
  int sec_r000667_3_1;
  int sec_r000667_3_2;
  int sec_r000667_4_1;
  int sec_r000667_4_2;
  int sec_r000667_5_1;
  int sec_r000667_5_2;
  int sec_r000667_6_1;
  int sec_r000667_6_2;
  int sec_r000667_7_1;
  int sec_r000667_7_2;
  int sec_r000667_8_1;
  int sec_r000667_8_2;
  int sec_r000667_9_1;
  int sec_r000667_9_2;
  int sec_r000667_10_1;
  int sec_r000667_10_2;
  int sec_r000667_11_1;
  int sec_r000667_11_2;
  int sec_r000667_12_1;
  int sec_r000667_12_2;
  int sec_r000667_13_1;
  int sec_r000667_13_2;
  int sec_r000667_14_1;
  int sec_r000667_14_2;
  int sec_r000667_15_1;
  int sec_r000667_15_2;
  int sec_r000667_16_1;
  int sec_r000667_16_2;
  int sec_r000667_17_1;
  int sec_r000667_17_2;
  int sec_r000667_18_1;
  int sec_r000667_18_2;
  int sec_r000667_19_1;
  int sec_r000667_19_2;
  int sec_r000667_20_1;
  int sec_r000667_20_2;
  int sec_r000667_21_1;
  int sec_r000667_21_2;
  int pub_r000667_0_1;
  int pub_r000667_0_2;
  int pub_r000667_1_1;
  int pub_r000667_1_2;
  int pub_r000667_2_1;
  int pub_r000667_2_2;
  int pub_r000667_3_1;
  int pub_r000667_3_2;
  int pub_r000667_4_1;
  int pub_r000667_4_2;
  int pub_r000667_5_1;
  int pub_r000667_5_2;
  int pub_r000667_6_1;
  int pub_r000667_6_2;
  int pub_r000667_7_1;
  int pub_r000667_7_2;
  int pub_r000667_8_1;
  int pub_r000667_8_2;
  int pub_r000667_9_1;
  int pub_r000667_9_2;
  int pub_r000667_10_1;
  int pub_r000667_10_2;
  int pub_r000667_11_1;
  int pub_r000667_11_2;
  int pub_r000667_12_1;
  int pub_r000667_12_2;
  int pub_r000667_13_1;
  int pub_r000667_13_2;
  int pub_r000667_14_1;
  int pub_r000667_14_2;
  int pub_r000667_15_1;
  int pub_r000667_15_2;
  int pub_r000667_16_1;
  int pub_r000667_16_2;
  int pub_r000667_17_1;
  int pub_r000667_17_2;
  int pub_r000667_18_1;
  int pub_r000667_18_2;
  int pub_r000667_19_1;
  int pub_r000667_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000667_0_1 >= (-100)) && (pub_r000667_0_1 <= 100));
  __CPROVER_assume((pub_r000667_0_2 >= (-100)) && (pub_r000667_0_2 <= 100));
  __CPROVER_assume((pub_r000667_1_1 >= (-100)) && (pub_r000667_1_1 <= 100));
  __CPROVER_assume((pub_r000667_1_2 >= (-100)) && (pub_r000667_1_2 <= 100));
  __CPROVER_assume((pub_r000667_2_1 >= (-100)) && (pub_r000667_2_1 <= 100));
  __CPROVER_assume((pub_r000667_2_2 >= (-100)) && (pub_r000667_2_2 <= 100));
  __CPROVER_assume((pub_r000667_3_1 >= (-100)) && (pub_r000667_3_1 <= 100));
  __CPROVER_assume((pub_r000667_3_2 >= (-100)) && (pub_r000667_3_2 <= 100));
  __CPROVER_assume((pub_r000667_4_1 >= (-100)) && (pub_r000667_4_1 <= 100));
  __CPROVER_assume((pub_r000667_4_2 >= (-100)) && (pub_r000667_4_2 <= 100));
  __CPROVER_assume((pub_r000667_5_1 >= (-100)) && (pub_r000667_5_1 <= 100));
  __CPROVER_assume((pub_r000667_5_2 >= (-100)) && (pub_r000667_5_2 <= 100));
  __CPROVER_assume((pub_r000667_6_1 >= (-100)) && (pub_r000667_6_1 <= 100));
  __CPROVER_assume((pub_r000667_6_2 >= (-100)) && (pub_r000667_6_2 <= 100));
  __CPROVER_assume((pub_r000667_7_1 >= (-100)) && (pub_r000667_7_1 <= 100));
  __CPROVER_assume((pub_r000667_7_2 >= (-100)) && (pub_r000667_7_2 <= 100));
  __CPROVER_assume((pub_r000667_8_1 >= (-100)) && (pub_r000667_8_1 <= 100));
  __CPROVER_assume((pub_r000667_8_2 >= (-100)) && (pub_r000667_8_2 <= 100));
  __CPROVER_assume((pub_r000667_9_1 >= (-100)) && (pub_r000667_9_1 <= 100));
  __CPROVER_assume((pub_r000667_9_2 >= (-100)) && (pub_r000667_9_2 <= 100));
  __CPROVER_assume((pub_r000667_10_1 >= (-100)) && (pub_r000667_10_1 <= 100));
  __CPROVER_assume((pub_r000667_10_2 >= (-100)) && (pub_r000667_10_2 <= 100));
  __CPROVER_assume((pub_r000667_11_1 >= (-100)) && (pub_r000667_11_1 <= 100));
  __CPROVER_assume((pub_r000667_11_2 >= (-100)) && (pub_r000667_11_2 <= 100));
  __CPROVER_assume((pub_r000667_12_1 >= (-100)) && (pub_r000667_12_1 <= 100));
  __CPROVER_assume((pub_r000667_12_2 >= (-100)) && (pub_r000667_12_2 <= 100));
  __CPROVER_assume((pub_r000667_13_1 >= (-100)) && (pub_r000667_13_1 <= 100));
  __CPROVER_assume((pub_r000667_13_2 >= (-100)) && (pub_r000667_13_2 <= 100));
  __CPROVER_assume((pub_r000667_14_1 >= (-100)) && (pub_r000667_14_1 <= 100));
  __CPROVER_assume((pub_r000667_14_2 >= (-100)) && (pub_r000667_14_2 <= 100));
  __CPROVER_assume((pub_r000667_15_1 >= (-100)) && (pub_r000667_15_1 <= 100));
  __CPROVER_assume((pub_r000667_15_2 >= (-100)) && (pub_r000667_15_2 <= 100));
  __CPROVER_assume((pub_r000667_16_1 >= (-100)) && (pub_r000667_16_1 <= 100));
  __CPROVER_assume((pub_r000667_16_2 >= (-100)) && (pub_r000667_16_2 <= 100));
  __CPROVER_assume((pub_r000667_17_1 >= (-100)) && (pub_r000667_17_1 <= 100));
  __CPROVER_assume((pub_r000667_17_2 >= (-100)) && (pub_r000667_17_2 <= 100));
  __CPROVER_assume((pub_r000667_18_1 >= (-100)) && (pub_r000667_18_1 <= 100));
  __CPROVER_assume((pub_r000667_18_2 >= (-100)) && (pub_r000667_18_2 <= 100));
  __CPROVER_assume((pub_r000667_19_1 >= (-100)) && (pub_r000667_19_1 <= 100));
  __CPROVER_assume((pub_r000667_19_2 >= (-100)) && (pub_r000667_19_2 <= 100));
  __CPROVER_assume((sec_r000667_0_1 >= 0) && (sec_r000667_0_1 <= 255));
  __CPROVER_assume((sec_r000667_0_2 >= 0) && (sec_r000667_0_2 <= 255));
  __CPROVER_assume((sec_r000667_1_1 >= 0) && (sec_r000667_1_1 <= 255));
  __CPROVER_assume((sec_r000667_1_2 >= 0) && (sec_r000667_1_2 <= 255));
  __CPROVER_assume((sec_r000667_2_1 >= 0) && (sec_r000667_2_1 <= 255));
  __CPROVER_assume((sec_r000667_2_2 >= 0) && (sec_r000667_2_2 <= 255));
  __CPROVER_assume((sec_r000667_3_1 >= 0) && (sec_r000667_3_1 <= 255));
  __CPROVER_assume((sec_r000667_3_2 >= 0) && (sec_r000667_3_2 <= 255));
  __CPROVER_assume((sec_r000667_4_1 >= 0) && (sec_r000667_4_1 <= 255));
  __CPROVER_assume((sec_r000667_4_2 >= 0) && (sec_r000667_4_2 <= 255));
  __CPROVER_assume((sec_r000667_5_1 >= 0) && (sec_r000667_5_1 <= 255));
  __CPROVER_assume((sec_r000667_5_2 >= 0) && (sec_r000667_5_2 <= 255));
  __CPROVER_assume((sec_r000667_6_1 >= 0) && (sec_r000667_6_1 <= 255));
  __CPROVER_assume((sec_r000667_6_2 >= 0) && (sec_r000667_6_2 <= 255));
  __CPROVER_assume((sec_r000667_7_1 >= 0) && (sec_r000667_7_1 <= 255));
  __CPROVER_assume((sec_r000667_7_2 >= 0) && (sec_r000667_7_2 <= 255));
  __CPROVER_assume((sec_r000667_8_1 >= 0) && (sec_r000667_8_1 <= 255));
  __CPROVER_assume((sec_r000667_8_2 >= 0) && (sec_r000667_8_2 <= 255));
  __CPROVER_assume((sec_r000667_9_1 >= 0) && (sec_r000667_9_1 <= 255));
  __CPROVER_assume((sec_r000667_9_2 >= 0) && (sec_r000667_9_2 <= 255));
  __CPROVER_assume((sec_r000667_10_1 >= 0) && (sec_r000667_10_1 <= 255));
  __CPROVER_assume((sec_r000667_10_2 >= 0) && (sec_r000667_10_2 <= 255));
  __CPROVER_assume((sec_r000667_11_1 >= 0) && (sec_r000667_11_1 <= 255));
  __CPROVER_assume((sec_r000667_11_2 >= 0) && (sec_r000667_11_2 <= 255));
  __CPROVER_assume((sec_r000667_12_1 >= 0) && (sec_r000667_12_1 <= 255));
  __CPROVER_assume((sec_r000667_12_2 >= 0) && (sec_r000667_12_2 <= 255));
  __CPROVER_assume((sec_r000667_13_1 >= 0) && (sec_r000667_13_1 <= 255));
  __CPROVER_assume((sec_r000667_13_2 >= 0) && (sec_r000667_13_2 <= 255));
  __CPROVER_assume((sec_r000667_14_1 >= 0) && (sec_r000667_14_1 <= 255));
  __CPROVER_assume((sec_r000667_14_2 >= 0) && (sec_r000667_14_2 <= 255));
  __CPROVER_assume((sec_r000667_15_1 >= 0) && (sec_r000667_15_1 <= 255));
  __CPROVER_assume((sec_r000667_15_2 >= 0) && (sec_r000667_15_2 <= 255));
  __CPROVER_assume((sec_r000667_16_1 >= 0) && (sec_r000667_16_1 <= 255));
  __CPROVER_assume((sec_r000667_16_2 >= 0) && (sec_r000667_16_2 <= 255));
  __CPROVER_assume((sec_r000667_17_1 >= 0) && (sec_r000667_17_1 <= 255));
  __CPROVER_assume((sec_r000667_17_2 >= 0) && (sec_r000667_17_2 <= 255));
  __CPROVER_assume((sec_r000667_18_1 >= 0) && (sec_r000667_18_1 <= 255));
  __CPROVER_assume((sec_r000667_18_2 >= 0) && (sec_r000667_18_2 <= 255));
  __CPROVER_assume((sec_r000667_19_1 >= 0) && (sec_r000667_19_1 <= 255));
  __CPROVER_assume((sec_r000667_19_2 >= 0) && (sec_r000667_19_2 <= 255));
  __CPROVER_assume((sec_r000667_20_1 >= 0) && (sec_r000667_20_1 <= 255));
  __CPROVER_assume((sec_r000667_20_2 >= 0) && (sec_r000667_20_2 <= 255));
  __CPROVER_assume((sec_r000667_21_1 >= 0) && (sec_r000667_21_1 <= 255));
  __CPROVER_assume((sec_r000667_21_2 >= 0) && (sec_r000667_21_2 <= 255));
  struct StreamBuffer_R000667_6713_0 st_var_0_1 = {0};
  struct StreamBuffer_R000667_6713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000667_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000667_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000667_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000667_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000667_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000667_0_2 + 7) & 15;
  struct SensorNode_R000667_6713_1 st_var_1_1 = {0};
  struct SensorNode_R000667_6713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000667_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000667_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000667_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000667_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000667_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000667_0_2 + 9) & 15;
  struct DeviceConfig_R000667_6713_2 st_var_2_1 = {0};
  struct DeviceConfig_R000667_6713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000667_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000667_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000667_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000667_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000667_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000667_0_2 + 11) & 15;
  union PacketPayload_R000667_6713_0 u_var_1;
  union PacketPayload_R000667_6713_0 u_var_2;
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
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = ((st_var_2_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_2_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 50)
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
  if (stage_v_5_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 50)
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
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = ((st_var_2_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_2_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 48)
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
  if (stage_v_8_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 48)
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
  int stage_v_10_1 = (st_var_1_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_1_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 25)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 25)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_15_1 = ((st_var_0_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_0_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 47)
    {
      chk_sum_1 ^= stage_v_15_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_15_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 47)
    {
      chk_sum_2 ^= stage_v_15_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((st_var_0_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_0_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 43)
    {
      chk_sum_1 ^= stage_v_27_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_27_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 43)
    {
      chk_sum_2 ^= stage_v_27_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((st_var_2_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_2_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 32)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 32)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_33_1 = ((st_var_0_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_0_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 46)
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
  if (stage_v_33_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 46)
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
  if ((sec_r000667_12_1 & 1) != 0)
  {
    if ((sec_r000667_3_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000667_16_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000667_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000667_16_1 + 7) & 127;
  }
  if ((sec_r000667_12_2 & 1) != 0)
  {
    if ((sec_r000667_3_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000667_16_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000667_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000667_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000667_9_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000667_12_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000667_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000667_12_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000667_9_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000667_12_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000667_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000667_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((sec_r000667_17_1 & 1) != 0)
  {
    if ((sec_r000667_0_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000667_9_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000667_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000667_9_1 + 7) & 127;
  }
  if ((sec_r000667_17_2 & 1) != 0)
  {
    if ((sec_r000667_0_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000667_9_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000667_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000667_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000667_14_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000667_18_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000667_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000667_18_1 + 7) & 127;
  }
  if ((sec_r000667_14_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000667_18_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000667_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000667_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000667_19_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000667_11_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000667_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000667_11_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000667_19_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000667_11_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000667_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000667_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000667_0_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000667_13_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000667_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000667_13_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000667_0_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000667_13_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000667_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000667_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000667_2_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000667_1_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000667_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000667_1_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000667_2_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000667_1_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000667_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000667_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000667_1_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000667_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000667_1_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000667_1_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000667_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000667_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((sec_r000667_15_1 & 1) != 0)
  {
    if ((sec_r000667_10_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000667_5_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000667_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000667_5_1 + 7) & 127;
  }
  if ((sec_r000667_15_2 & 1) != 0)
  {
    if ((sec_r000667_10_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000667_5_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000667_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000667_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000667_11_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000667_12_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000667_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000667_12_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000667_11_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000667_12_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000667_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000667_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000667_11_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000667_15_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000667_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000667_15_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000667_11_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000667_15_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000667_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000667_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000667_15_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000667_11_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000667_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000667_11_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000667_15_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000667_11_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000667_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000667_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000667_2_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000667_3_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000667_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000667_3_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000667_2_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000667_3_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000667_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000667_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000667_11_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000667_16_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000667_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000667_16_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000667_11_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000667_16_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000667_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000667_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000667_11_1 & 1) != 0)
  {
    if ((sec_r000667_16_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000667_1_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000667_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000667_1_1 + 7) & 127;
  }
  if ((sec_r000667_11_2 & 1) != 0)
  {
    if ((sec_r000667_16_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000667_1_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000667_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000667_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000667_15_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000667_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000667_15_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000667_15_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000667_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000667_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000667_19_1 & 1) != 0)
  {
    if ((sec_r000667_19_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000667_14_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000667_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000667_14_1 + 7) & 127;
  }
  if ((sec_r000667_19_2 & 1) != 0)
  {
    if ((sec_r000667_19_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000667_14_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000667_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000667_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000667_5_1 & 1) != 0)
  {
    if ((sec_r000667_15_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000667_4_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000667_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000667_4_1 + 7) & 127;
  }
  if ((sec_r000667_5_2 & 1) != 0)
  {
    if ((sec_r000667_15_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000667_4_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000667_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000667_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000667_18_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000667_7_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000667_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000667_7_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000667_18_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000667_7_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000667_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000667_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000667_1_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000667_18_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000667_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000667_18_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000667_1_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000667_18_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000667_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000667_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000667_14_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000667_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000667_14_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000667_14_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000667_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000667_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000667_14_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000667_14_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000667_5_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000667_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000667_5_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000667_5_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000667_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000667_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000667_3_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000667_1_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000667_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000667_1_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000667_3_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000667_1_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000667_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000667_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000667_9_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000667_1_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000667_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000667_1_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000667_9_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000667_1_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000667_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000667_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000667_10_1 & 1) != 0)
  {
    if ((sec_r000667_0_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000667_11_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000667_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000667_11_1 + 7) & 127;
  }
  if ((sec_r000667_10_2 & 1) != 0)
  {
    if ((sec_r000667_0_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000667_11_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000667_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000667_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000667_1_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000667_7_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000667_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000667_7_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000667_1_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000667_7_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000667_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000667_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000667_8_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000667_14_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000667_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000667_14_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000667_8_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000667_14_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000667_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000667_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000667_14_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000667_9_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000667_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000667_9_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000667_14_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000667_9_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000667_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000667_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000667_10_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000667_0_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000667_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000667_0_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000667_10_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000667_0_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000667_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000667_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000667_0_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000667_0_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000667_12_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000667_13_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000667_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000667_13_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000667_12_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000667_13_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000667_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000667_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000667_13_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000667_13_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000667_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000667_13_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000667_13_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000667_13_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000667_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000667_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000667_1_1 & 1) != 0)
  {
    if ((sec_r000667_6_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((sec_r000667_1_2 & 1) != 0)
  {
    if ((sec_r000667_6_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000667_4_1 & 1) != 0)
  {
    if ((sec_r000667_21_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000667_15_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000667_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000667_15_1 + 7) & 127;
  }
  if ((sec_r000667_4_2 & 1) != 0)
  {
    if ((sec_r000667_21_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000667_15_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000667_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000667_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000667_5_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000667_7_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000667_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000667_7_1 + 7) & 127;
  }
  if ((sec_r000667_5_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000667_7_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000667_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000667_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000667_1_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000667_4_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000667_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000667_4_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000667_1_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000667_4_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000667_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000667_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000667_10_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000667_11_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000667_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000667_11_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000667_10_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000667_11_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000667_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000667_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000667_12_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000667_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000667_12_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000667_12_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000667_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000667_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000667_14_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000667_3_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000667_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000667_3_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000667_14_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000667_3_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000667_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000667_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000667_16_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000667_2_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000667_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000667_2_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000667_16_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000667_2_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000667_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000667_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000667_8_1 & 1) != 0)
  {
    if ((sec_r000667_10_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000667_10_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000667_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000667_10_1 + 7) & 127;
  }
  if ((sec_r000667_8_2 & 1) != 0)
  {
    if ((sec_r000667_10_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000667_10_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000667_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000667_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000667_21_1 & 1) != 0)
  {
    if ((sec_r000667_12_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000667_7_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000667_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000667_7_1 + 7) & 127;
  }
  if ((sec_r000667_21_2 & 1) != 0)
  {
    if ((sec_r000667_12_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000667_7_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000667_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000667_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000667_18_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000667_2_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000667_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000667_2_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000667_18_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000667_2_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000667_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000667_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000667_2_1 & 1) != 0)
  {
    if ((sec_r000667_10_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000667_16_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000667_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000667_16_1 + 7) & 127;
  }
  if ((sec_r000667_2_2 & 1) != 0)
  {
    if ((sec_r000667_10_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000667_16_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000667_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000667_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000667_19_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000667_9_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000667_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000667_9_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000667_19_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000667_9_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000667_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000667_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000667_13_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000667_12_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000667_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000667_12_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000667_13_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000667_12_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000667_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000667_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000667_7_1 & 1) != 0)
  {
    if ((sec_r000667_2_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000667_14_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000667_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000667_14_1 + 7) & 127;
  }
  if ((sec_r000667_7_2 & 1) != 0)
  {
    if ((sec_r000667_2_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000667_14_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000667_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000667_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000667_13_1 & 1) != 0)
  {
    if ((sec_r000667_15_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000667_14_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000667_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000667_14_1 + 7) & 127;
  }
  if ((sec_r000667_13_2 & 1) != 0)
  {
    if ((sec_r000667_15_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000667_14_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000667_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000667_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000667_1_1 & 1) != 0)
  {
    if ((sec_r000667_0_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((sec_r000667_1_2 & 1) != 0)
  {
    if ((sec_r000667_0_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000667_11_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000667_1_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000667_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000667_1_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000667_11_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000667_1_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000667_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000667_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000667_1_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000667_12_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000667_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000667_12_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000667_1_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000667_12_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000667_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000667_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000667_7_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000667_2_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000667_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000667_2_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000667_7_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000667_2_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000667_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000667_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000667_12_1 & 1) != 0)
  {
    if ((sec_r000667_1_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000667_7_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000667_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000667_7_1 + 7) & 127;
  }
  if ((sec_r000667_12_2 & 1) != 0)
  {
    if ((sec_r000667_1_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000667_7_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000667_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000667_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000667_13_1 & 1) != 0)
  {
    if ((sec_r000667_9_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000667_18_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000667_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000667_18_1 + 7) & 127;
  }
  if ((sec_r000667_13_2 & 1) != 0)
  {
    if ((sec_r000667_9_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000667_18_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000667_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000667_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000667_16_1 & 1) != 0)
  {
    if ((sec_r000667_15_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000667_3_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000667_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000667_3_1 + 7) & 127;
  }
  if ((sec_r000667_16_2 & 1) != 0)
  {
    if ((sec_r000667_15_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000667_3_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000667_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000667_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000667_1_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000667_15_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000667_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000667_15_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000667_1_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000667_15_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000667_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000667_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000667_11_1 & 1) != 0)
  {
    if ((sec_r000667_7_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000667_10_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000667_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000667_10_1 + 7) & 127;
  }
  if ((sec_r000667_11_2 & 1) != 0)
  {
    if ((sec_r000667_7_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000667_10_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000667_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000667_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000667_13_1 & 1) != 0)
  {
    if ((sec_r000667_1_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000667_8_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000667_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000667_8_1 + 7) & 127;
  }
  if ((sec_r000667_13_2 & 1) != 0)
  {
    if ((sec_r000667_1_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000667_8_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000667_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000667_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000667_4_1 & 1) != 0)
  {
    if ((sec_r000667_21_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000667_9_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000667_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000667_9_1 + 7) & 127;
  }
  if ((sec_r000667_4_2 & 1) != 0)
  {
    if ((sec_r000667_21_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000667_9_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000667_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000667_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000667_16_1 & 1) != 0)
  {
    if ((sec_r000667_3_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000667_2_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000667_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000667_2_1 + 7) & 127;
  }
  if ((sec_r000667_16_2 & 1) != 0)
  {
    if ((sec_r000667_3_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000667_2_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000667_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000667_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000667_13_1 & 1) != 0)
  {
    if ((sec_r000667_18_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000667_7_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000667_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000667_7_1 + 7) & 127;
  }
  if ((sec_r000667_13_2 & 1) != 0)
  {
    if ((sec_r000667_18_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000667_7_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000667_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000667_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000667_4_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000667_5_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000667_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000667_5_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000667_4_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000667_5_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000667_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000667_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000667_10_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000667_4_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000667_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000667_4_1 + 7) & 127;
  }
  if ((sec_r000667_10_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000667_4_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000667_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000667_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000667_6_1 & 1) != 0)
  {
    if ((sec_r000667_11_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000667_13_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000667_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000667_13_1 + 7) & 127;
  }
  if ((sec_r000667_6_2 & 1) != 0)
  {
    if ((sec_r000667_11_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000667_13_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000667_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000667_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000667_14_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000667_7_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000667_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000667_7_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000667_14_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000667_7_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000667_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000667_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000667_3_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000667_4_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000667_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000667_4_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000667_3_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000667_4_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000667_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000667_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000667_3_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000667_11_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000667_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000667_11_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000667_3_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000667_11_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000667_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000667_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000667_21_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000667_4_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000667_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000667_4_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000667_21_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000667_4_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000667_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000667_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000667_15_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000667_9_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000667_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000667_9_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000667_15_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000667_9_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000667_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000667_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000667_0_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000667_7_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000667_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000667_7_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000667_0_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000667_7_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000667_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000667_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000667_0_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000667_10_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000667_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000667_10_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000667_0_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000667_10_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000667_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000667_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000667_21_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000667_21_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000667_9_1 & 1) != 0)
  {
    if ((sec_r000667_20_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000667_17_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000667_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000667_17_1 + 7) & 127;
  }
  if ((sec_r000667_9_2 & 1) != 0)
  {
    if ((sec_r000667_20_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000667_17_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000667_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000667_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000667_6_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000667_1_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000667_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000667_1_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000667_6_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000667_1_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000667_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000667_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000667_2_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000667_18_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000667_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000667_18_1 + 7) & 127;
  }
  if ((sec_r000667_2_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000667_18_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000667_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000667_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000667_20_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000667_9_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000667_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000667_9_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000667_20_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000667_9_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000667_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000667_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000667_18_1 & 1) != 0)
  {
    if ((sec_r000667_21_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000667_14_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000667_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000667_14_1 + 7) & 127;
  }
  if ((sec_r000667_18_2 & 1) != 0)
  {
    if ((sec_r000667_21_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000667_14_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000667_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000667_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000667_5_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000667_15_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000667_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000667_15_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000667_5_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000667_15_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000667_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000667_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000667_8_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000667_17_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000667_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000667_17_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000667_8_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000667_17_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000667_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000667_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000667_2_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000667_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000667_2_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000667_2_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000667_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000667_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000667_16_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000667_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000667_16_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000667_16_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000667_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000667_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000667_3_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000667_14_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000667_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000667_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000667_3_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000667_14_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000667_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000667_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000667_1_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000667_1_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000667_13_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000667_18_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000667_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000667_18_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000667_13_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000667_18_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000667_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000667_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000667_19_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000667_4_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000667_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000667_4_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000667_19_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000667_4_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000667_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000667_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000667_2_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000667_2_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000667_19_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000667_7_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000667_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000667_7_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000667_19_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000667_7_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000667_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000667_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000667_3_1 & 1) != 0)
  {
    if ((sec_r000667_19_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000667_12_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000667_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000667_12_1 + 7) & 127;
  }
  if ((sec_r000667_3_2 & 1) != 0)
  {
    if ((sec_r000667_19_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000667_12_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000667_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000667_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000667_19_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000667_19_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000667_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000667_19_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000667_19_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000667_19_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000667_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000667_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000667_17_1 & 1) != 0)
  {
    if ((sec_r000667_17_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000667_4_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000667_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000667_4_1 + 7) & 127;
  }
  if ((sec_r000667_17_2 & 1) != 0)
  {
    if ((sec_r000667_17_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000667_4_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000667_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000667_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000667_21_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000667_1_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000667_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000667_1_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000667_21_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000667_1_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000667_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000667_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000667_20_1 & 1) != 0)
  {
    if ((sec_r000667_1_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000667_13_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000667_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000667_13_1 + 7) & 127;
  }
  if ((sec_r000667_20_2 & 1) != 0)
  {
    if ((sec_r000667_1_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000667_13_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000667_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000667_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000667_11_1 & 1) != 0)
  {
    if ((sec_r000667_13_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((sec_r000667_11_2 & 1) != 0)
  {
    if ((sec_r000667_13_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000667_14_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000667_12_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000667_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000667_12_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000667_14_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000667_12_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000667_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000667_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000667_10_1 & 1) != 0)
  {
    if ((sec_r000667_0_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000667_6_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000667_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000667_6_1 + 7) & 127;
  }
  if ((sec_r000667_10_2 & 1) != 0)
  {
    if ((sec_r000667_0_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000667_6_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000667_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000667_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000667_3_1 & 1) != 0)
  {
    if ((sec_r000667_20_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000667_14_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000667_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000667_14_1 + 7) & 127;
  }
  if ((sec_r000667_3_2 & 1) != 0)
  {
    if ((sec_r000667_20_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000667_14_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000667_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000667_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000667_16_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000667_5_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000667_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000667_5_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000667_16_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000667_5_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000667_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000667_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000667_16_1 & 1) != 0)
  {
    if ((sec_r000667_5_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000667_13_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000667_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000667_13_1 + 7) & 127;
  }
  if ((sec_r000667_16_2 & 1) != 0)
  {
    if ((sec_r000667_5_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000667_13_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000667_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000667_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000667_12_1 & 1) != 0)
  {
    if ((sec_r000667_19_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000667_10_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000667_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000667_10_1 + 7) & 127;
  }
  if ((sec_r000667_12_2 & 1) != 0)
  {
    if ((sec_r000667_19_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000667_10_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000667_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000667_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000667_13_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000667_14_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000667_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000667_14_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000667_13_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000667_14_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000667_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000667_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000667_6_1 != sec_r000667_6_2);
  __CPROVER_assume(pub_r000667_3_1 == pub_r000667_3_2);
  __CPROVER_assume(sec_r000667_9_1 != sec_r000667_9_2);
  __CPROVER_assume(sec_r000667_14_1 != sec_r000667_14_2);
  __CPROVER_assume(pub_r000667_5_1 == pub_r000667_5_2);
  __CPROVER_assume(pub_r000667_9_1 == pub_r000667_9_2);
  __CPROVER_assume(pub_r000667_17_1 == pub_r000667_17_2);
  __CPROVER_assume(sec_r000667_3_1 != sec_r000667_3_2);
  __CPROVER_assume(sec_r000667_19_1 != sec_r000667_19_2);
  __CPROVER_assume(sec_r000667_17_1 != sec_r000667_17_2);
  __CPROVER_assume(sec_r000667_11_1 != sec_r000667_11_2);
  __CPROVER_assume(sec_r000667_12_1 != sec_r000667_12_2);
  __CPROVER_assume(pub_r000667_6_1 == pub_r000667_6_2);
  __CPROVER_assume(sec_r000667_2_1 != sec_r000667_2_2);
  __CPROVER_assume(pub_r000667_2_1 == pub_r000667_2_2);
  __CPROVER_assume(pub_r000667_14_1 == pub_r000667_14_2);
  __CPROVER_assume(sec_r000667_10_1 != sec_r000667_10_2);
  __CPROVER_assume(pub_r000667_18_1 == pub_r000667_18_2);
  __CPROVER_assume(sec_r000667_5_1 != sec_r000667_5_2);
  __CPROVER_assume(sec_r000667_1_1 != sec_r000667_1_2);
  __CPROVER_assume(pub_r000667_15_1 == pub_r000667_15_2);
  __CPROVER_assume(pub_r000667_1_1 == pub_r000667_1_2);
  __CPROVER_assume(sec_r000667_0_1 != sec_r000667_0_2);
  __CPROVER_assume(sec_r000667_18_1 != sec_r000667_18_2);
  __CPROVER_assume(pub_r000667_12_1 == pub_r000667_12_2);
  __CPROVER_assume(pub_r000667_7_1 == pub_r000667_7_2);
  __CPROVER_assume(sec_r000667_20_1 != sec_r000667_20_2);
  __CPROVER_assume(sec_r000667_7_1 != sec_r000667_7_2);
  __CPROVER_assume(pub_r000667_11_1 == pub_r000667_11_2);
  __CPROVER_assume(pub_r000667_19_1 == pub_r000667_19_2);
  __CPROVER_assume(sec_r000667_21_1 != sec_r000667_21_2);
  __CPROVER_assume(sec_r000667_8_1 != sec_r000667_8_2);
  __CPROVER_assume(sec_r000667_4_1 != sec_r000667_4_2);
  __CPROVER_assume(pub_r000667_10_1 == pub_r000667_10_2);
  __CPROVER_assume(sec_r000667_16_1 != sec_r000667_16_2);
  __CPROVER_assume(sec_r000667_13_1 != sec_r000667_13_2);
  __CPROVER_assume(pub_r000667_16_1 == pub_r000667_16_2);
  __CPROVER_assume(pub_r000667_8_1 == pub_r000667_8_2);
  __CPROVER_assume(sec_r000667_15_1 != sec_r000667_15_2);
  __CPROVER_assume(pub_r000667_0_1 == pub_r000667_0_2);
  __CPROVER_assume(pub_r000667_13_1 == pub_r000667_13_2);
  __CPROVER_assume(pub_r000667_4_1 == pub_r000667_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.head == st_var_0_2.head);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.port == st_var_2_2.port);
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
}


