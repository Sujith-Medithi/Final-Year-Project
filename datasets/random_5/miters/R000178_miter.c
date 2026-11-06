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
struct FilterState_R000178_7813_0
{
  short prev_out;
  short mode;
  int prev_in;
  int gain_db;
  int damping;
  short cutoff;
  int buffer[3];
};
struct SensorNode_R000178_7813_1
{
  short status;
  int reading;
  int offset;
  int calib;
  int buffer[3];
};
struct StreamBuffer_R000178_7813_2
{
  short checksum;
  int capacity;
  short tail;
  unsigned char watermark;
  unsigned char head;
  int buffer[3];
};
union ColorPixel_R000178_7813_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000178_7813_1
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
void fn_R000178_7813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st_1 = {0};
  struct FilterState_R000178_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_68_1 = local_arr_1[aux_1 % 3];
  int mask_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_68_2 * 2)) & 127;
  int delta_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_99_1)
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

  switch (delta_99_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_68_1 == mask_68_2);
  assert(delta_99_1 == delta_99_2);
}

int fn_R000178_7813_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int mask_68 = local_arr[aux % 3];
  acc = (acc + (mask_68 * 2)) & 127;
  int delta_99 = (aux + st.buffer[1]) & 3;
  switch (delta_99)
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

void fn_R000178_7813_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st_1 = {0};
  struct SensorNode_R000178_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_43_1 = local_arr_1[aux_1 % 3];
  int metric_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_43_2 * 2)) & 127;
  int accumulator_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_60_1 > 46)
  {
    acc_1 = ((acc_1 + (accumulator_60_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_60_2 > 46)
  {
    acc_2 = ((acc_2 + (accumulator_60_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_43_1 == metric_43_2);
  assert(accumulator_60_1 == accumulator_60_2);
}

int fn_R000178_7813_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int metric_43 = local_arr[aux % 3];
  acc = (acc + (metric_43 * 2)) & 127;
  int accumulator_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_60 > 46)
  {
    acc = ((acc + (accumulator_60 * 2)) + 5) & 127;
    aux ^= accumulator_60 & 15;
  }
  else
  {
    acc = ((acc - accumulator_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000178_7813_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st_1 = {0};
  struct FilterState_R000178_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quantum_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_75_1 > 22)
  {
    acc_1 = ((acc_1 + (quantum_75_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_75_2 > 22)
  {
    acc_2 = ((acc_2 + (quantum_75_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_52_1)
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

  switch (cursor_52_2)
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

  int residue_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_36_1) & 63;
  aux_2 = (aux_2 + residue_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_75_1 == quantum_75_2);
  assert(cursor_52_1 == cursor_52_2);
  assert(residue_36_1 == residue_36_2);
}

int fn_R000178_7813_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quantum_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_75 > 22)
  {
    acc = ((acc + (quantum_75 * 2)) + 5) & 127;
    aux ^= quantum_75 & 15;
  }
  else
  {
    acc = ((acc - quantum_75) + 11) & 127;
    aux += 3;
  }
  int cursor_52 = (aux + st.buffer[1]) & 3;
  switch (cursor_52)
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

  int residue_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_36) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000178_7813_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st_1 = {0};
  struct StreamBuffer_R000178_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_34_1 = local_arr_1[aux_1 % 3];
  int index_reg_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_34_2 * 2)) & 127;
  int residue_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_55_1 > 41)
  {
    acc_1 = ((acc_1 + (residue_55_1 * 2)) + 5) & 127;
    aux_1 ^= residue_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_55_2 > 41)
  {
    acc_2 = ((acc_2 + (residue_55_2 * 2)) + 5) & 127;
    aux_2 ^= residue_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_75_1) & 63;
  aux_2 = (aux_2 + metric_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_89_1)
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

  switch (scale_89_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_34_1 == index_reg_34_2);
  assert(residue_55_1 == residue_55_2);
  assert(metric_75_1 == metric_75_2);
  assert(scale_89_1 == scale_89_2);
}

int fn_R000178_7813_3(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int index_reg_34 = local_arr[aux % 3];
  acc = (acc + (index_reg_34 * 2)) & 127;
  int residue_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_55 > 41)
  {
    acc = ((acc + (residue_55 * 2)) + 5) & 127;
    aux ^= residue_55 & 15;
  }
  else
  {
    acc = ((acc - residue_55) + 11) & 127;
    aux += 3;
  }
  int metric_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_75) & 63;
  acc ^= aux;
  int scale_89 = (aux + st.buffer[1]) & 3;
  switch (scale_89)
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

void fn_R000178_7813_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st_1 = {0};
  struct StreamBuffer_R000178_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_48_1) & 63;
  aux_2 = (aux_2 + scale_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_92_1)
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

  switch (window_92_2)
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
  int residue_38_1 = local_arr_1[aux_1 % 3];
  int residue_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_38_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_48_1 == scale_48_2);
  assert(window_92_1 == window_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_38_1 == residue_38_2);
}

int fn_R000178_7813_4(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_48) & 63;
  acc ^= aux;
  int window_92 = (aux + st.buffer[1]) & 3;
  switch (window_92)
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
  int residue_38 = local_arr[aux % 3];
  acc = (acc + (residue_38 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000178_7813_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st_1 = {0};
  struct SensorNode_R000178_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_79_1 = local_arr_1[aux_1 % 3];
  int bound_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_79_2 * 2)) & 127;
  int mask_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_32_1 > 48)
  {
    acc_1 = ((acc_1 + (mask_32_1 * 2)) + 5) & 127;
    aux_1 ^= mask_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_32_2 > 48)
  {
    acc_2 = ((acc_2 + (mask_32_2 * 2)) + 5) & 127;
    aux_2 ^= mask_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_79_1 == bound_79_2);
  assert(mask_32_1 == mask_32_2);
}

int fn_R000178_7813_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int bound_79 = local_arr[aux % 3];
  acc = (acc + (bound_79 * 2)) & 127;
  int mask_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_32 > 48)
  {
    acc = ((acc + (mask_32 * 2)) + 5) & 127;
    aux ^= mask_32 & 15;
  }
  else
  {
    acc = ((acc - mask_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000178_7813_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st_1 = {0};
  struct FilterState_R000178_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int segment_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_90_1)
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

  switch (segment_90_2)
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

  int margin_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_23_1) & 63;
  aux_2 = (aux_2 + margin_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_90_1 == segment_90_2);
  assert(margin_23_1 == margin_23_2);
}

int fn_R000178_7813_6(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int segment_90 = (aux + st.buffer[1]) & 3;
  switch (segment_90)
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

  int margin_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000178_7813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st_1 = {0};
  struct FilterState_R000178_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int scale_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_68_1)
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

  switch (scale_68_2)
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

  int pivot_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_23_1 > 12)
  {
    acc_1 = ((acc_1 + (pivot_23_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_23_2 > 12)
  {
    acc_2 = ((acc_2 + (pivot_23_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_47_1 = local_arr_1[aux_1 % 3];
  int quotient_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_68_1 == scale_68_2);
  assert(pivot_23_1 == pivot_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_47_1 == quotient_47_2);
}

int fn_R000178_7813_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int scale_68 = (aux + st.buffer[1]) & 3;
  switch (scale_68)
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

  int pivot_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_23 > 12)
  {
    acc = ((acc + (pivot_23 * 2)) + 5) & 127;
    aux ^= pivot_23 & 15;
  }
  else
  {
    acc = ((acc - pivot_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_47 = local_arr[aux % 3];
  acc = (acc + (quotient_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000178_7813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st_1 = {0};
  struct SensorNode_R000178_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int damping_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_20_1 > 11)
  {
    acc_1 = ((acc_1 + (damping_20_1 * 2)) + 5) & 127;
    aux_1 ^= damping_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_20_2 > 11)
  {
    acc_2 = ((acc_2 + (damping_20_2 * 2)) + 5) & 127;
    aux_2 ^= damping_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_20_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_46_1 = local_arr_1[aux_1 % 3];
  int quantum_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_20_1 == damping_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_46_1 == quantum_46_2);
}

int fn_R000178_7813_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int damping_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_20 > 11)
  {
    acc = ((acc + (damping_20 * 2)) + 5) & 127;
    aux ^= damping_20 & 15;
  }
  else
  {
    acc = ((acc - damping_20) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quantum_46 = local_arr[aux % 3];
  acc = (acc + (quantum_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000178_7813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st_1 = {0};
  struct FilterState_R000178_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_28_1 = local_arr_1[aux_1 % 3];
  int segment_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_28_2 * 2)) & 127;
  int weight_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_89_1 > 28)
  {
    acc_1 = ((acc_1 + (weight_89_1 * 2)) + 5) & 127;
    aux_1 ^= weight_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_89_2 > 28)
  {
    acc_2 = ((acc_2 + (weight_89_2 * 2)) + 5) & 127;
    aux_2 ^= weight_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_28_1 == segment_28_2);
  assert(weight_89_1 == weight_89_2);
}

int fn_R000178_7813_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int segment_28 = local_arr[aux % 3];
  acc = (acc + (segment_28 * 2)) & 127;
  int weight_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_89 > 28)
  {
    acc = ((acc + (weight_89 * 2)) + 5) & 127;
    aux ^= weight_89 & 15;
  }
  else
  {
    acc = ((acc - weight_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000178_7813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st_1 = {0};
  struct StreamBuffer_R000178_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_85_1) & 63;
  aux_2 = (aux_2 + factor_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_81_1 = local_arr_1[aux_1 % 3];
  int anchor_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_85_1 == factor_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_81_1 == anchor_81_2);
}

int fn_R000178_7813_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_85) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_81 = local_arr[aux % 3];
  acc = (acc + (anchor_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000178_7813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st_1 = {0};
  struct SensorNode_R000178_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_57_1)
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

  switch (damping_57_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_57_1 == damping_57_2);
}

int fn_R000178_7813_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_57 = (aux + st.buffer[1]) & 3;
  switch (damping_57)
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

void fn_R000178_7813_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st_1 = {0};
  struct StreamBuffer_R000178_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int phase_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_66_1) & 63;
  aux_2 = (aux_2 + phase_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_54_1 = local_arr_1[aux_1 % 3];
  int threshold_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_66_1 == phase_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_54_1 == threshold_54_2);
}

int fn_R000178_7813_12(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int phase_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_66) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_54 = local_arr[aux % 3];
  acc = (acc + (threshold_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000178_7813_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st_1 = {0};
  struct SensorNode_R000178_7813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int segment_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_96_1) & 63;
  aux_2 = (aux_2 + segment_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_74_1 > 50)
  {
    acc_1 = ((acc_1 + (quantum_74_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_74_2 > 50)
  {
    acc_2 = ((acc_2 + (quantum_74_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_96_1 == segment_96_2);
  assert(quantum_74_1 == quantum_74_2);
}

int fn_R000178_7813_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000178_7813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int segment_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_96) & 63;
  acc ^= aux;
  int quantum_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_74 > 50)
  {
    acc = ((acc + (quantum_74 * 2)) + 5) & 127;
    aux ^= quantum_74 & 15;
  }
  else
  {
    acc = ((acc - quantum_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000178_7813_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st_1 = {0};
  struct FilterState_R000178_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_44_1 = local_arr_1[aux_1 % 3];
  int residue_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_44_2 * 2)) & 127;
  int index_reg_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_44_1) & 63;
  aux_2 = (aux_2 + index_reg_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_49_1 > 33)
  {
    acc_1 = ((acc_1 + (cursor_49_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_49_2 > 33)
  {
    acc_2 = ((acc_2 + (cursor_49_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_49_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_44_1 == residue_44_2);
  assert(index_reg_44_1 == index_reg_44_2);
  assert(cursor_49_1 == cursor_49_2);
}

int fn_R000178_7813_14(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int residue_44 = local_arr[aux % 3];
  acc = (acc + (residue_44 * 2)) & 127;
  int index_reg_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_44) & 63;
  acc ^= aux;
  int cursor_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_49 > 33)
  {
    acc = ((acc + (cursor_49 * 2)) + 5) & 127;
    aux ^= cursor_49 & 15;
  }
  else
  {
    acc = ((acc - cursor_49) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000178_7813_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st_1 = {0};
  struct FilterState_R000178_7813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int window_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_61_1) & 63;
  aux_2 = (aux_2 + window_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_91_1 = local_arr_1[aux_1 % 3];
  int margin_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_91_2 * 2)) & 127;
  int sample_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_60_1 > 33)
  {
    acc_1 = ((acc_1 + (sample_60_1 * 2)) + 5) & 127;
    aux_1 ^= sample_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_60_2 > 33)
  {
    acc_2 = ((acc_2 + (sample_60_2 * 2)) + 5) & 127;
    aux_2 ^= sample_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_61_1 == window_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_91_1 == margin_91_2);
  assert(sample_60_1 == sample_60_2);
}

int fn_R000178_7813_15(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000178_7813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int window_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_61) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_91 = local_arr[aux % 3];
  acc = (acc + (margin_91 * 2)) & 127;
  int sample_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_60 > 33)
  {
    acc = ((acc + (sample_60 * 2)) + 5) & 127;
    aux ^= sample_60 & 15;
  }
  else
  {
    acc = ((acc - sample_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000178_7813_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st_1 = {0};
  struct StreamBuffer_R000178_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int damping_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_22_1)
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

  switch (damping_22_2)
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
  int margin_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_18_1 > 24)
  {
    acc_1 = ((acc_1 + (margin_18_1 * 2)) + 5) & 127;
    aux_1 ^= margin_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_18_2 > 24)
  {
    acc_2 = ((acc_2 + (margin_18_2 * 2)) + 5) & 127;
    aux_2 ^= margin_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_22_1 == damping_22_2);
  assert(margin_18_1 == margin_18_2);
}

int fn_R000178_7813_16(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int damping_22 = (aux + st.buffer[1]) & 3;
  switch (damping_22)
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
  int margin_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_18 > 24)
  {
    acc = ((acc + (margin_18 * 2)) + 5) & 127;
    aux ^= margin_18 & 15;
  }
  else
  {
    acc = ((acc - margin_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000178_7813_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st_1 = {0};
  struct StreamBuffer_R000178_7813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int factor_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_49_1 > 36)
  {
    acc_1 = ((acc_1 + (factor_49_1 * 2)) + 5) & 127;
    aux_1 ^= factor_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_49_2 > 36)
  {
    acc_2 = ((acc_2 + (factor_49_2 * 2)) + 5) & 127;
    aux_2 ^= factor_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_31_1)
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

  switch (damping_31_2)
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

  int stride_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_29_1) & 63;
  aux_2 = (aux_2 + stride_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_68_1 = local_arr_1[aux_1 % 3];
  int offset_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_49_1 == factor_49_2);
  assert(damping_31_1 == damping_31_2);
  assert(stride_29_1 == stride_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_68_1 == offset_68_2);
}

int fn_R000178_7813_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000178_7813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int factor_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_49 > 36)
  {
    acc = ((acc + (factor_49 * 2)) + 5) & 127;
    aux ^= factor_49 & 15;
  }
  else
  {
    acc = ((acc - factor_49) + 11) & 127;
    aux += 3;
  }
  int damping_31 = (aux + st.buffer[1]) & 3;
  switch (damping_31)
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

  int stride_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_29) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_68 = local_arr[aux % 3];
  acc = (acc + (offset_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000178_0_1;
  int sec_r000178_0_2;
  int sec_r000178_1_1;
  int sec_r000178_1_2;
  int sec_r000178_2_1;
  int sec_r000178_2_2;
  int sec_r000178_3_1;
  int sec_r000178_3_2;
  int sec_r000178_4_1;
  int sec_r000178_4_2;
  int sec_r000178_5_1;
  int sec_r000178_5_2;
  int sec_r000178_6_1;
  int sec_r000178_6_2;
  int sec_r000178_7_1;
  int sec_r000178_7_2;
  int sec_r000178_8_1;
  int sec_r000178_8_2;
  int sec_r000178_9_1;
  int sec_r000178_9_2;
  int sec_r000178_10_1;
  int sec_r000178_10_2;
  int sec_r000178_11_1;
  int sec_r000178_11_2;
  int sec_r000178_12_1;
  int sec_r000178_12_2;
  int sec_r000178_13_1;
  int sec_r000178_13_2;
  int sec_r000178_14_1;
  int sec_r000178_14_2;
  int sec_r000178_15_1;
  int sec_r000178_15_2;
  int sec_r000178_16_1;
  int sec_r000178_16_2;
  int sec_r000178_17_1;
  int sec_r000178_17_2;
  int sec_r000178_18_1;
  int sec_r000178_18_2;
  int sec_r000178_19_1;
  int sec_r000178_19_2;
  int sec_r000178_20_1;
  int sec_r000178_20_2;
  int sec_r000178_21_1;
  int sec_r000178_21_2;
  int pub_r000178_0_1;
  int pub_r000178_0_2;
  int pub_r000178_1_1;
  int pub_r000178_1_2;
  int pub_r000178_2_1;
  int pub_r000178_2_2;
  int pub_r000178_3_1;
  int pub_r000178_3_2;
  int pub_r000178_4_1;
  int pub_r000178_4_2;
  int pub_r000178_5_1;
  int pub_r000178_5_2;
  int pub_r000178_6_1;
  int pub_r000178_6_2;
  int pub_r000178_7_1;
  int pub_r000178_7_2;
  int pub_r000178_8_1;
  int pub_r000178_8_2;
  int pub_r000178_9_1;
  int pub_r000178_9_2;
  int pub_r000178_10_1;
  int pub_r000178_10_2;
  int pub_r000178_11_1;
  int pub_r000178_11_2;
  int pub_r000178_12_1;
  int pub_r000178_12_2;
  int pub_r000178_13_1;
  int pub_r000178_13_2;
  int pub_r000178_14_1;
  int pub_r000178_14_2;
  int pub_r000178_15_1;
  int pub_r000178_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000178_0_1 >= (-100)) && (pub_r000178_0_1 <= 100));
  __CPROVER_assume((pub_r000178_0_2 >= (-100)) && (pub_r000178_0_2 <= 100));
  __CPROVER_assume((pub_r000178_1_1 >= (-100)) && (pub_r000178_1_1 <= 100));
  __CPROVER_assume((pub_r000178_1_2 >= (-100)) && (pub_r000178_1_2 <= 100));
  __CPROVER_assume((pub_r000178_2_1 >= (-100)) && (pub_r000178_2_1 <= 100));
  __CPROVER_assume((pub_r000178_2_2 >= (-100)) && (pub_r000178_2_2 <= 100));
  __CPROVER_assume((pub_r000178_3_1 >= (-100)) && (pub_r000178_3_1 <= 100));
  __CPROVER_assume((pub_r000178_3_2 >= (-100)) && (pub_r000178_3_2 <= 100));
  __CPROVER_assume((pub_r000178_4_1 >= (-100)) && (pub_r000178_4_1 <= 100));
  __CPROVER_assume((pub_r000178_4_2 >= (-100)) && (pub_r000178_4_2 <= 100));
  __CPROVER_assume((pub_r000178_5_1 >= (-100)) && (pub_r000178_5_1 <= 100));
  __CPROVER_assume((pub_r000178_5_2 >= (-100)) && (pub_r000178_5_2 <= 100));
  __CPROVER_assume((pub_r000178_6_1 >= (-100)) && (pub_r000178_6_1 <= 100));
  __CPROVER_assume((pub_r000178_6_2 >= (-100)) && (pub_r000178_6_2 <= 100));
  __CPROVER_assume((pub_r000178_7_1 >= (-100)) && (pub_r000178_7_1 <= 100));
  __CPROVER_assume((pub_r000178_7_2 >= (-100)) && (pub_r000178_7_2 <= 100));
  __CPROVER_assume((pub_r000178_8_1 >= (-100)) && (pub_r000178_8_1 <= 100));
  __CPROVER_assume((pub_r000178_8_2 >= (-100)) && (pub_r000178_8_2 <= 100));
  __CPROVER_assume((pub_r000178_9_1 >= (-100)) && (pub_r000178_9_1 <= 100));
  __CPROVER_assume((pub_r000178_9_2 >= (-100)) && (pub_r000178_9_2 <= 100));
  __CPROVER_assume((pub_r000178_10_1 >= (-100)) && (pub_r000178_10_1 <= 100));
  __CPROVER_assume((pub_r000178_10_2 >= (-100)) && (pub_r000178_10_2 <= 100));
  __CPROVER_assume((pub_r000178_11_1 >= (-100)) && (pub_r000178_11_1 <= 100));
  __CPROVER_assume((pub_r000178_11_2 >= (-100)) && (pub_r000178_11_2 <= 100));
  __CPROVER_assume((pub_r000178_12_1 >= (-100)) && (pub_r000178_12_1 <= 100));
  __CPROVER_assume((pub_r000178_12_2 >= (-100)) && (pub_r000178_12_2 <= 100));
  __CPROVER_assume((pub_r000178_13_1 >= (-100)) && (pub_r000178_13_1 <= 100));
  __CPROVER_assume((pub_r000178_13_2 >= (-100)) && (pub_r000178_13_2 <= 100));
  __CPROVER_assume((pub_r000178_14_1 >= (-100)) && (pub_r000178_14_1 <= 100));
  __CPROVER_assume((pub_r000178_14_2 >= (-100)) && (pub_r000178_14_2 <= 100));
  __CPROVER_assume((pub_r000178_15_1 >= (-100)) && (pub_r000178_15_1 <= 100));
  __CPROVER_assume((pub_r000178_15_2 >= (-100)) && (pub_r000178_15_2 <= 100));
  __CPROVER_assume((sec_r000178_0_1 >= 0) && (sec_r000178_0_1 <= 255));
  __CPROVER_assume((sec_r000178_0_2 >= 0) && (sec_r000178_0_2 <= 255));
  __CPROVER_assume((sec_r000178_1_1 >= 0) && (sec_r000178_1_1 <= 255));
  __CPROVER_assume((sec_r000178_1_2 >= 0) && (sec_r000178_1_2 <= 255));
  __CPROVER_assume((sec_r000178_2_1 >= 0) && (sec_r000178_2_1 <= 255));
  __CPROVER_assume((sec_r000178_2_2 >= 0) && (sec_r000178_2_2 <= 255));
  __CPROVER_assume((sec_r000178_3_1 >= 0) && (sec_r000178_3_1 <= 255));
  __CPROVER_assume((sec_r000178_3_2 >= 0) && (sec_r000178_3_2 <= 255));
  __CPROVER_assume((sec_r000178_4_1 >= 0) && (sec_r000178_4_1 <= 255));
  __CPROVER_assume((sec_r000178_4_2 >= 0) && (sec_r000178_4_2 <= 255));
  __CPROVER_assume((sec_r000178_5_1 >= 0) && (sec_r000178_5_1 <= 255));
  __CPROVER_assume((sec_r000178_5_2 >= 0) && (sec_r000178_5_2 <= 255));
  __CPROVER_assume((sec_r000178_6_1 >= 0) && (sec_r000178_6_1 <= 255));
  __CPROVER_assume((sec_r000178_6_2 >= 0) && (sec_r000178_6_2 <= 255));
  __CPROVER_assume((sec_r000178_7_1 >= 0) && (sec_r000178_7_1 <= 255));
  __CPROVER_assume((sec_r000178_7_2 >= 0) && (sec_r000178_7_2 <= 255));
  __CPROVER_assume((sec_r000178_8_1 >= 0) && (sec_r000178_8_1 <= 255));
  __CPROVER_assume((sec_r000178_8_2 >= 0) && (sec_r000178_8_2 <= 255));
  __CPROVER_assume((sec_r000178_9_1 >= 0) && (sec_r000178_9_1 <= 255));
  __CPROVER_assume((sec_r000178_9_2 >= 0) && (sec_r000178_9_2 <= 255));
  __CPROVER_assume((sec_r000178_10_1 >= 0) && (sec_r000178_10_1 <= 255));
  __CPROVER_assume((sec_r000178_10_2 >= 0) && (sec_r000178_10_2 <= 255));
  __CPROVER_assume((sec_r000178_11_1 >= 0) && (sec_r000178_11_1 <= 255));
  __CPROVER_assume((sec_r000178_11_2 >= 0) && (sec_r000178_11_2 <= 255));
  __CPROVER_assume((sec_r000178_12_1 >= 0) && (sec_r000178_12_1 <= 255));
  __CPROVER_assume((sec_r000178_12_2 >= 0) && (sec_r000178_12_2 <= 255));
  __CPROVER_assume((sec_r000178_13_1 >= 0) && (sec_r000178_13_1 <= 255));
  __CPROVER_assume((sec_r000178_13_2 >= 0) && (sec_r000178_13_2 <= 255));
  __CPROVER_assume((sec_r000178_14_1 >= 0) && (sec_r000178_14_1 <= 255));
  __CPROVER_assume((sec_r000178_14_2 >= 0) && (sec_r000178_14_2 <= 255));
  __CPROVER_assume((sec_r000178_15_1 >= 0) && (sec_r000178_15_1 <= 255));
  __CPROVER_assume((sec_r000178_15_2 >= 0) && (sec_r000178_15_2 <= 255));
  __CPROVER_assume((sec_r000178_16_1 >= 0) && (sec_r000178_16_1 <= 255));
  __CPROVER_assume((sec_r000178_16_2 >= 0) && (sec_r000178_16_2 <= 255));
  __CPROVER_assume((sec_r000178_17_1 >= 0) && (sec_r000178_17_1 <= 255));
  __CPROVER_assume((sec_r000178_17_2 >= 0) && (sec_r000178_17_2 <= 255));
  __CPROVER_assume((sec_r000178_18_1 >= 0) && (sec_r000178_18_1 <= 255));
  __CPROVER_assume((sec_r000178_18_2 >= 0) && (sec_r000178_18_2 <= 255));
  __CPROVER_assume((sec_r000178_19_1 >= 0) && (sec_r000178_19_1 <= 255));
  __CPROVER_assume((sec_r000178_19_2 >= 0) && (sec_r000178_19_2 <= 255));
  __CPROVER_assume((sec_r000178_20_1 >= 0) && (sec_r000178_20_1 <= 255));
  __CPROVER_assume((sec_r000178_20_2 >= 0) && (sec_r000178_20_2 <= 255));
  __CPROVER_assume((sec_r000178_21_1 >= 0) && (sec_r000178_21_1 <= 255));
  __CPROVER_assume((sec_r000178_21_2 >= 0) && (sec_r000178_21_2 <= 255));
  struct FilterState_R000178_7813_0 st_var_0_1 = {0};
  struct FilterState_R000178_7813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000178_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000178_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000178_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000178_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000178_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000178_0_2 + 7) & 15;
  struct SensorNode_R000178_7813_1 st_var_1_1 = {0};
  struct SensorNode_R000178_7813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000178_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000178_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000178_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000178_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000178_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000178_0_2 + 9) & 15;
  struct StreamBuffer_R000178_7813_2 st_var_2_1 = {0};
  struct StreamBuffer_R000178_7813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000178_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000178_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000178_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000178_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000178_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000178_0_2 + 11) & 15;
  union ColorPixel_R000178_7813_0 u_var_1;
  union ColorPixel_R000178_7813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = ((st_var_0_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_0_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 26)
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
  if (stage_v_3_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 26)
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
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((st_var_0_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_0_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 31)
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
  if (stage_v_9_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 31)
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
  int stage_v_11_1 = (st_var_2_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_2_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 26)
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
  if (stage_v_14_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 26)
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
  int stage_v_15_1 = ((st_var_0_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_0_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 44)
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
  if (stage_v_15_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 44)
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
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
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
  int stage_v_22_1 = ((st_var_1_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_1_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 25)
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
  if (stage_v_22_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 25)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 45)
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
  if (stage_v_25_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 45)
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
  int stage_v_26_1 = (st_var_2_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_2_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 28) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 29) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
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
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 34) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = ((st_var_1_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_1_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 27)
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
  if (stage_v_34_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 27)
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
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_15_1 & 1) == step_1)
    {
      stage_v_41_1 = ((stage_v_41_1 + (step_1 * 4)) + pub_r000178_15_1) & 63;
    }
    else
    {
      stage_v_41_1 = ((stage_v_41_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((sec_r000178_15_2 & 1) == step_2)
    {
      stage_v_41_2 = ((stage_v_41_2 + (step_2 * 4)) + pub_r000178_15_2) & 63;
    }
    else
    {
      stage_v_41_2 = ((stage_v_41_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_16_1 & 1) == step_1)
    {
      stage_v_42_1 = ((stage_v_42_1 + (step_1 * 4)) + pub_r000178_11_1) & 63;
    }
    else
    {
      stage_v_42_1 = ((stage_v_42_1 + pub_r000178_7_1) + 5) & 63;
    }
    if ((sec_r000178_16_2 & 1) == step_2)
    {
      stage_v_42_2 = ((stage_v_42_2 + (step_2 * 4)) + pub_r000178_11_2) & 63;
    }
    else
    {
      stage_v_42_2 = ((stage_v_42_2 + pub_r000178_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_10_1 & 1) == step_1)
    {
      stage_v_43_1 = ((stage_v_43_1 + (step_1 * 4)) + pub_r000178_4_1) & 63;
    }
    else
    {
      stage_v_43_1 = ((stage_v_43_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((sec_r000178_10_2 & 1) == step_2)
    {
      stage_v_43_2 = ((stage_v_43_2 + (step_2 * 4)) + pub_r000178_4_2) & 63;
    }
    else
    {
      stage_v_43_2 = ((stage_v_43_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_42_1 & 1) == step_1)
    {
      stage_v_44_1 = ((stage_v_44_1 + (step_1 * 4)) + pub_r000178_1_1) & 63;
    }
    else
    {
      stage_v_44_1 = ((stage_v_44_1 + pub_r000178_9_1) + 5) & 63;
    }
    if ((stage_v_42_2 & 1) == step_2)
    {
      stage_v_44_2 = ((stage_v_44_2 + (step_2 * 4)) + pub_r000178_1_2) & 63;
    }
    else
    {
      stage_v_44_2 = ((stage_v_44_2 + pub_r000178_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_42_1 & 1) == step_1)
    {
      stage_v_45_1 = ((stage_v_45_1 + (step_1 * 4)) + pub_r000178_4_1) & 63;
    }
    else
    {
      stage_v_45_1 = ((stage_v_45_1 + pub_r000178_13_1) + 5) & 63;
    }
    if ((stage_v_42_2 & 1) == step_2)
    {
      stage_v_45_2 = ((stage_v_45_2 + (step_2 * 4)) + pub_r000178_4_2) & 63;
    }
    else
    {
      stage_v_45_2 = ((stage_v_45_2 + pub_r000178_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_16_1 & 1) == step_1)
    {
      stage_v_46_1 = ((stage_v_46_1 + (step_1 * 4)) + pub_r000178_11_1) & 63;
    }
    else
    {
      stage_v_46_1 = ((stage_v_46_1 + pub_r000178_0_1) + 5) & 63;
    }
    if ((sec_r000178_16_2 & 1) == step_2)
    {
      stage_v_46_2 = ((stage_v_46_2 + (step_2 * 4)) + pub_r000178_11_2) & 63;
    }
    else
    {
      stage_v_46_2 = ((stage_v_46_2 + pub_r000178_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_44_1 & 1) == step_1)
    {
      stage_v_47_1 = ((stage_v_47_1 + (step_1 * 4)) + pub_r000178_3_1) & 63;
    }
    else
    {
      stage_v_47_1 = ((stage_v_47_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((stage_v_44_2 & 1) == step_2)
    {
      stage_v_47_2 = ((stage_v_47_2 + (step_2 * 4)) + pub_r000178_3_2) & 63;
    }
    else
    {
      stage_v_47_2 = ((stage_v_47_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_42_1 & 1) == step_1)
    {
      stage_v_48_1 = ((stage_v_48_1 + (step_1 * 4)) + pub_r000178_9_1) & 63;
    }
    else
    {
      stage_v_48_1 = ((stage_v_48_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_42_2 & 1) == step_2)
    {
      stage_v_48_2 = ((stage_v_48_2 + (step_2 * 4)) + pub_r000178_9_2) & 63;
    }
    else
    {
      stage_v_48_2 = ((stage_v_48_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_46_1 & 1) == step_1)
    {
      stage_v_49_1 = ((stage_v_49_1 + (step_1 * 4)) + pub_r000178_7_1) & 63;
    }
    else
    {
      stage_v_49_1 = ((stage_v_49_1 + pub_r000178_5_1) + 5) & 63;
    }
    if ((stage_v_46_2 & 1) == step_2)
    {
      stage_v_49_2 = ((stage_v_49_2 + (step_2 * 4)) + pub_r000178_7_2) & 63;
    }
    else
    {
      stage_v_49_2 = ((stage_v_49_2 + pub_r000178_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_21_1 & 1) == step_1)
    {
      stage_v_50_1 = ((stage_v_50_1 + (step_1 * 4)) + pub_r000178_1_1) & 63;
    }
    else
    {
      stage_v_50_1 = ((stage_v_50_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((sec_r000178_21_2 & 1) == step_2)
    {
      stage_v_50_2 = ((stage_v_50_2 + (step_2 * 4)) + pub_r000178_1_2) & 63;
    }
    else
    {
      stage_v_50_2 = ((stage_v_50_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_44_1 & 1) == step_1)
    {
      stage_v_51_1 = ((stage_v_51_1 + (step_1 * 4)) + pub_r000178_9_1) & 63;
    }
    else
    {
      stage_v_51_1 = ((stage_v_51_1 + pub_r000178_4_1) + 5) & 63;
    }
    if ((stage_v_44_2 & 1) == step_2)
    {
      stage_v_51_2 = ((stage_v_51_2 + (step_2 * 4)) + pub_r000178_9_2) & 63;
    }
    else
    {
      stage_v_51_2 = ((stage_v_51_2 + pub_r000178_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_45_1 & 1) == step_1)
    {
      stage_v_52_1 = ((stage_v_52_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_52_1 = ((stage_v_52_1 + pub_r000178_15_1) + 5) & 63;
    }
    if ((stage_v_45_2 & 1) == step_2)
    {
      stage_v_52_2 = ((stage_v_52_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_52_2 = ((stage_v_52_2 + pub_r000178_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_47_1 & 1) == step_1)
    {
      stage_v_53_1 = ((stage_v_53_1 + (step_1 * 4)) + pub_r000178_1_1) & 63;
    }
    else
    {
      stage_v_53_1 = ((stage_v_53_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_47_2 & 1) == step_2)
    {
      stage_v_53_2 = ((stage_v_53_2 + (step_2 * 4)) + pub_r000178_1_2) & 63;
    }
    else
    {
      stage_v_53_2 = ((stage_v_53_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_44_1 & 1) == step_1)
    {
      stage_v_54_1 = ((stage_v_54_1 + (step_1 * 4)) + pub_r000178_13_1) & 63;
    }
    else
    {
      stage_v_54_1 = ((stage_v_54_1 + pub_r000178_4_1) + 5) & 63;
    }
    if ((stage_v_44_2 & 1) == step_2)
    {
      stage_v_54_2 = ((stage_v_54_2 + (step_2 * 4)) + pub_r000178_13_2) & 63;
    }
    else
    {
      stage_v_54_2 = ((stage_v_54_2 + pub_r000178_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_18_1 & 1) == step_1)
    {
      stage_v_55_1 = ((stage_v_55_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_55_1 = ((stage_v_55_1 + pub_r000178_10_1) + 5) & 63;
    }
    if ((sec_r000178_18_2 & 1) == step_2)
    {
      stage_v_55_2 = ((stage_v_55_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_55_2 = ((stage_v_55_2 + pub_r000178_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_43_1 & 1) == step_1)
    {
      stage_v_56_1 = ((stage_v_56_1 + (step_1 * 4)) + pub_r000178_12_1) & 63;
    }
    else
    {
      stage_v_56_1 = ((stage_v_56_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_43_2 & 1) == step_2)
    {
      stage_v_56_2 = ((stage_v_56_2 + (step_2 * 4)) + pub_r000178_12_2) & 63;
    }
    else
    {
      stage_v_56_2 = ((stage_v_56_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_19_1 & 1) == step_1)
    {
      stage_v_57_1 = ((stage_v_57_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_57_1 = ((stage_v_57_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((sec_r000178_19_2 & 1) == step_2)
    {
      stage_v_57_2 = ((stage_v_57_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_57_2 = ((stage_v_57_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_43_1 & 1) == step_1)
    {
      stage_v_58_1 = ((stage_v_58_1 + (step_1 * 4)) + pub_r000178_9_1) & 63;
    }
    else
    {
      stage_v_58_1 = ((stage_v_58_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((stage_v_43_2 & 1) == step_2)
    {
      stage_v_58_2 = ((stage_v_58_2 + (step_2 * 4)) + pub_r000178_9_2) & 63;
    }
    else
    {
      stage_v_58_2 = ((stage_v_58_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_46_1 & 1) == step_1)
    {
      stage_v_59_1 = ((stage_v_59_1 + (step_1 * 4)) + pub_r000178_1_1) & 63;
    }
    else
    {
      stage_v_59_1 = ((stage_v_59_1 + pub_r000178_4_1) + 5) & 63;
    }
    if ((stage_v_46_2 & 1) == step_2)
    {
      stage_v_59_2 = ((stage_v_59_2 + (step_2 * 4)) + pub_r000178_1_2) & 63;
    }
    else
    {
      stage_v_59_2 = ((stage_v_59_2 + pub_r000178_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_44_1 & 1) == step_1)
    {
      stage_v_60_1 = ((stage_v_60_1 + (step_1 * 4)) + pub_r000178_4_1) & 63;
    }
    else
    {
      stage_v_60_1 = ((stage_v_60_1 + pub_r000178_4_1) + 5) & 63;
    }
    if ((stage_v_44_2 & 1) == step_2)
    {
      stage_v_60_2 = ((stage_v_60_2 + (step_2 * 4)) + pub_r000178_4_2) & 63;
    }
    else
    {
      stage_v_60_2 = ((stage_v_60_2 + pub_r000178_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_49_1 & 1) == step_1)
    {
      stage_v_61_1 = ((stage_v_61_1 + (step_1 * 4)) + pub_r000178_2_1) & 63;
    }
    else
    {
      stage_v_61_1 = ((stage_v_61_1 + pub_r000178_1_1) + 5) & 63;
    }
    if ((stage_v_49_2 & 1) == step_2)
    {
      stage_v_61_2 = ((stage_v_61_2 + (step_2 * 4)) + pub_r000178_2_2) & 63;
    }
    else
    {
      stage_v_61_2 = ((stage_v_61_2 + pub_r000178_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_5_1 & 1) == step_1)
    {
      stage_v_62_1 = ((stage_v_62_1 + (step_1 * 4)) + pub_r000178_4_1) & 63;
    }
    else
    {
      stage_v_62_1 = ((stage_v_62_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((sec_r000178_5_2 & 1) == step_2)
    {
      stage_v_62_2 = ((stage_v_62_2 + (step_2 * 4)) + pub_r000178_4_2) & 63;
    }
    else
    {
      stage_v_62_2 = ((stage_v_62_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_44_1 & 1) == step_1)
    {
      stage_v_63_1 = ((stage_v_63_1 + (step_1 * 4)) + pub_r000178_11_1) & 63;
    }
    else
    {
      stage_v_63_1 = ((stage_v_63_1 + pub_r000178_15_1) + 5) & 63;
    }
    if ((stage_v_44_2 & 1) == step_2)
    {
      stage_v_63_2 = ((stage_v_63_2 + (step_2 * 4)) + pub_r000178_11_2) & 63;
    }
    else
    {
      stage_v_63_2 = ((stage_v_63_2 + pub_r000178_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_5_1 & 1) == step_1)
    {
      stage_v_64_1 = ((stage_v_64_1 + (step_1 * 4)) + pub_r000178_11_1) & 63;
    }
    else
    {
      stage_v_64_1 = ((stage_v_64_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((sec_r000178_5_2 & 1) == step_2)
    {
      stage_v_64_2 = ((stage_v_64_2 + (step_2 * 4)) + pub_r000178_11_2) & 63;
    }
    else
    {
      stage_v_64_2 = ((stage_v_64_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_47_1 & 1) == step_1)
    {
      stage_v_65_1 = ((stage_v_65_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_65_1 = ((stage_v_65_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_47_2 & 1) == step_2)
    {
      stage_v_65_2 = ((stage_v_65_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_65_2 = ((stage_v_65_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_11_1 & 1) == step_1)
    {
      stage_v_66_1 = ((stage_v_66_1 + (step_1 * 4)) + pub_r000178_9_1) & 63;
    }
    else
    {
      stage_v_66_1 = ((stage_v_66_1 + pub_r000178_6_1) + 5) & 63;
    }
    if ((sec_r000178_11_2 & 1) == step_2)
    {
      stage_v_66_2 = ((stage_v_66_2 + (step_2 * 4)) + pub_r000178_9_2) & 63;
    }
    else
    {
      stage_v_66_2 = ((stage_v_66_2 + pub_r000178_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_50_1 & 1) == step_1)
    {
      stage_v_67_1 = ((stage_v_67_1 + (step_1 * 4)) + pub_r000178_11_1) & 63;
    }
    else
    {
      stage_v_67_1 = ((stage_v_67_1 + pub_r000178_6_1) + 5) & 63;
    }
    if ((stage_v_50_2 & 1) == step_2)
    {
      stage_v_67_2 = ((stage_v_67_2 + (step_2 * 4)) + pub_r000178_11_2) & 63;
    }
    else
    {
      stage_v_67_2 = ((stage_v_67_2 + pub_r000178_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_21_1 & 1) == step_1)
    {
      stage_v_68_1 = ((stage_v_68_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_68_1 = ((stage_v_68_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((sec_r000178_21_2 & 1) == step_2)
    {
      stage_v_68_2 = ((stage_v_68_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_68_2 = ((stage_v_68_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_60_1 & 1) == step_1)
    {
      stage_v_69_1 = ((stage_v_69_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_69_1 = ((stage_v_69_1 + pub_r000178_1_1) + 5) & 63;
    }
    if ((stage_v_60_2 & 1) == step_2)
    {
      stage_v_69_2 = ((stage_v_69_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_69_2 = ((stage_v_69_2 + pub_r000178_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_65_1 & 1) == step_1)
    {
      stage_v_70_1 = ((stage_v_70_1 + (step_1 * 4)) + pub_r000178_9_1) & 63;
    }
    else
    {
      stage_v_70_1 = ((stage_v_70_1 + pub_r000178_10_1) + 5) & 63;
    }
    if ((stage_v_65_2 & 1) == step_2)
    {
      stage_v_70_2 = ((stage_v_70_2 + (step_2 * 4)) + pub_r000178_9_2) & 63;
    }
    else
    {
      stage_v_70_2 = ((stage_v_70_2 + pub_r000178_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_42_1 & 1) == step_1)
    {
      stage_v_71_1 = ((stage_v_71_1 + (step_1 * 4)) + pub_r000178_15_1) & 63;
    }
    else
    {
      stage_v_71_1 = ((stage_v_71_1 + pub_r000178_4_1) + 5) & 63;
    }
    if ((stage_v_42_2 & 1) == step_2)
    {
      stage_v_71_2 = ((stage_v_71_2 + (step_2 * 4)) + pub_r000178_15_2) & 63;
    }
    else
    {
      stage_v_71_2 = ((stage_v_71_2 + pub_r000178_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_5_1 & 1) == step_1)
    {
      stage_v_72_1 = ((stage_v_72_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_72_1 = ((stage_v_72_1 + pub_r000178_5_1) + 5) & 63;
    }
    if ((sec_r000178_5_2 & 1) == step_2)
    {
      stage_v_72_2 = ((stage_v_72_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_72_2 = ((stage_v_72_2 + pub_r000178_5_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_60_1 & 1) == step_1)
    {
      stage_v_73_1 = ((stage_v_73_1 + (step_1 * 4)) + pub_r000178_7_1) & 63;
    }
    else
    {
      stage_v_73_1 = ((stage_v_73_1 + pub_r000178_10_1) + 5) & 63;
    }
    if ((stage_v_60_2 & 1) == step_2)
    {
      stage_v_73_2 = ((stage_v_73_2 + (step_2 * 4)) + pub_r000178_7_2) & 63;
    }
    else
    {
      stage_v_73_2 = ((stage_v_73_2 + pub_r000178_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_47_1 & 1) == step_1)
    {
      stage_v_74_1 = ((stage_v_74_1 + (step_1 * 4)) + pub_r000178_11_1) & 63;
    }
    else
    {
      stage_v_74_1 = ((stage_v_74_1 + pub_r000178_15_1) + 5) & 63;
    }
    if ((stage_v_47_2 & 1) == step_2)
    {
      stage_v_74_2 = ((stage_v_74_2 + (step_2 * 4)) + pub_r000178_11_2) & 63;
    }
    else
    {
      stage_v_74_2 = ((stage_v_74_2 + pub_r000178_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_0_1 & 1) == step_1)
    {
      stage_v_75_1 = ((stage_v_75_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_75_1 = ((stage_v_75_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((sec_r000178_0_2 & 1) == step_2)
    {
      stage_v_75_2 = ((stage_v_75_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_75_2 = ((stage_v_75_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_7_1 & 1) == step_1)
    {
      stage_v_76_1 = ((stage_v_76_1 + (step_1 * 4)) + pub_r000178_15_1) & 63;
    }
    else
    {
      stage_v_76_1 = ((stage_v_76_1 + pub_r000178_0_1) + 5) & 63;
    }
    if ((sec_r000178_7_2 & 1) == step_2)
    {
      stage_v_76_2 = ((stage_v_76_2 + (step_2 * 4)) + pub_r000178_15_2) & 63;
    }
    else
    {
      stage_v_76_2 = ((stage_v_76_2 + pub_r000178_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_69_1 & 1) == step_1)
    {
      stage_v_77_1 = ((stage_v_77_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_77_1 = ((stage_v_77_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_69_2 & 1) == step_2)
    {
      stage_v_77_2 = ((stage_v_77_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_77_2 = ((stage_v_77_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_65_1 & 1) == step_1)
    {
      stage_v_78_1 = ((stage_v_78_1 + (step_1 * 4)) + pub_r000178_15_1) & 63;
    }
    else
    {
      stage_v_78_1 = ((stage_v_78_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((stage_v_65_2 & 1) == step_2)
    {
      stage_v_78_2 = ((stage_v_78_2 + (step_2 * 4)) + pub_r000178_15_2) & 63;
    }
    else
    {
      stage_v_78_2 = ((stage_v_78_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_41_1 & 1) == step_1)
    {
      stage_v_79_1 = ((stage_v_79_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_79_1 = ((stage_v_79_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((stage_v_41_2 & 1) == step_2)
    {
      stage_v_79_2 = ((stage_v_79_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_79_2 = ((stage_v_79_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_78_1 & 1) == step_1)
    {
      stage_v_80_1 = ((stage_v_80_1 + (step_1 * 4)) + pub_r000178_15_1) & 63;
    }
    else
    {
      stage_v_80_1 = ((stage_v_80_1 + pub_r000178_3_1) + 5) & 63;
    }
    if ((stage_v_78_2 & 1) == step_2)
    {
      stage_v_80_2 = ((stage_v_80_2 + (step_2 * 4)) + pub_r000178_15_2) & 63;
    }
    else
    {
      stage_v_80_2 = ((stage_v_80_2 + pub_r000178_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_3_1 & 1) == step_1)
    {
      stage_v_81_1 = ((stage_v_81_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_81_1 = ((stage_v_81_1 + pub_r000178_9_1) + 5) & 63;
    }
    if ((sec_r000178_3_2 & 1) == step_2)
    {
      stage_v_81_2 = ((stage_v_81_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_81_2 = ((stage_v_81_2 + pub_r000178_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_59_1 & 1) == step_1)
    {
      stage_v_82_1 = ((stage_v_82_1 + (step_1 * 4)) + pub_r000178_14_1) & 63;
    }
    else
    {
      stage_v_82_1 = ((stage_v_82_1 + pub_r000178_9_1) + 5) & 63;
    }
    if ((stage_v_59_2 & 1) == step_2)
    {
      stage_v_82_2 = ((stage_v_82_2 + (step_2 * 4)) + pub_r000178_14_2) & 63;
    }
    else
    {
      stage_v_82_2 = ((stage_v_82_2 + pub_r000178_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_70_1 & 1) == step_1)
    {
      stage_v_83_1 = ((stage_v_83_1 + (step_1 * 4)) + pub_r000178_3_1) & 63;
    }
    else
    {
      stage_v_83_1 = ((stage_v_83_1 + pub_r000178_3_1) + 5) & 63;
    }
    if ((stage_v_70_2 & 1) == step_2)
    {
      stage_v_83_2 = ((stage_v_83_2 + (step_2 * 4)) + pub_r000178_3_2) & 63;
    }
    else
    {
      stage_v_83_2 = ((stage_v_83_2 + pub_r000178_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_51_1 & 1) == step_1)
    {
      stage_v_84_1 = ((stage_v_84_1 + (step_1 * 4)) + pub_r000178_5_1) & 63;
    }
    else
    {
      stage_v_84_1 = ((stage_v_84_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((stage_v_51_2 & 1) == step_2)
    {
      stage_v_84_2 = ((stage_v_84_2 + (step_2 * 4)) + pub_r000178_5_2) & 63;
    }
    else
    {
      stage_v_84_2 = ((stage_v_84_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_42_1 & 1) == step_1)
    {
      stage_v_85_1 = ((stage_v_85_1 + (step_1 * 4)) + pub_r000178_10_1) & 63;
    }
    else
    {
      stage_v_85_1 = ((stage_v_85_1 + pub_r000178_13_1) + 5) & 63;
    }
    if ((stage_v_42_2 & 1) == step_2)
    {
      stage_v_85_2 = ((stage_v_85_2 + (step_2 * 4)) + pub_r000178_10_2) & 63;
    }
    else
    {
      stage_v_85_2 = ((stage_v_85_2 + pub_r000178_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_4_1 & 1) == step_1)
    {
      stage_v_86_1 = ((stage_v_86_1 + (step_1 * 4)) + pub_r000178_2_1) & 63;
    }
    else
    {
      stage_v_86_1 = ((stage_v_86_1 + pub_r000178_6_1) + 5) & 63;
    }
    if ((sec_r000178_4_2 & 1) == step_2)
    {
      stage_v_86_2 = ((stage_v_86_2 + (step_2 * 4)) + pub_r000178_2_2) & 63;
    }
    else
    {
      stage_v_86_2 = ((stage_v_86_2 + pub_r000178_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_14_1 & 1) == step_1)
    {
      stage_v_87_1 = ((stage_v_87_1 + (step_1 * 4)) + pub_r000178_15_1) & 63;
    }
    else
    {
      stage_v_87_1 = ((stage_v_87_1 + pub_r000178_6_1) + 5) & 63;
    }
    if ((sec_r000178_14_2 & 1) == step_2)
    {
      stage_v_87_2 = ((stage_v_87_2 + (step_2 * 4)) + pub_r000178_15_2) & 63;
    }
    else
    {
      stage_v_87_2 = ((stage_v_87_2 + pub_r000178_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_48_1 & 1) == step_1)
    {
      stage_v_88_1 = ((stage_v_88_1 + (step_1 * 4)) + pub_r000178_4_1) & 63;
    }
    else
    {
      stage_v_88_1 = ((stage_v_88_1 + pub_r000178_13_1) + 5) & 63;
    }
    if ((stage_v_48_2 & 1) == step_2)
    {
      stage_v_88_2 = ((stage_v_88_2 + (step_2 * 4)) + pub_r000178_4_2) & 63;
    }
    else
    {
      stage_v_88_2 = ((stage_v_88_2 + pub_r000178_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_42_1 & 1) == step_1)
    {
      stage_v_89_1 = ((stage_v_89_1 + (step_1 * 4)) + pub_r000178_12_1) & 63;
    }
    else
    {
      stage_v_89_1 = ((stage_v_89_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_42_2 & 1) == step_2)
    {
      stage_v_89_2 = ((stage_v_89_2 + (step_2 * 4)) + pub_r000178_12_2) & 63;
    }
    else
    {
      stage_v_89_2 = ((stage_v_89_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_21_1 & 1) == step_1)
    {
      stage_v_90_1 = ((stage_v_90_1 + (step_1 * 4)) + pub_r000178_12_1) & 63;
    }
    else
    {
      stage_v_90_1 = ((stage_v_90_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((sec_r000178_21_2 & 1) == step_2)
    {
      stage_v_90_2 = ((stage_v_90_2 + (step_2 * 4)) + pub_r000178_12_2) & 63;
    }
    else
    {
      stage_v_90_2 = ((stage_v_90_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_53_1 & 1) == step_1)
    {
      stage_v_91_1 = ((stage_v_91_1 + (step_1 * 4)) + pub_r000178_5_1) & 63;
    }
    else
    {
      stage_v_91_1 = ((stage_v_91_1 + pub_r000178_13_1) + 5) & 63;
    }
    if ((stage_v_53_2 & 1) == step_2)
    {
      stage_v_91_2 = ((stage_v_91_2 + (step_2 * 4)) + pub_r000178_5_2) & 63;
    }
    else
    {
      stage_v_91_2 = ((stage_v_91_2 + pub_r000178_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_9_1 & 1) == step_1)
    {
      stage_v_92_1 = ((stage_v_92_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_92_1 = ((stage_v_92_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((sec_r000178_9_2 & 1) == step_2)
    {
      stage_v_92_2 = ((stage_v_92_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_92_2 = ((stage_v_92_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_76_1 & 1) == step_1)
    {
      stage_v_93_1 = ((stage_v_93_1 + (step_1 * 4)) + pub_r000178_7_1) & 63;
    }
    else
    {
      stage_v_93_1 = ((stage_v_93_1 + pub_r000178_15_1) + 5) & 63;
    }
    if ((stage_v_76_2 & 1) == step_2)
    {
      stage_v_93_2 = ((stage_v_93_2 + (step_2 * 4)) + pub_r000178_7_2) & 63;
    }
    else
    {
      stage_v_93_2 = ((stage_v_93_2 + pub_r000178_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_56_1 & 1) == step_1)
    {
      stage_v_94_1 = ((stage_v_94_1 + (step_1 * 4)) + pub_r000178_14_1) & 63;
    }
    else
    {
      stage_v_94_1 = ((stage_v_94_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((stage_v_56_2 & 1) == step_2)
    {
      stage_v_94_2 = ((stage_v_94_2 + (step_2 * 4)) + pub_r000178_14_2) & 63;
    }
    else
    {
      stage_v_94_2 = ((stage_v_94_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_87_1 & 1) == step_1)
    {
      stage_v_95_1 = ((stage_v_95_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_95_1 = ((stage_v_95_1 + pub_r000178_3_1) + 5) & 63;
    }
    if ((stage_v_87_2 & 1) == step_2)
    {
      stage_v_95_2 = ((stage_v_95_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_95_2 = ((stage_v_95_2 + pub_r000178_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_52_1 & 1) == step_1)
    {
      stage_v_96_1 = ((stage_v_96_1 + (step_1 * 4)) + pub_r000178_3_1) & 63;
    }
    else
    {
      stage_v_96_1 = ((stage_v_96_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_52_2 & 1) == step_2)
    {
      stage_v_96_2 = ((stage_v_96_2 + (step_2 * 4)) + pub_r000178_3_2) & 63;
    }
    else
    {
      stage_v_96_2 = ((stage_v_96_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_90_1 & 1) == step_1)
    {
      stage_v_97_1 = ((stage_v_97_1 + (step_1 * 4)) + pub_r000178_15_1) & 63;
    }
    else
    {
      stage_v_97_1 = ((stage_v_97_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((stage_v_90_2 & 1) == step_2)
    {
      stage_v_97_2 = ((stage_v_97_2 + (step_2 * 4)) + pub_r000178_15_2) & 63;
    }
    else
    {
      stage_v_97_2 = ((stage_v_97_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_77_1 & 1) == step_1)
    {
      stage_v_98_1 = ((stage_v_98_1 + (step_1 * 4)) + pub_r000178_14_1) & 63;
    }
    else
    {
      stage_v_98_1 = ((stage_v_98_1 + pub_r000178_4_1) + 5) & 63;
    }
    if ((stage_v_77_2 & 1) == step_2)
    {
      stage_v_98_2 = ((stage_v_98_2 + (step_2 * 4)) + pub_r000178_14_2) & 63;
    }
    else
    {
      stage_v_98_2 = ((stage_v_98_2 + pub_r000178_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_46_1 & 1) == step_1)
    {
      stage_v_99_1 = ((stage_v_99_1 + (step_1 * 4)) + pub_r000178_9_1) & 63;
    }
    else
    {
      stage_v_99_1 = ((stage_v_99_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((stage_v_46_2 & 1) == step_2)
    {
      stage_v_99_2 = ((stage_v_99_2 + (step_2 * 4)) + pub_r000178_9_2) & 63;
    }
    else
    {
      stage_v_99_2 = ((stage_v_99_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_71_1 & 1) == step_1)
    {
      stage_v_100_1 = ((stage_v_100_1 + (step_1 * 4)) + pub_r000178_10_1) & 63;
    }
    else
    {
      stage_v_100_1 = ((stage_v_100_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_71_2 & 1) == step_2)
    {
      stage_v_100_2 = ((stage_v_100_2 + (step_2 * 4)) + pub_r000178_10_2) & 63;
    }
    else
    {
      stage_v_100_2 = ((stage_v_100_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_19_1 & 1) == step_1)
    {
      stage_v_101_1 = ((stage_v_101_1 + (step_1 * 4)) + pub_r000178_10_1) & 63;
    }
    else
    {
      stage_v_101_1 = ((stage_v_101_1 + pub_r000178_9_1) + 5) & 63;
    }
    if ((sec_r000178_19_2 & 1) == step_2)
    {
      stage_v_101_2 = ((stage_v_101_2 + (step_2 * 4)) + pub_r000178_10_2) & 63;
    }
    else
    {
      stage_v_101_2 = ((stage_v_101_2 + pub_r000178_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_88_1 & 1) == step_1)
    {
      stage_v_102_1 = ((stage_v_102_1 + (step_1 * 4)) + pub_r000178_7_1) & 63;
    }
    else
    {
      stage_v_102_1 = ((stage_v_102_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((stage_v_88_2 & 1) == step_2)
    {
      stage_v_102_2 = ((stage_v_102_2 + (step_2 * 4)) + pub_r000178_7_2) & 63;
    }
    else
    {
      stage_v_102_2 = ((stage_v_102_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_103_1 = ((stage_v_103_1 + (step_1 * 4)) + pub_r000178_15_1) & 63;
    }
    else
    {
      stage_v_103_1 = ((stage_v_103_1 + pub_r000178_1_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_103_2 = ((stage_v_103_2 + (step_2 * 4)) + pub_r000178_15_2) & 63;
    }
    else
    {
      stage_v_103_2 = ((stage_v_103_2 + pub_r000178_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_42_1 & 1) == step_1)
    {
      stage_v_104_1 = ((stage_v_104_1 + (step_1 * 4)) + pub_r000178_8_1) & 63;
    }
    else
    {
      stage_v_104_1 = ((stage_v_104_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((stage_v_42_2 & 1) == step_2)
    {
      stage_v_104_2 = ((stage_v_104_2 + (step_2 * 4)) + pub_r000178_8_2) & 63;
    }
    else
    {
      stage_v_104_2 = ((stage_v_104_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_102_1 & 1) == step_1)
    {
      stage_v_105_1 = ((stage_v_105_1 + (step_1 * 4)) + pub_r000178_12_1) & 63;
    }
    else
    {
      stage_v_105_1 = ((stage_v_105_1 + pub_r000178_4_1) + 5) & 63;
    }
    if ((stage_v_102_2 & 1) == step_2)
    {
      stage_v_105_2 = ((stage_v_105_2 + (step_2 * 4)) + pub_r000178_12_2) & 63;
    }
    else
    {
      stage_v_105_2 = ((stage_v_105_2 + pub_r000178_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_0_1 & 1) == step_1)
    {
      stage_v_106_1 = ((stage_v_106_1 + (step_1 * 4)) + pub_r000178_10_1) & 63;
    }
    else
    {
      stage_v_106_1 = ((stage_v_106_1 + pub_r000178_10_1) + 5) & 63;
    }
    if ((sec_r000178_0_2 & 1) == step_2)
    {
      stage_v_106_2 = ((stage_v_106_2 + (step_2 * 4)) + pub_r000178_10_2) & 63;
    }
    else
    {
      stage_v_106_2 = ((stage_v_106_2 + pub_r000178_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_14_1 & 1) == step_1)
    {
      stage_v_107_1 = ((stage_v_107_1 + (step_1 * 4)) + pub_r000178_8_1) & 63;
    }
    else
    {
      stage_v_107_1 = ((stage_v_107_1 + pub_r000178_7_1) + 5) & 63;
    }
    if ((sec_r000178_14_2 & 1) == step_2)
    {
      stage_v_107_2 = ((stage_v_107_2 + (step_2 * 4)) + pub_r000178_8_2) & 63;
    }
    else
    {
      stage_v_107_2 = ((stage_v_107_2 + pub_r000178_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_5_1 & 1) == step_1)
    {
      stage_v_108_1 = ((stage_v_108_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_108_1 = ((stage_v_108_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((sec_r000178_5_2 & 1) == step_2)
    {
      stage_v_108_2 = ((stage_v_108_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_108_2 = ((stage_v_108_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_4_1 & 1) == step_1)
    {
      stage_v_109_1 = ((stage_v_109_1 + (step_1 * 4)) + pub_r000178_5_1) & 63;
    }
    else
    {
      stage_v_109_1 = ((stage_v_109_1 + pub_r000178_3_1) + 5) & 63;
    }
    if ((sec_r000178_4_2 & 1) == step_2)
    {
      stage_v_109_2 = ((stage_v_109_2 + (step_2 * 4)) + pub_r000178_5_2) & 63;
    }
    else
    {
      stage_v_109_2 = ((stage_v_109_2 + pub_r000178_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_2_1 & 1) == step_1)
    {
      stage_v_110_1 = ((stage_v_110_1 + (step_1 * 4)) + pub_r000178_4_1) & 63;
    }
    else
    {
      stage_v_110_1 = ((stage_v_110_1 + pub_r000178_7_1) + 5) & 63;
    }
    if ((sec_r000178_2_2 & 1) == step_2)
    {
      stage_v_110_2 = ((stage_v_110_2 + (step_2 * 4)) + pub_r000178_4_2) & 63;
    }
    else
    {
      stage_v_110_2 = ((stage_v_110_2 + pub_r000178_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_81_1 & 1) == step_1)
    {
      stage_v_111_1 = ((stage_v_111_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_111_1 = ((stage_v_111_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((stage_v_81_2 & 1) == step_2)
    {
      stage_v_111_2 = ((stage_v_111_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_111_2 = ((stage_v_111_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_18_1 & 1) == step_1)
    {
      stage_v_112_1 = ((stage_v_112_1 + (step_1 * 4)) + pub_r000178_13_1) & 63;
    }
    else
    {
      stage_v_112_1 = ((stage_v_112_1 + pub_r000178_4_1) + 5) & 63;
    }
    if ((sec_r000178_18_2 & 1) == step_2)
    {
      stage_v_112_2 = ((stage_v_112_2 + (step_2 * 4)) + pub_r000178_13_2) & 63;
    }
    else
    {
      stage_v_112_2 = ((stage_v_112_2 + pub_r000178_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_105_1 & 1) == step_1)
    {
      stage_v_113_1 = ((stage_v_113_1 + (step_1 * 4)) + pub_r000178_5_1) & 63;
    }
    else
    {
      stage_v_113_1 = ((stage_v_113_1 + pub_r000178_12_1) + 5) & 63;
    }
    if ((stage_v_105_2 & 1) == step_2)
    {
      stage_v_113_2 = ((stage_v_113_2 + (step_2 * 4)) + pub_r000178_5_2) & 63;
    }
    else
    {
      stage_v_113_2 = ((stage_v_113_2 + pub_r000178_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_18_1 & 1) == step_1)
    {
      stage_v_114_1 = ((stage_v_114_1 + (step_1 * 4)) + pub_r000178_3_1) & 63;
    }
    else
    {
      stage_v_114_1 = ((stage_v_114_1 + pub_r000178_10_1) + 5) & 63;
    }
    if ((sec_r000178_18_2 & 1) == step_2)
    {
      stage_v_114_2 = ((stage_v_114_2 + (step_2 * 4)) + pub_r000178_3_2) & 63;
    }
    else
    {
      stage_v_114_2 = ((stage_v_114_2 + pub_r000178_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_72_1 & 1) == step_1)
    {
      stage_v_115_1 = ((stage_v_115_1 + (step_1 * 4)) + pub_r000178_7_1) & 63;
    }
    else
    {
      stage_v_115_1 = ((stage_v_115_1 + pub_r000178_9_1) + 5) & 63;
    }
    if ((stage_v_72_2 & 1) == step_2)
    {
      stage_v_115_2 = ((stage_v_115_2 + (step_2 * 4)) + pub_r000178_7_2) & 63;
    }
    else
    {
      stage_v_115_2 = ((stage_v_115_2 + pub_r000178_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_1_1 & 1) == step_1)
    {
      stage_v_116_1 = ((stage_v_116_1 + (step_1 * 4)) + pub_r000178_7_1) & 63;
    }
    else
    {
      stage_v_116_1 = ((stage_v_116_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((sec_r000178_1_2 & 1) == step_2)
    {
      stage_v_116_2 = ((stage_v_116_2 + (step_2 * 4)) + pub_r000178_7_2) & 63;
    }
    else
    {
      stage_v_116_2 = ((stage_v_116_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_85_1 & 1) == step_1)
    {
      stage_v_117_1 = ((stage_v_117_1 + (step_1 * 4)) + pub_r000178_10_1) & 63;
    }
    else
    {
      stage_v_117_1 = ((stage_v_117_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((stage_v_85_2 & 1) == step_2)
    {
      stage_v_117_2 = ((stage_v_117_2 + (step_2 * 4)) + pub_r000178_10_2) & 63;
    }
    else
    {
      stage_v_117_2 = ((stage_v_117_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_16_1 & 1) == step_1)
    {
      stage_v_118_1 = ((stage_v_118_1 + (step_1 * 4)) + pub_r000178_2_1) & 63;
    }
    else
    {
      stage_v_118_1 = ((stage_v_118_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((sec_r000178_16_2 & 1) == step_2)
    {
      stage_v_118_2 = ((stage_v_118_2 + (step_2 * 4)) + pub_r000178_2_2) & 63;
    }
    else
    {
      stage_v_118_2 = ((stage_v_118_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_117_1 & 1) == step_1)
    {
      stage_v_119_1 = ((stage_v_119_1 + (step_1 * 4)) + pub_r000178_8_1) & 63;
    }
    else
    {
      stage_v_119_1 = ((stage_v_119_1 + pub_r000178_15_1) + 5) & 63;
    }
    if ((stage_v_117_2 & 1) == step_2)
    {
      stage_v_119_2 = ((stage_v_119_2 + (step_2 * 4)) + pub_r000178_8_2) & 63;
    }
    else
    {
      stage_v_119_2 = ((stage_v_119_2 + pub_r000178_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_118_1 & 1) == step_1)
    {
      stage_v_120_1 = ((stage_v_120_1 + (step_1 * 4)) + pub_r000178_8_1) & 63;
    }
    else
    {
      stage_v_120_1 = ((stage_v_120_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((stage_v_118_2 & 1) == step_2)
    {
      stage_v_120_2 = ((stage_v_120_2 + (step_2 * 4)) + pub_r000178_8_2) & 63;
    }
    else
    {
      stage_v_120_2 = ((stage_v_120_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_118_1 & 1) == step_1)
    {
      stage_v_121_1 = ((stage_v_121_1 + (step_1 * 4)) + pub_r000178_15_1) & 63;
    }
    else
    {
      stage_v_121_1 = ((stage_v_121_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((stage_v_118_2 & 1) == step_2)
    {
      stage_v_121_2 = ((stage_v_121_2 + (step_2 * 4)) + pub_r000178_15_2) & 63;
    }
    else
    {
      stage_v_121_2 = ((stage_v_121_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_21_1 & 1) == step_1)
    {
      stage_v_122_1 = ((stage_v_122_1 + (step_1 * 4)) + pub_r000178_5_1) & 63;
    }
    else
    {
      stage_v_122_1 = ((stage_v_122_1 + pub_r000178_10_1) + 5) & 63;
    }
    if ((sec_r000178_21_2 & 1) == step_2)
    {
      stage_v_122_2 = ((stage_v_122_2 + (step_2 * 4)) + pub_r000178_5_2) & 63;
    }
    else
    {
      stage_v_122_2 = ((stage_v_122_2 + pub_r000178_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_11_1 & 1) == step_1)
    {
      stage_v_123_1 = ((stage_v_123_1 + (step_1 * 4)) + pub_r000178_10_1) & 63;
    }
    else
    {
      stage_v_123_1 = ((stage_v_123_1 + pub_r000178_3_1) + 5) & 63;
    }
    if ((sec_r000178_11_2 & 1) == step_2)
    {
      stage_v_123_2 = ((stage_v_123_2 + (step_2 * 4)) + pub_r000178_10_2) & 63;
    }
    else
    {
      stage_v_123_2 = ((stage_v_123_2 + pub_r000178_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_122_1 & 1) == step_1)
    {
      stage_v_124_1 = ((stage_v_124_1 + (step_1 * 4)) + pub_r000178_9_1) & 63;
    }
    else
    {
      stage_v_124_1 = ((stage_v_124_1 + pub_r000178_13_1) + 5) & 63;
    }
    if ((stage_v_122_2 & 1) == step_2)
    {
      stage_v_124_2 = ((stage_v_124_2 + (step_2 * 4)) + pub_r000178_9_2) & 63;
    }
    else
    {
      stage_v_124_2 = ((stage_v_124_2 + pub_r000178_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_102_1 & 1) == step_1)
    {
      stage_v_125_1 = ((stage_v_125_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_125_1 = ((stage_v_125_1 + pub_r000178_0_1) + 5) & 63;
    }
    if ((stage_v_102_2 & 1) == step_2)
    {
      stage_v_125_2 = ((stage_v_125_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_125_2 = ((stage_v_125_2 + pub_r000178_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_124_1 & 1) == step_1)
    {
      stage_v_126_1 = ((stage_v_126_1 + (step_1 * 4)) + pub_r000178_13_1) & 63;
    }
    else
    {
      stage_v_126_1 = ((stage_v_126_1 + pub_r000178_13_1) + 5) & 63;
    }
    if ((stage_v_124_2 & 1) == step_2)
    {
      stage_v_126_2 = ((stage_v_126_2 + (step_2 * 4)) + pub_r000178_13_2) & 63;
    }
    else
    {
      stage_v_126_2 = ((stage_v_126_2 + pub_r000178_13_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_19_1 & 1) == step_1)
    {
      stage_v_127_1 = ((stage_v_127_1 + (step_1 * 4)) + pub_r000178_4_1) & 63;
    }
    else
    {
      stage_v_127_1 = ((stage_v_127_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((sec_r000178_19_2 & 1) == step_2)
    {
      stage_v_127_2 = ((stage_v_127_2 + (step_2 * 4)) + pub_r000178_4_2) & 63;
    }
    else
    {
      stage_v_127_2 = ((stage_v_127_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_15_1 & 1) == step_1)
    {
      stage_v_128_1 = ((stage_v_128_1 + (step_1 * 4)) + pub_r000178_11_1) & 63;
    }
    else
    {
      stage_v_128_1 = ((stage_v_128_1 + pub_r000178_10_1) + 5) & 63;
    }
    if ((sec_r000178_15_2 & 1) == step_2)
    {
      stage_v_128_2 = ((stage_v_128_2 + (step_2 * 4)) + pub_r000178_11_2) & 63;
    }
    else
    {
      stage_v_128_2 = ((stage_v_128_2 + pub_r000178_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_58_1 & 1) == step_1)
    {
      stage_v_129_1 = ((stage_v_129_1 + (step_1 * 4)) + pub_r000178_3_1) & 63;
    }
    else
    {
      stage_v_129_1 = ((stage_v_129_1 + pub_r000178_1_1) + 5) & 63;
    }
    if ((stage_v_58_2 & 1) == step_2)
    {
      stage_v_129_2 = ((stage_v_129_2 + (step_2 * 4)) + pub_r000178_3_2) & 63;
    }
    else
    {
      stage_v_129_2 = ((stage_v_129_2 + pub_r000178_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_84_1 & 1) == step_1)
    {
      stage_v_130_1 = ((stage_v_130_1 + (step_1 * 4)) + pub_r000178_8_1) & 63;
    }
    else
    {
      stage_v_130_1 = ((stage_v_130_1 + pub_r000178_9_1) + 5) & 63;
    }
    if ((stage_v_84_2 & 1) == step_2)
    {
      stage_v_130_2 = ((stage_v_130_2 + (step_2 * 4)) + pub_r000178_8_2) & 63;
    }
    else
    {
      stage_v_130_2 = ((stage_v_130_2 + pub_r000178_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_3_1 & 1) == step_1)
    {
      stage_v_131_1 = ((stage_v_131_1 + (step_1 * 4)) + pub_r000178_5_1) & 63;
    }
    else
    {
      stage_v_131_1 = ((stage_v_131_1 + pub_r000178_15_1) + 5) & 63;
    }
    if ((sec_r000178_3_2 & 1) == step_2)
    {
      stage_v_131_2 = ((stage_v_131_2 + (step_2 * 4)) + pub_r000178_5_2) & 63;
    }
    else
    {
      stage_v_131_2 = ((stage_v_131_2 + pub_r000178_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_0_1 & 1) == step_1)
    {
      stage_v_132_1 = ((stage_v_132_1 + (step_1 * 4)) + pub_r000178_6_1) & 63;
    }
    else
    {
      stage_v_132_1 = ((stage_v_132_1 + pub_r000178_15_1) + 5) & 63;
    }
    if ((sec_r000178_0_2 & 1) == step_2)
    {
      stage_v_132_2 = ((stage_v_132_2 + (step_2 * 4)) + pub_r000178_6_2) & 63;
    }
    else
    {
      stage_v_132_2 = ((stage_v_132_2 + pub_r000178_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_129_1 & 1) == step_1)
    {
      stage_v_133_1 = ((stage_v_133_1 + (step_1 * 4)) + pub_r000178_14_1) & 63;
    }
    else
    {
      stage_v_133_1 = ((stage_v_133_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((stage_v_129_2 & 1) == step_2)
    {
      stage_v_133_2 = ((stage_v_133_2 + (step_2 * 4)) + pub_r000178_14_2) & 63;
    }
    else
    {
      stage_v_133_2 = ((stage_v_133_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_13_1 & 1) == step_1)
    {
      stage_v_134_1 = ((stage_v_134_1 + (step_1 * 4)) + pub_r000178_12_1) & 63;
    }
    else
    {
      stage_v_134_1 = ((stage_v_134_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((sec_r000178_13_2 & 1) == step_2)
    {
      stage_v_134_2 = ((stage_v_134_2 + (step_2 * 4)) + pub_r000178_12_2) & 63;
    }
    else
    {
      stage_v_134_2 = ((stage_v_134_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_11_1 & 1) == step_1)
    {
      stage_v_135_1 = ((stage_v_135_1 + (step_1 * 4)) + pub_r000178_5_1) & 63;
    }
    else
    {
      stage_v_135_1 = ((stage_v_135_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((sec_r000178_11_2 & 1) == step_2)
    {
      stage_v_135_2 = ((stage_v_135_2 + (step_2 * 4)) + pub_r000178_5_2) & 63;
    }
    else
    {
      stage_v_135_2 = ((stage_v_135_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_114_1 & 1) == step_1)
    {
      stage_v_136_1 = ((stage_v_136_1 + (step_1 * 4)) + pub_r000178_4_1) & 63;
    }
    else
    {
      stage_v_136_1 = ((stage_v_136_1 + pub_r000178_15_1) + 5) & 63;
    }
    if ((stage_v_114_2 & 1) == step_2)
    {
      stage_v_136_2 = ((stage_v_136_2 + (step_2 * 4)) + pub_r000178_4_2) & 63;
    }
    else
    {
      stage_v_136_2 = ((stage_v_136_2 + pub_r000178_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_84_1 & 1) == step_1)
    {
      stage_v_137_1 = ((stage_v_137_1 + (step_1 * 4)) + pub_r000178_1_1) & 63;
    }
    else
    {
      stage_v_137_1 = ((stage_v_137_1 + pub_r000178_1_1) + 5) & 63;
    }
    if ((stage_v_84_2 & 1) == step_2)
    {
      stage_v_137_2 = ((stage_v_137_2 + (step_2 * 4)) + pub_r000178_1_2) & 63;
    }
    else
    {
      stage_v_137_2 = ((stage_v_137_2 + pub_r000178_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_10_1 & 1) == step_1)
    {
      stage_v_138_1 = ((stage_v_138_1 + (step_1 * 4)) + pub_r000178_3_1) & 63;
    }
    else
    {
      stage_v_138_1 = ((stage_v_138_1 + pub_r000178_14_1) + 5) & 63;
    }
    if ((sec_r000178_10_2 & 1) == step_2)
    {
      stage_v_138_2 = ((stage_v_138_2 + (step_2 * 4)) + pub_r000178_3_2) & 63;
    }
    else
    {
      stage_v_138_2 = ((stage_v_138_2 + pub_r000178_14_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_9_1 & 1) == step_1)
    {
      stage_v_139_1 = ((stage_v_139_1 + (step_1 * 4)) + pub_r000178_8_1) & 63;
    }
    else
    {
      stage_v_139_1 = ((stage_v_139_1 + pub_r000178_0_1) + 5) & 63;
    }
    if ((sec_r000178_9_2 & 1) == step_2)
    {
      stage_v_139_2 = ((stage_v_139_2 + (step_2 * 4)) + pub_r000178_8_2) & 63;
    }
    else
    {
      stage_v_139_2 = ((stage_v_139_2 + pub_r000178_0_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_130_1 & 1) == step_1)
    {
      stage_v_140_1 = ((stage_v_140_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_140_1 = ((stage_v_140_1 + pub_r000178_1_1) + 5) & 63;
    }
    if ((stage_v_130_2 & 1) == step_2)
    {
      stage_v_140_2 = ((stage_v_140_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_140_2 = ((stage_v_140_2 + pub_r000178_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_49_1 & 1) == step_1)
    {
      stage_v_141_1 = ((stage_v_141_1 + (step_1 * 4)) + pub_r000178_12_1) & 63;
    }
    else
    {
      stage_v_141_1 = ((stage_v_141_1 + pub_r000178_3_1) + 5) & 63;
    }
    if ((stage_v_49_2 & 1) == step_2)
    {
      stage_v_141_2 = ((stage_v_141_2 + (step_2 * 4)) + pub_r000178_12_2) & 63;
    }
    else
    {
      stage_v_141_2 = ((stage_v_141_2 + pub_r000178_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_74_1 & 1) == step_1)
    {
      stage_v_142_1 = ((stage_v_142_1 + (step_1 * 4)) + pub_r000178_14_1) & 63;
    }
    else
    {
      stage_v_142_1 = ((stage_v_142_1 + pub_r000178_9_1) + 5) & 63;
    }
    if ((stage_v_74_2 & 1) == step_2)
    {
      stage_v_142_2 = ((stage_v_142_2 + (step_2 * 4)) + pub_r000178_14_2) & 63;
    }
    else
    {
      stage_v_142_2 = ((stage_v_142_2 + pub_r000178_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_66_1 & 1) == step_1)
    {
      stage_v_143_1 = ((stage_v_143_1 + (step_1 * 4)) + pub_r000178_10_1) & 63;
    }
    else
    {
      stage_v_143_1 = ((stage_v_143_1 + pub_r000178_8_1) + 5) & 63;
    }
    if ((stage_v_66_2 & 1) == step_2)
    {
      stage_v_143_2 = ((stage_v_143_2 + (step_2 * 4)) + pub_r000178_10_2) & 63;
    }
    else
    {
      stage_v_143_2 = ((stage_v_143_2 + pub_r000178_8_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_14_1 & 1) == step_1)
    {
      stage_v_144_1 = ((stage_v_144_1 + (step_1 * 4)) + pub_r000178_14_1) & 63;
    }
    else
    {
      stage_v_144_1 = ((stage_v_144_1 + pub_r000178_10_1) + 5) & 63;
    }
    if ((sec_r000178_14_2 & 1) == step_2)
    {
      stage_v_144_2 = ((stage_v_144_2 + (step_2 * 4)) + pub_r000178_14_2) & 63;
    }
    else
    {
      stage_v_144_2 = ((stage_v_144_2 + pub_r000178_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_78_1 & 1) == step_1)
    {
      stage_v_145_1 = ((stage_v_145_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_145_1 = ((stage_v_145_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_78_2 & 1) == step_2)
    {
      stage_v_145_2 = ((stage_v_145_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_145_2 = ((stage_v_145_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_5_1 & 1) == step_1)
    {
      stage_v_146_1 = ((stage_v_146_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_146_1 = ((stage_v_146_1 + pub_r000178_10_1) + 5) & 63;
    }
    if ((sec_r000178_5_2 & 1) == step_2)
    {
      stage_v_146_2 = ((stage_v_146_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_146_2 = ((stage_v_146_2 + pub_r000178_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_121_1 & 1) == step_1)
    {
      stage_v_147_1 = ((stage_v_147_1 + (step_1 * 4)) + pub_r000178_0_1) & 63;
    }
    else
    {
      stage_v_147_1 = ((stage_v_147_1 + pub_r000178_1_1) + 5) & 63;
    }
    if ((stage_v_121_2 & 1) == step_2)
    {
      stage_v_147_2 = ((stage_v_147_2 + (step_2 * 4)) + pub_r000178_0_2) & 63;
    }
    else
    {
      stage_v_147_2 = ((stage_v_147_2 + pub_r000178_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_106_1 & 1) == step_1)
    {
      stage_v_148_1 = ((stage_v_148_1 + (step_1 * 4)) + pub_r000178_4_1) & 63;
    }
    else
    {
      stage_v_148_1 = ((stage_v_148_1 + pub_r000178_15_1) + 5) & 63;
    }
    if ((stage_v_106_2 & 1) == step_2)
    {
      stage_v_148_2 = ((stage_v_148_2 + (step_2 * 4)) + pub_r000178_4_2) & 63;
    }
    else
    {
      stage_v_148_2 = ((stage_v_148_2 + pub_r000178_15_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_62_1 & 1) == step_1)
    {
      stage_v_149_1 = ((stage_v_149_1 + (step_1 * 4)) + pub_r000178_8_1) & 63;
    }
    else
    {
      stage_v_149_1 = ((stage_v_149_1 + pub_r000178_11_1) + 5) & 63;
    }
    if ((stage_v_62_2 & 1) == step_2)
    {
      stage_v_149_2 = ((stage_v_149_2 + (step_2 * 4)) + pub_r000178_8_2) & 63;
    }
    else
    {
      stage_v_149_2 = ((stage_v_149_2 + pub_r000178_11_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_89_1 & 1) == step_1)
    {
      stage_v_150_1 = ((stage_v_150_1 + (step_1 * 4)) + pub_r000178_11_1) & 63;
    }
    else
    {
      stage_v_150_1 = ((stage_v_150_1 + pub_r000178_3_1) + 5) & 63;
    }
    if ((stage_v_89_2 & 1) == step_2)
    {
      stage_v_150_2 = ((stage_v_150_2 + (step_2 * 4)) + pub_r000178_11_2) & 63;
    }
    else
    {
      stage_v_150_2 = ((stage_v_150_2 + pub_r000178_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_151_1 = ((stage_v_151_1 + (step_1 * 4)) + pub_r000178_7_1) & 63;
    }
    else
    {
      stage_v_151_1 = ((stage_v_151_1 + pub_r000178_7_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_151_2 = ((stage_v_151_2 + (step_2 * 4)) + pub_r000178_7_2) & 63;
    }
    else
    {
      stage_v_151_2 = ((stage_v_151_2 + pub_r000178_7_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000178_6_1 & 1) == step_1)
    {
      stage_v_152_1 = ((stage_v_152_1 + (step_1 * 4)) + pub_r000178_3_1) & 63;
    }
    else
    {
      stage_v_152_1 = ((stage_v_152_1 + pub_r000178_2_1) + 5) & 63;
    }
    if ((sec_r000178_6_2 & 1) == step_2)
    {
      stage_v_152_2 = ((stage_v_152_2 + (step_2 * 4)) + pub_r000178_3_2) & 63;
    }
    else
    {
      stage_v_152_2 = ((stage_v_152_2 + pub_r000178_2_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000178_8_1 == pub_r000178_8_2);
  __CPROVER_assume(sec_r000178_15_1 != sec_r000178_15_2);
  __CPROVER_assume(pub_r000178_4_1 == pub_r000178_4_2);
  __CPROVER_assume(sec_r000178_2_1 != sec_r000178_2_2);
  __CPROVER_assume(sec_r000178_19_1 != sec_r000178_19_2);
  __CPROVER_assume(sec_r000178_11_1 != sec_r000178_11_2);
  __CPROVER_assume(pub_r000178_13_1 == pub_r000178_13_2);
  __CPROVER_assume(sec_r000178_9_1 != sec_r000178_9_2);
  __CPROVER_assume(sec_r000178_0_1 != sec_r000178_0_2);
  __CPROVER_assume(sec_r000178_17_1 != sec_r000178_17_2);
  __CPROVER_assume(sec_r000178_5_1 != sec_r000178_5_2);
  __CPROVER_assume(pub_r000178_7_1 == pub_r000178_7_2);
  __CPROVER_assume(sec_r000178_21_1 != sec_r000178_21_2);
  __CPROVER_assume(sec_r000178_16_1 != sec_r000178_16_2);
  __CPROVER_assume(pub_r000178_14_1 == pub_r000178_14_2);
  __CPROVER_assume(pub_r000178_1_1 == pub_r000178_1_2);
  __CPROVER_assume(sec_r000178_6_1 != sec_r000178_6_2);
  __CPROVER_assume(pub_r000178_11_1 == pub_r000178_11_2);
  __CPROVER_assume(pub_r000178_12_1 == pub_r000178_12_2);
  __CPROVER_assume(sec_r000178_4_1 != sec_r000178_4_2);
  __CPROVER_assume(sec_r000178_10_1 != sec_r000178_10_2);
  __CPROVER_assume(sec_r000178_1_1 != sec_r000178_1_2);
  __CPROVER_assume(sec_r000178_13_1 != sec_r000178_13_2);
  __CPROVER_assume(sec_r000178_3_1 != sec_r000178_3_2);
  __CPROVER_assume(pub_r000178_15_1 == pub_r000178_15_2);
  __CPROVER_assume(sec_r000178_12_1 != sec_r000178_12_2);
  __CPROVER_assume(pub_r000178_2_1 == pub_r000178_2_2);
  __CPROVER_assume(pub_r000178_3_1 == pub_r000178_3_2);
  __CPROVER_assume(pub_r000178_6_1 == pub_r000178_6_2);
  __CPROVER_assume(pub_r000178_9_1 == pub_r000178_9_2);
  __CPROVER_assume(sec_r000178_8_1 != sec_r000178_8_2);
  __CPROVER_assume(pub_r000178_0_1 == pub_r000178_0_2);
  __CPROVER_assume(sec_r000178_20_1 != sec_r000178_20_2);
  __CPROVER_assume(pub_r000178_10_1 == pub_r000178_10_2);
  __CPROVER_assume(sec_r000178_14_1 != sec_r000178_14_2);
  __CPROVER_assume(sec_r000178_7_1 != sec_r000178_7_2);
  __CPROVER_assume(pub_r000178_5_1 == pub_r000178_5_2);
  __CPROVER_assume(sec_r000178_18_1 != sec_r000178_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  assert(st_var_2_1.head == st_var_2_2.head);
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
}


