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
struct AudioFrame_R001680_8013_0
{
  unsigned char gain;
  int channels;
  int rms;
  int peak;
  short envelope;
  short sample_rate;
  int buffer[3];
};
struct Vector3D_R001680_8013_1
{
  unsigned char coord_x;
  unsigned char norm_sq;
  unsigned char coord_y;
  short heading;
  unsigned char coord_z;
  int buffer[3];
};
struct EventLog_R001680_8013_2
{
  int seq;
  short severity;
  short timestamp;
  int code;
  int buffer[3];
};
struct StreamBuffer_R001680_8013_3
{
  int capacity;
  int state;
  int head;
  int buffer[3];
};
union TelemetryField_R001680_8013_0
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
void fn_R001680_8013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st_1 = {0};
  struct StreamBuffer_R001680_8013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_45_1 = local_arr_1[aux_1 % 3];
  int tally_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_45_2 * 2)) & 127;
  int margin_56_1 = 0;
  int margin_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_56_1 = ((margin_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_56_2 = ((margin_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_56_1) & 127;
    acc_2 = (acc_2 + margin_56_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_45_1 == tally_45_2);
  assert(margin_56_1 == margin_56_2);
}

int fn_R001680_8013_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_45 = local_arr[aux % 3];
  acc = (acc + (tally_45 * 2)) & 127;
  int margin_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_56 = ((margin_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_56) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001680_8013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st_1 = {0};
  struct EventLog_R001680_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int index_reg_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_22_1) & 63;
  aux_2 = (aux_2 + index_reg_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_59_1 = 0;
  int coefficient_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_59_1 = ((coefficient_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_59_2 = ((coefficient_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_59_1) & 127;
    acc_2 = (acc_2 + coefficient_59_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_22_1 == index_reg_22_2);
  assert(coefficient_59_1 == coefficient_59_2);
}

int fn_R001680_8013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int index_reg_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_22) & 63;
  acc ^= aux;
  int coefficient_59 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_59 = ((coefficient_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_59) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001680_8013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st_1 = {0};
  struct AudioFrame_R001680_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_59_1 = local_arr_1[aux_1 % 3];
  int parity_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_59_2 * 2)) & 127;
  int parity_47_1 = 0;
  int parity_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_47_1 = ((parity_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_47_2 = ((parity_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_47_1) & 127;
    acc_2 = (acc_2 + parity_47_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_59_1 == parity_59_2);
  assert(parity_47_1 == parity_47_2);
}

int fn_R001680_8013_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int parity_59 = local_arr[aux % 3];
  acc = (acc + (parity_59 * 2)) & 127;
  int parity_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_47 = ((parity_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_47) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001680_8013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001680_8013_1 st_1 = {0};
  struct Vector3D_R001680_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int stride_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_48_1) & 63;
  aux_2 = (aux_2 + stride_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_28_1 > 11)
  {
    acc_1 = ((acc_1 + (sample_28_1 * 2)) + 5) & 127;
    aux_1 ^= sample_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_28_2 > 11)
  {
    acc_2 = ((acc_2 + (sample_28_2 * 2)) + 5) & 127;
    aux_2 ^= sample_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_28_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_48_1 == stride_48_2);
  assert(sample_28_1 == sample_28_2);
}

int fn_R001680_8013_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001680_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int stride_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_48) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_28 > 11)
  {
    acc = ((acc + (sample_28 * 2)) + 5) & 127;
    aux ^= sample_28 & 15;
  }
  else
  {
    acc = ((acc - sample_28) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001680_8013_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st_1 = {0};
  struct EventLog_R001680_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_35_1 = local_arr_1[aux_1 % 3];
  int anchor_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_35_2 * 2)) & 127;
  int delta_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_55_1) & 63;
  aux_2 = (aux_2 + delta_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_35_1 == anchor_35_2);
  assert(delta_55_1 == delta_55_2);
}

int fn_R001680_8013_4(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int anchor_35 = local_arr[aux % 3];
  acc = (acc + (anchor_35 * 2)) & 127;
  int delta_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001680_8013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st_1 = {0};
  struct AudioFrame_R001680_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int scale_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_42_1 > 21)
  {
    acc_1 = ((acc_1 + (scale_42_1 * 2)) + 5) & 127;
    aux_1 ^= scale_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_42_2 > 21)
  {
    acc_2 = ((acc_2 + (scale_42_2 * 2)) + 5) & 127;
    aux_2 ^= scale_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_51_1 = 0;
  int coefficient_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_51_1 = ((coefficient_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_51_2 = ((coefficient_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_51_1) & 127;
    acc_2 = (acc_2 + coefficient_51_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_82_1 = local_arr_1[aux_1 % 3];
  int threshold_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_42_1 == scale_42_2);
  assert(coefficient_51_1 == coefficient_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_82_1 == threshold_82_2);
}

int fn_R001680_8013_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int scale_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_42 > 21)
  {
    acc = ((acc + (scale_42 * 2)) + 5) & 127;
    aux ^= scale_42 & 15;
  }
  else
  {
    acc = ((acc - scale_42) + 11) & 127;
    aux += 3;
  }
  int coefficient_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_51 = ((coefficient_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_51) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int threshold_82 = local_arr[aux % 3];
  acc = (acc + (threshold_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001680_8013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st_1 = {0};
  struct StreamBuffer_R001680_8013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int accumulator_93_1 = 0;
  int accumulator_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_93_1 = ((accumulator_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_93_2 = ((accumulator_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_93_1) & 127;
    acc_2 = (acc_2 + accumulator_93_2) & 127;
  }

  int weight_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_71_1 > 25)
  {
    acc_1 = ((acc_1 + (weight_71_1 * 2)) + 5) & 127;
    aux_1 ^= weight_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_71_2 > 25)
  {
    acc_2 = ((acc_2 + (weight_71_2 * 2)) + 5) & 127;
    aux_2 ^= weight_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_93_1 == accumulator_93_2);
  assert(weight_71_1 == weight_71_2);
}

int fn_R001680_8013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int accumulator_93 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_93 = ((accumulator_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_93) & 127;
  }

  int weight_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_71 > 25)
  {
    acc = ((acc + (weight_71 * 2)) + 5) & 127;
    aux ^= weight_71 & 15;
  }
  else
  {
    acc = ((acc - weight_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001680_8013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st_1 = {0};
  struct StreamBuffer_R001680_8013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int checksum_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_29_1) & 63;
  aux_2 = (aux_2 + checksum_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_56_1 = local_arr_1[aux_1 % 3];
  int tracker_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_56_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_41_1 = 0;
  int segment_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_41_1 = ((segment_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_41_2 = ((segment_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_41_1) & 127;
    acc_2 = (acc_2 + segment_41_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_29_1 == checksum_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_56_1 == tracker_56_2);
  assert(segment_41_1 == segment_41_2);
}

int fn_R001680_8013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int checksum_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_29) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_56 = local_arr[aux % 3];
  acc = (acc + (tracker_56 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_41 = ((segment_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_41) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001680_8013_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st_1 = {0};
  struct EventLog_R001680_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int cursor_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_28_1) & 63;
  aux_2 = (aux_2 + cursor_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_50_1 = local_arr_1[aux_1 % 3];
  int bound_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_50_2 * 2)) & 127;
  int delta_83_1 = 0;
  int delta_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_83_1 = ((delta_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_83_2 = ((delta_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_83_1) & 127;
    acc_2 = (acc_2 + delta_83_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_28_1 == cursor_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_50_1 == bound_50_2);
  assert(delta_83_1 == delta_83_2);
}

int fn_R001680_8013_8(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int cursor_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_28) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_50 = local_arr[aux % 3];
  acc = (acc + (bound_50 * 2)) & 127;
  int delta_83 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_83 = ((delta_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_83) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001680_8013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st_1 = {0};
  struct StreamBuffer_R001680_8013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int parity_61_1 = 0;
  int parity_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_61_1 = ((parity_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_61_2 = ((parity_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_61_1) & 127;
    acc_2 = (acc_2 + parity_61_2) & 127;
  }

  int anchor_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_81_1) & 63;
  aux_2 = (aux_2 + anchor_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_82_1)
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

  switch (damping_82_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_61_1 == parity_61_2);
  assert(anchor_81_1 == anchor_81_2);
  assert(damping_82_1 == damping_82_2);
}

int fn_R001680_8013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int parity_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_61 = ((parity_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_61) & 127;
  }

  int anchor_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_81) & 63;
  acc ^= aux;
  int damping_82 = (aux + st.buffer[1]) & 3;
  switch (damping_82)
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
  return (acc + aux) & 255;
}

void fn_R001680_8013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st_1 = {0};
  struct EventLog_R001680_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_69_1 = local_arr_1[aux_1 % 3];
  int tally_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_69_2 * 2)) & 127;
  int index_reg_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_73_1 > 15)
  {
    acc_1 = ((acc_1 + (index_reg_73_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_73_2 > 15)
  {
    acc_2 = ((acc_2 + (index_reg_73_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_94_1 = 0;
  int mask_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_94_1 = ((mask_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_94_2 = ((mask_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_94_1) & 127;
    acc_2 = (acc_2 + mask_94_2) & 127;
  }

  int tally_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_93_1)
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

  switch (tally_93_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_69_1 == tally_69_2);
  assert(index_reg_73_1 == index_reg_73_2);
  assert(mask_94_1 == mask_94_2);
  assert(tally_93_1 == tally_93_2);
}

int fn_R001680_8013_10(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int tally_69 = local_arr[aux % 3];
  acc = (acc + (tally_69 * 2)) & 127;
  int index_reg_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_73 > 15)
  {
    acc = ((acc + (index_reg_73 * 2)) + 5) & 127;
    aux ^= index_reg_73 & 15;
  }
  else
  {
    acc = ((acc - index_reg_73) + 11) & 127;
    aux += 3;
  }
  int mask_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_94 = ((mask_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_94) & 127;
  }

  int tally_93 = (aux + st.buffer[1]) & 3;
  switch (tally_93)
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

void fn_R001680_8013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st_1 = {0};
  struct AudioFrame_R001680_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_65_1) & 63;
  aux_2 = (aux_2 + cursor_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_91_1 > 14)
  {
    acc_1 = ((acc_1 + (phase_91_1 * 2)) + 5) & 127;
    aux_1 ^= phase_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_91_2 > 14)
  {
    acc_2 = ((acc_2 + (phase_91_2 * 2)) + 5) & 127;
    aux_2 ^= phase_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_26_1)
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

  switch (mask_26_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_65_1 == cursor_65_2);
  assert(phase_91_1 == phase_91_2);
  assert(mask_26_1 == mask_26_2);
}

int fn_R001680_8013_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_65) & 63;
  acc ^= aux;
  int phase_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_91 > 14)
  {
    acc = ((acc + (phase_91 * 2)) + 5) & 127;
    aux ^= phase_91 & 15;
  }
  else
  {
    acc = ((acc - phase_91) + 11) & 127;
    aux += 3;
  }
  int mask_26 = (aux + st.buffer[1]) & 3;
  switch (mask_26)
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

void fn_R001680_8013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001680_8013_1 st_1 = {0};
  struct Vector3D_R001680_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quotient_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_50_1 > 27)
  {
    acc_1 = ((acc_1 + (quotient_50_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_50_2 > 27)
  {
    acc_2 = ((acc_2 + (quotient_50_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_52_1)
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

  switch (margin_52_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_50_1 == quotient_50_2);
  assert(margin_52_1 == margin_52_2);
}

int fn_R001680_8013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001680_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quotient_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_50 > 27)
  {
    acc = ((acc + (quotient_50 * 2)) + 5) & 127;
    aux ^= quotient_50 & 15;
  }
  else
  {
    acc = ((acc - quotient_50) + 11) & 127;
    aux += 3;
  }
  int margin_52 = (aux + st.buffer[1]) & 3;
  switch (margin_52)
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

void fn_R001680_8013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st_1 = {0};
  struct AudioFrame_R001680_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_56_1 = local_arr_1[aux_1 % 3];
  int bound_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_56_2 * 2)) & 127;
  int factor_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_18_1) & 63;
  aux_2 = (aux_2 + factor_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_70_1 = 0;
  int accumulator_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_70_1 = ((accumulator_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_70_2 = ((accumulator_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_70_1) & 127;
    acc_2 = (acc_2 + accumulator_70_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_56_1 == bound_56_2);
  assert(factor_18_1 == factor_18_2);
  assert(accumulator_70_1 == accumulator_70_2);
}

int fn_R001680_8013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int bound_56 = local_arr[aux % 3];
  acc = (acc + (bound_56 * 2)) & 127;
  int factor_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_18) & 63;
  acc ^= aux;
  int accumulator_70 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_70 = ((accumulator_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_70) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001680_8013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001680_8013_1 st_1 = {0};
  struct Vector3D_R001680_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int margin_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_62_1 > 27)
  {
    acc_1 = ((acc_1 + (margin_62_1 * 2)) + 5) & 127;
    aux_1 ^= margin_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_62_2 > 27)
  {
    acc_2 = ((acc_2 + (margin_62_2 * 2)) + 5) & 127;
    aux_2 ^= margin_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_16_1) & 63;
  aux_2 = (aux_2 + phase_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_68_1 = local_arr_1[aux_1 % 3];
  int offset_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_62_1 == margin_62_2);
  assert(phase_16_1 == phase_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_68_1 == offset_68_2);
}

int fn_R001680_8013_14(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001680_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int margin_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_62 > 27)
  {
    acc = ((acc + (margin_62 * 2)) + 5) & 127;
    aux ^= margin_62 & 15;
  }
  else
  {
    acc = ((acc - margin_62) + 11) & 127;
    aux += 3;
  }
  int phase_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_16) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_68 = local_arr[aux % 3];
  acc = (acc + (offset_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001680_8013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st_1 = {0};
  struct AudioFrame_R001680_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_67_1 = local_arr_1[aux_1 % 3];
  int delta_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_67_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_44_1 = 0;
  int metric_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_44_1 = ((metric_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_44_2 = ((metric_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_44_1) & 127;
    acc_2 = (acc_2 + metric_44_2) & 127;
  }

  int coefficient_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_69_1 > 30)
  {
    acc_1 = ((acc_1 + (coefficient_69_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_69_2 > 30)
  {
    acc_2 = ((acc_2 + (coefficient_69_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_67_1 == delta_67_2);
  assert(metric_44_1 == metric_44_2);
  assert(coefficient_69_1 == coefficient_69_2);
}

int fn_R001680_8013_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int delta_67 = local_arr[aux % 3];
  acc = (acc + (delta_67 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_44 = ((metric_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_44) & 127;
  }

  int coefficient_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_69 > 30)
  {
    acc = ((acc + (coefficient_69 * 2)) + 5) & 127;
    aux ^= coefficient_69 & 15;
  }
  else
  {
    acc = ((acc - coefficient_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001680_8013_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st_1 = {0};
  struct StreamBuffer_R001680_8013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int factor_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_23_1)
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

  switch (factor_23_2)
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
  int parity_75_1 = local_arr_1[aux_1 % 3];
  int parity_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_75_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_23_1 == factor_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_75_1 == parity_75_2);
}

int fn_R001680_8013_16(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int factor_23 = (aux + st.buffer[1]) & 3;
  switch (factor_23)
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
  int parity_75 = local_arr[aux % 3];
  acc = (acc + (parity_75 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001680_8013_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st_1 = {0};
  struct EventLog_R001680_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_36_1 = local_arr_1[aux_1 % 3];
  int tally_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_36_2 * 2)) & 127;
  int bound_44_1 = 0;
  int bound_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_44_1 = ((bound_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_44_2 = ((bound_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_44_1) & 127;
    acc_2 = (acc_2 + bound_44_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_36_1 == tally_36_2);
  assert(bound_44_1 == bound_44_2);
}

int fn_R001680_8013_17(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int tally_36 = local_arr[aux % 3];
  acc = (acc + (tally_36 * 2)) & 127;
  int bound_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_44 = ((bound_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_44) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001680_8013_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st_1 = {0};
  struct EventLog_R001680_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int parity_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_78_1) & 63;
  aux_2 = (aux_2 + parity_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_57_1)
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

  switch (threshold_57_2)
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

  int offset_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_58_1 > 35)
  {
    acc_1 = ((acc_1 + (offset_58_1 * 2)) + 5) & 127;
    aux_1 ^= offset_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_58_2 > 35)
  {
    acc_2 = ((acc_2 + (offset_58_2 * 2)) + 5) & 127;
    aux_2 ^= offset_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_78_1 == parity_78_2);
  assert(threshold_57_1 == threshold_57_2);
  assert(offset_58_1 == offset_58_2);
}

int fn_R001680_8013_18(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int parity_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_78) & 63;
  acc ^= aux;
  int threshold_57 = (aux + st.buffer[1]) & 3;
  switch (threshold_57)
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

  int offset_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_58 > 35)
  {
    acc = ((acc + (offset_58 * 2)) + 5) & 127;
    aux ^= offset_58 & 15;
  }
  else
  {
    acc = ((acc - offset_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001680_8013_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001680_8013_1 st_1 = {0};
  struct Vector3D_R001680_8013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int sample_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_83_1 > 23)
  {
    acc_1 = ((acc_1 + (sample_83_1 * 2)) + 5) & 127;
    aux_1 ^= sample_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_83_2 > 23)
  {
    acc_2 = ((acc_2 + (sample_83_2 * 2)) + 5) & 127;
    aux_2 ^= sample_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_28_1 = 0;
  int margin_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_28_1 = ((margin_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_28_2 = ((margin_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_28_1) & 127;
    acc_2 = (acc_2 + margin_28_2) & 127;
  }

  int threshold_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_15_1) & 63;
  aux_2 = (aux_2 + threshold_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_83_1 == sample_83_2);
  assert(margin_28_1 == margin_28_2);
  assert(threshold_15_1 == threshold_15_2);
}

int fn_R001680_8013_19(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001680_8013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int sample_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_83 > 23)
  {
    acc = ((acc + (sample_83 * 2)) + 5) & 127;
    aux ^= sample_83 & 15;
  }
  else
  {
    acc = ((acc - sample_83) + 11) & 127;
    aux += 3;
  }
  int margin_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_28 = ((margin_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_28) & 127;
  }

  int threshold_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001680_8013_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st_1 = {0};
  struct EventLog_R001680_8013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int sample_87_1 = 0;
  int sample_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_87_1 = ((sample_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_87_2 = ((sample_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_87_1) & 127;
    acc_2 = (acc_2 + sample_87_2) & 127;
  }

  int stride_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_48_1) & 63;
  aux_2 = (aux_2 + stride_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_70_1 = local_arr_1[aux_1 % 3];
  int accumulator_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_70_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_87_1 == sample_87_2);
  assert(stride_48_1 == stride_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_70_1 == accumulator_70_2);
}

int fn_R001680_8013_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001680_8013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int sample_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_87 = ((sample_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_87) & 127;
  }

  int stride_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_70 = local_arr[aux % 3];
  acc = (acc + (accumulator_70 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001680_8013_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st_1 = {0};
  struct StreamBuffer_R001680_8013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_71_1)
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

  switch (bound_71_2)
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
  int bound_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_22_1 > 47)
  {
    acc_1 = ((acc_1 + (bound_22_1 * 2)) + 5) & 127;
    aux_1 ^= bound_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_22_2 > 47)
  {
    acc_2 = ((acc_2 + (bound_22_2 * 2)) + 5) & 127;
    aux_2 ^= bound_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_71_1 == bound_71_2);
  assert(bound_22_1 == bound_22_2);
}

int fn_R001680_8013_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001680_8013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_71 = (aux + st.buffer[1]) & 3;
  switch (bound_71)
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
  int bound_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_22 > 47)
  {
    acc = ((acc + (bound_22 * 2)) + 5) & 127;
    aux ^= bound_22 & 15;
  }
  else
  {
    acc = ((acc - bound_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001680_8013_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st_1 = {0};
  struct AudioFrame_R001680_8013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_25_1 = 0;
  int pivot_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_25_1 = ((pivot_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_25_2 = ((pivot_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_25_1) & 127;
    acc_2 = (acc_2 + pivot_25_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_39_1 > 41)
  {
    acc_1 = ((acc_1 + (residue_39_1 * 2)) + 5) & 127;
    aux_1 ^= residue_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_39_2 > 41)
  {
    acc_2 = ((acc_2 + (residue_39_2 * 2)) + 5) & 127;
    aux_2 ^= residue_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_25_1 == pivot_25_2);
  assert(residue_39_1 == residue_39_2);
}

int fn_R001680_8013_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001680_8013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_25 = ((pivot_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_25) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_39 > 41)
  {
    acc = ((acc + (residue_39 * 2)) + 5) & 127;
    aux ^= residue_39 & 15;
  }
  else
  {
    acc = ((acc - residue_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001680_0_1;
  int sec_r001680_0_2;
  int sec_r001680_1_1;
  int sec_r001680_1_2;
  int sec_r001680_2_1;
  int sec_r001680_2_2;
  int sec_r001680_3_1;
  int sec_r001680_3_2;
  int sec_r001680_4_1;
  int sec_r001680_4_2;
  int sec_r001680_5_1;
  int sec_r001680_5_2;
  int sec_r001680_6_1;
  int sec_r001680_6_2;
  int sec_r001680_7_1;
  int sec_r001680_7_2;
  int sec_r001680_8_1;
  int sec_r001680_8_2;
  int sec_r001680_9_1;
  int sec_r001680_9_2;
  int sec_r001680_10_1;
  int sec_r001680_10_2;
  int sec_r001680_11_1;
  int sec_r001680_11_2;
  int sec_r001680_12_1;
  int sec_r001680_12_2;
  int sec_r001680_13_1;
  int sec_r001680_13_2;
  int sec_r001680_14_1;
  int sec_r001680_14_2;
  int sec_r001680_15_1;
  int sec_r001680_15_2;
  int sec_r001680_16_1;
  int sec_r001680_16_2;
  int sec_r001680_17_1;
  int sec_r001680_17_2;
  int sec_r001680_18_1;
  int sec_r001680_18_2;
  int sec_r001680_19_1;
  int sec_r001680_19_2;
  int sec_r001680_20_1;
  int sec_r001680_20_2;
  int sec_r001680_21_1;
  int sec_r001680_21_2;
  int sec_r001680_22_1;
  int sec_r001680_22_2;
  int sec_r001680_23_1;
  int sec_r001680_23_2;
  int pub_r001680_0_1;
  int pub_r001680_0_2;
  int pub_r001680_1_1;
  int pub_r001680_1_2;
  int pub_r001680_2_1;
  int pub_r001680_2_2;
  int pub_r001680_3_1;
  int pub_r001680_3_2;
  int pub_r001680_4_1;
  int pub_r001680_4_2;
  int pub_r001680_5_1;
  int pub_r001680_5_2;
  int pub_r001680_6_1;
  int pub_r001680_6_2;
  int pub_r001680_7_1;
  int pub_r001680_7_2;
  int pub_r001680_8_1;
  int pub_r001680_8_2;
  int pub_r001680_9_1;
  int pub_r001680_9_2;
  int pub_r001680_10_1;
  int pub_r001680_10_2;
  int pub_r001680_11_1;
  int pub_r001680_11_2;
  int pub_r001680_12_1;
  int pub_r001680_12_2;
  int pub_r001680_13_1;
  int pub_r001680_13_2;
  int pub_r001680_14_1;
  int pub_r001680_14_2;
  int pub_r001680_15_1;
  int pub_r001680_15_2;
  int pub_r001680_16_1;
  int pub_r001680_16_2;
  int pub_r001680_17_1;
  int pub_r001680_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001680_0_1 >= (-100)) && (pub_r001680_0_1 <= 100));
  __CPROVER_assume((pub_r001680_0_2 >= (-100)) && (pub_r001680_0_2 <= 100));
  __CPROVER_assume((pub_r001680_1_1 >= (-100)) && (pub_r001680_1_1 <= 100));
  __CPROVER_assume((pub_r001680_1_2 >= (-100)) && (pub_r001680_1_2 <= 100));
  __CPROVER_assume((pub_r001680_2_1 >= (-100)) && (pub_r001680_2_1 <= 100));
  __CPROVER_assume((pub_r001680_2_2 >= (-100)) && (pub_r001680_2_2 <= 100));
  __CPROVER_assume((pub_r001680_3_1 >= (-100)) && (pub_r001680_3_1 <= 100));
  __CPROVER_assume((pub_r001680_3_2 >= (-100)) && (pub_r001680_3_2 <= 100));
  __CPROVER_assume((pub_r001680_4_1 >= (-100)) && (pub_r001680_4_1 <= 100));
  __CPROVER_assume((pub_r001680_4_2 >= (-100)) && (pub_r001680_4_2 <= 100));
  __CPROVER_assume((pub_r001680_5_1 >= (-100)) && (pub_r001680_5_1 <= 100));
  __CPROVER_assume((pub_r001680_5_2 >= (-100)) && (pub_r001680_5_2 <= 100));
  __CPROVER_assume((pub_r001680_6_1 >= (-100)) && (pub_r001680_6_1 <= 100));
  __CPROVER_assume((pub_r001680_6_2 >= (-100)) && (pub_r001680_6_2 <= 100));
  __CPROVER_assume((pub_r001680_7_1 >= (-100)) && (pub_r001680_7_1 <= 100));
  __CPROVER_assume((pub_r001680_7_2 >= (-100)) && (pub_r001680_7_2 <= 100));
  __CPROVER_assume((pub_r001680_8_1 >= (-100)) && (pub_r001680_8_1 <= 100));
  __CPROVER_assume((pub_r001680_8_2 >= (-100)) && (pub_r001680_8_2 <= 100));
  __CPROVER_assume((pub_r001680_9_1 >= (-100)) && (pub_r001680_9_1 <= 100));
  __CPROVER_assume((pub_r001680_9_2 >= (-100)) && (pub_r001680_9_2 <= 100));
  __CPROVER_assume((pub_r001680_10_1 >= (-100)) && (pub_r001680_10_1 <= 100));
  __CPROVER_assume((pub_r001680_10_2 >= (-100)) && (pub_r001680_10_2 <= 100));
  __CPROVER_assume((pub_r001680_11_1 >= (-100)) && (pub_r001680_11_1 <= 100));
  __CPROVER_assume((pub_r001680_11_2 >= (-100)) && (pub_r001680_11_2 <= 100));
  __CPROVER_assume((pub_r001680_12_1 >= (-100)) && (pub_r001680_12_1 <= 100));
  __CPROVER_assume((pub_r001680_12_2 >= (-100)) && (pub_r001680_12_2 <= 100));
  __CPROVER_assume((pub_r001680_13_1 >= (-100)) && (pub_r001680_13_1 <= 100));
  __CPROVER_assume((pub_r001680_13_2 >= (-100)) && (pub_r001680_13_2 <= 100));
  __CPROVER_assume((pub_r001680_14_1 >= (-100)) && (pub_r001680_14_1 <= 100));
  __CPROVER_assume((pub_r001680_14_2 >= (-100)) && (pub_r001680_14_2 <= 100));
  __CPROVER_assume((pub_r001680_15_1 >= (-100)) && (pub_r001680_15_1 <= 100));
  __CPROVER_assume((pub_r001680_15_2 >= (-100)) && (pub_r001680_15_2 <= 100));
  __CPROVER_assume((pub_r001680_16_1 >= (-100)) && (pub_r001680_16_1 <= 100));
  __CPROVER_assume((pub_r001680_16_2 >= (-100)) && (pub_r001680_16_2 <= 100));
  __CPROVER_assume((pub_r001680_17_1 >= (-100)) && (pub_r001680_17_1 <= 100));
  __CPROVER_assume((pub_r001680_17_2 >= (-100)) && (pub_r001680_17_2 <= 100));
  __CPROVER_assume((sec_r001680_0_1 >= 0) && (sec_r001680_0_1 <= 255));
  __CPROVER_assume((sec_r001680_0_2 >= 0) && (sec_r001680_0_2 <= 255));
  __CPROVER_assume((sec_r001680_1_1 >= 0) && (sec_r001680_1_1 <= 255));
  __CPROVER_assume((sec_r001680_1_2 >= 0) && (sec_r001680_1_2 <= 255));
  __CPROVER_assume((sec_r001680_2_1 >= 0) && (sec_r001680_2_1 <= 255));
  __CPROVER_assume((sec_r001680_2_2 >= 0) && (sec_r001680_2_2 <= 255));
  __CPROVER_assume((sec_r001680_3_1 >= 0) && (sec_r001680_3_1 <= 255));
  __CPROVER_assume((sec_r001680_3_2 >= 0) && (sec_r001680_3_2 <= 255));
  __CPROVER_assume((sec_r001680_4_1 >= 0) && (sec_r001680_4_1 <= 255));
  __CPROVER_assume((sec_r001680_4_2 >= 0) && (sec_r001680_4_2 <= 255));
  __CPROVER_assume((sec_r001680_5_1 >= 0) && (sec_r001680_5_1 <= 255));
  __CPROVER_assume((sec_r001680_5_2 >= 0) && (sec_r001680_5_2 <= 255));
  __CPROVER_assume((sec_r001680_6_1 >= 0) && (sec_r001680_6_1 <= 255));
  __CPROVER_assume((sec_r001680_6_2 >= 0) && (sec_r001680_6_2 <= 255));
  __CPROVER_assume((sec_r001680_7_1 >= 0) && (sec_r001680_7_1 <= 255));
  __CPROVER_assume((sec_r001680_7_2 >= 0) && (sec_r001680_7_2 <= 255));
  __CPROVER_assume((sec_r001680_8_1 >= 0) && (sec_r001680_8_1 <= 255));
  __CPROVER_assume((sec_r001680_8_2 >= 0) && (sec_r001680_8_2 <= 255));
  __CPROVER_assume((sec_r001680_9_1 >= 0) && (sec_r001680_9_1 <= 255));
  __CPROVER_assume((sec_r001680_9_2 >= 0) && (sec_r001680_9_2 <= 255));
  __CPROVER_assume((sec_r001680_10_1 >= 0) && (sec_r001680_10_1 <= 255));
  __CPROVER_assume((sec_r001680_10_2 >= 0) && (sec_r001680_10_2 <= 255));
  __CPROVER_assume((sec_r001680_11_1 >= 0) && (sec_r001680_11_1 <= 255));
  __CPROVER_assume((sec_r001680_11_2 >= 0) && (sec_r001680_11_2 <= 255));
  __CPROVER_assume((sec_r001680_12_1 >= 0) && (sec_r001680_12_1 <= 255));
  __CPROVER_assume((sec_r001680_12_2 >= 0) && (sec_r001680_12_2 <= 255));
  __CPROVER_assume((sec_r001680_13_1 >= 0) && (sec_r001680_13_1 <= 255));
  __CPROVER_assume((sec_r001680_13_2 >= 0) && (sec_r001680_13_2 <= 255));
  __CPROVER_assume((sec_r001680_14_1 >= 0) && (sec_r001680_14_1 <= 255));
  __CPROVER_assume((sec_r001680_14_2 >= 0) && (sec_r001680_14_2 <= 255));
  __CPROVER_assume((sec_r001680_15_1 >= 0) && (sec_r001680_15_1 <= 255));
  __CPROVER_assume((sec_r001680_15_2 >= 0) && (sec_r001680_15_2 <= 255));
  __CPROVER_assume((sec_r001680_16_1 >= 0) && (sec_r001680_16_1 <= 255));
  __CPROVER_assume((sec_r001680_16_2 >= 0) && (sec_r001680_16_2 <= 255));
  __CPROVER_assume((sec_r001680_17_1 >= 0) && (sec_r001680_17_1 <= 255));
  __CPROVER_assume((sec_r001680_17_2 >= 0) && (sec_r001680_17_2 <= 255));
  __CPROVER_assume((sec_r001680_18_1 >= 0) && (sec_r001680_18_1 <= 255));
  __CPROVER_assume((sec_r001680_18_2 >= 0) && (sec_r001680_18_2 <= 255));
  __CPROVER_assume((sec_r001680_19_1 >= 0) && (sec_r001680_19_1 <= 255));
  __CPROVER_assume((sec_r001680_19_2 >= 0) && (sec_r001680_19_2 <= 255));
  __CPROVER_assume((sec_r001680_20_1 >= 0) && (sec_r001680_20_1 <= 255));
  __CPROVER_assume((sec_r001680_20_2 >= 0) && (sec_r001680_20_2 <= 255));
  __CPROVER_assume((sec_r001680_21_1 >= 0) && (sec_r001680_21_1 <= 255));
  __CPROVER_assume((sec_r001680_21_2 >= 0) && (sec_r001680_21_2 <= 255));
  __CPROVER_assume((sec_r001680_22_1 >= 0) && (sec_r001680_22_1 <= 255));
  __CPROVER_assume((sec_r001680_22_2 >= 0) && (sec_r001680_22_2 <= 255));
  __CPROVER_assume((sec_r001680_23_1 >= 0) && (sec_r001680_23_1 <= 255));
  __CPROVER_assume((sec_r001680_23_2 >= 0) && (sec_r001680_23_2 <= 255));
  struct AudioFrame_R001680_8013_0 st_var_0_1 = {0};
  struct AudioFrame_R001680_8013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001680_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001680_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001680_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001680_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001680_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001680_0_2 + 7) & 15;
  struct Vector3D_R001680_8013_1 st_var_1_1 = {0};
  struct Vector3D_R001680_8013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001680_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001680_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001680_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001680_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001680_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001680_0_2 + 9) & 15;
  struct EventLog_R001680_8013_2 st_var_2_1 = {0};
  struct EventLog_R001680_8013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001680_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001680_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001680_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001680_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001680_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001680_0_2 + 11) & 15;
  struct StreamBuffer_R001680_8013_3 st_var_3_1 = {0};
  struct StreamBuffer_R001680_8013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001680_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001680_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001680_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001680_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001680_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001680_0_2 + 13) & 15;
  union TelemetryField_R001680_8013_0 u_var_1;
  union TelemetryField_R001680_8013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001680_8013_0(sec_r001680_0_1, pub_r001680_1_1, pub_r001680_2_1, pub_r001680_3_1, pub_r001680_4_1);
  int helper_flow_0_2 = fn_R001680_8013_0(sec_r001680_0_2, pub_r001680_1_2, pub_r001680_2_2, pub_r001680_3_2, pub_r001680_4_2);
  fn_R001680_8013_0_2(sec_r001680_0_1, pub_r001680_1_1, pub_r001680_2_1, pub_r001680_3_1, pub_r001680_4_1, sec_r001680_0_2, pub_r001680_1_2, pub_r001680_2_2, pub_r001680_3_2, pub_r001680_4_2);
  int helper_flow_1_1 = fn_R001680_8013_1(sec_r001680_1_1, sec_r001680_2_1, pub_r001680_3_1);
  int helper_flow_1_2 = fn_R001680_8013_1(sec_r001680_1_2, sec_r001680_2_2, pub_r001680_3_2);
  fn_R001680_8013_1_2(sec_r001680_1_1, sec_r001680_2_1, pub_r001680_3_1, sec_r001680_1_2, sec_r001680_2_2, pub_r001680_3_2);
  int helper_flow_2_1 = fn_R001680_8013_2(sec_r001680_2_1, sec_r001680_3_1, pub_r001680_4_1, pub_r001680_5_1, pub_r001680_6_1);
  int helper_flow_2_2 = fn_R001680_8013_2(sec_r001680_2_2, sec_r001680_3_2, pub_r001680_4_2, pub_r001680_5_2, pub_r001680_6_2);
  fn_R001680_8013_2_2(sec_r001680_2_1, sec_r001680_3_1, pub_r001680_4_1, pub_r001680_5_1, pub_r001680_6_1, sec_r001680_2_2, sec_r001680_3_2, pub_r001680_4_2, pub_r001680_5_2, pub_r001680_6_2);
  int helper_flow_3_1 = fn_R001680_8013_3(sec_r001680_3_1, pub_r001680_4_1, pub_r001680_5_1, pub_r001680_6_1);
  int helper_flow_3_2 = fn_R001680_8013_3(sec_r001680_3_2, pub_r001680_4_2, pub_r001680_5_2, pub_r001680_6_2);
  fn_R001680_8013_3_2(sec_r001680_3_1, pub_r001680_4_1, pub_r001680_5_1, pub_r001680_6_1, sec_r001680_3_2, pub_r001680_4_2, pub_r001680_5_2, pub_r001680_6_2);
  int helper_flow_4_1 = fn_R001680_8013_4(sec_r001680_4_1, pub_r001680_5_1);
  int helper_flow_4_2 = fn_R001680_8013_4(sec_r001680_4_2, pub_r001680_5_2);
  fn_R001680_8013_4_2(sec_r001680_4_1, pub_r001680_5_1, sec_r001680_4_2, pub_r001680_5_2);
  int helper_flow_5_1 = fn_R001680_8013_5(sec_r001680_5_1, pub_r001680_6_1, pub_r001680_7_1, pub_r001680_8_1, pub_r001680_9_1);
  int helper_flow_5_2 = fn_R001680_8013_5(sec_r001680_5_2, pub_r001680_6_2, pub_r001680_7_2, pub_r001680_8_2, pub_r001680_9_2);
  fn_R001680_8013_5_2(sec_r001680_5_1, pub_r001680_6_1, pub_r001680_7_1, pub_r001680_8_1, pub_r001680_9_1, sec_r001680_5_2, pub_r001680_6_2, pub_r001680_7_2, pub_r001680_8_2, pub_r001680_9_2);
  int helper_flow_6_1 = fn_R001680_8013_6(sec_r001680_6_1, pub_r001680_7_1, pub_r001680_8_1);
  int helper_flow_6_2 = fn_R001680_8013_6(sec_r001680_6_2, pub_r001680_7_2, pub_r001680_8_2);
  fn_R001680_8013_6_2(sec_r001680_6_1, pub_r001680_7_1, pub_r001680_8_1, sec_r001680_6_2, pub_r001680_7_2, pub_r001680_8_2);
  int helper_flow_7_1 = fn_R001680_8013_7(sec_r001680_7_1, sec_r001680_8_1, pub_r001680_9_1, pub_r001680_10_1, pub_r001680_11_1);
  int helper_flow_7_2 = fn_R001680_8013_7(sec_r001680_7_2, sec_r001680_8_2, pub_r001680_9_2, pub_r001680_10_2, pub_r001680_11_2);
  fn_R001680_8013_7_2(sec_r001680_7_1, sec_r001680_8_1, pub_r001680_9_1, pub_r001680_10_1, pub_r001680_11_1, sec_r001680_7_2, sec_r001680_8_2, pub_r001680_9_2, pub_r001680_10_2, pub_r001680_11_2);
  int helper_flow_8_1 = fn_R001680_8013_8(sec_r001680_8_1, sec_r001680_9_1, pub_r001680_10_1);
  int helper_flow_8_2 = fn_R001680_8013_8(sec_r001680_8_2, sec_r001680_9_2, pub_r001680_10_2);
  fn_R001680_8013_8_2(sec_r001680_8_1, sec_r001680_9_1, pub_r001680_10_1, sec_r001680_8_2, sec_r001680_9_2, pub_r001680_10_2);
  int helper_flow_9_1 = fn_R001680_8013_9(sec_r001680_9_1, sec_r001680_10_1, pub_r001680_11_1);
  int helper_flow_9_2 = fn_R001680_8013_9(sec_r001680_9_2, sec_r001680_10_2, pub_r001680_11_2);
  fn_R001680_8013_9_2(sec_r001680_9_1, sec_r001680_10_1, pub_r001680_11_1, sec_r001680_9_2, sec_r001680_10_2, pub_r001680_11_2);
  int helper_flow_10_1 = fn_R001680_8013_10(sec_r001680_10_1, sec_r001680_11_1);
  int helper_flow_10_2 = fn_R001680_8013_10(sec_r001680_10_2, sec_r001680_11_2);
  fn_R001680_8013_10_2(sec_r001680_10_1, sec_r001680_11_1, sec_r001680_10_2, sec_r001680_11_2);
  int stage_v_0_1 = ((pub_r001680_16_1 * 2) + 7) & 63;
  int stage_v_0_2 = ((pub_r001680_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001680_6_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_1_2 = (((sec_r001680_6_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_1_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((sec_r001680_4_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_2_2 = (((sec_r001680_4_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_2_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((pub_r001680_2_1 * 2) + 44) & 63;
  int stage_v_3_2 = ((pub_r001680_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001680_16_1 * 2) + 31) & 63;
  int stage_v_4_2 = ((pub_r001680_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001680_14_1 * 2) + 12) & 63;
  int stage_v_5_2 = ((pub_r001680_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001680_13_1) & 127;
  int stage_v_6_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001680_13_2) & 127;
  if (stage_v_6_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((sec_r001680_5_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_7_2 = (((sec_r001680_5_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_7_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001680_16_1) & 127;
  int stage_v_8_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001680_16_2) & 127;
  if (stage_v_8_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001680_7_1) & 127;
  int stage_v_9_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001680_7_2) & 127;
  if (stage_v_9_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((sec_r001680_16_1 ^ 0x2A) * 2) + pub_r001680_0_1) & 127;
  int stage_v_10_2 = (((sec_r001680_16_2 ^ 0x2A) * 2) + pub_r001680_0_2) & 127;
  if (stage_v_10_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001680_10_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_11_2 = (((sec_r001680_10_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_11_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001680_2_1) & 127;
  int stage_v_12_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001680_2_2) & 127;
  if (stage_v_12_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((sec_r001680_20_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_13_2 = (((sec_r001680_20_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_13_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((sec_r001680_22_1 ^ 0x2A) * 2) + pub_r001680_16_1) & 127;
  int stage_v_14_2 = (((sec_r001680_22_2 ^ 0x2A) * 2) + pub_r001680_16_2) & 127;
  if (stage_v_14_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001680_17_1) & 127;
  int stage_v_15_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001680_17_2) & 127;
  if (stage_v_15_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_16_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_16_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001680_0_1 ^ 0x2A) * 2) + pub_r001680_0_1) & 127;
  int stage_v_17_2 = (((sec_r001680_0_2 ^ 0x2A) * 2) + pub_r001680_0_2) & 127;
  if (stage_v_17_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((pub_r001680_12_1 * 2) + 45) & 63;
  int stage_v_18_2 = ((pub_r001680_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001680_17_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_19_2 = (((sec_r001680_17_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_19_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((sec_r001680_18_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_20_2 = (((sec_r001680_18_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_20_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((pub_r001680_0_1 * 2) + 30) & 63;
  int stage_v_21_2 = ((pub_r001680_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001680_15_1) & 127;
  int stage_v_22_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001680_15_2) & 127;
  if (stage_v_22_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((sec_r001680_16_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_23_2 = (((sec_r001680_16_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_23_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_24_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_24_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((sec_r001680_13_1 ^ 0x2A) * 2) + pub_r001680_2_1) & 127;
  int stage_v_25_2 = (((sec_r001680_13_2 ^ 0x2A) * 2) + pub_r001680_2_2) & 127;
  if (stage_v_25_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_26_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_26_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_27_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_27_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((pub_r001680_2_1 * 2) + 13) & 63;
  int stage_v_28_2 = ((pub_r001680_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_29_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_29_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001680_17_1) & 127;
  int stage_v_30_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001680_17_2) & 127;
  if (stage_v_30_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((sec_r001680_16_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_31_2 = (((sec_r001680_16_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_31_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((sec_r001680_14_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_32_2 = (((sec_r001680_14_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_32_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_33_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_33_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001680_2_1) & 127;
  int stage_v_34_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001680_2_2) & 127;
  if (stage_v_34_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001680_11_1) & 127;
  int stage_v_35_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001680_11_2) & 127;
  if (stage_v_35_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001680_8_1) & 127;
  int stage_v_36_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001680_8_2) & 127;
  if (stage_v_36_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001680_8_1) & 127;
  int stage_v_37_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001680_8_2) & 127;
  if (stage_v_37_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_38_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_38_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_39_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_39_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((pub_r001680_11_1 * 2) + 14) & 63;
  int stage_v_40_2 = ((pub_r001680_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_41_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_41_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_42_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_42_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((pub_r001680_15_1 * 2) + 43) & 63;
  int stage_v_43_2 = ((pub_r001680_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_44_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_44_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_45_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_45_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((pub_r001680_0_1 * 2) + 40) & 63;
  int stage_v_46_2 = ((pub_r001680_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_47_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_47_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((sec_r001680_20_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_48_2 = (((sec_r001680_20_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_48_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((sec_r001680_11_1 ^ 0x2A) * 2) + pub_r001680_11_1) & 127;
  int stage_v_49_2 = (((sec_r001680_11_2 ^ 0x2A) * 2) + pub_r001680_11_2) & 127;
  if (stage_v_49_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_50_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_50_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001680_11_1) & 127;
  int stage_v_51_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001680_11_2) & 127;
  if (stage_v_51_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_52_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_52_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_53_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_53_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((pub_r001680_3_1 * 2) + 14) & 63;
  int stage_v_54_2 = ((pub_r001680_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001680_7_1) & 127;
  int stage_v_55_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001680_7_2) & 127;
  if (stage_v_55_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((sec_r001680_4_1 ^ 0x2A) * 2) + pub_r001680_7_1) & 127;
  int stage_v_56_2 = (((sec_r001680_4_2 ^ 0x2A) * 2) + pub_r001680_7_2) & 127;
  if (stage_v_56_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001680_0_1) & 127;
  int stage_v_57_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001680_0_2) & 127;
  if (stage_v_57_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((sec_r001680_12_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_58_2 = (((sec_r001680_12_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_58_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((pub_r001680_10_1 * 2) + 40) & 63;
  int stage_v_59_2 = ((pub_r001680_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001680_4_1) & 127;
  int stage_v_60_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001680_4_2) & 127;
  if (stage_v_60_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_61_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_61_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_62_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_62_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_63_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_63_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((pub_r001680_4_1 * 2) + 21) & 63;
  int stage_v_64_2 = ((pub_r001680_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001680_15_1) & 127;
  int stage_v_65_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001680_15_2) & 127;
  if (stage_v_65_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_66_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_66_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((sec_r001680_14_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_67_2 = (((sec_r001680_14_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_67_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001680_0_1) & 127;
  int stage_v_68_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001680_0_2) & 127;
  if (stage_v_68_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((pub_r001680_16_1 * 2) + 19) & 63;
  int stage_v_69_2 = ((pub_r001680_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((sec_r001680_5_1 ^ 0x2A) * 2) + pub_r001680_11_1) & 127;
  int stage_v_70_2 = (((sec_r001680_5_2 ^ 0x2A) * 2) + pub_r001680_11_2) & 127;
  if (stage_v_70_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_71_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_71_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_72_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_72_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_73_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_73_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_74_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_74_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((sec_r001680_6_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_75_2 = (((sec_r001680_6_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_75_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001680_13_1) & 127;
  int stage_v_76_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001680_13_2) & 127;
  if (stage_v_76_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_77_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_77_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((pub_r001680_1_1 * 2) + 42) & 63;
  int stage_v_78_2 = ((pub_r001680_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((sec_r001680_2_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_79_2 = (((sec_r001680_2_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_79_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001680_16_1) & 127;
  int stage_v_80_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001680_16_2) & 127;
  if (stage_v_80_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001680_4_1) & 127;
  int stage_v_81_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001680_4_2) & 127;
  if (stage_v_81_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((sec_r001680_3_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_82_2 = (((sec_r001680_3_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_82_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001680_17_1) & 127;
  int stage_v_83_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001680_17_2) & 127;
  if (stage_v_83_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_84_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_84_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001680_11_1) & 127;
  int stage_v_85_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001680_11_2) & 127;
  if (stage_v_85_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((sec_r001680_6_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_86_2 = (((sec_r001680_6_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_86_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_87_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_87_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((pub_r001680_7_1 * 2) + 41) & 63;
  int stage_v_88_2 = ((pub_r001680_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_89_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_89_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_90_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_90_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_91_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_91_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_92_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_92_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_93_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_93_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((sec_r001680_16_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_94_2 = (((sec_r001680_16_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_94_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_95_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_95_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001680_16_1) & 127;
  int stage_v_96_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001680_16_2) & 127;
  if (stage_v_96_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001680_8_1) & 127;
  int stage_v_97_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001680_8_2) & 127;
  if (stage_v_97_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001680_7_1) & 127;
  int stage_v_98_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001680_7_2) & 127;
  if (stage_v_98_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001680_8_1) & 127;
  int stage_v_99_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001680_8_2) & 127;
  if (stage_v_99_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((sec_r001680_8_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_100_2 = (((sec_r001680_8_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_100_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((pub_r001680_3_1 * 2) + 28) & 63;
  int stage_v_101_2 = ((pub_r001680_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_102_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_102_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((sec_r001680_14_1 ^ 0x2A) * 2) + pub_r001680_4_1) & 127;
  int stage_v_103_2 = (((sec_r001680_14_2 ^ 0x2A) * 2) + pub_r001680_4_2) & 127;
  if (stage_v_103_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_104_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_104_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001680_15_1) & 127;
  int stage_v_105_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001680_15_2) & 127;
  if (stage_v_105_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001680_0_1) & 127;
  int stage_v_106_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001680_0_2) & 127;
  if (stage_v_106_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((sec_r001680_23_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_107_2 = (((sec_r001680_23_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_107_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001680_13_1) & 127;
  int stage_v_108_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001680_13_2) & 127;
  if (stage_v_108_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_109_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_109_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_110_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_110_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((pub_r001680_5_1 * 2) + 10) & 63;
  int stage_v_111_2 = ((pub_r001680_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001680_11_1) & 127;
  int stage_v_112_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001680_11_2) & 127;
  if (stage_v_112_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((sec_r001680_1_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_113_2 = (((sec_r001680_1_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_113_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((sec_r001680_13_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_114_2 = (((sec_r001680_13_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_114_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((pub_r001680_8_1 * 2) + 19) & 63;
  int stage_v_115_2 = ((pub_r001680_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001680_14_1 * 2) + 30) & 63;
  int stage_v_116_2 = ((pub_r001680_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((sec_r001680_21_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_117_2 = (((sec_r001680_21_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_117_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((sec_r001680_0_1 ^ 0x2A) * 2) + pub_r001680_16_1) & 127;
  int stage_v_118_2 = (((sec_r001680_0_2 ^ 0x2A) * 2) + pub_r001680_16_2) & 127;
  if (stage_v_118_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001680_8_1) & 127;
  int stage_v_119_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001680_8_2) & 127;
  if (stage_v_119_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001680_13_1) & 127;
  int stage_v_120_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001680_13_2) & 127;
  if (stage_v_120_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((sec_r001680_13_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_121_2 = (((sec_r001680_13_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_121_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((pub_r001680_12_1 * 2) + 9) & 63;
  int stage_v_122_2 = ((pub_r001680_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001680_1_1 * 2) + 47) & 63;
  int stage_v_123_2 = ((pub_r001680_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((sec_r001680_6_1 ^ 0x2A) * 2) + pub_r001680_17_1) & 127;
  int stage_v_124_2 = (((sec_r001680_6_2 ^ 0x2A) * 2) + pub_r001680_17_2) & 127;
  if (stage_v_124_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_125_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_125_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001680_15_1) & 127;
  int stage_v_126_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001680_15_2) & 127;
  if (stage_v_126_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_127_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_127_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001680_4_1) & 127;
  int stage_v_128_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001680_4_2) & 127;
  if (stage_v_128_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_129_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_129_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001680_15_1) & 127;
  int stage_v_130_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001680_15_2) & 127;
  if (stage_v_130_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_131_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_131_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((pub_r001680_7_1 * 2) + 36) & 63;
  int stage_v_132_2 = ((pub_r001680_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001680_1_1 ^ 0x2A) * 2) + pub_r001680_8_1) & 127;
  int stage_v_133_2 = (((sec_r001680_1_2 ^ 0x2A) * 2) + pub_r001680_8_2) & 127;
  if (stage_v_133_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((sec_r001680_5_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_134_2 = (((sec_r001680_5_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_134_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001680_2_1) & 127;
  int stage_v_135_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001680_2_2) & 127;
  if (stage_v_135_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((sec_r001680_13_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_136_2 = (((sec_r001680_13_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_136_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_137_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_137_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((pub_r001680_2_1 * 2) + 33) & 63;
  int stage_v_138_2 = ((pub_r001680_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001680_8_1) & 127;
  int stage_v_139_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001680_8_2) & 127;
  if (stage_v_139_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((sec_r001680_23_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_140_2 = (((sec_r001680_23_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_140_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_141_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_141_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001680_0_1) & 127;
  int stage_v_142_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001680_0_2) & 127;
  if (stage_v_142_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_143_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_143_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((pub_r001680_3_1 * 2) + 10) & 63;
  int stage_v_144_2 = ((pub_r001680_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_145_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_145_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_146_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_146_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_147_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_147_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_148_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_148_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001680_11_1) & 127;
  int stage_v_149_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001680_11_2) & 127;
  if (stage_v_149_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_150_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_150_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((pub_r001680_9_1 * 2) + 5) & 63;
  int stage_v_151_2 = ((pub_r001680_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001680_17_1) & 127;
  int stage_v_152_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001680_17_2) & 127;
  if (stage_v_152_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_153_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_153_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001680_2_1) & 127;
  int stage_v_154_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001680_2_2) & 127;
  if (stage_v_154_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((sec_r001680_18_1 ^ 0x2A) * 2) + pub_r001680_0_1) & 127;
  int stage_v_155_2 = (((sec_r001680_18_2 ^ 0x2A) * 2) + pub_r001680_0_2) & 127;
  if (stage_v_155_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001680_0_1) & 127;
  int stage_v_156_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001680_0_2) & 127;
  if (stage_v_156_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001680_7_1) & 127;
  int stage_v_157_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001680_7_2) & 127;
  if (stage_v_157_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((pub_r001680_9_1 * 2) + 27) & 63;
  int stage_v_158_2 = ((pub_r001680_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((sec_r001680_1_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_159_2 = (((sec_r001680_1_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_159_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((pub_r001680_10_1 * 2) + 29) & 63;
  int stage_v_160_2 = ((pub_r001680_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001680_13_1 * 2) + 11) & 63;
  int stage_v_161_2 = ((pub_r001680_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_162_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_162_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((pub_r001680_10_1 * 2) + 20) & 63;
  int stage_v_163_2 = ((pub_r001680_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_164_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_164_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((sec_r001680_1_1 ^ 0x2A) * 2) + pub_r001680_7_1) & 127;
  int stage_v_165_2 = (((sec_r001680_1_2 ^ 0x2A) * 2) + pub_r001680_7_2) & 127;
  if (stage_v_165_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_166_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_166_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((pub_r001680_14_1 * 2) + 40) & 63;
  int stage_v_167_2 = ((pub_r001680_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001680_17_1 * 2) + 20) & 63;
  int stage_v_168_2 = ((pub_r001680_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_169_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_169_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001680_7_1) & 127;
  int stage_v_170_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001680_7_2) & 127;
  if (stage_v_170_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_171_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_171_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((sec_r001680_1_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_172_2 = (((sec_r001680_1_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_172_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_173_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_173_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_125_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_174_2 = (((stage_v_125_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_174_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((pub_r001680_5_1 * 2) + 10) & 63;
  int stage_v_175_2 = ((pub_r001680_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001680_12_1 * 2) + 42) & 63;
  int stage_v_176_2 = ((pub_r001680_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001680_14_1 * 2) + 25) & 63;
  int stage_v_177_2 = ((pub_r001680_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001680_0_1) & 127;
  int stage_v_178_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001680_0_2) & 127;
  if (stage_v_178_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001680_2_1) & 127;
  int stage_v_179_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001680_2_2) & 127;
  if (stage_v_179_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_180_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_180_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((pub_r001680_2_1 * 2) + 14) & 63;
  int stage_v_181_2 = ((pub_r001680_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_182_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_182_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_183_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_183_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((pub_r001680_13_1 * 2) + 13) & 63;
  int stage_v_184_2 = ((pub_r001680_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001680_5_1) & 127;
  int stage_v_185_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001680_5_2) & 127;
  if (stage_v_185_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001680_7_1) & 127;
  int stage_v_186_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001680_7_2) & 127;
  if (stage_v_186_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_187_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_187_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((pub_r001680_5_1 * 2) + 41) & 63;
  int stage_v_188_2 = ((pub_r001680_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_189_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_189_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001680_10_1) & 127;
  int stage_v_190_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001680_10_2) & 127;
  if (stage_v_190_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001680_8_1) & 127;
  int stage_v_191_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001680_8_2) & 127;
  if (stage_v_191_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001680_11_1) & 127;
  int stage_v_192_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001680_11_2) & 127;
  if (stage_v_192_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001680_12_1) & 127;
  int stage_v_193_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001680_12_2) & 127;
  if (stage_v_193_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001680_14_1) & 127;
  int stage_v_194_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001680_14_2) & 127;
  if (stage_v_194_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_195_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_195_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001680_15_1) & 127;
  int stage_v_196_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001680_15_2) & 127;
  if (stage_v_196_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001680_1_1) & 127;
  int stage_v_197_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001680_1_2) & 127;
  if (stage_v_197_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001680_13_1) & 127;
  int stage_v_198_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001680_13_2) & 127;
  if (stage_v_198_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((sec_r001680_19_1 ^ 0x2A) * 2) + pub_r001680_9_1) & 127;
  int stage_v_199_2 = (((sec_r001680_19_2 ^ 0x2A) * 2) + pub_r001680_9_2) & 127;
  if (stage_v_199_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_200_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_200_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((pub_r001680_9_1 * 2) + 16) & 63;
  int stage_v_201_2 = ((pub_r001680_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001680_3_1) & 127;
  int stage_v_202_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001680_3_2) & 127;
  if (stage_v_202_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_197_1 ^ 0x2A) * 2) + pub_r001680_6_1) & 127;
  int stage_v_203_2 = (((stage_v_197_2 ^ 0x2A) * 2) + pub_r001680_6_2) & 127;
  if (stage_v_203_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001680_10_1 == pub_r001680_10_2);
  __CPROVER_assume(pub_r001680_5_1 == pub_r001680_5_2);
  __CPROVER_assume(pub_r001680_16_1 == pub_r001680_16_2);
  __CPROVER_assume(sec_r001680_23_1 != sec_r001680_23_2);
  __CPROVER_assume(pub_r001680_1_1 == pub_r001680_1_2);
  __CPROVER_assume(pub_r001680_0_1 == pub_r001680_0_2);
  __CPROVER_assume(sec_r001680_1_1 != sec_r001680_1_2);
  __CPROVER_assume(sec_r001680_12_1 != sec_r001680_12_2);
  __CPROVER_assume(pub_r001680_14_1 == pub_r001680_14_2);
  __CPROVER_assume(sec_r001680_11_1 != sec_r001680_11_2);
  __CPROVER_assume(sec_r001680_5_1 != sec_r001680_5_2);
  __CPROVER_assume(pub_r001680_6_1 == pub_r001680_6_2);
  __CPROVER_assume(sec_r001680_10_1 != sec_r001680_10_2);
  __CPROVER_assume(sec_r001680_17_1 != sec_r001680_17_2);
  __CPROVER_assume(pub_r001680_9_1 == pub_r001680_9_2);
  __CPROVER_assume(sec_r001680_13_1 != sec_r001680_13_2);
  __CPROVER_assume(sec_r001680_9_1 != sec_r001680_9_2);
  __CPROVER_assume(sec_r001680_2_1 != sec_r001680_2_2);
  __CPROVER_assume(sec_r001680_8_1 != sec_r001680_8_2);
  __CPROVER_assume(sec_r001680_16_1 != sec_r001680_16_2);
  __CPROVER_assume(sec_r001680_19_1 != sec_r001680_19_2);
  __CPROVER_assume(sec_r001680_0_1 != sec_r001680_0_2);
  __CPROVER_assume(sec_r001680_6_1 != sec_r001680_6_2);
  __CPROVER_assume(sec_r001680_14_1 != sec_r001680_14_2);
  __CPROVER_assume(pub_r001680_13_1 == pub_r001680_13_2);
  __CPROVER_assume(pub_r001680_17_1 == pub_r001680_17_2);
  __CPROVER_assume(sec_r001680_7_1 != sec_r001680_7_2);
  __CPROVER_assume(pub_r001680_11_1 == pub_r001680_11_2);
  __CPROVER_assume(pub_r001680_15_1 == pub_r001680_15_2);
  __CPROVER_assume(pub_r001680_7_1 == pub_r001680_7_2);
  __CPROVER_assume(sec_r001680_18_1 != sec_r001680_18_2);
  __CPROVER_assume(sec_r001680_15_1 != sec_r001680_15_2);
  __CPROVER_assume(pub_r001680_4_1 == pub_r001680_4_2);
  __CPROVER_assume(sec_r001680_22_1 != sec_r001680_22_2);
  __CPROVER_assume(pub_r001680_8_1 == pub_r001680_8_2);
  __CPROVER_assume(pub_r001680_3_1 == pub_r001680_3_2);
  __CPROVER_assume(pub_r001680_12_1 == pub_r001680_12_2);
  __CPROVER_assume(sec_r001680_20_1 != sec_r001680_20_2);
  __CPROVER_assume(sec_r001680_3_1 != sec_r001680_3_2);
  __CPROVER_assume(sec_r001680_4_1 != sec_r001680_4_2);
  __CPROVER_assume(sec_r001680_21_1 != sec_r001680_21_2);
  __CPROVER_assume(pub_r001680_2_1 == pub_r001680_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.code == st_var_2_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.capacity == st_var_3_2.capacity);
  assert(st_var_3_1.state == st_var_3_2.state);
  assert(st_var_3_1.head == st_var_3_2.head);
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
  assert(helper_flow_10_1 == helper_flow_10_2);
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
}


