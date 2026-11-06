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
struct Vector3D_R000047_4713_0
{
  unsigned char coord_z;
  int norm_sq;
  unsigned char pitch;
  unsigned char coord_y;
  int heading;
  short coord_x;
  int buffer[3];
};
struct AudioFrame_R000047_4713_1
{
  short gain;
  short rms;
  int peak;
  int buffer[3];
};
struct StreamBuffer_R000047_4713_2
{
  unsigned char state;
  int head;
  int capacity;
  int checksum;
  int buffer[3];
};
struct SensorNode_R000047_4713_3
{
  int reading;
  short offset;
  int threshold;
  int calib;
  short gain;
  int buffer[3];
};
union RegisterBank_R000047_4713_0
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
void fn_R000047_4713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st_1 = {0};
  struct Vector3D_R000047_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_33_1 = local_arr_1[aux_1 % 3];
  int vector_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_33_2 * 2)) & 127;
  int tracker_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_37_1) & 63;
  aux_2 = (aux_2 + tracker_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_33_1 == vector_33_2);
  assert(tracker_37_1 == tracker_37_2);
}

int fn_R000047_4713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int vector_33 = local_arr[aux % 3];
  acc = (acc + (vector_33 * 2)) & 127;
  int tracker_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000047_4713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st_1 = {0};
  struct Vector3D_R000047_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_65_1) & 63;
  aux_2 = (aux_2 + cursor_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_30_1)
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

  switch (margin_30_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_65_1 == cursor_65_2);
  assert(margin_30_1 == margin_30_2);
}

int fn_R000047_4713_1(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_65) & 63;
  acc ^= aux;
  int margin_30 = (aux + st.buffer[1]) & 3;
  switch (margin_30)
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

void fn_R000047_4713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st_1 = {0};
  struct StreamBuffer_R000047_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int segment_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_64_1) & 63;
  aux_2 = (aux_2 + segment_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_87_1 > 24)
  {
    acc_1 = ((acc_1 + (quantum_87_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_87_2 > 24)
  {
    acc_2 = ((acc_2 + (quantum_87_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_87_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_64_1 == segment_64_2);
  assert(quantum_87_1 == quantum_87_2);
}

int fn_R000047_4713_2(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int segment_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_64) & 63;
  acc ^= aux;
  int quantum_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_87 > 24)
  {
    acc = ((acc + (quantum_87 * 2)) + 5) & 127;
    aux ^= quantum_87 & 15;
  }
  else
  {
    acc = ((acc - quantum_87) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000047_4713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000047_4713_1 st_1 = {0};
  struct AudioFrame_R000047_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tally_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_58_1 > 17)
  {
    acc_1 = ((acc_1 + (tally_58_1 * 2)) + 5) & 127;
    aux_1 ^= tally_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_58_2 > 17)
  {
    acc_2 = ((acc_2 + (tally_58_2 * 2)) + 5) & 127;
    aux_2 ^= tally_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_58_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_42_1)
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

  switch (anchor_42_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_43_1 = local_arr_1[aux_1 % 3];
  int segment_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_58_1 == tally_58_2);
  assert(anchor_42_1 == anchor_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_43_1 == segment_43_2);
}

int fn_R000047_4713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000047_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tally_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_58 > 17)
  {
    acc = ((acc + (tally_58 * 2)) + 5) & 127;
    aux ^= tally_58 & 15;
  }
  else
  {
    acc = ((acc - tally_58) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_42 = (aux + st.buffer[1]) & 3;
  switch (anchor_42)
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

  int local_arr[3] = {4, 9, 15};
  int segment_43 = local_arr[aux % 3];
  acc = (acc + (segment_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000047_4713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000047_4713_1 st_1 = {0};
  struct AudioFrame_R000047_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int factor_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_59_1 > 10)
  {
    acc_1 = ((acc_1 + (factor_59_1 * 2)) + 5) & 127;
    aux_1 ^= factor_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_59_2 > 10)
  {
    acc_2 = ((acc_2 + (factor_59_2 * 2)) + 5) & 127;
    aux_2 ^= factor_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_56_1 = local_arr_1[aux_1 % 3];
  int phase_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_56_2 * 2)) & 127;
  int margin_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_83_1)
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

  switch (margin_83_2)
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

  int margin_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_44_1) & 63;
  aux_2 = (aux_2 + margin_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_59_1 == factor_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_56_1 == phase_56_2);
  assert(margin_83_1 == margin_83_2);
  assert(margin_44_1 == margin_44_2);
}

int fn_R000047_4713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000047_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int factor_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_59 > 10)
  {
    acc = ((acc + (factor_59 * 2)) + 5) & 127;
    aux ^= factor_59 & 15;
  }
  else
  {
    acc = ((acc - factor_59) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_56 = local_arr[aux % 3];
  acc = (acc + (phase_56 * 2)) & 127;
  int margin_83 = (aux + st.buffer[1]) & 3;
  switch (margin_83)
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

  int margin_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000047_4713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st_1 = {0};
  struct StreamBuffer_R000047_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int window_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_51_1 > 29)
  {
    acc_1 = ((acc_1 + (window_51_1 * 2)) + 5) & 127;
    aux_1 ^= window_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_51_2 > 29)
  {
    acc_2 = ((acc_2 + (window_51_2 * 2)) + 5) & 127;
    aux_2 ^= window_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_96_1 = local_arr_1[aux_1 % 3];
  int sample_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_51_1 == window_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_96_1 == sample_96_2);
}

int fn_R000047_4713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int window_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_51 > 29)
  {
    acc = ((acc + (window_51 * 2)) + 5) & 127;
    aux ^= window_51 & 15;
  }
  else
  {
    acc = ((acc - window_51) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_96 = local_arr[aux % 3];
  acc = (acc + (sample_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000047_4713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000047_4713_3 st_1 = {0};
  struct SensorNode_R000047_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int quotient_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_22_1) & 63;
  aux_2 = (aux_2 + quotient_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_59_1 = local_arr_1[aux_1 % 3];
  int quotient_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_22_1 == quotient_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_59_1 == quotient_59_2);
}

int fn_R000047_4713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000047_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int quotient_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_22) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_59 = local_arr[aux % 3];
  acc = (acc + (quotient_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000047_4713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st_1 = {0};
  struct StreamBuffer_R000047_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int mask_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_62_1)
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

  switch (mask_62_2)
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

  int accumulator_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_58_1 > 38)
  {
    acc_1 = ((acc_1 + (accumulator_58_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_58_2 > 38)
  {
    acc_2 = ((acc_2 + (accumulator_58_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_62_1 == mask_62_2);
  assert(accumulator_58_1 == accumulator_58_2);
}

int fn_R000047_4713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int mask_62 = (aux + st.buffer[1]) & 3;
  switch (mask_62)
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

  int accumulator_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_58 > 38)
  {
    acc = ((acc + (accumulator_58 * 2)) + 5) & 127;
    aux ^= accumulator_58 & 15;
  }
  else
  {
    acc = ((acc - accumulator_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000047_4713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000047_4713_3 st_1 = {0};
  struct SensorNode_R000047_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_26_1)
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

  switch (index_reg_26_2)
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

  int cursor_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_25_1) & 63;
  aux_2 = (aux_2 + cursor_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_26_1 == index_reg_26_2);
  assert(cursor_25_1 == cursor_25_2);
}

int fn_R000047_4713_8(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000047_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_26 = (aux + st.buffer[1]) & 3;
  switch (index_reg_26)
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

  int cursor_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_25) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000047_4713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st_1 = {0};
  struct StreamBuffer_R000047_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tracker_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_34_1 > 18)
  {
    acc_1 = ((acc_1 + (tracker_34_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_34_2 > 18)
  {
    acc_2 = ((acc_2 + (tracker_34_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_81_1) & 63;
  aux_2 = (aux_2 + scale_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_34_1 == tracker_34_2);
  assert(scale_81_1 == scale_81_2);
}

int fn_R000047_4713_9(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tracker_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_34 > 18)
  {
    acc = ((acc + (tracker_34 * 2)) + 5) & 127;
    aux ^= tracker_34 & 15;
  }
  else
  {
    acc = ((acc - tracker_34) + 11) & 127;
    aux += 3;
  }
  int scale_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000047_4713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000047_4713_1 st_1 = {0};
  struct AudioFrame_R000047_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_87_1 > 29)
  {
    acc_1 = ((acc_1 + (offset_87_1 * 2)) + 5) & 127;
    aux_1 ^= offset_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_87_2 > 29)
  {
    acc_2 = ((acc_2 + (offset_87_2 * 2)) + 5) & 127;
    aux_2 ^= offset_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_17_1 = local_arr_1[aux_1 % 3];
  int parity_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_17_2 * 2)) & 127;
  int damping_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_36_1) & 63;
  aux_2 = (aux_2 + damping_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_87_1 == offset_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_17_1 == parity_17_2);
  assert(damping_36_1 == damping_36_2);
}

int fn_R000047_4713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000047_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_87 > 29)
  {
    acc = ((acc + (offset_87 * 2)) + 5) & 127;
    aux ^= offset_87 & 15;
  }
  else
  {
    acc = ((acc - offset_87) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_17 = local_arr[aux % 3];
  acc = (acc + (parity_17 * 2)) & 127;
  int damping_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_36) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000047_4713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st_1 = {0};
  struct Vector3D_R000047_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int cursor_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_12_1 > 48)
  {
    acc_1 = ((acc_1 + (cursor_12_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_12_2 > 48)
  {
    acc_2 = ((acc_2 + (cursor_12_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_98_1)
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

  switch (mask_98_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_12_1 == cursor_12_2);
  assert(mask_98_1 == mask_98_2);
}

int fn_R000047_4713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int cursor_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_12 > 48)
  {
    acc = ((acc + (cursor_12 * 2)) + 5) & 127;
    aux ^= cursor_12 & 15;
  }
  else
  {
    acc = ((acc - cursor_12) + 11) & 127;
    aux += 3;
  }
  int mask_98 = (aux + st.buffer[1]) & 3;
  switch (mask_98)
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

void fn_R000047_4713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st_1 = {0};
  struct Vector3D_R000047_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int factor_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_63_1) & 63;
  aux_2 = (aux_2 + factor_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_41_1 > 16)
  {
    acc_1 = ((acc_1 + (window_41_1 * 2)) + 5) & 127;
    aux_1 ^= window_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_41_2 > 16)
  {
    acc_2 = ((acc_2 + (window_41_2 * 2)) + 5) & 127;
    aux_2 ^= window_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_22_1 = local_arr_1[aux_1 % 3];
  int damping_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_63_1 == factor_63_2);
  assert(window_41_1 == window_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_22_1 == damping_22_2);
}

int fn_R000047_4713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_63) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_41 > 16)
  {
    acc = ((acc + (window_41 * 2)) + 5) & 127;
    aux ^= window_41 & 15;
  }
  else
  {
    acc = ((acc - window_41) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_22 = local_arr[aux % 3];
  acc = (acc + (damping_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000047_4713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st_1 = {0};
  struct Vector3D_R000047_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int scale_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_63_1) & 63;
  aux_2 = (aux_2 + scale_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_55_1 > 40)
  {
    acc_1 = ((acc_1 + (pivot_55_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_55_2 > 40)
  {
    acc_2 = ((acc_2 + (pivot_55_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_74_1)
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

  switch (parity_74_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_63_1 == scale_63_2);
  assert(pivot_55_1 == pivot_55_2);
  assert(parity_74_1 == parity_74_2);
}

int fn_R000047_4713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000047_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int scale_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_63) & 63;
  acc ^= aux;
  int pivot_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_55 > 40)
  {
    acc = ((acc + (pivot_55 * 2)) + 5) & 127;
    aux ^= pivot_55 & 15;
  }
  else
  {
    acc = ((acc - pivot_55) + 11) & 127;
    aux += 3;
  }
  int parity_74 = (aux + st.buffer[1]) & 3;
  switch (parity_74)
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

void fn_R000047_4713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st_1 = {0};
  struct StreamBuffer_R000047_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int stride_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_39_1 > 35)
  {
    acc_1 = ((acc_1 + (stride_39_1 * 2)) + 5) & 127;
    aux_1 ^= stride_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_39_2 > 35)
  {
    acc_2 = ((acc_2 + (stride_39_2 * 2)) + 5) & 127;
    aux_2 ^= stride_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_80_1) & 63;
  aux_2 = (aux_2 + factor_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_39_1 == stride_39_2);
  assert(factor_80_1 == factor_80_2);
}

int fn_R000047_4713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int stride_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_39 > 35)
  {
    acc = ((acc + (stride_39 * 2)) + 5) & 127;
    aux ^= stride_39 & 15;
  }
  else
  {
    acc = ((acc - stride_39) + 11) & 127;
    aux += 3;
  }
  int factor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_80) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000047_4713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st_1 = {0};
  struct StreamBuffer_R000047_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quotient_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_12_1 > 48)
  {
    acc_1 = ((acc_1 + (quotient_12_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_12_2 > 48)
  {
    acc_2 = ((acc_2 + (quotient_12_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_27_1 = local_arr_1[aux_1 % 3];
  int weight_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_27_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_12_1 == quotient_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_27_1 == weight_27_2);
}

int fn_R000047_4713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000047_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quotient_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_12 > 48)
  {
    acc = ((acc + (quotient_12 * 2)) + 5) & 127;
    aux ^= quotient_12 & 15;
  }
  else
  {
    acc = ((acc - quotient_12) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int weight_27 = local_arr[aux % 3];
  acc = (acc + (weight_27 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000047_4713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000047_4713_1 st_1 = {0};
  struct AudioFrame_R000047_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_82_1 = local_arr_1[aux_1 % 3];
  int window_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_82_2 * 2)) & 127;
  int index_reg_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_65_1 > 18)
  {
    acc_1 = ((acc_1 + (index_reg_65_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_65_2 > 18)
  {
    acc_2 = ((acc_2 + (index_reg_65_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_30_1) & 63;
  aux_2 = (aux_2 + delta_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_82_1 == window_82_2);
  assert(index_reg_65_1 == index_reg_65_2);
  assert(delta_30_1 == delta_30_2);
}

int fn_R000047_4713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000047_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int window_82 = local_arr[aux % 3];
  acc = (acc + (window_82 * 2)) & 127;
  int index_reg_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_65 > 18)
  {
    acc = ((acc + (index_reg_65 * 2)) + 5) & 127;
    aux ^= index_reg_65 & 15;
  }
  else
  {
    acc = ((acc - index_reg_65) + 11) & 127;
    aux += 3;
  }
  int delta_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000047_4713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000047_4713_3 st_1 = {0};
  struct SensorNode_R000047_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_14_1 = local_arr_1[aux_1 % 3];
  int stride_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_14_2 * 2)) & 127;
  int vector_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_73_1) & 63;
  aux_2 = (aux_2 + vector_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_66_1 > 31)
  {
    acc_1 = ((acc_1 + (metric_66_1 * 2)) + 5) & 127;
    aux_1 ^= metric_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_66_2 > 31)
  {
    acc_2 = ((acc_2 + (metric_66_2 * 2)) + 5) & 127;
    aux_2 ^= metric_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_40_1)
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

  switch (quantum_40_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_14_1 == stride_14_2);
  assert(vector_73_1 == vector_73_2);
  assert(metric_66_1 == metric_66_2);
  assert(quantum_40_1 == quantum_40_2);
}

int fn_R000047_4713_17(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000047_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int stride_14 = local_arr[aux % 3];
  acc = (acc + (stride_14 * 2)) & 127;
  int vector_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_73) & 63;
  acc ^= aux;
  int metric_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_66 > 31)
  {
    acc = ((acc + (metric_66 * 2)) + 5) & 127;
    aux ^= metric_66 & 15;
  }
  else
  {
    acc = ((acc - metric_66) + 11) & 127;
    aux += 3;
  }
  int quantum_40 = (aux + st.buffer[1]) & 3;
  switch (quantum_40)
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

void main()
{
  int sec_r000047_0_1;
  int sec_r000047_0_2;
  int sec_r000047_1_1;
  int sec_r000047_1_2;
  int sec_r000047_2_1;
  int sec_r000047_2_2;
  int sec_r000047_3_1;
  int sec_r000047_3_2;
  int sec_r000047_4_1;
  int sec_r000047_4_2;
  int sec_r000047_5_1;
  int sec_r000047_5_2;
  int sec_r000047_6_1;
  int sec_r000047_6_2;
  int sec_r000047_7_1;
  int sec_r000047_7_2;
  int sec_r000047_8_1;
  int sec_r000047_8_2;
  int sec_r000047_9_1;
  int sec_r000047_9_2;
  int sec_r000047_10_1;
  int sec_r000047_10_2;
  int sec_r000047_11_1;
  int sec_r000047_11_2;
  int sec_r000047_12_1;
  int sec_r000047_12_2;
  int sec_r000047_13_1;
  int sec_r000047_13_2;
  int sec_r000047_14_1;
  int sec_r000047_14_2;
  int sec_r000047_15_1;
  int sec_r000047_15_2;
  int sec_r000047_16_1;
  int sec_r000047_16_2;
  int sec_r000047_17_1;
  int sec_r000047_17_2;
  int sec_r000047_18_1;
  int sec_r000047_18_2;
  int sec_r000047_19_1;
  int sec_r000047_19_2;
  int sec_r000047_20_1;
  int sec_r000047_20_2;
  int sec_r000047_21_1;
  int sec_r000047_21_2;
  int sec_r000047_22_1;
  int sec_r000047_22_2;
  int pub_r000047_0_1;
  int pub_r000047_0_2;
  int pub_r000047_1_1;
  int pub_r000047_1_2;
  int pub_r000047_2_1;
  int pub_r000047_2_2;
  int pub_r000047_3_1;
  int pub_r000047_3_2;
  int pub_r000047_4_1;
  int pub_r000047_4_2;
  int pub_r000047_5_1;
  int pub_r000047_5_2;
  int pub_r000047_6_1;
  int pub_r000047_6_2;
  int pub_r000047_7_1;
  int pub_r000047_7_2;
  int pub_r000047_8_1;
  int pub_r000047_8_2;
  int pub_r000047_9_1;
  int pub_r000047_9_2;
  int pub_r000047_10_1;
  int pub_r000047_10_2;
  int pub_r000047_11_1;
  int pub_r000047_11_2;
  int pub_r000047_12_1;
  int pub_r000047_12_2;
  int pub_r000047_13_1;
  int pub_r000047_13_2;
  int pub_r000047_14_1;
  int pub_r000047_14_2;
  int pub_r000047_15_1;
  int pub_r000047_15_2;
  int pub_r000047_16_1;
  int pub_r000047_16_2;
  int pub_r000047_17_1;
  int pub_r000047_17_2;
  int pub_r000047_18_1;
  int pub_r000047_18_2;
  int pub_r000047_19_1;
  int pub_r000047_19_2;
  int pub_r000047_20_1;
  int pub_r000047_20_2;
  int pub_r000047_21_1;
  int pub_r000047_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000047_0_1 >= (-100)) && (pub_r000047_0_1 <= 100));
  __CPROVER_assume((pub_r000047_0_2 >= (-100)) && (pub_r000047_0_2 <= 100));
  __CPROVER_assume((pub_r000047_1_1 >= (-100)) && (pub_r000047_1_1 <= 100));
  __CPROVER_assume((pub_r000047_1_2 >= (-100)) && (pub_r000047_1_2 <= 100));
  __CPROVER_assume((pub_r000047_2_1 >= (-100)) && (pub_r000047_2_1 <= 100));
  __CPROVER_assume((pub_r000047_2_2 >= (-100)) && (pub_r000047_2_2 <= 100));
  __CPROVER_assume((pub_r000047_3_1 >= (-100)) && (pub_r000047_3_1 <= 100));
  __CPROVER_assume((pub_r000047_3_2 >= (-100)) && (pub_r000047_3_2 <= 100));
  __CPROVER_assume((pub_r000047_4_1 >= (-100)) && (pub_r000047_4_1 <= 100));
  __CPROVER_assume((pub_r000047_4_2 >= (-100)) && (pub_r000047_4_2 <= 100));
  __CPROVER_assume((pub_r000047_5_1 >= (-100)) && (pub_r000047_5_1 <= 100));
  __CPROVER_assume((pub_r000047_5_2 >= (-100)) && (pub_r000047_5_2 <= 100));
  __CPROVER_assume((pub_r000047_6_1 >= (-100)) && (pub_r000047_6_1 <= 100));
  __CPROVER_assume((pub_r000047_6_2 >= (-100)) && (pub_r000047_6_2 <= 100));
  __CPROVER_assume((pub_r000047_7_1 >= (-100)) && (pub_r000047_7_1 <= 100));
  __CPROVER_assume((pub_r000047_7_2 >= (-100)) && (pub_r000047_7_2 <= 100));
  __CPROVER_assume((pub_r000047_8_1 >= (-100)) && (pub_r000047_8_1 <= 100));
  __CPROVER_assume((pub_r000047_8_2 >= (-100)) && (pub_r000047_8_2 <= 100));
  __CPROVER_assume((pub_r000047_9_1 >= (-100)) && (pub_r000047_9_1 <= 100));
  __CPROVER_assume((pub_r000047_9_2 >= (-100)) && (pub_r000047_9_2 <= 100));
  __CPROVER_assume((pub_r000047_10_1 >= (-100)) && (pub_r000047_10_1 <= 100));
  __CPROVER_assume((pub_r000047_10_2 >= (-100)) && (pub_r000047_10_2 <= 100));
  __CPROVER_assume((pub_r000047_11_1 >= (-100)) && (pub_r000047_11_1 <= 100));
  __CPROVER_assume((pub_r000047_11_2 >= (-100)) && (pub_r000047_11_2 <= 100));
  __CPROVER_assume((pub_r000047_12_1 >= (-100)) && (pub_r000047_12_1 <= 100));
  __CPROVER_assume((pub_r000047_12_2 >= (-100)) && (pub_r000047_12_2 <= 100));
  __CPROVER_assume((pub_r000047_13_1 >= (-100)) && (pub_r000047_13_1 <= 100));
  __CPROVER_assume((pub_r000047_13_2 >= (-100)) && (pub_r000047_13_2 <= 100));
  __CPROVER_assume((pub_r000047_14_1 >= (-100)) && (pub_r000047_14_1 <= 100));
  __CPROVER_assume((pub_r000047_14_2 >= (-100)) && (pub_r000047_14_2 <= 100));
  __CPROVER_assume((pub_r000047_15_1 >= (-100)) && (pub_r000047_15_1 <= 100));
  __CPROVER_assume((pub_r000047_15_2 >= (-100)) && (pub_r000047_15_2 <= 100));
  __CPROVER_assume((pub_r000047_16_1 >= (-100)) && (pub_r000047_16_1 <= 100));
  __CPROVER_assume((pub_r000047_16_2 >= (-100)) && (pub_r000047_16_2 <= 100));
  __CPROVER_assume((pub_r000047_17_1 >= (-100)) && (pub_r000047_17_1 <= 100));
  __CPROVER_assume((pub_r000047_17_2 >= (-100)) && (pub_r000047_17_2 <= 100));
  __CPROVER_assume((pub_r000047_18_1 >= (-100)) && (pub_r000047_18_1 <= 100));
  __CPROVER_assume((pub_r000047_18_2 >= (-100)) && (pub_r000047_18_2 <= 100));
  __CPROVER_assume((pub_r000047_19_1 >= (-100)) && (pub_r000047_19_1 <= 100));
  __CPROVER_assume((pub_r000047_19_2 >= (-100)) && (pub_r000047_19_2 <= 100));
  __CPROVER_assume((pub_r000047_20_1 >= (-100)) && (pub_r000047_20_1 <= 100));
  __CPROVER_assume((pub_r000047_20_2 >= (-100)) && (pub_r000047_20_2 <= 100));
  __CPROVER_assume((pub_r000047_21_1 >= (-100)) && (pub_r000047_21_1 <= 100));
  __CPROVER_assume((pub_r000047_21_2 >= (-100)) && (pub_r000047_21_2 <= 100));
  __CPROVER_assume((sec_r000047_0_1 >= 0) && (sec_r000047_0_1 <= 255));
  __CPROVER_assume((sec_r000047_0_2 >= 0) && (sec_r000047_0_2 <= 255));
  __CPROVER_assume((sec_r000047_1_1 >= 0) && (sec_r000047_1_1 <= 255));
  __CPROVER_assume((sec_r000047_1_2 >= 0) && (sec_r000047_1_2 <= 255));
  __CPROVER_assume((sec_r000047_2_1 >= 0) && (sec_r000047_2_1 <= 255));
  __CPROVER_assume((sec_r000047_2_2 >= 0) && (sec_r000047_2_2 <= 255));
  __CPROVER_assume((sec_r000047_3_1 >= 0) && (sec_r000047_3_1 <= 255));
  __CPROVER_assume((sec_r000047_3_2 >= 0) && (sec_r000047_3_2 <= 255));
  __CPROVER_assume((sec_r000047_4_1 >= 0) && (sec_r000047_4_1 <= 255));
  __CPROVER_assume((sec_r000047_4_2 >= 0) && (sec_r000047_4_2 <= 255));
  __CPROVER_assume((sec_r000047_5_1 >= 0) && (sec_r000047_5_1 <= 255));
  __CPROVER_assume((sec_r000047_5_2 >= 0) && (sec_r000047_5_2 <= 255));
  __CPROVER_assume((sec_r000047_6_1 >= 0) && (sec_r000047_6_1 <= 255));
  __CPROVER_assume((sec_r000047_6_2 >= 0) && (sec_r000047_6_2 <= 255));
  __CPROVER_assume((sec_r000047_7_1 >= 0) && (sec_r000047_7_1 <= 255));
  __CPROVER_assume((sec_r000047_7_2 >= 0) && (sec_r000047_7_2 <= 255));
  __CPROVER_assume((sec_r000047_8_1 >= 0) && (sec_r000047_8_1 <= 255));
  __CPROVER_assume((sec_r000047_8_2 >= 0) && (sec_r000047_8_2 <= 255));
  __CPROVER_assume((sec_r000047_9_1 >= 0) && (sec_r000047_9_1 <= 255));
  __CPROVER_assume((sec_r000047_9_2 >= 0) && (sec_r000047_9_2 <= 255));
  __CPROVER_assume((sec_r000047_10_1 >= 0) && (sec_r000047_10_1 <= 255));
  __CPROVER_assume((sec_r000047_10_2 >= 0) && (sec_r000047_10_2 <= 255));
  __CPROVER_assume((sec_r000047_11_1 >= 0) && (sec_r000047_11_1 <= 255));
  __CPROVER_assume((sec_r000047_11_2 >= 0) && (sec_r000047_11_2 <= 255));
  __CPROVER_assume((sec_r000047_12_1 >= 0) && (sec_r000047_12_1 <= 255));
  __CPROVER_assume((sec_r000047_12_2 >= 0) && (sec_r000047_12_2 <= 255));
  __CPROVER_assume((sec_r000047_13_1 >= 0) && (sec_r000047_13_1 <= 255));
  __CPROVER_assume((sec_r000047_13_2 >= 0) && (sec_r000047_13_2 <= 255));
  __CPROVER_assume((sec_r000047_14_1 >= 0) && (sec_r000047_14_1 <= 255));
  __CPROVER_assume((sec_r000047_14_2 >= 0) && (sec_r000047_14_2 <= 255));
  __CPROVER_assume((sec_r000047_15_1 >= 0) && (sec_r000047_15_1 <= 255));
  __CPROVER_assume((sec_r000047_15_2 >= 0) && (sec_r000047_15_2 <= 255));
  __CPROVER_assume((sec_r000047_16_1 >= 0) && (sec_r000047_16_1 <= 255));
  __CPROVER_assume((sec_r000047_16_2 >= 0) && (sec_r000047_16_2 <= 255));
  __CPROVER_assume((sec_r000047_17_1 >= 0) && (sec_r000047_17_1 <= 255));
  __CPROVER_assume((sec_r000047_17_2 >= 0) && (sec_r000047_17_2 <= 255));
  __CPROVER_assume((sec_r000047_18_1 >= 0) && (sec_r000047_18_1 <= 255));
  __CPROVER_assume((sec_r000047_18_2 >= 0) && (sec_r000047_18_2 <= 255));
  __CPROVER_assume((sec_r000047_19_1 >= 0) && (sec_r000047_19_1 <= 255));
  __CPROVER_assume((sec_r000047_19_2 >= 0) && (sec_r000047_19_2 <= 255));
  __CPROVER_assume((sec_r000047_20_1 >= 0) && (sec_r000047_20_1 <= 255));
  __CPROVER_assume((sec_r000047_20_2 >= 0) && (sec_r000047_20_2 <= 255));
  __CPROVER_assume((sec_r000047_21_1 >= 0) && (sec_r000047_21_1 <= 255));
  __CPROVER_assume((sec_r000047_21_2 >= 0) && (sec_r000047_21_2 <= 255));
  __CPROVER_assume((sec_r000047_22_1 >= 0) && (sec_r000047_22_1 <= 255));
  __CPROVER_assume((sec_r000047_22_2 >= 0) && (sec_r000047_22_2 <= 255));
  struct Vector3D_R000047_4713_0 st_var_0_1 = {0};
  struct Vector3D_R000047_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000047_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000047_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000047_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000047_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000047_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000047_0_2 + 7) & 15;
  struct AudioFrame_R000047_4713_1 st_var_1_1 = {0};
  struct AudioFrame_R000047_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000047_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000047_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000047_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000047_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000047_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000047_0_2 + 9) & 15;
  struct StreamBuffer_R000047_4713_2 st_var_2_1 = {0};
  struct StreamBuffer_R000047_4713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000047_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000047_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000047_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000047_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000047_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000047_0_2 + 11) & 15;
  struct SensorNode_R000047_4713_3 st_var_3_1 = {0};
  struct SensorNode_R000047_4713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000047_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000047_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000047_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000047_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000047_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000047_0_2 + 13) & 15;
  union RegisterBank_R000047_4713_0 u_var_1;
  union RegisterBank_R000047_4713_0 u_var_2;
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
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((st_var_3_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_3_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 30)
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
  if (stage_v_7_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 30)
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
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 43)
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
  if (stage_v_8_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 43)
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 51)
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
  if (stage_v_13_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 51)
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
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 51)
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
  if (stage_v_14_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 51)
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
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
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
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 30)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 30)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 47)
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
  if (stage_v_37_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 47)
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
  if (stage_v_38_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 48)
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
  if (stage_v_38_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 48)
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
  int stage_v_39_1 = (st_var_3_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_3_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 43) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((st_var_2_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_2_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 39)
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
  if (stage_v_46_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 39)
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
  int stage_v_47_1 = ((st_var_3_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_3_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 29)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 29)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 55)
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
  if (stage_v_49_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 55)
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
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((sec_r000047_15_1 & 1) != 0)
  {
    if ((sec_r000047_2_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000047_11_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000047_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000047_11_1 + 7) & 127;
  }
  if ((sec_r000047_15_2 & 1) != 0)
  {
    if ((sec_r000047_2_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000047_11_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000047_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000047_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000047_5_1 & 1) != 0)
  {
    if ((sec_r000047_19_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000047_15_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000047_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000047_15_1 + 7) & 127;
  }
  if ((sec_r000047_5_2 & 1) != 0)
  {
    if ((sec_r000047_19_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000047_15_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000047_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000047_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000047_19_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000047_12_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000047_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000047_12_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000047_19_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000047_12_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000047_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000047_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000047_13_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000047_10_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000047_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000047_10_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000047_13_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000047_10_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000047_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000047_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000047_0_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000047_8_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000047_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000047_8_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000047_0_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000047_8_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000047_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000047_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000047_16_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000047_12_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000047_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000047_12_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000047_16_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000047_12_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000047_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000047_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000047_7_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000047_10_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000047_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000047_10_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000047_7_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000047_10_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000047_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000047_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000047_2_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000047_7_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000047_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000047_7_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000047_2_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000047_7_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000047_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000047_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000047_11_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000047_18_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000047_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000047_18_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000047_11_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000047_18_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000047_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000047_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000047_3_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000047_10_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000047_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000047_10_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000047_3_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000047_10_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000047_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000047_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000047_13_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000047_0_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000047_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000047_0_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000047_13_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000047_0_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000047_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000047_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000047_6_1 & 1) != 0)
  {
    if ((sec_r000047_8_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000047_0_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000047_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000047_0_1 + 7) & 127;
  }
  if ((sec_r000047_6_2 & 1) != 0)
  {
    if ((sec_r000047_8_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000047_0_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000047_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000047_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000047_1_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000047_4_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000047_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000047_4_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000047_1_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000047_4_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000047_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000047_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000047_17_1 & 1) != 0)
  {
    if ((sec_r000047_21_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000047_10_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000047_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000047_10_1 + 7) & 127;
  }
  if ((sec_r000047_17_2 & 1) != 0)
  {
    if ((sec_r000047_21_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000047_10_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000047_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000047_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000047_20_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000047_2_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000047_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000047_2_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000047_20_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000047_2_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000047_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000047_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000047_3_1 & 1) != 0)
  {
    if ((sec_r000047_4_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000047_10_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000047_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000047_10_1 + 7) & 127;
  }
  if ((sec_r000047_3_2 & 1) != 0)
  {
    if ((sec_r000047_4_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000047_10_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000047_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000047_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000047_12_1 & 1) != 0)
  {
    if ((sec_r000047_18_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000047_1_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000047_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000047_1_1 + 7) & 127;
  }
  if ((sec_r000047_12_2 & 1) != 0)
  {
    if ((sec_r000047_18_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000047_1_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000047_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000047_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000047_4_1 & 1) != 0)
  {
    if ((sec_r000047_22_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000047_7_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000047_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000047_7_1 + 7) & 127;
  }
  if ((sec_r000047_4_2 & 1) != 0)
  {
    if ((sec_r000047_22_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000047_7_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000047_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000047_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000047_8_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000047_17_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000047_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000047_17_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000047_8_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000047_17_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000047_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000047_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000047_7_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000047_18_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000047_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000047_18_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000047_7_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000047_18_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000047_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000047_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000047_7_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000047_15_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000047_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000047_15_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000047_7_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000047_15_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000047_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000047_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000047_2_1 & 1) != 0)
  {
    if ((sec_r000047_14_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000047_13_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000047_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000047_13_1 + 7) & 127;
  }
  if ((sec_r000047_2_2 & 1) != 0)
  {
    if ((sec_r000047_14_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000047_13_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000047_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000047_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000047_20_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000047_18_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000047_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000047_18_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000047_20_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000047_18_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000047_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000047_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000047_5_1 & 1) != 0)
  {
    if ((sec_r000047_16_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000047_1_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000047_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000047_1_1 + 7) & 127;
  }
  if ((sec_r000047_5_2 & 1) != 0)
  {
    if ((sec_r000047_16_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000047_1_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000047_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000047_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000047_22_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000047_2_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000047_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000047_2_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000047_22_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000047_2_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000047_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000047_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000047_7_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000047_6_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000047_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000047_6_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000047_7_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000047_6_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000047_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000047_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000047_11_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000047_1_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000047_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000047_1_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000047_11_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000047_1_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000047_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000047_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000047_14_1 & 1) != 0)
  {
    if ((sec_r000047_20_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000047_9_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000047_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000047_9_1 + 7) & 127;
  }
  if ((sec_r000047_14_2 & 1) != 0)
  {
    if ((sec_r000047_20_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000047_9_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000047_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000047_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000047_14_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000047_4_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000047_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000047_4_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000047_14_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000047_4_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000047_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000047_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000047_21_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000047_4_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000047_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000047_4_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000047_21_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000047_4_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000047_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000047_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000047_2_1 & 1) != 0)
  {
    if ((sec_r000047_22_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000047_13_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000047_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000047_13_1 + 7) & 127;
  }
  if ((sec_r000047_2_2 & 1) != 0)
  {
    if ((sec_r000047_22_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000047_13_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000047_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000047_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000047_20_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000047_17_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000047_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000047_17_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000047_20_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000047_17_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000047_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000047_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000047_14_1 & 1) != 0)
  {
    if ((sec_r000047_4_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000047_5_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000047_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000047_5_1 + 7) & 127;
  }
  if ((sec_r000047_14_2 & 1) != 0)
  {
    if ((sec_r000047_4_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000047_5_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000047_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000047_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000047_6_1 & 1) != 0)
  {
    if ((sec_r000047_13_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000047_15_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000047_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000047_15_1 + 7) & 127;
  }
  if ((sec_r000047_6_2 & 1) != 0)
  {
    if ((sec_r000047_13_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000047_15_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000047_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000047_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000047_22_1 & 1) != 0)
  {
    if ((sec_r000047_6_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000047_15_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000047_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000047_15_1 + 7) & 127;
  }
  if ((sec_r000047_22_2 & 1) != 0)
  {
    if ((sec_r000047_6_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000047_15_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000047_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000047_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000047_10_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000047_0_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000047_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000047_0_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000047_10_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000047_0_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000047_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000047_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000047_9_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000047_3_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000047_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000047_3_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000047_9_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000047_3_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000047_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000047_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000047_18_1 & 1) != 0)
  {
    if ((sec_r000047_2_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000047_20_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000047_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000047_20_1 + 7) & 127;
  }
  if ((sec_r000047_18_2 & 1) != 0)
  {
    if ((sec_r000047_2_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000047_20_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000047_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000047_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000047_12_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000047_11_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000047_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000047_11_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000047_12_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000047_11_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000047_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000047_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000047_10_1 & 1) != 0)
  {
    if ((sec_r000047_2_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000047_13_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000047_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000047_13_1 + 7) & 127;
  }
  if ((sec_r000047_10_2 & 1) != 0)
  {
    if ((sec_r000047_2_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000047_13_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000047_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000047_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000047_18_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000047_2_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000047_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000047_2_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000047_18_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000047_2_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000047_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000047_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000047_5_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000047_11_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000047_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000047_11_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000047_5_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000047_11_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000047_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000047_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000047_13_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000047_11_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000047_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000047_11_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000047_13_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000047_11_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000047_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000047_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000047_18_1 & 1) != 0)
  {
    if ((sec_r000047_13_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000047_2_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000047_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000047_2_1 + 7) & 127;
  }
  if ((sec_r000047_18_2 & 1) != 0)
  {
    if ((sec_r000047_13_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000047_2_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000047_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000047_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000047_15_1 & 1) != 0)
  {
    if ((sec_r000047_20_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000047_15_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000047_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000047_15_1 + 7) & 127;
  }
  if ((sec_r000047_15_2 & 1) != 0)
  {
    if ((sec_r000047_20_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000047_15_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000047_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000047_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000047_6_1 & 1) != 0)
  {
    if ((sec_r000047_15_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000047_6_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000047_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000047_6_1 + 7) & 127;
  }
  if ((sec_r000047_6_2 & 1) != 0)
  {
    if ((sec_r000047_15_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000047_6_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000047_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000047_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000047_9_1 & 1) != 0)
  {
    if ((sec_r000047_16_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000047_4_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000047_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000047_4_1 + 7) & 127;
  }
  if ((sec_r000047_9_2 & 1) != 0)
  {
    if ((sec_r000047_16_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000047_4_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000047_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000047_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000047_2_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000047_4_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000047_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000047_4_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000047_2_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000047_4_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000047_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000047_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000047_16_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000047_1_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000047_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000047_1_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000047_16_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000047_1_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000047_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000047_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000047_3_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000047_9_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000047_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000047_9_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000047_3_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000047_9_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000047_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000047_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000047_22_1 & 1) != 0)
  {
    if ((sec_r000047_17_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000047_1_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000047_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000047_1_1 + 7) & 127;
  }
  if ((sec_r000047_22_2 & 1) != 0)
  {
    if ((sec_r000047_17_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000047_1_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000047_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000047_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000047_1_1 & 1) != 0)
  {
    if ((sec_r000047_0_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000047_12_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000047_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000047_12_1 + 7) & 127;
  }
  if ((sec_r000047_1_2 & 1) != 0)
  {
    if ((sec_r000047_0_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000047_12_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000047_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000047_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000047_5_1 & 1) != 0)
  {
    if ((sec_r000047_8_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000047_2_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000047_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000047_2_1 + 7) & 127;
  }
  if ((sec_r000047_5_2 & 1) != 0)
  {
    if ((sec_r000047_8_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000047_2_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000047_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000047_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000047_1_1 & 1) != 0)
  {
    if ((sec_r000047_10_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000047_21_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000047_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000047_21_1 + 7) & 127;
  }
  if ((sec_r000047_1_2 & 1) != 0)
  {
    if ((sec_r000047_10_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000047_21_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000047_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000047_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000047_19_1 & 1) != 0)
  {
    if ((sec_r000047_21_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000047_10_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000047_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000047_10_1 + 7) & 127;
  }
  if ((sec_r000047_19_2 & 1) != 0)
  {
    if ((sec_r000047_21_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000047_10_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000047_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000047_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000047_16_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000047_8_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000047_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000047_8_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000047_16_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000047_8_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000047_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000047_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000047_20_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000047_0_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000047_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000047_0_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000047_20_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000047_0_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000047_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000047_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000047_6_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000047_6_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000047_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000047_6_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000047_6_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000047_6_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000047_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000047_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000047_16_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000047_14_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000047_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000047_14_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000047_16_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000047_14_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000047_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000047_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000047_0_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000047_19_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000047_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000047_19_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000047_0_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000047_19_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000047_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000047_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000047_12_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000047_14_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000047_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000047_14_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000047_12_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000047_14_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000047_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000047_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000047_5_1 & 1) != 0)
  {
    if ((sec_r000047_8_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000047_8_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000047_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000047_8_1 + 7) & 127;
  }
  if ((sec_r000047_5_2 & 1) != 0)
  {
    if ((sec_r000047_8_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000047_8_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000047_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000047_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000047_12_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000047_5_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000047_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000047_5_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000047_12_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000047_5_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000047_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000047_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000047_1_1 & 1) != 0)
  {
    if ((sec_r000047_4_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000047_15_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000047_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000047_15_1 + 7) & 127;
  }
  if ((sec_r000047_1_2 & 1) != 0)
  {
    if ((sec_r000047_4_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000047_15_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000047_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000047_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000047_9_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000047_14_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000047_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000047_14_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000047_9_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000047_14_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000047_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000047_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000047_18_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000047_7_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000047_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000047_7_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000047_18_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000047_7_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000047_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000047_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000047_12_1 & 1) != 0)
  {
    if ((sec_r000047_16_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000047_3_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000047_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000047_3_1 + 7) & 127;
  }
  if ((sec_r000047_12_2 & 1) != 0)
  {
    if ((sec_r000047_16_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000047_3_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000047_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000047_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000047_22_1 & 1) != 0)
  {
    if ((sec_r000047_10_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000047_16_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000047_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000047_16_1 + 7) & 127;
  }
  if ((sec_r000047_22_2 & 1) != 0)
  {
    if ((sec_r000047_10_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000047_16_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000047_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000047_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000047_5_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000047_3_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000047_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000047_3_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000047_5_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000047_3_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000047_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000047_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000047_3_1 & 1) != 0)
  {
    if ((sec_r000047_10_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000047_1_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000047_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000047_1_1 + 7) & 127;
  }
  if ((sec_r000047_3_2 & 1) != 0)
  {
    if ((sec_r000047_10_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000047_1_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000047_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000047_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000047_20_1 & 1) != 0)
  {
    if ((sec_r000047_7_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000047_18_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000047_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000047_18_1 + 7) & 127;
  }
  if ((sec_r000047_20_2 & 1) != 0)
  {
    if ((sec_r000047_7_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000047_18_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000047_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000047_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000047_21_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000047_10_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000047_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000047_10_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000047_21_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000047_10_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000047_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000047_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000047_4_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000047_11_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000047_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000047_11_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000047_4_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000047_11_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000047_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000047_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000047_1_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000047_1_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000047_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000047_1_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000047_1_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000047_1_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000047_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000047_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000047_19_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000047_4_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000047_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000047_4_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000047_19_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000047_4_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000047_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000047_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000047_2_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000047_3_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000047_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000047_3_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000047_2_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000047_3_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000047_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000047_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000047_11_1 & 1) != 0)
  {
    if ((sec_r000047_0_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000047_0_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000047_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000047_0_1 + 7) & 127;
  }
  if ((sec_r000047_11_2 & 1) != 0)
  {
    if ((sec_r000047_0_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000047_0_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000047_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000047_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000047_11_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000047_13_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000047_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000047_13_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000047_11_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000047_13_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000047_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000047_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000047_7_1 & 1) != 0)
  {
    if ((sec_r000047_4_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000047_10_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000047_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000047_10_1 + 7) & 127;
  }
  if ((sec_r000047_7_2 & 1) != 0)
  {
    if ((sec_r000047_4_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000047_10_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000047_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000047_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000047_1_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000047_0_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000047_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000047_0_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000047_1_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000047_0_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000047_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000047_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000047_1_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000047_2_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000047_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000047_2_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000047_1_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000047_2_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000047_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000047_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000047_13_1 != sec_r000047_13_2);
  __CPROVER_assume(pub_r000047_13_1 == pub_r000047_13_2);
  __CPROVER_assume(sec_r000047_9_1 != sec_r000047_9_2);
  __CPROVER_assume(pub_r000047_0_1 == pub_r000047_0_2);
  __CPROVER_assume(pub_r000047_9_1 == pub_r000047_9_2);
  __CPROVER_assume(sec_r000047_7_1 != sec_r000047_7_2);
  __CPROVER_assume(pub_r000047_18_1 == pub_r000047_18_2);
  __CPROVER_assume(pub_r000047_1_1 == pub_r000047_1_2);
  __CPROVER_assume(sec_r000047_10_1 != sec_r000047_10_2);
  __CPROVER_assume(sec_r000047_21_1 != sec_r000047_21_2);
  __CPROVER_assume(sec_r000047_4_1 != sec_r000047_4_2);
  __CPROVER_assume(sec_r000047_15_1 != sec_r000047_15_2);
  __CPROVER_assume(pub_r000047_20_1 == pub_r000047_20_2);
  __CPROVER_assume(sec_r000047_17_1 != sec_r000047_17_2);
  __CPROVER_assume(pub_r000047_5_1 == pub_r000047_5_2);
  __CPROVER_assume(sec_r000047_20_1 != sec_r000047_20_2);
  __CPROVER_assume(pub_r000047_11_1 == pub_r000047_11_2);
  __CPROVER_assume(pub_r000047_21_1 == pub_r000047_21_2);
  __CPROVER_assume(sec_r000047_11_1 != sec_r000047_11_2);
  __CPROVER_assume(sec_r000047_12_1 != sec_r000047_12_2);
  __CPROVER_assume(sec_r000047_22_1 != sec_r000047_22_2);
  __CPROVER_assume(pub_r000047_15_1 == pub_r000047_15_2);
  __CPROVER_assume(sec_r000047_14_1 != sec_r000047_14_2);
  __CPROVER_assume(pub_r000047_10_1 == pub_r000047_10_2);
  __CPROVER_assume(sec_r000047_3_1 != sec_r000047_3_2);
  __CPROVER_assume(sec_r000047_18_1 != sec_r000047_18_2);
  __CPROVER_assume(pub_r000047_3_1 == pub_r000047_3_2);
  __CPROVER_assume(pub_r000047_7_1 == pub_r000047_7_2);
  __CPROVER_assume(pub_r000047_8_1 == pub_r000047_8_2);
  __CPROVER_assume(pub_r000047_19_1 == pub_r000047_19_2);
  __CPROVER_assume(sec_r000047_19_1 != sec_r000047_19_2);
  __CPROVER_assume(pub_r000047_4_1 == pub_r000047_4_2);
  __CPROVER_assume(pub_r000047_6_1 == pub_r000047_6_2);
  __CPROVER_assume(sec_r000047_8_1 != sec_r000047_8_2);
  __CPROVER_assume(pub_r000047_12_1 == pub_r000047_12_2);
  __CPROVER_assume(sec_r000047_16_1 != sec_r000047_16_2);
  __CPROVER_assume(sec_r000047_1_1 != sec_r000047_1_2);
  __CPROVER_assume(sec_r000047_6_1 != sec_r000047_6_2);
  __CPROVER_assume(pub_r000047_16_1 == pub_r000047_16_2);
  __CPROVER_assume(sec_r000047_2_1 != sec_r000047_2_2);
  __CPROVER_assume(pub_r000047_17_1 == pub_r000047_17_2);
  __CPROVER_assume(sec_r000047_0_1 != sec_r000047_0_2);
  __CPROVER_assume(pub_r000047_2_1 == pub_r000047_2_2);
  __CPROVER_assume(pub_r000047_14_1 == pub_r000047_14_2);
  __CPROVER_assume(sec_r000047_5_1 != sec_r000047_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.state == st_var_2_2.state);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.reading == st_var_3_2.reading);
  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.threshold == st_var_3_2.threshold);
  assert(st_var_3_1.calib == st_var_3_2.calib);
  assert(st_var_3_1.gain == st_var_3_2.gain);
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
}


