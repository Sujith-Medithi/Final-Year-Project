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
struct SensorNode_R000788_8813_0
{
  unsigned char gain;
  unsigned char reading;
  short status;
  short threshold;
  int buffer[3];
};
struct DeviceConfig_R000788_8813_1
{
  int port;
  int parity;
  unsigned char timeout;
  int stop_bits;
  int id;
  int baud_rate;
  int buffer[3];
};
union PacketPayload_R000788_8813_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000788_8813_1
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
void fn_R000788_8813_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st_1 = {0};
  struct SensorNode_R000788_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int index_reg_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_33_1) & 63;
  aux_2 = (aux_2 + index_reg_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_24_1 = local_arr_1[aux_1 % 3];
  int coefficient_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_24_2 * 2)) & 127;
  int offset_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_56_1 > 43)
  {
    acc_1 = ((acc_1 + (offset_56_1 * 2)) + 5) & 127;
    aux_1 ^= offset_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_56_2 > 43)
  {
    acc_2 = ((acc_2 + (offset_56_2 * 2)) + 5) & 127;
    aux_2 ^= offset_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_46_1)
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

  switch (quotient_46_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_33_1 == index_reg_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_24_1 == coefficient_24_2);
  assert(offset_56_1 == offset_56_2);
  assert(quotient_46_1 == quotient_46_2);
}

int fn_R000788_8813_0(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int index_reg_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_33) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_24 = local_arr[aux % 3];
  acc = (acc + (coefficient_24 * 2)) & 127;
  int offset_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_56 > 43)
  {
    acc = ((acc + (offset_56 * 2)) + 5) & 127;
    aux ^= offset_56 & 15;
  }
  else
  {
    acc = ((acc - offset_56) + 11) & 127;
    aux += 3;
  }
  int quotient_46 = (aux + st.buffer[1]) & 3;
  switch (quotient_46)
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

void fn_R000788_8813_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st_1 = {0};
  struct SensorNode_R000788_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int scale_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_41_1) & 63;
  aux_2 = (aux_2 + scale_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_21_1 = local_arr_1[aux_1 % 3];
  int residue_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_21_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_70_1 > 40)
  {
    acc_1 = ((acc_1 + (coefficient_70_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_70_2 > 40)
  {
    acc_2 = ((acc_2 + (coefficient_70_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_41_1 == scale_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_21_1 == residue_21_2);
  assert(coefficient_70_1 == coefficient_70_2);
}

int fn_R000788_8813_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int scale_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_21 = local_arr[aux % 3];
  acc = (acc + (residue_21 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_70 > 40)
  {
    acc = ((acc + (coefficient_70 * 2)) + 5) & 127;
    aux ^= coefficient_70 & 15;
  }
  else
  {
    acc = ((acc - coefficient_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000788_8813_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st_1 = {0};
  struct DeviceConfig_R000788_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int parity_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_78_1)
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

  switch (parity_78_2)
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
  int window_45_1 = local_arr_1[aux_1 % 3];
  int window_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_45_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_27_1) & 63;
  aux_2 = (aux_2 + margin_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_78_1 == parity_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_45_1 == window_45_2);
  assert(margin_27_1 == margin_27_2);
}

int fn_R000788_8813_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int parity_78 = (aux + st.buffer[1]) & 3;
  switch (parity_78)
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
  int window_45 = local_arr[aux % 3];
  acc = (acc + (window_45 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000788_8813_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st_1 = {0};
  struct SensorNode_R000788_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int index_reg_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_14_1 > 35)
  {
    acc_1 = ((acc_1 + (index_reg_14_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_14_2 > 35)
  {
    acc_2 = ((acc_2 + (index_reg_14_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_37_1 = local_arr_1[aux_1 % 3];
  int tally_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_14_1 == index_reg_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_37_1 == tally_37_2);
}

int fn_R000788_8813_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int index_reg_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_14 > 35)
  {
    acc = ((acc + (index_reg_14 * 2)) + 5) & 127;
    aux ^= index_reg_14 & 15;
  }
  else
  {
    acc = ((acc - index_reg_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_37 = local_arr[aux % 3];
  acc = (acc + (tally_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000788_8813_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st_1 = {0};
  struct DeviceConfig_R000788_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int anchor_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_37_1)
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

  switch (anchor_37_2)
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

  int metric_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_46_1 > 29)
  {
    acc_1 = ((acc_1 + (metric_46_1 * 2)) + 5) & 127;
    aux_1 ^= metric_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_46_2 > 29)
  {
    acc_2 = ((acc_2 + (metric_46_2 * 2)) + 5) & 127;
    aux_2 ^= metric_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_24_1) & 63;
  aux_2 = (aux_2 + stride_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_37_1 == anchor_37_2);
  assert(metric_46_1 == metric_46_2);
  assert(stride_24_1 == stride_24_2);
}

int fn_R000788_8813_4(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int anchor_37 = (aux + st.buffer[1]) & 3;
  switch (anchor_37)
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

  int metric_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_46 > 29)
  {
    acc = ((acc + (metric_46 * 2)) + 5) & 127;
    aux ^= metric_46 & 15;
  }
  else
  {
    acc = ((acc - metric_46) + 11) & 127;
    aux += 3;
  }
  int stride_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000788_8813_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st_1 = {0};
  struct DeviceConfig_R000788_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_81_1 = local_arr_1[aux_1 % 3];
  int checksum_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_81_2 * 2)) & 127;
  int pivot_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_39_1)
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

  switch (pivot_39_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_81_1 == checksum_81_2);
  assert(pivot_39_1 == pivot_39_2);
}

int fn_R000788_8813_5(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int checksum_81 = local_arr[aux % 3];
  acc = (acc + (checksum_81 * 2)) & 127;
  int pivot_39 = (aux + st.buffer[1]) & 3;
  switch (pivot_39)
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

void fn_R000788_8813_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st_1 = {0};
  struct DeviceConfig_R000788_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_53_1)
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

  switch (index_reg_53_2)
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
  int damping_48_1 = local_arr_1[aux_1 % 3];
  int damping_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_53_1 == index_reg_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_48_1 == damping_48_2);
}

int fn_R000788_8813_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_53 = (aux + st.buffer[1]) & 3;
  switch (index_reg_53)
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
  int damping_48 = local_arr[aux % 3];
  acc = (acc + (damping_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000788_8813_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st_1 = {0};
  struct SensorNode_R000788_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int tally_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_60_1)
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

  switch (tally_60_2)
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

  int anchor_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_83_1 > 38)
  {
    acc_1 = ((acc_1 + (anchor_83_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_83_2 > 38)
  {
    acc_2 = ((acc_2 + (anchor_83_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_88_1) & 63;
  aux_2 = (aux_2 + delta_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_60_1 == tally_60_2);
  assert(anchor_83_1 == anchor_83_2);
  assert(delta_88_1 == delta_88_2);
}

int fn_R000788_8813_7(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int tally_60 = (aux + st.buffer[1]) & 3;
  switch (tally_60)
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

  int anchor_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_83 > 38)
  {
    acc = ((acc + (anchor_83 * 2)) + 5) & 127;
    aux ^= anchor_83 & 15;
  }
  else
  {
    acc = ((acc - anchor_83) + 11) & 127;
    aux += 3;
  }
  int delta_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000788_8813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st_1 = {0};
  struct SensorNode_R000788_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int sample_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_63_1)
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

  switch (sample_63_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_26_1 > 34)
  {
    acc_1 = ((acc_1 + (bound_26_1 * 2)) + 5) & 127;
    aux_1 ^= bound_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_26_2 > 34)
  {
    acc_2 = ((acc_2 + (bound_26_2 * 2)) + 5) & 127;
    aux_2 ^= bound_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_19_1) & 63;
  aux_2 = (aux_2 + vector_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_63_1 == sample_63_2);
  assert(bound_26_1 == bound_26_2);
  assert(vector_19_1 == vector_19_2);
}

int fn_R000788_8813_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int sample_63 = (aux + st.buffer[1]) & 3;
  switch (sample_63)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_26 > 34)
  {
    acc = ((acc + (bound_26 * 2)) + 5) & 127;
    aux ^= bound_26 & 15;
  }
  else
  {
    acc = ((acc - bound_26) + 11) & 127;
    aux += 3;
  }
  int vector_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_19) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000788_8813_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st_1 = {0};
  struct SensorNode_R000788_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_67_1 = local_arr_1[aux_1 % 3];
  int sample_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_67_2 * 2)) & 127;
  int delta_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_72_1 > 28)
  {
    acc_1 = ((acc_1 + (delta_72_1 * 2)) + 5) & 127;
    aux_1 ^= delta_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_72_2 > 28)
  {
    acc_2 = ((acc_2 + (delta_72_2 * 2)) + 5) & 127;
    aux_2 ^= delta_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_82_1) & 63;
  aux_2 = (aux_2 + anchor_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_73_1)
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

  switch (factor_73_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_67_1 == sample_67_2);
  assert(delta_72_1 == delta_72_2);
  assert(anchor_82_1 == anchor_82_2);
  assert(factor_73_1 == factor_73_2);
}

int fn_R000788_8813_9(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int sample_67 = local_arr[aux % 3];
  acc = (acc + (sample_67 * 2)) & 127;
  int delta_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_72 > 28)
  {
    acc = ((acc + (delta_72 * 2)) + 5) & 127;
    aux ^= delta_72 & 15;
  }
  else
  {
    acc = ((acc - delta_72) + 11) & 127;
    aux += 3;
  }
  int anchor_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_82) & 63;
  acc ^= aux;
  int factor_73 = (aux + st.buffer[1]) & 3;
  switch (factor_73)
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

void fn_R000788_8813_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st_1 = {0};
  struct SensorNode_R000788_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_11_1 = local_arr_1[aux_1 % 3];
  int segment_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_11_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_64_1 > 26)
  {
    acc_1 = ((acc_1 + (checksum_64_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_64_2 > 26)
  {
    acc_2 = ((acc_2 + (checksum_64_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_11_1 == segment_11_2);
  assert(checksum_64_1 == checksum_64_2);
}

int fn_R000788_8813_10(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int segment_11 = local_arr[aux % 3];
  acc = (acc + (segment_11 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_64 > 26)
  {
    acc = ((acc + (checksum_64 * 2)) + 5) & 127;
    aux ^= checksum_64 & 15;
  }
  else
  {
    acc = ((acc - checksum_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000788_8813_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st_1 = {0};
  struct DeviceConfig_R000788_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int delta_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_58_1) & 63;
  aux_2 = (aux_2 + delta_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_69_1)
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

  switch (pivot_69_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_21_1 = local_arr_1[aux_1 % 3];
  int margin_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_58_1 == delta_58_2);
  assert(pivot_69_1 == pivot_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_21_1 == margin_21_2);
}

int fn_R000788_8813_11(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int delta_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_58) & 63;
  acc ^= aux;
  int pivot_69 = (aux + st.buffer[1]) & 3;
  switch (pivot_69)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_21 = local_arr[aux % 3];
  acc = (acc + (margin_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000788_8813_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st_1 = {0};
  struct DeviceConfig_R000788_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int margin_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_53_1)
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

  switch (margin_53_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_53_1 == margin_53_2);
}

int fn_R000788_8813_12(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int margin_53 = (aux + st.buffer[1]) & 3;
  switch (margin_53)
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

void fn_R000788_8813_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st_1 = {0};
  struct SensorNode_R000788_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_61_1) & 63;
  aux_2 = (aux_2 + coefficient_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_93_1 > 48)
  {
    acc_1 = ((acc_1 + (checksum_93_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_93_2 > 48)
  {
    acc_2 = ((acc_2 + (checksum_93_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_61_1 == coefficient_61_2);
  assert(checksum_93_1 == checksum_93_2);
}

int fn_R000788_8813_13(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000788_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_61) & 63;
  acc ^= aux;
  int checksum_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_93 > 48)
  {
    acc = ((acc + (checksum_93 * 2)) + 5) & 127;
    aux ^= checksum_93 & 15;
  }
  else
  {
    acc = ((acc - checksum_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000788_8813_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st_1 = {0};
  struct DeviceConfig_R000788_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_46_1 = local_arr_1[aux_1 % 3];
  int tracker_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_46_2 * 2)) & 127;
  int residue_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_88_1 > 42)
  {
    acc_1 = ((acc_1 + (residue_88_1 * 2)) + 5) & 127;
    aux_1 ^= residue_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_88_2 > 42)
  {
    acc_2 = ((acc_2 + (residue_88_2 * 2)) + 5) & 127;
    aux_2 ^= residue_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_88_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_46_1 == tracker_46_2);
  assert(residue_88_1 == residue_88_2);
}

int fn_R000788_8813_14(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000788_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int tracker_46 = local_arr[aux % 3];
  acc = (acc + (tracker_46 * 2)) & 127;
  int residue_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_88 > 42)
  {
    acc = ((acc + (residue_88 * 2)) + 5) & 127;
    aux ^= residue_88 & 15;
  }
  else
  {
    acc = ((acc - residue_88) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000788_0_1;
  int sec_r000788_0_2;
  int sec_r000788_1_1;
  int sec_r000788_1_2;
  int sec_r000788_2_1;
  int sec_r000788_2_2;
  int sec_r000788_3_1;
  int sec_r000788_3_2;
  int sec_r000788_4_1;
  int sec_r000788_4_2;
  int sec_r000788_5_1;
  int sec_r000788_5_2;
  int sec_r000788_6_1;
  int sec_r000788_6_2;
  int sec_r000788_7_1;
  int sec_r000788_7_2;
  int sec_r000788_8_1;
  int sec_r000788_8_2;
  int sec_r000788_9_1;
  int sec_r000788_9_2;
  int sec_r000788_10_1;
  int sec_r000788_10_2;
  int sec_r000788_11_1;
  int sec_r000788_11_2;
  int sec_r000788_12_1;
  int sec_r000788_12_2;
  int sec_r000788_13_1;
  int sec_r000788_13_2;
  int sec_r000788_14_1;
  int sec_r000788_14_2;
  int sec_r000788_15_1;
  int sec_r000788_15_2;
  int sec_r000788_16_1;
  int sec_r000788_16_2;
  int sec_r000788_17_1;
  int sec_r000788_17_2;
  int sec_r000788_18_1;
  int sec_r000788_18_2;
  int sec_r000788_19_1;
  int sec_r000788_19_2;
  int pub_r000788_0_1;
  int pub_r000788_0_2;
  int pub_r000788_1_1;
  int pub_r000788_1_2;
  int pub_r000788_2_1;
  int pub_r000788_2_2;
  int pub_r000788_3_1;
  int pub_r000788_3_2;
  int pub_r000788_4_1;
  int pub_r000788_4_2;
  int pub_r000788_5_1;
  int pub_r000788_5_2;
  int pub_r000788_6_1;
  int pub_r000788_6_2;
  int pub_r000788_7_1;
  int pub_r000788_7_2;
  int pub_r000788_8_1;
  int pub_r000788_8_2;
  int pub_r000788_9_1;
  int pub_r000788_9_2;
  int pub_r000788_10_1;
  int pub_r000788_10_2;
  int pub_r000788_11_1;
  int pub_r000788_11_2;
  int pub_r000788_12_1;
  int pub_r000788_12_2;
  int pub_r000788_13_1;
  int pub_r000788_13_2;
  int pub_r000788_14_1;
  int pub_r000788_14_2;
  int pub_r000788_15_1;
  int pub_r000788_15_2;
  int pub_r000788_16_1;
  int pub_r000788_16_2;
  int pub_r000788_17_1;
  int pub_r000788_17_2;
  int pub_r000788_18_1;
  int pub_r000788_18_2;
  int pub_r000788_19_1;
  int pub_r000788_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000788_0_1 >= (-100)) && (pub_r000788_0_1 <= 100));
  __CPROVER_assume((pub_r000788_0_2 >= (-100)) && (pub_r000788_0_2 <= 100));
  __CPROVER_assume((pub_r000788_1_1 >= (-100)) && (pub_r000788_1_1 <= 100));
  __CPROVER_assume((pub_r000788_1_2 >= (-100)) && (pub_r000788_1_2 <= 100));
  __CPROVER_assume((pub_r000788_2_1 >= (-100)) && (pub_r000788_2_1 <= 100));
  __CPROVER_assume((pub_r000788_2_2 >= (-100)) && (pub_r000788_2_2 <= 100));
  __CPROVER_assume((pub_r000788_3_1 >= (-100)) && (pub_r000788_3_1 <= 100));
  __CPROVER_assume((pub_r000788_3_2 >= (-100)) && (pub_r000788_3_2 <= 100));
  __CPROVER_assume((pub_r000788_4_1 >= (-100)) && (pub_r000788_4_1 <= 100));
  __CPROVER_assume((pub_r000788_4_2 >= (-100)) && (pub_r000788_4_2 <= 100));
  __CPROVER_assume((pub_r000788_5_1 >= (-100)) && (pub_r000788_5_1 <= 100));
  __CPROVER_assume((pub_r000788_5_2 >= (-100)) && (pub_r000788_5_2 <= 100));
  __CPROVER_assume((pub_r000788_6_1 >= (-100)) && (pub_r000788_6_1 <= 100));
  __CPROVER_assume((pub_r000788_6_2 >= (-100)) && (pub_r000788_6_2 <= 100));
  __CPROVER_assume((pub_r000788_7_1 >= (-100)) && (pub_r000788_7_1 <= 100));
  __CPROVER_assume((pub_r000788_7_2 >= (-100)) && (pub_r000788_7_2 <= 100));
  __CPROVER_assume((pub_r000788_8_1 >= (-100)) && (pub_r000788_8_1 <= 100));
  __CPROVER_assume((pub_r000788_8_2 >= (-100)) && (pub_r000788_8_2 <= 100));
  __CPROVER_assume((pub_r000788_9_1 >= (-100)) && (pub_r000788_9_1 <= 100));
  __CPROVER_assume((pub_r000788_9_2 >= (-100)) && (pub_r000788_9_2 <= 100));
  __CPROVER_assume((pub_r000788_10_1 >= (-100)) && (pub_r000788_10_1 <= 100));
  __CPROVER_assume((pub_r000788_10_2 >= (-100)) && (pub_r000788_10_2 <= 100));
  __CPROVER_assume((pub_r000788_11_1 >= (-100)) && (pub_r000788_11_1 <= 100));
  __CPROVER_assume((pub_r000788_11_2 >= (-100)) && (pub_r000788_11_2 <= 100));
  __CPROVER_assume((pub_r000788_12_1 >= (-100)) && (pub_r000788_12_1 <= 100));
  __CPROVER_assume((pub_r000788_12_2 >= (-100)) && (pub_r000788_12_2 <= 100));
  __CPROVER_assume((pub_r000788_13_1 >= (-100)) && (pub_r000788_13_1 <= 100));
  __CPROVER_assume((pub_r000788_13_2 >= (-100)) && (pub_r000788_13_2 <= 100));
  __CPROVER_assume((pub_r000788_14_1 >= (-100)) && (pub_r000788_14_1 <= 100));
  __CPROVER_assume((pub_r000788_14_2 >= (-100)) && (pub_r000788_14_2 <= 100));
  __CPROVER_assume((pub_r000788_15_1 >= (-100)) && (pub_r000788_15_1 <= 100));
  __CPROVER_assume((pub_r000788_15_2 >= (-100)) && (pub_r000788_15_2 <= 100));
  __CPROVER_assume((pub_r000788_16_1 >= (-100)) && (pub_r000788_16_1 <= 100));
  __CPROVER_assume((pub_r000788_16_2 >= (-100)) && (pub_r000788_16_2 <= 100));
  __CPROVER_assume((pub_r000788_17_1 >= (-100)) && (pub_r000788_17_1 <= 100));
  __CPROVER_assume((pub_r000788_17_2 >= (-100)) && (pub_r000788_17_2 <= 100));
  __CPROVER_assume((pub_r000788_18_1 >= (-100)) && (pub_r000788_18_1 <= 100));
  __CPROVER_assume((pub_r000788_18_2 >= (-100)) && (pub_r000788_18_2 <= 100));
  __CPROVER_assume((pub_r000788_19_1 >= (-100)) && (pub_r000788_19_1 <= 100));
  __CPROVER_assume((pub_r000788_19_2 >= (-100)) && (pub_r000788_19_2 <= 100));
  __CPROVER_assume((sec_r000788_0_1 >= 0) && (sec_r000788_0_1 <= 255));
  __CPROVER_assume((sec_r000788_0_2 >= 0) && (sec_r000788_0_2 <= 255));
  __CPROVER_assume((sec_r000788_1_1 >= 0) && (sec_r000788_1_1 <= 255));
  __CPROVER_assume((sec_r000788_1_2 >= 0) && (sec_r000788_1_2 <= 255));
  __CPROVER_assume((sec_r000788_2_1 >= 0) && (sec_r000788_2_1 <= 255));
  __CPROVER_assume((sec_r000788_2_2 >= 0) && (sec_r000788_2_2 <= 255));
  __CPROVER_assume((sec_r000788_3_1 >= 0) && (sec_r000788_3_1 <= 255));
  __CPROVER_assume((sec_r000788_3_2 >= 0) && (sec_r000788_3_2 <= 255));
  __CPROVER_assume((sec_r000788_4_1 >= 0) && (sec_r000788_4_1 <= 255));
  __CPROVER_assume((sec_r000788_4_2 >= 0) && (sec_r000788_4_2 <= 255));
  __CPROVER_assume((sec_r000788_5_1 >= 0) && (sec_r000788_5_1 <= 255));
  __CPROVER_assume((sec_r000788_5_2 >= 0) && (sec_r000788_5_2 <= 255));
  __CPROVER_assume((sec_r000788_6_1 >= 0) && (sec_r000788_6_1 <= 255));
  __CPROVER_assume((sec_r000788_6_2 >= 0) && (sec_r000788_6_2 <= 255));
  __CPROVER_assume((sec_r000788_7_1 >= 0) && (sec_r000788_7_1 <= 255));
  __CPROVER_assume((sec_r000788_7_2 >= 0) && (sec_r000788_7_2 <= 255));
  __CPROVER_assume((sec_r000788_8_1 >= 0) && (sec_r000788_8_1 <= 255));
  __CPROVER_assume((sec_r000788_8_2 >= 0) && (sec_r000788_8_2 <= 255));
  __CPROVER_assume((sec_r000788_9_1 >= 0) && (sec_r000788_9_1 <= 255));
  __CPROVER_assume((sec_r000788_9_2 >= 0) && (sec_r000788_9_2 <= 255));
  __CPROVER_assume((sec_r000788_10_1 >= 0) && (sec_r000788_10_1 <= 255));
  __CPROVER_assume((sec_r000788_10_2 >= 0) && (sec_r000788_10_2 <= 255));
  __CPROVER_assume((sec_r000788_11_1 >= 0) && (sec_r000788_11_1 <= 255));
  __CPROVER_assume((sec_r000788_11_2 >= 0) && (sec_r000788_11_2 <= 255));
  __CPROVER_assume((sec_r000788_12_1 >= 0) && (sec_r000788_12_1 <= 255));
  __CPROVER_assume((sec_r000788_12_2 >= 0) && (sec_r000788_12_2 <= 255));
  __CPROVER_assume((sec_r000788_13_1 >= 0) && (sec_r000788_13_1 <= 255));
  __CPROVER_assume((sec_r000788_13_2 >= 0) && (sec_r000788_13_2 <= 255));
  __CPROVER_assume((sec_r000788_14_1 >= 0) && (sec_r000788_14_1 <= 255));
  __CPROVER_assume((sec_r000788_14_2 >= 0) && (sec_r000788_14_2 <= 255));
  __CPROVER_assume((sec_r000788_15_1 >= 0) && (sec_r000788_15_1 <= 255));
  __CPROVER_assume((sec_r000788_15_2 >= 0) && (sec_r000788_15_2 <= 255));
  __CPROVER_assume((sec_r000788_16_1 >= 0) && (sec_r000788_16_1 <= 255));
  __CPROVER_assume((sec_r000788_16_2 >= 0) && (sec_r000788_16_2 <= 255));
  __CPROVER_assume((sec_r000788_17_1 >= 0) && (sec_r000788_17_1 <= 255));
  __CPROVER_assume((sec_r000788_17_2 >= 0) && (sec_r000788_17_2 <= 255));
  __CPROVER_assume((sec_r000788_18_1 >= 0) && (sec_r000788_18_1 <= 255));
  __CPROVER_assume((sec_r000788_18_2 >= 0) && (sec_r000788_18_2 <= 255));
  __CPROVER_assume((sec_r000788_19_1 >= 0) && (sec_r000788_19_1 <= 255));
  __CPROVER_assume((sec_r000788_19_2 >= 0) && (sec_r000788_19_2 <= 255));
  struct SensorNode_R000788_8813_0 st_var_0_1 = {0};
  struct SensorNode_R000788_8813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000788_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000788_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000788_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000788_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000788_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000788_0_2 + 7) & 15;
  struct DeviceConfig_R000788_8813_1 st_var_1_1 = {0};
  struct DeviceConfig_R000788_8813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000788_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000788_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000788_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000788_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000788_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000788_0_2 + 9) & 15;
  union PacketPayload_R000788_8813_0 u_var_1;
  union PacketPayload_R000788_8813_0 u_var_2;
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
  int stage_v_2_1 = ((st_var_0_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_0_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 46)
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
  if (stage_v_2_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 46)
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
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 34)
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
  if (stage_v_4_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 34)
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
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_4_1 & 1) == step_1)
    {
      stage_v_7_1 = ((stage_v_7_1 + (step_1 * 4)) + pub_r000788_9_1) & 63;
    }
    else
    {
      stage_v_7_1 = ((stage_v_7_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((sec_r000788_4_2 & 1) == step_2)
    {
      stage_v_7_2 = ((stage_v_7_2 + (step_2 * 4)) + pub_r000788_9_2) & 63;
    }
    else
    {
      stage_v_7_2 = ((stage_v_7_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_7_1 & 1) == step_1)
    {
      stage_v_8_1 = ((stage_v_8_1 + (step_1 * 4)) + pub_r000788_8_1) & 63;
    }
    else
    {
      stage_v_8_1 = ((stage_v_8_1 + pub_r000788_2_1) + 5) & 63;
    }
    if ((stage_v_7_2 & 1) == step_2)
    {
      stage_v_8_2 = ((stage_v_8_2 + (step_2 * 4)) + pub_r000788_8_2) & 63;
    }
    else
    {
      stage_v_8_2 = ((stage_v_8_2 + pub_r000788_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_8_1 & 1) == step_1)
    {
      stage_v_9_1 = ((stage_v_9_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_9_1 = ((stage_v_9_1 + pub_r000788_12_1) + 5) & 63;
    }
    if ((stage_v_8_2 & 1) == step_2)
    {
      stage_v_9_2 = ((stage_v_9_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_9_2 = ((stage_v_9_2 + pub_r000788_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_8_1 & 1) == step_1)
    {
      stage_v_10_1 = ((stage_v_10_1 + (step_1 * 4)) + pub_r000788_9_1) & 63;
    }
    else
    {
      stage_v_10_1 = ((stage_v_10_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_8_2 & 1) == step_2)
    {
      stage_v_10_2 = ((stage_v_10_2 + (step_2 * 4)) + pub_r000788_9_2) & 63;
    }
    else
    {
      stage_v_10_2 = ((stage_v_10_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_7_1 & 1) == step_1)
    {
      stage_v_11_1 = ((stage_v_11_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_11_1 = ((stage_v_11_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_7_2 & 1) == step_2)
    {
      stage_v_11_2 = ((stage_v_11_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_11_2 = ((stage_v_11_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_7_1 & 1) == step_1)
    {
      stage_v_12_1 = ((stage_v_12_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_12_1 = ((stage_v_12_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((stage_v_7_2 & 1) == step_2)
    {
      stage_v_12_2 = ((stage_v_12_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_12_2 = ((stage_v_12_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_11_1 & 1) == step_1)
    {
      stage_v_13_1 = ((stage_v_13_1 + (step_1 * 4)) + pub_r000788_18_1) & 63;
    }
    else
    {
      stage_v_13_1 = ((stage_v_13_1 + pub_r000788_5_1) + 5) & 63;
    }
    if ((stage_v_11_2 & 1) == step_2)
    {
      stage_v_13_2 = ((stage_v_13_2 + (step_2 * 4)) + pub_r000788_18_2) & 63;
    }
    else
    {
      stage_v_13_2 = ((stage_v_13_2 + pub_r000788_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_16_1 & 1) == step_1)
    {
      stage_v_14_1 = ((stage_v_14_1 + (step_1 * 4)) + pub_r000788_6_1) & 63;
    }
    else
    {
      stage_v_14_1 = ((stage_v_14_1 + pub_r000788_11_1) + 5) & 63;
    }
    if ((sec_r000788_16_2 & 1) == step_2)
    {
      stage_v_14_2 = ((stage_v_14_2 + (step_2 * 4)) + pub_r000788_6_2) & 63;
    }
    else
    {
      stage_v_14_2 = ((stage_v_14_2 + pub_r000788_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_9_1 & 1) == step_1)
    {
      stage_v_15_1 = ((stage_v_15_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_15_1 = ((stage_v_15_1 + pub_r000788_17_1) + 5) & 63;
    }
    if ((stage_v_9_2 & 1) == step_2)
    {
      stage_v_15_2 = ((stage_v_15_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_15_2 = ((stage_v_15_2 + pub_r000788_17_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_13_1 & 1) == step_1)
    {
      stage_v_16_1 = ((stage_v_16_1 + (step_1 * 4)) + pub_r000788_6_1) & 63;
    }
    else
    {
      stage_v_16_1 = ((stage_v_16_1 + pub_r000788_16_1) + 5) & 63;
    }
    if ((sec_r000788_13_2 & 1) == step_2)
    {
      stage_v_16_2 = ((stage_v_16_2 + (step_2 * 4)) + pub_r000788_6_2) & 63;
    }
    else
    {
      stage_v_16_2 = ((stage_v_16_2 + pub_r000788_16_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_17_1 & 1) == step_1)
    {
      stage_v_17_1 = ((stage_v_17_1 + (step_1 * 4)) + pub_r000788_17_1) & 63;
    }
    else
    {
      stage_v_17_1 = ((stage_v_17_1 + pub_r000788_14_1) + 5) & 63;
    }
    if ((sec_r000788_17_2 & 1) == step_2)
    {
      stage_v_17_2 = ((stage_v_17_2 + (step_2 * 4)) + pub_r000788_17_2) & 63;
    }
    else
    {
      stage_v_17_2 = ((stage_v_17_2 + pub_r000788_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_15_1 & 1) == step_1)
    {
      stage_v_18_1 = ((stage_v_18_1 + (step_1 * 4)) + pub_r000788_6_1) & 63;
    }
    else
    {
      stage_v_18_1 = ((stage_v_18_1 + pub_r000788_11_1) + 5) & 63;
    }
    if ((stage_v_15_2 & 1) == step_2)
    {
      stage_v_18_2 = ((stage_v_18_2 + (step_2 * 4)) + pub_r000788_6_2) & 63;
    }
    else
    {
      stage_v_18_2 = ((stage_v_18_2 + pub_r000788_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_15_1 & 1) == step_1)
    {
      stage_v_19_1 = ((stage_v_19_1 + (step_1 * 4)) + pub_r000788_10_1) & 63;
    }
    else
    {
      stage_v_19_1 = ((stage_v_19_1 + pub_r000788_10_1) + 5) & 63;
    }
    if ((stage_v_15_2 & 1) == step_2)
    {
      stage_v_19_2 = ((stage_v_19_2 + (step_2 * 4)) + pub_r000788_10_2) & 63;
    }
    else
    {
      stage_v_19_2 = ((stage_v_19_2 + pub_r000788_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_17_1 & 1) == step_1)
    {
      stage_v_20_1 = ((stage_v_20_1 + (step_1 * 4)) + pub_r000788_19_1) & 63;
    }
    else
    {
      stage_v_20_1 = ((stage_v_20_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((stage_v_17_2 & 1) == step_2)
    {
      stage_v_20_2 = ((stage_v_20_2 + (step_2 * 4)) + pub_r000788_19_2) & 63;
    }
    else
    {
      stage_v_20_2 = ((stage_v_20_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_9_1 & 1) == step_1)
    {
      stage_v_21_1 = ((stage_v_21_1 + (step_1 * 4)) + pub_r000788_18_1) & 63;
    }
    else
    {
      stage_v_21_1 = ((stage_v_21_1 + pub_r000788_7_1) + 5) & 63;
    }
    if ((stage_v_9_2 & 1) == step_2)
    {
      stage_v_21_2 = ((stage_v_21_2 + (step_2 * 4)) + pub_r000788_18_2) & 63;
    }
    else
    {
      stage_v_21_2 = ((stage_v_21_2 + pub_r000788_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_16_1 & 1) == step_1)
    {
      stage_v_22_1 = ((stage_v_22_1 + (step_1 * 4)) + pub_r000788_0_1) & 63;
    }
    else
    {
      stage_v_22_1 = ((stage_v_22_1 + pub_r000788_14_1) + 5) & 63;
    }
    if ((stage_v_16_2 & 1) == step_2)
    {
      stage_v_22_2 = ((stage_v_22_2 + (step_2 * 4)) + pub_r000788_0_2) & 63;
    }
    else
    {
      stage_v_22_2 = ((stage_v_22_2 + pub_r000788_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_0_1 & 1) == step_1)
    {
      stage_v_23_1 = ((stage_v_23_1 + (step_1 * 4)) + pub_r000788_0_1) & 63;
    }
    else
    {
      stage_v_23_1 = ((stage_v_23_1 + pub_r000788_12_1) + 5) & 63;
    }
    if ((sec_r000788_0_2 & 1) == step_2)
    {
      stage_v_23_2 = ((stage_v_23_2 + (step_2 * 4)) + pub_r000788_0_2) & 63;
    }
    else
    {
      stage_v_23_2 = ((stage_v_23_2 + pub_r000788_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_1_1 & 1) == step_1)
    {
      stage_v_24_1 = ((stage_v_24_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_24_1 = ((stage_v_24_1 + pub_r000788_3_1) + 5) & 63;
    }
    if ((sec_r000788_1_2 & 1) == step_2)
    {
      stage_v_24_2 = ((stage_v_24_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_24_2 = ((stage_v_24_2 + pub_r000788_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_18_1 & 1) == step_1)
    {
      stage_v_25_1 = ((stage_v_25_1 + (step_1 * 4)) + pub_r000788_11_1) & 63;
    }
    else
    {
      stage_v_25_1 = ((stage_v_25_1 + pub_r000788_10_1) + 5) & 63;
    }
    if ((stage_v_18_2 & 1) == step_2)
    {
      stage_v_25_2 = ((stage_v_25_2 + (step_2 * 4)) + pub_r000788_11_2) & 63;
    }
    else
    {
      stage_v_25_2 = ((stage_v_25_2 + pub_r000788_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_7_1 & 1) == step_1)
    {
      stage_v_26_1 = ((stage_v_26_1 + (step_1 * 4)) + pub_r000788_13_1) & 63;
    }
    else
    {
      stage_v_26_1 = ((stage_v_26_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((stage_v_7_2 & 1) == step_2)
    {
      stage_v_26_2 = ((stage_v_26_2 + (step_2 * 4)) + pub_r000788_13_2) & 63;
    }
    else
    {
      stage_v_26_2 = ((stage_v_26_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_10_1 & 1) == step_1)
    {
      stage_v_27_1 = ((stage_v_27_1 + (step_1 * 4)) + pub_r000788_12_1) & 63;
    }
    else
    {
      stage_v_27_1 = ((stage_v_27_1 + pub_r000788_14_1) + 5) & 63;
    }
    if ((sec_r000788_10_2 & 1) == step_2)
    {
      stage_v_27_2 = ((stage_v_27_2 + (step_2 * 4)) + pub_r000788_12_2) & 63;
    }
    else
    {
      stage_v_27_2 = ((stage_v_27_2 + pub_r000788_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_7_1 & 1) == step_1)
    {
      stage_v_28_1 = ((stage_v_28_1 + (step_1 * 4)) + pub_r000788_11_1) & 63;
    }
    else
    {
      stage_v_28_1 = ((stage_v_28_1 + pub_r000788_7_1) + 5) & 63;
    }
    if ((stage_v_7_2 & 1) == step_2)
    {
      stage_v_28_2 = ((stage_v_28_2 + (step_2 * 4)) + pub_r000788_11_2) & 63;
    }
    else
    {
      stage_v_28_2 = ((stage_v_28_2 + pub_r000788_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_18_1 & 1) == step_1)
    {
      stage_v_29_1 = ((stage_v_29_1 + (step_1 * 4)) + pub_r000788_9_1) & 63;
    }
    else
    {
      stage_v_29_1 = ((stage_v_29_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((stage_v_18_2 & 1) == step_2)
    {
      stage_v_29_2 = ((stage_v_29_2 + (step_2 * 4)) + pub_r000788_9_2) & 63;
    }
    else
    {
      stage_v_29_2 = ((stage_v_29_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_6_1 & 1) == step_1)
    {
      stage_v_30_1 = ((stage_v_30_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_30_1 = ((stage_v_30_1 + pub_r000788_7_1) + 5) & 63;
    }
    if ((sec_r000788_6_2 & 1) == step_2)
    {
      stage_v_30_2 = ((stage_v_30_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_30_2 = ((stage_v_30_2 + pub_r000788_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_13_1 & 1) == step_1)
    {
      stage_v_31_1 = ((stage_v_31_1 + (step_1 * 4)) + pub_r000788_19_1) & 63;
    }
    else
    {
      stage_v_31_1 = ((stage_v_31_1 + pub_r000788_16_1) + 5) & 63;
    }
    if ((stage_v_13_2 & 1) == step_2)
    {
      stage_v_31_2 = ((stage_v_31_2 + (step_2 * 4)) + pub_r000788_19_2) & 63;
    }
    else
    {
      stage_v_31_2 = ((stage_v_31_2 + pub_r000788_16_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_25_1 & 1) == step_1)
    {
      stage_v_32_1 = ((stage_v_32_1 + (step_1 * 4)) + pub_r000788_16_1) & 63;
    }
    else
    {
      stage_v_32_1 = ((stage_v_32_1 + pub_r000788_2_1) + 5) & 63;
    }
    if ((stage_v_25_2 & 1) == step_2)
    {
      stage_v_32_2 = ((stage_v_32_2 + (step_2 * 4)) + pub_r000788_16_2) & 63;
    }
    else
    {
      stage_v_32_2 = ((stage_v_32_2 + pub_r000788_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_12_1 & 1) == step_1)
    {
      stage_v_33_1 = ((stage_v_33_1 + (step_1 * 4)) + pub_r000788_18_1) & 63;
    }
    else
    {
      stage_v_33_1 = ((stage_v_33_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((sec_r000788_12_2 & 1) == step_2)
    {
      stage_v_33_2 = ((stage_v_33_2 + (step_2 * 4)) + pub_r000788_18_2) & 63;
    }
    else
    {
      stage_v_33_2 = ((stage_v_33_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_19_1 & 1) == step_1)
    {
      stage_v_34_1 = ((stage_v_34_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_34_1 = ((stage_v_34_1 + pub_r000788_10_1) + 5) & 63;
    }
    if ((sec_r000788_19_2 & 1) == step_2)
    {
      stage_v_34_2 = ((stage_v_34_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_34_2 = ((stage_v_34_2 + pub_r000788_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_28_1 & 1) == step_1)
    {
      stage_v_35_1 = ((stage_v_35_1 + (step_1 * 4)) + pub_r000788_0_1) & 63;
    }
    else
    {
      stage_v_35_1 = ((stage_v_35_1 + pub_r000788_1_1) + 5) & 63;
    }
    if ((stage_v_28_2 & 1) == step_2)
    {
      stage_v_35_2 = ((stage_v_35_2 + (step_2 * 4)) + pub_r000788_0_2) & 63;
    }
    else
    {
      stage_v_35_2 = ((stage_v_35_2 + pub_r000788_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_32_1 & 1) == step_1)
    {
      stage_v_36_1 = ((stage_v_36_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_36_1 = ((stage_v_36_1 + pub_r000788_13_1) + 5) & 63;
    }
    if ((stage_v_32_2 & 1) == step_2)
    {
      stage_v_36_2 = ((stage_v_36_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_36_2 = ((stage_v_36_2 + pub_r000788_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_27_1 & 1) == step_1)
    {
      stage_v_37_1 = ((stage_v_37_1 + (step_1 * 4)) + pub_r000788_19_1) & 63;
    }
    else
    {
      stage_v_37_1 = ((stage_v_37_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((stage_v_27_2 & 1) == step_2)
    {
      stage_v_37_2 = ((stage_v_37_2 + (step_2 * 4)) + pub_r000788_19_2) & 63;
    }
    else
    {
      stage_v_37_2 = ((stage_v_37_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_13_1 & 1) == step_1)
    {
      stage_v_38_1 = ((stage_v_38_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_38_1 = ((stage_v_38_1 + pub_r000788_3_1) + 5) & 63;
    }
    if ((sec_r000788_13_2 & 1) == step_2)
    {
      stage_v_38_2 = ((stage_v_38_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_38_2 = ((stage_v_38_2 + pub_r000788_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_28_1 & 1) == step_1)
    {
      stage_v_39_1 = ((stage_v_39_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_39_1 = ((stage_v_39_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_28_2 & 1) == step_2)
    {
      stage_v_39_2 = ((stage_v_39_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_39_2 = ((stage_v_39_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_13_1 & 1) == step_1)
    {
      stage_v_40_1 = ((stage_v_40_1 + (step_1 * 4)) + pub_r000788_9_1) & 63;
    }
    else
    {
      stage_v_40_1 = ((stage_v_40_1 + pub_r000788_7_1) + 5) & 63;
    }
    if ((sec_r000788_13_2 & 1) == step_2)
    {
      stage_v_40_2 = ((stage_v_40_2 + (step_2 * 4)) + pub_r000788_9_2) & 63;
    }
    else
    {
      stage_v_40_2 = ((stage_v_40_2 + pub_r000788_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_31_1 & 1) == step_1)
    {
      stage_v_41_1 = ((stage_v_41_1 + (step_1 * 4)) + pub_r000788_19_1) & 63;
    }
    else
    {
      stage_v_41_1 = ((stage_v_41_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_31_2 & 1) == step_2)
    {
      stage_v_41_2 = ((stage_v_41_2 + (step_2 * 4)) + pub_r000788_19_2) & 63;
    }
    else
    {
      stage_v_41_2 = ((stage_v_41_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_16_1 & 1) == step_1)
    {
      stage_v_42_1 = ((stage_v_42_1 + (step_1 * 4)) + pub_r000788_2_1) & 63;
    }
    else
    {
      stage_v_42_1 = ((stage_v_42_1 + pub_r000788_5_1) + 5) & 63;
    }
    if ((sec_r000788_16_2 & 1) == step_2)
    {
      stage_v_42_2 = ((stage_v_42_2 + (step_2 * 4)) + pub_r000788_2_2) & 63;
    }
    else
    {
      stage_v_42_2 = ((stage_v_42_2 + pub_r000788_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_32_1 & 1) == step_1)
    {
      stage_v_43_1 = ((stage_v_43_1 + (step_1 * 4)) + pub_r000788_10_1) & 63;
    }
    else
    {
      stage_v_43_1 = ((stage_v_43_1 + pub_r000788_17_1) + 5) & 63;
    }
    if ((stage_v_32_2 & 1) == step_2)
    {
      stage_v_43_2 = ((stage_v_43_2 + (step_2 * 4)) + pub_r000788_10_2) & 63;
    }
    else
    {
      stage_v_43_2 = ((stage_v_43_2 + pub_r000788_17_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_14_1 & 1) == step_1)
    {
      stage_v_44_1 = ((stage_v_44_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_44_1 = ((stage_v_44_1 + pub_r000788_2_1) + 5) & 63;
    }
    if ((stage_v_14_2 & 1) == step_2)
    {
      stage_v_44_2 = ((stage_v_44_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_44_2 = ((stage_v_44_2 + pub_r000788_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_11_1 & 1) == step_1)
    {
      stage_v_45_1 = ((stage_v_45_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_45_1 = ((stage_v_45_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((stage_v_11_2 & 1) == step_2)
    {
      stage_v_45_2 = ((stage_v_45_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_45_2 = ((stage_v_45_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_46_1 = ((stage_v_46_1 + (step_1 * 4)) + pub_r000788_17_1) & 63;
    }
    else
    {
      stage_v_46_1 = ((stage_v_46_1 + pub_r000788_1_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_46_2 = ((stage_v_46_2 + (step_2 * 4)) + pub_r000788_17_2) & 63;
    }
    else
    {
      stage_v_46_2 = ((stage_v_46_2 + pub_r000788_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_47_1 = ((stage_v_47_1 + (step_1 * 4)) + pub_r000788_18_1) & 63;
    }
    else
    {
      stage_v_47_1 = ((stage_v_47_1 + pub_r000788_1_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_47_2 = ((stage_v_47_2 + (step_2 * 4)) + pub_r000788_18_2) & 63;
    }
    else
    {
      stage_v_47_2 = ((stage_v_47_2 + pub_r000788_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_7_1 & 1) == step_1)
    {
      stage_v_48_1 = ((stage_v_48_1 + (step_1 * 4)) + pub_r000788_13_1) & 63;
    }
    else
    {
      stage_v_48_1 = ((stage_v_48_1 + pub_r000788_5_1) + 5) & 63;
    }
    if ((stage_v_7_2 & 1) == step_2)
    {
      stage_v_48_2 = ((stage_v_48_2 + (step_2 * 4)) + pub_r000788_13_2) & 63;
    }
    else
    {
      stage_v_48_2 = ((stage_v_48_2 + pub_r000788_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_18_1 & 1) == step_1)
    {
      stage_v_49_1 = ((stage_v_49_1 + (step_1 * 4)) + pub_r000788_19_1) & 63;
    }
    else
    {
      stage_v_49_1 = ((stage_v_49_1 + pub_r000788_16_1) + 5) & 63;
    }
    if ((stage_v_18_2 & 1) == step_2)
    {
      stage_v_49_2 = ((stage_v_49_2 + (step_2 * 4)) + pub_r000788_19_2) & 63;
    }
    else
    {
      stage_v_49_2 = ((stage_v_49_2 + pub_r000788_16_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_0_1 & 1) == step_1)
    {
      stage_v_50_1 = ((stage_v_50_1 + (step_1 * 4)) + pub_r000788_9_1) & 63;
    }
    else
    {
      stage_v_50_1 = ((stage_v_50_1 + pub_r000788_11_1) + 5) & 63;
    }
    if ((sec_r000788_0_2 & 1) == step_2)
    {
      stage_v_50_2 = ((stage_v_50_2 + (step_2 * 4)) + pub_r000788_9_2) & 63;
    }
    else
    {
      stage_v_50_2 = ((stage_v_50_2 + pub_r000788_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_20_1 & 1) == step_1)
    {
      stage_v_51_1 = ((stage_v_51_1 + (step_1 * 4)) + pub_r000788_15_1) & 63;
    }
    else
    {
      stage_v_51_1 = ((stage_v_51_1 + pub_r000788_3_1) + 5) & 63;
    }
    if ((stage_v_20_2 & 1) == step_2)
    {
      stage_v_51_2 = ((stage_v_51_2 + (step_2 * 4)) + pub_r000788_15_2) & 63;
    }
    else
    {
      stage_v_51_2 = ((stage_v_51_2 + pub_r000788_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_29_1 & 1) == step_1)
    {
      stage_v_52_1 = ((stage_v_52_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_52_1 = ((stage_v_52_1 + pub_r000788_6_1) + 5) & 63;
    }
    if ((stage_v_29_2 & 1) == step_2)
    {
      stage_v_52_2 = ((stage_v_52_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_52_2 = ((stage_v_52_2 + pub_r000788_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_26_1 & 1) == step_1)
    {
      stage_v_53_1 = ((stage_v_53_1 + (step_1 * 4)) + pub_r000788_0_1) & 63;
    }
    else
    {
      stage_v_53_1 = ((stage_v_53_1 + pub_r000788_14_1) + 5) & 63;
    }
    if ((stage_v_26_2 & 1) == step_2)
    {
      stage_v_53_2 = ((stage_v_53_2 + (step_2 * 4)) + pub_r000788_0_2) & 63;
    }
    else
    {
      stage_v_53_2 = ((stage_v_53_2 + pub_r000788_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_48_1 & 1) == step_1)
    {
      stage_v_54_1 = ((stage_v_54_1 + (step_1 * 4)) + pub_r000788_14_1) & 63;
    }
    else
    {
      stage_v_54_1 = ((stage_v_54_1 + pub_r000788_1_1) + 5) & 63;
    }
    if ((stage_v_48_2 & 1) == step_2)
    {
      stage_v_54_2 = ((stage_v_54_2 + (step_2 * 4)) + pub_r000788_14_2) & 63;
    }
    else
    {
      stage_v_54_2 = ((stage_v_54_2 + pub_r000788_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_23_1 & 1) == step_1)
    {
      stage_v_55_1 = ((stage_v_55_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_55_1 = ((stage_v_55_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_23_2 & 1) == step_2)
    {
      stage_v_55_2 = ((stage_v_55_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_55_2 = ((stage_v_55_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_11_1 & 1) == step_1)
    {
      stage_v_56_1 = ((stage_v_56_1 + (step_1 * 4)) + pub_r000788_10_1) & 63;
    }
    else
    {
      stage_v_56_1 = ((stage_v_56_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((sec_r000788_11_2 & 1) == step_2)
    {
      stage_v_56_2 = ((stage_v_56_2 + (step_2 * 4)) + pub_r000788_10_2) & 63;
    }
    else
    {
      stage_v_56_2 = ((stage_v_56_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_15_1 & 1) == step_1)
    {
      stage_v_57_1 = ((stage_v_57_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_57_1 = ((stage_v_57_1 + pub_r000788_13_1) + 5) & 63;
    }
    if ((stage_v_15_2 & 1) == step_2)
    {
      stage_v_57_2 = ((stage_v_57_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_57_2 = ((stage_v_57_2 + pub_r000788_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_18_1 & 1) == step_1)
    {
      stage_v_58_1 = ((stage_v_58_1 + (step_1 * 4)) + pub_r000788_8_1) & 63;
    }
    else
    {
      stage_v_58_1 = ((stage_v_58_1 + pub_r000788_6_1) + 5) & 63;
    }
    if ((sec_r000788_18_2 & 1) == step_2)
    {
      stage_v_58_2 = ((stage_v_58_2 + (step_2 * 4)) + pub_r000788_8_2) & 63;
    }
    else
    {
      stage_v_58_2 = ((stage_v_58_2 + pub_r000788_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_15_1 & 1) == step_1)
    {
      stage_v_59_1 = ((stage_v_59_1 + (step_1 * 4)) + pub_r000788_5_1) & 63;
    }
    else
    {
      stage_v_59_1 = ((stage_v_59_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((sec_r000788_15_2 & 1) == step_2)
    {
      stage_v_59_2 = ((stage_v_59_2 + (step_2 * 4)) + pub_r000788_5_2) & 63;
    }
    else
    {
      stage_v_59_2 = ((stage_v_59_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_6_1 & 1) == step_1)
    {
      stage_v_60_1 = ((stage_v_60_1 + (step_1 * 4)) + pub_r000788_10_1) & 63;
    }
    else
    {
      stage_v_60_1 = ((stage_v_60_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((sec_r000788_6_2 & 1) == step_2)
    {
      stage_v_60_2 = ((stage_v_60_2 + (step_2 * 4)) + pub_r000788_10_2) & 63;
    }
    else
    {
      stage_v_60_2 = ((stage_v_60_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_0_1 & 1) == step_1)
    {
      stage_v_61_1 = ((stage_v_61_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_61_1 = ((stage_v_61_1 + pub_r000788_1_1) + 5) & 63;
    }
    if ((sec_r000788_0_2 & 1) == step_2)
    {
      stage_v_61_2 = ((stage_v_61_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_61_2 = ((stage_v_61_2 + pub_r000788_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_15_1 & 1) == step_1)
    {
      stage_v_62_1 = ((stage_v_62_1 + (step_1 * 4)) + pub_r000788_5_1) & 63;
    }
    else
    {
      stage_v_62_1 = ((stage_v_62_1 + pub_r000788_14_1) + 5) & 63;
    }
    if ((sec_r000788_15_2 & 1) == step_2)
    {
      stage_v_62_2 = ((stage_v_62_2 + (step_2 * 4)) + pub_r000788_5_2) & 63;
    }
    else
    {
      stage_v_62_2 = ((stage_v_62_2 + pub_r000788_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_18_1 & 1) == step_1)
    {
      stage_v_63_1 = ((stage_v_63_1 + (step_1 * 4)) + pub_r000788_18_1) & 63;
    }
    else
    {
      stage_v_63_1 = ((stage_v_63_1 + pub_r000788_7_1) + 5) & 63;
    }
    if ((stage_v_18_2 & 1) == step_2)
    {
      stage_v_63_2 = ((stage_v_63_2 + (step_2 * 4)) + pub_r000788_18_2) & 63;
    }
    else
    {
      stage_v_63_2 = ((stage_v_63_2 + pub_r000788_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_12_1 & 1) == step_1)
    {
      stage_v_64_1 = ((stage_v_64_1 + (step_1 * 4)) + pub_r000788_1_1) & 63;
    }
    else
    {
      stage_v_64_1 = ((stage_v_64_1 + pub_r000788_2_1) + 5) & 63;
    }
    if ((sec_r000788_12_2 & 1) == step_2)
    {
      stage_v_64_2 = ((stage_v_64_2 + (step_2 * 4)) + pub_r000788_1_2) & 63;
    }
    else
    {
      stage_v_64_2 = ((stage_v_64_2 + pub_r000788_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_22_1 & 1) == step_1)
    {
      stage_v_65_1 = ((stage_v_65_1 + (step_1 * 4)) + pub_r000788_2_1) & 63;
    }
    else
    {
      stage_v_65_1 = ((stage_v_65_1 + pub_r000788_4_1) + 5) & 63;
    }
    if ((stage_v_22_2 & 1) == step_2)
    {
      stage_v_65_2 = ((stage_v_65_2 + (step_2 * 4)) + pub_r000788_2_2) & 63;
    }
    else
    {
      stage_v_65_2 = ((stage_v_65_2 + pub_r000788_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_66_1 = ((stage_v_66_1 + (step_1 * 4)) + pub_r000788_2_1) & 63;
    }
    else
    {
      stage_v_66_1 = ((stage_v_66_1 + pub_r000788_7_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_66_2 = ((stage_v_66_2 + (step_2 * 4)) + pub_r000788_2_2) & 63;
    }
    else
    {
      stage_v_66_2 = ((stage_v_66_2 + pub_r000788_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_5_1 & 1) == step_1)
    {
      stage_v_67_1 = ((stage_v_67_1 + (step_1 * 4)) + pub_r000788_16_1) & 63;
    }
    else
    {
      stage_v_67_1 = ((stage_v_67_1 + pub_r000788_5_1) + 5) & 63;
    }
    if ((sec_r000788_5_2 & 1) == step_2)
    {
      stage_v_67_2 = ((stage_v_67_2 + (step_2 * 4)) + pub_r000788_16_2) & 63;
    }
    else
    {
      stage_v_67_2 = ((stage_v_67_2 + pub_r000788_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_4_1 & 1) == step_1)
    {
      stage_v_68_1 = ((stage_v_68_1 + (step_1 * 4)) + pub_r000788_19_1) & 63;
    }
    else
    {
      stage_v_68_1 = ((stage_v_68_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((sec_r000788_4_2 & 1) == step_2)
    {
      stage_v_68_2 = ((stage_v_68_2 + (step_2 * 4)) + pub_r000788_19_2) & 63;
    }
    else
    {
      stage_v_68_2 = ((stage_v_68_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_12_1 & 1) == step_1)
    {
      stage_v_69_1 = ((stage_v_69_1 + (step_1 * 4)) + pub_r000788_11_1) & 63;
    }
    else
    {
      stage_v_69_1 = ((stage_v_69_1 + pub_r000788_1_1) + 5) & 63;
    }
    if ((stage_v_12_2 & 1) == step_2)
    {
      stage_v_69_2 = ((stage_v_69_2 + (step_2 * 4)) + pub_r000788_11_2) & 63;
    }
    else
    {
      stage_v_69_2 = ((stage_v_69_2 + pub_r000788_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_70_1 = ((stage_v_70_1 + (step_1 * 4)) + pub_r000788_6_1) & 63;
    }
    else
    {
      stage_v_70_1 = ((stage_v_70_1 + pub_r000788_15_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_70_2 = ((stage_v_70_2 + (step_2 * 4)) + pub_r000788_6_2) & 63;
    }
    else
    {
      stage_v_70_2 = ((stage_v_70_2 + pub_r000788_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_56_1 & 1) == step_1)
    {
      stage_v_71_1 = ((stage_v_71_1 + (step_1 * 4)) + pub_r000788_11_1) & 63;
    }
    else
    {
      stage_v_71_1 = ((stage_v_71_1 + pub_r000788_17_1) + 5) & 63;
    }
    if ((stage_v_56_2 & 1) == step_2)
    {
      stage_v_71_2 = ((stage_v_71_2 + (step_2 * 4)) + pub_r000788_11_2) & 63;
    }
    else
    {
      stage_v_71_2 = ((stage_v_71_2 + pub_r000788_17_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_9_1 & 1) == step_1)
    {
      stage_v_72_1 = ((stage_v_72_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_72_1 = ((stage_v_72_1 + pub_r000788_2_1) + 5) & 63;
    }
    if ((stage_v_9_2 & 1) == step_2)
    {
      stage_v_72_2 = ((stage_v_72_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_72_2 = ((stage_v_72_2 + pub_r000788_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_11_1 & 1) == step_1)
    {
      stage_v_73_1 = ((stage_v_73_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_73_1 = ((stage_v_73_1 + pub_r000788_7_1) + 5) & 63;
    }
    if ((stage_v_11_2 & 1) == step_2)
    {
      stage_v_73_2 = ((stage_v_73_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_73_2 = ((stage_v_73_2 + pub_r000788_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_2_1 & 1) == step_1)
    {
      stage_v_74_1 = ((stage_v_74_1 + (step_1 * 4)) + pub_r000788_14_1) & 63;
    }
    else
    {
      stage_v_74_1 = ((stage_v_74_1 + pub_r000788_6_1) + 5) & 63;
    }
    if ((sec_r000788_2_2 & 1) == step_2)
    {
      stage_v_74_2 = ((stage_v_74_2 + (step_2 * 4)) + pub_r000788_14_2) & 63;
    }
    else
    {
      stage_v_74_2 = ((stage_v_74_2 + pub_r000788_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_40_1 & 1) == step_1)
    {
      stage_v_75_1 = ((stage_v_75_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_75_1 = ((stage_v_75_1 + pub_r000788_0_1) + 5) & 63;
    }
    if ((stage_v_40_2 & 1) == step_2)
    {
      stage_v_75_2 = ((stage_v_75_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_75_2 = ((stage_v_75_2 + pub_r000788_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_47_1 & 1) == step_1)
    {
      stage_v_76_1 = ((stage_v_76_1 + (step_1 * 4)) + pub_r000788_8_1) & 63;
    }
    else
    {
      stage_v_76_1 = ((stage_v_76_1 + pub_r000788_1_1) + 5) & 63;
    }
    if ((stage_v_47_2 & 1) == step_2)
    {
      stage_v_76_2 = ((stage_v_76_2 + (step_2 * 4)) + pub_r000788_8_2) & 63;
    }
    else
    {
      stage_v_76_2 = ((stage_v_76_2 + pub_r000788_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_34_1 & 1) == step_1)
    {
      stage_v_77_1 = ((stage_v_77_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_77_1 = ((stage_v_77_1 + pub_r000788_12_1) + 5) & 63;
    }
    if ((stage_v_34_2 & 1) == step_2)
    {
      stage_v_77_2 = ((stage_v_77_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_77_2 = ((stage_v_77_2 + pub_r000788_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_16_1 & 1) == step_1)
    {
      stage_v_78_1 = ((stage_v_78_1 + (step_1 * 4)) + pub_r000788_16_1) & 63;
    }
    else
    {
      stage_v_78_1 = ((stage_v_78_1 + pub_r000788_9_1) + 5) & 63;
    }
    if ((sec_r000788_16_2 & 1) == step_2)
    {
      stage_v_78_2 = ((stage_v_78_2 + (step_2 * 4)) + pub_r000788_16_2) & 63;
    }
    else
    {
      stage_v_78_2 = ((stage_v_78_2 + pub_r000788_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_8_1 & 1) == step_1)
    {
      stage_v_79_1 = ((stage_v_79_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_79_1 = ((stage_v_79_1 + pub_r000788_9_1) + 5) & 63;
    }
    if ((sec_r000788_8_2 & 1) == step_2)
    {
      stage_v_79_2 = ((stage_v_79_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_79_2 = ((stage_v_79_2 + pub_r000788_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_55_1 & 1) == step_1)
    {
      stage_v_80_1 = ((stage_v_80_1 + (step_1 * 4)) + pub_r000788_14_1) & 63;
    }
    else
    {
      stage_v_80_1 = ((stage_v_80_1 + pub_r000788_10_1) + 5) & 63;
    }
    if ((stage_v_55_2 & 1) == step_2)
    {
      stage_v_80_2 = ((stage_v_80_2 + (step_2 * 4)) + pub_r000788_14_2) & 63;
    }
    else
    {
      stage_v_80_2 = ((stage_v_80_2 + pub_r000788_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_19_1 & 1) == step_1)
    {
      stage_v_81_1 = ((stage_v_81_1 + (step_1 * 4)) + pub_r000788_10_1) & 63;
    }
    else
    {
      stage_v_81_1 = ((stage_v_81_1 + pub_r000788_2_1) + 5) & 63;
    }
    if ((sec_r000788_19_2 & 1) == step_2)
    {
      stage_v_81_2 = ((stage_v_81_2 + (step_2 * 4)) + pub_r000788_10_2) & 63;
    }
    else
    {
      stage_v_81_2 = ((stage_v_81_2 + pub_r000788_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_37_1 & 1) == step_1)
    {
      stage_v_82_1 = ((stage_v_82_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_82_1 = ((stage_v_82_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((stage_v_37_2 & 1) == step_2)
    {
      stage_v_82_2 = ((stage_v_82_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_82_2 = ((stage_v_82_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_31_1 & 1) == step_1)
    {
      stage_v_83_1 = ((stage_v_83_1 + (step_1 * 4)) + pub_r000788_18_1) & 63;
    }
    else
    {
      stage_v_83_1 = ((stage_v_83_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((stage_v_31_2 & 1) == step_2)
    {
      stage_v_83_2 = ((stage_v_83_2 + (step_2 * 4)) + pub_r000788_18_2) & 63;
    }
    else
    {
      stage_v_83_2 = ((stage_v_83_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_16_1 & 1) == step_1)
    {
      stage_v_84_1 = ((stage_v_84_1 + (step_1 * 4)) + pub_r000788_6_1) & 63;
    }
    else
    {
      stage_v_84_1 = ((stage_v_84_1 + pub_r000788_3_1) + 5) & 63;
    }
    if ((sec_r000788_16_2 & 1) == step_2)
    {
      stage_v_84_2 = ((stage_v_84_2 + (step_2 * 4)) + pub_r000788_6_2) & 63;
    }
    else
    {
      stage_v_84_2 = ((stage_v_84_2 + pub_r000788_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_84_1 & 1) == step_1)
    {
      stage_v_85_1 = ((stage_v_85_1 + (step_1 * 4)) + pub_r000788_16_1) & 63;
    }
    else
    {
      stage_v_85_1 = ((stage_v_85_1 + pub_r000788_17_1) + 5) & 63;
    }
    if ((stage_v_84_2 & 1) == step_2)
    {
      stage_v_85_2 = ((stage_v_85_2 + (step_2 * 4)) + pub_r000788_16_2) & 63;
    }
    else
    {
      stage_v_85_2 = ((stage_v_85_2 + pub_r000788_17_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_14_1 & 1) == step_1)
    {
      stage_v_86_1 = ((stage_v_86_1 + (step_1 * 4)) + pub_r000788_15_1) & 63;
    }
    else
    {
      stage_v_86_1 = ((stage_v_86_1 + pub_r000788_3_1) + 5) & 63;
    }
    if ((sec_r000788_14_2 & 1) == step_2)
    {
      stage_v_86_2 = ((stage_v_86_2 + (step_2 * 4)) + pub_r000788_15_2) & 63;
    }
    else
    {
      stage_v_86_2 = ((stage_v_86_2 + pub_r000788_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_6_1 & 1) == step_1)
    {
      stage_v_87_1 = ((stage_v_87_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_87_1 = ((stage_v_87_1 + pub_r000788_13_1) + 5) & 63;
    }
    if ((sec_r000788_6_2 & 1) == step_2)
    {
      stage_v_87_2 = ((stage_v_87_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_87_2 = ((stage_v_87_2 + pub_r000788_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_19_1 & 1) == step_1)
    {
      stage_v_88_1 = ((stage_v_88_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_88_1 = ((stage_v_88_1 + pub_r000788_1_1) + 5) & 63;
    }
    if ((stage_v_19_2 & 1) == step_2)
    {
      stage_v_88_2 = ((stage_v_88_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_88_2 = ((stage_v_88_2 + pub_r000788_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_48_1 & 1) == step_1)
    {
      stage_v_89_1 = ((stage_v_89_1 + (step_1 * 4)) + pub_r000788_0_1) & 63;
    }
    else
    {
      stage_v_89_1 = ((stage_v_89_1 + pub_r000788_4_1) + 5) & 63;
    }
    if ((stage_v_48_2 & 1) == step_2)
    {
      stage_v_89_2 = ((stage_v_89_2 + (step_2 * 4)) + pub_r000788_0_2) & 63;
    }
    else
    {
      stage_v_89_2 = ((stage_v_89_2 + pub_r000788_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_28_1 & 1) == step_1)
    {
      stage_v_90_1 = ((stage_v_90_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_90_1 = ((stage_v_90_1 + pub_r000788_17_1) + 5) & 63;
    }
    if ((stage_v_28_2 & 1) == step_2)
    {
      stage_v_90_2 = ((stage_v_90_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_90_2 = ((stage_v_90_2 + pub_r000788_17_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_22_1 & 1) == step_1)
    {
      stage_v_91_1 = ((stage_v_91_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_91_1 = ((stage_v_91_1 + pub_r000788_4_1) + 5) & 63;
    }
    if ((stage_v_22_2 & 1) == step_2)
    {
      stage_v_91_2 = ((stage_v_91_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_91_2 = ((stage_v_91_2 + pub_r000788_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_80_1 & 1) == step_1)
    {
      stage_v_92_1 = ((stage_v_92_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_92_1 = ((stage_v_92_1 + pub_r000788_3_1) + 5) & 63;
    }
    if ((stage_v_80_2 & 1) == step_2)
    {
      stage_v_92_2 = ((stage_v_92_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_92_2 = ((stage_v_92_2 + pub_r000788_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_15_1 & 1) == step_1)
    {
      stage_v_93_1 = ((stage_v_93_1 + (step_1 * 4)) + pub_r000788_5_1) & 63;
    }
    else
    {
      stage_v_93_1 = ((stage_v_93_1 + pub_r000788_14_1) + 5) & 63;
    }
    if ((sec_r000788_15_2 & 1) == step_2)
    {
      stage_v_93_2 = ((stage_v_93_2 + (step_2 * 4)) + pub_r000788_5_2) & 63;
    }
    else
    {
      stage_v_93_2 = ((stage_v_93_2 + pub_r000788_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_64_1 & 1) == step_1)
    {
      stage_v_94_1 = ((stage_v_94_1 + (step_1 * 4)) + pub_r000788_19_1) & 63;
    }
    else
    {
      stage_v_94_1 = ((stage_v_94_1 + pub_r000788_10_1) + 5) & 63;
    }
    if ((stage_v_64_2 & 1) == step_2)
    {
      stage_v_94_2 = ((stage_v_94_2 + (step_2 * 4)) + pub_r000788_19_2) & 63;
    }
    else
    {
      stage_v_94_2 = ((stage_v_94_2 + pub_r000788_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_8_1 & 1) == step_1)
    {
      stage_v_95_1 = ((stage_v_95_1 + (step_1 * 4)) + pub_r000788_18_1) & 63;
    }
    else
    {
      stage_v_95_1 = ((stage_v_95_1 + pub_r000788_3_1) + 5) & 63;
    }
    if ((sec_r000788_8_2 & 1) == step_2)
    {
      stage_v_95_2 = ((stage_v_95_2 + (step_2 * 4)) + pub_r000788_18_2) & 63;
    }
    else
    {
      stage_v_95_2 = ((stage_v_95_2 + pub_r000788_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_92_1 & 1) == step_1)
    {
      stage_v_96_1 = ((stage_v_96_1 + (step_1 * 4)) + pub_r000788_13_1) & 63;
    }
    else
    {
      stage_v_96_1 = ((stage_v_96_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_92_2 & 1) == step_2)
    {
      stage_v_96_2 = ((stage_v_96_2 + (step_2 * 4)) + pub_r000788_13_2) & 63;
    }
    else
    {
      stage_v_96_2 = ((stage_v_96_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_11_1 & 1) == step_1)
    {
      stage_v_97_1 = ((stage_v_97_1 + (step_1 * 4)) + pub_r000788_14_1) & 63;
    }
    else
    {
      stage_v_97_1 = ((stage_v_97_1 + pub_r000788_10_1) + 5) & 63;
    }
    if ((sec_r000788_11_2 & 1) == step_2)
    {
      stage_v_97_2 = ((stage_v_97_2 + (step_2 * 4)) + pub_r000788_14_2) & 63;
    }
    else
    {
      stage_v_97_2 = ((stage_v_97_2 + pub_r000788_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_31_1 & 1) == step_1)
    {
      stage_v_98_1 = ((stage_v_98_1 + (step_1 * 4)) + pub_r000788_15_1) & 63;
    }
    else
    {
      stage_v_98_1 = ((stage_v_98_1 + pub_r000788_7_1) + 5) & 63;
    }
    if ((stage_v_31_2 & 1) == step_2)
    {
      stage_v_98_2 = ((stage_v_98_2 + (step_2 * 4)) + pub_r000788_15_2) & 63;
    }
    else
    {
      stage_v_98_2 = ((stage_v_98_2 + pub_r000788_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_95_1 & 1) == step_1)
    {
      stage_v_99_1 = ((stage_v_99_1 + (step_1 * 4)) + pub_r000788_12_1) & 63;
    }
    else
    {
      stage_v_99_1 = ((stage_v_99_1 + pub_r000788_6_1) + 5) & 63;
    }
    if ((stage_v_95_2 & 1) == step_2)
    {
      stage_v_99_2 = ((stage_v_99_2 + (step_2 * 4)) + pub_r000788_12_2) & 63;
    }
    else
    {
      stage_v_99_2 = ((stage_v_99_2 + pub_r000788_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_9_1 & 1) == step_1)
    {
      stage_v_100_1 = ((stage_v_100_1 + (step_1 * 4)) + pub_r000788_2_1) & 63;
    }
    else
    {
      stage_v_100_1 = ((stage_v_100_1 + pub_r000788_16_1) + 5) & 63;
    }
    if ((sec_r000788_9_2 & 1) == step_2)
    {
      stage_v_100_2 = ((stage_v_100_2 + (step_2 * 4)) + pub_r000788_2_2) & 63;
    }
    else
    {
      stage_v_100_2 = ((stage_v_100_2 + pub_r000788_16_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_17_1 & 1) == step_1)
    {
      stage_v_101_1 = ((stage_v_101_1 + (step_1 * 4)) + pub_r000788_16_1) & 63;
    }
    else
    {
      stage_v_101_1 = ((stage_v_101_1 + pub_r000788_15_1) + 5) & 63;
    }
    if ((sec_r000788_17_2 & 1) == step_2)
    {
      stage_v_101_2 = ((stage_v_101_2 + (step_2 * 4)) + pub_r000788_16_2) & 63;
    }
    else
    {
      stage_v_101_2 = ((stage_v_101_2 + pub_r000788_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_16_1 & 1) == step_1)
    {
      stage_v_102_1 = ((stage_v_102_1 + (step_1 * 4)) + pub_r000788_13_1) & 63;
    }
    else
    {
      stage_v_102_1 = ((stage_v_102_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((sec_r000788_16_2 & 1) == step_2)
    {
      stage_v_102_2 = ((stage_v_102_2 + (step_2 * 4)) + pub_r000788_13_2) & 63;
    }
    else
    {
      stage_v_102_2 = ((stage_v_102_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_30_1 & 1) == step_1)
    {
      stage_v_103_1 = ((stage_v_103_1 + (step_1 * 4)) + pub_r000788_1_1) & 63;
    }
    else
    {
      stage_v_103_1 = ((stage_v_103_1 + pub_r000788_4_1) + 5) & 63;
    }
    if ((stage_v_30_2 & 1) == step_2)
    {
      stage_v_103_2 = ((stage_v_103_2 + (step_2 * 4)) + pub_r000788_1_2) & 63;
    }
    else
    {
      stage_v_103_2 = ((stage_v_103_2 + pub_r000788_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_9_1 & 1) == step_1)
    {
      stage_v_104_1 = ((stage_v_104_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_104_1 = ((stage_v_104_1 + pub_r000788_6_1) + 5) & 63;
    }
    if ((stage_v_9_2 & 1) == step_2)
    {
      stage_v_104_2 = ((stage_v_104_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_104_2 = ((stage_v_104_2 + pub_r000788_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_18_1 & 1) == step_1)
    {
      stage_v_105_1 = ((stage_v_105_1 + (step_1 * 4)) + pub_r000788_1_1) & 63;
    }
    else
    {
      stage_v_105_1 = ((stage_v_105_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((sec_r000788_18_2 & 1) == step_2)
    {
      stage_v_105_2 = ((stage_v_105_2 + (step_2 * 4)) + pub_r000788_1_2) & 63;
    }
    else
    {
      stage_v_105_2 = ((stage_v_105_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_66_1 & 1) == step_1)
    {
      stage_v_106_1 = ((stage_v_106_1 + (step_1 * 4)) + pub_r000788_1_1) & 63;
    }
    else
    {
      stage_v_106_1 = ((stage_v_106_1 + pub_r000788_17_1) + 5) & 63;
    }
    if ((stage_v_66_2 & 1) == step_2)
    {
      stage_v_106_2 = ((stage_v_106_2 + (step_2 * 4)) + pub_r000788_1_2) & 63;
    }
    else
    {
      stage_v_106_2 = ((stage_v_106_2 + pub_r000788_17_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_84_1 & 1) == step_1)
    {
      stage_v_107_1 = ((stage_v_107_1 + (step_1 * 4)) + pub_r000788_8_1) & 63;
    }
    else
    {
      stage_v_107_1 = ((stage_v_107_1 + pub_r000788_12_1) + 5) & 63;
    }
    if ((stage_v_84_2 & 1) == step_2)
    {
      stage_v_107_2 = ((stage_v_107_2 + (step_2 * 4)) + pub_r000788_8_2) & 63;
    }
    else
    {
      stage_v_107_2 = ((stage_v_107_2 + pub_r000788_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_8_1 & 1) == step_1)
    {
      stage_v_108_1 = ((stage_v_108_1 + (step_1 * 4)) + pub_r000788_13_1) & 63;
    }
    else
    {
      stage_v_108_1 = ((stage_v_108_1 + pub_r000788_7_1) + 5) & 63;
    }
    if ((stage_v_8_2 & 1) == step_2)
    {
      stage_v_108_2 = ((stage_v_108_2 + (step_2 * 4)) + pub_r000788_13_2) & 63;
    }
    else
    {
      stage_v_108_2 = ((stage_v_108_2 + pub_r000788_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_97_1 & 1) == step_1)
    {
      stage_v_109_1 = ((stage_v_109_1 + (step_1 * 4)) + pub_r000788_6_1) & 63;
    }
    else
    {
      stage_v_109_1 = ((stage_v_109_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_97_2 & 1) == step_2)
    {
      stage_v_109_2 = ((stage_v_109_2 + (step_2 * 4)) + pub_r000788_6_2) & 63;
    }
    else
    {
      stage_v_109_2 = ((stage_v_109_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_33_1 & 1) == step_1)
    {
      stage_v_110_1 = ((stage_v_110_1 + (step_1 * 4)) + pub_r000788_0_1) & 63;
    }
    else
    {
      stage_v_110_1 = ((stage_v_110_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((stage_v_33_2 & 1) == step_2)
    {
      stage_v_110_2 = ((stage_v_110_2 + (step_2 * 4)) + pub_r000788_0_2) & 63;
    }
    else
    {
      stage_v_110_2 = ((stage_v_110_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_12_1 & 1) == step_1)
    {
      stage_v_111_1 = ((stage_v_111_1 + (step_1 * 4)) + pub_r000788_0_1) & 63;
    }
    else
    {
      stage_v_111_1 = ((stage_v_111_1 + pub_r000788_11_1) + 5) & 63;
    }
    if ((sec_r000788_12_2 & 1) == step_2)
    {
      stage_v_111_2 = ((stage_v_111_2 + (step_2 * 4)) + pub_r000788_0_2) & 63;
    }
    else
    {
      stage_v_111_2 = ((stage_v_111_2 + pub_r000788_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_6_1 & 1) == step_1)
    {
      stage_v_112_1 = ((stage_v_112_1 + (step_1 * 4)) + pub_r000788_13_1) & 63;
    }
    else
    {
      stage_v_112_1 = ((stage_v_112_1 + pub_r000788_15_1) + 5) & 63;
    }
    if ((sec_r000788_6_2 & 1) == step_2)
    {
      stage_v_112_2 = ((stage_v_112_2 + (step_2 * 4)) + pub_r000788_13_2) & 63;
    }
    else
    {
      stage_v_112_2 = ((stage_v_112_2 + pub_r000788_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_93_1 & 1) == step_1)
    {
      stage_v_113_1 = ((stage_v_113_1 + (step_1 * 4)) + pub_r000788_11_1) & 63;
    }
    else
    {
      stage_v_113_1 = ((stage_v_113_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((stage_v_93_2 & 1) == step_2)
    {
      stage_v_113_2 = ((stage_v_113_2 + (step_2 * 4)) + pub_r000788_11_2) & 63;
    }
    else
    {
      stage_v_113_2 = ((stage_v_113_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_90_1 & 1) == step_1)
    {
      stage_v_114_1 = ((stage_v_114_1 + (step_1 * 4)) + pub_r000788_4_1) & 63;
    }
    else
    {
      stage_v_114_1 = ((stage_v_114_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_90_2 & 1) == step_2)
    {
      stage_v_114_2 = ((stage_v_114_2 + (step_2 * 4)) + pub_r000788_4_2) & 63;
    }
    else
    {
      stage_v_114_2 = ((stage_v_114_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_41_1 & 1) == step_1)
    {
      stage_v_115_1 = ((stage_v_115_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_115_1 = ((stage_v_115_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((stage_v_41_2 & 1) == step_2)
    {
      stage_v_115_2 = ((stage_v_115_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_115_2 = ((stage_v_115_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_14_1 & 1) == step_1)
    {
      stage_v_116_1 = ((stage_v_116_1 + (step_1 * 4)) + pub_r000788_10_1) & 63;
    }
    else
    {
      stage_v_116_1 = ((stage_v_116_1 + pub_r000788_3_1) + 5) & 63;
    }
    if ((sec_r000788_14_2 & 1) == step_2)
    {
      stage_v_116_2 = ((stage_v_116_2 + (step_2 * 4)) + pub_r000788_10_2) & 63;
    }
    else
    {
      stage_v_116_2 = ((stage_v_116_2 + pub_r000788_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_12_1 & 1) == step_1)
    {
      stage_v_117_1 = ((stage_v_117_1 + (step_1 * 4)) + pub_r000788_10_1) & 63;
    }
    else
    {
      stage_v_117_1 = ((stage_v_117_1 + pub_r000788_4_1) + 5) & 63;
    }
    if ((stage_v_12_2 & 1) == step_2)
    {
      stage_v_117_2 = ((stage_v_117_2 + (step_2 * 4)) + pub_r000788_10_2) & 63;
    }
    else
    {
      stage_v_117_2 = ((stage_v_117_2 + pub_r000788_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_118_1 = ((stage_v_118_1 + (step_1 * 4)) + pub_r000788_11_1) & 63;
    }
    else
    {
      stage_v_118_1 = ((stage_v_118_1 + pub_r000788_11_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_118_2 = ((stage_v_118_2 + (step_2 * 4)) + pub_r000788_11_2) & 63;
    }
    else
    {
      stage_v_118_2 = ((stage_v_118_2 + pub_r000788_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_51_1 & 1) == step_1)
    {
      stage_v_119_1 = ((stage_v_119_1 + (step_1 * 4)) + pub_r000788_1_1) & 63;
    }
    else
    {
      stage_v_119_1 = ((stage_v_119_1 + pub_r000788_12_1) + 5) & 63;
    }
    if ((stage_v_51_2 & 1) == step_2)
    {
      stage_v_119_2 = ((stage_v_119_2 + (step_2 * 4)) + pub_r000788_1_2) & 63;
    }
    else
    {
      stage_v_119_2 = ((stage_v_119_2 + pub_r000788_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_11_1 & 1) == step_1)
    {
      stage_v_120_1 = ((stage_v_120_1 + (step_1 * 4)) + pub_r000788_2_1) & 63;
    }
    else
    {
      stage_v_120_1 = ((stage_v_120_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((sec_r000788_11_2 & 1) == step_2)
    {
      stage_v_120_2 = ((stage_v_120_2 + (step_2 * 4)) + pub_r000788_2_2) & 63;
    }
    else
    {
      stage_v_120_2 = ((stage_v_120_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_121_1 = ((stage_v_121_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_121_1 = ((stage_v_121_1 + pub_r000788_15_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_121_2 = ((stage_v_121_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_121_2 = ((stage_v_121_2 + pub_r000788_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_39_1 & 1) == step_1)
    {
      stage_v_122_1 = ((stage_v_122_1 + (step_1 * 4)) + pub_r000788_14_1) & 63;
    }
    else
    {
      stage_v_122_1 = ((stage_v_122_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_39_2 & 1) == step_2)
    {
      stage_v_122_2 = ((stage_v_122_2 + (step_2 * 4)) + pub_r000788_14_2) & 63;
    }
    else
    {
      stage_v_122_2 = ((stage_v_122_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_57_1 & 1) == step_1)
    {
      stage_v_123_1 = ((stage_v_123_1 + (step_1 * 4)) + pub_r000788_12_1) & 63;
    }
    else
    {
      stage_v_123_1 = ((stage_v_123_1 + pub_r000788_8_1) + 5) & 63;
    }
    if ((stage_v_57_2 & 1) == step_2)
    {
      stage_v_123_2 = ((stage_v_123_2 + (step_2 * 4)) + pub_r000788_12_2) & 63;
    }
    else
    {
      stage_v_123_2 = ((stage_v_123_2 + pub_r000788_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_103_1 & 1) == step_1)
    {
      stage_v_124_1 = ((stage_v_124_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_124_1 = ((stage_v_124_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((stage_v_103_2 & 1) == step_2)
    {
      stage_v_124_2 = ((stage_v_124_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_124_2 = ((stage_v_124_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_62_1 & 1) == step_1)
    {
      stage_v_125_1 = ((stage_v_125_1 + (step_1 * 4)) + pub_r000788_2_1) & 63;
    }
    else
    {
      stage_v_125_1 = ((stage_v_125_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((stage_v_62_2 & 1) == step_2)
    {
      stage_v_125_2 = ((stage_v_125_2 + (step_2 * 4)) + pub_r000788_2_2) & 63;
    }
    else
    {
      stage_v_125_2 = ((stage_v_125_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_54_1 & 1) == step_1)
    {
      stage_v_126_1 = ((stage_v_126_1 + (step_1 * 4)) + pub_r000788_18_1) & 63;
    }
    else
    {
      stage_v_126_1 = ((stage_v_126_1 + pub_r000788_13_1) + 5) & 63;
    }
    if ((stage_v_54_2 & 1) == step_2)
    {
      stage_v_126_2 = ((stage_v_126_2 + (step_2 * 4)) + pub_r000788_18_2) & 63;
    }
    else
    {
      stage_v_126_2 = ((stage_v_126_2 + pub_r000788_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_120_1 & 1) == step_1)
    {
      stage_v_127_1 = ((stage_v_127_1 + (step_1 * 4)) + pub_r000788_3_1) & 63;
    }
    else
    {
      stage_v_127_1 = ((stage_v_127_1 + pub_r000788_2_1) + 5) & 63;
    }
    if ((stage_v_120_2 & 1) == step_2)
    {
      stage_v_127_2 = ((stage_v_127_2 + (step_2 * 4)) + pub_r000788_3_2) & 63;
    }
    else
    {
      stage_v_127_2 = ((stage_v_127_2 + pub_r000788_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_14_1 & 1) == step_1)
    {
      stage_v_128_1 = ((stage_v_128_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_128_1 = ((stage_v_128_1 + pub_r000788_11_1) + 5) & 63;
    }
    if ((sec_r000788_14_2 & 1) == step_2)
    {
      stage_v_128_2 = ((stage_v_128_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_128_2 = ((stage_v_128_2 + pub_r000788_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_54_1 & 1) == step_1)
    {
      stage_v_129_1 = ((stage_v_129_1 + (step_1 * 4)) + pub_r000788_8_1) & 63;
    }
    else
    {
      stage_v_129_1 = ((stage_v_129_1 + pub_r000788_12_1) + 5) & 63;
    }
    if ((stage_v_54_2 & 1) == step_2)
    {
      stage_v_129_2 = ((stage_v_129_2 + (step_2 * 4)) + pub_r000788_8_2) & 63;
    }
    else
    {
      stage_v_129_2 = ((stage_v_129_2 + pub_r000788_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_111_1 & 1) == step_1)
    {
      stage_v_130_1 = ((stage_v_130_1 + (step_1 * 4)) + pub_r000788_15_1) & 63;
    }
    else
    {
      stage_v_130_1 = ((stage_v_130_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((stage_v_111_2 & 1) == step_2)
    {
      stage_v_130_2 = ((stage_v_130_2 + (step_2 * 4)) + pub_r000788_15_2) & 63;
    }
    else
    {
      stage_v_130_2 = ((stage_v_130_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_80_1 & 1) == step_1)
    {
      stage_v_131_1 = ((stage_v_131_1 + (step_1 * 4)) + pub_r000788_7_1) & 63;
    }
    else
    {
      stage_v_131_1 = ((stage_v_131_1 + pub_r000788_13_1) + 5) & 63;
    }
    if ((stage_v_80_2 & 1) == step_2)
    {
      stage_v_131_2 = ((stage_v_131_2 + (step_2 * 4)) + pub_r000788_7_2) & 63;
    }
    else
    {
      stage_v_131_2 = ((stage_v_131_2 + pub_r000788_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_10_1 & 1) == step_1)
    {
      stage_v_132_1 = ((stage_v_132_1 + (step_1 * 4)) + pub_r000788_0_1) & 63;
    }
    else
    {
      stage_v_132_1 = ((stage_v_132_1 + pub_r000788_11_1) + 5) & 63;
    }
    if ((sec_r000788_10_2 & 1) == step_2)
    {
      stage_v_132_2 = ((stage_v_132_2 + (step_2 * 4)) + pub_r000788_0_2) & 63;
    }
    else
    {
      stage_v_132_2 = ((stage_v_132_2 + pub_r000788_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_12_1 & 1) == step_1)
    {
      stage_v_133_1 = ((stage_v_133_1 + (step_1 * 4)) + pub_r000788_6_1) & 63;
    }
    else
    {
      stage_v_133_1 = ((stage_v_133_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((sec_r000788_12_2 & 1) == step_2)
    {
      stage_v_133_2 = ((stage_v_133_2 + (step_2 * 4)) + pub_r000788_6_2) & 63;
    }
    else
    {
      stage_v_133_2 = ((stage_v_133_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_119_1 & 1) == step_1)
    {
      stage_v_134_1 = ((stage_v_134_1 + (step_1 * 4)) + pub_r000788_2_1) & 63;
    }
    else
    {
      stage_v_134_1 = ((stage_v_134_1 + pub_r000788_17_1) + 5) & 63;
    }
    if ((stage_v_119_2 & 1) == step_2)
    {
      stage_v_134_2 = ((stage_v_134_2 + (step_2 * 4)) + pub_r000788_2_2) & 63;
    }
    else
    {
      stage_v_134_2 = ((stage_v_134_2 + pub_r000788_17_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_7_1 & 1) == step_1)
    {
      stage_v_135_1 = ((stage_v_135_1 + (step_1 * 4)) + pub_r000788_19_1) & 63;
    }
    else
    {
      stage_v_135_1 = ((stage_v_135_1 + pub_r000788_9_1) + 5) & 63;
    }
    if ((sec_r000788_7_2 & 1) == step_2)
    {
      stage_v_135_2 = ((stage_v_135_2 + (step_2 * 4)) + pub_r000788_19_2) & 63;
    }
    else
    {
      stage_v_135_2 = ((stage_v_135_2 + pub_r000788_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_64_1 & 1) == step_1)
    {
      stage_v_136_1 = ((stage_v_136_1 + (step_1 * 4)) + pub_r000788_13_1) & 63;
    }
    else
    {
      stage_v_136_1 = ((stage_v_136_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_64_2 & 1) == step_2)
    {
      stage_v_136_2 = ((stage_v_136_2 + (step_2 * 4)) + pub_r000788_13_2) & 63;
    }
    else
    {
      stage_v_136_2 = ((stage_v_136_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_131_1 & 1) == step_1)
    {
      stage_v_137_1 = ((stage_v_137_1 + (step_1 * 4)) + pub_r000788_6_1) & 63;
    }
    else
    {
      stage_v_137_1 = ((stage_v_137_1 + pub_r000788_18_1) + 5) & 63;
    }
    if ((stage_v_131_2 & 1) == step_2)
    {
      stage_v_137_2 = ((stage_v_137_2 + (step_2 * 4)) + pub_r000788_6_2) & 63;
    }
    else
    {
      stage_v_137_2 = ((stage_v_137_2 + pub_r000788_18_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_2_1 & 1) == step_1)
    {
      stage_v_138_1 = ((stage_v_138_1 + (step_1 * 4)) + pub_r000788_0_1) & 63;
    }
    else
    {
      stage_v_138_1 = ((stage_v_138_1 + pub_r000788_4_1) + 5) & 63;
    }
    if ((sec_r000788_2_2 & 1) == step_2)
    {
      stage_v_138_2 = ((stage_v_138_2 + (step_2 * 4)) + pub_r000788_0_2) & 63;
    }
    else
    {
      stage_v_138_2 = ((stage_v_138_2 + pub_r000788_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_19_1 & 1) == step_1)
    {
      stage_v_139_1 = ((stage_v_139_1 + (step_1 * 4)) + pub_r000788_2_1) & 63;
    }
    else
    {
      stage_v_139_1 = ((stage_v_139_1 + pub_r000788_14_1) + 5) & 63;
    }
    if ((sec_r000788_19_2 & 1) == step_2)
    {
      stage_v_139_2 = ((stage_v_139_2 + (step_2 * 4)) + pub_r000788_2_2) & 63;
    }
    else
    {
      stage_v_139_2 = ((stage_v_139_2 + pub_r000788_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_24_1 & 1) == step_1)
    {
      stage_v_140_1 = ((stage_v_140_1 + (step_1 * 4)) + pub_r000788_2_1) & 63;
    }
    else
    {
      stage_v_140_1 = ((stage_v_140_1 + pub_r000788_19_1) + 5) & 63;
    }
    if ((stage_v_24_2 & 1) == step_2)
    {
      stage_v_140_2 = ((stage_v_140_2 + (step_2 * 4)) + pub_r000788_2_2) & 63;
    }
    else
    {
      stage_v_140_2 = ((stage_v_140_2 + pub_r000788_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_90_1 & 1) == step_1)
    {
      stage_v_141_1 = ((stage_v_141_1 + (step_1 * 4)) + pub_r000788_1_1) & 63;
    }
    else
    {
      stage_v_141_1 = ((stage_v_141_1 + pub_r000788_14_1) + 5) & 63;
    }
    if ((stage_v_90_2 & 1) == step_2)
    {
      stage_v_141_2 = ((stage_v_141_2 + (step_2 * 4)) + pub_r000788_1_2) & 63;
    }
    else
    {
      stage_v_141_2 = ((stage_v_141_2 + pub_r000788_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_4_1 & 1) == step_1)
    {
      stage_v_142_1 = ((stage_v_142_1 + (step_1 * 4)) + pub_r000788_16_1) & 63;
    }
    else
    {
      stage_v_142_1 = ((stage_v_142_1 + pub_r000788_9_1) + 5) & 63;
    }
    if ((sec_r000788_4_2 & 1) == step_2)
    {
      stage_v_142_2 = ((stage_v_142_2 + (step_2 * 4)) + pub_r000788_16_2) & 63;
    }
    else
    {
      stage_v_142_2 = ((stage_v_142_2 + pub_r000788_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_10_1 & 1) == step_1)
    {
      stage_v_143_1 = ((stage_v_143_1 + (step_1 * 4)) + pub_r000788_6_1) & 63;
    }
    else
    {
      stage_v_143_1 = ((stage_v_143_1 + pub_r000788_1_1) + 5) & 63;
    }
    if ((sec_r000788_10_2 & 1) == step_2)
    {
      stage_v_143_2 = ((stage_v_143_2 + (step_2 * 4)) + pub_r000788_6_2) & 63;
    }
    else
    {
      stage_v_143_2 = ((stage_v_143_2 + pub_r000788_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_8_1 & 1) == step_1)
    {
      stage_v_144_1 = ((stage_v_144_1 + (step_1 * 4)) + pub_r000788_8_1) & 63;
    }
    else
    {
      stage_v_144_1 = ((stage_v_144_1 + pub_r000788_16_1) + 5) & 63;
    }
    if ((sec_r000788_8_2 & 1) == step_2)
    {
      stage_v_144_2 = ((stage_v_144_2 + (step_2 * 4)) + pub_r000788_8_2) & 63;
    }
    else
    {
      stage_v_144_2 = ((stage_v_144_2 + pub_r000788_16_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000788_7_1 & 1) == step_1)
    {
      stage_v_145_1 = ((stage_v_145_1 + (step_1 * 4)) + pub_r000788_13_1) & 63;
    }
    else
    {
      stage_v_145_1 = ((stage_v_145_1 + pub_r000788_9_1) + 5) & 63;
    }
    if ((sec_r000788_7_2 & 1) == step_2)
    {
      stage_v_145_2 = ((stage_v_145_2 + (step_2 * 4)) + pub_r000788_13_2) & 63;
    }
    else
    {
      stage_v_145_2 = ((stage_v_145_2 + pub_r000788_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000788_5_1 != sec_r000788_5_2);
  __CPROVER_assume(sec_r000788_8_1 != sec_r000788_8_2);
  __CPROVER_assume(pub_r000788_13_1 == pub_r000788_13_2);
  __CPROVER_assume(pub_r000788_4_1 == pub_r000788_4_2);
  __CPROVER_assume(pub_r000788_9_1 == pub_r000788_9_2);
  __CPROVER_assume(pub_r000788_8_1 == pub_r000788_8_2);
  __CPROVER_assume(pub_r000788_15_1 == pub_r000788_15_2);
  __CPROVER_assume(sec_r000788_1_1 != sec_r000788_1_2);
  __CPROVER_assume(sec_r000788_12_1 != sec_r000788_12_2);
  __CPROVER_assume(pub_r000788_1_1 == pub_r000788_1_2);
  __CPROVER_assume(pub_r000788_5_1 == pub_r000788_5_2);
  __CPROVER_assume(sec_r000788_17_1 != sec_r000788_17_2);
  __CPROVER_assume(sec_r000788_4_1 != sec_r000788_4_2);
  __CPROVER_assume(pub_r000788_18_1 == pub_r000788_18_2);
  __CPROVER_assume(sec_r000788_15_1 != sec_r000788_15_2);
  __CPROVER_assume(sec_r000788_16_1 != sec_r000788_16_2);
  __CPROVER_assume(sec_r000788_14_1 != sec_r000788_14_2);
  __CPROVER_assume(pub_r000788_0_1 == pub_r000788_0_2);
  __CPROVER_assume(pub_r000788_3_1 == pub_r000788_3_2);
  __CPROVER_assume(sec_r000788_10_1 != sec_r000788_10_2);
  __CPROVER_assume(pub_r000788_19_1 == pub_r000788_19_2);
  __CPROVER_assume(sec_r000788_0_1 != sec_r000788_0_2);
  __CPROVER_assume(sec_r000788_7_1 != sec_r000788_7_2);
  __CPROVER_assume(pub_r000788_12_1 == pub_r000788_12_2);
  __CPROVER_assume(sec_r000788_2_1 != sec_r000788_2_2);
  __CPROVER_assume(pub_r000788_7_1 == pub_r000788_7_2);
  __CPROVER_assume(sec_r000788_18_1 != sec_r000788_18_2);
  __CPROVER_assume(sec_r000788_9_1 != sec_r000788_9_2);
  __CPROVER_assume(pub_r000788_17_1 == pub_r000788_17_2);
  __CPROVER_assume(pub_r000788_14_1 == pub_r000788_14_2);
  __CPROVER_assume(sec_r000788_6_1 != sec_r000788_6_2);
  __CPROVER_assume(sec_r000788_19_1 != sec_r000788_19_2);
  __CPROVER_assume(sec_r000788_13_1 != sec_r000788_13_2);
  __CPROVER_assume(pub_r000788_16_1 == pub_r000788_16_2);
  __CPROVER_assume(pub_r000788_10_1 == pub_r000788_10_2);
  __CPROVER_assume(pub_r000788_6_1 == pub_r000788_6_2);
  __CPROVER_assume(pub_r000788_11_1 == pub_r000788_11_2);
  __CPROVER_assume(sec_r000788_3_1 != sec_r000788_3_2);
  __CPROVER_assume(pub_r000788_2_1 == pub_r000788_2_2);
  __CPROVER_assume(sec_r000788_11_1 != sec_r000788_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
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
}


