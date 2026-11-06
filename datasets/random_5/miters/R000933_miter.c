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
struct SensorNode_R000933_3313_0
{
  int calib;
  unsigned char status;
  short offset;
  int buffer[3];
};
struct Vector3D_R000933_3313_1
{
  short heading;
  short coord_y;
  int norm_sq;
  int pitch;
  int coord_x;
  unsigned char coord_z;
  int buffer[3];
};
struct FilterState_R000933_3313_2
{
  short mode;
  int cutoff;
  short gain_db;
  unsigned char damping;
  int prev_in;
  int buffer[3];
};
struct EventLog_R000933_3313_3
{
  int code;
  int signature;
  unsigned char timestamp;
  int buffer[3];
};
union RegisterBank_R000933_3313_0
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
void fn_R000933_3313_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st_1 = {0};
  struct SensorNode_R000933_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int pivot_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_16_1) & 63;
  aux_2 = (aux_2 + pivot_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_20_1 = local_arr_1[aux_1 % 3];
  int tally_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_20_2 * 2)) & 127;
  int cursor_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_71_1)
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

  switch (cursor_71_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_16_1 == pivot_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_20_1 == tally_20_2);
  assert(cursor_71_1 == cursor_71_2);
}

int fn_R000933_3313_0(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int pivot_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_16) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_20 = local_arr[aux % 3];
  acc = (acc + (tally_20 * 2)) & 127;
  int cursor_71 = (aux + st.buffer[1]) & 3;
  switch (cursor_71)
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

void fn_R000933_3313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st_1 = {0};
  struct SensorNode_R000933_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_65_1) & 63;
  aux_2 = (aux_2 + scale_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_31_1)
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

  switch (damping_31_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_65_1 == scale_65_2);
  assert(damping_31_1 == damping_31_2);
}

int fn_R000933_3313_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_65) & 63;
  acc ^= aux;
  int damping_31 = (aux + st.buffer[1]) & 3;
  switch (damping_31)
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

void fn_R000933_3313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000933_3313_2 st_1 = {0};
  struct FilterState_R000933_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_74_1 = local_arr_1[aux_1 % 3];
  int weight_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_74_2 * 2)) & 127;
  int factor_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_50_1)
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

  switch (factor_50_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_74_1 == weight_74_2);
  assert(factor_50_1 == factor_50_2);
}

int fn_R000933_3313_2(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000933_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int weight_74 = local_arr[aux % 3];
  acc = (acc + (weight_74 * 2)) & 127;
  int factor_50 = (aux + st.buffer[1]) & 3;
  switch (factor_50)
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

void fn_R000933_3313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000933_3313_2 st_1 = {0};
  struct FilterState_R000933_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int scale_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_70_1)
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

  switch (scale_70_2)
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

  int scale_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_49_1) & 63;
  aux_2 = (aux_2 + scale_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_70_1 == scale_70_2);
  assert(scale_49_1 == scale_49_2);
}

int fn_R000933_3313_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000933_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int scale_70 = (aux + st.buffer[1]) & 3;
  switch (scale_70)
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

  int scale_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000933_3313_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st_1 = {0};
  struct EventLog_R000933_3313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int sample_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_24_1 > 33)
  {
    acc_1 = ((acc_1 + (sample_24_1 * 2)) + 5) & 127;
    aux_1 ^= sample_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_24_2 > 33)
  {
    acc_2 = ((acc_2 + (sample_24_2 * 2)) + 5) & 127;
    aux_2 ^= sample_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_56_1)
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

  switch (quantum_56_2)
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

  int vector_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_68_1) & 63;
  aux_2 = (aux_2 + vector_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_24_1 == sample_24_2);
  assert(quantum_56_1 == quantum_56_2);
  assert(vector_68_1 == vector_68_2);
}

int fn_R000933_3313_4(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int sample_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_24 > 33)
  {
    acc = ((acc + (sample_24 * 2)) + 5) & 127;
    aux ^= sample_24 & 15;
  }
  else
  {
    acc = ((acc - sample_24) + 11) & 127;
    aux += 3;
  }
  int quantum_56 = (aux + st.buffer[1]) & 3;
  switch (quantum_56)
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

  int vector_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_68) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000933_3313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st_1 = {0};
  struct SensorNode_R000933_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int residue_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_77_1 > 26)
  {
    acc_1 = ((acc_1 + (residue_77_1 * 2)) + 5) & 127;
    aux_1 ^= residue_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_77_2 > 26)
  {
    acc_2 = ((acc_2 + (residue_77_2 * 2)) + 5) & 127;
    aux_2 ^= residue_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_77_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_64_1) & 63;
  aux_2 = (aux_2 + threshold_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_77_1 == residue_77_2);
  assert(threshold_64_1 == threshold_64_2);
}

int fn_R000933_3313_5(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int residue_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_77 > 26)
  {
    acc = ((acc + (residue_77 * 2)) + 5) & 127;
    aux ^= residue_77 & 15;
  }
  else
  {
    acc = ((acc - residue_77) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000933_3313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st_1 = {0};
  struct EventLog_R000933_3313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int window_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_96_1)
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

  switch (window_96_2)
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
  int phase_60_1 = local_arr_1[aux_1 % 3];
  int phase_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_60_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_35_1) & 63;
  aux_2 = (aux_2 + stride_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_96_1 == window_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_60_1 == phase_60_2);
  assert(stride_35_1 == stride_35_2);
}

int fn_R000933_3313_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int window_96 = (aux + st.buffer[1]) & 3;
  switch (window_96)
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
  int phase_60 = local_arr[aux % 3];
  acc = (acc + (phase_60 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000933_3313_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st_1 = {0};
  struct SensorNode_R000933_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int accumulator_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_85_1 > 49)
  {
    acc_1 = ((acc_1 + (accumulator_85_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_85_2 > 49)
  {
    acc_2 = ((acc_2 + (accumulator_85_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_15_1 = local_arr_1[aux_1 % 3];
  int phase_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_15_2 * 2)) & 127;
  int index_reg_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_64_1) & 63;
  aux_2 = (aux_2 + index_reg_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_22_1)
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

  switch (anchor_22_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_85_1 == accumulator_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_15_1 == phase_15_2);
  assert(index_reg_64_1 == index_reg_64_2);
  assert(anchor_22_1 == anchor_22_2);
}

int fn_R000933_3313_7(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int accumulator_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_85 > 49)
  {
    acc = ((acc + (accumulator_85 * 2)) + 5) & 127;
    aux ^= accumulator_85 & 15;
  }
  else
  {
    acc = ((acc - accumulator_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_15 = local_arr[aux % 3];
  acc = (acc + (phase_15 * 2)) & 127;
  int index_reg_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_64) & 63;
  acc ^= aux;
  int anchor_22 = (aux + st.buffer[1]) & 3;
  switch (anchor_22)
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

void fn_R000933_3313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st_1 = {0};
  struct Vector3D_R000933_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int residue_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_63_1) & 63;
  aux_2 = (aux_2 + residue_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_63_1 == residue_63_2);
}

int fn_R000933_3313_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int residue_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_63) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000933_3313_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st_1 = {0};
  struct Vector3D_R000933_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_37_1 > 36)
  {
    acc_1 = ((acc_1 + (sample_37_1 * 2)) + 5) & 127;
    aux_1 ^= sample_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_37_2 > 36)
  {
    acc_2 = ((acc_2 + (sample_37_2 * 2)) + 5) & 127;
    aux_2 ^= sample_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_10_1 = local_arr_1[aux_1 % 3];
  int segment_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_10_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_14_1) & 63;
  aux_2 = (aux_2 + parity_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_37_1 == sample_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_10_1 == segment_10_2);
  assert(parity_14_1 == parity_14_2);
}

int fn_R000933_3313_9(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_37 > 36)
  {
    acc = ((acc + (sample_37 * 2)) + 5) & 127;
    aux ^= sample_37 & 15;
  }
  else
  {
    acc = ((acc - sample_37) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_10 = local_arr[aux % 3];
  acc = (acc + (segment_10 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000933_3313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st_1 = {0};
  struct Vector3D_R000933_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int bound_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_70_1) & 63;
  aux_2 = (aux_2 + bound_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_70_1 == bound_70_2);
}

int fn_R000933_3313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int bound_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000933_3313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st_1 = {0};
  struct EventLog_R000933_3313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int mask_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_77_1)
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

  switch (mask_77_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_11_1 = local_arr_1[aux_1 % 3];
  int phase_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_11_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_37_1 > 32)
  {
    acc_1 = ((acc_1 + (damping_37_1 * 2)) + 5) & 127;
    aux_1 ^= damping_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_37_2 > 32)
  {
    acc_2 = ((acc_2 + (damping_37_2 * 2)) + 5) & 127;
    aux_2 ^= damping_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_77_1 == mask_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_11_1 == phase_11_2);
  assert(damping_37_1 == damping_37_2);
}

int fn_R000933_3313_11(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int mask_77 = (aux + st.buffer[1]) & 3;
  switch (mask_77)
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

  int local_arr[3] = {4, 9, 15};
  int phase_11 = local_arr[aux % 3];
  acc = (acc + (phase_11 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_37 > 32)
  {
    acc = ((acc + (damping_37 * 2)) + 5) & 127;
    aux ^= damping_37 & 15;
  }
  else
  {
    acc = ((acc - damping_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000933_3313_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st_1 = {0};
  struct SensorNode_R000933_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_80_1 = local_arr_1[aux_1 % 3];
  int index_reg_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_80_2 * 2)) & 127;
  int stride_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_95_1)
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

  switch (stride_95_2)
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

  int tracker_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_81_1 > 30)
  {
    acc_1 = ((acc_1 + (tracker_81_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_81_2 > 30)
  {
    acc_2 = ((acc_2 + (tracker_81_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_80_1 == index_reg_80_2);
  assert(stride_95_1 == stride_95_2);
  assert(tracker_81_1 == tracker_81_2);
}

int fn_R000933_3313_12(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int index_reg_80 = local_arr[aux % 3];
  acc = (acc + (index_reg_80 * 2)) & 127;
  int stride_95 = (aux + st.buffer[1]) & 3;
  switch (stride_95)
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

  int tracker_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_81 > 30)
  {
    acc = ((acc + (tracker_81 * 2)) + 5) & 127;
    aux ^= tracker_81 & 15;
  }
  else
  {
    acc = ((acc - tracker_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000933_3313_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st_1 = {0};
  struct SensorNode_R000933_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int parity_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_13_1)
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

  switch (parity_13_2)
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

  int weight_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_45_1) & 63;
  aux_2 = (aux_2 + weight_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_25_1 > 18)
  {
    acc_1 = ((acc_1 + (anchor_25_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_25_2 > 18)
  {
    acc_2 = ((acc_2 + (anchor_25_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_13_1 == parity_13_2);
  assert(weight_45_1 == weight_45_2);
  assert(anchor_25_1 == anchor_25_2);
}

int fn_R000933_3313_13(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int parity_13 = (aux + st.buffer[1]) & 3;
  switch (parity_13)
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

  int weight_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_45) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_25 > 18)
  {
    acc = ((acc + (anchor_25 * 2)) + 5) & 127;
    aux ^= anchor_25 & 15;
  }
  else
  {
    acc = ((acc - anchor_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000933_3313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st_1 = {0};
  struct SensorNode_R000933_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int tally_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_37_1) & 63;
  aux_2 = (aux_2 + tally_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_37_1 == tally_37_2);
}

int fn_R000933_3313_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000933_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int tally_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_37) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000933_3313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000933_3313_2 st_1 = {0};
  struct FilterState_R000933_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_36_1) & 63;
  aux_2 = (aux_2 + pivot_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_60_1 > 46)
  {
    acc_1 = ((acc_1 + (tally_60_1 * 2)) + 5) & 127;
    aux_1 ^= tally_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_60_2 > 46)
  {
    acc_2 = ((acc_2 + (tally_60_2 * 2)) + 5) & 127;
    aux_2 ^= tally_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_29_1 = local_arr_1[aux_1 % 3];
  int weight_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_36_1 == pivot_36_2);
  assert(tally_60_1 == tally_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_29_1 == weight_29_2);
}

int fn_R000933_3313_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000933_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_36) & 63;
  acc ^= aux;
  int tally_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_60 > 46)
  {
    acc = ((acc + (tally_60 * 2)) + 5) & 127;
    aux ^= tally_60 & 15;
  }
  else
  {
    acc = ((acc - tally_60) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int weight_29 = local_arr[aux % 3];
  acc = (acc + (weight_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000933_3313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st_1 = {0};
  struct Vector3D_R000933_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int weight_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_69_1)
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

  switch (weight_69_2)
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

  int tracker_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_46_1 > 44)
  {
    acc_1 = ((acc_1 + (tracker_46_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_46_2 > 44)
  {
    acc_2 = ((acc_2 + (tracker_46_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_10_1 = local_arr_1[aux_1 % 3];
  int vector_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_10_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_69_1 == weight_69_2);
  assert(tracker_46_1 == tracker_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_10_1 == vector_10_2);
}

int fn_R000933_3313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int weight_69 = (aux + st.buffer[1]) & 3;
  switch (weight_69)
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

  int tracker_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_46 > 44)
  {
    acc = ((acc + (tracker_46 * 2)) + 5) & 127;
    aux ^= tracker_46 & 15;
  }
  else
  {
    acc = ((acc - tracker_46) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_10 = local_arr[aux % 3];
  acc = (acc + (vector_10 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000933_3313_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st_1 = {0};
  struct EventLog_R000933_3313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int tracker_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_75_1) & 63;
  aux_2 = (aux_2 + tracker_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_17_1 = local_arr_1[aux_1 % 3];
  int quotient_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_17_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_75_1 == tracker_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_17_1 == quotient_17_2);
}

int fn_R000933_3313_17(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int tracker_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_75) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_17 = local_arr[aux % 3];
  acc = (acc + (quotient_17 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000933_3313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st_1 = {0};
  struct EventLog_R000933_3313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int mask_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_99_1 > 41)
  {
    acc_1 = ((acc_1 + (mask_99_1 * 2)) + 5) & 127;
    aux_1 ^= mask_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_99_2 > 41)
  {
    acc_2 = ((acc_2 + (mask_99_2 * 2)) + 5) & 127;
    aux_2 ^= mask_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_22_1) & 63;
  aux_2 = (aux_2 + tally_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_94_1 = local_arr_1[aux_1 % 3];
  int mask_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_94_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_99_1 == mask_99_2);
  assert(tally_22_1 == tally_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_94_1 == mask_94_2);
}

int fn_R000933_3313_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int mask_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_99 > 41)
  {
    acc = ((acc + (mask_99 * 2)) + 5) & 127;
    aux ^= mask_99 & 15;
  }
  else
  {
    acc = ((acc - mask_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_22) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_94 = local_arr[aux % 3];
  acc = (acc + (mask_94 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000933_3313_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st_1 = {0};
  struct EventLog_R000933_3313_3 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_83_1 = local_arr_1[aux_1 % 3];
  int offset_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_83_2 * 2)) & 127;
  int quantum_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_32_1)
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

  switch (quantum_32_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_83_1 == offset_83_2);
  assert(quantum_32_1 == quantum_32_2);
}

int fn_R000933_3313_19(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000933_3313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_83 = local_arr[aux % 3];
  acc = (acc + (offset_83 * 2)) & 127;
  int quantum_32 = (aux + st.buffer[1]) & 3;
  switch (quantum_32)
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

void fn_R000933_3313_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st_1 = {0};
  struct Vector3D_R000933_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int coefficient_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_59_1)
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

  switch (coefficient_59_2)
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

  int threshold_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_68_1) & 63;
  aux_2 = (aux_2 + threshold_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_59_1 == coefficient_59_2);
  assert(threshold_68_1 == threshold_68_2);
}

int fn_R000933_3313_20(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000933_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int coefficient_59 = (aux + st.buffer[1]) & 3;
  switch (coefficient_59)
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

  int threshold_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_68) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000933_0_1;
  int sec_r000933_0_2;
  int sec_r000933_1_1;
  int sec_r000933_1_2;
  int sec_r000933_2_1;
  int sec_r000933_2_2;
  int sec_r000933_3_1;
  int sec_r000933_3_2;
  int sec_r000933_4_1;
  int sec_r000933_4_2;
  int sec_r000933_5_1;
  int sec_r000933_5_2;
  int sec_r000933_6_1;
  int sec_r000933_6_2;
  int sec_r000933_7_1;
  int sec_r000933_7_2;
  int sec_r000933_8_1;
  int sec_r000933_8_2;
  int sec_r000933_9_1;
  int sec_r000933_9_2;
  int sec_r000933_10_1;
  int sec_r000933_10_2;
  int sec_r000933_11_1;
  int sec_r000933_11_2;
  int sec_r000933_12_1;
  int sec_r000933_12_2;
  int sec_r000933_13_1;
  int sec_r000933_13_2;
  int sec_r000933_14_1;
  int sec_r000933_14_2;
  int sec_r000933_15_1;
  int sec_r000933_15_2;
  int sec_r000933_16_1;
  int sec_r000933_16_2;
  int sec_r000933_17_1;
  int sec_r000933_17_2;
  int sec_r000933_18_1;
  int sec_r000933_18_2;
  int sec_r000933_19_1;
  int sec_r000933_19_2;
  int sec_r000933_20_1;
  int sec_r000933_20_2;
  int sec_r000933_21_1;
  int sec_r000933_21_2;
  int pub_r000933_0_1;
  int pub_r000933_0_2;
  int pub_r000933_1_1;
  int pub_r000933_1_2;
  int pub_r000933_2_1;
  int pub_r000933_2_2;
  int pub_r000933_3_1;
  int pub_r000933_3_2;
  int pub_r000933_4_1;
  int pub_r000933_4_2;
  int pub_r000933_5_1;
  int pub_r000933_5_2;
  int pub_r000933_6_1;
  int pub_r000933_6_2;
  int pub_r000933_7_1;
  int pub_r000933_7_2;
  int pub_r000933_8_1;
  int pub_r000933_8_2;
  int pub_r000933_9_1;
  int pub_r000933_9_2;
  int pub_r000933_10_1;
  int pub_r000933_10_2;
  int pub_r000933_11_1;
  int pub_r000933_11_2;
  int pub_r000933_12_1;
  int pub_r000933_12_2;
  int pub_r000933_13_1;
  int pub_r000933_13_2;
  int pub_r000933_14_1;
  int pub_r000933_14_2;
  int pub_r000933_15_1;
  int pub_r000933_15_2;
  int pub_r000933_16_1;
  int pub_r000933_16_2;
  int pub_r000933_17_1;
  int pub_r000933_17_2;
  int pub_r000933_18_1;
  int pub_r000933_18_2;
  int pub_r000933_19_1;
  int pub_r000933_19_2;
  int pub_r000933_20_1;
  int pub_r000933_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000933_0_1 >= (-100)) && (pub_r000933_0_1 <= 100));
  __CPROVER_assume((pub_r000933_0_2 >= (-100)) && (pub_r000933_0_2 <= 100));
  __CPROVER_assume((pub_r000933_1_1 >= (-100)) && (pub_r000933_1_1 <= 100));
  __CPROVER_assume((pub_r000933_1_2 >= (-100)) && (pub_r000933_1_2 <= 100));
  __CPROVER_assume((pub_r000933_2_1 >= (-100)) && (pub_r000933_2_1 <= 100));
  __CPROVER_assume((pub_r000933_2_2 >= (-100)) && (pub_r000933_2_2 <= 100));
  __CPROVER_assume((pub_r000933_3_1 >= (-100)) && (pub_r000933_3_1 <= 100));
  __CPROVER_assume((pub_r000933_3_2 >= (-100)) && (pub_r000933_3_2 <= 100));
  __CPROVER_assume((pub_r000933_4_1 >= (-100)) && (pub_r000933_4_1 <= 100));
  __CPROVER_assume((pub_r000933_4_2 >= (-100)) && (pub_r000933_4_2 <= 100));
  __CPROVER_assume((pub_r000933_5_1 >= (-100)) && (pub_r000933_5_1 <= 100));
  __CPROVER_assume((pub_r000933_5_2 >= (-100)) && (pub_r000933_5_2 <= 100));
  __CPROVER_assume((pub_r000933_6_1 >= (-100)) && (pub_r000933_6_1 <= 100));
  __CPROVER_assume((pub_r000933_6_2 >= (-100)) && (pub_r000933_6_2 <= 100));
  __CPROVER_assume((pub_r000933_7_1 >= (-100)) && (pub_r000933_7_1 <= 100));
  __CPROVER_assume((pub_r000933_7_2 >= (-100)) && (pub_r000933_7_2 <= 100));
  __CPROVER_assume((pub_r000933_8_1 >= (-100)) && (pub_r000933_8_1 <= 100));
  __CPROVER_assume((pub_r000933_8_2 >= (-100)) && (pub_r000933_8_2 <= 100));
  __CPROVER_assume((pub_r000933_9_1 >= (-100)) && (pub_r000933_9_1 <= 100));
  __CPROVER_assume((pub_r000933_9_2 >= (-100)) && (pub_r000933_9_2 <= 100));
  __CPROVER_assume((pub_r000933_10_1 >= (-100)) && (pub_r000933_10_1 <= 100));
  __CPROVER_assume((pub_r000933_10_2 >= (-100)) && (pub_r000933_10_2 <= 100));
  __CPROVER_assume((pub_r000933_11_1 >= (-100)) && (pub_r000933_11_1 <= 100));
  __CPROVER_assume((pub_r000933_11_2 >= (-100)) && (pub_r000933_11_2 <= 100));
  __CPROVER_assume((pub_r000933_12_1 >= (-100)) && (pub_r000933_12_1 <= 100));
  __CPROVER_assume((pub_r000933_12_2 >= (-100)) && (pub_r000933_12_2 <= 100));
  __CPROVER_assume((pub_r000933_13_1 >= (-100)) && (pub_r000933_13_1 <= 100));
  __CPROVER_assume((pub_r000933_13_2 >= (-100)) && (pub_r000933_13_2 <= 100));
  __CPROVER_assume((pub_r000933_14_1 >= (-100)) && (pub_r000933_14_1 <= 100));
  __CPROVER_assume((pub_r000933_14_2 >= (-100)) && (pub_r000933_14_2 <= 100));
  __CPROVER_assume((pub_r000933_15_1 >= (-100)) && (pub_r000933_15_1 <= 100));
  __CPROVER_assume((pub_r000933_15_2 >= (-100)) && (pub_r000933_15_2 <= 100));
  __CPROVER_assume((pub_r000933_16_1 >= (-100)) && (pub_r000933_16_1 <= 100));
  __CPROVER_assume((pub_r000933_16_2 >= (-100)) && (pub_r000933_16_2 <= 100));
  __CPROVER_assume((pub_r000933_17_1 >= (-100)) && (pub_r000933_17_1 <= 100));
  __CPROVER_assume((pub_r000933_17_2 >= (-100)) && (pub_r000933_17_2 <= 100));
  __CPROVER_assume((pub_r000933_18_1 >= (-100)) && (pub_r000933_18_1 <= 100));
  __CPROVER_assume((pub_r000933_18_2 >= (-100)) && (pub_r000933_18_2 <= 100));
  __CPROVER_assume((pub_r000933_19_1 >= (-100)) && (pub_r000933_19_1 <= 100));
  __CPROVER_assume((pub_r000933_19_2 >= (-100)) && (pub_r000933_19_2 <= 100));
  __CPROVER_assume((pub_r000933_20_1 >= (-100)) && (pub_r000933_20_1 <= 100));
  __CPROVER_assume((pub_r000933_20_2 >= (-100)) && (pub_r000933_20_2 <= 100));
  __CPROVER_assume((sec_r000933_0_1 >= 0) && (sec_r000933_0_1 <= 255));
  __CPROVER_assume((sec_r000933_0_2 >= 0) && (sec_r000933_0_2 <= 255));
  __CPROVER_assume((sec_r000933_1_1 >= 0) && (sec_r000933_1_1 <= 255));
  __CPROVER_assume((sec_r000933_1_2 >= 0) && (sec_r000933_1_2 <= 255));
  __CPROVER_assume((sec_r000933_2_1 >= 0) && (sec_r000933_2_1 <= 255));
  __CPROVER_assume((sec_r000933_2_2 >= 0) && (sec_r000933_2_2 <= 255));
  __CPROVER_assume((sec_r000933_3_1 >= 0) && (sec_r000933_3_1 <= 255));
  __CPROVER_assume((sec_r000933_3_2 >= 0) && (sec_r000933_3_2 <= 255));
  __CPROVER_assume((sec_r000933_4_1 >= 0) && (sec_r000933_4_1 <= 255));
  __CPROVER_assume((sec_r000933_4_2 >= 0) && (sec_r000933_4_2 <= 255));
  __CPROVER_assume((sec_r000933_5_1 >= 0) && (sec_r000933_5_1 <= 255));
  __CPROVER_assume((sec_r000933_5_2 >= 0) && (sec_r000933_5_2 <= 255));
  __CPROVER_assume((sec_r000933_6_1 >= 0) && (sec_r000933_6_1 <= 255));
  __CPROVER_assume((sec_r000933_6_2 >= 0) && (sec_r000933_6_2 <= 255));
  __CPROVER_assume((sec_r000933_7_1 >= 0) && (sec_r000933_7_1 <= 255));
  __CPROVER_assume((sec_r000933_7_2 >= 0) && (sec_r000933_7_2 <= 255));
  __CPROVER_assume((sec_r000933_8_1 >= 0) && (sec_r000933_8_1 <= 255));
  __CPROVER_assume((sec_r000933_8_2 >= 0) && (sec_r000933_8_2 <= 255));
  __CPROVER_assume((sec_r000933_9_1 >= 0) && (sec_r000933_9_1 <= 255));
  __CPROVER_assume((sec_r000933_9_2 >= 0) && (sec_r000933_9_2 <= 255));
  __CPROVER_assume((sec_r000933_10_1 >= 0) && (sec_r000933_10_1 <= 255));
  __CPROVER_assume((sec_r000933_10_2 >= 0) && (sec_r000933_10_2 <= 255));
  __CPROVER_assume((sec_r000933_11_1 >= 0) && (sec_r000933_11_1 <= 255));
  __CPROVER_assume((sec_r000933_11_2 >= 0) && (sec_r000933_11_2 <= 255));
  __CPROVER_assume((sec_r000933_12_1 >= 0) && (sec_r000933_12_1 <= 255));
  __CPROVER_assume((sec_r000933_12_2 >= 0) && (sec_r000933_12_2 <= 255));
  __CPROVER_assume((sec_r000933_13_1 >= 0) && (sec_r000933_13_1 <= 255));
  __CPROVER_assume((sec_r000933_13_2 >= 0) && (sec_r000933_13_2 <= 255));
  __CPROVER_assume((sec_r000933_14_1 >= 0) && (sec_r000933_14_1 <= 255));
  __CPROVER_assume((sec_r000933_14_2 >= 0) && (sec_r000933_14_2 <= 255));
  __CPROVER_assume((sec_r000933_15_1 >= 0) && (sec_r000933_15_1 <= 255));
  __CPROVER_assume((sec_r000933_15_2 >= 0) && (sec_r000933_15_2 <= 255));
  __CPROVER_assume((sec_r000933_16_1 >= 0) && (sec_r000933_16_1 <= 255));
  __CPROVER_assume((sec_r000933_16_2 >= 0) && (sec_r000933_16_2 <= 255));
  __CPROVER_assume((sec_r000933_17_1 >= 0) && (sec_r000933_17_1 <= 255));
  __CPROVER_assume((sec_r000933_17_2 >= 0) && (sec_r000933_17_2 <= 255));
  __CPROVER_assume((sec_r000933_18_1 >= 0) && (sec_r000933_18_1 <= 255));
  __CPROVER_assume((sec_r000933_18_2 >= 0) && (sec_r000933_18_2 <= 255));
  __CPROVER_assume((sec_r000933_19_1 >= 0) && (sec_r000933_19_1 <= 255));
  __CPROVER_assume((sec_r000933_19_2 >= 0) && (sec_r000933_19_2 <= 255));
  __CPROVER_assume((sec_r000933_20_1 >= 0) && (sec_r000933_20_1 <= 255));
  __CPROVER_assume((sec_r000933_20_2 >= 0) && (sec_r000933_20_2 <= 255));
  __CPROVER_assume((sec_r000933_21_1 >= 0) && (sec_r000933_21_1 <= 255));
  __CPROVER_assume((sec_r000933_21_2 >= 0) && (sec_r000933_21_2 <= 255));
  struct SensorNode_R000933_3313_0 st_var_0_1 = {0};
  struct SensorNode_R000933_3313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000933_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000933_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000933_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000933_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000933_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000933_0_2 + 7) & 15;
  struct Vector3D_R000933_3313_1 st_var_1_1 = {0};
  struct Vector3D_R000933_3313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000933_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000933_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000933_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000933_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000933_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000933_0_2 + 9) & 15;
  struct FilterState_R000933_3313_2 st_var_2_1 = {0};
  struct FilterState_R000933_3313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000933_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000933_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000933_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000933_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000933_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000933_0_2 + 11) & 15;
  struct EventLog_R000933_3313_3 st_var_3_1 = {0};
  struct EventLog_R000933_3313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000933_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000933_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000933_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000933_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000933_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000933_0_2 + 13) & 15;
  union RegisterBank_R000933_3313_0 u_var_1;
  union RegisterBank_R000933_3313_0 u_var_2;
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
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 30)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 30)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = ((st_var_2_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_2_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 36)
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
  if (stage_v_10_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 36)
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
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = (st_var_2_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_2_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (st_var_3_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_3_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
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
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
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
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 54)
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
  if (stage_v_33_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 54)
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
  int stage_v_34_1 = ((st_var_2_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_2_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 33)
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
  if (stage_v_34_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 33)
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
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int sub_step_37_1 = ((sec_r000933_17_1 + pub_r000933_17_1) + 31) & 127;
  int sub_step_37_2 = ((sec_r000933_17_2 + pub_r000933_17_2) + 31) & 127;
  int stage_v_37_1 = ((sub_step_37_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_37_2 = ((sub_step_37_2 * 2) + pub_r000933_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_37_1 & 15;
  st_var_1_2.buffer[1] = stage_v_37_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int sub_step_38_1 = ((sec_r000933_9_1 + pub_r000933_16_1) + 13) & 127;
  int sub_step_38_2 = ((sec_r000933_9_2 + pub_r000933_16_2) + 13) & 127;
  int stage_v_38_1 = ((sub_step_38_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_38_2 = ((sub_step_38_2 * 2) + pub_r000933_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_38_1 & 15;
  st_var_2_2.buffer[2] = stage_v_38_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int sub_step_39_1 = ((stage_v_37_1 + pub_r000933_20_1) + 10) & 127;
  int sub_step_39_2 = ((stage_v_37_2 + pub_r000933_20_2) + 10) & 127;
  int stage_v_39_1 = ((sub_step_39_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_39_2 = ((sub_step_39_2 * 2) + pub_r000933_14_2) & 127;
  st_var_3_1.buffer[0] = stage_v_39_1 & 15;
  st_var_3_2.buffer[0] = stage_v_39_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int sub_step_40_1 = ((stage_v_38_1 + pub_r000933_9_1) + 30) & 127;
  int sub_step_40_2 = ((stage_v_38_2 + pub_r000933_9_2) + 30) & 127;
  int stage_v_40_1 = ((sub_step_40_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_40_2 = ((sub_step_40_2 * 2) + pub_r000933_8_2) & 127;
  st_var_0_1.buffer[1] = stage_v_40_1 & 15;
  st_var_0_2.buffer[1] = stage_v_40_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int sub_step_41_1 = ((sub_step_38_1 + pub_r000933_18_1) + 19) & 127;
  int sub_step_41_2 = ((sub_step_38_2 + pub_r000933_18_2) + 19) & 127;
  int stage_v_41_1 = ((sub_step_41_1 * 2) + pub_r000933_20_1) & 127;
  int stage_v_41_2 = ((sub_step_41_2 * 2) + pub_r000933_20_2) & 127;
  st_var_1_1.buffer[2] = stage_v_41_1 & 15;
  st_var_1_2.buffer[2] = stage_v_41_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int sub_step_42_1 = ((stage_v_39_1 + pub_r000933_4_1) + 5) & 127;
  int sub_step_42_2 = ((stage_v_39_2 + pub_r000933_4_2) + 5) & 127;
  int stage_v_42_1 = ((sub_step_42_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_42_2 = ((sub_step_42_2 * 2) + pub_r000933_8_2) & 127;
  st_var_2_1.buffer[0] = stage_v_42_1 & 15;
  st_var_2_2.buffer[0] = stage_v_42_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int sub_step_43_1 = ((stage_v_42_1 + pub_r000933_11_1) + 5) & 127;
  int sub_step_43_2 = ((stage_v_42_2 + pub_r000933_11_2) + 5) & 127;
  int stage_v_43_1 = ((sub_step_43_1 * 2) + pub_r000933_17_1) & 127;
  int stage_v_43_2 = ((sub_step_43_2 * 2) + pub_r000933_17_2) & 127;
  st_var_3_1.buffer[1] = stage_v_43_1 & 15;
  st_var_3_2.buffer[1] = stage_v_43_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int sub_step_44_1 = ((stage_v_42_1 + pub_r000933_5_1) + 19) & 127;
  int sub_step_44_2 = ((stage_v_42_2 + pub_r000933_5_2) + 19) & 127;
  int stage_v_44_1 = ((sub_step_44_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_44_2 = ((sub_step_44_2 * 2) + pub_r000933_12_2) & 127;
  st_var_0_1.buffer[2] = stage_v_44_1 & 15;
  st_var_0_2.buffer[2] = stage_v_44_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int sub_step_45_1 = ((stage_v_41_1 + pub_r000933_8_1) + 31) & 127;
  int sub_step_45_2 = ((stage_v_41_2 + pub_r000933_8_2) + 31) & 127;
  int stage_v_45_1 = ((sub_step_45_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_45_2 = ((sub_step_45_2 * 2) + pub_r000933_4_2) & 127;
  st_var_1_1.buffer[0] = stage_v_45_1 & 15;
  st_var_1_2.buffer[0] = stage_v_45_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int sub_step_46_1 = ((sec_r000933_20_1 + pub_r000933_20_1) + 24) & 127;
  int sub_step_46_2 = ((sec_r000933_20_2 + pub_r000933_20_2) + 24) & 127;
  int stage_v_46_1 = ((sub_step_46_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_46_2 = ((sub_step_46_2 * 2) + pub_r000933_14_2) & 127;
  st_var_2_1.buffer[1] = stage_v_46_1 & 15;
  st_var_2_2.buffer[1] = stage_v_46_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int sub_step_47_1 = ((sec_r000933_4_1 + pub_r000933_9_1) + 11) & 127;
  int sub_step_47_2 = ((sec_r000933_4_2 + pub_r000933_9_2) + 11) & 127;
  int stage_v_47_1 = ((sub_step_47_1 * 2) + pub_r000933_9_1) & 127;
  int stage_v_47_2 = ((sub_step_47_2 * 2) + pub_r000933_9_2) & 127;
  st_var_3_1.buffer[2] = stage_v_47_1 & 15;
  st_var_3_2.buffer[2] = stage_v_47_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int sub_step_48_1 = ((sec_r000933_8_1 + pub_r000933_12_1) + 35) & 127;
  int sub_step_48_2 = ((sec_r000933_8_2 + pub_r000933_12_2) + 35) & 127;
  int stage_v_48_1 = ((sub_step_48_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_48_2 = ((sub_step_48_2 * 2) + pub_r000933_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_48_1 & 15;
  st_var_0_2.buffer[0] = stage_v_48_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int sub_step_49_1 = ((sub_step_37_1 + pub_r000933_8_1) + 30) & 127;
  int sub_step_49_2 = ((sub_step_37_2 + pub_r000933_8_2) + 30) & 127;
  int stage_v_49_1 = ((sub_step_49_1 * 2) + pub_r000933_19_1) & 127;
  int stage_v_49_2 = ((sub_step_49_2 * 2) + pub_r000933_19_2) & 127;
  st_var_1_1.buffer[1] = stage_v_49_1 & 15;
  st_var_1_2.buffer[1] = stage_v_49_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int sub_step_50_1 = ((sub_step_46_1 + pub_r000933_2_1) + 17) & 127;
  int sub_step_50_2 = ((sub_step_46_2 + pub_r000933_2_2) + 17) & 127;
  int stage_v_50_1 = ((sub_step_50_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_50_2 = ((sub_step_50_2 * 2) + pub_r000933_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_50_1 & 15;
  st_var_2_2.buffer[2] = stage_v_50_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int sub_step_51_1 = ((stage_v_37_1 + pub_r000933_1_1) + 13) & 127;
  int sub_step_51_2 = ((stage_v_37_2 + pub_r000933_1_2) + 13) & 127;
  int stage_v_51_1 = ((sub_step_51_1 * 2) + pub_r000933_15_1) & 127;
  int stage_v_51_2 = ((sub_step_51_2 * 2) + pub_r000933_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_51_1 & 15;
  st_var_3_2.buffer[0] = stage_v_51_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int sub_step_52_1 = ((sub_step_42_1 + pub_r000933_7_1) + 34) & 127;
  int sub_step_52_2 = ((sub_step_42_2 + pub_r000933_7_2) + 34) & 127;
  int stage_v_52_1 = ((sub_step_52_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_52_2 = ((sub_step_52_2 * 2) + pub_r000933_6_2) & 127;
  st_var_0_1.buffer[1] = stage_v_52_1 & 15;
  st_var_0_2.buffer[1] = stage_v_52_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int sub_step_53_1 = ((sec_r000933_6_1 + pub_r000933_17_1) + 28) & 127;
  int sub_step_53_2 = ((sec_r000933_6_2 + pub_r000933_17_2) + 28) & 127;
  int stage_v_53_1 = ((sub_step_53_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_53_2 = ((sub_step_53_2 * 2) + pub_r000933_16_2) & 127;
  st_var_1_1.buffer[2] = stage_v_53_1 & 15;
  st_var_1_2.buffer[2] = stage_v_53_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int sub_step_54_1 = ((stage_v_38_1 + pub_r000933_12_1) + 12) & 127;
  int sub_step_54_2 = ((stage_v_38_2 + pub_r000933_12_2) + 12) & 127;
  int stage_v_54_1 = ((sub_step_54_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_54_2 = ((sub_step_54_2 * 2) + pub_r000933_6_2) & 127;
  st_var_2_1.buffer[0] = stage_v_54_1 & 15;
  st_var_2_2.buffer[0] = stage_v_54_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int sub_step_55_1 = ((sec_r000933_5_1 + pub_r000933_12_1) + 16) & 127;
  int sub_step_55_2 = ((sec_r000933_5_2 + pub_r000933_12_2) + 16) & 127;
  int stage_v_55_1 = ((sub_step_55_1 * 2) + pub_r000933_2_1) & 127;
  int stage_v_55_2 = ((sub_step_55_2 * 2) + pub_r000933_2_2) & 127;
  st_var_3_1.buffer[1] = stage_v_55_1 & 15;
  st_var_3_2.buffer[1] = stage_v_55_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int sub_step_56_1 = ((stage_v_48_1 + pub_r000933_5_1) + 6) & 127;
  int sub_step_56_2 = ((stage_v_48_2 + pub_r000933_5_2) + 6) & 127;
  int stage_v_56_1 = ((sub_step_56_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_56_2 = ((sub_step_56_2 * 2) + pub_r000933_18_2) & 127;
  st_var_0_1.buffer[2] = stage_v_56_1 & 15;
  st_var_0_2.buffer[2] = stage_v_56_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int sub_step_57_1 = ((sec_r000933_17_1 + pub_r000933_17_1) + 10) & 127;
  int sub_step_57_2 = ((sec_r000933_17_2 + pub_r000933_17_2) + 10) & 127;
  int stage_v_57_1 = ((sub_step_57_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_57_2 = ((sub_step_57_2 * 2) + pub_r000933_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_57_1 & 15;
  st_var_1_2.buffer[0] = stage_v_57_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int sub_step_58_1 = ((sub_step_38_1 + pub_r000933_3_1) + 28) & 127;
  int sub_step_58_2 = ((sub_step_38_2 + pub_r000933_3_2) + 28) & 127;
  int stage_v_58_1 = ((sub_step_58_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_58_2 = ((sub_step_58_2 * 2) + pub_r000933_3_2) & 127;
  st_var_2_1.buffer[1] = stage_v_58_1 & 15;
  st_var_2_2.buffer[1] = stage_v_58_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int sub_step_59_1 = ((stage_v_57_1 + pub_r000933_13_1) + 7) & 127;
  int sub_step_59_2 = ((stage_v_57_2 + pub_r000933_13_2) + 7) & 127;
  int stage_v_59_1 = ((sub_step_59_1 * 2) + pub_r000933_2_1) & 127;
  int stage_v_59_2 = ((sub_step_59_2 * 2) + pub_r000933_2_2) & 127;
  st_var_3_1.buffer[2] = stage_v_59_1 & 15;
  st_var_3_2.buffer[2] = stage_v_59_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int sub_step_60_1 = ((sub_step_59_1 + pub_r000933_7_1) + 17) & 127;
  int sub_step_60_2 = ((sub_step_59_2 + pub_r000933_7_2) + 17) & 127;
  int stage_v_60_1 = ((sub_step_60_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_60_2 = ((sub_step_60_2 * 2) + pub_r000933_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_60_1 & 15;
  st_var_0_2.buffer[0] = stage_v_60_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int sub_step_61_1 = ((stage_v_40_1 + pub_r000933_7_1) + 23) & 127;
  int sub_step_61_2 = ((stage_v_40_2 + pub_r000933_7_2) + 23) & 127;
  int stage_v_61_1 = ((sub_step_61_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_61_2 = ((sub_step_61_2 * 2) + pub_r000933_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_61_1 & 15;
  st_var_1_2.buffer[1] = stage_v_61_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int sub_step_62_1 = ((sub_step_61_1 + pub_r000933_13_1) + 23) & 127;
  int sub_step_62_2 = ((sub_step_61_2 + pub_r000933_13_2) + 23) & 127;
  int stage_v_62_1 = ((sub_step_62_1 * 2) + pub_r000933_2_1) & 127;
  int stage_v_62_2 = ((sub_step_62_2 * 2) + pub_r000933_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_62_1 & 15;
  st_var_2_2.buffer[2] = stage_v_62_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int sub_step_63_1 = ((sec_r000933_1_1 + pub_r000933_14_1) + 19) & 127;
  int sub_step_63_2 = ((sec_r000933_1_2 + pub_r000933_14_2) + 19) & 127;
  int stage_v_63_1 = ((sub_step_63_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_63_2 = ((sub_step_63_2 * 2) + pub_r000933_3_2) & 127;
  st_var_3_1.buffer[0] = stage_v_63_1 & 15;
  st_var_3_2.buffer[0] = stage_v_63_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int sub_step_64_1 = ((stage_v_52_1 + pub_r000933_7_1) + 28) & 127;
  int sub_step_64_2 = ((stage_v_52_2 + pub_r000933_7_2) + 28) & 127;
  int stage_v_64_1 = ((sub_step_64_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_64_2 = ((sub_step_64_2 * 2) + pub_r000933_12_2) & 127;
  st_var_0_1.buffer[1] = stage_v_64_1 & 15;
  st_var_0_2.buffer[1] = stage_v_64_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int sub_step_65_1 = ((sub_step_43_1 + pub_r000933_4_1) + 30) & 127;
  int sub_step_65_2 = ((sub_step_43_2 + pub_r000933_4_2) + 30) & 127;
  int stage_v_65_1 = ((sub_step_65_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_65_2 = ((sub_step_65_2 * 2) + pub_r000933_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_65_1 & 15;
  st_var_1_2.buffer[2] = stage_v_65_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int sub_step_66_1 = ((sec_r000933_12_1 + pub_r000933_14_1) + 17) & 127;
  int sub_step_66_2 = ((sec_r000933_12_2 + pub_r000933_14_2) + 17) & 127;
  int stage_v_66_1 = ((sub_step_66_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_66_2 = ((sub_step_66_2 * 2) + pub_r000933_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_66_1 & 15;
  st_var_2_2.buffer[0] = stage_v_66_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int sub_step_67_1 = ((sec_r000933_12_1 + pub_r000933_3_1) + 22) & 127;
  int sub_step_67_2 = ((sec_r000933_12_2 + pub_r000933_3_2) + 22) & 127;
  int stage_v_67_1 = ((sub_step_67_1 * 2) + pub_r000933_2_1) & 127;
  int stage_v_67_2 = ((sub_step_67_2 * 2) + pub_r000933_2_2) & 127;
  st_var_3_1.buffer[1] = stage_v_67_1 & 15;
  st_var_3_2.buffer[1] = stage_v_67_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int sub_step_68_1 = ((stage_v_42_1 + pub_r000933_9_1) + 23) & 127;
  int sub_step_68_2 = ((stage_v_42_2 + pub_r000933_9_2) + 23) & 127;
  int stage_v_68_1 = ((sub_step_68_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_68_2 = ((sub_step_68_2 * 2) + pub_r000933_3_2) & 127;
  st_var_0_1.buffer[2] = stage_v_68_1 & 15;
  st_var_0_2.buffer[2] = stage_v_68_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int sub_step_69_1 = ((stage_v_65_1 + pub_r000933_17_1) + 26) & 127;
  int sub_step_69_2 = ((stage_v_65_2 + pub_r000933_17_2) + 26) & 127;
  int stage_v_69_1 = ((sub_step_69_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_69_2 = ((sub_step_69_2 * 2) + pub_r000933_12_2) & 127;
  st_var_1_1.buffer[0] = stage_v_69_1 & 15;
  st_var_1_2.buffer[0] = stage_v_69_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int sub_step_70_1 = ((sub_step_41_1 + pub_r000933_8_1) + 26) & 127;
  int sub_step_70_2 = ((sub_step_41_2 + pub_r000933_8_2) + 26) & 127;
  int stage_v_70_1 = ((sub_step_70_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_70_2 = ((sub_step_70_2 * 2) + pub_r000933_6_2) & 127;
  st_var_2_1.buffer[1] = stage_v_70_1 & 15;
  st_var_2_2.buffer[1] = stage_v_70_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int sub_step_71_1 = ((sec_r000933_9_1 + pub_r000933_0_1) + 21) & 127;
  int sub_step_71_2 = ((sec_r000933_9_2 + pub_r000933_0_2) + 21) & 127;
  int stage_v_71_1 = ((sub_step_71_1 * 2) + pub_r000933_11_1) & 127;
  int stage_v_71_2 = ((sub_step_71_2 * 2) + pub_r000933_11_2) & 127;
  st_var_3_1.buffer[2] = stage_v_71_1 & 15;
  st_var_3_2.buffer[2] = stage_v_71_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int sub_step_72_1 = ((stage_v_48_1 + pub_r000933_8_1) + 19) & 127;
  int sub_step_72_2 = ((stage_v_48_2 + pub_r000933_8_2) + 19) & 127;
  int stage_v_72_1 = ((sub_step_72_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_72_2 = ((sub_step_72_2 * 2) + pub_r000933_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_72_1 & 15;
  st_var_0_2.buffer[0] = stage_v_72_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int sub_step_73_1 = ((sec_r000933_18_1 + pub_r000933_12_1) + 28) & 127;
  int sub_step_73_2 = ((sec_r000933_18_2 + pub_r000933_12_2) + 28) & 127;
  int stage_v_73_1 = ((sub_step_73_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_73_2 = ((sub_step_73_2 * 2) + pub_r000933_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_73_1 & 15;
  st_var_1_2.buffer[1] = stage_v_73_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int sub_step_74_1 = ((sec_r000933_0_1 + pub_r000933_4_1) + 12) & 127;
  int sub_step_74_2 = ((sec_r000933_0_2 + pub_r000933_4_2) + 12) & 127;
  int stage_v_74_1 = ((sub_step_74_1 * 2) + pub_r000933_20_1) & 127;
  int stage_v_74_2 = ((sub_step_74_2 * 2) + pub_r000933_20_2) & 127;
  st_var_2_1.buffer[2] = stage_v_74_1 & 15;
  st_var_2_2.buffer[2] = stage_v_74_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int sub_step_75_1 = ((stage_v_60_1 + pub_r000933_9_1) + 6) & 127;
  int sub_step_75_2 = ((stage_v_60_2 + pub_r000933_9_2) + 6) & 127;
  int stage_v_75_1 = ((sub_step_75_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_75_2 = ((sub_step_75_2 * 2) + pub_r000933_12_2) & 127;
  st_var_3_1.buffer[0] = stage_v_75_1 & 15;
  st_var_3_2.buffer[0] = stage_v_75_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int sub_step_76_1 = ((sub_step_57_1 + pub_r000933_17_1) + 5) & 127;
  int sub_step_76_2 = ((sub_step_57_2 + pub_r000933_17_2) + 5) & 127;
  int stage_v_76_1 = ((sub_step_76_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_76_2 = ((sub_step_76_2 * 2) + pub_r000933_7_2) & 127;
  st_var_0_1.buffer[1] = stage_v_76_1 & 15;
  st_var_0_2.buffer[1] = stage_v_76_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int sub_step_77_1 = ((sec_r000933_2_1 + pub_r000933_0_1) + 9) & 127;
  int sub_step_77_2 = ((sec_r000933_2_2 + pub_r000933_0_2) + 9) & 127;
  int stage_v_77_1 = ((sub_step_77_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_77_2 = ((sub_step_77_2 * 2) + pub_r000933_16_2) & 127;
  st_var_1_1.buffer[2] = stage_v_77_1 & 15;
  st_var_1_2.buffer[2] = stage_v_77_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int sub_step_78_1 = ((sub_step_59_1 + pub_r000933_10_1) + 9) & 127;
  int sub_step_78_2 = ((sub_step_59_2 + pub_r000933_10_2) + 9) & 127;
  int stage_v_78_1 = ((sub_step_78_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_78_2 = ((sub_step_78_2 * 2) + pub_r000933_0_2) & 127;
  st_var_2_1.buffer[0] = stage_v_78_1 & 15;
  st_var_2_2.buffer[0] = stage_v_78_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int sub_step_79_1 = ((stage_v_37_1 + pub_r000933_7_1) + 22) & 127;
  int sub_step_79_2 = ((stage_v_37_2 + pub_r000933_7_2) + 22) & 127;
  int stage_v_79_1 = ((sub_step_79_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_79_2 = ((sub_step_79_2 * 2) + pub_r000933_4_2) & 127;
  st_var_3_1.buffer[1] = stage_v_79_1 & 15;
  st_var_3_2.buffer[1] = stage_v_79_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int sub_step_80_1 = ((sub_step_63_1 + pub_r000933_14_1) + 35) & 127;
  int sub_step_80_2 = ((sub_step_63_2 + pub_r000933_14_2) + 35) & 127;
  int stage_v_80_1 = ((sub_step_80_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_80_2 = ((sub_step_80_2 * 2) + pub_r000933_6_2) & 127;
  st_var_0_1.buffer[2] = stage_v_80_1 & 15;
  st_var_0_2.buffer[2] = stage_v_80_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int sub_step_81_1 = ((sec_r000933_21_1 + pub_r000933_7_1) + 33) & 127;
  int sub_step_81_2 = ((sec_r000933_21_2 + pub_r000933_7_2) + 33) & 127;
  int stage_v_81_1 = ((sub_step_81_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_81_2 = ((sub_step_81_2 * 2) + pub_r000933_0_2) & 127;
  st_var_1_1.buffer[0] = stage_v_81_1 & 15;
  st_var_1_2.buffer[0] = stage_v_81_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int sub_step_82_1 = ((stage_v_64_1 + pub_r000933_3_1) + 8) & 127;
  int sub_step_82_2 = ((stage_v_64_2 + pub_r000933_3_2) + 8) & 127;
  int stage_v_82_1 = ((sub_step_82_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_82_2 = ((sub_step_82_2 * 2) + pub_r000933_16_2) & 127;
  st_var_2_1.buffer[1] = stage_v_82_1 & 15;
  st_var_2_2.buffer[1] = stage_v_82_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int sub_step_83_1 = ((sec_r000933_15_1 + pub_r000933_15_1) + 17) & 127;
  int sub_step_83_2 = ((sec_r000933_15_2 + pub_r000933_15_2) + 17) & 127;
  int stage_v_83_1 = ((sub_step_83_1 * 2) + pub_r000933_15_1) & 127;
  int stage_v_83_2 = ((sub_step_83_2 * 2) + pub_r000933_15_2) & 127;
  st_var_3_1.buffer[2] = stage_v_83_1 & 15;
  st_var_3_2.buffer[2] = stage_v_83_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int sub_step_84_1 = ((sec_r000933_1_1 + pub_r000933_4_1) + 31) & 127;
  int sub_step_84_2 = ((sec_r000933_1_2 + pub_r000933_4_2) + 31) & 127;
  int stage_v_84_1 = ((sub_step_84_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_84_2 = ((sub_step_84_2 * 2) + pub_r000933_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_84_1 & 15;
  st_var_0_2.buffer[0] = stage_v_84_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int sub_step_85_1 = ((stage_v_68_1 + pub_r000933_16_1) + 25) & 127;
  int sub_step_85_2 = ((stage_v_68_2 + pub_r000933_16_2) + 25) & 127;
  int stage_v_85_1 = ((sub_step_85_1 * 2) + pub_r000933_9_1) & 127;
  int stage_v_85_2 = ((sub_step_85_2 * 2) + pub_r000933_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_85_1 & 15;
  st_var_1_2.buffer[1] = stage_v_85_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int sub_step_86_1 = ((stage_v_49_1 + pub_r000933_8_1) + 33) & 127;
  int sub_step_86_2 = ((stage_v_49_2 + pub_r000933_8_2) + 33) & 127;
  int stage_v_86_1 = ((sub_step_86_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_86_2 = ((sub_step_86_2 * 2) + pub_r000933_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_86_1 & 15;
  st_var_2_2.buffer[2] = stage_v_86_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int sub_step_87_1 = ((sub_step_58_1 + pub_r000933_1_1) + 27) & 127;
  int sub_step_87_2 = ((sub_step_58_2 + pub_r000933_1_2) + 27) & 127;
  int stage_v_87_1 = ((sub_step_87_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_87_2 = ((sub_step_87_2 * 2) + pub_r000933_13_2) & 127;
  st_var_3_1.buffer[0] = stage_v_87_1 & 15;
  st_var_3_2.buffer[0] = stage_v_87_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int sub_step_88_1 = ((sub_step_47_1 + pub_r000933_13_1) + 11) & 127;
  int sub_step_88_2 = ((sub_step_47_2 + pub_r000933_13_2) + 11) & 127;
  int stage_v_88_1 = ((sub_step_88_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_88_2 = ((sub_step_88_2 * 2) + pub_r000933_4_2) & 127;
  st_var_0_1.buffer[1] = stage_v_88_1 & 15;
  st_var_0_2.buffer[1] = stage_v_88_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int sub_step_89_1 = ((sec_r000933_11_1 + pub_r000933_7_1) + 9) & 127;
  int sub_step_89_2 = ((sec_r000933_11_2 + pub_r000933_7_2) + 9) & 127;
  int stage_v_89_1 = ((sub_step_89_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_89_2 = ((sub_step_89_2 * 2) + pub_r000933_13_2) & 127;
  st_var_1_1.buffer[2] = stage_v_89_1 & 15;
  st_var_1_2.buffer[2] = stage_v_89_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int sub_step_90_1 = ((sec_r000933_7_1 + pub_r000933_8_1) + 12) & 127;
  int sub_step_90_2 = ((sec_r000933_7_2 + pub_r000933_8_2) + 12) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000933_7_2) & 127;
  st_var_2_1.buffer[0] = stage_v_90_1 & 15;
  st_var_2_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((sub_step_46_1 + pub_r000933_5_1) + 32) & 127;
  int sub_step_91_2 = ((sub_step_46_2 + pub_r000933_5_2) + 32) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000933_8_2) & 127;
  st_var_3_1.buffer[1] = stage_v_91_1 & 15;
  st_var_3_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((sec_r000933_4_1 + pub_r000933_13_1) + 10) & 127;
  int sub_step_92_2 = ((sec_r000933_4_2 + pub_r000933_13_2) + 10) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000933_6_2) & 127;
  st_var_0_1.buffer[2] = stage_v_92_1 & 15;
  st_var_0_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((sec_r000933_20_1 + pub_r000933_17_1) + 34) & 127;
  int sub_step_93_2 = ((sec_r000933_20_2 + pub_r000933_17_2) + 34) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000933_7_2) & 127;
  st_var_1_1.buffer[0] = stage_v_93_1 & 15;
  st_var_1_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((sec_r000933_15_1 + pub_r000933_12_1) + 29) & 127;
  int sub_step_94_2 = ((sec_r000933_15_2 + pub_r000933_12_2) + 29) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000933_15_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000933_15_2) & 127;
  st_var_2_1.buffer[1] = stage_v_94_1 & 15;
  st_var_2_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sub_step_63_1 + pub_r000933_16_1) + 17) & 127;
  int sub_step_95_2 = ((sub_step_63_2 + pub_r000933_16_2) + 17) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000933_16_2) & 127;
  st_var_3_1.buffer[2] = stage_v_95_1 & 15;
  st_var_3_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((sec_r000933_19_1 + pub_r000933_8_1) + 28) & 127;
  int sub_step_96_2 = ((sec_r000933_19_2 + pub_r000933_8_2) + 28) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000933_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((sub_step_45_1 + pub_r000933_12_1) + 22) & 127;
  int sub_step_97_2 = ((sub_step_45_2 + pub_r000933_12_2) + 22) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000933_17_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000933_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((stage_v_49_1 + pub_r000933_2_1) + 15) & 127;
  int sub_step_98_2 = ((stage_v_49_2 + pub_r000933_2_2) + 15) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000933_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((stage_v_86_1 + pub_r000933_4_1) + 16) & 127;
  int sub_step_99_2 = ((stage_v_86_2 + pub_r000933_4_2) + 16) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000933_4_2) & 127;
  st_var_3_1.buffer[0] = stage_v_99_1 & 15;
  st_var_3_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((stage_v_63_1 + pub_r000933_13_1) + 7) & 127;
  int sub_step_100_2 = ((stage_v_63_2 + pub_r000933_13_2) + 7) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000933_13_2) & 127;
  st_var_0_1.buffer[1] = stage_v_100_1 & 15;
  st_var_0_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((sec_r000933_14_1 + pub_r000933_8_1) + 17) & 127;
  int sub_step_101_2 = ((sec_r000933_14_2 + pub_r000933_8_2) + 17) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000933_20_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000933_20_2) & 127;
  st_var_1_1.buffer[2] = stage_v_101_1 & 15;
  st_var_1_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((sub_step_71_1 + pub_r000933_10_1) + 22) & 127;
  int sub_step_102_2 = ((sub_step_71_2 + pub_r000933_10_2) + 22) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000933_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_102_1 & 15;
  st_var_2_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((stage_v_81_1 + pub_r000933_20_1) + 17) & 127;
  int sub_step_103_2 = ((stage_v_81_2 + pub_r000933_20_2) + 17) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000933_3_2) & 127;
  st_var_3_1.buffer[1] = stage_v_103_1 & 15;
  st_var_3_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((sec_r000933_12_1 + pub_r000933_19_1) + 29) & 127;
  int sub_step_104_2 = ((sec_r000933_12_2 + pub_r000933_19_2) + 29) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000933_11_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000933_11_2) & 127;
  st_var_0_1.buffer[2] = stage_v_104_1 & 15;
  st_var_0_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((sec_r000933_15_1 + pub_r000933_11_1) + 13) & 127;
  int sub_step_105_2 = ((sec_r000933_15_2 + pub_r000933_11_2) + 13) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000933_13_2) & 127;
  st_var_1_1.buffer[0] = stage_v_105_1 & 15;
  st_var_1_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((sec_r000933_13_1 + pub_r000933_9_1) + 11) & 127;
  int sub_step_106_2 = ((sec_r000933_13_2 + pub_r000933_9_2) + 11) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000933_3_2) & 127;
  st_var_2_1.buffer[1] = stage_v_106_1 & 15;
  st_var_2_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((sec_r000933_15_1 + pub_r000933_7_1) + 35) & 127;
  int sub_step_107_2 = ((sec_r000933_15_2 + pub_r000933_7_2) + 35) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000933_19_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000933_19_2) & 127;
  st_var_3_1.buffer[2] = stage_v_107_1 & 15;
  st_var_3_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((stage_v_40_1 + pub_r000933_2_1) + 30) & 127;
  int sub_step_108_2 = ((stage_v_40_2 + pub_r000933_2_2) + 30) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000933_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((stage_v_56_1 + pub_r000933_14_1) + 16) & 127;
  int sub_step_109_2 = ((stage_v_56_2 + pub_r000933_14_2) + 16) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000933_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((sec_r000933_9_1 + pub_r000933_3_1) + 15) & 127;
  int sub_step_110_2 = ((sec_r000933_9_2 + pub_r000933_3_2) + 15) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000933_20_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000933_20_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((sub_step_86_1 + pub_r000933_14_1) + 10) & 127;
  int sub_step_111_2 = ((sub_step_86_2 + pub_r000933_14_2) + 10) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000933_15_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000933_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_111_1 & 15;
  st_var_3_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((sub_step_65_1 + pub_r000933_20_1) + 12) & 127;
  int sub_step_112_2 = ((sub_step_65_2 + pub_r000933_20_2) + 12) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000933_19_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000933_19_2) & 127;
  st_var_0_1.buffer[1] = stage_v_112_1 & 15;
  st_var_0_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((sec_r000933_15_1 + pub_r000933_16_1) + 23) & 127;
  int sub_step_113_2 = ((sec_r000933_15_2 + pub_r000933_16_2) + 23) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000933_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_113_1 & 15;
  st_var_1_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((sec_r000933_5_1 + pub_r000933_1_1) + 5) & 127;
  int sub_step_114_2 = ((sec_r000933_5_2 + pub_r000933_1_2) + 5) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000933_8_2) & 127;
  st_var_2_1.buffer[0] = stage_v_114_1 & 15;
  st_var_2_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((stage_v_61_1 + pub_r000933_10_1) + 17) & 127;
  int sub_step_115_2 = ((stage_v_61_2 + pub_r000933_10_2) + 17) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000933_17_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000933_17_2) & 127;
  st_var_3_1.buffer[1] = stage_v_115_1 & 15;
  st_var_3_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((stage_v_40_1 + pub_r000933_18_1) + 7) & 127;
  int sub_step_116_2 = ((stage_v_40_2 + pub_r000933_18_2) + 7) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000933_18_2) & 127;
  st_var_0_1.buffer[2] = stage_v_116_1 & 15;
  st_var_0_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((stage_v_47_1 + pub_r000933_17_1) + 30) & 127;
  int sub_step_117_2 = ((stage_v_47_2 + pub_r000933_17_2) + 30) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000933_9_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000933_9_2) & 127;
  st_var_1_1.buffer[0] = stage_v_117_1 & 15;
  st_var_1_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((sub_step_81_1 + pub_r000933_13_1) + 5) & 127;
  int sub_step_118_2 = ((sub_step_81_2 + pub_r000933_13_2) + 5) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000933_19_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000933_19_2) & 127;
  st_var_2_1.buffer[1] = stage_v_118_1 & 15;
  st_var_2_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((sub_step_103_1 + pub_r000933_11_1) + 17) & 127;
  int sub_step_119_2 = ((sub_step_103_2 + pub_r000933_11_2) + 17) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000933_12_2) & 127;
  st_var_3_1.buffer[2] = stage_v_119_1 & 15;
  st_var_3_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((sub_step_75_1 + pub_r000933_3_1) + 28) & 127;
  int sub_step_120_2 = ((sub_step_75_2 + pub_r000933_3_2) + 28) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000933_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((stage_v_75_1 + pub_r000933_10_1) + 12) & 127;
  int sub_step_121_2 = ((stage_v_75_2 + pub_r000933_10_2) + 12) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000933_9_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000933_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sec_r000933_12_1 + pub_r000933_19_1) + 22) & 127;
  int sub_step_122_2 = ((sec_r000933_12_2 + pub_r000933_19_2) + 22) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000933_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((stage_v_45_1 + pub_r000933_11_1) + 13) & 127;
  int sub_step_123_2 = ((stage_v_45_2 + pub_r000933_11_2) + 13) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000933_9_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000933_9_2) & 127;
  st_var_3_1.buffer[0] = stage_v_123_1 & 15;
  st_var_3_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((sub_step_50_1 + pub_r000933_19_1) + 10) & 127;
  int sub_step_124_2 = ((sub_step_50_2 + pub_r000933_19_2) + 10) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000933_1_2) & 127;
  st_var_0_1.buffer[1] = stage_v_124_1 & 15;
  st_var_0_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((stage_v_92_1 + pub_r000933_11_1) + 27) & 127;
  int sub_step_125_2 = ((stage_v_92_2 + pub_r000933_11_2) + 27) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000933_6_2) & 127;
  st_var_1_1.buffer[2] = stage_v_125_1 & 15;
  st_var_1_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((sec_r000933_14_1 + pub_r000933_15_1) + 19) & 127;
  int sub_step_126_2 = ((sec_r000933_14_2 + pub_r000933_15_2) + 19) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000933_15_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000933_15_2) & 127;
  st_var_2_1.buffer[0] = stage_v_126_1 & 15;
  st_var_2_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((sub_step_51_1 + pub_r000933_3_1) + 34) & 127;
  int sub_step_127_2 = ((sub_step_51_2 + pub_r000933_3_2) + 34) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000933_9_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000933_9_2) & 127;
  st_var_3_1.buffer[1] = stage_v_127_1 & 15;
  st_var_3_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((sec_r000933_12_1 + pub_r000933_7_1) + 12) & 127;
  int sub_step_128_2 = ((sec_r000933_12_2 + pub_r000933_7_2) + 12) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000933_7_2) & 127;
  st_var_0_1.buffer[2] = stage_v_128_1 & 15;
  st_var_0_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((sec_r000933_7_1 + pub_r000933_4_1) + 6) & 127;
  int sub_step_129_2 = ((sec_r000933_7_2 + pub_r000933_4_2) + 6) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000933_18_2) & 127;
  st_var_1_1.buffer[0] = stage_v_129_1 & 15;
  st_var_1_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((stage_v_106_1 + pub_r000933_2_1) + 25) & 127;
  int sub_step_130_2 = ((stage_v_106_2 + pub_r000933_2_2) + 25) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000933_14_2) & 127;
  st_var_2_1.buffer[1] = stage_v_130_1 & 15;
  st_var_2_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((sec_r000933_16_1 + pub_r000933_13_1) + 17) & 127;
  int sub_step_131_2 = ((sec_r000933_16_2 + pub_r000933_13_2) + 17) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000933_6_2) & 127;
  st_var_3_1.buffer[2] = stage_v_131_1 & 15;
  st_var_3_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((stage_v_55_1 + pub_r000933_0_1) + 5) & 127;
  int sub_step_132_2 = ((stage_v_55_2 + pub_r000933_0_2) + 5) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000933_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((sec_r000933_8_1 + pub_r000933_5_1) + 6) & 127;
  int sub_step_133_2 = ((sec_r000933_8_2 + pub_r000933_5_2) + 6) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000933_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((sec_r000933_19_1 + pub_r000933_11_1) + 15) & 127;
  int sub_step_134_2 = ((sec_r000933_19_2 + pub_r000933_11_2) + 15) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000933_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((sub_step_74_1 + pub_r000933_18_1) + 30) & 127;
  int sub_step_135_2 = ((sub_step_74_2 + pub_r000933_18_2) + 30) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000933_13_2) & 127;
  st_var_3_1.buffer[0] = stage_v_135_1 & 15;
  st_var_3_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((stage_v_117_1 + pub_r000933_3_1) + 11) & 127;
  int sub_step_136_2 = ((stage_v_117_2 + pub_r000933_3_2) + 11) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000933_7_2) & 127;
  st_var_0_1.buffer[1] = stage_v_136_1 & 15;
  st_var_0_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((stage_v_85_1 + pub_r000933_12_1) + 27) & 127;
  int sub_step_137_2 = ((stage_v_85_2 + pub_r000933_12_2) + 27) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000933_11_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000933_11_2) & 127;
  st_var_1_1.buffer[2] = stage_v_137_1 & 15;
  st_var_1_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((sub_step_38_1 + pub_r000933_13_1) + 24) & 127;
  int sub_step_138_2 = ((sub_step_38_2 + pub_r000933_13_2) + 24) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000933_19_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000933_19_2) & 127;
  st_var_2_1.buffer[0] = stage_v_138_1 & 15;
  st_var_2_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((sub_step_94_1 + pub_r000933_5_1) + 34) & 127;
  int sub_step_139_2 = ((sub_step_94_2 + pub_r000933_5_2) + 34) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000933_8_2) & 127;
  st_var_3_1.buffer[1] = stage_v_139_1 & 15;
  st_var_3_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((stage_v_135_1 + pub_r000933_1_1) + 27) & 127;
  int sub_step_140_2 = ((stage_v_135_2 + pub_r000933_1_2) + 27) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000933_18_2) & 127;
  st_var_0_1.buffer[2] = stage_v_140_1 & 15;
  st_var_0_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((stage_v_126_1 + pub_r000933_9_1) + 24) & 127;
  int sub_step_141_2 = ((stage_v_126_2 + pub_r000933_9_2) + 24) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000933_11_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000933_11_2) & 127;
  st_var_1_1.buffer[0] = stage_v_141_1 & 15;
  st_var_1_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((stage_v_134_1 + pub_r000933_9_1) + 20) & 127;
  int sub_step_142_2 = ((stage_v_134_2 + pub_r000933_9_2) + 20) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000933_13_2) & 127;
  st_var_2_1.buffer[1] = stage_v_142_1 & 15;
  st_var_2_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((stage_v_82_1 + pub_r000933_5_1) + 18) & 127;
  int sub_step_143_2 = ((stage_v_82_2 + pub_r000933_5_2) + 18) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000933_6_2) & 127;
  st_var_3_1.buffer[2] = stage_v_143_1 & 15;
  st_var_3_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((stage_v_67_1 + pub_r000933_12_1) + 20) & 127;
  int sub_step_144_2 = ((stage_v_67_2 + pub_r000933_12_2) + 20) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000933_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((stage_v_63_1 + pub_r000933_1_1) + 33) & 127;
  int sub_step_145_2 = ((stage_v_63_2 + pub_r000933_1_2) + 33) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000933_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((sec_r000933_0_1 + pub_r000933_7_1) + 5) & 127;
  int sub_step_146_2 = ((sec_r000933_0_2 + pub_r000933_7_2) + 5) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000933_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((stage_v_38_1 + pub_r000933_15_1) + 7) & 127;
  int sub_step_147_2 = ((stage_v_38_2 + pub_r000933_15_2) + 7) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000933_19_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000933_19_2) & 127;
  st_var_3_1.buffer[0] = stage_v_147_1 & 15;
  st_var_3_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((sec_r000933_1_1 + pub_r000933_0_1) + 23) & 127;
  int sub_step_148_2 = ((sec_r000933_1_2 + pub_r000933_0_2) + 23) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000933_20_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000933_20_2) & 127;
  st_var_0_1.buffer[1] = stage_v_148_1 & 15;
  st_var_0_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sec_r000933_14_1 + pub_r000933_13_1) + 32) & 127;
  int sub_step_149_2 = ((sec_r000933_14_2 + pub_r000933_13_2) + 32) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000933_7_2) & 127;
  st_var_1_1.buffer[2] = stage_v_149_1 & 15;
  st_var_1_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((stage_v_105_1 + pub_r000933_6_1) + 34) & 127;
  int sub_step_150_2 = ((stage_v_105_2 + pub_r000933_6_2) + 34) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000933_16_2) & 127;
  st_var_2_1.buffer[0] = stage_v_150_1 & 15;
  st_var_2_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((sec_r000933_19_1 + pub_r000933_7_1) + 17) & 127;
  int sub_step_151_2 = ((sec_r000933_19_2 + pub_r000933_7_2) + 17) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000933_2_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000933_2_2) & 127;
  st_var_3_1.buffer[1] = stage_v_151_1 & 15;
  st_var_3_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((sec_r000933_5_1 + pub_r000933_9_1) + 21) & 127;
  int sub_step_152_2 = ((sec_r000933_5_2 + pub_r000933_9_2) + 21) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000933_16_2) & 127;
  st_var_0_1.buffer[2] = stage_v_152_1 & 15;
  st_var_0_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((stage_v_77_1 + pub_r000933_12_1) + 27) & 127;
  int sub_step_153_2 = ((stage_v_77_2 + pub_r000933_12_2) + 27) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000933_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_153_1 & 15;
  st_var_1_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((sub_step_112_1 + pub_r000933_3_1) + 18) & 127;
  int sub_step_154_2 = ((sub_step_112_2 + pub_r000933_3_2) + 18) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000933_6_2) & 127;
  st_var_2_1.buffer[1] = stage_v_154_1 & 15;
  st_var_2_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((sec_r000933_21_1 + pub_r000933_18_1) + 31) & 127;
  int sub_step_155_2 = ((sec_r000933_21_2 + pub_r000933_18_2) + 31) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000933_0_2) & 127;
  st_var_3_1.buffer[2] = stage_v_155_1 & 15;
  st_var_3_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((stage_v_105_1 + pub_r000933_19_1) + 20) & 127;
  int sub_step_156_2 = ((stage_v_105_2 + pub_r000933_19_2) + 20) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000933_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((sec_r000933_16_1 + pub_r000933_5_1) + 35) & 127;
  int sub_step_157_2 = ((sec_r000933_16_2 + pub_r000933_5_2) + 35) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000933_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((sec_r000933_4_1 + pub_r000933_2_1) + 6) & 127;
  int sub_step_158_2 = ((sec_r000933_4_2 + pub_r000933_2_2) + 6) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000933_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((sec_r000933_11_1 + pub_r000933_9_1) + 24) & 127;
  int sub_step_159_2 = ((sec_r000933_11_2 + pub_r000933_9_2) + 24) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000933_7_2) & 127;
  st_var_3_1.buffer[0] = stage_v_159_1 & 15;
  st_var_3_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((sub_step_96_1 + pub_r000933_20_1) + 18) & 127;
  int sub_step_160_2 = ((sub_step_96_2 + pub_r000933_20_2) + 18) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000933_4_2) & 127;
  st_var_0_1.buffer[1] = stage_v_160_1 & 15;
  st_var_0_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((sub_step_112_1 + pub_r000933_3_1) + 28) & 127;
  int sub_step_161_2 = ((sub_step_112_2 + pub_r000933_3_2) + 28) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000933_2_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000933_2_2) & 127;
  st_var_1_1.buffer[2] = stage_v_161_1 & 15;
  st_var_1_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((sec_r000933_20_1 + pub_r000933_15_1) + 25) & 127;
  int sub_step_162_2 = ((sec_r000933_20_2 + pub_r000933_15_2) + 25) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000933_0_2) & 127;
  st_var_2_1.buffer[0] = stage_v_162_1 & 15;
  st_var_2_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((sec_r000933_15_1 + pub_r000933_2_1) + 32) & 127;
  int sub_step_163_2 = ((sec_r000933_15_2 + pub_r000933_2_2) + 32) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000933_5_2) & 127;
  st_var_3_1.buffer[1] = stage_v_163_1 & 15;
  st_var_3_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((sec_r000933_15_1 + pub_r000933_4_1) + 7) & 127;
  int sub_step_164_2 = ((sec_r000933_15_2 + pub_r000933_4_2) + 7) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000933_5_2) & 127;
  st_var_0_1.buffer[2] = stage_v_164_1 & 15;
  st_var_0_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((stage_v_82_1 + pub_r000933_0_1) + 35) & 127;
  int sub_step_165_2 = ((stage_v_82_2 + pub_r000933_0_2) + 35) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000933_16_2) & 127;
  st_var_1_1.buffer[0] = stage_v_165_1 & 15;
  st_var_1_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((stage_v_103_1 + pub_r000933_1_1) + 28) & 127;
  int sub_step_166_2 = ((stage_v_103_2 + pub_r000933_1_2) + 28) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000933_20_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000933_20_2) & 127;
  st_var_2_1.buffer[1] = stage_v_166_1 & 15;
  st_var_2_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((sec_r000933_12_1 + pub_r000933_15_1) + 7) & 127;
  int sub_step_167_2 = ((sec_r000933_12_2 + pub_r000933_15_2) + 7) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000933_17_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000933_17_2) & 127;
  st_var_3_1.buffer[2] = stage_v_167_1 & 15;
  st_var_3_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((sec_r000933_11_1 + pub_r000933_5_1) + 5) & 127;
  int sub_step_168_2 = ((sec_r000933_11_2 + pub_r000933_5_2) + 5) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000933_18_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((sub_step_135_1 + pub_r000933_12_1) + 28) & 127;
  int sub_step_169_2 = ((sub_step_135_2 + pub_r000933_12_2) + 28) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000933_9_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000933_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((sec_r000933_11_1 + pub_r000933_13_1) + 26) & 127;
  int sub_step_170_2 = ((sec_r000933_11_2 + pub_r000933_13_2) + 26) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000933_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((sub_step_155_1 + pub_r000933_9_1) + 15) & 127;
  int sub_step_171_2 = ((sub_step_155_2 + pub_r000933_9_2) + 15) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000933_7_2) & 127;
  st_var_3_1.buffer[0] = stage_v_171_1 & 15;
  st_var_3_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((sec_r000933_2_1 + pub_r000933_4_1) + 26) & 127;
  int sub_step_172_2 = ((sec_r000933_2_2 + pub_r000933_4_2) + 26) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000933_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_172_1 & 15;
  st_var_0_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((sub_step_81_1 + pub_r000933_16_1) + 18) & 127;
  int sub_step_173_2 = ((sub_step_81_2 + pub_r000933_16_2) + 18) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000933_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_173_1 & 15;
  st_var_1_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((sec_r000933_0_1 + pub_r000933_19_1) + 28) & 127;
  int sub_step_174_2 = ((sec_r000933_0_2 + pub_r000933_19_2) + 28) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000933_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_174_1 & 15;
  st_var_2_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((sub_step_41_1 + pub_r000933_2_1) + 11) & 127;
  int sub_step_175_2 = ((sub_step_41_2 + pub_r000933_2_2) + 11) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000933_15_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000933_15_2) & 127;
  st_var_3_1.buffer[1] = stage_v_175_1 & 15;
  st_var_3_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((sec_r000933_2_1 + pub_r000933_3_1) + 13) & 127;
  int sub_step_176_2 = ((sec_r000933_2_2 + pub_r000933_3_2) + 13) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000933_16_2) & 127;
  st_var_0_1.buffer[2] = stage_v_176_1 & 15;
  st_var_0_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((stage_v_156_1 + pub_r000933_15_1) + 8) & 127;
  int sub_step_177_2 = ((stage_v_156_2 + pub_r000933_15_2) + 8) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000933_1_2) & 127;
  st_var_1_1.buffer[0] = stage_v_177_1 & 15;
  st_var_1_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((sec_r000933_1_1 + pub_r000933_19_1) + 10) & 127;
  int sub_step_178_2 = ((sec_r000933_1_2 + pub_r000933_19_2) + 10) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000933_3_2) & 127;
  st_var_2_1.buffer[1] = stage_v_178_1 & 15;
  st_var_2_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((sec_r000933_9_1 + pub_r000933_3_1) + 34) & 127;
  int sub_step_179_2 = ((sec_r000933_9_2 + pub_r000933_3_2) + 34) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000933_6_2) & 127;
  st_var_3_1.buffer[2] = stage_v_179_1 & 15;
  st_var_3_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((sec_r000933_10_1 + pub_r000933_19_1) + 18) & 127;
  int sub_step_180_2 = ((sec_r000933_10_2 + pub_r000933_19_2) + 18) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000933_15_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000933_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((sub_step_108_1 + pub_r000933_19_1) + 33) & 127;
  int sub_step_181_2 = ((sub_step_108_2 + pub_r000933_19_2) + 33) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000933_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((sub_step_110_1 + pub_r000933_2_1) + 32) & 127;
  int sub_step_182_2 = ((sub_step_110_2 + pub_r000933_2_2) + 32) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000933_19_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000933_19_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((sub_step_102_1 + pub_r000933_5_1) + 24) & 127;
  int sub_step_183_2 = ((sub_step_102_2 + pub_r000933_5_2) + 24) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000933_11_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000933_11_2) & 127;
  st_var_3_1.buffer[0] = stage_v_183_1 & 15;
  st_var_3_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((sub_step_74_1 + pub_r000933_10_1) + 5) & 127;
  int sub_step_184_2 = ((sub_step_74_2 + pub_r000933_10_2) + 5) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000933_20_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000933_20_2) & 127;
  st_var_0_1.buffer[1] = stage_v_184_1 & 15;
  st_var_0_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((sub_step_87_1 + pub_r000933_3_1) + 31) & 127;
  int sub_step_185_2 = ((sub_step_87_2 + pub_r000933_3_2) + 31) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000933_16_2) & 127;
  st_var_1_1.buffer[2] = stage_v_185_1 & 15;
  st_var_1_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((sub_step_137_1 + pub_r000933_13_1) + 14) & 127;
  int sub_step_186_2 = ((sub_step_137_2 + pub_r000933_13_2) + 14) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000933_13_2) & 127;
  st_var_2_1.buffer[0] = stage_v_186_1 & 15;
  st_var_2_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((sub_step_58_1 + pub_r000933_1_1) + 31) & 127;
  int sub_step_187_2 = ((sub_step_58_2 + pub_r000933_1_2) + 31) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000933_18_2) & 127;
  st_var_3_1.buffer[1] = stage_v_187_1 & 15;
  st_var_3_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sub_step_45_1 + pub_r000933_3_1) + 33) & 127;
  int sub_step_188_2 = ((sub_step_45_2 + pub_r000933_3_2) + 33) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000933_10_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000933_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_188_1 & 15;
  st_var_0_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((sec_r000933_4_1 + pub_r000933_0_1) + 13) & 127;
  int sub_step_189_2 = ((sec_r000933_4_2 + pub_r000933_0_2) + 13) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000933_1_2) & 127;
  st_var_1_1.buffer[0] = stage_v_189_1 & 15;
  st_var_1_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((sec_r000933_2_1 + pub_r000933_6_1) + 15) & 127;
  int sub_step_190_2 = ((sec_r000933_2_2 + pub_r000933_6_2) + 15) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000933_7_2) & 127;
  st_var_2_1.buffer[1] = stage_v_190_1 & 15;
  st_var_2_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((sec_r000933_19_1 + pub_r000933_14_1) + 25) & 127;
  int sub_step_191_2 = ((sec_r000933_19_2 + pub_r000933_14_2) + 25) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000933_13_2) & 127;
  st_var_3_1.buffer[2] = stage_v_191_1 & 15;
  st_var_3_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((sub_step_184_1 + pub_r000933_19_1) + 9) & 127;
  int sub_step_192_2 = ((sub_step_184_2 + pub_r000933_19_2) + 9) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000933_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((stage_v_174_1 + pub_r000933_19_1) + 23) & 127;
  int sub_step_193_2 = ((stage_v_174_2 + pub_r000933_19_2) + 23) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000933_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((stage_v_107_1 + pub_r000933_10_1) + 8) & 127;
  int sub_step_194_2 = ((stage_v_107_2 + pub_r000933_10_2) + 8) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000933_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sec_r000933_4_1 + pub_r000933_14_1) + 28) & 127;
  int sub_step_195_2 = ((sec_r000933_4_2 + pub_r000933_14_2) + 28) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000933_7_2) & 127;
  st_var_3_1.buffer[0] = stage_v_195_1 & 15;
  st_var_3_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((stage_v_68_1 + pub_r000933_19_1) + 32) & 127;
  int sub_step_196_2 = ((stage_v_68_2 + pub_r000933_19_2) + 32) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000933_14_2) & 127;
  st_var_0_1.buffer[1] = stage_v_196_1 & 15;
  st_var_0_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((stage_v_95_1 + pub_r000933_19_1) + 5) & 127;
  int sub_step_197_2 = ((stage_v_95_2 + pub_r000933_19_2) + 5) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000933_6_2) & 127;
  st_var_1_1.buffer[2] = stage_v_197_1 & 15;
  st_var_1_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((sub_step_185_1 + pub_r000933_20_1) + 31) & 127;
  int sub_step_198_2 = ((sub_step_185_2 + pub_r000933_20_2) + 31) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000933_14_2) & 127;
  st_var_2_1.buffer[0] = stage_v_198_1 & 15;
  st_var_2_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((sec_r000933_1_1 + pub_r000933_12_1) + 23) & 127;
  int sub_step_199_2 = ((sec_r000933_1_2 + pub_r000933_12_2) + 23) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000933_14_2) & 127;
  st_var_3_1.buffer[1] = stage_v_199_1 & 15;
  st_var_3_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((stage_v_190_1 + pub_r000933_17_1) + 35) & 127;
  int sub_step_200_2 = ((stage_v_190_2 + pub_r000933_17_2) + 35) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000933_7_2) & 127;
  st_var_0_1.buffer[2] = stage_v_200_1 & 15;
  st_var_0_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sub_step_183_1 + pub_r000933_12_1) + 5) & 127;
  int sub_step_201_2 = ((sub_step_183_2 + pub_r000933_12_2) + 5) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000933_16_2) & 127;
  st_var_1_1.buffer[0] = stage_v_201_1 & 15;
  st_var_1_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((sub_step_130_1 + pub_r000933_0_1) + 25) & 127;
  int sub_step_202_2 = ((sub_step_130_2 + pub_r000933_0_2) + 25) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000933_12_2) & 127;
  st_var_2_1.buffer[1] = stage_v_202_1 & 15;
  st_var_2_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((sec_r000933_19_1 + pub_r000933_6_1) + 8) & 127;
  int sub_step_203_2 = ((sec_r000933_19_2 + pub_r000933_6_2) + 8) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000933_19_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000933_19_2) & 127;
  st_var_3_1.buffer[2] = stage_v_203_1 & 15;
  st_var_3_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((sec_r000933_21_1 + pub_r000933_6_1) + 13) & 127;
  int sub_step_204_2 = ((sec_r000933_21_2 + pub_r000933_6_2) + 13) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000933_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((stage_v_49_1 + pub_r000933_6_1) + 29) & 127;
  int sub_step_205_2 = ((stage_v_49_2 + pub_r000933_6_2) + 29) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000933_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((sec_r000933_0_1 + pub_r000933_15_1) + 27) & 127;
  int sub_step_206_2 = ((sec_r000933_0_2 + pub_r000933_15_2) + 27) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000933_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((sec_r000933_19_1 + pub_r000933_19_1) + 30) & 127;
  int sub_step_207_2 = ((sec_r000933_19_2 + pub_r000933_19_2) + 30) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000933_14_2) & 127;
  st_var_3_1.buffer[0] = stage_v_207_1 & 15;
  st_var_3_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((stage_v_41_1 + pub_r000933_5_1) + 21) & 127;
  int sub_step_208_2 = ((stage_v_41_2 + pub_r000933_5_2) + 21) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000933_4_2) & 127;
  st_var_0_1.buffer[1] = stage_v_208_1 & 15;
  st_var_0_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((sec_r000933_11_1 + pub_r000933_13_1) + 12) & 127;
  int sub_step_209_2 = ((sec_r000933_11_2 + pub_r000933_13_2) + 12) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000933_8_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000933_8_2) & 127;
  st_var_1_1.buffer[2] = stage_v_209_1 & 15;
  st_var_1_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((sub_step_87_1 + pub_r000933_14_1) + 21) & 127;
  int sub_step_210_2 = ((sub_step_87_2 + pub_r000933_14_2) + 21) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000933_4_2) & 127;
  st_var_2_1.buffer[0] = stage_v_210_1 & 15;
  st_var_2_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sec_r000933_3_1 + pub_r000933_6_1) + 25) & 127;
  int sub_step_211_2 = ((sec_r000933_3_2 + pub_r000933_6_2) + 25) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000933_0_2) & 127;
  st_var_3_1.buffer[1] = stage_v_211_1 & 15;
  st_var_3_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((sub_step_39_1 + pub_r000933_20_1) + 16) & 127;
  int sub_step_212_2 = ((sub_step_39_2 + pub_r000933_20_2) + 16) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000933_18_2) & 127;
  st_var_0_1.buffer[2] = stage_v_212_1 & 15;
  st_var_0_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((sec_r000933_21_1 + pub_r000933_7_1) + 35) & 127;
  int sub_step_213_2 = ((sec_r000933_21_2 + pub_r000933_7_2) + 35) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000933_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_213_1 & 15;
  st_var_1_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((stage_v_73_1 + pub_r000933_1_1) + 12) & 127;
  int sub_step_214_2 = ((stage_v_73_2 + pub_r000933_1_2) + 12) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000933_12_2) & 127;
  st_var_2_1.buffer[1] = stage_v_214_1 & 15;
  st_var_2_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((sec_r000933_6_1 + pub_r000933_16_1) + 34) & 127;
  int sub_step_215_2 = ((sec_r000933_6_2 + pub_r000933_16_2) + 34) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000933_11_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000933_11_2) & 127;
  st_var_3_1.buffer[2] = stage_v_215_1 & 15;
  st_var_3_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((sec_r000933_19_1 + pub_r000933_2_1) + 8) & 127;
  int sub_step_216_2 = ((sec_r000933_19_2 + pub_r000933_2_2) + 8) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000933_10_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000933_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((sec_r000933_18_1 + pub_r000933_18_1) + 21) & 127;
  int sub_step_217_2 = ((sec_r000933_18_2 + pub_r000933_18_2) + 21) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000933_11_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000933_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((stage_v_213_1 + pub_r000933_17_1) + 17) & 127;
  int sub_step_218_2 = ((stage_v_213_2 + pub_r000933_17_2) + 17) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000933_10_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000933_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((stage_v_134_1 + pub_r000933_5_1) + 29) & 127;
  int sub_step_219_2 = ((stage_v_134_2 + pub_r000933_5_2) + 29) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000933_7_2) & 127;
  st_var_3_1.buffer[0] = stage_v_219_1 & 15;
  st_var_3_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((stage_v_219_1 + pub_r000933_14_1) + 9) & 127;
  int sub_step_220_2 = ((stage_v_219_2 + pub_r000933_14_2) + 9) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000933_12_2) & 127;
  st_var_0_1.buffer[1] = stage_v_220_1 & 15;
  st_var_0_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((sub_step_140_1 + pub_r000933_11_1) + 24) & 127;
  int sub_step_221_2 = ((sub_step_140_2 + pub_r000933_11_2) + 24) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000933_3_2) & 127;
  st_var_1_1.buffer[2] = stage_v_221_1 & 15;
  st_var_1_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((sec_r000933_7_1 + pub_r000933_3_1) + 18) & 127;
  int sub_step_222_2 = ((sec_r000933_7_2 + pub_r000933_3_2) + 18) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000933_15_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000933_15_2) & 127;
  st_var_2_1.buffer[0] = stage_v_222_1 & 15;
  st_var_2_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((sec_r000933_17_1 + pub_r000933_0_1) + 32) & 127;
  int sub_step_223_2 = ((sec_r000933_17_2 + pub_r000933_0_2) + 32) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000933_20_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000933_20_2) & 127;
  st_var_3_1.buffer[1] = stage_v_223_1 & 15;
  st_var_3_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((sub_step_195_1 + pub_r000933_16_1) + 8) & 127;
  int sub_step_224_2 = ((sub_step_195_2 + pub_r000933_16_2) + 8) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000933_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_224_1 & 15;
  st_var_0_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((sec_r000933_16_1 + pub_r000933_3_1) + 25) & 127;
  int sub_step_225_2 = ((sec_r000933_16_2 + pub_r000933_3_2) + 25) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000933_18_2) & 127;
  st_var_1_1.buffer[0] = stage_v_225_1 & 15;
  st_var_1_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sec_r000933_6_1 + pub_r000933_12_1) + 19) & 127;
  int sub_step_226_2 = ((sec_r000933_6_2 + pub_r000933_12_2) + 19) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000933_6_2) & 127;
  st_var_2_1.buffer[1] = stage_v_226_1 & 15;
  st_var_2_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((sub_step_83_1 + pub_r000933_10_1) + 20) & 127;
  int sub_step_227_2 = ((sub_step_83_2 + pub_r000933_10_2) + 20) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000933_10_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000933_10_2) & 127;
  st_var_3_1.buffer[2] = stage_v_227_1 & 15;
  st_var_3_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((stage_v_102_1 + pub_r000933_7_1) + 19) & 127;
  int sub_step_228_2 = ((stage_v_102_2 + pub_r000933_7_2) + 19) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000933_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((stage_v_165_1 + pub_r000933_2_1) + 6) & 127;
  int sub_step_229_2 = ((stage_v_165_2 + pub_r000933_2_2) + 6) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000933_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((stage_v_63_1 + pub_r000933_0_1) + 28) & 127;
  int sub_step_230_2 = ((stage_v_63_2 + pub_r000933_0_2) + 28) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000933_18_2) & 127;
  st_var_2_1.buffer[2] = stage_v_230_1 & 15;
  st_var_2_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int sub_step_231_1 = ((stage_v_134_1 + pub_r000933_2_1) + 19) & 127;
  int sub_step_231_2 = ((stage_v_134_2 + pub_r000933_2_2) + 19) & 127;
  int stage_v_231_1 = ((sub_step_231_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_231_2 = ((sub_step_231_2 * 2) + pub_r000933_12_2) & 127;
  st_var_3_1.buffer[0] = stage_v_231_1 & 15;
  st_var_3_2.buffer[0] = stage_v_231_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int sub_step_232_1 = ((sub_step_80_1 + pub_r000933_13_1) + 22) & 127;
  int sub_step_232_2 = ((sub_step_80_2 + pub_r000933_13_2) + 22) & 127;
  int stage_v_232_1 = ((sub_step_232_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_232_2 = ((sub_step_232_2 * 2) + pub_r000933_0_2) & 127;
  st_var_0_1.buffer[1] = stage_v_232_1 & 15;
  st_var_0_2.buffer[1] = stage_v_232_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int sub_step_233_1 = ((stage_v_80_1 + pub_r000933_19_1) + 24) & 127;
  int sub_step_233_2 = ((stage_v_80_2 + pub_r000933_19_2) + 24) & 127;
  int stage_v_233_1 = ((sub_step_233_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_233_2 = ((sub_step_233_2 * 2) + pub_r000933_4_2) & 127;
  st_var_1_1.buffer[2] = stage_v_233_1 & 15;
  st_var_1_2.buffer[2] = stage_v_233_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int sub_step_234_1 = ((sub_step_129_1 + pub_r000933_13_1) + 9) & 127;
  int sub_step_234_2 = ((sub_step_129_2 + pub_r000933_13_2) + 9) & 127;
  int stage_v_234_1 = ((sub_step_234_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_234_2 = ((sub_step_234_2 * 2) + pub_r000933_13_2) & 127;
  st_var_2_1.buffer[0] = stage_v_234_1 & 15;
  st_var_2_2.buffer[0] = stage_v_234_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int sub_step_235_1 = ((sec_r000933_13_1 + pub_r000933_4_1) + 23) & 127;
  int sub_step_235_2 = ((sec_r000933_13_2 + pub_r000933_4_2) + 23) & 127;
  int stage_v_235_1 = ((sub_step_235_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_235_2 = ((sub_step_235_2 * 2) + pub_r000933_5_2) & 127;
  st_var_3_1.buffer[1] = stage_v_235_1 & 15;
  st_var_3_2.buffer[1] = stage_v_235_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int sub_step_236_1 = ((stage_v_209_1 + pub_r000933_1_1) + 14) & 127;
  int sub_step_236_2 = ((stage_v_209_2 + pub_r000933_1_2) + 14) & 127;
  int stage_v_236_1 = ((sub_step_236_1 * 2) + pub_r000933_11_1) & 127;
  int stage_v_236_2 = ((sub_step_236_2 * 2) + pub_r000933_11_2) & 127;
  st_var_0_1.buffer[2] = stage_v_236_1 & 15;
  st_var_0_2.buffer[2] = stage_v_236_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int sub_step_237_1 = ((stage_v_86_1 + pub_r000933_10_1) + 29) & 127;
  int sub_step_237_2 = ((stage_v_86_2 + pub_r000933_10_2) + 29) & 127;
  int stage_v_237_1 = ((sub_step_237_1 * 2) + pub_r000933_9_1) & 127;
  int stage_v_237_2 = ((sub_step_237_2 * 2) + pub_r000933_9_2) & 127;
  st_var_1_1.buffer[0] = stage_v_237_1 & 15;
  st_var_1_2.buffer[0] = stage_v_237_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int sub_step_238_1 = ((stage_v_109_1 + pub_r000933_20_1) + 12) & 127;
  int sub_step_238_2 = ((stage_v_109_2 + pub_r000933_20_2) + 12) & 127;
  int stage_v_238_1 = ((sub_step_238_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_238_2 = ((sub_step_238_2 * 2) + pub_r000933_18_2) & 127;
  st_var_2_1.buffer[1] = stage_v_238_1 & 15;
  st_var_2_2.buffer[1] = stage_v_238_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int sub_step_239_1 = ((sec_r000933_0_1 + pub_r000933_6_1) + 34) & 127;
  int sub_step_239_2 = ((sec_r000933_0_2 + pub_r000933_6_2) + 34) & 127;
  int stage_v_239_1 = ((sub_step_239_1 * 2) + pub_r000933_12_1) & 127;
  int stage_v_239_2 = ((sub_step_239_2 * 2) + pub_r000933_12_2) & 127;
  st_var_3_1.buffer[2] = stage_v_239_1 & 15;
  st_var_3_2.buffer[2] = stage_v_239_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int sub_step_240_1 = ((sub_step_235_1 + pub_r000933_9_1) + 28) & 127;
  int sub_step_240_2 = ((sub_step_235_2 + pub_r000933_9_2) + 28) & 127;
  int stage_v_240_1 = ((sub_step_240_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_240_2 = ((sub_step_240_2 * 2) + pub_r000933_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_240_1 & 15;
  st_var_0_2.buffer[0] = stage_v_240_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int sub_step_241_1 = ((stage_v_47_1 + pub_r000933_11_1) + 7) & 127;
  int sub_step_241_2 = ((stage_v_47_2 + pub_r000933_11_2) + 7) & 127;
  int stage_v_241_1 = ((sub_step_241_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_241_2 = ((sub_step_241_2 * 2) + pub_r000933_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_241_1 & 15;
  st_var_1_2.buffer[1] = stage_v_241_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int sub_step_242_1 = ((sub_step_46_1 + pub_r000933_12_1) + 22) & 127;
  int sub_step_242_2 = ((sub_step_46_2 + pub_r000933_12_2) + 22) & 127;
  int stage_v_242_1 = ((sub_step_242_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_242_2 = ((sub_step_242_2 * 2) + pub_r000933_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_242_1 & 15;
  st_var_2_2.buffer[2] = stage_v_242_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int sub_step_243_1 = ((sub_step_178_1 + pub_r000933_17_1) + 22) & 127;
  int sub_step_243_2 = ((sub_step_178_2 + pub_r000933_17_2) + 22) & 127;
  int stage_v_243_1 = ((sub_step_243_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_243_2 = ((sub_step_243_2 * 2) + pub_r000933_14_2) & 127;
  st_var_3_1.buffer[0] = stage_v_243_1 & 15;
  st_var_3_2.buffer[0] = stage_v_243_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int sub_step_244_1 = ((sec_r000933_18_1 + pub_r000933_1_1) + 30) & 127;
  int sub_step_244_2 = ((sec_r000933_18_2 + pub_r000933_1_2) + 30) & 127;
  int stage_v_244_1 = ((sub_step_244_1 * 2) + pub_r000933_2_1) & 127;
  int stage_v_244_2 = ((sub_step_244_2 * 2) + pub_r000933_2_2) & 127;
  st_var_0_1.buffer[1] = stage_v_244_1 & 15;
  st_var_0_2.buffer[1] = stage_v_244_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int sub_step_245_1 = ((sec_r000933_18_1 + pub_r000933_16_1) + 18) & 127;
  int sub_step_245_2 = ((sec_r000933_18_2 + pub_r000933_16_2) + 18) & 127;
  int stage_v_245_1 = ((sub_step_245_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_245_2 = ((sub_step_245_2 * 2) + pub_r000933_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_245_1 & 15;
  st_var_1_2.buffer[2] = stage_v_245_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int sub_step_246_1 = ((sec_r000933_2_1 + pub_r000933_4_1) + 5) & 127;
  int sub_step_246_2 = ((sec_r000933_2_2 + pub_r000933_4_2) + 5) & 127;
  int stage_v_246_1 = ((sub_step_246_1 * 2) + pub_r000933_14_1) & 127;
  int stage_v_246_2 = ((sub_step_246_2 * 2) + pub_r000933_14_2) & 127;
  st_var_2_1.buffer[0] = stage_v_246_1 & 15;
  st_var_2_2.buffer[0] = stage_v_246_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int sub_step_247_1 = ((sub_step_153_1 + pub_r000933_8_1) + 26) & 127;
  int sub_step_247_2 = ((sub_step_153_2 + pub_r000933_8_2) + 26) & 127;
  int stage_v_247_1 = ((sub_step_247_1 * 2) + pub_r000933_6_1) & 127;
  int stage_v_247_2 = ((sub_step_247_2 * 2) + pub_r000933_6_2) & 127;
  st_var_3_1.buffer[1] = stage_v_247_1 & 15;
  st_var_3_2.buffer[1] = stage_v_247_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int sub_step_248_1 = ((stage_v_239_1 + pub_r000933_1_1) + 29) & 127;
  int sub_step_248_2 = ((stage_v_239_2 + pub_r000933_1_2) + 29) & 127;
  int stage_v_248_1 = ((sub_step_248_1 * 2) + pub_r000933_1_1) & 127;
  int stage_v_248_2 = ((sub_step_248_2 * 2) + pub_r000933_1_2) & 127;
  st_var_0_1.buffer[2] = stage_v_248_1 & 15;
  st_var_0_2.buffer[2] = stage_v_248_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int sub_step_249_1 = ((sec_r000933_16_1 + pub_r000933_9_1) + 9) & 127;
  int sub_step_249_2 = ((sec_r000933_16_2 + pub_r000933_9_2) + 9) & 127;
  int stage_v_249_1 = ((sub_step_249_1 * 2) + pub_r000933_13_1) & 127;
  int stage_v_249_2 = ((sub_step_249_2 * 2) + pub_r000933_13_2) & 127;
  st_var_1_1.buffer[0] = stage_v_249_1 & 15;
  st_var_1_2.buffer[0] = stage_v_249_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int sub_step_250_1 = ((stage_v_240_1 + pub_r000933_4_1) + 10) & 127;
  int sub_step_250_2 = ((stage_v_240_2 + pub_r000933_4_2) + 10) & 127;
  int stage_v_250_1 = ((sub_step_250_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_250_2 = ((sub_step_250_2 * 2) + pub_r000933_3_2) & 127;
  st_var_2_1.buffer[1] = stage_v_250_1 & 15;
  st_var_2_2.buffer[1] = stage_v_250_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int sub_step_251_1 = ((sec_r000933_4_1 + pub_r000933_9_1) + 24) & 127;
  int sub_step_251_2 = ((sec_r000933_4_2 + pub_r000933_9_2) + 24) & 127;
  int stage_v_251_1 = ((sub_step_251_1 * 2) + pub_r000933_15_1) & 127;
  int stage_v_251_2 = ((sub_step_251_2 * 2) + pub_r000933_15_2) & 127;
  st_var_3_1.buffer[2] = stage_v_251_1 & 15;
  st_var_3_2.buffer[2] = stage_v_251_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int sub_step_252_1 = ((sub_step_115_1 + pub_r000933_12_1) + 19) & 127;
  int sub_step_252_2 = ((sub_step_115_2 + pub_r000933_12_2) + 19) & 127;
  int stage_v_252_1 = ((sub_step_252_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_252_2 = ((sub_step_252_2 * 2) + pub_r000933_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_252_1 & 15;
  st_var_0_2.buffer[0] = stage_v_252_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int sub_step_253_1 = ((sub_step_134_1 + pub_r000933_3_1) + 25) & 127;
  int sub_step_253_2 = ((sub_step_134_2 + pub_r000933_3_2) + 25) & 127;
  int stage_v_253_1 = ((sub_step_253_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_253_2 = ((sub_step_253_2 * 2) + pub_r000933_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_253_1 & 15;
  st_var_1_2.buffer[1] = stage_v_253_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int sub_step_254_1 = ((stage_v_188_1 + pub_r000933_6_1) + 9) & 127;
  int sub_step_254_2 = ((stage_v_188_2 + pub_r000933_6_2) + 9) & 127;
  int stage_v_254_1 = ((sub_step_254_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_254_2 = ((sub_step_254_2 * 2) + pub_r000933_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_254_1 & 15;
  st_var_2_2.buffer[2] = stage_v_254_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int sub_step_255_1 = ((sub_step_76_1 + pub_r000933_19_1) + 5) & 127;
  int sub_step_255_2 = ((sub_step_76_2 + pub_r000933_19_2) + 5) & 127;
  int stage_v_255_1 = ((sub_step_255_1 * 2) + pub_r000933_19_1) & 127;
  int stage_v_255_2 = ((sub_step_255_2 * 2) + pub_r000933_19_2) & 127;
  st_var_3_1.buffer[0] = stage_v_255_1 & 15;
  st_var_3_2.buffer[0] = stage_v_255_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int sub_step_256_1 = ((stage_v_183_1 + pub_r000933_14_1) + 29) & 127;
  int sub_step_256_2 = ((stage_v_183_2 + pub_r000933_14_2) + 29) & 127;
  int stage_v_256_1 = ((sub_step_256_1 * 2) + pub_r000933_11_1) & 127;
  int stage_v_256_2 = ((sub_step_256_2 * 2) + pub_r000933_11_2) & 127;
  st_var_0_1.buffer[1] = stage_v_256_1 & 15;
  st_var_0_2.buffer[1] = stage_v_256_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int sub_step_257_1 = ((stage_v_178_1 + pub_r000933_11_1) + 26) & 127;
  int sub_step_257_2 = ((stage_v_178_2 + pub_r000933_11_2) + 26) & 127;
  int stage_v_257_1 = ((sub_step_257_1 * 2) + pub_r000933_7_1) & 127;
  int stage_v_257_2 = ((sub_step_257_2 * 2) + pub_r000933_7_2) & 127;
  st_var_1_1.buffer[2] = stage_v_257_1 & 15;
  st_var_1_2.buffer[2] = stage_v_257_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int sub_step_258_1 = ((stage_v_76_1 + pub_r000933_3_1) + 24) & 127;
  int sub_step_258_2 = ((stage_v_76_2 + pub_r000933_3_2) + 24) & 127;
  int stage_v_258_1 = ((sub_step_258_1 * 2) + pub_r000933_3_1) & 127;
  int stage_v_258_2 = ((sub_step_258_2 * 2) + pub_r000933_3_2) & 127;
  st_var_2_1.buffer[0] = stage_v_258_1 & 15;
  st_var_2_2.buffer[0] = stage_v_258_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int sub_step_259_1 = ((sec_r000933_15_1 + pub_r000933_12_1) + 31) & 127;
  int sub_step_259_2 = ((sec_r000933_15_2 + pub_r000933_12_2) + 31) & 127;
  int stage_v_259_1 = ((sub_step_259_1 * 2) + pub_r000933_10_1) & 127;
  int stage_v_259_2 = ((sub_step_259_2 * 2) + pub_r000933_10_2) & 127;
  st_var_3_1.buffer[1] = stage_v_259_1 & 15;
  st_var_3_2.buffer[1] = stage_v_259_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int sub_step_260_1 = ((sec_r000933_12_1 + pub_r000933_16_1) + 11) & 127;
  int sub_step_260_2 = ((sec_r000933_12_2 + pub_r000933_16_2) + 11) & 127;
  int stage_v_260_1 = ((sub_step_260_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_260_2 = ((sub_step_260_2 * 2) + pub_r000933_5_2) & 127;
  st_var_0_1.buffer[2] = stage_v_260_1 & 15;
  st_var_0_2.buffer[2] = stage_v_260_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int sub_step_261_1 = ((stage_v_48_1 + pub_r000933_17_1) + 9) & 127;
  int sub_step_261_2 = ((stage_v_48_2 + pub_r000933_17_2) + 9) & 127;
  int stage_v_261_1 = ((sub_step_261_1 * 2) + pub_r000933_18_1) & 127;
  int stage_v_261_2 = ((sub_step_261_2 * 2) + pub_r000933_18_2) & 127;
  st_var_1_1.buffer[0] = stage_v_261_1 & 15;
  st_var_1_2.buffer[0] = stage_v_261_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int sub_step_262_1 = ((stage_v_54_1 + pub_r000933_16_1) + 21) & 127;
  int sub_step_262_2 = ((stage_v_54_2 + pub_r000933_16_2) + 21) & 127;
  int stage_v_262_1 = ((sub_step_262_1 * 2) + pub_r000933_20_1) & 127;
  int stage_v_262_2 = ((sub_step_262_2 * 2) + pub_r000933_20_2) & 127;
  st_var_2_1.buffer[1] = stage_v_262_1 & 15;
  st_var_2_2.buffer[1] = stage_v_262_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int sub_step_263_1 = ((sub_step_184_1 + pub_r000933_3_1) + 27) & 127;
  int sub_step_263_2 = ((sub_step_184_2 + pub_r000933_3_2) + 27) & 127;
  int stage_v_263_1 = ((sub_step_263_1 * 2) + pub_r000933_17_1) & 127;
  int stage_v_263_2 = ((sub_step_263_2 * 2) + pub_r000933_17_2) & 127;
  st_var_3_1.buffer[2] = stage_v_263_1 & 15;
  st_var_3_2.buffer[2] = stage_v_263_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int sub_step_264_1 = ((sub_step_135_1 + pub_r000933_17_1) + 29) & 127;
  int sub_step_264_2 = ((sub_step_135_2 + pub_r000933_17_2) + 29) & 127;
  int stage_v_264_1 = ((sub_step_264_1 * 2) + pub_r000933_16_1) & 127;
  int stage_v_264_2 = ((sub_step_264_2 * 2) + pub_r000933_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_264_1 & 15;
  st_var_0_2.buffer[0] = stage_v_264_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int sub_step_265_1 = ((sec_r000933_21_1 + pub_r000933_11_1) + 8) & 127;
  int sub_step_265_2 = ((sec_r000933_21_2 + pub_r000933_11_2) + 8) & 127;
  int stage_v_265_1 = ((sub_step_265_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_265_2 = ((sub_step_265_2 * 2) + pub_r000933_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_265_1 & 15;
  st_var_1_2.buffer[1] = stage_v_265_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int sub_step_266_1 = ((stage_v_201_1 + pub_r000933_15_1) + 30) & 127;
  int sub_step_266_2 = ((stage_v_201_2 + pub_r000933_15_2) + 30) & 127;
  int stage_v_266_1 = ((sub_step_266_1 * 2) + pub_r000933_4_1) & 127;
  int stage_v_266_2 = ((sub_step_266_2 * 2) + pub_r000933_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_266_1 & 15;
  st_var_2_2.buffer[2] = stage_v_266_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int sub_step_267_1 = ((sec_r000933_17_1 + pub_r000933_4_1) + 5) & 127;
  int sub_step_267_2 = ((sec_r000933_17_2 + pub_r000933_4_2) + 5) & 127;
  int stage_v_267_1 = ((sub_step_267_1 * 2) + pub_r000933_9_1) & 127;
  int stage_v_267_2 = ((sub_step_267_2 * 2) + pub_r000933_9_2) & 127;
  st_var_3_1.buffer[0] = stage_v_267_1 & 15;
  st_var_3_2.buffer[0] = stage_v_267_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int sub_step_268_1 = ((stage_v_58_1 + pub_r000933_3_1) + 34) & 127;
  int sub_step_268_2 = ((stage_v_58_2 + pub_r000933_3_2) + 34) & 127;
  int stage_v_268_1 = ((sub_step_268_1 * 2) + pub_r000933_5_1) & 127;
  int stage_v_268_2 = ((sub_step_268_2 * 2) + pub_r000933_5_2) & 127;
  st_var_0_1.buffer[1] = stage_v_268_1 & 15;
  st_var_0_2.buffer[1] = stage_v_268_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int sub_step_269_1 = ((sub_step_114_1 + pub_r000933_19_1) + 7) & 127;
  int sub_step_269_2 = ((sub_step_114_2 + pub_r000933_19_2) + 7) & 127;
  int stage_v_269_1 = ((sub_step_269_1 * 2) + pub_r000933_0_1) & 127;
  int stage_v_269_2 = ((sub_step_269_2 * 2) + pub_r000933_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_269_1 & 15;
  st_var_1_2.buffer[2] = stage_v_269_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000933_18_1 != sec_r000933_18_2);
  __CPROVER_assume(pub_r000933_14_1 == pub_r000933_14_2);
  __CPROVER_assume(sec_r000933_12_1 != sec_r000933_12_2);
  __CPROVER_assume(sec_r000933_6_1 != sec_r000933_6_2);
  __CPROVER_assume(pub_r000933_11_1 == pub_r000933_11_2);
  __CPROVER_assume(sec_r000933_1_1 != sec_r000933_1_2);
  __CPROVER_assume(sec_r000933_3_1 != sec_r000933_3_2);
  __CPROVER_assume(sec_r000933_19_1 != sec_r000933_19_2);
  __CPROVER_assume(pub_r000933_18_1 == pub_r000933_18_2);
  __CPROVER_assume(sec_r000933_2_1 != sec_r000933_2_2);
  __CPROVER_assume(pub_r000933_7_1 == pub_r000933_7_2);
  __CPROVER_assume(sec_r000933_20_1 != sec_r000933_20_2);
  __CPROVER_assume(sec_r000933_21_1 != sec_r000933_21_2);
  __CPROVER_assume(pub_r000933_2_1 == pub_r000933_2_2);
  __CPROVER_assume(pub_r000933_1_1 == pub_r000933_1_2);
  __CPROVER_assume(pub_r000933_19_1 == pub_r000933_19_2);
  __CPROVER_assume(sec_r000933_16_1 != sec_r000933_16_2);
  __CPROVER_assume(sec_r000933_15_1 != sec_r000933_15_2);
  __CPROVER_assume(pub_r000933_20_1 == pub_r000933_20_2);
  __CPROVER_assume(pub_r000933_6_1 == pub_r000933_6_2);
  __CPROVER_assume(pub_r000933_4_1 == pub_r000933_4_2);
  __CPROVER_assume(sec_r000933_7_1 != sec_r000933_7_2);
  __CPROVER_assume(pub_r000933_17_1 == pub_r000933_17_2);
  __CPROVER_assume(sec_r000933_8_1 != sec_r000933_8_2);
  __CPROVER_assume(sec_r000933_14_1 != sec_r000933_14_2);
  __CPROVER_assume(pub_r000933_9_1 == pub_r000933_9_2);
  __CPROVER_assume(pub_r000933_13_1 == pub_r000933_13_2);
  __CPROVER_assume(pub_r000933_3_1 == pub_r000933_3_2);
  __CPROVER_assume(sec_r000933_13_1 != sec_r000933_13_2);
  __CPROVER_assume(sec_r000933_5_1 != sec_r000933_5_2);
  __CPROVER_assume(pub_r000933_5_1 == pub_r000933_5_2);
  __CPROVER_assume(pub_r000933_10_1 == pub_r000933_10_2);
  __CPROVER_assume(sec_r000933_17_1 != sec_r000933_17_2);
  __CPROVER_assume(pub_r000933_16_1 == pub_r000933_16_2);
  __CPROVER_assume(sec_r000933_4_1 != sec_r000933_4_2);
  __CPROVER_assume(sec_r000933_11_1 != sec_r000933_11_2);
  __CPROVER_assume(sec_r000933_0_1 != sec_r000933_0_2);
  __CPROVER_assume(pub_r000933_15_1 == pub_r000933_15_2);
  __CPROVER_assume(pub_r000933_0_1 == pub_r000933_0_2);
  __CPROVER_assume(pub_r000933_8_1 == pub_r000933_8_2);
  __CPROVER_assume(sec_r000933_10_1 != sec_r000933_10_2);
  __CPROVER_assume(sec_r000933_9_1 != sec_r000933_9_2);
  __CPROVER_assume(pub_r000933_12_1 == pub_r000933_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
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
  assert(sub_step_37_1 == sub_step_37_2);
  assert(stage_v_37_1 == stage_v_37_2);
  assert(sub_step_38_1 == sub_step_38_2);
  assert(stage_v_38_1 == stage_v_38_2);
  assert(sub_step_39_1 == sub_step_39_2);
  assert(stage_v_39_1 == stage_v_39_2);
  assert(sub_step_40_1 == sub_step_40_2);
  assert(stage_v_40_1 == stage_v_40_2);
  assert(sub_step_41_1 == sub_step_41_2);
  assert(stage_v_41_1 == stage_v_41_2);
  assert(sub_step_42_1 == sub_step_42_2);
  assert(stage_v_42_1 == stage_v_42_2);
  assert(sub_step_43_1 == sub_step_43_2);
  assert(stage_v_43_1 == stage_v_43_2);
  assert(sub_step_44_1 == sub_step_44_2);
  assert(stage_v_44_1 == stage_v_44_2);
  assert(sub_step_45_1 == sub_step_45_2);
  assert(stage_v_45_1 == stage_v_45_2);
  assert(sub_step_46_1 == sub_step_46_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(sub_step_47_1 == sub_step_47_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(sub_step_48_1 == sub_step_48_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(sub_step_49_1 == sub_step_49_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(sub_step_50_1 == sub_step_50_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(sub_step_51_1 == sub_step_51_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(sub_step_52_1 == sub_step_52_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(sub_step_53_1 == sub_step_53_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(sub_step_54_1 == sub_step_54_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(sub_step_55_1 == sub_step_55_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(sub_step_56_1 == sub_step_56_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(sub_step_57_1 == sub_step_57_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(sub_step_58_1 == sub_step_58_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(sub_step_59_1 == sub_step_59_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(sub_step_60_1 == sub_step_60_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(sub_step_61_1 == sub_step_61_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(sub_step_62_1 == sub_step_62_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(sub_step_63_1 == sub_step_63_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(sub_step_64_1 == sub_step_64_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(sub_step_65_1 == sub_step_65_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(sub_step_66_1 == sub_step_66_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(sub_step_67_1 == sub_step_67_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(sub_step_68_1 == sub_step_68_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(sub_step_69_1 == sub_step_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(sub_step_70_1 == sub_step_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(sub_step_71_1 == sub_step_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(sub_step_72_1 == sub_step_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(sub_step_73_1 == sub_step_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(sub_step_74_1 == sub_step_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(sub_step_75_1 == sub_step_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(sub_step_76_1 == sub_step_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(sub_step_77_1 == sub_step_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(sub_step_78_1 == sub_step_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(sub_step_79_1 == sub_step_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(sub_step_80_1 == sub_step_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(sub_step_81_1 == sub_step_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(sub_step_82_1 == sub_step_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(sub_step_83_1 == sub_step_83_2);
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
  assert(sub_step_241_1 == sub_step_241_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(sub_step_242_1 == sub_step_242_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(sub_step_243_1 == sub_step_243_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(sub_step_244_1 == sub_step_244_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(sub_step_245_1 == sub_step_245_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(sub_step_246_1 == sub_step_246_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(sub_step_247_1 == sub_step_247_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(sub_step_248_1 == sub_step_248_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(sub_step_249_1 == sub_step_249_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(sub_step_250_1 == sub_step_250_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(sub_step_251_1 == sub_step_251_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(sub_step_252_1 == sub_step_252_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(sub_step_253_1 == sub_step_253_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(sub_step_254_1 == sub_step_254_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(sub_step_255_1 == sub_step_255_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(sub_step_256_1 == sub_step_256_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(sub_step_257_1 == sub_step_257_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(sub_step_258_1 == sub_step_258_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(sub_step_259_1 == sub_step_259_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(sub_step_260_1 == sub_step_260_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(sub_step_261_1 == sub_step_261_2);
  assert(stage_v_261_1 == stage_v_261_2);
  assert(sub_step_262_1 == sub_step_262_2);
  assert(stage_v_262_1 == stage_v_262_2);
  assert(sub_step_263_1 == sub_step_263_2);
  assert(stage_v_263_1 == stage_v_263_2);
  assert(sub_step_264_1 == sub_step_264_2);
  assert(stage_v_264_1 == stage_v_264_2);
  assert(sub_step_265_1 == sub_step_265_2);
  assert(stage_v_265_1 == stage_v_265_2);
  assert(sub_step_266_1 == sub_step_266_2);
  assert(stage_v_266_1 == stage_v_266_2);
  assert(sub_step_267_1 == sub_step_267_2);
  assert(stage_v_267_1 == stage_v_267_2);
  assert(sub_step_268_1 == sub_step_268_2);
  assert(stage_v_268_1 == stage_v_268_2);
  assert(sub_step_269_1 == sub_step_269_2);
  assert(stage_v_269_1 == stage_v_269_2);
}


