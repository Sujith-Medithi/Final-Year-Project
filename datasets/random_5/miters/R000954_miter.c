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
struct Transaction_R000954_5413_0
{
  unsigned char rate;
  unsigned char status;
  short balance;
  unsigned char fee;
  int buffer[3];
};
struct AudioFrame_R000954_5413_1
{
  int sample_rate;
  int rms;
  unsigned char envelope;
  int buffer[3];
};
union ColorPixel_R000954_5413_0
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
void fn_R000954_5413_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int parity_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_94_1)
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

  switch (parity_94_2)
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

  int tracker_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_58_1 > 33)
  {
    acc_1 = ((acc_1 + (tracker_58_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_58_2 > 33)
  {
    acc_2 = ((acc_2 + (tracker_58_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_58_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_94_1 == parity_94_2);
  assert(tracker_58_1 == tracker_58_2);
}

int fn_R000954_5413_0(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int parity_94 = (aux + st.buffer[1]) & 3;
  switch (parity_94)
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

  int tracker_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_58 > 33)
  {
    acc = ((acc + (tracker_58 * 2)) + 5) & 127;
    aux ^= tracker_58 & 15;
  }
  else
  {
    acc = ((acc - tracker_58) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000954_5413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st_1 = {0};
  struct Transaction_R000954_5413_0 st_2 = {0};
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
  int segment_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_15_1) & 63;
  aux_2 = (aux_2 + segment_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_27_1)
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

  switch (tracker_27_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_15_1 == segment_15_2);
  assert(tracker_27_1 == tracker_27_2);
}

int fn_R000954_5413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_15) & 63;
  acc ^= aux;
  int tracker_27 = (aux + st.buffer[1]) & 3;
  switch (tracker_27)
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

void fn_R000954_5413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int threshold_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_41_1) & 63;
  aux_2 = (aux_2 + threshold_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_34_1 > 47)
  {
    acc_1 = ((acc_1 + (mask_34_1 * 2)) + 5) & 127;
    aux_1 ^= mask_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_34_2 > 47)
  {
    acc_2 = ((acc_2 + (mask_34_2 * 2)) + 5) & 127;
    aux_2 ^= mask_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_41_1 == threshold_41_2);
  assert(mask_34_1 == mask_34_2);
}

int fn_R000954_5413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int threshold_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_41) & 63;
  acc ^= aux;
  int mask_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_34 > 47)
  {
    acc = ((acc + (mask_34 * 2)) + 5) & 127;
    aux ^= mask_34 & 15;
  }
  else
  {
    acc = ((acc - mask_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000954_5413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_64_1 = local_arr_1[aux_1 % 3];
  int metric_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_64_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_64_1 == metric_64_2);
}

int fn_R000954_5413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int metric_64 = local_arr[aux % 3];
  acc = (acc + (metric_64 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000954_5413_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st_1 = {0};
  struct Transaction_R000954_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int vector_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_48_1) & 63;
  aux_2 = (aux_2 + vector_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_26_1 > 40)
  {
    acc_1 = ((acc_1 + (vector_26_1 * 2)) + 5) & 127;
    aux_1 ^= vector_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_26_2 > 40)
  {
    acc_2 = ((acc_2 + (vector_26_2 * 2)) + 5) & 127;
    aux_2 ^= vector_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_70_1)
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

  switch (quantum_70_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_48_1 == vector_48_2);
  assert(vector_26_1 == vector_26_2);
  assert(quantum_70_1 == quantum_70_2);
}

int fn_R000954_5413_4(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int vector_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_48) & 63;
  acc ^= aux;
  int vector_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_26 > 40)
  {
    acc = ((acc + (vector_26 * 2)) + 5) & 127;
    aux ^= vector_26 & 15;
  }
  else
  {
    acc = ((acc - vector_26) + 11) & 127;
    aux += 3;
  }
  int quantum_70 = (aux + st.buffer[1]) & 3;
  switch (quantum_70)
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

void fn_R000954_5413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_65_1)
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

  switch (damping_65_2)
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

  int cursor_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_74_1 > 17)
  {
    acc_1 = ((acc_1 + (cursor_74_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_74_2 > 17)
  {
    acc_2 = ((acc_2 + (cursor_74_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_65_1 == damping_65_2);
  assert(cursor_74_1 == cursor_74_2);
}

int fn_R000954_5413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_65 = (aux + st.buffer[1]) & 3;
  switch (damping_65)
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

  int cursor_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_74 > 17)
  {
    acc = ((acc + (cursor_74 * 2)) + 5) & 127;
    aux ^= cursor_74 & 15;
  }
  else
  {
    acc = ((acc - cursor_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000954_5413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tally_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_69_1 > 23)
  {
    acc_1 = ((acc_1 + (tally_69_1 * 2)) + 5) & 127;
    aux_1 ^= tally_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_69_2 > 23)
  {
    acc_2 = ((acc_2 + (tally_69_2 * 2)) + 5) & 127;
    aux_2 ^= tally_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_97_1)
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

  switch (index_reg_97_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_69_1 == tally_69_2);
  assert(index_reg_97_1 == index_reg_97_2);
}

int fn_R000954_5413_6(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tally_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_69 > 23)
  {
    acc = ((acc + (tally_69 * 2)) + 5) & 127;
    aux ^= tally_69 & 15;
  }
  else
  {
    acc = ((acc - tally_69) + 11) & 127;
    aux += 3;
  }
  int index_reg_97 = (aux + st.buffer[1]) & 3;
  switch (index_reg_97)
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

void fn_R000954_5413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st_1 = {0};
  struct Transaction_R000954_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_31_1)
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

  switch (quantum_31_2)
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

  int checksum_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_15_1) & 63;
  aux_2 = (aux_2 + checksum_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_31_1 == quantum_31_2);
  assert(checksum_15_1 == checksum_15_2);
}

int fn_R000954_5413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_31 = (aux + st.buffer[1]) & 3;
  switch (quantum_31)
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

  int checksum_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_15) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000954_5413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_84_1 = local_arr_1[aux_1 % 3];
  int weight_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_84_2 * 2)) & 127;
  int index_reg_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_62_1 > 42)
  {
    acc_1 = ((acc_1 + (index_reg_62_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_62_2 > 42)
  {
    acc_2 = ((acc_2 + (index_reg_62_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_84_1 == weight_84_2);
  assert(index_reg_62_1 == index_reg_62_2);
}

int fn_R000954_5413_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int weight_84 = local_arr[aux % 3];
  acc = (acc + (weight_84 * 2)) & 127;
  int index_reg_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_62 > 42)
  {
    acc = ((acc + (index_reg_62 * 2)) + 5) & 127;
    aux ^= index_reg_62 & 15;
  }
  else
  {
    acc = ((acc - index_reg_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000954_5413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st_1 = {0};
  struct Transaction_R000954_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_97_1 = local_arr_1[aux_1 % 3];
  int quantum_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_97_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_73_1)
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

  switch (sample_73_2)
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

  int quotient_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_64_1) & 63;
  aux_2 = (aux_2 + quotient_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_97_1 == quantum_97_2);
  assert(sample_73_1 == sample_73_2);
  assert(quotient_64_1 == quotient_64_2);
}

int fn_R000954_5413_9(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int quantum_97 = local_arr[aux % 3];
  acc = (acc + (quantum_97 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_73 = (aux + st.buffer[1]) & 3;
  switch (sample_73)
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

  int quotient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000954_5413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int index_reg_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_92_1 > 35)
  {
    acc_1 = ((acc_1 + (index_reg_92_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_92_2 > 35)
  {
    acc_2 = ((acc_2 + (index_reg_92_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_92_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_92_1 == index_reg_92_2);
}

int fn_R000954_5413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int index_reg_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_92 > 35)
  {
    acc = ((acc + (index_reg_92 * 2)) + 5) & 127;
    aux ^= index_reg_92 & 15;
  }
  else
  {
    acc = ((acc - index_reg_92) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000954_5413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st_1 = {0};
  struct Transaction_R000954_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int offset_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_73_1 > 38)
  {
    acc_1 = ((acc_1 + (offset_73_1 * 2)) + 5) & 127;
    aux_1 ^= offset_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_73_2 > 38)
  {
    acc_2 = ((acc_2 + (offset_73_2 * 2)) + 5) & 127;
    aux_2 ^= offset_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_90_1)
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

  switch (window_90_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_73_1 == offset_73_2);
  assert(window_90_1 == window_90_2);
}

int fn_R000954_5413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int offset_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_73 > 38)
  {
    acc = ((acc + (offset_73 * 2)) + 5) & 127;
    aux ^= offset_73 & 15;
  }
  else
  {
    acc = ((acc - offset_73) + 11) & 127;
    aux += 3;
  }
  int window_90 = (aux + st.buffer[1]) & 3;
  switch (window_90)
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

void fn_R000954_5413_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_90_1 = local_arr_1[aux_1 % 3];
  int bound_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_90_2 * 2)) & 127;
  int residue_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_12_1) & 63;
  aux_2 = (aux_2 + residue_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_83_1 > 24)
  {
    acc_1 = ((acc_1 + (delta_83_1 * 2)) + 5) & 127;
    aux_1 ^= delta_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_83_2 > 24)
  {
    acc_2 = ((acc_2 + (delta_83_2 * 2)) + 5) & 127;
    aux_2 ^= delta_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_90_1)
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

  switch (checksum_90_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_90_1 == bound_90_2);
  assert(residue_12_1 == residue_12_2);
  assert(delta_83_1 == delta_83_2);
  assert(checksum_90_1 == checksum_90_2);
}

int fn_R000954_5413_12(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int bound_90 = local_arr[aux % 3];
  acc = (acc + (bound_90 * 2)) & 127;
  int residue_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_12) & 63;
  acc ^= aux;
  int delta_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_83 > 24)
  {
    acc = ((acc + (delta_83 * 2)) + 5) & 127;
    aux ^= delta_83 & 15;
  }
  else
  {
    acc = ((acc - delta_83) + 11) & 127;
    aux += 3;
  }
  int checksum_90 = (aux + st.buffer[1]) & 3;
  switch (checksum_90)
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

void fn_R000954_5413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st_1 = {0};
  struct Transaction_R000954_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int pivot_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_46_1)
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

  switch (pivot_46_2)
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

  int index_reg_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_95_1 > 34)
  {
    acc_1 = ((acc_1 + (index_reg_95_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_95_2 > 34)
  {
    acc_2 = ((acc_2 + (index_reg_95_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_95_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_46_1 == pivot_46_2);
  assert(index_reg_95_1 == index_reg_95_2);
}

int fn_R000954_5413_13(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int pivot_46 = (aux + st.buffer[1]) & 3;
  switch (pivot_46)
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

  int index_reg_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_95 > 34)
  {
    acc = ((acc + (index_reg_95 * 2)) + 5) & 127;
    aux ^= index_reg_95 & 15;
  }
  else
  {
    acc = ((acc - index_reg_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000954_5413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quantum_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_41_1 > 32)
  {
    acc_1 = ((acc_1 + (quantum_41_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_41_2 > 32)
  {
    acc_2 = ((acc_2 + (quantum_41_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_45_1)
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

  switch (factor_45_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_41_1 == quantum_41_2);
  assert(factor_45_1 == factor_45_2);
}

int fn_R000954_5413_14(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quantum_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_41 > 32)
  {
    acc = ((acc + (quantum_41 * 2)) + 5) & 127;
    aux ^= quantum_41 & 15;
  }
  else
  {
    acc = ((acc - quantum_41) + 11) & 127;
    aux += 3;
  }
  int factor_45 = (aux + st.buffer[1]) & 3;
  switch (factor_45)
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

void fn_R000954_5413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st_1 = {0};
  struct Transaction_R000954_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_22_1 = local_arr_1[aux_1 % 3];
  int quantum_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_22_2 * 2)) & 127;
  int sample_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_77_1) & 63;
  aux_2 = (aux_2 + sample_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_22_1 == quantum_22_2);
  assert(sample_77_1 == sample_77_2);
}

int fn_R000954_5413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int quantum_22 = local_arr[aux % 3];
  acc = (acc + (quantum_22 * 2)) & 127;
  int sample_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_77) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000954_5413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st_1 = {0};
  struct Transaction_R000954_5413_0 st_2 = {0};
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
  int quotient_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_18_1) & 63;
  aux_2 = (aux_2 + quotient_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_40_1)
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

  switch (offset_40_2)
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

  int accumulator_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_78_1 > 36)
  {
    acc_1 = ((acc_1 + (accumulator_78_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_78_2 > 36)
  {
    acc_2 = ((acc_2 + (accumulator_78_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_18_1 == quotient_18_2);
  assert(offset_40_1 == offset_40_2);
  assert(accumulator_78_1 == accumulator_78_2);
}

int fn_R000954_5413_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000954_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_18) & 63;
  acc ^= aux;
  int offset_40 = (aux + st.buffer[1]) & 3;
  switch (offset_40)
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

  int accumulator_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_78 > 36)
  {
    acc = ((acc + (accumulator_78 * 2)) + 5) & 127;
    aux ^= accumulator_78 & 15;
  }
  else
  {
    acc = ((acc - accumulator_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000954_5413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st_1 = {0};
  struct AudioFrame_R000954_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int segment_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_44_1)
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

  switch (segment_44_2)
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

  int coefficient_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_40_1 > 39)
  {
    acc_1 = ((acc_1 + (coefficient_40_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_40_2 > 39)
  {
    acc_2 = ((acc_2 + (coefficient_40_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_44_1 == segment_44_2);
  assert(coefficient_40_1 == coefficient_40_2);
}

int fn_R000954_5413_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000954_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int segment_44 = (aux + st.buffer[1]) & 3;
  switch (segment_44)
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

  int coefficient_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_40 > 39)
  {
    acc = ((acc + (coefficient_40 * 2)) + 5) & 127;
    aux ^= coefficient_40 & 15;
  }
  else
  {
    acc = ((acc - coefficient_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000954_0_1;
  int sec_r000954_0_2;
  int sec_r000954_1_1;
  int sec_r000954_1_2;
  int sec_r000954_2_1;
  int sec_r000954_2_2;
  int sec_r000954_3_1;
  int sec_r000954_3_2;
  int sec_r000954_4_1;
  int sec_r000954_4_2;
  int sec_r000954_5_1;
  int sec_r000954_5_2;
  int sec_r000954_6_1;
  int sec_r000954_6_2;
  int sec_r000954_7_1;
  int sec_r000954_7_2;
  int sec_r000954_8_1;
  int sec_r000954_8_2;
  int sec_r000954_9_1;
  int sec_r000954_9_2;
  int sec_r000954_10_1;
  int sec_r000954_10_2;
  int sec_r000954_11_1;
  int sec_r000954_11_2;
  int sec_r000954_12_1;
  int sec_r000954_12_2;
  int sec_r000954_13_1;
  int sec_r000954_13_2;
  int sec_r000954_14_1;
  int sec_r000954_14_2;
  int sec_r000954_15_1;
  int sec_r000954_15_2;
  int sec_r000954_16_1;
  int sec_r000954_16_2;
  int sec_r000954_17_1;
  int sec_r000954_17_2;
  int sec_r000954_18_1;
  int sec_r000954_18_2;
  int sec_r000954_19_1;
  int sec_r000954_19_2;
  int sec_r000954_20_1;
  int sec_r000954_20_2;
  int sec_r000954_21_1;
  int sec_r000954_21_2;
  int sec_r000954_22_1;
  int sec_r000954_22_2;
  int sec_r000954_23_1;
  int sec_r000954_23_2;
  int pub_r000954_0_1;
  int pub_r000954_0_2;
  int pub_r000954_1_1;
  int pub_r000954_1_2;
  int pub_r000954_2_1;
  int pub_r000954_2_2;
  int pub_r000954_3_1;
  int pub_r000954_3_2;
  int pub_r000954_4_1;
  int pub_r000954_4_2;
  int pub_r000954_5_1;
  int pub_r000954_5_2;
  int pub_r000954_6_1;
  int pub_r000954_6_2;
  int pub_r000954_7_1;
  int pub_r000954_7_2;
  int pub_r000954_8_1;
  int pub_r000954_8_2;
  int pub_r000954_9_1;
  int pub_r000954_9_2;
  int pub_r000954_10_1;
  int pub_r000954_10_2;
  int pub_r000954_11_1;
  int pub_r000954_11_2;
  int pub_r000954_12_1;
  int pub_r000954_12_2;
  int pub_r000954_13_1;
  int pub_r000954_13_2;
  int pub_r000954_14_1;
  int pub_r000954_14_2;
  int pub_r000954_15_1;
  int pub_r000954_15_2;
  int pub_r000954_16_1;
  int pub_r000954_16_2;
  int pub_r000954_17_1;
  int pub_r000954_17_2;
  int pub_r000954_18_1;
  int pub_r000954_18_2;
  int pub_r000954_19_1;
  int pub_r000954_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000954_0_1 >= (-100)) && (pub_r000954_0_1 <= 100));
  __CPROVER_assume((pub_r000954_0_2 >= (-100)) && (pub_r000954_0_2 <= 100));
  __CPROVER_assume((pub_r000954_1_1 >= (-100)) && (pub_r000954_1_1 <= 100));
  __CPROVER_assume((pub_r000954_1_2 >= (-100)) && (pub_r000954_1_2 <= 100));
  __CPROVER_assume((pub_r000954_2_1 >= (-100)) && (pub_r000954_2_1 <= 100));
  __CPROVER_assume((pub_r000954_2_2 >= (-100)) && (pub_r000954_2_2 <= 100));
  __CPROVER_assume((pub_r000954_3_1 >= (-100)) && (pub_r000954_3_1 <= 100));
  __CPROVER_assume((pub_r000954_3_2 >= (-100)) && (pub_r000954_3_2 <= 100));
  __CPROVER_assume((pub_r000954_4_1 >= (-100)) && (pub_r000954_4_1 <= 100));
  __CPROVER_assume((pub_r000954_4_2 >= (-100)) && (pub_r000954_4_2 <= 100));
  __CPROVER_assume((pub_r000954_5_1 >= (-100)) && (pub_r000954_5_1 <= 100));
  __CPROVER_assume((pub_r000954_5_2 >= (-100)) && (pub_r000954_5_2 <= 100));
  __CPROVER_assume((pub_r000954_6_1 >= (-100)) && (pub_r000954_6_1 <= 100));
  __CPROVER_assume((pub_r000954_6_2 >= (-100)) && (pub_r000954_6_2 <= 100));
  __CPROVER_assume((pub_r000954_7_1 >= (-100)) && (pub_r000954_7_1 <= 100));
  __CPROVER_assume((pub_r000954_7_2 >= (-100)) && (pub_r000954_7_2 <= 100));
  __CPROVER_assume((pub_r000954_8_1 >= (-100)) && (pub_r000954_8_1 <= 100));
  __CPROVER_assume((pub_r000954_8_2 >= (-100)) && (pub_r000954_8_2 <= 100));
  __CPROVER_assume((pub_r000954_9_1 >= (-100)) && (pub_r000954_9_1 <= 100));
  __CPROVER_assume((pub_r000954_9_2 >= (-100)) && (pub_r000954_9_2 <= 100));
  __CPROVER_assume((pub_r000954_10_1 >= (-100)) && (pub_r000954_10_1 <= 100));
  __CPROVER_assume((pub_r000954_10_2 >= (-100)) && (pub_r000954_10_2 <= 100));
  __CPROVER_assume((pub_r000954_11_1 >= (-100)) && (pub_r000954_11_1 <= 100));
  __CPROVER_assume((pub_r000954_11_2 >= (-100)) && (pub_r000954_11_2 <= 100));
  __CPROVER_assume((pub_r000954_12_1 >= (-100)) && (pub_r000954_12_1 <= 100));
  __CPROVER_assume((pub_r000954_12_2 >= (-100)) && (pub_r000954_12_2 <= 100));
  __CPROVER_assume((pub_r000954_13_1 >= (-100)) && (pub_r000954_13_1 <= 100));
  __CPROVER_assume((pub_r000954_13_2 >= (-100)) && (pub_r000954_13_2 <= 100));
  __CPROVER_assume((pub_r000954_14_1 >= (-100)) && (pub_r000954_14_1 <= 100));
  __CPROVER_assume((pub_r000954_14_2 >= (-100)) && (pub_r000954_14_2 <= 100));
  __CPROVER_assume((pub_r000954_15_1 >= (-100)) && (pub_r000954_15_1 <= 100));
  __CPROVER_assume((pub_r000954_15_2 >= (-100)) && (pub_r000954_15_2 <= 100));
  __CPROVER_assume((pub_r000954_16_1 >= (-100)) && (pub_r000954_16_1 <= 100));
  __CPROVER_assume((pub_r000954_16_2 >= (-100)) && (pub_r000954_16_2 <= 100));
  __CPROVER_assume((pub_r000954_17_1 >= (-100)) && (pub_r000954_17_1 <= 100));
  __CPROVER_assume((pub_r000954_17_2 >= (-100)) && (pub_r000954_17_2 <= 100));
  __CPROVER_assume((pub_r000954_18_1 >= (-100)) && (pub_r000954_18_1 <= 100));
  __CPROVER_assume((pub_r000954_18_2 >= (-100)) && (pub_r000954_18_2 <= 100));
  __CPROVER_assume((pub_r000954_19_1 >= (-100)) && (pub_r000954_19_1 <= 100));
  __CPROVER_assume((pub_r000954_19_2 >= (-100)) && (pub_r000954_19_2 <= 100));
  __CPROVER_assume((sec_r000954_0_1 >= 0) && (sec_r000954_0_1 <= 255));
  __CPROVER_assume((sec_r000954_0_2 >= 0) && (sec_r000954_0_2 <= 255));
  __CPROVER_assume((sec_r000954_1_1 >= 0) && (sec_r000954_1_1 <= 255));
  __CPROVER_assume((sec_r000954_1_2 >= 0) && (sec_r000954_1_2 <= 255));
  __CPROVER_assume((sec_r000954_2_1 >= 0) && (sec_r000954_2_1 <= 255));
  __CPROVER_assume((sec_r000954_2_2 >= 0) && (sec_r000954_2_2 <= 255));
  __CPROVER_assume((sec_r000954_3_1 >= 0) && (sec_r000954_3_1 <= 255));
  __CPROVER_assume((sec_r000954_3_2 >= 0) && (sec_r000954_3_2 <= 255));
  __CPROVER_assume((sec_r000954_4_1 >= 0) && (sec_r000954_4_1 <= 255));
  __CPROVER_assume((sec_r000954_4_2 >= 0) && (sec_r000954_4_2 <= 255));
  __CPROVER_assume((sec_r000954_5_1 >= 0) && (sec_r000954_5_1 <= 255));
  __CPROVER_assume((sec_r000954_5_2 >= 0) && (sec_r000954_5_2 <= 255));
  __CPROVER_assume((sec_r000954_6_1 >= 0) && (sec_r000954_6_1 <= 255));
  __CPROVER_assume((sec_r000954_6_2 >= 0) && (sec_r000954_6_2 <= 255));
  __CPROVER_assume((sec_r000954_7_1 >= 0) && (sec_r000954_7_1 <= 255));
  __CPROVER_assume((sec_r000954_7_2 >= 0) && (sec_r000954_7_2 <= 255));
  __CPROVER_assume((sec_r000954_8_1 >= 0) && (sec_r000954_8_1 <= 255));
  __CPROVER_assume((sec_r000954_8_2 >= 0) && (sec_r000954_8_2 <= 255));
  __CPROVER_assume((sec_r000954_9_1 >= 0) && (sec_r000954_9_1 <= 255));
  __CPROVER_assume((sec_r000954_9_2 >= 0) && (sec_r000954_9_2 <= 255));
  __CPROVER_assume((sec_r000954_10_1 >= 0) && (sec_r000954_10_1 <= 255));
  __CPROVER_assume((sec_r000954_10_2 >= 0) && (sec_r000954_10_2 <= 255));
  __CPROVER_assume((sec_r000954_11_1 >= 0) && (sec_r000954_11_1 <= 255));
  __CPROVER_assume((sec_r000954_11_2 >= 0) && (sec_r000954_11_2 <= 255));
  __CPROVER_assume((sec_r000954_12_1 >= 0) && (sec_r000954_12_1 <= 255));
  __CPROVER_assume((sec_r000954_12_2 >= 0) && (sec_r000954_12_2 <= 255));
  __CPROVER_assume((sec_r000954_13_1 >= 0) && (sec_r000954_13_1 <= 255));
  __CPROVER_assume((sec_r000954_13_2 >= 0) && (sec_r000954_13_2 <= 255));
  __CPROVER_assume((sec_r000954_14_1 >= 0) && (sec_r000954_14_1 <= 255));
  __CPROVER_assume((sec_r000954_14_2 >= 0) && (sec_r000954_14_2 <= 255));
  __CPROVER_assume((sec_r000954_15_1 >= 0) && (sec_r000954_15_1 <= 255));
  __CPROVER_assume((sec_r000954_15_2 >= 0) && (sec_r000954_15_2 <= 255));
  __CPROVER_assume((sec_r000954_16_1 >= 0) && (sec_r000954_16_1 <= 255));
  __CPROVER_assume((sec_r000954_16_2 >= 0) && (sec_r000954_16_2 <= 255));
  __CPROVER_assume((sec_r000954_17_1 >= 0) && (sec_r000954_17_1 <= 255));
  __CPROVER_assume((sec_r000954_17_2 >= 0) && (sec_r000954_17_2 <= 255));
  __CPROVER_assume((sec_r000954_18_1 >= 0) && (sec_r000954_18_1 <= 255));
  __CPROVER_assume((sec_r000954_18_2 >= 0) && (sec_r000954_18_2 <= 255));
  __CPROVER_assume((sec_r000954_19_1 >= 0) && (sec_r000954_19_1 <= 255));
  __CPROVER_assume((sec_r000954_19_2 >= 0) && (sec_r000954_19_2 <= 255));
  __CPROVER_assume((sec_r000954_20_1 >= 0) && (sec_r000954_20_1 <= 255));
  __CPROVER_assume((sec_r000954_20_2 >= 0) && (sec_r000954_20_2 <= 255));
  __CPROVER_assume((sec_r000954_21_1 >= 0) && (sec_r000954_21_1 <= 255));
  __CPROVER_assume((sec_r000954_21_2 >= 0) && (sec_r000954_21_2 <= 255));
  __CPROVER_assume((sec_r000954_22_1 >= 0) && (sec_r000954_22_1 <= 255));
  __CPROVER_assume((sec_r000954_22_2 >= 0) && (sec_r000954_22_2 <= 255));
  __CPROVER_assume((sec_r000954_23_1 >= 0) && (sec_r000954_23_1 <= 255));
  __CPROVER_assume((sec_r000954_23_2 >= 0) && (sec_r000954_23_2 <= 255));
  struct Transaction_R000954_5413_0 st_var_0_1 = {0};
  struct Transaction_R000954_5413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000954_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000954_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000954_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000954_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000954_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000954_0_2 + 7) & 15;
  struct AudioFrame_R000954_5413_1 st_var_1_1 = {0};
  struct AudioFrame_R000954_5413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000954_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000954_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000954_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000954_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000954_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000954_0_2 + 9) & 15;
  union ColorPixel_R000954_5413_0 u_var_1;
  union ColorPixel_R000954_5413_0 u_var_2;
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
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (st_var_0_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_0_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = ((st_var_1_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_1_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 55)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 55)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 45)
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
  if (stage_v_7_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 45)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((st_var_0_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_0_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 37)
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
  if (stage_v_10_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 37)
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
  int stage_v_11_1 = ((st_var_1_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_1_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 45)
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
  if (stage_v_11_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 45)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (st_var_0_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_0_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = ((st_var_0_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_0_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 42)
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
  if (stage_v_16_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 42)
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
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (st_var_0_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_0_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((st_var_0_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_0_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 30)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 30)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = (st_var_1_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_1_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 33)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 33)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_30_1 = ((st_var_0_1.buffer[0] * 2) + 97) & 63;
  int stage_v_30_2 = ((st_var_0_2.buffer[0] * 2) + 97) & 63;
  if (stage_v_30_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_30_1) - 5) & 255;
    if (stage_v_30_1 > 31)
    {
      chk_sum_1 ^= stage_v_30_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_30_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_30_2) - 5) & 255;
    if (stage_v_30_2 > 31)
    {
      chk_sum_2 ^= stage_v_30_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 35) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((st_var_1_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_1_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 31)
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
  if (stage_v_35_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 31)
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
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = (st_var_1_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_1_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 35)
    {
      chk_sum_1 ^= stage_v_40_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_40_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 35)
    {
      chk_sum_2 ^= stage_v_40_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 36)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 36)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 45) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = ((st_var_0_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_0_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 40)
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
  if (stage_v_46_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 40)
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
  int stage_v_47_1 = (st_var_1_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_1_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
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
  int stage_v_51_1 = (st_var_1_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_1_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = (st_var_0_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_0_2.buffer[0] ^ 55) & 3;
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

  int stage_v_53_1 = (st_var_1_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_1_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((st_var_1_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_1_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 42)
    {
      chk_sum_1 ^= stage_v_55_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_55_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 42)
    {
      chk_sum_2 ^= stage_v_55_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((st_var_0_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_0_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 37)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 37)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  int stage_v_63_1 = ((st_var_1_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_1_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 43)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 43)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 28)
    {
      chk_sum_1 ^= stage_v_64_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_64_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 28)
    {
      chk_sum_2 ^= stage_v_64_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 66) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
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
  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = (st_var_1_1.buffer[0] ^ 72) & 3;
  int stage_v_69_2 = (st_var_1_2.buffer[0] ^ 72) & 3;
  switch (stage_v_69_1)
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

  switch (stage_v_69_2)
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

  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = table_1[0];
  int stage_v_72_2 = table_2[0];
  table_1[0] = (table_1[1] + 145) & 63;
  table_2[0] = (table_2[1] + 145) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 77) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  int stage_v_77_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (82 & 31);
  int stage_v_77_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (82 & 31);
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= (stage_v_77_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_77_2 << 1) & 127;
  int stage_v_78_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_78_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_79_1 = (st_var_1_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_1_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
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

  switch (stage_v_79_2)
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

  int stage_v_80_1 = ((st_var_0_1.buffer[2] * 2) + 247) & 63;
  int stage_v_80_2 = ((st_var_0_2.buffer[2] * 2) + 247) & 63;
  if (stage_v_80_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_80_1) - 5) & 255;
    if (stage_v_80_1 > 36)
    {
      chk_sum_1 ^= stage_v_80_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_80_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_80_2) - 5) & 255;
    if (stage_v_80_2 > 36)
    {
      chk_sum_2 ^= stage_v_80_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_81_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (86 & 31);
  int stage_v_81_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (86 & 31);
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= (stage_v_81_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_81_2 << 1) & 127;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((sec_r000954_5_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_15_1) + 19) & 127;
  int stage_v_83_2 = ((((sec_r000954_5_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((sec_r000954_11_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_4_1) + 18) & 127;
  int stage_v_84_2 = ((((sec_r000954_11_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((stage_v_83_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_7_1) + 36) & 127;
  int stage_v_85_2 = ((((stage_v_83_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((stage_v_84_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_0_1) + 33) & 127;
  int stage_v_86_2 = ((((stage_v_84_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((sec_r000954_13_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_0_1) + 32) & 127;
  int stage_v_87_2 = ((((sec_r000954_13_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((stage_v_86_1 * 3) + (sec_r000954_10_1 * 2)) - pub_r000954_16_1) + 18) & 127;
  int stage_v_88_2 = ((((stage_v_86_2 * 3) + (sec_r000954_10_2 * 2)) - pub_r000954_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((sec_r000954_18_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_7_1) + 30) & 127;
  int stage_v_89_2 = ((((sec_r000954_18_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_85_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_5_1) + 4) & 127;
  int stage_v_90_2 = ((((stage_v_85_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((stage_v_85_1 * 3) + (sec_r000954_17_1 * 2)) - pub_r000954_10_1) + 25) & 127;
  int stage_v_91_2 = ((((stage_v_85_2 * 3) + (sec_r000954_17_2 * 2)) - pub_r000954_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((stage_v_84_1 * 3) + (sec_r000954_7_1 * 2)) - pub_r000954_16_1) + 4) & 127;
  int stage_v_92_2 = ((((stage_v_84_2 * 3) + (sec_r000954_7_2 * 2)) - pub_r000954_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((sec_r000954_11_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_5_1) + 4) & 127;
  int stage_v_93_2 = ((((sec_r000954_11_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((sec_r000954_17_1 * 3) + (sec_r000954_17_1 * 2)) - pub_r000954_4_1) + 12) & 127;
  int stage_v_94_2 = ((((sec_r000954_17_2 * 3) + (sec_r000954_17_2 * 2)) - pub_r000954_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((stage_v_84_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_14_1) + 12) & 127;
  int stage_v_95_2 = ((((stage_v_84_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((stage_v_83_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_10_1) + 27) & 127;
  int stage_v_96_2 = ((((stage_v_83_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((sec_r000954_17_1 * 3) + (sec_r000954_17_1 * 2)) - pub_r000954_13_1) + 36) & 127;
  int stage_v_97_2 = ((((sec_r000954_17_2 * 3) + (sec_r000954_17_2 * 2)) - pub_r000954_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((stage_v_89_1 * 3) + (sec_r000954_22_1 * 2)) - pub_r000954_11_1) + 21) & 127;
  int stage_v_98_2 = ((((stage_v_89_2 * 3) + (sec_r000954_22_2 * 2)) - pub_r000954_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((sec_r000954_12_1 * 3) + (sec_r000954_12_1 * 2)) - pub_r000954_13_1) + 23) & 127;
  int stage_v_99_2 = ((((sec_r000954_12_2 * 3) + (sec_r000954_12_2 * 2)) - pub_r000954_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((sec_r000954_2_1 * 3) + (sec_r000954_2_1 * 2)) - pub_r000954_15_1) + 3) & 127;
  int stage_v_100_2 = ((((sec_r000954_2_2 * 3) + (sec_r000954_2_2 * 2)) - pub_r000954_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((stage_v_92_1 * 3) + (sec_r000954_22_1 * 2)) - pub_r000954_12_1) + 30) & 127;
  int stage_v_101_2 = ((((stage_v_92_2 * 3) + (sec_r000954_22_2 * 2)) - pub_r000954_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((stage_v_94_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_6_1) + 15) & 127;
  int stage_v_102_2 = ((((stage_v_94_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((sec_r000954_16_1 * 3) + (sec_r000954_16_1 * 2)) - pub_r000954_11_1) + 11) & 127;
  int stage_v_103_2 = ((((sec_r000954_16_2 * 3) + (sec_r000954_16_2 * 2)) - pub_r000954_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((sec_r000954_15_1 * 3) + (sec_r000954_15_1 * 2)) - pub_r000954_15_1) + 26) & 127;
  int stage_v_104_2 = ((((sec_r000954_15_2 * 3) + (sec_r000954_15_2 * 2)) - pub_r000954_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((sec_r000954_4_1 * 3) + (sec_r000954_4_1 * 2)) - pub_r000954_19_1) + 34) & 127;
  int stage_v_105_2 = ((((sec_r000954_4_2 * 3) + (sec_r000954_4_2 * 2)) - pub_r000954_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((sec_r000954_10_1 * 3) + (sec_r000954_10_1 * 2)) - pub_r000954_14_1) + 20) & 127;
  int stage_v_106_2 = ((((sec_r000954_10_2 * 3) + (sec_r000954_10_2 * 2)) - pub_r000954_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((sec_r000954_2_1 * 3) + (sec_r000954_2_1 * 2)) - pub_r000954_8_1) + 18) & 127;
  int stage_v_107_2 = ((((sec_r000954_2_2 * 3) + (sec_r000954_2_2 * 2)) - pub_r000954_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((sec_r000954_16_1 * 3) + (sec_r000954_16_1 * 2)) - pub_r000954_7_1) + 17) & 127;
  int stage_v_108_2 = ((((sec_r000954_16_2 * 3) + (sec_r000954_16_2 * 2)) - pub_r000954_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((sec_r000954_7_1 * 3) + (sec_r000954_7_1 * 2)) - pub_r000954_19_1) + 24) & 127;
  int stage_v_109_2 = ((((sec_r000954_7_2 * 3) + (sec_r000954_7_2 * 2)) - pub_r000954_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((stage_v_109_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_11_1) + 8) & 127;
  int stage_v_110_2 = ((((stage_v_109_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((stage_v_99_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_14_1) + 33) & 127;
  int stage_v_111_2 = ((((stage_v_99_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((sec_r000954_8_1 * 3) + (sec_r000954_8_1 * 2)) - pub_r000954_0_1) + 15) & 127;
  int stage_v_112_2 = ((((sec_r000954_8_2 * 3) + (sec_r000954_8_2 * 2)) - pub_r000954_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((stage_v_91_1 * 3) + (sec_r000954_7_1 * 2)) - pub_r000954_16_1) + 9) & 127;
  int stage_v_113_2 = ((((stage_v_91_2 * 3) + (sec_r000954_7_2 * 2)) - pub_r000954_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((stage_v_87_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_6_1) + 13) & 127;
  int stage_v_114_2 = ((((stage_v_87_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_5_1) + 7) & 127;
  int stage_v_115_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_18_1) + 12) & 127;
  int stage_v_116_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_9_1) + 21) & 127;
  int stage_v_117_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((stage_v_106_1 * 3) + (sec_r000954_2_1 * 2)) - pub_r000954_13_1) + 6) & 127;
  int stage_v_118_2 = ((((stage_v_106_2 * 3) + (sec_r000954_2_2 * 2)) - pub_r000954_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((sec_r000954_5_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_11_1) + 25) & 127;
  int stage_v_119_2 = ((((sec_r000954_5_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((sec_r000954_9_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_7_1) + 8) & 127;
  int stage_v_120_2 = ((((sec_r000954_9_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((stage_v_108_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_19_1) + 23) & 127;
  int stage_v_121_2 = ((((stage_v_108_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_121_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_19_1) + 32) & 127;
  int stage_v_122_2 = ((((stage_v_121_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((stage_v_116_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_7_1) + 26) & 127;
  int stage_v_123_2 = ((((stage_v_116_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((stage_v_102_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_18_1) + 31) & 127;
  int stage_v_124_2 = ((((stage_v_102_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_15_1) + 37) & 127;
  int stage_v_125_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((stage_v_122_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_5_1) + 25) & 127;
  int stage_v_126_2 = ((((stage_v_122_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((sec_r000954_13_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_18_1) + 6) & 127;
  int stage_v_127_2 = ((((sec_r000954_13_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((stage_v_101_1 * 3) + (sec_r000954_7_1 * 2)) - pub_r000954_4_1) + 5) & 127;
  int stage_v_128_2 = ((((stage_v_101_2 * 3) + (sec_r000954_7_2 * 2)) - pub_r000954_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_106_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_18_1) + 17) & 127;
  int stage_v_129_2 = ((((stage_v_106_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((stage_v_114_1 * 3) + (sec_r000954_12_1 * 2)) - pub_r000954_6_1) + 4) & 127;
  int stage_v_130_2 = ((((stage_v_114_2 * 3) + (sec_r000954_12_2 * 2)) - pub_r000954_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((stage_v_121_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_16_1) + 30) & 127;
  int stage_v_131_2 = ((((stage_v_121_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((sec_r000954_13_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_7_1) + 22) & 127;
  int stage_v_132_2 = ((((sec_r000954_13_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((sec_r000954_12_1 * 3) + (sec_r000954_12_1 * 2)) - pub_r000954_4_1) + 6) & 127;
  int stage_v_133_2 = ((((sec_r000954_12_2 * 3) + (sec_r000954_12_2 * 2)) - pub_r000954_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((sec_r000954_5_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_7_1) + 37) & 127;
  int stage_v_134_2 = ((((sec_r000954_5_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((stage_v_119_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_1_1) + 17) & 127;
  int stage_v_135_2 = ((((stage_v_119_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((sec_r000954_6_1 * 3) + (sec_r000954_6_1 * 2)) - pub_r000954_9_1) + 6) & 127;
  int stage_v_136_2 = ((((sec_r000954_6_2 * 3) + (sec_r000954_6_2 * 2)) - pub_r000954_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((stage_v_87_1 * 3) + (sec_r000954_16_1 * 2)) - pub_r000954_18_1) + 9) & 127;
  int stage_v_137_2 = ((((stage_v_87_2 * 3) + (sec_r000954_16_2 * 2)) - pub_r000954_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((sec_r000954_5_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_11_1) + 22) & 127;
  int stage_v_138_2 = ((((sec_r000954_5_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((stage_v_138_1 * 3) + (sec_r000954_10_1 * 2)) - pub_r000954_14_1) + 15) & 127;
  int stage_v_139_2 = ((((stage_v_138_2 * 3) + (sec_r000954_10_2 * 2)) - pub_r000954_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_139_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_1_1) + 7) & 127;
  int stage_v_140_2 = ((((stage_v_139_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((stage_v_108_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_19_1) + 5) & 127;
  int stage_v_141_2 = ((((stage_v_108_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_19_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((stage_v_110_1 * 3) + (sec_r000954_15_1 * 2)) - pub_r000954_2_1) + 37) & 127;
  int stage_v_142_2 = ((((stage_v_110_2 * 3) + (sec_r000954_15_2 * 2)) - pub_r000954_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((stage_v_129_1 * 3) + (sec_r000954_10_1 * 2)) - pub_r000954_17_1) + 3) & 127;
  int stage_v_143_2 = ((((stage_v_129_2 * 3) + (sec_r000954_10_2 * 2)) - pub_r000954_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((stage_v_83_1 * 3) + (sec_r000954_1_1 * 2)) - pub_r000954_19_1) + 3) & 127;
  int stage_v_144_2 = ((((stage_v_83_2 * 3) + (sec_r000954_1_2 * 2)) - pub_r000954_19_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((stage_v_130_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_17_1) + 35) & 127;
  int stage_v_145_2 = ((((stage_v_130_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_100_1 * 3) + (sec_r000954_6_1 * 2)) - pub_r000954_3_1) + 10) & 127;
  int stage_v_146_2 = ((((stage_v_100_2 * 3) + (sec_r000954_6_2 * 2)) - pub_r000954_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((sec_r000954_10_1 * 3) + (sec_r000954_10_1 * 2)) - pub_r000954_3_1) + 5) & 127;
  int stage_v_147_2 = ((((sec_r000954_10_2 * 3) + (sec_r000954_10_2 * 2)) - pub_r000954_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((stage_v_134_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_15_1) + 17) & 127;
  int stage_v_148_2 = ((((stage_v_134_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((sec_r000954_14_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_15_1) + 28) & 127;
  int stage_v_149_2 = ((((sec_r000954_14_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((sec_r000954_13_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_16_1) + 26) & 127;
  int stage_v_150_2 = ((((sec_r000954_13_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((stage_v_132_1 * 3) + (sec_r000954_1_1 * 2)) - pub_r000954_15_1) + 29) & 127;
  int stage_v_151_2 = ((((stage_v_132_2 * 3) + (sec_r000954_1_2 * 2)) - pub_r000954_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((stage_v_107_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_2_1) + 11) & 127;
  int stage_v_152_2 = ((((stage_v_107_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((sec_r000954_10_1 * 3) + (sec_r000954_10_1 * 2)) - pub_r000954_15_1) + 27) & 127;
  int stage_v_153_2 = ((((sec_r000954_10_2 * 3) + (sec_r000954_10_2 * 2)) - pub_r000954_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((stage_v_148_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_6_1) + 12) & 127;
  int stage_v_154_2 = ((((stage_v_148_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((stage_v_103_1 * 3) + (sec_r000954_19_1 * 2)) - pub_r000954_5_1) + 4) & 127;
  int stage_v_155_2 = ((((stage_v_103_2 * 3) + (sec_r000954_19_2 * 2)) - pub_r000954_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_101_1 * 3) + (sec_r000954_2_1 * 2)) - pub_r000954_18_1) + 26) & 127;
  int stage_v_156_2 = ((((stage_v_101_2 * 3) + (sec_r000954_2_2 * 2)) - pub_r000954_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((sec_r000954_3_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_16_1) + 16) & 127;
  int stage_v_157_2 = ((((sec_r000954_3_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((stage_v_140_1 * 3) + (sec_r000954_17_1 * 2)) - pub_r000954_13_1) + 31) & 127;
  int stage_v_158_2 = ((((stage_v_140_2 * 3) + (sec_r000954_17_2 * 2)) - pub_r000954_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((sec_r000954_2_1 * 3) + (sec_r000954_2_1 * 2)) - pub_r000954_19_1) + 30) & 127;
  int stage_v_159_2 = ((((sec_r000954_2_2 * 3) + (sec_r000954_2_2 * 2)) - pub_r000954_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((stage_v_123_1 * 3) + (sec_r000954_16_1 * 2)) - pub_r000954_15_1) + 7) & 127;
  int stage_v_160_2 = ((((stage_v_123_2 * 3) + (sec_r000954_16_2 * 2)) - pub_r000954_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((sec_r000954_21_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_3_1) + 37) & 127;
  int stage_v_161_2 = ((((sec_r000954_21_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((stage_v_140_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_0_1) + 35) & 127;
  int stage_v_162_2 = ((((stage_v_140_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((stage_v_130_1 * 3) + (sec_r000954_10_1 * 2)) - pub_r000954_15_1) + 35) & 127;
  int stage_v_163_2 = ((((stage_v_130_2 * 3) + (sec_r000954_10_2 * 2)) - pub_r000954_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((stage_v_134_1 * 3) + (sec_r000954_8_1 * 2)) - pub_r000954_14_1) + 28) & 127;
  int stage_v_164_2 = ((((stage_v_134_2 * 3) + (sec_r000954_8_2 * 2)) - pub_r000954_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((stage_v_131_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_3_1) + 19) & 127;
  int stage_v_165_2 = ((((stage_v_131_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((stage_v_145_1 * 3) + (sec_r000954_22_1 * 2)) - pub_r000954_11_1) + 28) & 127;
  int stage_v_166_2 = ((((stage_v_145_2 * 3) + (sec_r000954_22_2 * 2)) - pub_r000954_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_89_1 * 3) + (sec_r000954_8_1 * 2)) - pub_r000954_8_1) + 16) & 127;
  int stage_v_167_2 = ((((stage_v_89_2 * 3) + (sec_r000954_8_2 * 2)) - pub_r000954_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((stage_v_133_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_13_1) + 37) & 127;
  int stage_v_168_2 = ((((stage_v_133_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((stage_v_112_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_0_1) + 17) & 127;
  int stage_v_169_2 = ((((stage_v_112_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_4_1) + 15) & 127;
  int stage_v_170_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((stage_v_95_1 * 3) + (sec_r000954_2_1 * 2)) - pub_r000954_3_1) + 27) & 127;
  int stage_v_171_2 = ((((stage_v_95_2 * 3) + (sec_r000954_2_2 * 2)) - pub_r000954_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((sec_r000954_12_1 * 3) + (sec_r000954_12_1 * 2)) - pub_r000954_4_1) + 27) & 127;
  int stage_v_172_2 = ((((sec_r000954_12_2 * 3) + (sec_r000954_12_2 * 2)) - pub_r000954_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_168_1 * 3) + (sec_r000954_12_1 * 2)) - pub_r000954_5_1) + 18) & 127;
  int stage_v_173_2 = ((((stage_v_168_2 * 3) + (sec_r000954_12_2 * 2)) - pub_r000954_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_89_1 * 3) + (sec_r000954_12_1 * 2)) - pub_r000954_5_1) + 24) & 127;
  int stage_v_174_2 = ((((stage_v_89_2 * 3) + (sec_r000954_12_2 * 2)) - pub_r000954_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((stage_v_127_1 * 3) + (sec_r000954_1_1 * 2)) - pub_r000954_12_1) + 3) & 127;
  int stage_v_175_2 = ((((stage_v_127_2 * 3) + (sec_r000954_1_2 * 2)) - pub_r000954_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_143_1 * 3) + (sec_r000954_7_1 * 2)) - pub_r000954_3_1) + 17) & 127;
  int stage_v_176_2 = ((((stage_v_143_2 * 3) + (sec_r000954_7_2 * 2)) - pub_r000954_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((stage_v_144_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_14_1) + 21) & 127;
  int stage_v_177_2 = ((((stage_v_144_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((stage_v_90_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_19_1) + 20) & 127;
  int stage_v_178_2 = ((((stage_v_90_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((sec_r000954_0_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_14_1) + 15) & 127;
  int stage_v_179_2 = ((((sec_r000954_0_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((sec_r000954_16_1 * 3) + (sec_r000954_16_1 * 2)) - pub_r000954_9_1) + 3) & 127;
  int stage_v_180_2 = ((((sec_r000954_16_2 * 3) + (sec_r000954_16_2 * 2)) - pub_r000954_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_153_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_13_1) + 21) & 127;
  int stage_v_181_2 = ((((stage_v_153_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_10_1) + 14) & 127;
  int stage_v_182_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((sec_r000954_18_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_13_1) + 13) & 127;
  int stage_v_183_2 = ((((sec_r000954_18_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((stage_v_110_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_18_1) + 27) & 127;
  int stage_v_184_2 = ((((stage_v_110_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((sec_r000954_14_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_18_1) + 24) & 127;
  int stage_v_185_2 = ((((sec_r000954_14_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((sec_r000954_14_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_5_1) + 32) & 127;
  int stage_v_186_2 = ((((sec_r000954_14_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((stage_v_180_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_1_1) + 31) & 127;
  int stage_v_187_2 = ((((stage_v_180_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((stage_v_144_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_14_1) + 37) & 127;
  int stage_v_188_2 = ((((stage_v_144_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_132_1 * 3) + (sec_r000954_12_1 * 2)) - pub_r000954_5_1) + 6) & 127;
  int stage_v_189_2 = ((((stage_v_132_2 * 3) + (sec_r000954_12_2 * 2)) - pub_r000954_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((stage_v_119_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_4_1) + 21) & 127;
  int stage_v_190_2 = ((((stage_v_119_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((sec_r000954_18_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_7_1) + 13) & 127;
  int stage_v_191_2 = ((((sec_r000954_18_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_140_1 * 3) + (sec_r000954_8_1 * 2)) - pub_r000954_2_1) + 16) & 127;
  int stage_v_192_2 = ((((stage_v_140_2 * 3) + (sec_r000954_8_2 * 2)) - pub_r000954_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((stage_v_171_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_16_1) + 22) & 127;
  int stage_v_193_2 = ((((stage_v_171_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_130_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_1_1) + 35) & 127;
  int stage_v_194_2 = ((((stage_v_130_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((stage_v_85_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_11_1) + 30) & 127;
  int stage_v_195_2 = ((((stage_v_85_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((sec_r000954_11_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_13_1) + 10) & 127;
  int stage_v_196_2 = ((((sec_r000954_11_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((sec_r000954_15_1 * 3) + (sec_r000954_15_1 * 2)) - pub_r000954_8_1) + 26) & 127;
  int stage_v_197_2 = ((((sec_r000954_15_2 * 3) + (sec_r000954_15_2 * 2)) - pub_r000954_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((sec_r000954_22_1 * 3) + (sec_r000954_22_1 * 2)) - pub_r000954_9_1) + 25) & 127;
  int stage_v_198_2 = ((((sec_r000954_22_2 * 3) + (sec_r000954_22_2 * 2)) - pub_r000954_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((sec_r000954_14_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_16_1) + 5) & 127;
  int stage_v_199_2 = ((((sec_r000954_14_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((stage_v_137_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_1_1) + 23) & 127;
  int stage_v_200_2 = ((((stage_v_137_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((sec_r000954_4_1 * 3) + (sec_r000954_4_1 * 2)) - pub_r000954_4_1) + 32) & 127;
  int stage_v_201_2 = ((((sec_r000954_4_2 * 3) + (sec_r000954_4_2 * 2)) - pub_r000954_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((sec_r000954_3_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_17_1) + 32) & 127;
  int stage_v_202_2 = ((((sec_r000954_3_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((sec_r000954_3_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_2_1) + 27) & 127;
  int stage_v_203_2 = ((((sec_r000954_3_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_109_1 * 3) + (sec_r000954_17_1 * 2)) - pub_r000954_19_1) + 35) & 127;
  int stage_v_204_2 = ((((stage_v_109_2 * 3) + (sec_r000954_17_2 * 2)) - pub_r000954_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_148_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_18_1) + 7) & 127;
  int stage_v_205_2 = ((((stage_v_148_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_18_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((sec_r000954_21_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_12_1) + 3) & 127;
  int stage_v_206_2 = ((((sec_r000954_21_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((sec_r000954_18_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_7_1) + 32) & 127;
  int stage_v_207_2 = ((((sec_r000954_18_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((stage_v_99_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_14_1) + 29) & 127;
  int stage_v_208_2 = ((((stage_v_99_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((sec_r000954_3_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_8_1) + 37) & 127;
  int stage_v_209_2 = ((((sec_r000954_3_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((stage_v_130_1 * 3) + (sec_r000954_15_1 * 2)) - pub_r000954_16_1) + 18) & 127;
  int stage_v_210_2 = ((((stage_v_130_2 * 3) + (sec_r000954_15_2 * 2)) - pub_r000954_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((sec_r000954_18_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_9_1) + 15) & 127;
  int stage_v_211_2 = ((((sec_r000954_18_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((sec_r000954_2_1 * 3) + (sec_r000954_2_1 * 2)) - pub_r000954_15_1) + 28) & 127;
  int stage_v_212_2 = ((((sec_r000954_2_2 * 3) + (sec_r000954_2_2 * 2)) - pub_r000954_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((stage_v_112_1 * 3) + (sec_r000954_1_1 * 2)) - pub_r000954_2_1) + 21) & 127;
  int stage_v_213_2 = ((((stage_v_112_2 * 3) + (sec_r000954_1_2 * 2)) - pub_r000954_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((stage_v_108_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_9_1) + 11) & 127;
  int stage_v_214_2 = ((((stage_v_108_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((sec_r000954_9_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_14_1) + 31) & 127;
  int stage_v_215_2 = ((((sec_r000954_9_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_202_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_13_1) + 14) & 127;
  int stage_v_216_2 = ((((stage_v_202_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((sec_r000954_9_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_2_1) + 5) & 127;
  int stage_v_217_2 = ((((sec_r000954_9_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((stage_v_92_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_5_1) + 8) & 127;
  int stage_v_218_2 = ((((stage_v_92_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_130_1 * 3) + (sec_r000954_19_1 * 2)) - pub_r000954_13_1) + 21) & 127;
  int stage_v_219_2 = ((((stage_v_130_2 * 3) + (sec_r000954_19_2 * 2)) - pub_r000954_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((stage_v_125_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_19_1) + 30) & 127;
  int stage_v_220_2 = ((((stage_v_125_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_184_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_16_1) + 31) & 127;
  int stage_v_221_2 = ((((stage_v_184_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((sec_r000954_7_1 * 3) + (sec_r000954_7_1 * 2)) - pub_r000954_4_1) + 30) & 127;
  int stage_v_222_2 = ((((sec_r000954_7_2 * 3) + (sec_r000954_7_2 * 2)) - pub_r000954_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((stage_v_215_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_11_1) + 12) & 127;
  int stage_v_223_2 = ((((stage_v_215_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_15_1) + 28) & 127;
  int stage_v_224_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((stage_v_224_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_18_1) + 30) & 127;
  int stage_v_225_2 = ((((stage_v_224_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((stage_v_134_1 * 3) + (sec_r000954_12_1 * 2)) - pub_r000954_8_1) + 5) & 127;
  int stage_v_226_2 = ((((stage_v_134_2 * 3) + (sec_r000954_12_2 * 2)) - pub_r000954_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((stage_v_109_1 * 3) + (sec_r000954_6_1 * 2)) - pub_r000954_0_1) + 36) & 127;
  int stage_v_227_2 = ((((stage_v_109_2 * 3) + (sec_r000954_6_2 * 2)) - pub_r000954_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((stage_v_89_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_19_1) + 32) & 127;
  int stage_v_228_2 = ((((stage_v_89_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((sec_r000954_3_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_4_1) + 20) & 127;
  int stage_v_229_2 = ((((sec_r000954_3_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((stage_v_147_1 * 3) + (sec_r000954_19_1 * 2)) - pub_r000954_0_1) + 11) & 127;
  int stage_v_230_2 = ((((stage_v_147_2 * 3) + (sec_r000954_19_2 * 2)) - pub_r000954_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((sec_r000954_4_1 * 3) + (sec_r000954_4_1 * 2)) - pub_r000954_18_1) + 14) & 127;
  int stage_v_231_2 = ((((sec_r000954_4_2 * 3) + (sec_r000954_4_2 * 2)) - pub_r000954_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((stage_v_98_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_13_1) + 26) & 127;
  int stage_v_232_2 = ((((stage_v_98_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((stage_v_180_1 * 3) + (sec_r000954_15_1 * 2)) - pub_r000954_7_1) + 37) & 127;
  int stage_v_233_2 = ((((stage_v_180_2 * 3) + (sec_r000954_15_2 * 2)) - pub_r000954_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((stage_v_171_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_0_1) + 37) & 127;
  int stage_v_234_2 = ((((stage_v_171_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((stage_v_223_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_17_1) + 12) & 127;
  int stage_v_235_2 = ((((stage_v_223_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_5_1) + 23) & 127;
  int stage_v_236_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_203_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_18_1) + 6) & 127;
  int stage_v_237_2 = ((((stage_v_203_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((stage_v_202_1 * 3) + (sec_r000954_17_1 * 2)) - pub_r000954_7_1) + 22) & 127;
  int stage_v_238_2 = ((((stage_v_202_2 * 3) + (sec_r000954_17_2 * 2)) - pub_r000954_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((sec_r000954_10_1 * 3) + (sec_r000954_10_1 * 2)) - pub_r000954_8_1) + 10) & 127;
  int stage_v_239_2 = ((((sec_r000954_10_2 * 3) + (sec_r000954_10_2 * 2)) - pub_r000954_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((sec_r000954_2_1 * 3) + (sec_r000954_2_1 * 2)) - pub_r000954_7_1) + 18) & 127;
  int stage_v_240_2 = ((((sec_r000954_2_2 * 3) + (sec_r000954_2_2 * 2)) - pub_r000954_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((sec_r000954_13_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_9_1) + 19) & 127;
  int stage_v_241_2 = ((((sec_r000954_13_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((stage_v_200_1 * 3) + (sec_r000954_7_1 * 2)) - pub_r000954_15_1) + 35) & 127;
  int stage_v_242_2 = ((((stage_v_200_2 * 3) + (sec_r000954_7_2 * 2)) - pub_r000954_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_177_1 * 3) + (sec_r000954_7_1 * 2)) - pub_r000954_16_1) + 22) & 127;
  int stage_v_243_2 = ((((stage_v_177_2 * 3) + (sec_r000954_7_2 * 2)) - pub_r000954_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_128_1 * 3) + (sec_r000954_22_1 * 2)) - pub_r000954_2_1) + 23) & 127;
  int stage_v_244_2 = ((((stage_v_128_2 * 3) + (sec_r000954_22_2 * 2)) - pub_r000954_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_91_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_4_1) + 34) & 127;
  int stage_v_245_2 = ((((stage_v_91_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_228_1 * 3) + (sec_r000954_15_1 * 2)) - pub_r000954_4_1) + 31) & 127;
  int stage_v_246_2 = ((((stage_v_228_2 * 3) + (sec_r000954_15_2 * 2)) - pub_r000954_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_246_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_12_1) + 11) & 127;
  int stage_v_247_2 = ((((stage_v_246_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_107_1 * 3) + (sec_r000954_6_1 * 2)) - pub_r000954_4_1) + 33) & 127;
  int stage_v_248_2 = ((((stage_v_107_2 * 3) + (sec_r000954_6_2 * 2)) - pub_r000954_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_238_1 * 3) + (sec_r000954_6_1 * 2)) - pub_r000954_3_1) + 12) & 127;
  int stage_v_249_2 = ((((stage_v_238_2 * 3) + (sec_r000954_6_2 * 2)) - pub_r000954_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_241_1 * 3) + (sec_r000954_19_1 * 2)) - pub_r000954_16_1) + 21) & 127;
  int stage_v_250_2 = ((((stage_v_241_2 * 3) + (sec_r000954_19_2 * 2)) - pub_r000954_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((sec_r000954_6_1 * 3) + (sec_r000954_6_1 * 2)) - pub_r000954_4_1) + 20) & 127;
  int stage_v_251_2 = ((((sec_r000954_6_2 * 3) + (sec_r000954_6_2 * 2)) - pub_r000954_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((sec_r000954_5_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_6_1) + 10) & 127;
  int stage_v_252_2 = ((((sec_r000954_5_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((stage_v_175_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_0_1) + 31) & 127;
  int stage_v_253_2 = ((((stage_v_175_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((sec_r000954_21_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_12_1) + 33) & 127;
  int stage_v_254_2 = ((((sec_r000954_21_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((stage_v_189_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_0_1) + 30) & 127;
  int stage_v_255_2 = ((((stage_v_189_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((stage_v_84_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_8_1) + 11) & 127;
  int stage_v_256_2 = ((((stage_v_84_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((stage_v_213_1 * 3) + (sec_r000954_3_1 * 2)) - pub_r000954_8_1) + 14) & 127;
  int stage_v_257_2 = ((((stage_v_213_2 * 3) + (sec_r000954_3_2 * 2)) - pub_r000954_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((stage_v_162_1 * 3) + (sec_r000954_16_1 * 2)) - pub_r000954_4_1) + 22) & 127;
  int stage_v_258_2 = ((((stage_v_162_2 * 3) + (sec_r000954_16_2 * 2)) - pub_r000954_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((stage_v_234_1 * 3) + (sec_r000954_1_1 * 2)) - pub_r000954_0_1) + 10) & 127;
  int stage_v_259_2 = ((((stage_v_234_2 * 3) + (sec_r000954_1_2 * 2)) - pub_r000954_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((stage_v_165_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_18_1) + 12) & 127;
  int stage_v_260_2 = ((((stage_v_165_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((sec_r000954_15_1 * 3) + (sec_r000954_15_1 * 2)) - pub_r000954_18_1) + 14) & 127;
  int stage_v_261_2 = ((((sec_r000954_15_2 * 3) + (sec_r000954_15_2 * 2)) - pub_r000954_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((stage_v_246_1 * 3) + (sec_r000954_15_1 * 2)) - pub_r000954_6_1) + 27) & 127;
  int stage_v_262_2 = ((((stage_v_246_2 * 3) + (sec_r000954_15_2 * 2)) - pub_r000954_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((sec_r000954_9_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_9_1) + 16) & 127;
  int stage_v_263_2 = ((((sec_r000954_9_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((sec_r000954_5_1 * 3) + (sec_r000954_5_1 * 2)) - pub_r000954_3_1) + 24) & 127;
  int stage_v_264_2 = ((((sec_r000954_5_2 * 3) + (sec_r000954_5_2 * 2)) - pub_r000954_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((sec_r000954_22_1 * 3) + (sec_r000954_22_1 * 2)) - pub_r000954_3_1) + 30) & 127;
  int stage_v_265_2 = ((((sec_r000954_22_2 * 3) + (sec_r000954_22_2 * 2)) - pub_r000954_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((stage_v_199_1 * 3) + (sec_r000954_1_1 * 2)) - pub_r000954_18_1) + 23) & 127;
  int stage_v_266_2 = ((((stage_v_199_2 * 3) + (sec_r000954_1_2 * 2)) - pub_r000954_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((stage_v_178_1 * 3) + (sec_r000954_17_1 * 2)) - pub_r000954_1_1) + 35) & 127;
  int stage_v_267_2 = ((((stage_v_178_2 * 3) + (sec_r000954_17_2 * 2)) - pub_r000954_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_120_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_10_1) + 25) & 127;
  int stage_v_268_2 = ((((stage_v_120_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((stage_v_89_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_17_1) + 3) & 127;
  int stage_v_269_2 = ((((stage_v_89_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((stage_v_96_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_13_1) + 9) & 127;
  int stage_v_270_2 = ((((stage_v_96_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_5_1) + 22) & 127;
  int stage_v_271_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((sec_r000954_17_1 * 3) + (sec_r000954_17_1 * 2)) - pub_r000954_3_1) + 16) & 127;
  int stage_v_272_2 = ((((sec_r000954_17_2 * 3) + (sec_r000954_17_2 * 2)) - pub_r000954_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((sec_r000954_23_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_8_1) + 35) & 127;
  int stage_v_273_2 = ((((sec_r000954_23_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((stage_v_165_1 * 3) + (sec_r000954_16_1 * 2)) - pub_r000954_15_1) + 23) & 127;
  int stage_v_274_2 = ((((stage_v_165_2 * 3) + (sec_r000954_16_2 * 2)) - pub_r000954_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((stage_v_153_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_0_1) + 20) & 127;
  int stage_v_275_2 = ((((stage_v_153_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((stage_v_216_1 * 3) + (sec_r000954_13_1 * 2)) - pub_r000954_14_1) + 10) & 127;
  int stage_v_276_2 = ((((stage_v_216_2 * 3) + (sec_r000954_13_2 * 2)) - pub_r000954_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((stage_v_126_1 * 3) + (sec_r000954_17_1 * 2)) - pub_r000954_11_1) + 3) & 127;
  int stage_v_277_2 = ((((stage_v_126_2 * 3) + (sec_r000954_17_2 * 2)) - pub_r000954_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((stage_v_151_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_13_1) + 28) & 127;
  int stage_v_278_2 = ((((stage_v_151_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((stage_v_178_1 * 3) + (sec_r000954_0_1 * 2)) - pub_r000954_9_1) + 17) & 127;
  int stage_v_279_2 = ((((stage_v_178_2 * 3) + (sec_r000954_0_2 * 2)) - pub_r000954_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((sec_r000954_18_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_12_1) + 34) & 127;
  int stage_v_280_2 = ((((sec_r000954_18_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_154_1 * 3) + (sec_r000954_8_1 * 2)) - pub_r000954_1_1) + 3) & 127;
  int stage_v_281_2 = ((((stage_v_154_2 * 3) + (sec_r000954_8_2 * 2)) - pub_r000954_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((sec_r000954_10_1 * 3) + (sec_r000954_10_1 * 2)) - pub_r000954_17_1) + 29) & 127;
  int stage_v_282_2 = ((((sec_r000954_10_2 * 3) + (sec_r000954_10_2 * 2)) - pub_r000954_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((stage_v_250_1 * 3) + (sec_r000954_22_1 * 2)) - pub_r000954_9_1) + 21) & 127;
  int stage_v_283_2 = ((((stage_v_250_2 * 3) + (sec_r000954_22_2 * 2)) - pub_r000954_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((sec_r000954_20_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_2_1) + 34) & 127;
  int stage_v_284_2 = ((((sec_r000954_20_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((sec_r000954_11_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_5_1) + 7) & 127;
  int stage_v_285_2 = ((((sec_r000954_11_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((sec_r000954_11_1 * 3) + (sec_r000954_11_1 * 2)) - pub_r000954_2_1) + 10) & 127;
  int stage_v_286_2 = ((((sec_r000954_11_2 * 3) + (sec_r000954_11_2 * 2)) - pub_r000954_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((stage_v_207_1 * 3) + (sec_r000954_9_1 * 2)) - pub_r000954_15_1) + 26) & 127;
  int stage_v_287_2 = ((((stage_v_207_2 * 3) + (sec_r000954_9_2 * 2)) - pub_r000954_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((stage_v_113_1 * 3) + (sec_r000954_21_1 * 2)) - pub_r000954_3_1) + 31) & 127;
  int stage_v_288_2 = ((((stage_v_113_2 * 3) + (sec_r000954_21_2 * 2)) - pub_r000954_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((stage_v_244_1 * 3) + (sec_r000954_23_1 * 2)) - pub_r000954_17_1) + 24) & 127;
  int stage_v_289_2 = ((((stage_v_244_2 * 3) + (sec_r000954_23_2 * 2)) - pub_r000954_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((stage_v_132_1 * 3) + (sec_r000954_1_1 * 2)) - pub_r000954_6_1) + 16) & 127;
  int stage_v_290_2 = ((((stage_v_132_2 * 3) + (sec_r000954_1_2 * 2)) - pub_r000954_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((sec_r000954_14_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_5_1) + 21) & 127;
  int stage_v_291_2 = ((((sec_r000954_14_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((sec_r000954_12_1 * 3) + (sec_r000954_12_1 * 2)) - pub_r000954_4_1) + 28) & 127;
  int stage_v_292_2 = ((((sec_r000954_12_2 * 3) + (sec_r000954_12_2 * 2)) - pub_r000954_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((stage_v_115_1 * 3) + (sec_r000954_20_1 * 2)) - pub_r000954_19_1) + 22) & 127;
  int stage_v_293_2 = ((((stage_v_115_2 * 3) + (sec_r000954_20_2 * 2)) - pub_r000954_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((stage_v_256_1 * 3) + (sec_r000954_2_1 * 2)) - pub_r000954_10_1) + 32) & 127;
  int stage_v_294_2 = ((((stage_v_256_2 * 3) + (sec_r000954_2_2 * 2)) - pub_r000954_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((stage_v_122_1 * 3) + (sec_r000954_14_1 * 2)) - pub_r000954_12_1) + 16) & 127;
  int stage_v_295_2 = ((((stage_v_122_2 * 3) + (sec_r000954_14_2 * 2)) - pub_r000954_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((stage_v_259_1 * 3) + (sec_r000954_8_1 * 2)) - pub_r000954_10_1) + 36) & 127;
  int stage_v_296_2 = ((((stage_v_259_2 * 3) + (sec_r000954_8_2 * 2)) - pub_r000954_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((sec_r000954_18_1 * 3) + (sec_r000954_18_1 * 2)) - pub_r000954_11_1) + 20) & 127;
  int stage_v_297_2 = ((((sec_r000954_18_2 * 3) + (sec_r000954_18_2 * 2)) - pub_r000954_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000954_17_1 != sec_r000954_17_2);
  __CPROVER_assume(sec_r000954_19_1 != sec_r000954_19_2);
  __CPROVER_assume(sec_r000954_1_1 != sec_r000954_1_2);
  __CPROVER_assume(pub_r000954_13_1 == pub_r000954_13_2);
  __CPROVER_assume(sec_r000954_5_1 != sec_r000954_5_2);
  __CPROVER_assume(pub_r000954_17_1 == pub_r000954_17_2);
  __CPROVER_assume(sec_r000954_20_1 != sec_r000954_20_2);
  __CPROVER_assume(sec_r000954_21_1 != sec_r000954_21_2);
  __CPROVER_assume(sec_r000954_13_1 != sec_r000954_13_2);
  __CPROVER_assume(sec_r000954_0_1 != sec_r000954_0_2);
  __CPROVER_assume(pub_r000954_11_1 == pub_r000954_11_2);
  __CPROVER_assume(pub_r000954_12_1 == pub_r000954_12_2);
  __CPROVER_assume(pub_r000954_8_1 == pub_r000954_8_2);
  __CPROVER_assume(pub_r000954_15_1 == pub_r000954_15_2);
  __CPROVER_assume(sec_r000954_4_1 != sec_r000954_4_2);
  __CPROVER_assume(sec_r000954_11_1 != sec_r000954_11_2);
  __CPROVER_assume(sec_r000954_7_1 != sec_r000954_7_2);
  __CPROVER_assume(pub_r000954_2_1 == pub_r000954_2_2);
  __CPROVER_assume(pub_r000954_5_1 == pub_r000954_5_2);
  __CPROVER_assume(sec_r000954_16_1 != sec_r000954_16_2);
  __CPROVER_assume(pub_r000954_7_1 == pub_r000954_7_2);
  __CPROVER_assume(pub_r000954_1_1 == pub_r000954_1_2);
  __CPROVER_assume(pub_r000954_3_1 == pub_r000954_3_2);
  __CPROVER_assume(sec_r000954_9_1 != sec_r000954_9_2);
  __CPROVER_assume(sec_r000954_22_1 != sec_r000954_22_2);
  __CPROVER_assume(sec_r000954_23_1 != sec_r000954_23_2);
  __CPROVER_assume(pub_r000954_6_1 == pub_r000954_6_2);
  __CPROVER_assume(sec_r000954_3_1 != sec_r000954_3_2);
  __CPROVER_assume(sec_r000954_18_1 != sec_r000954_18_2);
  __CPROVER_assume(pub_r000954_18_1 == pub_r000954_18_2);
  __CPROVER_assume(pub_r000954_4_1 == pub_r000954_4_2);
  __CPROVER_assume(pub_r000954_0_1 == pub_r000954_0_2);
  __CPROVER_assume(pub_r000954_10_1 == pub_r000954_10_2);
  __CPROVER_assume(pub_r000954_9_1 == pub_r000954_9_2);
  __CPROVER_assume(sec_r000954_10_1 != sec_r000954_10_2);
  __CPROVER_assume(pub_r000954_19_1 == pub_r000954_19_2);
  __CPROVER_assume(pub_r000954_14_1 == pub_r000954_14_2);
  __CPROVER_assume(pub_r000954_16_1 == pub_r000954_16_2);
  __CPROVER_assume(sec_r000954_2_1 != sec_r000954_2_2);
  __CPROVER_assume(sec_r000954_12_1 != sec_r000954_12_2);
  __CPROVER_assume(sec_r000954_8_1 != sec_r000954_8_2);
  __CPROVER_assume(sec_r000954_15_1 != sec_r000954_15_2);
  __CPROVER_assume(sec_r000954_6_1 != sec_r000954_6_2);
  __CPROVER_assume(sec_r000954_14_1 != sec_r000954_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
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
}


