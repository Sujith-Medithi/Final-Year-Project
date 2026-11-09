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
struct EventLog_R001142_4213_0
{
  int severity;
  unsigned char seq;
  int code;
  short signature;
  int buffer[3];
};
struct Vector3D_R001142_4213_1
{
  int heading;
  int coord_x;
  int norm_sq;
  unsigned char coord_y;
  int coord_z;
  short pitch;
  int buffer[3];
};
struct StreamBuffer_R001142_4213_2
{
  int watermark;
  int capacity;
  unsigned char head;
  short checksum;
  int buffer[3];
};
struct SensorNode_R001142_4213_3
{
  int threshold;
  short gain;
  short reading;
  int status;
  short calib;
  int buffer[3];
};
union TelemetryField_R001142_4213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001142_4213_1
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
void fn_R001142_4213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001142_4213_0 st_1 = {0};
  struct EventLog_R001142_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_83_1) & 63;
  aux_2 = (aux_2 + window_83_2) & 63;
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

  assert(window_83_1 == window_83_2);
}

int fn_R001142_4213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001142_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001142_4213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st_1 = {0};
  struct SensorNode_R001142_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int mask_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_27_1) & 63;
  aux_2 = (aux_2 + mask_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_33_1)
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

  switch (window_33_2)
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

  int quotient_61_1 = 0;
  int quotient_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_61_1 = ((quotient_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_61_2 = ((quotient_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_61_1) & 127;
    acc_2 = (acc_2 + quotient_61_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_27_1 == mask_27_2);
  assert(window_33_1 == window_33_2);
  assert(quotient_61_1 == quotient_61_2);
}

int fn_R001142_4213_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int mask_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_27) & 63;
  acc ^= aux;
  int window_33 = (aux + st.buffer[1]) & 3;
  switch (window_33)
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

  int quotient_61 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_61 = ((quotient_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_61) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001142_4213_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st_1 = {0};
  struct Vector3D_R001142_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int margin_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_38_1) & 63;
  aux_2 = (aux_2 + margin_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_68_1 > 23)
  {
    acc_1 = ((acc_1 + (cursor_68_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_68_2 > 23)
  {
    acc_2 = ((acc_2 + (cursor_68_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_38_1 == margin_38_2);
  assert(cursor_68_1 == cursor_68_2);
}

int fn_R001142_4213_2(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int margin_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_38) & 63;
  acc ^= aux;
  int cursor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_68 > 23)
  {
    acc = ((acc + (cursor_68 * 2)) + 5) & 127;
    aux ^= cursor_68 & 15;
  }
  else
  {
    acc = ((acc - cursor_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001142_4213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st_1 = {0};
  struct Vector3D_R001142_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int coefficient_16_1 = 0;
  int coefficient_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_16_1 = ((coefficient_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_16_2 = ((coefficient_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_16_1) & 127;
    acc_2 = (acc_2 + coefficient_16_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_76_1 = local_arr_1[aux_1 % 3];
  int residue_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_76_2 * 2)) & 127;
  int segment_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_26_1)
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

  switch (segment_26_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_16_1 == coefficient_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_76_1 == residue_76_2);
  assert(segment_26_1 == segment_26_2);
}

int fn_R001142_4213_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int coefficient_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_16 = ((coefficient_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_16) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int residue_76 = local_arr[aux % 3];
  acc = (acc + (residue_76 * 2)) & 127;
  int segment_26 = (aux + st.buffer[1]) & 3;
  switch (segment_26)
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

void fn_R001142_4213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st_1 = {0};
  struct StreamBuffer_R001142_4213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_69_1 > 50)
  {
    acc_1 = ((acc_1 + (anchor_69_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_69_2 > 50)
  {
    acc_2 = ((acc_2 + (anchor_69_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_78_1 = 0;
  int sample_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_78_1 = ((sample_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_78_2 = ((sample_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_78_1) & 127;
    acc_2 = (acc_2 + sample_78_2) & 127;
  }

  int margin_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_59_1) & 63;
  aux_2 = (aux_2 + margin_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_69_1 == anchor_69_2);
  assert(sample_78_1 == sample_78_2);
  assert(margin_59_1 == margin_59_2);
}

int fn_R001142_4213_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_69 > 50)
  {
    acc = ((acc + (anchor_69 * 2)) + 5) & 127;
    aux ^= anchor_69 & 15;
  }
  else
  {
    acc = ((acc - anchor_69) + 11) & 127;
    aux += 3;
  }
  int sample_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_78 = ((sample_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_78) & 127;
  }

  int margin_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001142_4213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st_1 = {0};
  struct SensorNode_R001142_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int damping_85_1 = 0;
  int damping_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_85_1 = ((damping_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_85_2 = ((damping_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_85_1) & 127;
    acc_2 = (acc_2 + damping_85_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_13_1) & 63;
  aux_2 = (aux_2 + mask_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_56_1 > 18)
  {
    acc_1 = ((acc_1 + (threshold_56_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_56_2 > 18)
  {
    acc_2 = ((acc_2 + (threshold_56_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_85_1 == damping_85_2);
  assert(mask_13_1 == mask_13_2);
  assert(threshold_56_1 == threshold_56_2);
}

int fn_R001142_4213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int damping_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_85 = ((damping_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_85) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_13) & 63;
  acc ^= aux;
  int threshold_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_56 > 18)
  {
    acc = ((acc + (threshold_56 * 2)) + 5) & 127;
    aux ^= threshold_56 & 15;
  }
  else
  {
    acc = ((acc - threshold_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001142_4213_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st_1 = {0};
  struct StreamBuffer_R001142_4213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int mask_10_1 = 0;
  int mask_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_10_1 = ((mask_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_10_2 = ((mask_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_10_1) & 127;
    acc_2 = (acc_2 + mask_10_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_63_1 > 22)
  {
    acc_1 = ((acc_1 + (phase_63_1 * 2)) + 5) & 127;
    aux_1 ^= phase_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_63_2 > 22)
  {
    acc_2 = ((acc_2 + (phase_63_2 * 2)) + 5) & 127;
    aux_2 ^= phase_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_10_1 == mask_10_2);
  assert(phase_63_1 == phase_63_2);
}

int fn_R001142_4213_6(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int mask_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_10 = ((mask_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_10) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_63 > 22)
  {
    acc = ((acc + (phase_63 * 2)) + 5) & 127;
    aux ^= phase_63 & 15;
  }
  else
  {
    acc = ((acc - phase_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001142_4213_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001142_4213_0 st_1 = {0};
  struct EventLog_R001142_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_98_1)
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

  switch (weight_98_2)
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

  int quantum_32_1 = 0;
  int quantum_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_32_1 = ((quantum_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_32_2 = ((quantum_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_32_1) & 127;
    acc_2 = (acc_2 + quantum_32_2) & 127;
  }

  int delta_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_41_1) & 63;
  aux_2 = (aux_2 + delta_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_39_1 = local_arr_1[aux_1 % 3];
  int accumulator_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_39_2 * 2)) & 127;
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

  assert(weight_98_1 == weight_98_2);
  assert(quantum_32_1 == quantum_32_2);
  assert(delta_41_1 == delta_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_39_1 == accumulator_39_2);
}

int fn_R001142_4213_7(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001142_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_98 = (aux + st.buffer[1]) & 3;
  switch (weight_98)
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

  int quantum_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_32 = ((quantum_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_32) & 127;
  }

  int delta_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_39 = local_arr[aux % 3];
  acc = (acc + (accumulator_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001142_4213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st_1 = {0};
  struct StreamBuffer_R001142_4213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int vector_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_23_1) & 63;
  aux_2 = (aux_2 + vector_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_30_1 > 41)
  {
    acc_1 = ((acc_1 + (margin_30_1 * 2)) + 5) & 127;
    aux_1 ^= margin_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_30_2 > 41)
  {
    acc_2 = ((acc_2 + (margin_30_2 * 2)) + 5) & 127;
    aux_2 ^= margin_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_30_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_23_1 == vector_23_2);
  assert(margin_30_1 == margin_30_2);
}

int fn_R001142_4213_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int vector_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_23) & 63;
  acc ^= aux;
  int margin_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_30 > 41)
  {
    acc = ((acc + (margin_30 * 2)) + 5) & 127;
    aux ^= margin_30 & 15;
  }
  else
  {
    acc = ((acc - margin_30) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001142_4213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001142_4213_0 st_1 = {0};
  struct EventLog_R001142_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quantum_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_18_1) & 63;
  aux_2 = (aux_2 + quantum_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_67_1 = local_arr_1[aux_1 % 3];
  int phase_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_67_2 * 2)) & 127;
  int stride_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_92_1)
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

  switch (stride_92_2)
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

  assert(quantum_18_1 == quantum_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_67_1 == phase_67_2);
  assert(stride_92_1 == stride_92_2);
}

int fn_R001142_4213_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001142_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quantum_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_18) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_67 = local_arr[aux % 3];
  acc = (acc + (phase_67 * 2)) & 127;
  int stride_92 = (aux + st.buffer[1]) & 3;
  switch (stride_92)
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

void fn_R001142_4213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st_1 = {0};
  struct SensorNode_R001142_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int vector_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_80_1) & 63;
  aux_2 = (aux_2 + vector_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_98_1)
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

  switch (checksum_98_2)
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

  int quotient_11_1 = 0;
  int quotient_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_11_1 = ((quotient_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_11_2 = ((quotient_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_11_1) & 127;
    acc_2 = (acc_2 + quotient_11_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_80_1 == vector_80_2);
  assert(checksum_98_1 == checksum_98_2);
  assert(quotient_11_1 == quotient_11_2);
}

int fn_R001142_4213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int vector_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_80) & 63;
  acc ^= aux;
  int checksum_98 = (aux + st.buffer[1]) & 3;
  switch (checksum_98)
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

  int quotient_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_11 = ((quotient_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_11) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001142_4213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st_1 = {0};
  struct Vector3D_R001142_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int phase_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_83_1) & 63;
  aux_2 = (aux_2 + phase_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_20_1 = 0;
  int factor_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_20_1 = ((factor_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_20_2 = ((factor_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_20_1) & 127;
    acc_2 = (acc_2 + factor_20_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_83_1 == phase_83_2);
  assert(factor_20_1 == factor_20_2);
}

int fn_R001142_4213_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int phase_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_83) & 63;
  acc ^= aux;
  int factor_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_20 = ((factor_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_20) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001142_4213_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st_1 = {0};
  struct SensorNode_R001142_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int scale_69_1 = 0;
  int scale_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_69_1 = ((scale_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_69_2 = ((scale_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_69_1) & 127;
    acc_2 = (acc_2 + scale_69_2) & 127;
  }

  int factor_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_54_1 > 44)
  {
    acc_1 = ((acc_1 + (factor_54_1 * 2)) + 5) & 127;
    aux_1 ^= factor_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_54_2 > 44)
  {
    acc_2 = ((acc_2 + (factor_54_2 * 2)) + 5) & 127;
    aux_2 ^= factor_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_14_1)
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

  switch (scale_14_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_12_1 = local_arr_1[aux_1 % 3];
  int factor_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_69_1 == scale_69_2);
  assert(factor_54_1 == factor_54_2);
  assert(scale_14_1 == scale_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_12_1 == factor_12_2);
}

int fn_R001142_4213_12(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int scale_69 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_69 = ((scale_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_69) & 127;
  }

  int factor_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_54 > 44)
  {
    acc = ((acc + (factor_54 * 2)) + 5) & 127;
    aux ^= factor_54 & 15;
  }
  else
  {
    acc = ((acc - factor_54) + 11) & 127;
    aux += 3;
  }
  int scale_14 = (aux + st.buffer[1]) & 3;
  switch (scale_14)
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

  int local_arr[3] = {4, 9, 15};
  int factor_12 = local_arr[aux % 3];
  acc = (acc + (factor_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001142_4213_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st_1 = {0};
  struct SensorNode_R001142_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int damping_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_15_1) & 63;
  aux_2 = (aux_2 + damping_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_29_1 = local_arr_1[aux_1 % 3];
  int sample_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_29_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_15_1 == damping_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_29_1 == sample_29_2);
}

int fn_R001142_4213_13(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int damping_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_15) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_29 = local_arr[aux % 3];
  acc = (acc + (sample_29 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001142_4213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001142_4213_0 st_1 = {0};
  struct EventLog_R001142_4213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_47_1)
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

  switch (pivot_47_2)
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

  int scale_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_41_1) & 63;
  aux_2 = (aux_2 + scale_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_41_1 > 29)
  {
    acc_1 = ((acc_1 + (weight_41_1 * 2)) + 5) & 127;
    aux_1 ^= weight_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_41_2 > 29)
  {
    acc_2 = ((acc_2 + (weight_41_2 * 2)) + 5) & 127;
    aux_2 ^= weight_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_41_2) + 11) & 127;
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

  assert(pivot_47_1 == pivot_47_2);
  assert(scale_41_1 == scale_41_2);
  assert(weight_41_1 == weight_41_2);
}

int fn_R001142_4213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001142_4213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_47 = (aux + st.buffer[1]) & 3;
  switch (pivot_47)
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

  int scale_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_41) & 63;
  acc ^= aux;
  int weight_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_41 > 29)
  {
    acc = ((acc + (weight_41 * 2)) + 5) & 127;
    aux ^= weight_41 & 15;
  }
  else
  {
    acc = ((acc - weight_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001142_4213_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st_1 = {0};
  struct StreamBuffer_R001142_4213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int coefficient_79_1 = 0;
  int coefficient_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_79_1 = ((coefficient_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_79_2 = ((coefficient_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_79_1) & 127;
    acc_2 = (acc_2 + coefficient_79_2) & 127;
  }

  int bound_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_94_1)
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

  switch (bound_94_2)
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

  int cursor_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_38_1) & 63;
  aux_2 = (aux_2 + cursor_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_79_1 == coefficient_79_2);
  assert(bound_94_1 == bound_94_2);
  assert(cursor_38_1 == cursor_38_2);
}

int fn_R001142_4213_15(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int coefficient_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_79 = ((coefficient_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_79) & 127;
  }

  int bound_94 = (aux + st.buffer[1]) & 3;
  switch (bound_94)
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

  int cursor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001142_4213_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st_1 = {0};
  struct Vector3D_R001142_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int margin_56_1 = 0;
  int margin_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_56_1 = ((margin_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_56_2 = ((margin_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_56_1) & 127;
    acc_2 = (acc_2 + margin_56_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_36_1 = local_arr_1[aux_1 % 3];
  int checksum_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_36_2 * 2)) & 127;
  int factor_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_33_1 > 11)
  {
    acc_1 = ((acc_1 + (factor_33_1 * 2)) + 5) & 127;
    aux_1 ^= factor_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_33_2 > 11)
  {
    acc_2 = ((acc_2 + (factor_33_2 * 2)) + 5) & 127;
    aux_2 ^= factor_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_33_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_56_1 == margin_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_36_1 == checksum_36_2);
  assert(factor_33_1 == factor_33_2);
}

int fn_R001142_4213_16(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int margin_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_56 = ((margin_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_56) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int checksum_36 = local_arr[aux % 3];
  acc = (acc + (checksum_36 * 2)) & 127;
  int factor_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_33 > 11)
  {
    acc = ((acc + (factor_33 * 2)) + 5) & 127;
    aux ^= factor_33 & 15;
  }
  else
  {
    acc = ((acc - factor_33) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001142_4213_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st_1 = {0};
  struct SensorNode_R001142_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_37_1)
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

  switch (metric_37_2)
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

  int accumulator_53_1 = 0;
  int accumulator_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_53_1 = ((accumulator_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_53_2 = ((accumulator_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_53_1) & 127;
    acc_2 = (acc_2 + accumulator_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_37_1 == metric_37_2);
  assert(accumulator_53_1 == accumulator_53_2);
}

int fn_R001142_4213_17(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_37 = (aux + st.buffer[1]) & 3;
  switch (metric_37)
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

  int accumulator_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_53 = ((accumulator_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001142_4213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st_1 = {0};
  struct StreamBuffer_R001142_4213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_12_1 > 44)
  {
    acc_1 = ((acc_1 + (pivot_12_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_12_2 > 44)
  {
    acc_2 = ((acc_2 + (pivot_12_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_74_1 = 0;
  int sample_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_74_1 = ((sample_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_74_2 = ((sample_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_74_1) & 127;
    acc_2 = (acc_2 + sample_74_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_70_1 = local_arr_1[aux_1 % 3];
  int quotient_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_12_1 == pivot_12_2);
  assert(sample_74_1 == sample_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_70_1 == quotient_70_2);
}

int fn_R001142_4213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001142_4213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_12 > 44)
  {
    acc = ((acc + (pivot_12 * 2)) + 5) & 127;
    aux ^= pivot_12 & 15;
  }
  else
  {
    acc = ((acc - pivot_12) + 11) & 127;
    aux += 3;
  }
  int sample_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_74 = ((sample_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_74) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_70 = local_arr[aux % 3];
  acc = (acc + (quotient_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001142_4213_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st_1 = {0};
  struct Vector3D_R001142_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int offset_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_65_1) & 63;
  aux_2 = (aux_2 + offset_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_18_1 = 0;
  int threshold_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_18_1 = ((threshold_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_18_2 = ((threshold_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_18_1) & 127;
    acc_2 = (acc_2 + threshold_18_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_65_1 == offset_65_2);
  assert(threshold_18_1 == threshold_18_2);
}

int fn_R001142_4213_19(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int offset_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_65) & 63;
  acc ^= aux;
  int threshold_18 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_18 = ((threshold_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_18) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001142_4213_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st_1 = {0};
  struct Vector3D_R001142_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int coefficient_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_31_1 > 37)
  {
    acc_1 = ((acc_1 + (coefficient_31_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_31_2 > 37)
  {
    acc_2 = ((acc_2 + (coefficient_31_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_31_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_86_1 = local_arr_1[aux_1 % 3];
  int factor_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_31_1 == coefficient_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_86_1 == factor_86_2);
}

int fn_R001142_4213_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int coefficient_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_31 > 37)
  {
    acc = ((acc + (coefficient_31 * 2)) + 5) & 127;
    aux ^= coefficient_31 & 15;
  }
  else
  {
    acc = ((acc - coefficient_31) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_86 = local_arr[aux % 3];
  acc = (acc + (factor_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001142_4213_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st_1 = {0};
  struct SensorNode_R001142_4213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_72_1 > 16)
  {
    acc_1 = ((acc_1 + (threshold_72_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_72_2 > 16)
  {
    acc_2 = ((acc_2 + (threshold_72_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_58_1 = 0;
  int threshold_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_58_1 = ((threshold_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_58_2 = ((threshold_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_58_1) & 127;
    acc_2 = (acc_2 + threshold_58_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_52_1)
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

  switch (quotient_52_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_72_1 == threshold_72_2);
  assert(threshold_58_1 == threshold_58_2);
  assert(quotient_52_1 == quotient_52_2);
}

int fn_R001142_4213_21(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001142_4213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_72 > 16)
  {
    acc = ((acc + (threshold_72 * 2)) + 5) & 127;
    aux ^= threshold_72 & 15;
  }
  else
  {
    acc = ((acc - threshold_72) + 11) & 127;
    aux += 3;
  }
  int threshold_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_58 = ((threshold_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_58) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_52 = (aux + st.buffer[1]) & 3;
  switch (quotient_52)
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

void fn_R001142_4213_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st_1 = {0};
  struct Vector3D_R001142_4213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int checksum_56_1 = 0;
  int checksum_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_56_1 = ((checksum_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_56_2 = ((checksum_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_56_1) & 127;
    acc_2 = (acc_2 + checksum_56_2) & 127;
  }

  int parity_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_47_1)
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

  switch (parity_47_2)
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

  int delta_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_69_1) & 63;
  aux_2 = (aux_2 + delta_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_91_1 > 45)
  {
    acc_1 = ((acc_1 + (residue_91_1 * 2)) + 5) & 127;
    aux_1 ^= residue_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_91_2 > 45)
  {
    acc_2 = ((acc_2 + (residue_91_2 * 2)) + 5) & 127;
    aux_2 ^= residue_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_91_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_56_1 == checksum_56_2);
  assert(parity_47_1 == parity_47_2);
  assert(delta_69_1 == delta_69_2);
  assert(residue_91_1 == residue_91_2);
}

int fn_R001142_4213_22(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001142_4213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int checksum_56 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_56 = ((checksum_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_56) & 127;
  }

  int parity_47 = (aux + st.buffer[1]) & 3;
  switch (parity_47)
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

  int delta_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_69) & 63;
  acc ^= aux;
  int residue_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_91 > 45)
  {
    acc = ((acc + (residue_91 * 2)) + 5) & 127;
    aux ^= residue_91 & 15;
  }
  else
  {
    acc = ((acc - residue_91) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001142_0_1;
  int sec_r001142_0_2;
  int sec_r001142_1_1;
  int sec_r001142_1_2;
  int sec_r001142_2_1;
  int sec_r001142_2_2;
  int sec_r001142_3_1;
  int sec_r001142_3_2;
  int sec_r001142_4_1;
  int sec_r001142_4_2;
  int sec_r001142_5_1;
  int sec_r001142_5_2;
  int sec_r001142_6_1;
  int sec_r001142_6_2;
  int sec_r001142_7_1;
  int sec_r001142_7_2;
  int sec_r001142_8_1;
  int sec_r001142_8_2;
  int sec_r001142_9_1;
  int sec_r001142_9_2;
  int sec_r001142_10_1;
  int sec_r001142_10_2;
  int sec_r001142_11_1;
  int sec_r001142_11_2;
  int sec_r001142_12_1;
  int sec_r001142_12_2;
  int sec_r001142_13_1;
  int sec_r001142_13_2;
  int sec_r001142_14_1;
  int sec_r001142_14_2;
  int sec_r001142_15_1;
  int sec_r001142_15_2;
  int sec_r001142_16_1;
  int sec_r001142_16_2;
  int sec_r001142_17_1;
  int sec_r001142_17_2;
  int sec_r001142_18_1;
  int sec_r001142_18_2;
  int sec_r001142_19_1;
  int sec_r001142_19_2;
  int sec_r001142_20_1;
  int sec_r001142_20_2;
  int sec_r001142_21_1;
  int sec_r001142_21_2;
  int pub_r001142_0_1;
  int pub_r001142_0_2;
  int pub_r001142_1_1;
  int pub_r001142_1_2;
  int pub_r001142_2_1;
  int pub_r001142_2_2;
  int pub_r001142_3_1;
  int pub_r001142_3_2;
  int pub_r001142_4_1;
  int pub_r001142_4_2;
  int pub_r001142_5_1;
  int pub_r001142_5_2;
  int pub_r001142_6_1;
  int pub_r001142_6_2;
  int pub_r001142_7_1;
  int pub_r001142_7_2;
  int pub_r001142_8_1;
  int pub_r001142_8_2;
  int pub_r001142_9_1;
  int pub_r001142_9_2;
  int pub_r001142_10_1;
  int pub_r001142_10_2;
  int pub_r001142_11_1;
  int pub_r001142_11_2;
  int pub_r001142_12_1;
  int pub_r001142_12_2;
  int pub_r001142_13_1;
  int pub_r001142_13_2;
  int pub_r001142_14_1;
  int pub_r001142_14_2;
  int pub_r001142_15_1;
  int pub_r001142_15_2;
  int pub_r001142_16_1;
  int pub_r001142_16_2;
  int pub_r001142_17_1;
  int pub_r001142_17_2;
  int pub_r001142_18_1;
  int pub_r001142_18_2;
  int pub_r001142_19_1;
  int pub_r001142_19_2;
  int pub_r001142_20_1;
  int pub_r001142_20_2;
  int pub_r001142_21_1;
  int pub_r001142_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001142_0_1 >= (-100)) && (pub_r001142_0_1 <= 100));
  __CPROVER_assume((pub_r001142_0_2 >= (-100)) && (pub_r001142_0_2 <= 100));
  __CPROVER_assume((pub_r001142_1_1 >= (-100)) && (pub_r001142_1_1 <= 100));
  __CPROVER_assume((pub_r001142_1_2 >= (-100)) && (pub_r001142_1_2 <= 100));
  __CPROVER_assume((pub_r001142_2_1 >= (-100)) && (pub_r001142_2_1 <= 100));
  __CPROVER_assume((pub_r001142_2_2 >= (-100)) && (pub_r001142_2_2 <= 100));
  __CPROVER_assume((pub_r001142_3_1 >= (-100)) && (pub_r001142_3_1 <= 100));
  __CPROVER_assume((pub_r001142_3_2 >= (-100)) && (pub_r001142_3_2 <= 100));
  __CPROVER_assume((pub_r001142_4_1 >= (-100)) && (pub_r001142_4_1 <= 100));
  __CPROVER_assume((pub_r001142_4_2 >= (-100)) && (pub_r001142_4_2 <= 100));
  __CPROVER_assume((pub_r001142_5_1 >= (-100)) && (pub_r001142_5_1 <= 100));
  __CPROVER_assume((pub_r001142_5_2 >= (-100)) && (pub_r001142_5_2 <= 100));
  __CPROVER_assume((pub_r001142_6_1 >= (-100)) && (pub_r001142_6_1 <= 100));
  __CPROVER_assume((pub_r001142_6_2 >= (-100)) && (pub_r001142_6_2 <= 100));
  __CPROVER_assume((pub_r001142_7_1 >= (-100)) && (pub_r001142_7_1 <= 100));
  __CPROVER_assume((pub_r001142_7_2 >= (-100)) && (pub_r001142_7_2 <= 100));
  __CPROVER_assume((pub_r001142_8_1 >= (-100)) && (pub_r001142_8_1 <= 100));
  __CPROVER_assume((pub_r001142_8_2 >= (-100)) && (pub_r001142_8_2 <= 100));
  __CPROVER_assume((pub_r001142_9_1 >= (-100)) && (pub_r001142_9_1 <= 100));
  __CPROVER_assume((pub_r001142_9_2 >= (-100)) && (pub_r001142_9_2 <= 100));
  __CPROVER_assume((pub_r001142_10_1 >= (-100)) && (pub_r001142_10_1 <= 100));
  __CPROVER_assume((pub_r001142_10_2 >= (-100)) && (pub_r001142_10_2 <= 100));
  __CPROVER_assume((pub_r001142_11_1 >= (-100)) && (pub_r001142_11_1 <= 100));
  __CPROVER_assume((pub_r001142_11_2 >= (-100)) && (pub_r001142_11_2 <= 100));
  __CPROVER_assume((pub_r001142_12_1 >= (-100)) && (pub_r001142_12_1 <= 100));
  __CPROVER_assume((pub_r001142_12_2 >= (-100)) && (pub_r001142_12_2 <= 100));
  __CPROVER_assume((pub_r001142_13_1 >= (-100)) && (pub_r001142_13_1 <= 100));
  __CPROVER_assume((pub_r001142_13_2 >= (-100)) && (pub_r001142_13_2 <= 100));
  __CPROVER_assume((pub_r001142_14_1 >= (-100)) && (pub_r001142_14_1 <= 100));
  __CPROVER_assume((pub_r001142_14_2 >= (-100)) && (pub_r001142_14_2 <= 100));
  __CPROVER_assume((pub_r001142_15_1 >= (-100)) && (pub_r001142_15_1 <= 100));
  __CPROVER_assume((pub_r001142_15_2 >= (-100)) && (pub_r001142_15_2 <= 100));
  __CPROVER_assume((pub_r001142_16_1 >= (-100)) && (pub_r001142_16_1 <= 100));
  __CPROVER_assume((pub_r001142_16_2 >= (-100)) && (pub_r001142_16_2 <= 100));
  __CPROVER_assume((pub_r001142_17_1 >= (-100)) && (pub_r001142_17_1 <= 100));
  __CPROVER_assume((pub_r001142_17_2 >= (-100)) && (pub_r001142_17_2 <= 100));
  __CPROVER_assume((pub_r001142_18_1 >= (-100)) && (pub_r001142_18_1 <= 100));
  __CPROVER_assume((pub_r001142_18_2 >= (-100)) && (pub_r001142_18_2 <= 100));
  __CPROVER_assume((pub_r001142_19_1 >= (-100)) && (pub_r001142_19_1 <= 100));
  __CPROVER_assume((pub_r001142_19_2 >= (-100)) && (pub_r001142_19_2 <= 100));
  __CPROVER_assume((pub_r001142_20_1 >= (-100)) && (pub_r001142_20_1 <= 100));
  __CPROVER_assume((pub_r001142_20_2 >= (-100)) && (pub_r001142_20_2 <= 100));
  __CPROVER_assume((pub_r001142_21_1 >= (-100)) && (pub_r001142_21_1 <= 100));
  __CPROVER_assume((pub_r001142_21_2 >= (-100)) && (pub_r001142_21_2 <= 100));
  __CPROVER_assume((sec_r001142_0_1 >= 0) && (sec_r001142_0_1 <= 255));
  __CPROVER_assume((sec_r001142_0_2 >= 0) && (sec_r001142_0_2 <= 255));
  __CPROVER_assume((sec_r001142_1_1 >= 0) && (sec_r001142_1_1 <= 255));
  __CPROVER_assume((sec_r001142_1_2 >= 0) && (sec_r001142_1_2 <= 255));
  __CPROVER_assume((sec_r001142_2_1 >= 0) && (sec_r001142_2_1 <= 255));
  __CPROVER_assume((sec_r001142_2_2 >= 0) && (sec_r001142_2_2 <= 255));
  __CPROVER_assume((sec_r001142_3_1 >= 0) && (sec_r001142_3_1 <= 255));
  __CPROVER_assume((sec_r001142_3_2 >= 0) && (sec_r001142_3_2 <= 255));
  __CPROVER_assume((sec_r001142_4_1 >= 0) && (sec_r001142_4_1 <= 255));
  __CPROVER_assume((sec_r001142_4_2 >= 0) && (sec_r001142_4_2 <= 255));
  __CPROVER_assume((sec_r001142_5_1 >= 0) && (sec_r001142_5_1 <= 255));
  __CPROVER_assume((sec_r001142_5_2 >= 0) && (sec_r001142_5_2 <= 255));
  __CPROVER_assume((sec_r001142_6_1 >= 0) && (sec_r001142_6_1 <= 255));
  __CPROVER_assume((sec_r001142_6_2 >= 0) && (sec_r001142_6_2 <= 255));
  __CPROVER_assume((sec_r001142_7_1 >= 0) && (sec_r001142_7_1 <= 255));
  __CPROVER_assume((sec_r001142_7_2 >= 0) && (sec_r001142_7_2 <= 255));
  __CPROVER_assume((sec_r001142_8_1 >= 0) && (sec_r001142_8_1 <= 255));
  __CPROVER_assume((sec_r001142_8_2 >= 0) && (sec_r001142_8_2 <= 255));
  __CPROVER_assume((sec_r001142_9_1 >= 0) && (sec_r001142_9_1 <= 255));
  __CPROVER_assume((sec_r001142_9_2 >= 0) && (sec_r001142_9_2 <= 255));
  __CPROVER_assume((sec_r001142_10_1 >= 0) && (sec_r001142_10_1 <= 255));
  __CPROVER_assume((sec_r001142_10_2 >= 0) && (sec_r001142_10_2 <= 255));
  __CPROVER_assume((sec_r001142_11_1 >= 0) && (sec_r001142_11_1 <= 255));
  __CPROVER_assume((sec_r001142_11_2 >= 0) && (sec_r001142_11_2 <= 255));
  __CPROVER_assume((sec_r001142_12_1 >= 0) && (sec_r001142_12_1 <= 255));
  __CPROVER_assume((sec_r001142_12_2 >= 0) && (sec_r001142_12_2 <= 255));
  __CPROVER_assume((sec_r001142_13_1 >= 0) && (sec_r001142_13_1 <= 255));
  __CPROVER_assume((sec_r001142_13_2 >= 0) && (sec_r001142_13_2 <= 255));
  __CPROVER_assume((sec_r001142_14_1 >= 0) && (sec_r001142_14_1 <= 255));
  __CPROVER_assume((sec_r001142_14_2 >= 0) && (sec_r001142_14_2 <= 255));
  __CPROVER_assume((sec_r001142_15_1 >= 0) && (sec_r001142_15_1 <= 255));
  __CPROVER_assume((sec_r001142_15_2 >= 0) && (sec_r001142_15_2 <= 255));
  __CPROVER_assume((sec_r001142_16_1 >= 0) && (sec_r001142_16_1 <= 255));
  __CPROVER_assume((sec_r001142_16_2 >= 0) && (sec_r001142_16_2 <= 255));
  __CPROVER_assume((sec_r001142_17_1 >= 0) && (sec_r001142_17_1 <= 255));
  __CPROVER_assume((sec_r001142_17_2 >= 0) && (sec_r001142_17_2 <= 255));
  __CPROVER_assume((sec_r001142_18_1 >= 0) && (sec_r001142_18_1 <= 255));
  __CPROVER_assume((sec_r001142_18_2 >= 0) && (sec_r001142_18_2 <= 255));
  __CPROVER_assume((sec_r001142_19_1 >= 0) && (sec_r001142_19_1 <= 255));
  __CPROVER_assume((sec_r001142_19_2 >= 0) && (sec_r001142_19_2 <= 255));
  __CPROVER_assume((sec_r001142_20_1 >= 0) && (sec_r001142_20_1 <= 255));
  __CPROVER_assume((sec_r001142_20_2 >= 0) && (sec_r001142_20_2 <= 255));
  __CPROVER_assume((sec_r001142_21_1 >= 0) && (sec_r001142_21_1 <= 255));
  __CPROVER_assume((sec_r001142_21_2 >= 0) && (sec_r001142_21_2 <= 255));
  struct EventLog_R001142_4213_0 st_var_0_1 = {0};
  struct EventLog_R001142_4213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001142_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001142_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001142_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001142_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001142_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001142_0_2 + 7) & 15;
  struct Vector3D_R001142_4213_1 st_var_1_1 = {0};
  struct Vector3D_R001142_4213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001142_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001142_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001142_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001142_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001142_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001142_0_2 + 9) & 15;
  struct StreamBuffer_R001142_4213_2 st_var_2_1 = {0};
  struct StreamBuffer_R001142_4213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001142_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001142_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001142_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001142_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001142_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001142_0_2 + 11) & 15;
  struct SensorNode_R001142_4213_3 st_var_3_1 = {0};
  struct SensorNode_R001142_4213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001142_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001142_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001142_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001142_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001142_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001142_0_2 + 13) & 15;
  union TelemetryField_R001142_4213_0 u_var_1;
  union TelemetryField_R001142_4213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001142_4213_0(sec_r001142_0_1, sec_r001142_1_1, pub_r001142_2_1);
  int helper_flow_0_2 = fn_R001142_4213_0(sec_r001142_0_2, sec_r001142_1_2, pub_r001142_2_2);
  fn_R001142_4213_0_2(sec_r001142_0_1, sec_r001142_1_1, pub_r001142_2_1, sec_r001142_0_2, sec_r001142_1_2, pub_r001142_2_2);
  int helper_flow_1_1 = fn_R001142_4213_1(sec_r001142_1_1, pub_r001142_2_1, pub_r001142_3_1, pub_r001142_4_1, pub_r001142_5_1);
  int helper_flow_1_2 = fn_R001142_4213_1(sec_r001142_1_2, pub_r001142_2_2, pub_r001142_3_2, pub_r001142_4_2, pub_r001142_5_2);
  fn_R001142_4213_1_2(sec_r001142_1_1, pub_r001142_2_1, pub_r001142_3_1, pub_r001142_4_1, pub_r001142_5_1, sec_r001142_1_2, pub_r001142_2_2, pub_r001142_3_2, pub_r001142_4_2, pub_r001142_5_2);
  int helper_flow_2_1 = fn_R001142_4213_2(sec_r001142_2_1, pub_r001142_3_1, pub_r001142_4_1);
  int helper_flow_2_2 = fn_R001142_4213_2(sec_r001142_2_2, pub_r001142_3_2, pub_r001142_4_2);
  fn_R001142_4213_2_2(sec_r001142_2_1, pub_r001142_3_1, pub_r001142_4_1, sec_r001142_2_2, pub_r001142_3_2, pub_r001142_4_2);
  int helper_flow_3_1 = fn_R001142_4213_3(sec_r001142_3_1, sec_r001142_4_1, pub_r001142_5_1, pub_r001142_6_1);
  int helper_flow_3_2 = fn_R001142_4213_3(sec_r001142_3_2, sec_r001142_4_2, pub_r001142_5_2, pub_r001142_6_2);
  fn_R001142_4213_3_2(sec_r001142_3_1, sec_r001142_4_1, pub_r001142_5_1, pub_r001142_6_1, sec_r001142_3_2, sec_r001142_4_2, pub_r001142_5_2, pub_r001142_6_2);
  int helper_flow_4_1 = fn_R001142_4213_4(sec_r001142_4_1, sec_r001142_5_1, pub_r001142_6_1, pub_r001142_7_1, pub_r001142_8_1);
  int helper_flow_4_2 = fn_R001142_4213_4(sec_r001142_4_2, sec_r001142_5_2, pub_r001142_6_2, pub_r001142_7_2, pub_r001142_8_2);
  fn_R001142_4213_4_2(sec_r001142_4_1, sec_r001142_5_1, pub_r001142_6_1, pub_r001142_7_1, pub_r001142_8_1, sec_r001142_4_2, sec_r001142_5_2, pub_r001142_6_2, pub_r001142_7_2, pub_r001142_8_2);
  int helper_flow_5_1 = fn_R001142_4213_5(sec_r001142_5_1, pub_r001142_6_1, pub_r001142_7_1);
  int helper_flow_5_2 = fn_R001142_4213_5(sec_r001142_5_2, pub_r001142_6_2, pub_r001142_7_2);
  fn_R001142_4213_5_2(sec_r001142_5_1, pub_r001142_6_1, pub_r001142_7_1, sec_r001142_5_2, pub_r001142_6_2, pub_r001142_7_2);
  int stage_v_0_1 = ((pub_r001142_9_1 * 2) + 18) & 63;
  int stage_v_0_2 = ((pub_r001142_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001142_14_1 * 2) + 28) & 63;
  int stage_v_1_2 = ((pub_r001142_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001142_13_1 * 2) + 6) & 63;
  int stage_v_2_2 = ((pub_r001142_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001142_17_1 * 2) + 36) & 63;
  int stage_v_3_2 = ((pub_r001142_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001142_0_1 * 2) + 27) & 63;
  int stage_v_4_2 = ((pub_r001142_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001142_10_1 * 2) + 28) & 63;
  int stage_v_5_2 = ((pub_r001142_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001142_14_1 * 2) + 15) & 63;
  int stage_v_6_2 = ((pub_r001142_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((helper_flow_2_1 * 3) + pub_r001142_5_1) + 38) & 127;
  int stage_v_7_2 = (((helper_flow_2_2 * 3) + pub_r001142_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001142_6_1 * 2) + 29) & 63;
  int stage_v_8_2 = ((pub_r001142_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001142_2_1 * 2) + 32) & 63;
  int stage_v_9_2 = ((pub_r001142_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001142_21_1 * 2) + 50) & 63;
  int stage_v_10_2 = ((pub_r001142_21_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001142_7_1 * 3) + pub_r001142_4_1) + 16) & 127;
  int stage_v_11_2 = (((sec_r001142_7_2 * 3) + pub_r001142_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((sec_r001142_10_1 * 3) + pub_r001142_13_1) + 40) & 127;
  int stage_v_12_2 = (((sec_r001142_10_2 * 3) + pub_r001142_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001142_19_1 * 2) + 21) & 63;
  int stage_v_13_2 = ((pub_r001142_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001142_9_1 * 3) + pub_r001142_2_1) + 36) & 127;
  int stage_v_14_2 = (((sec_r001142_9_2 * 3) + pub_r001142_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001142_4_1 * 2) + 17) & 63;
  int stage_v_15_2 = ((pub_r001142_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001142_14_1 * 2) + 14) & 63;
  int stage_v_16_2 = ((pub_r001142_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001142_17_1 * 2) + 20) & 63;
  int stage_v_17_2 = ((pub_r001142_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001142_19_1 * 2) + 24) & 63;
  int stage_v_18_2 = ((pub_r001142_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001142_21_1 * 2) + 39) & 63;
  int stage_v_19_2 = ((pub_r001142_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001142_13_1 * 2) + 5) & 63;
  int stage_v_20_2 = ((pub_r001142_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001142_12_1 * 2) + 26) & 63;
  int stage_v_21_2 = ((pub_r001142_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001142_0_1 * 2) + 25) & 63;
  int stage_v_22_2 = ((pub_r001142_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((stage_v_12_1 * 3) + pub_r001142_14_1) + 35) & 127;
  int stage_v_23_2 = (((stage_v_12_2 * 3) + pub_r001142_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001142_2_1 * 3) + pub_r001142_6_1) + 5) & 127;
  int stage_v_24_2 = (((sec_r001142_2_2 * 3) + pub_r001142_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001142_7_1 * 2) + 25) & 63;
  int stage_v_25_2 = ((pub_r001142_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001142_20_1 * 2) + 35) & 63;
  int stage_v_26_2 = ((pub_r001142_20_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((sec_r001142_3_1 * 3) + pub_r001142_18_1) + 15) & 127;
  int stage_v_27_2 = (((sec_r001142_3_2 * 3) + pub_r001142_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001142_18_1 * 2) + 20) & 63;
  int stage_v_28_2 = ((pub_r001142_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001142_0_1 * 2) + 10) & 63;
  int stage_v_29_2 = ((pub_r001142_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001142_3_1 * 2) + 5) & 63;
  int stage_v_30_2 = ((pub_r001142_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001142_6_1 * 2) + 27) & 63;
  int stage_v_31_2 = ((pub_r001142_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001142_1_1 * 2) + 7) & 63;
  int stage_v_32_2 = ((pub_r001142_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001142_15_1 * 2) + 44) & 63;
  int stage_v_33_2 = ((pub_r001142_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((sec_r001142_19_1 * 3) + pub_r001142_5_1) + 22) & 127;
  int stage_v_34_2 = (((sec_r001142_19_2 * 3) + pub_r001142_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001142_17_1 * 2) + 50) & 63;
  int stage_v_35_2 = ((pub_r001142_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001142_19_1 * 2) + 33) & 63;
  int stage_v_36_2 = ((pub_r001142_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001142_4_1 * 2) + 13) & 63;
  int stage_v_37_2 = ((pub_r001142_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((sec_r001142_17_1 * 3) + pub_r001142_20_1) + 13) & 127;
  int stage_v_38_2 = (((sec_r001142_17_2 * 3) + pub_r001142_20_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001142_19_1 * 2) + 11) & 63;
  int stage_v_39_2 = ((pub_r001142_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001142_5_1 * 2) + 13) & 63;
  int stage_v_40_2 = ((pub_r001142_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((sec_r001142_5_1 * 3) + pub_r001142_2_1) + 37) & 127;
  int stage_v_41_2 = (((sec_r001142_5_2 * 3) + pub_r001142_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001142_13_1 * 2) + 31) & 63;
  int stage_v_42_2 = ((pub_r001142_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001142_13_1 * 2) + 25) & 63;
  int stage_v_43_2 = ((pub_r001142_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((sec_r001142_2_1 * 3) + pub_r001142_19_1) + 24) & 127;
  int stage_v_44_2 = (((sec_r001142_2_2 * 3) + pub_r001142_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((sec_r001142_9_1 * 3) + pub_r001142_14_1) + 45) & 127;
  int stage_v_45_2 = (((sec_r001142_9_2 * 3) + pub_r001142_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = ((pub_r001142_10_1 * 2) + 19) & 63;
  int stage_v_46_2 = ((pub_r001142_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((sec_r001142_1_1 * 3) + pub_r001142_16_1) + 21) & 127;
  int stage_v_47_2 = (((sec_r001142_1_2 * 3) + pub_r001142_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001142_14_1 * 2) + 35) & 63;
  int stage_v_48_2 = ((pub_r001142_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001142_9_1 * 2) + 32) & 63;
  int stage_v_49_2 = ((pub_r001142_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001142_17_1 * 2) + 45) & 63;
  int stage_v_50_2 = ((pub_r001142_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001142_20_1 * 2) + 9) & 63;
  int stage_v_51_2 = ((pub_r001142_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001142_6_1 * 2) + 41) & 63;
  int stage_v_52_2 = ((pub_r001142_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001142_7_1 * 2) + 22) & 63;
  int stage_v_53_2 = ((pub_r001142_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001142_3_1 * 2) + 13) & 63;
  int stage_v_54_2 = ((pub_r001142_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001142_1_1 * 2) + 6) & 63;
  int stage_v_55_2 = ((pub_r001142_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001142_16_1 * 2) + 39) & 63;
  int stage_v_56_2 = ((pub_r001142_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001142_2_1 * 2) + 20) & 63;
  int stage_v_57_2 = ((pub_r001142_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001142_20_1 * 2) + 5) & 63;
  int stage_v_58_2 = ((pub_r001142_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001142_14_1 * 2) + 12) & 63;
  int stage_v_59_2 = ((pub_r001142_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((sec_r001142_6_1 * 3) + pub_r001142_5_1) + 24) & 127;
  int stage_v_60_2 = (((sec_r001142_6_2 * 3) + pub_r001142_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((stage_v_24_1 * 3) + pub_r001142_16_1) + 24) & 127;
  int stage_v_61_2 = (((stage_v_24_2 * 3) + pub_r001142_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((helper_flow_3_1 * 3) + pub_r001142_1_1) + 42) & 127;
  int stage_v_62_2 = (((helper_flow_3_2 * 3) + pub_r001142_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = ((pub_r001142_9_1 * 2) + 30) & 63;
  int stage_v_63_2 = ((pub_r001142_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001142_9_1 * 2) + 23) & 63;
  int stage_v_64_2 = ((pub_r001142_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001142_0_1 * 2) + 50) & 63;
  int stage_v_65_2 = ((pub_r001142_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((sec_r001142_0_1 * 3) + pub_r001142_15_1) + 42) & 127;
  int stage_v_66_2 = (((sec_r001142_0_2 * 3) + pub_r001142_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = ((pub_r001142_20_1 * 2) + 8) & 63;
  int stage_v_67_2 = ((pub_r001142_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001142_21_1 * 2) + 18) & 63;
  int stage_v_68_2 = ((pub_r001142_21_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((helper_flow_0_1 * 3) + pub_r001142_10_1) + 34) & 127;
  int stage_v_69_2 = (((helper_flow_0_2 * 3) + pub_r001142_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((helper_flow_3_1 * 3) + pub_r001142_8_1) + 30) & 127;
  int stage_v_70_2 = (((helper_flow_3_2 * 3) + pub_r001142_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001142_7_1 * 2) + 48) & 63;
  int stage_v_71_2 = ((pub_r001142_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_7_1 * 3) + pub_r001142_3_1) + 45) & 127;
  int stage_v_72_2 = (((stage_v_7_2 * 3) + pub_r001142_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((sec_r001142_18_1 * 3) + pub_r001142_9_1) + 22) & 127;
  int stage_v_73_2 = (((sec_r001142_18_2 * 3) + pub_r001142_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001142_2_1 * 2) + 11) & 63;
  int stage_v_74_2 = ((pub_r001142_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001142_20_1 * 2) + 6) & 63;
  int stage_v_75_2 = ((pub_r001142_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001142_10_1 * 2) + 37) & 63;
  int stage_v_76_2 = ((pub_r001142_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((sec_r001142_15_1 * 3) + pub_r001142_0_1) + 40) & 127;
  int stage_v_77_2 = (((sec_r001142_15_2 * 3) + pub_r001142_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((sec_r001142_3_1 * 3) + pub_r001142_5_1) + 34) & 127;
  int stage_v_78_2 = (((sec_r001142_3_2 * 3) + pub_r001142_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001142_21_1 * 2) + 20) & 63;
  int stage_v_79_2 = ((pub_r001142_21_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001142_20_1 * 2) + 11) & 63;
  int stage_v_80_2 = ((pub_r001142_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001142_11_1 * 2) + 41) & 63;
  int stage_v_81_2 = ((pub_r001142_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001142_9_1 * 2) + 23) & 63;
  int stage_v_82_2 = ((pub_r001142_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((stage_v_72_1 * 3) + pub_r001142_10_1) + 29) & 127;
  int stage_v_83_2 = (((stage_v_72_2 * 3) + pub_r001142_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((stage_v_60_1 * 3) + pub_r001142_1_1) + 31) & 127;
  int stage_v_84_2 = (((stage_v_60_2 * 3) + pub_r001142_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((sec_r001142_19_1 * 3) + pub_r001142_17_1) + 37) & 127;
  int stage_v_85_2 = (((sec_r001142_19_2 * 3) + pub_r001142_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001142_6_1 * 2) + 6) & 63;
  int stage_v_86_2 = ((pub_r001142_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001142_16_1 * 2) + 17) & 63;
  int stage_v_87_2 = ((pub_r001142_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001142_3_1 * 2) + 36) & 63;
  int stage_v_88_2 = ((pub_r001142_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001142_16_1 * 2) + 27) & 63;
  int stage_v_89_2 = ((pub_r001142_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((sec_r001142_15_1 * 3) + pub_r001142_2_1) + 21) & 127;
  int stage_v_90_2 = (((sec_r001142_15_2 * 3) + pub_r001142_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001142_0_1 * 2) + 20) & 63;
  int stage_v_91_2 = ((pub_r001142_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_47_1 * 3) + pub_r001142_6_1) + 32) & 127;
  int stage_v_92_2 = (((stage_v_47_2 * 3) + pub_r001142_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((stage_v_11_1 * 3) + pub_r001142_13_1) + 7) & 127;
  int stage_v_93_2 = (((stage_v_11_2 * 3) + pub_r001142_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((sec_r001142_2_1 * 3) + pub_r001142_1_1) + 28) & 127;
  int stage_v_94_2 = (((sec_r001142_2_2 * 3) + pub_r001142_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = ((pub_r001142_5_1 * 2) + 9) & 63;
  int stage_v_95_2 = ((pub_r001142_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001142_11_1 * 2) + 38) & 63;
  int stage_v_96_2 = ((pub_r001142_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001142_21_1 * 2) + 23) & 63;
  int stage_v_97_2 = ((pub_r001142_21_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001142_16_1 * 2) + 46) & 63;
  int stage_v_98_2 = ((pub_r001142_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_84_1 * 3) + pub_r001142_18_1) + 12) & 127;
  int stage_v_99_2 = (((stage_v_84_2 * 3) + pub_r001142_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001142_6_1 * 2) + 47) & 63;
  int stage_v_100_2 = ((pub_r001142_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_72_1 * 3) + pub_r001142_15_1) + 15) & 127;
  int stage_v_101_2 = (((stage_v_72_2 * 3) + pub_r001142_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001142_14_1 * 2) + 26) & 63;
  int stage_v_102_2 = ((pub_r001142_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001142_1_1 * 2) + 46) & 63;
  int stage_v_103_2 = ((pub_r001142_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001142_7_1 * 2) + 30) & 63;
  int stage_v_104_2 = ((pub_r001142_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_73_1 * 3) + pub_r001142_18_1) + 23) & 127;
  int stage_v_105_2 = (((stage_v_73_2 * 3) + pub_r001142_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001142_19_1 * 2) + 46) & 63;
  int stage_v_106_2 = ((pub_r001142_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((sec_r001142_10_1 * 3) + pub_r001142_2_1) + 22) & 127;
  int stage_v_107_2 = (((sec_r001142_10_2 * 3) + pub_r001142_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_105_1 * 3) + pub_r001142_8_1) + 12) & 127;
  int stage_v_108_2 = (((stage_v_105_2 * 3) + pub_r001142_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_12_1 * 3) + pub_r001142_2_1) + 12) & 127;
  int stage_v_109_2 = (((stage_v_12_2 * 3) + pub_r001142_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001142_13_1 * 2) + 24) & 63;
  int stage_v_110_2 = ((pub_r001142_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((sec_r001142_11_1 * 3) + pub_r001142_9_1) + 25) & 127;
  int stage_v_111_2 = (((sec_r001142_11_2 * 3) + pub_r001142_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = (((stage_v_61_1 * 3) + pub_r001142_6_1) + 16) & 127;
  int stage_v_112_2 = (((stage_v_61_2 * 3) + pub_r001142_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001142_13_1 * 2) + 9) & 63;
  int stage_v_113_2 = ((pub_r001142_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_77_1 * 3) + pub_r001142_8_1) + 4) & 127;
  int stage_v_114_2 = (((stage_v_77_2 * 3) + pub_r001142_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001142_3_1 * 2) + 42) & 63;
  int stage_v_115_2 = ((pub_r001142_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_111_1 * 3) + pub_r001142_18_1) + 15) & 127;
  int stage_v_116_2 = (((stage_v_111_2 * 3) + pub_r001142_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001142_10_1 * 2) + 21) & 63;
  int stage_v_117_2 = ((pub_r001142_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((sec_r001142_10_1 * 3) + pub_r001142_20_1) + 29) & 127;
  int stage_v_118_2 = (((sec_r001142_10_2 * 3) + pub_r001142_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001142_18_1 * 2) + 19) & 63;
  int stage_v_119_2 = ((pub_r001142_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001142_2_1 * 2) + 29) & 63;
  int stage_v_120_2 = ((pub_r001142_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001142_6_1 * 2) + 39) & 63;
  int stage_v_121_2 = ((pub_r001142_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001142_15_1 * 2) + 31) & 63;
  int stage_v_122_2 = ((pub_r001142_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001142_16_1 * 2) + 28) & 63;
  int stage_v_123_2 = ((pub_r001142_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001142_6_1 * 2) + 10) & 63;
  int stage_v_124_2 = ((pub_r001142_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001142_15_1 * 2) + 41) & 63;
  int stage_v_125_2 = ((pub_r001142_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001142_7_1 * 2) + 40) & 63;
  int stage_v_126_2 = ((pub_r001142_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001142_20_1 * 2) + 40) & 63;
  int stage_v_127_2 = ((pub_r001142_20_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001142_14_1 * 2) + 50) & 63;
  int stage_v_128_2 = ((pub_r001142_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_99_1 * 3) + pub_r001142_16_1) + 8) & 127;
  int stage_v_129_2 = (((stage_v_99_2 * 3) + pub_r001142_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001142_7_1 * 2) + 28) & 63;
  int stage_v_130_2 = ((pub_r001142_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_116_1 * 3) + pub_r001142_19_1) + 38) & 127;
  int stage_v_131_2 = (((stage_v_116_2 * 3) + pub_r001142_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001142_5_1 * 2) + 39) & 63;
  int stage_v_132_2 = ((pub_r001142_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001142_19_1 * 3) + pub_r001142_17_1) + 27) & 127;
  int stage_v_133_2 = (((sec_r001142_19_2 * 3) + pub_r001142_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001142_15_1 * 2) + 38) & 63;
  int stage_v_134_2 = ((pub_r001142_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_45_1 * 3) + pub_r001142_13_1) + 13) & 127;
  int stage_v_135_2 = (((stage_v_45_2 * 3) + pub_r001142_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001142_13_1 * 2) + 50) & 63;
  int stage_v_136_2 = ((pub_r001142_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((sec_r001142_7_1 * 3) + pub_r001142_3_1) + 17) & 127;
  int stage_v_137_2 = (((sec_r001142_7_2 * 3) + pub_r001142_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001142_5_1 * 2) + 17) & 63;
  int stage_v_138_2 = ((pub_r001142_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001142_3_1 * 2) + 32) & 63;
  int stage_v_139_2 = ((pub_r001142_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001142_8_1 * 2) + 48) & 63;
  int stage_v_140_2 = ((pub_r001142_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((sec_r001142_16_1 * 3) + pub_r001142_7_1) + 42) & 127;
  int stage_v_141_2 = (((sec_r001142_16_2 * 3) + pub_r001142_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = ((pub_r001142_3_1 * 2) + 34) & 63;
  int stage_v_142_2 = ((pub_r001142_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001142_5_1 * 2) + 40) & 63;
  int stage_v_143_2 = ((pub_r001142_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_14_1 * 3) + pub_r001142_18_1) + 38) & 127;
  int stage_v_144_2 = (((stage_v_14_2 * 3) + pub_r001142_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = ((pub_r001142_19_1 * 2) + 30) & 63;
  int stage_v_145_2 = ((pub_r001142_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001142_5_1 * 2) + 23) & 63;
  int stage_v_146_2 = ((pub_r001142_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((sec_r001142_14_1 * 3) + pub_r001142_5_1) + 41) & 127;
  int stage_v_147_2 = (((sec_r001142_14_2 * 3) + pub_r001142_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001142_9_1 * 2) + 47) & 63;
  int stage_v_148_2 = ((pub_r001142_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((stage_v_90_1 * 3) + pub_r001142_14_1) + 9) & 127;
  int stage_v_149_2 = (((stage_v_90_2 * 3) + pub_r001142_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001142_6_1 * 2) + 48) & 63;
  int stage_v_150_2 = ((pub_r001142_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001142_1_1 * 2) + 12) & 63;
  int stage_v_151_2 = ((pub_r001142_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001142_5_1 * 2) + 50) & 63;
  int stage_v_152_2 = ((pub_r001142_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001142_2_1 * 2) + 16) & 63;
  int stage_v_153_2 = ((pub_r001142_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001142_7_1 * 2) + 44) & 63;
  int stage_v_154_2 = ((pub_r001142_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001142_16_1 * 2) + 29) & 63;
  int stage_v_155_2 = ((pub_r001142_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_141_1 * 3) + pub_r001142_6_1) + 16) & 127;
  int stage_v_156_2 = (((stage_v_141_2 * 3) + pub_r001142_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001142_14_1 * 2) + 22) & 63;
  int stage_v_157_2 = ((pub_r001142_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001142_16_1 * 2) + 22) & 63;
  int stage_v_158_2 = ((pub_r001142_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001142_10_1 * 2) + 34) & 63;
  int stage_v_159_2 = ((pub_r001142_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001142_15_1 * 2) + 13) & 63;
  int stage_v_160_2 = ((pub_r001142_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001142_9_1 * 2) + 35) & 63;
  int stage_v_161_2 = ((pub_r001142_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((sec_r001142_15_1 * 3) + pub_r001142_19_1) + 13) & 127;
  int stage_v_162_2 = (((sec_r001142_15_2 * 3) + pub_r001142_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001142_21_1 * 2) + 41) & 63;
  int stage_v_163_2 = ((pub_r001142_21_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_12_1 * 3) + pub_r001142_6_1) + 13) & 127;
  int stage_v_164_2 = (((stage_v_12_2 * 3) + pub_r001142_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001142_2_1 * 2) + 11) & 63;
  int stage_v_165_2 = ((pub_r001142_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001142_3_1 * 2) + 42) & 63;
  int stage_v_166_2 = ((pub_r001142_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_144_1 * 3) + pub_r001142_3_1) + 19) & 127;
  int stage_v_167_2 = (((stage_v_144_2 * 3) + pub_r001142_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001142_13_1 * 2) + 31) & 63;
  int stage_v_168_2 = ((pub_r001142_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_47_1 * 3) + pub_r001142_12_1) + 18) & 127;
  int stage_v_169_2 = (((stage_v_47_2 * 3) + pub_r001142_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_72_1 * 3) + pub_r001142_13_1) + 16) & 127;
  int stage_v_170_2 = (((stage_v_72_2 * 3) + pub_r001142_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001142_20_1 * 2) + 16) & 63;
  int stage_v_171_2 = ((pub_r001142_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001142_15_1 * 2) + 30) & 63;
  int stage_v_172_2 = ((pub_r001142_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001142_0_1 * 2) + 33) & 63;
  int stage_v_173_2 = ((pub_r001142_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001142_4_1 * 2) + 29) & 63;
  int stage_v_174_2 = ((pub_r001142_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001142_13_1 * 2) + 6) & 63;
  int stage_v_175_2 = ((pub_r001142_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_11_1 * 3) + pub_r001142_10_1) + 28) & 127;
  int stage_v_176_2 = (((stage_v_11_2 * 3) + pub_r001142_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001142_17_1 * 2) + 14) & 63;
  int stage_v_177_2 = ((pub_r001142_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((sec_r001142_10_1 * 3) + pub_r001142_13_1) + 20) & 127;
  int stage_v_178_2 = (((sec_r001142_10_2 * 3) + pub_r001142_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((stage_v_129_1 * 3) + pub_r001142_18_1) + 6) & 127;
  int stage_v_179_2 = (((stage_v_129_2 * 3) + pub_r001142_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = ((pub_r001142_15_1 * 2) + 18) & 63;
  int stage_v_180_2 = ((pub_r001142_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001142_8_1 * 2) + 26) & 63;
  int stage_v_181_2 = ((pub_r001142_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001142_15_1 * 2) + 8) & 63;
  int stage_v_182_2 = ((pub_r001142_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_83_1 * 3) + pub_r001142_4_1) + 31) & 127;
  int stage_v_183_2 = (((stage_v_83_2 * 3) + pub_r001142_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001142_18_1 * 2) + 37) & 63;
  int stage_v_184_2 = ((pub_r001142_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001142_18_1 * 2) + 16) & 63;
  int stage_v_185_2 = ((pub_r001142_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_27_1 * 3) + pub_r001142_9_1) + 19) & 127;
  int stage_v_186_2 = (((stage_v_27_2 * 3) + pub_r001142_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001142_8_1 * 2) + 13) & 63;
  int stage_v_187_2 = ((pub_r001142_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((sec_r001142_1_1 * 3) + pub_r001142_11_1) + 17) & 127;
  int stage_v_188_2 = (((sec_r001142_1_2 * 3) + pub_r001142_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001142_19_1 * 2) + 42) & 63;
  int stage_v_189_2 = ((pub_r001142_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001142_20_1 * 2) + 12) & 63;
  int stage_v_190_2 = ((pub_r001142_20_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_66_1 * 3) + pub_r001142_18_1) + 32) & 127;
  int stage_v_191_2 = (((stage_v_66_2 * 3) + pub_r001142_18_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_47_1 * 3) + pub_r001142_7_1) + 22) & 127;
  int stage_v_192_2 = (((stage_v_47_2 * 3) + pub_r001142_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_23_1 * 3) + pub_r001142_21_1) + 24) & 127;
  int stage_v_193_2 = (((stage_v_23_2 * 3) + pub_r001142_21_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001142_13_1 * 2) + 36) & 63;
  int stage_v_194_2 = ((pub_r001142_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001142_10_1 * 2) + 25) & 63;
  int stage_v_195_2 = ((pub_r001142_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001142_13_1 * 2) + 31) & 63;
  int stage_v_196_2 = ((pub_r001142_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_105_1 * 3) + pub_r001142_10_1) + 16) & 127;
  int stage_v_197_2 = (((stage_v_105_2 * 3) + pub_r001142_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = ((pub_r001142_3_1 * 2) + 29) & 63;
  int stage_v_198_2 = ((pub_r001142_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001142_11_1 * 2) + 9) & 63;
  int stage_v_199_2 = ((pub_r001142_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_188_1 * 3) + pub_r001142_18_1) + 5) & 127;
  int stage_v_200_2 = (((stage_v_188_2 * 3) + pub_r001142_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001142_18_1 * 2) + 33) & 63;
  int stage_v_201_2 = ((pub_r001142_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001142_8_1 * 2) + 23) & 63;
  int stage_v_202_2 = ((pub_r001142_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001142_0_1 * 2) + 45) & 63;
  int stage_v_203_2 = ((pub_r001142_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001142_6_1 * 2) + 10) & 63;
  int stage_v_204_2 = ((pub_r001142_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_135_1 * 3) + pub_r001142_20_1) + 20) & 127;
  int stage_v_205_2 = (((stage_v_135_2 * 3) + pub_r001142_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001142_0_1 * 2) + 50) & 63;
  int stage_v_206_2 = ((pub_r001142_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_107_1 * 3) + pub_r001142_13_1) + 6) & 127;
  int stage_v_207_2 = (((stage_v_107_2 * 3) + pub_r001142_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001142_11_1 * 2) + 30) & 63;
  int stage_v_208_2 = ((pub_r001142_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001142_21_1 * 2) + 44) & 63;
  int stage_v_209_2 = ((pub_r001142_21_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001142_14_1 * 2) + 27) & 63;
  int stage_v_210_2 = ((pub_r001142_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001142_13_1 * 2) + 13) & 63;
  int stage_v_211_2 = ((pub_r001142_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_183_1 * 3) + pub_r001142_21_1) + 14) & 127;
  int stage_v_212_2 = (((stage_v_183_2 * 3) + pub_r001142_21_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001142_11_1 * 2) + 18) & 63;
  int stage_v_213_2 = ((pub_r001142_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001142_17_1 * 2) + 25) & 63;
  int stage_v_214_2 = ((pub_r001142_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001142_12_1 * 2) + 7) & 63;
  int stage_v_215_2 = ((pub_r001142_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_24_1 * 3) + pub_r001142_0_1) + 27) & 127;
  int stage_v_216_2 = (((stage_v_24_2 * 3) + pub_r001142_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001142_8_1 * 2) + 28) & 63;
  int stage_v_217_2 = ((pub_r001142_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001142_10_1 * 2) + 7) & 63;
  int stage_v_218_2 = ((pub_r001142_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001142_6_1 * 2) + 24) & 63;
  int stage_v_219_2 = ((pub_r001142_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001142_7_1 * 2) + 8) & 63;
  int stage_v_220_2 = ((pub_r001142_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001142_9_1 * 2) + 30) & 63;
  int stage_v_221_2 = ((pub_r001142_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_47_1 * 3) + pub_r001142_7_1) + 12) & 127;
  int stage_v_222_2 = (((stage_v_47_2 * 3) + pub_r001142_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = (((stage_v_169_1 * 3) + pub_r001142_0_1) + 15) & 127;
  int stage_v_223_2 = (((stage_v_169_2 * 3) + pub_r001142_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = ((pub_r001142_15_1 * 2) + 20) & 63;
  int stage_v_224_2 = ((pub_r001142_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_186_1 * 3) + pub_r001142_0_1) + 18) & 127;
  int stage_v_225_2 = (((stage_v_186_2 * 3) + pub_r001142_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001142_5_1 * 2) + 14) & 63;
  int stage_v_226_2 = ((pub_r001142_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001142_9_1 * 2) + 45) & 63;
  int stage_v_227_2 = ((pub_r001142_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001142_17_1 * 2) + 50) & 63;
  int stage_v_228_2 = ((pub_r001142_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_212_1 * 3) + pub_r001142_0_1) + 15) & 127;
  int stage_v_229_2 = (((stage_v_212_2 * 3) + pub_r001142_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001142_15_1 * 2) + 48) & 63;
  int stage_v_230_2 = ((pub_r001142_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001142_14_1 * 2) + 13) & 63;
  int stage_v_231_2 = ((pub_r001142_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001142_20_1 * 2) + 38) & 63;
  int stage_v_232_2 = ((pub_r001142_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001142_18_1 * 2) + 6) & 63;
  int stage_v_233_2 = ((pub_r001142_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_72_1 * 3) + pub_r001142_13_1) + 26) & 127;
  int stage_v_234_2 = (((stage_v_72_2 * 3) + pub_r001142_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_72_1 * 3) + pub_r001142_13_1) + 8) & 127;
  int stage_v_235_2 = (((stage_v_72_2 * 3) + pub_r001142_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001142_3_1 * 2) + 36) & 63;
  int stage_v_236_2 = ((pub_r001142_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_11_1 * 3) + pub_r001142_13_1) + 34) & 127;
  int stage_v_237_2 = (((stage_v_11_2 * 3) + pub_r001142_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_147_1 * 3) + pub_r001142_17_1) + 16) & 127;
  int stage_v_238_2 = (((stage_v_147_2 * 3) + pub_r001142_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001142_7_1 * 2) + 50) & 63;
  int stage_v_239_2 = ((pub_r001142_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_41_1 * 3) + pub_r001142_17_1) + 43) & 127;
  int stage_v_240_2 = (((stage_v_41_2 * 3) + pub_r001142_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001142_21_1 * 2) + 49) & 63;
  int stage_v_241_2 = ((pub_r001142_21_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001142_1_1 * 2) + 14) & 63;
  int stage_v_242_2 = ((pub_r001142_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_164_1 * 3) + pub_r001142_19_1) + 28) & 127;
  int stage_v_243_2 = (((stage_v_164_2 * 3) + pub_r001142_19_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001142_10_1 * 2) + 35) & 63;
  int stage_v_244_2 = ((pub_r001142_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((sec_r001142_19_1 * 3) + pub_r001142_5_1) + 21) & 127;
  int stage_v_245_2 = (((sec_r001142_19_2 * 3) + pub_r001142_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001142_1_1 * 2) + 25) & 63;
  int stage_v_246_2 = ((pub_r001142_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((sec_r001142_0_1 * 3) + pub_r001142_8_1) + 19) & 127;
  int stage_v_247_2 = (((sec_r001142_0_2 * 3) + pub_r001142_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = (((stage_v_162_1 * 3) + pub_r001142_10_1) + 16) & 127;
  int stage_v_248_2 = (((stage_v_162_2 * 3) + pub_r001142_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = ((pub_r001142_12_1 * 2) + 30) & 63;
  int stage_v_249_2 = ((pub_r001142_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001142_8_1 * 2) + 37) & 63;
  int stage_v_250_2 = ((pub_r001142_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((stage_v_108_1 * 3) + pub_r001142_6_1) + 4) & 127;
  int stage_v_251_2 = (((stage_v_108_2 * 3) + pub_r001142_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001142_2_1 * 2) + 46) & 63;
  int stage_v_252_2 = ((pub_r001142_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((sec_r001142_6_1 * 3) + pub_r001142_18_1) + 35) & 127;
  int stage_v_253_2 = (((sec_r001142_6_2 * 3) + pub_r001142_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001142_20_1 * 2) + 24) & 63;
  int stage_v_254_2 = ((pub_r001142_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((sec_r001142_12_1 * 3) + pub_r001142_4_1) + 29) & 127;
  int stage_v_255_2 = (((sec_r001142_12_2 * 3) + pub_r001142_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001142_16_1 * 2) + 7) & 63;
  int stage_v_256_2 = ((pub_r001142_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((sec_r001142_2_1 * 3) + pub_r001142_20_1) + 27) & 127;
  int stage_v_257_2 = (((sec_r001142_2_2 * 3) + pub_r001142_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = ((pub_r001142_10_1 * 2) + 46) & 63;
  int stage_v_258_2 = ((pub_r001142_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = (((sec_r001142_1_1 * 3) + pub_r001142_18_1) + 25) & 127;
  int stage_v_259_2 = (((sec_r001142_1_2 * 3) + pub_r001142_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001142_17_1 * 2) + 48) & 63;
  int stage_v_260_2 = ((pub_r001142_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001142_8_1 * 2) + 20) & 63;
  int stage_v_261_2 = ((pub_r001142_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001142_20_1 * 2) + 31) & 63;
  int stage_v_262_2 = ((pub_r001142_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_118_1 * 3) + pub_r001142_3_1) + 44) & 127;
  int stage_v_263_2 = (((stage_v_118_2 * 3) + pub_r001142_3_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001142_18_1 * 2) + 47) & 63;
  int stage_v_264_2 = ((pub_r001142_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001142_15_1 * 2) + 22) & 63;
  int stage_v_265_2 = ((pub_r001142_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001142_2_1 * 2) + 17) & 63;
  int stage_v_266_2 = ((pub_r001142_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001142_7_1 * 2) + 37) & 63;
  int stage_v_267_2 = ((pub_r001142_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001142_11_1 * 2) + 31) & 63;
  int stage_v_268_2 = ((pub_r001142_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = (((stage_v_38_1 * 3) + pub_r001142_1_1) + 15) & 127;
  int stage_v_269_2 = (((stage_v_38_2 * 3) + pub_r001142_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001142_7_1 * 2) + 31) & 63;
  int stage_v_270_2 = ((pub_r001142_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001142_6_1 * 2) + 47) & 63;
  int stage_v_271_2 = ((pub_r001142_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001142_1_1 * 2) + 35) & 63;
  int stage_v_272_2 = ((pub_r001142_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001142_13_1 * 2) + 14) & 63;
  int stage_v_273_2 = ((pub_r001142_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001142_3_1 * 2) + 18) & 63;
  int stage_v_274_2 = ((pub_r001142_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001142_18_1 * 2) + 19) & 63;
  int stage_v_275_2 = ((pub_r001142_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_225_1 * 3) + pub_r001142_19_1) + 16) & 127;
  int stage_v_276_2 = (((stage_v_225_2 * 3) + pub_r001142_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001142_0_1 * 2) + 20) & 63;
  int stage_v_277_2 = ((pub_r001142_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_38_1 * 3) + pub_r001142_3_1) + 37) & 127;
  int stage_v_278_2 = (((stage_v_38_2 * 3) + pub_r001142_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001142_15_1 * 2) + 50) & 63;
  int stage_v_279_2 = ((pub_r001142_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((sec_r001142_19_1 * 3) + pub_r001142_18_1) + 20) & 127;
  int stage_v_280_2 = (((sec_r001142_19_2 * 3) + pub_r001142_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_183_1 * 3) + pub_r001142_13_1) + 9) & 127;
  int stage_v_281_2 = (((stage_v_183_2 * 3) + pub_r001142_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001142_10_1 * 2) + 45) & 63;
  int stage_v_282_2 = ((pub_r001142_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((sec_r001142_20_1 * 3) + pub_r001142_3_1) + 41) & 127;
  int stage_v_283_2 = (((sec_r001142_20_2 * 3) + pub_r001142_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = ((pub_r001142_17_1 * 2) + 47) & 63;
  int stage_v_284_2 = ((pub_r001142_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001142_15_1 * 2) + 9) & 63;
  int stage_v_285_2 = ((pub_r001142_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001142_16_1 * 2) + 48) & 63;
  int stage_v_286_2 = ((pub_r001142_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001142_11_1 * 2) + 28) & 63;
  int stage_v_287_2 = ((pub_r001142_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001142_15_1 * 2) + 23) & 63;
  int stage_v_288_2 = ((pub_r001142_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001142_10_1 * 2) + 25) & 63;
  int stage_v_289_2 = ((pub_r001142_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001142_20_1 * 2) + 41) & 63;
  int stage_v_290_2 = ((pub_r001142_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001142_20_1 * 2) + 9) & 63;
  int stage_v_291_2 = ((pub_r001142_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_269_1 * 3) + pub_r001142_16_1) + 10) & 127;
  int stage_v_292_2 = (((stage_v_269_2 * 3) + pub_r001142_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((sec_r001142_16_1 * 3) + pub_r001142_4_1) + 5) & 127;
  int stage_v_293_2 = (((sec_r001142_16_2 * 3) + pub_r001142_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001142_11_1 * 2) + 50) & 63;
  int stage_v_294_2 = ((pub_r001142_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001142_11_1 * 2) + 27) & 63;
  int stage_v_295_2 = ((pub_r001142_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001142_14_1 * 2) + 20) & 63;
  int stage_v_296_2 = ((pub_r001142_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001142_8_1 * 2) + 22) & 63;
  int stage_v_297_2 = ((pub_r001142_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((sec_r001142_3_1 * 3) + pub_r001142_2_1) + 34) & 127;
  int stage_v_298_2 = (((sec_r001142_3_2 * 3) + pub_r001142_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_276_1 * 3) + pub_r001142_17_1) + 20) & 127;
  int stage_v_299_2 = (((stage_v_276_2 * 3) + pub_r001142_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001142_16_1 * 2) + 7) & 63;
  int stage_v_300_2 = ((pub_r001142_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = (((helper_flow_1_1 * 3) + pub_r001142_11_1) + 22) & 127;
  int stage_v_301_2 = (((helper_flow_1_2 * 3) + pub_r001142_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001142_12_1 * 2) + 39) & 63;
  int stage_v_302_2 = ((pub_r001142_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001142_9_1 * 2) + 18) & 63;
  int stage_v_303_2 = ((pub_r001142_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001142_0_1 * 2) + 50) & 63;
  int stage_v_304_2 = ((pub_r001142_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001142_19_1 * 2) + 22) & 63;
  int stage_v_305_2 = ((pub_r001142_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((helper_flow_0_1 * 3) + pub_r001142_4_1) + 11) & 127;
  int stage_v_306_2 = (((helper_flow_0_2 * 3) + pub_r001142_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001142_20_1 * 2) + 46) & 63;
  int stage_v_307_2 = ((pub_r001142_20_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001142_21_1 * 2) + 32) & 63;
  int stage_v_308_2 = ((pub_r001142_21_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001142_16_1 * 2) + 21) & 63;
  int stage_v_309_2 = ((pub_r001142_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_283_1 * 3) + pub_r001142_6_1) + 26) & 127;
  int stage_v_310_2 = (((stage_v_283_2 * 3) + pub_r001142_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001142_20_1 * 2) + 13) & 63;
  int stage_v_311_2 = ((pub_r001142_20_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001142_7_1 * 2) + 36) & 63;
  int stage_v_312_2 = ((pub_r001142_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_133_1 * 3) + pub_r001142_8_1) + 33) & 127;
  int stage_v_313_2 = (((stage_v_133_2 * 3) + pub_r001142_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001142_9_1 * 2) + 30) & 63;
  int stage_v_314_2 = ((pub_r001142_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001142_10_1 * 2) + 17) & 63;
  int stage_v_315_2 = ((pub_r001142_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_147_1 * 3) + pub_r001142_3_1) + 34) & 127;
  int stage_v_316_2 = (((stage_v_147_2 * 3) + pub_r001142_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001142_5_1 * 2) + 47) & 63;
  int stage_v_317_2 = ((pub_r001142_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001142_12_1 * 2) + 5) & 63;
  int stage_v_318_2 = ((pub_r001142_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001142_20_1 * 2) + 18) & 63;
  int stage_v_319_2 = ((pub_r001142_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_238_1 * 3) + pub_r001142_16_1) + 19) & 127;
  int stage_v_320_2 = (((stage_v_238_2 * 3) + pub_r001142_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001142_6_1 * 2) + 23) & 63;
  int stage_v_321_2 = ((pub_r001142_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001142_2_1 * 2) + 42) & 63;
  int stage_v_322_2 = ((pub_r001142_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001142_2_1 * 2) + 48) & 63;
  int stage_v_323_2 = ((pub_r001142_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001142_21_1 * 2) + 9) & 63;
  int stage_v_324_2 = ((pub_r001142_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((stage_v_70_1 * 3) + pub_r001142_13_1) + 22) & 127;
  int stage_v_325_2 = (((stage_v_70_2 * 3) + pub_r001142_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001142_16_1 * 2) + 32) & 63;
  int stage_v_326_2 = ((pub_r001142_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = (((stage_v_243_1 * 3) + pub_r001142_10_1) + 42) & 127;
  int stage_v_327_2 = (((stage_v_243_2 * 3) + pub_r001142_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((sec_r001142_10_1 * 3) + pub_r001142_10_1) + 38) & 127;
  int stage_v_328_2 = (((sec_r001142_10_2 * 3) + pub_r001142_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001142_9_1 * 2) + 11) & 63;
  int stage_v_329_2 = ((pub_r001142_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001142_21_1 * 2) + 22) & 63;
  int stage_v_330_2 = ((pub_r001142_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001142_11_1 * 2) + 31) & 63;
  int stage_v_331_2 = ((pub_r001142_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_105_1 * 3) + pub_r001142_19_1) + 4) & 127;
  int stage_v_332_2 = (((stage_v_105_2 * 3) + pub_r001142_19_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001142_10_1 * 2) + 45) & 63;
  int stage_v_333_2 = ((pub_r001142_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001142_6_1 * 2) + 11) & 63;
  int stage_v_334_2 = ((pub_r001142_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001142_5_1 * 2) + 17) & 63;
  int stage_v_335_2 = ((pub_r001142_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_327_1 * 3) + pub_r001142_2_1) + 32) & 127;
  int stage_v_336_2 = (((stage_v_327_2 * 3) + pub_r001142_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_191_1 * 3) + pub_r001142_14_1) + 5) & 127;
  int stage_v_337_2 = (((stage_v_191_2 * 3) + pub_r001142_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_137_1 * 3) + pub_r001142_0_1) + 30) & 127;
  int stage_v_338_2 = (((stage_v_137_2 * 3) + pub_r001142_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((sec_r001142_16_1 * 3) + pub_r001142_9_1) + 23) & 127;
  int stage_v_339_2 = (((sec_r001142_16_2 * 3) + pub_r001142_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001142_4_1 * 2) + 48) & 63;
  int stage_v_340_2 = ((pub_r001142_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001142_10_1 * 2) + 45) & 63;
  int stage_v_341_2 = ((pub_r001142_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001142_8_1 * 2) + 8) & 63;
  int stage_v_342_2 = ((pub_r001142_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_47_1 * 3) + pub_r001142_15_1) + 4) & 127;
  int stage_v_343_2 = (((stage_v_47_2 * 3) + pub_r001142_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = ((pub_r001142_0_1 * 2) + 25) & 63;
  int stage_v_344_2 = ((pub_r001142_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_216_1 * 3) + pub_r001142_8_1) + 14) & 127;
  int stage_v_345_2 = (((stage_v_216_2 * 3) + pub_r001142_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((stage_v_78_1 * 3) + pub_r001142_5_1) + 21) & 127;
  int stage_v_346_2 = (((stage_v_78_2 * 3) + pub_r001142_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001142_15_1 * 2) + 28) & 63;
  int stage_v_347_2 = ((pub_r001142_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001142_2_1 * 2) + 25) & 63;
  int stage_v_348_2 = ((pub_r001142_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((stage_v_72_1 * 3) + pub_r001142_18_1) + 17) & 127;
  int stage_v_349_2 = (((stage_v_72_2 * 3) + pub_r001142_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001142_7_1 * 2) + 39) & 63;
  int stage_v_350_2 = ((pub_r001142_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001142_7_1 * 2) + 23) & 63;
  int stage_v_351_2 = ((pub_r001142_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001142_5_1 * 2) + 13) & 63;
  int stage_v_352_2 = ((pub_r001142_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001142_11_1 * 2) + 43) & 63;
  int stage_v_353_2 = ((pub_r001142_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_188_1 * 3) + pub_r001142_13_1) + 12) & 127;
  int stage_v_354_2 = (((stage_v_188_2 * 3) + pub_r001142_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_293_1 * 3) + pub_r001142_20_1) + 34) & 127;
  int stage_v_355_2 = (((stage_v_293_2 * 3) + pub_r001142_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_169_1 * 3) + pub_r001142_7_1) + 43) & 127;
  int stage_v_356_2 = (((stage_v_169_2 * 3) + pub_r001142_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001142_0_1 * 2) + 46) & 63;
  int stage_v_357_2 = ((pub_r001142_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001142_16_1 * 2) + 49) & 63;
  int stage_v_358_2 = ((pub_r001142_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((sec_r001142_4_1 * 3) + pub_r001142_12_1) + 27) & 127;
  int stage_v_359_2 = (((sec_r001142_4_2 * 3) + pub_r001142_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_238_1 * 3) + pub_r001142_6_1) + 9) & 127;
  int stage_v_360_2 = (((stage_v_238_2 * 3) + pub_r001142_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001142_10_1 * 2) + 5) & 63;
  int stage_v_361_2 = ((pub_r001142_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001142_1_1 * 2) + 18) & 63;
  int stage_v_362_2 = ((pub_r001142_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001142_19_1 * 2) + 27) & 63;
  int stage_v_363_2 = ((pub_r001142_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_243_1 * 3) + pub_r001142_12_1) + 42) & 127;
  int stage_v_364_2 = (((stage_v_243_2 * 3) + pub_r001142_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001142_5_1 * 2) + 43) & 63;
  int stage_v_365_2 = ((pub_r001142_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001142_7_1 * 2) + 43) & 63;
  int stage_v_366_2 = ((pub_r001142_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001142_6_1 * 2) + 42) & 63;
  int stage_v_367_2 = ((pub_r001142_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = (((stage_v_263_1 * 3) + pub_r001142_16_1) + 27) & 127;
  int stage_v_368_2 = (((stage_v_263_2 * 3) + pub_r001142_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001142_13_1 * 2) + 8) & 63;
  int stage_v_369_2 = ((pub_r001142_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_368_1 * 3) + pub_r001142_1_1) + 41) & 127;
  int stage_v_370_2 = (((stage_v_368_2 * 3) + pub_r001142_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = ((pub_r001142_15_1 * 2) + 40) & 63;
  int stage_v_371_2 = ((pub_r001142_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001142_9_1 * 2) + 20) & 63;
  int stage_v_372_2 = ((pub_r001142_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001142_7_1 * 2) + 14) & 63;
  int stage_v_373_2 = ((pub_r001142_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001142_9_1 * 2) + 16) & 63;
  int stage_v_374_2 = ((pub_r001142_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((stage_v_27_1 * 3) + pub_r001142_12_1) + 44) & 127;
  int stage_v_375_2 = (((stage_v_27_2 * 3) + pub_r001142_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_38_1 * 3) + pub_r001142_1_1) + 44) & 127;
  int stage_v_376_2 = (((stage_v_38_2 * 3) + pub_r001142_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_99_1 * 3) + pub_r001142_4_1) + 24) & 127;
  int stage_v_377_2 = (((stage_v_99_2 * 3) + pub_r001142_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001142_7_1 * 2) + 23) & 63;
  int stage_v_378_2 = ((pub_r001142_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((stage_v_85_1 * 3) + pub_r001142_12_1) + 20) & 127;
  int stage_v_379_2 = (((stage_v_85_2 * 3) + pub_r001142_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001142_8_1 * 2) + 40) & 63;
  int stage_v_380_2 = ((pub_r001142_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001142_3_1 * 2) + 17) & 63;
  int stage_v_381_2 = ((pub_r001142_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_292_1 * 3) + pub_r001142_18_1) + 33) & 127;
  int stage_v_382_2 = (((stage_v_292_2 * 3) + pub_r001142_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001142_4_1 * 2) + 29) & 63;
  int stage_v_383_2 = ((pub_r001142_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001142_21_1 * 2) + 27) & 63;
  int stage_v_384_2 = ((pub_r001142_21_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = (((stage_v_14_1 * 3) + pub_r001142_2_1) + 36) & 127;
  int stage_v_385_2 = (((stage_v_14_2 * 3) + pub_r001142_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = (((sec_r001142_2_1 * 3) + pub_r001142_12_1) + 16) & 127;
  int stage_v_386_2 = (((sec_r001142_2_2 * 3) + pub_r001142_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = ((pub_r001142_5_1 * 2) + 14) & 63;
  int stage_v_387_2 = ((pub_r001142_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001142_1_1 * 2) + 39) & 63;
  int stage_v_388_2 = ((pub_r001142_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001142_2_1 * 2) + 41) & 63;
  int stage_v_389_2 = ((pub_r001142_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_164_1 * 3) + pub_r001142_4_1) + 19) & 127;
  int stage_v_390_2 = (((stage_v_164_2 * 3) + pub_r001142_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_281_1 * 3) + pub_r001142_13_1) + 23) & 127;
  int stage_v_391_2 = (((stage_v_281_2 * 3) + pub_r001142_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = ((pub_r001142_4_1 * 2) + 9) & 63;
  int stage_v_392_2 = ((pub_r001142_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001142_1_1 * 2) + 35) & 63;
  int stage_v_393_2 = ((pub_r001142_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001142_12_1 * 2) + 17) & 63;
  int stage_v_394_2 = ((pub_r001142_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_370_1 * 3) + pub_r001142_3_1) + 4) & 127;
  int stage_v_395_2 = (((stage_v_370_2 * 3) + pub_r001142_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = (((stage_v_156_1 * 3) + pub_r001142_1_1) + 27) & 127;
  int stage_v_396_2 = (((stage_v_156_2 * 3) + pub_r001142_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((sec_r001142_4_1 * 3) + pub_r001142_20_1) + 35) & 127;
  int stage_v_397_2 = (((sec_r001142_4_2 * 3) + pub_r001142_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = ((pub_r001142_0_1 * 2) + 20) & 63;
  int stage_v_398_2 = ((pub_r001142_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = (((stage_v_222_1 * 3) + pub_r001142_8_1) + 45) & 127;
  int stage_v_399_2 = (((stage_v_222_2 * 3) + pub_r001142_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((stage_v_247_1 * 3) + pub_r001142_8_1) + 25) & 127;
  int stage_v_400_2 = (((stage_v_247_2 * 3) + pub_r001142_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001142_15_1 * 2) + 29) & 63;
  int stage_v_401_2 = ((pub_r001142_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_47_1 * 3) + pub_r001142_2_1) + 36) & 127;
  int stage_v_402_2 = (((stage_v_47_2 * 3) + pub_r001142_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = ((pub_r001142_9_1 * 2) + 21) & 63;
  int stage_v_403_2 = ((pub_r001142_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((sec_r001142_0_1 * 3) + pub_r001142_16_1) + 42) & 127;
  int stage_v_404_2 = (((sec_r001142_0_2 * 3) + pub_r001142_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_114_1 * 3) + pub_r001142_20_1) + 16) & 127;
  int stage_v_405_2 = (((stage_v_114_2 * 3) + pub_r001142_20_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((helper_flow_2_1 * 3) + pub_r001142_6_1) + 21) & 127;
  int stage_v_406_2 = (((helper_flow_2_2 * 3) + pub_r001142_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001142_21_1 * 2) + 28) & 63;
  int stage_v_407_2 = ((pub_r001142_21_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_70_1 * 3) + pub_r001142_20_1) + 9) & 127;
  int stage_v_408_2 = (((stage_v_70_2 * 3) + pub_r001142_20_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001142_1_1 * 2) + 42) & 63;
  int stage_v_409_2 = ((pub_r001142_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = (((stage_v_170_1 * 3) + pub_r001142_17_1) + 22) & 127;
  int stage_v_410_2 = (((stage_v_170_2 * 3) + pub_r001142_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = ((pub_r001142_21_1 * 2) + 26) & 63;
  int stage_v_411_2 = ((pub_r001142_21_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_99_1 * 3) + pub_r001142_11_1) + 16) & 127;
  int stage_v_412_2 = (((stage_v_99_2 * 3) + pub_r001142_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = (((stage_v_11_1 * 3) + pub_r001142_9_1) + 28) & 127;
  int stage_v_413_2 = (((stage_v_11_2 * 3) + pub_r001142_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = (((stage_v_240_1 * 3) + pub_r001142_8_1) + 40) & 127;
  int stage_v_414_2 = (((stage_v_240_2 * 3) + pub_r001142_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001142_5_1 * 2) + 20) & 63;
  int stage_v_415_2 = ((pub_r001142_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((sec_r001142_1_1 * 3) + pub_r001142_4_1) + 30) & 127;
  int stage_v_416_2 = (((sec_r001142_1_2 * 3) + pub_r001142_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = ((pub_r001142_7_1 * 2) + 38) & 63;
  int stage_v_417_2 = ((pub_r001142_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = (((stage_v_12_1 * 3) + pub_r001142_4_1) + 26) & 127;
  int stage_v_418_2 = (((stage_v_12_2 * 3) + pub_r001142_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = ((pub_r001142_20_1 * 2) + 9) & 63;
  int stage_v_419_2 = ((pub_r001142_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001142_2_1 * 2) + 30) & 63;
  int stage_v_420_2 = ((pub_r001142_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001142_7_1 * 2) + 39) & 63;
  int stage_v_421_2 = ((pub_r001142_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001142_14_1 * 2) + 7) & 63;
  int stage_v_422_2 = ((pub_r001142_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001142_16_1 * 2) + 16) & 63;
  int stage_v_423_2 = ((pub_r001142_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001142_9_1 * 2) + 11) & 63;
  int stage_v_424_2 = ((pub_r001142_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001142_10_1 * 2) + 27) & 63;
  int stage_v_425_2 = ((pub_r001142_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001142_14_1 * 2) + 33) & 63;
  int stage_v_426_2 = ((pub_r001142_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = (((stage_v_70_1 * 3) + pub_r001142_4_1) + 31) & 127;
  int stage_v_427_2 = (((stage_v_70_2 * 3) + pub_r001142_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = (((stage_v_332_1 * 3) + pub_r001142_8_1) + 12) & 127;
  int stage_v_428_2 = (((stage_v_332_2 * 3) + pub_r001142_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((stage_v_137_1 * 3) + pub_r001142_17_1) + 40) & 127;
  int stage_v_429_2 = (((stage_v_137_2 * 3) + pub_r001142_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = (((stage_v_376_1 * 3) + pub_r001142_0_1) + 20) & 127;
  int stage_v_430_2 = (((stage_v_376_2 * 3) + pub_r001142_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = ((pub_r001142_7_1 * 2) + 21) & 63;
  int stage_v_431_2 = ((pub_r001142_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = (((helper_flow_4_1 * 3) + pub_r001142_6_1) + 39) & 127;
  int stage_v_432_2 = (((helper_flow_4_2 * 3) + pub_r001142_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = (((stage_v_430_1 * 3) + pub_r001142_2_1) + 30) & 127;
  int stage_v_433_2 = (((stage_v_430_2 * 3) + pub_r001142_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = (((stage_v_85_1 * 3) + pub_r001142_3_1) + 37) & 127;
  int stage_v_434_2 = (((stage_v_85_2 * 3) + pub_r001142_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001142_8_1 * 2) + 9) & 63;
  int stage_v_435_2 = ((pub_r001142_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((helper_flow_5_1 * 3) + pub_r001142_13_1) + 44) & 127;
  int stage_v_436_2 = (((helper_flow_5_2 * 3) + pub_r001142_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = ((pub_r001142_21_1 * 2) + 41) & 63;
  int stage_v_437_2 = ((pub_r001142_21_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001142_6_1 * 2) + 42) & 63;
  int stage_v_438_2 = ((pub_r001142_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001142_13_1 * 2) + 8) & 63;
  int stage_v_439_2 = ((pub_r001142_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = (((stage_v_170_1 * 3) + pub_r001142_20_1) + 44) & 127;
  int stage_v_440_2 = (((stage_v_170_2 * 3) + pub_r001142_20_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = (((stage_v_70_1 * 3) + pub_r001142_21_1) + 36) & 127;
  int stage_v_441_2 = (((stage_v_70_2 * 3) + pub_r001142_21_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = (((sec_r001142_0_1 * 3) + pub_r001142_6_1) + 28) & 127;
  int stage_v_442_2 = (((sec_r001142_0_2 * 3) + pub_r001142_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = ((pub_r001142_21_1 * 2) + 26) & 63;
  int stage_v_443_2 = ((pub_r001142_21_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001142_8_1 * 2) + 23) & 63;
  int stage_v_444_2 = ((pub_r001142_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = (((sec_r001142_8_1 * 3) + pub_r001142_8_1) + 10) & 127;
  int stage_v_445_2 = (((sec_r001142_8_2 * 3) + pub_r001142_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = ((pub_r001142_14_1 * 2) + 23) & 63;
  int stage_v_446_2 = ((pub_r001142_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001142_12_1 * 2) + 9) & 63;
  int stage_v_447_2 = ((pub_r001142_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001142_0_1 * 2) + 45) & 63;
  int stage_v_448_2 = ((pub_r001142_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001142_19_1 * 2) + 18) & 63;
  int stage_v_449_2 = ((pub_r001142_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = ((pub_r001142_21_1 * 2) + 23) & 63;
  int stage_v_450_2 = ((pub_r001142_21_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = ((pub_r001142_2_1 * 2) + 15) & 63;
  int stage_v_451_2 = ((pub_r001142_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = ((pub_r001142_15_1 * 2) + 7) & 63;
  int stage_v_452_2 = ((pub_r001142_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001142_18_1 * 2) + 42) & 63;
  int stage_v_453_2 = ((pub_r001142_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001142_12_1 * 2) + 9) & 63;
  int stage_v_454_2 = ((pub_r001142_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001142_20_1 * 2) + 47) & 63;
  int stage_v_455_2 = ((pub_r001142_20_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((pub_r001142_10_1 * 2) + 5) & 63;
  int stage_v_456_2 = ((pub_r001142_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = ((pub_r001142_0_1 * 2) + 10) & 63;
  int stage_v_457_2 = ((pub_r001142_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001142_17_1 * 2) + 27) & 63;
  int stage_v_458_2 = ((pub_r001142_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = (((stage_v_405_1 * 3) + pub_r001142_8_1) + 44) & 127;
  int stage_v_459_2 = (((stage_v_405_2 * 3) + pub_r001142_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = ((pub_r001142_0_1 * 2) + 22) & 63;
  int stage_v_460_2 = ((pub_r001142_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001142_13_1 * 2) + 42) & 63;
  int stage_v_461_2 = ((pub_r001142_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001142_4_1 != sec_r001142_4_2);
  __CPROVER_assume(pub_r001142_6_1 == pub_r001142_6_2);
  __CPROVER_assume(pub_r001142_11_1 == pub_r001142_11_2);
  __CPROVER_assume(sec_r001142_0_1 != sec_r001142_0_2);
  __CPROVER_assume(sec_r001142_8_1 != sec_r001142_8_2);
  __CPROVER_assume(pub_r001142_16_1 == pub_r001142_16_2);
  __CPROVER_assume(sec_r001142_19_1 != sec_r001142_19_2);
  __CPROVER_assume(sec_r001142_13_1 != sec_r001142_13_2);
  __CPROVER_assume(pub_r001142_15_1 == pub_r001142_15_2);
  __CPROVER_assume(sec_r001142_6_1 != sec_r001142_6_2);
  __CPROVER_assume(pub_r001142_21_1 == pub_r001142_21_2);
  __CPROVER_assume(sec_r001142_11_1 != sec_r001142_11_2);
  __CPROVER_assume(pub_r001142_18_1 == pub_r001142_18_2);
  __CPROVER_assume(sec_r001142_5_1 != sec_r001142_5_2);
  __CPROVER_assume(sec_r001142_10_1 != sec_r001142_10_2);
  __CPROVER_assume(pub_r001142_13_1 == pub_r001142_13_2);
  __CPROVER_assume(pub_r001142_9_1 == pub_r001142_9_2);
  __CPROVER_assume(pub_r001142_2_1 == pub_r001142_2_2);
  __CPROVER_assume(sec_r001142_2_1 != sec_r001142_2_2);
  __CPROVER_assume(sec_r001142_20_1 != sec_r001142_20_2);
  __CPROVER_assume(pub_r001142_14_1 == pub_r001142_14_2);
  __CPROVER_assume(sec_r001142_14_1 != sec_r001142_14_2);
  __CPROVER_assume(pub_r001142_19_1 == pub_r001142_19_2);
  __CPROVER_assume(pub_r001142_10_1 == pub_r001142_10_2);
  __CPROVER_assume(sec_r001142_3_1 != sec_r001142_3_2);
  __CPROVER_assume(pub_r001142_17_1 == pub_r001142_17_2);
  __CPROVER_assume(sec_r001142_7_1 != sec_r001142_7_2);
  __CPROVER_assume(sec_r001142_15_1 != sec_r001142_15_2);
  __CPROVER_assume(pub_r001142_7_1 == pub_r001142_7_2);
  __CPROVER_assume(sec_r001142_17_1 != sec_r001142_17_2);
  __CPROVER_assume(pub_r001142_20_1 == pub_r001142_20_2);
  __CPROVER_assume(pub_r001142_5_1 == pub_r001142_5_2);
  __CPROVER_assume(sec_r001142_12_1 != sec_r001142_12_2);
  __CPROVER_assume(sec_r001142_1_1 != sec_r001142_1_2);
  __CPROVER_assume(pub_r001142_12_1 == pub_r001142_12_2);
  __CPROVER_assume(pub_r001142_4_1 == pub_r001142_4_2);
  __CPROVER_assume(sec_r001142_18_1 != sec_r001142_18_2);
  __CPROVER_assume(pub_r001142_3_1 == pub_r001142_3_2);
  __CPROVER_assume(sec_r001142_9_1 != sec_r001142_9_2);
  __CPROVER_assume(pub_r001142_1_1 == pub_r001142_1_2);
  __CPROVER_assume(sec_r001142_21_1 != sec_r001142_21_2);
  __CPROVER_assume(sec_r001142_16_1 != sec_r001142_16_2);
  __CPROVER_assume(pub_r001142_0_1 == pub_r001142_0_2);
  __CPROVER_assume(pub_r001142_8_1 == pub_r001142_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.threshold == st_var_3_2.threshold);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.reading == st_var_3_2.reading);
  assert(st_var_3_1.status == st_var_3_2.status);
  assert(st_var_3_1.calib == st_var_3_2.calib);
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
}


