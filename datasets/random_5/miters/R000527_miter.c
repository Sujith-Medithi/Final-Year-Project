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
struct MatrixBlock_R000527_2713_0
{
  short scale;
  unsigned char dim;
  int determinant;
  int buffer[3];
};
struct EventLog_R000527_2713_1
{
  unsigned char timestamp;
  int severity;
  int signature;
  unsigned char code;
  unsigned char seq;
  int buffer[3];
};
struct SensorNode_R000527_2713_2
{
  short status;
  int offset;
  short calib;
  unsigned char gain;
  int buffer[3];
};
struct CipherContext_R000527_2713_3
{
  int iv;
  unsigned char round_key;
  short flags;
  unsigned char nonce;
  int counter;
  unsigned char tag;
  int buffer[3];
};
union TelemetryField_R000527_2713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000527_2713_1
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
void fn_R000527_2713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st_1 = {0};
  struct MatrixBlock_R000527_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_41_1)
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

  switch (threshold_41_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_41_1 == threshold_41_2);
}

int fn_R000527_2713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_41 = (aux + st.buffer[1]) & 3;
  switch (threshold_41)
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

void fn_R000527_2713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st_1 = {0};
  struct EventLog_R000527_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_56_1 > 28)
  {
    acc_1 = ((acc_1 + (parity_56_1 * 2)) + 5) & 127;
    aux_1 ^= parity_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_56_2 > 28)
  {
    acc_2 = ((acc_2 + (parity_56_2 * 2)) + 5) & 127;
    aux_2 ^= parity_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_56_1 == parity_56_2);
}

int fn_R000527_2713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_56 > 28)
  {
    acc = ((acc + (parity_56 * 2)) + 5) & 127;
    aux ^= parity_56 & 15;
  }
  else
  {
    acc = ((acc - parity_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000527_2713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st_1 = {0};
  struct CipherContext_R000527_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int factor_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_65_1)
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

  switch (factor_65_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_95_1 > 26)
  {
    acc_1 = ((acc_1 + (cursor_95_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_95_2 > 26)
  {
    acc_2 = ((acc_2 + (cursor_95_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_95_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_65_1 == factor_65_2);
  assert(cursor_95_1 == cursor_95_2);
}

int fn_R000527_2713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int factor_65 = (aux + st.buffer[1]) & 3;
  switch (factor_65)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_95 > 26)
  {
    acc = ((acc + (cursor_95 * 2)) + 5) & 127;
    aux ^= cursor_95 & 15;
  }
  else
  {
    acc = ((acc - cursor_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000527_2713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st_1 = {0};
  struct CipherContext_R000527_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_35_1 = local_arr_1[aux_1 % 3];
  int mask_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_35_2 * 2)) & 127;
  int parity_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_36_1) & 63;
  aux_2 = (aux_2 + parity_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_35_1 == mask_35_2);
  assert(parity_36_1 == parity_36_2);
}

int fn_R000527_2713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int mask_35 = local_arr[aux % 3];
  acc = (acc + (mask_35 * 2)) & 127;
  int parity_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_36) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000527_2713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st_1 = {0};
  struct SensorNode_R000527_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int phase_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_21_1 > 35)
  {
    acc_1 = ((acc_1 + (phase_21_1 * 2)) + 5) & 127;
    aux_1 ^= phase_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_21_2 > 35)
  {
    acc_2 = ((acc_2 + (phase_21_2 * 2)) + 5) & 127;
    aux_2 ^= phase_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_93_1 = local_arr_1[aux_1 % 3];
  int window_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_67_1) & 63;
  aux_2 = (aux_2 + damping_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_21_1 == phase_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_93_1 == window_93_2);
  assert(damping_67_1 == damping_67_2);
}

int fn_R000527_2713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int phase_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_21 > 35)
  {
    acc = ((acc + (phase_21 * 2)) + 5) & 127;
    aux ^= phase_21 & 15;
  }
  else
  {
    acc = ((acc - phase_21) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_93 = local_arr[aux % 3];
  acc = (acc + (window_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_67) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000527_2713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st_1 = {0};
  struct CipherContext_R000527_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_67_1 = local_arr_1[aux_1 % 3];
  int pivot_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_67_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_67_1 == pivot_67_2);
}

int fn_R000527_2713_5(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int pivot_67 = local_arr[aux % 3];
  acc = (acc + (pivot_67 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st_1 = {0};
  struct MatrixBlock_R000527_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int index_reg_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_63_1) & 63;
  aux_2 = (aux_2 + index_reg_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_77_1)
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

  switch (tracker_77_2)
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

  int coefficient_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_96_1 > 25)
  {
    acc_1 = ((acc_1 + (coefficient_96_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_96_2 > 25)
  {
    acc_2 = ((acc_2 + (coefficient_96_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_96_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_63_1 == index_reg_63_2);
  assert(tracker_77_1 == tracker_77_2);
  assert(coefficient_96_1 == coefficient_96_2);
}

int fn_R000527_2713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int index_reg_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_63) & 63;
  acc ^= aux;
  int tracker_77 = (aux + st.buffer[1]) & 3;
  switch (tracker_77)
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

  int coefficient_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_96 > 25)
  {
    acc = ((acc + (coefficient_96 * 2)) + 5) & 127;
    aux ^= coefficient_96 & 15;
  }
  else
  {
    acc = ((acc - coefficient_96) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st_1 = {0};
  struct MatrixBlock_R000527_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_66_1)
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

  switch (tracker_66_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_34_1 = local_arr_1[aux_1 % 3];
  int stride_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_34_2 * 2)) & 127;
  int coefficient_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_52_1 > 27)
  {
    acc_1 = ((acc_1 + (coefficient_52_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_52_2 > 27)
  {
    acc_2 = ((acc_2 + (coefficient_52_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_66_1 == tracker_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_34_1 == stride_34_2);
  assert(coefficient_52_1 == coefficient_52_2);
}

int fn_R000527_2713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_66 = (aux + st.buffer[1]) & 3;
  switch (tracker_66)
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

  int local_arr[3] = {4, 9, 15};
  int stride_34 = local_arr[aux % 3];
  acc = (acc + (stride_34 * 2)) & 127;
  int coefficient_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_52 > 27)
  {
    acc = ((acc + (coefficient_52 * 2)) + 5) & 127;
    aux ^= coefficient_52 & 15;
  }
  else
  {
    acc = ((acc - coefficient_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000527_2713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st_1 = {0};
  struct EventLog_R000527_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_35_1 = local_arr_1[aux_1 % 3];
  int quantum_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_35_2 * 2)) & 127;
  int damping_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_97_1 > 12)
  {
    acc_1 = ((acc_1 + (damping_97_1 * 2)) + 5) & 127;
    aux_1 ^= damping_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_97_2 > 12)
  {
    acc_2 = ((acc_2 + (damping_97_2 * 2)) + 5) & 127;
    aux_2 ^= damping_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_97_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_35_1 == quantum_35_2);
  assert(damping_97_1 == damping_97_2);
}

int fn_R000527_2713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int quantum_35 = local_arr[aux % 3];
  acc = (acc + (quantum_35 * 2)) & 127;
  int damping_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_97 > 12)
  {
    acc = ((acc + (damping_97 * 2)) + 5) & 127;
    aux ^= damping_97 & 15;
  }
  else
  {
    acc = ((acc - damping_97) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st_1 = {0};
  struct CipherContext_R000527_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int parity_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_13_1)
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

  switch (parity_13_2)
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
  int anchor_48_1 = local_arr_1[aux_1 % 3];
  int anchor_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_48_2 * 2)) & 127;
  int stride_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_75_1 > 21)
  {
    acc_1 = ((acc_1 + (stride_75_1 * 2)) + 5) & 127;
    aux_1 ^= stride_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_75_2 > 21)
  {
    acc_2 = ((acc_2 + (stride_75_2 * 2)) + 5) & 127;
    aux_2 ^= stride_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_13_1 == parity_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_48_1 == anchor_48_2);
  assert(stride_75_1 == stride_75_2);
}

int fn_R000527_2713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int parity_13 = (aux + st.buffer[1]) & 3;
  switch (parity_13)
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
  int anchor_48 = local_arr[aux % 3];
  acc = (acc + (anchor_48 * 2)) & 127;
  int stride_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_75 > 21)
  {
    acc = ((acc + (stride_75 * 2)) + 5) & 127;
    aux ^= stride_75 & 15;
  }
  else
  {
    acc = ((acc - stride_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000527_2713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st_1 = {0};
  struct EventLog_R000527_2713_1 st_2 = {0};
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
  int threshold_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_37_1 > 48)
  {
    acc_1 = ((acc_1 + (threshold_37_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_37_2 > 48)
  {
    acc_2 = ((acc_2 + (threshold_37_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_59_1 = local_arr_1[aux_1 % 3];
  int coefficient_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_37_1 == threshold_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_59_1 == coefficient_59_2);
}

int fn_R000527_2713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_37 > 48)
  {
    acc = ((acc + (threshold_37 * 2)) + 5) & 127;
    aux ^= threshold_37 & 15;
  }
  else
  {
    acc = ((acc - threshold_37) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_59 = local_arr[aux % 3];
  acc = (acc + (coefficient_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st_1 = {0};
  struct SensorNode_R000527_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_34_1 = local_arr_1[aux_1 % 3];
  int vector_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_34_2 * 2)) & 127;
  int margin_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_61_1) & 63;
  aux_2 = (aux_2 + margin_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_13_1)
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

  switch (margin_13_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
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

  assert(vector_34_1 == vector_34_2);
  assert(margin_61_1 == margin_61_2);
  assert(margin_13_1 == margin_13_2);
}

int fn_R000527_2713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int vector_34 = local_arr[aux % 3];
  acc = (acc + (vector_34 * 2)) & 127;
  int margin_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_61) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_13 = (aux + st.buffer[1]) & 3;
  switch (margin_13)
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

void fn_R000527_2713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st_1 = {0};
  struct EventLog_R000527_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int offset_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_93_1 > 25)
  {
    acc_1 = ((acc_1 + (offset_93_1 * 2)) + 5) & 127;
    aux_1 ^= offset_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_93_2 > 25)
  {
    acc_2 = ((acc_2 + (offset_93_2 * 2)) + 5) & 127;
    aux_2 ^= offset_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_24_1)
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

  switch (stride_24_2)
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
  int sample_77_1 = local_arr_1[aux_1 % 3];
  int sample_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_93_1 == offset_93_2);
  assert(stride_24_1 == stride_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_77_1 == sample_77_2);
}

int fn_R000527_2713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int offset_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_93 > 25)
  {
    acc = ((acc + (offset_93 * 2)) + 5) & 127;
    aux ^= offset_93 & 15;
  }
  else
  {
    acc = ((acc - offset_93) + 11) & 127;
    aux += 3;
  }
  int stride_24 = (aux + st.buffer[1]) & 3;
  switch (stride_24)
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
  int sample_77 = local_arr[aux % 3];
  acc = (acc + (sample_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st_1 = {0};
  struct EventLog_R000527_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_18_1 = local_arr_1[aux_1 % 3];
  int vector_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_18_2 * 2)) & 127;
  int weight_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_81_1 > 49)
  {
    acc_1 = ((acc_1 + (weight_81_1 * 2)) + 5) & 127;
    aux_1 ^= weight_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_81_2 > 49)
  {
    acc_2 = ((acc_2 + (weight_81_2 * 2)) + 5) & 127;
    aux_2 ^= weight_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_77_1) & 63;
  aux_2 = (aux_2 + threshold_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_18_1 == vector_18_2);
  assert(weight_81_1 == weight_81_2);
  assert(threshold_77_1 == threshold_77_2);
}

int fn_R000527_2713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int vector_18 = local_arr[aux % 3];
  acc = (acc + (vector_18 * 2)) & 127;
  int weight_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_81 > 49)
  {
    acc = ((acc + (weight_81 * 2)) + 5) & 127;
    aux ^= weight_81 & 15;
  }
  else
  {
    acc = ((acc - weight_81) + 11) & 127;
    aux += 3;
  }
  int threshold_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_77) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st_1 = {0};
  struct EventLog_R000527_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int metric_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_17_1 > 20)
  {
    acc_1 = ((acc_1 + (metric_17_1 * 2)) + 5) & 127;
    aux_1 ^= metric_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_17_2 > 20)
  {
    acc_2 = ((acc_2 + (metric_17_2 * 2)) + 5) & 127;
    aux_2 ^= metric_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_17_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_28_1 = local_arr_1[aux_1 % 3];
  int parity_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_17_1 == metric_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_28_1 == parity_28_2);
}

int fn_R000527_2713_14(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int metric_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_17 > 20)
  {
    acc = ((acc + (metric_17 * 2)) + 5) & 127;
    aux ^= metric_17 & 15;
  }
  else
  {
    acc = ((acc - metric_17) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_28 = local_arr[aux % 3];
  acc = (acc + (parity_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st_1 = {0};
  struct MatrixBlock_R000527_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_39_1 = local_arr_1[aux_1 % 3];
  int parity_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_39_2 * 2)) & 127;
  int margin_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_90_1) & 63;
  aux_2 = (aux_2 + margin_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_83_1 > 49)
  {
    acc_1 = ((acc_1 + (phase_83_1 * 2)) + 5) & 127;
    aux_1 ^= phase_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_83_2 > 49)
  {
    acc_2 = ((acc_2 + (phase_83_2 * 2)) + 5) & 127;
    aux_2 ^= phase_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_39_1 == parity_39_2);
  assert(margin_90_1 == margin_90_2);
  assert(phase_83_1 == phase_83_2);
}

int fn_R000527_2713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int parity_39 = local_arr[aux % 3];
  acc = (acc + (parity_39 * 2)) & 127;
  int margin_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_90) & 63;
  acc ^= aux;
  int phase_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_83 > 49)
  {
    acc = ((acc + (phase_83 * 2)) + 5) & 127;
    aux ^= phase_83 & 15;
  }
  else
  {
    acc = ((acc - phase_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000527_2713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st_1 = {0};
  struct MatrixBlock_R000527_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quotient_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_44_1) & 63;
  aux_2 = (aux_2 + quotient_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_90_1 > 22)
  {
    acc_1 = ((acc_1 + (offset_90_1 * 2)) + 5) & 127;
    aux_1 ^= offset_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_90_2 > 22)
  {
    acc_2 = ((acc_2 + (offset_90_2 * 2)) + 5) & 127;
    aux_2 ^= offset_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_36_1)
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

  switch (sample_36_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_44_1 == quotient_44_2);
  assert(offset_90_1 == offset_90_2);
  assert(sample_36_1 == sample_36_2);
}

int fn_R000527_2713_16(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quotient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_44) & 63;
  acc ^= aux;
  int offset_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_90 > 22)
  {
    acc = ((acc + (offset_90 * 2)) + 5) & 127;
    aux ^= offset_90 & 15;
  }
  else
  {
    acc = ((acc - offset_90) + 11) & 127;
    aux += 3;
  }
  int sample_36 = (aux + st.buffer[1]) & 3;
  switch (sample_36)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st_1 = {0};
  struct SensorNode_R000527_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int residue_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_90_1 > 39)
  {
    acc_1 = ((acc_1 + (residue_90_1 * 2)) + 5) & 127;
    aux_1 ^= residue_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_90_2 > 39)
  {
    acc_2 = ((acc_2 + (residue_90_2 * 2)) + 5) & 127;
    aux_2 ^= residue_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_63_1)
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

  switch (factor_63_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_90_1 == residue_90_2);
  assert(factor_63_1 == factor_63_2);
}

int fn_R000527_2713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int residue_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_90 > 39)
  {
    acc = ((acc + (residue_90 * 2)) + 5) & 127;
    aux ^= residue_90 & 15;
  }
  else
  {
    acc = ((acc - residue_90) + 11) & 127;
    aux += 3;
  }
  int factor_63 = (aux + st.buffer[1]) & 3;
  switch (factor_63)
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

void fn_R000527_2713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st_1 = {0};
  struct SensorNode_R000527_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int sample_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_23_1)
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

  switch (sample_23_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_83_1 = local_arr_1[aux_1 % 3];
  int residue_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_23_1 == sample_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_83_1 == residue_83_2);
}

int fn_R000527_2713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int sample_23 = (aux + st.buffer[1]) & 3;
  switch (sample_23)
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

  int local_arr[3] = {4, 9, 15};
  int residue_83 = local_arr[aux % 3];
  acc = (acc + (residue_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st_1 = {0};
  struct EventLog_R000527_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int accumulator_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_77_1 > 11)
  {
    acc_1 = ((acc_1 + (accumulator_77_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_77_2 > 11)
  {
    acc_2 = ((acc_2 + (accumulator_77_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_13_1)
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

  switch (parity_13_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_77_1 == accumulator_77_2);
  assert(parity_13_1 == parity_13_2);
}

int fn_R000527_2713_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int accumulator_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_77 > 11)
  {
    acc = ((acc + (accumulator_77 * 2)) + 5) & 127;
    aux ^= accumulator_77 & 15;
  }
  else
  {
    acc = ((acc - accumulator_77) + 11) & 127;
    aux += 3;
  }
  int parity_13 = (aux + st.buffer[1]) & 3;
  switch (parity_13)
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

void fn_R000527_2713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st_1 = {0};
  struct SensorNode_R000527_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_82_1 = local_arr_1[aux_1 % 3];
  int checksum_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_82_2 * 2)) & 127;
  int index_reg_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_36_1 > 47)
  {
    acc_1 = ((acc_1 + (index_reg_36_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_36_2 > 47)
  {
    acc_2 = ((acc_2 + (index_reg_36_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_36_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
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

  assert(checksum_82_1 == checksum_82_2);
  assert(index_reg_36_1 == index_reg_36_2);
}

int fn_R000527_2713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000527_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int checksum_82 = local_arr[aux % 3];
  acc = (acc + (checksum_82 * 2)) & 127;
  int index_reg_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_36 > 47)
  {
    acc = ((acc + (index_reg_36 * 2)) + 5) & 127;
    aux ^= index_reg_36 & 15;
  }
  else
  {
    acc = ((acc - index_reg_36) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000527_2713_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st_1 = {0};
  struct CipherContext_R000527_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_74_1 > 31)
  {
    acc_1 = ((acc_1 + (tracker_74_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_74_2 > 31)
  {
    acc_2 = ((acc_2 + (tracker_74_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_37_1 = local_arr_1[aux_1 % 3];
  int metric_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_74_1 == tracker_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_37_1 == metric_37_2);
}

int fn_R000527_2713_21(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000527_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_74 > 31)
  {
    acc = ((acc + (tracker_74 * 2)) + 5) & 127;
    aux ^= tracker_74 & 15;
  }
  else
  {
    acc = ((acc - tracker_74) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_37 = local_arr[aux % 3];
  acc = (acc + (metric_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000527_2713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st_1 = {0};
  struct MatrixBlock_R000527_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int offset_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_19_1) & 63;
  aux_2 = (aux_2 + offset_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_95_1 = local_arr_1[aux_1 % 3];
  int cursor_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_95_2 * 2)) & 127;
  int quantum_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_46_1 > 34)
  {
    acc_1 = ((acc_1 + (quantum_46_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_46_2 > 34)
  {
    acc_2 = ((acc_2 + (quantum_46_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_19_1 == offset_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_95_1 == cursor_95_2);
  assert(quantum_46_1 == quantum_46_2);
}

int fn_R000527_2713_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000527_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int offset_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_19) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_95 = local_arr[aux % 3];
  acc = (acc + (cursor_95 * 2)) & 127;
  int quantum_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_46 > 34)
  {
    acc = ((acc + (quantum_46 * 2)) + 5) & 127;
    aux ^= quantum_46 & 15;
  }
  else
  {
    acc = ((acc - quantum_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000527_2713_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st_1 = {0};
  struct EventLog_R000527_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tracker_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_65_1)
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

  switch (tracker_65_2)
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
  int delta_52_1 = local_arr_1[aux_1 % 3];
  int delta_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_52_2 * 2)) & 127;
  int window_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_88_1 > 21)
  {
    acc_1 = ((acc_1 + (window_88_1 * 2)) + 5) & 127;
    aux_1 ^= window_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_88_2 > 21)
  {
    acc_2 = ((acc_2 + (window_88_2 * 2)) + 5) & 127;
    aux_2 ^= window_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_88_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_65_1 == tracker_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_52_1 == delta_52_2);
  assert(window_88_1 == window_88_2);
}

int fn_R000527_2713_23(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000527_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tracker_65 = (aux + st.buffer[1]) & 3;
  switch (tracker_65)
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
  int delta_52 = local_arr[aux % 3];
  acc = (acc + (delta_52 * 2)) & 127;
  int window_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_88 > 21)
  {
    acc = ((acc + (window_88 * 2)) + 5) & 127;
    aux ^= window_88 & 15;
  }
  else
  {
    acc = ((acc - window_88) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000527_0_1;
  int sec_r000527_0_2;
  int sec_r000527_1_1;
  int sec_r000527_1_2;
  int sec_r000527_2_1;
  int sec_r000527_2_2;
  int sec_r000527_3_1;
  int sec_r000527_3_2;
  int sec_r000527_4_1;
  int sec_r000527_4_2;
  int sec_r000527_5_1;
  int sec_r000527_5_2;
  int sec_r000527_6_1;
  int sec_r000527_6_2;
  int sec_r000527_7_1;
  int sec_r000527_7_2;
  int sec_r000527_8_1;
  int sec_r000527_8_2;
  int sec_r000527_9_1;
  int sec_r000527_9_2;
  int sec_r000527_10_1;
  int sec_r000527_10_2;
  int sec_r000527_11_1;
  int sec_r000527_11_2;
  int sec_r000527_12_1;
  int sec_r000527_12_2;
  int sec_r000527_13_1;
  int sec_r000527_13_2;
  int sec_r000527_14_1;
  int sec_r000527_14_2;
  int sec_r000527_15_1;
  int sec_r000527_15_2;
  int sec_r000527_16_1;
  int sec_r000527_16_2;
  int sec_r000527_17_1;
  int sec_r000527_17_2;
  int sec_r000527_18_1;
  int sec_r000527_18_2;
  int sec_r000527_19_1;
  int sec_r000527_19_2;
  int pub_r000527_0_1;
  int pub_r000527_0_2;
  int pub_r000527_1_1;
  int pub_r000527_1_2;
  int pub_r000527_2_1;
  int pub_r000527_2_2;
  int pub_r000527_3_1;
  int pub_r000527_3_2;
  int pub_r000527_4_1;
  int pub_r000527_4_2;
  int pub_r000527_5_1;
  int pub_r000527_5_2;
  int pub_r000527_6_1;
  int pub_r000527_6_2;
  int pub_r000527_7_1;
  int pub_r000527_7_2;
  int pub_r000527_8_1;
  int pub_r000527_8_2;
  int pub_r000527_9_1;
  int pub_r000527_9_2;
  int pub_r000527_10_1;
  int pub_r000527_10_2;
  int pub_r000527_11_1;
  int pub_r000527_11_2;
  int pub_r000527_12_1;
  int pub_r000527_12_2;
  int pub_r000527_13_1;
  int pub_r000527_13_2;
  int pub_r000527_14_1;
  int pub_r000527_14_2;
  int pub_r000527_15_1;
  int pub_r000527_15_2;
  int pub_r000527_16_1;
  int pub_r000527_16_2;
  int pub_r000527_17_1;
  int pub_r000527_17_2;
  int pub_r000527_18_1;
  int pub_r000527_18_2;
  int pub_r000527_19_1;
  int pub_r000527_19_2;
  int pub_r000527_20_1;
  int pub_r000527_20_2;
  int pub_r000527_21_1;
  int pub_r000527_21_2;
  int pub_r000527_22_1;
  int pub_r000527_22_2;
  int pub_r000527_23_1;
  int pub_r000527_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000527_0_1 >= (-100)) && (pub_r000527_0_1 <= 100));
  __CPROVER_assume((pub_r000527_0_2 >= (-100)) && (pub_r000527_0_2 <= 100));
  __CPROVER_assume((pub_r000527_1_1 >= (-100)) && (pub_r000527_1_1 <= 100));
  __CPROVER_assume((pub_r000527_1_2 >= (-100)) && (pub_r000527_1_2 <= 100));
  __CPROVER_assume((pub_r000527_2_1 >= (-100)) && (pub_r000527_2_1 <= 100));
  __CPROVER_assume((pub_r000527_2_2 >= (-100)) && (pub_r000527_2_2 <= 100));
  __CPROVER_assume((pub_r000527_3_1 >= (-100)) && (pub_r000527_3_1 <= 100));
  __CPROVER_assume((pub_r000527_3_2 >= (-100)) && (pub_r000527_3_2 <= 100));
  __CPROVER_assume((pub_r000527_4_1 >= (-100)) && (pub_r000527_4_1 <= 100));
  __CPROVER_assume((pub_r000527_4_2 >= (-100)) && (pub_r000527_4_2 <= 100));
  __CPROVER_assume((pub_r000527_5_1 >= (-100)) && (pub_r000527_5_1 <= 100));
  __CPROVER_assume((pub_r000527_5_2 >= (-100)) && (pub_r000527_5_2 <= 100));
  __CPROVER_assume((pub_r000527_6_1 >= (-100)) && (pub_r000527_6_1 <= 100));
  __CPROVER_assume((pub_r000527_6_2 >= (-100)) && (pub_r000527_6_2 <= 100));
  __CPROVER_assume((pub_r000527_7_1 >= (-100)) && (pub_r000527_7_1 <= 100));
  __CPROVER_assume((pub_r000527_7_2 >= (-100)) && (pub_r000527_7_2 <= 100));
  __CPROVER_assume((pub_r000527_8_1 >= (-100)) && (pub_r000527_8_1 <= 100));
  __CPROVER_assume((pub_r000527_8_2 >= (-100)) && (pub_r000527_8_2 <= 100));
  __CPROVER_assume((pub_r000527_9_1 >= (-100)) && (pub_r000527_9_1 <= 100));
  __CPROVER_assume((pub_r000527_9_2 >= (-100)) && (pub_r000527_9_2 <= 100));
  __CPROVER_assume((pub_r000527_10_1 >= (-100)) && (pub_r000527_10_1 <= 100));
  __CPROVER_assume((pub_r000527_10_2 >= (-100)) && (pub_r000527_10_2 <= 100));
  __CPROVER_assume((pub_r000527_11_1 >= (-100)) && (pub_r000527_11_1 <= 100));
  __CPROVER_assume((pub_r000527_11_2 >= (-100)) && (pub_r000527_11_2 <= 100));
  __CPROVER_assume((pub_r000527_12_1 >= (-100)) && (pub_r000527_12_1 <= 100));
  __CPROVER_assume((pub_r000527_12_2 >= (-100)) && (pub_r000527_12_2 <= 100));
  __CPROVER_assume((pub_r000527_13_1 >= (-100)) && (pub_r000527_13_1 <= 100));
  __CPROVER_assume((pub_r000527_13_2 >= (-100)) && (pub_r000527_13_2 <= 100));
  __CPROVER_assume((pub_r000527_14_1 >= (-100)) && (pub_r000527_14_1 <= 100));
  __CPROVER_assume((pub_r000527_14_2 >= (-100)) && (pub_r000527_14_2 <= 100));
  __CPROVER_assume((pub_r000527_15_1 >= (-100)) && (pub_r000527_15_1 <= 100));
  __CPROVER_assume((pub_r000527_15_2 >= (-100)) && (pub_r000527_15_2 <= 100));
  __CPROVER_assume((pub_r000527_16_1 >= (-100)) && (pub_r000527_16_1 <= 100));
  __CPROVER_assume((pub_r000527_16_2 >= (-100)) && (pub_r000527_16_2 <= 100));
  __CPROVER_assume((pub_r000527_17_1 >= (-100)) && (pub_r000527_17_1 <= 100));
  __CPROVER_assume((pub_r000527_17_2 >= (-100)) && (pub_r000527_17_2 <= 100));
  __CPROVER_assume((pub_r000527_18_1 >= (-100)) && (pub_r000527_18_1 <= 100));
  __CPROVER_assume((pub_r000527_18_2 >= (-100)) && (pub_r000527_18_2 <= 100));
  __CPROVER_assume((pub_r000527_19_1 >= (-100)) && (pub_r000527_19_1 <= 100));
  __CPROVER_assume((pub_r000527_19_2 >= (-100)) && (pub_r000527_19_2 <= 100));
  __CPROVER_assume((pub_r000527_20_1 >= (-100)) && (pub_r000527_20_1 <= 100));
  __CPROVER_assume((pub_r000527_20_2 >= (-100)) && (pub_r000527_20_2 <= 100));
  __CPROVER_assume((pub_r000527_21_1 >= (-100)) && (pub_r000527_21_1 <= 100));
  __CPROVER_assume((pub_r000527_21_2 >= (-100)) && (pub_r000527_21_2 <= 100));
  __CPROVER_assume((pub_r000527_22_1 >= (-100)) && (pub_r000527_22_1 <= 100));
  __CPROVER_assume((pub_r000527_22_2 >= (-100)) && (pub_r000527_22_2 <= 100));
  __CPROVER_assume((pub_r000527_23_1 >= (-100)) && (pub_r000527_23_1 <= 100));
  __CPROVER_assume((pub_r000527_23_2 >= (-100)) && (pub_r000527_23_2 <= 100));
  __CPROVER_assume((sec_r000527_0_1 >= 0) && (sec_r000527_0_1 <= 255));
  __CPROVER_assume((sec_r000527_0_2 >= 0) && (sec_r000527_0_2 <= 255));
  __CPROVER_assume((sec_r000527_1_1 >= 0) && (sec_r000527_1_1 <= 255));
  __CPROVER_assume((sec_r000527_1_2 >= 0) && (sec_r000527_1_2 <= 255));
  __CPROVER_assume((sec_r000527_2_1 >= 0) && (sec_r000527_2_1 <= 255));
  __CPROVER_assume((sec_r000527_2_2 >= 0) && (sec_r000527_2_2 <= 255));
  __CPROVER_assume((sec_r000527_3_1 >= 0) && (sec_r000527_3_1 <= 255));
  __CPROVER_assume((sec_r000527_3_2 >= 0) && (sec_r000527_3_2 <= 255));
  __CPROVER_assume((sec_r000527_4_1 >= 0) && (sec_r000527_4_1 <= 255));
  __CPROVER_assume((sec_r000527_4_2 >= 0) && (sec_r000527_4_2 <= 255));
  __CPROVER_assume((sec_r000527_5_1 >= 0) && (sec_r000527_5_1 <= 255));
  __CPROVER_assume((sec_r000527_5_2 >= 0) && (sec_r000527_5_2 <= 255));
  __CPROVER_assume((sec_r000527_6_1 >= 0) && (sec_r000527_6_1 <= 255));
  __CPROVER_assume((sec_r000527_6_2 >= 0) && (sec_r000527_6_2 <= 255));
  __CPROVER_assume((sec_r000527_7_1 >= 0) && (sec_r000527_7_1 <= 255));
  __CPROVER_assume((sec_r000527_7_2 >= 0) && (sec_r000527_7_2 <= 255));
  __CPROVER_assume((sec_r000527_8_1 >= 0) && (sec_r000527_8_1 <= 255));
  __CPROVER_assume((sec_r000527_8_2 >= 0) && (sec_r000527_8_2 <= 255));
  __CPROVER_assume((sec_r000527_9_1 >= 0) && (sec_r000527_9_1 <= 255));
  __CPROVER_assume((sec_r000527_9_2 >= 0) && (sec_r000527_9_2 <= 255));
  __CPROVER_assume((sec_r000527_10_1 >= 0) && (sec_r000527_10_1 <= 255));
  __CPROVER_assume((sec_r000527_10_2 >= 0) && (sec_r000527_10_2 <= 255));
  __CPROVER_assume((sec_r000527_11_1 >= 0) && (sec_r000527_11_1 <= 255));
  __CPROVER_assume((sec_r000527_11_2 >= 0) && (sec_r000527_11_2 <= 255));
  __CPROVER_assume((sec_r000527_12_1 >= 0) && (sec_r000527_12_1 <= 255));
  __CPROVER_assume((sec_r000527_12_2 >= 0) && (sec_r000527_12_2 <= 255));
  __CPROVER_assume((sec_r000527_13_1 >= 0) && (sec_r000527_13_1 <= 255));
  __CPROVER_assume((sec_r000527_13_2 >= 0) && (sec_r000527_13_2 <= 255));
  __CPROVER_assume((sec_r000527_14_1 >= 0) && (sec_r000527_14_1 <= 255));
  __CPROVER_assume((sec_r000527_14_2 >= 0) && (sec_r000527_14_2 <= 255));
  __CPROVER_assume((sec_r000527_15_1 >= 0) && (sec_r000527_15_1 <= 255));
  __CPROVER_assume((sec_r000527_15_2 >= 0) && (sec_r000527_15_2 <= 255));
  __CPROVER_assume((sec_r000527_16_1 >= 0) && (sec_r000527_16_1 <= 255));
  __CPROVER_assume((sec_r000527_16_2 >= 0) && (sec_r000527_16_2 <= 255));
  __CPROVER_assume((sec_r000527_17_1 >= 0) && (sec_r000527_17_1 <= 255));
  __CPROVER_assume((sec_r000527_17_2 >= 0) && (sec_r000527_17_2 <= 255));
  __CPROVER_assume((sec_r000527_18_1 >= 0) && (sec_r000527_18_1 <= 255));
  __CPROVER_assume((sec_r000527_18_2 >= 0) && (sec_r000527_18_2 <= 255));
  __CPROVER_assume((sec_r000527_19_1 >= 0) && (sec_r000527_19_1 <= 255));
  __CPROVER_assume((sec_r000527_19_2 >= 0) && (sec_r000527_19_2 <= 255));
  struct MatrixBlock_R000527_2713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000527_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000527_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000527_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000527_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000527_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000527_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000527_0_2 + 7) & 15;
  struct EventLog_R000527_2713_1 st_var_1_1 = {0};
  struct EventLog_R000527_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000527_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000527_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000527_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000527_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000527_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000527_0_2 + 9) & 15;
  struct SensorNode_R000527_2713_2 st_var_2_1 = {0};
  struct SensorNode_R000527_2713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000527_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000527_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000527_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000527_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000527_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000527_0_2 + 11) & 15;
  struct CipherContext_R000527_2713_3 st_var_3_1 = {0};
  struct CipherContext_R000527_2713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000527_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000527_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000527_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000527_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000527_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000527_0_2 + 13) & 15;
  union TelemetryField_R000527_2713_0 u_var_1;
  union TelemetryField_R000527_2713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 46)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 46)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 51)
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
  if (stage_v_1_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 51)
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
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 46)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 46)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 38)
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
  if (stage_v_4_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 38)
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
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
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
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
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

  int stage_v_15_1 = ((st_var_3_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_3_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 49)
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
  if (stage_v_15_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 49)
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
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 37)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 37)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
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
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = ((st_var_2_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_2_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 26)
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
  if (stage_v_22_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 26)
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
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

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
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
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

  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 35) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 36) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 42) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 42) & 15;
  int stage_v_41_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_41_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= stage_v_41_1;
  chk_sum_2 ^= stage_v_41_2;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((st_var_0_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_0_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 42)
    {
      chk_sum_1 ^= stage_v_44_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_44_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 42)
    {
      chk_sum_2 ^= stage_v_44_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = ((st_var_3_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_3_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 46)
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
  if (stage_v_47_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 46)
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
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 30)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 30)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 33)
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
  if (stage_v_49_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 33)
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
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000527_15_1 & 1) != 0)
  {
    if ((sec_r000527_17_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000527_21_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000527_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000527_21_1 + 7) & 127;
  }
  if ((sec_r000527_15_2 & 1) != 0)
  {
    if ((sec_r000527_17_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000527_21_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000527_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000527_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000527_8_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000527_5_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000527_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000527_5_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000527_8_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000527_5_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000527_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000527_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000527_19_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000527_15_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000527_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000527_15_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000527_19_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000527_15_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000527_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000527_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000527_5_1 & 1) != 0)
  {
    if ((sec_r000527_6_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000527_20_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000527_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000527_20_1 + 7) & 127;
  }
  if ((sec_r000527_5_2 & 1) != 0)
  {
    if ((sec_r000527_6_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000527_20_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000527_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000527_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000527_3_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000527_23_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000527_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000527_23_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000527_3_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000527_23_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000527_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000527_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000527_0_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000527_18_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000527_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000527_18_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000527_0_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000527_18_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000527_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000527_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000527_10_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000527_22_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000527_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000527_22_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000527_10_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000527_22_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000527_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000527_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000527_7_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000527_6_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000527_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000527_6_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000527_7_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000527_6_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000527_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000527_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000527_1_1 & 1) != 0)
  {
    if ((sec_r000527_13_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000527_22_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000527_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000527_22_1 + 7) & 127;
  }
  if ((sec_r000527_1_2 & 1) != 0)
  {
    if ((sec_r000527_13_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000527_22_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000527_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000527_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000527_8_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000527_18_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000527_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000527_18_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000527_8_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000527_18_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000527_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000527_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000527_18_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000527_17_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000527_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000527_17_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000527_18_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000527_17_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000527_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000527_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000527_1_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000527_12_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000527_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000527_12_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000527_1_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000527_12_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000527_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000527_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000527_4_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000527_0_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000527_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000527_0_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000527_4_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000527_0_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000527_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000527_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000527_6_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000527_13_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000527_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000527_13_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000527_6_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000527_13_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000527_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000527_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000527_19_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000527_0_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000527_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000527_0_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000527_19_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000527_0_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000527_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000527_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000527_19_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000527_21_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000527_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000527_21_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000527_19_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000527_21_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000527_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000527_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000527_15_1 & 1) != 0)
  {
    if ((sec_r000527_9_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000527_12_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000527_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000527_12_1 + 7) & 127;
  }
  if ((sec_r000527_15_2 & 1) != 0)
  {
    if ((sec_r000527_9_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000527_12_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000527_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000527_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000527_11_1 & 1) != 0)
  {
    if ((sec_r000527_7_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000527_0_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000527_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000527_0_1 + 7) & 127;
  }
  if ((sec_r000527_11_2 & 1) != 0)
  {
    if ((sec_r000527_7_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000527_0_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000527_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000527_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000527_1_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000527_9_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000527_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000527_9_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000527_1_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000527_9_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000527_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000527_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000527_0_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000527_23_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000527_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000527_23_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000527_0_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000527_23_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000527_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000527_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000527_12_1 & 1) != 0)
  {
    if ((sec_r000527_0_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000527_10_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000527_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000527_10_1 + 7) & 127;
  }
  if ((sec_r000527_12_2 & 1) != 0)
  {
    if ((sec_r000527_0_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000527_10_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000527_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000527_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000527_3_1 & 1) != 0)
  {
    if ((sec_r000527_9_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000527_21_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000527_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000527_21_1 + 7) & 127;
  }
  if ((sec_r000527_3_2 & 1) != 0)
  {
    if ((sec_r000527_9_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000527_21_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000527_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000527_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000527_2_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000527_16_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000527_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000527_16_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000527_2_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000527_16_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000527_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000527_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000527_11_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000527_21_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000527_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000527_21_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000527_11_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000527_21_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000527_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000527_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000527_15_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000527_3_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000527_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000527_3_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000527_15_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000527_3_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000527_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000527_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000527_7_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000527_0_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000527_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000527_0_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000527_7_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000527_0_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000527_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000527_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000527_11_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000527_17_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000527_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000527_17_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000527_11_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000527_17_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000527_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000527_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000527_1_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000527_7_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000527_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000527_7_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000527_1_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000527_7_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000527_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000527_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000527_13_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000527_23_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000527_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000527_23_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000527_13_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000527_23_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000527_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000527_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000527_0_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000527_21_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000527_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000527_21_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000527_0_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000527_21_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000527_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000527_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000527_4_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000527_17_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000527_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000527_17_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000527_4_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000527_17_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000527_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000527_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000527_4_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000527_16_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000527_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000527_16_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000527_4_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000527_16_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000527_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000527_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000527_6_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000527_10_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000527_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000527_10_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000527_6_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000527_10_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000527_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000527_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000527_1_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000527_16_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000527_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000527_16_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000527_1_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000527_16_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000527_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000527_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000527_9_1 & 1) != 0)
  {
    if ((sec_r000527_15_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000527_9_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000527_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000527_9_1 + 7) & 127;
  }
  if ((sec_r000527_9_2 & 1) != 0)
  {
    if ((sec_r000527_15_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000527_9_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000527_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000527_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000527_1_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000527_5_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000527_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000527_5_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000527_1_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000527_5_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000527_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000527_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000527_0_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000527_10_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000527_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000527_10_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000527_0_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000527_10_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000527_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000527_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000527_13_1 & 1) != 0)
  {
    if ((sec_r000527_3_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000527_4_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000527_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000527_4_1 + 7) & 127;
  }
  if ((sec_r000527_13_2 & 1) != 0)
  {
    if ((sec_r000527_3_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000527_4_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000527_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000527_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000527_13_1 & 1) != 0)
  {
    if ((sec_r000527_10_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000527_15_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000527_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000527_15_1 + 7) & 127;
  }
  if ((sec_r000527_13_2 & 1) != 0)
  {
    if ((sec_r000527_10_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000527_15_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000527_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000527_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000527_16_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000527_14_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000527_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000527_14_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000527_16_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000527_14_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000527_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000527_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000527_7_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000527_4_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000527_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000527_4_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000527_7_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000527_4_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000527_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000527_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000527_18_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000527_2_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000527_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000527_2_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000527_18_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000527_2_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000527_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000527_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000527_7_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000527_1_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000527_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000527_1_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000527_7_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000527_1_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000527_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000527_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000527_10_1 & 1) != 0)
  {
    if ((sec_r000527_17_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000527_4_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000527_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000527_4_1 + 7) & 127;
  }
  if ((sec_r000527_10_2 & 1) != 0)
  {
    if ((sec_r000527_17_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000527_4_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000527_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000527_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000527_4_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000527_15_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000527_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000527_15_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000527_4_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000527_15_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000527_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000527_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000527_13_1 & 1) != 0)
  {
    if ((sec_r000527_16_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000527_10_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000527_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000527_10_1 + 7) & 127;
  }
  if ((sec_r000527_13_2 & 1) != 0)
  {
    if ((sec_r000527_16_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000527_10_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000527_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000527_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000527_9_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000527_0_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000527_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000527_0_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000527_9_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000527_0_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000527_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000527_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000527_4_1 & 1) != 0)
  {
    if ((sec_r000527_12_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000527_14_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000527_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000527_14_1 + 7) & 127;
  }
  if ((sec_r000527_4_2 & 1) != 0)
  {
    if ((sec_r000527_12_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000527_14_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000527_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000527_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000527_18_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000527_19_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000527_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000527_19_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000527_18_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000527_19_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000527_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000527_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000527_13_1 & 1) != 0)
  {
    if ((sec_r000527_7_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000527_18_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000527_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000527_18_1 + 7) & 127;
  }
  if ((sec_r000527_13_2 & 1) != 0)
  {
    if ((sec_r000527_7_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000527_18_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000527_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000527_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000527_18_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000527_21_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000527_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000527_21_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000527_18_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000527_21_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000527_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000527_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000527_4_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000527_4_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000527_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000527_4_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000527_4_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000527_4_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000527_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000527_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000527_14_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000527_11_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000527_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000527_11_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000527_14_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000527_11_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000527_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000527_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000527_8_1 & 1) != 0)
  {
    if ((sec_r000527_11_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000527_11_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000527_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000527_11_1 + 7) & 127;
  }
  if ((sec_r000527_8_2 & 1) != 0)
  {
    if ((sec_r000527_11_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000527_11_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000527_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000527_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000527_11_1 & 1) != 0)
  {
    if ((sec_r000527_18_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000527_18_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000527_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000527_18_1 + 7) & 127;
  }
  if ((sec_r000527_11_2 & 1) != 0)
  {
    if ((sec_r000527_18_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000527_18_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000527_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000527_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000527_17_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000527_5_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000527_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000527_5_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000527_17_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000527_5_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000527_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000527_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000527_16_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000527_12_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000527_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000527_12_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000527_16_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000527_12_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000527_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000527_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000527_4_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000527_13_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000527_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000527_13_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000527_4_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000527_13_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000527_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000527_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000527_4_1 & 1) != 0)
  {
    if ((sec_r000527_11_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000527_1_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000527_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000527_1_1 + 7) & 127;
  }
  if ((sec_r000527_4_2 & 1) != 0)
  {
    if ((sec_r000527_11_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000527_1_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000527_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000527_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000527_4_1 & 1) != 0)
  {
    if ((sec_r000527_18_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000527_21_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000527_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000527_21_1 + 7) & 127;
  }
  if ((sec_r000527_4_2 & 1) != 0)
  {
    if ((sec_r000527_18_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000527_21_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000527_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000527_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000527_11_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000527_18_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000527_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000527_18_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000527_11_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000527_18_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000527_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000527_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000527_11_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000527_20_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000527_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000527_20_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000527_11_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000527_20_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000527_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000527_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000527_9_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000527_16_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000527_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000527_16_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000527_9_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000527_16_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000527_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000527_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000527_9_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000527_23_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000527_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000527_23_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000527_9_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000527_23_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000527_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000527_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000527_11_1 & 1) != 0)
  {
    if ((sec_r000527_11_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000527_16_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000527_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000527_16_1 + 7) & 127;
  }
  if ((sec_r000527_11_2 & 1) != 0)
  {
    if ((sec_r000527_11_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000527_16_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000527_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000527_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000527_4_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000527_10_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000527_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000527_10_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000527_4_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000527_10_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000527_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000527_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000527_9_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000527_5_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000527_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000527_5_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000527_9_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000527_5_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000527_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000527_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000527_10_1 & 1) != 0)
  {
    if ((sec_r000527_7_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000527_8_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000527_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000527_8_1 + 7) & 127;
  }
  if ((sec_r000527_10_2 & 1) != 0)
  {
    if ((sec_r000527_7_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000527_8_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000527_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000527_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000527_12_1 & 1) != 0)
  {
    if ((sec_r000527_6_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000527_4_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000527_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000527_4_1 + 7) & 127;
  }
  if ((sec_r000527_12_2 & 1) != 0)
  {
    if ((sec_r000527_6_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000527_4_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000527_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000527_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000527_7_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000527_18_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000527_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000527_18_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000527_7_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000527_18_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000527_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000527_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000527_6_1 == pub_r000527_6_2);
  __CPROVER_assume(sec_r000527_18_1 != sec_r000527_18_2);
  __CPROVER_assume(pub_r000527_5_1 == pub_r000527_5_2);
  __CPROVER_assume(sec_r000527_1_1 != sec_r000527_1_2);
  __CPROVER_assume(pub_r000527_9_1 == pub_r000527_9_2);
  __CPROVER_assume(sec_r000527_9_1 != sec_r000527_9_2);
  __CPROVER_assume(pub_r000527_18_1 == pub_r000527_18_2);
  __CPROVER_assume(sec_r000527_6_1 != sec_r000527_6_2);
  __CPROVER_assume(pub_r000527_3_1 == pub_r000527_3_2);
  __CPROVER_assume(sec_r000527_16_1 != sec_r000527_16_2);
  __CPROVER_assume(sec_r000527_8_1 != sec_r000527_8_2);
  __CPROVER_assume(pub_r000527_2_1 == pub_r000527_2_2);
  __CPROVER_assume(pub_r000527_19_1 == pub_r000527_19_2);
  __CPROVER_assume(sec_r000527_5_1 != sec_r000527_5_2);
  __CPROVER_assume(pub_r000527_17_1 == pub_r000527_17_2);
  __CPROVER_assume(sec_r000527_7_1 != sec_r000527_7_2);
  __CPROVER_assume(pub_r000527_14_1 == pub_r000527_14_2);
  __CPROVER_assume(pub_r000527_4_1 == pub_r000527_4_2);
  __CPROVER_assume(pub_r000527_0_1 == pub_r000527_0_2);
  __CPROVER_assume(pub_r000527_15_1 == pub_r000527_15_2);
  __CPROVER_assume(sec_r000527_11_1 != sec_r000527_11_2);
  __CPROVER_assume(sec_r000527_15_1 != sec_r000527_15_2);
  __CPROVER_assume(pub_r000527_7_1 == pub_r000527_7_2);
  __CPROVER_assume(pub_r000527_1_1 == pub_r000527_1_2);
  __CPROVER_assume(sec_r000527_10_1 != sec_r000527_10_2);
  __CPROVER_assume(pub_r000527_12_1 == pub_r000527_12_2);
  __CPROVER_assume(sec_r000527_14_1 != sec_r000527_14_2);
  __CPROVER_assume(sec_r000527_2_1 != sec_r000527_2_2);
  __CPROVER_assume(sec_r000527_12_1 != sec_r000527_12_2);
  __CPROVER_assume(pub_r000527_10_1 == pub_r000527_10_2);
  __CPROVER_assume(pub_r000527_21_1 == pub_r000527_21_2);
  __CPROVER_assume(sec_r000527_19_1 != sec_r000527_19_2);
  __CPROVER_assume(pub_r000527_23_1 == pub_r000527_23_2);
  __CPROVER_assume(sec_r000527_4_1 != sec_r000527_4_2);
  __CPROVER_assume(pub_r000527_11_1 == pub_r000527_11_2);
  __CPROVER_assume(pub_r000527_22_1 == pub_r000527_22_2);
  __CPROVER_assume(pub_r000527_8_1 == pub_r000527_8_2);
  __CPROVER_assume(sec_r000527_3_1 != sec_r000527_3_2);
  __CPROVER_assume(pub_r000527_16_1 == pub_r000527_16_2);
  __CPROVER_assume(sec_r000527_0_1 != sec_r000527_0_2);
  __CPROVER_assume(pub_r000527_13_1 == pub_r000527_13_2);
  __CPROVER_assume(pub_r000527_20_1 == pub_r000527_20_2);
  __CPROVER_assume(sec_r000527_13_1 != sec_r000527_13_2);
  __CPROVER_assume(sec_r000527_17_1 != sec_r000527_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.iv == st_var_3_2.iv);
  assert(st_var_3_1.round_key == st_var_3_2.round_key);
  assert(st_var_3_1.flags == st_var_3_2.flags);
  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.counter == st_var_3_2.counter);
  assert(st_var_3_1.tag == st_var_3_2.tag);
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
}


