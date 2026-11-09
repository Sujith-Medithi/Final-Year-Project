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
struct EventLog_R001326_2613_0
{
  int seq;
  short facility;
  short code;
  int buffer[3];
};
struct FilterState_R001326_2613_1
{
  unsigned char gain_db;
  int damping;
  short prev_in;
  short prev_out;
  int mode;
  int buffer[3];
};
struct AudioFrame_R001326_2613_2
{
  unsigned char rms;
  short sample_rate;
  int channels;
  int gain;
  int buffer[3];
};
union ColorPixel_R001326_2613_0
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
void fn_R001326_2613_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st_1 = {0};
  struct FilterState_R001326_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_46_1 = local_arr_1[aux_1 % 3];
  int vector_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_46_1 == vector_46_2);
}

int fn_R001326_2613_0(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_46 = local_arr[aux % 3];
  acc = (acc + (vector_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001326_2613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st_1 = {0};
  struct AudioFrame_R001326_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int delta_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_28_1)
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

  switch (delta_28_2)
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

  int segment_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_35_1) & 63;
  aux_2 = (aux_2 + segment_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_13_1 > 42)
  {
    acc_1 = ((acc_1 + (weight_13_1 * 2)) + 5) & 127;
    aux_1 ^= weight_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_13_2 > 42)
  {
    acc_2 = ((acc_2 + (weight_13_2 * 2)) + 5) & 127;
    aux_2 ^= weight_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_28_1 == delta_28_2);
  assert(segment_35_1 == segment_35_2);
  assert(weight_13_1 == weight_13_2);
}

int fn_R001326_2613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int delta_28 = (aux + st.buffer[1]) & 3;
  switch (delta_28)
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

  int segment_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_35) & 63;
  acc ^= aux;
  int weight_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_13 > 42)
  {
    acc = ((acc + (weight_13 * 2)) + 5) & 127;
    aux ^= weight_13 & 15;
  }
  else
  {
    acc = ((acc - weight_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001326_2613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st_1 = {0};
  struct FilterState_R001326_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_74_1) & 63;
  aux_2 = (aux_2 + mask_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_14_1 > 12)
  {
    acc_1 = ((acc_1 + (checksum_14_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_14_2 > 12)
  {
    acc_2 = ((acc_2 + (checksum_14_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_74_1 == mask_74_2);
  assert(checksum_14_1 == checksum_14_2);
}

int fn_R001326_2613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_74) & 63;
  acc ^= aux;
  int checksum_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_14 > 12)
  {
    acc = ((acc + (checksum_14 * 2)) + 5) & 127;
    aux ^= checksum_14 & 15;
  }
  else
  {
    acc = ((acc - checksum_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001326_2613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st_1 = {0};
  struct EventLog_R001326_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int accumulator_43_1 = 0;
  int accumulator_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_43_1 = ((accumulator_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_43_2 = ((accumulator_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_43_1) & 127;
    acc_2 = (acc_2 + accumulator_43_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_90_1 = local_arr_1[aux_1 % 3];
  int pivot_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_90_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_50_1)
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

  switch (offset_50_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_43_1 == accumulator_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_90_1 == pivot_90_2);
  assert(offset_50_1 == offset_50_2);
}

int fn_R001326_2613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int accumulator_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_43 = ((accumulator_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_43) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_90 = local_arr[aux % 3];
  acc = (acc + (pivot_90 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_50 = (aux + st.buffer[1]) & 3;
  switch (offset_50)
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

void fn_R001326_2613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st_1 = {0};
  struct AudioFrame_R001326_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int offset_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_80_1 > 36)
  {
    acc_1 = ((acc_1 + (offset_80_1 * 2)) + 5) & 127;
    aux_1 ^= offset_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_80_2 > 36)
  {
    acc_2 = ((acc_2 + (offset_80_2 * 2)) + 5) & 127;
    aux_2 ^= offset_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_36_1 = 0;
  int checksum_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_36_1 = ((checksum_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_36_2 = ((checksum_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_36_1) & 127;
    acc_2 = (acc_2 + checksum_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_80_1 == offset_80_2);
  assert(checksum_36_1 == checksum_36_2);
}

int fn_R001326_2613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int offset_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_80 > 36)
  {
    acc = ((acc + (offset_80 * 2)) + 5) & 127;
    aux ^= offset_80 & 15;
  }
  else
  {
    acc = ((acc - offset_80) + 11) & 127;
    aux += 3;
  }
  int checksum_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_36 = ((checksum_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001326_2613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st_1 = {0};
  struct AudioFrame_R001326_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int stride_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_39_1)
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

  switch (stride_39_2)
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
  int anchor_99_1 = local_arr_1[aux_1 % 3];
  int anchor_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_99_2 * 2)) & 127;
  int segment_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_72_1) & 63;
  aux_2 = (aux_2 + segment_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_77_1 > 18)
  {
    acc_1 = ((acc_1 + (bound_77_1 * 2)) + 5) & 127;
    aux_1 ^= bound_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_77_2 > 18)
  {
    acc_2 = ((acc_2 + (bound_77_2 * 2)) + 5) & 127;
    aux_2 ^= bound_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_39_1 == stride_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_99_1 == anchor_99_2);
  assert(segment_72_1 == segment_72_2);
  assert(bound_77_1 == bound_77_2);
}

int fn_R001326_2613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int stride_39 = (aux + st.buffer[1]) & 3;
  switch (stride_39)
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
  int anchor_99 = local_arr[aux % 3];
  acc = (acc + (anchor_99 * 2)) & 127;
  int segment_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_72) & 63;
  acc ^= aux;
  int bound_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_77 > 18)
  {
    acc = ((acc + (bound_77 * 2)) + 5) & 127;
    aux ^= bound_77 & 15;
  }
  else
  {
    acc = ((acc - bound_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001326_2613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st_1 = {0};
  struct FilterState_R001326_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int window_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_15_1)
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

  switch (window_15_2)
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

  int threshold_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_49_1) & 63;
  aux_2 = (aux_2 + threshold_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_15_1 == window_15_2);
  assert(threshold_49_1 == threshold_49_2);
}

int fn_R001326_2613_6(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int window_15 = (aux + st.buffer[1]) & 3;
  switch (window_15)
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

  int threshold_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001326_2613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st_1 = {0};
  struct EventLog_R001326_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int checksum_85_1 = 0;
  int checksum_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_85_1 = ((checksum_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_85_2 = ((checksum_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_85_1) & 127;
    acc_2 = (acc_2 + checksum_85_2) & 127;
  }

  int window_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_54_1) & 63;
  aux_2 = (aux_2 + window_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_83_1)
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

  switch (tally_83_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_85_1 == checksum_85_2);
  assert(window_54_1 == window_54_2);
  assert(tally_83_1 == tally_83_2);
}

int fn_R001326_2613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int checksum_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_85 = ((checksum_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_85) & 127;
  }

  int window_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_54) & 63;
  acc ^= aux;
  int tally_83 = (aux + st.buffer[1]) & 3;
  switch (tally_83)
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

void fn_R001326_2613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st_1 = {0};
  struct EventLog_R001326_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int vector_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_18_1) & 63;
  aux_2 = (aux_2 + vector_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_50_1)
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

  switch (damping_50_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_18_1 == vector_18_2);
  assert(damping_50_1 == damping_50_2);
}

int fn_R001326_2613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int vector_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_18) & 63;
  acc ^= aux;
  int damping_50 = (aux + st.buffer[1]) & 3;
  switch (damping_50)
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

void fn_R001326_2613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st_1 = {0};
  struct EventLog_R001326_2613_0 st_2 = {0};
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
  int pivot_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_41_1 > 26)
  {
    acc_1 = ((acc_1 + (pivot_41_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_41_2 > 26)
  {
    acc_2 = ((acc_2 + (pivot_41_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_66_1 = local_arr_1[aux_1 % 3];
  int window_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_66_2 * 2)) & 127;
  int index_reg_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_44_1) & 63;
  aux_2 = (aux_2 + index_reg_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_41_1 == pivot_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_66_1 == window_66_2);
  assert(index_reg_44_1 == index_reg_44_2);
}

int fn_R001326_2613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_41 > 26)
  {
    acc = ((acc + (pivot_41 * 2)) + 5) & 127;
    aux ^= pivot_41 & 15;
  }
  else
  {
    acc = ((acc - pivot_41) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_66 = local_arr[aux % 3];
  acc = (acc + (window_66 * 2)) & 127;
  int index_reg_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001326_2613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st_1 = {0};
  struct EventLog_R001326_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int scale_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_30_1)
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

  switch (scale_30_2)
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

  int index_reg_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_42_1) & 63;
  aux_2 = (aux_2 + index_reg_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_80_1 > 10)
  {
    acc_1 = ((acc_1 + (damping_80_1 * 2)) + 5) & 127;
    aux_1 ^= damping_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_80_2 > 10)
  {
    acc_2 = ((acc_2 + (damping_80_2 * 2)) + 5) & 127;
    aux_2 ^= damping_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_30_1 == scale_30_2);
  assert(index_reg_42_1 == index_reg_42_2);
  assert(damping_80_1 == damping_80_2);
}

int fn_R001326_2613_10(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int scale_30 = (aux + st.buffer[1]) & 3;
  switch (scale_30)
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

  int index_reg_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_42) & 63;
  acc ^= aux;
  int damping_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_80 > 10)
  {
    acc = ((acc + (damping_80 * 2)) + 5) & 127;
    aux ^= damping_80 & 15;
  }
  else
  {
    acc = ((acc - damping_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001326_2613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st_1 = {0};
  struct AudioFrame_R001326_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_74_1 = local_arr_1[aux_1 % 3];
  int tracker_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_74_2 * 2)) & 127;
  int tracker_11_1 = 0;
  int tracker_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_11_1 = ((tracker_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_11_2 = ((tracker_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_11_1) & 127;
    acc_2 = (acc_2 + tracker_11_2) & 127;
  }

  int tracker_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_60_1 > 15)
  {
    acc_1 = ((acc_1 + (tracker_60_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_60_2 > 15)
  {
    acc_2 = ((acc_2 + (tracker_60_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_64_1) & 63;
  aux_2 = (aux_2 + cursor_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_74_1 == tracker_74_2);
  assert(tracker_11_1 == tracker_11_2);
  assert(tracker_60_1 == tracker_60_2);
  assert(cursor_64_1 == cursor_64_2);
}

int fn_R001326_2613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int tracker_74 = local_arr[aux % 3];
  acc = (acc + (tracker_74 * 2)) & 127;
  int tracker_11 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_11 = ((tracker_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_11) & 127;
  }

  int tracker_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_60 > 15)
  {
    acc = ((acc + (tracker_60 * 2)) + 5) & 127;
    aux ^= tracker_60 & 15;
  }
  else
  {
    acc = ((acc - tracker_60) + 11) & 127;
    aux += 3;
  }
  int cursor_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001326_2613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st_1 = {0};
  struct AudioFrame_R001326_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int anchor_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_37_1) & 63;
  aux_2 = (aux_2 + anchor_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_99_1 > 42)
  {
    acc_1 = ((acc_1 + (vector_99_1 * 2)) + 5) & 127;
    aux_1 ^= vector_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_99_2 > 42)
  {
    acc_2 = ((acc_2 + (vector_99_2 * 2)) + 5) & 127;
    aux_2 ^= vector_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_42_1)
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

  switch (delta_42_2)
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
  int stride_53_1 = local_arr_1[aux_1 % 3];
  int stride_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_37_1 == anchor_37_2);
  assert(vector_99_1 == vector_99_2);
  assert(delta_42_1 == delta_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_53_1 == stride_53_2);
}

int fn_R001326_2613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int anchor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_37) & 63;
  acc ^= aux;
  int vector_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_99 > 42)
  {
    acc = ((acc + (vector_99 * 2)) + 5) & 127;
    aux ^= vector_99 & 15;
  }
  else
  {
    acc = ((acc - vector_99) + 11) & 127;
    aux += 3;
  }
  int delta_42 = (aux + st.buffer[1]) & 3;
  switch (delta_42)
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
  int stride_53 = local_arr[aux % 3];
  acc = (acc + (stride_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001326_2613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st_1 = {0};
  struct FilterState_R001326_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int factor_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_63_1) & 63;
  aux_2 = (aux_2 + factor_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_14_1 > 42)
  {
    acc_1 = ((acc_1 + (pivot_14_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_14_2 > 42)
  {
    acc_2 = ((acc_2 + (pivot_14_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_12_1)
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

  switch (pivot_12_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_63_1 == factor_63_2);
  assert(pivot_14_1 == pivot_14_2);
  assert(pivot_12_1 == pivot_12_2);
}

int fn_R001326_2613_13(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_63) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_14 > 42)
  {
    acc = ((acc + (pivot_14 * 2)) + 5) & 127;
    aux ^= pivot_14 & 15;
  }
  else
  {
    acc = ((acc - pivot_14) + 11) & 127;
    aux += 3;
  }
  int pivot_12 = (aux + st.buffer[1]) & 3;
  switch (pivot_12)
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

void fn_R001326_2613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st_1 = {0};
  struct FilterState_R001326_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_49_1)
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

  switch (pivot_49_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_49_1 == pivot_49_2);
}

int fn_R001326_2613_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001326_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_49 = (aux + st.buffer[1]) & 3;
  switch (pivot_49)
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

void fn_R001326_2613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st_1 = {0};
  struct EventLog_R001326_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int sample_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_28_1)
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

  switch (sample_28_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_28_1 == sample_28_2);
}

int fn_R001326_2613_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int sample_28 = (aux + st.buffer[1]) & 3;
  switch (sample_28)
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

void fn_R001326_2613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st_1 = {0};
  struct EventLog_R001326_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quotient_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_52_1 > 39)
  {
    acc_1 = ((acc_1 + (quotient_52_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_52_2 > 39)
  {
    acc_2 = ((acc_2 + (quotient_52_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_67_1 = 0;
  int checksum_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_67_1 = ((checksum_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_67_2 = ((checksum_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_67_1) & 127;
    acc_2 = (acc_2 + checksum_67_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_90_1 = local_arr_1[aux_1 % 3];
  int accumulator_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_52_1 == quotient_52_2);
  assert(checksum_67_1 == checksum_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_90_1 == accumulator_90_2);
}

int fn_R001326_2613_16(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001326_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quotient_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_52 > 39)
  {
    acc = ((acc + (quotient_52 * 2)) + 5) & 127;
    aux ^= quotient_52 & 15;
  }
  else
  {
    acc = ((acc - quotient_52) + 11) & 127;
    aux += 3;
  }
  int checksum_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_67 = ((checksum_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_67) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_90 = local_arr[aux % 3];
  acc = (acc + (accumulator_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001326_2613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st_1 = {0};
  struct AudioFrame_R001326_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int window_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_22_1 > 39)
  {
    acc_1 = ((acc_1 + (window_22_1 * 2)) + 5) & 127;
    aux_1 ^= window_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_22_2 > 39)
  {
    acc_2 = ((acc_2 + (window_22_2 * 2)) + 5) & 127;
    aux_2 ^= window_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_76_1 = local_arr_1[aux_1 % 3];
  int parity_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_22_1 == window_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_76_1 == parity_76_2);
}

int fn_R001326_2613_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001326_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int window_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_22 > 39)
  {
    acc = ((acc + (window_22 * 2)) + 5) & 127;
    aux ^= window_22 & 15;
  }
  else
  {
    acc = ((acc - window_22) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_76 = local_arr[aux % 3];
  acc = (acc + (parity_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001326_0_1;
  int sec_r001326_0_2;
  int sec_r001326_1_1;
  int sec_r001326_1_2;
  int sec_r001326_2_1;
  int sec_r001326_2_2;
  int sec_r001326_3_1;
  int sec_r001326_3_2;
  int sec_r001326_4_1;
  int sec_r001326_4_2;
  int sec_r001326_5_1;
  int sec_r001326_5_2;
  int sec_r001326_6_1;
  int sec_r001326_6_2;
  int sec_r001326_7_1;
  int sec_r001326_7_2;
  int sec_r001326_8_1;
  int sec_r001326_8_2;
  int sec_r001326_9_1;
  int sec_r001326_9_2;
  int sec_r001326_10_1;
  int sec_r001326_10_2;
  int sec_r001326_11_1;
  int sec_r001326_11_2;
  int sec_r001326_12_1;
  int sec_r001326_12_2;
  int sec_r001326_13_1;
  int sec_r001326_13_2;
  int sec_r001326_14_1;
  int sec_r001326_14_2;
  int sec_r001326_15_1;
  int sec_r001326_15_2;
  int sec_r001326_16_1;
  int sec_r001326_16_2;
  int sec_r001326_17_1;
  int sec_r001326_17_2;
  int sec_r001326_18_1;
  int sec_r001326_18_2;
  int pub_r001326_0_1;
  int pub_r001326_0_2;
  int pub_r001326_1_1;
  int pub_r001326_1_2;
  int pub_r001326_2_1;
  int pub_r001326_2_2;
  int pub_r001326_3_1;
  int pub_r001326_3_2;
  int pub_r001326_4_1;
  int pub_r001326_4_2;
  int pub_r001326_5_1;
  int pub_r001326_5_2;
  int pub_r001326_6_1;
  int pub_r001326_6_2;
  int pub_r001326_7_1;
  int pub_r001326_7_2;
  int pub_r001326_8_1;
  int pub_r001326_8_2;
  int pub_r001326_9_1;
  int pub_r001326_9_2;
  int pub_r001326_10_1;
  int pub_r001326_10_2;
  int pub_r001326_11_1;
  int pub_r001326_11_2;
  int pub_r001326_12_1;
  int pub_r001326_12_2;
  int pub_r001326_13_1;
  int pub_r001326_13_2;
  int pub_r001326_14_1;
  int pub_r001326_14_2;
  int pub_r001326_15_1;
  int pub_r001326_15_2;
  int pub_r001326_16_1;
  int pub_r001326_16_2;
  int pub_r001326_17_1;
  int pub_r001326_17_2;
  int pub_r001326_18_1;
  int pub_r001326_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001326_0_1 >= (-100)) && (pub_r001326_0_1 <= 100));
  __CPROVER_assume((pub_r001326_0_2 >= (-100)) && (pub_r001326_0_2 <= 100));
  __CPROVER_assume((pub_r001326_1_1 >= (-100)) && (pub_r001326_1_1 <= 100));
  __CPROVER_assume((pub_r001326_1_2 >= (-100)) && (pub_r001326_1_2 <= 100));
  __CPROVER_assume((pub_r001326_2_1 >= (-100)) && (pub_r001326_2_1 <= 100));
  __CPROVER_assume((pub_r001326_2_2 >= (-100)) && (pub_r001326_2_2 <= 100));
  __CPROVER_assume((pub_r001326_3_1 >= (-100)) && (pub_r001326_3_1 <= 100));
  __CPROVER_assume((pub_r001326_3_2 >= (-100)) && (pub_r001326_3_2 <= 100));
  __CPROVER_assume((pub_r001326_4_1 >= (-100)) && (pub_r001326_4_1 <= 100));
  __CPROVER_assume((pub_r001326_4_2 >= (-100)) && (pub_r001326_4_2 <= 100));
  __CPROVER_assume((pub_r001326_5_1 >= (-100)) && (pub_r001326_5_1 <= 100));
  __CPROVER_assume((pub_r001326_5_2 >= (-100)) && (pub_r001326_5_2 <= 100));
  __CPROVER_assume((pub_r001326_6_1 >= (-100)) && (pub_r001326_6_1 <= 100));
  __CPROVER_assume((pub_r001326_6_2 >= (-100)) && (pub_r001326_6_2 <= 100));
  __CPROVER_assume((pub_r001326_7_1 >= (-100)) && (pub_r001326_7_1 <= 100));
  __CPROVER_assume((pub_r001326_7_2 >= (-100)) && (pub_r001326_7_2 <= 100));
  __CPROVER_assume((pub_r001326_8_1 >= (-100)) && (pub_r001326_8_1 <= 100));
  __CPROVER_assume((pub_r001326_8_2 >= (-100)) && (pub_r001326_8_2 <= 100));
  __CPROVER_assume((pub_r001326_9_1 >= (-100)) && (pub_r001326_9_1 <= 100));
  __CPROVER_assume((pub_r001326_9_2 >= (-100)) && (pub_r001326_9_2 <= 100));
  __CPROVER_assume((pub_r001326_10_1 >= (-100)) && (pub_r001326_10_1 <= 100));
  __CPROVER_assume((pub_r001326_10_2 >= (-100)) && (pub_r001326_10_2 <= 100));
  __CPROVER_assume((pub_r001326_11_1 >= (-100)) && (pub_r001326_11_1 <= 100));
  __CPROVER_assume((pub_r001326_11_2 >= (-100)) && (pub_r001326_11_2 <= 100));
  __CPROVER_assume((pub_r001326_12_1 >= (-100)) && (pub_r001326_12_1 <= 100));
  __CPROVER_assume((pub_r001326_12_2 >= (-100)) && (pub_r001326_12_2 <= 100));
  __CPROVER_assume((pub_r001326_13_1 >= (-100)) && (pub_r001326_13_1 <= 100));
  __CPROVER_assume((pub_r001326_13_2 >= (-100)) && (pub_r001326_13_2 <= 100));
  __CPROVER_assume((pub_r001326_14_1 >= (-100)) && (pub_r001326_14_1 <= 100));
  __CPROVER_assume((pub_r001326_14_2 >= (-100)) && (pub_r001326_14_2 <= 100));
  __CPROVER_assume((pub_r001326_15_1 >= (-100)) && (pub_r001326_15_1 <= 100));
  __CPROVER_assume((pub_r001326_15_2 >= (-100)) && (pub_r001326_15_2 <= 100));
  __CPROVER_assume((pub_r001326_16_1 >= (-100)) && (pub_r001326_16_1 <= 100));
  __CPROVER_assume((pub_r001326_16_2 >= (-100)) && (pub_r001326_16_2 <= 100));
  __CPROVER_assume((pub_r001326_17_1 >= (-100)) && (pub_r001326_17_1 <= 100));
  __CPROVER_assume((pub_r001326_17_2 >= (-100)) && (pub_r001326_17_2 <= 100));
  __CPROVER_assume((pub_r001326_18_1 >= (-100)) && (pub_r001326_18_1 <= 100));
  __CPROVER_assume((pub_r001326_18_2 >= (-100)) && (pub_r001326_18_2 <= 100));
  __CPROVER_assume((sec_r001326_0_1 >= 0) && (sec_r001326_0_1 <= 255));
  __CPROVER_assume((sec_r001326_0_2 >= 0) && (sec_r001326_0_2 <= 255));
  __CPROVER_assume((sec_r001326_1_1 >= 0) && (sec_r001326_1_1 <= 255));
  __CPROVER_assume((sec_r001326_1_2 >= 0) && (sec_r001326_1_2 <= 255));
  __CPROVER_assume((sec_r001326_2_1 >= 0) && (sec_r001326_2_1 <= 255));
  __CPROVER_assume((sec_r001326_2_2 >= 0) && (sec_r001326_2_2 <= 255));
  __CPROVER_assume((sec_r001326_3_1 >= 0) && (sec_r001326_3_1 <= 255));
  __CPROVER_assume((sec_r001326_3_2 >= 0) && (sec_r001326_3_2 <= 255));
  __CPROVER_assume((sec_r001326_4_1 >= 0) && (sec_r001326_4_1 <= 255));
  __CPROVER_assume((sec_r001326_4_2 >= 0) && (sec_r001326_4_2 <= 255));
  __CPROVER_assume((sec_r001326_5_1 >= 0) && (sec_r001326_5_1 <= 255));
  __CPROVER_assume((sec_r001326_5_2 >= 0) && (sec_r001326_5_2 <= 255));
  __CPROVER_assume((sec_r001326_6_1 >= 0) && (sec_r001326_6_1 <= 255));
  __CPROVER_assume((sec_r001326_6_2 >= 0) && (sec_r001326_6_2 <= 255));
  __CPROVER_assume((sec_r001326_7_1 >= 0) && (sec_r001326_7_1 <= 255));
  __CPROVER_assume((sec_r001326_7_2 >= 0) && (sec_r001326_7_2 <= 255));
  __CPROVER_assume((sec_r001326_8_1 >= 0) && (sec_r001326_8_1 <= 255));
  __CPROVER_assume((sec_r001326_8_2 >= 0) && (sec_r001326_8_2 <= 255));
  __CPROVER_assume((sec_r001326_9_1 >= 0) && (sec_r001326_9_1 <= 255));
  __CPROVER_assume((sec_r001326_9_2 >= 0) && (sec_r001326_9_2 <= 255));
  __CPROVER_assume((sec_r001326_10_1 >= 0) && (sec_r001326_10_1 <= 255));
  __CPROVER_assume((sec_r001326_10_2 >= 0) && (sec_r001326_10_2 <= 255));
  __CPROVER_assume((sec_r001326_11_1 >= 0) && (sec_r001326_11_1 <= 255));
  __CPROVER_assume((sec_r001326_11_2 >= 0) && (sec_r001326_11_2 <= 255));
  __CPROVER_assume((sec_r001326_12_1 >= 0) && (sec_r001326_12_1 <= 255));
  __CPROVER_assume((sec_r001326_12_2 >= 0) && (sec_r001326_12_2 <= 255));
  __CPROVER_assume((sec_r001326_13_1 >= 0) && (sec_r001326_13_1 <= 255));
  __CPROVER_assume((sec_r001326_13_2 >= 0) && (sec_r001326_13_2 <= 255));
  __CPROVER_assume((sec_r001326_14_1 >= 0) && (sec_r001326_14_1 <= 255));
  __CPROVER_assume((sec_r001326_14_2 >= 0) && (sec_r001326_14_2 <= 255));
  __CPROVER_assume((sec_r001326_15_1 >= 0) && (sec_r001326_15_1 <= 255));
  __CPROVER_assume((sec_r001326_15_2 >= 0) && (sec_r001326_15_2 <= 255));
  __CPROVER_assume((sec_r001326_16_1 >= 0) && (sec_r001326_16_1 <= 255));
  __CPROVER_assume((sec_r001326_16_2 >= 0) && (sec_r001326_16_2 <= 255));
  __CPROVER_assume((sec_r001326_17_1 >= 0) && (sec_r001326_17_1 <= 255));
  __CPROVER_assume((sec_r001326_17_2 >= 0) && (sec_r001326_17_2 <= 255));
  __CPROVER_assume((sec_r001326_18_1 >= 0) && (sec_r001326_18_1 <= 255));
  __CPROVER_assume((sec_r001326_18_2 >= 0) && (sec_r001326_18_2 <= 255));
  struct EventLog_R001326_2613_0 st_var_0_1 = {0};
  struct EventLog_R001326_2613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001326_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001326_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001326_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001326_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001326_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001326_0_2 + 7) & 15;
  struct FilterState_R001326_2613_1 st_var_1_1 = {0};
  struct FilterState_R001326_2613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001326_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001326_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001326_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001326_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001326_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001326_0_2 + 9) & 15;
  struct AudioFrame_R001326_2613_2 st_var_2_1 = {0};
  struct AudioFrame_R001326_2613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001326_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001326_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001326_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001326_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001326_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001326_0_2 + 11) & 15;
  union ColorPixel_R001326_2613_0 u_var_1;
  union ColorPixel_R001326_2613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001326_2613_0(sec_r001326_0_1, sec_r001326_1_1, pub_r001326_2_1);
  int helper_flow_0_2 = fn_R001326_2613_0(sec_r001326_0_2, sec_r001326_1_2, pub_r001326_2_2);
  fn_R001326_2613_0_2(sec_r001326_0_1, sec_r001326_1_1, pub_r001326_2_1, sec_r001326_0_2, sec_r001326_1_2, pub_r001326_2_2);
  int helper_flow_1_1 = fn_R001326_2613_1(sec_r001326_1_1, sec_r001326_2_1, pub_r001326_3_1);
  int helper_flow_1_2 = fn_R001326_2613_1(sec_r001326_1_2, sec_r001326_2_2, pub_r001326_3_2);
  fn_R001326_2613_1_2(sec_r001326_1_1, sec_r001326_2_1, pub_r001326_3_1, sec_r001326_1_2, sec_r001326_2_2, pub_r001326_3_2);
  int helper_flow_2_1 = fn_R001326_2613_2(sec_r001326_2_1, sec_r001326_3_1, pub_r001326_4_1, pub_r001326_5_1);
  int helper_flow_2_2 = fn_R001326_2613_2(sec_r001326_2_2, sec_r001326_3_2, pub_r001326_4_2, pub_r001326_5_2);
  fn_R001326_2613_2_2(sec_r001326_2_1, sec_r001326_3_1, pub_r001326_4_1, pub_r001326_5_1, sec_r001326_2_2, sec_r001326_3_2, pub_r001326_4_2, pub_r001326_5_2);
  int helper_flow_3_1 = fn_R001326_2613_3(sec_r001326_3_1, pub_r001326_4_1, pub_r001326_5_1);
  int helper_flow_3_2 = fn_R001326_2613_3(sec_r001326_3_2, pub_r001326_4_2, pub_r001326_5_2);
  fn_R001326_2613_3_2(sec_r001326_3_1, pub_r001326_4_1, pub_r001326_5_1, sec_r001326_3_2, pub_r001326_4_2, pub_r001326_5_2);
  int helper_flow_4_1 = fn_R001326_2613_4(sec_r001326_4_1, pub_r001326_5_1, pub_r001326_6_1, pub_r001326_7_1, pub_r001326_8_1);
  int helper_flow_4_2 = fn_R001326_2613_4(sec_r001326_4_2, pub_r001326_5_2, pub_r001326_6_2, pub_r001326_7_2, pub_r001326_8_2);
  fn_R001326_2613_4_2(sec_r001326_4_1, pub_r001326_5_1, pub_r001326_6_1, pub_r001326_7_1, pub_r001326_8_1, sec_r001326_4_2, pub_r001326_5_2, pub_r001326_6_2, pub_r001326_7_2, pub_r001326_8_2);
  int helper_flow_5_1 = fn_R001326_2613_5(sec_r001326_5_1, pub_r001326_6_1, pub_r001326_7_1, pub_r001326_8_1);
  int helper_flow_5_2 = fn_R001326_2613_5(sec_r001326_5_2, pub_r001326_6_2, pub_r001326_7_2, pub_r001326_8_2);
  fn_R001326_2613_5_2(sec_r001326_5_1, pub_r001326_6_1, pub_r001326_7_1, pub_r001326_8_1, sec_r001326_5_2, pub_r001326_6_2, pub_r001326_7_2, pub_r001326_8_2);
  int helper_flow_6_1 = fn_R001326_2613_6(sec_r001326_6_1, pub_r001326_7_1);
  int helper_flow_6_2 = fn_R001326_2613_6(sec_r001326_6_2, pub_r001326_7_2);
  fn_R001326_2613_6_2(sec_r001326_6_1, pub_r001326_7_1, sec_r001326_6_2, pub_r001326_7_2);
  int helper_flow_7_1 = fn_R001326_2613_7(sec_r001326_7_1, pub_r001326_8_1, pub_r001326_9_1, pub_r001326_10_1, pub_r001326_11_1);
  int helper_flow_7_2 = fn_R001326_2613_7(sec_r001326_7_2, pub_r001326_8_2, pub_r001326_9_2, pub_r001326_10_2, pub_r001326_11_2);
  fn_R001326_2613_7_2(sec_r001326_7_1, pub_r001326_8_1, pub_r001326_9_1, pub_r001326_10_1, pub_r001326_11_1, sec_r001326_7_2, pub_r001326_8_2, pub_r001326_9_2, pub_r001326_10_2, pub_r001326_11_2);
  int helper_flow_8_1 = fn_R001326_2613_8(sec_r001326_8_1, pub_r001326_9_1, pub_r001326_10_1);
  int helper_flow_8_2 = fn_R001326_2613_8(sec_r001326_8_2, pub_r001326_9_2, pub_r001326_10_2);
  fn_R001326_2613_8_2(sec_r001326_8_1, pub_r001326_9_1, pub_r001326_10_1, sec_r001326_8_2, pub_r001326_9_2, pub_r001326_10_2);
  int helper_flow_9_1 = fn_R001326_2613_9(sec_r001326_9_1, sec_r001326_10_1, pub_r001326_11_1, pub_r001326_12_1, pub_r001326_13_1);
  int helper_flow_9_2 = fn_R001326_2613_9(sec_r001326_9_2, sec_r001326_10_2, pub_r001326_11_2, pub_r001326_12_2, pub_r001326_13_2);
  fn_R001326_2613_9_2(sec_r001326_9_1, sec_r001326_10_1, pub_r001326_11_1, pub_r001326_12_1, pub_r001326_13_1, sec_r001326_9_2, sec_r001326_10_2, pub_r001326_11_2, pub_r001326_12_2, pub_r001326_13_2);
  int helper_flow_10_1 = fn_R001326_2613_10(sec_r001326_10_1, sec_r001326_11_1);
  int helper_flow_10_2 = fn_R001326_2613_10(sec_r001326_10_2, sec_r001326_11_2);
  fn_R001326_2613_10_2(sec_r001326_10_1, sec_r001326_11_1, sec_r001326_10_2, sec_r001326_11_2);
  int stage_v_0_1 = ((helper_flow_1_1 + (pub_r001326_2_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_1_2 + (pub_r001326_2_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001326_17_1 * 2) + 24) & 63;
  int stage_v_1_2 = ((pub_r001326_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((helper_flow_8_1 + (pub_r001326_7_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((helper_flow_8_2 + (pub_r001326_7_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((helper_flow_4_1 + (pub_r001326_12_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((helper_flow_4_2 + (pub_r001326_12_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((helper_flow_5_1 + (pub_r001326_18_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((helper_flow_5_2 + (pub_r001326_18_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((helper_flow_1_1 + (pub_r001326_8_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((helper_flow_1_2 + (pub_r001326_8_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((stage_v_3_1 + (pub_r001326_2_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((stage_v_3_2 + (pub_r001326_2_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((pub_r001326_11_1 * 2) + 37) & 63;
  int stage_v_7_2 = ((pub_r001326_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((helper_flow_7_1 + (pub_r001326_14_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((helper_flow_7_2 + (pub_r001326_14_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((sec_r001326_9_1 + (pub_r001326_14_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001326_9_2 + (pub_r001326_14_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((stage_v_4_1 + (pub_r001326_9_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((stage_v_4_2 + (pub_r001326_9_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((stage_v_5_1 + (pub_r001326_3_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((stage_v_5_2 + (pub_r001326_3_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((sec_r001326_11_1 + (pub_r001326_14_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001326_11_2 + (pub_r001326_14_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((pub_r001326_4_1 * 2) + 45) & 63;
  int stage_v_13_2 = ((pub_r001326_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((helper_flow_10_1 + (pub_r001326_0_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((helper_flow_10_2 + (pub_r001326_0_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_0_1 + (pub_r001326_5_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_0_2 + (pub_r001326_5_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001326_16_1 * 2) + 10) & 63;
  int stage_v_16_2 = ((pub_r001326_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001326_10_1 * 2) + 31) & 63;
  int stage_v_17_2 = ((pub_r001326_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((stage_v_6_1 + (pub_r001326_14_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((stage_v_6_2 + (pub_r001326_14_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001326_9_1 * 2) + 8) & 63;
  int stage_v_19_2 = ((pub_r001326_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001326_18_1 * 2) + 34) & 63;
  int stage_v_20_2 = ((pub_r001326_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001326_13_1 * 2) + 8) & 63;
  int stage_v_21_2 = ((pub_r001326_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001326_15_1 * 2) + 32) & 63;
  int stage_v_22_2 = ((pub_r001326_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((stage_v_12_1 + (pub_r001326_17_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((stage_v_12_2 + (pub_r001326_17_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((stage_v_5_1 + (pub_r001326_3_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_5_2 + (pub_r001326_3_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((sec_r001326_2_1 + (pub_r001326_7_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((sec_r001326_2_2 + (pub_r001326_7_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((pub_r001326_16_1 * 2) + 21) & 63;
  int stage_v_26_2 = ((pub_r001326_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((helper_flow_4_1 + (pub_r001326_13_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((helper_flow_4_2 + (pub_r001326_13_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001326_5_1 * 2) + 33) & 63;
  int stage_v_28_2 = ((pub_r001326_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001326_0_1 + (pub_r001326_11_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001326_0_2 + (pub_r001326_11_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((sec_r001326_1_1 + (pub_r001326_15_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((sec_r001326_1_2 + (pub_r001326_15_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((stage_v_29_1 + (pub_r001326_6_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_29_2 + (pub_r001326_6_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001326_18_1 * 2) + 36) & 63;
  int stage_v_32_2 = ((pub_r001326_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((sec_r001326_1_1 + (pub_r001326_17_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001326_1_2 + (pub_r001326_17_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001326_15_1 * 2) + 28) & 63;
  int stage_v_34_2 = ((pub_r001326_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((sec_r001326_0_1 + (pub_r001326_8_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001326_0_2 + (pub_r001326_8_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001326_5_1 * 2) + 39) & 63;
  int stage_v_36_2 = ((pub_r001326_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((stage_v_11_1 + (pub_r001326_15_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_11_2 + (pub_r001326_15_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((stage_v_9_1 + (pub_r001326_4_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_9_2 + (pub_r001326_4_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((sec_r001326_17_1 + (pub_r001326_16_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001326_17_2 + (pub_r001326_16_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((stage_v_12_1 + (pub_r001326_8_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_12_2 + (pub_r001326_8_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001326_3_1 * 2) + 10) & 63;
  int stage_v_41_2 = ((pub_r001326_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001326_5_1 * 2) + 32) & 63;
  int stage_v_42_2 = ((pub_r001326_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((helper_flow_2_1 + (pub_r001326_4_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((helper_flow_2_2 + (pub_r001326_4_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((stage_v_5_1 + (pub_r001326_5_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_5_2 + (pub_r001326_5_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((stage_v_9_1 + (pub_r001326_4_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_9_2 + (pub_r001326_4_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((sec_r001326_4_1 + (pub_r001326_16_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((sec_r001326_4_2 + (pub_r001326_16_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((stage_v_23_1 + (pub_r001326_11_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_23_2 + (pub_r001326_11_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((stage_v_2_1 + (pub_r001326_14_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_2_2 + (pub_r001326_14_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_46_1 + (pub_r001326_6_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_46_2 + (pub_r001326_6_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((helper_flow_3_1 + (pub_r001326_14_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((helper_flow_3_2 + (pub_r001326_14_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((stage_v_27_1 + (pub_r001326_1_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_27_2 + (pub_r001326_1_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001326_13_1 * 2) + 15) & 63;
  int stage_v_52_2 = ((pub_r001326_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001326_9_1 * 2) + 10) & 63;
  int stage_v_53_2 = ((pub_r001326_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((stage_v_35_1 + (pub_r001326_2_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_35_2 + (pub_r001326_2_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((pub_r001326_14_1 * 2) + 35) & 63;
  int stage_v_55_2 = ((pub_r001326_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001326_5_1 * 2) + 21) & 63;
  int stage_v_56_2 = ((pub_r001326_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001326_4_1 * 2) + 50) & 63;
  int stage_v_57_2 = ((pub_r001326_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((sec_r001326_3_1 + (pub_r001326_8_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((sec_r001326_3_2 + (pub_r001326_8_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001326_17_1 * 2) + 32) & 63;
  int stage_v_59_2 = ((pub_r001326_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((stage_v_30_1 + (pub_r001326_18_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_30_2 + (pub_r001326_18_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_39_1 + (pub_r001326_8_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_39_2 + (pub_r001326_8_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((pub_r001326_15_1 * 2) + 22) & 63;
  int stage_v_62_2 = ((pub_r001326_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((sec_r001326_7_1 + (pub_r001326_8_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((sec_r001326_7_2 + (pub_r001326_8_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((pub_r001326_11_1 * 2) + 26) & 63;
  int stage_v_64_2 = ((pub_r001326_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((stage_v_51_1 + (pub_r001326_6_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_51_2 + (pub_r001326_6_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((helper_flow_7_1 + (pub_r001326_5_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((helper_flow_7_2 + (pub_r001326_5_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((pub_r001326_15_1 * 2) + 13) & 63;
  int stage_v_67_2 = ((pub_r001326_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((stage_v_18_1 + (pub_r001326_18_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_18_2 + (pub_r001326_18_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((pub_r001326_2_1 * 2) + 50) & 63;
  int stage_v_69_2 = ((pub_r001326_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_31_1 + (pub_r001326_1_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_31_2 + (pub_r001326_1_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_0_1 + (pub_r001326_12_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_0_2 + (pub_r001326_12_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_4_1 + (pub_r001326_13_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_4_2 + (pub_r001326_13_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001326_8_1 * 2) + 13) & 63;
  int stage_v_73_2 = ((pub_r001326_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((helper_flow_7_1 + (pub_r001326_7_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((helper_flow_7_2 + (pub_r001326_7_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001326_15_1 * 2) + 33) & 63;
  int stage_v_75_2 = ((pub_r001326_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001326_1_1 * 2) + 45) & 63;
  int stage_v_76_2 = ((pub_r001326_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001326_12_1 * 2) + 45) & 63;
  int stage_v_77_2 = ((pub_r001326_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001326_7_1 * 2) + 18) & 63;
  int stage_v_78_2 = ((pub_r001326_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((helper_flow_9_1 + (pub_r001326_10_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((helper_flow_9_2 + (pub_r001326_10_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((helper_flow_6_1 + (pub_r001326_4_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((helper_flow_6_2 + (pub_r001326_4_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((sec_r001326_16_1 + (pub_r001326_18_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((sec_r001326_16_2 + (pub_r001326_18_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((sec_r001326_2_1 + (pub_r001326_16_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((sec_r001326_2_2 + (pub_r001326_16_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_18_1 + (pub_r001326_3_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_18_2 + (pub_r001326_3_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((stage_v_38_1 + (pub_r001326_4_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_38_2 + (pub_r001326_4_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_3_1 + (pub_r001326_6_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_3_2 + (pub_r001326_6_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_3_1 + (pub_r001326_13_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_3_2 + (pub_r001326_13_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_40_1 + (pub_r001326_16_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_40_2 + (pub_r001326_16_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((helper_flow_4_1 + (pub_r001326_2_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((helper_flow_4_2 + (pub_r001326_2_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_0_1 + (pub_r001326_1_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_0_2 + (pub_r001326_1_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((helper_flow_8_1 + (pub_r001326_4_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((helper_flow_8_2 + (pub_r001326_4_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_24_1 + (pub_r001326_13_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_24_2 + (pub_r001326_13_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_6_1 + (pub_r001326_10_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_6_2 + (pub_r001326_10_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_74_1 + (pub_r001326_12_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_74_2 + (pub_r001326_12_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((pub_r001326_8_1 * 2) + 48) & 63;
  int stage_v_94_2 = ((pub_r001326_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((stage_v_8_1 + (pub_r001326_18_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_8_2 + (pub_r001326_18_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((stage_v_9_1 + (pub_r001326_2_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_9_2 + (pub_r001326_2_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((pub_r001326_17_1 * 2) + 20) & 63;
  int stage_v_97_2 = ((pub_r001326_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_90_1 + (pub_r001326_13_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_90_2 + (pub_r001326_13_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001326_4_1 * 2) + 9) & 63;
  int stage_v_99_2 = ((pub_r001326_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((stage_v_88_1 + (pub_r001326_14_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_88_2 + (pub_r001326_14_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((pub_r001326_15_1 * 2) + 14) & 63;
  int stage_v_101_2 = ((pub_r001326_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_58_1 + (pub_r001326_4_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_58_2 + (pub_r001326_4_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((sec_r001326_15_1 + (pub_r001326_0_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001326_15_2 + (pub_r001326_0_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_58_1 + (pub_r001326_18_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_58_2 + (pub_r001326_18_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((sec_r001326_8_1 + (pub_r001326_10_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((sec_r001326_8_2 + (pub_r001326_10_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_4_1 + (pub_r001326_18_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_4_2 + (pub_r001326_18_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((helper_flow_1_1 + (pub_r001326_14_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((helper_flow_1_2 + (pub_r001326_14_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_33_1 + (pub_r001326_9_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_33_2 + (pub_r001326_9_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_4_1 + (pub_r001326_10_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_4_2 + (pub_r001326_10_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001326_13_1 * 2) + 33) & 63;
  int stage_v_110_2 = ((pub_r001326_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_79_1 + (pub_r001326_2_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_79_2 + (pub_r001326_2_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((pub_r001326_10_1 * 2) + 14) & 63;
  int stage_v_112_2 = ((pub_r001326_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001326_5_1 * 2) + 16) & 63;
  int stage_v_113_2 = ((pub_r001326_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_103_1 + (pub_r001326_1_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_103_2 + (pub_r001326_1_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_14_1 + (pub_r001326_4_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_14_2 + (pub_r001326_4_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((pub_r001326_15_1 * 2) + 22) & 63;
  int stage_v_116_2 = ((pub_r001326_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001326_11_1 * 2) + 43) & 63;
  int stage_v_117_2 = ((pub_r001326_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_103_1 + (pub_r001326_3_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_103_2 + (pub_r001326_3_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((pub_r001326_14_1 * 2) + 9) & 63;
  int stage_v_119_2 = ((pub_r001326_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_46_1 + (pub_r001326_6_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_46_2 + (pub_r001326_6_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001326_4_1 * 2) + 43) & 63;
  int stage_v_121_2 = ((pub_r001326_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001326_9_1 * 2) + 10) & 63;
  int stage_v_122_2 = ((pub_r001326_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001326_15_1 * 2) + 39) & 63;
  int stage_v_123_2 = ((pub_r001326_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001326_13_1 * 2) + 19) & 63;
  int stage_v_124_2 = ((pub_r001326_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_18_1 + (pub_r001326_7_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_18_2 + (pub_r001326_7_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((pub_r001326_16_1 * 2) + 11) & 63;
  int stage_v_126_2 = ((pub_r001326_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_107_1 + (pub_r001326_9_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_107_2 + (pub_r001326_9_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_127_1 + (pub_r001326_8_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_127_2 + (pub_r001326_8_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((pub_r001326_7_1 * 2) + 8) & 63;
  int stage_v_129_2 = ((pub_r001326_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_54_1 + (pub_r001326_1_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_54_2 + (pub_r001326_1_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001326_9_1 * 2) + 9) & 63;
  int stage_v_131_2 = ((pub_r001326_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_6_1 + (pub_r001326_10_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_6_2 + (pub_r001326_10_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001326_13_1 * 2) + 48) & 63;
  int stage_v_133_2 = ((pub_r001326_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((sec_r001326_0_1 + (pub_r001326_12_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((sec_r001326_0_2 + (pub_r001326_12_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_60_1 + (pub_r001326_14_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_60_2 + (pub_r001326_14_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_4_1 + (pub_r001326_2_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_4_2 + (pub_r001326_2_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001326_12_1 * 2) + 42) & 63;
  int stage_v_137_2 = ((pub_r001326_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001326_1_1 * 2) + 41) & 63;
  int stage_v_138_2 = ((pub_r001326_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_38_1 + (pub_r001326_1_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_38_2 + (pub_r001326_1_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((pub_r001326_3_1 * 2) + 16) & 63;
  int stage_v_140_2 = ((pub_r001326_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_63_1 + (pub_r001326_8_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_63_2 + (pub_r001326_8_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_136_1 + (pub_r001326_7_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_136_2 + (pub_r001326_7_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((pub_r001326_7_1 * 2) + 46) & 63;
  int stage_v_143_2 = ((pub_r001326_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001326_15_1 * 2) + 39) & 63;
  int stage_v_144_2 = ((pub_r001326_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_30_1 + (pub_r001326_15_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_30_2 + (pub_r001326_15_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((pub_r001326_10_1 * 2) + 40) & 63;
  int stage_v_146_2 = ((pub_r001326_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_90_1 + (pub_r001326_5_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_90_2 + (pub_r001326_5_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_105_1 + (pub_r001326_13_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_105_2 + (pub_r001326_13_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_35_1 + (pub_r001326_1_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_35_2 + (pub_r001326_1_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_37_1 + (pub_r001326_12_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_37_2 + (pub_r001326_12_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001326_11_1 * 2) + 32) & 63;
  int stage_v_151_2 = ((pub_r001326_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_90_1 + (pub_r001326_12_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_90_2 + (pub_r001326_12_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001326_16_1 * 2) + 12) & 63;
  int stage_v_153_2 = ((pub_r001326_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001326_4_1 * 2) + 22) & 63;
  int stage_v_154_2 = ((pub_r001326_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((sec_r001326_10_1 + (pub_r001326_14_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((sec_r001326_10_2 + (pub_r001326_14_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_149_1 + (pub_r001326_6_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_149_2 + (pub_r001326_6_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_107_1 + (pub_r001326_16_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_107_2 + (pub_r001326_16_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_0_1 + (pub_r001326_9_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_0_2 + (pub_r001326_9_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_93_1 + (pub_r001326_16_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_93_2 + (pub_r001326_16_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((pub_r001326_16_1 * 2) + 5) & 63;
  int stage_v_160_2 = ((pub_r001326_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001326_0_1 * 2) + 23) & 63;
  int stage_v_161_2 = ((pub_r001326_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001326_17_1 * 2) + 43) & 63;
  int stage_v_162_2 = ((pub_r001326_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_83_1 + (pub_r001326_9_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_83_2 + (pub_r001326_9_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001326_13_1 * 2) + 14) & 63;
  int stage_v_164_2 = ((pub_r001326_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001326_14_1 * 2) + 19) & 63;
  int stage_v_165_2 = ((pub_r001326_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001326_9_1 * 2) + 17) & 63;
  int stage_v_166_2 = ((pub_r001326_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_14_1 + (pub_r001326_13_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_14_2 + (pub_r001326_13_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((pub_r001326_13_1 * 2) + 26) & 63;
  int stage_v_168_2 = ((pub_r001326_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((stage_v_45_1 + (pub_r001326_16_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_45_2 + (pub_r001326_16_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_103_1 + (pub_r001326_16_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_103_2 + (pub_r001326_16_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((stage_v_128_1 + (pub_r001326_16_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_128_2 + (pub_r001326_16_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((pub_r001326_1_1 * 2) + 38) & 63;
  int stage_v_172_2 = ((pub_r001326_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001326_6_1 * 2) + 28) & 63;
  int stage_v_173_2 = ((pub_r001326_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001326_8_1 * 2) + 24) & 63;
  int stage_v_174_2 = ((pub_r001326_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001326_10_1 * 2) + 10) & 63;
  int stage_v_175_2 = ((pub_r001326_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001326_12_1 * 2) + 10) & 63;
  int stage_v_176_2 = ((pub_r001326_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001326_14_1 * 2) + 19) & 63;
  int stage_v_177_2 = ((pub_r001326_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_156_1 + (pub_r001326_15_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_156_2 + (pub_r001326_15_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((helper_flow_7_1 + (pub_r001326_13_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((helper_flow_7_2 + (pub_r001326_13_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_125_1 + (pub_r001326_18_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_125_2 + (pub_r001326_18_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_170_1 + (pub_r001326_7_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_170_2 + (pub_r001326_7_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_156_1 + (pub_r001326_3_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_156_2 + (pub_r001326_3_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_98_1 + (pub_r001326_7_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_98_2 + (pub_r001326_7_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((pub_r001326_4_1 * 2) + 32) & 63;
  int stage_v_184_2 = ((pub_r001326_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((sec_r001326_17_1 + (pub_r001326_8_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((sec_r001326_17_2 + (pub_r001326_8_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_128_1 + (pub_r001326_1_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_128_2 + (pub_r001326_1_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_50_1 + (pub_r001326_0_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_50_2 + (pub_r001326_0_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001326_0_1 * 2) + 13) & 63;
  int stage_v_188_2 = ((pub_r001326_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001326_10_1 * 2) + 38) & 63;
  int stage_v_189_2 = ((pub_r001326_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001326_3_1 * 2) + 43) & 63;
  int stage_v_190_2 = ((pub_r001326_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001326_6_1 * 2) + 44) & 63;
  int stage_v_191_2 = ((pub_r001326_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_142_1 + (pub_r001326_16_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_142_2 + (pub_r001326_16_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_14_1 + (pub_r001326_16_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_14_2 + (pub_r001326_16_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((pub_r001326_13_1 * 2) + 12) & 63;
  int stage_v_194_2 = ((pub_r001326_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001326_18_1 * 2) + 47) & 63;
  int stage_v_195_2 = ((pub_r001326_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001326_15_1 * 2) + 49) & 63;
  int stage_v_196_2 = ((pub_r001326_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_93_1 + (pub_r001326_14_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_93_2 + (pub_r001326_14_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((pub_r001326_4_1 * 2) + 23) & 63;
  int stage_v_198_2 = ((pub_r001326_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((sec_r001326_6_1 + (pub_r001326_14_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((sec_r001326_6_2 + (pub_r001326_14_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001326_16_1 * 2) + 38) & 63;
  int stage_v_200_2 = ((pub_r001326_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_199_1 + (pub_r001326_11_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_199_2 + (pub_r001326_11_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((pub_r001326_2_1 * 2) + 30) & 63;
  int stage_v_202_2 = ((pub_r001326_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001326_11_1 * 2) + 18) & 63;
  int stage_v_203_2 = ((pub_r001326_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_169_1 + (pub_r001326_2_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_169_2 + (pub_r001326_2_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((pub_r001326_8_1 * 2) + 30) & 63;
  int stage_v_205_2 = ((pub_r001326_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001326_18_1 * 2) + 12) & 63;
  int stage_v_206_2 = ((pub_r001326_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_183_1 + (pub_r001326_17_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_183_2 + (pub_r001326_17_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((pub_r001326_12_1 * 2) + 23) & 63;
  int stage_v_208_2 = ((pub_r001326_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((stage_v_102_1 + (pub_r001326_9_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_102_2 + (pub_r001326_9_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_25_1 + (pub_r001326_5_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_25_2 + (pub_r001326_5_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((stage_v_109_1 + (pub_r001326_11_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_109_2 + (pub_r001326_11_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((stage_v_35_1 + (pub_r001326_11_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_35_2 + (pub_r001326_11_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((stage_v_18_1 + (pub_r001326_0_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_18_2 + (pub_r001326_0_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((sec_r001326_9_1 + (pub_r001326_9_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((sec_r001326_9_2 + (pub_r001326_9_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((stage_v_98_1 + (pub_r001326_4_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_98_2 + (pub_r001326_4_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((stage_v_24_1 + (pub_r001326_17_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_24_2 + (pub_r001326_17_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((sec_r001326_18_1 + (pub_r001326_9_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((sec_r001326_18_2 + (pub_r001326_9_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_39_1 + (pub_r001326_9_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_39_2 + (pub_r001326_9_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((pub_r001326_9_1 * 2) + 16) & 63;
  int stage_v_219_2 = ((pub_r001326_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((stage_v_157_1 + (pub_r001326_6_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_157_2 + (pub_r001326_6_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((stage_v_54_1 + (pub_r001326_4_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_54_2 + (pub_r001326_4_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_130_1 + (pub_r001326_17_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_130_2 + (pub_r001326_17_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((pub_r001326_17_1 * 2) + 11) & 63;
  int stage_v_223_2 = ((pub_r001326_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_60_1 + (pub_r001326_2_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_60_2 + (pub_r001326_2_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_132_1 + (pub_r001326_15_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_132_2 + (pub_r001326_15_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((pub_r001326_1_1 * 2) + 42) & 63;
  int stage_v_226_2 = ((pub_r001326_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001326_13_1 * 2) + 47) & 63;
  int stage_v_227_2 = ((pub_r001326_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((stage_v_23_1 + (pub_r001326_16_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_23_2 + (pub_r001326_16_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((stage_v_209_1 + (pub_r001326_7_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((stage_v_209_2 + (pub_r001326_7_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((stage_v_220_1 + (pub_r001326_6_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_220_2 + (pub_r001326_6_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((pub_r001326_10_1 * 2) + 8) & 63;
  int stage_v_231_2 = ((pub_r001326_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001326_15_1 * 2) + 43) & 63;
  int stage_v_232_2 = ((pub_r001326_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((stage_v_31_1 + (pub_r001326_13_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_31_2 + (pub_r001326_13_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((stage_v_159_1 + (pub_r001326_13_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((stage_v_159_2 + (pub_r001326_13_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_235_1 = ((stage_v_40_1 + (pub_r001326_16_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_40_2 + (pub_r001326_16_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((stage_v_185_1 + (pub_r001326_0_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((stage_v_185_2 + (pub_r001326_0_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_237_1 = ((pub_r001326_5_1 * 2) + 12) & 63;
  int stage_v_237_2 = ((pub_r001326_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001326_12_1 * 2) + 38) & 63;
  int stage_v_238_2 = ((pub_r001326_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001326_11_1 * 2) + 50) & 63;
  int stage_v_239_2 = ((pub_r001326_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((stage_v_104_1 + (pub_r001326_8_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((stage_v_104_2 + (pub_r001326_8_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((stage_v_24_1 + (pub_r001326_7_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((stage_v_24_2 + (pub_r001326_7_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((stage_v_48_1 + (pub_r001326_0_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((stage_v_48_2 + (pub_r001326_0_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((pub_r001326_3_1 * 2) + 8) & 63;
  int stage_v_243_2 = ((pub_r001326_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001326_10_1 * 2) + 29) & 63;
  int stage_v_244_2 = ((pub_r001326_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001326_4_1 * 2) + 21) & 63;
  int stage_v_245_2 = ((pub_r001326_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_50_1 + (pub_r001326_11_1 * 2)) + 743) & 127;
  int stage_v_246_2 = ((stage_v_50_2 + (pub_r001326_11_2 * 2)) + 743) & 127;
  if (stage_v_246_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_246_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_246_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_246_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_247_1 = ((pub_r001326_2_1 * 2) + 47) & 63;
  int stage_v_247_2 = ((pub_r001326_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001326_12_1 * 2) + 37) & 63;
  int stage_v_248_2 = ((pub_r001326_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((stage_v_6_1 + (pub_r001326_17_1 * 2)) + 752) & 127;
  int stage_v_249_2 = ((stage_v_6_2 + (pub_r001326_17_2 * 2)) + 752) & 127;
  if (stage_v_249_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_249_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_249_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_249_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_250_1 = ((pub_r001326_11_1 * 2) + 44) & 63;
  int stage_v_250_2 = ((pub_r001326_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((stage_v_192_1 + (pub_r001326_4_1 * 2)) + 758) & 127;
  int stage_v_251_2 = ((stage_v_192_2 + (pub_r001326_4_2 * 2)) + 758) & 127;
  if (stage_v_251_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_251_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_251_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_251_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_252_1 = ((pub_r001326_4_1 * 2) + 37) & 63;
  int stage_v_252_2 = ((pub_r001326_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001326_15_1 * 2) + 23) & 63;
  int stage_v_253_2 = ((pub_r001326_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((sec_r001326_2_1 + (pub_r001326_10_1 * 2)) + 767) & 127;
  int stage_v_254_2 = ((sec_r001326_2_2 + (pub_r001326_10_2 * 2)) + 767) & 127;
  if (stage_v_254_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_254_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_254_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_254_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_254_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_254_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_254_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_254_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_255_1 = ((stage_v_152_1 + (pub_r001326_9_1 * 2)) + 770) & 127;
  int stage_v_255_2 = ((stage_v_152_2 + (pub_r001326_9_2 * 2)) + 770) & 127;
  if (stage_v_255_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_255_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_255_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_255_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_255_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_255_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_255_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_255_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_256_1 = ((pub_r001326_6_1 * 2) + 42) & 63;
  int stage_v_256_2 = ((pub_r001326_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001326_0_1 * 2) + 18) & 63;
  int stage_v_257_2 = ((pub_r001326_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((stage_v_193_1 + (pub_r001326_17_1 * 2)) + 779) & 127;
  int stage_v_258_2 = ((stage_v_193_2 + (pub_r001326_17_2 * 2)) + 779) & 127;
  if (stage_v_258_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_258_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_258_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_258_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_258_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_258_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_258_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_258_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_259_1 = ((stage_v_185_1 + (pub_r001326_16_1 * 2)) + 782) & 127;
  int stage_v_259_2 = ((stage_v_185_2 + (pub_r001326_16_2 * 2)) + 782) & 127;
  if (stage_v_259_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_259_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_259_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_259_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_259_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_259_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_259_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_259_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_260_1 = ((pub_r001326_9_1 * 2) + 46) & 63;
  int stage_v_260_2 = ((pub_r001326_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((stage_v_38_1 + (pub_r001326_5_1 * 2)) + 788) & 127;
  int stage_v_261_2 = ((stage_v_38_2 + (pub_r001326_5_2 * 2)) + 788) & 127;
  if (stage_v_261_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_261_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_261_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_261_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_261_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_261_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_261_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_261_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_262_1 = ((stage_v_163_1 + (pub_r001326_4_1 * 2)) + 791) & 127;
  int stage_v_262_2 = ((stage_v_163_2 + (pub_r001326_4_2 * 2)) + 791) & 127;
  if (stage_v_262_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_262_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_262_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_262_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_262_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_262_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_262_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_262_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_263_1 = ((stage_v_68_1 + (pub_r001326_18_1 * 2)) + 794) & 127;
  int stage_v_263_2 = ((stage_v_68_2 + (pub_r001326_18_2 * 2)) + 794) & 127;
  if (stage_v_263_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_263_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_263_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_263_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_263_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_263_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_263_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_263_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_264_1 = ((stage_v_63_1 + (pub_r001326_5_1 * 2)) + 797) & 127;
  int stage_v_264_2 = ((stage_v_63_2 + (pub_r001326_5_2 * 2)) + 797) & 127;
  if (stage_v_264_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_264_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_264_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_264_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_264_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_264_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_264_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_264_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_265_1 = ((stage_v_87_1 + (pub_r001326_1_1 * 2)) + 800) & 127;
  int stage_v_265_2 = ((stage_v_87_2 + (pub_r001326_1_2 * 2)) + 800) & 127;
  if (stage_v_265_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_265_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_265_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_265_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_265_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_265_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_265_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_265_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_266_1 = ((stage_v_163_1 + (pub_r001326_10_1 * 2)) + 803) & 127;
  int stage_v_266_2 = ((stage_v_163_2 + (pub_r001326_10_2 * 2)) + 803) & 127;
  if (stage_v_266_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_266_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_266_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_266_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_266_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_266_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_266_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_266_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_267_1 = ((stage_v_259_1 + (pub_r001326_18_1 * 2)) + 806) & 127;
  int stage_v_267_2 = ((stage_v_259_2 + (pub_r001326_18_2 * 2)) + 806) & 127;
  if (stage_v_267_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_267_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_267_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_267_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_267_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_267_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_267_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_267_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_268_1 = ((pub_r001326_18_1 * 2) + 33) & 63;
  int stage_v_268_2 = ((pub_r001326_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((stage_v_145_1 + (pub_r001326_9_1 * 2)) + 812) & 127;
  int stage_v_269_2 = ((stage_v_145_2 + (pub_r001326_9_2 * 2)) + 812) & 127;
  if (stage_v_269_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_269_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_269_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_269_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_269_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_269_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_269_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_269_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_270_1 = ((pub_r001326_18_1 * 2) + 30) & 63;
  int stage_v_270_2 = ((pub_r001326_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((stage_v_207_1 + (pub_r001326_14_1 * 2)) + 818) & 127;
  int stage_v_271_2 = ((stage_v_207_2 + (pub_r001326_14_2 * 2)) + 818) & 127;
  if (stage_v_271_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_271_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_271_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_271_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_271_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_271_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_271_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_271_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001326_3_1 != sec_r001326_3_2);
  __CPROVER_assume(pub_r001326_3_1 == pub_r001326_3_2);
  __CPROVER_assume(pub_r001326_16_1 == pub_r001326_16_2);
  __CPROVER_assume(sec_r001326_16_1 != sec_r001326_16_2);
  __CPROVER_assume(sec_r001326_1_1 != sec_r001326_1_2);
  __CPROVER_assume(pub_r001326_8_1 == pub_r001326_8_2);
  __CPROVER_assume(pub_r001326_5_1 == pub_r001326_5_2);
  __CPROVER_assume(pub_r001326_6_1 == pub_r001326_6_2);
  __CPROVER_assume(sec_r001326_2_1 != sec_r001326_2_2);
  __CPROVER_assume(pub_r001326_0_1 == pub_r001326_0_2);
  __CPROVER_assume(sec_r001326_0_1 != sec_r001326_0_2);
  __CPROVER_assume(sec_r001326_15_1 != sec_r001326_15_2);
  __CPROVER_assume(sec_r001326_11_1 != sec_r001326_11_2);
  __CPROVER_assume(sec_r001326_13_1 != sec_r001326_13_2);
  __CPROVER_assume(pub_r001326_15_1 == pub_r001326_15_2);
  __CPROVER_assume(pub_r001326_13_1 == pub_r001326_13_2);
  __CPROVER_assume(sec_r001326_4_1 != sec_r001326_4_2);
  __CPROVER_assume(sec_r001326_6_1 != sec_r001326_6_2);
  __CPROVER_assume(pub_r001326_4_1 == pub_r001326_4_2);
  __CPROVER_assume(sec_r001326_9_1 != sec_r001326_9_2);
  __CPROVER_assume(pub_r001326_12_1 == pub_r001326_12_2);
  __CPROVER_assume(pub_r001326_1_1 == pub_r001326_1_2);
  __CPROVER_assume(sec_r001326_12_1 != sec_r001326_12_2);
  __CPROVER_assume(sec_r001326_5_1 != sec_r001326_5_2);
  __CPROVER_assume(sec_r001326_10_1 != sec_r001326_10_2);
  __CPROVER_assume(pub_r001326_11_1 == pub_r001326_11_2);
  __CPROVER_assume(sec_r001326_18_1 != sec_r001326_18_2);
  __CPROVER_assume(pub_r001326_14_1 == pub_r001326_14_2);
  __CPROVER_assume(pub_r001326_10_1 == pub_r001326_10_2);
  __CPROVER_assume(sec_r001326_14_1 != sec_r001326_14_2);
  __CPROVER_assume(pub_r001326_9_1 == pub_r001326_9_2);
  __CPROVER_assume(pub_r001326_2_1 == pub_r001326_2_2);
  __CPROVER_assume(pub_r001326_7_1 == pub_r001326_7_2);
  __CPROVER_assume(pub_r001326_17_1 == pub_r001326_17_2);
  __CPROVER_assume(sec_r001326_7_1 != sec_r001326_7_2);
  __CPROVER_assume(sec_r001326_8_1 != sec_r001326_8_2);
  __CPROVER_assume(pub_r001326_18_1 == pub_r001326_18_2);
  __CPROVER_assume(sec_r001326_17_1 != sec_r001326_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.code == st_var_0_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.rms == st_var_2_2.rms);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.channels == st_var_2_2.channels);
  assert(st_var_2_1.gain == st_var_2_2.gain);
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
}


