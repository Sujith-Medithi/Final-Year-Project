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
struct Vector3D_R000553_5313_0
{
  int coord_z;
  int norm_sq;
  int coord_y;
  int coord_x;
  int heading;
  int buffer[3];
};
struct FilterState_R000553_5313_1
{
  int cutoff;
  short gain_db;
  short prev_in;
  int buffer[3];
};
struct MatrixBlock_R000553_5313_2
{
  unsigned char trace;
  short scale;
  int stride;
  int buffer[3];
};
struct AudioFrame_R000553_5313_3
{
  unsigned char channels;
  int peak;
  unsigned char rms;
  int envelope;
  int sample_rate;
  int buffer[3];
};
union TelemetryField_R000553_5313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000553_5313_1
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
void fn_R000553_5313_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st_1 = {0};
  struct AudioFrame_R000553_5313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int mask_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_24_1) & 63;
  aux_2 = (aux_2 + mask_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_34_1 = local_arr_1[aux_1 % 3];
  int metric_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_34_2 * 2)) & 127;
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_24_1 == mask_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_34_1 == metric_34_2);
  assert(parity_47_1 == parity_47_2);
}

int fn_R000553_5313_0(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int mask_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_24) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_34 = local_arr[aux % 3];
  acc = (acc + (metric_34 * 2)) & 127;
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

  return (acc + aux) & 255;
}

void fn_R000553_5313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st_1 = {0};
  struct AudioFrame_R000553_5313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quantum_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_43_1)
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

  switch (quantum_43_2)
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

  int parity_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_24_1 > 27)
  {
    acc_1 = ((acc_1 + (parity_24_1 * 2)) + 5) & 127;
    aux_1 ^= parity_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_24_2 > 27)
  {
    acc_2 = ((acc_2 + (parity_24_2 * 2)) + 5) & 127;
    aux_2 ^= parity_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_26_1) & 63;
  aux_2 = (aux_2 + scale_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_43_1 == quantum_43_2);
  assert(parity_24_1 == parity_24_2);
  assert(scale_26_1 == scale_26_2);
}

int fn_R000553_5313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quantum_43 = (aux + st.buffer[1]) & 3;
  switch (quantum_43)
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

  int parity_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_24 > 27)
  {
    acc = ((acc + (parity_24 * 2)) + 5) & 127;
    aux ^= parity_24 & 15;
  }
  else
  {
    acc = ((acc - parity_24) + 11) & 127;
    aux += 3;
  }
  int scale_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000553_5313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000553_5313_2 st_1 = {0};
  struct MatrixBlock_R000553_5313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int window_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_18_1)
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

  switch (window_18_2)
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

  int tracker_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_78_1) & 63;
  aux_2 = (aux_2 + tracker_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_75_1 > 15)
  {
    acc_1 = ((acc_1 + (margin_75_1 * 2)) + 5) & 127;
    aux_1 ^= margin_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_75_2 > 15)
  {
    acc_2 = ((acc_2 + (margin_75_2 * 2)) + 5) & 127;
    aux_2 ^= margin_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_75_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_18_1 == window_18_2);
  assert(tracker_78_1 == tracker_78_2);
  assert(margin_75_1 == margin_75_2);
}

int fn_R000553_5313_2(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000553_5313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int window_18 = (aux + st.buffer[1]) & 3;
  switch (window_18)
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

  int tracker_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_78) & 63;
  acc ^= aux;
  int margin_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_75 > 15)
  {
    acc = ((acc + (margin_75 * 2)) + 5) & 127;
    aux ^= margin_75 & 15;
  }
  else
  {
    acc = ((acc - margin_75) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st_1 = {0};
  struct FilterState_R000553_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_78_1 > 34)
  {
    acc_1 = ((acc_1 + (margin_78_1 * 2)) + 5) & 127;
    aux_1 ^= margin_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_78_2 > 34)
  {
    acc_2 = ((acc_2 + (margin_78_2 * 2)) + 5) & 127;
    aux_2 ^= margin_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_26_1)
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

  switch (coefficient_26_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_78_1 == margin_78_2);
  assert(coefficient_26_1 == coefficient_26_2);
}

int fn_R000553_5313_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_78 > 34)
  {
    acc = ((acc + (margin_78 * 2)) + 5) & 127;
    aux ^= margin_78 & 15;
  }
  else
  {
    acc = ((acc - margin_78) + 11) & 127;
    aux += 3;
  }
  int coefficient_26 = (aux + st.buffer[1]) & 3;
  switch (coefficient_26)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st_1 = {0};
  struct FilterState_R000553_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int weight_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_35_1) & 63;
  aux_2 = (aux_2 + weight_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_31_1 = local_arr_1[aux_1 % 3];
  int phase_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_35_1 == weight_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_31_1 == phase_31_2);
}

int fn_R000553_5313_4(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int weight_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_31 = local_arr[aux % 3];
  acc = (acc + (phase_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st_1 = {0};
  struct Vector3D_R000553_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_34_1 > 33)
  {
    acc_1 = ((acc_1 + (anchor_34_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_34_2 > 33)
  {
    acc_2 = ((acc_2 + (anchor_34_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_28_1 = local_arr_1[aux_1 % 3];
  int checksum_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_34_1 == anchor_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_28_1 == checksum_28_2);
}

int fn_R000553_5313_5(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_34 > 33)
  {
    acc = ((acc + (anchor_34 * 2)) + 5) & 127;
    aux ^= anchor_34 & 15;
  }
  else
  {
    acc = ((acc - anchor_34) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_28 = local_arr[aux % 3];
  acc = (acc + (checksum_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st_1 = {0};
  struct FilterState_R000553_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int mask_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_70_1) & 63;
  aux_2 = (aux_2 + mask_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_49_1)
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

  switch (factor_49_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_78_1 > 31)
  {
    acc_1 = ((acc_1 + (parity_78_1 * 2)) + 5) & 127;
    aux_1 ^= parity_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_78_2 > 31)
  {
    acc_2 = ((acc_2 + (parity_78_2 * 2)) + 5) & 127;
    aux_2 ^= parity_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_70_1 == mask_70_2);
  assert(factor_49_1 == factor_49_2);
  assert(parity_78_1 == parity_78_2);
}

int fn_R000553_5313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int mask_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_70) & 63;
  acc ^= aux;
  int factor_49 = (aux + st.buffer[1]) & 3;
  switch (factor_49)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_78 > 31)
  {
    acc = ((acc + (parity_78 * 2)) + 5) & 127;
    aux ^= parity_78 & 15;
  }
  else
  {
    acc = ((acc - parity_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000553_5313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000553_5313_2 st_1 = {0};
  struct MatrixBlock_R000553_5313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int delta_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_46_1 > 16)
  {
    acc_1 = ((acc_1 + (delta_46_1 * 2)) + 5) & 127;
    aux_1 ^= delta_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_46_2 > 16)
  {
    acc_2 = ((acc_2 + (delta_46_2 * 2)) + 5) & 127;
    aux_2 ^= delta_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_93_1)
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

  switch (factor_93_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_23_1) & 63;
  aux_2 = (aux_2 + index_reg_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_46_1 == delta_46_2);
  assert(factor_93_1 == factor_93_2);
  assert(index_reg_23_1 == index_reg_23_2);
}

int fn_R000553_5313_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000553_5313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int delta_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_46 > 16)
  {
    acc = ((acc + (delta_46 * 2)) + 5) & 127;
    aux ^= delta_46 & 15;
  }
  else
  {
    acc = ((acc - delta_46) + 11) & 127;
    aux += 3;
  }
  int factor_93 = (aux + st.buffer[1]) & 3;
  switch (factor_93)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000553_5313_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st_1 = {0};
  struct FilterState_R000553_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int factor_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_79_1)
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

  switch (factor_79_2)
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
  int quotient_17_1 = local_arr_1[aux_1 % 3];
  int quotient_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_17_2 * 2)) & 127;
  int quantum_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_35_1 > 28)
  {
    acc_1 = ((acc_1 + (quantum_35_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_35_2 > 28)
  {
    acc_2 = ((acc_2 + (quantum_35_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_79_1 == factor_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_17_1 == quotient_17_2);
  assert(quantum_35_1 == quantum_35_2);
}

int fn_R000553_5313_8(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int factor_79 = (aux + st.buffer[1]) & 3;
  switch (factor_79)
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
  int quotient_17 = local_arr[aux % 3];
  acc = (acc + (quotient_17 * 2)) & 127;
  int quantum_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_35 > 28)
  {
    acc = ((acc + (quantum_35 * 2)) + 5) & 127;
    aux ^= quantum_35 & 15;
  }
  else
  {
    acc = ((acc - quantum_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st_1 = {0};
  struct AudioFrame_R000553_5313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int weight_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_67_1)
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

  switch (weight_67_2)
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

  int sample_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_40_1 > 49)
  {
    acc_1 = ((acc_1 + (sample_40_1 * 2)) + 5) & 127;
    aux_1 ^= sample_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_40_2 > 49)
  {
    acc_2 = ((acc_2 + (sample_40_2 * 2)) + 5) & 127;
    aux_2 ^= sample_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_41_1) & 63;
  aux_2 = (aux_2 + anchor_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_73_1 = local_arr_1[aux_1 % 3];
  int accumulator_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_67_1 == weight_67_2);
  assert(sample_40_1 == sample_40_2);
  assert(anchor_41_1 == anchor_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_73_1 == accumulator_73_2);
}

int fn_R000553_5313_9(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int weight_67 = (aux + st.buffer[1]) & 3;
  switch (weight_67)
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

  int sample_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_40 > 49)
  {
    acc = ((acc + (sample_40 * 2)) + 5) & 127;
    aux ^= sample_40 & 15;
  }
  else
  {
    acc = ((acc - sample_40) + 11) & 127;
    aux += 3;
  }
  int anchor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_73 = local_arr[aux % 3];
  acc = (acc + (accumulator_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st_1 = {0};
  struct FilterState_R000553_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int factor_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_73_1)
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

  switch (factor_73_2)
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

  int phase_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_78_1) & 63;
  aux_2 = (aux_2 + phase_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_71_1 = local_arr_1[aux_1 % 3];
  int window_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_73_1 == factor_73_2);
  assert(phase_78_1 == phase_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_71_1 == window_71_2);
}

int fn_R000553_5313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int factor_73 = (aux + st.buffer[1]) & 3;
  switch (factor_73)
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

  int phase_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_78) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_71 = local_arr[aux % 3];
  acc = (acc + (window_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st_1 = {0};
  struct FilterState_R000553_5313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_75_1) & 63;
  aux_2 = (aux_2 + mask_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_75_1 == mask_75_2);
}

int fn_R000553_5313_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000553_5313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000553_5313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st_1 = {0};
  struct Vector3D_R000553_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_22_1 = local_arr_1[aux_1 % 3];
  int margin_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_22_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_57_1 > 37)
  {
    acc_1 = ((acc_1 + (checksum_57_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_57_2 > 37)
  {
    acc_2 = ((acc_2 + (checksum_57_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_90_1) & 63;
  aux_2 = (aux_2 + anchor_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_22_1 == margin_22_2);
  assert(checksum_57_1 == checksum_57_2);
  assert(anchor_90_1 == anchor_90_2);
}

int fn_R000553_5313_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int margin_22 = local_arr[aux % 3];
  acc = (acc + (margin_22 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_57 > 37)
  {
    acc = ((acc + (checksum_57 * 2)) + 5) & 127;
    aux ^= checksum_57 & 15;
  }
  else
  {
    acc = ((acc - checksum_57) + 11) & 127;
    aux += 3;
  }
  int anchor_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000553_5313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st_1 = {0};
  struct AudioFrame_R000553_5313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_15_1) & 63;
  aux_2 = (aux_2 + cursor_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_32_1 = local_arr_1[aux_1 % 3];
  int checksum_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_32_2 * 2)) & 127;
  int tally_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_36_1)
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

  switch (tally_36_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_15_1 == cursor_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_32_1 == checksum_32_2);
  assert(tally_36_1 == tally_36_2);
}

int fn_R000553_5313_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_15) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_32 = local_arr[aux % 3];
  acc = (acc + (checksum_32 * 2)) & 127;
  int tally_36 = (aux + st.buffer[1]) & 3;
  switch (tally_36)
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

void fn_R000553_5313_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st_1 = {0};
  struct AudioFrame_R000553_5313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_63_1) & 63;
  aux_2 = (aux_2 + quotient_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_80_1)
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

  switch (phase_80_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_63_1 == quotient_63_2);
  assert(phase_80_1 == phase_80_2);
}

int fn_R000553_5313_14(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_63) & 63;
  acc ^= aux;
  int phase_80 = (aux + st.buffer[1]) & 3;
  switch (phase_80)
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

void fn_R000553_5313_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st_1 = {0};
  struct Vector3D_R000553_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_46_1) & 63;
  aux_2 = (aux_2 + delta_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_86_1 = local_arr_1[aux_1 % 3];
  int scale_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_46_1 == delta_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_86_1 == scale_86_2);
}

int fn_R000553_5313_15(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_46) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_86 = local_arr[aux % 3];
  acc = (acc + (scale_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000553_5313_2 st_1 = {0};
  struct MatrixBlock_R000553_5313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int bound_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_67_1 > 13)
  {
    acc_1 = ((acc_1 + (bound_67_1 * 2)) + 5) & 127;
    aux_1 ^= bound_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_67_2 > 13)
  {
    acc_2 = ((acc_2 + (bound_67_2 * 2)) + 5) & 127;
    aux_2 ^= bound_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_28_1) & 63;
  aux_2 = (aux_2 + delta_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_67_1 == bound_67_2);
  assert(delta_28_1 == delta_28_2);
}

int fn_R000553_5313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000553_5313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int bound_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_67 > 13)
  {
    acc = ((acc + (bound_67 * 2)) + 5) & 127;
    aux ^= bound_67 & 15;
  }
  else
  {
    acc = ((acc - bound_67) + 11) & 127;
    aux += 3;
  }
  int delta_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_28) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st_1 = {0};
  struct AudioFrame_R000553_5313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int mask_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_50_1)
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

  switch (mask_50_2)
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

  int pivot_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_29_1) & 63;
  aux_2 = (aux_2 + pivot_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_50_1 == mask_50_2);
  assert(pivot_29_1 == pivot_29_2);
}

int fn_R000553_5313_17(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000553_5313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int mask_50 = (aux + st.buffer[1]) & 3;
  switch (mask_50)
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

  int pivot_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_29) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000553_5313_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st_1 = {0};
  struct Vector3D_R000553_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int delta_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_33_1 > 42)
  {
    acc_1 = ((acc_1 + (delta_33_1 * 2)) + 5) & 127;
    aux_1 ^= delta_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_33_2 > 42)
  {
    acc_2 = ((acc_2 + (delta_33_2 * 2)) + 5) & 127;
    aux_2 ^= delta_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_79_1)
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

  switch (quotient_79_2)
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
  int metric_49_1 = local_arr_1[aux_1 % 3];
  int metric_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_49_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_33_1 == delta_33_2);
  assert(quotient_79_1 == quotient_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_49_1 == metric_49_2);
}

int fn_R000553_5313_18(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int delta_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_33 > 42)
  {
    acc = ((acc + (delta_33 * 2)) + 5) & 127;
    aux ^= delta_33 & 15;
  }
  else
  {
    acc = ((acc - delta_33) + 11) & 127;
    aux += 3;
  }
  int quotient_79 = (aux + st.buffer[1]) & 3;
  switch (quotient_79)
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
  int metric_49 = local_arr[aux % 3];
  acc = (acc + (metric_49 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000553_5313_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st_1 = {0};
  struct Vector3D_R000553_5313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_63_1 = local_arr_1[aux_1 % 3];
  int checksum_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_63_2 * 2)) & 127;
  int vector_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_13_1) & 63;
  aux_2 = (aux_2 + vector_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_63_1 == checksum_63_2);
  assert(vector_13_1 == vector_13_2);
}

int fn_R000553_5313_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000553_5313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int checksum_63 = local_arr[aux % 3];
  acc = (acc + (checksum_63 * 2)) & 127;
  int vector_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000553_0_1;
  int sec_r000553_0_2;
  int sec_r000553_1_1;
  int sec_r000553_1_2;
  int sec_r000553_2_1;
  int sec_r000553_2_2;
  int sec_r000553_3_1;
  int sec_r000553_3_2;
  int sec_r000553_4_1;
  int sec_r000553_4_2;
  int sec_r000553_5_1;
  int sec_r000553_5_2;
  int sec_r000553_6_1;
  int sec_r000553_6_2;
  int sec_r000553_7_1;
  int sec_r000553_7_2;
  int sec_r000553_8_1;
  int sec_r000553_8_2;
  int sec_r000553_9_1;
  int sec_r000553_9_2;
  int sec_r000553_10_1;
  int sec_r000553_10_2;
  int sec_r000553_11_1;
  int sec_r000553_11_2;
  int sec_r000553_12_1;
  int sec_r000553_12_2;
  int sec_r000553_13_1;
  int sec_r000553_13_2;
  int sec_r000553_14_1;
  int sec_r000553_14_2;
  int sec_r000553_15_1;
  int sec_r000553_15_2;
  int sec_r000553_16_1;
  int sec_r000553_16_2;
  int sec_r000553_17_1;
  int sec_r000553_17_2;
  int sec_r000553_18_1;
  int sec_r000553_18_2;
  int sec_r000553_19_1;
  int sec_r000553_19_2;
  int pub_r000553_0_1;
  int pub_r000553_0_2;
  int pub_r000553_1_1;
  int pub_r000553_1_2;
  int pub_r000553_2_1;
  int pub_r000553_2_2;
  int pub_r000553_3_1;
  int pub_r000553_3_2;
  int pub_r000553_4_1;
  int pub_r000553_4_2;
  int pub_r000553_5_1;
  int pub_r000553_5_2;
  int pub_r000553_6_1;
  int pub_r000553_6_2;
  int pub_r000553_7_1;
  int pub_r000553_7_2;
  int pub_r000553_8_1;
  int pub_r000553_8_2;
  int pub_r000553_9_1;
  int pub_r000553_9_2;
  int pub_r000553_10_1;
  int pub_r000553_10_2;
  int pub_r000553_11_1;
  int pub_r000553_11_2;
  int pub_r000553_12_1;
  int pub_r000553_12_2;
  int pub_r000553_13_1;
  int pub_r000553_13_2;
  int pub_r000553_14_1;
  int pub_r000553_14_2;
  int pub_r000553_15_1;
  int pub_r000553_15_2;
  int pub_r000553_16_1;
  int pub_r000553_16_2;
  int pub_r000553_17_1;
  int pub_r000553_17_2;
  int pub_r000553_18_1;
  int pub_r000553_18_2;
  int pub_r000553_19_1;
  int pub_r000553_19_2;
  int pub_r000553_20_1;
  int pub_r000553_20_2;
  int pub_r000553_21_1;
  int pub_r000553_21_2;
  int pub_r000553_22_1;
  int pub_r000553_22_2;
  int pub_r000553_23_1;
  int pub_r000553_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000553_0_1 >= (-100)) && (pub_r000553_0_1 <= 100));
  __CPROVER_assume((pub_r000553_0_2 >= (-100)) && (pub_r000553_0_2 <= 100));
  __CPROVER_assume((pub_r000553_1_1 >= (-100)) && (pub_r000553_1_1 <= 100));
  __CPROVER_assume((pub_r000553_1_2 >= (-100)) && (pub_r000553_1_2 <= 100));
  __CPROVER_assume((pub_r000553_2_1 >= (-100)) && (pub_r000553_2_1 <= 100));
  __CPROVER_assume((pub_r000553_2_2 >= (-100)) && (pub_r000553_2_2 <= 100));
  __CPROVER_assume((pub_r000553_3_1 >= (-100)) && (pub_r000553_3_1 <= 100));
  __CPROVER_assume((pub_r000553_3_2 >= (-100)) && (pub_r000553_3_2 <= 100));
  __CPROVER_assume((pub_r000553_4_1 >= (-100)) && (pub_r000553_4_1 <= 100));
  __CPROVER_assume((pub_r000553_4_2 >= (-100)) && (pub_r000553_4_2 <= 100));
  __CPROVER_assume((pub_r000553_5_1 >= (-100)) && (pub_r000553_5_1 <= 100));
  __CPROVER_assume((pub_r000553_5_2 >= (-100)) && (pub_r000553_5_2 <= 100));
  __CPROVER_assume((pub_r000553_6_1 >= (-100)) && (pub_r000553_6_1 <= 100));
  __CPROVER_assume((pub_r000553_6_2 >= (-100)) && (pub_r000553_6_2 <= 100));
  __CPROVER_assume((pub_r000553_7_1 >= (-100)) && (pub_r000553_7_1 <= 100));
  __CPROVER_assume((pub_r000553_7_2 >= (-100)) && (pub_r000553_7_2 <= 100));
  __CPROVER_assume((pub_r000553_8_1 >= (-100)) && (pub_r000553_8_1 <= 100));
  __CPROVER_assume((pub_r000553_8_2 >= (-100)) && (pub_r000553_8_2 <= 100));
  __CPROVER_assume((pub_r000553_9_1 >= (-100)) && (pub_r000553_9_1 <= 100));
  __CPROVER_assume((pub_r000553_9_2 >= (-100)) && (pub_r000553_9_2 <= 100));
  __CPROVER_assume((pub_r000553_10_1 >= (-100)) && (pub_r000553_10_1 <= 100));
  __CPROVER_assume((pub_r000553_10_2 >= (-100)) && (pub_r000553_10_2 <= 100));
  __CPROVER_assume((pub_r000553_11_1 >= (-100)) && (pub_r000553_11_1 <= 100));
  __CPROVER_assume((pub_r000553_11_2 >= (-100)) && (pub_r000553_11_2 <= 100));
  __CPROVER_assume((pub_r000553_12_1 >= (-100)) && (pub_r000553_12_1 <= 100));
  __CPROVER_assume((pub_r000553_12_2 >= (-100)) && (pub_r000553_12_2 <= 100));
  __CPROVER_assume((pub_r000553_13_1 >= (-100)) && (pub_r000553_13_1 <= 100));
  __CPROVER_assume((pub_r000553_13_2 >= (-100)) && (pub_r000553_13_2 <= 100));
  __CPROVER_assume((pub_r000553_14_1 >= (-100)) && (pub_r000553_14_1 <= 100));
  __CPROVER_assume((pub_r000553_14_2 >= (-100)) && (pub_r000553_14_2 <= 100));
  __CPROVER_assume((pub_r000553_15_1 >= (-100)) && (pub_r000553_15_1 <= 100));
  __CPROVER_assume((pub_r000553_15_2 >= (-100)) && (pub_r000553_15_2 <= 100));
  __CPROVER_assume((pub_r000553_16_1 >= (-100)) && (pub_r000553_16_1 <= 100));
  __CPROVER_assume((pub_r000553_16_2 >= (-100)) && (pub_r000553_16_2 <= 100));
  __CPROVER_assume((pub_r000553_17_1 >= (-100)) && (pub_r000553_17_1 <= 100));
  __CPROVER_assume((pub_r000553_17_2 >= (-100)) && (pub_r000553_17_2 <= 100));
  __CPROVER_assume((pub_r000553_18_1 >= (-100)) && (pub_r000553_18_1 <= 100));
  __CPROVER_assume((pub_r000553_18_2 >= (-100)) && (pub_r000553_18_2 <= 100));
  __CPROVER_assume((pub_r000553_19_1 >= (-100)) && (pub_r000553_19_1 <= 100));
  __CPROVER_assume((pub_r000553_19_2 >= (-100)) && (pub_r000553_19_2 <= 100));
  __CPROVER_assume((pub_r000553_20_1 >= (-100)) && (pub_r000553_20_1 <= 100));
  __CPROVER_assume((pub_r000553_20_2 >= (-100)) && (pub_r000553_20_2 <= 100));
  __CPROVER_assume((pub_r000553_21_1 >= (-100)) && (pub_r000553_21_1 <= 100));
  __CPROVER_assume((pub_r000553_21_2 >= (-100)) && (pub_r000553_21_2 <= 100));
  __CPROVER_assume((pub_r000553_22_1 >= (-100)) && (pub_r000553_22_1 <= 100));
  __CPROVER_assume((pub_r000553_22_2 >= (-100)) && (pub_r000553_22_2 <= 100));
  __CPROVER_assume((pub_r000553_23_1 >= (-100)) && (pub_r000553_23_1 <= 100));
  __CPROVER_assume((pub_r000553_23_2 >= (-100)) && (pub_r000553_23_2 <= 100));
  __CPROVER_assume((sec_r000553_0_1 >= 0) && (sec_r000553_0_1 <= 255));
  __CPROVER_assume((sec_r000553_0_2 >= 0) && (sec_r000553_0_2 <= 255));
  __CPROVER_assume((sec_r000553_1_1 >= 0) && (sec_r000553_1_1 <= 255));
  __CPROVER_assume((sec_r000553_1_2 >= 0) && (sec_r000553_1_2 <= 255));
  __CPROVER_assume((sec_r000553_2_1 >= 0) && (sec_r000553_2_1 <= 255));
  __CPROVER_assume((sec_r000553_2_2 >= 0) && (sec_r000553_2_2 <= 255));
  __CPROVER_assume((sec_r000553_3_1 >= 0) && (sec_r000553_3_1 <= 255));
  __CPROVER_assume((sec_r000553_3_2 >= 0) && (sec_r000553_3_2 <= 255));
  __CPROVER_assume((sec_r000553_4_1 >= 0) && (sec_r000553_4_1 <= 255));
  __CPROVER_assume((sec_r000553_4_2 >= 0) && (sec_r000553_4_2 <= 255));
  __CPROVER_assume((sec_r000553_5_1 >= 0) && (sec_r000553_5_1 <= 255));
  __CPROVER_assume((sec_r000553_5_2 >= 0) && (sec_r000553_5_2 <= 255));
  __CPROVER_assume((sec_r000553_6_1 >= 0) && (sec_r000553_6_1 <= 255));
  __CPROVER_assume((sec_r000553_6_2 >= 0) && (sec_r000553_6_2 <= 255));
  __CPROVER_assume((sec_r000553_7_1 >= 0) && (sec_r000553_7_1 <= 255));
  __CPROVER_assume((sec_r000553_7_2 >= 0) && (sec_r000553_7_2 <= 255));
  __CPROVER_assume((sec_r000553_8_1 >= 0) && (sec_r000553_8_1 <= 255));
  __CPROVER_assume((sec_r000553_8_2 >= 0) && (sec_r000553_8_2 <= 255));
  __CPROVER_assume((sec_r000553_9_1 >= 0) && (sec_r000553_9_1 <= 255));
  __CPROVER_assume((sec_r000553_9_2 >= 0) && (sec_r000553_9_2 <= 255));
  __CPROVER_assume((sec_r000553_10_1 >= 0) && (sec_r000553_10_1 <= 255));
  __CPROVER_assume((sec_r000553_10_2 >= 0) && (sec_r000553_10_2 <= 255));
  __CPROVER_assume((sec_r000553_11_1 >= 0) && (sec_r000553_11_1 <= 255));
  __CPROVER_assume((sec_r000553_11_2 >= 0) && (sec_r000553_11_2 <= 255));
  __CPROVER_assume((sec_r000553_12_1 >= 0) && (sec_r000553_12_1 <= 255));
  __CPROVER_assume((sec_r000553_12_2 >= 0) && (sec_r000553_12_2 <= 255));
  __CPROVER_assume((sec_r000553_13_1 >= 0) && (sec_r000553_13_1 <= 255));
  __CPROVER_assume((sec_r000553_13_2 >= 0) && (sec_r000553_13_2 <= 255));
  __CPROVER_assume((sec_r000553_14_1 >= 0) && (sec_r000553_14_1 <= 255));
  __CPROVER_assume((sec_r000553_14_2 >= 0) && (sec_r000553_14_2 <= 255));
  __CPROVER_assume((sec_r000553_15_1 >= 0) && (sec_r000553_15_1 <= 255));
  __CPROVER_assume((sec_r000553_15_2 >= 0) && (sec_r000553_15_2 <= 255));
  __CPROVER_assume((sec_r000553_16_1 >= 0) && (sec_r000553_16_1 <= 255));
  __CPROVER_assume((sec_r000553_16_2 >= 0) && (sec_r000553_16_2 <= 255));
  __CPROVER_assume((sec_r000553_17_1 >= 0) && (sec_r000553_17_1 <= 255));
  __CPROVER_assume((sec_r000553_17_2 >= 0) && (sec_r000553_17_2 <= 255));
  __CPROVER_assume((sec_r000553_18_1 >= 0) && (sec_r000553_18_1 <= 255));
  __CPROVER_assume((sec_r000553_18_2 >= 0) && (sec_r000553_18_2 <= 255));
  __CPROVER_assume((sec_r000553_19_1 >= 0) && (sec_r000553_19_1 <= 255));
  __CPROVER_assume((sec_r000553_19_2 >= 0) && (sec_r000553_19_2 <= 255));
  struct Vector3D_R000553_5313_0 st_var_0_1 = {0};
  struct Vector3D_R000553_5313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000553_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000553_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000553_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000553_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000553_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000553_0_2 + 7) & 15;
  struct FilterState_R000553_5313_1 st_var_1_1 = {0};
  struct FilterState_R000553_5313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000553_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000553_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000553_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000553_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000553_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000553_0_2 + 9) & 15;
  struct MatrixBlock_R000553_5313_2 st_var_2_1 = {0};
  struct MatrixBlock_R000553_5313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000553_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000553_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000553_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000553_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000553_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000553_0_2 + 11) & 15;
  struct AudioFrame_R000553_5313_3 st_var_3_1 = {0};
  struct AudioFrame_R000553_5313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000553_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000553_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000553_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000553_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000553_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000553_0_2 + 13) & 15;
  union TelemetryField_R000553_5313_0 u_var_1;
  union TelemetryField_R000553_5313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
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

  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = (st_var_2_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_2_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_15_1 = ((st_var_3_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_3_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 27)
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
  if (stage_v_15_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 27)
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
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((st_var_2_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_2_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 43)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 43)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_23_1 = ((st_var_3_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_3_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 43)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 43)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
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
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((st_var_3_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_3_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 47)
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
  if (stage_v_27_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 47)
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
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 32)
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
  if (stage_v_28_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 32)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 31) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = (st_var_2_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_2_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 36) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 55)
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
  if (stage_v_37_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 55)
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
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 35)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 35)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((st_var_3_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_3_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 31)
    {
      chk_sum_1 ^= stage_v_43_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_43_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 31)
    {
      chk_sum_2 ^= stage_v_43_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 45) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((st_var_3_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_3_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 47)
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
  if (stage_v_51_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 47)
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
  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_53_1 = ((st_var_1_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_1_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 28)
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
  if (stage_v_53_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 28)
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
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 59) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 60) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_3_2.buffer[2] * 3) & 63;
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
  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = ((st_var_2_1.buffer[2] * 2) + 193) & 63;
  int stage_v_62_2 = ((st_var_2_2.buffer[2] * 2) + 193) & 63;
  if (stage_v_62_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_62_1) - 5) & 255;
    if (stage_v_62_1 > 32)
    {
      chk_sum_1 ^= stage_v_62_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_62_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_62_2) - 5) & 255;
    if (stage_v_62_2 > 32)
    {
      chk_sum_2 ^= stage_v_62_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 67) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 69) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int sub_step_69_1 = ((sec_r000553_3_1 + pub_r000553_13_1) + 26) & 127;
  int sub_step_69_2 = ((sec_r000553_3_2 + pub_r000553_13_2) + 26) & 127;
  int stage_v_69_1 = ((sub_step_69_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_69_2 = ((sub_step_69_2 * 2) + pub_r000553_16_2) & 127;
  st_var_1_1.buffer[0] = stage_v_69_1 & 15;
  st_var_1_2.buffer[0] = stage_v_69_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int sub_step_70_1 = ((stage_v_69_1 + pub_r000553_22_1) + 32) & 127;
  int sub_step_70_2 = ((stage_v_69_2 + pub_r000553_22_2) + 32) & 127;
  int stage_v_70_1 = ((sub_step_70_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_70_2 = ((sub_step_70_2 * 2) + pub_r000553_11_2) & 127;
  st_var_2_1.buffer[1] = stage_v_70_1 & 15;
  st_var_2_2.buffer[1] = stage_v_70_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int sub_step_71_1 = ((stage_v_70_1 + pub_r000553_9_1) + 27) & 127;
  int sub_step_71_2 = ((stage_v_70_2 + pub_r000553_9_2) + 27) & 127;
  int stage_v_71_1 = ((sub_step_71_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_71_2 = ((sub_step_71_2 * 2) + pub_r000553_11_2) & 127;
  st_var_3_1.buffer[2] = stage_v_71_1 & 15;
  st_var_3_2.buffer[2] = stage_v_71_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int sub_step_72_1 = ((stage_v_71_1 + pub_r000553_4_1) + 18) & 127;
  int sub_step_72_2 = ((stage_v_71_2 + pub_r000553_4_2) + 18) & 127;
  int stage_v_72_1 = ((sub_step_72_1 * 2) + pub_r000553_13_1) & 127;
  int stage_v_72_2 = ((sub_step_72_2 * 2) + pub_r000553_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_72_1 & 15;
  st_var_0_2.buffer[0] = stage_v_72_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int sub_step_73_1 = ((sub_step_71_1 + pub_r000553_10_1) + 18) & 127;
  int sub_step_73_2 = ((sub_step_71_2 + pub_r000553_10_2) + 18) & 127;
  int stage_v_73_1 = ((sub_step_73_1 * 2) + pub_r000553_23_1) & 127;
  int stage_v_73_2 = ((sub_step_73_2 * 2) + pub_r000553_23_2) & 127;
  st_var_1_1.buffer[1] = stage_v_73_1 & 15;
  st_var_1_2.buffer[1] = stage_v_73_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int sub_step_74_1 = ((sub_step_70_1 + pub_r000553_23_1) + 35) & 127;
  int sub_step_74_2 = ((sub_step_70_2 + pub_r000553_23_2) + 35) & 127;
  int stage_v_74_1 = ((sub_step_74_1 * 2) + pub_r000553_6_1) & 127;
  int stage_v_74_2 = ((sub_step_74_2 * 2) + pub_r000553_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_74_1 & 15;
  st_var_2_2.buffer[2] = stage_v_74_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int sub_step_75_1 = ((sub_step_71_1 + pub_r000553_8_1) + 21) & 127;
  int sub_step_75_2 = ((sub_step_71_2 + pub_r000553_8_2) + 21) & 127;
  int stage_v_75_1 = ((sub_step_75_1 * 2) + pub_r000553_0_1) & 127;
  int stage_v_75_2 = ((sub_step_75_2 * 2) + pub_r000553_0_2) & 127;
  st_var_3_1.buffer[0] = stage_v_75_1 & 15;
  st_var_3_2.buffer[0] = stage_v_75_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int sub_step_76_1 = ((sub_step_69_1 + pub_r000553_21_1) + 21) & 127;
  int sub_step_76_2 = ((sub_step_69_2 + pub_r000553_21_2) + 21) & 127;
  int stage_v_76_1 = ((sub_step_76_1 * 2) + pub_r000553_21_1) & 127;
  int stage_v_76_2 = ((sub_step_76_2 * 2) + pub_r000553_21_2) & 127;
  st_var_0_1.buffer[1] = stage_v_76_1 & 15;
  st_var_0_2.buffer[1] = stage_v_76_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int sub_step_77_1 = ((stage_v_76_1 + pub_r000553_12_1) + 27) & 127;
  int sub_step_77_2 = ((stage_v_76_2 + pub_r000553_12_2) + 27) & 127;
  int stage_v_77_1 = ((sub_step_77_1 * 2) + pub_r000553_7_1) & 127;
  int stage_v_77_2 = ((sub_step_77_2 * 2) + pub_r000553_7_2) & 127;
  st_var_1_1.buffer[2] = stage_v_77_1 & 15;
  st_var_1_2.buffer[2] = stage_v_77_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int sub_step_78_1 = ((stage_v_69_1 + pub_r000553_11_1) + 30) & 127;
  int sub_step_78_2 = ((stage_v_69_2 + pub_r000553_11_2) + 30) & 127;
  int stage_v_78_1 = ((sub_step_78_1 * 2) + pub_r000553_9_1) & 127;
  int stage_v_78_2 = ((sub_step_78_2 * 2) + pub_r000553_9_2) & 127;
  st_var_2_1.buffer[0] = stage_v_78_1 & 15;
  st_var_2_2.buffer[0] = stage_v_78_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int sub_step_79_1 = ((sec_r000553_9_1 + pub_r000553_16_1) + 23) & 127;
  int sub_step_79_2 = ((sec_r000553_9_2 + pub_r000553_16_2) + 23) & 127;
  int stage_v_79_1 = ((sub_step_79_1 * 2) + pub_r000553_9_1) & 127;
  int stage_v_79_2 = ((sub_step_79_2 * 2) + pub_r000553_9_2) & 127;
  st_var_3_1.buffer[1] = stage_v_79_1 & 15;
  st_var_3_2.buffer[1] = stage_v_79_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int sub_step_80_1 = ((stage_v_73_1 + pub_r000553_21_1) + 21) & 127;
  int sub_step_80_2 = ((stage_v_73_2 + pub_r000553_21_2) + 21) & 127;
  int stage_v_80_1 = ((sub_step_80_1 * 2) + pub_r000553_10_1) & 127;
  int stage_v_80_2 = ((sub_step_80_2 * 2) + pub_r000553_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_80_1 & 15;
  st_var_0_2.buffer[2] = stage_v_80_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int sub_step_81_1 = ((sec_r000553_17_1 + pub_r000553_17_1) + 20) & 127;
  int sub_step_81_2 = ((sec_r000553_17_2 + pub_r000553_17_2) + 20) & 127;
  int stage_v_81_1 = ((sub_step_81_1 * 2) + pub_r000553_21_1) & 127;
  int stage_v_81_2 = ((sub_step_81_2 * 2) + pub_r000553_21_2) & 127;
  st_var_1_1.buffer[0] = stage_v_81_1 & 15;
  st_var_1_2.buffer[0] = stage_v_81_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int sub_step_82_1 = ((stage_v_74_1 + pub_r000553_23_1) + 32) & 127;
  int sub_step_82_2 = ((stage_v_74_2 + pub_r000553_23_2) + 32) & 127;
  int stage_v_82_1 = ((sub_step_82_1 * 2) + pub_r000553_20_1) & 127;
  int stage_v_82_2 = ((sub_step_82_2 * 2) + pub_r000553_20_2) & 127;
  st_var_2_1.buffer[1] = stage_v_82_1 & 15;
  st_var_2_2.buffer[1] = stage_v_82_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int sub_step_83_1 = ((sub_step_79_1 + pub_r000553_6_1) + 21) & 127;
  int sub_step_83_2 = ((sub_step_79_2 + pub_r000553_6_2) + 21) & 127;
  int stage_v_83_1 = ((sub_step_83_1 * 2) + pub_r000553_5_1) & 127;
  int stage_v_83_2 = ((sub_step_83_2 * 2) + pub_r000553_5_2) & 127;
  st_var_3_1.buffer[2] = stage_v_83_1 & 15;
  st_var_3_2.buffer[2] = stage_v_83_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int sub_step_84_1 = ((sec_r000553_2_1 + pub_r000553_5_1) + 12) & 127;
  int sub_step_84_2 = ((sec_r000553_2_2 + pub_r000553_5_2) + 12) & 127;
  int stage_v_84_1 = ((sub_step_84_1 * 2) + pub_r000553_8_1) & 127;
  int stage_v_84_2 = ((sub_step_84_2 * 2) + pub_r000553_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_84_1 & 15;
  st_var_0_2.buffer[0] = stage_v_84_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int sub_step_85_1 = ((sub_step_72_1 + pub_r000553_10_1) + 20) & 127;
  int sub_step_85_2 = ((sub_step_72_2 + pub_r000553_10_2) + 20) & 127;
  int stage_v_85_1 = ((sub_step_85_1 * 2) + pub_r000553_21_1) & 127;
  int stage_v_85_2 = ((sub_step_85_2 * 2) + pub_r000553_21_2) & 127;
  st_var_1_1.buffer[1] = stage_v_85_1 & 15;
  st_var_1_2.buffer[1] = stage_v_85_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int sub_step_86_1 = ((sub_step_77_1 + pub_r000553_12_1) + 25) & 127;
  int sub_step_86_2 = ((sub_step_77_2 + pub_r000553_12_2) + 25) & 127;
  int stage_v_86_1 = ((sub_step_86_1 * 2) + pub_r000553_4_1) & 127;
  int stage_v_86_2 = ((sub_step_86_2 * 2) + pub_r000553_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_86_1 & 15;
  st_var_2_2.buffer[2] = stage_v_86_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int sub_step_87_1 = ((sub_step_76_1 + pub_r000553_1_1) + 24) & 127;
  int sub_step_87_2 = ((sub_step_76_2 + pub_r000553_1_2) + 24) & 127;
  int stage_v_87_1 = ((sub_step_87_1 * 2) + pub_r000553_4_1) & 127;
  int stage_v_87_2 = ((sub_step_87_2 * 2) + pub_r000553_4_2) & 127;
  st_var_3_1.buffer[0] = stage_v_87_1 & 15;
  st_var_3_2.buffer[0] = stage_v_87_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int sub_step_88_1 = ((sec_r000553_3_1 + pub_r000553_12_1) + 15) & 127;
  int sub_step_88_2 = ((sec_r000553_3_2 + pub_r000553_12_2) + 15) & 127;
  int stage_v_88_1 = ((sub_step_88_1 * 2) + pub_r000553_6_1) & 127;
  int stage_v_88_2 = ((sub_step_88_2 * 2) + pub_r000553_6_2) & 127;
  st_var_0_1.buffer[1] = stage_v_88_1 & 15;
  st_var_0_2.buffer[1] = stage_v_88_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int sub_step_89_1 = ((sub_step_88_1 + pub_r000553_14_1) + 11) & 127;
  int sub_step_89_2 = ((sub_step_88_2 + pub_r000553_14_2) + 11) & 127;
  int stage_v_89_1 = ((sub_step_89_1 * 2) + pub_r000553_20_1) & 127;
  int stage_v_89_2 = ((sub_step_89_2 * 2) + pub_r000553_20_2) & 127;
  st_var_1_1.buffer[2] = stage_v_89_1 & 15;
  st_var_1_2.buffer[2] = stage_v_89_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int sub_step_90_1 = ((sub_step_70_1 + pub_r000553_1_1) + 12) & 127;
  int sub_step_90_2 = ((sub_step_70_2 + pub_r000553_1_2) + 12) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000553_16_2) & 127;
  st_var_2_1.buffer[0] = stage_v_90_1 & 15;
  st_var_2_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((sec_r000553_14_1 + pub_r000553_7_1) + 28) & 127;
  int sub_step_91_2 = ((sec_r000553_14_2 + pub_r000553_7_2) + 28) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000553_11_2) & 127;
  st_var_3_1.buffer[1] = stage_v_91_1 & 15;
  st_var_3_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((sec_r000553_6_1 + pub_r000553_7_1) + 31) & 127;
  int sub_step_92_2 = ((sec_r000553_6_2 + pub_r000553_7_2) + 31) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000553_0_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000553_0_2) & 127;
  st_var_0_1.buffer[2] = stage_v_92_1 & 15;
  st_var_0_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((sub_step_84_1 + pub_r000553_9_1) + 20) & 127;
  int sub_step_93_2 = ((sub_step_84_2 + pub_r000553_9_2) + 20) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000553_16_2) & 127;
  st_var_1_1.buffer[0] = stage_v_93_1 & 15;
  st_var_1_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((stage_v_87_1 + pub_r000553_10_1) + 12) & 127;
  int sub_step_94_2 = ((stage_v_87_2 + pub_r000553_10_2) + 12) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000553_14_2) & 127;
  st_var_2_1.buffer[1] = stage_v_94_1 & 15;
  st_var_2_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sec_r000553_3_1 + pub_r000553_20_1) + 8) & 127;
  int sub_step_95_2 = ((sec_r000553_3_2 + pub_r000553_20_2) + 8) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000553_11_2) & 127;
  st_var_3_1.buffer[2] = stage_v_95_1 & 15;
  st_var_3_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((sec_r000553_8_1 + pub_r000553_7_1) + 22) & 127;
  int sub_step_96_2 = ((sec_r000553_8_2 + pub_r000553_7_2) + 22) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000553_13_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000553_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((sec_r000553_18_1 + pub_r000553_23_1) + 18) & 127;
  int sub_step_97_2 = ((sec_r000553_18_2 + pub_r000553_23_2) + 18) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000553_6_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000553_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((sub_step_75_1 + pub_r000553_12_1) + 18) & 127;
  int sub_step_98_2 = ((sub_step_75_2 + pub_r000553_12_2) + 18) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000553_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((sub_step_88_1 + pub_r000553_9_1) + 23) & 127;
  int sub_step_99_2 = ((sub_step_88_2 + pub_r000553_9_2) + 23) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000553_2_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000553_2_2) & 127;
  st_var_3_1.buffer[0] = stage_v_99_1 & 15;
  st_var_3_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((stage_v_69_1 + pub_r000553_5_1) + 27) & 127;
  int sub_step_100_2 = ((stage_v_69_2 + pub_r000553_5_2) + 27) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000553_16_2) & 127;
  st_var_0_1.buffer[1] = stage_v_100_1 & 15;
  st_var_0_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((sec_r000553_6_1 + pub_r000553_19_1) + 17) & 127;
  int sub_step_101_2 = ((sec_r000553_6_2 + pub_r000553_19_2) + 17) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000553_0_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000553_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_101_1 & 15;
  st_var_1_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((sub_step_97_1 + pub_r000553_16_1) + 6) & 127;
  int sub_step_102_2 = ((sub_step_97_2 + pub_r000553_16_2) + 6) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000553_0_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000553_0_2) & 127;
  st_var_2_1.buffer[0] = stage_v_102_1 & 15;
  st_var_2_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((sub_step_71_1 + pub_r000553_18_1) + 10) & 127;
  int sub_step_103_2 = ((sub_step_71_2 + pub_r000553_18_2) + 10) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000553_21_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000553_21_2) & 127;
  st_var_3_1.buffer[1] = stage_v_103_1 & 15;
  st_var_3_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((stage_v_84_1 + pub_r000553_14_1) + 20) & 127;
  int sub_step_104_2 = ((stage_v_84_2 + pub_r000553_14_2) + 20) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000553_12_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000553_12_2) & 127;
  st_var_0_1.buffer[2] = stage_v_104_1 & 15;
  st_var_0_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((sub_step_94_1 + pub_r000553_13_1) + 19) & 127;
  int sub_step_105_2 = ((sub_step_94_2 + pub_r000553_13_2) + 19) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000553_11_2) & 127;
  st_var_1_1.buffer[0] = stage_v_105_1 & 15;
  st_var_1_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((sub_step_83_1 + pub_r000553_20_1) + 31) & 127;
  int sub_step_106_2 = ((sub_step_83_2 + pub_r000553_20_2) + 31) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000553_15_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000553_15_2) & 127;
  st_var_2_1.buffer[1] = stage_v_106_1 & 15;
  st_var_2_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((stage_v_80_1 + pub_r000553_16_1) + 28) & 127;
  int sub_step_107_2 = ((stage_v_80_2 + pub_r000553_16_2) + 28) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000553_4_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000553_4_2) & 127;
  st_var_3_1.buffer[2] = stage_v_107_1 & 15;
  st_var_3_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((sub_step_106_1 + pub_r000553_9_1) + 24) & 127;
  int sub_step_108_2 = ((sub_step_106_2 + pub_r000553_9_2) + 24) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000553_7_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000553_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((stage_v_93_1 + pub_r000553_1_1) + 16) & 127;
  int sub_step_109_2 = ((stage_v_93_2 + pub_r000553_1_2) + 16) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000553_20_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000553_20_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((sec_r000553_0_1 + pub_r000553_10_1) + 13) & 127;
  int sub_step_110_2 = ((sec_r000553_0_2 + pub_r000553_10_2) + 13) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000553_2_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000553_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((sec_r000553_5_1 + pub_r000553_1_1) + 22) & 127;
  int sub_step_111_2 = ((sec_r000553_5_2 + pub_r000553_1_2) + 22) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000553_5_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000553_5_2) & 127;
  st_var_3_1.buffer[0] = stage_v_111_1 & 15;
  st_var_3_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((sec_r000553_18_1 + pub_r000553_17_1) + 10) & 127;
  int sub_step_112_2 = ((sec_r000553_18_2 + pub_r000553_17_2) + 10) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000553_23_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000553_23_2) & 127;
  st_var_0_1.buffer[1] = stage_v_112_1 & 15;
  st_var_0_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((sub_step_93_1 + pub_r000553_23_1) + 8) & 127;
  int sub_step_113_2 = ((sub_step_93_2 + pub_r000553_23_2) + 8) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000553_14_2) & 127;
  st_var_1_1.buffer[2] = stage_v_113_1 & 15;
  st_var_1_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((sec_r000553_0_1 + pub_r000553_13_1) + 16) & 127;
  int sub_step_114_2 = ((sec_r000553_0_2 + pub_r000553_13_2) + 16) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000553_14_2) & 127;
  st_var_2_1.buffer[0] = stage_v_114_1 & 15;
  st_var_2_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((sub_step_87_1 + pub_r000553_16_1) + 29) & 127;
  int sub_step_115_2 = ((sub_step_87_2 + pub_r000553_16_2) + 29) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000553_7_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000553_7_2) & 127;
  st_var_3_1.buffer[1] = stage_v_115_1 & 15;
  st_var_3_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((stage_v_102_1 + pub_r000553_9_1) + 13) & 127;
  int sub_step_116_2 = ((stage_v_102_2 + pub_r000553_9_2) + 13) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000553_4_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000553_4_2) & 127;
  st_var_0_1.buffer[2] = stage_v_116_1 & 15;
  st_var_0_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((sec_r000553_1_1 + pub_r000553_19_1) + 29) & 127;
  int sub_step_117_2 = ((sec_r000553_1_2 + pub_r000553_19_2) + 29) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000553_3_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000553_3_2) & 127;
  st_var_1_1.buffer[0] = stage_v_117_1 & 15;
  st_var_1_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((sub_step_100_1 + pub_r000553_1_1) + 33) & 127;
  int sub_step_118_2 = ((sub_step_100_2 + pub_r000553_1_2) + 33) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000553_16_2) & 127;
  st_var_2_1.buffer[1] = stage_v_118_1 & 15;
  st_var_2_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((sec_r000553_11_1 + pub_r000553_7_1) + 33) & 127;
  int sub_step_119_2 = ((sec_r000553_11_2 + pub_r000553_7_2) + 33) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000553_22_2) & 127;
  st_var_3_1.buffer[2] = stage_v_119_1 & 15;
  st_var_3_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((sec_r000553_3_1 + pub_r000553_18_1) + 19) & 127;
  int sub_step_120_2 = ((sec_r000553_3_2 + pub_r000553_18_2) + 19) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000553_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((stage_v_108_1 + pub_r000553_12_1) + 5) & 127;
  int sub_step_121_2 = ((stage_v_108_2 + pub_r000553_12_2) + 5) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000553_13_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000553_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sec_r000553_0_1 + pub_r000553_11_1) + 33) & 127;
  int sub_step_122_2 = ((sec_r000553_0_2 + pub_r000553_11_2) + 33) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000553_22_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((sec_r000553_4_1 + pub_r000553_20_1) + 24) & 127;
  int sub_step_123_2 = ((sec_r000553_4_2 + pub_r000553_20_2) + 24) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000553_15_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000553_15_2) & 127;
  st_var_3_1.buffer[0] = stage_v_123_1 & 15;
  st_var_3_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((sub_step_90_1 + pub_r000553_22_1) + 10) & 127;
  int sub_step_124_2 = ((sub_step_90_2 + pub_r000553_22_2) + 10) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000553_11_2) & 127;
  st_var_0_1.buffer[1] = stage_v_124_1 & 15;
  st_var_0_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((sub_step_119_1 + pub_r000553_21_1) + 24) & 127;
  int sub_step_125_2 = ((sub_step_119_2 + pub_r000553_21_2) + 24) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000553_9_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000553_9_2) & 127;
  st_var_1_1.buffer[2] = stage_v_125_1 & 15;
  st_var_1_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((sub_step_100_1 + pub_r000553_6_1) + 31) & 127;
  int sub_step_126_2 = ((sub_step_100_2 + pub_r000553_6_2) + 31) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000553_0_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000553_0_2) & 127;
  st_var_2_1.buffer[0] = stage_v_126_1 & 15;
  st_var_2_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((sec_r000553_9_1 + pub_r000553_19_1) + 33) & 127;
  int sub_step_127_2 = ((sec_r000553_9_2 + pub_r000553_19_2) + 33) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000553_2_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000553_2_2) & 127;
  st_var_3_1.buffer[1] = stage_v_127_1 & 15;
  st_var_3_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((stage_v_77_1 + pub_r000553_11_1) + 35) & 127;
  int sub_step_128_2 = ((stage_v_77_2 + pub_r000553_11_2) + 35) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000553_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_128_1 & 15;
  st_var_0_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((sec_r000553_5_1 + pub_r000553_0_1) + 26) & 127;
  int sub_step_129_2 = ((sec_r000553_5_2 + pub_r000553_0_2) + 26) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000553_6_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000553_6_2) & 127;
  st_var_1_1.buffer[0] = stage_v_129_1 & 15;
  st_var_1_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((stage_v_114_1 + pub_r000553_13_1) + 24) & 127;
  int sub_step_130_2 = ((stage_v_114_2 + pub_r000553_13_2) + 24) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000553_7_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000553_7_2) & 127;
  st_var_2_1.buffer[1] = stage_v_130_1 & 15;
  st_var_2_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((stage_v_96_1 + pub_r000553_9_1) + 9) & 127;
  int sub_step_131_2 = ((stage_v_96_2 + pub_r000553_9_2) + 9) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000553_4_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000553_4_2) & 127;
  st_var_3_1.buffer[2] = stage_v_131_1 & 15;
  st_var_3_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((stage_v_73_1 + pub_r000553_14_1) + 16) & 127;
  int sub_step_132_2 = ((stage_v_73_2 + pub_r000553_14_2) + 16) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000553_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((sub_step_129_1 + pub_r000553_0_1) + 31) & 127;
  int sub_step_133_2 = ((sub_step_129_2 + pub_r000553_0_2) + 31) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000553_20_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000553_20_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((stage_v_105_1 + pub_r000553_13_1) + 17) & 127;
  int sub_step_134_2 = ((stage_v_105_2 + pub_r000553_13_2) + 17) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000553_22_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((stage_v_99_1 + pub_r000553_4_1) + 27) & 127;
  int sub_step_135_2 = ((stage_v_99_2 + pub_r000553_4_2) + 27) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000553_7_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000553_7_2) & 127;
  st_var_3_1.buffer[0] = stage_v_135_1 & 15;
  st_var_3_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((sub_step_81_1 + pub_r000553_5_1) + 21) & 127;
  int sub_step_136_2 = ((sub_step_81_2 + pub_r000553_5_2) + 21) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000553_5_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000553_5_2) & 127;
  st_var_0_1.buffer[1] = stage_v_136_1 & 15;
  st_var_0_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((sub_step_97_1 + pub_r000553_11_1) + 15) & 127;
  int sub_step_137_2 = ((sub_step_97_2 + pub_r000553_11_2) + 15) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000553_17_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000553_17_2) & 127;
  st_var_1_1.buffer[2] = stage_v_137_1 & 15;
  st_var_1_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((stage_v_126_1 + pub_r000553_3_1) + 12) & 127;
  int sub_step_138_2 = ((stage_v_126_2 + pub_r000553_3_2) + 12) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000553_19_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000553_19_2) & 127;
  st_var_2_1.buffer[0] = stage_v_138_1 & 15;
  st_var_2_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((sec_r000553_10_1 + pub_r000553_15_1) + 21) & 127;
  int sub_step_139_2 = ((sec_r000553_10_2 + pub_r000553_15_2) + 21) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000553_9_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000553_9_2) & 127;
  st_var_3_1.buffer[1] = stage_v_139_1 & 15;
  st_var_3_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((sub_step_119_1 + pub_r000553_20_1) + 8) & 127;
  int sub_step_140_2 = ((sub_step_119_2 + pub_r000553_20_2) + 8) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000553_20_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000553_20_2) & 127;
  st_var_0_1.buffer[2] = stage_v_140_1 & 15;
  st_var_0_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sub_step_78_1 + pub_r000553_19_1) + 30) & 127;
  int sub_step_141_2 = ((sub_step_78_2 + pub_r000553_19_2) + 30) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000553_4_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000553_4_2) & 127;
  st_var_1_1.buffer[0] = stage_v_141_1 & 15;
  st_var_1_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((sec_r000553_4_1 + pub_r000553_14_1) + 11) & 127;
  int sub_step_142_2 = ((sec_r000553_4_2 + pub_r000553_14_2) + 11) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000553_18_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000553_18_2) & 127;
  st_var_2_1.buffer[1] = stage_v_142_1 & 15;
  st_var_2_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((stage_v_120_1 + pub_r000553_15_1) + 32) & 127;
  int sub_step_143_2 = ((stage_v_120_2 + pub_r000553_15_2) + 32) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000553_23_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000553_23_2) & 127;
  st_var_3_1.buffer[2] = stage_v_143_1 & 15;
  st_var_3_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((sec_r000553_1_1 + pub_r000553_16_1) + 15) & 127;
  int sub_step_144_2 = ((sec_r000553_1_2 + pub_r000553_16_2) + 15) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000553_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((sub_step_141_1 + pub_r000553_3_1) + 7) & 127;
  int sub_step_145_2 = ((sub_step_141_2 + pub_r000553_3_2) + 7) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000553_8_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000553_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((sec_r000553_12_1 + pub_r000553_21_1) + 9) & 127;
  int sub_step_146_2 = ((sec_r000553_12_2 + pub_r000553_21_2) + 9) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000553_1_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000553_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((stage_v_144_1 + pub_r000553_2_1) + 25) & 127;
  int sub_step_147_2 = ((stage_v_144_2 + pub_r000553_2_2) + 25) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000553_3_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000553_3_2) & 127;
  st_var_3_1.buffer[0] = stage_v_147_1 & 15;
  st_var_3_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((sub_step_132_1 + pub_r000553_5_1) + 22) & 127;
  int sub_step_148_2 = ((sub_step_132_2 + pub_r000553_5_2) + 22) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000553_18_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000553_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_148_1 & 15;
  st_var_0_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sub_step_84_1 + pub_r000553_8_1) + 23) & 127;
  int sub_step_149_2 = ((sub_step_84_2 + pub_r000553_8_2) + 23) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000553_0_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000553_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_149_1 & 15;
  st_var_1_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((stage_v_93_1 + pub_r000553_8_1) + 8) & 127;
  int sub_step_150_2 = ((stage_v_93_2 + pub_r000553_8_2) + 8) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000553_5_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000553_5_2) & 127;
  st_var_2_1.buffer[0] = stage_v_150_1 & 15;
  st_var_2_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((sec_r000553_3_1 + pub_r000553_4_1) + 18) & 127;
  int sub_step_151_2 = ((sec_r000553_3_2 + pub_r000553_4_2) + 18) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000553_3_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000553_3_2) & 127;
  st_var_3_1.buffer[1] = stage_v_151_1 & 15;
  st_var_3_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((sub_step_77_1 + pub_r000553_13_1) + 25) & 127;
  int sub_step_152_2 = ((sub_step_77_2 + pub_r000553_13_2) + 25) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000553_22_2) & 127;
  st_var_0_1.buffer[2] = stage_v_152_1 & 15;
  st_var_0_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((sub_step_93_1 + pub_r000553_23_1) + 10) & 127;
  int sub_step_153_2 = ((sub_step_93_2 + pub_r000553_23_2) + 10) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000553_5_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000553_5_2) & 127;
  st_var_1_1.buffer[0] = stage_v_153_1 & 15;
  st_var_1_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((stage_v_80_1 + pub_r000553_19_1) + 21) & 127;
  int sub_step_154_2 = ((stage_v_80_2 + pub_r000553_19_2) + 21) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000553_5_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000553_5_2) & 127;
  st_var_2_1.buffer[1] = stage_v_154_1 & 15;
  st_var_2_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((stage_v_89_1 + pub_r000553_12_1) + 28) & 127;
  int sub_step_155_2 = ((stage_v_89_2 + pub_r000553_12_2) + 28) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000553_14_2) & 127;
  st_var_3_1.buffer[2] = stage_v_155_1 & 15;
  st_var_3_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((stage_v_84_1 + pub_r000553_19_1) + 16) & 127;
  int sub_step_156_2 = ((stage_v_84_2 + pub_r000553_19_2) + 16) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000553_13_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000553_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((sub_step_136_1 + pub_r000553_0_1) + 19) & 127;
  int sub_step_157_2 = ((sub_step_136_2 + pub_r000553_0_2) + 19) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000553_18_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000553_18_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((sub_step_82_1 + pub_r000553_7_1) + 12) & 127;
  int sub_step_158_2 = ((sub_step_82_2 + pub_r000553_7_2) + 12) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000553_1_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000553_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((sec_r000553_14_1 + pub_r000553_8_1) + 26) & 127;
  int sub_step_159_2 = ((sec_r000553_14_2 + pub_r000553_8_2) + 26) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000553_1_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000553_1_2) & 127;
  st_var_3_1.buffer[0] = stage_v_159_1 & 15;
  st_var_3_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((sec_r000553_9_1 + pub_r000553_9_1) + 35) & 127;
  int sub_step_160_2 = ((sec_r000553_9_2 + pub_r000553_9_2) + 35) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000553_16_2) & 127;
  st_var_0_1.buffer[1] = stage_v_160_1 & 15;
  st_var_0_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((sub_step_83_1 + pub_r000553_14_1) + 22) & 127;
  int sub_step_161_2 = ((sub_step_83_2 + pub_r000553_14_2) + 22) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000553_10_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000553_10_2) & 127;
  st_var_1_1.buffer[2] = stage_v_161_1 & 15;
  st_var_1_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((sub_step_127_1 + pub_r000553_15_1) + 19) & 127;
  int sub_step_162_2 = ((sub_step_127_2 + pub_r000553_15_2) + 19) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000553_13_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000553_13_2) & 127;
  st_var_2_1.buffer[0] = stage_v_162_1 & 15;
  st_var_2_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((sub_step_138_1 + pub_r000553_1_1) + 30) & 127;
  int sub_step_163_2 = ((sub_step_138_2 + pub_r000553_1_2) + 30) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000553_14_2) & 127;
  st_var_3_1.buffer[1] = stage_v_163_1 & 15;
  st_var_3_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((sub_step_154_1 + pub_r000553_9_1) + 15) & 127;
  int sub_step_164_2 = ((sub_step_154_2 + pub_r000553_9_2) + 15) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000553_23_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000553_23_2) & 127;
  st_var_0_1.buffer[2] = stage_v_164_1 & 15;
  st_var_0_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((stage_v_90_1 + pub_r000553_14_1) + 6) & 127;
  int sub_step_165_2 = ((stage_v_90_2 + pub_r000553_14_2) + 6) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000553_10_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000553_10_2) & 127;
  st_var_1_1.buffer[0] = stage_v_165_1 & 15;
  st_var_1_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((stage_v_117_1 + pub_r000553_3_1) + 15) & 127;
  int sub_step_166_2 = ((stage_v_117_2 + pub_r000553_3_2) + 15) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000553_14_2) & 127;
  st_var_2_1.buffer[1] = stage_v_166_1 & 15;
  st_var_2_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((sec_r000553_8_1 + pub_r000553_1_1) + 23) & 127;
  int sub_step_167_2 = ((sec_r000553_8_2 + pub_r000553_1_2) + 23) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000553_16_2) & 127;
  st_var_3_1.buffer[2] = stage_v_167_1 & 15;
  st_var_3_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((sec_r000553_5_1 + pub_r000553_6_1) + 21) & 127;
  int sub_step_168_2 = ((sec_r000553_5_2 + pub_r000553_6_2) + 21) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000553_9_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000553_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((stage_v_157_1 + pub_r000553_2_1) + 22) & 127;
  int sub_step_169_2 = ((stage_v_157_2 + pub_r000553_2_2) + 22) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000553_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((stage_v_130_1 + pub_r000553_14_1) + 12) & 127;
  int sub_step_170_2 = ((stage_v_130_2 + pub_r000553_14_2) + 12) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000553_22_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((sec_r000553_0_1 + pub_r000553_12_1) + 21) & 127;
  int sub_step_171_2 = ((sec_r000553_0_2 + pub_r000553_12_2) + 21) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000553_21_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000553_21_2) & 127;
  st_var_3_1.buffer[0] = stage_v_171_1 & 15;
  st_var_3_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((sub_step_125_1 + pub_r000553_16_1) + 29) & 127;
  int sub_step_172_2 = ((sub_step_125_2 + pub_r000553_16_2) + 29) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000553_3_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000553_3_2) & 127;
  st_var_0_1.buffer[1] = stage_v_172_1 & 15;
  st_var_0_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((stage_v_112_1 + pub_r000553_12_1) + 20) & 127;
  int sub_step_173_2 = ((stage_v_112_2 + pub_r000553_12_2) + 20) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000553_17_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000553_17_2) & 127;
  st_var_1_1.buffer[2] = stage_v_173_1 & 15;
  st_var_1_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((sub_step_76_1 + pub_r000553_2_1) + 21) & 127;
  int sub_step_174_2 = ((sub_step_76_2 + pub_r000553_2_2) + 21) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000553_7_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000553_7_2) & 127;
  st_var_2_1.buffer[0] = stage_v_174_1 & 15;
  st_var_2_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((sec_r000553_5_1 + pub_r000553_3_1) + 5) & 127;
  int sub_step_175_2 = ((sec_r000553_5_2 + pub_r000553_3_2) + 5) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000553_12_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000553_12_2) & 127;
  st_var_3_1.buffer[1] = stage_v_175_1 & 15;
  st_var_3_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((sec_r000553_7_1 + pub_r000553_2_1) + 18) & 127;
  int sub_step_176_2 = ((sec_r000553_7_2 + pub_r000553_2_2) + 18) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000553_20_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000553_20_2) & 127;
  st_var_0_1.buffer[2] = stage_v_176_1 & 15;
  st_var_0_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((stage_v_77_1 + pub_r000553_22_1) + 13) & 127;
  int sub_step_177_2 = ((stage_v_77_2 + pub_r000553_22_2) + 13) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000553_15_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000553_15_2) & 127;
  st_var_1_1.buffer[0] = stage_v_177_1 & 15;
  st_var_1_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((sec_r000553_5_1 + pub_r000553_15_1) + 20) & 127;
  int sub_step_178_2 = ((sec_r000553_5_2 + pub_r000553_15_2) + 20) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000553_16_2) & 127;
  st_var_2_1.buffer[1] = stage_v_178_1 & 15;
  st_var_2_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((sec_r000553_2_1 + pub_r000553_19_1) + 8) & 127;
  int sub_step_179_2 = ((sec_r000553_2_2 + pub_r000553_19_2) + 8) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000553_6_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000553_6_2) & 127;
  st_var_3_1.buffer[2] = stage_v_179_1 & 15;
  st_var_3_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((sec_r000553_17_1 + pub_r000553_15_1) + 8) & 127;
  int sub_step_180_2 = ((sec_r000553_17_2 + pub_r000553_15_2) + 8) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000553_19_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000553_19_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((sec_r000553_0_1 + pub_r000553_8_1) + 5) & 127;
  int sub_step_181_2 = ((sec_r000553_0_2 + pub_r000553_8_2) + 5) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000553_22_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((stage_v_156_1 + pub_r000553_9_1) + 34) & 127;
  int sub_step_182_2 = ((stage_v_156_2 + pub_r000553_9_2) + 34) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000553_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((sec_r000553_3_1 + pub_r000553_12_1) + 8) & 127;
  int sub_step_183_2 = ((sec_r000553_3_2 + pub_r000553_12_2) + 8) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000553_11_2) & 127;
  st_var_3_1.buffer[0] = stage_v_183_1 & 15;
  st_var_3_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((sec_r000553_5_1 + pub_r000553_20_1) + 22) & 127;
  int sub_step_184_2 = ((sec_r000553_5_2 + pub_r000553_20_2) + 22) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000553_8_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000553_8_2) & 127;
  st_var_0_1.buffer[1] = stage_v_184_1 & 15;
  st_var_0_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((sub_step_153_1 + pub_r000553_6_1) + 33) & 127;
  int sub_step_185_2 = ((sub_step_153_2 + pub_r000553_6_2) + 33) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000553_0_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000553_0_2) & 127;
  st_var_1_1.buffer[2] = stage_v_185_1 & 15;
  st_var_1_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((sec_r000553_14_1 + pub_r000553_6_1) + 16) & 127;
  int sub_step_186_2 = ((sec_r000553_14_2 + pub_r000553_6_2) + 16) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000553_13_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000553_13_2) & 127;
  st_var_2_1.buffer[0] = stage_v_186_1 & 15;
  st_var_2_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((sub_step_138_1 + pub_r000553_17_1) + 14) & 127;
  int sub_step_187_2 = ((sub_step_138_2 + pub_r000553_17_2) + 14) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000553_16_2) & 127;
  st_var_3_1.buffer[1] = stage_v_187_1 & 15;
  st_var_3_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sec_r000553_9_1 + pub_r000553_16_1) + 32) & 127;
  int sub_step_188_2 = ((sec_r000553_9_2 + pub_r000553_16_2) + 32) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000553_7_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000553_7_2) & 127;
  st_var_0_1.buffer[2] = stage_v_188_1 & 15;
  st_var_0_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((sub_step_121_1 + pub_r000553_18_1) + 25) & 127;
  int sub_step_189_2 = ((sub_step_121_2 + pub_r000553_18_2) + 25) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000553_18_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000553_18_2) & 127;
  st_var_1_1.buffer[0] = stage_v_189_1 & 15;
  st_var_1_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((sec_r000553_8_1 + pub_r000553_10_1) + 23) & 127;
  int sub_step_190_2 = ((sec_r000553_8_2 + pub_r000553_10_2) + 23) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000553_12_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000553_12_2) & 127;
  st_var_2_1.buffer[1] = stage_v_190_1 & 15;
  st_var_2_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((stage_v_129_1 + pub_r000553_0_1) + 6) & 127;
  int sub_step_191_2 = ((stage_v_129_2 + pub_r000553_0_2) + 6) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000553_17_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000553_17_2) & 127;
  st_var_3_1.buffer[2] = stage_v_191_1 & 15;
  st_var_3_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((sub_step_147_1 + pub_r000553_13_1) + 18) & 127;
  int sub_step_192_2 = ((sub_step_147_2 + pub_r000553_13_2) + 18) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000553_21_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000553_21_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((stage_v_147_1 + pub_r000553_16_1) + 16) & 127;
  int sub_step_193_2 = ((stage_v_147_2 + pub_r000553_16_2) + 16) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000553_13_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000553_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((sub_step_143_1 + pub_r000553_19_1) + 11) & 127;
  int sub_step_194_2 = ((sub_step_143_2 + pub_r000553_19_2) + 11) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000553_22_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sub_step_118_1 + pub_r000553_1_1) + 11) & 127;
  int sub_step_195_2 = ((sub_step_118_2 + pub_r000553_1_2) + 11) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000553_0_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000553_0_2) & 127;
  st_var_3_1.buffer[0] = stage_v_195_1 & 15;
  st_var_3_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((stage_v_174_1 + pub_r000553_4_1) + 22) & 127;
  int sub_step_196_2 = ((stage_v_174_2 + pub_r000553_4_2) + 22) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000553_22_2) & 127;
  st_var_0_1.buffer[1] = stage_v_196_1 & 15;
  st_var_0_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((stage_v_173_1 + pub_r000553_16_1) + 7) & 127;
  int sub_step_197_2 = ((stage_v_173_2 + pub_r000553_16_2) + 7) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000553_3_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000553_3_2) & 127;
  st_var_1_1.buffer[2] = stage_v_197_1 & 15;
  st_var_1_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((sub_step_90_1 + pub_r000553_13_1) + 34) & 127;
  int sub_step_198_2 = ((sub_step_90_2 + pub_r000553_13_2) + 34) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000553_20_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000553_20_2) & 127;
  st_var_2_1.buffer[0] = stage_v_198_1 & 15;
  st_var_2_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((stage_v_122_1 + pub_r000553_23_1) + 17) & 127;
  int sub_step_199_2 = ((stage_v_122_2 + pub_r000553_23_2) + 17) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000553_16_2) & 127;
  st_var_3_1.buffer[1] = stage_v_199_1 & 15;
  st_var_3_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((stage_v_162_1 + pub_r000553_9_1) + 20) & 127;
  int sub_step_200_2 = ((stage_v_162_2 + pub_r000553_9_2) + 20) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000553_18_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000553_18_2) & 127;
  st_var_0_1.buffer[2] = stage_v_200_1 & 15;
  st_var_0_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((stage_v_119_1 + pub_r000553_7_1) + 13) & 127;
  int sub_step_201_2 = ((stage_v_119_2 + pub_r000553_7_2) + 13) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000553_10_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000553_10_2) & 127;
  st_var_1_1.buffer[0] = stage_v_201_1 & 15;
  st_var_1_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((sec_r000553_12_1 + pub_r000553_22_1) + 10) & 127;
  int sub_step_202_2 = ((sec_r000553_12_2 + pub_r000553_22_2) + 10) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000553_16_2) & 127;
  st_var_2_1.buffer[1] = stage_v_202_1 & 15;
  st_var_2_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((sub_step_158_1 + pub_r000553_3_1) + 31) & 127;
  int sub_step_203_2 = ((sub_step_158_2 + pub_r000553_3_2) + 31) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000553_15_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000553_15_2) & 127;
  st_var_3_1.buffer[2] = stage_v_203_1 & 15;
  st_var_3_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((stage_v_115_1 + pub_r000553_20_1) + 12) & 127;
  int sub_step_204_2 = ((stage_v_115_2 + pub_r000553_20_2) + 12) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000553_22_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sub_step_194_1 + pub_r000553_21_1) + 31) & 127;
  int sub_step_205_2 = ((sub_step_194_2 + pub_r000553_21_2) + 31) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000553_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((sub_step_122_1 + pub_r000553_7_1) + 8) & 127;
  int sub_step_206_2 = ((sub_step_122_2 + pub_r000553_7_2) + 8) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000553_2_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000553_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((sub_step_80_1 + pub_r000553_18_1) + 29) & 127;
  int sub_step_207_2 = ((sub_step_80_2 + pub_r000553_18_2) + 29) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000553_5_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000553_5_2) & 127;
  st_var_3_1.buffer[0] = stage_v_207_1 & 15;
  st_var_3_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((stage_v_139_1 + pub_r000553_19_1) + 8) & 127;
  int sub_step_208_2 = ((stage_v_139_2 + pub_r000553_19_2) + 8) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000553_6_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000553_6_2) & 127;
  st_var_0_1.buffer[1] = stage_v_208_1 & 15;
  st_var_0_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((sub_step_188_1 + pub_r000553_11_1) + 10) & 127;
  int sub_step_209_2 = ((sub_step_188_2 + pub_r000553_11_2) + 10) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000553_8_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000553_8_2) & 127;
  st_var_1_1.buffer[2] = stage_v_209_1 & 15;
  st_var_1_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((stage_v_103_1 + pub_r000553_17_1) + 28) & 127;
  int sub_step_210_2 = ((stage_v_103_2 + pub_r000553_17_2) + 28) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000553_0_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000553_0_2) & 127;
  st_var_2_1.buffer[0] = stage_v_210_1 & 15;
  st_var_2_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sec_r000553_4_1 + pub_r000553_13_1) + 19) & 127;
  int sub_step_211_2 = ((sec_r000553_4_2 + pub_r000553_13_2) + 19) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000553_10_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000553_10_2) & 127;
  st_var_3_1.buffer[1] = stage_v_211_1 & 15;
  st_var_3_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((stage_v_74_1 + pub_r000553_18_1) + 13) & 127;
  int sub_step_212_2 = ((stage_v_74_2 + pub_r000553_18_2) + 13) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000553_11_2) & 127;
  st_var_0_1.buffer[2] = stage_v_212_1 & 15;
  st_var_0_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((sec_r000553_3_1 + pub_r000553_14_1) + 28) & 127;
  int sub_step_213_2 = ((sec_r000553_3_2 + pub_r000553_14_2) + 28) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000553_8_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000553_8_2) & 127;
  st_var_1_1.buffer[0] = stage_v_213_1 & 15;
  st_var_1_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((sub_step_137_1 + pub_r000553_4_1) + 6) & 127;
  int sub_step_214_2 = ((sub_step_137_2 + pub_r000553_4_2) + 6) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000553_2_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000553_2_2) & 127;
  st_var_2_1.buffer[1] = stage_v_214_1 & 15;
  st_var_2_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((sub_step_94_1 + pub_r000553_20_1) + 35) & 127;
  int sub_step_215_2 = ((sub_step_94_2 + pub_r000553_20_2) + 35) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000553_21_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000553_21_2) & 127;
  st_var_3_1.buffer[2] = stage_v_215_1 & 15;
  st_var_3_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((stage_v_154_1 + pub_r000553_10_1) + 22) & 127;
  int sub_step_216_2 = ((stage_v_154_2 + pub_r000553_10_2) + 22) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000553_18_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000553_18_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((stage_v_146_1 + pub_r000553_16_1) + 12) & 127;
  int sub_step_217_2 = ((stage_v_146_2 + pub_r000553_16_2) + 12) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000553_13_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000553_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((sec_r000553_18_1 + pub_r000553_8_1) + 8) & 127;
  int sub_step_218_2 = ((sec_r000553_18_2 + pub_r000553_8_2) + 8) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000553_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((sec_r000553_1_1 + pub_r000553_17_1) + 13) & 127;
  int sub_step_219_2 = ((sec_r000553_1_2 + pub_r000553_17_2) + 13) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000553_7_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000553_7_2) & 127;
  st_var_3_1.buffer[0] = stage_v_219_1 & 15;
  st_var_3_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((sub_step_213_1 + pub_r000553_15_1) + 26) & 127;
  int sub_step_220_2 = ((sub_step_213_2 + pub_r000553_15_2) + 26) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000553_3_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000553_3_2) & 127;
  st_var_0_1.buffer[1] = stage_v_220_1 & 15;
  st_var_0_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((sub_step_200_1 + pub_r000553_4_1) + 27) & 127;
  int sub_step_221_2 = ((sub_step_200_2 + pub_r000553_4_2) + 27) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000553_14_2) & 127;
  st_var_1_1.buffer[2] = stage_v_221_1 & 15;
  st_var_1_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((stage_v_218_1 + pub_r000553_14_1) + 27) & 127;
  int sub_step_222_2 = ((stage_v_218_2 + pub_r000553_14_2) + 27) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000553_17_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000553_17_2) & 127;
  st_var_2_1.buffer[0] = stage_v_222_1 & 15;
  st_var_2_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((stage_v_167_1 + pub_r000553_6_1) + 29) & 127;
  int sub_step_223_2 = ((stage_v_167_2 + pub_r000553_6_2) + 29) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000553_22_2) & 127;
  st_var_3_1.buffer[1] = stage_v_223_1 & 15;
  st_var_3_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((sec_r000553_13_1 + pub_r000553_3_1) + 5) & 127;
  int sub_step_224_2 = ((sec_r000553_13_2 + pub_r000553_3_2) + 5) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000553_1_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000553_1_2) & 127;
  st_var_0_1.buffer[2] = stage_v_224_1 & 15;
  st_var_0_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((sub_step_71_1 + pub_r000553_21_1) + 15) & 127;
  int sub_step_225_2 = ((sub_step_71_2 + pub_r000553_21_2) + 15) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000553_13_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000553_13_2) & 127;
  st_var_1_1.buffer[0] = stage_v_225_1 & 15;
  st_var_1_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sub_step_92_1 + pub_r000553_15_1) + 32) & 127;
  int sub_step_226_2 = ((sub_step_92_2 + pub_r000553_15_2) + 32) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000553_15_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000553_15_2) & 127;
  st_var_2_1.buffer[1] = stage_v_226_1 & 15;
  st_var_2_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((sec_r000553_9_1 + pub_r000553_5_1) + 29) & 127;
  int sub_step_227_2 = ((sec_r000553_9_2 + pub_r000553_5_2) + 29) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000553_16_2) & 127;
  st_var_3_1.buffer[2] = stage_v_227_1 & 15;
  st_var_3_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((stage_v_105_1 + pub_r000553_13_1) + 30) & 127;
  int sub_step_228_2 = ((stage_v_105_2 + pub_r000553_13_2) + 30) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000553_10_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000553_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((sub_step_156_1 + pub_r000553_5_1) + 21) & 127;
  int sub_step_229_2 = ((sub_step_156_2 + pub_r000553_5_2) + 21) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000553_5_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000553_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((sec_r000553_6_1 + pub_r000553_9_1) + 5) & 127;
  int sub_step_230_2 = ((sec_r000553_6_2 + pub_r000553_9_2) + 5) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000553_20_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000553_20_2) & 127;
  st_var_2_1.buffer[2] = stage_v_230_1 & 15;
  st_var_2_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int sub_step_231_1 = ((sec_r000553_15_1 + pub_r000553_20_1) + 6) & 127;
  int sub_step_231_2 = ((sec_r000553_15_2 + pub_r000553_20_2) + 6) & 127;
  int stage_v_231_1 = ((sub_step_231_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_231_2 = ((sub_step_231_2 * 2) + pub_r000553_11_2) & 127;
  st_var_3_1.buffer[0] = stage_v_231_1 & 15;
  st_var_3_2.buffer[0] = stage_v_231_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int sub_step_232_1 = ((stage_v_199_1 + pub_r000553_16_1) + 6) & 127;
  int sub_step_232_2 = ((stage_v_199_2 + pub_r000553_16_2) + 6) & 127;
  int stage_v_232_1 = ((sub_step_232_1 * 2) + pub_r000553_9_1) & 127;
  int stage_v_232_2 = ((sub_step_232_2 * 2) + pub_r000553_9_2) & 127;
  st_var_0_1.buffer[1] = stage_v_232_1 & 15;
  st_var_0_2.buffer[1] = stage_v_232_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int sub_step_233_1 = ((sec_r000553_6_1 + pub_r000553_8_1) + 20) & 127;
  int sub_step_233_2 = ((sec_r000553_6_2 + pub_r000553_8_2) + 20) & 127;
  int stage_v_233_1 = ((sub_step_233_1 * 2) + pub_r000553_15_1) & 127;
  int stage_v_233_2 = ((sub_step_233_2 * 2) + pub_r000553_15_2) & 127;
  st_var_1_1.buffer[2] = stage_v_233_1 & 15;
  st_var_1_2.buffer[2] = stage_v_233_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int sub_step_234_1 = ((stage_v_139_1 + pub_r000553_20_1) + 33) & 127;
  int sub_step_234_2 = ((stage_v_139_2 + pub_r000553_20_2) + 33) & 127;
  int stage_v_234_1 = ((sub_step_234_1 * 2) + pub_r000553_15_1) & 127;
  int stage_v_234_2 = ((sub_step_234_2 * 2) + pub_r000553_15_2) & 127;
  st_var_2_1.buffer[0] = stage_v_234_1 & 15;
  st_var_2_2.buffer[0] = stage_v_234_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int sub_step_235_1 = ((sub_step_108_1 + pub_r000553_3_1) + 29) & 127;
  int sub_step_235_2 = ((sub_step_108_2 + pub_r000553_3_2) + 29) & 127;
  int stage_v_235_1 = ((sub_step_235_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_235_2 = ((sub_step_235_2 * 2) + pub_r000553_16_2) & 127;
  st_var_3_1.buffer[1] = stage_v_235_1 & 15;
  st_var_3_2.buffer[1] = stage_v_235_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int sub_step_236_1 = ((stage_v_88_1 + pub_r000553_6_1) + 17) & 127;
  int sub_step_236_2 = ((stage_v_88_2 + pub_r000553_6_2) + 17) & 127;
  int stage_v_236_1 = ((sub_step_236_1 * 2) + pub_r000553_18_1) & 127;
  int stage_v_236_2 = ((sub_step_236_2 * 2) + pub_r000553_18_2) & 127;
  st_var_0_1.buffer[2] = stage_v_236_1 & 15;
  st_var_0_2.buffer[2] = stage_v_236_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int sub_step_237_1 = ((stage_v_209_1 + pub_r000553_12_1) + 32) & 127;
  int sub_step_237_2 = ((stage_v_209_2 + pub_r000553_12_2) + 32) & 127;
  int stage_v_237_1 = ((sub_step_237_1 * 2) + pub_r000553_10_1) & 127;
  int stage_v_237_2 = ((sub_step_237_2 * 2) + pub_r000553_10_2) & 127;
  st_var_1_1.buffer[0] = stage_v_237_1 & 15;
  st_var_1_2.buffer[0] = stage_v_237_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int sub_step_238_1 = ((stage_v_120_1 + pub_r000553_2_1) + 33) & 127;
  int sub_step_238_2 = ((stage_v_120_2 + pub_r000553_2_2) + 33) & 127;
  int stage_v_238_1 = ((sub_step_238_1 * 2) + pub_r000553_16_1) & 127;
  int stage_v_238_2 = ((sub_step_238_2 * 2) + pub_r000553_16_2) & 127;
  st_var_2_1.buffer[1] = stage_v_238_1 & 15;
  st_var_2_2.buffer[1] = stage_v_238_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int sub_step_239_1 = ((sec_r000553_18_1 + pub_r000553_4_1) + 35) & 127;
  int sub_step_239_2 = ((sec_r000553_18_2 + pub_r000553_4_2) + 35) & 127;
  int stage_v_239_1 = ((sub_step_239_1 * 2) + pub_r000553_22_1) & 127;
  int stage_v_239_2 = ((sub_step_239_2 * 2) + pub_r000553_22_2) & 127;
  st_var_3_1.buffer[2] = stage_v_239_1 & 15;
  st_var_3_2.buffer[2] = stage_v_239_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int sub_step_240_1 = ((sec_r000553_11_1 + pub_r000553_12_1) + 14) & 127;
  int sub_step_240_2 = ((sec_r000553_11_2 + pub_r000553_12_2) + 14) & 127;
  int stage_v_240_1 = ((sub_step_240_1 * 2) + pub_r000553_14_1) & 127;
  int stage_v_240_2 = ((sub_step_240_2 * 2) + pub_r000553_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_240_1 & 15;
  st_var_0_2.buffer[0] = stage_v_240_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int sub_step_241_1 = ((stage_v_204_1 + pub_r000553_4_1) + 32) & 127;
  int sub_step_241_2 = ((stage_v_204_2 + pub_r000553_4_2) + 32) & 127;
  int stage_v_241_1 = ((sub_step_241_1 * 2) + pub_r000553_23_1) & 127;
  int stage_v_241_2 = ((sub_step_241_2 * 2) + pub_r000553_23_2) & 127;
  st_var_1_1.buffer[1] = stage_v_241_1 & 15;
  st_var_1_2.buffer[1] = stage_v_241_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int sub_step_242_1 = ((sec_r000553_7_1 + pub_r000553_7_1) + 25) & 127;
  int sub_step_242_2 = ((sec_r000553_7_2 + pub_r000553_7_2) + 25) & 127;
  int stage_v_242_1 = ((sub_step_242_1 * 2) + pub_r000553_6_1) & 127;
  int stage_v_242_2 = ((sub_step_242_2 * 2) + pub_r000553_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_242_1 & 15;
  st_var_2_2.buffer[2] = stage_v_242_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int sub_step_243_1 = ((sec_r000553_3_1 + pub_r000553_16_1) + 29) & 127;
  int sub_step_243_2 = ((sec_r000553_3_2 + pub_r000553_16_2) + 29) & 127;
  int stage_v_243_1 = ((sub_step_243_1 * 2) + pub_r000553_17_1) & 127;
  int stage_v_243_2 = ((sub_step_243_2 * 2) + pub_r000553_17_2) & 127;
  st_var_3_1.buffer[0] = stage_v_243_1 & 15;
  st_var_3_2.buffer[0] = stage_v_243_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int sub_step_244_1 = ((stage_v_126_1 + pub_r000553_4_1) + 34) & 127;
  int sub_step_244_2 = ((stage_v_126_2 + pub_r000553_4_2) + 34) & 127;
  int stage_v_244_1 = ((sub_step_244_1 * 2) + pub_r000553_18_1) & 127;
  int stage_v_244_2 = ((sub_step_244_2 * 2) + pub_r000553_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_244_1 & 15;
  st_var_0_2.buffer[1] = stage_v_244_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int sub_step_245_1 = ((sec_r000553_13_1 + pub_r000553_14_1) + 31) & 127;
  int sub_step_245_2 = ((sec_r000553_13_2 + pub_r000553_14_2) + 31) & 127;
  int stage_v_245_1 = ((sub_step_245_1 * 2) + pub_r000553_20_1) & 127;
  int stage_v_245_2 = ((sub_step_245_2 * 2) + pub_r000553_20_2) & 127;
  st_var_1_1.buffer[2] = stage_v_245_1 & 15;
  st_var_1_2.buffer[2] = stage_v_245_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int sub_step_246_1 = ((sec_r000553_14_1 + pub_r000553_19_1) + 31) & 127;
  int sub_step_246_2 = ((sec_r000553_14_2 + pub_r000553_19_2) + 31) & 127;
  int stage_v_246_1 = ((sub_step_246_1 * 2) + pub_r000553_11_1) & 127;
  int stage_v_246_2 = ((sub_step_246_2 * 2) + pub_r000553_11_2) & 127;
  st_var_2_1.buffer[0] = stage_v_246_1 & 15;
  st_var_2_2.buffer[0] = stage_v_246_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int sub_step_247_1 = ((sub_step_243_1 + pub_r000553_3_1) + 30) & 127;
  int sub_step_247_2 = ((sub_step_243_2 + pub_r000553_3_2) + 30) & 127;
  int stage_v_247_1 = ((sub_step_247_1 * 2) + pub_r000553_15_1) & 127;
  int stage_v_247_2 = ((sub_step_247_2 * 2) + pub_r000553_15_2) & 127;
  st_var_3_1.buffer[1] = stage_v_247_1 & 15;
  st_var_3_2.buffer[1] = stage_v_247_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int sub_step_248_1 = ((sec_r000553_3_1 + pub_r000553_5_1) + 9) & 127;
  int sub_step_248_2 = ((sec_r000553_3_2 + pub_r000553_5_2) + 9) & 127;
  int stage_v_248_1 = ((sub_step_248_1 * 2) + pub_r000553_19_1) & 127;
  int stage_v_248_2 = ((sub_step_248_2 * 2) + pub_r000553_19_2) & 127;
  st_var_0_1.buffer[2] = stage_v_248_1 & 15;
  st_var_0_2.buffer[2] = stage_v_248_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000553_11_1 == pub_r000553_11_2);
  __CPROVER_assume(pub_r000553_22_1 == pub_r000553_22_2);
  __CPROVER_assume(pub_r000553_23_1 == pub_r000553_23_2);
  __CPROVER_assume(sec_r000553_15_1 != sec_r000553_15_2);
  __CPROVER_assume(pub_r000553_3_1 == pub_r000553_3_2);
  __CPROVER_assume(pub_r000553_14_1 == pub_r000553_14_2);
  __CPROVER_assume(pub_r000553_7_1 == pub_r000553_7_2);
  __CPROVER_assume(sec_r000553_7_1 != sec_r000553_7_2);
  __CPROVER_assume(sec_r000553_10_1 != sec_r000553_10_2);
  __CPROVER_assume(sec_r000553_18_1 != sec_r000553_18_2);
  __CPROVER_assume(pub_r000553_17_1 == pub_r000553_17_2);
  __CPROVER_assume(sec_r000553_5_1 != sec_r000553_5_2);
  __CPROVER_assume(pub_r000553_12_1 == pub_r000553_12_2);
  __CPROVER_assume(sec_r000553_13_1 != sec_r000553_13_2);
  __CPROVER_assume(sec_r000553_16_1 != sec_r000553_16_2);
  __CPROVER_assume(pub_r000553_13_1 == pub_r000553_13_2);
  __CPROVER_assume(pub_r000553_0_1 == pub_r000553_0_2);
  __CPROVER_assume(pub_r000553_19_1 == pub_r000553_19_2);
  __CPROVER_assume(sec_r000553_1_1 != sec_r000553_1_2);
  __CPROVER_assume(pub_r000553_9_1 == pub_r000553_9_2);
  __CPROVER_assume(pub_r000553_21_1 == pub_r000553_21_2);
  __CPROVER_assume(sec_r000553_12_1 != sec_r000553_12_2);
  __CPROVER_assume(sec_r000553_0_1 != sec_r000553_0_2);
  __CPROVER_assume(sec_r000553_2_1 != sec_r000553_2_2);
  __CPROVER_assume(pub_r000553_1_1 == pub_r000553_1_2);
  __CPROVER_assume(sec_r000553_14_1 != sec_r000553_14_2);
  __CPROVER_assume(sec_r000553_19_1 != sec_r000553_19_2);
  __CPROVER_assume(pub_r000553_16_1 == pub_r000553_16_2);
  __CPROVER_assume(pub_r000553_4_1 == pub_r000553_4_2);
  __CPROVER_assume(pub_r000553_10_1 == pub_r000553_10_2);
  __CPROVER_assume(pub_r000553_15_1 == pub_r000553_15_2);
  __CPROVER_assume(pub_r000553_8_1 == pub_r000553_8_2);
  __CPROVER_assume(sec_r000553_8_1 != sec_r000553_8_2);
  __CPROVER_assume(sec_r000553_11_1 != sec_r000553_11_2);
  __CPROVER_assume(pub_r000553_2_1 == pub_r000553_2_2);
  __CPROVER_assume(pub_r000553_5_1 == pub_r000553_5_2);
  __CPROVER_assume(pub_r000553_6_1 == pub_r000553_6_2);
  __CPROVER_assume(sec_r000553_17_1 != sec_r000553_17_2);
  __CPROVER_assume(pub_r000553_18_1 == pub_r000553_18_2);
  __CPROVER_assume(sec_r000553_4_1 != sec_r000553_4_2);
  __CPROVER_assume(sec_r000553_9_1 != sec_r000553_9_2);
  __CPROVER_assume(sec_r000553_3_1 != sec_r000553_3_2);
  __CPROVER_assume(pub_r000553_20_1 == pub_r000553_20_2);
  __CPROVER_assume(sec_r000553_6_1 != sec_r000553_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.channels == st_var_3_2.channels);
  assert(st_var_3_1.peak == st_var_3_2.peak);
  assert(st_var_3_1.rms == st_var_3_2.rms);
  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
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
}


