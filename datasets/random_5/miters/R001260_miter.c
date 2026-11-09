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
struct Transaction_R001260_6013_0
{
  int rate;
  int fee;
  short account_id;
  int balance;
  short status;
  int buffer[3];
};
struct DeviceConfig_R001260_6013_1
{
  int stop_bits;
  unsigned char port;
  int id;
  short timeout;
  int buffer[3];
};
struct AudioFrame_R001260_6013_2
{
  int channels;
  unsigned char envelope;
  int peak;
  unsigned char gain;
  int sample_rate;
  int buffer[3];
};
union RegisterBank_R001260_6013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001260_6013_1
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
void fn_R001260_6013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int accumulator_34_1 = 0;
  int accumulator_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_34_1 = ((accumulator_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_34_2 = ((accumulator_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_34_1) & 127;
    acc_2 = (acc_2 + accumulator_34_2) & 127;
  }

  int vector_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_20_1) & 63;
  aux_2 = (aux_2 + vector_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_34_1 == accumulator_34_2);
  assert(vector_20_1 == vector_20_2);
}

int fn_R001260_6013_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int accumulator_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_34 = ((accumulator_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_34) & 127;
  }

  int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_20) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_64_1) & 63;
  aux_2 = (aux_2 + mask_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_29_1 = 0;
  int checksum_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_29_1 = ((checksum_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_29_2 = ((checksum_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_29_1) & 127;
    acc_2 = (acc_2 + checksum_29_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_66_1 = local_arr_1[aux_1 % 3];
  int pivot_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_64_1 == mask_64_2);
  assert(checksum_29_1 == checksum_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_66_1 == pivot_66_2);
}

int fn_R001260_6013_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_64) & 63;
  acc ^= aux;
  int checksum_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_29 = ((checksum_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_29) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_66 = local_arr[aux % 3];
  acc = (acc + (pivot_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_30_1 = local_arr_1[aux_1 % 3];
  int weight_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_30_2 * 2)) & 127;
  int damping_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_73_1 > 44)
  {
    acc_1 = ((acc_1 + (damping_73_1 * 2)) + 5) & 127;
    aux_1 ^= damping_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_73_2 > 44)
  {
    acc_2 = ((acc_2 + (damping_73_2 * 2)) + 5) & 127;
    aux_2 ^= damping_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_73_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_30_1 == weight_30_2);
  assert(damping_73_1 == damping_73_2);
}

int fn_R001260_6013_2(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int weight_30 = local_arr[aux % 3];
  acc = (acc + (weight_30 * 2)) & 127;
  int damping_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_73 > 44)
  {
    acc = ((acc + (damping_73 * 2)) + 5) & 127;
    aux ^= damping_73 & 15;
  }
  else
  {
    acc = ((acc - damping_73) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int vector_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_21_1 > 10)
  {
    acc_1 = ((acc_1 + (vector_21_1 * 2)) + 5) & 127;
    aux_1 ^= vector_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_21_2 > 10)
  {
    acc_2 = ((acc_2 + (vector_21_2 * 2)) + 5) & 127;
    aux_2 ^= vector_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_21_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_60_1 = local_arr_1[aux_1 % 3];
  int weight_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_60_2 * 2)) & 127;
  int weight_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_71_1)
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

  switch (weight_71_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_21_1 == vector_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_60_1 == weight_60_2);
  assert(weight_71_1 == weight_71_2);
}

int fn_R001260_6013_3(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int vector_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_21 > 10)
  {
    acc = ((acc + (vector_21 * 2)) + 5) & 127;
    aux ^= vector_21 & 15;
  }
  else
  {
    acc = ((acc - vector_21) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_60 = local_arr[aux % 3];
  acc = (acc + (weight_60 * 2)) & 127;
  int weight_71 = (aux + st.buffer[1]) & 3;
  switch (weight_71)
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

void fn_R001260_6013_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int sample_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_75_1) & 63;
  aux_2 = (aux_2 + sample_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_75_1 == sample_75_2);
}

int fn_R001260_6013_4(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int sample_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st_1 = {0};
  struct DeviceConfig_R001260_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_42_1 = local_arr_1[aux_1 % 3];
  int factor_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_42_2 * 2)) & 127;
  int scale_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_94_1)
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

  switch (scale_94_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_42_1 == factor_42_2);
  assert(scale_94_1 == scale_94_2);
}

int fn_R001260_6013_5(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_42 = local_arr[aux % 3];
  acc = (acc + (factor_42 * 2)) & 127;
  int scale_94 = (aux + st.buffer[1]) & 3;
  switch (scale_94)
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

void fn_R001260_6013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st_1 = {0};
  struct DeviceConfig_R001260_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tracker_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_24_1)
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

  switch (tracker_24_2)
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

  int bound_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_67_1 > 48)
  {
    acc_1 = ((acc_1 + (bound_67_1 * 2)) + 5) & 127;
    aux_1 ^= bound_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_67_2 > 48)
  {
    acc_2 = ((acc_2 + (bound_67_2 * 2)) + 5) & 127;
    aux_2 ^= bound_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_24_1 = 0;
  int pivot_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_24_1 = ((pivot_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_24_2 = ((pivot_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_24_1) & 127;
    acc_2 = (acc_2 + pivot_24_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_24_1 == tracker_24_2);
  assert(bound_67_1 == bound_67_2);
  assert(pivot_24_1 == pivot_24_2);
}

int fn_R001260_6013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tracker_24 = (aux + st.buffer[1]) & 3;
  switch (tracker_24)
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

  int bound_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_67 > 48)
  {
    acc = ((acc + (bound_67 * 2)) + 5) & 127;
    aux ^= bound_67 & 15;
  }
  else
  {
    acc = ((acc - bound_67) + 11) & 127;
    aux += 3;
  }
  int pivot_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_24 = ((pivot_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_24) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001260_6013_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st_1 = {0};
  struct DeviceConfig_R001260_6013_1 st_2 = {0};
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
  int cursor_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_78_1 > 46)
  {
    acc_1 = ((acc_1 + (cursor_78_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_78_2 > 46)
  {
    acc_2 = ((acc_2 + (cursor_78_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_78_1 == cursor_78_2);
}

int fn_R001260_6013_7(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_78 > 46)
  {
    acc = ((acc + (cursor_78 * 2)) + 5) & 127;
    aux ^= cursor_78 & 15;
  }
  else
  {
    acc = ((acc - cursor_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001260_6013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_53_1 = local_arr_1[aux_1 % 3];
  int anchor_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_53_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_53_1 == anchor_53_2);
}

int fn_R001260_6013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int anchor_53 = local_arr[aux % 3];
  acc = (acc + (anchor_53 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001260_6013_0 st_1 = {0};
  struct Transaction_R001260_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int factor_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_97_1) & 63;
  aux_2 = (aux_2 + factor_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_97_1 == factor_97_2);
}

int fn_R001260_6013_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001260_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int factor_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_97) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st_1 = {0};
  struct DeviceConfig_R001260_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int pivot_10_1 = 0;
  int pivot_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_10_1 = ((pivot_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_10_2 = ((pivot_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_10_1) & 127;
    acc_2 = (acc_2 + pivot_10_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_10_1 = local_arr_1[aux_1 % 3];
  int window_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_10_2 * 2)) & 127;
  int bound_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_43_1)
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

  switch (bound_43_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_10_1 == pivot_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_10_1 == window_10_2);
  assert(bound_43_1 == bound_43_2);
}

int fn_R001260_6013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int pivot_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_10 = ((pivot_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_10) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_10 = local_arr[aux % 3];
  acc = (acc + (window_10 * 2)) & 127;
  int bound_43 = (aux + st.buffer[1]) & 3;
  switch (bound_43)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
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
  int delta_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_25_1) & 63;
  aux_2 = (aux_2 + delta_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_82_1 = local_arr_1[aux_1 % 3];
  int window_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_25_1 == delta_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_82_1 == window_82_2);
}

int fn_R001260_6013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_25) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_82 = local_arr[aux % 3];
  acc = (acc + (window_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_55_1 > 35)
  {
    acc_1 = ((acc_1 + (anchor_55_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_55_2 > 35)
  {
    acc_2 = ((acc_2 + (anchor_55_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_55_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_72_1)
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

  switch (residue_72_2)
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

  int cursor_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_47_1) & 63;
  aux_2 = (aux_2 + cursor_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_55_1 == anchor_55_2);
  assert(residue_72_1 == residue_72_2);
  assert(cursor_47_1 == cursor_47_2);
}

int fn_R001260_6013_12(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_55 > 35)
  {
    acc = ((acc + (anchor_55 * 2)) + 5) & 127;
    aux ^= anchor_55 & 15;
  }
  else
  {
    acc = ((acc - anchor_55) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_72 = (aux + st.buffer[1]) & 3;
  switch (residue_72)
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

  int cursor_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001260_6013_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int mask_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_45_1)
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

  switch (mask_45_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_45_1 == mask_45_2);
}

int fn_R001260_6013_13(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int mask_45 = (aux + st.buffer[1]) & 3;
  switch (mask_45)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st_1 = {0};
  struct DeviceConfig_R001260_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_93_1 = local_arr_1[aux_1 % 3];
  int residue_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_93_1 == residue_93_2);
}

int fn_R001260_6013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_93 = local_arr[aux % 3];
  acc = (acc + (residue_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001260_6013_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st_1 = {0};
  struct DeviceConfig_R001260_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_42_1 = 0;
  int quantum_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_42_1 = ((quantum_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_42_2 = ((quantum_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_42_1) & 127;
    acc_2 = (acc_2 + quantum_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_42_1 == quantum_42_2);
}

int fn_R001260_6013_15(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001260_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_42 = ((quantum_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001260_6013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tally_49_1 = 0;
  int tally_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_49_1 = ((tally_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_49_2 = ((tally_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_49_1) & 127;
    acc_2 = (acc_2 + tally_49_2) & 127;
  }

  int scale_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_56_1)
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

  switch (scale_56_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_49_1 == tally_49_2);
  assert(scale_56_1 == scale_56_2);
}

int fn_R001260_6013_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tally_49 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_49 = ((tally_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_49) & 127;
  }

  int scale_56 = (aux + st.buffer[1]) & 3;
  switch (scale_56)
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

void fn_R001260_6013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int damping_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_19_1 > 42)
  {
    acc_1 = ((acc_1 + (damping_19_1 * 2)) + 5) & 127;
    aux_1 ^= damping_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_19_2 > 42)
  {
    acc_2 = ((acc_2 + (damping_19_2 * 2)) + 5) & 127;
    aux_2 ^= damping_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_79_1 = local_arr_1[aux_1 % 3];
  int damping_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_79_2 * 2)) & 127;
  int margin_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_39_1)
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

  switch (margin_39_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_19_1 == damping_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_79_1 == damping_79_2);
  assert(margin_39_1 == margin_39_2);
}

int fn_R001260_6013_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int damping_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_19 > 42)
  {
    acc = ((acc + (damping_19 * 2)) + 5) & 127;
    aux ^= damping_19 & 15;
  }
  else
  {
    acc = ((acc - damping_19) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_79 = local_arr[aux % 3];
  acc = (acc + (damping_79 * 2)) & 127;
  int margin_39 = (aux + st.buffer[1]) & 3;
  switch (margin_39)
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
  return (acc + aux) & 255;
}

void fn_R001260_6013_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int checksum_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_91_1) & 63;
  aux_2 = (aux_2 + checksum_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_92_1 = 0;
  int threshold_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_92_1 = ((threshold_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_92_2 = ((threshold_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_92_1) & 127;
    acc_2 = (acc_2 + threshold_92_2) & 127;
  }

  int segment_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_31_1 > 22)
  {
    acc_1 = ((acc_1 + (segment_31_1 * 2)) + 5) & 127;
    aux_1 ^= segment_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_31_2 > 22)
  {
    acc_2 = ((acc_2 + (segment_31_2 * 2)) + 5) & 127;
    aux_2 ^= segment_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_91_1 == checksum_91_2);
  assert(threshold_92_1 == threshold_92_2);
  assert(segment_31_1 == segment_31_2);
}

int fn_R001260_6013_18(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int checksum_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_91) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_92 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_92 = ((threshold_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_92) & 127;
  }

  int segment_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_31 > 22)
  {
    acc = ((acc + (segment_31 * 2)) + 5) & 127;
    aux ^= segment_31 & 15;
  }
  else
  {
    acc = ((acc - segment_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001260_6013_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st_1 = {0};
  struct AudioFrame_R001260_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int segment_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_79_1)
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

  switch (segment_79_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_90_1 = local_arr_1[aux_1 % 3];
  int factor_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_90_2 * 2)) & 127;
  int phase_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_49_1) & 63;
  aux_2 = (aux_2 + phase_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_79_1 == segment_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_90_1 == factor_90_2);
  assert(phase_49_1 == phase_49_2);
}

int fn_R001260_6013_19(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001260_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int segment_79 = (aux + st.buffer[1]) & 3;
  switch (segment_79)
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
  int local_arr[3] = {4, 9, 15};
  int factor_90 = local_arr[aux % 3];
  acc = (acc + (factor_90 * 2)) & 127;
  int phase_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001260_0_1;
  int sec_r001260_0_2;
  int sec_r001260_1_1;
  int sec_r001260_1_2;
  int sec_r001260_2_1;
  int sec_r001260_2_2;
  int sec_r001260_3_1;
  int sec_r001260_3_2;
  int sec_r001260_4_1;
  int sec_r001260_4_2;
  int sec_r001260_5_1;
  int sec_r001260_5_2;
  int sec_r001260_6_1;
  int sec_r001260_6_2;
  int sec_r001260_7_1;
  int sec_r001260_7_2;
  int sec_r001260_8_1;
  int sec_r001260_8_2;
  int sec_r001260_9_1;
  int sec_r001260_9_2;
  int sec_r001260_10_1;
  int sec_r001260_10_2;
  int sec_r001260_11_1;
  int sec_r001260_11_2;
  int sec_r001260_12_1;
  int sec_r001260_12_2;
  int sec_r001260_13_1;
  int sec_r001260_13_2;
  int sec_r001260_14_1;
  int sec_r001260_14_2;
  int sec_r001260_15_1;
  int sec_r001260_15_2;
  int sec_r001260_16_1;
  int sec_r001260_16_2;
  int sec_r001260_17_1;
  int sec_r001260_17_2;
  int sec_r001260_18_1;
  int sec_r001260_18_2;
  int sec_r001260_19_1;
  int sec_r001260_19_2;
  int pub_r001260_0_1;
  int pub_r001260_0_2;
  int pub_r001260_1_1;
  int pub_r001260_1_2;
  int pub_r001260_2_1;
  int pub_r001260_2_2;
  int pub_r001260_3_1;
  int pub_r001260_3_2;
  int pub_r001260_4_1;
  int pub_r001260_4_2;
  int pub_r001260_5_1;
  int pub_r001260_5_2;
  int pub_r001260_6_1;
  int pub_r001260_6_2;
  int pub_r001260_7_1;
  int pub_r001260_7_2;
  int pub_r001260_8_1;
  int pub_r001260_8_2;
  int pub_r001260_9_1;
  int pub_r001260_9_2;
  int pub_r001260_10_1;
  int pub_r001260_10_2;
  int pub_r001260_11_1;
  int pub_r001260_11_2;
  int pub_r001260_12_1;
  int pub_r001260_12_2;
  int pub_r001260_13_1;
  int pub_r001260_13_2;
  int pub_r001260_14_1;
  int pub_r001260_14_2;
  int pub_r001260_15_1;
  int pub_r001260_15_2;
  int pub_r001260_16_1;
  int pub_r001260_16_2;
  int pub_r001260_17_1;
  int pub_r001260_17_2;
  int pub_r001260_18_1;
  int pub_r001260_18_2;
  int pub_r001260_19_1;
  int pub_r001260_19_2;
  int pub_r001260_20_1;
  int pub_r001260_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001260_0_1 >= (-100)) && (pub_r001260_0_1 <= 100));
  __CPROVER_assume((pub_r001260_0_2 >= (-100)) && (pub_r001260_0_2 <= 100));
  __CPROVER_assume((pub_r001260_1_1 >= (-100)) && (pub_r001260_1_1 <= 100));
  __CPROVER_assume((pub_r001260_1_2 >= (-100)) && (pub_r001260_1_2 <= 100));
  __CPROVER_assume((pub_r001260_2_1 >= (-100)) && (pub_r001260_2_1 <= 100));
  __CPROVER_assume((pub_r001260_2_2 >= (-100)) && (pub_r001260_2_2 <= 100));
  __CPROVER_assume((pub_r001260_3_1 >= (-100)) && (pub_r001260_3_1 <= 100));
  __CPROVER_assume((pub_r001260_3_2 >= (-100)) && (pub_r001260_3_2 <= 100));
  __CPROVER_assume((pub_r001260_4_1 >= (-100)) && (pub_r001260_4_1 <= 100));
  __CPROVER_assume((pub_r001260_4_2 >= (-100)) && (pub_r001260_4_2 <= 100));
  __CPROVER_assume((pub_r001260_5_1 >= (-100)) && (pub_r001260_5_1 <= 100));
  __CPROVER_assume((pub_r001260_5_2 >= (-100)) && (pub_r001260_5_2 <= 100));
  __CPROVER_assume((pub_r001260_6_1 >= (-100)) && (pub_r001260_6_1 <= 100));
  __CPROVER_assume((pub_r001260_6_2 >= (-100)) && (pub_r001260_6_2 <= 100));
  __CPROVER_assume((pub_r001260_7_1 >= (-100)) && (pub_r001260_7_1 <= 100));
  __CPROVER_assume((pub_r001260_7_2 >= (-100)) && (pub_r001260_7_2 <= 100));
  __CPROVER_assume((pub_r001260_8_1 >= (-100)) && (pub_r001260_8_1 <= 100));
  __CPROVER_assume((pub_r001260_8_2 >= (-100)) && (pub_r001260_8_2 <= 100));
  __CPROVER_assume((pub_r001260_9_1 >= (-100)) && (pub_r001260_9_1 <= 100));
  __CPROVER_assume((pub_r001260_9_2 >= (-100)) && (pub_r001260_9_2 <= 100));
  __CPROVER_assume((pub_r001260_10_1 >= (-100)) && (pub_r001260_10_1 <= 100));
  __CPROVER_assume((pub_r001260_10_2 >= (-100)) && (pub_r001260_10_2 <= 100));
  __CPROVER_assume((pub_r001260_11_1 >= (-100)) && (pub_r001260_11_1 <= 100));
  __CPROVER_assume((pub_r001260_11_2 >= (-100)) && (pub_r001260_11_2 <= 100));
  __CPROVER_assume((pub_r001260_12_1 >= (-100)) && (pub_r001260_12_1 <= 100));
  __CPROVER_assume((pub_r001260_12_2 >= (-100)) && (pub_r001260_12_2 <= 100));
  __CPROVER_assume((pub_r001260_13_1 >= (-100)) && (pub_r001260_13_1 <= 100));
  __CPROVER_assume((pub_r001260_13_2 >= (-100)) && (pub_r001260_13_2 <= 100));
  __CPROVER_assume((pub_r001260_14_1 >= (-100)) && (pub_r001260_14_1 <= 100));
  __CPROVER_assume((pub_r001260_14_2 >= (-100)) && (pub_r001260_14_2 <= 100));
  __CPROVER_assume((pub_r001260_15_1 >= (-100)) && (pub_r001260_15_1 <= 100));
  __CPROVER_assume((pub_r001260_15_2 >= (-100)) && (pub_r001260_15_2 <= 100));
  __CPROVER_assume((pub_r001260_16_1 >= (-100)) && (pub_r001260_16_1 <= 100));
  __CPROVER_assume((pub_r001260_16_2 >= (-100)) && (pub_r001260_16_2 <= 100));
  __CPROVER_assume((pub_r001260_17_1 >= (-100)) && (pub_r001260_17_1 <= 100));
  __CPROVER_assume((pub_r001260_17_2 >= (-100)) && (pub_r001260_17_2 <= 100));
  __CPROVER_assume((pub_r001260_18_1 >= (-100)) && (pub_r001260_18_1 <= 100));
  __CPROVER_assume((pub_r001260_18_2 >= (-100)) && (pub_r001260_18_2 <= 100));
  __CPROVER_assume((pub_r001260_19_1 >= (-100)) && (pub_r001260_19_1 <= 100));
  __CPROVER_assume((pub_r001260_19_2 >= (-100)) && (pub_r001260_19_2 <= 100));
  __CPROVER_assume((pub_r001260_20_1 >= (-100)) && (pub_r001260_20_1 <= 100));
  __CPROVER_assume((pub_r001260_20_2 >= (-100)) && (pub_r001260_20_2 <= 100));
  __CPROVER_assume((sec_r001260_0_1 >= 0) && (sec_r001260_0_1 <= 255));
  __CPROVER_assume((sec_r001260_0_2 >= 0) && (sec_r001260_0_2 <= 255));
  __CPROVER_assume((sec_r001260_1_1 >= 0) && (sec_r001260_1_1 <= 255));
  __CPROVER_assume((sec_r001260_1_2 >= 0) && (sec_r001260_1_2 <= 255));
  __CPROVER_assume((sec_r001260_2_1 >= 0) && (sec_r001260_2_1 <= 255));
  __CPROVER_assume((sec_r001260_2_2 >= 0) && (sec_r001260_2_2 <= 255));
  __CPROVER_assume((sec_r001260_3_1 >= 0) && (sec_r001260_3_1 <= 255));
  __CPROVER_assume((sec_r001260_3_2 >= 0) && (sec_r001260_3_2 <= 255));
  __CPROVER_assume((sec_r001260_4_1 >= 0) && (sec_r001260_4_1 <= 255));
  __CPROVER_assume((sec_r001260_4_2 >= 0) && (sec_r001260_4_2 <= 255));
  __CPROVER_assume((sec_r001260_5_1 >= 0) && (sec_r001260_5_1 <= 255));
  __CPROVER_assume((sec_r001260_5_2 >= 0) && (sec_r001260_5_2 <= 255));
  __CPROVER_assume((sec_r001260_6_1 >= 0) && (sec_r001260_6_1 <= 255));
  __CPROVER_assume((sec_r001260_6_2 >= 0) && (sec_r001260_6_2 <= 255));
  __CPROVER_assume((sec_r001260_7_1 >= 0) && (sec_r001260_7_1 <= 255));
  __CPROVER_assume((sec_r001260_7_2 >= 0) && (sec_r001260_7_2 <= 255));
  __CPROVER_assume((sec_r001260_8_1 >= 0) && (sec_r001260_8_1 <= 255));
  __CPROVER_assume((sec_r001260_8_2 >= 0) && (sec_r001260_8_2 <= 255));
  __CPROVER_assume((sec_r001260_9_1 >= 0) && (sec_r001260_9_1 <= 255));
  __CPROVER_assume((sec_r001260_9_2 >= 0) && (sec_r001260_9_2 <= 255));
  __CPROVER_assume((sec_r001260_10_1 >= 0) && (sec_r001260_10_1 <= 255));
  __CPROVER_assume((sec_r001260_10_2 >= 0) && (sec_r001260_10_2 <= 255));
  __CPROVER_assume((sec_r001260_11_1 >= 0) && (sec_r001260_11_1 <= 255));
  __CPROVER_assume((sec_r001260_11_2 >= 0) && (sec_r001260_11_2 <= 255));
  __CPROVER_assume((sec_r001260_12_1 >= 0) && (sec_r001260_12_1 <= 255));
  __CPROVER_assume((sec_r001260_12_2 >= 0) && (sec_r001260_12_2 <= 255));
  __CPROVER_assume((sec_r001260_13_1 >= 0) && (sec_r001260_13_1 <= 255));
  __CPROVER_assume((sec_r001260_13_2 >= 0) && (sec_r001260_13_2 <= 255));
  __CPROVER_assume((sec_r001260_14_1 >= 0) && (sec_r001260_14_1 <= 255));
  __CPROVER_assume((sec_r001260_14_2 >= 0) && (sec_r001260_14_2 <= 255));
  __CPROVER_assume((sec_r001260_15_1 >= 0) && (sec_r001260_15_1 <= 255));
  __CPROVER_assume((sec_r001260_15_2 >= 0) && (sec_r001260_15_2 <= 255));
  __CPROVER_assume((sec_r001260_16_1 >= 0) && (sec_r001260_16_1 <= 255));
  __CPROVER_assume((sec_r001260_16_2 >= 0) && (sec_r001260_16_2 <= 255));
  __CPROVER_assume((sec_r001260_17_1 >= 0) && (sec_r001260_17_1 <= 255));
  __CPROVER_assume((sec_r001260_17_2 >= 0) && (sec_r001260_17_2 <= 255));
  __CPROVER_assume((sec_r001260_18_1 >= 0) && (sec_r001260_18_1 <= 255));
  __CPROVER_assume((sec_r001260_18_2 >= 0) && (sec_r001260_18_2 <= 255));
  __CPROVER_assume((sec_r001260_19_1 >= 0) && (sec_r001260_19_1 <= 255));
  __CPROVER_assume((sec_r001260_19_2 >= 0) && (sec_r001260_19_2 <= 255));
  struct Transaction_R001260_6013_0 st_var_0_1 = {0};
  struct Transaction_R001260_6013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001260_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001260_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001260_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001260_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001260_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001260_0_2 + 7) & 15;
  struct DeviceConfig_R001260_6013_1 st_var_1_1 = {0};
  struct DeviceConfig_R001260_6013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001260_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001260_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001260_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001260_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001260_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001260_0_2 + 9) & 15;
  struct AudioFrame_R001260_6013_2 st_var_2_1 = {0};
  struct AudioFrame_R001260_6013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001260_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001260_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001260_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001260_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001260_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001260_0_2 + 11) & 15;
  union RegisterBank_R001260_6013_0 u_var_1;
  union RegisterBank_R001260_6013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001260_6013_0(sec_r001260_0_1, sec_r001260_1_1, pub_r001260_2_1, pub_r001260_3_1);
  int helper_flow_0_2 = fn_R001260_6013_0(sec_r001260_0_2, sec_r001260_1_2, pub_r001260_2_2, pub_r001260_3_2);
  fn_R001260_6013_0_2(sec_r001260_0_1, sec_r001260_1_1, pub_r001260_2_1, pub_r001260_3_1, sec_r001260_0_2, sec_r001260_1_2, pub_r001260_2_2, pub_r001260_3_2);
  int helper_flow_1_1 = fn_R001260_6013_1(sec_r001260_1_1, pub_r001260_2_1, pub_r001260_3_1, pub_r001260_4_1, pub_r001260_5_1);
  int helper_flow_1_2 = fn_R001260_6013_1(sec_r001260_1_2, pub_r001260_2_2, pub_r001260_3_2, pub_r001260_4_2, pub_r001260_5_2);
  fn_R001260_6013_1_2(sec_r001260_1_1, pub_r001260_2_1, pub_r001260_3_1, pub_r001260_4_1, pub_r001260_5_1, sec_r001260_1_2, pub_r001260_2_2, pub_r001260_3_2, pub_r001260_4_2, pub_r001260_5_2);
  int helper_flow_2_1 = fn_R001260_6013_2(sec_r001260_2_1, pub_r001260_3_1);
  int helper_flow_2_2 = fn_R001260_6013_2(sec_r001260_2_2, pub_r001260_3_2);
  fn_R001260_6013_2_2(sec_r001260_2_1, pub_r001260_3_1, sec_r001260_2_2, pub_r001260_3_2);
  int helper_flow_3_1 = fn_R001260_6013_3(sec_r001260_3_1, sec_r001260_4_1);
  int helper_flow_3_2 = fn_R001260_6013_3(sec_r001260_3_2, sec_r001260_4_2);
  fn_R001260_6013_3_2(sec_r001260_3_1, sec_r001260_4_1, sec_r001260_3_2, sec_r001260_4_2);
  int helper_flow_4_1 = fn_R001260_6013_4(sec_r001260_4_1, sec_r001260_5_1, pub_r001260_6_1);
  int helper_flow_4_2 = fn_R001260_6013_4(sec_r001260_4_2, sec_r001260_5_2, pub_r001260_6_2);
  fn_R001260_6013_4_2(sec_r001260_4_1, sec_r001260_5_1, pub_r001260_6_1, sec_r001260_4_2, sec_r001260_5_2, pub_r001260_6_2);
  int helper_flow_5_1 = fn_R001260_6013_5(sec_r001260_5_1, pub_r001260_6_1);
  int helper_flow_5_2 = fn_R001260_6013_5(sec_r001260_5_2, pub_r001260_6_2);
  fn_R001260_6013_5_2(sec_r001260_5_1, pub_r001260_6_1, sec_r001260_5_2, pub_r001260_6_2);
  int helper_flow_6_1 = fn_R001260_6013_6(sec_r001260_6_1, pub_r001260_7_1, pub_r001260_8_1, pub_r001260_9_1);
  int helper_flow_6_2 = fn_R001260_6013_6(sec_r001260_6_2, pub_r001260_7_2, pub_r001260_8_2, pub_r001260_9_2);
  fn_R001260_6013_6_2(sec_r001260_6_1, pub_r001260_7_1, pub_r001260_8_1, pub_r001260_9_1, sec_r001260_6_2, pub_r001260_7_2, pub_r001260_8_2, pub_r001260_9_2);
  int helper_flow_7_1 = fn_R001260_6013_7(sec_r001260_7_1, sec_r001260_8_1);
  int helper_flow_7_2 = fn_R001260_6013_7(sec_r001260_7_2, sec_r001260_8_2);
  fn_R001260_6013_7_2(sec_r001260_7_1, sec_r001260_8_1, sec_r001260_7_2, sec_r001260_8_2);
  int helper_flow_8_1 = fn_R001260_6013_8(sec_r001260_8_1, sec_r001260_9_1, pub_r001260_10_1, pub_r001260_11_1);
  int helper_flow_8_2 = fn_R001260_6013_8(sec_r001260_8_2, sec_r001260_9_2, pub_r001260_10_2, pub_r001260_11_2);
  fn_R001260_6013_8_2(sec_r001260_8_1, sec_r001260_9_1, pub_r001260_10_1, pub_r001260_11_1, sec_r001260_8_2, sec_r001260_9_2, pub_r001260_10_2, pub_r001260_11_2);
  int stage_v_0_1 = (((sec_r001260_5_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_0_2 = (((sec_r001260_5_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_0_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((pub_r001260_13_1 * 2) + 19) & 63;
  int stage_v_1_2 = ((pub_r001260_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001260_9_1 ^ 0x2A) * 2) + pub_r001260_8_1) & 127;
  int stage_v_2_2 = (((sec_r001260_9_2 ^ 0x2A) * 2) + pub_r001260_8_2) & 127;
  if (stage_v_2_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001260_18_1 ^ 0x2A) * 2) + pub_r001260_4_1) & 127;
  int stage_v_3_2 = (((sec_r001260_18_2 ^ 0x2A) * 2) + pub_r001260_4_2) & 127;
  if (stage_v_3_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((sec_r001260_15_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_4_2 = (((sec_r001260_15_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_4_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((sec_r001260_12_1 ^ 0x2A) * 2) + pub_r001260_14_1) & 127;
  int stage_v_5_2 = (((sec_r001260_12_2 ^ 0x2A) * 2) + pub_r001260_14_2) & 127;
  if (stage_v_5_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001260_17_1) & 127;
  int stage_v_6_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001260_17_2) & 127;
  if (stage_v_6_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((pub_r001260_4_1 * 2) + 44) & 63;
  int stage_v_7_2 = ((pub_r001260_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001260_5_1 ^ 0x2A) * 2) + pub_r001260_2_1) & 127;
  int stage_v_8_2 = (((sec_r001260_5_2 ^ 0x2A) * 2) + pub_r001260_2_2) & 127;
  if (stage_v_8_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001260_19_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_9_2 = (((sec_r001260_19_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_9_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((sec_r001260_4_1 ^ 0x2A) * 2) + pub_r001260_13_1) & 127;
  int stage_v_10_2 = (((sec_r001260_4_2 ^ 0x2A) * 2) + pub_r001260_13_2) & 127;
  if (stage_v_10_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001260_17_1 ^ 0x2A) * 2) + pub_r001260_13_1) & 127;
  int stage_v_11_2 = (((sec_r001260_17_2 ^ 0x2A) * 2) + pub_r001260_13_2) & 127;
  if (stage_v_11_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r001260_12_1 ^ 0x2A) * 2) + pub_r001260_4_1) & 127;
  int stage_v_12_2 = (((sec_r001260_12_2 ^ 0x2A) * 2) + pub_r001260_4_2) & 127;
  if (stage_v_12_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001260_17_1) & 127;
  int stage_v_13_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001260_17_2) & 127;
  if (stage_v_13_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((pub_r001260_12_1 * 2) + 21) & 63;
  int stage_v_14_2 = ((pub_r001260_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001260_17_1) & 127;
  int stage_v_15_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001260_17_2) & 127;
  if (stage_v_15_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((pub_r001260_6_1 * 2) + 39) & 63;
  int stage_v_16_2 = ((pub_r001260_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001260_2_1) & 127;
  int stage_v_17_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001260_2_2) & 127;
  if (stage_v_17_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((pub_r001260_1_1 * 2) + 49) & 63;
  int stage_v_18_2 = ((pub_r001260_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001260_14_1 ^ 0x2A) * 2) + pub_r001260_1_1) & 127;
  int stage_v_19_2 = (((sec_r001260_14_2 ^ 0x2A) * 2) + pub_r001260_1_2) & 127;
  if (stage_v_19_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001260_18_1) & 127;
  int stage_v_20_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001260_18_2) & 127;
  if (stage_v_20_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((pub_r001260_0_1 * 2) + 44) & 63;
  int stage_v_21_2 = ((pub_r001260_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_22_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
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
  int stage_v_23_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001260_14_1) & 127;
  int stage_v_23_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001260_14_2) & 127;
  if (stage_v_23_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001260_20_1) & 127;
  int stage_v_24_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001260_20_2) & 127;
  if (stage_v_24_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001260_17_1) & 127;
  int stage_v_25_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001260_17_2) & 127;
  if (stage_v_25_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((pub_r001260_13_1 * 2) + 27) & 63;
  int stage_v_26_2 = ((pub_r001260_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((sec_r001260_15_1 ^ 0x2A) * 2) + pub_r001260_1_1) & 127;
  int stage_v_27_2 = (((sec_r001260_15_2 ^ 0x2A) * 2) + pub_r001260_1_2) & 127;
  if (stage_v_27_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_28_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_28_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001260_8_1) & 127;
  int stage_v_29_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001260_8_2) & 127;
  if (stage_v_29_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001260_10_1) & 127;
  int stage_v_30_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001260_10_2) & 127;
  if (stage_v_30_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_31_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_31_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((sec_r001260_7_1 ^ 0x2A) * 2) + pub_r001260_1_1) & 127;
  int stage_v_32_2 = (((sec_r001260_7_2 ^ 0x2A) * 2) + pub_r001260_1_2) & 127;
  if (stage_v_32_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_33_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_33_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001260_16_1) & 127;
  int stage_v_34_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001260_16_2) & 127;
  if (stage_v_34_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((pub_r001260_1_1 * 2) + 39) & 63;
  int stage_v_35_2 = ((pub_r001260_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001260_2_1 ^ 0x2A) * 2) + pub_r001260_10_1) & 127;
  int stage_v_36_2 = (((sec_r001260_2_2 ^ 0x2A) * 2) + pub_r001260_10_2) & 127;
  if (stage_v_36_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((sec_r001260_15_1 ^ 0x2A) * 2) + pub_r001260_17_1) & 127;
  int stage_v_37_2 = (((sec_r001260_15_2 ^ 0x2A) * 2) + pub_r001260_17_2) & 127;
  if (stage_v_37_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_38_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_38_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((pub_r001260_0_1 * 2) + 36) & 63;
  int stage_v_39_2 = ((pub_r001260_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((sec_r001260_10_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_40_2 = (((sec_r001260_10_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_40_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((pub_r001260_10_1 * 2) + 49) & 63;
  int stage_v_41_2 = ((pub_r001260_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001260_10_1) & 127;
  int stage_v_42_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001260_10_2) & 127;
  if (stage_v_42_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((pub_r001260_5_1 * 2) + 39) & 63;
  int stage_v_43_2 = ((pub_r001260_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001260_7_1 * 2) + 14) & 63;
  int stage_v_44_2 = ((pub_r001260_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001260_10_1) & 127;
  int stage_v_45_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001260_10_2) & 127;
  if (stage_v_45_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((pub_r001260_16_1 * 2) + 14) & 63;
  int stage_v_46_2 = ((pub_r001260_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((sec_r001260_17_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_47_2 = (((sec_r001260_17_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_47_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((sec_r001260_1_1 ^ 0x2A) * 2) + pub_r001260_14_1) & 127;
  int stage_v_48_2 = (((sec_r001260_1_2 ^ 0x2A) * 2) + pub_r001260_14_2) & 127;
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
  int stage_v_49_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001260_1_1) & 127;
  int stage_v_49_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001260_1_2) & 127;
  if (stage_v_49_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((pub_r001260_7_1 * 2) + 24) & 63;
  int stage_v_50_2 = ((pub_r001260_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_51_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_51_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001260_18_1) & 127;
  int stage_v_52_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001260_18_2) & 127;
  if (stage_v_52_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((pub_r001260_9_1 * 2) + 43) & 63;
  int stage_v_53_2 = ((pub_r001260_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_54_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_54_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((pub_r001260_14_1 * 2) + 50) & 63;
  int stage_v_55_2 = ((pub_r001260_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001260_12_1 * 2) + 10) & 63;
  int stage_v_56_2 = ((pub_r001260_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((sec_r001260_15_1 ^ 0x2A) * 2) + pub_r001260_14_1) & 127;
  int stage_v_57_2 = (((sec_r001260_15_2 ^ 0x2A) * 2) + pub_r001260_14_2) & 127;
  if (stage_v_57_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001260_19_1) & 127;
  int stage_v_58_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001260_19_2) & 127;
  if (stage_v_58_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001260_1_1) & 127;
  int stage_v_59_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001260_1_2) & 127;
  if (stage_v_59_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001260_15_1) & 127;
  int stage_v_60_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001260_15_2) & 127;
  if (stage_v_60_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_61_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_61_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001260_0_1) & 127;
  int stage_v_62_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001260_0_2) & 127;
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
  int stage_v_63_1 = (((sec_r001260_0_1 ^ 0x2A) * 2) + pub_r001260_19_1) & 127;
  int stage_v_63_2 = (((sec_r001260_0_2 ^ 0x2A) * 2) + pub_r001260_19_2) & 127;
  if (stage_v_63_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001260_10_1) & 127;
  int stage_v_64_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001260_10_2) & 127;
  if (stage_v_64_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((sec_r001260_7_1 ^ 0x2A) * 2) + pub_r001260_9_1) & 127;
  int stage_v_65_2 = (((sec_r001260_7_2 ^ 0x2A) * 2) + pub_r001260_9_2) & 127;
  if (stage_v_65_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_66_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_66_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((pub_r001260_0_1 * 2) + 31) & 63;
  int stage_v_67_2 = ((pub_r001260_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001260_13_1) & 127;
  int stage_v_68_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001260_13_2) & 127;
  if (stage_v_68_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((sec_r001260_6_1 ^ 0x2A) * 2) + pub_r001260_16_1) & 127;
  int stage_v_69_2 = (((sec_r001260_6_2 ^ 0x2A) * 2) + pub_r001260_16_2) & 127;
  if (stage_v_69_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((pub_r001260_17_1 * 2) + 12) & 63;
  int stage_v_70_2 = ((pub_r001260_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((sec_r001260_14_1 ^ 0x2A) * 2) + pub_r001260_20_1) & 127;
  int stage_v_71_2 = (((sec_r001260_14_2 ^ 0x2A) * 2) + pub_r001260_20_2) & 127;
  if (stage_v_71_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001260_15_1) & 127;
  int stage_v_72_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001260_15_2) & 127;
  if (stage_v_72_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001260_0_1) & 127;
  int stage_v_73_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001260_0_2) & 127;
  if (stage_v_73_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001260_10_1) & 127;
  int stage_v_74_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001260_10_2) & 127;
  if (stage_v_74_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001260_7_1) & 127;
  int stage_v_75_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001260_7_2) & 127;
  if (stage_v_75_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001260_9_1) & 127;
  int stage_v_76_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001260_9_2) & 127;
  if (stage_v_76_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_77_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_77_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((sec_r001260_17_1 ^ 0x2A) * 2) + pub_r001260_4_1) & 127;
  int stage_v_78_2 = (((sec_r001260_17_2 ^ 0x2A) * 2) + pub_r001260_4_2) & 127;
  if (stage_v_78_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((sec_r001260_4_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_79_2 = (((sec_r001260_4_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_79_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001260_4_1) & 127;
  int stage_v_80_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001260_4_2) & 127;
  if (stage_v_80_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((sec_r001260_14_1 ^ 0x2A) * 2) + pub_r001260_18_1) & 127;
  int stage_v_81_2 = (((sec_r001260_14_2 ^ 0x2A) * 2) + pub_r001260_18_2) & 127;
  if (stage_v_81_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((pub_r001260_2_1 * 2) + 5) & 63;
  int stage_v_82_2 = ((pub_r001260_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001260_13_1) & 127;
  int stage_v_83_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001260_13_2) & 127;
  if (stage_v_83_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001260_0_1) & 127;
  int stage_v_84_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001260_0_2) & 127;
  if (stage_v_84_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((pub_r001260_3_1 * 2) + 21) & 63;
  int stage_v_85_2 = ((pub_r001260_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001260_9_1) & 127;
  int stage_v_86_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001260_9_2) & 127;
  if (stage_v_86_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((sec_r001260_11_1 ^ 0x2A) * 2) + pub_r001260_18_1) & 127;
  int stage_v_87_2 = (((sec_r001260_11_2 ^ 0x2A) * 2) + pub_r001260_18_2) & 127;
  if (stage_v_87_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001260_4_1) & 127;
  int stage_v_88_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001260_4_2) & 127;
  if (stage_v_88_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_89_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_89_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((sec_r001260_3_1 ^ 0x2A) * 2) + pub_r001260_14_1) & 127;
  int stage_v_90_2 = (((sec_r001260_3_2 ^ 0x2A) * 2) + pub_r001260_14_2) & 127;
  if (stage_v_90_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_91_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_91_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001260_16_1) & 127;
  int stage_v_92_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001260_16_2) & 127;
  if (stage_v_92_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((sec_r001260_15_1 ^ 0x2A) * 2) + pub_r001260_8_1) & 127;
  int stage_v_93_2 = (((sec_r001260_15_2 ^ 0x2A) * 2) + pub_r001260_8_2) & 127;
  if (stage_v_93_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((sec_r001260_9_1 ^ 0x2A) * 2) + pub_r001260_12_1) & 127;
  int stage_v_94_2 = (((sec_r001260_9_2 ^ 0x2A) * 2) + pub_r001260_12_2) & 127;
  if (stage_v_94_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001260_12_1 * 2) + 27) & 63;
  int stage_v_95_2 = ((pub_r001260_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001260_9_1 * 2) + 50) & 63;
  int stage_v_96_2 = ((pub_r001260_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001260_19_1) & 127;
  int stage_v_97_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001260_19_2) & 127;
  if (stage_v_97_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_98_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_98_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001260_2_1) & 127;
  int stage_v_99_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001260_2_2) & 127;
  if (stage_v_99_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((pub_r001260_5_1 * 2) + 23) & 63;
  int stage_v_100_2 = ((pub_r001260_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_101_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_101_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_102_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_102_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001260_10_1) & 127;
  int stage_v_103_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001260_10_2) & 127;
  if (stage_v_103_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001260_18_1) & 127;
  int stage_v_104_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001260_18_2) & 127;
  if (stage_v_104_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((sec_r001260_12_1 ^ 0x2A) * 2) + pub_r001260_2_1) & 127;
  int stage_v_105_2 = (((sec_r001260_12_2 ^ 0x2A) * 2) + pub_r001260_2_2) & 127;
  if (stage_v_105_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001260_12_1) & 127;
  int stage_v_106_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001260_12_2) & 127;
  if (stage_v_106_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001260_4_1) & 127;
  int stage_v_107_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001260_4_2) & 127;
  if (stage_v_107_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001260_0_1) & 127;
  int stage_v_108_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001260_0_2) & 127;
  if (stage_v_108_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((sec_r001260_15_1 ^ 0x2A) * 2) + pub_r001260_18_1) & 127;
  int stage_v_109_2 = (((sec_r001260_15_2 ^ 0x2A) * 2) + pub_r001260_18_2) & 127;
  if (stage_v_109_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((pub_r001260_14_1 * 2) + 35) & 63;
  int stage_v_110_2 = ((pub_r001260_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001260_8_1) & 127;
  int stage_v_111_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001260_8_2) & 127;
  if (stage_v_111_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((pub_r001260_19_1 * 2) + 12) & 63;
  int stage_v_112_2 = ((pub_r001260_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001260_17_1 * 2) + 7) & 63;
  int stage_v_113_2 = ((pub_r001260_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_114_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
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
  int stage_v_115_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001260_7_1) & 127;
  int stage_v_115_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001260_7_2) & 127;
  if (stage_v_115_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001260_4_1) & 127;
  int stage_v_116_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001260_4_2) & 127;
  if (stage_v_116_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001260_15_1) & 127;
  int stage_v_117_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001260_15_2) & 127;
  if (stage_v_117_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001260_19_1) & 127;
  int stage_v_118_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001260_19_2) & 127;
  if (stage_v_118_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_119_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_119_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((sec_r001260_19_1 ^ 0x2A) * 2) + pub_r001260_4_1) & 127;
  int stage_v_120_2 = (((sec_r001260_19_2 ^ 0x2A) * 2) + pub_r001260_4_2) & 127;
  if (stage_v_120_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001260_2_1) & 127;
  int stage_v_121_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001260_2_2) & 127;
  if (stage_v_121_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001260_19_1) & 127;
  int stage_v_122_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001260_19_2) & 127;
  if (stage_v_122_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001260_14_1) & 127;
  int stage_v_123_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001260_14_2) & 127;
  if (stage_v_123_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001260_1_1) & 127;
  int stage_v_124_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001260_1_2) & 127;
  if (stage_v_124_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((sec_r001260_9_1 ^ 0x2A) * 2) + pub_r001260_20_1) & 127;
  int stage_v_125_2 = (((sec_r001260_9_2 ^ 0x2A) * 2) + pub_r001260_20_2) & 127;
  if (stage_v_125_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((pub_r001260_16_1 * 2) + 27) & 63;
  int stage_v_126_2 = ((pub_r001260_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001260_17_1 * 2) + 32) & 63;
  int stage_v_127_2 = ((pub_r001260_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_128_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_128_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((sec_r001260_10_1 ^ 0x2A) * 2) + pub_r001260_15_1) & 127;
  int stage_v_129_2 = (((sec_r001260_10_2 ^ 0x2A) * 2) + pub_r001260_15_2) & 127;
  if (stage_v_129_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((sec_r001260_11_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_130_2 = (((sec_r001260_11_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_130_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((pub_r001260_1_1 * 2) + 28) & 63;
  int stage_v_131_2 = ((pub_r001260_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001260_7_1) & 127;
  int stage_v_132_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001260_7_2) & 127;
  if (stage_v_132_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((sec_r001260_3_1 ^ 0x2A) * 2) + pub_r001260_14_1) & 127;
  int stage_v_133_2 = (((sec_r001260_3_2 ^ 0x2A) * 2) + pub_r001260_14_2) & 127;
  if (stage_v_133_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_134_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_134_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001260_14_1) & 127;
  int stage_v_135_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001260_14_2) & 127;
  if (stage_v_135_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_136_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_136_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((pub_r001260_6_1 * 2) + 26) & 63;
  int stage_v_137_2 = ((pub_r001260_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001260_16_1) & 127;
  int stage_v_138_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001260_16_2) & 127;
  if (stage_v_138_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((pub_r001260_5_1 * 2) + 21) & 63;
  int stage_v_139_2 = ((pub_r001260_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_140_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_140_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001260_15_1) & 127;
  int stage_v_141_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001260_15_2) & 127;
  if (stage_v_141_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_121_1 ^ 0x2A) * 2) + pub_r001260_17_1) & 127;
  int stage_v_142_2 = (((stage_v_121_2 ^ 0x2A) * 2) + pub_r001260_17_2) & 127;
  if (stage_v_142_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001260_1_1) & 127;
  int stage_v_143_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001260_1_2) & 127;
  if (stage_v_143_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_142_1 ^ 0x2A) * 2) + pub_r001260_9_1) & 127;
  int stage_v_144_2 = (((stage_v_142_2 ^ 0x2A) * 2) + pub_r001260_9_2) & 127;
  if (stage_v_144_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_145_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_145_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((pub_r001260_7_1 * 2) + 8) & 63;
  int stage_v_146_2 = ((pub_r001260_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((sec_r001260_17_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_147_2 = (((sec_r001260_17_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_147_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((pub_r001260_20_1 * 2) + 9) & 63;
  int stage_v_148_2 = ((pub_r001260_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_149_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_149_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_150_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_150_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((pub_r001260_8_1 * 2) + 13) & 63;
  int stage_v_151_2 = ((pub_r001260_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_144_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_152_2 = (((stage_v_144_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_152_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_109_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_153_2 = (((stage_v_109_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_153_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_144_1 ^ 0x2A) * 2) + pub_r001260_19_1) & 127;
  int stage_v_154_2 = (((stage_v_144_2 ^ 0x2A) * 2) + pub_r001260_19_2) & 127;
  if (stage_v_154_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_147_1 ^ 0x2A) * 2) + pub_r001260_7_1) & 127;
  int stage_v_155_2 = (((stage_v_147_2 ^ 0x2A) * 2) + pub_r001260_7_2) & 127;
  if (stage_v_155_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001260_17_1) & 127;
  int stage_v_156_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001260_17_2) & 127;
  if (stage_v_156_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_156_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_157_2 = (((stage_v_156_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_157_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001260_12_1) & 127;
  int stage_v_158_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001260_12_2) & 127;
  if (stage_v_158_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((pub_r001260_20_1 * 2) + 16) & 63;
  int stage_v_159_2 = ((pub_r001260_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001260_0_1) & 127;
  int stage_v_160_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001260_0_2) & 127;
  if (stage_v_160_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((pub_r001260_11_1 * 2) + 45) & 63;
  int stage_v_161_2 = ((pub_r001260_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_147_1 ^ 0x2A) * 2) + pub_r001260_7_1) & 127;
  int stage_v_162_2 = (((stage_v_147_2 ^ 0x2A) * 2) + pub_r001260_7_2) & 127;
  if (stage_v_162_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_135_1 ^ 0x2A) * 2) + pub_r001260_14_1) & 127;
  int stage_v_163_2 = (((stage_v_135_2 ^ 0x2A) * 2) + pub_r001260_14_2) & 127;
  if (stage_v_163_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001260_18_1) & 127;
  int stage_v_164_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001260_18_2) & 127;
  if (stage_v_164_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001260_7_1) & 127;
  int stage_v_165_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001260_7_2) & 127;
  if (stage_v_165_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_166_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_166_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_152_1 ^ 0x2A) * 2) + pub_r001260_8_1) & 127;
  int stage_v_167_2 = (((stage_v_152_2 ^ 0x2A) * 2) + pub_r001260_8_2) & 127;
  if (stage_v_167_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((pub_r001260_1_1 * 2) + 20) & 63;
  int stage_v_168_2 = ((pub_r001260_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001260_9_1) & 127;
  int stage_v_169_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001260_9_2) & 127;
  if (stage_v_169_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001260_20_1) & 127;
  int stage_v_170_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001260_20_2) & 127;
  if (stage_v_170_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001260_0_1) & 127;
  int stage_v_171_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001260_0_2) & 127;
  if (stage_v_171_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_172_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_172_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001260_2_1) & 127;
  int stage_v_173_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001260_2_2) & 127;
  if (stage_v_173_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001260_7_1) & 127;
  int stage_v_174_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001260_7_2) & 127;
  if (stage_v_174_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((pub_r001260_15_1 * 2) + 10) & 63;
  int stage_v_175_2 = ((pub_r001260_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001260_20_1) & 127;
  int stage_v_176_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001260_20_2) & 127;
  if (stage_v_176_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001260_0_1) & 127;
  int stage_v_177_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001260_0_2) & 127;
  if (stage_v_177_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_178_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_178_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((sec_r001260_6_1 ^ 0x2A) * 2) + pub_r001260_13_1) & 127;
  int stage_v_179_2 = (((sec_r001260_6_2 ^ 0x2A) * 2) + pub_r001260_13_2) & 127;
  if (stage_v_179_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_142_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_180_2 = (((stage_v_142_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_180_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001260_8_1) & 127;
  int stage_v_181_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001260_8_2) & 127;
  if (stage_v_181_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001260_4_1) & 127;
  int stage_v_182_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001260_4_2) & 127;
  if (stage_v_182_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001260_19_1) & 127;
  int stage_v_183_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001260_19_2) & 127;
  if (stage_v_183_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((pub_r001260_12_1 * 2) + 33) & 63;
  int stage_v_184_2 = ((pub_r001260_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001260_6_1 * 2) + 50) & 63;
  int stage_v_185_2 = ((pub_r001260_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001260_11_1) & 127;
  int stage_v_186_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001260_11_2) & 127;
  if (stage_v_186_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001260_0_1) & 127;
  int stage_v_187_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001260_0_2) & 127;
  if (stage_v_187_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((sec_r001260_9_1 ^ 0x2A) * 2) + pub_r001260_20_1) & 127;
  int stage_v_188_2 = (((sec_r001260_9_2 ^ 0x2A) * 2) + pub_r001260_20_2) & 127;
  if (stage_v_188_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((pub_r001260_2_1 * 2) + 48) & 63;
  int stage_v_189_2 = ((pub_r001260_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001260_17_1 * 2) + 29) & 63;
  int stage_v_190_2 = ((pub_r001260_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_181_1 ^ 0x2A) * 2) + pub_r001260_9_1) & 127;
  int stage_v_191_2 = (((stage_v_181_2 ^ 0x2A) * 2) + pub_r001260_9_2) & 127;
  if (stage_v_191_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_192_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_192_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001260_10_1) & 127;
  int stage_v_193_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001260_10_2) & 127;
  if (stage_v_193_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001260_8_1) & 127;
  int stage_v_194_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001260_8_2) & 127;
  if (stage_v_194_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001260_20_1) & 127;
  int stage_v_195_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001260_20_2) & 127;
  if (stage_v_195_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001260_17_1) & 127;
  int stage_v_196_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001260_17_2) & 127;
  if (stage_v_196_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001260_20_1) & 127;
  int stage_v_197_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001260_20_2) & 127;
  if (stage_v_197_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((pub_r001260_13_1 * 2) + 20) & 63;
  int stage_v_198_2 = ((pub_r001260_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((sec_r001260_11_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_199_2 = (((sec_r001260_11_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_199_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_162_1 ^ 0x2A) * 2) + pub_r001260_15_1) & 127;
  int stage_v_200_2 = (((stage_v_162_2 ^ 0x2A) * 2) + pub_r001260_15_2) & 127;
  if (stage_v_200_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((sec_r001260_4_1 ^ 0x2A) * 2) + pub_r001260_12_1) & 127;
  int stage_v_201_2 = (((sec_r001260_4_2 ^ 0x2A) * 2) + pub_r001260_12_2) & 127;
  if (stage_v_201_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((pub_r001260_7_1 * 2) + 40) & 63;
  int stage_v_202_2 = ((pub_r001260_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_183_1 ^ 0x2A) * 2) + pub_r001260_13_1) & 127;
  int stage_v_203_2 = (((stage_v_183_2 ^ 0x2A) * 2) + pub_r001260_13_2) & 127;
  if (stage_v_203_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_204_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_204_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((pub_r001260_6_1 * 2) + 18) & 63;
  int stage_v_205_2 = ((pub_r001260_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001260_18_1 * 2) + 18) & 63;
  int stage_v_206_2 = ((pub_r001260_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001260_2_1) & 127;
  int stage_v_207_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001260_2_2) & 127;
  if (stage_v_207_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001260_18_1) & 127;
  int stage_v_208_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001260_18_2) & 127;
  if (stage_v_208_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001260_16_1) & 127;
  int stage_v_209_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001260_16_2) & 127;
  if (stage_v_209_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001260_7_1) & 127;
  int stage_v_210_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001260_7_2) & 127;
  if (stage_v_210_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001260_1_1) & 127;
  int stage_v_211_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001260_1_2) & 127;
  if (stage_v_211_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((sec_r001260_7_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_212_2 = (((sec_r001260_7_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_212_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001260_13_1) & 127;
  int stage_v_213_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001260_13_2) & 127;
  if (stage_v_213_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((sec_r001260_9_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_214_2 = (((sec_r001260_9_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_214_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((stage_v_214_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_215_2 = (((stage_v_214_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_215_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((pub_r001260_10_1 * 2) + 28) & 63;
  int stage_v_216_2 = ((pub_r001260_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((sec_r001260_9_1 ^ 0x2A) * 2) + pub_r001260_5_1) & 127;
  int stage_v_217_2 = (((sec_r001260_9_2 ^ 0x2A) * 2) + pub_r001260_5_2) & 127;
  if (stage_v_217_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_203_1 ^ 0x2A) * 2) + pub_r001260_1_1) & 127;
  int stage_v_218_2 = (((stage_v_203_2 ^ 0x2A) * 2) + pub_r001260_1_2) & 127;
  if (stage_v_218_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((pub_r001260_10_1 * 2) + 45) & 63;
  int stage_v_219_2 = ((pub_r001260_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_201_1 ^ 0x2A) * 2) + pub_r001260_6_1) & 127;
  int stage_v_220_2 = (((stage_v_201_2 ^ 0x2A) * 2) + pub_r001260_6_2) & 127;
  if (stage_v_220_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_177_1 ^ 0x2A) * 2) + pub_r001260_12_1) & 127;
  int stage_v_221_2 = (((stage_v_177_2 ^ 0x2A) * 2) + pub_r001260_12_2) & 127;
  if (stage_v_221_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001260_3_1) & 127;
  int stage_v_222_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001260_3_2) & 127;
  if (stage_v_222_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001260_20_1) & 127;
  int stage_v_223_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001260_20_2) & 127;
  if (stage_v_223_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001260_2_1) & 127;
  int stage_v_224_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001260_2_2) & 127;
  if (stage_v_224_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001260_18_1 != sec_r001260_18_2);
  __CPROVER_assume(pub_r001260_14_1 == pub_r001260_14_2);
  __CPROVER_assume(sec_r001260_13_1 != sec_r001260_13_2);
  __CPROVER_assume(pub_r001260_9_1 == pub_r001260_9_2);
  __CPROVER_assume(pub_r001260_12_1 == pub_r001260_12_2);
  __CPROVER_assume(sec_r001260_8_1 != sec_r001260_8_2);
  __CPROVER_assume(pub_r001260_2_1 == pub_r001260_2_2);
  __CPROVER_assume(pub_r001260_1_1 == pub_r001260_1_2);
  __CPROVER_assume(pub_r001260_5_1 == pub_r001260_5_2);
  __CPROVER_assume(pub_r001260_8_1 == pub_r001260_8_2);
  __CPROVER_assume(sec_r001260_11_1 != sec_r001260_11_2);
  __CPROVER_assume(sec_r001260_7_1 != sec_r001260_7_2);
  __CPROVER_assume(pub_r001260_11_1 == pub_r001260_11_2);
  __CPROVER_assume(pub_r001260_3_1 == pub_r001260_3_2);
  __CPROVER_assume(sec_r001260_1_1 != sec_r001260_1_2);
  __CPROVER_assume(sec_r001260_16_1 != sec_r001260_16_2);
  __CPROVER_assume(sec_r001260_3_1 != sec_r001260_3_2);
  __CPROVER_assume(pub_r001260_6_1 == pub_r001260_6_2);
  __CPROVER_assume(pub_r001260_13_1 == pub_r001260_13_2);
  __CPROVER_assume(sec_r001260_15_1 != sec_r001260_15_2);
  __CPROVER_assume(sec_r001260_4_1 != sec_r001260_4_2);
  __CPROVER_assume(sec_r001260_19_1 != sec_r001260_19_2);
  __CPROVER_assume(sec_r001260_0_1 != sec_r001260_0_2);
  __CPROVER_assume(pub_r001260_19_1 == pub_r001260_19_2);
  __CPROVER_assume(sec_r001260_2_1 != sec_r001260_2_2);
  __CPROVER_assume(sec_r001260_6_1 != sec_r001260_6_2);
  __CPROVER_assume(pub_r001260_4_1 == pub_r001260_4_2);
  __CPROVER_assume(sec_r001260_9_1 != sec_r001260_9_2);
  __CPROVER_assume(sec_r001260_12_1 != sec_r001260_12_2);
  __CPROVER_assume(pub_r001260_0_1 == pub_r001260_0_2);
  __CPROVER_assume(sec_r001260_10_1 != sec_r001260_10_2);
  __CPROVER_assume(sec_r001260_5_1 != sec_r001260_5_2);
  __CPROVER_assume(pub_r001260_18_1 == pub_r001260_18_2);
  __CPROVER_assume(pub_r001260_16_1 == pub_r001260_16_2);
  __CPROVER_assume(pub_r001260_7_1 == pub_r001260_7_2);
  __CPROVER_assume(pub_r001260_15_1 == pub_r001260_15_2);
  __CPROVER_assume(pub_r001260_20_1 == pub_r001260_20_2);
  __CPROVER_assume(pub_r001260_17_1 == pub_r001260_17_2);
  __CPROVER_assume(sec_r001260_14_1 != sec_r001260_14_2);
  __CPROVER_assume(sec_r001260_17_1 != sec_r001260_17_2);
  __CPROVER_assume(pub_r001260_10_1 == pub_r001260_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.channels == st_var_2_2.channels);
  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
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
}


