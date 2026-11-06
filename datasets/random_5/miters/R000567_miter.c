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
struct AudioFrame_R000567_6713_0
{
  int rms;
  int channels;
  int gain;
  int sample_rate;
  unsigned char peak;
  int buffer[3];
};
struct Vector3D_R000567_6713_1
{
  short norm_sq;
  int heading;
  unsigned char coord_z;
  int buffer[3];
};
struct FilterState_R000567_6713_2
{
  short mode;
  unsigned char gain_db;
  short cutoff;
  int prev_in;
  short prev_out;
  unsigned char damping;
  int buffer[3];
};
union TelemetryField_R000567_6713_0
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
void fn_R000567_6713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int threshold_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_17_1)
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

  switch (threshold_17_2)
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

  int window_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_73_1) & 63;
  aux_2 = (aux_2 + window_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_21_1 = local_arr_1[aux_1 % 3];
  int offset_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_17_1 == threshold_17_2);
  assert(window_73_1 == window_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_21_1 == offset_21_2);
}

int fn_R000567_6713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int threshold_17 = (aux + st.buffer[1]) & 3;
  switch (threshold_17)
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

  int window_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_73) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_21 = local_arr[aux % 3];
  acc = (acc + (offset_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000567_6713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000567_6713_0 st_1 = {0};
  struct AudioFrame_R000567_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int damping_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_80_1)
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

  switch (damping_80_2)
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
  int mask_31_1 = local_arr_1[aux_1 % 3];
  int mask_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_31_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_70_1 > 39)
  {
    acc_1 = ((acc_1 + (tracker_70_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_70_2 > 39)
  {
    acc_2 = ((acc_2 + (tracker_70_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_80_1 == damping_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_31_1 == mask_31_2);
  assert(tracker_70_1 == tracker_70_2);
}

int fn_R000567_6713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000567_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int damping_80 = (aux + st.buffer[1]) & 3;
  switch (damping_80)
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
  int mask_31 = local_arr[aux % 3];
  acc = (acc + (mask_31 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_70 > 39)
  {
    acc = ((acc + (tracker_70 * 2)) + 5) & 127;
    aux ^= tracker_70 & 15;
  }
  else
  {
    acc = ((acc - tracker_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000567_6713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int mask_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_24_1 > 49)
  {
    acc_1 = ((acc_1 + (mask_24_1 * 2)) + 5) & 127;
    aux_1 ^= mask_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_24_2 > 49)
  {
    acc_2 = ((acc_2 + (mask_24_2 * 2)) + 5) & 127;
    aux_2 ^= mask_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_47_1) & 63;
  aux_2 = (aux_2 + scale_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_24_1 == mask_24_2);
  assert(scale_47_1 == scale_47_2);
}

int fn_R000567_6713_2(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int mask_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_24 > 49)
  {
    acc = ((acc + (mask_24 * 2)) + 5) & 127;
    aux ^= mask_24 & 15;
  }
  else
  {
    acc = ((acc - mask_24) + 11) & 127;
    aux += 3;
  }
  int scale_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000567_6713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int residue_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_93_1 > 44)
  {
    acc_1 = ((acc_1 + (residue_93_1 * 2)) + 5) & 127;
    aux_1 ^= residue_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_93_2 > 44)
  {
    acc_2 = ((acc_2 + (residue_93_2 * 2)) + 5) & 127;
    aux_2 ^= residue_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_66_1) & 63;
  aux_2 = (aux_2 + delta_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_93_1 == residue_93_2);
  assert(delta_66_1 == delta_66_2);
}

int fn_R000567_6713_3(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int residue_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_93 > 44)
  {
    acc = ((acc + (residue_93 * 2)) + 5) & 127;
    aux ^= residue_93 & 15;
  }
  else
  {
    acc = ((acc - residue_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000567_6713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st_1 = {0};
  struct FilterState_R000567_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int stride_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_35_1) & 63;
  aux_2 = (aux_2 + stride_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_97_1 > 41)
  {
    acc_1 = ((acc_1 + (parity_97_1 * 2)) + 5) & 127;
    aux_1 ^= parity_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_97_2 > 41)
  {
    acc_2 = ((acc_2 + (parity_97_2 * 2)) + 5) & 127;
    aux_2 ^= parity_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_97_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_35_1 == stride_35_2);
  assert(parity_97_1 == parity_97_2);
}

int fn_R000567_6713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int stride_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_35) & 63;
  acc ^= aux;
  int parity_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_97 > 41)
  {
    acc = ((acc + (parity_97 * 2)) + 5) & 127;
    aux ^= parity_97 & 15;
  }
  else
  {
    acc = ((acc - parity_97) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000567_6713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st_1 = {0};
  struct FilterState_R000567_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tally_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_62_1) & 63;
  aux_2 = (aux_2 + tally_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_51_1 = local_arr_1[aux_1 % 3];
  int stride_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_51_2 * 2)) & 127;
  int accumulator_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_83_1)
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

  switch (accumulator_83_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_62_1 == tally_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_51_1 == stride_51_2);
  assert(accumulator_83_1 == accumulator_83_2);
}

int fn_R000567_6713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tally_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_62) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_51 = local_arr[aux % 3];
  acc = (acc + (stride_51 * 2)) & 127;
  int accumulator_83 = (aux + st.buffer[1]) & 3;
  switch (accumulator_83)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000567_6713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_84_1 > 35)
  {
    acc_1 = ((acc_1 + (offset_84_1 * 2)) + 5) & 127;
    aux_1 ^= offset_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_84_2 > 35)
  {
    acc_2 = ((acc_2 + (offset_84_2 * 2)) + 5) & 127;
    aux_2 ^= offset_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_99_1 = local_arr_1[aux_1 % 3];
  int metric_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_84_1 == offset_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_99_1 == metric_99_2);
}

int fn_R000567_6713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_84 > 35)
  {
    acc = ((acc + (offset_84 * 2)) + 5) & 127;
    aux ^= offset_84 & 15;
  }
  else
  {
    acc = ((acc - offset_84) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_99 = local_arr[aux % 3];
  acc = (acc + (metric_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000567_6713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st_1 = {0};
  struct FilterState_R000567_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_67_1) & 63;
  aux_2 = (aux_2 + factor_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_67_1 == factor_67_2);
}

int fn_R000567_6713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_67) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000567_6713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st_1 = {0};
  struct FilterState_R000567_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_47_1 > 44)
  {
    acc_1 = ((acc_1 + (coefficient_47_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_47_2 > 44)
  {
    acc_2 = ((acc_2 + (coefficient_47_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_23_1)
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

  switch (anchor_23_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_47_1 == coefficient_47_2);
  assert(anchor_23_1 == anchor_23_2);
}

int fn_R000567_6713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_47 > 44)
  {
    acc = ((acc + (coefficient_47 * 2)) + 5) & 127;
    aux ^= coefficient_47 & 15;
  }
  else
  {
    acc = ((acc - coefficient_47) + 11) & 127;
    aux += 3;
  }
  int anchor_23 = (aux + st.buffer[1]) & 3;
  switch (anchor_23)
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

void fn_R000567_6713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int vector_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_67_1)
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

  switch (vector_67_2)
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

  int damping_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_84_1) & 63;
  aux_2 = (aux_2 + damping_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_53_1 = local_arr_1[aux_1 % 3];
  int quotient_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_53_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_67_1 == vector_67_2);
  assert(damping_84_1 == damping_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_53_1 == quotient_53_2);
}

int fn_R000567_6713_9(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int vector_67 = (aux + st.buffer[1]) & 3;
  switch (vector_67)
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

  int damping_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_84) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_53 = local_arr[aux % 3];
  acc = (acc + (quotient_53 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000567_6713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quotient_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_16_1) & 63;
  aux_2 = (aux_2 + quotient_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_32_1 = local_arr_1[aux_1 % 3];
  int cursor_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_16_1 == quotient_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_32_1 == cursor_32_2);
}

int fn_R000567_6713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quotient_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_16) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_32 = local_arr[aux % 3];
  acc = (acc + (cursor_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000567_6713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st_1 = {0};
  struct FilterState_R000567_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int checksum_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_39_1) & 63;
  aux_2 = (aux_2 + checksum_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_36_1)
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

  switch (coefficient_36_2)
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

  int factor_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_96_1 > 28)
  {
    acc_1 = ((acc_1 + (factor_96_1 * 2)) + 5) & 127;
    aux_1 ^= factor_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_96_2 > 28)
  {
    acc_2 = ((acc_2 + (factor_96_2 * 2)) + 5) & 127;
    aux_2 ^= factor_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_39_1 == checksum_39_2);
  assert(coefficient_36_1 == coefficient_36_2);
  assert(factor_96_1 == factor_96_2);
}

int fn_R000567_6713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int checksum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_39) & 63;
  acc ^= aux;
  int coefficient_36 = (aux + st.buffer[1]) & 3;
  switch (coefficient_36)
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

  int factor_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_96 > 28)
  {
    acc = ((acc + (factor_96 * 2)) + 5) & 127;
    aux ^= factor_96 & 15;
  }
  else
  {
    acc = ((acc - factor_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000567_6713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_87_1)
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

  switch (mask_87_2)
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

  int delta_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_29_1 > 28)
  {
    acc_1 = ((acc_1 + (delta_29_1 * 2)) + 5) & 127;
    aux_1 ^= delta_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_29_2 > 28)
  {
    acc_2 = ((acc_2 + (delta_29_2 * 2)) + 5) & 127;
    aux_2 ^= delta_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_87_1 == mask_87_2);
  assert(delta_29_1 == delta_29_2);
}

int fn_R000567_6713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_87 = (aux + st.buffer[1]) & 3;
  switch (mask_87)
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

  int delta_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_29 > 28)
  {
    acc = ((acc + (delta_29 * 2)) + 5) & 127;
    aux ^= delta_29 & 15;
  }
  else
  {
    acc = ((acc - delta_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000567_6713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int phase_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_67_1 > 43)
  {
    acc_1 = ((acc_1 + (phase_67_1 * 2)) + 5) & 127;
    aux_1 ^= phase_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_67_2 > 43)
  {
    acc_2 = ((acc_2 + (phase_67_2 * 2)) + 5) & 127;
    aux_2 ^= phase_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_82_1 = local_arr_1[aux_1 % 3];
  int stride_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_82_2 * 2)) & 127;
  int accumulator_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_76_1)
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

  switch (accumulator_76_2)
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

  int segment_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_26_1) & 63;
  aux_2 = (aux_2 + segment_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_67_1 == phase_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_82_1 == stride_82_2);
  assert(accumulator_76_1 == accumulator_76_2);
  assert(segment_26_1 == segment_26_2);
}

int fn_R000567_6713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int phase_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_67 > 43)
  {
    acc = ((acc + (phase_67 * 2)) + 5) & 127;
    aux ^= phase_67 & 15;
  }
  else
  {
    acc = ((acc - phase_67) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_82 = local_arr[aux % 3];
  acc = (acc + (stride_82 * 2)) & 127;
  int accumulator_76 = (aux + st.buffer[1]) & 3;
  switch (accumulator_76)
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

  int segment_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000567_6713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st_1 = {0};
  struct FilterState_R000567_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_27_1 > 47)
  {
    acc_1 = ((acc_1 + (damping_27_1 * 2)) + 5) & 127;
    aux_1 ^= damping_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_27_2 > 47)
  {
    acc_2 = ((acc_2 + (damping_27_2 * 2)) + 5) & 127;
    aux_2 ^= damping_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_30_1 = local_arr_1[aux_1 % 3];
  int segment_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_30_2 * 2)) & 127;
  int mask_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_26_1)
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

  switch (mask_26_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_27_1 == damping_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_30_1 == segment_30_2);
  assert(mask_26_1 == mask_26_2);
}

int fn_R000567_6713_14(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000567_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_27 > 47)
  {
    acc = ((acc + (damping_27 * 2)) + 5) & 127;
    aux ^= damping_27 & 15;
  }
  else
  {
    acc = ((acc - damping_27) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_30 = local_arr[aux % 3];
  acc = (acc + (segment_30 * 2)) & 127;
  int mask_26 = (aux + st.buffer[1]) & 3;
  switch (mask_26)
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

void fn_R000567_6713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_88_1 = local_arr_1[aux_1 % 3];
  int accumulator_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_88_2 * 2)) & 127;
  int delta_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_26_1)
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

  switch (delta_26_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_88_1 == accumulator_88_2);
  assert(delta_26_1 == delta_26_2);
}

int fn_R000567_6713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int accumulator_88 = local_arr[aux % 3];
  acc = (acc + (accumulator_88 * 2)) & 127;
  int delta_26 = (aux + st.buffer[1]) & 3;
  switch (delta_26)
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

void fn_R000567_6713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000567_6713_0 st_1 = {0};
  struct AudioFrame_R000567_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_22_1 = local_arr_1[aux_1 % 3];
  int scale_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_22_2 * 2)) & 127;
  int threshold_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_37_1)
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

  switch (threshold_37_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_22_1 == scale_22_2);
  assert(threshold_37_1 == threshold_37_2);
}

int fn_R000567_6713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000567_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int scale_22 = local_arr[aux % 3];
  acc = (acc + (scale_22 * 2)) & 127;
  int threshold_37 = (aux + st.buffer[1]) & 3;
  switch (threshold_37)
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

void fn_R000567_6713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st_1 = {0};
  struct Vector3D_R000567_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int metric_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_65_1) & 63;
  aux_2 = (aux_2 + metric_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_77_1 > 26)
  {
    acc_1 = ((acc_1 + (stride_77_1 * 2)) + 5) & 127;
    aux_1 ^= stride_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_77_2 > 26)
  {
    acc_2 = ((acc_2 + (stride_77_2 * 2)) + 5) & 127;
    aux_2 ^= stride_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_33_1)
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

  switch (accumulator_33_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_65_1 == metric_65_2);
  assert(stride_77_1 == stride_77_2);
  assert(accumulator_33_1 == accumulator_33_2);
}

int fn_R000567_6713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000567_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int metric_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_65) & 63;
  acc ^= aux;
  int stride_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_77 > 26)
  {
    acc = ((acc + (stride_77 * 2)) + 5) & 127;
    aux ^= stride_77 & 15;
  }
  else
  {
    acc = ((acc - stride_77) + 11) & 127;
    aux += 3;
  }
  int accumulator_33 = (aux + st.buffer[1]) & 3;
  switch (accumulator_33)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000567_0_1;
  int sec_r000567_0_2;
  int sec_r000567_1_1;
  int sec_r000567_1_2;
  int sec_r000567_2_1;
  int sec_r000567_2_2;
  int sec_r000567_3_1;
  int sec_r000567_3_2;
  int sec_r000567_4_1;
  int sec_r000567_4_2;
  int sec_r000567_5_1;
  int sec_r000567_5_2;
  int sec_r000567_6_1;
  int sec_r000567_6_2;
  int sec_r000567_7_1;
  int sec_r000567_7_2;
  int sec_r000567_8_1;
  int sec_r000567_8_2;
  int sec_r000567_9_1;
  int sec_r000567_9_2;
  int sec_r000567_10_1;
  int sec_r000567_10_2;
  int sec_r000567_11_1;
  int sec_r000567_11_2;
  int sec_r000567_12_1;
  int sec_r000567_12_2;
  int sec_r000567_13_1;
  int sec_r000567_13_2;
  int sec_r000567_14_1;
  int sec_r000567_14_2;
  int sec_r000567_15_1;
  int sec_r000567_15_2;
  int sec_r000567_16_1;
  int sec_r000567_16_2;
  int sec_r000567_17_1;
  int sec_r000567_17_2;
  int sec_r000567_18_1;
  int sec_r000567_18_2;
  int pub_r000567_0_1;
  int pub_r000567_0_2;
  int pub_r000567_1_1;
  int pub_r000567_1_2;
  int pub_r000567_2_1;
  int pub_r000567_2_2;
  int pub_r000567_3_1;
  int pub_r000567_3_2;
  int pub_r000567_4_1;
  int pub_r000567_4_2;
  int pub_r000567_5_1;
  int pub_r000567_5_2;
  int pub_r000567_6_1;
  int pub_r000567_6_2;
  int pub_r000567_7_1;
  int pub_r000567_7_2;
  int pub_r000567_8_1;
  int pub_r000567_8_2;
  int pub_r000567_9_1;
  int pub_r000567_9_2;
  int pub_r000567_10_1;
  int pub_r000567_10_2;
  int pub_r000567_11_1;
  int pub_r000567_11_2;
  int pub_r000567_12_1;
  int pub_r000567_12_2;
  int pub_r000567_13_1;
  int pub_r000567_13_2;
  int pub_r000567_14_1;
  int pub_r000567_14_2;
  int pub_r000567_15_1;
  int pub_r000567_15_2;
  int pub_r000567_16_1;
  int pub_r000567_16_2;
  int pub_r000567_17_1;
  int pub_r000567_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000567_0_1 >= (-100)) && (pub_r000567_0_1 <= 100));
  __CPROVER_assume((pub_r000567_0_2 >= (-100)) && (pub_r000567_0_2 <= 100));
  __CPROVER_assume((pub_r000567_1_1 >= (-100)) && (pub_r000567_1_1 <= 100));
  __CPROVER_assume((pub_r000567_1_2 >= (-100)) && (pub_r000567_1_2 <= 100));
  __CPROVER_assume((pub_r000567_2_1 >= (-100)) && (pub_r000567_2_1 <= 100));
  __CPROVER_assume((pub_r000567_2_2 >= (-100)) && (pub_r000567_2_2 <= 100));
  __CPROVER_assume((pub_r000567_3_1 >= (-100)) && (pub_r000567_3_1 <= 100));
  __CPROVER_assume((pub_r000567_3_2 >= (-100)) && (pub_r000567_3_2 <= 100));
  __CPROVER_assume((pub_r000567_4_1 >= (-100)) && (pub_r000567_4_1 <= 100));
  __CPROVER_assume((pub_r000567_4_2 >= (-100)) && (pub_r000567_4_2 <= 100));
  __CPROVER_assume((pub_r000567_5_1 >= (-100)) && (pub_r000567_5_1 <= 100));
  __CPROVER_assume((pub_r000567_5_2 >= (-100)) && (pub_r000567_5_2 <= 100));
  __CPROVER_assume((pub_r000567_6_1 >= (-100)) && (pub_r000567_6_1 <= 100));
  __CPROVER_assume((pub_r000567_6_2 >= (-100)) && (pub_r000567_6_2 <= 100));
  __CPROVER_assume((pub_r000567_7_1 >= (-100)) && (pub_r000567_7_1 <= 100));
  __CPROVER_assume((pub_r000567_7_2 >= (-100)) && (pub_r000567_7_2 <= 100));
  __CPROVER_assume((pub_r000567_8_1 >= (-100)) && (pub_r000567_8_1 <= 100));
  __CPROVER_assume((pub_r000567_8_2 >= (-100)) && (pub_r000567_8_2 <= 100));
  __CPROVER_assume((pub_r000567_9_1 >= (-100)) && (pub_r000567_9_1 <= 100));
  __CPROVER_assume((pub_r000567_9_2 >= (-100)) && (pub_r000567_9_2 <= 100));
  __CPROVER_assume((pub_r000567_10_1 >= (-100)) && (pub_r000567_10_1 <= 100));
  __CPROVER_assume((pub_r000567_10_2 >= (-100)) && (pub_r000567_10_2 <= 100));
  __CPROVER_assume((pub_r000567_11_1 >= (-100)) && (pub_r000567_11_1 <= 100));
  __CPROVER_assume((pub_r000567_11_2 >= (-100)) && (pub_r000567_11_2 <= 100));
  __CPROVER_assume((pub_r000567_12_1 >= (-100)) && (pub_r000567_12_1 <= 100));
  __CPROVER_assume((pub_r000567_12_2 >= (-100)) && (pub_r000567_12_2 <= 100));
  __CPROVER_assume((pub_r000567_13_1 >= (-100)) && (pub_r000567_13_1 <= 100));
  __CPROVER_assume((pub_r000567_13_2 >= (-100)) && (pub_r000567_13_2 <= 100));
  __CPROVER_assume((pub_r000567_14_1 >= (-100)) && (pub_r000567_14_1 <= 100));
  __CPROVER_assume((pub_r000567_14_2 >= (-100)) && (pub_r000567_14_2 <= 100));
  __CPROVER_assume((pub_r000567_15_1 >= (-100)) && (pub_r000567_15_1 <= 100));
  __CPROVER_assume((pub_r000567_15_2 >= (-100)) && (pub_r000567_15_2 <= 100));
  __CPROVER_assume((pub_r000567_16_1 >= (-100)) && (pub_r000567_16_1 <= 100));
  __CPROVER_assume((pub_r000567_16_2 >= (-100)) && (pub_r000567_16_2 <= 100));
  __CPROVER_assume((pub_r000567_17_1 >= (-100)) && (pub_r000567_17_1 <= 100));
  __CPROVER_assume((pub_r000567_17_2 >= (-100)) && (pub_r000567_17_2 <= 100));
  __CPROVER_assume((sec_r000567_0_1 >= 0) && (sec_r000567_0_1 <= 255));
  __CPROVER_assume((sec_r000567_0_2 >= 0) && (sec_r000567_0_2 <= 255));
  __CPROVER_assume((sec_r000567_1_1 >= 0) && (sec_r000567_1_1 <= 255));
  __CPROVER_assume((sec_r000567_1_2 >= 0) && (sec_r000567_1_2 <= 255));
  __CPROVER_assume((sec_r000567_2_1 >= 0) && (sec_r000567_2_1 <= 255));
  __CPROVER_assume((sec_r000567_2_2 >= 0) && (sec_r000567_2_2 <= 255));
  __CPROVER_assume((sec_r000567_3_1 >= 0) && (sec_r000567_3_1 <= 255));
  __CPROVER_assume((sec_r000567_3_2 >= 0) && (sec_r000567_3_2 <= 255));
  __CPROVER_assume((sec_r000567_4_1 >= 0) && (sec_r000567_4_1 <= 255));
  __CPROVER_assume((sec_r000567_4_2 >= 0) && (sec_r000567_4_2 <= 255));
  __CPROVER_assume((sec_r000567_5_1 >= 0) && (sec_r000567_5_1 <= 255));
  __CPROVER_assume((sec_r000567_5_2 >= 0) && (sec_r000567_5_2 <= 255));
  __CPROVER_assume((sec_r000567_6_1 >= 0) && (sec_r000567_6_1 <= 255));
  __CPROVER_assume((sec_r000567_6_2 >= 0) && (sec_r000567_6_2 <= 255));
  __CPROVER_assume((sec_r000567_7_1 >= 0) && (sec_r000567_7_1 <= 255));
  __CPROVER_assume((sec_r000567_7_2 >= 0) && (sec_r000567_7_2 <= 255));
  __CPROVER_assume((sec_r000567_8_1 >= 0) && (sec_r000567_8_1 <= 255));
  __CPROVER_assume((sec_r000567_8_2 >= 0) && (sec_r000567_8_2 <= 255));
  __CPROVER_assume((sec_r000567_9_1 >= 0) && (sec_r000567_9_1 <= 255));
  __CPROVER_assume((sec_r000567_9_2 >= 0) && (sec_r000567_9_2 <= 255));
  __CPROVER_assume((sec_r000567_10_1 >= 0) && (sec_r000567_10_1 <= 255));
  __CPROVER_assume((sec_r000567_10_2 >= 0) && (sec_r000567_10_2 <= 255));
  __CPROVER_assume((sec_r000567_11_1 >= 0) && (sec_r000567_11_1 <= 255));
  __CPROVER_assume((sec_r000567_11_2 >= 0) && (sec_r000567_11_2 <= 255));
  __CPROVER_assume((sec_r000567_12_1 >= 0) && (sec_r000567_12_1 <= 255));
  __CPROVER_assume((sec_r000567_12_2 >= 0) && (sec_r000567_12_2 <= 255));
  __CPROVER_assume((sec_r000567_13_1 >= 0) && (sec_r000567_13_1 <= 255));
  __CPROVER_assume((sec_r000567_13_2 >= 0) && (sec_r000567_13_2 <= 255));
  __CPROVER_assume((sec_r000567_14_1 >= 0) && (sec_r000567_14_1 <= 255));
  __CPROVER_assume((sec_r000567_14_2 >= 0) && (sec_r000567_14_2 <= 255));
  __CPROVER_assume((sec_r000567_15_1 >= 0) && (sec_r000567_15_1 <= 255));
  __CPROVER_assume((sec_r000567_15_2 >= 0) && (sec_r000567_15_2 <= 255));
  __CPROVER_assume((sec_r000567_16_1 >= 0) && (sec_r000567_16_1 <= 255));
  __CPROVER_assume((sec_r000567_16_2 >= 0) && (sec_r000567_16_2 <= 255));
  __CPROVER_assume((sec_r000567_17_1 >= 0) && (sec_r000567_17_1 <= 255));
  __CPROVER_assume((sec_r000567_17_2 >= 0) && (sec_r000567_17_2 <= 255));
  __CPROVER_assume((sec_r000567_18_1 >= 0) && (sec_r000567_18_1 <= 255));
  __CPROVER_assume((sec_r000567_18_2 >= 0) && (sec_r000567_18_2 <= 255));
  struct AudioFrame_R000567_6713_0 st_var_0_1 = {0};
  struct AudioFrame_R000567_6713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000567_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000567_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000567_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000567_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000567_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000567_0_2 + 7) & 15;
  struct Vector3D_R000567_6713_1 st_var_1_1 = {0};
  struct Vector3D_R000567_6713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000567_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000567_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000567_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000567_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000567_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000567_0_2 + 9) & 15;
  struct FilterState_R000567_6713_2 st_var_2_1 = {0};
  struct FilterState_R000567_6713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000567_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000567_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000567_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000567_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000567_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000567_0_2 + 11) & 15;
  union TelemetryField_R000567_6713_0 u_var_1;
  union TelemetryField_R000567_6713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 52)
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
  if (stage_v_0_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 52)
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
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
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
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = ((st_var_1_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_1_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 28)
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
  if (stage_v_10_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 28)
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
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 17) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 18) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 55)
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
  if (stage_v_19_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 55)
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
  int stage_v_20_1 = (st_var_2_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_2_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = ((st_var_0_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_0_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 37)
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
  if (stage_v_27_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 37)
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
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((sec_r000567_11_1 & 1) != 0)
  {
    if ((sec_r000567_8_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((sec_r000567_11_2 & 1) != 0)
  {
    if ((sec_r000567_8_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000567_7_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000567_15_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000567_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000567_15_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000567_7_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000567_15_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000567_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000567_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((sec_r000567_11_1 & 1) != 0)
  {
    if ((sec_r000567_9_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000567_0_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000567_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000567_0_1 + 7) & 127;
  }
  if ((sec_r000567_11_2 & 1) != 0)
  {
    if ((sec_r000567_9_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000567_0_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000567_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000567_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((sec_r000567_0_1 & 1) != 0)
  {
    if ((sec_r000567_12_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((sec_r000567_0_2 & 1) != 0)
  {
    if ((sec_r000567_12_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((sec_r000567_0_1 & 1) != 0)
  {
    if ((sec_r000567_15_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000567_8_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000567_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000567_8_1 + 7) & 127;
  }
  if ((sec_r000567_0_2 & 1) != 0)
  {
    if ((sec_r000567_15_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000567_8_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000567_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000567_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000567_0_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000567_4_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000567_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000567_4_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000567_0_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000567_4_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000567_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000567_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000567_7_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000567_7_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000567_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000567_7_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000567_7_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000567_7_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000567_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000567_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((sec_r000567_16_1 & 1) != 0)
  {
    if ((sec_r000567_4_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000567_9_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000567_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000567_9_1 + 7) & 127;
  }
  if ((sec_r000567_16_2 & 1) != 0)
  {
    if ((sec_r000567_4_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000567_9_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000567_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000567_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000567_11_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000567_11_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000567_0_1 & 1) != 0)
  {
    if ((sec_r000567_18_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000567_8_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000567_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000567_8_1 + 7) & 127;
  }
  if ((sec_r000567_0_2 & 1) != 0)
  {
    if ((sec_r000567_18_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000567_8_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000567_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000567_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000567_9_1 & 1) != 0)
  {
    if ((sec_r000567_18_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000567_8_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000567_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000567_8_1 + 7) & 127;
  }
  if ((sec_r000567_9_2 & 1) != 0)
  {
    if ((sec_r000567_18_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000567_8_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000567_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000567_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000567_0_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000567_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000567_0_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000567_0_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000567_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000567_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000567_17_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000567_0_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000567_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000567_0_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000567_17_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000567_0_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000567_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000567_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000567_12_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000567_4_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000567_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000567_4_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000567_12_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000567_4_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000567_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000567_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((sec_r000567_10_1 & 1) != 0)
  {
    if ((sec_r000567_15_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000567_14_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000567_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000567_14_1 + 7) & 127;
  }
  if ((sec_r000567_10_2 & 1) != 0)
  {
    if ((sec_r000567_15_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000567_14_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000567_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000567_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000567_1_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000567_13_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000567_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000567_13_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000567_1_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000567_13_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000567_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000567_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000567_5_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000567_4_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000567_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000567_4_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000567_5_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000567_4_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000567_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000567_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000567_1_1 & 1) != 0)
  {
    if ((sec_r000567_3_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000567_4_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000567_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000567_4_1 + 7) & 127;
  }
  if ((sec_r000567_1_2 & 1) != 0)
  {
    if ((sec_r000567_3_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000567_4_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000567_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000567_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000567_5_1 & 1) != 0)
  {
    if ((sec_r000567_3_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000567_4_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000567_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000567_4_1 + 7) & 127;
  }
  if ((sec_r000567_5_2 & 1) != 0)
  {
    if ((sec_r000567_3_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000567_4_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000567_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000567_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000567_12_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000567_15_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000567_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000567_15_1 + 7) & 127;
  }
  if ((sec_r000567_12_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000567_15_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000567_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000567_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000567_9_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000567_8_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000567_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000567_8_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000567_9_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000567_8_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000567_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000567_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000567_14_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000567_16_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000567_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000567_16_1 + 7) & 127;
  }
  if ((sec_r000567_14_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000567_16_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000567_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000567_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000567_1_1 & 1) != 0)
  {
    if ((sec_r000567_3_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000567_8_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000567_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000567_8_1 + 7) & 127;
  }
  if ((sec_r000567_1_2 & 1) != 0)
  {
    if ((sec_r000567_3_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000567_8_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000567_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000567_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000567_7_1 & 1) != 0)
  {
    if ((sec_r000567_5_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000567_9_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000567_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000567_9_1 + 7) & 127;
  }
  if ((sec_r000567_7_2 & 1) != 0)
  {
    if ((sec_r000567_5_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000567_9_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000567_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000567_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000567_13_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000567_9_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000567_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000567_9_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000567_13_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000567_9_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000567_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000567_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000567_14_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000567_5_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000567_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000567_5_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000567_14_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000567_5_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000567_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000567_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000567_16_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000567_0_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000567_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000567_0_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000567_16_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000567_0_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000567_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000567_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000567_8_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000567_16_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000567_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000567_16_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000567_8_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000567_16_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000567_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000567_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000567_8_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000567_8_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000567_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000567_8_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000567_8_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000567_8_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000567_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000567_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000567_2_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000567_0_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000567_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000567_0_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000567_2_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000567_0_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000567_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000567_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000567_7_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000567_14_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000567_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000567_14_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000567_7_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000567_14_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000567_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000567_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000567_11_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000567_10_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000567_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000567_10_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000567_11_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000567_10_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000567_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000567_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000567_6_1 & 1) != 0)
  {
    if ((sec_r000567_2_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000567_16_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000567_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000567_16_1 + 7) & 127;
  }
  if ((sec_r000567_6_2 & 1) != 0)
  {
    if ((sec_r000567_2_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000567_16_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000567_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000567_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000567_10_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000567_7_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000567_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000567_7_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000567_10_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000567_7_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000567_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000567_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((sec_r000567_4_1 & 1) != 0)
  {
    if ((sec_r000567_12_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((sec_r000567_4_2 & 1) != 0)
  {
    if ((sec_r000567_12_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000567_8_1 & 1) != 0)
  {
    if ((sec_r000567_4_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000567_7_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000567_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000567_7_1 + 7) & 127;
  }
  if ((sec_r000567_8_2 & 1) != 0)
  {
    if ((sec_r000567_4_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000567_7_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000567_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000567_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000567_8_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000567_2_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000567_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000567_2_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000567_8_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000567_2_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000567_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000567_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000567_14_1 & 1) != 0)
  {
    if ((sec_r000567_14_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((sec_r000567_14_2 & 1) != 0)
  {
    if ((sec_r000567_14_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000567_16_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000567_3_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000567_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000567_3_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000567_16_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000567_3_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000567_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000567_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000567_13_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000567_9_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000567_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000567_9_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000567_13_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000567_9_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000567_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000567_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000567_9_1 & 1) != 0)
  {
    if ((sec_r000567_7_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000567_2_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000567_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000567_2_1 + 7) & 127;
  }
  if ((sec_r000567_9_2 & 1) != 0)
  {
    if ((sec_r000567_7_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000567_2_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000567_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000567_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000567_9_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000567_4_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000567_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000567_4_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000567_9_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000567_4_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000567_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000567_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000567_8_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000567_0_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000567_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000567_0_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000567_8_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000567_0_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000567_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000567_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000567_11_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000567_16_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000567_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000567_16_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000567_11_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000567_16_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000567_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000567_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000567_15_1 & 1) != 0)
  {
    if ((sec_r000567_14_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000567_10_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000567_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000567_10_1 + 7) & 127;
  }
  if ((sec_r000567_15_2 & 1) != 0)
  {
    if ((sec_r000567_14_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000567_10_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000567_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000567_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000567_8_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000567_17_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000567_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000567_17_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000567_8_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000567_17_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000567_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000567_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000567_8_1 & 1) != 0)
  {
    if ((sec_r000567_2_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000567_10_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000567_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000567_10_1 + 7) & 127;
  }
  if ((sec_r000567_8_2 & 1) != 0)
  {
    if ((sec_r000567_2_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000567_10_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000567_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000567_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000567_11_1 & 1) != 0)
  {
    if ((sec_r000567_18_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000567_16_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000567_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000567_16_1 + 7) & 127;
  }
  if ((sec_r000567_11_2 & 1) != 0)
  {
    if ((sec_r000567_18_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000567_16_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000567_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000567_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000567_5_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000567_16_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000567_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000567_16_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000567_5_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000567_16_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000567_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000567_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000567_7_1 & 1) != 0)
  {
    if ((sec_r000567_3_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000567_6_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000567_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000567_6_1 + 7) & 127;
  }
  if ((sec_r000567_7_2 & 1) != 0)
  {
    if ((sec_r000567_3_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000567_6_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000567_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000567_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000567_5_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000567_6_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000567_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000567_6_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000567_5_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000567_6_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000567_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000567_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000567_7_1 & 1) != 0)
  {
    if ((sec_r000567_14_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000567_17_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000567_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000567_17_1 + 7) & 127;
  }
  if ((sec_r000567_7_2 & 1) != 0)
  {
    if ((sec_r000567_14_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000567_17_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000567_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000567_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000567_7_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000567_0_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000567_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000567_0_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000567_7_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000567_0_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000567_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000567_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000567_5_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000567_10_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000567_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000567_10_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000567_5_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000567_10_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000567_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000567_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000567_2_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000567_2_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000567_15_1 & 1) != 0)
  {
    if ((sec_r000567_4_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000567_12_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000567_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000567_12_1 + 7) & 127;
  }
  if ((sec_r000567_15_2 & 1) != 0)
  {
    if ((sec_r000567_4_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000567_12_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000567_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000567_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000567_13_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000567_15_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000567_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000567_15_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000567_13_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000567_15_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000567_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000567_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000567_17_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000567_3_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000567_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000567_3_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000567_17_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000567_3_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000567_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000567_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000567_6_1 & 1) != 0)
  {
    if ((sec_r000567_8_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000567_1_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000567_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000567_1_1 + 7) & 127;
  }
  if ((sec_r000567_6_2 & 1) != 0)
  {
    if ((sec_r000567_8_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000567_1_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000567_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000567_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000567_15_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000567_2_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000567_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000567_2_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000567_15_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000567_2_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000567_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000567_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000567_4_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000567_14_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000567_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000567_14_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000567_4_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000567_14_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000567_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000567_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000567_10_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000567_5_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000567_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000567_5_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000567_10_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000567_5_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000567_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000567_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000567_3_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000567_14_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000567_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000567_14_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000567_3_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000567_14_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000567_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000567_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000567_14_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000567_14_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000567_12_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000567_17_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000567_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000567_17_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000567_12_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000567_17_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000567_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000567_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000567_6_1 & 1) != 0)
  {
    if ((sec_r000567_1_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000567_14_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000567_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000567_14_1 + 7) & 127;
  }
  if ((sec_r000567_6_2 & 1) != 0)
  {
    if ((sec_r000567_1_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000567_14_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000567_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000567_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000567_0_1 & 1) != 0)
  {
    if ((sec_r000567_0_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000567_3_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000567_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000567_3_1 + 7) & 127;
  }
  if ((sec_r000567_0_2 & 1) != 0)
  {
    if ((sec_r000567_0_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000567_3_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000567_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000567_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000567_7_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000567_17_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000567_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000567_17_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000567_7_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000567_17_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000567_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000567_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000567_6_1 & 1) != 0)
  {
    if ((sec_r000567_16_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000567_0_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000567_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000567_0_1 + 7) & 127;
  }
  if ((sec_r000567_6_2 & 1) != 0)
  {
    if ((sec_r000567_16_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000567_0_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000567_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000567_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000567_5_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000567_15_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000567_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000567_15_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000567_5_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000567_15_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000567_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000567_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000567_10_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000567_8_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000567_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000567_8_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000567_10_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000567_8_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000567_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000567_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000567_3_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000567_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000567_3_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000567_3_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000567_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000567_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000567_1_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000567_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000567_1_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000567_1_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000567_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000567_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000567_1_1 & 1) != 0)
  {
    if ((sec_r000567_5_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000567_17_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000567_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000567_17_1 + 7) & 127;
  }
  if ((sec_r000567_1_2 & 1) != 0)
  {
    if ((sec_r000567_5_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000567_17_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000567_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000567_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000567_7_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000567_0_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000567_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000567_0_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000567_7_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000567_0_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000567_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000567_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000567_11_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000567_14_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000567_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000567_14_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000567_11_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000567_14_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000567_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000567_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000567_15_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000567_14_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000567_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000567_14_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000567_15_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000567_14_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000567_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000567_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000567_0_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000567_3_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000567_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000567_3_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000567_0_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000567_3_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000567_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000567_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000567_3_1 & 1) != 0)
  {
    if ((sec_r000567_2_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000567_15_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000567_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000567_15_1 + 7) & 127;
  }
  if ((sec_r000567_3_2 & 1) != 0)
  {
    if ((sec_r000567_2_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000567_15_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000567_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000567_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000567_17_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000567_4_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000567_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000567_4_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000567_17_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000567_4_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000567_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000567_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000567_1_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000567_10_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000567_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000567_10_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000567_1_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000567_10_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000567_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000567_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000567_4_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000567_17_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000567_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000567_17_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000567_4_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000567_17_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000567_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000567_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000567_1_1 & 1) != 0)
  {
    if ((sec_r000567_3_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000567_6_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000567_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000567_6_1 + 7) & 127;
  }
  if ((sec_r000567_1_2 & 1) != 0)
  {
    if ((sec_r000567_3_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000567_6_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000567_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000567_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000567_13_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000567_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000567_13_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000567_13_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000567_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000567_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000567_0_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000567_6_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000567_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000567_6_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000567_0_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000567_6_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000567_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000567_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000567_0_1 & 1) != 0)
  {
    if ((sec_r000567_4_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000567_1_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000567_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000567_1_1 + 7) & 127;
  }
  if ((sec_r000567_0_2 & 1) != 0)
  {
    if ((sec_r000567_4_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000567_1_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000567_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000567_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000567_8_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000567_10_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000567_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000567_10_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000567_8_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000567_10_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000567_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000567_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000567_4_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000567_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000567_4_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000567_4_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000567_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000567_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000567_18_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000567_14_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000567_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000567_14_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000567_18_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000567_14_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000567_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000567_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000567_15_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000567_12_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000567_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000567_12_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000567_15_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000567_12_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000567_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000567_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000567_7_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000567_9_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000567_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000567_9_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000567_7_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000567_9_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000567_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000567_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000567_15_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000567_5_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000567_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000567_5_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000567_15_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000567_5_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000567_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000567_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000567_3_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000567_2_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000567_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000567_2_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000567_3_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000567_2_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000567_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000567_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000567_1_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000567_1_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000567_18_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000567_13_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000567_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000567_13_1 + 7) & 127;
  }
  if ((sec_r000567_18_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000567_13_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000567_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000567_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000567_16_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000567_16_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000567_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000567_16_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000567_16_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000567_16_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000567_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000567_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000567_14_1 & 1) != 0)
  {
    if ((sec_r000567_0_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000567_2_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000567_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000567_2_1 + 7) & 127;
  }
  if ((sec_r000567_14_2 & 1) != 0)
  {
    if ((sec_r000567_0_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000567_2_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000567_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000567_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000567_11_1 & 1) != 0)
  {
    if ((sec_r000567_1_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000567_17_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000567_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000567_17_1 + 7) & 127;
  }
  if ((sec_r000567_11_2 & 1) != 0)
  {
    if ((sec_r000567_1_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000567_17_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000567_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000567_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000567_14_1 & 1) != 0)
  {
    if ((sec_r000567_4_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((sec_r000567_14_2 & 1) != 0)
  {
    if ((sec_r000567_4_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000567_7_1 & 1) != 0)
  {
    if ((sec_r000567_14_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000567_4_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000567_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000567_4_1 + 7) & 127;
  }
  if ((sec_r000567_7_2 & 1) != 0)
  {
    if ((sec_r000567_14_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000567_4_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000567_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000567_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000567_15_1 & 1) != 0)
  {
    if ((sec_r000567_14_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000567_14_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000567_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000567_14_1 + 7) & 127;
  }
  if ((sec_r000567_15_2 & 1) != 0)
  {
    if ((sec_r000567_14_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000567_14_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000567_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000567_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000567_17_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000567_8_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000567_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000567_8_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000567_17_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000567_8_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000567_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000567_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000567_10_1 & 1) != 0)
  {
    if ((sec_r000567_16_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000567_13_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000567_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000567_13_1 + 7) & 127;
  }
  if ((sec_r000567_10_2 & 1) != 0)
  {
    if ((sec_r000567_16_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000567_13_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000567_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000567_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000567_3_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000567_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000567_3_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000567_3_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000567_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000567_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000567_14_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000567_6_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000567_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000567_6_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000567_14_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000567_6_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000567_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000567_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000567_2_1 & 1) != 0)
  {
    if ((sec_r000567_11_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000567_11_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000567_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000567_11_1 + 7) & 127;
  }
  if ((sec_r000567_2_2 & 1) != 0)
  {
    if ((sec_r000567_11_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000567_11_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000567_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000567_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000567_0_1 & 1) != 0)
  {
    if ((sec_r000567_6_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000567_12_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000567_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000567_12_1 + 7) & 127;
  }
  if ((sec_r000567_0_2 & 1) != 0)
  {
    if ((sec_r000567_6_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000567_12_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000567_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000567_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000567_0_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000567_16_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000567_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000567_16_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000567_0_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000567_16_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000567_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000567_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000567_13_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000567_12_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000567_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000567_12_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000567_13_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000567_12_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000567_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000567_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000567_2_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000567_6_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000567_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000567_6_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000567_2_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000567_6_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000567_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000567_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000567_16_1 & 1) != 0)
  {
    if ((sec_r000567_11_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000567_7_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000567_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000567_7_1 + 7) & 127;
  }
  if ((sec_r000567_16_2 & 1) != 0)
  {
    if ((sec_r000567_11_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000567_7_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000567_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000567_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000567_0_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000567_15_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000567_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000567_15_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000567_0_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000567_15_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000567_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000567_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000567_1_1 & 1) != 0)
  {
    if ((sec_r000567_18_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000567_1_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000567_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000567_1_1 + 7) & 127;
  }
  if ((sec_r000567_1_2 & 1) != 0)
  {
    if ((sec_r000567_18_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000567_1_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000567_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000567_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((sec_r000567_17_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000567_8_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000567_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000567_8_1 + 7) & 127;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((sec_r000567_17_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000567_8_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000567_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000567_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000567_15_1 == pub_r000567_15_2);
  __CPROVER_assume(pub_r000567_1_1 == pub_r000567_1_2);
  __CPROVER_assume(sec_r000567_2_1 != sec_r000567_2_2);
  __CPROVER_assume(sec_r000567_1_1 != sec_r000567_1_2);
  __CPROVER_assume(sec_r000567_3_1 != sec_r000567_3_2);
  __CPROVER_assume(sec_r000567_13_1 != sec_r000567_13_2);
  __CPROVER_assume(sec_r000567_8_1 != sec_r000567_8_2);
  __CPROVER_assume(sec_r000567_5_1 != sec_r000567_5_2);
  __CPROVER_assume(pub_r000567_5_1 == pub_r000567_5_2);
  __CPROVER_assume(pub_r000567_14_1 == pub_r000567_14_2);
  __CPROVER_assume(sec_r000567_10_1 != sec_r000567_10_2);
  __CPROVER_assume(pub_r000567_4_1 == pub_r000567_4_2);
  __CPROVER_assume(sec_r000567_15_1 != sec_r000567_15_2);
  __CPROVER_assume(pub_r000567_12_1 == pub_r000567_12_2);
  __CPROVER_assume(pub_r000567_6_1 == pub_r000567_6_2);
  __CPROVER_assume(sec_r000567_7_1 != sec_r000567_7_2);
  __CPROVER_assume(sec_r000567_6_1 != sec_r000567_6_2);
  __CPROVER_assume(sec_r000567_14_1 != sec_r000567_14_2);
  __CPROVER_assume(pub_r000567_17_1 == pub_r000567_17_2);
  __CPROVER_assume(pub_r000567_2_1 == pub_r000567_2_2);
  __CPROVER_assume(pub_r000567_9_1 == pub_r000567_9_2);
  __CPROVER_assume(pub_r000567_7_1 == pub_r000567_7_2);
  __CPROVER_assume(sec_r000567_18_1 != sec_r000567_18_2);
  __CPROVER_assume(sec_r000567_16_1 != sec_r000567_16_2);
  __CPROVER_assume(pub_r000567_3_1 == pub_r000567_3_2);
  __CPROVER_assume(sec_r000567_4_1 != sec_r000567_4_2);
  __CPROVER_assume(pub_r000567_16_1 == pub_r000567_16_2);
  __CPROVER_assume(pub_r000567_0_1 == pub_r000567_0_2);
  __CPROVER_assume(pub_r000567_8_1 == pub_r000567_8_2);
  __CPROVER_assume(pub_r000567_13_1 == pub_r000567_13_2);
  __CPROVER_assume(sec_r000567_9_1 != sec_r000567_9_2);
  __CPROVER_assume(pub_r000567_11_1 == pub_r000567_11_2);
  __CPROVER_assume(sec_r000567_17_1 != sec_r000567_17_2);
  __CPROVER_assume(sec_r000567_12_1 != sec_r000567_12_2);
  __CPROVER_assume(sec_r000567_0_1 != sec_r000567_0_2);
  __CPROVER_assume(pub_r000567_10_1 == pub_r000567_10_2);
  __CPROVER_assume(sec_r000567_11_1 != sec_r000567_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.damping == st_var_2_2.damping);
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
}


