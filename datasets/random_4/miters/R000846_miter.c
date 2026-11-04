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
struct Vector3D_R000846_4613_0
{
  short heading;
  int coord_z;
  int pitch;
  int buffer[3];
};
struct EventLog_R000846_4613_1
{
  int timestamp;
  int signature;
  unsigned char seq;
  short severity;
  unsigned char facility;
  int buffer[3];
};
struct FilterState_R000846_4613_2
{
  int mode;
  unsigned char damping;
  int prev_out;
  unsigned char gain_db;
  int buffer[3];
};
union PacketPayload_R000846_4613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000846_4613_1
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
void fn_R000846_4613_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st_1 = {0};
  struct EventLog_R000846_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int tracker_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_38_1)
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

  switch (tracker_38_2)
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

  int scale_54_1 = 0;
  int scale_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_54_1 = ((scale_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_54_2 = ((scale_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_54_1) & 127;
    acc_2 = (acc_2 + scale_54_2) & 127;
  }

  int weight_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_64_1 > 42)
  {
    acc_1 = ((acc_1 + (weight_64_1 * 2)) + 5) & 127;
    aux_1 ^= weight_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_64_2 > 42)
  {
    acc_2 = ((acc_2 + (weight_64_2 * 2)) + 5) & 127;
    aux_2 ^= weight_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_64_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_38_1 == tracker_38_2);
  assert(scale_54_1 == scale_54_2);
  assert(weight_64_1 == weight_64_2);
}

int fn_R000846_4613_0(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int tracker_38 = (aux + st.buffer[1]) & 3;
  switch (tracker_38)
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

  int scale_54 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_54 = ((scale_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_54) & 127;
  }

  int weight_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_64 > 42)
  {
    acc = ((acc + (weight_64 * 2)) + 5) & 127;
    aux ^= weight_64 & 15;
  }
  else
  {
    acc = ((acc - weight_64) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000846_4613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st_1 = {0};
  struct FilterState_R000846_4613_2 st_2 = {0};
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
  int residue_46_1 = 0;
  int residue_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_46_1 = ((residue_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_46_2 = ((residue_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_46_1) & 127;
    acc_2 = (acc_2 + residue_46_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_46_1 == residue_46_2);
}

int fn_R000846_4613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_46 = ((residue_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_46) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000846_4613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st_1 = {0};
  struct Vector3D_R000846_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int margin_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_73_1 > 26)
  {
    acc_1 = ((acc_1 + (margin_73_1 * 2)) + 5) & 127;
    aux_1 ^= margin_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_73_2 > 26)
  {
    acc_2 = ((acc_2 + (margin_73_2 * 2)) + 5) & 127;
    aux_2 ^= margin_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_97_1) & 63;
  aux_2 = (aux_2 + threshold_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_49_1 = 0;
  int window_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_49_1 = ((window_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_49_2 = ((window_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_49_1) & 127;
    acc_2 = (acc_2 + window_49_2) & 127;
  }

  int segment_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_61_1)
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

  switch (segment_61_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_73_1 == margin_73_2);
  assert(threshold_97_1 == threshold_97_2);
  assert(window_49_1 == window_49_2);
  assert(segment_61_1 == segment_61_2);
}

int fn_R000846_4613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int margin_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_73 > 26)
  {
    acc = ((acc + (margin_73 * 2)) + 5) & 127;
    aux ^= margin_73 & 15;
  }
  else
  {
    acc = ((acc - margin_73) + 11) & 127;
    aux += 3;
  }
  int threshold_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_97) & 63;
  acc ^= aux;
  int window_49 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_49 = ((window_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_49) & 127;
  }

  int segment_61 = (aux + st.buffer[1]) & 3;
  switch (segment_61)
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

void fn_R000846_4613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st_1 = {0};
  struct EventLog_R000846_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quantum_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_21_1)
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

  switch (quantum_21_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_38_1 > 31)
  {
    acc_1 = ((acc_1 + (metric_38_1 * 2)) + 5) & 127;
    aux_1 ^= metric_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_38_2 > 31)
  {
    acc_2 = ((acc_2 + (metric_38_2 * 2)) + 5) & 127;
    aux_2 ^= metric_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_21_1 == quantum_21_2);
  assert(metric_38_1 == metric_38_2);
}

int fn_R000846_4613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quantum_21 = (aux + st.buffer[1]) & 3;
  switch (quantum_21)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_38 > 31)
  {
    acc = ((acc + (metric_38 * 2)) + 5) & 127;
    aux ^= metric_38 & 15;
  }
  else
  {
    acc = ((acc - metric_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000846_4613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st_1 = {0};
  struct FilterState_R000846_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_86_1 = local_arr_1[aux_1 % 3];
  int accumulator_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_86_2 * 2)) & 127;
  int threshold_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_70_1)
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

  switch (threshold_70_2)
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
  assert(st_1.mode == st_2.mode);
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

  assert(accumulator_86_1 == accumulator_86_2);
  assert(threshold_70_1 == threshold_70_2);
}

int fn_R000846_4613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int accumulator_86 = local_arr[aux % 3];
  acc = (acc + (accumulator_86 * 2)) & 127;
  int threshold_70 = (aux + st.buffer[1]) & 3;
  switch (threshold_70)
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

void fn_R000846_4613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st_1 = {0};
  struct EventLog_R000846_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int segment_20_1 = 0;
  int segment_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_20_1 = ((segment_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_20_2 = ((segment_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_20_1) & 127;
    acc_2 = (acc_2 + segment_20_2) & 127;
  }

  int damping_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_66_1)
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

  switch (damping_66_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_35_1) & 63;
  aux_2 = (aux_2 + tracker_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_20_1 == segment_20_2);
  assert(damping_66_1 == damping_66_2);
  assert(tracker_35_1 == tracker_35_2);
}

int fn_R000846_4613_5(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int segment_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_20 = ((segment_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_20) & 127;
  }

  int damping_66 = (aux + st.buffer[1]) & 3;
  switch (damping_66)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000846_4613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st_1 = {0};
  struct FilterState_R000846_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_34_1 = local_arr_1[aux_1 % 3];
  int coefficient_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_34_2 * 2)) & 127;
  int metric_86_1 = 0;
  int metric_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_86_1 = ((metric_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_86_2 = ((metric_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_86_1) & 127;
    acc_2 = (acc_2 + metric_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
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

  assert(coefficient_34_1 == coefficient_34_2);
  assert(metric_86_1 == metric_86_2);
}

int fn_R000846_4613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int coefficient_34 = local_arr[aux % 3];
  acc = (acc + (coefficient_34 * 2)) & 127;
  int metric_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_86 = ((metric_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000846_4613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st_1 = {0};
  struct Vector3D_R000846_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_46_1 = local_arr_1[aux_1 % 3];
  int window_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_46_2 * 2)) & 127;
  int window_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_90_1)
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

  switch (window_90_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_42_1) & 63;
  aux_2 = (aux_2 + quotient_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_46_1 == window_46_2);
  assert(window_90_1 == window_90_2);
  assert(quotient_42_1 == quotient_42_2);
}

int fn_R000846_4613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int window_46 = local_arr[aux % 3];
  acc = (acc + (window_46 * 2)) & 127;
  int window_90 = (aux + st.buffer[1]) & 3;
  switch (window_90)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000846_4613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st_1 = {0};
  struct Vector3D_R000846_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int offset_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_77_1)
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

  switch (offset_77_2)
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

  int checksum_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_10_1 > 35)
  {
    acc_1 = ((acc_1 + (checksum_10_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_10_2 > 35)
  {
    acc_2 = ((acc_2 + (checksum_10_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_10_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_77_1 == offset_77_2);
  assert(checksum_10_1 == checksum_10_2);
}

int fn_R000846_4613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int offset_77 = (aux + st.buffer[1]) & 3;
  switch (offset_77)
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

  int checksum_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_10 > 35)
  {
    acc = ((acc + (checksum_10 * 2)) + 5) & 127;
    aux ^= checksum_10 & 15;
  }
  else
  {
    acc = ((acc - checksum_10) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000846_4613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st_1 = {0};
  struct Vector3D_R000846_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int margin_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_14_1) & 63;
  aux_2 = (aux_2 + margin_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_11_1 = 0;
  int checksum_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_11_1 = ((checksum_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_11_2 = ((checksum_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_11_1) & 127;
    acc_2 = (acc_2 + checksum_11_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_14_1 == margin_14_2);
  assert(checksum_11_1 == checksum_11_2);
}

int fn_R000846_4613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int margin_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_11 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_11 = ((checksum_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_11) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000846_4613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st_1 = {0};
  struct Vector3D_R000846_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int checksum_72_1 = 0;
  int checksum_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_72_1 = ((checksum_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_72_2 = ((checksum_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_72_1) & 127;
    acc_2 = (acc_2 + checksum_72_2) & 127;
  }

  int offset_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_74_1)
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

  switch (offset_74_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_72_1 == checksum_72_2);
  assert(offset_74_1 == offset_74_2);
}

int fn_R000846_4613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int checksum_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_72 = ((checksum_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_72) & 127;
  }

  int offset_74 = (aux + st.buffer[1]) & 3;
  switch (offset_74)
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

void fn_R000846_4613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st_1 = {0};
  struct EventLog_R000846_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_19_1 = local_arr_1[aux_1 % 3];
  int delta_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_19_2 * 2)) & 127;
  int delta_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_46_1 > 45)
  {
    acc_1 = ((acc_1 + (delta_46_1 * 2)) + 5) & 127;
    aux_1 ^= delta_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_46_2 > 45)
  {
    acc_2 = ((acc_2 + (delta_46_2 * 2)) + 5) & 127;
    aux_2 ^= delta_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_68_1)
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

  switch (metric_68_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_19_1 == delta_19_2);
  assert(delta_46_1 == delta_46_2);
  assert(metric_68_1 == metric_68_2);
}

int fn_R000846_4613_11(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int delta_19 = local_arr[aux % 3];
  acc = (acc + (delta_19 * 2)) & 127;
  int delta_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_46 > 45)
  {
    acc = ((acc + (delta_46 * 2)) + 5) & 127;
    aux ^= delta_46 & 15;
  }
  else
  {
    acc = ((acc - delta_46) + 11) & 127;
    aux += 3;
  }
  int metric_68 = (aux + st.buffer[1]) & 3;
  switch (metric_68)
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

void fn_R000846_4613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st_1 = {0};
  struct FilterState_R000846_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int weight_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_85_1)
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

  switch (weight_85_2)
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

  int metric_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_75_1 > 28)
  {
    acc_1 = ((acc_1 + (metric_75_1 * 2)) + 5) & 127;
    aux_1 ^= metric_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_75_2 > 28)
  {
    acc_2 = ((acc_2 + (metric_75_2 * 2)) + 5) & 127;
    aux_2 ^= metric_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_71_1) & 63;
  aux_2 = (aux_2 + pivot_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_85_1 == weight_85_2);
  assert(metric_75_1 == metric_75_2);
  assert(pivot_71_1 == pivot_71_2);
}

int fn_R000846_4613_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int weight_85 = (aux + st.buffer[1]) & 3;
  switch (weight_85)
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

  int metric_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_75 > 28)
  {
    acc = ((acc + (metric_75 * 2)) + 5) & 127;
    aux ^= metric_75 & 15;
  }
  else
  {
    acc = ((acc - metric_75) + 11) & 127;
    aux += 3;
  }
  int pivot_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_71) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000846_4613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st_1 = {0};
  struct EventLog_R000846_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int margin_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_56_1) & 63;
  aux_2 = (aux_2 + margin_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_99_1 = local_arr_1[aux_1 % 3];
  int weight_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_99_2 * 2)) & 127;
  int bound_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_49_1)
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

  switch (bound_49_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_56_1 == margin_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_99_1 == weight_99_2);
  assert(bound_49_1 == bound_49_2);
}

int fn_R000846_4613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int margin_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_56) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_99 = local_arr[aux % 3];
  acc = (acc + (weight_99 * 2)) & 127;
  int bound_49 = (aux + st.buffer[1]) & 3;
  switch (bound_49)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000846_4613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st_1 = {0};
  struct FilterState_R000846_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_76_1) & 63;
  aux_2 = (aux_2 + pivot_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_34_1 = 0;
  int window_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_34_1 = ((window_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_34_2 = ((window_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_34_1) & 127;
    acc_2 = (acc_2 + window_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_76_1 == pivot_76_2);
  assert(window_34_1 == window_34_2);
}

int fn_R000846_4613_14(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_76) & 63;
  acc ^= aux;
  int window_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_34 = ((window_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000846_4613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st_1 = {0};
  struct EventLog_R000846_4613_1 st_2 = {0};
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
  int damping_46_1 = 0;
  int damping_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_46_1 = ((damping_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_46_2 = ((damping_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_46_1) & 127;
    acc_2 = (acc_2 + damping_46_2) & 127;
  }

  int tracker_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_16_1)
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

  switch (tracker_16_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_46_1 == damping_46_2);
  assert(tracker_16_1 == tracker_16_2);
}

int fn_R000846_4613_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_46 = ((damping_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_46) & 127;
  }

  int tracker_16 = (aux + st.buffer[1]) & 3;
  switch (tracker_16)
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

void fn_R000846_4613_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st_1 = {0};
  struct EventLog_R000846_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int scale_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_60_1)
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

  switch (scale_60_2)
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

  int coefficient_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_29_1 > 24)
  {
    acc_1 = ((acc_1 + (coefficient_29_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_29_2 > 24)
  {
    acc_2 = ((acc_2 + (coefficient_29_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_49_1 = local_arr_1[aux_1 % 3];
  int cursor_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_49_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_60_1 == scale_60_2);
  assert(coefficient_29_1 == coefficient_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_49_1 == cursor_49_2);
}

int fn_R000846_4613_16(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int scale_60 = (aux + st.buffer[1]) & 3;
  switch (scale_60)
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

  int coefficient_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_29 > 24)
  {
    acc = ((acc + (coefficient_29 * 2)) + 5) & 127;
    aux ^= coefficient_29 & 15;
  }
  else
  {
    acc = ((acc - coefficient_29) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_49 = local_arr[aux % 3];
  acc = (acc + (cursor_49 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000846_4613_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st_1 = {0};
  struct EventLog_R000846_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int window_78_1 = 0;
  int window_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_78_1 = ((window_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_78_2 = ((window_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_78_1) & 127;
    acc_2 = (acc_2 + window_78_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_80_1 = local_arr_1[aux_1 % 3];
  int metric_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_78_1 == window_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_80_1 == metric_80_2);
}

int fn_R000846_4613_17(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int window_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_78 = ((window_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_78) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_80 = local_arr[aux % 3];
  acc = (acc + (metric_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000846_4613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st_1 = {0};
  struct FilterState_R000846_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int coefficient_12_1 = 0;
  int coefficient_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_12_1 = ((coefficient_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_12_2 = ((coefficient_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_12_1) & 127;
    acc_2 = (acc_2 + coefficient_12_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_71_1 = local_arr_1[aux_1 % 3];
  int cursor_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_71_2 * 2)) & 127;
  int window_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_77_1)
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

  switch (window_77_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_12_1 == coefficient_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_71_1 == cursor_71_2);
  assert(window_77_1 == window_77_2);
}

int fn_R000846_4613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int coefficient_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_12 = ((coefficient_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_12) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int cursor_71 = local_arr[aux % 3];
  acc = (acc + (cursor_71 * 2)) & 127;
  int window_77 = (aux + st.buffer[1]) & 3;
  switch (window_77)
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

void fn_R000846_4613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st_1 = {0};
  struct FilterState_R000846_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int cursor_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_29_1)
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

  switch (cursor_29_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_29_1 == cursor_29_2);
}

int fn_R000846_4613_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000846_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int cursor_29 = (aux + st.buffer[1]) & 3;
  switch (cursor_29)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000846_4613_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st_1 = {0};
  struct Vector3D_R000846_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_61_1 = local_arr_1[aux_1 % 3];
  int window_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_61_2 * 2)) & 127;
  int cursor_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_94_1)
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

  switch (cursor_94_2)
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

  int window_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_92_1) & 63;
  aux_2 = (aux_2 + window_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_59_1 = 0;
  int vector_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_59_1 = ((vector_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_59_2 = ((vector_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_59_1) & 127;
    acc_2 = (acc_2 + vector_59_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_61_1 == window_61_2);
  assert(cursor_94_1 == cursor_94_2);
  assert(window_92_1 == window_92_2);
  assert(vector_59_1 == vector_59_2);
}

int fn_R000846_4613_20(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int window_61 = local_arr[aux % 3];
  acc = (acc + (window_61 * 2)) & 127;
  int cursor_94 = (aux + st.buffer[1]) & 3;
  switch (cursor_94)
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

  int window_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_92) & 63;
  acc ^= aux;
  int vector_59 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_59 = ((vector_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_59) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000846_4613_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st_1 = {0};
  struct EventLog_R000846_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int window_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_62_1 > 18)
  {
    acc_1 = ((acc_1 + (window_62_1 * 2)) + 5) & 127;
    aux_1 ^= window_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_62_2 > 18)
  {
    acc_2 = ((acc_2 + (window_62_2 * 2)) + 5) & 127;
    aux_2 ^= window_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_60_1) & 63;
  aux_2 = (aux_2 + parity_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_30_1 = 0;
  int delta_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_30_1 = ((delta_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_30_2 = ((delta_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_30_1) & 127;
    acc_2 = (acc_2 + delta_30_2) & 127;
  }

  int damping_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_71_1)
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

  switch (damping_71_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_62_1 == window_62_2);
  assert(parity_60_1 == parity_60_2);
  assert(delta_30_1 == delta_30_2);
  assert(damping_71_1 == damping_71_2);
}

int fn_R000846_4613_21(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000846_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int window_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_62 > 18)
  {
    acc = ((acc + (window_62 * 2)) + 5) & 127;
    aux ^= window_62 & 15;
  }
  else
  {
    acc = ((acc - window_62) + 11) & 127;
    aux += 3;
  }
  int parity_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_60) & 63;
  acc ^= aux;
  int delta_30 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_30 = ((delta_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_30) & 127;
  }

  int damping_71 = (aux + st.buffer[1]) & 3;
  switch (damping_71)
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

void fn_R000846_4613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st_1 = {0};
  struct Vector3D_R000846_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int margin_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_88_1 > 29)
  {
    acc_1 = ((acc_1 + (margin_88_1 * 2)) + 5) & 127;
    aux_1 ^= margin_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_88_2 > 29)
  {
    acc_2 = ((acc_2 + (margin_88_2 * 2)) + 5) & 127;
    aux_2 ^= margin_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_12_1 = 0;
  int coefficient_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_12_1 = ((coefficient_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_12_2 = ((coefficient_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_12_1) & 127;
    acc_2 = (acc_2 + coefficient_12_2) & 127;
  }

  int mask_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_95_1) & 63;
  aux_2 = (aux_2 + mask_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_88_1 == margin_88_2);
  assert(coefficient_12_1 == coefficient_12_2);
  assert(mask_95_1 == mask_95_2);
}

int fn_R000846_4613_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000846_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int margin_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_88 > 29)
  {
    acc = ((acc + (margin_88 * 2)) + 5) & 127;
    aux ^= margin_88 & 15;
  }
  else
  {
    acc = ((acc - margin_88) + 11) & 127;
    aux += 3;
  }
  int coefficient_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_12 = ((coefficient_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_12) & 127;
  }

  int mask_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_95) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000846_0_1;
  int sec_r000846_0_2;
  int sec_r000846_1_1;
  int sec_r000846_1_2;
  int sec_r000846_2_1;
  int sec_r000846_2_2;
  int sec_r000846_3_1;
  int sec_r000846_3_2;
  int sec_r000846_4_1;
  int sec_r000846_4_2;
  int sec_r000846_5_1;
  int sec_r000846_5_2;
  int sec_r000846_6_1;
  int sec_r000846_6_2;
  int sec_r000846_7_1;
  int sec_r000846_7_2;
  int sec_r000846_8_1;
  int sec_r000846_8_2;
  int sec_r000846_9_1;
  int sec_r000846_9_2;
  int sec_r000846_10_1;
  int sec_r000846_10_2;
  int sec_r000846_11_1;
  int sec_r000846_11_2;
  int sec_r000846_12_1;
  int sec_r000846_12_2;
  int sec_r000846_13_1;
  int sec_r000846_13_2;
  int sec_r000846_14_1;
  int sec_r000846_14_2;
  int sec_r000846_15_1;
  int sec_r000846_15_2;
  int sec_r000846_16_1;
  int sec_r000846_16_2;
  int sec_r000846_17_1;
  int sec_r000846_17_2;
  int sec_r000846_18_1;
  int sec_r000846_18_2;
  int sec_r000846_19_1;
  int sec_r000846_19_2;
  int sec_r000846_20_1;
  int sec_r000846_20_2;
  int sec_r000846_21_1;
  int sec_r000846_21_2;
  int pub_r000846_0_1;
  int pub_r000846_0_2;
  int pub_r000846_1_1;
  int pub_r000846_1_2;
  int pub_r000846_2_1;
  int pub_r000846_2_2;
  int pub_r000846_3_1;
  int pub_r000846_3_2;
  int pub_r000846_4_1;
  int pub_r000846_4_2;
  int pub_r000846_5_1;
  int pub_r000846_5_2;
  int pub_r000846_6_1;
  int pub_r000846_6_2;
  int pub_r000846_7_1;
  int pub_r000846_7_2;
  int pub_r000846_8_1;
  int pub_r000846_8_2;
  int pub_r000846_9_1;
  int pub_r000846_9_2;
  int pub_r000846_10_1;
  int pub_r000846_10_2;
  int pub_r000846_11_1;
  int pub_r000846_11_2;
  int pub_r000846_12_1;
  int pub_r000846_12_2;
  int pub_r000846_13_1;
  int pub_r000846_13_2;
  int pub_r000846_14_1;
  int pub_r000846_14_2;
  int pub_r000846_15_1;
  int pub_r000846_15_2;
  int pub_r000846_16_1;
  int pub_r000846_16_2;
  int pub_r000846_17_1;
  int pub_r000846_17_2;
  int pub_r000846_18_1;
  int pub_r000846_18_2;
  int pub_r000846_19_1;
  int pub_r000846_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000846_0_1 >= (-100)) && (pub_r000846_0_1 <= 100));
  __CPROVER_assume((pub_r000846_0_2 >= (-100)) && (pub_r000846_0_2 <= 100));
  __CPROVER_assume((pub_r000846_1_1 >= (-100)) && (pub_r000846_1_1 <= 100));
  __CPROVER_assume((pub_r000846_1_2 >= (-100)) && (pub_r000846_1_2 <= 100));
  __CPROVER_assume((pub_r000846_2_1 >= (-100)) && (pub_r000846_2_1 <= 100));
  __CPROVER_assume((pub_r000846_2_2 >= (-100)) && (pub_r000846_2_2 <= 100));
  __CPROVER_assume((pub_r000846_3_1 >= (-100)) && (pub_r000846_3_1 <= 100));
  __CPROVER_assume((pub_r000846_3_2 >= (-100)) && (pub_r000846_3_2 <= 100));
  __CPROVER_assume((pub_r000846_4_1 >= (-100)) && (pub_r000846_4_1 <= 100));
  __CPROVER_assume((pub_r000846_4_2 >= (-100)) && (pub_r000846_4_2 <= 100));
  __CPROVER_assume((pub_r000846_5_1 >= (-100)) && (pub_r000846_5_1 <= 100));
  __CPROVER_assume((pub_r000846_5_2 >= (-100)) && (pub_r000846_5_2 <= 100));
  __CPROVER_assume((pub_r000846_6_1 >= (-100)) && (pub_r000846_6_1 <= 100));
  __CPROVER_assume((pub_r000846_6_2 >= (-100)) && (pub_r000846_6_2 <= 100));
  __CPROVER_assume((pub_r000846_7_1 >= (-100)) && (pub_r000846_7_1 <= 100));
  __CPROVER_assume((pub_r000846_7_2 >= (-100)) && (pub_r000846_7_2 <= 100));
  __CPROVER_assume((pub_r000846_8_1 >= (-100)) && (pub_r000846_8_1 <= 100));
  __CPROVER_assume((pub_r000846_8_2 >= (-100)) && (pub_r000846_8_2 <= 100));
  __CPROVER_assume((pub_r000846_9_1 >= (-100)) && (pub_r000846_9_1 <= 100));
  __CPROVER_assume((pub_r000846_9_2 >= (-100)) && (pub_r000846_9_2 <= 100));
  __CPROVER_assume((pub_r000846_10_1 >= (-100)) && (pub_r000846_10_1 <= 100));
  __CPROVER_assume((pub_r000846_10_2 >= (-100)) && (pub_r000846_10_2 <= 100));
  __CPROVER_assume((pub_r000846_11_1 >= (-100)) && (pub_r000846_11_1 <= 100));
  __CPROVER_assume((pub_r000846_11_2 >= (-100)) && (pub_r000846_11_2 <= 100));
  __CPROVER_assume((pub_r000846_12_1 >= (-100)) && (pub_r000846_12_1 <= 100));
  __CPROVER_assume((pub_r000846_12_2 >= (-100)) && (pub_r000846_12_2 <= 100));
  __CPROVER_assume((pub_r000846_13_1 >= (-100)) && (pub_r000846_13_1 <= 100));
  __CPROVER_assume((pub_r000846_13_2 >= (-100)) && (pub_r000846_13_2 <= 100));
  __CPROVER_assume((pub_r000846_14_1 >= (-100)) && (pub_r000846_14_1 <= 100));
  __CPROVER_assume((pub_r000846_14_2 >= (-100)) && (pub_r000846_14_2 <= 100));
  __CPROVER_assume((pub_r000846_15_1 >= (-100)) && (pub_r000846_15_1 <= 100));
  __CPROVER_assume((pub_r000846_15_2 >= (-100)) && (pub_r000846_15_2 <= 100));
  __CPROVER_assume((pub_r000846_16_1 >= (-100)) && (pub_r000846_16_1 <= 100));
  __CPROVER_assume((pub_r000846_16_2 >= (-100)) && (pub_r000846_16_2 <= 100));
  __CPROVER_assume((pub_r000846_17_1 >= (-100)) && (pub_r000846_17_1 <= 100));
  __CPROVER_assume((pub_r000846_17_2 >= (-100)) && (pub_r000846_17_2 <= 100));
  __CPROVER_assume((pub_r000846_18_1 >= (-100)) && (pub_r000846_18_1 <= 100));
  __CPROVER_assume((pub_r000846_18_2 >= (-100)) && (pub_r000846_18_2 <= 100));
  __CPROVER_assume((pub_r000846_19_1 >= (-100)) && (pub_r000846_19_1 <= 100));
  __CPROVER_assume((pub_r000846_19_2 >= (-100)) && (pub_r000846_19_2 <= 100));
  __CPROVER_assume((sec_r000846_0_1 >= 0) && (sec_r000846_0_1 <= 255));
  __CPROVER_assume((sec_r000846_0_2 >= 0) && (sec_r000846_0_2 <= 255));
  __CPROVER_assume((sec_r000846_1_1 >= 0) && (sec_r000846_1_1 <= 255));
  __CPROVER_assume((sec_r000846_1_2 >= 0) && (sec_r000846_1_2 <= 255));
  __CPROVER_assume((sec_r000846_2_1 >= 0) && (sec_r000846_2_1 <= 255));
  __CPROVER_assume((sec_r000846_2_2 >= 0) && (sec_r000846_2_2 <= 255));
  __CPROVER_assume((sec_r000846_3_1 >= 0) && (sec_r000846_3_1 <= 255));
  __CPROVER_assume((sec_r000846_3_2 >= 0) && (sec_r000846_3_2 <= 255));
  __CPROVER_assume((sec_r000846_4_1 >= 0) && (sec_r000846_4_1 <= 255));
  __CPROVER_assume((sec_r000846_4_2 >= 0) && (sec_r000846_4_2 <= 255));
  __CPROVER_assume((sec_r000846_5_1 >= 0) && (sec_r000846_5_1 <= 255));
  __CPROVER_assume((sec_r000846_5_2 >= 0) && (sec_r000846_5_2 <= 255));
  __CPROVER_assume((sec_r000846_6_1 >= 0) && (sec_r000846_6_1 <= 255));
  __CPROVER_assume((sec_r000846_6_2 >= 0) && (sec_r000846_6_2 <= 255));
  __CPROVER_assume((sec_r000846_7_1 >= 0) && (sec_r000846_7_1 <= 255));
  __CPROVER_assume((sec_r000846_7_2 >= 0) && (sec_r000846_7_2 <= 255));
  __CPROVER_assume((sec_r000846_8_1 >= 0) && (sec_r000846_8_1 <= 255));
  __CPROVER_assume((sec_r000846_8_2 >= 0) && (sec_r000846_8_2 <= 255));
  __CPROVER_assume((sec_r000846_9_1 >= 0) && (sec_r000846_9_1 <= 255));
  __CPROVER_assume((sec_r000846_9_2 >= 0) && (sec_r000846_9_2 <= 255));
  __CPROVER_assume((sec_r000846_10_1 >= 0) && (sec_r000846_10_1 <= 255));
  __CPROVER_assume((sec_r000846_10_2 >= 0) && (sec_r000846_10_2 <= 255));
  __CPROVER_assume((sec_r000846_11_1 >= 0) && (sec_r000846_11_1 <= 255));
  __CPROVER_assume((sec_r000846_11_2 >= 0) && (sec_r000846_11_2 <= 255));
  __CPROVER_assume((sec_r000846_12_1 >= 0) && (sec_r000846_12_1 <= 255));
  __CPROVER_assume((sec_r000846_12_2 >= 0) && (sec_r000846_12_2 <= 255));
  __CPROVER_assume((sec_r000846_13_1 >= 0) && (sec_r000846_13_1 <= 255));
  __CPROVER_assume((sec_r000846_13_2 >= 0) && (sec_r000846_13_2 <= 255));
  __CPROVER_assume((sec_r000846_14_1 >= 0) && (sec_r000846_14_1 <= 255));
  __CPROVER_assume((sec_r000846_14_2 >= 0) && (sec_r000846_14_2 <= 255));
  __CPROVER_assume((sec_r000846_15_1 >= 0) && (sec_r000846_15_1 <= 255));
  __CPROVER_assume((sec_r000846_15_2 >= 0) && (sec_r000846_15_2 <= 255));
  __CPROVER_assume((sec_r000846_16_1 >= 0) && (sec_r000846_16_1 <= 255));
  __CPROVER_assume((sec_r000846_16_2 >= 0) && (sec_r000846_16_2 <= 255));
  __CPROVER_assume((sec_r000846_17_1 >= 0) && (sec_r000846_17_1 <= 255));
  __CPROVER_assume((sec_r000846_17_2 >= 0) && (sec_r000846_17_2 <= 255));
  __CPROVER_assume((sec_r000846_18_1 >= 0) && (sec_r000846_18_1 <= 255));
  __CPROVER_assume((sec_r000846_18_2 >= 0) && (sec_r000846_18_2 <= 255));
  __CPROVER_assume((sec_r000846_19_1 >= 0) && (sec_r000846_19_1 <= 255));
  __CPROVER_assume((sec_r000846_19_2 >= 0) && (sec_r000846_19_2 <= 255));
  __CPROVER_assume((sec_r000846_20_1 >= 0) && (sec_r000846_20_1 <= 255));
  __CPROVER_assume((sec_r000846_20_2 >= 0) && (sec_r000846_20_2 <= 255));
  __CPROVER_assume((sec_r000846_21_1 >= 0) && (sec_r000846_21_1 <= 255));
  __CPROVER_assume((sec_r000846_21_2 >= 0) && (sec_r000846_21_2 <= 255));
  struct Vector3D_R000846_4613_0 st_var_0_1 = {0};
  struct Vector3D_R000846_4613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000846_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000846_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000846_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000846_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000846_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000846_0_2 + 7) & 15;
  struct EventLog_R000846_4613_1 st_var_1_1 = {0};
  struct EventLog_R000846_4613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000846_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000846_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000846_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000846_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000846_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000846_0_2 + 9) & 15;
  struct FilterState_R000846_4613_2 st_var_2_1 = {0};
  struct FilterState_R000846_4613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000846_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000846_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000846_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000846_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000846_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000846_0_2 + 11) & 15;
  union PacketPayload_R000846_4613_0 u_var_1;
  union PacketPayload_R000846_4613_0 u_var_2;
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
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
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
  int stage_v_11_1 = (st_var_2_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_2_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((st_var_1_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_1_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 29)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 29)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 54)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 54)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((st_var_2_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_2_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 35)
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
  if (stage_v_20_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 35)
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
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_27_1 = (st_var_0_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_0_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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
  int stage_v_33_1 = (st_var_0_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_0_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = ((st_var_1_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_1_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 48)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 48)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_35_1 = ((st_var_2_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_2_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 28)
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
  if (stage_v_35_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 28)
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

  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 52)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 52)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_52_1 = (st_var_1_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_1_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = ((st_var_2_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_2_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 35)
    {
      chk_sum_1 ^= stage_v_53_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_53_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 35)
    {
      chk_sum_2 ^= stage_v_53_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 60) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_66_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 68) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = (st_var_2_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_2_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (81 & 31);
  int stage_v_76_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (81 & 31);
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= (stage_v_76_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_76_2 << 1) & 127;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (st_var_0_1.buffer[0] ^ 81) & 3;
  int stage_v_78_2 = (st_var_0_2.buffer[0] ^ 81) & 3;
  switch (stage_v_78_1)
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

  switch (stage_v_78_2)
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

  int stage_v_79_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (84 & 31);
  int stage_v_79_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (84 & 31);
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= (stage_v_79_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_79_2 << 1) & 127;
  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_85_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 88) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 88) & 15;
  int stage_v_87_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_87_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= stage_v_87_1;
  chk_sum_2 ^= stage_v_87_2;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (st_var_2_1.buffer[0] ^ 92) & 3;
  int stage_v_89_2 = (st_var_2_2.buffer[0] ^ 92) & 3;
  switch (stage_v_89_1)
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

  switch (stage_v_89_2)
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

  int stage_v_90_1 = (st_var_0_1.buffer[0] ^ 93) & 3;
  int stage_v_90_2 = (st_var_0_2.buffer[0] ^ 93) & 3;
  switch (stage_v_90_1)
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

  switch (stage_v_90_2)
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

  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((st_var_2_1.buffer[2] * 2) + 283) & 63;
  int stage_v_92_2 = ((st_var_2_2.buffer[2] * 2) + 283) & 63;
  if (stage_v_92_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_92_1) - 5) & 255;
    if (stage_v_92_1 > 25)
    {
      chk_sum_1 ^= stage_v_92_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_92_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_92_2) - 5) & 255;
    if (stage_v_92_2 > 25)
    {
      chk_sum_2 ^= stage_v_92_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_93_1 = table_1[1];
  int stage_v_93_2 = table_2[1];
  table_1[1] = (table_1[2] + 187) & 63;
  table_2[1] = (table_2[2] + 187) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 95) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 95) & 15;
  int stage_v_94_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_94_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  chk_sum_1 ^= stage_v_94_1;
  chk_sum_2 ^= stage_v_94_2;
  int stage_v_95_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_95_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_96_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_96_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 98) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 98) & 15;
  int stage_v_97_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_97_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= stage_v_97_1;
  chk_sum_2 ^= stage_v_97_2;
  int stage_v_98_1 = (st_var_2_1.buffer[0] ^ 101) & 3;
  int stage_v_98_2 = (st_var_2_2.buffer[0] ^ 101) & 3;
  switch (stage_v_98_1)
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

  switch (stage_v_98_2)
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

  int stage_v_99_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_99_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_100_1 = (st_var_1_1.buffer[0] ^ 103) & 3;
  int stage_v_100_2 = (st_var_1_2.buffer[0] ^ 103) & 3;
  switch (stage_v_100_1)
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

  switch (stage_v_100_2)
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

  int stage_v_101_1 = (st_var_2_1.buffer[0] ^ 104) & 3;
  int stage_v_101_2 = (st_var_2_2.buffer[0] ^ 104) & 3;
  switch (stage_v_101_1)
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

  switch (stage_v_101_2)
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

  int stage_v_102_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (107 & 31);
  int stage_v_102_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (107 & 31);
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= (stage_v_102_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_102_2 << 1) & 127;
  int stage_v_103_1 = table_1[3];
  int stage_v_103_2 = table_2[3];
  table_1[3] = (table_1[0] + 207) & 63;
  table_2[3] = (table_2[0] + 207) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (110 & 31);
  int stage_v_105_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (110 & 31);
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= (stage_v_105_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_105_2 << 1) & 127;
  int stage_v_106_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (111 & 31);
  int stage_v_106_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (111 & 31);
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  chk_sum_1 ^= (stage_v_106_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_106_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 108) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 108) & 15;
  int stage_v_107_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_107_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= stage_v_107_1;
  chk_sum_2 ^= stage_v_107_2;
  int stage_v_108_1 = (st_var_0_1.buffer[0] ^ 111) & 3;
  int stage_v_108_2 = (st_var_0_2.buffer[0] ^ 111) & 3;
  switch (stage_v_108_1)
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

  switch (stage_v_108_2)
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

  int stage_v_109_1 = ((st_var_1_1.buffer[1] * 2) + 334) & 63;
  int stage_v_109_2 = ((st_var_1_2.buffer[1] * 2) + 334) & 63;
  if (stage_v_109_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_109_1) - 5) & 255;
    if (stage_v_109_1 > 42)
    {
      chk_sum_1 ^= stage_v_109_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_109_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_109_2) - 5) & 255;
    if (stage_v_109_2 > 42)
    {
      chk_sum_2 ^= stage_v_109_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (st_var_0_1.buffer[0] ^ 114) & 3;
  int stage_v_111_2 = (st_var_0_2.buffer[0] ^ 114) & 3;
  switch (stage_v_111_1)
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

  switch (stage_v_111_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 113) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 113) & 15;
  int stage_v_112_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_112_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= stage_v_112_1;
  chk_sum_2 ^= stage_v_112_2;
  int stage_v_113_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (118 & 31);
  int stage_v_113_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (118 & 31);
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= (stage_v_113_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_113_2 << 1) & 127;
  int stage_v_114_1 = ((st_var_0_1.buffer[0] * 2) + 349) & 63;
  int stage_v_114_2 = ((st_var_0_2.buffer[0] * 2) + 349) & 63;
  if (stage_v_114_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_114_1) - 5) & 255;
    if (stage_v_114_1 > 27)
    {
      chk_sum_1 ^= stage_v_114_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_114_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_114_2) - 5) & 255;
    if (stage_v_114_2 > 27)
    {
      chk_sum_2 ^= stage_v_114_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_115_1 = (st_var_1_1.buffer[0] ^ 118) & 3;
  int stage_v_115_2 = (st_var_1_2.buffer[0] ^ 118) & 3;
  switch (stage_v_115_1)
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

  switch (stage_v_115_2)
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

  int stage_v_116_1 = table_1[0];
  int stage_v_116_2 = table_2[0];
  table_1[0] = (table_1[1] + 233) & 63;
  table_2[0] = (table_2[1] + 233) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_117_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_118_1 = (st_var_1_1.buffer[0] ^ 121) & 3;
  int stage_v_118_2 = (st_var_1_2.buffer[0] ^ 121) & 3;
  switch (stage_v_118_1)
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

  switch (stage_v_118_2)
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

  int stage_v_119_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (124 & 31);
  int stage_v_119_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (124 & 31);
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= (stage_v_119_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_119_2 << 1) & 127;
  int stage_v_120_1 = table_1[0];
  int stage_v_120_2 = table_2[0];
  table_1[0] = (table_1[1] + 241) & 63;
  table_2[0] = (table_2[1] + 241) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 122) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 122) & 15;
  int stage_v_121_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_121_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  chk_sum_1 ^= stage_v_121_1;
  chk_sum_2 ^= stage_v_121_2;
  int stage_v_122_1 = (st_var_2_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_2_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = ((st_var_0_1.buffer[0] * 2) + 376) & 63;
  int stage_v_123_2 = ((st_var_0_2.buffer[0] * 2) + 376) & 63;
  if (stage_v_123_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_123_1) - 5) & 255;
    if (stage_v_123_1 > 55)
    {
      chk_sum_1 ^= stage_v_123_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_123_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_123_2) - 5) & 255;
    if (stage_v_123_2 > 55)
    {
      chk_sum_2 ^= stage_v_123_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_124_1 = (st_var_1_1.buffer[0] ^ 127) & 3;
  int stage_v_124_2 = (st_var_1_2.buffer[0] ^ 127) & 3;
  switch (stage_v_124_1)
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

  switch (stage_v_124_2)
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

  int stage_v_125_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (130 & 31);
  int stage_v_125_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (130 & 31);
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= (stage_v_125_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_125_2 << 1) & 127;
  int stage_v_126_1 = ((st_var_0_1.buffer[0] * 2) + 385) & 63;
  int stage_v_126_2 = ((st_var_0_2.buffer[0] * 2) + 385) & 63;
  if (stage_v_126_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_126_1) - 5) & 255;
    if (stage_v_126_1 > 45)
    {
      chk_sum_1 ^= stage_v_126_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_126_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_126_2) - 5) & 255;
    if (stage_v_126_2 > 45)
    {
      chk_sum_2 ^= stage_v_126_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_127_1 = ((st_var_1_1.buffer[1] * 2) + 388) & 63;
  int stage_v_127_2 = ((st_var_1_2.buffer[1] * 2) + 388) & 63;
  if (stage_v_127_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_127_1) - 5) & 255;
    if (stage_v_127_1 > 47)
    {
      chk_sum_1 ^= stage_v_127_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_127_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_127_2) - 5) & 255;
    if (stage_v_127_2 > 47)
    {
      chk_sum_2 ^= stage_v_127_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_128_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_128_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_130_1 = ((stage_v_130_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_130_2 = ((stage_v_130_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((st_var_2_1.buffer[2] * 2) + 400) & 63;
  int stage_v_131_2 = ((st_var_2_2.buffer[2] * 2) + 400) & 63;
  if (stage_v_131_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_131_1) - 5) & 255;
    if (stage_v_131_1 > 30)
    {
      chk_sum_1 ^= stage_v_131_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_131_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_131_2) - 5) & 255;
    if (stage_v_131_2 > 30)
    {
      chk_sum_2 ^= stage_v_131_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_132_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (137 & 31);
  int stage_v_132_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (137 & 31);
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  chk_sum_1 ^= (stage_v_132_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_132_2 << 1) & 127;
  int stage_v_133_1 = ((st_var_1_1.buffer[1] * 2) + 406) & 63;
  int stage_v_133_2 = ((st_var_1_2.buffer[1] * 2) + 406) & 63;
  if (stage_v_133_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_133_1) - 5) & 255;
    if (stage_v_133_1 > 28)
    {
      chk_sum_1 ^= stage_v_133_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_133_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_133_2) - 5) & 255;
    if (stage_v_133_2 > 28)
    {
      chk_sum_2 ^= stage_v_133_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_134_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (139 & 31);
  int stage_v_134_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (139 & 31);
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= (stage_v_134_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_134_2 << 1) & 127;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_135_1 = ((stage_v_135_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = table_1[0];
  int stage_v_136_2 = table_2[0];
  table_1[0] = (table_1[1] + 273) & 63;
  table_2[0] = (table_2[1] + 273) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 138) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 138) & 15;
  int stage_v_137_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_137_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= stage_v_137_1;
  chk_sum_2 ^= stage_v_137_2;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((st_var_1_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_1_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 54)
    {
      chk_sum_1 ^= stage_v_139_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_139_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 54)
    {
      chk_sum_2 ^= stage_v_139_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_140_1 = table_1[0];
  int stage_v_140_2 = table_2[0];
  table_1[0] = (table_1[1] + 281) & 63;
  table_2[0] = (table_2[1] + 281) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 142) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 142) & 15;
  int stage_v_141_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_141_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= stage_v_141_1;
  chk_sum_2 ^= stage_v_141_2;
  int stage_v_142_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (147 & 31);
  int stage_v_142_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (147 & 31);
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= (stage_v_142_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_142_2 << 1) & 127;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_144_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_145_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (150 & 31);
  int stage_v_145_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (150 & 31);
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= (stage_v_145_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_145_2 << 1) & 127;
  int stage_v_146_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (151 & 31);
  int stage_v_146_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (151 & 31);
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= (stage_v_146_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_146_2 << 1) & 127;
  int stage_v_147_1 = ((st_var_0_1.buffer[0] * 2) + 448) & 63;
  int stage_v_147_2 = ((st_var_0_2.buffer[0] * 2) + 448) & 63;
  if (stage_v_147_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_147_1) - 5) & 255;
    if (stage_v_147_1 > 28)
    {
      chk_sum_1 ^= stage_v_147_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_147_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_147_2) - 5) & 255;
    if (stage_v_147_2 > 28)
    {
      chk_sum_2 ^= stage_v_147_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_148_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_148_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_149_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (154 & 31);
  int stage_v_149_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (154 & 31);
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  chk_sum_1 ^= (stage_v_149_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_149_2 << 1) & 127;
  int stage_v_150_1 = table_1[2];
  int stage_v_150_2 = table_2[2];
  table_1[2] = (table_1[3] + 301) & 63;
  table_2[2] = (table_2[3] + 301) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((st_var_1_1.buffer[1] * 2) + 460) & 63;
  int stage_v_151_2 = ((st_var_1_2.buffer[1] * 2) + 460) & 63;
  if (stage_v_151_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_151_1) - 5) & 255;
    if (stage_v_151_1 > 52)
    {
      chk_sum_1 ^= stage_v_151_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_151_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_151_2) - 5) & 255;
    if (stage_v_151_2 > 52)
    {
      chk_sum_2 ^= stage_v_151_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_152_1 = (st_var_2_1.buffer[0] ^ 155) & 3;
  int stage_v_152_2 = (st_var_2_2.buffer[0] ^ 155) & 3;
  switch (stage_v_152_1)
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

  switch (stage_v_152_2)
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

  int stage_v_153_1 = (st_var_0_1.buffer[0] ^ 156) & 3;
  int stage_v_153_2 = (st_var_0_2.buffer[0] ^ 156) & 3;
  switch (stage_v_153_1)
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

  switch (stage_v_153_2)
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

  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = table_1[3];
  int stage_v_155_2 = table_2[3];
  table_1[3] = (table_1[0] + 311) & 63;
  table_2[3] = (table_2[0] + 311) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_156_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 158) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 158) & 15;
  int stage_v_157_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_157_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= stage_v_157_1;
  chk_sum_2 ^= stage_v_157_2;
  int stage_v_158_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_158_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_159_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_159_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_161_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_162_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_162_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_162_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_162_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_163_1 = ((st_var_1_1.buffer[1] * 2) + 496) & 63;
  int stage_v_163_2 = ((st_var_1_2.buffer[1] * 2) + 496) & 63;
  if (stage_v_163_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_163_1) - 5) & 255;
    if (stage_v_163_1 > 34)
    {
      chk_sum_1 ^= stage_v_163_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_163_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_163_2) - 5) & 255;
    if (stage_v_163_2 > 34)
    {
      chk_sum_2 ^= stage_v_163_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_164_1 = ((st_var_2_1.buffer[2] * 2) + 499) & 63;
  int stage_v_164_2 = ((st_var_2_2.buffer[2] * 2) + 499) & 63;
  if (stage_v_164_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_164_1) - 5) & 255;
    if (stage_v_164_1 > 46)
    {
      chk_sum_1 ^= stage_v_164_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_164_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_164_2) - 5) & 255;
    if (stage_v_164_2 > 46)
    {
      chk_sum_2 ^= stage_v_164_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_165_1 = table_1[1];
  int stage_v_165_2 = table_2[1];
  table_1[1] = (table_1[2] + 331) & 63;
  table_2[1] = (table_2[2] + 331) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_166_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 168) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 168) & 15;
  int stage_v_167_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_167_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= stage_v_167_1;
  chk_sum_2 ^= stage_v_167_2;
  int stage_v_168_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_168_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_169_1 = table_1[1];
  int stage_v_169_2 = table_2[1];
  table_1[1] = (table_1[2] + 339) & 63;
  table_2[1] = (table_2[2] + 339) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((st_var_2_1.buffer[2] * 2) + 517) & 63;
  int stage_v_170_2 = ((st_var_2_2.buffer[2] * 2) + 517) & 63;
  if (stage_v_170_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_170_1) - 5) & 255;
    if (stage_v_170_1 > 55)
    {
      chk_sum_1 ^= stage_v_170_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_170_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_170_2) - 5) & 255;
    if (stage_v_170_2 > 55)
    {
      chk_sum_2 ^= stage_v_170_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_171_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (176 & 31);
  int stage_v_171_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (176 & 31);
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= (stage_v_171_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_171_2 << 1) & 127;
  int stage_v_172_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (177 & 31);
  int stage_v_172_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (177 & 31);
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  chk_sum_1 ^= (stage_v_172_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_172_2 << 1) & 127;
  int stage_v_173_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_173_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_174_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_174_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_174_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_174_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_175_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (180 & 31);
  int stage_v_175_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (180 & 31);
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  chk_sum_1 ^= (stage_v_175_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_175_2 << 1) & 127;
  int stage_v_176_1 = (st_var_2_1.buffer[0] ^ 179) & 3;
  int stage_v_176_2 = (st_var_2_2.buffer[0] ^ 179) & 3;
  switch (stage_v_176_1)
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

  switch (stage_v_176_2)
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

  int stage_v_177_1 = (st_var_0_1.buffer[0] ^ 180) & 3;
  int stage_v_177_2 = (st_var_0_2.buffer[0] ^ 180) & 3;
  switch (stage_v_177_1)
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

  switch (stage_v_177_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 179) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 179) & 15;
  int stage_v_178_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_178_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= stage_v_178_1;
  chk_sum_2 ^= stage_v_178_2;
  int stage_v_179_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_179_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_179_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_179_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_180_1 = table_1[0];
  int stage_v_180_2 = table_2[0];
  table_1[0] = (table_1[1] + 361) & 63;
  table_2[0] = (table_2[1] + 361) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_181_1 = ((stage_v_181_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_182_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_182_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_182_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_183_1 = table_1[3];
  int stage_v_183_2 = table_2[3];
  table_1[3] = (table_1[0] + 367) & 63;
  table_2[3] = (table_2[0] + 367) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = table_1[0];
  int stage_v_184_2 = table_2[0];
  table_1[0] = (table_1[1] + 369) & 63;
  table_2[0] = (table_2[1] + 369) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (st_var_2_1.buffer[0] ^ 188) & 3;
  int stage_v_185_2 = (st_var_2_2.buffer[0] ^ 188) & 3;
  switch (stage_v_185_1)
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

  switch (stage_v_185_2)
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

  int stage_v_186_1 = table_1[2];
  int stage_v_186_2 = table_2[2];
  table_1[2] = (table_1[3] + 373) & 63;
  table_2[2] = (table_2[3] + 373) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (st_var_1_1.buffer[0] ^ 190) & 3;
  int stage_v_187_2 = (st_var_1_2.buffer[0] ^ 190) & 3;
  switch (stage_v_187_1)
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

  switch (stage_v_187_2)
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

  int stage_v_188_1 = (st_var_2_1.buffer[0] ^ 191) & 3;
  int stage_v_188_2 = (st_var_2_2.buffer[0] ^ 191) & 3;
  switch (stage_v_188_1)
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

  switch (stage_v_188_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 190) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 190) & 15;
  int stage_v_189_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_189_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  chk_sum_1 ^= stage_v_189_1;
  chk_sum_2 ^= stage_v_189_2;
  int s_lut_1[4] = {59, 35, 20, 72};
  int s_lut_2[4] = {59, 35, 20, 72};
  int s_idx_1 = sec_r000846_18_1 & 3;
  int s_idx_2 = sec_r000846_18_2 & 3;
  out_sink_1 += s_lut_1[s_idx_1];
  out_sink_2 += s_lut_2[s_idx_2];
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000846_1_1 == pub_r000846_1_2);
  __CPROVER_assume(sec_r000846_8_1 != sec_r000846_8_2);
  __CPROVER_assume(sec_r000846_2_1 != sec_r000846_2_2);
  __CPROVER_assume(pub_r000846_13_1 == pub_r000846_13_2);
  __CPROVER_assume(pub_r000846_7_1 == pub_r000846_7_2);
  __CPROVER_assume(sec_r000846_5_1 != sec_r000846_5_2);
  __CPROVER_assume(pub_r000846_3_1 == pub_r000846_3_2);
  __CPROVER_assume(pub_r000846_4_1 == pub_r000846_4_2);
  __CPROVER_assume(sec_r000846_13_1 != sec_r000846_13_2);
  __CPROVER_assume(pub_r000846_11_1 == pub_r000846_11_2);
  __CPROVER_assume(pub_r000846_19_1 == pub_r000846_19_2);
  __CPROVER_assume(pub_r000846_8_1 == pub_r000846_8_2);
  __CPROVER_assume(pub_r000846_14_1 == pub_r000846_14_2);
  __CPROVER_assume(sec_r000846_7_1 != sec_r000846_7_2);
  __CPROVER_assume(sec_r000846_21_1 != sec_r000846_21_2);
  __CPROVER_assume(pub_r000846_0_1 == pub_r000846_0_2);
  __CPROVER_assume(pub_r000846_16_1 == pub_r000846_16_2);
  __CPROVER_assume(sec_r000846_17_1 != sec_r000846_17_2);
  __CPROVER_assume(sec_r000846_19_1 != sec_r000846_19_2);
  __CPROVER_assume(sec_r000846_20_1 != sec_r000846_20_2);
  __CPROVER_assume(sec_r000846_12_1 != sec_r000846_12_2);
  __CPROVER_assume(pub_r000846_12_1 == pub_r000846_12_2);
  __CPROVER_assume(sec_r000846_18_1 != sec_r000846_18_2);
  __CPROVER_assume(sec_r000846_6_1 != sec_r000846_6_2);
  __CPROVER_assume(sec_r000846_10_1 != sec_r000846_10_2);
  __CPROVER_assume(pub_r000846_9_1 == pub_r000846_9_2);
  __CPROVER_assume(sec_r000846_3_1 != sec_r000846_3_2);
  __CPROVER_assume(sec_r000846_4_1 != sec_r000846_4_2);
  __CPROVER_assume(pub_r000846_6_1 == pub_r000846_6_2);
  __CPROVER_assume(sec_r000846_15_1 != sec_r000846_15_2);
  __CPROVER_assume(sec_r000846_14_1 != sec_r000846_14_2);
  __CPROVER_assume(pub_r000846_18_1 == pub_r000846_18_2);
  __CPROVER_assume(sec_r000846_1_1 != sec_r000846_1_2);
  __CPROVER_assume(pub_r000846_2_1 == pub_r000846_2_2);
  __CPROVER_assume(sec_r000846_11_1 != sec_r000846_11_2);
  __CPROVER_assume(sec_r000846_16_1 != sec_r000846_16_2);
  __CPROVER_assume(pub_r000846_10_1 == pub_r000846_10_2);
  __CPROVER_assume(sec_r000846_9_1 != sec_r000846_9_2);
  __CPROVER_assume(sec_r000846_0_1 != sec_r000846_0_2);
  __CPROVER_assume(pub_r000846_15_1 == pub_r000846_15_2);
  __CPROVER_assume(pub_r000846_5_1 == pub_r000846_5_2);
  __CPROVER_assume(pub_r000846_17_1 == pub_r000846_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
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
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(s_lut_1[i_0] == s_lut_2[i_0]);
  }

  assert(s_idx_1 == s_idx_2);
}


