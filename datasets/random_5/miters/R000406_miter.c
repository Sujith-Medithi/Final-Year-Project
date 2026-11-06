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
struct SensorNode_R000406_613_0
{
  short offset;
  int threshold;
  int reading;
  int buffer[3];
};
struct EventLog_R000406_613_1
{
  unsigned char timestamp;
  unsigned char code;
  int seq;
  int severity;
  int signature;
  int buffer[3];
};
struct StreamBuffer_R000406_613_2
{
  short checksum;
  int head;
  int watermark;
  int buffer[3];
};
union RegisterBank_R000406_613_0
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
void fn_R000406_613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st_1 = {0};
  struct EventLog_R000406_613_1 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_49_1 = local_arr_1[aux_1 % 3];
  int index_reg_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_49_2 * 2)) & 127;
  int bound_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_40_1) & 63;
  aux_2 = (aux_2 + bound_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_76_1)
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

  switch (bound_76_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_49_1 == index_reg_49_2);
  assert(bound_40_1 == bound_40_2);
  assert(bound_76_1 == bound_76_2);
}

int fn_R000406_613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_49 = local_arr[aux % 3];
  acc = (acc + (index_reg_49 * 2)) & 127;
  int bound_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_40) & 63;
  acc ^= aux;
  int bound_76 = (aux + st.buffer[1]) & 3;
  switch (bound_76)
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

void fn_R000406_613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000406_613_0 st_1 = {0};
  struct SensorNode_R000406_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_86_1)
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

  switch (accumulator_86_2)
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

  int residue_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_56_1) & 63;
  aux_2 = (aux_2 + residue_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_55_1 > 49)
  {
    acc_1 = ((acc_1 + (weight_55_1 * 2)) + 5) & 127;
    aux_1 ^= weight_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_55_2 > 49)
  {
    acc_2 = ((acc_2 + (weight_55_2 * 2)) + 5) & 127;
    aux_2 ^= weight_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_55_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_86_1 == accumulator_86_2);
  assert(residue_56_1 == residue_56_2);
  assert(weight_55_1 == weight_55_2);
}

int fn_R000406_613_1(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000406_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_86 = (aux + st.buffer[1]) & 3;
  switch (accumulator_86)
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

  int residue_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_56) & 63;
  acc ^= aux;
  int weight_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_55 > 49)
  {
    acc = ((acc + (weight_55 * 2)) + 5) & 127;
    aux ^= weight_55 & 15;
  }
  else
  {
    acc = ((acc - weight_55) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000406_613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st_1 = {0};
  struct EventLog_R000406_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int scale_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_71_1 > 19)
  {
    acc_1 = ((acc_1 + (scale_71_1 * 2)) + 5) & 127;
    aux_1 ^= scale_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_71_2 > 19)
  {
    acc_2 = ((acc_2 + (scale_71_2 * 2)) + 5) & 127;
    aux_2 ^= scale_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_32_1 = local_arr_1[aux_1 % 3];
  int window_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_32_2 * 2)) & 127;
  int tally_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_21_1)
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

  switch (tally_21_2)
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

  int pivot_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_21_1) & 63;
  aux_2 = (aux_2 + pivot_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_71_1 == scale_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_32_1 == window_32_2);
  assert(tally_21_1 == tally_21_2);
  assert(pivot_21_1 == pivot_21_2);
}

int fn_R000406_613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int scale_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_71 > 19)
  {
    acc = ((acc + (scale_71 * 2)) + 5) & 127;
    aux ^= scale_71 & 15;
  }
  else
  {
    acc = ((acc - scale_71) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_32 = local_arr[aux % 3];
  acc = (acc + (window_32 * 2)) & 127;
  int tally_21 = (aux + st.buffer[1]) & 3;
  switch (tally_21)
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

  int pivot_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000406_613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st_1 = {0};
  struct StreamBuffer_R000406_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int checksum_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_42_1)
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

  switch (checksum_42_2)
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

  int accumulator_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_74_1 > 24)
  {
    acc_1 = ((acc_1 + (accumulator_74_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_74_2 > 24)
  {
    acc_2 = ((acc_2 + (accumulator_74_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_42_1 == checksum_42_2);
  assert(accumulator_74_1 == accumulator_74_2);
}

int fn_R000406_613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int checksum_42 = (aux + st.buffer[1]) & 3;
  switch (checksum_42)
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

  int accumulator_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_74 > 24)
  {
    acc = ((acc + (accumulator_74 * 2)) + 5) & 127;
    aux ^= accumulator_74 & 15;
  }
  else
  {
    acc = ((acc - accumulator_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000406_613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st_1 = {0};
  struct EventLog_R000406_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int bound_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_35_1) & 63;
  aux_2 = (aux_2 + bound_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_25_1)
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

  switch (margin_25_2)
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

  int index_reg_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_30_1 > 23)
  {
    acc_1 = ((acc_1 + (index_reg_30_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_30_2 > 23)
  {
    acc_2 = ((acc_2 + (index_reg_30_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_30_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_35_1 == bound_35_2);
  assert(margin_25_1 == margin_25_2);
  assert(index_reg_30_1 == index_reg_30_2);
}

int fn_R000406_613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int bound_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_35) & 63;
  acc ^= aux;
  int margin_25 = (aux + st.buffer[1]) & 3;
  switch (margin_25)
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

  int index_reg_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_30 > 23)
  {
    acc = ((acc + (index_reg_30 * 2)) + 5) & 127;
    aux ^= index_reg_30 & 15;
  }
  else
  {
    acc = ((acc - index_reg_30) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000406_613_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000406_613_0 st_1 = {0};
  struct SensorNode_R000406_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int checksum_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_16_1) & 63;
  aux_2 = (aux_2 + checksum_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_64_1 = local_arr_1[aux_1 % 3];
  int index_reg_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_64_2 * 2)) & 127;
  int weight_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_44_1 > 49)
  {
    acc_1 = ((acc_1 + (weight_44_1 * 2)) + 5) & 127;
    aux_1 ^= weight_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_44_2 > 49)
  {
    acc_2 = ((acc_2 + (weight_44_2 * 2)) + 5) & 127;
    aux_2 ^= weight_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_16_1 == checksum_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_64_1 == index_reg_64_2);
  assert(weight_44_1 == weight_44_2);
}

int fn_R000406_613_5(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000406_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int checksum_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_16) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_64 = local_arr[aux % 3];
  acc = (acc + (index_reg_64 * 2)) & 127;
  int weight_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_44 > 49)
  {
    acc = ((acc + (weight_44 * 2)) + 5) & 127;
    aux ^= weight_44 & 15;
  }
  else
  {
    acc = ((acc - weight_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000406_613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st_1 = {0};
  struct EventLog_R000406_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_85_1 > 18)
  {
    acc_1 = ((acc_1 + (accumulator_85_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_85_2 > 18)
  {
    acc_2 = ((acc_2 + (accumulator_85_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_85_1 == accumulator_85_2);
}

int fn_R000406_613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_85 > 18)
  {
    acc = ((acc + (accumulator_85 * 2)) + 5) & 127;
    aux ^= accumulator_85 & 15;
  }
  else
  {
    acc = ((acc - accumulator_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000406_613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st_1 = {0};
  struct EventLog_R000406_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int index_reg_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_71_1 > 45)
  {
    acc_1 = ((acc_1 + (index_reg_71_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_71_2 > 45)
  {
    acc_2 = ((acc_2 + (index_reg_71_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_76_1)
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

  switch (coefficient_76_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_71_1 == index_reg_71_2);
  assert(coefficient_76_1 == coefficient_76_2);
}

int fn_R000406_613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int index_reg_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_71 > 45)
  {
    acc = ((acc + (index_reg_71 * 2)) + 5) & 127;
    aux ^= index_reg_71 & 15;
  }
  else
  {
    acc = ((acc - index_reg_71) + 11) & 127;
    aux += 3;
  }
  int coefficient_76 = (aux + st.buffer[1]) & 3;
  switch (coefficient_76)
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

void fn_R000406_613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st_1 = {0};
  struct StreamBuffer_R000406_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int coefficient_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_22_1)
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

  switch (coefficient_22_2)
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

  int anchor_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_70_1) & 63;
  aux_2 = (aux_2 + anchor_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_57_1 > 26)
  {
    acc_1 = ((acc_1 + (checksum_57_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_57_2 > 26)
  {
    acc_2 = ((acc_2 + (checksum_57_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_22_1 == coefficient_22_2);
  assert(anchor_70_1 == anchor_70_2);
  assert(checksum_57_1 == checksum_57_2);
}

int fn_R000406_613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int coefficient_22 = (aux + st.buffer[1]) & 3;
  switch (coefficient_22)
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

  int anchor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_57 > 26)
  {
    acc = ((acc + (checksum_57 * 2)) + 5) & 127;
    aux ^= checksum_57 & 15;
  }
  else
  {
    acc = ((acc - checksum_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000406_613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st_1 = {0};
  struct EventLog_R000406_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int scale_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_11_1) & 63;
  aux_2 = (aux_2 + scale_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_27_1 = local_arr_1[aux_1 % 3];
  int window_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_27_2 * 2)) & 127;
  int segment_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_82_1)
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

  switch (segment_82_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_11_1 == scale_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_27_1 == window_27_2);
  assert(segment_82_1 == segment_82_2);
}

int fn_R000406_613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int scale_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_11) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_27 = local_arr[aux % 3];
  acc = (acc + (window_27 * 2)) & 127;
  int segment_82 = (aux + st.buffer[1]) & 3;
  switch (segment_82)
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

void fn_R000406_613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000406_613_0 st_1 = {0};
  struct SensorNode_R000406_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_85_1) & 63;
  aux_2 = (aux_2 + anchor_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_95_1 > 35)
  {
    acc_1 = ((acc_1 + (residue_95_1 * 2)) + 5) & 127;
    aux_1 ^= residue_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_95_2 > 35)
  {
    acc_2 = ((acc_2 + (residue_95_2 * 2)) + 5) & 127;
    aux_2 ^= residue_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_28_1)
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

  switch (sample_28_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_85_1 == anchor_85_2);
  assert(residue_95_1 == residue_95_2);
  assert(sample_28_1 == sample_28_2);
}

int fn_R000406_613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000406_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_85) & 63;
  acc ^= aux;
  int residue_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_95 > 35)
  {
    acc = ((acc + (residue_95 * 2)) + 5) & 127;
    aux ^= residue_95 & 15;
  }
  else
  {
    acc = ((acc - residue_95) + 11) & 127;
    aux += 3;
  }
  int sample_28 = (aux + st.buffer[1]) & 3;
  switch (sample_28)
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

void fn_R000406_613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st_1 = {0};
  struct EventLog_R000406_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int bound_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_25_1 > 22)
  {
    acc_1 = ((acc_1 + (bound_25_1 * 2)) + 5) & 127;
    aux_1 ^= bound_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_25_2 > 22)
  {
    acc_2 = ((acc_2 + (bound_25_2 * 2)) + 5) & 127;
    aux_2 ^= bound_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_12_1) & 63;
  aux_2 = (aux_2 + vector_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_25_1 == bound_25_2);
  assert(vector_12_1 == vector_12_2);
}

int fn_R000406_613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000406_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int bound_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_25 > 22)
  {
    acc = ((acc + (bound_25 * 2)) + 5) & 127;
    aux ^= bound_25 & 15;
  }
  else
  {
    acc = ((acc - bound_25) + 11) & 127;
    aux += 3;
  }
  int vector_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000406_613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st_1 = {0};
  struct StreamBuffer_R000406_613_2 st_2 = {0};
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
  int anchor_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_52_1 > 22)
  {
    acc_1 = ((acc_1 + (anchor_52_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_52_2 > 22)
  {
    acc_2 = ((acc_2 + (anchor_52_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_52_1 == anchor_52_2);
}

int fn_R000406_613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_52 > 22)
  {
    acc = ((acc + (anchor_52 * 2)) + 5) & 127;
    aux ^= anchor_52 & 15;
  }
  else
  {
    acc = ((acc - anchor_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000406_613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st_1 = {0};
  struct StreamBuffer_R000406_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int metric_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_65_1 > 32)
  {
    acc_1 = ((acc_1 + (metric_65_1 * 2)) + 5) & 127;
    aux_1 ^= metric_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_65_2 > 32)
  {
    acc_2 = ((acc_2 + (metric_65_2 * 2)) + 5) & 127;
    aux_2 ^= metric_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_39_1)
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

  switch (cursor_39_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_65_1 == metric_65_2);
  assert(cursor_39_1 == cursor_39_2);
}

int fn_R000406_613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int metric_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_65 > 32)
  {
    acc = ((acc + (metric_65 * 2)) + 5) & 127;
    aux ^= metric_65 & 15;
  }
  else
  {
    acc = ((acc - metric_65) + 11) & 127;
    aux += 3;
  }
  int cursor_39 = (aux + st.buffer[1]) & 3;
  switch (cursor_39)
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

void fn_R000406_613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st_1 = {0};
  struct StreamBuffer_R000406_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quotient_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_89_1 > 35)
  {
    acc_1 = ((acc_1 + (quotient_89_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_89_2 > 35)
  {
    acc_2 = ((acc_2 + (quotient_89_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_50_1)
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

  switch (pivot_50_2)
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

  int delta_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_80_1) & 63;
  aux_2 = (aux_2 + delta_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_89_1 == quotient_89_2);
  assert(pivot_50_1 == pivot_50_2);
  assert(delta_80_1 == delta_80_2);
}

int fn_R000406_613_14(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quotient_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_89 > 35)
  {
    acc = ((acc + (quotient_89 * 2)) + 5) & 127;
    aux ^= quotient_89 & 15;
  }
  else
  {
    acc = ((acc - quotient_89) + 11) & 127;
    aux += 3;
  }
  int pivot_50 = (aux + st.buffer[1]) & 3;
  switch (pivot_50)
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

  int delta_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_80) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000406_613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st_1 = {0};
  struct StreamBuffer_R000406_613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int checksum_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_71_1) & 63;
  aux_2 = (aux_2 + checksum_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_58_1 = local_arr_1[aux_1 % 3];
  int factor_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_58_2 * 2)) & 127;
  int tracker_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_63_1 > 32)
  {
    acc_1 = ((acc_1 + (tracker_63_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_63_2 > 32)
  {
    acc_2 = ((acc_2 + (tracker_63_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_63_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_71_1 == checksum_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_58_1 == factor_58_2);
  assert(tracker_63_1 == tracker_63_2);
}

int fn_R000406_613_15(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000406_613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int checksum_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_71) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_58 = local_arr[aux % 3];
  acc = (acc + (factor_58 * 2)) & 127;
  int tracker_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_63 > 32)
  {
    acc = ((acc + (tracker_63 * 2)) + 5) & 127;
    aux ^= tracker_63 & 15;
  }
  else
  {
    acc = ((acc - tracker_63) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000406_0_1;
  int sec_r000406_0_2;
  int sec_r000406_1_1;
  int sec_r000406_1_2;
  int sec_r000406_2_1;
  int sec_r000406_2_2;
  int sec_r000406_3_1;
  int sec_r000406_3_2;
  int sec_r000406_4_1;
  int sec_r000406_4_2;
  int sec_r000406_5_1;
  int sec_r000406_5_2;
  int sec_r000406_6_1;
  int sec_r000406_6_2;
  int sec_r000406_7_1;
  int sec_r000406_7_2;
  int sec_r000406_8_1;
  int sec_r000406_8_2;
  int sec_r000406_9_1;
  int sec_r000406_9_2;
  int sec_r000406_10_1;
  int sec_r000406_10_2;
  int sec_r000406_11_1;
  int sec_r000406_11_2;
  int sec_r000406_12_1;
  int sec_r000406_12_2;
  int sec_r000406_13_1;
  int sec_r000406_13_2;
  int sec_r000406_14_1;
  int sec_r000406_14_2;
  int sec_r000406_15_1;
  int sec_r000406_15_2;
  int sec_r000406_16_1;
  int sec_r000406_16_2;
  int sec_r000406_17_1;
  int sec_r000406_17_2;
  int sec_r000406_18_1;
  int sec_r000406_18_2;
  int sec_r000406_19_1;
  int sec_r000406_19_2;
  int sec_r000406_20_1;
  int sec_r000406_20_2;
  int sec_r000406_21_1;
  int sec_r000406_21_2;
  int sec_r000406_22_1;
  int sec_r000406_22_2;
  int sec_r000406_23_1;
  int sec_r000406_23_2;
  int pub_r000406_0_1;
  int pub_r000406_0_2;
  int pub_r000406_1_1;
  int pub_r000406_1_2;
  int pub_r000406_2_1;
  int pub_r000406_2_2;
  int pub_r000406_3_1;
  int pub_r000406_3_2;
  int pub_r000406_4_1;
  int pub_r000406_4_2;
  int pub_r000406_5_1;
  int pub_r000406_5_2;
  int pub_r000406_6_1;
  int pub_r000406_6_2;
  int pub_r000406_7_1;
  int pub_r000406_7_2;
  int pub_r000406_8_1;
  int pub_r000406_8_2;
  int pub_r000406_9_1;
  int pub_r000406_9_2;
  int pub_r000406_10_1;
  int pub_r000406_10_2;
  int pub_r000406_11_1;
  int pub_r000406_11_2;
  int pub_r000406_12_1;
  int pub_r000406_12_2;
  int pub_r000406_13_1;
  int pub_r000406_13_2;
  int pub_r000406_14_1;
  int pub_r000406_14_2;
  int pub_r000406_15_1;
  int pub_r000406_15_2;
  int pub_r000406_16_1;
  int pub_r000406_16_2;
  int pub_r000406_17_1;
  int pub_r000406_17_2;
  int pub_r000406_18_1;
  int pub_r000406_18_2;
  int pub_r000406_19_1;
  int pub_r000406_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000406_0_1 >= (-100)) && (pub_r000406_0_1 <= 100));
  __CPROVER_assume((pub_r000406_0_2 >= (-100)) && (pub_r000406_0_2 <= 100));
  __CPROVER_assume((pub_r000406_1_1 >= (-100)) && (pub_r000406_1_1 <= 100));
  __CPROVER_assume((pub_r000406_1_2 >= (-100)) && (pub_r000406_1_2 <= 100));
  __CPROVER_assume((pub_r000406_2_1 >= (-100)) && (pub_r000406_2_1 <= 100));
  __CPROVER_assume((pub_r000406_2_2 >= (-100)) && (pub_r000406_2_2 <= 100));
  __CPROVER_assume((pub_r000406_3_1 >= (-100)) && (pub_r000406_3_1 <= 100));
  __CPROVER_assume((pub_r000406_3_2 >= (-100)) && (pub_r000406_3_2 <= 100));
  __CPROVER_assume((pub_r000406_4_1 >= (-100)) && (pub_r000406_4_1 <= 100));
  __CPROVER_assume((pub_r000406_4_2 >= (-100)) && (pub_r000406_4_2 <= 100));
  __CPROVER_assume((pub_r000406_5_1 >= (-100)) && (pub_r000406_5_1 <= 100));
  __CPROVER_assume((pub_r000406_5_2 >= (-100)) && (pub_r000406_5_2 <= 100));
  __CPROVER_assume((pub_r000406_6_1 >= (-100)) && (pub_r000406_6_1 <= 100));
  __CPROVER_assume((pub_r000406_6_2 >= (-100)) && (pub_r000406_6_2 <= 100));
  __CPROVER_assume((pub_r000406_7_1 >= (-100)) && (pub_r000406_7_1 <= 100));
  __CPROVER_assume((pub_r000406_7_2 >= (-100)) && (pub_r000406_7_2 <= 100));
  __CPROVER_assume((pub_r000406_8_1 >= (-100)) && (pub_r000406_8_1 <= 100));
  __CPROVER_assume((pub_r000406_8_2 >= (-100)) && (pub_r000406_8_2 <= 100));
  __CPROVER_assume((pub_r000406_9_1 >= (-100)) && (pub_r000406_9_1 <= 100));
  __CPROVER_assume((pub_r000406_9_2 >= (-100)) && (pub_r000406_9_2 <= 100));
  __CPROVER_assume((pub_r000406_10_1 >= (-100)) && (pub_r000406_10_1 <= 100));
  __CPROVER_assume((pub_r000406_10_2 >= (-100)) && (pub_r000406_10_2 <= 100));
  __CPROVER_assume((pub_r000406_11_1 >= (-100)) && (pub_r000406_11_1 <= 100));
  __CPROVER_assume((pub_r000406_11_2 >= (-100)) && (pub_r000406_11_2 <= 100));
  __CPROVER_assume((pub_r000406_12_1 >= (-100)) && (pub_r000406_12_1 <= 100));
  __CPROVER_assume((pub_r000406_12_2 >= (-100)) && (pub_r000406_12_2 <= 100));
  __CPROVER_assume((pub_r000406_13_1 >= (-100)) && (pub_r000406_13_1 <= 100));
  __CPROVER_assume((pub_r000406_13_2 >= (-100)) && (pub_r000406_13_2 <= 100));
  __CPROVER_assume((pub_r000406_14_1 >= (-100)) && (pub_r000406_14_1 <= 100));
  __CPROVER_assume((pub_r000406_14_2 >= (-100)) && (pub_r000406_14_2 <= 100));
  __CPROVER_assume((pub_r000406_15_1 >= (-100)) && (pub_r000406_15_1 <= 100));
  __CPROVER_assume((pub_r000406_15_2 >= (-100)) && (pub_r000406_15_2 <= 100));
  __CPROVER_assume((pub_r000406_16_1 >= (-100)) && (pub_r000406_16_1 <= 100));
  __CPROVER_assume((pub_r000406_16_2 >= (-100)) && (pub_r000406_16_2 <= 100));
  __CPROVER_assume((pub_r000406_17_1 >= (-100)) && (pub_r000406_17_1 <= 100));
  __CPROVER_assume((pub_r000406_17_2 >= (-100)) && (pub_r000406_17_2 <= 100));
  __CPROVER_assume((pub_r000406_18_1 >= (-100)) && (pub_r000406_18_1 <= 100));
  __CPROVER_assume((pub_r000406_18_2 >= (-100)) && (pub_r000406_18_2 <= 100));
  __CPROVER_assume((pub_r000406_19_1 >= (-100)) && (pub_r000406_19_1 <= 100));
  __CPROVER_assume((pub_r000406_19_2 >= (-100)) && (pub_r000406_19_2 <= 100));
  __CPROVER_assume((sec_r000406_0_1 >= 0) && (sec_r000406_0_1 <= 255));
  __CPROVER_assume((sec_r000406_0_2 >= 0) && (sec_r000406_0_2 <= 255));
  __CPROVER_assume((sec_r000406_1_1 >= 0) && (sec_r000406_1_1 <= 255));
  __CPROVER_assume((sec_r000406_1_2 >= 0) && (sec_r000406_1_2 <= 255));
  __CPROVER_assume((sec_r000406_2_1 >= 0) && (sec_r000406_2_1 <= 255));
  __CPROVER_assume((sec_r000406_2_2 >= 0) && (sec_r000406_2_2 <= 255));
  __CPROVER_assume((sec_r000406_3_1 >= 0) && (sec_r000406_3_1 <= 255));
  __CPROVER_assume((sec_r000406_3_2 >= 0) && (sec_r000406_3_2 <= 255));
  __CPROVER_assume((sec_r000406_4_1 >= 0) && (sec_r000406_4_1 <= 255));
  __CPROVER_assume((sec_r000406_4_2 >= 0) && (sec_r000406_4_2 <= 255));
  __CPROVER_assume((sec_r000406_5_1 >= 0) && (sec_r000406_5_1 <= 255));
  __CPROVER_assume((sec_r000406_5_2 >= 0) && (sec_r000406_5_2 <= 255));
  __CPROVER_assume((sec_r000406_6_1 >= 0) && (sec_r000406_6_1 <= 255));
  __CPROVER_assume((sec_r000406_6_2 >= 0) && (sec_r000406_6_2 <= 255));
  __CPROVER_assume((sec_r000406_7_1 >= 0) && (sec_r000406_7_1 <= 255));
  __CPROVER_assume((sec_r000406_7_2 >= 0) && (sec_r000406_7_2 <= 255));
  __CPROVER_assume((sec_r000406_8_1 >= 0) && (sec_r000406_8_1 <= 255));
  __CPROVER_assume((sec_r000406_8_2 >= 0) && (sec_r000406_8_2 <= 255));
  __CPROVER_assume((sec_r000406_9_1 >= 0) && (sec_r000406_9_1 <= 255));
  __CPROVER_assume((sec_r000406_9_2 >= 0) && (sec_r000406_9_2 <= 255));
  __CPROVER_assume((sec_r000406_10_1 >= 0) && (sec_r000406_10_1 <= 255));
  __CPROVER_assume((sec_r000406_10_2 >= 0) && (sec_r000406_10_2 <= 255));
  __CPROVER_assume((sec_r000406_11_1 >= 0) && (sec_r000406_11_1 <= 255));
  __CPROVER_assume((sec_r000406_11_2 >= 0) && (sec_r000406_11_2 <= 255));
  __CPROVER_assume((sec_r000406_12_1 >= 0) && (sec_r000406_12_1 <= 255));
  __CPROVER_assume((sec_r000406_12_2 >= 0) && (sec_r000406_12_2 <= 255));
  __CPROVER_assume((sec_r000406_13_1 >= 0) && (sec_r000406_13_1 <= 255));
  __CPROVER_assume((sec_r000406_13_2 >= 0) && (sec_r000406_13_2 <= 255));
  __CPROVER_assume((sec_r000406_14_1 >= 0) && (sec_r000406_14_1 <= 255));
  __CPROVER_assume((sec_r000406_14_2 >= 0) && (sec_r000406_14_2 <= 255));
  __CPROVER_assume((sec_r000406_15_1 >= 0) && (sec_r000406_15_1 <= 255));
  __CPROVER_assume((sec_r000406_15_2 >= 0) && (sec_r000406_15_2 <= 255));
  __CPROVER_assume((sec_r000406_16_1 >= 0) && (sec_r000406_16_1 <= 255));
  __CPROVER_assume((sec_r000406_16_2 >= 0) && (sec_r000406_16_2 <= 255));
  __CPROVER_assume((sec_r000406_17_1 >= 0) && (sec_r000406_17_1 <= 255));
  __CPROVER_assume((sec_r000406_17_2 >= 0) && (sec_r000406_17_2 <= 255));
  __CPROVER_assume((sec_r000406_18_1 >= 0) && (sec_r000406_18_1 <= 255));
  __CPROVER_assume((sec_r000406_18_2 >= 0) && (sec_r000406_18_2 <= 255));
  __CPROVER_assume((sec_r000406_19_1 >= 0) && (sec_r000406_19_1 <= 255));
  __CPROVER_assume((sec_r000406_19_2 >= 0) && (sec_r000406_19_2 <= 255));
  __CPROVER_assume((sec_r000406_20_1 >= 0) && (sec_r000406_20_1 <= 255));
  __CPROVER_assume((sec_r000406_20_2 >= 0) && (sec_r000406_20_2 <= 255));
  __CPROVER_assume((sec_r000406_21_1 >= 0) && (sec_r000406_21_1 <= 255));
  __CPROVER_assume((sec_r000406_21_2 >= 0) && (sec_r000406_21_2 <= 255));
  __CPROVER_assume((sec_r000406_22_1 >= 0) && (sec_r000406_22_1 <= 255));
  __CPROVER_assume((sec_r000406_22_2 >= 0) && (sec_r000406_22_2 <= 255));
  __CPROVER_assume((sec_r000406_23_1 >= 0) && (sec_r000406_23_1 <= 255));
  __CPROVER_assume((sec_r000406_23_2 >= 0) && (sec_r000406_23_2 <= 255));
  struct SensorNode_R000406_613_0 st_var_0_1 = {0};
  struct SensorNode_R000406_613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000406_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000406_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000406_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000406_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000406_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000406_0_2 + 7) & 15;
  struct EventLog_R000406_613_1 st_var_1_1 = {0};
  struct EventLog_R000406_613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000406_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000406_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000406_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000406_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000406_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000406_0_2 + 9) & 15;
  struct StreamBuffer_R000406_613_2 st_var_2_1 = {0};
  struct StreamBuffer_R000406_613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000406_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000406_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000406_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000406_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000406_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000406_0_2 + 11) & 15;
  union RegisterBank_R000406_613_0 u_var_1;
  union RegisterBank_R000406_613_0 u_var_2;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 35)
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
  if (stage_v_2_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 35)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
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
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = ((st_var_0_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_0_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 28)
    {
      chk_sum_1 ^= stage_v_9_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_9_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 28)
    {
      chk_sum_2 ^= stage_v_9_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 44)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 44)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 18) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
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
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = ((st_var_2_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_2_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 46)
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
  if (stage_v_20_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 46)
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
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 29)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 29)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = ((st_var_1_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_1_2.buffer[1] * 2) + 73) & 63;
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
  int stage_v_23_1 = (st_var_2_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_2_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((sec_r000406_14_1 & 63) > 41)
  {
    stage_v_24_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  }
  else
  {
    stage_v_24_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
  }
  if ((sec_r000406_14_2 & 63) > 41)
  {
    stage_v_24_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  }
  else
  {
    stage_v_24_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_24_1 & 63) > 16)
  {
    stage_v_25_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  }
  else
  {
    stage_v_25_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 16)
  {
    stage_v_25_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  }
  else
  {
    stage_v_25_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_25_1 & 63) > 28)
  {
    stage_v_26_1 = ((pub_r000406_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  }
  else
  {
    stage_v_26_1 = ((pub_r000406_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
  }
  if ((stage_v_25_2 & 63) > 28)
  {
    stage_v_26_2 = ((pub_r000406_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  }
  else
  {
    stage_v_26_2 = ((pub_r000406_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_24_1 & 63) > 41)
  {
    stage_v_27_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  }
  else
  {
    stage_v_27_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
  }
  if ((stage_v_24_2 & 63) > 41)
  {
    stage_v_27_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  }
  else
  {
    stage_v_27_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((sec_r000406_21_1 & 63) > 49)
  {
    stage_v_28_1 = ((pub_r000406_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  }
  else
  {
    stage_v_28_1 = ((pub_r000406_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
  }
  if ((sec_r000406_21_2 & 63) > 49)
  {
    stage_v_28_2 = ((pub_r000406_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  }
  else
  {
    stage_v_28_2 = ((pub_r000406_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_25_1 & 63) > 56)
  {
    stage_v_29_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  }
  else
  {
    stage_v_29_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
  }
  if ((stage_v_25_2 & 63) > 56)
  {
    stage_v_29_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  }
  else
  {
    stage_v_29_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((sec_r000406_20_1 & 63) > 53)
  {
    stage_v_30_1 = ((pub_r000406_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  }
  else
  {
    stage_v_30_1 = ((pub_r000406_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
  }
  if ((sec_r000406_20_2 & 63) > 53)
  {
    stage_v_30_2 = ((pub_r000406_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  }
  else
  {
    stage_v_30_2 = ((pub_r000406_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_26_1 & 63) > 45)
  {
    stage_v_31_1 = ((pub_r000406_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  }
  else
  {
    stage_v_31_1 = ((pub_r000406_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
  }
  if ((stage_v_26_2 & 63) > 45)
  {
    stage_v_31_2 = ((pub_r000406_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  }
  else
  {
    stage_v_31_2 = ((pub_r000406_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_29_1 & 63) > 51)
  {
    stage_v_32_1 = ((pub_r000406_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  }
  else
  {
    stage_v_32_1 = ((pub_r000406_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
  }
  if ((stage_v_29_2 & 63) > 51)
  {
    stage_v_32_2 = ((pub_r000406_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  }
  else
  {
    stage_v_32_2 = ((pub_r000406_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_25_1 & 63) > 23)
  {
    stage_v_33_1 = ((pub_r000406_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  }
  else
  {
    stage_v_33_1 = ((pub_r000406_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
  }
  if ((stage_v_25_2 & 63) > 23)
  {
    stage_v_33_2 = ((pub_r000406_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  }
  else
  {
    stage_v_33_2 = ((pub_r000406_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((sec_r000406_0_1 & 63) > 36)
  {
    stage_v_34_1 = ((pub_r000406_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  }
  else
  {
    stage_v_34_1 = ((pub_r000406_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
  }
  if ((sec_r000406_0_2 & 63) > 36)
  {
    stage_v_34_2 = ((pub_r000406_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  }
  else
  {
    stage_v_34_2 = ((pub_r000406_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((sec_r000406_17_1 & 63) > 19)
  {
    stage_v_35_1 = ((pub_r000406_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  }
  else
  {
    stage_v_35_1 = ((pub_r000406_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
  }
  if ((sec_r000406_17_2 & 63) > 19)
  {
    stage_v_35_2 = ((pub_r000406_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  }
  else
  {
    stage_v_35_2 = ((pub_r000406_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_34_1 & 63) > 53)
  {
    stage_v_36_1 = ((pub_r000406_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  }
  else
  {
    stage_v_36_1 = ((pub_r000406_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 53)
  {
    stage_v_36_2 = ((pub_r000406_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  }
  else
  {
    stage_v_36_2 = ((pub_r000406_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_26_1 & 63) > 57)
  {
    stage_v_37_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  }
  else
  {
    stage_v_37_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
  }
  if ((stage_v_26_2 & 63) > 57)
  {
    stage_v_37_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  }
  else
  {
    stage_v_37_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_34_1 & 63) > 30)
  {
    stage_v_38_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  }
  else
  {
    stage_v_38_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 30)
  {
    stage_v_38_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  }
  else
  {
    stage_v_38_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000406_15_1 & 63) > 56)
  {
    stage_v_39_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  }
  else
  {
    stage_v_39_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
  }
  if ((sec_r000406_15_2 & 63) > 56)
  {
    stage_v_39_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  }
  else
  {
    stage_v_39_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_39_1 & 63) > 51)
  {
    stage_v_40_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  }
  else
  {
    stage_v_40_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
  }
  if ((stage_v_39_2 & 63) > 51)
  {
    stage_v_40_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  }
  else
  {
    stage_v_40_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_32_1 & 63) > 21)
  {
    stage_v_41_1 = ((pub_r000406_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  }
  else
  {
    stage_v_41_1 = ((pub_r000406_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
  }
  if ((stage_v_32_2 & 63) > 21)
  {
    stage_v_41_2 = ((pub_r000406_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  }
  else
  {
    stage_v_41_2 = ((pub_r000406_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_32_1 & 63) > 28)
  {
    stage_v_42_1 = ((pub_r000406_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  }
  else
  {
    stage_v_42_1 = ((pub_r000406_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
  }
  if ((stage_v_32_2 & 63) > 28)
  {
    stage_v_42_2 = ((pub_r000406_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  }
  else
  {
    stage_v_42_2 = ((pub_r000406_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((sec_r000406_16_1 & 63) > 28)
  {
    stage_v_43_1 = ((pub_r000406_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  }
  else
  {
    stage_v_43_1 = ((pub_r000406_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
  }
  if ((sec_r000406_16_2 & 63) > 28)
  {
    stage_v_43_2 = ((pub_r000406_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  }
  else
  {
    stage_v_43_2 = ((pub_r000406_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_29_1 & 63) > 24)
  {
    stage_v_44_1 = ((pub_r000406_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  }
  else
  {
    stage_v_44_1 = ((pub_r000406_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
  }
  if ((stage_v_29_2 & 63) > 24)
  {
    stage_v_44_2 = ((pub_r000406_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  }
  else
  {
    stage_v_44_2 = ((pub_r000406_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_35_1 & 63) > 18)
  {
    stage_v_45_1 = ((pub_r000406_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  }
  else
  {
    stage_v_45_1 = ((pub_r000406_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
  }
  if ((stage_v_35_2 & 63) > 18)
  {
    stage_v_45_2 = ((pub_r000406_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  }
  else
  {
    stage_v_45_2 = ((pub_r000406_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000406_11_1 & 63) > 33)
  {
    stage_v_46_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  }
  else
  {
    stage_v_46_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
  }
  if ((sec_r000406_11_2 & 63) > 33)
  {
    stage_v_46_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  }
  else
  {
    stage_v_46_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000406_4_1 & 63) > 53)
  {
    stage_v_47_1 = ((pub_r000406_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  }
  else
  {
    stage_v_47_1 = ((pub_r000406_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
  }
  if ((sec_r000406_4_2 & 63) > 53)
  {
    stage_v_47_2 = ((pub_r000406_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  }
  else
  {
    stage_v_47_2 = ((pub_r000406_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_45_1 & 63) > 27)
  {
    stage_v_48_1 = ((pub_r000406_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  }
  else
  {
    stage_v_48_1 = ((pub_r000406_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
  }
  if ((stage_v_45_2 & 63) > 27)
  {
    stage_v_48_2 = ((pub_r000406_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  }
  else
  {
    stage_v_48_2 = ((pub_r000406_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_45_1 & 63) > 15)
  {
    stage_v_49_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  }
  else
  {
    stage_v_49_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
  }
  if ((stage_v_45_2 & 63) > 15)
  {
    stage_v_49_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  }
  else
  {
    stage_v_49_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_45_1 & 63) > 33)
  {
    stage_v_50_1 = ((pub_r000406_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  }
  else
  {
    stage_v_50_1 = ((pub_r000406_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
  }
  if ((stage_v_45_2 & 63) > 33)
  {
    stage_v_50_2 = ((pub_r000406_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  }
  else
  {
    stage_v_50_2 = ((pub_r000406_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000406_10_1 & 63) > 52)
  {
    stage_v_51_1 = ((pub_r000406_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  }
  else
  {
    stage_v_51_1 = ((pub_r000406_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
  }
  if ((sec_r000406_10_2 & 63) > 52)
  {
    stage_v_51_2 = ((pub_r000406_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  }
  else
  {
    stage_v_51_2 = ((pub_r000406_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000406_1_1 & 63) > 47)
  {
    stage_v_52_1 = ((pub_r000406_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  }
  else
  {
    stage_v_52_1 = ((pub_r000406_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
  }
  if ((sec_r000406_1_2 & 63) > 47)
  {
    stage_v_52_2 = ((pub_r000406_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  }
  else
  {
    stage_v_52_2 = ((pub_r000406_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_38_1 & 63) > 16)
  {
    stage_v_53_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  }
  else
  {
    stage_v_53_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
  }
  if ((stage_v_38_2 & 63) > 16)
  {
    stage_v_53_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  }
  else
  {
    stage_v_53_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000406_8_1 & 63) > 44)
  {
    stage_v_54_1 = ((pub_r000406_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  }
  else
  {
    stage_v_54_1 = ((pub_r000406_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
  }
  if ((sec_r000406_8_2 & 63) > 44)
  {
    stage_v_54_2 = ((pub_r000406_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  }
  else
  {
    stage_v_54_2 = ((pub_r000406_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_33_1 & 63) > 54)
  {
    stage_v_55_1 = ((pub_r000406_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  }
  else
  {
    stage_v_55_1 = ((pub_r000406_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
  }
  if ((stage_v_33_2 & 63) > 54)
  {
    stage_v_55_2 = ((pub_r000406_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  }
  else
  {
    stage_v_55_2 = ((pub_r000406_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_52_1 & 63) > 19)
  {
    stage_v_56_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  }
  else
  {
    stage_v_56_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 19)
  {
    stage_v_56_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  }
  else
  {
    stage_v_56_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000406_8_1 & 63) > 53)
  {
    stage_v_57_1 = ((pub_r000406_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  }
  else
  {
    stage_v_57_1 = ((pub_r000406_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
  }
  if ((sec_r000406_8_2 & 63) > 53)
  {
    stage_v_57_2 = ((pub_r000406_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  }
  else
  {
    stage_v_57_2 = ((pub_r000406_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_39_1 & 63) > 53)
  {
    stage_v_58_1 = ((pub_r000406_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  }
  else
  {
    stage_v_58_1 = ((pub_r000406_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
  }
  if ((stage_v_39_2 & 63) > 53)
  {
    stage_v_58_2 = ((pub_r000406_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  }
  else
  {
    stage_v_58_2 = ((pub_r000406_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_25_1 & 63) > 24)
  {
    stage_v_59_1 = ((pub_r000406_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  }
  else
  {
    stage_v_59_1 = ((pub_r000406_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
  }
  if ((stage_v_25_2 & 63) > 24)
  {
    stage_v_59_2 = ((pub_r000406_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  }
  else
  {
    stage_v_59_2 = ((pub_r000406_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_34_1 & 63) > 31)
  {
    stage_v_60_1 = ((pub_r000406_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  }
  else
  {
    stage_v_60_1 = ((pub_r000406_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 31)
  {
    stage_v_60_2 = ((pub_r000406_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  }
  else
  {
    stage_v_60_2 = ((pub_r000406_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_59_1 & 63) > 47)
  {
    stage_v_61_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  }
  else
  {
    stage_v_61_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
  }
  if ((stage_v_59_2 & 63) > 47)
  {
    stage_v_61_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  }
  else
  {
    stage_v_61_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_37_1 & 63) > 53)
  {
    stage_v_62_1 = ((pub_r000406_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  }
  else
  {
    stage_v_62_1 = ((pub_r000406_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
  }
  if ((stage_v_37_2 & 63) > 53)
  {
    stage_v_62_2 = ((pub_r000406_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  }
  else
  {
    stage_v_62_2 = ((pub_r000406_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_51_1 & 63) > 34)
  {
    stage_v_63_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  }
  else
  {
    stage_v_63_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
  }
  if ((stage_v_51_2 & 63) > 34)
  {
    stage_v_63_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  }
  else
  {
    stage_v_63_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000406_6_1 & 63) > 30)
  {
    stage_v_64_1 = ((pub_r000406_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  }
  else
  {
    stage_v_64_1 = ((pub_r000406_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
  }
  if ((sec_r000406_6_2 & 63) > 30)
  {
    stage_v_64_2 = ((pub_r000406_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  }
  else
  {
    stage_v_64_2 = ((pub_r000406_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000406_16_1 & 63) > 40)
  {
    stage_v_65_1 = ((pub_r000406_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  }
  else
  {
    stage_v_65_1 = ((pub_r000406_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
  }
  if ((sec_r000406_16_2 & 63) > 40)
  {
    stage_v_65_2 = ((pub_r000406_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  }
  else
  {
    stage_v_65_2 = ((pub_r000406_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_34_1 & 63) > 33)
  {
    stage_v_66_1 = ((pub_r000406_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  }
  else
  {
    stage_v_66_1 = ((pub_r000406_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 33)
  {
    stage_v_66_2 = ((pub_r000406_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  }
  else
  {
    stage_v_66_2 = ((pub_r000406_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000406_18_1 & 63) > 50)
  {
    stage_v_67_1 = ((pub_r000406_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  }
  else
  {
    stage_v_67_1 = ((pub_r000406_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
  }
  if ((sec_r000406_18_2 & 63) > 50)
  {
    stage_v_67_2 = ((pub_r000406_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  }
  else
  {
    stage_v_67_2 = ((pub_r000406_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_52_1 & 63) > 19)
  {
    stage_v_68_1 = ((pub_r000406_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  }
  else
  {
    stage_v_68_1 = ((pub_r000406_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 19)
  {
    stage_v_68_2 = ((pub_r000406_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  }
  else
  {
    stage_v_68_2 = ((pub_r000406_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000406_12_1 & 63) > 46)
  {
    stage_v_69_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  }
  else
  {
    stage_v_69_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
  }
  if ((sec_r000406_12_2 & 63) > 46)
  {
    stage_v_69_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  }
  else
  {
    stage_v_69_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000406_0_1 & 63) > 23)
  {
    stage_v_70_1 = ((pub_r000406_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  }
  else
  {
    stage_v_70_1 = ((pub_r000406_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
  }
  if ((sec_r000406_0_2 & 63) > 23)
  {
    stage_v_70_2 = ((pub_r000406_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  }
  else
  {
    stage_v_70_2 = ((pub_r000406_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_64_1 & 63) > 52)
  {
    stage_v_71_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  }
  else
  {
    stage_v_71_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
  }
  if ((stage_v_64_2 & 63) > 52)
  {
    stage_v_71_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  }
  else
  {
    stage_v_71_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_49_1 & 63) > 24)
  {
    stage_v_72_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  }
  else
  {
    stage_v_72_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
  }
  if ((stage_v_49_2 & 63) > 24)
  {
    stage_v_72_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  }
  else
  {
    stage_v_72_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_43_1 & 63) > 40)
  {
    stage_v_73_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  }
  else
  {
    stage_v_73_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
  }
  if ((stage_v_43_2 & 63) > 40)
  {
    stage_v_73_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  }
  else
  {
    stage_v_73_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_27_1 & 63) > 18)
  {
    stage_v_74_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  }
  else
  {
    stage_v_74_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
  }
  if ((stage_v_27_2 & 63) > 18)
  {
    stage_v_74_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  }
  else
  {
    stage_v_74_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_57_1 & 63) > 31)
  {
    stage_v_75_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  }
  else
  {
    stage_v_75_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
  }
  if ((stage_v_57_2 & 63) > 31)
  {
    stage_v_75_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  }
  else
  {
    stage_v_75_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_43_1 & 63) > 59)
  {
    stage_v_76_1 = ((pub_r000406_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  }
  else
  {
    stage_v_76_1 = ((pub_r000406_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
  }
  if ((stage_v_43_2 & 63) > 59)
  {
    stage_v_76_2 = ((pub_r000406_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  }
  else
  {
    stage_v_76_2 = ((pub_r000406_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_75_1 & 63) > 25)
  {
    stage_v_77_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  }
  else
  {
    stage_v_77_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
  }
  if ((stage_v_75_2 & 63) > 25)
  {
    stage_v_77_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  }
  else
  {
    stage_v_77_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_76_1 & 63) > 31)
  {
    stage_v_78_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  }
  else
  {
    stage_v_78_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
  }
  if ((stage_v_76_2 & 63) > 31)
  {
    stage_v_78_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  }
  else
  {
    stage_v_78_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000406_19_1 & 63) > 33)
  {
    stage_v_79_1 = ((pub_r000406_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  }
  else
  {
    stage_v_79_1 = ((pub_r000406_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
  }
  if ((sec_r000406_19_2 & 63) > 33)
  {
    stage_v_79_2 = ((pub_r000406_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  }
  else
  {
    stage_v_79_2 = ((pub_r000406_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_40_1 & 63) > 27)
  {
    stage_v_80_1 = ((pub_r000406_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  }
  else
  {
    stage_v_80_1 = ((pub_r000406_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
  }
  if ((stage_v_40_2 & 63) > 27)
  {
    stage_v_80_2 = ((pub_r000406_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  }
  else
  {
    stage_v_80_2 = ((pub_r000406_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000406_23_1 & 63) > 60)
  {
    stage_v_81_1 = ((pub_r000406_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  }
  else
  {
    stage_v_81_1 = ((pub_r000406_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
  }
  if ((sec_r000406_23_2 & 63) > 60)
  {
    stage_v_81_2 = ((pub_r000406_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  }
  else
  {
    stage_v_81_2 = ((pub_r000406_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_79_1 & 63) > 24)
  {
    stage_v_82_1 = ((pub_r000406_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  }
  else
  {
    stage_v_82_1 = ((pub_r000406_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
  }
  if ((stage_v_79_2 & 63) > 24)
  {
    stage_v_82_2 = ((pub_r000406_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  }
  else
  {
    stage_v_82_2 = ((pub_r000406_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000406_16_1 & 63) > 36)
  {
    stage_v_83_1 = ((pub_r000406_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  }
  else
  {
    stage_v_83_1 = ((pub_r000406_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
  }
  if ((sec_r000406_16_2 & 63) > 36)
  {
    stage_v_83_2 = ((pub_r000406_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  }
  else
  {
    stage_v_83_2 = ((pub_r000406_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_67_1 & 63) > 34)
  {
    stage_v_84_1 = ((pub_r000406_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  }
  else
  {
    stage_v_84_1 = ((pub_r000406_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
  }
  if ((stage_v_67_2 & 63) > 34)
  {
    stage_v_84_2 = ((pub_r000406_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  }
  else
  {
    stage_v_84_2 = ((pub_r000406_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000406_21_1 & 63) > 32)
  {
    stage_v_85_1 = ((pub_r000406_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  }
  else
  {
    stage_v_85_1 = ((pub_r000406_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
  }
  if ((sec_r000406_21_2 & 63) > 32)
  {
    stage_v_85_2 = ((pub_r000406_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  }
  else
  {
    stage_v_85_2 = ((pub_r000406_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_73_1 & 63) > 16)
  {
    stage_v_86_1 = ((pub_r000406_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  }
  else
  {
    stage_v_86_1 = ((pub_r000406_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
  }
  if ((stage_v_73_2 & 63) > 16)
  {
    stage_v_86_2 = ((pub_r000406_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  }
  else
  {
    stage_v_86_2 = ((pub_r000406_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_59_1 & 63) > 22)
  {
    stage_v_87_1 = ((pub_r000406_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  }
  else
  {
    stage_v_87_1 = ((pub_r000406_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
  }
  if ((stage_v_59_2 & 63) > 22)
  {
    stage_v_87_2 = ((pub_r000406_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  }
  else
  {
    stage_v_87_2 = ((pub_r000406_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000406_3_1 & 63) > 53)
  {
    stage_v_88_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  }
  else
  {
    stage_v_88_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
  }
  if ((sec_r000406_3_2 & 63) > 53)
  {
    stage_v_88_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  }
  else
  {
    stage_v_88_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_63_1 & 63) > 27)
  {
    stage_v_89_1 = ((pub_r000406_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  }
  else
  {
    stage_v_89_1 = ((pub_r000406_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
  }
  if ((stage_v_63_2 & 63) > 27)
  {
    stage_v_89_2 = ((pub_r000406_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  }
  else
  {
    stage_v_89_2 = ((pub_r000406_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_51_1 & 63) > 15)
  {
    stage_v_90_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  }
  else
  {
    stage_v_90_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
  }
  if ((stage_v_51_2 & 63) > 15)
  {
    stage_v_90_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  }
  else
  {
    stage_v_90_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000406_1_1 & 63) > 28)
  {
    stage_v_91_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  }
  else
  {
    stage_v_91_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
  }
  if ((sec_r000406_1_2 & 63) > 28)
  {
    stage_v_91_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  }
  else
  {
    stage_v_91_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_50_1 & 63) > 36)
  {
    stage_v_92_1 = ((pub_r000406_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  }
  else
  {
    stage_v_92_1 = ((pub_r000406_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
  }
  if ((stage_v_50_2 & 63) > 36)
  {
    stage_v_92_2 = ((pub_r000406_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  }
  else
  {
    stage_v_92_2 = ((pub_r000406_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000406_17_1 & 63) > 22)
  {
    stage_v_93_1 = ((pub_r000406_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  }
  else
  {
    stage_v_93_1 = ((pub_r000406_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
  }
  if ((sec_r000406_17_2 & 63) > 22)
  {
    stage_v_93_2 = ((pub_r000406_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  }
  else
  {
    stage_v_93_2 = ((pub_r000406_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_68_1 & 63) > 36)
  {
    stage_v_94_1 = ((pub_r000406_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  }
  else
  {
    stage_v_94_1 = ((pub_r000406_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
  }
  if ((stage_v_68_2 & 63) > 36)
  {
    stage_v_94_2 = ((pub_r000406_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  }
  else
  {
    stage_v_94_2 = ((pub_r000406_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_31_1 & 63) > 35)
  {
    stage_v_95_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  }
  else
  {
    stage_v_95_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
  }
  if ((stage_v_31_2 & 63) > 35)
  {
    stage_v_95_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  }
  else
  {
    stage_v_95_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_34_1 & 63) > 21)
  {
    stage_v_96_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  }
  else
  {
    stage_v_96_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
  }
  if ((stage_v_34_2 & 63) > 21)
  {
    stage_v_96_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  }
  else
  {
    stage_v_96_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_69_1 & 63) > 29)
  {
    stage_v_97_1 = ((pub_r000406_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  }
  else
  {
    stage_v_97_1 = ((pub_r000406_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
  }
  if ((stage_v_69_2 & 63) > 29)
  {
    stage_v_97_2 = ((pub_r000406_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  }
  else
  {
    stage_v_97_2 = ((pub_r000406_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_63_1 & 63) > 36)
  {
    stage_v_98_1 = ((pub_r000406_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  }
  else
  {
    stage_v_98_1 = ((pub_r000406_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
  }
  if ((stage_v_63_2 & 63) > 36)
  {
    stage_v_98_2 = ((pub_r000406_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  }
  else
  {
    stage_v_98_2 = ((pub_r000406_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000406_5_1 & 63) > 46)
  {
    stage_v_99_1 = ((pub_r000406_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  }
  else
  {
    stage_v_99_1 = ((pub_r000406_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
  }
  if ((sec_r000406_5_2 & 63) > 46)
  {
    stage_v_99_2 = ((pub_r000406_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  }
  else
  {
    stage_v_99_2 = ((pub_r000406_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_57_1 & 63) > 24)
  {
    stage_v_100_1 = ((pub_r000406_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  }
  else
  {
    stage_v_100_1 = ((pub_r000406_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
  }
  if ((stage_v_57_2 & 63) > 24)
  {
    stage_v_100_2 = ((pub_r000406_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  }
  else
  {
    stage_v_100_2 = ((pub_r000406_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_82_1 & 63) > 19)
  {
    stage_v_101_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  }
  else
  {
    stage_v_101_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
  }
  if ((stage_v_82_2 & 63) > 19)
  {
    stage_v_101_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  }
  else
  {
    stage_v_101_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_53_1 & 63) > 51)
  {
    stage_v_102_1 = ((pub_r000406_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  }
  else
  {
    stage_v_102_1 = ((pub_r000406_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
  }
  if ((stage_v_53_2 & 63) > 51)
  {
    stage_v_102_2 = ((pub_r000406_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  }
  else
  {
    stage_v_102_2 = ((pub_r000406_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000406_19_1 & 63) > 51)
  {
    stage_v_103_1 = ((pub_r000406_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  }
  else
  {
    stage_v_103_1 = ((pub_r000406_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
  }
  if ((sec_r000406_19_2 & 63) > 51)
  {
    stage_v_103_2 = ((pub_r000406_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  }
  else
  {
    stage_v_103_2 = ((pub_r000406_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_90_1 & 63) > 51)
  {
    stage_v_104_1 = ((pub_r000406_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  }
  else
  {
    stage_v_104_1 = ((pub_r000406_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
  }
  if ((stage_v_90_2 & 63) > 51)
  {
    stage_v_104_2 = ((pub_r000406_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  }
  else
  {
    stage_v_104_2 = ((pub_r000406_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_60_1 & 63) > 17)
  {
    stage_v_105_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  }
  else
  {
    stage_v_105_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
  }
  if ((stage_v_60_2 & 63) > 17)
  {
    stage_v_105_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  }
  else
  {
    stage_v_105_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000406_1_1 & 63) > 38)
  {
    stage_v_106_1 = ((pub_r000406_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  }
  else
  {
    stage_v_106_1 = ((pub_r000406_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
  }
  if ((sec_r000406_1_2 & 63) > 38)
  {
    stage_v_106_2 = ((pub_r000406_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  }
  else
  {
    stage_v_106_2 = ((pub_r000406_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_55_1 & 63) > 60)
  {
    stage_v_107_1 = ((pub_r000406_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  }
  else
  {
    stage_v_107_1 = ((pub_r000406_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
  }
  if ((stage_v_55_2 & 63) > 60)
  {
    stage_v_107_2 = ((pub_r000406_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  }
  else
  {
    stage_v_107_2 = ((pub_r000406_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_42_1 & 63) > 48)
  {
    stage_v_108_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  }
  else
  {
    stage_v_108_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
  }
  if ((stage_v_42_2 & 63) > 48)
  {
    stage_v_108_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  }
  else
  {
    stage_v_108_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_107_1 & 63) > 25)
  {
    stage_v_109_1 = ((pub_r000406_7_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  }
  else
  {
    stage_v_109_1 = ((pub_r000406_7_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
  }
  if ((stage_v_107_2 & 63) > 25)
  {
    stage_v_109_2 = ((pub_r000406_7_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  }
  else
  {
    stage_v_109_2 = ((pub_r000406_7_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_33_1 & 63) > 43)
  {
    stage_v_110_1 = ((pub_r000406_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  }
  else
  {
    stage_v_110_1 = ((pub_r000406_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
  }
  if ((stage_v_33_2 & 63) > 43)
  {
    stage_v_110_2 = ((pub_r000406_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  }
  else
  {
    stage_v_110_2 = ((pub_r000406_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_50_1 & 63) > 57)
  {
    stage_v_111_1 = ((pub_r000406_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  }
  else
  {
    stage_v_111_1 = ((pub_r000406_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
  }
  if ((stage_v_50_2 & 63) > 57)
  {
    stage_v_111_2 = ((pub_r000406_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  }
  else
  {
    stage_v_111_2 = ((pub_r000406_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000406_22_1 & 63) > 19)
  {
    stage_v_112_1 = ((pub_r000406_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  }
  else
  {
    stage_v_112_1 = ((pub_r000406_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
  }
  if ((sec_r000406_22_2 & 63) > 19)
  {
    stage_v_112_2 = ((pub_r000406_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  }
  else
  {
    stage_v_112_2 = ((pub_r000406_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000406_1_1 & 63) > 32)
  {
    stage_v_113_1 = ((pub_r000406_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  }
  else
  {
    stage_v_113_1 = ((pub_r000406_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
  }
  if ((sec_r000406_1_2 & 63) > 32)
  {
    stage_v_113_2 = ((pub_r000406_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  }
  else
  {
    stage_v_113_2 = ((pub_r000406_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_94_1 & 63) > 55)
  {
    stage_v_114_1 = ((pub_r000406_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  }
  else
  {
    stage_v_114_1 = ((pub_r000406_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
  }
  if ((stage_v_94_2 & 63) > 55)
  {
    stage_v_114_2 = ((pub_r000406_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  }
  else
  {
    stage_v_114_2 = ((pub_r000406_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000406_2_1 & 63) > 43)
  {
    stage_v_115_1 = ((pub_r000406_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  }
  else
  {
    stage_v_115_1 = ((pub_r000406_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
  }
  if ((sec_r000406_2_2 & 63) > 43)
  {
    stage_v_115_2 = ((pub_r000406_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  }
  else
  {
    stage_v_115_2 = ((pub_r000406_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_111_1 & 63) > 59)
  {
    stage_v_116_1 = ((pub_r000406_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  }
  else
  {
    stage_v_116_1 = ((pub_r000406_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
  }
  if ((stage_v_111_2 & 63) > 59)
  {
    stage_v_116_2 = ((pub_r000406_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  }
  else
  {
    stage_v_116_2 = ((pub_r000406_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_69_1 & 63) > 36)
  {
    stage_v_117_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  }
  else
  {
    stage_v_117_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
  }
  if ((stage_v_69_2 & 63) > 36)
  {
    stage_v_117_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  }
  else
  {
    stage_v_117_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_84_1 & 63) > 55)
  {
    stage_v_118_1 = ((pub_r000406_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  }
  else
  {
    stage_v_118_1 = ((pub_r000406_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
  }
  if ((stage_v_84_2 & 63) > 55)
  {
    stage_v_118_2 = ((pub_r000406_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  }
  else
  {
    stage_v_118_2 = ((pub_r000406_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000406_6_1 & 63) > 44)
  {
    stage_v_119_1 = ((pub_r000406_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  }
  else
  {
    stage_v_119_1 = ((pub_r000406_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
  }
  if ((sec_r000406_6_2 & 63) > 44)
  {
    stage_v_119_2 = ((pub_r000406_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  }
  else
  {
    stage_v_119_2 = ((pub_r000406_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_52_1 & 63) > 60)
  {
    stage_v_120_1 = ((pub_r000406_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  }
  else
  {
    stage_v_120_1 = ((pub_r000406_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
  }
  if ((stage_v_52_2 & 63) > 60)
  {
    stage_v_120_2 = ((pub_r000406_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  }
  else
  {
    stage_v_120_2 = ((pub_r000406_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_89_1 & 63) > 41)
  {
    stage_v_121_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  }
  else
  {
    stage_v_121_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
  }
  if ((stage_v_89_2 & 63) > 41)
  {
    stage_v_121_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  }
  else
  {
    stage_v_121_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_55_1 & 63) > 55)
  {
    stage_v_122_1 = ((pub_r000406_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  }
  else
  {
    stage_v_122_1 = ((pub_r000406_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
  }
  if ((stage_v_55_2 & 63) > 55)
  {
    stage_v_122_2 = ((pub_r000406_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  }
  else
  {
    stage_v_122_2 = ((pub_r000406_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_83_1 & 63) > 52)
  {
    stage_v_123_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  }
  else
  {
    stage_v_123_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
  }
  if ((stage_v_83_2 & 63) > 52)
  {
    stage_v_123_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  }
  else
  {
    stage_v_123_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000406_21_1 & 63) > 25)
  {
    stage_v_124_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  }
  else
  {
    stage_v_124_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
  }
  if ((sec_r000406_21_2 & 63) > 25)
  {
    stage_v_124_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  }
  else
  {
    stage_v_124_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000406_2_1 & 63) > 52)
  {
    stage_v_125_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  }
  else
  {
    stage_v_125_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
  }
  if ((sec_r000406_2_2 & 63) > 52)
  {
    stage_v_125_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  }
  else
  {
    stage_v_125_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000406_14_1 & 63) > 53)
  {
    stage_v_126_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  }
  else
  {
    stage_v_126_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
  }
  if ((sec_r000406_14_2 & 63) > 53)
  {
    stage_v_126_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  }
  else
  {
    stage_v_126_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000406_1_1 & 63) > 47)
  {
    stage_v_127_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  }
  else
  {
    stage_v_127_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
  }
  if ((sec_r000406_1_2 & 63) > 47)
  {
    stage_v_127_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  }
  else
  {
    stage_v_127_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_117_1 & 63) > 58)
  {
    stage_v_128_1 = ((pub_r000406_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  }
  else
  {
    stage_v_128_1 = ((pub_r000406_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
  }
  if ((stage_v_117_2 & 63) > 58)
  {
    stage_v_128_2 = ((pub_r000406_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  }
  else
  {
    stage_v_128_2 = ((pub_r000406_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000406_21_1 & 63) > 42)
  {
    stage_v_129_1 = ((pub_r000406_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  }
  else
  {
    stage_v_129_1 = ((pub_r000406_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
  }
  if ((sec_r000406_21_2 & 63) > 42)
  {
    stage_v_129_2 = ((pub_r000406_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  }
  else
  {
    stage_v_129_2 = ((pub_r000406_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_42_1 & 63) > 41)
  {
    stage_v_130_1 = ((pub_r000406_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  }
  else
  {
    stage_v_130_1 = ((pub_r000406_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
  }
  if ((stage_v_42_2 & 63) > 41)
  {
    stage_v_130_2 = ((pub_r000406_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  }
  else
  {
    stage_v_130_2 = ((pub_r000406_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000406_4_1 & 63) > 48)
  {
    stage_v_131_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  }
  else
  {
    stage_v_131_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
  }
  if ((sec_r000406_4_2 & 63) > 48)
  {
    stage_v_131_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  }
  else
  {
    stage_v_131_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_92_1 & 63) > 33)
  {
    stage_v_132_1 = ((pub_r000406_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  }
  else
  {
    stage_v_132_1 = ((pub_r000406_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
  }
  if ((stage_v_92_2 & 63) > 33)
  {
    stage_v_132_2 = ((pub_r000406_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  }
  else
  {
    stage_v_132_2 = ((pub_r000406_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_62_1 & 63) > 38)
  {
    stage_v_133_1 = ((pub_r000406_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  }
  else
  {
    stage_v_133_1 = ((pub_r000406_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
  }
  if ((stage_v_62_2 & 63) > 38)
  {
    stage_v_133_2 = ((pub_r000406_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  }
  else
  {
    stage_v_133_2 = ((pub_r000406_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_123_1 & 63) > 17)
  {
    stage_v_134_1 = ((pub_r000406_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  }
  else
  {
    stage_v_134_1 = ((pub_r000406_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
  }
  if ((stage_v_123_2 & 63) > 17)
  {
    stage_v_134_2 = ((pub_r000406_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  }
  else
  {
    stage_v_134_2 = ((pub_r000406_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_40_1 & 63) > 59)
  {
    stage_v_135_1 = ((pub_r000406_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  }
  else
  {
    stage_v_135_1 = ((pub_r000406_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
  }
  if ((stage_v_40_2 & 63) > 59)
  {
    stage_v_135_2 = ((pub_r000406_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  }
  else
  {
    stage_v_135_2 = ((pub_r000406_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000406_14_1 & 63) > 18)
  {
    stage_v_136_1 = ((pub_r000406_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  }
  else
  {
    stage_v_136_1 = ((pub_r000406_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
  }
  if ((sec_r000406_14_2 & 63) > 18)
  {
    stage_v_136_2 = ((pub_r000406_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  }
  else
  {
    stage_v_136_2 = ((pub_r000406_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_83_1 & 63) > 40)
  {
    stage_v_137_1 = ((pub_r000406_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  }
  else
  {
    stage_v_137_1 = ((pub_r000406_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
  }
  if ((stage_v_83_2 & 63) > 40)
  {
    stage_v_137_2 = ((pub_r000406_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  }
  else
  {
    stage_v_137_2 = ((pub_r000406_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_30_1 & 63) > 29)
  {
    stage_v_138_1 = ((pub_r000406_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  }
  else
  {
    stage_v_138_1 = ((pub_r000406_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
  }
  if ((stage_v_30_2 & 63) > 29)
  {
    stage_v_138_2 = ((pub_r000406_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  }
  else
  {
    stage_v_138_2 = ((pub_r000406_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000406_21_1 & 63) > 45)
  {
    stage_v_139_1 = ((pub_r000406_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  }
  else
  {
    stage_v_139_1 = ((pub_r000406_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
  }
  if ((sec_r000406_21_2 & 63) > 45)
  {
    stage_v_139_2 = ((pub_r000406_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  }
  else
  {
    stage_v_139_2 = ((pub_r000406_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000406_7_1 & 63) > 27)
  {
    stage_v_140_1 = ((pub_r000406_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  }
  else
  {
    stage_v_140_1 = ((pub_r000406_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
  }
  if ((sec_r000406_7_2 & 63) > 27)
  {
    stage_v_140_2 = ((pub_r000406_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  }
  else
  {
    stage_v_140_2 = ((pub_r000406_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_140_1 & 63) > 16)
  {
    stage_v_141_1 = ((pub_r000406_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  }
  else
  {
    stage_v_141_1 = ((pub_r000406_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
  }
  if ((stage_v_140_2 & 63) > 16)
  {
    stage_v_141_2 = ((pub_r000406_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  }
  else
  {
    stage_v_141_2 = ((pub_r000406_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000406_2_1 & 63) > 27)
  {
    stage_v_142_1 = ((pub_r000406_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  }
  else
  {
    stage_v_142_1 = ((pub_r000406_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
  }
  if ((sec_r000406_2_2 & 63) > 27)
  {
    stage_v_142_2 = ((pub_r000406_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  }
  else
  {
    stage_v_142_2 = ((pub_r000406_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_33_1 & 63) > 52)
  {
    stage_v_143_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  }
  else
  {
    stage_v_143_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
  }
  if ((stage_v_33_2 & 63) > 52)
  {
    stage_v_143_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  }
  else
  {
    stage_v_143_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_42_1 & 63) > 51)
  {
    stage_v_144_1 = ((pub_r000406_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  }
  else
  {
    stage_v_144_1 = ((pub_r000406_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
  }
  if ((stage_v_42_2 & 63) > 51)
  {
    stage_v_144_2 = ((pub_r000406_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  }
  else
  {
    stage_v_144_2 = ((pub_r000406_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_32_1 & 63) > 50)
  {
    stage_v_145_1 = ((pub_r000406_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  }
  else
  {
    stage_v_145_1 = ((pub_r000406_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
  }
  if ((stage_v_32_2 & 63) > 50)
  {
    stage_v_145_2 = ((pub_r000406_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  }
  else
  {
    stage_v_145_2 = ((pub_r000406_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000406_13_1 & 63) > 32)
  {
    stage_v_146_1 = ((pub_r000406_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  }
  else
  {
    stage_v_146_1 = ((pub_r000406_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
  }
  if ((sec_r000406_13_2 & 63) > 32)
  {
    stage_v_146_2 = ((pub_r000406_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  }
  else
  {
    stage_v_146_2 = ((pub_r000406_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_106_1 & 63) > 26)
  {
    stage_v_147_1 = ((pub_r000406_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  }
  else
  {
    stage_v_147_1 = ((pub_r000406_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
  }
  if ((stage_v_106_2 & 63) > 26)
  {
    stage_v_147_2 = ((pub_r000406_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  }
  else
  {
    stage_v_147_2 = ((pub_r000406_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000406_8_1 & 63) > 49)
  {
    stage_v_148_1 = ((pub_r000406_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  }
  else
  {
    stage_v_148_1 = ((pub_r000406_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
  }
  if ((sec_r000406_8_2 & 63) > 49)
  {
    stage_v_148_2 = ((pub_r000406_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  }
  else
  {
    stage_v_148_2 = ((pub_r000406_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_58_1 & 63) > 27)
  {
    stage_v_149_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  }
  else
  {
    stage_v_149_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
  }
  if ((stage_v_58_2 & 63) > 27)
  {
    stage_v_149_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  }
  else
  {
    stage_v_149_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_61_1 & 63) > 28)
  {
    stage_v_150_1 = ((pub_r000406_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  }
  else
  {
    stage_v_150_1 = ((pub_r000406_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
  }
  if ((stage_v_61_2 & 63) > 28)
  {
    stage_v_150_2 = ((pub_r000406_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  }
  else
  {
    stage_v_150_2 = ((pub_r000406_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_137_1 & 63) > 35)
  {
    stage_v_151_1 = ((pub_r000406_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  }
  else
  {
    stage_v_151_1 = ((pub_r000406_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
  }
  if ((stage_v_137_2 & 63) > 35)
  {
    stage_v_151_2 = ((pub_r000406_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  }
  else
  {
    stage_v_151_2 = ((pub_r000406_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_146_1 & 63) > 44)
  {
    stage_v_152_1 = ((pub_r000406_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  }
  else
  {
    stage_v_152_1 = ((pub_r000406_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
  }
  if ((stage_v_146_2 & 63) > 44)
  {
    stage_v_152_2 = ((pub_r000406_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  }
  else
  {
    stage_v_152_2 = ((pub_r000406_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_135_1 & 63) > 59)
  {
    stage_v_153_1 = ((pub_r000406_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  }
  else
  {
    stage_v_153_1 = ((pub_r000406_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
  }
  if ((stage_v_135_2 & 63) > 59)
  {
    stage_v_153_2 = ((pub_r000406_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  }
  else
  {
    stage_v_153_2 = ((pub_r000406_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((sec_r000406_4_1 & 63) > 24)
  {
    stage_v_154_1 = ((pub_r000406_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  }
  else
  {
    stage_v_154_1 = ((pub_r000406_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
  }
  if ((sec_r000406_4_2 & 63) > 24)
  {
    stage_v_154_2 = ((pub_r000406_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  }
  else
  {
    stage_v_154_2 = ((pub_r000406_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_64_1 & 63) > 26)
  {
    stage_v_155_1 = ((pub_r000406_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  }
  else
  {
    stage_v_155_1 = ((pub_r000406_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
  }
  if ((stage_v_64_2 & 63) > 26)
  {
    stage_v_155_2 = ((pub_r000406_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  }
  else
  {
    stage_v_155_2 = ((pub_r000406_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_126_1 & 63) > 28)
  {
    stage_v_156_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  }
  else
  {
    stage_v_156_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
  }
  if ((stage_v_126_2 & 63) > 28)
  {
    stage_v_156_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  }
  else
  {
    stage_v_156_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_116_1 & 63) > 36)
  {
    stage_v_157_1 = ((pub_r000406_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  }
  else
  {
    stage_v_157_1 = ((pub_r000406_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
  }
  if ((stage_v_116_2 & 63) > 36)
  {
    stage_v_157_2 = ((pub_r000406_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  }
  else
  {
    stage_v_157_2 = ((pub_r000406_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((sec_r000406_8_1 & 63) > 20)
  {
    stage_v_158_1 = ((pub_r000406_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  }
  else
  {
    stage_v_158_1 = ((pub_r000406_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
  }
  if ((sec_r000406_8_2 & 63) > 20)
  {
    stage_v_158_2 = ((pub_r000406_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  }
  else
  {
    stage_v_158_2 = ((pub_r000406_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_116_1 & 63) > 60)
  {
    stage_v_159_1 = ((pub_r000406_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  }
  else
  {
    stage_v_159_1 = ((pub_r000406_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
  }
  if ((stage_v_116_2 & 63) > 60)
  {
    stage_v_159_2 = ((pub_r000406_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  }
  else
  {
    stage_v_159_2 = ((pub_r000406_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000406_10_1 & 63) > 23)
  {
    stage_v_160_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  }
  else
  {
    stage_v_160_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
  }
  if ((sec_r000406_10_2 & 63) > 23)
  {
    stage_v_160_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  }
  else
  {
    stage_v_160_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_62_1 & 63) > 51)
  {
    stage_v_161_1 = ((pub_r000406_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  }
  else
  {
    stage_v_161_1 = ((pub_r000406_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
  }
  if ((stage_v_62_2 & 63) > 51)
  {
    stage_v_161_2 = ((pub_r000406_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  }
  else
  {
    stage_v_161_2 = ((pub_r000406_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((sec_r000406_19_1 & 63) > 35)
  {
    stage_v_162_1 = ((pub_r000406_8_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  }
  else
  {
    stage_v_162_1 = ((pub_r000406_8_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
  }
  if ((sec_r000406_19_2 & 63) > 35)
  {
    stage_v_162_2 = ((pub_r000406_8_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  }
  else
  {
    stage_v_162_2 = ((pub_r000406_8_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_113_1 & 63) > 59)
  {
    stage_v_163_1 = ((pub_r000406_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  }
  else
  {
    stage_v_163_1 = ((pub_r000406_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
  }
  if ((stage_v_113_2 & 63) > 59)
  {
    stage_v_163_2 = ((pub_r000406_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  }
  else
  {
    stage_v_163_2 = ((pub_r000406_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((stage_v_157_1 & 63) > 54)
  {
    stage_v_164_1 = ((pub_r000406_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  }
  else
  {
    stage_v_164_1 = ((pub_r000406_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
  }
  if ((stage_v_157_2 & 63) > 54)
  {
    stage_v_164_2 = ((pub_r000406_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  }
  else
  {
    stage_v_164_2 = ((pub_r000406_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((stage_v_107_1 & 63) > 59)
  {
    stage_v_165_1 = ((pub_r000406_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  }
  else
  {
    stage_v_165_1 = ((pub_r000406_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
  }
  if ((stage_v_107_2 & 63) > 59)
  {
    stage_v_165_2 = ((pub_r000406_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  }
  else
  {
    stage_v_165_2 = ((pub_r000406_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((sec_r000406_3_1 & 63) > 51)
  {
    stage_v_166_1 = ((pub_r000406_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  }
  else
  {
    stage_v_166_1 = ((pub_r000406_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
  }
  if ((sec_r000406_3_2 & 63) > 51)
  {
    stage_v_166_2 = ((pub_r000406_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  }
  else
  {
    stage_v_166_2 = ((pub_r000406_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000406_5_1 == pub_r000406_5_2);
  __CPROVER_assume(sec_r000406_14_1 != sec_r000406_14_2);
  __CPROVER_assume(sec_r000406_12_1 != sec_r000406_12_2);
  __CPROVER_assume(sec_r000406_19_1 != sec_r000406_19_2);
  __CPROVER_assume(sec_r000406_22_1 != sec_r000406_22_2);
  __CPROVER_assume(sec_r000406_0_1 != sec_r000406_0_2);
  __CPROVER_assume(sec_r000406_7_1 != sec_r000406_7_2);
  __CPROVER_assume(sec_r000406_6_1 != sec_r000406_6_2);
  __CPROVER_assume(pub_r000406_9_1 == pub_r000406_9_2);
  __CPROVER_assume(pub_r000406_3_1 == pub_r000406_3_2);
  __CPROVER_assume(pub_r000406_18_1 == pub_r000406_18_2);
  __CPROVER_assume(pub_r000406_19_1 == pub_r000406_19_2);
  __CPROVER_assume(sec_r000406_20_1 != sec_r000406_20_2);
  __CPROVER_assume(sec_r000406_1_1 != sec_r000406_1_2);
  __CPROVER_assume(sec_r000406_8_1 != sec_r000406_8_2);
  __CPROVER_assume(sec_r000406_18_1 != sec_r000406_18_2);
  __CPROVER_assume(pub_r000406_2_1 == pub_r000406_2_2);
  __CPROVER_assume(sec_r000406_17_1 != sec_r000406_17_2);
  __CPROVER_assume(pub_r000406_16_1 == pub_r000406_16_2);
  __CPROVER_assume(pub_r000406_13_1 == pub_r000406_13_2);
  __CPROVER_assume(sec_r000406_10_1 != sec_r000406_10_2);
  __CPROVER_assume(sec_r000406_5_1 != sec_r000406_5_2);
  __CPROVER_assume(sec_r000406_13_1 != sec_r000406_13_2);
  __CPROVER_assume(pub_r000406_14_1 == pub_r000406_14_2);
  __CPROVER_assume(sec_r000406_9_1 != sec_r000406_9_2);
  __CPROVER_assume(sec_r000406_15_1 != sec_r000406_15_2);
  __CPROVER_assume(sec_r000406_21_1 != sec_r000406_21_2);
  __CPROVER_assume(pub_r000406_4_1 == pub_r000406_4_2);
  __CPROVER_assume(pub_r000406_11_1 == pub_r000406_11_2);
  __CPROVER_assume(pub_r000406_7_1 == pub_r000406_7_2);
  __CPROVER_assume(sec_r000406_3_1 != sec_r000406_3_2);
  __CPROVER_assume(pub_r000406_6_1 == pub_r000406_6_2);
  __CPROVER_assume(pub_r000406_8_1 == pub_r000406_8_2);
  __CPROVER_assume(pub_r000406_15_1 == pub_r000406_15_2);
  __CPROVER_assume(pub_r000406_0_1 == pub_r000406_0_2);
  __CPROVER_assume(pub_r000406_10_1 == pub_r000406_10_2);
  __CPROVER_assume(sec_r000406_16_1 != sec_r000406_16_2);
  __CPROVER_assume(sec_r000406_4_1 != sec_r000406_4_2);
  __CPROVER_assume(sec_r000406_23_1 != sec_r000406_23_2);
  __CPROVER_assume(sec_r000406_11_1 != sec_r000406_11_2);
  __CPROVER_assume(pub_r000406_12_1 == pub_r000406_12_2);
  __CPROVER_assume(sec_r000406_2_1 != sec_r000406_2_2);
  __CPROVER_assume(pub_r000406_1_1 == pub_r000406_1_2);
  __CPROVER_assume(pub_r000406_17_1 == pub_r000406_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
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
}


