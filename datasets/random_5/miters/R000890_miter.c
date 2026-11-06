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
struct FilterState_R000890_9013_0
{
  unsigned char prev_in;
  unsigned char cutoff;
  short damping;
  int buffer[3];
};
struct Transaction_R000890_9013_1
{
  short rate;
  short auth_code;
  int balance;
  int buffer[3];
};
union PacketPayload_R000890_9013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000890_9013_1
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
void fn_R000890_9013_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int window_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_83_1) & 63;
  aux_2 = (aux_2 + window_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_84_1)
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

  switch (factor_84_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_44_1 > 44)
  {
    acc_1 = ((acc_1 + (accumulator_44_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_44_2 > 44)
  {
    acc_2 = ((acc_2 + (accumulator_44_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_83_1 == window_83_2);
  assert(factor_84_1 == factor_84_2);
  assert(accumulator_44_1 == accumulator_44_2);
}

int fn_R000890_9013_0(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int window_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_83) & 63;
  acc ^= aux;
  int factor_84 = (aux + st.buffer[1]) & 3;
  switch (factor_84)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_44 > 44)
  {
    acc = ((acc + (accumulator_44 * 2)) + 5) & 127;
    aux ^= accumulator_44 & 15;
  }
  else
  {
    acc = ((acc - accumulator_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000890_9013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int offset_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_21_1 > 32)
  {
    acc_1 = ((acc_1 + (offset_21_1 * 2)) + 5) & 127;
    aux_1 ^= offset_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_21_2 > 32)
  {
    acc_2 = ((acc_2 + (offset_21_2 * 2)) + 5) & 127;
    aux_2 ^= offset_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_37_1 = local_arr_1[aux_1 % 3];
  int bound_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_37_2 * 2)) & 127;
  int coefficient_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_89_1)
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

  switch (coefficient_89_2)
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

  int metric_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_59_1) & 63;
  aux_2 = (aux_2 + metric_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_21_1 == offset_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_37_1 == bound_37_2);
  assert(coefficient_89_1 == coefficient_89_2);
  assert(metric_59_1 == metric_59_2);
}

int fn_R000890_9013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int offset_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_21 > 32)
  {
    acc = ((acc + (offset_21 * 2)) + 5) & 127;
    aux ^= offset_21 & 15;
  }
  else
  {
    acc = ((acc - offset_21) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_37 = local_arr[aux % 3];
  acc = (acc + (bound_37 * 2)) & 127;
  int coefficient_89 = (aux + st.buffer[1]) & 3;
  switch (coefficient_89)
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

  int metric_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000890_9013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int cursor_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_72_1) & 63;
  aux_2 = (aux_2 + cursor_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_37_1 = local_arr_1[aux_1 % 3];
  int vector_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_37_2 * 2)) & 127;
  int damping_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_30_1)
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

  switch (damping_30_2)
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

  int tracker_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_77_1 > 47)
  {
    acc_1 = ((acc_1 + (tracker_77_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_77_2 > 47)
  {
    acc_2 = ((acc_2 + (tracker_77_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_72_1 == cursor_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_37_1 == vector_37_2);
  assert(damping_30_1 == damping_30_2);
  assert(tracker_77_1 == tracker_77_2);
}

int fn_R000890_9013_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int cursor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_37 = local_arr[aux % 3];
  acc = (acc + (vector_37 * 2)) & 127;
  int damping_30 = (aux + st.buffer[1]) & 3;
  switch (damping_30)
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

  int tracker_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_77 > 47)
  {
    acc = ((acc + (tracker_77 * 2)) + 5) & 127;
    aux ^= tracker_77 & 15;
  }
  else
  {
    acc = ((acc - tracker_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000890_9013_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_95_1 = local_arr_1[aux_1 % 3];
  int residue_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_95_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_50_1) & 63;
  aux_2 = (aux_2 + weight_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_95_1 == residue_95_2);
  assert(weight_50_1 == weight_50_2);
}

int fn_R000890_9013_3(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int residue_95 = local_arr[aux % 3];
  acc = (acc + (residue_95 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_50) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000890_9013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st_1 = {0};
  struct FilterState_R000890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_59_1 > 22)
  {
    acc_1 = ((acc_1 + (offset_59_1 * 2)) + 5) & 127;
    aux_1 ^= offset_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_59_2 > 22)
  {
    acc_2 = ((acc_2 + (offset_59_2 * 2)) + 5) & 127;
    aux_2 ^= offset_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_49_1 = local_arr_1[aux_1 % 3];
  int coefficient_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_49_2 * 2)) & 127;
  int factor_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_41_1)
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

  switch (factor_41_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_59_1 == offset_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_49_1 == coefficient_49_2);
  assert(factor_41_1 == factor_41_2);
}

int fn_R000890_9013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_59 > 22)
  {
    acc = ((acc + (offset_59 * 2)) + 5) & 127;
    aux ^= offset_59 & 15;
  }
  else
  {
    acc = ((acc - offset_59) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_49 = local_arr[aux % 3];
  acc = (acc + (coefficient_49 * 2)) & 127;
  int factor_41 = (aux + st.buffer[1]) & 3;
  switch (factor_41)
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

void fn_R000890_9013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_15_1 = local_arr_1[aux_1 % 3];
  int stride_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_15_2 * 2)) & 127;
  int window_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_35_1) & 63;
  aux_2 = (aux_2 + window_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_70_1 > 13)
  {
    acc_1 = ((acc_1 + (checksum_70_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_70_2 > 13)
  {
    acc_2 = ((acc_2 + (checksum_70_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_15_1 == stride_15_2);
  assert(window_35_1 == window_35_2);
  assert(checksum_70_1 == checksum_70_2);
}

int fn_R000890_9013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int stride_15 = local_arr[aux % 3];
  acc = (acc + (stride_15 * 2)) & 127;
  int window_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_70 > 13)
  {
    acc = ((acc + (checksum_70 * 2)) + 5) & 127;
    aux ^= checksum_70 & 15;
  }
  else
  {
    acc = ((acc - checksum_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000890_9013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int vector_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_88_1) & 63;
  aux_2 = (aux_2 + vector_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_88_1 > 34)
  {
    acc_1 = ((acc_1 + (cursor_88_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_88_2 > 34)
  {
    acc_2 = ((acc_2 + (cursor_88_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_88_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_88_1 == vector_88_2);
  assert(cursor_88_1 == cursor_88_2);
}

int fn_R000890_9013_6(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int vector_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_88) & 63;
  acc ^= aux;
  int cursor_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_88 > 34)
  {
    acc = ((acc + (cursor_88 * 2)) + 5) & 127;
    aux ^= cursor_88 & 15;
  }
  else
  {
    acc = ((acc - cursor_88) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000890_9013_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st_1 = {0};
  struct FilterState_R000890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int scale_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_18_1)
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

  switch (scale_18_2)
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

  int window_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_31_1) & 63;
  aux_2 = (aux_2 + window_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_34_1 = local_arr_1[aux_1 % 3];
  int vector_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_18_1 == scale_18_2);
  assert(window_31_1 == window_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_34_1 == vector_34_2);
}

int fn_R000890_9013_7(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int scale_18 = (aux + st.buffer[1]) & 3;
  switch (scale_18)
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

  int window_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_31) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_34 = local_arr[aux % 3];
  acc = (acc + (vector_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000890_9013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int margin_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_60_1 > 48)
  {
    acc_1 = ((acc_1 + (margin_60_1 * 2)) + 5) & 127;
    aux_1 ^= margin_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_60_2 > 48)
  {
    acc_2 = ((acc_2 + (margin_60_2 * 2)) + 5) & 127;
    aux_2 ^= margin_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_99_1)
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

  switch (accumulator_99_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_60_1 == margin_60_2);
  assert(accumulator_99_1 == accumulator_99_2);
}

int fn_R000890_9013_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int margin_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_60 > 48)
  {
    acc = ((acc + (margin_60 * 2)) + 5) & 127;
    aux ^= margin_60 & 15;
  }
  else
  {
    acc = ((acc - margin_60) + 11) & 127;
    aux += 3;
  }
  int accumulator_99 = (aux + st.buffer[1]) & 3;
  switch (accumulator_99)
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

void fn_R000890_9013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_95_1) & 63;
  aux_2 = (aux_2 + cursor_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_95_1 == cursor_95_2);
}

int fn_R000890_9013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_95) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000890_9013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st_1 = {0};
  struct FilterState_R000890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int parity_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_11_1) & 63;
  aux_2 = (aux_2 + parity_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_40_1 > 49)
  {
    acc_1 = ((acc_1 + (anchor_40_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_40_2 > 49)
  {
    acc_2 = ((acc_2 + (anchor_40_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_40_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_18_1 = local_arr_1[aux_1 % 3];
  int tracker_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_18_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_11_1 == parity_11_2);
  assert(anchor_40_1 == anchor_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_18_1 == tracker_18_2);
}

int fn_R000890_9013_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int parity_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_11) & 63;
  acc ^= aux;
  int anchor_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_40 > 49)
  {
    acc = ((acc + (anchor_40 * 2)) + 5) & 127;
    aux ^= anchor_40 & 15;
  }
  else
  {
    acc = ((acc - anchor_40) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tracker_18 = local_arr[aux % 3];
  acc = (acc + (tracker_18 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000890_9013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_43_1 = local_arr_1[aux_1 % 3];
  int window_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_43_2 * 2)) & 127;
  int vector_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_98_1 > 34)
  {
    acc_1 = ((acc_1 + (vector_98_1 * 2)) + 5) & 127;
    aux_1 ^= vector_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_98_2 > 34)
  {
    acc_2 = ((acc_2 + (vector_98_2 * 2)) + 5) & 127;
    aux_2 ^= vector_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_15_1) & 63;
  aux_2 = (aux_2 + threshold_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_43_1 == window_43_2);
  assert(vector_98_1 == vector_98_2);
  assert(threshold_15_1 == threshold_15_2);
}

int fn_R000890_9013_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_43 = local_arr[aux % 3];
  acc = (acc + (window_43 * 2)) & 127;
  int vector_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_98 > 34)
  {
    acc = ((acc + (vector_98 * 2)) + 5) & 127;
    aux ^= vector_98 & 15;
  }
  else
  {
    acc = ((acc - vector_98) + 11) & 127;
    aux += 3;
  }
  int threshold_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000890_9013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int pivot_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_72_1) & 63;
  aux_2 = (aux_2 + pivot_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_34_1 > 41)
  {
    acc_1 = ((acc_1 + (residue_34_1 * 2)) + 5) & 127;
    aux_1 ^= residue_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_34_2 > 41)
  {
    acc_2 = ((acc_2 + (residue_34_2 * 2)) + 5) & 127;
    aux_2 ^= residue_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_72_1 == pivot_72_2);
  assert(residue_34_1 == residue_34_2);
}

int fn_R000890_9013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int pivot_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_72) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_34 > 41)
  {
    acc = ((acc + (residue_34 * 2)) + 5) & 127;
    aux ^= residue_34 & 15;
  }
  else
  {
    acc = ((acc - residue_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000890_9013_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st_1 = {0};
  struct FilterState_R000890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_12_1) & 63;
  aux_2 = (aux_2 + phase_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_91_1 = local_arr_1[aux_1 % 3];
  int segment_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_91_2 * 2)) & 127;
  int damping_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_37_1)
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

  switch (damping_37_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_12_1 == phase_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_91_1 == segment_91_2);
  assert(damping_37_1 == damping_37_2);
}

int fn_R000890_9013_13(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_12) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_91 = local_arr[aux % 3];
  acc = (acc + (segment_91 * 2)) & 127;
  int damping_37 = (aux + st.buffer[1]) & 3;
  switch (damping_37)
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

void fn_R000890_9013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int phase_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_38_1)
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

  switch (phase_38_2)
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
  int tally_75_1 = local_arr_1[aux_1 % 3];
  int tally_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_75_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_38_1 == phase_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_75_1 == tally_75_2);
}

int fn_R000890_9013_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int phase_38 = (aux + st.buffer[1]) & 3;
  switch (phase_38)
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
  int tally_75 = local_arr[aux % 3];
  acc = (acc + (tally_75 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000890_9013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int tally_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_19_1 > 31)
  {
    acc_1 = ((acc_1 + (tally_19_1 * 2)) + 5) & 127;
    aux_1 ^= tally_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_19_2 > 31)
  {
    acc_2 = ((acc_2 + (tally_19_2 * 2)) + 5) & 127;
    aux_2 ^= tally_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_55_1)
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

  switch (cursor_55_2)
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

  int delta_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_38_1) & 63;
  aux_2 = (aux_2 + delta_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_19_1 == tally_19_2);
  assert(cursor_55_1 == cursor_55_2);
  assert(delta_38_1 == delta_38_2);
}

int fn_R000890_9013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int tally_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_19 > 31)
  {
    acc = ((acc + (tally_19 * 2)) + 5) & 127;
    aux ^= tally_19 & 15;
  }
  else
  {
    acc = ((acc - tally_19) + 11) & 127;
    aux += 3;
  }
  int cursor_55 = (aux + st.buffer[1]) & 3;
  switch (cursor_55)
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

  int delta_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000890_9013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st_1 = {0};
  struct FilterState_R000890_9013_0 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_95_1 = local_arr_1[aux_1 % 3];
  int quantum_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_95_1 == quantum_95_2);
}

int fn_R000890_9013_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quantum_95 = local_arr[aux % 3];
  acc = (acc + (quantum_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000890_9013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st_1 = {0};
  struct FilterState_R000890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int factor_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_27_1) & 63;
  aux_2 = (aux_2 + factor_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_31_1 > 32)
  {
    acc_1 = ((acc_1 + (stride_31_1 * 2)) + 5) & 127;
    aux_1 ^= stride_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_31_2 > 32)
  {
    acc_2 = ((acc_2 + (stride_31_2 * 2)) + 5) & 127;
    aux_2 ^= stride_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_27_1 == factor_27_2);
  assert(stride_31_1 == stride_31_2);
}

int fn_R000890_9013_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int factor_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_27) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_31 > 32)
  {
    acc = ((acc + (stride_31 * 2)) + 5) & 127;
    aux ^= stride_31 & 15;
  }
  else
  {
    acc = ((acc - stride_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000890_9013_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int metric_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_84_1)
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

  switch (metric_84_2)
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

  int factor_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_61_1 > 15)
  {
    acc_1 = ((acc_1 + (factor_61_1 * 2)) + 5) & 127;
    aux_1 ^= factor_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_61_2 > 15)
  {
    acc_2 = ((acc_2 + (factor_61_2 * 2)) + 5) & 127;
    aux_2 ^= factor_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_84_1 == metric_84_2);
  assert(factor_61_1 == factor_61_2);
}

int fn_R000890_9013_18(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int metric_84 = (aux + st.buffer[1]) & 3;
  switch (metric_84)
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

  int factor_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_61 > 15)
  {
    acc = ((acc + (factor_61 * 2)) + 5) & 127;
    aux ^= factor_61 & 15;
  }
  else
  {
    acc = ((acc - factor_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000890_9013_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int factor_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_41_1 > 36)
  {
    acc_1 = ((acc_1 + (factor_41_1 * 2)) + 5) & 127;
    aux_1 ^= factor_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_41_2 > 36)
  {
    acc_2 = ((acc_2 + (factor_41_2 * 2)) + 5) & 127;
    aux_2 ^= factor_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_45_1)
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

  switch (accumulator_45_2)
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

  int mask_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_71_1) & 63;
  aux_2 = (aux_2 + mask_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_60_1 = local_arr_1[aux_1 % 3];
  int accumulator_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_41_1 == factor_41_2);
  assert(accumulator_45_1 == accumulator_45_2);
  assert(mask_71_1 == mask_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_60_1 == accumulator_60_2);
}

int fn_R000890_9013_19(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int factor_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_41 > 36)
  {
    acc = ((acc + (factor_41 * 2)) + 5) & 127;
    aux ^= factor_41 & 15;
  }
  else
  {
    acc = ((acc - factor_41) + 11) & 127;
    aux += 3;
  }
  int accumulator_45 = (aux + st.buffer[1]) & 3;
  switch (accumulator_45)
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

  int mask_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_71) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_60 = local_arr[aux % 3];
  acc = (acc + (accumulator_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000890_9013_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st_1 = {0};
  struct Transaction_R000890_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int weight_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_96_1) & 63;
  aux_2 = (aux_2 + weight_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_78_1 > 49)
  {
    acc_1 = ((acc_1 + (mask_78_1 * 2)) + 5) & 127;
    aux_1 ^= mask_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_78_2 > 49)
  {
    acc_2 = ((acc_2 + (mask_78_2 * 2)) + 5) & 127;
    aux_2 ^= mask_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_68_1)
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

  switch (segment_68_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_96_1 == weight_96_2);
  assert(mask_78_1 == mask_78_2);
  assert(segment_68_1 == segment_68_2);
}

int fn_R000890_9013_20(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000890_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int weight_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_96) & 63;
  acc ^= aux;
  int mask_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_78 > 49)
  {
    acc = ((acc + (mask_78 * 2)) + 5) & 127;
    aux ^= mask_78 & 15;
  }
  else
  {
    acc = ((acc - mask_78) + 11) & 127;
    aux += 3;
  }
  int segment_68 = (aux + st.buffer[1]) & 3;
  switch (segment_68)
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

void fn_R000890_9013_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st_1 = {0};
  struct FilterState_R000890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int index_reg_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_37_1 > 15)
  {
    acc_1 = ((acc_1 + (index_reg_37_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_37_2 > 15)
  {
    acc_2 = ((acc_2 + (index_reg_37_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_37_1 == index_reg_37_2);
}

int fn_R000890_9013_21(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int index_reg_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_37 > 15)
  {
    acc = ((acc + (index_reg_37 * 2)) + 5) & 127;
    aux ^= index_reg_37 & 15;
  }
  else
  {
    acc = ((acc - index_reg_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000890_9013_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st_1 = {0};
  struct FilterState_R000890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_50_1 > 34)
  {
    acc_1 = ((acc_1 + (threshold_50_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_50_2 > 34)
  {
    acc_2 = ((acc_2 + (threshold_50_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_50_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_17_1)
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

  switch (quantum_17_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_50_1 == threshold_50_2);
  assert(quantum_17_1 == quantum_17_2);
}

int fn_R000890_9013_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_50 > 34)
  {
    acc = ((acc + (threshold_50 * 2)) + 5) & 127;
    aux ^= threshold_50 & 15;
  }
  else
  {
    acc = ((acc - threshold_50) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_17 = (aux + st.buffer[1]) & 3;
  switch (quantum_17)
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

void fn_R000890_9013_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st_1 = {0};
  struct FilterState_R000890_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int checksum_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_23_1)
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

  switch (checksum_23_2)
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

  int damping_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_87_1) & 63;
  aux_2 = (aux_2 + damping_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_83_1 > 13)
  {
    acc_1 = ((acc_1 + (factor_83_1 * 2)) + 5) & 127;
    aux_1 ^= factor_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_83_2 > 13)
  {
    acc_2 = ((acc_2 + (factor_83_2 * 2)) + 5) & 127;
    aux_2 ^= factor_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_23_1 == checksum_23_2);
  assert(damping_87_1 == damping_87_2);
  assert(factor_83_1 == factor_83_2);
}

int fn_R000890_9013_23(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000890_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int checksum_23 = (aux + st.buffer[1]) & 3;
  switch (checksum_23)
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

  int damping_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_87) & 63;
  acc ^= aux;
  int factor_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_83 > 13)
  {
    acc = ((acc + (factor_83 * 2)) + 5) & 127;
    aux ^= factor_83 & 15;
  }
  else
  {
    acc = ((acc - factor_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000890_0_1;
  int sec_r000890_0_2;
  int sec_r000890_1_1;
  int sec_r000890_1_2;
  int sec_r000890_2_1;
  int sec_r000890_2_2;
  int sec_r000890_3_1;
  int sec_r000890_3_2;
  int sec_r000890_4_1;
  int sec_r000890_4_2;
  int sec_r000890_5_1;
  int sec_r000890_5_2;
  int sec_r000890_6_1;
  int sec_r000890_6_2;
  int sec_r000890_7_1;
  int sec_r000890_7_2;
  int sec_r000890_8_1;
  int sec_r000890_8_2;
  int sec_r000890_9_1;
  int sec_r000890_9_2;
  int sec_r000890_10_1;
  int sec_r000890_10_2;
  int sec_r000890_11_1;
  int sec_r000890_11_2;
  int sec_r000890_12_1;
  int sec_r000890_12_2;
  int sec_r000890_13_1;
  int sec_r000890_13_2;
  int sec_r000890_14_1;
  int sec_r000890_14_2;
  int sec_r000890_15_1;
  int sec_r000890_15_2;
  int pub_r000890_0_1;
  int pub_r000890_0_2;
  int pub_r000890_1_1;
  int pub_r000890_1_2;
  int pub_r000890_2_1;
  int pub_r000890_2_2;
  int pub_r000890_3_1;
  int pub_r000890_3_2;
  int pub_r000890_4_1;
  int pub_r000890_4_2;
  int pub_r000890_5_1;
  int pub_r000890_5_2;
  int pub_r000890_6_1;
  int pub_r000890_6_2;
  int pub_r000890_7_1;
  int pub_r000890_7_2;
  int pub_r000890_8_1;
  int pub_r000890_8_2;
  int pub_r000890_9_1;
  int pub_r000890_9_2;
  int pub_r000890_10_1;
  int pub_r000890_10_2;
  int pub_r000890_11_1;
  int pub_r000890_11_2;
  int pub_r000890_12_1;
  int pub_r000890_12_2;
  int pub_r000890_13_1;
  int pub_r000890_13_2;
  int pub_r000890_14_1;
  int pub_r000890_14_2;
  int pub_r000890_15_1;
  int pub_r000890_15_2;
  int pub_r000890_16_1;
  int pub_r000890_16_2;
  int pub_r000890_17_1;
  int pub_r000890_17_2;
  int pub_r000890_18_1;
  int pub_r000890_18_2;
  int pub_r000890_19_1;
  int pub_r000890_19_2;
  int pub_r000890_20_1;
  int pub_r000890_20_2;
  int pub_r000890_21_1;
  int pub_r000890_21_2;
  int pub_r000890_22_1;
  int pub_r000890_22_2;
  int pub_r000890_23_1;
  int pub_r000890_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000890_0_1 >= (-100)) && (pub_r000890_0_1 <= 100));
  __CPROVER_assume((pub_r000890_0_2 >= (-100)) && (pub_r000890_0_2 <= 100));
  __CPROVER_assume((pub_r000890_1_1 >= (-100)) && (pub_r000890_1_1 <= 100));
  __CPROVER_assume((pub_r000890_1_2 >= (-100)) && (pub_r000890_1_2 <= 100));
  __CPROVER_assume((pub_r000890_2_1 >= (-100)) && (pub_r000890_2_1 <= 100));
  __CPROVER_assume((pub_r000890_2_2 >= (-100)) && (pub_r000890_2_2 <= 100));
  __CPROVER_assume((pub_r000890_3_1 >= (-100)) && (pub_r000890_3_1 <= 100));
  __CPROVER_assume((pub_r000890_3_2 >= (-100)) && (pub_r000890_3_2 <= 100));
  __CPROVER_assume((pub_r000890_4_1 >= (-100)) && (pub_r000890_4_1 <= 100));
  __CPROVER_assume((pub_r000890_4_2 >= (-100)) && (pub_r000890_4_2 <= 100));
  __CPROVER_assume((pub_r000890_5_1 >= (-100)) && (pub_r000890_5_1 <= 100));
  __CPROVER_assume((pub_r000890_5_2 >= (-100)) && (pub_r000890_5_2 <= 100));
  __CPROVER_assume((pub_r000890_6_1 >= (-100)) && (pub_r000890_6_1 <= 100));
  __CPROVER_assume((pub_r000890_6_2 >= (-100)) && (pub_r000890_6_2 <= 100));
  __CPROVER_assume((pub_r000890_7_1 >= (-100)) && (pub_r000890_7_1 <= 100));
  __CPROVER_assume((pub_r000890_7_2 >= (-100)) && (pub_r000890_7_2 <= 100));
  __CPROVER_assume((pub_r000890_8_1 >= (-100)) && (pub_r000890_8_1 <= 100));
  __CPROVER_assume((pub_r000890_8_2 >= (-100)) && (pub_r000890_8_2 <= 100));
  __CPROVER_assume((pub_r000890_9_1 >= (-100)) && (pub_r000890_9_1 <= 100));
  __CPROVER_assume((pub_r000890_9_2 >= (-100)) && (pub_r000890_9_2 <= 100));
  __CPROVER_assume((pub_r000890_10_1 >= (-100)) && (pub_r000890_10_1 <= 100));
  __CPROVER_assume((pub_r000890_10_2 >= (-100)) && (pub_r000890_10_2 <= 100));
  __CPROVER_assume((pub_r000890_11_1 >= (-100)) && (pub_r000890_11_1 <= 100));
  __CPROVER_assume((pub_r000890_11_2 >= (-100)) && (pub_r000890_11_2 <= 100));
  __CPROVER_assume((pub_r000890_12_1 >= (-100)) && (pub_r000890_12_1 <= 100));
  __CPROVER_assume((pub_r000890_12_2 >= (-100)) && (pub_r000890_12_2 <= 100));
  __CPROVER_assume((pub_r000890_13_1 >= (-100)) && (pub_r000890_13_1 <= 100));
  __CPROVER_assume((pub_r000890_13_2 >= (-100)) && (pub_r000890_13_2 <= 100));
  __CPROVER_assume((pub_r000890_14_1 >= (-100)) && (pub_r000890_14_1 <= 100));
  __CPROVER_assume((pub_r000890_14_2 >= (-100)) && (pub_r000890_14_2 <= 100));
  __CPROVER_assume((pub_r000890_15_1 >= (-100)) && (pub_r000890_15_1 <= 100));
  __CPROVER_assume((pub_r000890_15_2 >= (-100)) && (pub_r000890_15_2 <= 100));
  __CPROVER_assume((pub_r000890_16_1 >= (-100)) && (pub_r000890_16_1 <= 100));
  __CPROVER_assume((pub_r000890_16_2 >= (-100)) && (pub_r000890_16_2 <= 100));
  __CPROVER_assume((pub_r000890_17_1 >= (-100)) && (pub_r000890_17_1 <= 100));
  __CPROVER_assume((pub_r000890_17_2 >= (-100)) && (pub_r000890_17_2 <= 100));
  __CPROVER_assume((pub_r000890_18_1 >= (-100)) && (pub_r000890_18_1 <= 100));
  __CPROVER_assume((pub_r000890_18_2 >= (-100)) && (pub_r000890_18_2 <= 100));
  __CPROVER_assume((pub_r000890_19_1 >= (-100)) && (pub_r000890_19_1 <= 100));
  __CPROVER_assume((pub_r000890_19_2 >= (-100)) && (pub_r000890_19_2 <= 100));
  __CPROVER_assume((pub_r000890_20_1 >= (-100)) && (pub_r000890_20_1 <= 100));
  __CPROVER_assume((pub_r000890_20_2 >= (-100)) && (pub_r000890_20_2 <= 100));
  __CPROVER_assume((pub_r000890_21_1 >= (-100)) && (pub_r000890_21_1 <= 100));
  __CPROVER_assume((pub_r000890_21_2 >= (-100)) && (pub_r000890_21_2 <= 100));
  __CPROVER_assume((pub_r000890_22_1 >= (-100)) && (pub_r000890_22_1 <= 100));
  __CPROVER_assume((pub_r000890_22_2 >= (-100)) && (pub_r000890_22_2 <= 100));
  __CPROVER_assume((pub_r000890_23_1 >= (-100)) && (pub_r000890_23_1 <= 100));
  __CPROVER_assume((pub_r000890_23_2 >= (-100)) && (pub_r000890_23_2 <= 100));
  __CPROVER_assume((sec_r000890_0_1 >= 0) && (sec_r000890_0_1 <= 255));
  __CPROVER_assume((sec_r000890_0_2 >= 0) && (sec_r000890_0_2 <= 255));
  __CPROVER_assume((sec_r000890_1_1 >= 0) && (sec_r000890_1_1 <= 255));
  __CPROVER_assume((sec_r000890_1_2 >= 0) && (sec_r000890_1_2 <= 255));
  __CPROVER_assume((sec_r000890_2_1 >= 0) && (sec_r000890_2_1 <= 255));
  __CPROVER_assume((sec_r000890_2_2 >= 0) && (sec_r000890_2_2 <= 255));
  __CPROVER_assume((sec_r000890_3_1 >= 0) && (sec_r000890_3_1 <= 255));
  __CPROVER_assume((sec_r000890_3_2 >= 0) && (sec_r000890_3_2 <= 255));
  __CPROVER_assume((sec_r000890_4_1 >= 0) && (sec_r000890_4_1 <= 255));
  __CPROVER_assume((sec_r000890_4_2 >= 0) && (sec_r000890_4_2 <= 255));
  __CPROVER_assume((sec_r000890_5_1 >= 0) && (sec_r000890_5_1 <= 255));
  __CPROVER_assume((sec_r000890_5_2 >= 0) && (sec_r000890_5_2 <= 255));
  __CPROVER_assume((sec_r000890_6_1 >= 0) && (sec_r000890_6_1 <= 255));
  __CPROVER_assume((sec_r000890_6_2 >= 0) && (sec_r000890_6_2 <= 255));
  __CPROVER_assume((sec_r000890_7_1 >= 0) && (sec_r000890_7_1 <= 255));
  __CPROVER_assume((sec_r000890_7_2 >= 0) && (sec_r000890_7_2 <= 255));
  __CPROVER_assume((sec_r000890_8_1 >= 0) && (sec_r000890_8_1 <= 255));
  __CPROVER_assume((sec_r000890_8_2 >= 0) && (sec_r000890_8_2 <= 255));
  __CPROVER_assume((sec_r000890_9_1 >= 0) && (sec_r000890_9_1 <= 255));
  __CPROVER_assume((sec_r000890_9_2 >= 0) && (sec_r000890_9_2 <= 255));
  __CPROVER_assume((sec_r000890_10_1 >= 0) && (sec_r000890_10_1 <= 255));
  __CPROVER_assume((sec_r000890_10_2 >= 0) && (sec_r000890_10_2 <= 255));
  __CPROVER_assume((sec_r000890_11_1 >= 0) && (sec_r000890_11_1 <= 255));
  __CPROVER_assume((sec_r000890_11_2 >= 0) && (sec_r000890_11_2 <= 255));
  __CPROVER_assume((sec_r000890_12_1 >= 0) && (sec_r000890_12_1 <= 255));
  __CPROVER_assume((sec_r000890_12_2 >= 0) && (sec_r000890_12_2 <= 255));
  __CPROVER_assume((sec_r000890_13_1 >= 0) && (sec_r000890_13_1 <= 255));
  __CPROVER_assume((sec_r000890_13_2 >= 0) && (sec_r000890_13_2 <= 255));
  __CPROVER_assume((sec_r000890_14_1 >= 0) && (sec_r000890_14_1 <= 255));
  __CPROVER_assume((sec_r000890_14_2 >= 0) && (sec_r000890_14_2 <= 255));
  __CPROVER_assume((sec_r000890_15_1 >= 0) && (sec_r000890_15_1 <= 255));
  __CPROVER_assume((sec_r000890_15_2 >= 0) && (sec_r000890_15_2 <= 255));
  struct FilterState_R000890_9013_0 st_var_0_1 = {0};
  struct FilterState_R000890_9013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000890_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000890_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000890_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000890_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000890_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000890_0_2 + 7) & 15;
  struct Transaction_R000890_9013_1 st_var_1_1 = {0};
  struct Transaction_R000890_9013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000890_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000890_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000890_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000890_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000890_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000890_0_2 + 9) & 15;
  union PacketPayload_R000890_9013_0 u_var_1;
  union PacketPayload_R000890_9013_0 u_var_2;
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
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 41)
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
  if (stage_v_1_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 41)
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
  int stage_v_2_1 = ((st_var_0_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_0_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 33)
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
  if (stage_v_2_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 33)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 4) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 26)
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
  if (stage_v_7_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 26)
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
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = ((st_var_0_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_0_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 32)
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
  if (stage_v_10_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 32)
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
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
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
  int stage_v_14_1 = ((st_var_0_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_0_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 52)
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
  if (stage_v_14_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 52)
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
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  int stage_v_16_1 = ((st_var_0_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_0_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 48)
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
  if (stage_v_16_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 48)
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
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 35)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 35)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 40)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 40)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((st_var_1_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_1_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 27)
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
  if (stage_v_27_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 27)
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
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 35) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 36) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_1_2.buffer[2] * 3) & 63;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = (st_var_0_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_0_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 48)
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
  if (stage_v_40_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 48)
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
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 37)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 37)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (47 & 31);
  int stage_v_42_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (47 & 31);
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= (stage_v_42_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_42_2 << 1) & 127;
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 25)
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
  if (stage_v_43_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 25)
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
  int stage_v_44_1 = table_1[0];
  int stage_v_44_2 = table_2[0];
  table_1[0] = (table_1[1] + 89) & 63;
  table_2[0] = (table_2[1] + 89) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((st_var_1_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_1_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 41)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 41)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = ((sec_r000890_6_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_47_2 = ((sec_r000890_6_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_47_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((stage_v_47_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_48_2 = ((stage_v_47_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_48_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((stage_v_48_1 ^ 0x2A) + pub_r000890_7_1) & 127;
  int stage_v_49_2 = ((stage_v_48_2 ^ 0x2A) + pub_r000890_7_2) & 127;
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
  int stage_v_50_1 = ((stage_v_48_1 ^ 0x2A) + pub_r000890_16_1) & 127;
  int stage_v_50_2 = ((stage_v_48_2 ^ 0x2A) + pub_r000890_16_2) & 127;
  if (stage_v_50_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((stage_v_50_1 ^ 0x2A) + pub_r000890_15_1) & 127;
  int stage_v_51_2 = ((stage_v_50_2 ^ 0x2A) + pub_r000890_15_2) & 127;
  if (stage_v_51_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((stage_v_50_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_52_2 = ((stage_v_50_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_52_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((sec_r000890_10_1 ^ 0x2A) + pub_r000890_22_1) & 127;
  int stage_v_53_2 = ((sec_r000890_10_2 ^ 0x2A) + pub_r000890_22_2) & 127;
  if (stage_v_53_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((stage_v_53_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_54_2 = ((stage_v_53_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_54_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((stage_v_51_1 ^ 0x2A) + pub_r000890_0_1) & 127;
  int stage_v_55_2 = ((stage_v_51_2 ^ 0x2A) + pub_r000890_0_2) & 127;
  if (stage_v_55_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((sec_r000890_0_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_56_2 = ((sec_r000890_0_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_56_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((stage_v_54_1 ^ 0x2A) + pub_r000890_12_1) & 127;
  int stage_v_57_2 = ((stage_v_54_2 ^ 0x2A) + pub_r000890_12_2) & 127;
  if (stage_v_57_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((sec_r000890_4_1 ^ 0x2A) + pub_r000890_22_1) & 127;
  int stage_v_58_2 = ((sec_r000890_4_2 ^ 0x2A) + pub_r000890_22_2) & 127;
  if (stage_v_58_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((stage_v_51_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_59_2 = ((stage_v_51_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_59_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((stage_v_59_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_60_2 = ((stage_v_59_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_60_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((stage_v_60_1 ^ 0x2A) + pub_r000890_13_1) & 127;
  int stage_v_61_2 = ((stage_v_60_2 ^ 0x2A) + pub_r000890_13_2) & 127;
  if (stage_v_61_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((stage_v_61_1 ^ 0x2A) + pub_r000890_16_1) & 127;
  int stage_v_62_2 = ((stage_v_61_2 ^ 0x2A) + pub_r000890_16_2) & 127;
  if (stage_v_62_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((sec_r000890_13_1 ^ 0x2A) + pub_r000890_0_1) & 127;
  int stage_v_63_2 = ((sec_r000890_13_2 ^ 0x2A) + pub_r000890_0_2) & 127;
  if (stage_v_63_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((stage_v_49_1 ^ 0x2A) + pub_r000890_8_1) & 127;
  int stage_v_64_2 = ((stage_v_49_2 ^ 0x2A) + pub_r000890_8_2) & 127;
  if (stage_v_64_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((stage_v_56_1 ^ 0x2A) + pub_r000890_0_1) & 127;
  int stage_v_65_2 = ((stage_v_56_2 ^ 0x2A) + pub_r000890_0_2) & 127;
  if (stage_v_65_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((sec_r000890_1_1 ^ 0x2A) + pub_r000890_17_1) & 127;
  int stage_v_66_2 = ((sec_r000890_1_2 ^ 0x2A) + pub_r000890_17_2) & 127;
  if (stage_v_66_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((stage_v_62_1 ^ 0x2A) + pub_r000890_20_1) & 127;
  int stage_v_67_2 = ((stage_v_62_2 ^ 0x2A) + pub_r000890_20_2) & 127;
  if (stage_v_67_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((stage_v_54_1 ^ 0x2A) + pub_r000890_19_1) & 127;
  int stage_v_68_2 = ((stage_v_54_2 ^ 0x2A) + pub_r000890_19_2) & 127;
  if (stage_v_68_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((sec_r000890_8_1 ^ 0x2A) + pub_r000890_7_1) & 127;
  int stage_v_69_2 = ((sec_r000890_8_2 ^ 0x2A) + pub_r000890_7_2) & 127;
  if (stage_v_69_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((stage_v_47_1 ^ 0x2A) + pub_r000890_0_1) & 127;
  int stage_v_70_2 = ((stage_v_47_2 ^ 0x2A) + pub_r000890_0_2) & 127;
  if (stage_v_70_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((stage_v_57_1 ^ 0x2A) + pub_r000890_18_1) & 127;
  int stage_v_71_2 = ((stage_v_57_2 ^ 0x2A) + pub_r000890_18_2) & 127;
  if (stage_v_71_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((stage_v_50_1 ^ 0x2A) + pub_r000890_19_1) & 127;
  int stage_v_72_2 = ((stage_v_50_2 ^ 0x2A) + pub_r000890_19_2) & 127;
  if (stage_v_72_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((sec_r000890_4_1 ^ 0x2A) + pub_r000890_17_1) & 127;
  int stage_v_73_2 = ((sec_r000890_4_2 ^ 0x2A) + pub_r000890_17_2) & 127;
  if (stage_v_73_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((stage_v_66_1 ^ 0x2A) + pub_r000890_15_1) & 127;
  int stage_v_74_2 = ((stage_v_66_2 ^ 0x2A) + pub_r000890_15_2) & 127;
  if (stage_v_74_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((sec_r000890_9_1 ^ 0x2A) + pub_r000890_1_1) & 127;
  int stage_v_75_2 = ((sec_r000890_9_2 ^ 0x2A) + pub_r000890_1_2) & 127;
  if (stage_v_75_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((stage_v_53_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_76_2 = ((stage_v_53_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_76_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((stage_v_70_1 ^ 0x2A) + pub_r000890_22_1) & 127;
  int stage_v_77_2 = ((stage_v_70_2 ^ 0x2A) + pub_r000890_22_2) & 127;
  if (stage_v_77_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((sec_r000890_11_1 ^ 0x2A) + pub_r000890_3_1) & 127;
  int stage_v_78_2 = ((sec_r000890_11_2 ^ 0x2A) + pub_r000890_3_2) & 127;
  if (stage_v_78_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((sec_r000890_13_1 ^ 0x2A) + pub_r000890_3_1) & 127;
  int stage_v_79_2 = ((sec_r000890_13_2 ^ 0x2A) + pub_r000890_3_2) & 127;
  if (stage_v_79_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((stage_v_48_1 ^ 0x2A) + pub_r000890_14_1) & 127;
  int stage_v_80_2 = ((stage_v_48_2 ^ 0x2A) + pub_r000890_14_2) & 127;
  if (stage_v_80_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((stage_v_73_1 ^ 0x2A) + pub_r000890_17_1) & 127;
  int stage_v_81_2 = ((stage_v_73_2 ^ 0x2A) + pub_r000890_17_2) & 127;
  if (stage_v_81_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((sec_r000890_0_1 ^ 0x2A) + pub_r000890_12_1) & 127;
  int stage_v_82_2 = ((sec_r000890_0_2 ^ 0x2A) + pub_r000890_12_2) & 127;
  if (stage_v_82_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((stage_v_72_1 ^ 0x2A) + pub_r000890_19_1) & 127;
  int stage_v_83_2 = ((stage_v_72_2 ^ 0x2A) + pub_r000890_19_2) & 127;
  if (stage_v_83_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((stage_v_57_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_84_2 = ((stage_v_57_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_84_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((stage_v_80_1 ^ 0x2A) + pub_r000890_7_1) & 127;
  int stage_v_85_2 = ((stage_v_80_2 ^ 0x2A) + pub_r000890_7_2) & 127;
  if (stage_v_85_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((stage_v_72_1 ^ 0x2A) + pub_r000890_3_1) & 127;
  int stage_v_86_2 = ((stage_v_72_2 ^ 0x2A) + pub_r000890_3_2) & 127;
  if (stage_v_86_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((stage_v_57_1 ^ 0x2A) + pub_r000890_8_1) & 127;
  int stage_v_87_2 = ((stage_v_57_2 ^ 0x2A) + pub_r000890_8_2) & 127;
  if (stage_v_87_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((stage_v_47_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_88_2 = ((stage_v_47_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_88_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((stage_v_53_1 ^ 0x2A) + pub_r000890_0_1) & 127;
  int stage_v_89_2 = ((stage_v_53_2 ^ 0x2A) + pub_r000890_0_2) & 127;
  if (stage_v_89_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((stage_v_53_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_90_2 = ((stage_v_53_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_90_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((stage_v_83_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_91_2 = ((stage_v_83_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_91_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_47_1 ^ 0x2A) + pub_r000890_5_1) & 127;
  int stage_v_92_2 = ((stage_v_47_2 ^ 0x2A) + pub_r000890_5_2) & 127;
  if (stage_v_92_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((sec_r000890_6_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_93_2 = ((sec_r000890_6_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_93_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((sec_r000890_1_1 ^ 0x2A) + pub_r000890_3_1) & 127;
  int stage_v_94_2 = ((sec_r000890_1_2 ^ 0x2A) + pub_r000890_3_2) & 127;
  if (stage_v_94_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((stage_v_56_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_95_2 = ((stage_v_56_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_95_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((stage_v_56_1 ^ 0x2A) + pub_r000890_17_1) & 127;
  int stage_v_96_2 = ((stage_v_56_2 ^ 0x2A) + pub_r000890_17_2) & 127;
  if (stage_v_96_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((sec_r000890_11_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_97_2 = ((sec_r000890_11_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_97_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((stage_v_66_1 ^ 0x2A) + pub_r000890_16_1) & 127;
  int stage_v_98_2 = ((stage_v_66_2 ^ 0x2A) + pub_r000890_16_2) & 127;
  if (stage_v_98_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((stage_v_89_1 ^ 0x2A) + pub_r000890_5_1) & 127;
  int stage_v_99_2 = ((stage_v_89_2 ^ 0x2A) + pub_r000890_5_2) & 127;
  if (stage_v_99_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_56_1 ^ 0x2A) + pub_r000890_23_1) & 127;
  int stage_v_100_2 = ((stage_v_56_2 ^ 0x2A) + pub_r000890_23_2) & 127;
  if (stage_v_100_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((sec_r000890_6_1 ^ 0x2A) + pub_r000890_3_1) & 127;
  int stage_v_101_2 = ((sec_r000890_6_2 ^ 0x2A) + pub_r000890_3_2) & 127;
  if (stage_v_101_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((sec_r000890_7_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_102_2 = ((sec_r000890_7_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_102_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((stage_v_54_1 ^ 0x2A) + pub_r000890_22_1) & 127;
  int stage_v_103_2 = ((stage_v_54_2 ^ 0x2A) + pub_r000890_22_2) & 127;
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
  int stage_v_104_1 = ((stage_v_61_1 ^ 0x2A) + pub_r000890_20_1) & 127;
  int stage_v_104_2 = ((stage_v_61_2 ^ 0x2A) + pub_r000890_20_2) & 127;
  if (stage_v_104_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((sec_r000890_7_1 ^ 0x2A) + pub_r000890_0_1) & 127;
  int stage_v_105_2 = ((sec_r000890_7_2 ^ 0x2A) + pub_r000890_0_2) & 127;
  if (stage_v_105_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_63_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_106_2 = ((stage_v_63_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_106_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((stage_v_61_1 ^ 0x2A) + pub_r000890_13_1) & 127;
  int stage_v_107_2 = ((stage_v_61_2 ^ 0x2A) + pub_r000890_13_2) & 127;
  if (stage_v_107_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_94_1 ^ 0x2A) + pub_r000890_7_1) & 127;
  int stage_v_108_2 = ((stage_v_94_2 ^ 0x2A) + pub_r000890_7_2) & 127;
  if (stage_v_108_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((sec_r000890_4_1 ^ 0x2A) + pub_r000890_8_1) & 127;
  int stage_v_109_2 = ((sec_r000890_4_2 ^ 0x2A) + pub_r000890_8_2) & 127;
  if (stage_v_109_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((stage_v_48_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_110_2 = ((stage_v_48_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_110_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_84_1 ^ 0x2A) + pub_r000890_7_1) & 127;
  int stage_v_111_2 = ((stage_v_84_2 ^ 0x2A) + pub_r000890_7_2) & 127;
  if (stage_v_111_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((sec_r000890_4_1 ^ 0x2A) + pub_r000890_18_1) & 127;
  int stage_v_112_2 = ((sec_r000890_4_2 ^ 0x2A) + pub_r000890_18_2) & 127;
  if (stage_v_112_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((stage_v_100_1 ^ 0x2A) + pub_r000890_16_1) & 127;
  int stage_v_113_2 = ((stage_v_100_2 ^ 0x2A) + pub_r000890_16_2) & 127;
  if (stage_v_113_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((stage_v_108_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_114_2 = ((stage_v_108_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_114_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((stage_v_103_1 ^ 0x2A) + pub_r000890_0_1) & 127;
  int stage_v_115_2 = ((stage_v_103_2 ^ 0x2A) + pub_r000890_0_2) & 127;
  if (stage_v_115_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((sec_r000890_4_1 ^ 0x2A) + pub_r000890_15_1) & 127;
  int stage_v_116_2 = ((sec_r000890_4_2 ^ 0x2A) + pub_r000890_15_2) & 127;
  if (stage_v_116_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_75_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_117_2 = ((stage_v_75_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_117_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((stage_v_68_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_118_2 = ((stage_v_68_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_118_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((sec_r000890_7_1 ^ 0x2A) + pub_r000890_13_1) & 127;
  int stage_v_119_2 = ((sec_r000890_7_2 ^ 0x2A) + pub_r000890_13_2) & 127;
  if (stage_v_119_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((stage_v_64_1 ^ 0x2A) + pub_r000890_13_1) & 127;
  int stage_v_120_2 = ((stage_v_64_2 ^ 0x2A) + pub_r000890_13_2) & 127;
  if (stage_v_120_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((stage_v_74_1 ^ 0x2A) + pub_r000890_17_1) & 127;
  int stage_v_121_2 = ((stage_v_74_2 ^ 0x2A) + pub_r000890_17_2) & 127;
  if (stage_v_121_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_77_1 ^ 0x2A) + pub_r000890_14_1) & 127;
  int stage_v_122_2 = ((stage_v_77_2 ^ 0x2A) + pub_r000890_14_2) & 127;
  if (stage_v_122_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_99_1 ^ 0x2A) + pub_r000890_5_1) & 127;
  int stage_v_123_2 = ((stage_v_99_2 ^ 0x2A) + pub_r000890_5_2) & 127;
  if (stage_v_123_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((stage_v_119_1 ^ 0x2A) + pub_r000890_14_1) & 127;
  int stage_v_124_2 = ((stage_v_119_2 ^ 0x2A) + pub_r000890_14_2) & 127;
  if (stage_v_124_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000890_3_1) & 127;
  int stage_v_125_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000890_3_2) & 127;
  if (stage_v_125_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((stage_v_99_1 ^ 0x2A) + pub_r000890_18_1) & 127;
  int stage_v_126_2 = ((stage_v_99_2 ^ 0x2A) + pub_r000890_18_2) & 127;
  if (stage_v_126_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((stage_v_51_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_127_2 = ((stage_v_51_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_127_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((sec_r000890_4_1 ^ 0x2A) + pub_r000890_12_1) & 127;
  int stage_v_128_2 = ((sec_r000890_4_2 ^ 0x2A) + pub_r000890_12_2) & 127;
  if (stage_v_128_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((stage_v_94_1 ^ 0x2A) + pub_r000890_1_1) & 127;
  int stage_v_129_2 = ((stage_v_94_2 ^ 0x2A) + pub_r000890_1_2) & 127;
  if (stage_v_129_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_85_1 ^ 0x2A) + pub_r000890_12_1) & 127;
  int stage_v_130_2 = ((stage_v_85_2 ^ 0x2A) + pub_r000890_12_2) & 127;
  if (stage_v_130_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((stage_v_81_1 ^ 0x2A) + pub_r000890_15_1) & 127;
  int stage_v_131_2 = ((stage_v_81_2 ^ 0x2A) + pub_r000890_15_2) & 127;
  if (stage_v_131_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((sec_r000890_3_1 ^ 0x2A) + pub_r000890_6_1) & 127;
  int stage_v_132_2 = ((sec_r000890_3_2 ^ 0x2A) + pub_r000890_6_2) & 127;
  if (stage_v_132_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((stage_v_65_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_133_2 = ((stage_v_65_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_133_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((stage_v_107_1 ^ 0x2A) + pub_r000890_12_1) & 127;
  int stage_v_134_2 = ((stage_v_107_2 ^ 0x2A) + pub_r000890_12_2) & 127;
  if (stage_v_134_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((sec_r000890_3_1 ^ 0x2A) + pub_r000890_5_1) & 127;
  int stage_v_135_2 = ((sec_r000890_3_2 ^ 0x2A) + pub_r000890_5_2) & 127;
  if (stage_v_135_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((stage_v_70_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_136_2 = ((stage_v_70_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_136_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((stage_v_103_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_137_2 = ((stage_v_103_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_137_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_123_1 ^ 0x2A) + pub_r000890_17_1) & 127;
  int stage_v_138_2 = ((stage_v_123_2 ^ 0x2A) + pub_r000890_17_2) & 127;
  if (stage_v_138_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((stage_v_113_1 ^ 0x2A) + pub_r000890_3_1) & 127;
  int stage_v_139_2 = ((stage_v_113_2 ^ 0x2A) + pub_r000890_3_2) & 127;
  if (stage_v_139_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((sec_r000890_1_1 ^ 0x2A) + pub_r000890_8_1) & 127;
  int stage_v_140_2 = ((sec_r000890_1_2 ^ 0x2A) + pub_r000890_8_2) & 127;
  if (stage_v_140_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((stage_v_89_1 ^ 0x2A) + pub_r000890_5_1) & 127;
  int stage_v_141_2 = ((stage_v_89_2 ^ 0x2A) + pub_r000890_5_2) & 127;
  if (stage_v_141_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_113_1 ^ 0x2A) + pub_r000890_22_1) & 127;
  int stage_v_142_2 = ((stage_v_113_2 ^ 0x2A) + pub_r000890_22_2) & 127;
  if (stage_v_142_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((stage_v_102_1 ^ 0x2A) + pub_r000890_1_1) & 127;
  int stage_v_143_2 = ((stage_v_102_2 ^ 0x2A) + pub_r000890_1_2) & 127;
  if (stage_v_143_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((stage_v_114_1 ^ 0x2A) + pub_r000890_8_1) & 127;
  int stage_v_144_2 = ((stage_v_114_2 ^ 0x2A) + pub_r000890_8_2) & 127;
  if (stage_v_144_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_115_1 ^ 0x2A) + pub_r000890_2_1) & 127;
  int stage_v_145_2 = ((stage_v_115_2 ^ 0x2A) + pub_r000890_2_2) & 127;
  if (stage_v_145_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((stage_v_98_1 ^ 0x2A) + pub_r000890_18_1) & 127;
  int stage_v_146_2 = ((stage_v_98_2 ^ 0x2A) + pub_r000890_18_2) & 127;
  if (stage_v_146_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((stage_v_67_1 ^ 0x2A) + pub_r000890_2_1) & 127;
  int stage_v_147_2 = ((stage_v_67_2 ^ 0x2A) + pub_r000890_2_2) & 127;
  if (stage_v_147_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_125_1 ^ 0x2A) + pub_r000890_7_1) & 127;
  int stage_v_148_2 = ((stage_v_125_2 ^ 0x2A) + pub_r000890_7_2) & 127;
  if (stage_v_148_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((stage_v_108_1 ^ 0x2A) + pub_r000890_23_1) & 127;
  int stage_v_149_2 = ((stage_v_108_2 ^ 0x2A) + pub_r000890_23_2) & 127;
  if (stage_v_149_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((stage_v_108_1 ^ 0x2A) + pub_r000890_6_1) & 127;
  int stage_v_150_2 = ((stage_v_108_2 ^ 0x2A) + pub_r000890_6_2) & 127;
  if (stage_v_150_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((stage_v_49_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_151_2 = ((stage_v_49_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_151_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((sec_r000890_6_1 ^ 0x2A) + pub_r000890_8_1) & 127;
  int stage_v_152_2 = ((sec_r000890_6_2 ^ 0x2A) + pub_r000890_8_2) & 127;
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
  int stage_v_153_1 = ((stage_v_150_1 ^ 0x2A) + pub_r000890_4_1) & 127;
  int stage_v_153_2 = ((stage_v_150_2 ^ 0x2A) + pub_r000890_4_2) & 127;
  if (stage_v_153_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((sec_r000890_10_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_154_2 = ((sec_r000890_10_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_154_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((stage_v_83_1 ^ 0x2A) + pub_r000890_22_1) & 127;
  int stage_v_155_2 = ((stage_v_83_2 ^ 0x2A) + pub_r000890_22_2) & 127;
  if (stage_v_155_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_97_1 ^ 0x2A) + pub_r000890_19_1) & 127;
  int stage_v_156_2 = ((stage_v_97_2 ^ 0x2A) + pub_r000890_19_2) & 127;
  if (stage_v_156_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((sec_r000890_0_1 ^ 0x2A) + pub_r000890_13_1) & 127;
  int stage_v_157_2 = ((sec_r000890_0_2 ^ 0x2A) + pub_r000890_13_2) & 127;
  if (stage_v_157_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((stage_v_76_1 ^ 0x2A) + pub_r000890_6_1) & 127;
  int stage_v_158_2 = ((stage_v_76_2 ^ 0x2A) + pub_r000890_6_2) & 127;
  if (stage_v_158_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((sec_r000890_9_1 ^ 0x2A) + pub_r000890_20_1) & 127;
  int stage_v_159_2 = ((sec_r000890_9_2 ^ 0x2A) + pub_r000890_20_2) & 127;
  if (stage_v_159_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((stage_v_132_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_160_2 = ((stage_v_132_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_160_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_122_1 ^ 0x2A) + pub_r000890_12_1) & 127;
  int stage_v_161_2 = ((stage_v_122_2 ^ 0x2A) + pub_r000890_12_2) & 127;
  if (stage_v_161_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000890_22_1) & 127;
  int stage_v_162_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000890_22_2) & 127;
  if (stage_v_162_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((stage_v_121_1 ^ 0x2A) + pub_r000890_7_1) & 127;
  int stage_v_163_2 = ((stage_v_121_2 ^ 0x2A) + pub_r000890_7_2) & 127;
  if (stage_v_163_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((sec_r000890_4_1 ^ 0x2A) + pub_r000890_14_1) & 127;
  int stage_v_164_2 = ((sec_r000890_4_2 ^ 0x2A) + pub_r000890_14_2) & 127;
  if (stage_v_164_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((stage_v_155_1 ^ 0x2A) + pub_r000890_4_1) & 127;
  int stage_v_165_2 = ((stage_v_155_2 ^ 0x2A) + pub_r000890_4_2) & 127;
  if (stage_v_165_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((stage_v_97_1 ^ 0x2A) + pub_r000890_19_1) & 127;
  int stage_v_166_2 = ((stage_v_97_2 ^ 0x2A) + pub_r000890_19_2) & 127;
  if (stage_v_166_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((sec_r000890_5_1 ^ 0x2A) + pub_r000890_19_1) & 127;
  int stage_v_167_2 = ((sec_r000890_5_2 ^ 0x2A) + pub_r000890_19_2) & 127;
  if (stage_v_167_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((stage_v_147_1 ^ 0x2A) + pub_r000890_19_1) & 127;
  int stage_v_168_2 = ((stage_v_147_2 ^ 0x2A) + pub_r000890_19_2) & 127;
  if (stage_v_168_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((stage_v_110_1 ^ 0x2A) + pub_r000890_14_1) & 127;
  int stage_v_169_2 = ((stage_v_110_2 ^ 0x2A) + pub_r000890_14_2) & 127;
  if (stage_v_169_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((sec_r000890_11_1 ^ 0x2A) + pub_r000890_20_1) & 127;
  int stage_v_170_2 = ((sec_r000890_11_2 ^ 0x2A) + pub_r000890_20_2) & 127;
  if (stage_v_170_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((stage_v_115_1 ^ 0x2A) + pub_r000890_17_1) & 127;
  int stage_v_171_2 = ((stage_v_115_2 ^ 0x2A) + pub_r000890_17_2) & 127;
  if (stage_v_171_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_127_1 ^ 0x2A) + pub_r000890_15_1) & 127;
  int stage_v_172_2 = ((stage_v_127_2 ^ 0x2A) + pub_r000890_15_2) & 127;
  if (stage_v_172_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_92_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_173_2 = ((stage_v_92_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_173_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((stage_v_55_1 ^ 0x2A) + pub_r000890_14_1) & 127;
  int stage_v_174_2 = ((stage_v_55_2 ^ 0x2A) + pub_r000890_14_2) & 127;
  if (stage_v_174_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((stage_v_167_1 ^ 0x2A) + pub_r000890_23_1) & 127;
  int stage_v_175_2 = ((stage_v_167_2 ^ 0x2A) + pub_r000890_23_2) & 127;
  if (stage_v_175_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((stage_v_134_1 ^ 0x2A) + pub_r000890_14_1) & 127;
  int stage_v_176_2 = ((stage_v_134_2 ^ 0x2A) + pub_r000890_14_2) & 127;
  if (stage_v_176_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((sec_r000890_9_1 ^ 0x2A) + pub_r000890_10_1) & 127;
  int stage_v_177_2 = ((sec_r000890_9_2 ^ 0x2A) + pub_r000890_10_2) & 127;
  if (stage_v_177_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((stage_v_142_1 ^ 0x2A) + pub_r000890_15_1) & 127;
  int stage_v_178_2 = ((stage_v_142_2 ^ 0x2A) + pub_r000890_15_2) & 127;
  if (stage_v_178_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((sec_r000890_15_1 ^ 0x2A) + pub_r000890_14_1) & 127;
  int stage_v_179_2 = ((sec_r000890_15_2 ^ 0x2A) + pub_r000890_14_2) & 127;
  if (stage_v_179_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((stage_v_122_1 ^ 0x2A) + pub_r000890_6_1) & 127;
  int stage_v_180_2 = ((stage_v_122_2 ^ 0x2A) + pub_r000890_6_2) & 127;
  if (stage_v_180_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((stage_v_151_1 ^ 0x2A) + pub_r000890_12_1) & 127;
  int stage_v_181_2 = ((stage_v_151_2 ^ 0x2A) + pub_r000890_12_2) & 127;
  if (stage_v_181_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((sec_r000890_13_1 ^ 0x2A) + pub_r000890_18_1) & 127;
  int stage_v_182_2 = ((sec_r000890_13_2 ^ 0x2A) + pub_r000890_18_2) & 127;
  if (stage_v_182_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_85_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_183_2 = ((stage_v_85_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_183_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((stage_v_92_1 ^ 0x2A) + pub_r000890_18_1) & 127;
  int stage_v_184_2 = ((stage_v_92_2 ^ 0x2A) + pub_r000890_18_2) & 127;
  if (stage_v_184_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((sec_r000890_7_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_185_2 = ((sec_r000890_7_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_185_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_125_1 ^ 0x2A) + pub_r000890_3_1) & 127;
  int stage_v_186_2 = ((stage_v_125_2 ^ 0x2A) + pub_r000890_3_2) & 127;
  if (stage_v_186_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((sec_r000890_8_1 ^ 0x2A) + pub_r000890_12_1) & 127;
  int stage_v_187_2 = ((sec_r000890_8_2 ^ 0x2A) + pub_r000890_12_2) & 127;
  if (stage_v_187_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((sec_r000890_0_1 ^ 0x2A) + pub_r000890_13_1) & 127;
  int stage_v_188_2 = ((sec_r000890_0_2 ^ 0x2A) + pub_r000890_13_2) & 127;
  if (stage_v_188_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((stage_v_170_1 ^ 0x2A) + pub_r000890_8_1) & 127;
  int stage_v_189_2 = ((stage_v_170_2 ^ 0x2A) + pub_r000890_8_2) & 127;
  if (stage_v_189_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((stage_v_129_1 ^ 0x2A) + pub_r000890_14_1) & 127;
  int stage_v_190_2 = ((stage_v_129_2 ^ 0x2A) + pub_r000890_14_2) & 127;
  if (stage_v_190_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((sec_r000890_10_1 ^ 0x2A) + pub_r000890_4_1) & 127;
  int stage_v_191_2 = ((sec_r000890_10_2 ^ 0x2A) + pub_r000890_4_2) & 127;
  if (stage_v_191_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((sec_r000890_8_1 ^ 0x2A) + pub_r000890_23_1) & 127;
  int stage_v_192_2 = ((sec_r000890_8_2 ^ 0x2A) + pub_r000890_23_2) & 127;
  if (stage_v_192_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((sec_r000890_2_1 ^ 0x2A) + pub_r000890_22_1) & 127;
  int stage_v_193_2 = ((sec_r000890_2_2 ^ 0x2A) + pub_r000890_22_2) & 127;
  if (stage_v_193_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((sec_r000890_14_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_194_2 = ((sec_r000890_14_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_194_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_165_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_195_2 = ((stage_v_165_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_195_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((sec_r000890_5_1 ^ 0x2A) + pub_r000890_3_1) & 127;
  int stage_v_196_2 = ((sec_r000890_5_2 ^ 0x2A) + pub_r000890_3_2) & 127;
  if (stage_v_196_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((stage_v_98_1 ^ 0x2A) + pub_r000890_21_1) & 127;
  int stage_v_197_2 = ((stage_v_98_2 ^ 0x2A) + pub_r000890_21_2) & 127;
  if (stage_v_197_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_173_1 ^ 0x2A) + pub_r000890_11_1) & 127;
  int stage_v_198_2 = ((stage_v_173_2 ^ 0x2A) + pub_r000890_11_2) & 127;
  if (stage_v_198_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_117_1 ^ 0x2A) + pub_r000890_0_1) & 127;
  int stage_v_199_2 = ((stage_v_117_2 ^ 0x2A) + pub_r000890_0_2) & 127;
  if (stage_v_199_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_51_1 ^ 0x2A) + pub_r000890_20_1) & 127;
  int stage_v_200_2 = ((stage_v_51_2 ^ 0x2A) + pub_r000890_20_2) & 127;
  if (stage_v_200_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((stage_v_98_1 ^ 0x2A) + pub_r000890_9_1) & 127;
  int stage_v_201_2 = ((stage_v_98_2 ^ 0x2A) + pub_r000890_9_2) & 127;
  if (stage_v_201_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((stage_v_196_1 ^ 0x2A) + pub_r000890_1_1) & 127;
  int stage_v_202_2 = ((stage_v_196_2 ^ 0x2A) + pub_r000890_1_2) & 127;
  if (stage_v_202_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((sec_r000890_13_1 ^ 0x2A) + pub_r000890_6_1) & 127;
  int stage_v_203_2 = ((sec_r000890_13_2 ^ 0x2A) + pub_r000890_6_2) & 127;
  if (stage_v_203_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((sec_r000890_8_1 ^ 0x2A) + pub_r000890_17_1) & 127;
  int stage_v_204_2 = ((sec_r000890_8_2 ^ 0x2A) + pub_r000890_17_2) & 127;
  if (stage_v_204_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((stage_v_134_1 ^ 0x2A) + pub_r000890_16_1) & 127;
  int stage_v_205_2 = ((stage_v_134_2 ^ 0x2A) + pub_r000890_16_2) & 127;
  if (stage_v_205_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((stage_v_146_1 ^ 0x2A) + pub_r000890_15_1) & 127;
  int stage_v_206_2 = ((stage_v_146_2 ^ 0x2A) + pub_r000890_15_2) & 127;
  if (stage_v_206_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((stage_v_134_1 ^ 0x2A) + pub_r000890_6_1) & 127;
  int stage_v_207_2 = ((stage_v_134_2 ^ 0x2A) + pub_r000890_6_2) & 127;
  if (stage_v_207_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((sec_r000890_3_1 ^ 0x2A) + pub_r000890_20_1) & 127;
  int stage_v_208_2 = ((sec_r000890_3_2 ^ 0x2A) + pub_r000890_20_2) & 127;
  if (stage_v_208_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((sec_r000890_0_1 ^ 0x2A) + pub_r000890_23_1) & 127;
  int stage_v_209_2 = ((sec_r000890_0_2 ^ 0x2A) + pub_r000890_23_2) & 127;
  if (stage_v_209_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000890_23_1) & 127;
  int stage_v_210_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000890_23_2) & 127;
  if (stage_v_210_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((sec_r000890_12_1 ^ 0x2A) + pub_r000890_2_1) & 127;
  int stage_v_211_2 = ((sec_r000890_12_2 ^ 0x2A) + pub_r000890_2_2) & 127;
  if (stage_v_211_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((stage_v_169_1 ^ 0x2A) + pub_r000890_15_1) & 127;
  int stage_v_212_2 = ((stage_v_169_2 ^ 0x2A) + pub_r000890_15_2) & 127;
  if (stage_v_212_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((sec_r000890_5_1 ^ 0x2A) + pub_r000890_12_1) & 127;
  int stage_v_213_2 = ((sec_r000890_5_2 ^ 0x2A) + pub_r000890_12_2) & 127;
  if (stage_v_213_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000890_13_1) & 127;
  int stage_v_214_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000890_13_2) & 127;
  if (stage_v_214_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000890_11_1 != sec_r000890_11_2);
  __CPROVER_assume(sec_r000890_7_1 != sec_r000890_7_2);
  __CPROVER_assume(pub_r000890_19_1 == pub_r000890_19_2);
  __CPROVER_assume(pub_r000890_12_1 == pub_r000890_12_2);
  __CPROVER_assume(sec_r000890_0_1 != sec_r000890_0_2);
  __CPROVER_assume(pub_r000890_10_1 == pub_r000890_10_2);
  __CPROVER_assume(pub_r000890_7_1 == pub_r000890_7_2);
  __CPROVER_assume(pub_r000890_6_1 == pub_r000890_6_2);
  __CPROVER_assume(sec_r000890_8_1 != sec_r000890_8_2);
  __CPROVER_assume(sec_r000890_10_1 != sec_r000890_10_2);
  __CPROVER_assume(pub_r000890_23_1 == pub_r000890_23_2);
  __CPROVER_assume(sec_r000890_3_1 != sec_r000890_3_2);
  __CPROVER_assume(sec_r000890_9_1 != sec_r000890_9_2);
  __CPROVER_assume(sec_r000890_5_1 != sec_r000890_5_2);
  __CPROVER_assume(pub_r000890_4_1 == pub_r000890_4_2);
  __CPROVER_assume(sec_r000890_6_1 != sec_r000890_6_2);
  __CPROVER_assume(sec_r000890_12_1 != sec_r000890_12_2);
  __CPROVER_assume(pub_r000890_21_1 == pub_r000890_21_2);
  __CPROVER_assume(pub_r000890_16_1 == pub_r000890_16_2);
  __CPROVER_assume(pub_r000890_1_1 == pub_r000890_1_2);
  __CPROVER_assume(pub_r000890_22_1 == pub_r000890_22_2);
  __CPROVER_assume(sec_r000890_15_1 != sec_r000890_15_2);
  __CPROVER_assume(pub_r000890_11_1 == pub_r000890_11_2);
  __CPROVER_assume(sec_r000890_2_1 != sec_r000890_2_2);
  __CPROVER_assume(pub_r000890_17_1 == pub_r000890_17_2);
  __CPROVER_assume(sec_r000890_13_1 != sec_r000890_13_2);
  __CPROVER_assume(pub_r000890_5_1 == pub_r000890_5_2);
  __CPROVER_assume(pub_r000890_9_1 == pub_r000890_9_2);
  __CPROVER_assume(pub_r000890_3_1 == pub_r000890_3_2);
  __CPROVER_assume(pub_r000890_15_1 == pub_r000890_15_2);
  __CPROVER_assume(pub_r000890_18_1 == pub_r000890_18_2);
  __CPROVER_assume(sec_r000890_4_1 != sec_r000890_4_2);
  __CPROVER_assume(pub_r000890_8_1 == pub_r000890_8_2);
  __CPROVER_assume(pub_r000890_2_1 == pub_r000890_2_2);
  __CPROVER_assume(sec_r000890_1_1 != sec_r000890_1_2);
  __CPROVER_assume(pub_r000890_20_1 == pub_r000890_20_2);
  __CPROVER_assume(pub_r000890_0_1 == pub_r000890_0_2);
  __CPROVER_assume(pub_r000890_13_1 == pub_r000890_13_2);
  __CPROVER_assume(pub_r000890_14_1 == pub_r000890_14_2);
  __CPROVER_assume(sec_r000890_14_1 != sec_r000890_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.balance == st_var_1_2.balance);
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
}


