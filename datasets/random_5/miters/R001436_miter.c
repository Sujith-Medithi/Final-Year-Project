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
struct StreamBuffer_R001436_3613_0
{
  short state;
  int capacity;
  int head;
  int buffer[3];
};
struct AudioFrame_R001436_3613_1
{
  unsigned char envelope;
  unsigned char peak;
  unsigned char sample_rate;
  int buffer[3];
};
union PacketPayload_R001436_3613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001436_3613_1
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
void fn_R001436_3613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st_1 = {0};
  struct AudioFrame_R001436_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int parity_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_88_1 > 16)
  {
    acc_1 = ((acc_1 + (parity_88_1 * 2)) + 5) & 127;
    aux_1 ^= parity_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_88_2 > 16)
  {
    acc_2 = ((acc_2 + (parity_88_2 * 2)) + 5) & 127;
    aux_2 ^= parity_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_16_1)
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

  switch (damping_16_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_88_1 == parity_88_2);
  assert(damping_16_1 == damping_16_2);
}

int fn_R001436_3613_0(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int parity_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_88 > 16)
  {
    acc = ((acc + (parity_88 * 2)) + 5) & 127;
    aux ^= parity_88 & 15;
  }
  else
  {
    acc = ((acc - parity_88) + 11) & 127;
    aux += 3;
  }
  int damping_16 = (aux + st.buffer[1]) & 3;
  switch (damping_16)
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

void fn_R001436_3613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st_1 = {0};
  struct AudioFrame_R001436_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_89_1 = local_arr_1[aux_1 % 3];
  int accumulator_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_89_2 * 2)) & 127;
  int margin_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_28_1)
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

  switch (margin_28_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_89_1 == accumulator_89_2);
  assert(margin_28_1 == margin_28_2);
}

int fn_R001436_3613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int accumulator_89 = local_arr[aux % 3];
  acc = (acc + (accumulator_89 * 2)) & 127;
  int margin_28 = (aux + st.buffer[1]) & 3;
  switch (margin_28)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001436_3613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int scale_70_1 = 0;
  int scale_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_70_1 = ((scale_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_70_2 = ((scale_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_70_1) & 127;
    acc_2 = (acc_2 + scale_70_2) & 127;
  }

  int parity_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_37_1 > 21)
  {
    acc_1 = ((acc_1 + (parity_37_1 * 2)) + 5) & 127;
    aux_1 ^= parity_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_37_2 > 21)
  {
    acc_2 = ((acc_2 + (parity_37_2 * 2)) + 5) & 127;
    aux_2 ^= parity_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_22_1)
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

  switch (threshold_22_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_70_1 == scale_70_2);
  assert(parity_37_1 == parity_37_2);
  assert(threshold_22_1 == threshold_22_2);
}

int fn_R001436_3613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int scale_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_70 = ((scale_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_70) & 127;
  }

  int parity_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_37 > 21)
  {
    acc = ((acc + (parity_37 * 2)) + 5) & 127;
    aux ^= parity_37 & 15;
  }
  else
  {
    acc = ((acc - parity_37) + 11) & 127;
    aux += 3;
  }
  int threshold_22 = (aux + st.buffer[1]) & 3;
  switch (threshold_22)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001436_3613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int window_78_1 = 0;
  int window_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_78_1 = ((window_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_78_2 = ((window_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_78_1) & 127;
    acc_2 = (acc_2 + window_78_2) & 127;
  }

  int tracker_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_11_1) & 63;
  aux_2 = (aux_2 + tracker_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_54_1 = local_arr_1[aux_1 % 3];
  int anchor_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_54_2 * 2)) & 127;
  int damping_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_32_1)
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

  switch (damping_32_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_78_1 == window_78_2);
  assert(tracker_11_1 == tracker_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_54_1 == anchor_54_2);
  assert(damping_32_1 == damping_32_2);
}

int fn_R001436_3613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int window_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_78 = ((window_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_78) & 127;
  }

  int tracker_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_11) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_54 = local_arr[aux % 3];
  acc = (acc + (anchor_54 * 2)) & 127;
  int damping_32 = (aux + st.buffer[1]) & 3;
  switch (damping_32)
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

void fn_R001436_3613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_70_1 = local_arr_1[aux_1 % 3];
  int delta_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_70_2 * 2)) & 127;
  int tally_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_84_1 > 19)
  {
    acc_1 = ((acc_1 + (tally_84_1 * 2)) + 5) & 127;
    aux_1 ^= tally_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_84_2 > 19)
  {
    acc_2 = ((acc_2 + (tally_84_2 * 2)) + 5) & 127;
    aux_2 ^= tally_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_70_1 == delta_70_2);
  assert(tally_84_1 == tally_84_2);
}

int fn_R001436_3613_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_70 = local_arr[aux % 3];
  acc = (acc + (delta_70 * 2)) & 127;
  int tally_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_84 > 19)
  {
    acc = ((acc + (tally_84 * 2)) + 5) & 127;
    aux ^= tally_84 & 15;
  }
  else
  {
    acc = ((acc - tally_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001436_3613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st_1 = {0};
  struct AudioFrame_R001436_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quantum_60_1 = 0;
  int quantum_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_60_1 = ((quantum_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_60_2 = ((quantum_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_60_1) & 127;
    acc_2 = (acc_2 + quantum_60_2) & 127;
  }

  int anchor_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_26_1)
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

  switch (anchor_26_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_60_1 == quantum_60_2);
  assert(anchor_26_1 == anchor_26_2);
}

int fn_R001436_3613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quantum_60 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_60 = ((quantum_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_60) & 127;
  }

  int anchor_26 = (aux + st.buffer[1]) & 3;
  switch (anchor_26)
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

void fn_R001436_3613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st_1 = {0};
  struct AudioFrame_R001436_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tracker_88_1 = 0;
  int tracker_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_88_1 = ((tracker_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_88_2 = ((tracker_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_88_1) & 127;
    acc_2 = (acc_2 + tracker_88_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_85_1 = local_arr_1[aux_1 % 3];
  int residue_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_88_1 == tracker_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_85_1 == residue_85_2);
}

int fn_R001436_3613_6(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tracker_88 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_88 = ((tracker_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_88) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int residue_85 = local_arr[aux % 3];
  acc = (acc + (residue_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001436_3613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st_1 = {0};
  struct AudioFrame_R001436_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tally_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_13_1) & 63;
  aux_2 = (aux_2 + tally_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_31_1 > 28)
  {
    acc_1 = ((acc_1 + (sample_31_1 * 2)) + 5) & 127;
    aux_1 ^= sample_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_31_2 > 28)
  {
    acc_2 = ((acc_2 + (sample_31_2 * 2)) + 5) & 127;
    aux_2 ^= sample_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_86_1 = local_arr_1[aux_1 % 3];
  int coefficient_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_86_2 * 2)) & 127;
  int offset_41_1 = 0;
  int offset_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_41_1 = ((offset_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_41_2 = ((offset_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_41_1) & 127;
    acc_2 = (acc_2 + offset_41_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_13_1 == tally_13_2);
  assert(sample_31_1 == sample_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_86_1 == coefficient_86_2);
  assert(offset_41_1 == offset_41_2);
}

int fn_R001436_3613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tally_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_13) & 63;
  acc ^= aux;
  int sample_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_31 > 28)
  {
    acc = ((acc + (sample_31 * 2)) + 5) & 127;
    aux ^= sample_31 & 15;
  }
  else
  {
    acc = ((acc - sample_31) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_86 = local_arr[aux % 3];
  acc = (acc + (coefficient_86 * 2)) & 127;
  int offset_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_41 = ((offset_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_41) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001436_3613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int coefficient_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_47_1 > 17)
  {
    acc_1 = ((acc_1 + (coefficient_47_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_47_2 > 17)
  {
    acc_2 = ((acc_2 + (coefficient_47_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_47_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_47_1 == coefficient_47_2);
}

int fn_R001436_3613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int coefficient_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_47 > 17)
  {
    acc = ((acc + (coefficient_47 * 2)) + 5) & 127;
    aux ^= coefficient_47 & 15;
  }
  else
  {
    acc = ((acc - coefficient_47) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001436_3613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_16_1 = local_arr_1[aux_1 % 3];
  int index_reg_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_16_2 * 2)) & 127;
  int residue_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_86_1 > 46)
  {
    acc_1 = ((acc_1 + (residue_86_1 * 2)) + 5) & 127;
    aux_1 ^= residue_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_86_2 > 46)
  {
    acc_2 = ((acc_2 + (residue_86_2 * 2)) + 5) & 127;
    aux_2 ^= residue_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_53_1 = 0;
  int index_reg_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_53_1 = ((index_reg_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_53_2 = ((index_reg_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_53_1) & 127;
    acc_2 = (acc_2 + index_reg_53_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_16_1 == index_reg_16_2);
  assert(residue_86_1 == residue_86_2);
  assert(index_reg_53_1 == index_reg_53_2);
}

int fn_R001436_3613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int index_reg_16 = local_arr[aux % 3];
  acc = (acc + (index_reg_16 * 2)) & 127;
  int residue_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_86 > 46)
  {
    acc = ((acc + (residue_86 * 2)) + 5) & 127;
    aux ^= residue_86 & 15;
  }
  else
  {
    acc = ((acc - residue_86) + 11) & 127;
    aux += 3;
  }
  int index_reg_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_53 = ((index_reg_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_53) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001436_3613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int accumulator_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_53_1 > 50)
  {
    acc_1 = ((acc_1 + (accumulator_53_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_53_2 > 50)
  {
    acc_2 = ((acc_2 + (accumulator_53_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_53_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_21_1) & 63;
  aux_2 = (aux_2 + sample_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_93_1 = 0;
  int quotient_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_93_1 = ((quotient_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_93_2 = ((quotient_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_93_1) & 127;
    acc_2 = (acc_2 + quotient_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_53_1 == accumulator_53_2);
  assert(sample_21_1 == sample_21_2);
  assert(quotient_93_1 == quotient_93_2);
}

int fn_R001436_3613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int accumulator_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_53 > 50)
  {
    acc = ((acc + (accumulator_53 * 2)) + 5) & 127;
    aux ^= accumulator_53 & 15;
  }
  else
  {
    acc = ((acc - accumulator_53) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_21) & 63;
  acc ^= aux;
  int quotient_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_93 = ((quotient_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001436_3613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st_1 = {0};
  struct AudioFrame_R001436_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int segment_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_92_1) & 63;
  aux_2 = (aux_2 + segment_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_87_1 = 0;
  int vector_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_87_1 = ((vector_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_87_2 = ((vector_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_87_1) & 127;
    acc_2 = (acc_2 + vector_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_92_1 == segment_92_2);
  assert(vector_87_1 == vector_87_2);
}

int fn_R001436_3613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int segment_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_92) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_87 = ((vector_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001436_3613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int delta_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_74_1 > 33)
  {
    acc_1 = ((acc_1 + (delta_74_1 * 2)) + 5) & 127;
    aux_1 ^= delta_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_74_2 > 33)
  {
    acc_2 = ((acc_2 + (delta_74_2 * 2)) + 5) & 127;
    aux_2 ^= delta_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_67_1 = 0;
  int quotient_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_67_1 = ((quotient_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_67_2 = ((quotient_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_67_1) & 127;
    acc_2 = (acc_2 + quotient_67_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_74_1 == delta_74_2);
  assert(quotient_67_1 == quotient_67_2);
}

int fn_R001436_3613_12(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int delta_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_74 > 33)
  {
    acc = ((acc + (delta_74 * 2)) + 5) & 127;
    aux ^= delta_74 & 15;
  }
  else
  {
    acc = ((acc - delta_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_67 = ((quotient_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_67) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001436_3613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int damping_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_80_1)
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

  switch (damping_80_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_90_1 = 0;
  int phase_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_90_1 = ((phase_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_90_2 = ((phase_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_90_1) & 127;
    acc_2 = (acc_2 + phase_90_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_80_1 == damping_80_2);
  assert(phase_90_1 == phase_90_2);
}

int fn_R001436_3613_13(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int damping_80 = (aux + st.buffer[1]) & 3;
  switch (damping_80)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_90 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_90 = ((phase_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_90) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001436_3613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int pivot_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_55_1)
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

  switch (pivot_55_2)
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

  int offset_69_1 = 0;
  int offset_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_69_1 = ((offset_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_69_2 = ((offset_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_69_1) & 127;
    acc_2 = (acc_2 + offset_69_2) & 127;
  }

  int quantum_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_87_1) & 63;
  aux_2 = (aux_2 + quantum_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_60_1 = local_arr_1[aux_1 % 3];
  int scale_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_55_1 == pivot_55_2);
  assert(offset_69_1 == offset_69_2);
  assert(quantum_87_1 == quantum_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_60_1 == scale_60_2);
}

int fn_R001436_3613_14(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int pivot_55 = (aux + st.buffer[1]) & 3;
  switch (pivot_55)
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

  int offset_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_69 = ((offset_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_69) & 127;
  }

  int quantum_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_60 = local_arr[aux % 3];
  acc = (acc + (scale_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001436_3613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st_1 = {0};
  struct AudioFrame_R001436_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_21_1 = 0;
  int factor_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_21_1 = ((factor_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_21_2 = ((factor_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_21_1) & 127;
    acc_2 = (acc_2 + factor_21_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_21_1 == factor_21_2);
}

int fn_R001436_3613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_21 = ((factor_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_21) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001436_3613_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int window_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_71_1) & 63;
  aux_2 = (aux_2 + window_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_54_1 = local_arr_1[aux_1 % 3];
  int weight_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_54_2 * 2)) & 127;
  int stride_47_1 = 0;
  int stride_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_47_1 = ((stride_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_47_2 = ((stride_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_47_1) & 127;
    acc_2 = (acc_2 + stride_47_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_71_1 == window_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_54_1 == weight_54_2);
  assert(stride_47_1 == stride_47_2);
}

int fn_R001436_3613_16(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int window_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_71) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_54 = local_arr[aux % 3];
  acc = (acc + (weight_54 * 2)) & 127;
  int stride_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_47 = ((stride_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_47) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001436_3613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int threshold_10_1 = 0;
  int threshold_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_10_1 = ((threshold_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_10_2 = ((threshold_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_10_1) & 127;
    acc_2 = (acc_2 + threshold_10_2) & 127;
  }

  int tally_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_36_1)
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

  switch (tally_36_2)
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
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_10_1 == threshold_10_2);
  assert(tally_36_1 == tally_36_2);
}

int fn_R001436_3613_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001436_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int threshold_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_10 = ((threshold_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_10) & 127;
  }

  int tally_36 = (aux + st.buffer[1]) & 3;
  switch (tally_36)
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

void fn_R001436_3613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st_1 = {0};
  struct AudioFrame_R001436_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_31_1) & 63;
  aux_2 = (aux_2 + delta_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_31_1 == delta_31_2);
}

int fn_R001436_3613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001436_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001436_0_1;
  int sec_r001436_0_2;
  int sec_r001436_1_1;
  int sec_r001436_1_2;
  int sec_r001436_2_1;
  int sec_r001436_2_2;
  int sec_r001436_3_1;
  int sec_r001436_3_2;
  int sec_r001436_4_1;
  int sec_r001436_4_2;
  int sec_r001436_5_1;
  int sec_r001436_5_2;
  int sec_r001436_6_1;
  int sec_r001436_6_2;
  int sec_r001436_7_1;
  int sec_r001436_7_2;
  int sec_r001436_8_1;
  int sec_r001436_8_2;
  int sec_r001436_9_1;
  int sec_r001436_9_2;
  int sec_r001436_10_1;
  int sec_r001436_10_2;
  int sec_r001436_11_1;
  int sec_r001436_11_2;
  int sec_r001436_12_1;
  int sec_r001436_12_2;
  int sec_r001436_13_1;
  int sec_r001436_13_2;
  int sec_r001436_14_1;
  int sec_r001436_14_2;
  int sec_r001436_15_1;
  int sec_r001436_15_2;
  int sec_r001436_16_1;
  int sec_r001436_16_2;
  int sec_r001436_17_1;
  int sec_r001436_17_2;
  int sec_r001436_18_1;
  int sec_r001436_18_2;
  int sec_r001436_19_1;
  int sec_r001436_19_2;
  int pub_r001436_0_1;
  int pub_r001436_0_2;
  int pub_r001436_1_1;
  int pub_r001436_1_2;
  int pub_r001436_2_1;
  int pub_r001436_2_2;
  int pub_r001436_3_1;
  int pub_r001436_3_2;
  int pub_r001436_4_1;
  int pub_r001436_4_2;
  int pub_r001436_5_1;
  int pub_r001436_5_2;
  int pub_r001436_6_1;
  int pub_r001436_6_2;
  int pub_r001436_7_1;
  int pub_r001436_7_2;
  int pub_r001436_8_1;
  int pub_r001436_8_2;
  int pub_r001436_9_1;
  int pub_r001436_9_2;
  int pub_r001436_10_1;
  int pub_r001436_10_2;
  int pub_r001436_11_1;
  int pub_r001436_11_2;
  int pub_r001436_12_1;
  int pub_r001436_12_2;
  int pub_r001436_13_1;
  int pub_r001436_13_2;
  int pub_r001436_14_1;
  int pub_r001436_14_2;
  int pub_r001436_15_1;
  int pub_r001436_15_2;
  int pub_r001436_16_1;
  int pub_r001436_16_2;
  int pub_r001436_17_1;
  int pub_r001436_17_2;
  int pub_r001436_18_1;
  int pub_r001436_18_2;
  int pub_r001436_19_1;
  int pub_r001436_19_2;
  int pub_r001436_20_1;
  int pub_r001436_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001436_0_1 >= (-100)) && (pub_r001436_0_1 <= 100));
  __CPROVER_assume((pub_r001436_0_2 >= (-100)) && (pub_r001436_0_2 <= 100));
  __CPROVER_assume((pub_r001436_1_1 >= (-100)) && (pub_r001436_1_1 <= 100));
  __CPROVER_assume((pub_r001436_1_2 >= (-100)) && (pub_r001436_1_2 <= 100));
  __CPROVER_assume((pub_r001436_2_1 >= (-100)) && (pub_r001436_2_1 <= 100));
  __CPROVER_assume((pub_r001436_2_2 >= (-100)) && (pub_r001436_2_2 <= 100));
  __CPROVER_assume((pub_r001436_3_1 >= (-100)) && (pub_r001436_3_1 <= 100));
  __CPROVER_assume((pub_r001436_3_2 >= (-100)) && (pub_r001436_3_2 <= 100));
  __CPROVER_assume((pub_r001436_4_1 >= (-100)) && (pub_r001436_4_1 <= 100));
  __CPROVER_assume((pub_r001436_4_2 >= (-100)) && (pub_r001436_4_2 <= 100));
  __CPROVER_assume((pub_r001436_5_1 >= (-100)) && (pub_r001436_5_1 <= 100));
  __CPROVER_assume((pub_r001436_5_2 >= (-100)) && (pub_r001436_5_2 <= 100));
  __CPROVER_assume((pub_r001436_6_1 >= (-100)) && (pub_r001436_6_1 <= 100));
  __CPROVER_assume((pub_r001436_6_2 >= (-100)) && (pub_r001436_6_2 <= 100));
  __CPROVER_assume((pub_r001436_7_1 >= (-100)) && (pub_r001436_7_1 <= 100));
  __CPROVER_assume((pub_r001436_7_2 >= (-100)) && (pub_r001436_7_2 <= 100));
  __CPROVER_assume((pub_r001436_8_1 >= (-100)) && (pub_r001436_8_1 <= 100));
  __CPROVER_assume((pub_r001436_8_2 >= (-100)) && (pub_r001436_8_2 <= 100));
  __CPROVER_assume((pub_r001436_9_1 >= (-100)) && (pub_r001436_9_1 <= 100));
  __CPROVER_assume((pub_r001436_9_2 >= (-100)) && (pub_r001436_9_2 <= 100));
  __CPROVER_assume((pub_r001436_10_1 >= (-100)) && (pub_r001436_10_1 <= 100));
  __CPROVER_assume((pub_r001436_10_2 >= (-100)) && (pub_r001436_10_2 <= 100));
  __CPROVER_assume((pub_r001436_11_1 >= (-100)) && (pub_r001436_11_1 <= 100));
  __CPROVER_assume((pub_r001436_11_2 >= (-100)) && (pub_r001436_11_2 <= 100));
  __CPROVER_assume((pub_r001436_12_1 >= (-100)) && (pub_r001436_12_1 <= 100));
  __CPROVER_assume((pub_r001436_12_2 >= (-100)) && (pub_r001436_12_2 <= 100));
  __CPROVER_assume((pub_r001436_13_1 >= (-100)) && (pub_r001436_13_1 <= 100));
  __CPROVER_assume((pub_r001436_13_2 >= (-100)) && (pub_r001436_13_2 <= 100));
  __CPROVER_assume((pub_r001436_14_1 >= (-100)) && (pub_r001436_14_1 <= 100));
  __CPROVER_assume((pub_r001436_14_2 >= (-100)) && (pub_r001436_14_2 <= 100));
  __CPROVER_assume((pub_r001436_15_1 >= (-100)) && (pub_r001436_15_1 <= 100));
  __CPROVER_assume((pub_r001436_15_2 >= (-100)) && (pub_r001436_15_2 <= 100));
  __CPROVER_assume((pub_r001436_16_1 >= (-100)) && (pub_r001436_16_1 <= 100));
  __CPROVER_assume((pub_r001436_16_2 >= (-100)) && (pub_r001436_16_2 <= 100));
  __CPROVER_assume((pub_r001436_17_1 >= (-100)) && (pub_r001436_17_1 <= 100));
  __CPROVER_assume((pub_r001436_17_2 >= (-100)) && (pub_r001436_17_2 <= 100));
  __CPROVER_assume((pub_r001436_18_1 >= (-100)) && (pub_r001436_18_1 <= 100));
  __CPROVER_assume((pub_r001436_18_2 >= (-100)) && (pub_r001436_18_2 <= 100));
  __CPROVER_assume((pub_r001436_19_1 >= (-100)) && (pub_r001436_19_1 <= 100));
  __CPROVER_assume((pub_r001436_19_2 >= (-100)) && (pub_r001436_19_2 <= 100));
  __CPROVER_assume((pub_r001436_20_1 >= (-100)) && (pub_r001436_20_1 <= 100));
  __CPROVER_assume((pub_r001436_20_2 >= (-100)) && (pub_r001436_20_2 <= 100));
  __CPROVER_assume((sec_r001436_0_1 >= 0) && (sec_r001436_0_1 <= 255));
  __CPROVER_assume((sec_r001436_0_2 >= 0) && (sec_r001436_0_2 <= 255));
  __CPROVER_assume((sec_r001436_1_1 >= 0) && (sec_r001436_1_1 <= 255));
  __CPROVER_assume((sec_r001436_1_2 >= 0) && (sec_r001436_1_2 <= 255));
  __CPROVER_assume((sec_r001436_2_1 >= 0) && (sec_r001436_2_1 <= 255));
  __CPROVER_assume((sec_r001436_2_2 >= 0) && (sec_r001436_2_2 <= 255));
  __CPROVER_assume((sec_r001436_3_1 >= 0) && (sec_r001436_3_1 <= 255));
  __CPROVER_assume((sec_r001436_3_2 >= 0) && (sec_r001436_3_2 <= 255));
  __CPROVER_assume((sec_r001436_4_1 >= 0) && (sec_r001436_4_1 <= 255));
  __CPROVER_assume((sec_r001436_4_2 >= 0) && (sec_r001436_4_2 <= 255));
  __CPROVER_assume((sec_r001436_5_1 >= 0) && (sec_r001436_5_1 <= 255));
  __CPROVER_assume((sec_r001436_5_2 >= 0) && (sec_r001436_5_2 <= 255));
  __CPROVER_assume((sec_r001436_6_1 >= 0) && (sec_r001436_6_1 <= 255));
  __CPROVER_assume((sec_r001436_6_2 >= 0) && (sec_r001436_6_2 <= 255));
  __CPROVER_assume((sec_r001436_7_1 >= 0) && (sec_r001436_7_1 <= 255));
  __CPROVER_assume((sec_r001436_7_2 >= 0) && (sec_r001436_7_2 <= 255));
  __CPROVER_assume((sec_r001436_8_1 >= 0) && (sec_r001436_8_1 <= 255));
  __CPROVER_assume((sec_r001436_8_2 >= 0) && (sec_r001436_8_2 <= 255));
  __CPROVER_assume((sec_r001436_9_1 >= 0) && (sec_r001436_9_1 <= 255));
  __CPROVER_assume((sec_r001436_9_2 >= 0) && (sec_r001436_9_2 <= 255));
  __CPROVER_assume((sec_r001436_10_1 >= 0) && (sec_r001436_10_1 <= 255));
  __CPROVER_assume((sec_r001436_10_2 >= 0) && (sec_r001436_10_2 <= 255));
  __CPROVER_assume((sec_r001436_11_1 >= 0) && (sec_r001436_11_1 <= 255));
  __CPROVER_assume((sec_r001436_11_2 >= 0) && (sec_r001436_11_2 <= 255));
  __CPROVER_assume((sec_r001436_12_1 >= 0) && (sec_r001436_12_1 <= 255));
  __CPROVER_assume((sec_r001436_12_2 >= 0) && (sec_r001436_12_2 <= 255));
  __CPROVER_assume((sec_r001436_13_1 >= 0) && (sec_r001436_13_1 <= 255));
  __CPROVER_assume((sec_r001436_13_2 >= 0) && (sec_r001436_13_2 <= 255));
  __CPROVER_assume((sec_r001436_14_1 >= 0) && (sec_r001436_14_1 <= 255));
  __CPROVER_assume((sec_r001436_14_2 >= 0) && (sec_r001436_14_2 <= 255));
  __CPROVER_assume((sec_r001436_15_1 >= 0) && (sec_r001436_15_1 <= 255));
  __CPROVER_assume((sec_r001436_15_2 >= 0) && (sec_r001436_15_2 <= 255));
  __CPROVER_assume((sec_r001436_16_1 >= 0) && (sec_r001436_16_1 <= 255));
  __CPROVER_assume((sec_r001436_16_2 >= 0) && (sec_r001436_16_2 <= 255));
  __CPROVER_assume((sec_r001436_17_1 >= 0) && (sec_r001436_17_1 <= 255));
  __CPROVER_assume((sec_r001436_17_2 >= 0) && (sec_r001436_17_2 <= 255));
  __CPROVER_assume((sec_r001436_18_1 >= 0) && (sec_r001436_18_1 <= 255));
  __CPROVER_assume((sec_r001436_18_2 >= 0) && (sec_r001436_18_2 <= 255));
  __CPROVER_assume((sec_r001436_19_1 >= 0) && (sec_r001436_19_1 <= 255));
  __CPROVER_assume((sec_r001436_19_2 >= 0) && (sec_r001436_19_2 <= 255));
  struct StreamBuffer_R001436_3613_0 st_var_0_1 = {0};
  struct StreamBuffer_R001436_3613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001436_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001436_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001436_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001436_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001436_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001436_0_2 + 7) & 15;
  struct AudioFrame_R001436_3613_1 st_var_1_1 = {0};
  struct AudioFrame_R001436_3613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001436_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001436_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001436_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001436_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001436_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001436_0_2 + 9) & 15;
  union PacketPayload_R001436_3613_0 u_var_1;
  union PacketPayload_R001436_3613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001436_3613_0(sec_r001436_0_1, sec_r001436_1_1);
  int helper_flow_0_2 = fn_R001436_3613_0(sec_r001436_0_2, sec_r001436_1_2);
  fn_R001436_3613_0_2(sec_r001436_0_1, sec_r001436_1_1, sec_r001436_0_2, sec_r001436_1_2);
  int helper_flow_1_1 = fn_R001436_3613_1(sec_r001436_1_1, pub_r001436_2_1, pub_r001436_3_1);
  int helper_flow_1_2 = fn_R001436_3613_1(sec_r001436_1_2, pub_r001436_2_2, pub_r001436_3_2);
  fn_R001436_3613_1_2(sec_r001436_1_1, pub_r001436_2_1, pub_r001436_3_1, sec_r001436_1_2, pub_r001436_2_2, pub_r001436_3_2);
  int helper_flow_2_1 = fn_R001436_3613_2(sec_r001436_2_1, sec_r001436_3_1, pub_r001436_4_1, pub_r001436_5_1);
  int helper_flow_2_2 = fn_R001436_3613_2(sec_r001436_2_2, sec_r001436_3_2, pub_r001436_4_2, pub_r001436_5_2);
  fn_R001436_3613_2_2(sec_r001436_2_1, sec_r001436_3_1, pub_r001436_4_1, pub_r001436_5_1, sec_r001436_2_2, sec_r001436_3_2, pub_r001436_4_2, pub_r001436_5_2);
  int helper_flow_3_1 = fn_R001436_3613_3(sec_r001436_3_1, pub_r001436_4_1, pub_r001436_5_1, pub_r001436_6_1);
  int helper_flow_3_2 = fn_R001436_3613_3(sec_r001436_3_2, pub_r001436_4_2, pub_r001436_5_2, pub_r001436_6_2);
  fn_R001436_3613_3_2(sec_r001436_3_1, pub_r001436_4_1, pub_r001436_5_1, pub_r001436_6_1, sec_r001436_3_2, pub_r001436_4_2, pub_r001436_5_2, pub_r001436_6_2);
  int helper_flow_4_1 = fn_R001436_3613_4(sec_r001436_4_1, pub_r001436_5_1, pub_r001436_6_1, pub_r001436_7_1, pub_r001436_8_1);
  int helper_flow_4_2 = fn_R001436_3613_4(sec_r001436_4_2, pub_r001436_5_2, pub_r001436_6_2, pub_r001436_7_2, pub_r001436_8_2);
  fn_R001436_3613_4_2(sec_r001436_4_1, pub_r001436_5_1, pub_r001436_6_1, pub_r001436_7_1, pub_r001436_8_1, sec_r001436_4_2, pub_r001436_5_2, pub_r001436_6_2, pub_r001436_7_2, pub_r001436_8_2);
  int helper_flow_5_1 = fn_R001436_3613_5(sec_r001436_5_1, pub_r001436_6_1, pub_r001436_7_1, pub_r001436_8_1, pub_r001436_9_1);
  int helper_flow_5_2 = fn_R001436_3613_5(sec_r001436_5_2, pub_r001436_6_2, pub_r001436_7_2, pub_r001436_8_2, pub_r001436_9_2);
  fn_R001436_3613_5_2(sec_r001436_5_1, pub_r001436_6_1, pub_r001436_7_1, pub_r001436_8_1, pub_r001436_9_1, sec_r001436_5_2, pub_r001436_6_2, pub_r001436_7_2, pub_r001436_8_2, pub_r001436_9_2);
  int helper_flow_6_1 = fn_R001436_3613_6(sec_r001436_6_1, sec_r001436_7_1);
  int helper_flow_6_2 = fn_R001436_3613_6(sec_r001436_6_2, sec_r001436_7_2);
  fn_R001436_3613_6_2(sec_r001436_6_1, sec_r001436_7_1, sec_r001436_6_2, sec_r001436_7_2);
  int helper_flow_7_1 = fn_R001436_3613_7(sec_r001436_7_1, sec_r001436_8_1, pub_r001436_9_1, pub_r001436_10_1);
  int helper_flow_7_2 = fn_R001436_3613_7(sec_r001436_7_2, sec_r001436_8_2, pub_r001436_9_2, pub_r001436_10_2);
  fn_R001436_3613_7_2(sec_r001436_7_1, sec_r001436_8_1, pub_r001436_9_1, pub_r001436_10_1, sec_r001436_7_2, sec_r001436_8_2, pub_r001436_9_2, pub_r001436_10_2);
  int helper_flow_8_1 = fn_R001436_3613_8(sec_r001436_8_1, pub_r001436_9_1, pub_r001436_10_1, pub_r001436_11_1);
  int helper_flow_8_2 = fn_R001436_3613_8(sec_r001436_8_2, pub_r001436_9_2, pub_r001436_10_2, pub_r001436_11_2);
  fn_R001436_3613_8_2(sec_r001436_8_1, pub_r001436_9_1, pub_r001436_10_1, pub_r001436_11_1, sec_r001436_8_2, pub_r001436_9_2, pub_r001436_10_2, pub_r001436_11_2);
  int stage_v_0_1 = ((helper_flow_3_1 + (pub_r001436_7_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_3_2 + (pub_r001436_7_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((helper_flow_0_1 + (pub_r001436_3_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((helper_flow_0_2 + (pub_r001436_3_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001436_12_1 + (pub_r001436_17_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001436_12_2 + (pub_r001436_17_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((pub_r001436_16_1 * 2) + 7) & 63;
  int stage_v_3_2 = ((pub_r001436_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001436_16_1 * 2) + 36) & 63;
  int stage_v_4_2 = ((pub_r001436_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((helper_flow_7_1 + (pub_r001436_13_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((helper_flow_7_2 + (pub_r001436_13_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001436_16_1 * 2) + 12) & 63;
  int stage_v_6_2 = ((pub_r001436_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((helper_flow_1_1 + (pub_r001436_7_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((helper_flow_1_2 + (pub_r001436_7_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((helper_flow_1_1 + (pub_r001436_18_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((helper_flow_1_2 + (pub_r001436_18_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001436_11_1 * 2) + 27) & 63;
  int stage_v_9_2 = ((pub_r001436_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001436_18_1 * 2) + 46) & 63;
  int stage_v_10_2 = ((pub_r001436_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((helper_flow_8_1 + (pub_r001436_18_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((helper_flow_8_2 + (pub_r001436_18_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((helper_flow_4_1 + (pub_r001436_10_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((helper_flow_4_2 + (pub_r001436_10_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001436_2_1 + (pub_r001436_20_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001436_2_2 + (pub_r001436_20_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((stage_v_5_1 + (pub_r001436_1_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((stage_v_5_2 + (pub_r001436_1_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((sec_r001436_16_1 + (pub_r001436_19_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001436_16_2 + (pub_r001436_19_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001436_1_1 * 2) + 14) & 63;
  int stage_v_16_2 = ((pub_r001436_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001436_10_1 * 2) + 31) & 63;
  int stage_v_17_2 = ((pub_r001436_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((sec_r001436_9_1 + (pub_r001436_4_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001436_9_2 + (pub_r001436_4_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001436_18_1 * 2) + 6) & 63;
  int stage_v_19_2 = ((pub_r001436_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001436_9_1 * 2) + 6) & 63;
  int stage_v_20_2 = ((pub_r001436_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((helper_flow_8_1 + (pub_r001436_19_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((helper_flow_8_2 + (pub_r001436_19_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001436_19_1 + (pub_r001436_12_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001436_19_2 + (pub_r001436_12_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001436_18_1 * 2) + 50) & 63;
  int stage_v_23_2 = ((pub_r001436_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001436_4_1 * 2) + 30) & 63;
  int stage_v_24_2 = ((pub_r001436_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001436_5_1 * 2) + 10) & 63;
  int stage_v_25_2 = ((pub_r001436_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((sec_r001436_9_1 + (pub_r001436_19_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001436_9_2 + (pub_r001436_19_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((pub_r001436_7_1 * 2) + 31) & 63;
  int stage_v_27_2 = ((pub_r001436_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001436_17_1 * 2) + 45) & 63;
  int stage_v_28_2 = ((pub_r001436_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001436_6_1 + (pub_r001436_16_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001436_6_2 + (pub_r001436_16_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((sec_r001436_9_1 + (pub_r001436_16_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((sec_r001436_9_2 + (pub_r001436_16_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001436_16_1 * 2) + 29) & 63;
  int stage_v_31_2 = ((pub_r001436_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((stage_v_18_1 + (pub_r001436_12_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_18_2 + (pub_r001436_12_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((pub_r001436_10_1 * 2) + 20) & 63;
  int stage_v_33_2 = ((pub_r001436_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((stage_v_15_1 + (pub_r001436_2_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_15_2 + (pub_r001436_2_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001436_14_1 + (pub_r001436_16_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001436_14_2 + (pub_r001436_16_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((sec_r001436_11_1 + (pub_r001436_17_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((sec_r001436_11_2 + (pub_r001436_17_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001436_0_1 * 2) + 5) & 63;
  int stage_v_37_2 = ((pub_r001436_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001436_15_1 * 2) + 6) & 63;
  int stage_v_38_2 = ((pub_r001436_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001436_13_1 * 2) + 45) & 63;
  int stage_v_39_2 = ((pub_r001436_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001436_1_1 * 2) + 22) & 63;
  int stage_v_40_2 = ((pub_r001436_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((sec_r001436_17_1 + (pub_r001436_18_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((sec_r001436_17_2 + (pub_r001436_18_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((helper_flow_2_1 + (pub_r001436_8_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((helper_flow_2_2 + (pub_r001436_8_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((stage_v_1_1 + (pub_r001436_15_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_1_2 + (pub_r001436_15_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((stage_v_36_1 + (pub_r001436_18_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_36_2 + (pub_r001436_18_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((pub_r001436_8_1 * 2) + 31) & 63;
  int stage_v_45_2 = ((pub_r001436_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((stage_v_44_1 + (pub_r001436_9_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_44_2 + (pub_r001436_9_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((stage_v_32_1 + (pub_r001436_11_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_32_2 + (pub_r001436_11_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((stage_v_7_1 + (pub_r001436_10_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_7_2 + (pub_r001436_10_2 * 2)) + 149) & 127;
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
  int stage_v_49_1 = ((stage_v_2_1 + (pub_r001436_14_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_2_2 + (pub_r001436_14_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001436_9_1 * 2) + 28) & 63;
  int stage_v_50_2 = ((pub_r001436_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((sec_r001436_11_1 + (pub_r001436_14_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((sec_r001436_11_2 + (pub_r001436_14_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((sec_r001436_10_1 + (pub_r001436_15_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001436_10_2 + (pub_r001436_15_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001436_6_1 * 2) + 30) & 63;
  int stage_v_53_2 = ((pub_r001436_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001436_16_1 * 2) + 30) & 63;
  int stage_v_54_2 = ((pub_r001436_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((helper_flow_7_1 + (pub_r001436_13_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((helper_flow_7_2 + (pub_r001436_13_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((helper_flow_8_1 + (pub_r001436_13_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((helper_flow_8_2 + (pub_r001436_13_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((pub_r001436_16_1 * 2) + 46) & 63;
  int stage_v_57_2 = ((pub_r001436_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001436_6_1 * 2) + 43) & 63;
  int stage_v_58_2 = ((pub_r001436_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((sec_r001436_8_1 + (pub_r001436_16_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((sec_r001436_8_2 + (pub_r001436_16_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((helper_flow_1_1 + (pub_r001436_5_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((helper_flow_1_2 + (pub_r001436_5_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_48_1 + (pub_r001436_19_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_48_2 + (pub_r001436_19_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_35_1 + (pub_r001436_10_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_35_2 + (pub_r001436_10_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((sec_r001436_15_1 + (pub_r001436_16_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((sec_r001436_15_2 + (pub_r001436_16_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_12_1 + (pub_r001436_19_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_12_2 + (pub_r001436_19_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((sec_r001436_3_1 + (pub_r001436_5_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((sec_r001436_3_2 + (pub_r001436_5_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001436_15_1 * 2) + 38) & 63;
  int stage_v_66_2 = ((pub_r001436_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001436_18_1 * 2) + 12) & 63;
  int stage_v_67_2 = ((pub_r001436_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((stage_v_14_1 + (pub_r001436_18_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_14_2 + (pub_r001436_18_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((pub_r001436_17_1 * 2) + 45) & 63;
  int stage_v_69_2 = ((pub_r001436_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001436_18_1 * 2) + 9) & 63;
  int stage_v_70_2 = ((pub_r001436_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001436_11_1 * 2) + 41) & 63;
  int stage_v_71_2 = ((pub_r001436_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((sec_r001436_16_1 + (pub_r001436_8_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((sec_r001436_16_2 + (pub_r001436_8_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001436_20_1 * 2) + 28) & 63;
  int stage_v_73_2 = ((pub_r001436_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001436_13_1 * 2) + 6) & 63;
  int stage_v_74_2 = ((pub_r001436_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((sec_r001436_15_1 + (pub_r001436_1_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((sec_r001436_15_2 + (pub_r001436_1_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((sec_r001436_2_1 + (pub_r001436_1_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((sec_r001436_2_2 + (pub_r001436_1_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_1_1 + (pub_r001436_16_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_1_2 + (pub_r001436_16_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_43_1 + (pub_r001436_5_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_43_2 + (pub_r001436_5_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001436_9_1 * 2) + 42) & 63;
  int stage_v_79_2 = ((pub_r001436_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_55_1 + (pub_r001436_16_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_55_2 + (pub_r001436_16_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_49_1 + (pub_r001436_7_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_49_2 + (pub_r001436_7_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001436_10_1 * 2) + 12) & 63;
  int stage_v_82_2 = ((pub_r001436_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001436_10_1 * 2) + 34) & 63;
  int stage_v_83_2 = ((pub_r001436_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001436_13_1 * 2) + 14) & 63;
  int stage_v_84_2 = ((pub_r001436_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001436_15_1 * 2) + 31) & 63;
  int stage_v_85_2 = ((pub_r001436_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001436_4_1 * 2) + 23) & 63;
  int stage_v_86_2 = ((pub_r001436_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001436_10_1 * 2) + 42) & 63;
  int stage_v_87_2 = ((pub_r001436_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((stage_v_30_1 + (pub_r001436_10_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_30_2 + (pub_r001436_10_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((pub_r001436_19_1 * 2) + 38) & 63;
  int stage_v_89_2 = ((pub_r001436_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((sec_r001436_12_1 + (pub_r001436_18_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((sec_r001436_12_2 + (pub_r001436_18_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((pub_r001436_6_1 * 2) + 33) & 63;
  int stage_v_91_2 = ((pub_r001436_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001436_5_1 * 2) + 45) & 63;
  int stage_v_92_2 = ((pub_r001436_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((stage_v_36_1 + (pub_r001436_3_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_36_2 + (pub_r001436_3_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_47_1 + (pub_r001436_1_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_47_2 + (pub_r001436_1_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((pub_r001436_12_1 * 2) + 34) & 63;
  int stage_v_95_2 = ((pub_r001436_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001436_19_1 * 2) + 19) & 63;
  int stage_v_96_2 = ((pub_r001436_19_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_60_1 + (pub_r001436_8_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_60_2 + (pub_r001436_8_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_12_1 + (pub_r001436_0_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_12_2 + (pub_r001436_0_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001436_3_1 * 2) + 24) & 63;
  int stage_v_99_2 = ((pub_r001436_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001436_6_1 * 2) + 5) & 63;
  int stage_v_100_2 = ((pub_r001436_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001436_5_1 * 2) + 42) & 63;
  int stage_v_101_2 = ((pub_r001436_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_97_1 + (pub_r001436_12_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_97_2 + (pub_r001436_12_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((sec_r001436_2_1 + (pub_r001436_11_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001436_2_2 + (pub_r001436_11_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((sec_r001436_4_1 + (pub_r001436_3_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((sec_r001436_4_2 + (pub_r001436_3_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((pub_r001436_17_1 * 2) + 48) & 63;
  int stage_v_105_2 = ((pub_r001436_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_32_1 + (pub_r001436_14_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_32_2 + (pub_r001436_14_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_93_1 + (pub_r001436_12_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_93_2 + (pub_r001436_12_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001436_12_1 * 2) + 10) & 63;
  int stage_v_108_2 = ((pub_r001436_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_104_1 + (pub_r001436_1_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_104_2 + (pub_r001436_1_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((sec_r001436_9_1 + (pub_r001436_9_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((sec_r001436_9_2 + (pub_r001436_9_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_41_1 + (pub_r001436_15_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_41_2 + (pub_r001436_15_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((pub_r001436_19_1 * 2) + 13) & 63;
  int stage_v_112_2 = ((pub_r001436_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001436_2_1 * 2) + 32) & 63;
  int stage_v_113_2 = ((pub_r001436_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001436_10_1 * 2) + 44) & 63;
  int stage_v_114_2 = ((pub_r001436_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_1_1 + (pub_r001436_19_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_1_2 + (pub_r001436_19_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_64_1 + (pub_r001436_19_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_64_2 + (pub_r001436_19_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_42_1 + (pub_r001436_3_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_42_2 + (pub_r001436_3_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((pub_r001436_14_1 * 2) + 6) & 63;
  int stage_v_118_2 = ((pub_r001436_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((sec_r001436_16_1 + (pub_r001436_10_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((sec_r001436_16_2 + (pub_r001436_10_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((pub_r001436_7_1 * 2) + 15) & 63;
  int stage_v_120_2 = ((pub_r001436_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_88_1 + (pub_r001436_5_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_88_2 + (pub_r001436_5_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_8_1 + (pub_r001436_11_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_8_2 + (pub_r001436_11_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_15_1 + (pub_r001436_6_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_15_2 + (pub_r001436_6_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((stage_v_93_1 + (pub_r001436_8_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_93_2 + (pub_r001436_8_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((pub_r001436_17_1 * 2) + 44) & 63;
  int stage_v_125_2 = ((pub_r001436_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001436_17_1 * 2) + 47) & 63;
  int stage_v_126_2 = ((pub_r001436_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001436_1_1 * 2) + 24) & 63;
  int stage_v_127_2 = ((pub_r001436_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_35_1 + (pub_r001436_2_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_35_2 + (pub_r001436_2_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_21_1 + (pub_r001436_1_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_21_2 + (pub_r001436_1_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_109_1 + (pub_r001436_15_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_109_2 + (pub_r001436_15_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001436_6_1 * 2) + 7) & 63;
  int stage_v_131_2 = ((pub_r001436_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001436_15_1 * 2) + 36) & 63;
  int stage_v_132_2 = ((pub_r001436_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((sec_r001436_13_1 + (pub_r001436_6_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((sec_r001436_13_2 + (pub_r001436_6_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_123_1 + (pub_r001436_9_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_123_2 + (pub_r001436_9_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_30_1 + (pub_r001436_13_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_30_2 + (pub_r001436_13_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((helper_flow_2_1 + (pub_r001436_5_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((helper_flow_2_2 + (pub_r001436_5_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001436_8_1 * 2) + 23) & 63;
  int stage_v_137_2 = ((pub_r001436_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001436_0_1 * 2) + 16) & 63;
  int stage_v_138_2 = ((pub_r001436_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((sec_r001436_19_1 + (pub_r001436_3_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((sec_r001436_19_2 + (pub_r001436_3_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_15_1 + (pub_r001436_19_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_15_2 + (pub_r001436_19_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001436_4_1 * 2) + 38) & 63;
  int stage_v_141_2 = ((pub_r001436_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001436_15_1 * 2) + 26) & 63;
  int stage_v_142_2 = ((pub_r001436_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_14_1 + (pub_r001436_18_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_14_2 + (pub_r001436_18_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((sec_r001436_2_1 + (pub_r001436_2_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((sec_r001436_2_2 + (pub_r001436_2_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_88_1 + (pub_r001436_2_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_88_2 + (pub_r001436_2_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((pub_r001436_14_1 * 2) + 12) & 63;
  int stage_v_146_2 = ((pub_r001436_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001436_11_1 * 2) + 27) & 63;
  int stage_v_147_2 = ((pub_r001436_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001436_3_1 * 2) + 29) & 63;
  int stage_v_148_2 = ((pub_r001436_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001436_7_1 * 2) + 16) & 63;
  int stage_v_149_2 = ((pub_r001436_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_63_1 + (pub_r001436_12_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_63_2 + (pub_r001436_12_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001436_0_1 * 2) + 38) & 63;
  int stage_v_151_2 = ((pub_r001436_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_78_1 + (pub_r001436_20_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_78_2 + (pub_r001436_20_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_109_1 + (pub_r001436_14_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_109_2 + (pub_r001436_14_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((sec_r001436_15_1 + (pub_r001436_7_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((sec_r001436_15_2 + (pub_r001436_7_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((pub_r001436_17_1 * 2) + 10) & 63;
  int stage_v_155_2 = ((pub_r001436_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((stage_v_72_1 + (pub_r001436_18_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_72_2 + (pub_r001436_18_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_152_1 + (pub_r001436_8_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_152_2 + (pub_r001436_8_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_62_1 + (pub_r001436_5_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_62_2 + (pub_r001436_5_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_140_1 + (pub_r001436_19_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_140_2 + (pub_r001436_19_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((pub_r001436_3_1 * 2) + 9) & 63;
  int stage_v_160_2 = ((pub_r001436_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001436_6_1 * 2) + 43) & 63;
  int stage_v_161_2 = ((pub_r001436_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_140_1 + (pub_r001436_7_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_140_2 + (pub_r001436_7_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((pub_r001436_3_1 * 2) + 33) & 63;
  int stage_v_163_2 = ((pub_r001436_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_76_1 + (pub_r001436_20_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_76_2 + (pub_r001436_20_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_55_1 + (pub_r001436_13_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_55_2 + (pub_r001436_13_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_154_1 + (pub_r001436_2_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_154_2 + (pub_r001436_2_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_164_1 + (pub_r001436_14_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_164_2 + (pub_r001436_14_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_162_1 + (pub_r001436_15_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_162_2 + (pub_r001436_15_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_124_1 + (pub_r001436_2_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_124_2 + (pub_r001436_2_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_134_1 + (pub_r001436_11_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_134_2 + (pub_r001436_11_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((pub_r001436_9_1 * 2) + 20) & 63;
  int stage_v_171_2 = ((pub_r001436_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_12_1 + (pub_r001436_15_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_12_2 + (pub_r001436_15_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_145_1 + (pub_r001436_4_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_145_2 + (pub_r001436_4_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((pub_r001436_0_1 * 2) + 11) & 63;
  int stage_v_174_2 = ((pub_r001436_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((helper_flow_5_1 + (pub_r001436_15_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((helper_flow_5_2 + (pub_r001436_15_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_165_1 + (pub_r001436_1_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_165_2 + (pub_r001436_1_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_94_1 + (pub_r001436_2_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_94_2 + (pub_r001436_2_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((pub_r001436_4_1 * 2) + 15) & 63;
  int stage_v_178_2 = ((pub_r001436_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((stage_v_145_1 + (pub_r001436_7_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_145_2 + (pub_r001436_7_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_123_1 + (pub_r001436_20_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_123_2 + (pub_r001436_20_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_167_1 + (pub_r001436_19_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_167_2 + (pub_r001436_19_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((sec_r001436_17_1 + (pub_r001436_5_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((sec_r001436_17_2 + (pub_r001436_5_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_98_1 + (pub_r001436_19_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_98_2 + (pub_r001436_19_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_49_1 + (pub_r001436_14_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_49_2 + (pub_r001436_14_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_166_1 + (pub_r001436_19_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_166_2 + (pub_r001436_19_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_41_1 + (pub_r001436_11_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_41_2 + (pub_r001436_11_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((pub_r001436_2_1 * 2) + 41) & 63;
  int stage_v_187_2 = ((pub_r001436_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001436_16_1 * 2) + 9) & 63;
  int stage_v_188_2 = ((pub_r001436_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_130_1 + (pub_r001436_3_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_130_2 + (pub_r001436_3_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001436_19_1 * 2) + 29) & 63;
  int stage_v_190_2 = ((pub_r001436_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001436_3_1 * 2) + 49) & 63;
  int stage_v_191_2 = ((pub_r001436_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((sec_r001436_4_1 + (pub_r001436_14_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((sec_r001436_4_2 + (pub_r001436_14_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_46_1 + (pub_r001436_5_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_46_2 + (pub_r001436_5_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_168_1 + (pub_r001436_8_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_168_2 + (pub_r001436_8_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((pub_r001436_13_1 * 2) + 9) & 63;
  int stage_v_195_2 = ((pub_r001436_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_104_1 + (pub_r001436_4_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_104_2 + (pub_r001436_4_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((pub_r001436_4_1 * 2) + 30) & 63;
  int stage_v_197_2 = ((pub_r001436_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((stage_v_196_1 + (pub_r001436_14_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_196_2 + (pub_r001436_14_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_26_1 + (pub_r001436_0_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_26_2 + (pub_r001436_0_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001436_15_1 * 2) + 8) & 63;
  int stage_v_200_2 = ((pub_r001436_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_136_1 + (pub_r001436_7_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_136_2 + (pub_r001436_7_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_75_1 + (pub_r001436_0_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_75_2 + (pub_r001436_0_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((pub_r001436_4_1 * 2) + 7) & 63;
  int stage_v_203_2 = ((pub_r001436_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_115_1 + (pub_r001436_10_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_115_2 + (pub_r001436_10_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_152_1 + (pub_r001436_3_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_152_2 + (pub_r001436_3_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001436_6_1 * 2) + 27) & 63;
  int stage_v_206_2 = ((pub_r001436_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_204_1 + (pub_r001436_16_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_204_2 + (pub_r001436_16_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((sec_r001436_2_1 + (pub_r001436_20_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((sec_r001436_2_2 + (pub_r001436_20_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_22_1 + (pub_r001436_5_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_22_2 + (pub_r001436_5_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((sec_r001436_19_1 + (pub_r001436_3_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((sec_r001436_19_2 + (pub_r001436_3_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((helper_flow_0_1 + (pub_r001436_20_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((helper_flow_0_2 + (pub_r001436_20_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001436_18_1 * 2) + 12) & 63;
  int stage_v_212_2 = ((pub_r001436_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((sec_r001436_15_1 + (pub_r001436_3_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((sec_r001436_15_2 + (pub_r001436_3_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_179_1 + (pub_r001436_15_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_179_2 + (pub_r001436_15_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((stage_v_35_1 + (pub_r001436_10_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_35_2 + (pub_r001436_10_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((stage_v_7_1 + (pub_r001436_7_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_7_2 + (pub_r001436_7_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_152_1 + (pub_r001436_9_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_152_2 + (pub_r001436_9_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_167_1 + (pub_r001436_12_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_167_2 + (pub_r001436_12_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_0_1 + (pub_r001436_7_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_0_2 + (pub_r001436_7_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_41_1 + (pub_r001436_19_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_41_2 + (pub_r001436_19_2 * 2)) + 665) & 127;
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
  int stage_v_221_1 = ((stage_v_192_1 + (pub_r001436_12_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_192_2 + (pub_r001436_12_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_60_1 + (pub_r001436_8_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_60_2 + (pub_r001436_8_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_26_1 + (pub_r001436_0_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_26_2 + (pub_r001436_0_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((sec_r001436_14_1 + (pub_r001436_12_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((sec_r001436_14_2 + (pub_r001436_12_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_88_1 + (pub_r001436_4_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_88_2 + (pub_r001436_4_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((stage_v_107_1 + (pub_r001436_0_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_107_2 + (pub_r001436_0_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((stage_v_2_1 + (pub_r001436_18_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_2_2 + (pub_r001436_18_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((stage_v_90_1 + (pub_r001436_4_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_90_2 + (pub_r001436_4_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((stage_v_201_1 + (pub_r001436_11_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((stage_v_201_2 + (pub_r001436_11_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001436_18_1 != sec_r001436_18_2);
  __CPROVER_assume(pub_r001436_15_1 == pub_r001436_15_2);
  __CPROVER_assume(pub_r001436_18_1 == pub_r001436_18_2);
  __CPROVER_assume(sec_r001436_12_1 != sec_r001436_12_2);
  __CPROVER_assume(pub_r001436_11_1 == pub_r001436_11_2);
  __CPROVER_assume(pub_r001436_13_1 == pub_r001436_13_2);
  __CPROVER_assume(sec_r001436_7_1 != sec_r001436_7_2);
  __CPROVER_assume(sec_r001436_1_1 != sec_r001436_1_2);
  __CPROVER_assume(sec_r001436_8_1 != sec_r001436_8_2);
  __CPROVER_assume(pub_r001436_19_1 == pub_r001436_19_2);
  __CPROVER_assume(sec_r001436_15_1 != sec_r001436_15_2);
  __CPROVER_assume(sec_r001436_13_1 != sec_r001436_13_2);
  __CPROVER_assume(pub_r001436_17_1 == pub_r001436_17_2);
  __CPROVER_assume(sec_r001436_4_1 != sec_r001436_4_2);
  __CPROVER_assume(sec_r001436_19_1 != sec_r001436_19_2);
  __CPROVER_assume(sec_r001436_10_1 != sec_r001436_10_2);
  __CPROVER_assume(pub_r001436_6_1 == pub_r001436_6_2);
  __CPROVER_assume(sec_r001436_9_1 != sec_r001436_9_2);
  __CPROVER_assume(pub_r001436_10_1 == pub_r001436_10_2);
  __CPROVER_assume(sec_r001436_14_1 != sec_r001436_14_2);
  __CPROVER_assume(pub_r001436_0_1 == pub_r001436_0_2);
  __CPROVER_assume(pub_r001436_3_1 == pub_r001436_3_2);
  __CPROVER_assume(sec_r001436_2_1 != sec_r001436_2_2);
  __CPROVER_assume(sec_r001436_6_1 != sec_r001436_6_2);
  __CPROVER_assume(pub_r001436_2_1 == pub_r001436_2_2);
  __CPROVER_assume(pub_r001436_9_1 == pub_r001436_9_2);
  __CPROVER_assume(pub_r001436_16_1 == pub_r001436_16_2);
  __CPROVER_assume(pub_r001436_7_1 == pub_r001436_7_2);
  __CPROVER_assume(pub_r001436_12_1 == pub_r001436_12_2);
  __CPROVER_assume(pub_r001436_5_1 == pub_r001436_5_2);
  __CPROVER_assume(pub_r001436_8_1 == pub_r001436_8_2);
  __CPROVER_assume(pub_r001436_1_1 == pub_r001436_1_2);
  __CPROVER_assume(pub_r001436_14_1 == pub_r001436_14_2);
  __CPROVER_assume(sec_r001436_11_1 != sec_r001436_11_2);
  __CPROVER_assume(pub_r001436_20_1 == pub_r001436_20_2);
  __CPROVER_assume(sec_r001436_16_1 != sec_r001436_16_2);
  __CPROVER_assume(sec_r001436_17_1 != sec_r001436_17_2);
  __CPROVER_assume(sec_r001436_3_1 != sec_r001436_3_2);
  __CPROVER_assume(sec_r001436_0_1 != sec_r001436_0_2);
  __CPROVER_assume(sec_r001436_5_1 != sec_r001436_5_2);
  __CPROVER_assume(pub_r001436_4_1 == pub_r001436_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.head == st_var_0_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
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
  assert(stage_v_225_1 == stage_v_225_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(stage_v_229_1 == stage_v_229_2);
}


