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
struct AudioFrame_R000463_6313_0
{
  int envelope;
  int sample_rate;
  int gain;
  int peak;
  int buffer[3];
};
struct DeviceConfig_R000463_6313_1
{
  short id;
  int stop_bits;
  int port;
  unsigned char parity;
  int buffer[3];
};
struct MatrixBlock_R000463_6313_2
{
  unsigned char density;
  int determinant;
  unsigned char trace;
  unsigned char scale;
  int dim;
  int buffer[3];
};
struct SensorNode_R000463_6313_3
{
  int offset;
  int calib;
  int gain;
  int threshold;
  int reading;
  int buffer[3];
};
union ColorPixel_R000463_6313_0
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
void fn_R000463_6313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000463_6313_3 st_1 = {0};
  struct SensorNode_R000463_6313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int threshold_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_49_1 > 31)
  {
    acc_1 = ((acc_1 + (threshold_49_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_49_2 > 31)
  {
    acc_2 = ((acc_2 + (threshold_49_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_65_1) & 63;
  aux_2 = (aux_2 + mask_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_76_1)
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

  switch (sample_76_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_49_1 == threshold_49_2);
  assert(mask_65_1 == mask_65_2);
  assert(sample_76_1 == sample_76_2);
}

int fn_R000463_6313_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000463_6313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int threshold_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_49 > 31)
  {
    acc = ((acc + (threshold_49 * 2)) + 5) & 127;
    aux ^= threshold_49 & 15;
  }
  else
  {
    acc = ((acc - threshold_49) + 11) & 127;
    aux += 3;
  }
  int mask_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_65) & 63;
  acc ^= aux;
  int sample_76 = (aux + st.buffer[1]) & 3;
  switch (sample_76)
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

  return (acc + aux) & 255;
}

void fn_R000463_6313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st_1 = {0};
  struct AudioFrame_R000463_6313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int sample_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_11_1)
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

  switch (sample_11_2)
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

  int margin_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_82_1) & 63;
  aux_2 = (aux_2 + margin_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_74_1 = local_arr_1[aux_1 % 3];
  int weight_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_74_2 * 2)) & 127;
  int tracker_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_42_1 > 30)
  {
    acc_1 = ((acc_1 + (tracker_42_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_42_2 > 30)
  {
    acc_2 = ((acc_2 + (tracker_42_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_11_1 == sample_11_2);
  assert(margin_82_1 == margin_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_74_1 == weight_74_2);
  assert(tracker_42_1 == tracker_42_2);
}

int fn_R000463_6313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int sample_11 = (aux + st.buffer[1]) & 3;
  switch (sample_11)
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

  int margin_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_82) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_74 = local_arr[aux % 3];
  acc = (acc + (weight_74 * 2)) & 127;
  int tracker_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_42 > 30)
  {
    acc = ((acc + (tracker_42 * 2)) + 5) & 127;
    aux ^= tracker_42 & 15;
  }
  else
  {
    acc = ((acc - tracker_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000463_6313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st_1 = {0};
  struct DeviceConfig_R000463_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int scale_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_63_1) & 63;
  aux_2 = (aux_2 + scale_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_50_1)
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

  switch (margin_50_2)
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

  int checksum_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_38_1 > 36)
  {
    acc_1 = ((acc_1 + (checksum_38_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_38_2 > 36)
  {
    acc_2 = ((acc_2 + (checksum_38_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_63_1 == scale_63_2);
  assert(margin_50_1 == margin_50_2);
  assert(checksum_38_1 == checksum_38_2);
}

int fn_R000463_6313_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int scale_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_63) & 63;
  acc ^= aux;
  int margin_50 = (aux + st.buffer[1]) & 3;
  switch (margin_50)
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

  int checksum_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_38 > 36)
  {
    acc = ((acc + (checksum_38 * 2)) + 5) & 127;
    aux ^= checksum_38 & 15;
  }
  else
  {
    acc = ((acc - checksum_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000463_6313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000463_6313_3 st_1 = {0};
  struct SensorNode_R000463_6313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_35_1 > 48)
  {
    acc_1 = ((acc_1 + (offset_35_1 * 2)) + 5) & 127;
    aux_1 ^= offset_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_35_2 > 48)
  {
    acc_2 = ((acc_2 + (offset_35_2 * 2)) + 5) & 127;
    aux_2 ^= offset_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_99_1 = local_arr_1[aux_1 % 3];
  int delta_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_99_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_66_1)
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

  switch (scale_66_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_35_1 == offset_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_99_1 == delta_99_2);
  assert(scale_66_1 == scale_66_2);
}

int fn_R000463_6313_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000463_6313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_35 > 48)
  {
    acc = ((acc + (offset_35 * 2)) + 5) & 127;
    aux ^= offset_35 & 15;
  }
  else
  {
    acc = ((acc - offset_35) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_99 = local_arr[aux % 3];
  acc = (acc + (delta_99 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_66 = (aux + st.buffer[1]) & 3;
  switch (scale_66)
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

void fn_R000463_6313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000463_6313_3 st_1 = {0};
  struct SensorNode_R000463_6313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_87_1)
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

  switch (scale_87_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_99_1 > 50)
  {
    acc_1 = ((acc_1 + (weight_99_1 * 2)) + 5) & 127;
    aux_1 ^= weight_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_99_2 > 50)
  {
    acc_2 = ((acc_2 + (weight_99_2 * 2)) + 5) & 127;
    aux_2 ^= weight_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_87_1 == scale_87_2);
  assert(weight_99_1 == weight_99_2);
}

int fn_R000463_6313_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000463_6313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_87 = (aux + st.buffer[1]) & 3;
  switch (scale_87)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_99 > 50)
  {
    acc = ((acc + (weight_99 * 2)) + 5) & 127;
    aux ^= weight_99 & 15;
  }
  else
  {
    acc = ((acc - weight_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000463_6313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st_1 = {0};
  struct AudioFrame_R000463_6313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int segment_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_66_1)
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

  switch (segment_66_2)
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
  int factor_88_1 = local_arr_1[aux_1 % 3];
  int factor_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_88_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_66_1 == segment_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_88_1 == factor_88_2);
}

int fn_R000463_6313_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int segment_66 = (aux + st.buffer[1]) & 3;
  switch (segment_66)
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
  int factor_88 = local_arr[aux % 3];
  acc = (acc + (factor_88 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000463_6313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st_1 = {0};
  struct AudioFrame_R000463_6313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int quantum_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_53_1)
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

  switch (quantum_53_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_19_1 = local_arr_1[aux_1 % 3];
  int quotient_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_19_2 * 2)) & 127;
  int parity_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_94_1 > 28)
  {
    acc_1 = ((acc_1 + (parity_94_1 * 2)) + 5) & 127;
    aux_1 ^= parity_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_94_2 > 28)
  {
    acc_2 = ((acc_2 + (parity_94_2 * 2)) + 5) & 127;
    aux_2 ^= parity_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_53_1 == quantum_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_19_1 == quotient_19_2);
  assert(parity_94_1 == parity_94_2);
}

int fn_R000463_6313_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int quantum_53 = (aux + st.buffer[1]) & 3;
  switch (quantum_53)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_19 = local_arr[aux % 3];
  acc = (acc + (quotient_19 * 2)) & 127;
  int parity_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_94 > 28)
  {
    acc = ((acc + (parity_94 * 2)) + 5) & 127;
    aux ^= parity_94 & 15;
  }
  else
  {
    acc = ((acc - parity_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000463_6313_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st_1 = {0};
  struct MatrixBlock_R000463_6313_2 st_2 = {0};
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
  int index_reg_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_61_1 > 25)
  {
    acc_1 = ((acc_1 + (index_reg_61_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_61_2 > 25)
  {
    acc_2 = ((acc_2 + (index_reg_61_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_61_1 == index_reg_61_2);
}

int fn_R000463_6313_7(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_61 > 25)
  {
    acc = ((acc + (index_reg_61 * 2)) + 5) & 127;
    aux ^= index_reg_61 & 15;
  }
  else
  {
    acc = ((acc - index_reg_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000463_6313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st_1 = {0};
  struct MatrixBlock_R000463_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int mask_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_55_1)
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

  switch (mask_55_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_40_1 = local_arr_1[aux_1 % 3];
  int anchor_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_55_1 == mask_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_40_1 == anchor_40_2);
}

int fn_R000463_6313_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int mask_55 = (aux + st.buffer[1]) & 3;
  switch (mask_55)
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
  int local_arr[3] = {4, 9, 15};
  int anchor_40 = local_arr[aux % 3];
  acc = (acc + (anchor_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000463_6313_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st_1 = {0};
  struct DeviceConfig_R000463_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_11_1 = local_arr_1[aux_1 % 3];
  int pivot_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_11_2 * 2)) & 127;
  int margin_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_94_1)
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

  switch (margin_94_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_11_1 == pivot_11_2);
  assert(margin_94_1 == margin_94_2);
}

int fn_R000463_6313_9(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int pivot_11 = local_arr[aux % 3];
  acc = (acc + (pivot_11 * 2)) & 127;
  int margin_94 = (aux + st.buffer[1]) & 3;
  switch (margin_94)
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

  return (acc + aux) & 255;
}

void fn_R000463_6313_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st_1 = {0};
  struct MatrixBlock_R000463_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int damping_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_58_1)
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

  switch (damping_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_58_1 == damping_58_2);
}

int fn_R000463_6313_10(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int damping_58 = (aux + st.buffer[1]) & 3;
  switch (damping_58)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000463_6313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st_1 = {0};
  struct MatrixBlock_R000463_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int stride_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_59_1) & 63;
  aux_2 = (aux_2 + stride_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_11_1 = local_arr_1[aux_1 % 3];
  int accumulator_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_11_2 * 2)) & 127;
  int sample_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_22_1 > 41)
  {
    acc_1 = ((acc_1 + (sample_22_1 * 2)) + 5) & 127;
    aux_1 ^= sample_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_22_2 > 41)
  {
    acc_2 = ((acc_2 + (sample_22_2 * 2)) + 5) & 127;
    aux_2 ^= sample_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_59_1 == stride_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_11_1 == accumulator_11_2);
  assert(sample_22_1 == sample_22_2);
}

int fn_R000463_6313_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int stride_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_59) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_11 = local_arr[aux % 3];
  acc = (acc + (accumulator_11 * 2)) & 127;
  int sample_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_22 > 41)
  {
    acc = ((acc + (sample_22 * 2)) + 5) & 127;
    aux ^= sample_22 & 15;
  }
  else
  {
    acc = ((acc - sample_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000463_6313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st_1 = {0};
  struct DeviceConfig_R000463_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_23_1 > 28)
  {
    acc_1 = ((acc_1 + (delta_23_1 * 2)) + 5) & 127;
    aux_1 ^= delta_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_23_2 > 28)
  {
    acc_2 = ((acc_2 + (delta_23_2 * 2)) + 5) & 127;
    aux_2 ^= delta_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_23_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_23_1 == delta_23_2);
}

int fn_R000463_6313_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_23 > 28)
  {
    acc = ((acc + (delta_23 * 2)) + 5) & 127;
    aux ^= delta_23 & 15;
  }
  else
  {
    acc = ((acc - delta_23) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000463_6313_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st_1 = {0};
  struct MatrixBlock_R000463_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_51_1 > 25)
  {
    acc_1 = ((acc_1 + (delta_51_1 * 2)) + 5) & 127;
    aux_1 ^= delta_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_51_2 > 25)
  {
    acc_2 = ((acc_2 + (delta_51_2 * 2)) + 5) & 127;
    aux_2 ^= delta_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_95_1 = local_arr_1[aux_1 % 3];
  int delta_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_51_1 == delta_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_95_1 == delta_95_2);
}

int fn_R000463_6313_13(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_51 > 25)
  {
    acc = ((acc + (delta_51 * 2)) + 5) & 127;
    aux ^= delta_51 & 15;
  }
  else
  {
    acc = ((acc - delta_51) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_95 = local_arr[aux % 3];
  acc = (acc + (delta_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000463_6313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st_1 = {0};
  struct AudioFrame_R000463_6313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quantum_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_10_1)
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

  switch (quantum_10_2)
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

  int offset_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_37_1) & 63;
  aux_2 = (aux_2 + offset_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_10_1 == quantum_10_2);
  assert(offset_37_1 == offset_37_2);
}

int fn_R000463_6313_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quantum_10 = (aux + st.buffer[1]) & 3;
  switch (quantum_10)
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

  int offset_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_37) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000463_6313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st_1 = {0};
  struct MatrixBlock_R000463_6313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_49_1 = local_arr_1[aux_1 % 3];
  int stride_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_49_2 * 2)) & 127;
  int bound_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_69_1)
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

  switch (bound_69_2)
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

  int cursor_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_22_1 > 31)
  {
    acc_1 = ((acc_1 + (cursor_22_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_22_2 > 31)
  {
    acc_2 = ((acc_2 + (cursor_22_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
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

  assert(stride_49_1 == stride_49_2);
  assert(bound_69_1 == bound_69_2);
  assert(cursor_22_1 == cursor_22_2);
}

int fn_R000463_6313_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000463_6313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_49 = local_arr[aux % 3];
  acc = (acc + (stride_49 * 2)) & 127;
  int bound_69 = (aux + st.buffer[1]) & 3;
  switch (bound_69)
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

  int cursor_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_22 > 31)
  {
    acc = ((acc + (cursor_22 * 2)) + 5) & 127;
    aux ^= cursor_22 & 15;
  }
  else
  {
    acc = ((acc - cursor_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000463_6313_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st_1 = {0};
  struct DeviceConfig_R000463_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int residue_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_88_1) & 63;
  aux_2 = (aux_2 + residue_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_24_1)
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

  switch (damping_24_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_88_1 == residue_88_2);
  assert(damping_24_1 == damping_24_2);
}

int fn_R000463_6313_16(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int residue_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_88) & 63;
  acc ^= aux;
  int damping_24 = (aux + st.buffer[1]) & 3;
  switch (damping_24)
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

void fn_R000463_6313_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st_1 = {0};
  struct DeviceConfig_R000463_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_66_1)
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

  switch (pivot_66_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_66_1 == pivot_66_2);
}

int fn_R000463_6313_17(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_66 = (aux + st.buffer[1]) & 3;
  switch (pivot_66)
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

void fn_R000463_6313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st_1 = {0};
  struct AudioFrame_R000463_6313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_40_1) & 63;
  aux_2 = (aux_2 + weight_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_18_1 > 16)
  {
    acc_1 = ((acc_1 + (segment_18_1 * 2)) + 5) & 127;
    aux_1 ^= segment_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_18_2 > 16)
  {
    acc_2 = ((acc_2 + (segment_18_2 * 2)) + 5) & 127;
    aux_2 ^= segment_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_18_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_40_1 == weight_40_2);
  assert(segment_18_1 == segment_18_2);
}

int fn_R000463_6313_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000463_6313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_40) & 63;
  acc ^= aux;
  int segment_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_18 > 16)
  {
    acc = ((acc + (segment_18 * 2)) + 5) & 127;
    aux ^= segment_18 & 15;
  }
  else
  {
    acc = ((acc - segment_18) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000463_6313_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st_1 = {0};
  struct DeviceConfig_R000463_6313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int mask_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_65_1) & 63;
  aux_2 = (aux_2 + mask_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_33_1 = local_arr_1[aux_1 % 3];
  int delta_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_33_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_65_1 == mask_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_33_1 == delta_33_2);
}

int fn_R000463_6313_19(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000463_6313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int mask_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_65) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_33 = local_arr[aux % 3];
  acc = (acc + (delta_33 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000463_0_1;
  int sec_r000463_0_2;
  int sec_r000463_1_1;
  int sec_r000463_1_2;
  int sec_r000463_2_1;
  int sec_r000463_2_2;
  int sec_r000463_3_1;
  int sec_r000463_3_2;
  int sec_r000463_4_1;
  int sec_r000463_4_2;
  int sec_r000463_5_1;
  int sec_r000463_5_2;
  int sec_r000463_6_1;
  int sec_r000463_6_2;
  int sec_r000463_7_1;
  int sec_r000463_7_2;
  int sec_r000463_8_1;
  int sec_r000463_8_2;
  int sec_r000463_9_1;
  int sec_r000463_9_2;
  int sec_r000463_10_1;
  int sec_r000463_10_2;
  int sec_r000463_11_1;
  int sec_r000463_11_2;
  int sec_r000463_12_1;
  int sec_r000463_12_2;
  int sec_r000463_13_1;
  int sec_r000463_13_2;
  int sec_r000463_14_1;
  int sec_r000463_14_2;
  int sec_r000463_15_1;
  int sec_r000463_15_2;
  int sec_r000463_16_1;
  int sec_r000463_16_2;
  int sec_r000463_17_1;
  int sec_r000463_17_2;
  int sec_r000463_18_1;
  int sec_r000463_18_2;
  int sec_r000463_19_1;
  int sec_r000463_19_2;
  int sec_r000463_20_1;
  int sec_r000463_20_2;
  int sec_r000463_21_1;
  int sec_r000463_21_2;
  int sec_r000463_22_1;
  int sec_r000463_22_2;
  int pub_r000463_0_1;
  int pub_r000463_0_2;
  int pub_r000463_1_1;
  int pub_r000463_1_2;
  int pub_r000463_2_1;
  int pub_r000463_2_2;
  int pub_r000463_3_1;
  int pub_r000463_3_2;
  int pub_r000463_4_1;
  int pub_r000463_4_2;
  int pub_r000463_5_1;
  int pub_r000463_5_2;
  int pub_r000463_6_1;
  int pub_r000463_6_2;
  int pub_r000463_7_1;
  int pub_r000463_7_2;
  int pub_r000463_8_1;
  int pub_r000463_8_2;
  int pub_r000463_9_1;
  int pub_r000463_9_2;
  int pub_r000463_10_1;
  int pub_r000463_10_2;
  int pub_r000463_11_1;
  int pub_r000463_11_2;
  int pub_r000463_12_1;
  int pub_r000463_12_2;
  int pub_r000463_13_1;
  int pub_r000463_13_2;
  int pub_r000463_14_1;
  int pub_r000463_14_2;
  int pub_r000463_15_1;
  int pub_r000463_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000463_0_1 >= (-100)) && (pub_r000463_0_1 <= 100));
  __CPROVER_assume((pub_r000463_0_2 >= (-100)) && (pub_r000463_0_2 <= 100));
  __CPROVER_assume((pub_r000463_1_1 >= (-100)) && (pub_r000463_1_1 <= 100));
  __CPROVER_assume((pub_r000463_1_2 >= (-100)) && (pub_r000463_1_2 <= 100));
  __CPROVER_assume((pub_r000463_2_1 >= (-100)) && (pub_r000463_2_1 <= 100));
  __CPROVER_assume((pub_r000463_2_2 >= (-100)) && (pub_r000463_2_2 <= 100));
  __CPROVER_assume((pub_r000463_3_1 >= (-100)) && (pub_r000463_3_1 <= 100));
  __CPROVER_assume((pub_r000463_3_2 >= (-100)) && (pub_r000463_3_2 <= 100));
  __CPROVER_assume((pub_r000463_4_1 >= (-100)) && (pub_r000463_4_1 <= 100));
  __CPROVER_assume((pub_r000463_4_2 >= (-100)) && (pub_r000463_4_2 <= 100));
  __CPROVER_assume((pub_r000463_5_1 >= (-100)) && (pub_r000463_5_1 <= 100));
  __CPROVER_assume((pub_r000463_5_2 >= (-100)) && (pub_r000463_5_2 <= 100));
  __CPROVER_assume((pub_r000463_6_1 >= (-100)) && (pub_r000463_6_1 <= 100));
  __CPROVER_assume((pub_r000463_6_2 >= (-100)) && (pub_r000463_6_2 <= 100));
  __CPROVER_assume((pub_r000463_7_1 >= (-100)) && (pub_r000463_7_1 <= 100));
  __CPROVER_assume((pub_r000463_7_2 >= (-100)) && (pub_r000463_7_2 <= 100));
  __CPROVER_assume((pub_r000463_8_1 >= (-100)) && (pub_r000463_8_1 <= 100));
  __CPROVER_assume((pub_r000463_8_2 >= (-100)) && (pub_r000463_8_2 <= 100));
  __CPROVER_assume((pub_r000463_9_1 >= (-100)) && (pub_r000463_9_1 <= 100));
  __CPROVER_assume((pub_r000463_9_2 >= (-100)) && (pub_r000463_9_2 <= 100));
  __CPROVER_assume((pub_r000463_10_1 >= (-100)) && (pub_r000463_10_1 <= 100));
  __CPROVER_assume((pub_r000463_10_2 >= (-100)) && (pub_r000463_10_2 <= 100));
  __CPROVER_assume((pub_r000463_11_1 >= (-100)) && (pub_r000463_11_1 <= 100));
  __CPROVER_assume((pub_r000463_11_2 >= (-100)) && (pub_r000463_11_2 <= 100));
  __CPROVER_assume((pub_r000463_12_1 >= (-100)) && (pub_r000463_12_1 <= 100));
  __CPROVER_assume((pub_r000463_12_2 >= (-100)) && (pub_r000463_12_2 <= 100));
  __CPROVER_assume((pub_r000463_13_1 >= (-100)) && (pub_r000463_13_1 <= 100));
  __CPROVER_assume((pub_r000463_13_2 >= (-100)) && (pub_r000463_13_2 <= 100));
  __CPROVER_assume((pub_r000463_14_1 >= (-100)) && (pub_r000463_14_1 <= 100));
  __CPROVER_assume((pub_r000463_14_2 >= (-100)) && (pub_r000463_14_2 <= 100));
  __CPROVER_assume((pub_r000463_15_1 >= (-100)) && (pub_r000463_15_1 <= 100));
  __CPROVER_assume((pub_r000463_15_2 >= (-100)) && (pub_r000463_15_2 <= 100));
  __CPROVER_assume((sec_r000463_0_1 >= 0) && (sec_r000463_0_1 <= 255));
  __CPROVER_assume((sec_r000463_0_2 >= 0) && (sec_r000463_0_2 <= 255));
  __CPROVER_assume((sec_r000463_1_1 >= 0) && (sec_r000463_1_1 <= 255));
  __CPROVER_assume((sec_r000463_1_2 >= 0) && (sec_r000463_1_2 <= 255));
  __CPROVER_assume((sec_r000463_2_1 >= 0) && (sec_r000463_2_1 <= 255));
  __CPROVER_assume((sec_r000463_2_2 >= 0) && (sec_r000463_2_2 <= 255));
  __CPROVER_assume((sec_r000463_3_1 >= 0) && (sec_r000463_3_1 <= 255));
  __CPROVER_assume((sec_r000463_3_2 >= 0) && (sec_r000463_3_2 <= 255));
  __CPROVER_assume((sec_r000463_4_1 >= 0) && (sec_r000463_4_1 <= 255));
  __CPROVER_assume((sec_r000463_4_2 >= 0) && (sec_r000463_4_2 <= 255));
  __CPROVER_assume((sec_r000463_5_1 >= 0) && (sec_r000463_5_1 <= 255));
  __CPROVER_assume((sec_r000463_5_2 >= 0) && (sec_r000463_5_2 <= 255));
  __CPROVER_assume((sec_r000463_6_1 >= 0) && (sec_r000463_6_1 <= 255));
  __CPROVER_assume((sec_r000463_6_2 >= 0) && (sec_r000463_6_2 <= 255));
  __CPROVER_assume((sec_r000463_7_1 >= 0) && (sec_r000463_7_1 <= 255));
  __CPROVER_assume((sec_r000463_7_2 >= 0) && (sec_r000463_7_2 <= 255));
  __CPROVER_assume((sec_r000463_8_1 >= 0) && (sec_r000463_8_1 <= 255));
  __CPROVER_assume((sec_r000463_8_2 >= 0) && (sec_r000463_8_2 <= 255));
  __CPROVER_assume((sec_r000463_9_1 >= 0) && (sec_r000463_9_1 <= 255));
  __CPROVER_assume((sec_r000463_9_2 >= 0) && (sec_r000463_9_2 <= 255));
  __CPROVER_assume((sec_r000463_10_1 >= 0) && (sec_r000463_10_1 <= 255));
  __CPROVER_assume((sec_r000463_10_2 >= 0) && (sec_r000463_10_2 <= 255));
  __CPROVER_assume((sec_r000463_11_1 >= 0) && (sec_r000463_11_1 <= 255));
  __CPROVER_assume((sec_r000463_11_2 >= 0) && (sec_r000463_11_2 <= 255));
  __CPROVER_assume((sec_r000463_12_1 >= 0) && (sec_r000463_12_1 <= 255));
  __CPROVER_assume((sec_r000463_12_2 >= 0) && (sec_r000463_12_2 <= 255));
  __CPROVER_assume((sec_r000463_13_1 >= 0) && (sec_r000463_13_1 <= 255));
  __CPROVER_assume((sec_r000463_13_2 >= 0) && (sec_r000463_13_2 <= 255));
  __CPROVER_assume((sec_r000463_14_1 >= 0) && (sec_r000463_14_1 <= 255));
  __CPROVER_assume((sec_r000463_14_2 >= 0) && (sec_r000463_14_2 <= 255));
  __CPROVER_assume((sec_r000463_15_1 >= 0) && (sec_r000463_15_1 <= 255));
  __CPROVER_assume((sec_r000463_15_2 >= 0) && (sec_r000463_15_2 <= 255));
  __CPROVER_assume((sec_r000463_16_1 >= 0) && (sec_r000463_16_1 <= 255));
  __CPROVER_assume((sec_r000463_16_2 >= 0) && (sec_r000463_16_2 <= 255));
  __CPROVER_assume((sec_r000463_17_1 >= 0) && (sec_r000463_17_1 <= 255));
  __CPROVER_assume((sec_r000463_17_2 >= 0) && (sec_r000463_17_2 <= 255));
  __CPROVER_assume((sec_r000463_18_1 >= 0) && (sec_r000463_18_1 <= 255));
  __CPROVER_assume((sec_r000463_18_2 >= 0) && (sec_r000463_18_2 <= 255));
  __CPROVER_assume((sec_r000463_19_1 >= 0) && (sec_r000463_19_1 <= 255));
  __CPROVER_assume((sec_r000463_19_2 >= 0) && (sec_r000463_19_2 <= 255));
  __CPROVER_assume((sec_r000463_20_1 >= 0) && (sec_r000463_20_1 <= 255));
  __CPROVER_assume((sec_r000463_20_2 >= 0) && (sec_r000463_20_2 <= 255));
  __CPROVER_assume((sec_r000463_21_1 >= 0) && (sec_r000463_21_1 <= 255));
  __CPROVER_assume((sec_r000463_21_2 >= 0) && (sec_r000463_21_2 <= 255));
  __CPROVER_assume((sec_r000463_22_1 >= 0) && (sec_r000463_22_1 <= 255));
  __CPROVER_assume((sec_r000463_22_2 >= 0) && (sec_r000463_22_2 <= 255));
  struct AudioFrame_R000463_6313_0 st_var_0_1 = {0};
  struct AudioFrame_R000463_6313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000463_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000463_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000463_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000463_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000463_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000463_0_2 + 7) & 15;
  struct DeviceConfig_R000463_6313_1 st_var_1_1 = {0};
  struct DeviceConfig_R000463_6313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000463_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000463_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000463_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000463_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000463_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000463_0_2 + 9) & 15;
  struct MatrixBlock_R000463_6313_2 st_var_2_1 = {0};
  struct MatrixBlock_R000463_6313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000463_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000463_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000463_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000463_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000463_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000463_0_2 + 11) & 15;
  struct SensorNode_R000463_6313_3 st_var_3_1 = {0};
  struct SensorNode_R000463_6313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000463_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000463_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000463_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000463_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000463_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000463_0_2 + 13) & 15;
  union ColorPixel_R000463_6313_0 u_var_1;
  union ColorPixel_R000463_6313_0 u_var_2;
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
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 29)
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
  if (stage_v_2_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 29)
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
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = (st_var_2_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_2_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = ((st_var_3_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_3_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 37)
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
  if (stage_v_11_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 37)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
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
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 25)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 25)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
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
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 44)
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
  if (stage_v_24_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 44)
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
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 28) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((st_var_3_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_3_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 25)
    {
      chk_sum_1 ^= stage_v_31_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_31_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 25)
    {
      chk_sum_2 ^= stage_v_31_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
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
  int stage_v_35_1 = ((st_var_3_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_3_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 55)
    {
      chk_sum_1 ^= stage_v_35_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_35_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 55)
    {
      chk_sum_2 ^= stage_v_35_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 32)
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
  if (stage_v_37_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 32)
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
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 38)
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
  if (stage_v_38_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 38)
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
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (st_var_2_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_2_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = (st_var_2_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_2_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

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
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 40)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 40)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 28)
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
  if (stage_v_50_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 28)
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
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 28)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 28)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (st_var_3_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_3_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
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

  switch (stage_v_55_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = ((st_var_1_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_1_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 45)
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
  if (stage_v_65_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 45)
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
  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  int stage_v_67_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_67_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (st_var_2_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_2_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  int stage_v_71_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (76 & 31);
  int stage_v_71_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (76 & 31);
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= (stage_v_71_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_71_2 << 1) & 127;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  int stage_v_74_1 = (st_var_2_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_2_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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

  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 77) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 78) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 79) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 79) & 15;
  int stage_v_78_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_78_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= stage_v_78_1;
  chk_sum_2 ^= stage_v_78_2;
  int stage_v_79_1 = ((st_var_3_1.buffer[1] * 2) + 244) & 63;
  int stage_v_79_2 = ((st_var_3_2.buffer[1] * 2) + 244) & 63;
  if (stage_v_79_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_79_1) - 5) & 255;
    if (stage_v_79_1 > 48)
    {
      chk_sum_1 ^= stage_v_79_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_79_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_79_2) - 5) & 255;
    if (stage_v_79_2 > 48)
    {
      chk_sum_2 ^= stage_v_79_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_81_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 83) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  int stage_v_83_1 = ((st_var_3_1.buffer[2] * 2) + 256) & 63;
  int stage_v_83_2 = ((st_var_3_2.buffer[2] * 2) + 256) & 63;
  if (stage_v_83_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_83_1) - 5) & 255;
    if (stage_v_83_1 > 38)
    {
      chk_sum_1 ^= stage_v_83_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_83_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_83_2) - 5) & 255;
    if (stage_v_83_2 > 38)
    {
      chk_sum_2 ^= stage_v_83_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int sub_step_84_1 = ((sec_r000463_11_1 + pub_r000463_7_1) + 34) & 127;
  int sub_step_84_2 = ((sec_r000463_11_2 + pub_r000463_7_2) + 34) & 127;
  int stage_v_84_1 = ((sub_step_84_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_84_2 = ((sub_step_84_2 * 2) + pub_r000463_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_84_1 & 15;
  st_var_0_2.buffer[0] = stage_v_84_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int sub_step_85_1 = ((sec_r000463_13_1 + pub_r000463_5_1) + 31) & 127;
  int sub_step_85_2 = ((sec_r000463_13_2 + pub_r000463_5_2) + 31) & 127;
  int stage_v_85_1 = ((sub_step_85_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_85_2 = ((sub_step_85_2 * 2) + pub_r000463_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_85_1 & 15;
  st_var_1_2.buffer[1] = stage_v_85_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int sub_step_86_1 = ((sub_step_85_1 + pub_r000463_11_1) + 22) & 127;
  int sub_step_86_2 = ((sub_step_85_2 + pub_r000463_11_2) + 22) & 127;
  int stage_v_86_1 = ((sub_step_86_1 * 2) + pub_r000463_7_1) & 127;
  int stage_v_86_2 = ((sub_step_86_2 * 2) + pub_r000463_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_86_1 & 15;
  st_var_2_2.buffer[2] = stage_v_86_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int sub_step_87_1 = ((sec_r000463_1_1 + pub_r000463_3_1) + 19) & 127;
  int sub_step_87_2 = ((sec_r000463_1_2 + pub_r000463_3_2) + 19) & 127;
  int stage_v_87_1 = ((sub_step_87_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_87_2 = ((sub_step_87_2 * 2) + pub_r000463_2_2) & 127;
  st_var_3_1.buffer[0] = stage_v_87_1 & 15;
  st_var_3_2.buffer[0] = stage_v_87_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int sub_step_88_1 = ((sub_step_85_1 + pub_r000463_7_1) + 35) & 127;
  int sub_step_88_2 = ((sub_step_85_2 + pub_r000463_7_2) + 35) & 127;
  int stage_v_88_1 = ((sub_step_88_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_88_2 = ((sub_step_88_2 * 2) + pub_r000463_3_2) & 127;
  st_var_0_1.buffer[1] = stage_v_88_1 & 15;
  st_var_0_2.buffer[1] = stage_v_88_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int sub_step_89_1 = ((stage_v_87_1 + pub_r000463_9_1) + 32) & 127;
  int sub_step_89_2 = ((stage_v_87_2 + pub_r000463_9_2) + 32) & 127;
  int stage_v_89_1 = ((sub_step_89_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_89_2 = ((sub_step_89_2 * 2) + pub_r000463_10_2) & 127;
  st_var_1_1.buffer[2] = stage_v_89_1 & 15;
  st_var_1_2.buffer[2] = stage_v_89_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int sub_step_90_1 = ((stage_v_85_1 + pub_r000463_6_1) + 23) & 127;
  int sub_step_90_2 = ((stage_v_85_2 + pub_r000463_6_2) + 23) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000463_15_2) & 127;
  st_var_2_1.buffer[0] = stage_v_90_1 & 15;
  st_var_2_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((sec_r000463_9_1 + pub_r000463_11_1) + 7) & 127;
  int sub_step_91_2 = ((sec_r000463_9_2 + pub_r000463_11_2) + 7) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000463_6_2) & 127;
  st_var_3_1.buffer[1] = stage_v_91_1 & 15;
  st_var_3_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((stage_v_88_1 + pub_r000463_2_1) + 15) & 127;
  int sub_step_92_2 = ((stage_v_88_2 + pub_r000463_2_2) + 15) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000463_4_2) & 127;
  st_var_0_1.buffer[2] = stage_v_92_1 & 15;
  st_var_0_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((stage_v_86_1 + pub_r000463_1_1) + 35) & 127;
  int sub_step_93_2 = ((stage_v_86_2 + pub_r000463_1_2) + 35) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000463_14_2) & 127;
  st_var_1_1.buffer[0] = stage_v_93_1 & 15;
  st_var_1_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((sub_step_89_1 + pub_r000463_15_1) + 10) & 127;
  int sub_step_94_2 = ((sub_step_89_2 + pub_r000463_15_2) + 10) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000463_9_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000463_9_2) & 127;
  st_var_2_1.buffer[1] = stage_v_94_1 & 15;
  st_var_2_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sub_step_93_1 + pub_r000463_1_1) + 25) & 127;
  int sub_step_95_2 = ((sub_step_93_2 + pub_r000463_1_2) + 25) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000463_15_2) & 127;
  st_var_3_1.buffer[2] = stage_v_95_1 & 15;
  st_var_3_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((sec_r000463_19_1 + pub_r000463_0_1) + 32) & 127;
  int sub_step_96_2 = ((sec_r000463_19_2 + pub_r000463_0_2) + 32) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000463_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((sub_step_87_1 + pub_r000463_7_1) + 26) & 127;
  int sub_step_97_2 = ((sub_step_87_2 + pub_r000463_7_2) + 26) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000463_5_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000463_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((sub_step_91_1 + pub_r000463_2_1) + 25) & 127;
  int sub_step_98_2 = ((sub_step_91_2 + pub_r000463_2_2) + 25) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000463_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((sub_step_91_1 + pub_r000463_1_1) + 26) & 127;
  int sub_step_99_2 = ((sub_step_91_2 + pub_r000463_1_2) + 26) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000463_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_99_1 & 15;
  st_var_3_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((sec_r000463_0_1 + pub_r000463_1_1) + 27) & 127;
  int sub_step_100_2 = ((sec_r000463_0_2 + pub_r000463_1_2) + 27) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000463_6_2) & 127;
  st_var_0_1.buffer[1] = stage_v_100_1 & 15;
  st_var_0_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((stage_v_89_1 + pub_r000463_10_1) + 10) & 127;
  int sub_step_101_2 = ((stage_v_89_2 + pub_r000463_10_2) + 10) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000463_14_2) & 127;
  st_var_1_1.buffer[2] = stage_v_101_1 & 15;
  st_var_1_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((sec_r000463_10_1 + pub_r000463_8_1) + 9) & 127;
  int sub_step_102_2 = ((sec_r000463_10_2 + pub_r000463_8_2) + 9) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000463_2_2) & 127;
  st_var_2_1.buffer[0] = stage_v_102_1 & 15;
  st_var_2_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((sub_step_101_1 + pub_r000463_5_1) + 16) & 127;
  int sub_step_103_2 = ((sub_step_101_2 + pub_r000463_5_2) + 16) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000463_3_2) & 127;
  st_var_3_1.buffer[1] = stage_v_103_1 & 15;
  st_var_3_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((stage_v_84_1 + pub_r000463_0_1) + 32) & 127;
  int sub_step_104_2 = ((stage_v_84_2 + pub_r000463_0_2) + 32) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000463_0_2) & 127;
  st_var_0_1.buffer[2] = stage_v_104_1 & 15;
  st_var_0_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((stage_v_86_1 + pub_r000463_12_1) + 10) & 127;
  int sub_step_105_2 = ((stage_v_86_2 + pub_r000463_12_2) + 10) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000463_14_2) & 127;
  st_var_1_1.buffer[0] = stage_v_105_1 & 15;
  st_var_1_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((sub_step_88_1 + pub_r000463_3_1) + 11) & 127;
  int sub_step_106_2 = ((sub_step_88_2 + pub_r000463_3_2) + 11) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000463_11_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000463_11_2) & 127;
  st_var_2_1.buffer[1] = stage_v_106_1 & 15;
  st_var_2_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((sec_r000463_0_1 + pub_r000463_12_1) + 26) & 127;
  int sub_step_107_2 = ((sec_r000463_0_2 + pub_r000463_12_2) + 26) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000463_3_2) & 127;
  st_var_3_1.buffer[2] = stage_v_107_1 & 15;
  st_var_3_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((sub_step_90_1 + pub_r000463_15_1) + 10) & 127;
  int sub_step_108_2 = ((sub_step_90_2 + pub_r000463_15_2) + 10) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000463_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((sub_step_89_1 + pub_r000463_2_1) + 34) & 127;
  int sub_step_109_2 = ((sub_step_89_2 + pub_r000463_2_2) + 34) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000463_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((sec_r000463_13_1 + pub_r000463_6_1) + 31) & 127;
  int sub_step_110_2 = ((sec_r000463_13_2 + pub_r000463_6_2) + 31) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000463_8_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000463_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((sec_r000463_17_1 + pub_r000463_7_1) + 21) & 127;
  int sub_step_111_2 = ((sec_r000463_17_2 + pub_r000463_7_2) + 21) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000463_0_2) & 127;
  st_var_3_1.buffer[0] = stage_v_111_1 & 15;
  st_var_3_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((sub_step_95_1 + pub_r000463_1_1) + 11) & 127;
  int sub_step_112_2 = ((sub_step_95_2 + pub_r000463_1_2) + 11) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000463_9_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000463_9_2) & 127;
  st_var_0_1.buffer[1] = stage_v_112_1 & 15;
  st_var_0_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((sub_step_109_1 + pub_r000463_3_1) + 15) & 127;
  int sub_step_113_2 = ((sub_step_109_2 + pub_r000463_3_2) + 15) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000463_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_113_1 & 15;
  st_var_1_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((sub_step_92_1 + pub_r000463_6_1) + 32) & 127;
  int sub_step_114_2 = ((sub_step_92_2 + pub_r000463_6_2) + 32) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000463_4_2) & 127;
  st_var_2_1.buffer[0] = stage_v_114_1 & 15;
  st_var_2_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((sub_step_113_1 + pub_r000463_3_1) + 32) & 127;
  int sub_step_115_2 = ((sub_step_113_2 + pub_r000463_3_2) + 32) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000463_0_2) & 127;
  st_var_3_1.buffer[1] = stage_v_115_1 & 15;
  st_var_3_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((stage_v_103_1 + pub_r000463_5_1) + 10) & 127;
  int sub_step_116_2 = ((stage_v_103_2 + pub_r000463_5_2) + 10) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000463_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_116_1 & 15;
  st_var_0_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((sec_r000463_17_1 + pub_r000463_1_1) + 22) & 127;
  int sub_step_117_2 = ((sec_r000463_17_2 + pub_r000463_1_2) + 22) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000463_10_2) & 127;
  st_var_1_1.buffer[0] = stage_v_117_1 & 15;
  st_var_1_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((sec_r000463_5_1 + pub_r000463_13_1) + 23) & 127;
  int sub_step_118_2 = ((sec_r000463_5_2 + pub_r000463_13_2) + 23) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000463_3_2) & 127;
  st_var_2_1.buffer[1] = stage_v_118_1 & 15;
  st_var_2_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((stage_v_98_1 + pub_r000463_0_1) + 9) & 127;
  int sub_step_119_2 = ((stage_v_98_2 + pub_r000463_0_2) + 9) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000463_11_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000463_11_2) & 127;
  st_var_3_1.buffer[2] = stage_v_119_1 & 15;
  st_var_3_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((sub_step_104_1 + pub_r000463_8_1) + 15) & 127;
  int sub_step_120_2 = ((sub_step_104_2 + pub_r000463_8_2) + 15) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000463_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((sub_step_115_1 + pub_r000463_11_1) + 6) & 127;
  int sub_step_121_2 = ((sub_step_115_2 + pub_r000463_11_2) + 6) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000463_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sub_step_120_1 + pub_r000463_7_1) + 10) & 127;
  int sub_step_122_2 = ((sub_step_120_2 + pub_r000463_7_2) + 10) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000463_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((stage_v_108_1 + pub_r000463_12_1) + 30) & 127;
  int sub_step_123_2 = ((stage_v_108_2 + pub_r000463_12_2) + 30) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000463_6_2) & 127;
  st_var_3_1.buffer[0] = stage_v_123_1 & 15;
  st_var_3_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((sub_step_102_1 + pub_r000463_13_1) + 24) & 127;
  int sub_step_124_2 = ((sub_step_102_2 + pub_r000463_13_2) + 24) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000463_14_2) & 127;
  st_var_0_1.buffer[1] = stage_v_124_1 & 15;
  st_var_0_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((sec_r000463_1_1 + pub_r000463_1_1) + 21) & 127;
  int sub_step_125_2 = ((sec_r000463_1_2 + pub_r000463_1_2) + 21) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000463_5_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000463_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_125_1 & 15;
  st_var_1_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((stage_v_108_1 + pub_r000463_0_1) + 14) & 127;
  int sub_step_126_2 = ((stage_v_108_2 + pub_r000463_0_2) + 14) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000463_1_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000463_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_126_1 & 15;
  st_var_2_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((stage_v_101_1 + pub_r000463_7_1) + 26) & 127;
  int sub_step_127_2 = ((stage_v_101_2 + pub_r000463_7_2) + 26) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000463_2_2) & 127;
  st_var_3_1.buffer[1] = stage_v_127_1 & 15;
  st_var_3_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((sub_step_108_1 + pub_r000463_9_1) + 9) & 127;
  int sub_step_128_2 = ((sub_step_108_2 + pub_r000463_9_2) + 9) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000463_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_128_1 & 15;
  st_var_0_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((stage_v_121_1 + pub_r000463_13_1) + 8) & 127;
  int sub_step_129_2 = ((stage_v_121_2 + pub_r000463_13_2) + 8) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000463_9_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000463_9_2) & 127;
  st_var_1_1.buffer[0] = stage_v_129_1 & 15;
  st_var_1_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((sub_step_105_1 + pub_r000463_11_1) + 20) & 127;
  int sub_step_130_2 = ((sub_step_105_2 + pub_r000463_11_2) + 20) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000463_12_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000463_12_2) & 127;
  st_var_2_1.buffer[1] = stage_v_130_1 & 15;
  st_var_2_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((stage_v_99_1 + pub_r000463_1_1) + 17) & 127;
  int sub_step_131_2 = ((stage_v_99_2 + pub_r000463_1_2) + 17) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000463_2_2) & 127;
  st_var_3_1.buffer[2] = stage_v_131_1 & 15;
  st_var_3_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((sub_step_93_1 + pub_r000463_7_1) + 18) & 127;
  int sub_step_132_2 = ((sub_step_93_2 + pub_r000463_7_2) + 18) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000463_11_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000463_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((sub_step_125_1 + pub_r000463_15_1) + 8) & 127;
  int sub_step_133_2 = ((sub_step_125_2 + pub_r000463_15_2) + 8) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000463_5_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000463_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((sec_r000463_9_1 + pub_r000463_1_1) + 34) & 127;
  int sub_step_134_2 = ((sec_r000463_9_2 + pub_r000463_1_2) + 34) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000463_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((stage_v_122_1 + pub_r000463_2_1) + 16) & 127;
  int sub_step_135_2 = ((stage_v_122_2 + pub_r000463_2_2) + 16) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000463_0_2) & 127;
  st_var_3_1.buffer[0] = stage_v_135_1 & 15;
  st_var_3_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((sub_step_86_1 + pub_r000463_4_1) + 8) & 127;
  int sub_step_136_2 = ((sub_step_86_2 + pub_r000463_4_2) + 8) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000463_13_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000463_13_2) & 127;
  st_var_0_1.buffer[1] = stage_v_136_1 & 15;
  st_var_0_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((stage_v_136_1 + pub_r000463_1_1) + 33) & 127;
  int sub_step_137_2 = ((stage_v_136_2 + pub_r000463_1_2) + 33) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000463_3_2) & 127;
  st_var_1_1.buffer[2] = stage_v_137_1 & 15;
  st_var_1_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((stage_v_137_1 + pub_r000463_14_1) + 32) & 127;
  int sub_step_138_2 = ((stage_v_137_2 + pub_r000463_14_2) + 32) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000463_13_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000463_13_2) & 127;
  st_var_2_1.buffer[0] = stage_v_138_1 & 15;
  st_var_2_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((sec_r000463_16_1 + pub_r000463_8_1) + 8) & 127;
  int sub_step_139_2 = ((sec_r000463_16_2 + pub_r000463_8_2) + 8) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000463_7_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000463_7_2) & 127;
  st_var_3_1.buffer[1] = stage_v_139_1 & 15;
  st_var_3_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((sec_r000463_12_1 + pub_r000463_8_1) + 22) & 127;
  int sub_step_140_2 = ((sec_r000463_12_2 + pub_r000463_8_2) + 22) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000463_15_2) & 127;
  st_var_0_1.buffer[2] = stage_v_140_1 & 15;
  st_var_0_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sub_step_119_1 + pub_r000463_9_1) + 35) & 127;
  int sub_step_141_2 = ((sub_step_119_2 + pub_r000463_9_2) + 35) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000463_15_2) & 127;
  st_var_1_1.buffer[0] = stage_v_141_1 & 15;
  st_var_1_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((stage_v_117_1 + pub_r000463_7_1) + 9) & 127;
  int sub_step_142_2 = ((stage_v_117_2 + pub_r000463_7_2) + 9) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000463_4_2) & 127;
  st_var_2_1.buffer[1] = stage_v_142_1 & 15;
  st_var_2_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((sec_r000463_9_1 + pub_r000463_2_1) + 13) & 127;
  int sub_step_143_2 = ((sec_r000463_9_2 + pub_r000463_2_2) + 13) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000463_14_2) & 127;
  st_var_3_1.buffer[2] = stage_v_143_1 & 15;
  st_var_3_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((sec_r000463_11_1 + pub_r000463_12_1) + 6) & 127;
  int sub_step_144_2 = ((sec_r000463_11_2 + pub_r000463_12_2) + 6) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000463_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((sub_step_91_1 + pub_r000463_15_1) + 13) & 127;
  int sub_step_145_2 = ((sub_step_91_2 + pub_r000463_15_2) + 13) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000463_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((sub_step_128_1 + pub_r000463_14_1) + 27) & 127;
  int sub_step_146_2 = ((sub_step_128_2 + pub_r000463_14_2) + 27) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000463_13_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000463_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((stage_v_110_1 + pub_r000463_2_1) + 30) & 127;
  int sub_step_147_2 = ((stage_v_110_2 + pub_r000463_2_2) + 30) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000463_10_2) & 127;
  st_var_3_1.buffer[0] = stage_v_147_1 & 15;
  st_var_3_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((stage_v_93_1 + pub_r000463_10_1) + 11) & 127;
  int sub_step_148_2 = ((stage_v_93_2 + pub_r000463_10_2) + 11) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000463_4_2) & 127;
  st_var_0_1.buffer[1] = stage_v_148_1 & 15;
  st_var_0_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sec_r000463_16_1 + pub_r000463_13_1) + 20) & 127;
  int sub_step_149_2 = ((sec_r000463_16_2 + pub_r000463_13_2) + 20) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000463_5_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000463_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_149_1 & 15;
  st_var_1_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((sub_step_112_1 + pub_r000463_10_1) + 19) & 127;
  int sub_step_150_2 = ((sub_step_112_2 + pub_r000463_10_2) + 19) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000463_13_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000463_13_2) & 127;
  st_var_2_1.buffer[0] = stage_v_150_1 & 15;
  st_var_2_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((stage_v_107_1 + pub_r000463_1_1) + 9) & 127;
  int sub_step_151_2 = ((stage_v_107_2 + pub_r000463_1_2) + 9) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000463_3_2) & 127;
  st_var_3_1.buffer[1] = stage_v_151_1 & 15;
  st_var_3_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((sec_r000463_18_1 + pub_r000463_14_1) + 7) & 127;
  int sub_step_152_2 = ((sec_r000463_18_2 + pub_r000463_14_2) + 7) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000463_7_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000463_7_2) & 127;
  st_var_0_1.buffer[2] = stage_v_152_1 & 15;
  st_var_0_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((stage_v_116_1 + pub_r000463_12_1) + 15) & 127;
  int sub_step_153_2 = ((stage_v_116_2 + pub_r000463_12_2) + 15) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000463_4_2) & 127;
  st_var_1_1.buffer[0] = stage_v_153_1 & 15;
  st_var_1_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((sub_step_115_1 + pub_r000463_0_1) + 30) & 127;
  int sub_step_154_2 = ((sub_step_115_2 + pub_r000463_0_2) + 30) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000463_7_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000463_7_2) & 127;
  st_var_2_1.buffer[1] = stage_v_154_1 & 15;
  st_var_2_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((stage_v_139_1 + pub_r000463_12_1) + 13) & 127;
  int sub_step_155_2 = ((stage_v_139_2 + pub_r000463_12_2) + 13) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000463_15_2) & 127;
  st_var_3_1.buffer[2] = stage_v_155_1 & 15;
  st_var_3_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((sec_r000463_4_1 + pub_r000463_0_1) + 23) & 127;
  int sub_step_156_2 = ((sec_r000463_4_2 + pub_r000463_0_2) + 23) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000463_11_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000463_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((stage_v_122_1 + pub_r000463_8_1) + 32) & 127;
  int sub_step_157_2 = ((stage_v_122_2 + pub_r000463_8_2) + 32) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000463_11_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000463_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((sub_step_135_1 + pub_r000463_15_1) + 6) & 127;
  int sub_step_158_2 = ((sub_step_135_2 + pub_r000463_15_2) + 6) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000463_7_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000463_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((sec_r000463_12_1 + pub_r000463_5_1) + 35) & 127;
  int sub_step_159_2 = ((sec_r000463_12_2 + pub_r000463_5_2) + 35) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000463_3_2) & 127;
  st_var_3_1.buffer[0] = stage_v_159_1 & 15;
  st_var_3_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((stage_v_95_1 + pub_r000463_2_1) + 29) & 127;
  int sub_step_160_2 = ((stage_v_95_2 + pub_r000463_2_2) + 29) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000463_3_2) & 127;
  st_var_0_1.buffer[1] = stage_v_160_1 & 15;
  st_var_0_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((sub_step_157_1 + pub_r000463_5_1) + 11) & 127;
  int sub_step_161_2 = ((sub_step_157_2 + pub_r000463_5_2) + 11) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000463_5_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000463_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_161_1 & 15;
  st_var_1_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((sec_r000463_10_1 + pub_r000463_12_1) + 8) & 127;
  int sub_step_162_2 = ((sec_r000463_10_2 + pub_r000463_12_2) + 8) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000463_1_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000463_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_162_1 & 15;
  st_var_2_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((stage_v_94_1 + pub_r000463_3_1) + 19) & 127;
  int sub_step_163_2 = ((stage_v_94_2 + pub_r000463_3_2) + 19) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000463_3_2) & 127;
  st_var_3_1.buffer[1] = stage_v_163_1 & 15;
  st_var_3_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((stage_v_99_1 + pub_r000463_15_1) + 28) & 127;
  int sub_step_164_2 = ((stage_v_99_2 + pub_r000463_15_2) + 28) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000463_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_164_1 & 15;
  st_var_0_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((stage_v_158_1 + pub_r000463_13_1) + 14) & 127;
  int sub_step_165_2 = ((stage_v_158_2 + pub_r000463_13_2) + 14) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000463_15_2) & 127;
  st_var_1_1.buffer[0] = stage_v_165_1 & 15;
  st_var_1_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((sec_r000463_20_1 + pub_r000463_9_1) + 26) & 127;
  int sub_step_166_2 = ((sec_r000463_20_2 + pub_r000463_9_2) + 26) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000463_2_2) & 127;
  st_var_2_1.buffer[1] = stage_v_166_1 & 15;
  st_var_2_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((sec_r000463_14_1 + pub_r000463_14_1) + 27) & 127;
  int sub_step_167_2 = ((sec_r000463_14_2 + pub_r000463_14_2) + 27) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000463_3_2) & 127;
  st_var_3_1.buffer[2] = stage_v_167_1 & 15;
  st_var_3_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((stage_v_87_1 + pub_r000463_2_1) + 28) & 127;
  int sub_step_168_2 = ((stage_v_87_2 + pub_r000463_2_2) + 28) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000463_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((stage_v_138_1 + pub_r000463_1_1) + 11) & 127;
  int sub_step_169_2 = ((stage_v_138_2 + pub_r000463_1_2) + 11) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000463_13_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000463_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((stage_v_106_1 + pub_r000463_8_1) + 5) & 127;
  int sub_step_170_2 = ((stage_v_106_2 + pub_r000463_8_2) + 5) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000463_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((sec_r000463_14_1 + pub_r000463_2_1) + 27) & 127;
  int sub_step_171_2 = ((sec_r000463_14_2 + pub_r000463_2_2) + 27) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000463_10_2) & 127;
  st_var_3_1.buffer[0] = stage_v_171_1 & 15;
  st_var_3_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((sec_r000463_4_1 + pub_r000463_4_1) + 28) & 127;
  int sub_step_172_2 = ((sec_r000463_4_2 + pub_r000463_4_2) + 28) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000463_6_2) & 127;
  st_var_0_1.buffer[1] = stage_v_172_1 & 15;
  st_var_0_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((stage_v_136_1 + pub_r000463_2_1) + 15) & 127;
  int sub_step_173_2 = ((stage_v_136_2 + pub_r000463_2_2) + 15) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000463_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_173_1 & 15;
  st_var_1_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((sec_r000463_22_1 + pub_r000463_14_1) + 9) & 127;
  int sub_step_174_2 = ((sec_r000463_22_2 + pub_r000463_14_2) + 9) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000463_10_2) & 127;
  st_var_2_1.buffer[0] = stage_v_174_1 & 15;
  st_var_2_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((stage_v_164_1 + pub_r000463_4_1) + 9) & 127;
  int sub_step_175_2 = ((stage_v_164_2 + pub_r000463_4_2) + 9) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000463_1_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000463_1_2) & 127;
  st_var_3_1.buffer[1] = stage_v_175_1 & 15;
  st_var_3_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((stage_v_147_1 + pub_r000463_0_1) + 26) & 127;
  int sub_step_176_2 = ((stage_v_147_2 + pub_r000463_0_2) + 26) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000463_4_2) & 127;
  st_var_0_1.buffer[2] = stage_v_176_1 & 15;
  st_var_0_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((sub_step_134_1 + pub_r000463_15_1) + 31) & 127;
  int sub_step_177_2 = ((sub_step_134_2 + pub_r000463_15_2) + 31) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000463_2_2) & 127;
  st_var_1_1.buffer[0] = stage_v_177_1 & 15;
  st_var_1_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((sub_step_148_1 + pub_r000463_14_1) + 32) & 127;
  int sub_step_178_2 = ((sub_step_148_2 + pub_r000463_14_2) + 32) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000463_6_2) & 127;
  st_var_2_1.buffer[1] = stage_v_178_1 & 15;
  st_var_2_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((sub_step_173_1 + pub_r000463_3_1) + 20) & 127;
  int sub_step_179_2 = ((sub_step_173_2 + pub_r000463_3_2) + 20) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000463_0_2) & 127;
  st_var_3_1.buffer[2] = stage_v_179_1 & 15;
  st_var_3_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((sub_step_153_1 + pub_r000463_10_1) + 9) & 127;
  int sub_step_180_2 = ((sub_step_153_2 + pub_r000463_10_2) + 9) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000463_8_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000463_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((sec_r000463_15_1 + pub_r000463_4_1) + 5) & 127;
  int sub_step_181_2 = ((sec_r000463_15_2 + pub_r000463_4_2) + 5) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000463_8_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000463_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((sec_r000463_3_1 + pub_r000463_1_1) + 6) & 127;
  int sub_step_182_2 = ((sec_r000463_3_2 + pub_r000463_1_2) + 6) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000463_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((sec_r000463_12_1 + pub_r000463_7_1) + 31) & 127;
  int sub_step_183_2 = ((sec_r000463_12_2 + pub_r000463_7_2) + 31) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000463_6_2) & 127;
  st_var_3_1.buffer[0] = stage_v_183_1 & 15;
  st_var_3_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((stage_v_109_1 + pub_r000463_8_1) + 11) & 127;
  int sub_step_184_2 = ((stage_v_109_2 + pub_r000463_8_2) + 11) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000463_14_2) & 127;
  st_var_0_1.buffer[1] = stage_v_184_1 & 15;
  st_var_0_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((stage_v_167_1 + pub_r000463_2_1) + 28) & 127;
  int sub_step_185_2 = ((stage_v_167_2 + pub_r000463_2_2) + 28) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000463_5_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000463_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_185_1 & 15;
  st_var_1_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((sec_r000463_14_1 + pub_r000463_11_1) + 32) & 127;
  int sub_step_186_2 = ((sec_r000463_14_2 + pub_r000463_11_2) + 32) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000463_7_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000463_7_2) & 127;
  st_var_2_1.buffer[0] = stage_v_186_1 & 15;
  st_var_2_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((stage_v_176_1 + pub_r000463_3_1) + 31) & 127;
  int sub_step_187_2 = ((stage_v_176_2 + pub_r000463_3_2) + 31) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000463_2_2) & 127;
  st_var_3_1.buffer[1] = stage_v_187_1 & 15;
  st_var_3_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sec_r000463_1_1 + pub_r000463_3_1) + 25) & 127;
  int sub_step_188_2 = ((sec_r000463_1_2 + pub_r000463_3_2) + 25) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000463_0_2) & 127;
  st_var_0_1.buffer[2] = stage_v_188_1 & 15;
  st_var_0_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((stage_v_109_1 + pub_r000463_12_1) + 31) & 127;
  int sub_step_189_2 = ((stage_v_109_2 + pub_r000463_12_2) + 31) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000463_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_189_1 & 15;
  st_var_1_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((sec_r000463_12_1 + pub_r000463_3_1) + 19) & 127;
  int sub_step_190_2 = ((sec_r000463_12_2 + pub_r000463_3_2) + 19) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000463_10_2) & 127;
  st_var_2_1.buffer[1] = stage_v_190_1 & 15;
  st_var_2_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((sec_r000463_20_1 + pub_r000463_1_1) + 6) & 127;
  int sub_step_191_2 = ((sec_r000463_20_2 + pub_r000463_1_2) + 6) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000463_4_2) & 127;
  st_var_3_1.buffer[2] = stage_v_191_1 & 15;
  st_var_3_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((sub_step_181_1 + pub_r000463_7_1) + 20) & 127;
  int sub_step_192_2 = ((sub_step_181_2 + pub_r000463_7_2) + 20) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000463_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((stage_v_121_1 + pub_r000463_9_1) + 16) & 127;
  int sub_step_193_2 = ((stage_v_121_2 + pub_r000463_9_2) + 16) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000463_9_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000463_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((stage_v_118_1 + pub_r000463_12_1) + 35) & 127;
  int sub_step_194_2 = ((stage_v_118_2 + pub_r000463_12_2) + 35) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000463_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sec_r000463_8_1 + pub_r000463_7_1) + 14) & 127;
  int sub_step_195_2 = ((sec_r000463_8_2 + pub_r000463_7_2) + 14) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000463_0_2) & 127;
  st_var_3_1.buffer[0] = stage_v_195_1 & 15;
  st_var_3_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((sec_r000463_14_1 + pub_r000463_9_1) + 10) & 127;
  int sub_step_196_2 = ((sec_r000463_14_2 + pub_r000463_9_2) + 10) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000463_12_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000463_12_2) & 127;
  st_var_0_1.buffer[1] = stage_v_196_1 & 15;
  st_var_0_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((sec_r000463_1_1 + pub_r000463_13_1) + 22) & 127;
  int sub_step_197_2 = ((sec_r000463_1_2 + pub_r000463_13_2) + 22) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000463_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_197_1 & 15;
  st_var_1_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((sec_r000463_13_1 + pub_r000463_6_1) + 12) & 127;
  int sub_step_198_2 = ((sec_r000463_13_2 + pub_r000463_6_2) + 12) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000463_9_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000463_9_2) & 127;
  st_var_2_1.buffer[0] = stage_v_198_1 & 15;
  st_var_2_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((sub_step_84_1 + pub_r000463_7_1) + 20) & 127;
  int sub_step_199_2 = ((sub_step_84_2 + pub_r000463_7_2) + 20) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000463_15_2) & 127;
  st_var_3_1.buffer[1] = stage_v_199_1 & 15;
  st_var_3_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((sub_step_190_1 + pub_r000463_13_1) + 14) & 127;
  int sub_step_200_2 = ((sub_step_190_2 + pub_r000463_13_2) + 14) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000463_9_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000463_9_2) & 127;
  st_var_0_1.buffer[2] = stage_v_200_1 & 15;
  st_var_0_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sub_step_112_1 + pub_r000463_13_1) + 15) & 127;
  int sub_step_201_2 = ((sub_step_112_2 + pub_r000463_13_2) + 15) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000463_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_201_1 & 15;
  st_var_1_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((sub_step_192_1 + pub_r000463_10_1) + 22) & 127;
  int sub_step_202_2 = ((sub_step_192_2 + pub_r000463_10_2) + 22) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000463_14_2) & 127;
  st_var_2_1.buffer[1] = stage_v_202_1 & 15;
  st_var_2_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((sec_r000463_15_1 + pub_r000463_7_1) + 14) & 127;
  int sub_step_203_2 = ((sec_r000463_15_2 + pub_r000463_7_2) + 14) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000463_0_2) & 127;
  st_var_3_1.buffer[2] = stage_v_203_1 & 15;
  st_var_3_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((stage_v_183_1 + pub_r000463_3_1) + 26) & 127;
  int sub_step_204_2 = ((stage_v_183_2 + pub_r000463_3_2) + 26) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000463_1_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000463_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sec_r000463_12_1 + pub_r000463_10_1) + 11) & 127;
  int sub_step_205_2 = ((sec_r000463_12_2 + pub_r000463_10_2) + 11) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000463_1_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000463_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((stage_v_182_1 + pub_r000463_0_1) + 24) & 127;
  int sub_step_206_2 = ((stage_v_182_2 + pub_r000463_0_2) + 24) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000463_8_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000463_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((stage_v_170_1 + pub_r000463_15_1) + 22) & 127;
  int sub_step_207_2 = ((stage_v_170_2 + pub_r000463_15_2) + 22) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000463_13_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000463_13_2) & 127;
  st_var_3_1.buffer[0] = stage_v_207_1 & 15;
  st_var_3_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((sec_r000463_20_1 + pub_r000463_10_1) + 10) & 127;
  int sub_step_208_2 = ((sec_r000463_20_2 + pub_r000463_10_2) + 10) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000463_15_2) & 127;
  st_var_0_1.buffer[1] = stage_v_208_1 & 15;
  st_var_0_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((stage_v_204_1 + pub_r000463_0_1) + 27) & 127;
  int sub_step_209_2 = ((stage_v_204_2 + pub_r000463_0_2) + 27) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000463_4_2) & 127;
  st_var_1_1.buffer[2] = stage_v_209_1 & 15;
  st_var_1_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((stage_v_200_1 + pub_r000463_2_1) + 12) & 127;
  int sub_step_210_2 = ((stage_v_200_2 + pub_r000463_2_2) + 12) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000463_2_2) & 127;
  st_var_2_1.buffer[0] = stage_v_210_1 & 15;
  st_var_2_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sec_r000463_18_1 + pub_r000463_4_1) + 24) & 127;
  int sub_step_211_2 = ((sec_r000463_18_2 + pub_r000463_4_2) + 24) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000463_14_2) & 127;
  st_var_3_1.buffer[1] = stage_v_211_1 & 15;
  st_var_3_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((sub_step_91_1 + pub_r000463_13_1) + 16) & 127;
  int sub_step_212_2 = ((sub_step_91_2 + pub_r000463_13_2) + 16) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000463_0_2) & 127;
  st_var_0_1.buffer[2] = stage_v_212_1 & 15;
  st_var_0_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((sec_r000463_14_1 + pub_r000463_10_1) + 24) & 127;
  int sub_step_213_2 = ((sec_r000463_14_2 + pub_r000463_10_2) + 24) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000463_9_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000463_9_2) & 127;
  st_var_1_1.buffer[0] = stage_v_213_1 & 15;
  st_var_1_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((sec_r000463_11_1 + pub_r000463_6_1) + 25) & 127;
  int sub_step_214_2 = ((sec_r000463_11_2 + pub_r000463_6_2) + 25) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000463_7_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000463_7_2) & 127;
  st_var_2_1.buffer[1] = stage_v_214_1 & 15;
  st_var_2_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((sec_r000463_12_1 + pub_r000463_14_1) + 34) & 127;
  int sub_step_215_2 = ((sec_r000463_12_2 + pub_r000463_14_2) + 34) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000463_7_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000463_7_2) & 127;
  st_var_3_1.buffer[2] = stage_v_215_1 & 15;
  st_var_3_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((stage_v_164_1 + pub_r000463_12_1) + 28) & 127;
  int sub_step_216_2 = ((stage_v_164_2 + pub_r000463_12_2) + 28) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000463_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((stage_v_152_1 + pub_r000463_5_1) + 35) & 127;
  int sub_step_217_2 = ((stage_v_152_2 + pub_r000463_5_2) + 35) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000463_9_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000463_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((sec_r000463_2_1 + pub_r000463_0_1) + 31) & 127;
  int sub_step_218_2 = ((sec_r000463_2_2 + pub_r000463_0_2) + 31) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000463_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((sec_r000463_10_1 + pub_r000463_6_1) + 30) & 127;
  int sub_step_219_2 = ((sec_r000463_10_2 + pub_r000463_6_2) + 30) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000463_4_2) & 127;
  st_var_3_1.buffer[0] = stage_v_219_1 & 15;
  st_var_3_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((sec_r000463_6_1 + pub_r000463_12_1) + 18) & 127;
  int sub_step_220_2 = ((sec_r000463_6_2 + pub_r000463_12_2) + 18) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000463_8_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000463_8_2) & 127;
  st_var_0_1.buffer[1] = stage_v_220_1 & 15;
  st_var_0_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((stage_v_87_1 + pub_r000463_12_1) + 31) & 127;
  int sub_step_221_2 = ((stage_v_87_2 + pub_r000463_12_2) + 31) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000463_15_2) & 127;
  st_var_1_1.buffer[2] = stage_v_221_1 & 15;
  st_var_1_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((sec_r000463_8_1 + pub_r000463_2_1) + 27) & 127;
  int sub_step_222_2 = ((sec_r000463_8_2 + pub_r000463_2_2) + 27) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000463_14_2) & 127;
  st_var_2_1.buffer[0] = stage_v_222_1 & 15;
  st_var_2_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((sec_r000463_0_1 + pub_r000463_13_1) + 16) & 127;
  int sub_step_223_2 = ((sec_r000463_0_2 + pub_r000463_13_2) + 16) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000463_11_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000463_11_2) & 127;
  st_var_3_1.buffer[1] = stage_v_223_1 & 15;
  st_var_3_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((sub_step_124_1 + pub_r000463_7_1) + 34) & 127;
  int sub_step_224_2 = ((sub_step_124_2 + pub_r000463_7_2) + 34) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000463_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_224_1 & 15;
  st_var_0_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((stage_v_163_1 + pub_r000463_8_1) + 28) & 127;
  int sub_step_225_2 = ((stage_v_163_2 + pub_r000463_8_2) + 28) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000463_6_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000463_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_225_1 & 15;
  st_var_1_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sub_step_175_1 + pub_r000463_15_1) + 24) & 127;
  int sub_step_226_2 = ((sub_step_175_2 + pub_r000463_15_2) + 24) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000463_4_2) & 127;
  st_var_2_1.buffer[1] = stage_v_226_1 & 15;
  st_var_2_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((sub_step_183_1 + pub_r000463_2_1) + 32) & 127;
  int sub_step_227_2 = ((sub_step_183_2 + pub_r000463_2_2) + 32) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000463_12_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000463_12_2) & 127;
  st_var_3_1.buffer[2] = stage_v_227_1 & 15;
  st_var_3_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((sub_step_153_1 + pub_r000463_5_1) + 26) & 127;
  int sub_step_228_2 = ((sub_step_153_2 + pub_r000463_5_2) + 26) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000463_12_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000463_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((stage_v_198_1 + pub_r000463_15_1) + 11) & 127;
  int sub_step_229_2 = ((stage_v_198_2 + pub_r000463_15_2) + 11) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000463_9_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000463_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((stage_v_166_1 + pub_r000463_8_1) + 30) & 127;
  int sub_step_230_2 = ((stage_v_166_2 + pub_r000463_8_2) + 30) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000463_10_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000463_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_230_1 & 15;
  st_var_2_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int sub_step_231_1 = ((sec_r000463_1_1 + pub_r000463_0_1) + 9) & 127;
  int sub_step_231_2 = ((sec_r000463_1_2 + pub_r000463_0_2) + 9) & 127;
  int stage_v_231_1 = ((sub_step_231_1 * 2) + pub_r000463_15_1) & 127;
  int stage_v_231_2 = ((sub_step_231_2 * 2) + pub_r000463_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_231_1 & 15;
  st_var_3_2.buffer[0] = stage_v_231_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int sub_step_232_1 = ((sub_step_146_1 + pub_r000463_5_1) + 6) & 127;
  int sub_step_232_2 = ((sub_step_146_2 + pub_r000463_5_2) + 6) & 127;
  int stage_v_232_1 = ((sub_step_232_1 * 2) + pub_r000463_14_1) & 127;
  int stage_v_232_2 = ((sub_step_232_2 * 2) + pub_r000463_14_2) & 127;
  st_var_0_1.buffer[1] = stage_v_232_1 & 15;
  st_var_0_2.buffer[1] = stage_v_232_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int sub_step_233_1 = ((sec_r000463_20_1 + pub_r000463_9_1) + 27) & 127;
  int sub_step_233_2 = ((sec_r000463_20_2 + pub_r000463_9_2) + 27) & 127;
  int stage_v_233_1 = ((sub_step_233_1 * 2) + pub_r000463_3_1) & 127;
  int stage_v_233_2 = ((sub_step_233_2 * 2) + pub_r000463_3_2) & 127;
  st_var_1_1.buffer[2] = stage_v_233_1 & 15;
  st_var_1_2.buffer[2] = stage_v_233_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int sub_step_234_1 = ((stage_v_228_1 + pub_r000463_10_1) + 16) & 127;
  int sub_step_234_2 = ((stage_v_228_2 + pub_r000463_10_2) + 16) & 127;
  int stage_v_234_1 = ((sub_step_234_1 * 2) + pub_r000463_5_1) & 127;
  int stage_v_234_2 = ((sub_step_234_2 * 2) + pub_r000463_5_2) & 127;
  st_var_2_1.buffer[0] = stage_v_234_1 & 15;
  st_var_2_2.buffer[0] = stage_v_234_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int sub_step_235_1 = ((stage_v_202_1 + pub_r000463_8_1) + 27) & 127;
  int sub_step_235_2 = ((stage_v_202_2 + pub_r000463_8_2) + 27) & 127;
  int stage_v_235_1 = ((sub_step_235_1 * 2) + pub_r000463_5_1) & 127;
  int stage_v_235_2 = ((sub_step_235_2 * 2) + pub_r000463_5_2) & 127;
  st_var_3_1.buffer[1] = stage_v_235_1 & 15;
  st_var_3_2.buffer[1] = stage_v_235_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int sub_step_236_1 = ((stage_v_219_1 + pub_r000463_8_1) + 25) & 127;
  int sub_step_236_2 = ((stage_v_219_2 + pub_r000463_8_2) + 25) & 127;
  int stage_v_236_1 = ((sub_step_236_1 * 2) + pub_r000463_4_1) & 127;
  int stage_v_236_2 = ((sub_step_236_2 * 2) + pub_r000463_4_2) & 127;
  st_var_0_1.buffer[2] = stage_v_236_1 & 15;
  st_var_0_2.buffer[2] = stage_v_236_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int sub_step_237_1 = ((sub_step_159_1 + pub_r000463_14_1) + 9) & 127;
  int sub_step_237_2 = ((sub_step_159_2 + pub_r000463_14_2) + 9) & 127;
  int stage_v_237_1 = ((sub_step_237_1 * 2) + pub_r000463_0_1) & 127;
  int stage_v_237_2 = ((sub_step_237_2 * 2) + pub_r000463_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_237_1 & 15;
  st_var_1_2.buffer[0] = stage_v_237_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int sub_step_238_1 = ((sub_step_117_1 + pub_r000463_6_1) + 13) & 127;
  int sub_step_238_2 = ((sub_step_117_2 + pub_r000463_6_2) + 13) & 127;
  int stage_v_238_1 = ((sub_step_238_1 * 2) + pub_r000463_8_1) & 127;
  int stage_v_238_2 = ((sub_step_238_2 * 2) + pub_r000463_8_2) & 127;
  st_var_2_1.buffer[1] = stage_v_238_1 & 15;
  st_var_2_2.buffer[1] = stage_v_238_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int sub_step_239_1 = ((sub_step_169_1 + pub_r000463_8_1) + 14) & 127;
  int sub_step_239_2 = ((sub_step_169_2 + pub_r000463_8_2) + 14) & 127;
  int stage_v_239_1 = ((sub_step_239_1 * 2) + pub_r000463_13_1) & 127;
  int stage_v_239_2 = ((sub_step_239_2 * 2) + pub_r000463_13_2) & 127;
  st_var_3_1.buffer[2] = stage_v_239_1 & 15;
  st_var_3_2.buffer[2] = stage_v_239_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int sub_step_240_1 = ((sec_r000463_7_1 + pub_r000463_9_1) + 8) & 127;
  int sub_step_240_2 = ((sec_r000463_7_2 + pub_r000463_9_2) + 8) & 127;
  int stage_v_240_1 = ((sub_step_240_1 * 2) + pub_r000463_2_1) & 127;
  int stage_v_240_2 = ((sub_step_240_2 * 2) + pub_r000463_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_240_1 & 15;
  st_var_0_2.buffer[0] = stage_v_240_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000463_0_1 != sec_r000463_0_2);
  __CPROVER_assume(pub_r000463_14_1 == pub_r000463_14_2);
  __CPROVER_assume(sec_r000463_18_1 != sec_r000463_18_2);
  __CPROVER_assume(sec_r000463_4_1 != sec_r000463_4_2);
  __CPROVER_assume(pub_r000463_15_1 == pub_r000463_15_2);
  __CPROVER_assume(pub_r000463_7_1 == pub_r000463_7_2);
  __CPROVER_assume(pub_r000463_3_1 == pub_r000463_3_2);
  __CPROVER_assume(pub_r000463_4_1 == pub_r000463_4_2);
  __CPROVER_assume(sec_r000463_6_1 != sec_r000463_6_2);
  __CPROVER_assume(pub_r000463_6_1 == pub_r000463_6_2);
  __CPROVER_assume(pub_r000463_1_1 == pub_r000463_1_2);
  __CPROVER_assume(pub_r000463_2_1 == pub_r000463_2_2);
  __CPROVER_assume(pub_r000463_5_1 == pub_r000463_5_2);
  __CPROVER_assume(sec_r000463_22_1 != sec_r000463_22_2);
  __CPROVER_assume(sec_r000463_1_1 != sec_r000463_1_2);
  __CPROVER_assume(pub_r000463_0_1 == pub_r000463_0_2);
  __CPROVER_assume(pub_r000463_8_1 == pub_r000463_8_2);
  __CPROVER_assume(sec_r000463_3_1 != sec_r000463_3_2);
  __CPROVER_assume(sec_r000463_11_1 != sec_r000463_11_2);
  __CPROVER_assume(sec_r000463_8_1 != sec_r000463_8_2);
  __CPROVER_assume(sec_r000463_15_1 != sec_r000463_15_2);
  __CPROVER_assume(sec_r000463_13_1 != sec_r000463_13_2);
  __CPROVER_assume(pub_r000463_9_1 == pub_r000463_9_2);
  __CPROVER_assume(sec_r000463_12_1 != sec_r000463_12_2);
  __CPROVER_assume(sec_r000463_2_1 != sec_r000463_2_2);
  __CPROVER_assume(sec_r000463_9_1 != sec_r000463_9_2);
  __CPROVER_assume(pub_r000463_11_1 == pub_r000463_11_2);
  __CPROVER_assume(pub_r000463_13_1 == pub_r000463_13_2);
  __CPROVER_assume(sec_r000463_5_1 != sec_r000463_5_2);
  __CPROVER_assume(sec_r000463_19_1 != sec_r000463_19_2);
  __CPROVER_assume(sec_r000463_17_1 != sec_r000463_17_2);
  __CPROVER_assume(sec_r000463_16_1 != sec_r000463_16_2);
  __CPROVER_assume(sec_r000463_14_1 != sec_r000463_14_2);
  __CPROVER_assume(sec_r000463_20_1 != sec_r000463_20_2);
  __CPROVER_assume(pub_r000463_10_1 == pub_r000463_10_2);
  __CPROVER_assume(sec_r000463_7_1 != sec_r000463_7_2);
  __CPROVER_assume(pub_r000463_12_1 == pub_r000463_12_2);
  __CPROVER_assume(sec_r000463_21_1 != sec_r000463_21_2);
  __CPROVER_assume(sec_r000463_10_1 != sec_r000463_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.calib == st_var_3_2.calib);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.threshold == st_var_3_2.threshold);
  assert(st_var_3_1.reading == st_var_3_2.reading);
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
  assert(sub_step_84_1 == sub_step_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(sub_step_85_1 == sub_step_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(sub_step_86_1 == sub_step_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(sub_step_87_1 == sub_step_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(sub_step_88_1 == sub_step_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(sub_step_89_1 == sub_step_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(sub_step_90_1 == sub_step_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(sub_step_91_1 == sub_step_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(sub_step_92_1 == sub_step_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(sub_step_93_1 == sub_step_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(sub_step_94_1 == sub_step_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(sub_step_95_1 == sub_step_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(sub_step_96_1 == sub_step_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(sub_step_97_1 == sub_step_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(sub_step_98_1 == sub_step_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(sub_step_99_1 == sub_step_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(sub_step_100_1 == sub_step_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(sub_step_101_1 == sub_step_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(sub_step_102_1 == sub_step_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(sub_step_103_1 == sub_step_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(sub_step_104_1 == sub_step_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(sub_step_105_1 == sub_step_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(sub_step_106_1 == sub_step_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(sub_step_107_1 == sub_step_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(sub_step_108_1 == sub_step_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(sub_step_109_1 == sub_step_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(sub_step_110_1 == sub_step_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(sub_step_111_1 == sub_step_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(sub_step_112_1 == sub_step_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(sub_step_113_1 == sub_step_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(sub_step_114_1 == sub_step_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(sub_step_115_1 == sub_step_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(sub_step_116_1 == sub_step_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(sub_step_117_1 == sub_step_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(sub_step_118_1 == sub_step_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(sub_step_119_1 == sub_step_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(sub_step_120_1 == sub_step_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(sub_step_121_1 == sub_step_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(sub_step_122_1 == sub_step_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(sub_step_123_1 == sub_step_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(sub_step_124_1 == sub_step_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(sub_step_125_1 == sub_step_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(sub_step_126_1 == sub_step_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(sub_step_127_1 == sub_step_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(sub_step_128_1 == sub_step_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(sub_step_129_1 == sub_step_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(sub_step_130_1 == sub_step_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(sub_step_131_1 == sub_step_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(sub_step_132_1 == sub_step_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(sub_step_133_1 == sub_step_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(sub_step_134_1 == sub_step_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(sub_step_135_1 == sub_step_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(sub_step_136_1 == sub_step_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(sub_step_137_1 == sub_step_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(sub_step_138_1 == sub_step_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(sub_step_139_1 == sub_step_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(sub_step_140_1 == sub_step_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(sub_step_141_1 == sub_step_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(sub_step_142_1 == sub_step_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(sub_step_143_1 == sub_step_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(sub_step_144_1 == sub_step_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(sub_step_145_1 == sub_step_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(sub_step_146_1 == sub_step_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(sub_step_147_1 == sub_step_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(sub_step_148_1 == sub_step_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(sub_step_149_1 == sub_step_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(sub_step_150_1 == sub_step_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(sub_step_151_1 == sub_step_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(sub_step_152_1 == sub_step_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(sub_step_153_1 == sub_step_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(sub_step_154_1 == sub_step_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(sub_step_155_1 == sub_step_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(sub_step_156_1 == sub_step_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(sub_step_157_1 == sub_step_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(sub_step_158_1 == sub_step_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(sub_step_159_1 == sub_step_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(sub_step_160_1 == sub_step_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(sub_step_161_1 == sub_step_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(sub_step_162_1 == sub_step_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(sub_step_163_1 == sub_step_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(sub_step_164_1 == sub_step_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(sub_step_165_1 == sub_step_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(sub_step_166_1 == sub_step_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(sub_step_167_1 == sub_step_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(sub_step_168_1 == sub_step_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(sub_step_169_1 == sub_step_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(sub_step_170_1 == sub_step_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(sub_step_171_1 == sub_step_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(sub_step_172_1 == sub_step_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(sub_step_173_1 == sub_step_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(sub_step_174_1 == sub_step_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(sub_step_175_1 == sub_step_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(sub_step_176_1 == sub_step_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(sub_step_177_1 == sub_step_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(sub_step_178_1 == sub_step_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(sub_step_179_1 == sub_step_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(sub_step_180_1 == sub_step_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(sub_step_181_1 == sub_step_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(sub_step_182_1 == sub_step_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(sub_step_183_1 == sub_step_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(sub_step_184_1 == sub_step_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(sub_step_185_1 == sub_step_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(sub_step_186_1 == sub_step_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(sub_step_187_1 == sub_step_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(sub_step_188_1 == sub_step_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(sub_step_189_1 == sub_step_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(sub_step_190_1 == sub_step_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(sub_step_191_1 == sub_step_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(sub_step_192_1 == sub_step_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(sub_step_193_1 == sub_step_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(sub_step_194_1 == sub_step_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(sub_step_195_1 == sub_step_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(sub_step_196_1 == sub_step_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(sub_step_197_1 == sub_step_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(sub_step_198_1 == sub_step_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(sub_step_199_1 == sub_step_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(sub_step_200_1 == sub_step_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(sub_step_201_1 == sub_step_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(sub_step_202_1 == sub_step_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(sub_step_203_1 == sub_step_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(sub_step_204_1 == sub_step_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(sub_step_205_1 == sub_step_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(sub_step_206_1 == sub_step_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(sub_step_207_1 == sub_step_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(sub_step_208_1 == sub_step_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(sub_step_209_1 == sub_step_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(sub_step_210_1 == sub_step_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(sub_step_211_1 == sub_step_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(sub_step_212_1 == sub_step_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(sub_step_213_1 == sub_step_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(sub_step_214_1 == sub_step_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(sub_step_215_1 == sub_step_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(sub_step_216_1 == sub_step_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(sub_step_217_1 == sub_step_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(sub_step_218_1 == sub_step_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(sub_step_219_1 == sub_step_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(sub_step_220_1 == sub_step_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(sub_step_221_1 == sub_step_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(sub_step_222_1 == sub_step_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(sub_step_223_1 == sub_step_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(sub_step_224_1 == sub_step_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(sub_step_225_1 == sub_step_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(sub_step_226_1 == sub_step_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(sub_step_227_1 == sub_step_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(sub_step_228_1 == sub_step_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(sub_step_229_1 == sub_step_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(sub_step_230_1 == sub_step_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(sub_step_231_1 == sub_step_231_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(sub_step_232_1 == sub_step_232_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(sub_step_233_1 == sub_step_233_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(sub_step_234_1 == sub_step_234_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(sub_step_235_1 == sub_step_235_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(sub_step_236_1 == sub_step_236_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(sub_step_237_1 == sub_step_237_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(sub_step_238_1 == sub_step_238_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(sub_step_239_1 == sub_step_239_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(sub_step_240_1 == sub_step_240_2);
  assert(stage_v_240_1 == stage_v_240_2);
}


