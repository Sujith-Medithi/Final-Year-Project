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
struct StreamBuffer_R000095_9513_0
{
  unsigned char checksum;
  int state;
  short tail;
  short head;
  int buffer[3];
};
struct AudioFrame_R000095_9513_1
{
  int sample_rate;
  short envelope;
  unsigned char channels;
  int peak;
  unsigned char gain;
  int buffer[3];
};
struct MatrixBlock_R000095_9513_2
{
  int scale;
  int trace;
  unsigned char density;
  int dim;
  int stride;
  int buffer[3];
};
union TelemetryField_R000095_9513_0
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
void fn_R000095_9513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000095_9513_1 st_1 = {0};
  struct AudioFrame_R000095_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int tracker_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_19_1 > 34)
  {
    acc_1 = ((acc_1 + (tracker_19_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_19_2 > 34)
  {
    acc_2 = ((acc_2 + (tracker_19_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_59_1) & 63;
  aux_2 = (aux_2 + margin_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_83_1 = local_arr_1[aux_1 % 3];
  int tally_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_19_1 == tracker_19_2);
  assert(margin_59_1 == margin_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_83_1 == tally_83_2);
}

int fn_R000095_9513_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000095_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int tracker_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_19 > 34)
  {
    acc = ((acc + (tracker_19 * 2)) + 5) & 127;
    aux ^= tracker_19 & 15;
  }
  else
  {
    acc = ((acc - tracker_19) + 11) & 127;
    aux += 3;
  }
  int margin_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_59) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_83 = local_arr[aux % 3];
  acc = (acc + (tally_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000095_9513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st_1 = {0};
  struct MatrixBlock_R000095_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int bound_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_77_1) & 63;
  aux_2 = (aux_2 + bound_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_20_1)
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

  switch (anchor_20_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_77_1 == bound_77_2);
  assert(anchor_20_1 == anchor_20_2);
}

int fn_R000095_9513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int bound_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_77) & 63;
  acc ^= aux;
  int anchor_20 = (aux + st.buffer[1]) & 3;
  switch (anchor_20)
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

void fn_R000095_9513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000095_9513_1 st_1 = {0};
  struct AudioFrame_R000095_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_26_1)
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

  switch (accumulator_26_2)
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

  int scale_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_58_1 > 35)
  {
    acc_1 = ((acc_1 + (scale_58_1 * 2)) + 5) & 127;
    aux_1 ^= scale_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_58_2 > 35)
  {
    acc_2 = ((acc_2 + (scale_58_2 * 2)) + 5) & 127;
    aux_2 ^= scale_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_26_1 == accumulator_26_2);
  assert(scale_58_1 == scale_58_2);
}

int fn_R000095_9513_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000095_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_26 = (aux + st.buffer[1]) & 3;
  switch (accumulator_26)
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

  int scale_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_58 > 35)
  {
    acc = ((acc + (scale_58 * 2)) + 5) & 127;
    aux ^= scale_58 & 15;
  }
  else
  {
    acc = ((acc - scale_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000095_9513_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st_1 = {0};
  struct MatrixBlock_R000095_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_95_1 = local_arr_1[aux_1 % 3];
  int anchor_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_95_2 * 2)) & 127;
  int tracker_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_76_1) & 63;
  aux_2 = (aux_2 + tracker_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_95_1 == anchor_95_2);
  assert(tracker_76_1 == tracker_76_2);
}

int fn_R000095_9513_3(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int anchor_95 = local_arr[aux % 3];
  acc = (acc + (anchor_95 * 2)) & 127;
  int tracker_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_76) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000095_9513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000095_9513_0 st_1 = {0};
  struct StreamBuffer_R000095_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_90_1 = local_arr_1[aux_1 % 3];
  int damping_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_90_2 * 2)) & 127;
  int phase_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_71_1 > 32)
  {
    acc_1 = ((acc_1 + (phase_71_1 * 2)) + 5) & 127;
    aux_1 ^= phase_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_71_2 > 32)
  {
    acc_2 = ((acc_2 + (phase_71_2 * 2)) + 5) & 127;
    aux_2 ^= phase_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_29_1)
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

  switch (bound_29_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_90_1 == damping_90_2);
  assert(phase_71_1 == phase_71_2);
  assert(bound_29_1 == bound_29_2);
}

int fn_R000095_9513_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000095_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int damping_90 = local_arr[aux % 3];
  acc = (acc + (damping_90 * 2)) & 127;
  int phase_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_71 > 32)
  {
    acc = ((acc + (phase_71 * 2)) + 5) & 127;
    aux ^= phase_71 & 15;
  }
  else
  {
    acc = ((acc - phase_71) + 11) & 127;
    aux += 3;
  }
  int bound_29 = (aux + st.buffer[1]) & 3;
  switch (bound_29)
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

void fn_R000095_9513_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000095_9513_0 st_1 = {0};
  struct StreamBuffer_R000095_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_68_1 = local_arr_1[aux_1 % 3];
  int checksum_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_68_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_83_1)
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

  switch (margin_83_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_68_1 == checksum_68_2);
  assert(margin_83_1 == margin_83_2);
}

int fn_R000095_9513_5(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000095_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int checksum_68 = local_arr[aux % 3];
  acc = (acc + (checksum_68 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_83 = (aux + st.buffer[1]) & 3;
  switch (margin_83)
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

void fn_R000095_9513_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000095_9513_0 st_1 = {0};
  struct StreamBuffer_R000095_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int residue_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_48_1) & 63;
  aux_2 = (aux_2 + residue_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_60_1 = local_arr_1[aux_1 % 3];
  int anchor_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_48_1 == residue_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_60_1 == anchor_60_2);
}

int fn_R000095_9513_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000095_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int residue_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_60 = local_arr[aux % 3];
  acc = (acc + (anchor_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000095_9513_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000095_9513_0 st_1 = {0};
  struct StreamBuffer_R000095_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int factor_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_21_1)
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

  switch (factor_21_2)
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

  int window_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_45_1) & 63;
  aux_2 = (aux_2 + window_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_21_1 == factor_21_2);
  assert(window_45_1 == window_45_2);
}

int fn_R000095_9513_7(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000095_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int factor_21 = (aux + st.buffer[1]) & 3;
  switch (factor_21)
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

  int window_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000095_9513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st_1 = {0};
  struct MatrixBlock_R000095_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_33_1 = local_arr_1[aux_1 % 3];
  int coefficient_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_33_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_61_1)
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

  switch (bound_61_2)
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

  int tally_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_49_1 > 17)
  {
    acc_1 = ((acc_1 + (tally_49_1 * 2)) + 5) & 127;
    aux_1 ^= tally_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_49_2 > 17)
  {
    acc_2 = ((acc_2 + (tally_49_2 * 2)) + 5) & 127;
    aux_2 ^= tally_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_33_1 == coefficient_33_2);
  assert(bound_61_1 == bound_61_2);
  assert(tally_49_1 == tally_49_2);
}

int fn_R000095_9513_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int coefficient_33 = local_arr[aux % 3];
  acc = (acc + (coefficient_33 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_61 = (aux + st.buffer[1]) & 3;
  switch (bound_61)
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

  int tally_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_49 > 17)
  {
    acc = ((acc + (tally_49 * 2)) + 5) & 127;
    aux ^= tally_49 & 15;
  }
  else
  {
    acc = ((acc - tally_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000095_9513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000095_9513_1 st_1 = {0};
  struct AudioFrame_R000095_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int checksum_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_14_1)
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

  switch (checksum_14_2)
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
  int metric_70_1 = local_arr_1[aux_1 % 3];
  int metric_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_70_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_21_1 > 13)
  {
    acc_1 = ((acc_1 + (quantum_21_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_21_2 > 13)
  {
    acc_2 = ((acc_2 + (quantum_21_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_14_1 == checksum_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_70_1 == metric_70_2);
  assert(quantum_21_1 == quantum_21_2);
}

int fn_R000095_9513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000095_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int checksum_14 = (aux + st.buffer[1]) & 3;
  switch (checksum_14)
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
  int metric_70 = local_arr[aux % 3];
  acc = (acc + (metric_70 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_21 > 13)
  {
    acc = ((acc + (quantum_21 * 2)) + 5) & 127;
    aux ^= quantum_21 & 15;
  }
  else
  {
    acc = ((acc - quantum_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000095_9513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st_1 = {0};
  struct MatrixBlock_R000095_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int factor_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_18_1 > 32)
  {
    acc_1 = ((acc_1 + (factor_18_1 * 2)) + 5) & 127;
    aux_1 ^= factor_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_18_2 > 32)
  {
    acc_2 = ((acc_2 + (factor_18_2 * 2)) + 5) & 127;
    aux_2 ^= factor_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_26_1) & 63;
  aux_2 = (aux_2 + mask_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_18_1 == factor_18_2);
  assert(mask_26_1 == mask_26_2);
}

int fn_R000095_9513_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int factor_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_18 > 32)
  {
    acc = ((acc + (factor_18 * 2)) + 5) & 127;
    aux ^= factor_18 & 15;
  }
  else
  {
    acc = ((acc - factor_18) + 11) & 127;
    aux += 3;
  }
  int mask_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000095_9513_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st_1 = {0};
  struct MatrixBlock_R000095_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int scale_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_63_1 > 43)
  {
    acc_1 = ((acc_1 + (scale_63_1 * 2)) + 5) & 127;
    aux_1 ^= scale_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_63_2 > 43)
  {
    acc_2 = ((acc_2 + (scale_63_2 * 2)) + 5) & 127;
    aux_2 ^= scale_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_68_1 = local_arr_1[aux_1 % 3];
  int residue_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_68_2 * 2)) & 127;
  int margin_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_10_1)
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

  switch (margin_10_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_63_1 == scale_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_68_1 == residue_68_2);
  assert(margin_10_1 == margin_10_2);
}

int fn_R000095_9513_11(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int scale_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_63 > 43)
  {
    acc = ((acc + (scale_63 * 2)) + 5) & 127;
    aux ^= scale_63 & 15;
  }
  else
  {
    acc = ((acc - scale_63) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_68 = local_arr[aux % 3];
  acc = (acc + (residue_68 * 2)) & 127;
  int margin_10 = (aux + st.buffer[1]) & 3;
  switch (margin_10)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000095_9513_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000095_9513_1 st_1 = {0};
  struct AudioFrame_R000095_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_33_1 = local_arr_1[aux_1 % 3];
  int index_reg_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_33_2 * 2)) & 127;
  int sample_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_64_1) & 63;
  aux_2 = (aux_2 + sample_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_22_1 > 16)
  {
    acc_1 = ((acc_1 + (coefficient_22_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_22_2 > 16)
  {
    acc_2 = ((acc_2 + (coefficient_22_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_33_1 == index_reg_33_2);
  assert(sample_64_1 == sample_64_2);
  assert(coefficient_22_1 == coefficient_22_2);
}

int fn_R000095_9513_12(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000095_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_33 = local_arr[aux % 3];
  acc = (acc + (index_reg_33 * 2)) & 127;
  int sample_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_64) & 63;
  acc ^= aux;
  int coefficient_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_22 > 16)
  {
    acc = ((acc + (coefficient_22 * 2)) + 5) & 127;
    aux ^= coefficient_22 & 15;
  }
  else
  {
    acc = ((acc - coefficient_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000095_9513_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st_1 = {0};
  struct MatrixBlock_R000095_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_55_1 = local_arr_1[aux_1 % 3];
  int metric_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_55_1 == metric_55_2);
}

int fn_R000095_9513_13(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_55 = local_arr[aux % 3];
  acc = (acc + (metric_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000095_9513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st_1 = {0};
  struct MatrixBlock_R000095_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_43_1 > 28)
  {
    acc_1 = ((acc_1 + (threshold_43_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_43_2 > 28)
  {
    acc_2 = ((acc_2 + (threshold_43_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_45_1)
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

  switch (threshold_45_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_43_1 == threshold_43_2);
  assert(threshold_45_1 == threshold_45_2);
}

int fn_R000095_9513_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000095_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_43 > 28)
  {
    acc = ((acc + (threshold_43 * 2)) + 5) & 127;
    aux ^= threshold_43 & 15;
  }
  else
  {
    acc = ((acc - threshold_43) + 11) & 127;
    aux += 3;
  }
  int threshold_45 = (aux + st.buffer[1]) & 3;
  switch (threshold_45)
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

void main()
{
  int sec_r000095_0_1;
  int sec_r000095_0_2;
  int sec_r000095_1_1;
  int sec_r000095_1_2;
  int sec_r000095_2_1;
  int sec_r000095_2_2;
  int sec_r000095_3_1;
  int sec_r000095_3_2;
  int sec_r000095_4_1;
  int sec_r000095_4_2;
  int sec_r000095_5_1;
  int sec_r000095_5_2;
  int sec_r000095_6_1;
  int sec_r000095_6_2;
  int sec_r000095_7_1;
  int sec_r000095_7_2;
  int sec_r000095_8_1;
  int sec_r000095_8_2;
  int sec_r000095_9_1;
  int sec_r000095_9_2;
  int sec_r000095_10_1;
  int sec_r000095_10_2;
  int sec_r000095_11_1;
  int sec_r000095_11_2;
  int sec_r000095_12_1;
  int sec_r000095_12_2;
  int sec_r000095_13_1;
  int sec_r000095_13_2;
  int sec_r000095_14_1;
  int sec_r000095_14_2;
  int sec_r000095_15_1;
  int sec_r000095_15_2;
  int sec_r000095_16_1;
  int sec_r000095_16_2;
  int sec_r000095_17_1;
  int sec_r000095_17_2;
  int sec_r000095_18_1;
  int sec_r000095_18_2;
  int pub_r000095_0_1;
  int pub_r000095_0_2;
  int pub_r000095_1_1;
  int pub_r000095_1_2;
  int pub_r000095_2_1;
  int pub_r000095_2_2;
  int pub_r000095_3_1;
  int pub_r000095_3_2;
  int pub_r000095_4_1;
  int pub_r000095_4_2;
  int pub_r000095_5_1;
  int pub_r000095_5_2;
  int pub_r000095_6_1;
  int pub_r000095_6_2;
  int pub_r000095_7_1;
  int pub_r000095_7_2;
  int pub_r000095_8_1;
  int pub_r000095_8_2;
  int pub_r000095_9_1;
  int pub_r000095_9_2;
  int pub_r000095_10_1;
  int pub_r000095_10_2;
  int pub_r000095_11_1;
  int pub_r000095_11_2;
  int pub_r000095_12_1;
  int pub_r000095_12_2;
  int pub_r000095_13_1;
  int pub_r000095_13_2;
  int pub_r000095_14_1;
  int pub_r000095_14_2;
  int pub_r000095_15_1;
  int pub_r000095_15_2;
  int pub_r000095_16_1;
  int pub_r000095_16_2;
  int pub_r000095_17_1;
  int pub_r000095_17_2;
  int pub_r000095_18_1;
  int pub_r000095_18_2;
  int pub_r000095_19_1;
  int pub_r000095_19_2;
  int pub_r000095_20_1;
  int pub_r000095_20_2;
  int pub_r000095_21_1;
  int pub_r000095_21_2;
  int pub_r000095_22_1;
  int pub_r000095_22_2;
  int pub_r000095_23_1;
  int pub_r000095_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000095_0_1 >= (-100)) && (pub_r000095_0_1 <= 100));
  __CPROVER_assume((pub_r000095_0_2 >= (-100)) && (pub_r000095_0_2 <= 100));
  __CPROVER_assume((pub_r000095_1_1 >= (-100)) && (pub_r000095_1_1 <= 100));
  __CPROVER_assume((pub_r000095_1_2 >= (-100)) && (pub_r000095_1_2 <= 100));
  __CPROVER_assume((pub_r000095_2_1 >= (-100)) && (pub_r000095_2_1 <= 100));
  __CPROVER_assume((pub_r000095_2_2 >= (-100)) && (pub_r000095_2_2 <= 100));
  __CPROVER_assume((pub_r000095_3_1 >= (-100)) && (pub_r000095_3_1 <= 100));
  __CPROVER_assume((pub_r000095_3_2 >= (-100)) && (pub_r000095_3_2 <= 100));
  __CPROVER_assume((pub_r000095_4_1 >= (-100)) && (pub_r000095_4_1 <= 100));
  __CPROVER_assume((pub_r000095_4_2 >= (-100)) && (pub_r000095_4_2 <= 100));
  __CPROVER_assume((pub_r000095_5_1 >= (-100)) && (pub_r000095_5_1 <= 100));
  __CPROVER_assume((pub_r000095_5_2 >= (-100)) && (pub_r000095_5_2 <= 100));
  __CPROVER_assume((pub_r000095_6_1 >= (-100)) && (pub_r000095_6_1 <= 100));
  __CPROVER_assume((pub_r000095_6_2 >= (-100)) && (pub_r000095_6_2 <= 100));
  __CPROVER_assume((pub_r000095_7_1 >= (-100)) && (pub_r000095_7_1 <= 100));
  __CPROVER_assume((pub_r000095_7_2 >= (-100)) && (pub_r000095_7_2 <= 100));
  __CPROVER_assume((pub_r000095_8_1 >= (-100)) && (pub_r000095_8_1 <= 100));
  __CPROVER_assume((pub_r000095_8_2 >= (-100)) && (pub_r000095_8_2 <= 100));
  __CPROVER_assume((pub_r000095_9_1 >= (-100)) && (pub_r000095_9_1 <= 100));
  __CPROVER_assume((pub_r000095_9_2 >= (-100)) && (pub_r000095_9_2 <= 100));
  __CPROVER_assume((pub_r000095_10_1 >= (-100)) && (pub_r000095_10_1 <= 100));
  __CPROVER_assume((pub_r000095_10_2 >= (-100)) && (pub_r000095_10_2 <= 100));
  __CPROVER_assume((pub_r000095_11_1 >= (-100)) && (pub_r000095_11_1 <= 100));
  __CPROVER_assume((pub_r000095_11_2 >= (-100)) && (pub_r000095_11_2 <= 100));
  __CPROVER_assume((pub_r000095_12_1 >= (-100)) && (pub_r000095_12_1 <= 100));
  __CPROVER_assume((pub_r000095_12_2 >= (-100)) && (pub_r000095_12_2 <= 100));
  __CPROVER_assume((pub_r000095_13_1 >= (-100)) && (pub_r000095_13_1 <= 100));
  __CPROVER_assume((pub_r000095_13_2 >= (-100)) && (pub_r000095_13_2 <= 100));
  __CPROVER_assume((pub_r000095_14_1 >= (-100)) && (pub_r000095_14_1 <= 100));
  __CPROVER_assume((pub_r000095_14_2 >= (-100)) && (pub_r000095_14_2 <= 100));
  __CPROVER_assume((pub_r000095_15_1 >= (-100)) && (pub_r000095_15_1 <= 100));
  __CPROVER_assume((pub_r000095_15_2 >= (-100)) && (pub_r000095_15_2 <= 100));
  __CPROVER_assume((pub_r000095_16_1 >= (-100)) && (pub_r000095_16_1 <= 100));
  __CPROVER_assume((pub_r000095_16_2 >= (-100)) && (pub_r000095_16_2 <= 100));
  __CPROVER_assume((pub_r000095_17_1 >= (-100)) && (pub_r000095_17_1 <= 100));
  __CPROVER_assume((pub_r000095_17_2 >= (-100)) && (pub_r000095_17_2 <= 100));
  __CPROVER_assume((pub_r000095_18_1 >= (-100)) && (pub_r000095_18_1 <= 100));
  __CPROVER_assume((pub_r000095_18_2 >= (-100)) && (pub_r000095_18_2 <= 100));
  __CPROVER_assume((pub_r000095_19_1 >= (-100)) && (pub_r000095_19_1 <= 100));
  __CPROVER_assume((pub_r000095_19_2 >= (-100)) && (pub_r000095_19_2 <= 100));
  __CPROVER_assume((pub_r000095_20_1 >= (-100)) && (pub_r000095_20_1 <= 100));
  __CPROVER_assume((pub_r000095_20_2 >= (-100)) && (pub_r000095_20_2 <= 100));
  __CPROVER_assume((pub_r000095_21_1 >= (-100)) && (pub_r000095_21_1 <= 100));
  __CPROVER_assume((pub_r000095_21_2 >= (-100)) && (pub_r000095_21_2 <= 100));
  __CPROVER_assume((pub_r000095_22_1 >= (-100)) && (pub_r000095_22_1 <= 100));
  __CPROVER_assume((pub_r000095_22_2 >= (-100)) && (pub_r000095_22_2 <= 100));
  __CPROVER_assume((pub_r000095_23_1 >= (-100)) && (pub_r000095_23_1 <= 100));
  __CPROVER_assume((pub_r000095_23_2 >= (-100)) && (pub_r000095_23_2 <= 100));
  __CPROVER_assume((sec_r000095_0_1 >= 0) && (sec_r000095_0_1 <= 255));
  __CPROVER_assume((sec_r000095_0_2 >= 0) && (sec_r000095_0_2 <= 255));
  __CPROVER_assume((sec_r000095_1_1 >= 0) && (sec_r000095_1_1 <= 255));
  __CPROVER_assume((sec_r000095_1_2 >= 0) && (sec_r000095_1_2 <= 255));
  __CPROVER_assume((sec_r000095_2_1 >= 0) && (sec_r000095_2_1 <= 255));
  __CPROVER_assume((sec_r000095_2_2 >= 0) && (sec_r000095_2_2 <= 255));
  __CPROVER_assume((sec_r000095_3_1 >= 0) && (sec_r000095_3_1 <= 255));
  __CPROVER_assume((sec_r000095_3_2 >= 0) && (sec_r000095_3_2 <= 255));
  __CPROVER_assume((sec_r000095_4_1 >= 0) && (sec_r000095_4_1 <= 255));
  __CPROVER_assume((sec_r000095_4_2 >= 0) && (sec_r000095_4_2 <= 255));
  __CPROVER_assume((sec_r000095_5_1 >= 0) && (sec_r000095_5_1 <= 255));
  __CPROVER_assume((sec_r000095_5_2 >= 0) && (sec_r000095_5_2 <= 255));
  __CPROVER_assume((sec_r000095_6_1 >= 0) && (sec_r000095_6_1 <= 255));
  __CPROVER_assume((sec_r000095_6_2 >= 0) && (sec_r000095_6_2 <= 255));
  __CPROVER_assume((sec_r000095_7_1 >= 0) && (sec_r000095_7_1 <= 255));
  __CPROVER_assume((sec_r000095_7_2 >= 0) && (sec_r000095_7_2 <= 255));
  __CPROVER_assume((sec_r000095_8_1 >= 0) && (sec_r000095_8_1 <= 255));
  __CPROVER_assume((sec_r000095_8_2 >= 0) && (sec_r000095_8_2 <= 255));
  __CPROVER_assume((sec_r000095_9_1 >= 0) && (sec_r000095_9_1 <= 255));
  __CPROVER_assume((sec_r000095_9_2 >= 0) && (sec_r000095_9_2 <= 255));
  __CPROVER_assume((sec_r000095_10_1 >= 0) && (sec_r000095_10_1 <= 255));
  __CPROVER_assume((sec_r000095_10_2 >= 0) && (sec_r000095_10_2 <= 255));
  __CPROVER_assume((sec_r000095_11_1 >= 0) && (sec_r000095_11_1 <= 255));
  __CPROVER_assume((sec_r000095_11_2 >= 0) && (sec_r000095_11_2 <= 255));
  __CPROVER_assume((sec_r000095_12_1 >= 0) && (sec_r000095_12_1 <= 255));
  __CPROVER_assume((sec_r000095_12_2 >= 0) && (sec_r000095_12_2 <= 255));
  __CPROVER_assume((sec_r000095_13_1 >= 0) && (sec_r000095_13_1 <= 255));
  __CPROVER_assume((sec_r000095_13_2 >= 0) && (sec_r000095_13_2 <= 255));
  __CPROVER_assume((sec_r000095_14_1 >= 0) && (sec_r000095_14_1 <= 255));
  __CPROVER_assume((sec_r000095_14_2 >= 0) && (sec_r000095_14_2 <= 255));
  __CPROVER_assume((sec_r000095_15_1 >= 0) && (sec_r000095_15_1 <= 255));
  __CPROVER_assume((sec_r000095_15_2 >= 0) && (sec_r000095_15_2 <= 255));
  __CPROVER_assume((sec_r000095_16_1 >= 0) && (sec_r000095_16_1 <= 255));
  __CPROVER_assume((sec_r000095_16_2 >= 0) && (sec_r000095_16_2 <= 255));
  __CPROVER_assume((sec_r000095_17_1 >= 0) && (sec_r000095_17_1 <= 255));
  __CPROVER_assume((sec_r000095_17_2 >= 0) && (sec_r000095_17_2 <= 255));
  __CPROVER_assume((sec_r000095_18_1 >= 0) && (sec_r000095_18_1 <= 255));
  __CPROVER_assume((sec_r000095_18_2 >= 0) && (sec_r000095_18_2 <= 255));
  struct StreamBuffer_R000095_9513_0 st_var_0_1 = {0};
  struct StreamBuffer_R000095_9513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000095_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000095_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000095_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000095_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000095_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000095_0_2 + 7) & 15;
  struct AudioFrame_R000095_9513_1 st_var_1_1 = {0};
  struct AudioFrame_R000095_9513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000095_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000095_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000095_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000095_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000095_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000095_0_2 + 9) & 15;
  struct MatrixBlock_R000095_9513_2 st_var_2_1 = {0};
  struct MatrixBlock_R000095_9513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000095_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000095_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000095_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000095_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000095_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000095_0_2 + 11) & 15;
  union TelemetryField_R000095_9513_0 u_var_1;
  union TelemetryField_R000095_9513_0 u_var_2;
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
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((st_var_1_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_1_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 44)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 44)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (st_var_1_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_1_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = (st_var_2_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_2_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
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
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 52)
    {
      chk_sum_1 ^= stage_v_18_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_18_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 52)
    {
      chk_sum_2 ^= stage_v_18_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
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
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
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

  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 33) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = (st_var_0_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_0_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = (((sec_r000095_10_1 << 1) ^ (sec_r000095_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_40_2 = (((sec_r000095_10_2 << 1) ^ (sec_r000095_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = (((stage_v_40_1 << 2) ^ (sec_r000095_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_41_2 = (((stage_v_40_2 << 2) ^ (sec_r000095_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = (((sec_r000095_12_1 << 2) ^ (sec_r000095_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_42_2 = (((sec_r000095_12_2 << 2) ^ (sec_r000095_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = (((sec_r000095_3_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_43_2 = (((sec_r000095_3_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = (((stage_v_42_1 << 1) ^ (sec_r000095_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_44_2 = (((stage_v_42_2 << 1) ^ (sec_r000095_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = (((stage_v_44_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_45_2 = (((stage_v_44_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = (((stage_v_44_1 << 2) ^ (sec_r000095_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_46_2 = (((stage_v_44_2 << 2) ^ (sec_r000095_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = (((sec_r000095_17_1 << 1) ^ (sec_r000095_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_47_2 = (((sec_r000095_17_2 << 1) ^ (sec_r000095_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = (((sec_r000095_15_1 << 1) ^ (sec_r000095_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_48_2 = (((sec_r000095_15_2 << 1) ^ (sec_r000095_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = (((stage_v_48_1 << 1) ^ (sec_r000095_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_49_2 = (((stage_v_48_2 << 1) ^ (sec_r000095_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = (((sec_r000095_0_1 << 2) ^ (sec_r000095_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_50_2 = (((sec_r000095_0_2 << 2) ^ (sec_r000095_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = (((stage_v_40_1 << 1) ^ (sec_r000095_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_51_2 = (((stage_v_40_2 << 1) ^ (sec_r000095_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = (((stage_v_45_1 << 1) ^ (sec_r000095_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_52_2 = (((stage_v_45_2 << 1) ^ (sec_r000095_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = (((stage_v_40_1 << 2) ^ (sec_r000095_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_53_2 = (((stage_v_40_2 << 2) ^ (sec_r000095_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = (((stage_v_44_1 << 2) ^ (sec_r000095_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_54_2 = (((stage_v_44_2 << 2) ^ (sec_r000095_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = (((stage_v_50_1 << 1) ^ (sec_r000095_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_55_2 = (((stage_v_50_2 << 1) ^ (sec_r000095_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = (((stage_v_49_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_56_2 = (((stage_v_49_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = (((stage_v_40_1 << 1) ^ (sec_r000095_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_57_2 = (((stage_v_40_2 << 1) ^ (sec_r000095_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = (((sec_r000095_7_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_58_2 = (((sec_r000095_7_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = (((stage_v_53_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_59_2 = (((stage_v_53_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = (((stage_v_44_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_60_2 = (((stage_v_44_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = (((stage_v_46_1 << 2) ^ (sec_r000095_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_61_2 = (((stage_v_46_2 << 2) ^ (sec_r000095_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = (((sec_r000095_7_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_62_2 = (((sec_r000095_7_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = (((stage_v_49_1 << 2) ^ (sec_r000095_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_63_2 = (((stage_v_49_2 << 2) ^ (sec_r000095_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = (((sec_r000095_2_1 << 2) ^ (sec_r000095_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_64_2 = (((sec_r000095_2_2 << 2) ^ (sec_r000095_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = (((stage_v_40_1 << 1) ^ (sec_r000095_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_65_2 = (((stage_v_40_2 << 1) ^ (sec_r000095_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = (((stage_v_49_1 << 1) ^ (sec_r000095_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_66_2 = (((stage_v_49_2 << 1) ^ (sec_r000095_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = (((stage_v_53_1 << 2) ^ (sec_r000095_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_67_2 = (((stage_v_53_2 << 2) ^ (sec_r000095_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = (((stage_v_64_1 << 2) ^ (sec_r000095_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_68_2 = (((stage_v_64_2 << 2) ^ (sec_r000095_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = (((stage_v_53_1 << 2) ^ (sec_r000095_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_69_2 = (((stage_v_53_2 << 2) ^ (sec_r000095_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = (((sec_r000095_0_1 << 2) ^ (sec_r000095_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_70_2 = (((sec_r000095_0_2 << 2) ^ (sec_r000095_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = (((stage_v_45_1 << 2) ^ (sec_r000095_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_71_2 = (((stage_v_45_2 << 2) ^ (sec_r000095_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = (((stage_v_61_1 << 2) ^ (sec_r000095_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_72_2 = (((stage_v_61_2 << 2) ^ (sec_r000095_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = (((stage_v_42_1 << 1) ^ (sec_r000095_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_73_2 = (((stage_v_42_2 << 1) ^ (sec_r000095_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = (((sec_r000095_2_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_74_2 = (((sec_r000095_2_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = (((stage_v_63_1 << 1) ^ (sec_r000095_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_75_2 = (((stage_v_63_2 << 1) ^ (sec_r000095_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = (((stage_v_45_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_76_2 = (((stage_v_45_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = (((stage_v_67_1 << 2) ^ (sec_r000095_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_77_2 = (((stage_v_67_2 << 2) ^ (sec_r000095_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = (((sec_r000095_12_1 << 1) ^ (sec_r000095_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_78_2 = (((sec_r000095_12_2 << 1) ^ (sec_r000095_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = (((sec_r000095_9_1 << 1) ^ (sec_r000095_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_79_2 = (((sec_r000095_9_2 << 1) ^ (sec_r000095_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = (((stage_v_73_1 << 1) ^ (sec_r000095_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_80_2 = (((stage_v_73_2 << 1) ^ (sec_r000095_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = (((stage_v_78_1 << 2) ^ (sec_r000095_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_81_2 = (((stage_v_78_2 << 2) ^ (sec_r000095_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = (((stage_v_71_1 << 1) ^ (sec_r000095_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_82_2 = (((stage_v_71_2 << 1) ^ (sec_r000095_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = (((stage_v_62_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_83_2 = (((stage_v_62_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_83_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_83_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = (((stage_v_54_1 << 1) ^ (sec_r000095_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_84_2 = (((stage_v_54_2 << 1) ^ (sec_r000095_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = (((stage_v_60_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_85_2 = (((stage_v_60_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = (((sec_r000095_6_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_86_2 = (((sec_r000095_6_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = (((sec_r000095_5_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_87_2 = (((sec_r000095_5_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = (((sec_r000095_15_1 << 1) ^ (sec_r000095_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_88_2 = (((sec_r000095_15_2 << 1) ^ (sec_r000095_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = (((stage_v_88_1 << 2) ^ (sec_r000095_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_89_2 = (((stage_v_88_2 << 2) ^ (sec_r000095_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = (((sec_r000095_4_1 << 1) ^ (sec_r000095_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_90_2 = (((sec_r000095_4_2 << 1) ^ (sec_r000095_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = (((sec_r000095_1_1 << 2) ^ (sec_r000095_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_91_2 = (((sec_r000095_1_2 << 2) ^ (sec_r000095_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = (((stage_v_79_1 << 1) ^ (sec_r000095_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_92_2 = (((stage_v_79_2 << 1) ^ (sec_r000095_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_92_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_92_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = (((stage_v_73_1 << 1) ^ (sec_r000095_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_93_2 = (((stage_v_73_2 << 1) ^ (sec_r000095_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = (((sec_r000095_17_1 << 2) ^ (sec_r000095_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_94_2 = (((sec_r000095_17_2 << 2) ^ (sec_r000095_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = (((sec_r000095_4_1 << 1) ^ (sec_r000095_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_95_2 = (((sec_r000095_4_2 << 1) ^ (sec_r000095_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = (((stage_v_72_1 << 1) ^ (sec_r000095_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_96_2 = (((stage_v_72_2 << 1) ^ (sec_r000095_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = (((sec_r000095_3_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_97_2 = (((sec_r000095_3_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = (((sec_r000095_15_1 << 2) ^ (sec_r000095_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_98_2 = (((sec_r000095_15_2 << 2) ^ (sec_r000095_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = (((sec_r000095_17_1 << 2) ^ (sec_r000095_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_99_2 = (((sec_r000095_17_2 << 2) ^ (sec_r000095_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = (((sec_r000095_18_1 << 1) ^ (sec_r000095_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_100_2 = (((sec_r000095_18_2 << 1) ^ (sec_r000095_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = (((stage_v_71_1 << 2) ^ (sec_r000095_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_101_2 = (((stage_v_71_2 << 2) ^ (sec_r000095_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = (((sec_r000095_12_1 << 2) ^ (sec_r000095_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_102_2 = (((sec_r000095_12_2 << 2) ^ (sec_r000095_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = (((sec_r000095_0_1 << 1) ^ (sec_r000095_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_103_2 = (((sec_r000095_0_2 << 1) ^ (sec_r000095_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = (((stage_v_49_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_104_2 = (((stage_v_49_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = (((stage_v_46_1 << 1) ^ (sec_r000095_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_105_2 = (((stage_v_46_2 << 1) ^ (sec_r000095_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_105_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_105_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = (((stage_v_102_1 << 2) ^ (sec_r000095_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_106_2 = (((stage_v_102_2 << 2) ^ (sec_r000095_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = (((stage_v_69_1 << 2) ^ (sec_r000095_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_107_2 = (((stage_v_69_2 << 2) ^ (sec_r000095_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = (((stage_v_82_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_108_2 = (((stage_v_82_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = (((stage_v_69_1 << 1) ^ (sec_r000095_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_109_2 = (((stage_v_69_2 << 1) ^ (sec_r000095_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = (((stage_v_95_1 << 1) ^ (sec_r000095_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_110_2 = (((stage_v_95_2 << 1) ^ (sec_r000095_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = (((sec_r000095_18_1 << 2) ^ (sec_r000095_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_111_2 = (((sec_r000095_18_2 << 2) ^ (sec_r000095_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = (((stage_v_52_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_112_2 = (((stage_v_52_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = (((stage_v_59_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_113_2 = (((stage_v_59_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = (((sec_r000095_5_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_114_2 = (((sec_r000095_5_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = (((stage_v_82_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_115_2 = (((stage_v_82_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = (((stage_v_52_1 << 2) ^ (sec_r000095_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_116_2 = (((stage_v_52_2 << 2) ^ (sec_r000095_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = (((stage_v_43_1 << 1) ^ (sec_r000095_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_117_2 = (((stage_v_43_2 << 1) ^ (sec_r000095_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = (((stage_v_113_1 << 2) ^ (sec_r000095_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_118_2 = (((stage_v_113_2 << 2) ^ (sec_r000095_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = (((stage_v_103_1 << 2) ^ (sec_r000095_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_119_2 = (((stage_v_103_2 << 2) ^ (sec_r000095_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = (((stage_v_62_1 << 2) ^ (sec_r000095_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_120_2 = (((stage_v_62_2 << 2) ^ (sec_r000095_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = (((stage_v_63_1 << 1) ^ (sec_r000095_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_121_2 = (((stage_v_63_2 << 1) ^ (sec_r000095_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = (((stage_v_94_1 << 1) ^ (sec_r000095_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_122_2 = (((stage_v_94_2 << 1) ^ (sec_r000095_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = (((stage_v_73_1 << 2) ^ (sec_r000095_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_123_2 = (((stage_v_73_2 << 2) ^ (sec_r000095_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = (((stage_v_113_1 << 1) ^ (sec_r000095_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_124_2 = (((stage_v_113_2 << 1) ^ (sec_r000095_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = (((sec_r000095_10_1 << 2) ^ (sec_r000095_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_125_2 = (((sec_r000095_10_2 << 2) ^ (sec_r000095_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = (((stage_v_54_1 << 1) ^ (sec_r000095_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_126_2 = (((stage_v_54_2 << 1) ^ (sec_r000095_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = (((sec_r000095_6_1 << 2) ^ (sec_r000095_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_127_2 = (((sec_r000095_6_2 << 2) ^ (sec_r000095_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = (((stage_v_44_1 << 2) ^ (sec_r000095_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_128_2 = (((stage_v_44_2 << 2) ^ (sec_r000095_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = (((stage_v_127_1 << 1) ^ (sec_r000095_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_129_2 = (((stage_v_127_2 << 1) ^ (sec_r000095_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = (((stage_v_102_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_130_2 = (((stage_v_102_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = (((stage_v_97_1 << 2) ^ (sec_r000095_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_131_2 = (((stage_v_97_2 << 2) ^ (sec_r000095_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = (((sec_r000095_3_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_132_2 = (((sec_r000095_3_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = (((stage_v_65_1 << 2) ^ (sec_r000095_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_133_2 = (((stage_v_65_2 << 2) ^ (sec_r000095_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = (((stage_v_65_1 << 1) ^ (sec_r000095_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_134_2 = (((stage_v_65_2 << 1) ^ (sec_r000095_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_134_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_134_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = (((sec_r000095_14_1 << 1) ^ (sec_r000095_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_135_2 = (((sec_r000095_14_2 << 1) ^ (sec_r000095_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = (((stage_v_99_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_136_2 = (((stage_v_99_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = (((stage_v_47_1 << 2) ^ (sec_r000095_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_137_2 = (((stage_v_47_2 << 2) ^ (sec_r000095_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = (((sec_r000095_7_1 << 2) ^ (sec_r000095_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_138_2 = (((sec_r000095_7_2 << 2) ^ (sec_r000095_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = (((sec_r000095_17_1 << 2) ^ (sec_r000095_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_139_2 = (((sec_r000095_17_2 << 2) ^ (sec_r000095_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = (((stage_v_95_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_140_2 = (((stage_v_95_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = (((sec_r000095_2_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_141_2 = (((sec_r000095_2_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_141_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_141_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = (((stage_v_137_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_142_2 = (((stage_v_137_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_142_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_142_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = (((stage_v_54_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_143_2 = (((stage_v_54_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = (((stage_v_82_1 << 2) ^ (sec_r000095_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_144_2 = (((stage_v_82_2 << 2) ^ (sec_r000095_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = (((sec_r000095_5_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_145_2 = (((sec_r000095_5_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = (((sec_r000095_6_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_146_2 = (((sec_r000095_6_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = (((stage_v_73_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_147_2 = (((stage_v_73_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = (((sec_r000095_7_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_148_2 = (((sec_r000095_7_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = (((stage_v_76_1 << 2) ^ (sec_r000095_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_149_2 = (((stage_v_76_2 << 2) ^ (sec_r000095_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = (((sec_r000095_13_1 << 2) ^ (sec_r000095_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_150_2 = (((sec_r000095_13_2 << 2) ^ (sec_r000095_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = (((stage_v_107_1 << 1) ^ (sec_r000095_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_151_2 = (((stage_v_107_2 << 1) ^ (sec_r000095_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = (((sec_r000095_1_1 << 1) ^ (sec_r000095_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_152_2 = (((sec_r000095_1_2 << 1) ^ (sec_r000095_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = (((stage_v_149_1 << 2) ^ (sec_r000095_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_153_2 = (((stage_v_149_2 << 2) ^ (sec_r000095_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = (((stage_v_62_1 << 1) ^ (sec_r000095_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_154_2 = (((stage_v_62_2 << 1) ^ (sec_r000095_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_154_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_154_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = (((stage_v_66_1 << 1) ^ (sec_r000095_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_155_2 = (((stage_v_66_2 << 1) ^ (sec_r000095_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = (((stage_v_57_1 << 1) ^ (sec_r000095_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_156_2 = (((stage_v_57_2 << 1) ^ (sec_r000095_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = (((stage_v_137_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_157_2 = (((stage_v_137_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = (((sec_r000095_2_1 << 2) ^ (sec_r000095_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_158_2 = (((sec_r000095_2_2 << 2) ^ (sec_r000095_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = (((stage_v_88_1 << 2) ^ (sec_r000095_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_159_2 = (((stage_v_88_2 << 2) ^ (sec_r000095_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = (((stage_v_97_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_160_2 = (((stage_v_97_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = (((sec_r000095_14_1 << 2) ^ (sec_r000095_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_161_2 = (((sec_r000095_14_2 << 2) ^ (sec_r000095_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = (((stage_v_59_1 << 2) ^ (sec_r000095_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_162_2 = (((stage_v_59_2 << 2) ^ (sec_r000095_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_162_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_162_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = (((stage_v_141_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_163_2 = (((stage_v_141_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = (((stage_v_155_1 << 1) ^ (sec_r000095_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_164_2 = (((stage_v_155_2 << 1) ^ (sec_r000095_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_164_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_164_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = (((sec_r000095_2_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_165_2 = (((sec_r000095_2_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = (((stage_v_94_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_166_2 = (((stage_v_94_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = (((stage_v_59_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_167_2 = (((stage_v_59_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = (((sec_r000095_10_1 << 1) ^ (sec_r000095_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_168_2 = (((sec_r000095_10_2 << 1) ^ (sec_r000095_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = (((stage_v_105_1 << 2) ^ (sec_r000095_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_169_2 = (((stage_v_105_2 << 2) ^ (sec_r000095_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = (((stage_v_102_1 << 2) ^ (sec_r000095_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_170_2 = (((stage_v_102_2 << 2) ^ (sec_r000095_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_170_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_170_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = (((stage_v_141_1 << 2) ^ (sec_r000095_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_171_2 = (((stage_v_141_2 << 2) ^ (sec_r000095_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = (((stage_v_135_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_172_2 = (((stage_v_135_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = (((stage_v_84_1 << 2) ^ (sec_r000095_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_173_2 = (((stage_v_84_2 << 2) ^ (sec_r000095_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = (((stage_v_83_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_174_2 = (((stage_v_83_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_174_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_174_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = (((stage_v_68_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_175_2 = (((stage_v_68_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = (((stage_v_125_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_176_2 = (((stage_v_125_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_176_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_176_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = (((stage_v_44_1 << 1) ^ (sec_r000095_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_177_2 = (((stage_v_44_2 << 1) ^ (sec_r000095_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = (((sec_r000095_1_1 << 2) ^ (sec_r000095_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_178_2 = (((sec_r000095_1_2 << 2) ^ (sec_r000095_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_178_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_178_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = (((stage_v_162_1 << 2) ^ (sec_r000095_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_179_2 = (((stage_v_162_2 << 2) ^ (sec_r000095_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_179_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_179_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = (((stage_v_75_1 << 1) ^ (sec_r000095_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_180_2 = (((stage_v_75_2 << 1) ^ (sec_r000095_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_180_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_180_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = (((stage_v_105_1 << 2) ^ (sec_r000095_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_181_2 = (((stage_v_105_2 << 2) ^ (sec_r000095_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = (((stage_v_140_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_182_2 = (((stage_v_140_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_182_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_182_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = (((stage_v_163_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_183_2 = (((stage_v_163_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_183_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_183_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = (((sec_r000095_0_1 << 1) ^ (sec_r000095_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_184_2 = (((sec_r000095_0_2 << 1) ^ (sec_r000095_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = (((stage_v_78_1 << 2) ^ (sec_r000095_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_185_2 = (((stage_v_78_2 << 2) ^ (sec_r000095_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_185_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_185_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = (((stage_v_158_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_186_2 = (((stage_v_158_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_186_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_186_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = (((stage_v_50_1 << 1) ^ (sec_r000095_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_187_2 = (((stage_v_50_2 << 1) ^ (sec_r000095_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_187_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_187_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = (((sec_r000095_10_1 << 2) ^ (sec_r000095_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_188_2 = (((sec_r000095_10_2 << 2) ^ (sec_r000095_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_188_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_188_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = (((stage_v_44_1 << 2) ^ (sec_r000095_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_189_2 = (((stage_v_44_2 << 2) ^ (sec_r000095_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_189_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_189_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = (((sec_r000095_18_1 << 1) ^ (sec_r000095_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_190_2 = (((sec_r000095_18_2 << 1) ^ (sec_r000095_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_190_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_190_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = (((stage_v_174_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_191_2 = (((stage_v_174_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_191_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_191_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = (((stage_v_143_1 << 1) ^ (sec_r000095_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_192_2 = (((stage_v_143_2 << 1) ^ (sec_r000095_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_192_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_192_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = (((stage_v_92_1 << 1) ^ (sec_r000095_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_193_2 = (((stage_v_92_2 << 1) ^ (sec_r000095_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_193_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_193_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = (((sec_r000095_6_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_194_2 = (((sec_r000095_6_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_194_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_194_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = (((stage_v_192_1 << 1) ^ (sec_r000095_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_195_2 = (((stage_v_192_2 << 1) ^ (sec_r000095_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_195_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_195_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = (((sec_r000095_2_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_196_2 = (((sec_r000095_2_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_196_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_196_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = (((stage_v_64_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_197_2 = (((stage_v_64_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_197_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_197_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = (((stage_v_74_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_198_2 = (((stage_v_74_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_198_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_198_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = (((sec_r000095_2_1 << 2) ^ (sec_r000095_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_199_2 = (((sec_r000095_2_2 << 2) ^ (sec_r000095_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_199_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_199_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = (((sec_r000095_15_1 << 2) ^ (sec_r000095_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_200_2 = (((sec_r000095_15_2 << 2) ^ (sec_r000095_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_200_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_200_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = (((stage_v_189_1 << 2) ^ (sec_r000095_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_201_2 = (((stage_v_189_2 << 2) ^ (sec_r000095_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_201_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_201_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = (((stage_v_72_1 << 1) ^ (sec_r000095_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_202_2 = (((stage_v_72_2 << 1) ^ (sec_r000095_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_202_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_202_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = (((sec_r000095_3_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_203_2 = (((sec_r000095_3_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_203_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_203_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = (((sec_r000095_12_1 << 1) ^ (sec_r000095_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_204_2 = (((sec_r000095_12_2 << 1) ^ (sec_r000095_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_204_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_204_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = (((stage_v_132_1 << 2) ^ (sec_r000095_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_205_2 = (((stage_v_132_2 << 2) ^ (sec_r000095_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_205_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_205_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = (((stage_v_116_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_206_2 = (((stage_v_116_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_206_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_206_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = (((stage_v_101_1 << 2) ^ (sec_r000095_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_207_2 = (((stage_v_101_2 << 2) ^ (sec_r000095_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_207_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_207_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = (((sec_r000095_16_1 << 1) ^ (sec_r000095_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_208_2 = (((sec_r000095_16_2 << 1) ^ (sec_r000095_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_208_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_208_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = (((stage_v_107_1 << 2) ^ (sec_r000095_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_209_2 = (((stage_v_107_2 << 2) ^ (sec_r000095_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_209_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_209_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = (((stage_v_89_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_210_2 = (((stage_v_89_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_210_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_210_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = (((sec_r000095_14_1 << 1) ^ (sec_r000095_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_211_2 = (((sec_r000095_14_2 << 1) ^ (sec_r000095_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_211_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_211_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = (((stage_v_114_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_212_2 = (((stage_v_114_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_212_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_212_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = (((sec_r000095_1_1 << 1) ^ (sec_r000095_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_213_2 = (((sec_r000095_1_2 << 1) ^ (sec_r000095_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_213_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_213_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = (((stage_v_131_1 << 2) ^ (sec_r000095_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_214_2 = (((stage_v_131_2 << 2) ^ (sec_r000095_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_214_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_214_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = (((stage_v_107_1 << 1) ^ (sec_r000095_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_215_2 = (((stage_v_107_2 << 1) ^ (sec_r000095_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_215_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_215_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = (((sec_r000095_17_1 << 1) ^ (sec_r000095_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_216_2 = (((sec_r000095_17_2 << 1) ^ (sec_r000095_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_216_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_216_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = (((stage_v_201_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_217_2 = (((stage_v_201_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_217_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_217_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = (((sec_r000095_11_1 << 1) ^ (sec_r000095_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_218_2 = (((sec_r000095_11_2 << 1) ^ (sec_r000095_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_218_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_218_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = (((sec_r000095_9_1 << 1) ^ (sec_r000095_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_219_2 = (((sec_r000095_9_2 << 1) ^ (sec_r000095_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_219_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_219_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = (((sec_r000095_0_1 << 1) ^ (sec_r000095_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_220_2 = (((sec_r000095_0_2 << 1) ^ (sec_r000095_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_220_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_220_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = (((stage_v_216_1 << 1) ^ (sec_r000095_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_221_2 = (((stage_v_216_2 << 1) ^ (sec_r000095_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_221_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_221_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = (((stage_v_202_1 << 1) ^ (sec_r000095_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_222_2 = (((stage_v_202_2 << 1) ^ (sec_r000095_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_222_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_222_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = (((stage_v_189_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_223_2 = (((stage_v_189_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_223_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_223_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = (((sec_r000095_10_1 << 2) ^ (sec_r000095_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_224_2 = (((sec_r000095_10_2 << 2) ^ (sec_r000095_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_224_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_224_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = (((stage_v_203_1 << 1) ^ (sec_r000095_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_225_2 = (((stage_v_203_2 << 1) ^ (sec_r000095_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_225_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_225_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = (((stage_v_199_1 << 2) ^ (sec_r000095_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_226_2 = (((stage_v_199_2 << 2) ^ (sec_r000095_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_226_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_226_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = (((stage_v_149_1 << 2) ^ (sec_r000095_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_227_2 = (((stage_v_149_2 << 2) ^ (sec_r000095_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_227_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_227_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = (((stage_v_176_1 << 1) ^ (sec_r000095_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_228_2 = (((stage_v_176_2 << 1) ^ (sec_r000095_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_228_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_228_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = (((stage_v_205_1 << 2) ^ (sec_r000095_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_229_2 = (((stage_v_205_2 << 2) ^ (sec_r000095_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_229_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_229_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = (((stage_v_90_1 << 2) ^ (sec_r000095_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_230_2 = (((stage_v_90_2 << 2) ^ (sec_r000095_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_230_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_230_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = (((stage_v_203_1 << 1) ^ (sec_r000095_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_231_2 = (((stage_v_203_2 << 1) ^ (sec_r000095_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_231_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_231_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = (((stage_v_213_1 << 1) ^ (sec_r000095_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_232_2 = (((stage_v_213_2 << 1) ^ (sec_r000095_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_232_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_232_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = (((stage_v_87_1 << 2) ^ (sec_r000095_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_233_2 = (((stage_v_87_2 << 2) ^ (sec_r000095_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_233_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_233_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = (((stage_v_86_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_234_2 = (((stage_v_86_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_234_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_234_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = (((stage_v_184_1 << 2) ^ (sec_r000095_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_235_2 = (((stage_v_184_2 << 2) ^ (sec_r000095_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_235_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_235_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = (((stage_v_201_1 << 2) ^ (sec_r000095_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_236_2 = (((stage_v_201_2 << 2) ^ (sec_r000095_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_236_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_236_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = (((stage_v_106_1 << 2) ^ (sec_r000095_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_237_2 = (((stage_v_106_2 << 2) ^ (sec_r000095_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_237_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_237_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = (((sec_r000095_12_1 << 2) ^ (sec_r000095_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_238_2 = (((sec_r000095_12_2 << 2) ^ (sec_r000095_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_238_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_238_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = (((sec_r000095_9_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_239_2 = (((sec_r000095_9_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_239_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_239_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = (((stage_v_104_1 << 2) ^ (sec_r000095_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_240_2 = (((stage_v_104_2 << 2) ^ (sec_r000095_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_240_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_240_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = (((stage_v_211_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_241_2 = (((stage_v_211_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_241_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_241_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = (((stage_v_173_1 << 2) ^ (sec_r000095_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_242_2 = (((stage_v_173_2 << 2) ^ (sec_r000095_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_242_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_242_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = (((stage_v_96_1 << 2) ^ (sec_r000095_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_243_2 = (((stage_v_96_2 << 2) ^ (sec_r000095_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_243_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_243_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = (((sec_r000095_17_1 << 2) ^ (sec_r000095_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_244_2 = (((sec_r000095_17_2 << 2) ^ (sec_r000095_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_244_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_244_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = (((stage_v_90_1 << 2) ^ (sec_r000095_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_245_2 = (((stage_v_90_2 << 2) ^ (sec_r000095_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_245_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_245_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = (((stage_v_132_1 << 1) ^ (sec_r000095_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_246_2 = (((stage_v_132_2 << 1) ^ (sec_r000095_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_246_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_246_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = (((sec_r000095_12_1 << 2) ^ (sec_r000095_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_247_2 = (((sec_r000095_12_2 << 2) ^ (sec_r000095_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_247_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_247_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = (((stage_v_110_1 << 1) ^ (sec_r000095_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_248_2 = (((stage_v_110_2 << 1) ^ (sec_r000095_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_248_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_248_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = (((sec_r000095_2_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_249_2 = (((sec_r000095_2_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_249_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_249_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = (((stage_v_153_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_250_2 = (((stage_v_153_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_250_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_250_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = (((stage_v_185_1 << 2) ^ (sec_r000095_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_251_2 = (((stage_v_185_2 << 2) ^ (sec_r000095_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_251_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_251_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = (((stage_v_215_1 << 2) ^ (sec_r000095_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_252_2 = (((stage_v_215_2 << 2) ^ (sec_r000095_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_252_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_252_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = (((stage_v_173_1 << 1) ^ (sec_r000095_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_253_2 = (((stage_v_173_2 << 1) ^ (sec_r000095_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_253_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_253_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = (((stage_v_56_1 << 1) ^ (sec_r000095_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_254_2 = (((stage_v_56_2 << 1) ^ (sec_r000095_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_254_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_254_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = (((stage_v_177_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_255_2 = (((stage_v_177_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_255_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_255_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = (((stage_v_244_1 << 2) ^ (sec_r000095_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_256_2 = (((stage_v_244_2 << 2) ^ (sec_r000095_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_256_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_256_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = (((sec_r000095_7_1 << 2) ^ (sec_r000095_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_257_2 = (((sec_r000095_7_2 << 2) ^ (sec_r000095_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_257_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_257_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = (((stage_v_165_1 << 2) ^ (sec_r000095_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_258_2 = (((stage_v_165_2 << 2) ^ (sec_r000095_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_258_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_258_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = (((sec_r000095_5_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_259_2 = (((sec_r000095_5_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_259_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_259_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = (((stage_v_176_1 << 2) ^ (sec_r000095_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_260_2 = (((stage_v_176_2 << 2) ^ (sec_r000095_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_260_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_260_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = (((stage_v_105_1 << 2) ^ (sec_r000095_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_261_2 = (((stage_v_105_2 << 2) ^ (sec_r000095_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_261_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_261_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = (((stage_v_146_1 << 1) ^ (sec_r000095_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_262_2 = (((stage_v_146_2 << 1) ^ (sec_r000095_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_262_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_262_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = (((sec_r000095_13_1 << 2) ^ (sec_r000095_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_263_2 = (((sec_r000095_13_2 << 2) ^ (sec_r000095_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_263_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_263_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = (((stage_v_68_1 << 2) ^ (sec_r000095_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_264_2 = (((stage_v_68_2 << 2) ^ (sec_r000095_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_264_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_264_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = (((sec_r000095_4_1 << 2) ^ (sec_r000095_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_265_2 = (((sec_r000095_4_2 << 2) ^ (sec_r000095_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_265_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_265_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = (((stage_v_127_1 << 1) ^ (sec_r000095_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_266_2 = (((stage_v_127_2 << 1) ^ (sec_r000095_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_266_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_266_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = (((stage_v_262_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_267_2 = (((stage_v_262_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_267_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_267_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = (((stage_v_116_1 << 2) ^ (sec_r000095_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_268_2 = (((stage_v_116_2 << 2) ^ (sec_r000095_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_268_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_268_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_268_1 & 63;
  out_sink_2 ^= stage_v_268_2 & 63;
  int stage_v_269_1 = (((stage_v_81_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_269_2 = (((stage_v_81_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_269_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_269_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = (((stage_v_257_1 << 2) ^ (sec_r000095_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_270_2 = (((stage_v_257_2 << 2) ^ (sec_r000095_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_270_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_270_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = (((sec_r000095_2_1 << 1) ^ (sec_r000095_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_271_2 = (((sec_r000095_2_2 << 1) ^ (sec_r000095_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_271_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_271_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = (((sec_r000095_6_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_272_2 = (((sec_r000095_6_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_272_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_272_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = (((stage_v_141_1 << 2) ^ (sec_r000095_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_273_2 = (((stage_v_141_2 << 2) ^ (sec_r000095_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_273_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_273_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = (((sec_r000095_13_1 << 1) ^ (sec_r000095_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_274_2 = (((sec_r000095_13_2 << 1) ^ (sec_r000095_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_274_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_274_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = (((sec_r000095_8_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_275_2 = (((sec_r000095_8_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_275_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_275_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = (((stage_v_199_1 << 1) ^ (sec_r000095_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_276_2 = (((stage_v_199_2 << 1) ^ (sec_r000095_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_276_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_276_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = (((stage_v_113_1 << 1) ^ (sec_r000095_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_277_2 = (((stage_v_113_2 << 1) ^ (sec_r000095_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_277_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_277_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = (((stage_v_258_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_278_2 = (((stage_v_258_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_278_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_278_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = (((stage_v_234_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_279_2 = (((stage_v_234_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_279_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_279_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = (((stage_v_151_1 << 2) ^ (sec_r000095_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_280_2 = (((stage_v_151_2 << 2) ^ (sec_r000095_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_280_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_280_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = (((stage_v_169_1 << 1) ^ (sec_r000095_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_281_2 = (((stage_v_169_2 << 1) ^ (sec_r000095_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_281_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_281_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = (((stage_v_90_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_282_2 = (((stage_v_90_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_282_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_282_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = (((stage_v_44_1 << 1) ^ (sec_r000095_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_283_2 = (((stage_v_44_2 << 1) ^ (sec_r000095_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_283_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_283_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = (((stage_v_79_1 << 1) ^ (sec_r000095_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_284_2 = (((stage_v_79_2 << 1) ^ (sec_r000095_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_284_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_284_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = (((stage_v_218_1 << 2) ^ (sec_r000095_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_285_2 = (((stage_v_218_2 << 2) ^ (sec_r000095_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_285_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_285_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = (((stage_v_78_1 << 1) ^ (sec_r000095_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_286_2 = (((stage_v_78_2 << 1) ^ (sec_r000095_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_286_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_286_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = (((stage_v_54_1 << 1) ^ (sec_r000095_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_287_2 = (((stage_v_54_2 << 1) ^ (sec_r000095_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_287_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_287_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = (((stage_v_143_1 << 1) ^ (sec_r000095_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_288_2 = (((stage_v_143_2 << 1) ^ (sec_r000095_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_288_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_288_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_288_1 & 63;
  out_sink_2 ^= stage_v_288_2 & 63;
  int stage_v_289_1 = (((stage_v_270_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_289_2 = (((stage_v_270_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_289_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_289_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = (((stage_v_137_1 << 1) ^ (sec_r000095_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_290_2 = (((stage_v_137_2 << 1) ^ (sec_r000095_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_290_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_290_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = (((sec_r000095_3_1 << 1) ^ (sec_r000095_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_291_2 = (((sec_r000095_3_2 << 1) ^ (sec_r000095_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_291_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_291_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = (((stage_v_93_1 << 1) ^ (sec_r000095_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_292_2 = (((stage_v_93_2 << 1) ^ (sec_r000095_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_292_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_292_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = (((sec_r000095_10_1 << 2) ^ (sec_r000095_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_293_2 = (((sec_r000095_10_2 << 2) ^ (sec_r000095_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_293_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_293_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = (((sec_r000095_8_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_294_2 = (((sec_r000095_8_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_294_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_294_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = (((stage_v_291_1 << 2) ^ (sec_r000095_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_295_2 = (((stage_v_291_2 << 2) ^ (sec_r000095_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_295_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_295_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = (((stage_v_206_1 << 1) ^ (sec_r000095_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_296_2 = (((stage_v_206_2 << 1) ^ (sec_r000095_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_296_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_296_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = (((stage_v_63_1 << 2) ^ (sec_r000095_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_297_2 = (((stage_v_63_2 << 2) ^ (sec_r000095_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_297_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_297_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = (((stage_v_269_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_298_2 = (((stage_v_269_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_298_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_298_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = (((stage_v_278_1 << 1) ^ (sec_r000095_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_299_2 = (((stage_v_278_2 << 1) ^ (sec_r000095_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_299_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_299_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = (((stage_v_48_1 << 2) ^ (sec_r000095_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_300_2 = (((stage_v_48_2 << 2) ^ (sec_r000095_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_300_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_300_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = (((stage_v_80_1 << 1) ^ (sec_r000095_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_301_2 = (((stage_v_80_2 << 1) ^ (sec_r000095_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_301_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_301_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = (((stage_v_235_1 << 2) ^ (sec_r000095_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_302_2 = (((stage_v_235_2 << 2) ^ (sec_r000095_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_302_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_302_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = (((stage_v_273_1 << 1) ^ (sec_r000095_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_303_2 = (((stage_v_273_2 << 1) ^ (sec_r000095_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_303_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_303_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = (((sec_r000095_18_1 << 2) ^ (sec_r000095_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_304_2 = (((sec_r000095_18_2 << 2) ^ (sec_r000095_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_304_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_304_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = (((stage_v_178_1 << 2) ^ (sec_r000095_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_305_2 = (((stage_v_178_2 << 2) ^ (sec_r000095_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_305_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_305_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000095_14_1 != sec_r000095_14_2);
  __CPROVER_assume(pub_r000095_16_1 == pub_r000095_16_2);
  __CPROVER_assume(sec_r000095_0_1 != sec_r000095_0_2);
  __CPROVER_assume(sec_r000095_13_1 != sec_r000095_13_2);
  __CPROVER_assume(sec_r000095_9_1 != sec_r000095_9_2);
  __CPROVER_assume(sec_r000095_3_1 != sec_r000095_3_2);
  __CPROVER_assume(pub_r000095_11_1 == pub_r000095_11_2);
  __CPROVER_assume(sec_r000095_6_1 != sec_r000095_6_2);
  __CPROVER_assume(pub_r000095_6_1 == pub_r000095_6_2);
  __CPROVER_assume(sec_r000095_7_1 != sec_r000095_7_2);
  __CPROVER_assume(sec_r000095_16_1 != sec_r000095_16_2);
  __CPROVER_assume(pub_r000095_15_1 == pub_r000095_15_2);
  __CPROVER_assume(pub_r000095_9_1 == pub_r000095_9_2);
  __CPROVER_assume(pub_r000095_1_1 == pub_r000095_1_2);
  __CPROVER_assume(pub_r000095_5_1 == pub_r000095_5_2);
  __CPROVER_assume(sec_r000095_18_1 != sec_r000095_18_2);
  __CPROVER_assume(sec_r000095_17_1 != sec_r000095_17_2);
  __CPROVER_assume(sec_r000095_15_1 != sec_r000095_15_2);
  __CPROVER_assume(pub_r000095_10_1 == pub_r000095_10_2);
  __CPROVER_assume(pub_r000095_4_1 == pub_r000095_4_2);
  __CPROVER_assume(pub_r000095_20_1 == pub_r000095_20_2);
  __CPROVER_assume(pub_r000095_14_1 == pub_r000095_14_2);
  __CPROVER_assume(pub_r000095_21_1 == pub_r000095_21_2);
  __CPROVER_assume(sec_r000095_1_1 != sec_r000095_1_2);
  __CPROVER_assume(pub_r000095_22_1 == pub_r000095_22_2);
  __CPROVER_assume(sec_r000095_5_1 != sec_r000095_5_2);
  __CPROVER_assume(sec_r000095_12_1 != sec_r000095_12_2);
  __CPROVER_assume(sec_r000095_4_1 != sec_r000095_4_2);
  __CPROVER_assume(pub_r000095_7_1 == pub_r000095_7_2);
  __CPROVER_assume(pub_r000095_2_1 == pub_r000095_2_2);
  __CPROVER_assume(sec_r000095_11_1 != sec_r000095_11_2);
  __CPROVER_assume(sec_r000095_10_1 != sec_r000095_10_2);
  __CPROVER_assume(sec_r000095_8_1 != sec_r000095_8_2);
  __CPROVER_assume(pub_r000095_8_1 == pub_r000095_8_2);
  __CPROVER_assume(pub_r000095_23_1 == pub_r000095_23_2);
  __CPROVER_assume(sec_r000095_2_1 != sec_r000095_2_2);
  __CPROVER_assume(pub_r000095_12_1 == pub_r000095_12_2);
  __CPROVER_assume(pub_r000095_0_1 == pub_r000095_0_2);
  __CPROVER_assume(pub_r000095_3_1 == pub_r000095_3_2);
  __CPROVER_assume(pub_r000095_19_1 == pub_r000095_19_2);
  __CPROVER_assume(pub_r000095_18_1 == pub_r000095_18_2);
  __CPROVER_assume(pub_r000095_17_1 == pub_r000095_17_2);
  __CPROVER_assume(pub_r000095_13_1 == pub_r000095_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  assert(st_var_0_1.head == st_var_0_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.stride == st_var_2_2.stride);
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
}


