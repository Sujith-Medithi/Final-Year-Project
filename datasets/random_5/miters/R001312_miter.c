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
struct DeviceConfig_R001312_1213_0
{
  short parity;
  int id;
  int timeout;
  short baud_rate;
  int port;
  int buffer[3];
};
struct SensorNode_R001312_1213_1
{
  short reading;
  int threshold;
  unsigned char gain;
  int offset;
  short calib;
  int buffer[3];
};
union PacketPayload_R001312_1213_0
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
void fn_R001312_1213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int accumulator_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_79_1)
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

  switch (accumulator_79_2)
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

  int offset_21_1 = 0;
  int offset_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_21_1 = ((offset_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_21_2 = ((offset_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_21_1) & 127;
    acc_2 = (acc_2 + offset_21_2) & 127;
  }

  int bound_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_73_1) & 63;
  aux_2 = (aux_2 + bound_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_18_1 = local_arr_1[aux_1 % 3];
  int damping_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_18_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_79_1 == accumulator_79_2);
  assert(offset_21_1 == offset_21_2);
  assert(bound_73_1 == bound_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_18_1 == damping_18_2);
}

int fn_R001312_1213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int accumulator_79 = (aux + st.buffer[1]) & 3;
  switch (accumulator_79)
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

  int offset_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_21 = ((offset_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_21) & 127;
  }

  int bound_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_73) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_18 = local_arr[aux % 3];
  acc = (acc + (damping_18 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int factor_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_15_1 > 36)
  {
    acc_1 = ((acc_1 + (factor_15_1 * 2)) + 5) & 127;
    aux_1 ^= factor_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_15_2 > 36)
  {
    acc_2 = ((acc_2 + (factor_15_2 * 2)) + 5) & 127;
    aux_2 ^= factor_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_63_1 = 0;
  int cursor_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_63_1 = ((cursor_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_63_2 = ((cursor_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_63_1) & 127;
    acc_2 = (acc_2 + cursor_63_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_14_1 = local_arr_1[aux_1 % 3];
  int offset_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_15_1 == factor_15_2);
  assert(cursor_63_1 == cursor_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_14_1 == offset_14_2);
}

int fn_R001312_1213_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int factor_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_15 > 36)
  {
    acc = ((acc + (factor_15 * 2)) + 5) & 127;
    aux ^= factor_15 & 15;
  }
  else
  {
    acc = ((acc - factor_15) + 11) & 127;
    aux += 3;
  }
  int cursor_63 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_63 = ((cursor_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_63) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_14 = local_arr[aux % 3];
  acc = (acc + (offset_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int stride_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_43_1 > 41)
  {
    acc_1 = ((acc_1 + (stride_43_1 * 2)) + 5) & 127;
    aux_1 ^= stride_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_43_2 > 41)
  {
    acc_2 = ((acc_2 + (stride_43_2 * 2)) + 5) & 127;
    aux_2 ^= stride_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_60_1 = 0;
  int anchor_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_60_1 = ((anchor_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_60_2 = ((anchor_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_60_1) & 127;
    acc_2 = (acc_2 + anchor_60_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_43_1 == stride_43_2);
  assert(anchor_60_1 == anchor_60_2);
}

int fn_R001312_1213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int stride_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_43 > 41)
  {
    acc = ((acc + (stride_43 * 2)) + 5) & 127;
    aux ^= stride_43 & 15;
  }
  else
  {
    acc = ((acc - stride_43) + 11) & 127;
    aux += 3;
  }
  int anchor_60 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_60 = ((anchor_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_60) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int stride_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_37_1 > 25)
  {
    acc_1 = ((acc_1 + (stride_37_1 * 2)) + 5) & 127;
    aux_1 ^= stride_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_37_2 > 25)
  {
    acc_2 = ((acc_2 + (stride_37_2 * 2)) + 5) & 127;
    aux_2 ^= stride_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_15_1)
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

  switch (phase_15_2)
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
  int tracker_59_1 = local_arr_1[aux_1 % 3];
  int tracker_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_59_2 * 2)) & 127;
  int offset_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_53_1) & 63;
  aux_2 = (aux_2 + offset_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_37_1 == stride_37_2);
  assert(phase_15_1 == phase_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_59_1 == tracker_59_2);
  assert(offset_53_1 == offset_53_2);
}

int fn_R001312_1213_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int stride_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_37 > 25)
  {
    acc = ((acc + (stride_37 * 2)) + 5) & 127;
    aux ^= stride_37 & 15;
  }
  else
  {
    acc = ((acc - stride_37) + 11) & 127;
    aux += 3;
  }
  int phase_15 = (aux + st.buffer[1]) & 3;
  switch (phase_15)
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
  int tracker_59 = local_arr[aux % 3];
  acc = (acc + (tracker_59 * 2)) & 127;
  int offset_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_53) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001312_1213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_32_1 = local_arr_1[aux_1 % 3];
  int delta_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_32_2 * 2)) & 127;
  int vector_32_1 = 0;
  int vector_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_32_1 = ((vector_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_32_2 = ((vector_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_32_1) & 127;
    acc_2 = (acc_2 + vector_32_2) & 127;
  }

  int tally_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_11_1) & 63;
  aux_2 = (aux_2 + tally_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_89_1 > 31)
  {
    acc_1 = ((acc_1 + (accumulator_89_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_89_2 > 31)
  {
    acc_2 = ((acc_2 + (accumulator_89_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
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

  assert(delta_32_1 == delta_32_2);
  assert(vector_32_1 == vector_32_2);
  assert(tally_11_1 == tally_11_2);
  assert(accumulator_89_1 == accumulator_89_2);
}

int fn_R001312_1213_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int delta_32 = local_arr[aux % 3];
  acc = (acc + (delta_32 * 2)) & 127;
  int vector_32 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_32 = ((vector_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_32) & 127;
  }

  int tally_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_11) & 63;
  acc ^= aux;
  int accumulator_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_89 > 31)
  {
    acc = ((acc + (accumulator_89 * 2)) + 5) & 127;
    aux ^= accumulator_89 & 15;
  }
  else
  {
    acc = ((acc - accumulator_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001312_1213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int damping_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_62_1 > 22)
  {
    acc_1 = ((acc_1 + (damping_62_1 * 2)) + 5) & 127;
    aux_1 ^= damping_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_62_2 > 22)
  {
    acc_2 = ((acc_2 + (damping_62_2 * 2)) + 5) & 127;
    aux_2 ^= damping_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_90_1) & 63;
  aux_2 = (aux_2 + margin_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_62_1 == damping_62_2);
  assert(margin_90_1 == margin_90_2);
}

int fn_R001312_1213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int damping_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_62 > 22)
  {
    acc = ((acc + (damping_62 * 2)) + 5) & 127;
    aux ^= damping_62 & 15;
  }
  else
  {
    acc = ((acc - damping_62) + 11) & 127;
    aux += 3;
  }
  int margin_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_90) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int anchor_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_46_1) & 63;
  aux_2 = (aux_2 + anchor_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_40_1 = 0;
  int scale_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_40_1 = ((scale_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_40_2 = ((scale_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_40_1) & 127;
    acc_2 = (acc_2 + scale_40_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_46_1 == anchor_46_2);
  assert(scale_40_1 == scale_40_2);
}

int fn_R001312_1213_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int anchor_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_46) & 63;
  acc ^= aux;
  int scale_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_40 = ((scale_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_40) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001312_1213_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int window_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_41_1 > 50)
  {
    acc_1 = ((acc_1 + (window_41_1 * 2)) + 5) & 127;
    aux_1 ^= window_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_41_2 > 50)
  {
    acc_2 = ((acc_2 + (window_41_2 * 2)) + 5) & 127;
    aux_2 ^= window_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_83_1)
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

  switch (coefficient_83_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_33_1 = local_arr_1[aux_1 % 3];
  int weight_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_41_1 == window_41_2);
  assert(coefficient_83_1 == coefficient_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_33_1 == weight_33_2);
}

int fn_R001312_1213_7(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int window_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_41 > 50)
  {
    acc = ((acc + (window_41 * 2)) + 5) & 127;
    aux ^= window_41 & 15;
  }
  else
  {
    acc = ((acc - window_41) + 11) & 127;
    aux += 3;
  }
  int coefficient_83 = (aux + st.buffer[1]) & 3;
  switch (coefficient_83)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_33 = local_arr[aux % 3];
  acc = (acc + (weight_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_32_1 = local_arr_1[aux_1 % 3];
  int quotient_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_32_2 * 2)) & 127;
  int quotient_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_52_1) & 63;
  aux_2 = (aux_2 + quotient_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_32_1 == quotient_32_2);
  assert(quotient_52_1 == quotient_52_2);
}

int fn_R001312_1213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int quotient_32 = local_arr[aux % 3];
  acc = (acc + (quotient_32 * 2)) & 127;
  int quotient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001312_1213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
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
  int checksum_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_76_1)
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

  switch (checksum_76_2)
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

  int stride_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_96_1) & 63;
  aux_2 = (aux_2 + stride_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_91_1 == margin_91_2);
  assert(checksum_76_1 == checksum_76_2);
  assert(stride_96_1 == stride_96_2);
}

int fn_R001312_1213_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
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
  int checksum_76 = (aux + st.buffer[1]) & 3;
  switch (checksum_76)
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

  int stride_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001312_1213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int damping_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_67_1) & 63;
  aux_2 = (aux_2 + damping_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_67_1 == damping_67_2);
}

int fn_R001312_1213_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int damping_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_67) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int tally_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_77_1) & 63;
  aux_2 = (aux_2 + tally_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_71_1 > 43)
  {
    acc_1 = ((acc_1 + (residue_71_1 * 2)) + 5) & 127;
    aux_1 ^= residue_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_71_2 > 43)
  {
    acc_2 = ((acc_2 + (residue_71_2 * 2)) + 5) & 127;
    aux_2 ^= residue_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_71_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_77_1 == tally_77_2);
  assert(residue_71_1 == residue_71_2);
}

int fn_R001312_1213_11(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int tally_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_77) & 63;
  acc ^= aux;
  int residue_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_71 > 43)
  {
    acc = ((acc + (residue_71 * 2)) + 5) & 127;
    aux ^= residue_71 & 15;
  }
  else
  {
    acc = ((acc - residue_71) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_70_1)
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

  switch (quotient_70_2)
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
  int phase_20_1 = local_arr_1[aux_1 % 3];
  int phase_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_20_2 * 2)) & 127;
  int metric_36_1 = 0;
  int metric_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_36_1 = ((metric_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_36_2 = ((metric_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_36_1) & 127;
    acc_2 = (acc_2 + metric_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_70_1 == quotient_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_20_1 == phase_20_2);
  assert(metric_36_1 == metric_36_2);
}

int fn_R001312_1213_12(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_70 = (aux + st.buffer[1]) & 3;
  switch (quotient_70)
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
  int phase_20 = local_arr[aux % 3];
  acc = (acc + (phase_20 * 2)) & 127;
  int metric_36 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_36 = ((metric_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001312_1213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int cursor_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_38_1 > 10)
  {
    acc_1 = ((acc_1 + (cursor_38_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_38_2 > 10)
  {
    acc_2 = ((acc_2 + (cursor_38_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_99_1)
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

  switch (parity_99_2)
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
  int cursor_44_1 = local_arr_1[aux_1 % 3];
  int cursor_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_44_2 * 2)) & 127;
  int bound_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_68_1) & 63;
  aux_2 = (aux_2 + bound_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_38_1 == cursor_38_2);
  assert(parity_99_1 == parity_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_44_1 == cursor_44_2);
  assert(bound_68_1 == bound_68_2);
}

int fn_R001312_1213_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int cursor_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_38 > 10)
  {
    acc = ((acc + (cursor_38 * 2)) + 5) & 127;
    aux ^= cursor_38 & 15;
  }
  else
  {
    acc = ((acc - cursor_38) + 11) & 127;
    aux += 3;
  }
  int parity_99 = (aux + st.buffer[1]) & 3;
  switch (parity_99)
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
  int cursor_44 = local_arr[aux % 3];
  acc = (acc + (cursor_44 * 2)) & 127;
  int bound_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001312_1213_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tally_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_36_1) & 63;
  aux_2 = (aux_2 + tally_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_45_1 = local_arr_1[aux_1 % 3];
  int sample_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_36_1 == tally_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_45_1 == sample_45_2);
}

int fn_R001312_1213_14(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tally_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_36) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_45 = local_arr[aux % 3];
  acc = (acc + (sample_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int phase_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_24_1 > 33)
  {
    acc_1 = ((acc_1 + (phase_24_1 * 2)) + 5) & 127;
    aux_1 ^= phase_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_24_2 > 33)
  {
    acc_2 = ((acc_2 + (phase_24_2 * 2)) + 5) & 127;
    aux_2 ^= phase_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_59_1 = local_arr_1[aux_1 % 3];
  int bound_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_59_2 * 2)) & 127;
  int offset_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_33_1) & 63;
  aux_2 = (aux_2 + offset_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_24_1 == phase_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_59_1 == bound_59_2);
  assert(offset_33_1 == offset_33_2);
}

int fn_R001312_1213_15(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int phase_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_24 > 33)
  {
    acc = ((acc + (phase_24 * 2)) + 5) & 127;
    aux ^= phase_24 & 15;
  }
  else
  {
    acc = ((acc - phase_24) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_59 = local_arr[aux % 3];
  acc = (acc + (bound_59 * 2)) & 127;
  int offset_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_33) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int bound_33_1 = 0;
  int bound_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_33_1 = ((bound_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_33_2 = ((bound_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_33_1) & 127;
    acc_2 = (acc_2 + bound_33_2) & 127;
  }

  int window_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_64_1)
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

  switch (window_64_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_33_1 == bound_33_2);
  assert(window_64_1 == window_64_2);
}

int fn_R001312_1213_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int bound_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_33 = ((bound_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_33) & 127;
  }

  int window_64 = (aux + st.buffer[1]) & 3;
  switch (window_64)
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

void fn_R001312_1213_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_48_1 > 12)
  {
    acc_1 = ((acc_1 + (bound_48_1 * 2)) + 5) & 127;
    aux_1 ^= bound_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_48_2 > 12)
  {
    acc_2 = ((acc_2 + (bound_48_2 * 2)) + 5) & 127;
    aux_2 ^= bound_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_51_1)
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

  switch (phase_51_2)
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

  int accumulator_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_65_1) & 63;
  aux_2 = (aux_2 + accumulator_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_48_1 == bound_48_2);
  assert(phase_51_1 == phase_51_2);
  assert(accumulator_65_1 == accumulator_65_2);
}

int fn_R001312_1213_17(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_48 > 12)
  {
    acc = ((acc + (bound_48 * 2)) + 5) & 127;
    aux ^= bound_48 & 15;
  }
  else
  {
    acc = ((acc - bound_48) + 11) & 127;
    aux += 3;
  }
  int phase_51 = (aux + st.buffer[1]) & 3;
  switch (phase_51)
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

  int accumulator_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_65) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int threshold_52_1 = 0;
  int threshold_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_52_1 = ((threshold_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_52_2 = ((threshold_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_52_1) & 127;
    acc_2 = (acc_2 + threshold_52_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_14_1 = local_arr_1[aux_1 % 3];
  int anchor_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_52_1 == threshold_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_14_1 == anchor_14_2);
}

int fn_R001312_1213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int threshold_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_52 = ((threshold_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_52) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_14 = local_arr[aux % 3];
  acc = (acc + (anchor_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int metric_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_91_1)
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

  switch (metric_91_2)
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
  int damping_50_1 = local_arr_1[aux_1 % 3];
  int damping_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_43_1 = 0;
  int quantum_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_43_1 = ((quantum_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_43_2 = ((quantum_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_43_1) & 127;
    acc_2 = (acc_2 + quantum_43_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_91_1 == metric_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_50_1 == damping_50_2);
  assert(quantum_43_1 == quantum_43_2);
}

int fn_R001312_1213_19(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int metric_91 = (aux + st.buffer[1]) & 3;
  switch (metric_91)
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
  int damping_50 = local_arr[aux % 3];
  acc = (acc + (damping_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_43 = ((quantum_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_43) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001312_1213_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_78_1)
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

  switch (tally_78_2)
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

  int bound_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_14_1) & 63;
  aux_2 = (aux_2 + bound_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_86_1 > 49)
  {
    acc_1 = ((acc_1 + (metric_86_1 * 2)) + 5) & 127;
    aux_1 ^= metric_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_86_2 > 49)
  {
    acc_2 = ((acc_2 + (metric_86_2 * 2)) + 5) & 127;
    aux_2 ^= metric_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_78_1 == tally_78_2);
  assert(bound_14_1 == bound_14_2);
  assert(metric_86_1 == metric_86_2);
}

int fn_R001312_1213_20(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_78 = (aux + st.buffer[1]) & 3;
  switch (tally_78)
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

  int bound_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_14) & 63;
  acc ^= aux;
  int metric_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_86 > 49)
  {
    acc = ((acc + (metric_86 * 2)) + 5) & 127;
    aux ^= metric_86 & 15;
  }
  else
  {
    acc = ((acc - metric_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001312_1213_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st_1 = {0};
  struct SensorNode_R001312_1213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int offset_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_84_1 > 20)
  {
    acc_1 = ((acc_1 + (offset_84_1 * 2)) + 5) & 127;
    aux_1 ^= offset_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_84_2 > 20)
  {
    acc_2 = ((acc_2 + (offset_84_2 * 2)) + 5) & 127;
    aux_2 ^= offset_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_17_1)
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

  switch (bound_17_2)
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

  int quantum_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_69_1) & 63;
  aux_2 = (aux_2 + quantum_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_95_1 = local_arr_1[aux_1 % 3];
  int tracker_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_84_1 == offset_84_2);
  assert(bound_17_1 == bound_17_2);
  assert(quantum_69_1 == quantum_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_95_1 == tracker_95_2);
}

int fn_R001312_1213_21(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001312_1213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int offset_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_84 > 20)
  {
    acc = ((acc + (offset_84 * 2)) + 5) & 127;
    aux ^= offset_84 & 15;
  }
  else
  {
    acc = ((acc - offset_84) + 11) & 127;
    aux += 3;
  }
  int bound_17 = (aux + st.buffer[1]) & 3;
  switch (bound_17)
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

  int quantum_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_69) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_95 = local_arr[aux % 3];
  acc = (acc + (tracker_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_41_1)
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

  switch (pivot_41_2)
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

  int window_71_1 = 0;
  int window_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_71_1 = ((window_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_71_2 = ((window_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_71_1) & 127;
    acc_2 = (acc_2 + window_71_2) & 127;
  }

  int segment_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_82_1) & 63;
  aux_2 = (aux_2 + segment_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_41_1 == pivot_41_2);
  assert(window_71_1 == window_71_2);
  assert(segment_82_1 == segment_82_2);
}

int fn_R001312_1213_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_41 = (aux + st.buffer[1]) & 3;
  switch (pivot_41)
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

  int window_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_71 = ((window_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_71) & 127;
  }

  int segment_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_82) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001312_1213_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int accumulator_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_45_1) & 63;
  aux_2 = (aux_2 + accumulator_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_15_1 = 0;
  int pivot_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_15_1 = ((pivot_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_15_2 = ((pivot_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_15_1) & 127;
    acc_2 = (acc_2 + pivot_15_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_45_1 == accumulator_45_2);
  assert(pivot_15_1 == pivot_15_2);
}

int fn_R001312_1213_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001312_1213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int accumulator_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_45) & 63;
  acc ^= aux;
  int pivot_15 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_15 = ((pivot_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_15) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001312_0_1;
  int sec_r001312_0_2;
  int sec_r001312_1_1;
  int sec_r001312_1_2;
  int sec_r001312_2_1;
  int sec_r001312_2_2;
  int sec_r001312_3_1;
  int sec_r001312_3_2;
  int sec_r001312_4_1;
  int sec_r001312_4_2;
  int sec_r001312_5_1;
  int sec_r001312_5_2;
  int sec_r001312_6_1;
  int sec_r001312_6_2;
  int sec_r001312_7_1;
  int sec_r001312_7_2;
  int sec_r001312_8_1;
  int sec_r001312_8_2;
  int sec_r001312_9_1;
  int sec_r001312_9_2;
  int sec_r001312_10_1;
  int sec_r001312_10_2;
  int sec_r001312_11_1;
  int sec_r001312_11_2;
  int sec_r001312_12_1;
  int sec_r001312_12_2;
  int sec_r001312_13_1;
  int sec_r001312_13_2;
  int sec_r001312_14_1;
  int sec_r001312_14_2;
  int sec_r001312_15_1;
  int sec_r001312_15_2;
  int sec_r001312_16_1;
  int sec_r001312_16_2;
  int sec_r001312_17_1;
  int sec_r001312_17_2;
  int pub_r001312_0_1;
  int pub_r001312_0_2;
  int pub_r001312_1_1;
  int pub_r001312_1_2;
  int pub_r001312_2_1;
  int pub_r001312_2_2;
  int pub_r001312_3_1;
  int pub_r001312_3_2;
  int pub_r001312_4_1;
  int pub_r001312_4_2;
  int pub_r001312_5_1;
  int pub_r001312_5_2;
  int pub_r001312_6_1;
  int pub_r001312_6_2;
  int pub_r001312_7_1;
  int pub_r001312_7_2;
  int pub_r001312_8_1;
  int pub_r001312_8_2;
  int pub_r001312_9_1;
  int pub_r001312_9_2;
  int pub_r001312_10_1;
  int pub_r001312_10_2;
  int pub_r001312_11_1;
  int pub_r001312_11_2;
  int pub_r001312_12_1;
  int pub_r001312_12_2;
  int pub_r001312_13_1;
  int pub_r001312_13_2;
  int pub_r001312_14_1;
  int pub_r001312_14_2;
  int pub_r001312_15_1;
  int pub_r001312_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001312_0_1 >= (-100)) && (pub_r001312_0_1 <= 100));
  __CPROVER_assume((pub_r001312_0_2 >= (-100)) && (pub_r001312_0_2 <= 100));
  __CPROVER_assume((pub_r001312_1_1 >= (-100)) && (pub_r001312_1_1 <= 100));
  __CPROVER_assume((pub_r001312_1_2 >= (-100)) && (pub_r001312_1_2 <= 100));
  __CPROVER_assume((pub_r001312_2_1 >= (-100)) && (pub_r001312_2_1 <= 100));
  __CPROVER_assume((pub_r001312_2_2 >= (-100)) && (pub_r001312_2_2 <= 100));
  __CPROVER_assume((pub_r001312_3_1 >= (-100)) && (pub_r001312_3_1 <= 100));
  __CPROVER_assume((pub_r001312_3_2 >= (-100)) && (pub_r001312_3_2 <= 100));
  __CPROVER_assume((pub_r001312_4_1 >= (-100)) && (pub_r001312_4_1 <= 100));
  __CPROVER_assume((pub_r001312_4_2 >= (-100)) && (pub_r001312_4_2 <= 100));
  __CPROVER_assume((pub_r001312_5_1 >= (-100)) && (pub_r001312_5_1 <= 100));
  __CPROVER_assume((pub_r001312_5_2 >= (-100)) && (pub_r001312_5_2 <= 100));
  __CPROVER_assume((pub_r001312_6_1 >= (-100)) && (pub_r001312_6_1 <= 100));
  __CPROVER_assume((pub_r001312_6_2 >= (-100)) && (pub_r001312_6_2 <= 100));
  __CPROVER_assume((pub_r001312_7_1 >= (-100)) && (pub_r001312_7_1 <= 100));
  __CPROVER_assume((pub_r001312_7_2 >= (-100)) && (pub_r001312_7_2 <= 100));
  __CPROVER_assume((pub_r001312_8_1 >= (-100)) && (pub_r001312_8_1 <= 100));
  __CPROVER_assume((pub_r001312_8_2 >= (-100)) && (pub_r001312_8_2 <= 100));
  __CPROVER_assume((pub_r001312_9_1 >= (-100)) && (pub_r001312_9_1 <= 100));
  __CPROVER_assume((pub_r001312_9_2 >= (-100)) && (pub_r001312_9_2 <= 100));
  __CPROVER_assume((pub_r001312_10_1 >= (-100)) && (pub_r001312_10_1 <= 100));
  __CPROVER_assume((pub_r001312_10_2 >= (-100)) && (pub_r001312_10_2 <= 100));
  __CPROVER_assume((pub_r001312_11_1 >= (-100)) && (pub_r001312_11_1 <= 100));
  __CPROVER_assume((pub_r001312_11_2 >= (-100)) && (pub_r001312_11_2 <= 100));
  __CPROVER_assume((pub_r001312_12_1 >= (-100)) && (pub_r001312_12_1 <= 100));
  __CPROVER_assume((pub_r001312_12_2 >= (-100)) && (pub_r001312_12_2 <= 100));
  __CPROVER_assume((pub_r001312_13_1 >= (-100)) && (pub_r001312_13_1 <= 100));
  __CPROVER_assume((pub_r001312_13_2 >= (-100)) && (pub_r001312_13_2 <= 100));
  __CPROVER_assume((pub_r001312_14_1 >= (-100)) && (pub_r001312_14_1 <= 100));
  __CPROVER_assume((pub_r001312_14_2 >= (-100)) && (pub_r001312_14_2 <= 100));
  __CPROVER_assume((pub_r001312_15_1 >= (-100)) && (pub_r001312_15_1 <= 100));
  __CPROVER_assume((pub_r001312_15_2 >= (-100)) && (pub_r001312_15_2 <= 100));
  __CPROVER_assume((sec_r001312_0_1 >= 0) && (sec_r001312_0_1 <= 255));
  __CPROVER_assume((sec_r001312_0_2 >= 0) && (sec_r001312_0_2 <= 255));
  __CPROVER_assume((sec_r001312_1_1 >= 0) && (sec_r001312_1_1 <= 255));
  __CPROVER_assume((sec_r001312_1_2 >= 0) && (sec_r001312_1_2 <= 255));
  __CPROVER_assume((sec_r001312_2_1 >= 0) && (sec_r001312_2_1 <= 255));
  __CPROVER_assume((sec_r001312_2_2 >= 0) && (sec_r001312_2_2 <= 255));
  __CPROVER_assume((sec_r001312_3_1 >= 0) && (sec_r001312_3_1 <= 255));
  __CPROVER_assume((sec_r001312_3_2 >= 0) && (sec_r001312_3_2 <= 255));
  __CPROVER_assume((sec_r001312_4_1 >= 0) && (sec_r001312_4_1 <= 255));
  __CPROVER_assume((sec_r001312_4_2 >= 0) && (sec_r001312_4_2 <= 255));
  __CPROVER_assume((sec_r001312_5_1 >= 0) && (sec_r001312_5_1 <= 255));
  __CPROVER_assume((sec_r001312_5_2 >= 0) && (sec_r001312_5_2 <= 255));
  __CPROVER_assume((sec_r001312_6_1 >= 0) && (sec_r001312_6_1 <= 255));
  __CPROVER_assume((sec_r001312_6_2 >= 0) && (sec_r001312_6_2 <= 255));
  __CPROVER_assume((sec_r001312_7_1 >= 0) && (sec_r001312_7_1 <= 255));
  __CPROVER_assume((sec_r001312_7_2 >= 0) && (sec_r001312_7_2 <= 255));
  __CPROVER_assume((sec_r001312_8_1 >= 0) && (sec_r001312_8_1 <= 255));
  __CPROVER_assume((sec_r001312_8_2 >= 0) && (sec_r001312_8_2 <= 255));
  __CPROVER_assume((sec_r001312_9_1 >= 0) && (sec_r001312_9_1 <= 255));
  __CPROVER_assume((sec_r001312_9_2 >= 0) && (sec_r001312_9_2 <= 255));
  __CPROVER_assume((sec_r001312_10_1 >= 0) && (sec_r001312_10_1 <= 255));
  __CPROVER_assume((sec_r001312_10_2 >= 0) && (sec_r001312_10_2 <= 255));
  __CPROVER_assume((sec_r001312_11_1 >= 0) && (sec_r001312_11_1 <= 255));
  __CPROVER_assume((sec_r001312_11_2 >= 0) && (sec_r001312_11_2 <= 255));
  __CPROVER_assume((sec_r001312_12_1 >= 0) && (sec_r001312_12_1 <= 255));
  __CPROVER_assume((sec_r001312_12_2 >= 0) && (sec_r001312_12_2 <= 255));
  __CPROVER_assume((sec_r001312_13_1 >= 0) && (sec_r001312_13_1 <= 255));
  __CPROVER_assume((sec_r001312_13_2 >= 0) && (sec_r001312_13_2 <= 255));
  __CPROVER_assume((sec_r001312_14_1 >= 0) && (sec_r001312_14_1 <= 255));
  __CPROVER_assume((sec_r001312_14_2 >= 0) && (sec_r001312_14_2 <= 255));
  __CPROVER_assume((sec_r001312_15_1 >= 0) && (sec_r001312_15_1 <= 255));
  __CPROVER_assume((sec_r001312_15_2 >= 0) && (sec_r001312_15_2 <= 255));
  __CPROVER_assume((sec_r001312_16_1 >= 0) && (sec_r001312_16_1 <= 255));
  __CPROVER_assume((sec_r001312_16_2 >= 0) && (sec_r001312_16_2 <= 255));
  __CPROVER_assume((sec_r001312_17_1 >= 0) && (sec_r001312_17_1 <= 255));
  __CPROVER_assume((sec_r001312_17_2 >= 0) && (sec_r001312_17_2 <= 255));
  struct DeviceConfig_R001312_1213_0 st_var_0_1 = {0};
  struct DeviceConfig_R001312_1213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001312_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001312_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001312_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001312_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001312_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001312_0_2 + 7) & 15;
  struct SensorNode_R001312_1213_1 st_var_1_1 = {0};
  struct SensorNode_R001312_1213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001312_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001312_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001312_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001312_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001312_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001312_0_2 + 9) & 15;
  union PacketPayload_R001312_1213_0 u_var_1;
  union PacketPayload_R001312_1213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001312_1213_0(sec_r001312_0_1, pub_r001312_1_1, pub_r001312_2_1);
  int helper_flow_0_2 = fn_R001312_1213_0(sec_r001312_0_2, pub_r001312_1_2, pub_r001312_2_2);
  fn_R001312_1213_0_2(sec_r001312_0_1, pub_r001312_1_1, pub_r001312_2_1, sec_r001312_0_2, pub_r001312_1_2, pub_r001312_2_2);
  int helper_flow_1_1 = fn_R001312_1213_1(sec_r001312_1_1, sec_r001312_2_1, pub_r001312_3_1, pub_r001312_4_1);
  int helper_flow_1_2 = fn_R001312_1213_1(sec_r001312_1_2, sec_r001312_2_2, pub_r001312_3_2, pub_r001312_4_2);
  fn_R001312_1213_1_2(sec_r001312_1_1, sec_r001312_2_1, pub_r001312_3_1, pub_r001312_4_1, sec_r001312_1_2, sec_r001312_2_2, pub_r001312_3_2, pub_r001312_4_2);
  int helper_flow_2_1 = fn_R001312_1213_2(sec_r001312_2_1, pub_r001312_3_1, pub_r001312_4_1, pub_r001312_5_1);
  int helper_flow_2_2 = fn_R001312_1213_2(sec_r001312_2_2, pub_r001312_3_2, pub_r001312_4_2, pub_r001312_5_2);
  fn_R001312_1213_2_2(sec_r001312_2_1, pub_r001312_3_1, pub_r001312_4_1, pub_r001312_5_1, sec_r001312_2_2, pub_r001312_3_2, pub_r001312_4_2, pub_r001312_5_2);
  int stage_v_0_1 = ((pub_r001312_4_1 * 2) + 37) & 63;
  int stage_v_0_2 = ((pub_r001312_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001312_4_1 * 3) + pub_r001312_3_1) + 43) & 127;
  int stage_v_1_2 = (((sec_r001312_4_2 * 3) + pub_r001312_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((sec_r001312_4_1 * 3) + pub_r001312_0_1) + 29) & 127;
  int stage_v_2_2 = (((sec_r001312_4_2 * 3) + pub_r001312_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001312_8_1 * 3) + pub_r001312_0_1) + 34) & 127;
  int stage_v_3_2 = (((sec_r001312_8_2 * 3) + pub_r001312_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = ((pub_r001312_9_1 * 2) + 8) & 63;
  int stage_v_4_2 = ((pub_r001312_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((stage_v_2_1 * 3) + pub_r001312_11_1) + 7) & 127;
  int stage_v_5_2 = (((stage_v_2_2 * 3) + pub_r001312_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001312_0_1 * 2) + 47) & 63;
  int stage_v_6_2 = ((pub_r001312_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001312_2_1 * 2) + 33) & 63;
  int stage_v_7_2 = ((pub_r001312_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001312_15_1 * 2) + 9) & 63;
  int stage_v_8_2 = ((pub_r001312_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001312_6_1 * 2) + 16) & 63;
  int stage_v_9_2 = ((pub_r001312_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001312_12_1 * 2) + 22) & 63;
  int stage_v_10_2 = ((pub_r001312_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001312_4_1 * 3) + pub_r001312_13_1) + 17) & 127;
  int stage_v_11_2 = (((sec_r001312_4_2 * 3) + pub_r001312_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((stage_v_1_1 * 3) + pub_r001312_7_1) + 13) & 127;
  int stage_v_12_2 = (((stage_v_1_2 * 3) + pub_r001312_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((sec_r001312_12_1 * 3) + pub_r001312_13_1) + 41) & 127;
  int stage_v_13_2 = (((sec_r001312_12_2 * 3) + pub_r001312_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((helper_flow_1_1 * 3) + pub_r001312_12_1) + 38) & 127;
  int stage_v_14_2 = (((helper_flow_1_2 * 3) + pub_r001312_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001312_0_1 * 2) + 45) & 63;
  int stage_v_15_2 = ((pub_r001312_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001312_13_1 * 3) + pub_r001312_15_1) + 31) & 127;
  int stage_v_16_2 = (((sec_r001312_13_2 * 3) + pub_r001312_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((sec_r001312_8_1 * 3) + pub_r001312_6_1) + 6) & 127;
  int stage_v_17_2 = (((sec_r001312_8_2 * 3) + pub_r001312_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001312_4_1 * 2) + 20) & 63;
  int stage_v_18_2 = ((pub_r001312_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001312_3_1 * 3) + pub_r001312_10_1) + 31) & 127;
  int stage_v_19_2 = (((sec_r001312_3_2 * 3) + pub_r001312_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001312_8_1 * 2) + 5) & 63;
  int stage_v_20_2 = ((pub_r001312_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001312_12_1 * 2) + 17) & 63;
  int stage_v_21_2 = ((pub_r001312_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001312_9_1 * 2) + 45) & 63;
  int stage_v_22_2 = ((pub_r001312_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((stage_v_16_1 * 3) + pub_r001312_14_1) + 20) & 127;
  int stage_v_23_2 = (((stage_v_16_2 * 3) + pub_r001312_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = ((pub_r001312_14_1 * 2) + 26) & 63;
  int stage_v_24_2 = ((pub_r001312_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001312_5_1 * 2) + 9) & 63;
  int stage_v_25_2 = ((pub_r001312_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((stage_v_16_1 * 3) + pub_r001312_11_1) + 6) & 127;
  int stage_v_26_2 = (((stage_v_16_2 * 3) + pub_r001312_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001312_2_1 * 2) + 44) & 63;
  int stage_v_27_2 = ((pub_r001312_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001312_12_1 * 2) + 47) & 63;
  int stage_v_28_2 = ((pub_r001312_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001312_3_1 * 2) + 24) & 63;
  int stage_v_29_2 = ((pub_r001312_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001312_14_1 * 3) + pub_r001312_4_1) + 28) & 127;
  int stage_v_30_2 = (((sec_r001312_14_2 * 3) + pub_r001312_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((sec_r001312_11_1 * 3) + pub_r001312_5_1) + 35) & 127;
  int stage_v_31_2 = (((sec_r001312_11_2 * 3) + pub_r001312_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((sec_r001312_16_1 * 3) + pub_r001312_15_1) + 7) & 127;
  int stage_v_32_2 = (((sec_r001312_16_2 * 3) + pub_r001312_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001312_17_1 * 3) + pub_r001312_10_1) + 18) & 127;
  int stage_v_33_2 = (((sec_r001312_17_2 * 3) + pub_r001312_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001312_13_1 * 2) + 31) & 63;
  int stage_v_34_2 = ((pub_r001312_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001312_4_1 * 2) + 33) & 63;
  int stage_v_35_2 = ((pub_r001312_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((stage_v_11_1 * 3) + pub_r001312_14_1) + 26) & 127;
  int stage_v_36_2 = (((stage_v_11_2 * 3) + pub_r001312_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001312_6_1 * 2) + 35) & 63;
  int stage_v_37_2 = ((pub_r001312_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((stage_v_30_1 * 3) + pub_r001312_8_1) + 40) & 127;
  int stage_v_38_2 = (((stage_v_30_2 * 3) + pub_r001312_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((sec_r001312_4_1 * 3) + pub_r001312_12_1) + 22) & 127;
  int stage_v_39_2 = (((sec_r001312_4_2 * 3) + pub_r001312_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = (((stage_v_31_1 * 3) + pub_r001312_10_1) + 43) & 127;
  int stage_v_40_2 = (((stage_v_31_2 * 3) + pub_r001312_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001312_13_1 * 2) + 40) & 63;
  int stage_v_41_2 = ((pub_r001312_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001312_7_1 * 2) + 5) & 63;
  int stage_v_42_2 = ((pub_r001312_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_1_1 * 3) + pub_r001312_5_1) + 8) & 127;
  int stage_v_43_2 = (((stage_v_1_2 * 3) + pub_r001312_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001312_10_1 * 2) + 12) & 63;
  int stage_v_44_2 = ((pub_r001312_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001312_14_1 * 2) + 11) & 63;
  int stage_v_45_2 = ((pub_r001312_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_13_1 * 3) + pub_r001312_14_1) + 11) & 127;
  int stage_v_46_2 = (((stage_v_13_2 * 3) + pub_r001312_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001312_13_1 * 2) + 41) & 63;
  int stage_v_47_2 = ((pub_r001312_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001312_4_1 * 2) + 50) & 63;
  int stage_v_48_2 = ((pub_r001312_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_38_1 * 3) + pub_r001312_0_1) + 12) & 127;
  int stage_v_49_2 = (((stage_v_38_2 * 3) + pub_r001312_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001312_0_1 * 2) + 32) & 63;
  int stage_v_50_2 = ((pub_r001312_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001312_0_1 * 2) + 8) & 63;
  int stage_v_51_2 = ((pub_r001312_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((sec_r001312_4_1 * 3) + pub_r001312_1_1) + 38) & 127;
  int stage_v_52_2 = (((sec_r001312_4_2 * 3) + pub_r001312_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001312_5_1 * 2) + 23) & 63;
  int stage_v_53_2 = ((pub_r001312_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001312_3_1 * 2) + 42) & 63;
  int stage_v_54_2 = ((pub_r001312_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001312_11_1 * 2) + 46) & 63;
  int stage_v_55_2 = ((pub_r001312_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001312_0_1 * 2) + 36) & 63;
  int stage_v_56_2 = ((pub_r001312_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001312_9_1 * 2) + 7) & 63;
  int stage_v_57_2 = ((pub_r001312_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_14_1 * 3) + pub_r001312_7_1) + 19) & 127;
  int stage_v_58_2 = (((stage_v_14_2 * 3) + pub_r001312_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001312_13_1 * 2) + 28) & 63;
  int stage_v_59_2 = ((pub_r001312_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001312_14_1 * 2) + 46) & 63;
  int stage_v_60_2 = ((pub_r001312_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_46_1 * 3) + pub_r001312_0_1) + 12) & 127;
  int stage_v_61_2 = (((stage_v_46_2 * 3) + pub_r001312_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001312_9_1 * 2) + 5) & 63;
  int stage_v_62_2 = ((pub_r001312_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001312_7_1 * 2) + 50) & 63;
  int stage_v_63_2 = ((pub_r001312_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001312_6_1 * 2) + 37) & 63;
  int stage_v_64_2 = ((pub_r001312_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001312_8_1 * 2) + 17) & 63;
  int stage_v_65_2 = ((pub_r001312_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_30_1 * 3) + pub_r001312_1_1) + 14) & 127;
  int stage_v_66_2 = (((stage_v_30_2 * 3) + pub_r001312_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = ((pub_r001312_11_1 * 2) + 9) & 63;
  int stage_v_67_2 = ((pub_r001312_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001312_10_1 * 2) + 31) & 63;
  int stage_v_68_2 = ((pub_r001312_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001312_5_1 * 2) + 5) & 63;
  int stage_v_69_2 = ((pub_r001312_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_31_1 * 3) + pub_r001312_10_1) + 31) & 127;
  int stage_v_70_2 = (((stage_v_31_2 * 3) + pub_r001312_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001312_1_1 * 2) + 46) & 63;
  int stage_v_71_2 = ((pub_r001312_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_3_1 * 3) + pub_r001312_13_1) + 40) & 127;
  int stage_v_72_2 = (((stage_v_3_2 * 3) + pub_r001312_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001312_4_1 * 2) + 32) & 63;
  int stage_v_73_2 = ((pub_r001312_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001312_15_1 * 2) + 41) & 63;
  int stage_v_74_2 = ((pub_r001312_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001312_11_1 * 2) + 29) & 63;
  int stage_v_75_2 = ((pub_r001312_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001312_15_1 * 2) + 12) & 63;
  int stage_v_76_2 = ((pub_r001312_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001312_3_1 * 2) + 48) & 63;
  int stage_v_77_2 = ((pub_r001312_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001312_12_1 * 2) + 5) & 63;
  int stage_v_78_2 = ((pub_r001312_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001312_8_1 * 2) + 15) & 63;
  int stage_v_79_2 = ((pub_r001312_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001312_7_1 * 2) + 37) & 63;
  int stage_v_80_2 = ((pub_r001312_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001312_8_1 * 2) + 50) & 63;
  int stage_v_81_2 = ((pub_r001312_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001312_9_1 * 2) + 40) & 63;
  int stage_v_82_2 = ((pub_r001312_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((stage_v_66_1 * 3) + pub_r001312_12_1) + 41) & 127;
  int stage_v_83_2 = (((stage_v_66_2 * 3) + pub_r001312_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001312_7_1 * 2) + 29) & 63;
  int stage_v_84_2 = ((pub_r001312_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001312_7_1 * 2) + 29) & 63;
  int stage_v_85_2 = ((pub_r001312_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001312_0_1 * 2) + 38) & 63;
  int stage_v_86_2 = ((pub_r001312_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001312_0_1 * 2) + 36) & 63;
  int stage_v_87_2 = ((pub_r001312_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001312_7_1 * 2) + 23) & 63;
  int stage_v_88_2 = ((pub_r001312_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001312_6_1 * 2) + 36) & 63;
  int stage_v_89_2 = ((pub_r001312_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001312_9_1 * 2) + 11) & 63;
  int stage_v_90_2 = ((pub_r001312_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_72_1 * 3) + pub_r001312_4_1) + 14) & 127;
  int stage_v_91_2 = (((stage_v_72_2 * 3) + pub_r001312_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001312_0_1 * 2) + 13) & 63;
  int stage_v_92_2 = ((pub_r001312_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001312_9_1 * 2) + 10) & 63;
  int stage_v_93_2 = ((pub_r001312_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001312_9_1 * 2) + 42) & 63;
  int stage_v_94_2 = ((pub_r001312_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_70_1 * 3) + pub_r001312_15_1) + 3) & 127;
  int stage_v_95_2 = (((stage_v_70_2 * 3) + pub_r001312_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001312_12_1 * 2) + 49) & 63;
  int stage_v_96_2 = ((pub_r001312_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001312_1_1 * 2) + 48) & 63;
  int stage_v_97_2 = ((pub_r001312_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001312_8_1 * 2) + 42) & 63;
  int stage_v_98_2 = ((pub_r001312_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001312_15_1 * 2) + 23) & 63;
  int stage_v_99_2 = ((pub_r001312_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001312_4_1 * 2) + 20) & 63;
  int stage_v_100_2 = ((pub_r001312_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001312_3_1 * 2) + 46) & 63;
  int stage_v_101_2 = ((pub_r001312_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001312_2_1 * 2) + 32) & 63;
  int stage_v_102_2 = ((pub_r001312_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001312_12_1 * 2) + 34) & 63;
  int stage_v_103_2 = ((pub_r001312_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001312_13_1 * 2) + 26) & 63;
  int stage_v_104_2 = ((pub_r001312_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_83_1 * 3) + pub_r001312_12_1) + 12) & 127;
  int stage_v_105_2 = (((stage_v_83_2 * 3) + pub_r001312_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001312_5_1 * 2) + 12) & 63;
  int stage_v_106_2 = ((pub_r001312_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001312_12_1 * 2) + 19) & 63;
  int stage_v_107_2 = ((pub_r001312_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001312_1_1 * 2) + 22) & 63;
  int stage_v_108_2 = ((pub_r001312_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001312_2_1 * 2) + 48) & 63;
  int stage_v_109_2 = ((pub_r001312_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001312_5_1 * 2) + 38) & 63;
  int stage_v_110_2 = ((pub_r001312_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((sec_r001312_11_1 * 3) + pub_r001312_3_1) + 36) & 127;
  int stage_v_111_2 = (((sec_r001312_11_2 * 3) + pub_r001312_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = (((sec_r001312_15_1 * 3) + pub_r001312_9_1) + 44) & 127;
  int stage_v_112_2 = (((sec_r001312_15_2 * 3) + pub_r001312_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001312_14_1 * 2) + 27) & 63;
  int stage_v_113_2 = ((pub_r001312_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_31_1 * 3) + pub_r001312_15_1) + 30) & 127;
  int stage_v_114_2 = (((stage_v_31_2 * 3) + pub_r001312_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001312_6_1 * 2) + 15) & 63;
  int stage_v_115_2 = ((pub_r001312_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_16_1 * 3) + pub_r001312_9_1) + 40) & 127;
  int stage_v_116_2 = (((stage_v_16_2 * 3) + pub_r001312_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001312_8_1 * 2) + 39) & 63;
  int stage_v_117_2 = ((pub_r001312_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001312_2_1 * 2) + 24) & 63;
  int stage_v_118_2 = ((pub_r001312_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_83_1 * 3) + pub_r001312_12_1) + 29) & 127;
  int stage_v_119_2 = (((stage_v_83_2 * 3) + pub_r001312_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((stage_v_66_1 * 3) + pub_r001312_12_1) + 23) & 127;
  int stage_v_120_2 = (((stage_v_66_2 * 3) + pub_r001312_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_39_1 * 3) + pub_r001312_7_1) + 22) & 127;
  int stage_v_121_2 = (((stage_v_39_2 * 3) + pub_r001312_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((sec_r001312_10_1 * 3) + pub_r001312_11_1) + 7) & 127;
  int stage_v_122_2 = (((sec_r001312_10_2 * 3) + pub_r001312_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((stage_v_3_1 * 3) + pub_r001312_7_1) + 13) & 127;
  int stage_v_123_2 = (((stage_v_3_2 * 3) + pub_r001312_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_26_1 * 3) + pub_r001312_14_1) + 21) & 127;
  int stage_v_124_2 = (((stage_v_26_2 * 3) + pub_r001312_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001312_0_1 * 2) + 23) & 63;
  int stage_v_125_2 = ((pub_r001312_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_72_1 * 3) + pub_r001312_6_1) + 19) & 127;
  int stage_v_126_2 = (((stage_v_72_2 * 3) + pub_r001312_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((sec_r001312_0_1 * 3) + pub_r001312_7_1) + 8) & 127;
  int stage_v_127_2 = (((sec_r001312_0_2 * 3) + pub_r001312_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_105_1 * 3) + pub_r001312_5_1) + 8) & 127;
  int stage_v_128_2 = (((stage_v_105_2 * 3) + pub_r001312_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = ((pub_r001312_3_1 * 2) + 48) & 63;
  int stage_v_129_2 = ((pub_r001312_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001312_8_1 * 2) + 35) & 63;
  int stage_v_130_2 = ((pub_r001312_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001312_6_1 * 2) + 23) & 63;
  int stage_v_131_2 = ((pub_r001312_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_126_1 * 3) + pub_r001312_1_1) + 11) & 127;
  int stage_v_132_2 = (((stage_v_126_2 * 3) + pub_r001312_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = ((pub_r001312_10_1 * 2) + 45) & 63;
  int stage_v_133_2 = ((pub_r001312_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001312_2_1 * 2) + 42) & 63;
  int stage_v_134_2 = ((pub_r001312_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001312_7_1 * 2) + 37) & 63;
  int stage_v_135_2 = ((pub_r001312_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((sec_r001312_3_1 * 3) + pub_r001312_4_1) + 43) & 127;
  int stage_v_136_2 = (((sec_r001312_3_2 * 3) + pub_r001312_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001312_7_1 * 2) + 13) & 63;
  int stage_v_137_2 = ((pub_r001312_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001312_1_1 * 2) + 22) & 63;
  int stage_v_138_2 = ((pub_r001312_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((sec_r001312_14_1 * 3) + pub_r001312_12_1) + 19) & 127;
  int stage_v_139_2 = (((sec_r001312_14_2 * 3) + pub_r001312_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_2_1 * 3) + pub_r001312_15_1) + 42) & 127;
  int stage_v_140_2 = (((stage_v_2_2 * 3) + pub_r001312_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001312_6_1 * 2) + 22) & 63;
  int stage_v_141_2 = ((pub_r001312_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((helper_flow_1_1 * 3) + pub_r001312_10_1) + 31) & 127;
  int stage_v_142_2 = (((helper_flow_1_2 * 3) + pub_r001312_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001312_13_1 * 2) + 17) & 63;
  int stage_v_143_2 = ((pub_r001312_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((sec_r001312_10_1 * 3) + pub_r001312_7_1) + 8) & 127;
  int stage_v_144_2 = (((sec_r001312_10_2 * 3) + pub_r001312_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_66_1 * 3) + pub_r001312_3_1) + 36) & 127;
  int stage_v_145_2 = (((stage_v_66_2 * 3) + pub_r001312_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001312_15_1 * 2) + 9) & 63;
  int stage_v_146_2 = ((pub_r001312_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001312_2_1 * 2) + 10) & 63;
  int stage_v_147_2 = ((pub_r001312_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_114_1 * 3) + pub_r001312_15_1) + 42) & 127;
  int stage_v_148_2 = (((stage_v_114_2 * 3) + pub_r001312_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_43_1 * 3) + pub_r001312_0_1) + 11) & 127;
  int stage_v_149_2 = (((stage_v_43_2 * 3) + pub_r001312_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001312_6_1 * 2) + 26) & 63;
  int stage_v_150_2 = ((pub_r001312_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((sec_r001312_8_1 * 3) + pub_r001312_11_1) + 16) & 127;
  int stage_v_151_2 = (((sec_r001312_8_2 * 3) + pub_r001312_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_12_1 * 3) + pub_r001312_6_1) + 23) & 127;
  int stage_v_152_2 = (((stage_v_12_2 * 3) + pub_r001312_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001312_0_1 * 2) + 34) & 63;
  int stage_v_153_2 = ((pub_r001312_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_32_1 * 3) + pub_r001312_15_1) + 25) & 127;
  int stage_v_154_2 = (((stage_v_32_2 * 3) + pub_r001312_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001312_0_1 * 2) + 32) & 63;
  int stage_v_155_2 = ((pub_r001312_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001312_5_1 * 2) + 38) & 63;
  int stage_v_156_2 = ((pub_r001312_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((stage_v_36_1 * 3) + pub_r001312_4_1) + 7) & 127;
  int stage_v_157_2 = (((stage_v_36_2 * 3) + pub_r001312_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001312_0_1 * 2) + 6) & 63;
  int stage_v_158_2 = ((pub_r001312_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001312_9_1 * 2) + 38) & 63;
  int stage_v_159_2 = ((pub_r001312_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001312_12_1 * 2) + 43) & 63;
  int stage_v_160_2 = ((pub_r001312_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_26_1 * 3) + pub_r001312_4_1) + 25) & 127;
  int stage_v_161_2 = (((stage_v_26_2 * 3) + pub_r001312_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((sec_r001312_15_1 * 3) + pub_r001312_8_1) + 7) & 127;
  int stage_v_162_2 = (((sec_r001312_15_2 * 3) + pub_r001312_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001312_0_1 * 2) + 17) & 63;
  int stage_v_163_2 = ((pub_r001312_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001312_1_1 * 2) + 34) & 63;
  int stage_v_164_2 = ((pub_r001312_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_120_1 * 3) + pub_r001312_6_1) + 9) & 127;
  int stage_v_165_2 = (((stage_v_120_2 * 3) + pub_r001312_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001312_2_1 * 2) + 42) & 63;
  int stage_v_166_2 = ((pub_r001312_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001312_13_1 * 2) + 11) & 63;
  int stage_v_167_2 = ((pub_r001312_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001312_9_1 * 2) + 5) & 63;
  int stage_v_168_2 = ((pub_r001312_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_154_1 * 3) + pub_r001312_2_1) + 12) & 127;
  int stage_v_169_2 = (((stage_v_154_2 * 3) + pub_r001312_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_5_1 * 3) + pub_r001312_5_1) + 39) & 127;
  int stage_v_170_2 = (((stage_v_5_2 * 3) + pub_r001312_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((stage_v_126_1 * 3) + pub_r001312_14_1) + 29) & 127;
  int stage_v_171_2 = (((stage_v_126_2 * 3) + pub_r001312_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = ((pub_r001312_0_1 * 2) + 11) & 63;
  int stage_v_172_2 = ((pub_r001312_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001312_0_1 * 2) + 28) & 63;
  int stage_v_173_2 = ((pub_r001312_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_13_1 * 3) + pub_r001312_10_1) + 9) & 127;
  int stage_v_174_2 = (((stage_v_13_2 * 3) + pub_r001312_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001312_10_1 * 2) + 9) & 63;
  int stage_v_175_2 = ((pub_r001312_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001312_8_1 * 2) + 17) & 63;
  int stage_v_176_2 = ((pub_r001312_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001312_0_1 * 2) + 20) & 63;
  int stage_v_177_2 = ((pub_r001312_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001312_14_1 * 2) + 14) & 63;
  int stage_v_178_2 = ((pub_r001312_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001312_0_1 * 2) + 50) & 63;
  int stage_v_179_2 = ((pub_r001312_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_3_1 * 3) + pub_r001312_2_1) + 39) & 127;
  int stage_v_180_2 = (((stage_v_3_2 * 3) + pub_r001312_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001312_10_1 * 2) + 22) & 63;
  int stage_v_181_2 = ((pub_r001312_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_95_1 * 3) + pub_r001312_11_1) + 41) & 127;
  int stage_v_182_2 = (((stage_v_95_2 * 3) + pub_r001312_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001312_15_1 * 2) + 20) & 63;
  int stage_v_183_2 = ((pub_r001312_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001312_10_1 * 2) + 46) & 63;
  int stage_v_184_2 = ((pub_r001312_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_83_1 * 3) + pub_r001312_6_1) + 43) & 127;
  int stage_v_185_2 = (((stage_v_83_2 * 3) + pub_r001312_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001312_3_1 * 2) + 7) & 63;
  int stage_v_186_2 = ((pub_r001312_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001312_1_1 * 2) + 6) & 63;
  int stage_v_187_2 = ((pub_r001312_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001312_12_1 * 2) + 9) & 63;
  int stage_v_188_2 = ((pub_r001312_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001312_1_1 * 2) + 23) & 63;
  int stage_v_189_2 = ((pub_r001312_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001312_2_1 * 2) + 46) & 63;
  int stage_v_190_2 = ((pub_r001312_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((sec_r001312_12_1 * 3) + pub_r001312_6_1) + 25) & 127;
  int stage_v_191_2 = (((sec_r001312_12_2 * 3) + pub_r001312_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001312_10_1 * 2) + 18) & 63;
  int stage_v_192_2 = ((pub_r001312_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001312_15_1 * 2) + 48) & 63;
  int stage_v_193_2 = ((pub_r001312_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((sec_r001312_16_1 * 3) + pub_r001312_12_1) + 19) & 127;
  int stage_v_194_2 = (((sec_r001312_16_2 * 3) + pub_r001312_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_12_1 * 3) + pub_r001312_0_1) + 3) & 127;
  int stage_v_195_2 = (((stage_v_12_2 * 3) + pub_r001312_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((stage_v_111_1 * 3) + pub_r001312_8_1) + 19) & 127;
  int stage_v_196_2 = (((stage_v_111_2 * 3) + pub_r001312_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001312_9_1 * 2) + 18) & 63;
  int stage_v_197_2 = ((pub_r001312_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_83_1 * 3) + pub_r001312_13_1) + 6) & 127;
  int stage_v_198_2 = (((stage_v_83_2 * 3) + pub_r001312_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001312_1_1 * 2) + 7) & 63;
  int stage_v_199_2 = ((pub_r001312_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_196_1 * 3) + pub_r001312_4_1) + 35) & 127;
  int stage_v_200_2 = (((stage_v_196_2 * 3) + pub_r001312_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001312_6_1 * 2) + 42) & 63;
  int stage_v_201_2 = ((pub_r001312_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_119_1 * 3) + pub_r001312_6_1) + 45) & 127;
  int stage_v_202_2 = (((stage_v_119_2 * 3) + pub_r001312_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001312_15_1 * 2) + 24) & 63;
  int stage_v_203_2 = ((pub_r001312_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((sec_r001312_2_1 * 3) + pub_r001312_7_1) + 38) & 127;
  int stage_v_204_2 = (((sec_r001312_2_2 * 3) + pub_r001312_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001312_9_1 * 2) + 30) & 63;
  int stage_v_205_2 = ((pub_r001312_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((stage_v_83_1 * 3) + pub_r001312_9_1) + 5) & 127;
  int stage_v_206_2 = (((stage_v_83_2 * 3) + pub_r001312_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001312_5_1 * 2) + 30) & 63;
  int stage_v_207_2 = ((pub_r001312_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001312_1_1 * 2) + 41) & 63;
  int stage_v_208_2 = ((pub_r001312_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001312_15_1 * 2) + 47) & 63;
  int stage_v_209_2 = ((pub_r001312_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_49_1 * 3) + pub_r001312_15_1) + 10) & 127;
  int stage_v_210_2 = (((stage_v_49_2 * 3) + pub_r001312_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = ((pub_r001312_11_1 * 2) + 43) & 63;
  int stage_v_211_2 = ((pub_r001312_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_36_1 * 3) + pub_r001312_14_1) + 12) & 127;
  int stage_v_212_2 = (((stage_v_36_2 * 3) + pub_r001312_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001312_1_1 * 2) + 36) & 63;
  int stage_v_213_2 = ((pub_r001312_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((sec_r001312_11_1 * 3) + pub_r001312_2_1) + 38) & 127;
  int stage_v_214_2 = (((sec_r001312_11_2 * 3) + pub_r001312_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_58_1 * 3) + pub_r001312_6_1) + 29) & 127;
  int stage_v_215_2 = (((stage_v_58_2 * 3) + pub_r001312_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001312_5_1 * 2) + 21) & 63;
  int stage_v_216_2 = ((pub_r001312_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001312_4_1 * 2) + 21) & 63;
  int stage_v_217_2 = ((pub_r001312_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_154_1 * 3) + pub_r001312_9_1) + 27) & 127;
  int stage_v_218_2 = (((stage_v_154_2 * 3) + pub_r001312_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_194_1 * 3) + pub_r001312_0_1) + 39) & 127;
  int stage_v_219_2 = (((stage_v_194_2 * 3) + pub_r001312_0_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_3_1 * 3) + pub_r001312_4_1) + 5) & 127;
  int stage_v_220_2 = (((stage_v_3_2 * 3) + pub_r001312_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((helper_flow_0_1 * 3) + pub_r001312_8_1) + 41) & 127;
  int stage_v_221_2 = (((helper_flow_0_2 * 3) + pub_r001312_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((stage_v_182_1 * 3) + pub_r001312_13_1) + 9) & 127;
  int stage_v_222_2 = (((stage_v_182_2 * 3) + pub_r001312_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001312_9_1 * 2) + 34) & 63;
  int stage_v_223_2 = ((pub_r001312_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001312_3_1 * 2) + 23) & 63;
  int stage_v_224_2 = ((pub_r001312_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001312_0_1 * 2) + 32) & 63;
  int stage_v_225_2 = ((pub_r001312_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001312_10_1 * 2) + 19) & 63;
  int stage_v_226_2 = ((pub_r001312_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001312_12_1 * 2) + 35) & 63;
  int stage_v_227_2 = ((pub_r001312_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((helper_flow_1_1 * 3) + pub_r001312_0_1) + 35) & 127;
  int stage_v_228_2 = (((helper_flow_1_2 * 3) + pub_r001312_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001312_9_1 * 2) + 25) & 63;
  int stage_v_229_2 = ((pub_r001312_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001312_9_1 * 2) + 8) & 63;
  int stage_v_230_2 = ((pub_r001312_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_70_1 * 3) + pub_r001312_9_1) + 8) & 127;
  int stage_v_231_2 = (((stage_v_70_2 * 3) + pub_r001312_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001312_0_1 * 2) + 11) & 63;
  int stage_v_232_2 = ((pub_r001312_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001312_15_1 * 2) + 11) & 63;
  int stage_v_233_2 = ((pub_r001312_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001312_2_1 * 2) + 28) & 63;
  int stage_v_234_2 = ((pub_r001312_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001312_14_1 * 2) + 12) & 63;
  int stage_v_235_2 = ((pub_r001312_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((sec_r001312_1_1 * 3) + pub_r001312_10_1) + 17) & 127;
  int stage_v_236_2 = (((sec_r001312_1_2 * 3) + pub_r001312_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001312_1_1 * 2) + 15) & 63;
  int stage_v_237_2 = ((pub_r001312_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001312_14_1 * 2) + 34) & 63;
  int stage_v_238_2 = ((pub_r001312_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001312_7_1 * 2) + 10) & 63;
  int stage_v_239_2 = ((pub_r001312_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_218_1 * 3) + pub_r001312_7_1) + 20) & 127;
  int stage_v_240_2 = (((stage_v_218_2 * 3) + pub_r001312_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001312_9_1 * 2) + 46) & 63;
  int stage_v_241_2 = ((pub_r001312_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((stage_v_43_1 * 3) + pub_r001312_11_1) + 8) & 127;
  int stage_v_242_2 = (((stage_v_43_2 * 3) + pub_r001312_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001312_13_1 * 2) + 11) & 63;
  int stage_v_243_2 = ((pub_r001312_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001312_10_1 * 2) + 7) & 63;
  int stage_v_244_2 = ((pub_r001312_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001312_6_1 * 2) + 5) & 63;
  int stage_v_245_2 = ((pub_r001312_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001312_10_1 * 2) + 5) & 63;
  int stage_v_246_2 = ((pub_r001312_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001312_6_1 * 2) + 40) & 63;
  int stage_v_247_2 = ((pub_r001312_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001312_8_1 * 2) + 17) & 63;
  int stage_v_248_2 = ((pub_r001312_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((sec_r001312_16_1 * 3) + pub_r001312_8_1) + 31) & 127;
  int stage_v_249_2 = (((sec_r001312_16_2 * 3) + pub_r001312_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_142_1 * 3) + pub_r001312_14_1) + 31) & 127;
  int stage_v_250_2 = (((stage_v_142_2 * 3) + pub_r001312_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_242_1 * 3) + pub_r001312_10_1) + 26) & 127;
  int stage_v_251_2 = (((stage_v_242_2 * 3) + pub_r001312_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_95_1 * 3) + pub_r001312_0_1) + 31) & 127;
  int stage_v_252_2 = (((stage_v_95_2 * 3) + pub_r001312_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001312_15_1 * 2) + 8) & 63;
  int stage_v_253_2 = ((pub_r001312_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((sec_r001312_14_1 * 3) + pub_r001312_9_1) + 28) & 127;
  int stage_v_254_2 = (((sec_r001312_14_2 * 3) + pub_r001312_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_33_1 * 3) + pub_r001312_3_1) + 41) & 127;
  int stage_v_255_2 = (((stage_v_33_2 * 3) + pub_r001312_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001312_0_1 * 2) + 15) & 63;
  int stage_v_256_2 = ((pub_r001312_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_157_1 * 3) + pub_r001312_14_1) + 17) & 127;
  int stage_v_257_2 = (((stage_v_157_2 * 3) + pub_r001312_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((sec_r001312_4_1 * 3) + pub_r001312_6_1) + 39) & 127;
  int stage_v_258_2 = (((sec_r001312_4_2 * 3) + pub_r001312_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001312_2_1 * 2) + 16) & 63;
  int stage_v_259_2 = ((pub_r001312_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((stage_v_195_1 * 3) + pub_r001312_9_1) + 25) & 127;
  int stage_v_260_2 = (((stage_v_195_2 * 3) + pub_r001312_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = ((pub_r001312_15_1 * 2) + 42) & 63;
  int stage_v_261_2 = ((pub_r001312_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001312_4_1 * 2) + 14) & 63;
  int stage_v_262_2 = ((pub_r001312_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001312_9_1 * 2) + 10) & 63;
  int stage_v_263_2 = ((pub_r001312_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_49_1 * 3) + pub_r001312_8_1) + 17) & 127;
  int stage_v_264_2 = (((stage_v_49_2 * 3) + pub_r001312_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_91_1 * 3) + pub_r001312_15_1) + 32) & 127;
  int stage_v_265_2 = (((stage_v_91_2 * 3) + pub_r001312_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_258_1 * 3) + pub_r001312_2_1) + 41) & 127;
  int stage_v_266_2 = (((stage_v_258_2 * 3) + pub_r001312_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((sec_r001312_7_1 * 3) + pub_r001312_6_1) + 26) & 127;
  int stage_v_267_2 = (((sec_r001312_7_2 * 3) + pub_r001312_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_43_1 * 3) + pub_r001312_15_1) + 14) & 127;
  int stage_v_268_2 = (((stage_v_43_2 * 3) + pub_r001312_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_58_1 * 3) + pub_r001312_15_1) + 7) & 127;
  int stage_v_269_2 = (((stage_v_58_2 * 3) + pub_r001312_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001312_10_1 * 2) + 31) & 63;
  int stage_v_270_2 = ((pub_r001312_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((sec_r001312_10_1 * 3) + pub_r001312_7_1) + 14) & 127;
  int stage_v_271_2 = (((sec_r001312_10_2 * 3) + pub_r001312_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((stage_v_161_1 * 3) + pub_r001312_11_1) + 12) & 127;
  int stage_v_272_2 = (((stage_v_161_2 * 3) + pub_r001312_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_116_1 * 3) + pub_r001312_5_1) + 3) & 127;
  int stage_v_273_2 = (((stage_v_116_2 * 3) + pub_r001312_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((helper_flow_2_1 * 3) + pub_r001312_2_1) + 42) & 127;
  int stage_v_274_2 = (((helper_flow_2_2 * 3) + pub_r001312_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = ((pub_r001312_4_1 * 2) + 25) & 63;
  int stage_v_275_2 = ((pub_r001312_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((sec_r001312_3_1 * 3) + pub_r001312_14_1) + 32) & 127;
  int stage_v_276_2 = (((sec_r001312_3_2 * 3) + pub_r001312_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_219_1 * 3) + pub_r001312_7_1) + 35) & 127;
  int stage_v_277_2 = (((stage_v_219_2 * 3) + pub_r001312_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001312_4_1 * 2) + 20) & 63;
  int stage_v_278_2 = ((pub_r001312_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001312_4_1 * 2) + 44) & 63;
  int stage_v_279_2 = ((pub_r001312_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001312_6_1 * 2) + 28) & 63;
  int stage_v_280_2 = ((pub_r001312_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001312_4_1 * 2) + 23) & 63;
  int stage_v_281_2 = ((pub_r001312_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((sec_r001312_7_1 * 3) + pub_r001312_4_1) + 37) & 127;
  int stage_v_282_2 = (((sec_r001312_7_2 * 3) + pub_r001312_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((stage_v_198_1 * 3) + pub_r001312_6_1) + 45) & 127;
  int stage_v_283_2 = (((stage_v_198_2 * 3) + pub_r001312_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = ((pub_r001312_7_1 * 2) + 5) & 63;
  int stage_v_284_2 = ((pub_r001312_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001312_9_1 * 2) + 37) & 63;
  int stage_v_285_2 = ((pub_r001312_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001312_14_1 * 2) + 23) & 63;
  int stage_v_286_2 = ((pub_r001312_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001312_3_1 * 2) + 8) & 63;
  int stage_v_287_2 = ((pub_r001312_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = (((stage_v_114_1 * 3) + pub_r001312_0_1) + 6) & 127;
  int stage_v_288_2 = (((stage_v_114_2 * 3) + pub_r001312_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001312_8_1 * 2) + 20) & 63;
  int stage_v_289_2 = ((pub_r001312_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = (((stage_v_228_1 * 3) + pub_r001312_7_1) + 34) & 127;
  int stage_v_290_2 = (((stage_v_228_2 * 3) + pub_r001312_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001312_14_1 * 2) + 30) & 63;
  int stage_v_291_2 = ((pub_r001312_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_36_1 * 3) + pub_r001312_11_1) + 9) & 127;
  int stage_v_292_2 = (((stage_v_36_2 * 3) + pub_r001312_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001312_7_1 * 2) + 15) & 63;
  int stage_v_293_2 = ((pub_r001312_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_195_1 * 3) + pub_r001312_3_1) + 4) & 127;
  int stage_v_294_2 = (((stage_v_195_2 * 3) + pub_r001312_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_19_1 * 3) + pub_r001312_9_1) + 38) & 127;
  int stage_v_295_2 = (((stage_v_19_2 * 3) + pub_r001312_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001312_2_1 * 2) + 18) & 63;
  int stage_v_296_2 = ((pub_r001312_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001312_13_1 * 2) + 31) & 63;
  int stage_v_297_2 = ((pub_r001312_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001312_7_1 * 2) + 25) & 63;
  int stage_v_298_2 = ((pub_r001312_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = (((sec_r001312_8_1 * 3) + pub_r001312_7_1) + 14) & 127;
  int stage_v_299_2 = (((sec_r001312_8_2 * 3) + pub_r001312_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = (((stage_v_144_1 * 3) + pub_r001312_1_1) + 43) & 127;
  int stage_v_300_2 = (((stage_v_144_2 * 3) + pub_r001312_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_31_1 * 3) + pub_r001312_8_1) + 25) & 127;
  int stage_v_301_2 = (((stage_v_31_2 * 3) + pub_r001312_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001312_9_1 * 2) + 18) & 63;
  int stage_v_302_2 = ((pub_r001312_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001312_1_1 * 2) + 26) & 63;
  int stage_v_303_2 = ((pub_r001312_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001312_15_1 * 2) + 47) & 63;
  int stage_v_304_2 = ((pub_r001312_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001312_0_1 * 2) + 17) & 63;
  int stage_v_305_2 = ((pub_r001312_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001312_3_1 * 2) + 44) & 63;
  int stage_v_306_2 = ((pub_r001312_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001312_9_1 * 2) + 16) & 63;
  int stage_v_307_2 = ((pub_r001312_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001312_5_1 * 2) + 47) & 63;
  int stage_v_308_2 = ((pub_r001312_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001312_12_1 * 2) + 18) & 63;
  int stage_v_309_2 = ((pub_r001312_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001312_9_1 * 2) + 30) & 63;
  int stage_v_310_2 = ((pub_r001312_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_258_1 * 3) + pub_r001312_7_1) + 44) & 127;
  int stage_v_311_2 = (((stage_v_258_2 * 3) + pub_r001312_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001312_10_1 * 2) + 50) & 63;
  int stage_v_312_2 = ((pub_r001312_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001312_8_1 * 2) + 48) & 63;
  int stage_v_313_2 = ((pub_r001312_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001312_1_1 * 2) + 21) & 63;
  int stage_v_314_2 = ((pub_r001312_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001312_8_1 * 2) + 23) & 63;
  int stage_v_315_2 = ((pub_r001312_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001312_15_1 * 2) + 47) & 63;
  int stage_v_316_2 = ((pub_r001312_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001312_9_1 * 2) + 38) & 63;
  int stage_v_317_2 = ((pub_r001312_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001312_2_1 * 2) + 25) & 63;
  int stage_v_318_2 = ((pub_r001312_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001312_6_1 * 2) + 7) & 63;
  int stage_v_319_2 = ((pub_r001312_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001312_7_1 * 2) + 33) & 63;
  int stage_v_320_2 = ((pub_r001312_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001312_11_1 * 2) + 27) & 63;
  int stage_v_321_2 = ((pub_r001312_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001312_9_1 * 2) + 44) & 63;
  int stage_v_322_2 = ((pub_r001312_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001312_10_1 * 2) + 23) & 63;
  int stage_v_323_2 = ((pub_r001312_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001312_14_1 * 2) + 40) & 63;
  int stage_v_324_2 = ((pub_r001312_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((stage_v_148_1 * 3) + pub_r001312_1_1) + 19) & 127;
  int stage_v_325_2 = (((stage_v_148_2 * 3) + pub_r001312_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001312_15_1 * 2) + 16) & 63;
  int stage_v_326_2 = ((pub_r001312_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = (((stage_v_91_1 * 3) + pub_r001312_0_1) + 23) & 127;
  int stage_v_327_2 = (((stage_v_91_2 * 3) + pub_r001312_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = ((pub_r001312_4_1 * 2) + 41) & 63;
  int stage_v_328_2 = ((pub_r001312_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001312_1_1 * 2) + 38) & 63;
  int stage_v_329_2 = ((pub_r001312_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = (((stage_v_170_1 * 3) + pub_r001312_8_1) + 24) & 127;
  int stage_v_330_2 = (((stage_v_170_2 * 3) + pub_r001312_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001312_1_1 * 2) + 42) & 63;
  int stage_v_331_2 = ((pub_r001312_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001312_2_1 * 2) + 39) & 63;
  int stage_v_332_2 = ((pub_r001312_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001312_5_1 * 2) + 31) & 63;
  int stage_v_333_2 = ((pub_r001312_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001312_10_1 * 2) + 46) & 63;
  int stage_v_334_2 = ((pub_r001312_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((stage_v_38_1 * 3) + pub_r001312_3_1) + 31) & 127;
  int stage_v_335_2 = (((stage_v_38_2 * 3) + pub_r001312_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = ((pub_r001312_5_1 * 2) + 9) & 63;
  int stage_v_336_2 = ((pub_r001312_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_152_1 * 3) + pub_r001312_5_1) + 7) & 127;
  int stage_v_337_2 = (((stage_v_152_2 * 3) + pub_r001312_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_3_1 * 3) + pub_r001312_7_1) + 16) & 127;
  int stage_v_338_2 = (((stage_v_3_2 * 3) + pub_r001312_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_12_1 * 3) + pub_r001312_11_1) + 20) & 127;
  int stage_v_339_2 = (((stage_v_12_2 * 3) + pub_r001312_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001312_5_1 * 2) + 38) & 63;
  int stage_v_340_2 = ((pub_r001312_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001312_6_1 * 2) + 45) & 63;
  int stage_v_341_2 = ((pub_r001312_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((stage_v_242_1 * 3) + pub_r001312_3_1) + 13) & 127;
  int stage_v_342_2 = (((stage_v_242_2 * 3) + pub_r001312_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_40_1 * 3) + pub_r001312_3_1) + 4) & 127;
  int stage_v_343_2 = (((stage_v_40_2 * 3) + pub_r001312_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = ((pub_r001312_9_1 * 2) + 11) & 63;
  int stage_v_344_2 = ((pub_r001312_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((helper_flow_0_1 * 3) + pub_r001312_8_1) + 5) & 127;
  int stage_v_345_2 = (((helper_flow_0_2 * 3) + pub_r001312_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001312_10_1 * 2) + 48) & 63;
  int stage_v_346_2 = ((pub_r001312_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001312_11_1 * 2) + 9) & 63;
  int stage_v_347_2 = ((pub_r001312_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001312_13_1 * 2) + 48) & 63;
  int stage_v_348_2 = ((pub_r001312_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((sec_r001312_8_1 * 3) + pub_r001312_13_1) + 3) & 127;
  int stage_v_349_2 = (((sec_r001312_8_2 * 3) + pub_r001312_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001312_9_1 * 2) + 5) & 63;
  int stage_v_350_2 = ((pub_r001312_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = (((stage_v_123_1 * 3) + pub_r001312_4_1) + 44) & 127;
  int stage_v_351_2 = (((stage_v_123_2 * 3) + pub_r001312_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001312_14_1 * 2) + 11) & 63;
  int stage_v_352_2 = ((pub_r001312_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_218_1 * 3) + pub_r001312_6_1) + 4) & 127;
  int stage_v_353_2 = (((stage_v_218_2 * 3) + pub_r001312_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001312_15_1 * 2) + 48) & 63;
  int stage_v_354_2 = ((pub_r001312_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001312_12_1 * 2) + 50) & 63;
  int stage_v_355_2 = ((pub_r001312_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001312_15_1 * 2) + 39) & 63;
  int stage_v_356_2 = ((pub_r001312_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_182_1 * 3) + pub_r001312_5_1) + 8) & 127;
  int stage_v_357_2 = (((stage_v_182_2 * 3) + pub_r001312_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_128_1 * 3) + pub_r001312_4_1) + 7) & 127;
  int stage_v_358_2 = (((stage_v_128_2 * 3) + pub_r001312_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001312_3_1 * 2) + 28) & 63;
  int stage_v_359_2 = ((pub_r001312_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001312_9_1 * 2) + 38) & 63;
  int stage_v_360_2 = ((pub_r001312_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001312_14_1 * 2) + 44) & 63;
  int stage_v_361_2 = ((pub_r001312_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001312_7_1 * 2) + 49) & 63;
  int stage_v_362_2 = ((pub_r001312_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_272_1 * 3) + pub_r001312_0_1) + 40) & 127;
  int stage_v_363_2 = (((stage_v_272_2 * 3) + pub_r001312_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = ((pub_r001312_4_1 * 2) + 6) & 63;
  int stage_v_364_2 = ((pub_r001312_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001312_2_1 * 2) + 11) & 63;
  int stage_v_365_2 = ((pub_r001312_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((stage_v_242_1 * 3) + pub_r001312_13_1) + 11) & 127;
  int stage_v_366_2 = (((stage_v_242_2 * 3) + pub_r001312_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = ((pub_r001312_0_1 * 2) + 23) & 63;
  int stage_v_367_2 = ((pub_r001312_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001312_9_1 * 2) + 25) & 63;
  int stage_v_368_2 = ((pub_r001312_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001312_10_1 * 2) + 14) & 63;
  int stage_v_369_2 = ((pub_r001312_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001312_13_1 * 2) + 35) & 63;
  int stage_v_370_2 = ((pub_r001312_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001312_1_1 * 2) + 18) & 63;
  int stage_v_371_2 = ((pub_r001312_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001312_2_1 * 2) + 47) & 63;
  int stage_v_372_2 = ((pub_r001312_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001312_11_1 * 2) + 6) & 63;
  int stage_v_373_2 = ((pub_r001312_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_337_1 * 3) + pub_r001312_13_1) + 23) & 127;
  int stage_v_374_2 = (((stage_v_337_2 * 3) + pub_r001312_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_1_1 * 3) + pub_r001312_15_1) + 38) & 127;
  int stage_v_375_2 = (((stage_v_1_2 * 3) + pub_r001312_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001312_14_1 * 2) + 35) & 63;
  int stage_v_376_2 = ((pub_r001312_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_202_1 * 3) + pub_r001312_14_1) + 31) & 127;
  int stage_v_377_2 = (((stage_v_202_2 * 3) + pub_r001312_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((sec_r001312_9_1 * 3) + pub_r001312_14_1) + 44) & 127;
  int stage_v_378_2 = (((sec_r001312_9_2 * 3) + pub_r001312_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_174_1 * 3) + pub_r001312_0_1) + 40) & 127;
  int stage_v_379_2 = (((stage_v_174_2 * 3) + pub_r001312_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001312_6_1 * 2) + 18) & 63;
  int stage_v_380_2 = ((pub_r001312_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = (((sec_r001312_2_1 * 3) + pub_r001312_5_1) + 28) & 127;
  int stage_v_381_2 = (((sec_r001312_2_2 * 3) + pub_r001312_5_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001312_9_1 * 2) + 25) & 63;
  int stage_v_382_2 = ((pub_r001312_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001312_8_1 * 2) + 28) & 63;
  int stage_v_383_2 = ((pub_r001312_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001312_4_1 * 2) + 25) & 63;
  int stage_v_384_2 = ((pub_r001312_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001312_0_1 * 2) + 7) & 63;
  int stage_v_385_2 = ((pub_r001312_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001312_10_1 * 2) + 8) & 63;
  int stage_v_386_2 = ((pub_r001312_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001312_6_1 * 2) + 45) & 63;
  int stage_v_387_2 = ((pub_r001312_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = (((stage_v_14_1 * 3) + pub_r001312_3_1) + 28) & 127;
  int stage_v_388_2 = (((stage_v_14_2 * 3) + pub_r001312_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = ((pub_r001312_10_1 * 2) + 44) & 63;
  int stage_v_389_2 = ((pub_r001312_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_38_1 * 3) + pub_r001312_11_1) + 33) & 127;
  int stage_v_390_2 = (((stage_v_38_2 * 3) + pub_r001312_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_252_1 * 3) + pub_r001312_4_1) + 26) & 127;
  int stage_v_391_2 = (((stage_v_252_2 * 3) + pub_r001312_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = ((pub_r001312_14_1 * 2) + 37) & 63;
  int stage_v_392_2 = ((pub_r001312_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001312_4_1 * 2) + 17) & 63;
  int stage_v_393_2 = ((pub_r001312_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001312_8_1 * 2) + 42) & 63;
  int stage_v_394_2 = ((pub_r001312_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_142_1 * 3) + pub_r001312_7_1) + 43) & 127;
  int stage_v_395_2 = (((stage_v_142_2 * 3) + pub_r001312_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001312_3_1 * 2) + 22) & 63;
  int stage_v_396_2 = ((pub_r001312_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = (((stage_v_353_1 * 3) + pub_r001312_11_1) + 5) & 127;
  int stage_v_397_2 = (((stage_v_353_2 * 3) + pub_r001312_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = ((pub_r001312_5_1 * 2) + 34) & 63;
  int stage_v_398_2 = ((pub_r001312_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001312_11_1 * 2) + 43) & 63;
  int stage_v_399_2 = ((pub_r001312_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001312_8_1 * 2) + 41) & 63;
  int stage_v_400_2 = ((pub_r001312_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001312_7_1 * 2) + 23) & 63;
  int stage_v_401_2 = ((pub_r001312_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001312_7_1 * 2) + 35) & 63;
  int stage_v_402_2 = ((pub_r001312_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = (((stage_v_123_1 * 3) + pub_r001312_0_1) + 11) & 127;
  int stage_v_403_2 = (((stage_v_123_2 * 3) + pub_r001312_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = ((pub_r001312_6_1 * 2) + 9) & 63;
  int stage_v_404_2 = ((pub_r001312_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = (((stage_v_264_1 * 3) + pub_r001312_10_1) + 16) & 127;
  int stage_v_405_2 = (((stage_v_264_2 * 3) + pub_r001312_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001312_10_1 * 2) + 28) & 63;
  int stage_v_406_2 = ((pub_r001312_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001312_15_1 * 2) + 27) & 63;
  int stage_v_407_2 = ((pub_r001312_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((sec_r001312_8_1 * 3) + pub_r001312_15_1) + 9) & 127;
  int stage_v_408_2 = (((sec_r001312_8_2 * 3) + pub_r001312_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = (((stage_v_335_1 * 3) + pub_r001312_7_1) + 13) & 127;
  int stage_v_409_2 = (((stage_v_335_2 * 3) + pub_r001312_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001312_8_1 * 2) + 36) & 63;
  int stage_v_410_2 = ((pub_r001312_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001312_14_1 * 2) + 41) & 63;
  int stage_v_411_2 = ((pub_r001312_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_195_1 * 3) + pub_r001312_15_1) + 13) & 127;
  int stage_v_412_2 = (((stage_v_195_2 * 3) + pub_r001312_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = ((pub_r001312_7_1 * 2) + 5) & 63;
  int stage_v_413_2 = ((pub_r001312_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001312_13_1 * 2) + 29) & 63;
  int stage_v_414_2 = ((pub_r001312_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_148_1 * 3) + pub_r001312_15_1) + 31) & 127;
  int stage_v_415_2 = (((stage_v_148_2 * 3) + pub_r001312_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = (((stage_v_349_1 * 3) + pub_r001312_10_1) + 6) & 127;
  int stage_v_416_2 = (((stage_v_349_2 * 3) + pub_r001312_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_228_1 * 3) + pub_r001312_14_1) + 7) & 127;
  int stage_v_417_2 = (((stage_v_228_2 * 3) + pub_r001312_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001312_10_1 * 2) + 29) & 63;
  int stage_v_418_2 = ((pub_r001312_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001312_11_1 * 2) + 21) & 63;
  int stage_v_419_2 = ((pub_r001312_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001312_12_1 * 2) + 46) & 63;
  int stage_v_420_2 = ((pub_r001312_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001312_5_1 * 2) + 50) & 63;
  int stage_v_421_2 = ((pub_r001312_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001312_5_1 * 2) + 49) & 63;
  int stage_v_422_2 = ((pub_r001312_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001312_15_1 * 2) + 34) & 63;
  int stage_v_423_2 = ((pub_r001312_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001312_9_1 * 2) + 42) & 63;
  int stage_v_424_2 = ((pub_r001312_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001312_4_1 * 2) + 42) & 63;
  int stage_v_425_2 = ((pub_r001312_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001312_4_1 * 2) + 41) & 63;
  int stage_v_426_2 = ((pub_r001312_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001312_8_1 * 2) + 12) & 63;
  int stage_v_427_2 = ((pub_r001312_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = (((stage_v_249_1 * 3) + pub_r001312_9_1) + 7) & 127;
  int stage_v_428_2 = (((stage_v_249_2 * 3) + pub_r001312_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = ((pub_r001312_12_1 * 2) + 20) & 63;
  int stage_v_429_2 = ((pub_r001312_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((pub_r001312_10_1 * 2) + 43) & 63;
  int stage_v_430_2 = ((pub_r001312_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = ((pub_r001312_15_1 * 2) + 12) & 63;
  int stage_v_431_2 = ((pub_r001312_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001312_14_1 * 2) + 20) & 63;
  int stage_v_432_2 = ((pub_r001312_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001312_4_1 * 2) + 16) & 63;
  int stage_v_433_2 = ((pub_r001312_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001312_12_1 * 2) + 43) & 63;
  int stage_v_434_2 = ((pub_r001312_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001312_4_1 * 2) + 42) & 63;
  int stage_v_435_2 = ((pub_r001312_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001312_1_1 * 2) + 15) & 63;
  int stage_v_436_2 = ((pub_r001312_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001312_1_1 * 2) + 13) & 63;
  int stage_v_437_2 = ((pub_r001312_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001312_2_1 * 2) + 11) & 63;
  int stage_v_438_2 = ((pub_r001312_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = (((sec_r001312_11_1 * 3) + pub_r001312_0_1) + 39) & 127;
  int stage_v_439_2 = (((sec_r001312_11_2 * 3) + pub_r001312_0_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = ((pub_r001312_6_1 * 2) + 22) & 63;
  int stage_v_440_2 = ((pub_r001312_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001312_8_1 * 2) + 38) & 63;
  int stage_v_441_2 = ((pub_r001312_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001312_14_1 * 2) + 12) & 63;
  int stage_v_442_2 = ((pub_r001312_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001312_10_1 * 2) + 27) & 63;
  int stage_v_443_2 = ((pub_r001312_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = (((stage_v_111_1 * 3) + pub_r001312_9_1) + 27) & 127;
  int stage_v_444_2 = (((stage_v_111_2 * 3) + pub_r001312_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_444_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_444_2 * 2)) & 255;
  int stage_v_445_1 = ((pub_r001312_3_1 * 2) + 34) & 63;
  int stage_v_445_2 = ((pub_r001312_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = (((stage_v_337_1 * 3) + pub_r001312_1_1) + 34) & 127;
  int stage_v_446_2 = (((stage_v_337_2 * 3) + pub_r001312_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = ((pub_r001312_14_1 * 2) + 47) & 63;
  int stage_v_447_2 = ((pub_r001312_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001312_0_1 * 2) + 41) & 63;
  int stage_v_448_2 = ((pub_r001312_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001312_13_1 * 2) + 39) & 63;
  int stage_v_449_2 = ((pub_r001312_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = ((pub_r001312_5_1 * 2) + 29) & 63;
  int stage_v_450_2 = ((pub_r001312_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = (((stage_v_49_1 * 3) + pub_r001312_1_1) + 18) & 127;
  int stage_v_451_2 = (((stage_v_49_2 * 3) + pub_r001312_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = (((stage_v_31_1 * 3) + pub_r001312_15_1) + 45) & 127;
  int stage_v_452_2 = (((stage_v_31_2 * 3) + pub_r001312_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = (((stage_v_148_1 * 3) + pub_r001312_2_1) + 16) & 127;
  int stage_v_453_2 = (((stage_v_148_2 * 3) + pub_r001312_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_453_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_453_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_453_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_453_2 * 2)) & 255;
  int stage_v_454_1 = ((pub_r001312_4_1 * 2) + 35) & 63;
  int stage_v_454_2 = ((pub_r001312_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001312_2_1 * 2) + 26) & 63;
  int stage_v_455_2 = ((pub_r001312_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((pub_r001312_7_1 * 2) + 18) & 63;
  int stage_v_456_2 = ((pub_r001312_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = (((stage_v_33_1 * 3) + pub_r001312_14_1) + 40) & 127;
  int stage_v_457_2 = (((stage_v_33_2 * 3) + pub_r001312_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  int stage_v_458_1 = ((pub_r001312_0_1 * 2) + 27) & 63;
  int stage_v_458_2 = ((pub_r001312_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = (((sec_r001312_3_1 * 3) + pub_r001312_12_1) + 14) & 127;
  int stage_v_459_2 = (((sec_r001312_3_2 * 3) + pub_r001312_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = (((stage_v_91_1 * 3) + pub_r001312_7_1) + 31) & 127;
  int stage_v_460_2 = (((stage_v_91_2 * 3) + pub_r001312_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = (((stage_v_61_1 * 3) + pub_r001312_14_1) + 28) & 127;
  int stage_v_461_2 = (((stage_v_61_2 * 3) + pub_r001312_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_461_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_461_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_461_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_461_2 * 2)) & 255;
  int stage_v_462_1 = ((pub_r001312_10_1 * 2) + 41) & 63;
  int stage_v_462_2 = ((pub_r001312_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = (((sec_r001312_2_1 * 3) + pub_r001312_7_1) + 5) & 127;
  int stage_v_463_2 = (((sec_r001312_2_2 * 3) + pub_r001312_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = ((pub_r001312_15_1 * 2) + 33) & 63;
  int stage_v_464_2 = ((pub_r001312_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = (((stage_v_453_1 * 3) + pub_r001312_2_1) + 15) & 127;
  int stage_v_465_2 = (((stage_v_453_2 * 3) + pub_r001312_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_465_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_465_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_465_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_465_2 * 2)) & 255;
  int stage_v_466_1 = ((pub_r001312_14_1 * 2) + 47) & 63;
  int stage_v_466_2 = ((pub_r001312_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = ((pub_r001312_3_1 * 2) + 23) & 63;
  int stage_v_467_2 = ((pub_r001312_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = (((stage_v_154_1 * 3) + pub_r001312_13_1) + 23) & 127;
  int stage_v_468_2 = (((stage_v_154_2 * 3) + pub_r001312_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = ((pub_r001312_0_1 * 2) + 37) & 63;
  int stage_v_469_2 = ((pub_r001312_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = (((sec_r001312_8_1 * 3) + pub_r001312_4_1) + 31) & 127;
  int stage_v_470_2 = (((sec_r001312_8_2 * 3) + pub_r001312_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = ((pub_r001312_10_1 * 2) + 17) & 63;
  int stage_v_471_2 = ((pub_r001312_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = ((pub_r001312_14_1 * 2) + 29) & 63;
  int stage_v_472_2 = ((pub_r001312_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((pub_r001312_2_1 * 2) + 25) & 63;
  int stage_v_473_2 = ((pub_r001312_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = ((pub_r001312_11_1 * 2) + 25) & 63;
  int stage_v_474_2 = ((pub_r001312_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = ((pub_r001312_2_1 * 2) + 36) & 63;
  int stage_v_475_2 = ((pub_r001312_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = (((stage_v_11_1 * 3) + pub_r001312_9_1) + 4) & 127;
  int stage_v_476_2 = (((stage_v_11_2 * 3) + pub_r001312_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_476_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_476_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_476_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_476_2 * 2)) & 255;
  int stage_v_477_1 = (((stage_v_269_1 * 3) + pub_r001312_12_1) + 44) & 127;
  int stage_v_477_2 = (((stage_v_269_2 * 3) + pub_r001312_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = ((pub_r001312_5_1 * 2) + 19) & 63;
  int stage_v_478_2 = ((pub_r001312_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = ((pub_r001312_8_1 * 2) + 43) & 63;
  int stage_v_479_2 = ((pub_r001312_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((pub_r001312_1_1 * 2) + 41) & 63;
  int stage_v_480_2 = ((pub_r001312_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((pub_r001312_8_1 * 2) + 34) & 63;
  int stage_v_481_2 = ((pub_r001312_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = ((pub_r001312_0_1 * 2) + 37) & 63;
  int stage_v_482_2 = ((pub_r001312_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = (((stage_v_395_1 * 3) + pub_r001312_6_1) + 39) & 127;
  int stage_v_483_2 = (((stage_v_395_2 * 3) + pub_r001312_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_483_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_483_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_483_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_483_2 * 2)) & 255;
  int stage_v_484_1 = ((pub_r001312_15_1 * 2) + 45) & 63;
  int stage_v_484_2 = ((pub_r001312_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = ((pub_r001312_7_1 * 2) + 27) & 63;
  int stage_v_485_2 = ((pub_r001312_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_485_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_485_2) & 127;
  int stage_v_486_1 = (((stage_v_170_1 * 3) + pub_r001312_12_1) + 39) & 127;
  int stage_v_486_2 = (((stage_v_170_2 * 3) + pub_r001312_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_486_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_486_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_486_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_486_2 * 2)) & 255;
  int stage_v_487_1 = ((pub_r001312_13_1 * 2) + 12) & 63;
  int stage_v_487_2 = ((pub_r001312_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_487_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_487_2) & 127;
  int stage_v_488_1 = ((pub_r001312_3_1 * 2) + 39) & 63;
  int stage_v_488_2 = ((pub_r001312_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_488_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_488_2) & 127;
  int stage_v_489_1 = ((pub_r001312_2_1 * 2) + 8) & 63;
  int stage_v_489_2 = ((pub_r001312_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = ((pub_r001312_2_1 * 2) + 50) & 63;
  int stage_v_490_2 = ((pub_r001312_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_490_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_490_2) & 127;
  int stage_v_491_1 = ((pub_r001312_8_1 * 2) + 34) & 63;
  int stage_v_491_2 = ((pub_r001312_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = ((pub_r001312_12_1 * 2) + 25) & 63;
  int stage_v_492_2 = ((pub_r001312_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_492_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_492_2) & 127;
  int stage_v_493_1 = ((pub_r001312_12_1 * 2) + 8) & 63;
  int stage_v_493_2 = ((pub_r001312_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_493_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_493_2) & 127;
  int stage_v_494_1 = (((stage_v_123_1 * 3) + pub_r001312_6_1) + 24) & 127;
  int stage_v_494_2 = (((stage_v_123_2 * 3) + pub_r001312_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_494_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_494_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_494_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_494_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001312_17_1 != sec_r001312_17_2);
  __CPROVER_assume(pub_r001312_12_1 == pub_r001312_12_2);
  __CPROVER_assume(sec_r001312_12_1 != sec_r001312_12_2);
  __CPROVER_assume(sec_r001312_10_1 != sec_r001312_10_2);
  __CPROVER_assume(sec_r001312_6_1 != sec_r001312_6_2);
  __CPROVER_assume(sec_r001312_14_1 != sec_r001312_14_2);
  __CPROVER_assume(sec_r001312_4_1 != sec_r001312_4_2);
  __CPROVER_assume(sec_r001312_7_1 != sec_r001312_7_2);
  __CPROVER_assume(pub_r001312_1_1 == pub_r001312_1_2);
  __CPROVER_assume(pub_r001312_14_1 == pub_r001312_14_2);
  __CPROVER_assume(pub_r001312_4_1 == pub_r001312_4_2);
  __CPROVER_assume(pub_r001312_10_1 == pub_r001312_10_2);
  __CPROVER_assume(pub_r001312_15_1 == pub_r001312_15_2);
  __CPROVER_assume(sec_r001312_8_1 != sec_r001312_8_2);
  __CPROVER_assume(sec_r001312_1_1 != sec_r001312_1_2);
  __CPROVER_assume(pub_r001312_2_1 == pub_r001312_2_2);
  __CPROVER_assume(sec_r001312_0_1 != sec_r001312_0_2);
  __CPROVER_assume(sec_r001312_5_1 != sec_r001312_5_2);
  __CPROVER_assume(pub_r001312_0_1 == pub_r001312_0_2);
  __CPROVER_assume(pub_r001312_8_1 == pub_r001312_8_2);
  __CPROVER_assume(sec_r001312_2_1 != sec_r001312_2_2);
  __CPROVER_assume(sec_r001312_3_1 != sec_r001312_3_2);
  __CPROVER_assume(sec_r001312_15_1 != sec_r001312_15_2);
  __CPROVER_assume(sec_r001312_16_1 != sec_r001312_16_2);
  __CPROVER_assume(pub_r001312_11_1 == pub_r001312_11_2);
  __CPROVER_assume(pub_r001312_7_1 == pub_r001312_7_2);
  __CPROVER_assume(sec_r001312_13_1 != sec_r001312_13_2);
  __CPROVER_assume(sec_r001312_9_1 != sec_r001312_9_2);
  __CPROVER_assume(pub_r001312_9_1 == pub_r001312_9_2);
  __CPROVER_assume(pub_r001312_3_1 == pub_r001312_3_2);
  __CPROVER_assume(pub_r001312_13_1 == pub_r001312_13_2);
  __CPROVER_assume(pub_r001312_6_1 == pub_r001312_6_2);
  __CPROVER_assume(sec_r001312_11_1 != sec_r001312_11_2);
  __CPROVER_assume(pub_r001312_5_1 == pub_r001312_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.port == st_var_0_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.calib == st_var_1_2.calib);
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
  assert(stage_v_447_1 == stage_v_447_2);
  assert(stage_v_448_1 == stage_v_448_2);
  assert(stage_v_449_1 == stage_v_449_2);
  assert(stage_v_450_1 == stage_v_450_2);
  assert(stage_v_451_1 == stage_v_451_2);
  assert(stage_v_452_1 == stage_v_452_2);
  assert(stage_v_453_1 == stage_v_453_2);
  assert(stage_v_454_1 == stage_v_454_2);
  assert(stage_v_455_1 == stage_v_455_2);
  assert(stage_v_456_1 == stage_v_456_2);
  assert(stage_v_457_1 == stage_v_457_2);
  assert(stage_v_458_1 == stage_v_458_2);
  assert(stage_v_459_1 == stage_v_459_2);
  assert(stage_v_460_1 == stage_v_460_2);
  assert(stage_v_461_1 == stage_v_461_2);
  assert(stage_v_462_1 == stage_v_462_2);
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
  assert(stage_v_465_1 == stage_v_465_2);
  assert(stage_v_466_1 == stage_v_466_2);
  assert(stage_v_467_1 == stage_v_467_2);
  assert(stage_v_468_1 == stage_v_468_2);
  assert(stage_v_469_1 == stage_v_469_2);
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
}


