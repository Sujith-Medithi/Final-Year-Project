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
struct SensorNode_R000557_5713_0
{
  short threshold;
  int reading;
  int gain;
  int offset;
  int buffer[3];
};
struct EventLog_R000557_5713_1
{
  int code;
  short signature;
  int facility;
  int severity;
  int timestamp;
  int seq;
  int buffer[3];
};
struct FilterState_R000557_5713_2
{
  short prev_out;
  int damping;
  int cutoff;
  short mode;
  unsigned char gain_db;
  int buffer[3];
};
union PacketPayload_R000557_5713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000557_5713_1
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
void fn_R000557_5713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st_1 = {0};
  struct EventLog_R000557_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_34_1 > 32)
  {
    acc_1 = ((acc_1 + (quotient_34_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_34_2 > 32)
  {
    acc_2 = ((acc_2 + (quotient_34_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_34_1 == quotient_34_2);
}

int fn_R000557_5713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_34 > 32)
  {
    acc = ((acc + (quotient_34 * 2)) + 5) & 127;
    aux ^= quotient_34 & 15;
  }
  else
  {
    acc = ((acc - quotient_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000557_5713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st_1 = {0};
  struct FilterState_R000557_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int margin_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_12_1)
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

  switch (margin_12_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_28_1 = local_arr_1[aux_1 % 3];
  int mask_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_28_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_37_1 > 39)
  {
    acc_1 = ((acc_1 + (anchor_37_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_37_2 > 39)
  {
    acc_2 = ((acc_2 + (anchor_37_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_12_1 == margin_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_28_1 == mask_28_2);
  assert(anchor_37_1 == anchor_37_2);
}

int fn_R000557_5713_1(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int margin_12 = (aux + st.buffer[1]) & 3;
  switch (margin_12)
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

  int local_arr[3] = {4, 9, 15};
  int mask_28 = local_arr[aux % 3];
  acc = (acc + (mask_28 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_37 > 39)
  {
    acc = ((acc + (anchor_37 * 2)) + 5) & 127;
    aux ^= anchor_37 & 15;
  }
  else
  {
    acc = ((acc - anchor_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000557_5713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st_1 = {0};
  struct SensorNode_R000557_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int window_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_48_1 > 23)
  {
    acc_1 = ((acc_1 + (window_48_1 * 2)) + 5) & 127;
    aux_1 ^= window_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_48_2 > 23)
  {
    acc_2 = ((acc_2 + (window_48_2 * 2)) + 5) & 127;
    aux_2 ^= window_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_48_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_48_1 == window_48_2);
}

int fn_R000557_5713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int window_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_48 > 23)
  {
    acc = ((acc + (window_48 * 2)) + 5) & 127;
    aux ^= window_48 & 15;
  }
  else
  {
    acc = ((acc - window_48) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st_1 = {0};
  struct SensorNode_R000557_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_13_1) & 63;
  aux_2 = (aux_2 + pivot_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_17_1 > 24)
  {
    acc_1 = ((acc_1 + (residue_17_1 * 2)) + 5) & 127;
    aux_1 ^= residue_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_17_2 > 24)
  {
    acc_2 = ((acc_2 + (residue_17_2 * 2)) + 5) & 127;
    aux_2 ^= residue_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_70_1 = local_arr_1[aux_1 % 3];
  int quantum_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_13_1 == pivot_13_2);
  assert(residue_17_1 == residue_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_70_1 == quantum_70_2);
}

int fn_R000557_5713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_13) & 63;
  acc ^= aux;
  int residue_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_17 > 24)
  {
    acc = ((acc + (residue_17 * 2)) + 5) & 127;
    aux ^= residue_17 & 15;
  }
  else
  {
    acc = ((acc - residue_17) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_70 = local_arr[aux % 3];
  acc = (acc + (quantum_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st_1 = {0};
  struct FilterState_R000557_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_28_1 = local_arr_1[aux_1 % 3];
  int phase_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_28_2 * 2)) & 127;
  int delta_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_96_1 > 31)
  {
    acc_1 = ((acc_1 + (delta_96_1 * 2)) + 5) & 127;
    aux_1 ^= delta_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_96_2 > 31)
  {
    acc_2 = ((acc_2 + (delta_96_2 * 2)) + 5) & 127;
    aux_2 ^= delta_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_55_1) & 63;
  aux_2 = (aux_2 + factor_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_28_1 == phase_28_2);
  assert(delta_96_1 == delta_96_2);
  assert(factor_55_1 == factor_55_2);
}

int fn_R000557_5713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int phase_28 = local_arr[aux % 3];
  acc = (acc + (phase_28 * 2)) & 127;
  int delta_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_96 > 31)
  {
    acc = ((acc + (delta_96 * 2)) + 5) & 127;
    aux ^= delta_96 & 15;
  }
  else
  {
    acc = ((acc - delta_96) + 11) & 127;
    aux += 3;
  }
  int factor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_55) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st_1 = {0};
  struct SensorNode_R000557_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tracker_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_18_1)
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

  switch (tracker_18_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_40_1 = local_arr_1[aux_1 % 3];
  int anchor_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_18_1 == tracker_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_40_1 == anchor_40_2);
}

int fn_R000557_5713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tracker_18 = (aux + st.buffer[1]) & 3;
  switch (tracker_18)
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
  int local_arr[3] = {4, 9, 15};
  int anchor_40 = local_arr[aux % 3];
  acc = (acc + (anchor_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st_1 = {0};
  struct EventLog_R000557_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int vector_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_25_1 > 44)
  {
    acc_1 = ((acc_1 + (vector_25_1 * 2)) + 5) & 127;
    aux_1 ^= vector_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_25_2 > 44)
  {
    acc_2 = ((acc_2 + (vector_25_2 * 2)) + 5) & 127;
    aux_2 ^= vector_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_25_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_98_1) & 63;
  aux_2 = (aux_2 + pivot_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_25_1 == vector_25_2);
  assert(pivot_98_1 == pivot_98_2);
}

int fn_R000557_5713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int vector_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_25 > 44)
  {
    acc = ((acc + (vector_25 * 2)) + 5) & 127;
    aux ^= vector_25 & 15;
  }
  else
  {
    acc = ((acc - vector_25) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000557_5713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st_1 = {0};
  struct EventLog_R000557_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int stride_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_81_1 > 24)
  {
    acc_1 = ((acc_1 + (stride_81_1 * 2)) + 5) & 127;
    aux_1 ^= stride_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_81_2 > 24)
  {
    acc_2 = ((acc_2 + (stride_81_2 * 2)) + 5) & 127;
    aux_2 ^= stride_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_50_1 = local_arr_1[aux_1 % 3];
  int tally_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_81_1 == stride_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_50_1 == tally_50_2);
}

int fn_R000557_5713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int stride_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_81 > 24)
  {
    acc = ((acc + (stride_81 * 2)) + 5) & 127;
    aux ^= stride_81 & 15;
  }
  else
  {
    acc = ((acc - stride_81) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_50 = local_arr[aux % 3];
  acc = (acc + (tally_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st_1 = {0};
  struct EventLog_R000557_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_13_1) & 63;
  aux_2 = (aux_2 + margin_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_80_1)
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

  switch (phase_80_2)
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

  int pivot_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_37_1 > 43)
  {
    acc_1 = ((acc_1 + (pivot_37_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_37_2 > 43)
  {
    acc_2 = ((acc_2 + (pivot_37_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_13_1 == margin_13_2);
  assert(phase_80_1 == phase_80_2);
  assert(pivot_37_1 == pivot_37_2);
}

int fn_R000557_5713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_13) & 63;
  acc ^= aux;
  int phase_80 = (aux + st.buffer[1]) & 3;
  switch (phase_80)
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

  int pivot_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_37 > 43)
  {
    acc = ((acc + (pivot_37 * 2)) + 5) & 127;
    aux ^= pivot_37 & 15;
  }
  else
  {
    acc = ((acc - pivot_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000557_5713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st_1 = {0};
  struct EventLog_R000557_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quotient_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_43_1)
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

  switch (quotient_43_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_43_1 == quotient_43_2);
}

int fn_R000557_5713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quotient_43 = (aux + st.buffer[1]) & 3;
  switch (quotient_43)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st_1 = {0};
  struct FilterState_R000557_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int mask_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_57_1) & 63;
  aux_2 = (aux_2 + mask_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_32_1)
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

  switch (mask_32_2)
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

  int quotient_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_68_1 > 23)
  {
    acc_1 = ((acc_1 + (quotient_68_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_68_2 > 23)
  {
    acc_2 = ((acc_2 + (quotient_68_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_10_1 = local_arr_1[aux_1 % 3];
  int window_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_57_1 == mask_57_2);
  assert(mask_32_1 == mask_32_2);
  assert(quotient_68_1 == quotient_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_10_1 == window_10_2);
}

int fn_R000557_5713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int mask_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_57) & 63;
  acc ^= aux;
  int mask_32 = (aux + st.buffer[1]) & 3;
  switch (mask_32)
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

  int quotient_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_68 > 23)
  {
    acc = ((acc + (quotient_68 * 2)) + 5) & 127;
    aux ^= quotient_68 & 15;
  }
  else
  {
    acc = ((acc - quotient_68) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_10 = local_arr[aux % 3];
  acc = (acc + (window_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st_1 = {0};
  struct FilterState_R000557_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int stride_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_78_1) & 63;
  aux_2 = (aux_2 + stride_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_78_1 == stride_78_2);
}

int fn_R000557_5713_11(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int stride_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_78) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st_1 = {0};
  struct FilterState_R000557_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_87_1)
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

  switch (stride_87_2)
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

  int accumulator_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_68_1 > 24)
  {
    acc_1 = ((acc_1 + (accumulator_68_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_68_2 > 24)
  {
    acc_2 = ((acc_2 + (accumulator_68_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_65_1) & 63;
  aux_2 = (aux_2 + mask_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_87_1 == stride_87_2);
  assert(accumulator_68_1 == accumulator_68_2);
  assert(mask_65_1 == mask_65_2);
}

int fn_R000557_5713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_87 = (aux + st.buffer[1]) & 3;
  switch (stride_87)
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

  int accumulator_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_68 > 24)
  {
    acc = ((acc + (accumulator_68 * 2)) + 5) & 127;
    aux ^= accumulator_68 & 15;
  }
  else
  {
    acc = ((acc - accumulator_68) + 11) & 127;
    aux += 3;
  }
  int mask_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000557_5713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st_1 = {0};
  struct FilterState_R000557_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int phase_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_47_1)
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

  switch (phase_47_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_51_1 > 14)
  {
    acc_1 = ((acc_1 + (anchor_51_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_51_2 > 14)
  {
    acc_2 = ((acc_2 + (anchor_51_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_81_1) & 63;
  aux_2 = (aux_2 + quantum_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_47_1 == phase_47_2);
  assert(anchor_51_1 == anchor_51_2);
  assert(quantum_81_1 == quantum_81_2);
}

int fn_R000557_5713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int phase_47 = (aux + st.buffer[1]) & 3;
  switch (phase_47)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_51 > 14)
  {
    acc = ((acc + (anchor_51 * 2)) + 5) & 127;
    aux ^= anchor_51 & 15;
  }
  else
  {
    acc = ((acc - anchor_51) + 11) & 127;
    aux += 3;
  }
  int quantum_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000557_5713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st_1 = {0};
  struct EventLog_R000557_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int index_reg_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_43_1 > 35)
  {
    acc_1 = ((acc_1 + (index_reg_43_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_43_2 > 35)
  {
    acc_2 = ((acc_2 + (index_reg_43_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_13_1 = local_arr_1[aux_1 % 3];
  int window_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_43_1 == index_reg_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_13_1 == window_13_2);
}

int fn_R000557_5713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int index_reg_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_43 > 35)
  {
    acc = ((acc + (index_reg_43 * 2)) + 5) & 127;
    aux ^= index_reg_43 & 15;
  }
  else
  {
    acc = ((acc - index_reg_43) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_13 = local_arr[aux % 3];
  acc = (acc + (window_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st_1 = {0};
  struct EventLog_R000557_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_31_1 = local_arr_1[aux_1 % 3];
  int coefficient_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_31_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_85_1)
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

  switch (weight_85_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_31_1 == coefficient_31_2);
  assert(weight_85_1 == weight_85_2);
}

int fn_R000557_5713_15(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int coefficient_31 = local_arr[aux % 3];
  acc = (acc + (coefficient_31 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_85 = (aux + st.buffer[1]) & 3;
  switch (weight_85)
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

void fn_R000557_5713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st_1 = {0};
  struct SensorNode_R000557_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_89_1)
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

  switch (residue_89_2)
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

  int quantum_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_21_1) & 63;
  aux_2 = (aux_2 + quantum_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_89_1 == residue_89_2);
  assert(quantum_21_1 == quantum_21_2);
}

int fn_R000557_5713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_89 = (aux + st.buffer[1]) & 3;
  switch (residue_89)
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

  int quantum_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000557_5713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st_1 = {0};
  struct FilterState_R000557_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int window_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_39_1 > 47)
  {
    acc_1 = ((acc_1 + (window_39_1 * 2)) + 5) & 127;
    aux_1 ^= window_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_39_2 > 47)
  {
    acc_2 = ((acc_2 + (window_39_2 * 2)) + 5) & 127;
    aux_2 ^= window_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_57_1)
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

  switch (checksum_57_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_39_1 == window_39_2);
  assert(checksum_57_1 == checksum_57_2);
}

int fn_R000557_5713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int window_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_39 > 47)
  {
    acc = ((acc + (window_39 * 2)) + 5) & 127;
    aux ^= window_39 & 15;
  }
  else
  {
    acc = ((acc - window_39) + 11) & 127;
    aux += 3;
  }
  int checksum_57 = (aux + st.buffer[1]) & 3;
  switch (checksum_57)
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

void fn_R000557_5713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st_1 = {0};
  struct SensorNode_R000557_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_90_1 = local_arr_1[aux_1 % 3];
  int pivot_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_90_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_90_1 == pivot_90_2);
}

int fn_R000557_5713_18(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int pivot_90 = local_arr[aux % 3];
  acc = (acc + (pivot_90 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st_1 = {0};
  struct SensorNode_R000557_5713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int phase_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_76_1) & 63;
  aux_2 = (aux_2 + phase_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_39_1 > 25)
  {
    acc_1 = ((acc_1 + (segment_39_1 * 2)) + 5) & 127;
    aux_1 ^= segment_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_39_2 > 25)
  {
    acc_2 = ((acc_2 + (segment_39_2 * 2)) + 5) & 127;
    aux_2 ^= segment_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_39_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_76_1 == phase_76_2);
  assert(segment_39_1 == segment_39_2);
}

int fn_R000557_5713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000557_5713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int phase_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_76) & 63;
  acc ^= aux;
  int segment_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_39 > 25)
  {
    acc = ((acc + (segment_39 * 2)) + 5) & 127;
    aux ^= segment_39 & 15;
  }
  else
  {
    acc = ((acc - segment_39) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000557_5713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st_1 = {0};
  struct EventLog_R000557_5713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int coefficient_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_88_1) & 63;
  aux_2 = (aux_2 + coefficient_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_20_1)
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

  switch (margin_20_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_88_1 == coefficient_88_2);
  assert(margin_20_1 == margin_20_2);
}

int fn_R000557_5713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000557_5713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int coefficient_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_88) & 63;
  acc ^= aux;
  int margin_20 = (aux + st.buffer[1]) & 3;
  switch (margin_20)
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

void fn_R000557_5713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st_1 = {0};
  struct FilterState_R000557_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int sample_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_39_1 > 13)
  {
    acc_1 = ((acc_1 + (sample_39_1 * 2)) + 5) & 127;
    aux_1 ^= sample_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_39_2 > 13)
  {
    acc_2 = ((acc_2 + (sample_39_2 * 2)) + 5) & 127;
    aux_2 ^= sample_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_39_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_61_1) & 63;
  aux_2 = (aux_2 + parity_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_39_1 == sample_39_2);
  assert(parity_61_1 == parity_61_2);
}

int fn_R000557_5713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int sample_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_39 > 13)
  {
    acc = ((acc + (sample_39 * 2)) + 5) & 127;
    aux ^= sample_39 & 15;
  }
  else
  {
    acc = ((acc - sample_39) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000557_5713_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st_1 = {0};
  struct FilterState_R000557_5713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int factor_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_41_1) & 63;
  aux_2 = (aux_2 + factor_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_99_1)
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

  switch (weight_99_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_41_1 == factor_41_2);
  assert(weight_99_1 == weight_99_2);
}

int fn_R000557_5713_22(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000557_5713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int factor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_41) & 63;
  acc ^= aux;
  int weight_99 = (aux + st.buffer[1]) & 3;
  switch (weight_99)
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

void main()
{
  int sec_r000557_0_1;
  int sec_r000557_0_2;
  int sec_r000557_1_1;
  int sec_r000557_1_2;
  int sec_r000557_2_1;
  int sec_r000557_2_2;
  int sec_r000557_3_1;
  int sec_r000557_3_2;
  int sec_r000557_4_1;
  int sec_r000557_4_2;
  int sec_r000557_5_1;
  int sec_r000557_5_2;
  int sec_r000557_6_1;
  int sec_r000557_6_2;
  int sec_r000557_7_1;
  int sec_r000557_7_2;
  int sec_r000557_8_1;
  int sec_r000557_8_2;
  int sec_r000557_9_1;
  int sec_r000557_9_2;
  int sec_r000557_10_1;
  int sec_r000557_10_2;
  int sec_r000557_11_1;
  int sec_r000557_11_2;
  int sec_r000557_12_1;
  int sec_r000557_12_2;
  int sec_r000557_13_1;
  int sec_r000557_13_2;
  int sec_r000557_14_1;
  int sec_r000557_14_2;
  int sec_r000557_15_1;
  int sec_r000557_15_2;
  int sec_r000557_16_1;
  int sec_r000557_16_2;
  int sec_r000557_17_1;
  int sec_r000557_17_2;
  int sec_r000557_18_1;
  int sec_r000557_18_2;
  int sec_r000557_19_1;
  int sec_r000557_19_2;
  int sec_r000557_20_1;
  int sec_r000557_20_2;
  int sec_r000557_21_1;
  int sec_r000557_21_2;
  int pub_r000557_0_1;
  int pub_r000557_0_2;
  int pub_r000557_1_1;
  int pub_r000557_1_2;
  int pub_r000557_2_1;
  int pub_r000557_2_2;
  int pub_r000557_3_1;
  int pub_r000557_3_2;
  int pub_r000557_4_1;
  int pub_r000557_4_2;
  int pub_r000557_5_1;
  int pub_r000557_5_2;
  int pub_r000557_6_1;
  int pub_r000557_6_2;
  int pub_r000557_7_1;
  int pub_r000557_7_2;
  int pub_r000557_8_1;
  int pub_r000557_8_2;
  int pub_r000557_9_1;
  int pub_r000557_9_2;
  int pub_r000557_10_1;
  int pub_r000557_10_2;
  int pub_r000557_11_1;
  int pub_r000557_11_2;
  int pub_r000557_12_1;
  int pub_r000557_12_2;
  int pub_r000557_13_1;
  int pub_r000557_13_2;
  int pub_r000557_14_1;
  int pub_r000557_14_2;
  int pub_r000557_15_1;
  int pub_r000557_15_2;
  int pub_r000557_16_1;
  int pub_r000557_16_2;
  int pub_r000557_17_1;
  int pub_r000557_17_2;
  int pub_r000557_18_1;
  int pub_r000557_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000557_0_1 >= (-100)) && (pub_r000557_0_1 <= 100));
  __CPROVER_assume((pub_r000557_0_2 >= (-100)) && (pub_r000557_0_2 <= 100));
  __CPROVER_assume((pub_r000557_1_1 >= (-100)) && (pub_r000557_1_1 <= 100));
  __CPROVER_assume((pub_r000557_1_2 >= (-100)) && (pub_r000557_1_2 <= 100));
  __CPROVER_assume((pub_r000557_2_1 >= (-100)) && (pub_r000557_2_1 <= 100));
  __CPROVER_assume((pub_r000557_2_2 >= (-100)) && (pub_r000557_2_2 <= 100));
  __CPROVER_assume((pub_r000557_3_1 >= (-100)) && (pub_r000557_3_1 <= 100));
  __CPROVER_assume((pub_r000557_3_2 >= (-100)) && (pub_r000557_3_2 <= 100));
  __CPROVER_assume((pub_r000557_4_1 >= (-100)) && (pub_r000557_4_1 <= 100));
  __CPROVER_assume((pub_r000557_4_2 >= (-100)) && (pub_r000557_4_2 <= 100));
  __CPROVER_assume((pub_r000557_5_1 >= (-100)) && (pub_r000557_5_1 <= 100));
  __CPROVER_assume((pub_r000557_5_2 >= (-100)) && (pub_r000557_5_2 <= 100));
  __CPROVER_assume((pub_r000557_6_1 >= (-100)) && (pub_r000557_6_1 <= 100));
  __CPROVER_assume((pub_r000557_6_2 >= (-100)) && (pub_r000557_6_2 <= 100));
  __CPROVER_assume((pub_r000557_7_1 >= (-100)) && (pub_r000557_7_1 <= 100));
  __CPROVER_assume((pub_r000557_7_2 >= (-100)) && (pub_r000557_7_2 <= 100));
  __CPROVER_assume((pub_r000557_8_1 >= (-100)) && (pub_r000557_8_1 <= 100));
  __CPROVER_assume((pub_r000557_8_2 >= (-100)) && (pub_r000557_8_2 <= 100));
  __CPROVER_assume((pub_r000557_9_1 >= (-100)) && (pub_r000557_9_1 <= 100));
  __CPROVER_assume((pub_r000557_9_2 >= (-100)) && (pub_r000557_9_2 <= 100));
  __CPROVER_assume((pub_r000557_10_1 >= (-100)) && (pub_r000557_10_1 <= 100));
  __CPROVER_assume((pub_r000557_10_2 >= (-100)) && (pub_r000557_10_2 <= 100));
  __CPROVER_assume((pub_r000557_11_1 >= (-100)) && (pub_r000557_11_1 <= 100));
  __CPROVER_assume((pub_r000557_11_2 >= (-100)) && (pub_r000557_11_2 <= 100));
  __CPROVER_assume((pub_r000557_12_1 >= (-100)) && (pub_r000557_12_1 <= 100));
  __CPROVER_assume((pub_r000557_12_2 >= (-100)) && (pub_r000557_12_2 <= 100));
  __CPROVER_assume((pub_r000557_13_1 >= (-100)) && (pub_r000557_13_1 <= 100));
  __CPROVER_assume((pub_r000557_13_2 >= (-100)) && (pub_r000557_13_2 <= 100));
  __CPROVER_assume((pub_r000557_14_1 >= (-100)) && (pub_r000557_14_1 <= 100));
  __CPROVER_assume((pub_r000557_14_2 >= (-100)) && (pub_r000557_14_2 <= 100));
  __CPROVER_assume((pub_r000557_15_1 >= (-100)) && (pub_r000557_15_1 <= 100));
  __CPROVER_assume((pub_r000557_15_2 >= (-100)) && (pub_r000557_15_2 <= 100));
  __CPROVER_assume((pub_r000557_16_1 >= (-100)) && (pub_r000557_16_1 <= 100));
  __CPROVER_assume((pub_r000557_16_2 >= (-100)) && (pub_r000557_16_2 <= 100));
  __CPROVER_assume((pub_r000557_17_1 >= (-100)) && (pub_r000557_17_1 <= 100));
  __CPROVER_assume((pub_r000557_17_2 >= (-100)) && (pub_r000557_17_2 <= 100));
  __CPROVER_assume((pub_r000557_18_1 >= (-100)) && (pub_r000557_18_1 <= 100));
  __CPROVER_assume((pub_r000557_18_2 >= (-100)) && (pub_r000557_18_2 <= 100));
  __CPROVER_assume((sec_r000557_0_1 >= 0) && (sec_r000557_0_1 <= 255));
  __CPROVER_assume((sec_r000557_0_2 >= 0) && (sec_r000557_0_2 <= 255));
  __CPROVER_assume((sec_r000557_1_1 >= 0) && (sec_r000557_1_1 <= 255));
  __CPROVER_assume((sec_r000557_1_2 >= 0) && (sec_r000557_1_2 <= 255));
  __CPROVER_assume((sec_r000557_2_1 >= 0) && (sec_r000557_2_1 <= 255));
  __CPROVER_assume((sec_r000557_2_2 >= 0) && (sec_r000557_2_2 <= 255));
  __CPROVER_assume((sec_r000557_3_1 >= 0) && (sec_r000557_3_1 <= 255));
  __CPROVER_assume((sec_r000557_3_2 >= 0) && (sec_r000557_3_2 <= 255));
  __CPROVER_assume((sec_r000557_4_1 >= 0) && (sec_r000557_4_1 <= 255));
  __CPROVER_assume((sec_r000557_4_2 >= 0) && (sec_r000557_4_2 <= 255));
  __CPROVER_assume((sec_r000557_5_1 >= 0) && (sec_r000557_5_1 <= 255));
  __CPROVER_assume((sec_r000557_5_2 >= 0) && (sec_r000557_5_2 <= 255));
  __CPROVER_assume((sec_r000557_6_1 >= 0) && (sec_r000557_6_1 <= 255));
  __CPROVER_assume((sec_r000557_6_2 >= 0) && (sec_r000557_6_2 <= 255));
  __CPROVER_assume((sec_r000557_7_1 >= 0) && (sec_r000557_7_1 <= 255));
  __CPROVER_assume((sec_r000557_7_2 >= 0) && (sec_r000557_7_2 <= 255));
  __CPROVER_assume((sec_r000557_8_1 >= 0) && (sec_r000557_8_1 <= 255));
  __CPROVER_assume((sec_r000557_8_2 >= 0) && (sec_r000557_8_2 <= 255));
  __CPROVER_assume((sec_r000557_9_1 >= 0) && (sec_r000557_9_1 <= 255));
  __CPROVER_assume((sec_r000557_9_2 >= 0) && (sec_r000557_9_2 <= 255));
  __CPROVER_assume((sec_r000557_10_1 >= 0) && (sec_r000557_10_1 <= 255));
  __CPROVER_assume((sec_r000557_10_2 >= 0) && (sec_r000557_10_2 <= 255));
  __CPROVER_assume((sec_r000557_11_1 >= 0) && (sec_r000557_11_1 <= 255));
  __CPROVER_assume((sec_r000557_11_2 >= 0) && (sec_r000557_11_2 <= 255));
  __CPROVER_assume((sec_r000557_12_1 >= 0) && (sec_r000557_12_1 <= 255));
  __CPROVER_assume((sec_r000557_12_2 >= 0) && (sec_r000557_12_2 <= 255));
  __CPROVER_assume((sec_r000557_13_1 >= 0) && (sec_r000557_13_1 <= 255));
  __CPROVER_assume((sec_r000557_13_2 >= 0) && (sec_r000557_13_2 <= 255));
  __CPROVER_assume((sec_r000557_14_1 >= 0) && (sec_r000557_14_1 <= 255));
  __CPROVER_assume((sec_r000557_14_2 >= 0) && (sec_r000557_14_2 <= 255));
  __CPROVER_assume((sec_r000557_15_1 >= 0) && (sec_r000557_15_1 <= 255));
  __CPROVER_assume((sec_r000557_15_2 >= 0) && (sec_r000557_15_2 <= 255));
  __CPROVER_assume((sec_r000557_16_1 >= 0) && (sec_r000557_16_1 <= 255));
  __CPROVER_assume((sec_r000557_16_2 >= 0) && (sec_r000557_16_2 <= 255));
  __CPROVER_assume((sec_r000557_17_1 >= 0) && (sec_r000557_17_1 <= 255));
  __CPROVER_assume((sec_r000557_17_2 >= 0) && (sec_r000557_17_2 <= 255));
  __CPROVER_assume((sec_r000557_18_1 >= 0) && (sec_r000557_18_1 <= 255));
  __CPROVER_assume((sec_r000557_18_2 >= 0) && (sec_r000557_18_2 <= 255));
  __CPROVER_assume((sec_r000557_19_1 >= 0) && (sec_r000557_19_1 <= 255));
  __CPROVER_assume((sec_r000557_19_2 >= 0) && (sec_r000557_19_2 <= 255));
  __CPROVER_assume((sec_r000557_20_1 >= 0) && (sec_r000557_20_1 <= 255));
  __CPROVER_assume((sec_r000557_20_2 >= 0) && (sec_r000557_20_2 <= 255));
  __CPROVER_assume((sec_r000557_21_1 >= 0) && (sec_r000557_21_1 <= 255));
  __CPROVER_assume((sec_r000557_21_2 >= 0) && (sec_r000557_21_2 <= 255));
  struct SensorNode_R000557_5713_0 st_var_0_1 = {0};
  struct SensorNode_R000557_5713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000557_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000557_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000557_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000557_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000557_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000557_0_2 + 7) & 15;
  struct EventLog_R000557_5713_1 st_var_1_1 = {0};
  struct EventLog_R000557_5713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000557_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000557_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000557_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000557_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000557_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000557_0_2 + 9) & 15;
  struct FilterState_R000557_5713_2 st_var_2_1 = {0};
  struct FilterState_R000557_5713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000557_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000557_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000557_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000557_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000557_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000557_0_2 + 11) & 15;
  union PacketPayload_R000557_5713_0 u_var_1;
  union PacketPayload_R000557_5713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 48)
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
  if (stage_v_0_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 48)
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
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
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
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
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
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
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

  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = ((st_var_0_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_0_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 35)
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
  if (stage_v_27_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 35)
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
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
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
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
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
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((sec_r000557_1_1 & 1) != 0)
  {
    if ((sec_r000557_6_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000557_12_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000557_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000557_12_1 + 7) & 127;
  }
  if ((sec_r000557_1_2 & 1) != 0)
  {
    if ((sec_r000557_6_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000557_12_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000557_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000557_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000557_16_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000557_4_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000557_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000557_4_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000557_16_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000557_4_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000557_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000557_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000557_21_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000557_11_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000557_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000557_11_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000557_21_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000557_11_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000557_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000557_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000557_11_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000557_5_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000557_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000557_5_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000557_11_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000557_5_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000557_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000557_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000557_20_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000557_13_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000557_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000557_13_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000557_20_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000557_13_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000557_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000557_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000557_11_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000557_8_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000557_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000557_8_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000557_11_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000557_8_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000557_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000557_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000557_0_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000557_0_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000557_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000557_0_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000557_0_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000557_0_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000557_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000557_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000557_10_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000557_13_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000557_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000557_13_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000557_10_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000557_13_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000557_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000557_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000557_1_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000557_18_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000557_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000557_18_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000557_1_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000557_18_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000557_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000557_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000557_20_1 & 1) != 0)
  {
    if ((sec_r000557_0_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000557_14_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000557_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000557_14_1 + 7) & 127;
  }
  if ((sec_r000557_20_2 & 1) != 0)
  {
    if ((sec_r000557_0_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000557_14_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000557_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000557_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000557_7_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000557_10_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000557_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000557_10_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000557_7_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000557_10_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000557_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000557_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000557_19_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000557_9_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000557_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000557_9_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000557_19_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000557_9_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000557_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000557_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000557_13_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000557_9_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000557_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000557_9_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000557_13_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000557_9_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000557_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000557_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000557_19_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000557_9_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000557_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000557_9_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000557_19_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000557_9_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000557_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000557_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000557_21_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000557_18_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000557_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000557_18_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000557_21_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000557_18_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000557_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000557_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000557_16_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000557_8_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000557_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000557_8_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000557_16_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000557_8_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000557_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000557_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000557_20_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000557_5_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000557_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000557_5_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000557_20_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000557_5_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000557_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000557_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000557_0_1 & 1) != 0)
  {
    if ((sec_r000557_11_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000557_18_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000557_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000557_18_1 + 7) & 127;
  }
  if ((sec_r000557_0_2 & 1) != 0)
  {
    if ((sec_r000557_11_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000557_18_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000557_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000557_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000557_12_1 & 1) != 0)
  {
    if ((sec_r000557_21_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000557_15_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000557_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000557_15_1 + 7) & 127;
  }
  if ((sec_r000557_12_2 & 1) != 0)
  {
    if ((sec_r000557_21_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000557_15_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000557_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000557_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000557_9_1 & 1) != 0)
  {
    if ((sec_r000557_20_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000557_14_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000557_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000557_14_1 + 7) & 127;
  }
  if ((sec_r000557_9_2 & 1) != 0)
  {
    if ((sec_r000557_20_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000557_14_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000557_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000557_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000557_10_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000557_4_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000557_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000557_4_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000557_10_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000557_4_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000557_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000557_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000557_13_1 & 1) != 0)
  {
    if ((sec_r000557_13_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000557_8_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000557_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000557_8_1 + 7) & 127;
  }
  if ((sec_r000557_13_2 & 1) != 0)
  {
    if ((sec_r000557_13_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000557_8_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000557_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000557_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000557_5_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000557_12_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000557_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000557_12_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000557_5_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000557_12_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000557_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000557_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000557_17_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000557_12_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000557_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000557_12_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000557_17_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000557_12_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000557_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000557_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000557_2_1 & 1) != 0)
  {
    if ((sec_r000557_6_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000557_6_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000557_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000557_6_1 + 7) & 127;
  }
  if ((sec_r000557_2_2 & 1) != 0)
  {
    if ((sec_r000557_6_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000557_6_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000557_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000557_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000557_4_1 & 1) != 0)
  {
    if ((sec_r000557_9_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000557_10_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000557_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000557_10_1 + 7) & 127;
  }
  if ((sec_r000557_4_2 & 1) != 0)
  {
    if ((sec_r000557_9_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000557_10_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000557_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000557_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000557_6_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000557_16_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000557_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000557_16_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000557_6_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000557_16_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000557_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000557_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000557_1_1 & 1) != 0)
  {
    if ((sec_r000557_15_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000557_13_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000557_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000557_13_1 + 7) & 127;
  }
  if ((sec_r000557_1_2 & 1) != 0)
  {
    if ((sec_r000557_15_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000557_13_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000557_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000557_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000557_11_1 & 1) != 0)
  {
    if ((sec_r000557_17_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000557_5_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000557_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000557_5_1 + 7) & 127;
  }
  if ((sec_r000557_11_2 & 1) != 0)
  {
    if ((sec_r000557_17_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000557_5_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000557_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000557_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000557_8_1 & 1) != 0)
  {
    if ((sec_r000557_13_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000557_3_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000557_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000557_3_1 + 7) & 127;
  }
  if ((sec_r000557_8_2 & 1) != 0)
  {
    if ((sec_r000557_13_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000557_3_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000557_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000557_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000557_19_1 & 1) != 0)
  {
    if ((sec_r000557_16_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000557_6_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000557_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000557_6_1 + 7) & 127;
  }
  if ((sec_r000557_19_2 & 1) != 0)
  {
    if ((sec_r000557_16_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000557_6_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000557_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000557_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000557_4_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000557_4_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000557_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000557_4_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000557_4_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000557_4_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000557_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000557_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000557_14_1 & 1) != 0)
  {
    if ((sec_r000557_7_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000557_6_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000557_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000557_6_1 + 7) & 127;
  }
  if ((sec_r000557_14_2 & 1) != 0)
  {
    if ((sec_r000557_7_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000557_6_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000557_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000557_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000557_20_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000557_3_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000557_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000557_3_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000557_20_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000557_3_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000557_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000557_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000557_19_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000557_4_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000557_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000557_4_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000557_19_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000557_4_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000557_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000557_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000557_7_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000557_1_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000557_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000557_1_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000557_7_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000557_1_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000557_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000557_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000557_16_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000557_6_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000557_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000557_6_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000557_16_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000557_6_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000557_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000557_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000557_19_1 & 1) != 0)
  {
    if ((sec_r000557_9_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000557_7_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000557_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000557_7_1 + 7) & 127;
  }
  if ((sec_r000557_19_2 & 1) != 0)
  {
    if ((sec_r000557_9_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000557_7_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000557_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000557_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000557_8_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000557_2_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000557_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000557_2_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000557_8_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000557_2_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000557_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000557_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000557_11_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000557_1_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000557_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000557_1_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000557_11_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000557_1_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000557_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000557_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000557_10_1 & 1) != 0)
  {
    if ((sec_r000557_21_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000557_0_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000557_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000557_0_1 + 7) & 127;
  }
  if ((sec_r000557_10_2 & 1) != 0)
  {
    if ((sec_r000557_21_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000557_0_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000557_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000557_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000557_15_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000557_16_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000557_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000557_16_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000557_15_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000557_16_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000557_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000557_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000557_0_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000557_3_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000557_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000557_3_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000557_0_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000557_3_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000557_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000557_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000557_2_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000557_14_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000557_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000557_14_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000557_2_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000557_14_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000557_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000557_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000557_17_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000557_9_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000557_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000557_9_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000557_17_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000557_9_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000557_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000557_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000557_4_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000557_1_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000557_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000557_1_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000557_4_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000557_1_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000557_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000557_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000557_2_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000557_9_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000557_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000557_9_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000557_2_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000557_9_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000557_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000557_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000557_8_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000557_13_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000557_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000557_13_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000557_8_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000557_13_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000557_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000557_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000557_8_1 & 1) != 0)
  {
    if ((sec_r000557_7_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000557_1_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000557_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000557_1_1 + 7) & 127;
  }
  if ((sec_r000557_8_2 & 1) != 0)
  {
    if ((sec_r000557_7_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000557_1_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000557_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000557_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000557_21_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000557_8_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000557_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000557_8_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000557_21_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000557_8_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000557_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000557_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000557_16_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000557_12_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000557_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000557_12_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000557_16_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000557_12_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000557_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000557_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000557_21_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000557_7_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000557_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000557_7_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000557_21_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000557_7_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000557_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000557_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000557_6_1 & 1) != 0)
  {
    if ((sec_r000557_0_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000557_10_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000557_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000557_10_1 + 7) & 127;
  }
  if ((sec_r000557_6_2 & 1) != 0)
  {
    if ((sec_r000557_0_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000557_10_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000557_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000557_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000557_13_1 & 1) != 0)
  {
    if ((sec_r000557_7_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000557_17_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000557_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000557_17_1 + 7) & 127;
  }
  if ((sec_r000557_13_2 & 1) != 0)
  {
    if ((sec_r000557_7_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000557_17_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000557_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000557_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000557_7_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000557_16_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000557_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000557_16_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000557_7_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000557_16_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000557_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000557_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000557_7_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000557_5_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000557_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000557_5_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000557_7_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000557_5_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000557_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000557_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000557_13_1 & 1) != 0)
  {
    if ((sec_r000557_5_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000557_10_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000557_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000557_10_1 + 7) & 127;
  }
  if ((sec_r000557_13_2 & 1) != 0)
  {
    if ((sec_r000557_5_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000557_10_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000557_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000557_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000557_7_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000557_10_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000557_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000557_10_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000557_7_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000557_10_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000557_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000557_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000557_13_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000557_8_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000557_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000557_8_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000557_13_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000557_8_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000557_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000557_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000557_8_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000557_15_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000557_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000557_15_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000557_8_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000557_15_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000557_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000557_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000557_7_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000557_14_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000557_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000557_14_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000557_7_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000557_14_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000557_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000557_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000557_10_1 & 1) != 0)
  {
    if ((sec_r000557_12_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000557_5_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000557_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000557_5_1 + 7) & 127;
  }
  if ((sec_r000557_10_2 & 1) != 0)
  {
    if ((sec_r000557_12_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000557_5_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000557_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000557_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000557_6_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000557_12_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000557_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000557_12_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000557_6_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000557_12_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000557_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000557_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000557_0_1 & 1) != 0)
  {
    if ((sec_r000557_4_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000557_12_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000557_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000557_12_1 + 7) & 127;
  }
  if ((sec_r000557_0_2 & 1) != 0)
  {
    if ((sec_r000557_4_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000557_12_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000557_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000557_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000557_15_1 & 1) != 0)
  {
    if ((sec_r000557_20_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000557_1_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000557_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000557_1_1 + 7) & 127;
  }
  if ((sec_r000557_15_2 & 1) != 0)
  {
    if ((sec_r000557_20_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000557_1_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000557_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000557_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000557_0_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000557_14_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000557_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000557_14_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000557_0_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000557_14_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000557_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000557_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000557_4_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000557_14_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000557_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000557_14_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000557_4_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000557_14_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000557_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000557_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000557_2_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000557_17_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000557_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000557_17_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000557_2_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000557_17_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000557_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000557_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000557_17_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000557_5_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000557_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000557_5_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000557_17_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000557_5_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000557_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000557_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000557_4_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000557_14_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000557_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000557_14_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000557_4_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000557_14_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000557_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000557_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000557_11_1 & 1) != 0)
  {
    if ((sec_r000557_12_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000557_2_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000557_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000557_2_1 + 7) & 127;
  }
  if ((sec_r000557_11_2 & 1) != 0)
  {
    if ((sec_r000557_12_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000557_2_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000557_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000557_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000557_2_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000557_0_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000557_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000557_0_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000557_2_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000557_0_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000557_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000557_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000557_0_1 & 1) != 0)
  {
    if ((sec_r000557_17_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000557_6_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000557_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000557_6_1 + 7) & 127;
  }
  if ((sec_r000557_0_2 & 1) != 0)
  {
    if ((sec_r000557_17_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000557_6_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000557_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000557_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000557_20_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000557_17_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000557_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000557_17_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000557_20_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000557_17_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000557_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000557_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000557_16_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000557_18_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000557_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000557_18_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000557_16_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000557_18_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000557_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000557_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000557_15_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000557_3_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000557_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000557_3_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000557_15_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000557_3_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000557_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000557_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000557_14_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000557_8_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000557_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000557_8_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000557_14_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000557_8_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000557_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000557_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000557_21_1 & 1) != 0)
  {
    if ((sec_r000557_16_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000557_14_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000557_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000557_14_1 + 7) & 127;
  }
  if ((sec_r000557_21_2 & 1) != 0)
  {
    if ((sec_r000557_16_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000557_14_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000557_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000557_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000557_12_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000557_16_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000557_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000557_16_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000557_12_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000557_16_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000557_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000557_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000557_5_1 & 1) != 0)
  {
    if ((sec_r000557_8_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000557_15_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000557_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000557_15_1 + 7) & 127;
  }
  if ((sec_r000557_5_2 & 1) != 0)
  {
    if ((sec_r000557_8_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000557_15_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000557_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000557_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000557_8_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000557_5_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000557_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000557_5_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000557_8_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000557_5_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000557_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000557_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000557_2_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000557_7_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000557_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000557_7_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000557_2_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000557_7_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000557_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000557_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000557_13_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000557_3_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000557_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000557_3_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000557_13_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000557_3_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000557_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000557_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000557_14_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000557_9_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000557_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000557_9_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000557_14_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000557_9_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000557_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000557_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000557_2_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000557_18_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000557_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000557_18_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000557_2_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000557_18_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000557_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000557_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000557_11_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000557_12_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000557_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000557_12_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000557_11_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000557_12_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000557_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000557_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000557_10_1 & 1) != 0)
  {
    if ((sec_r000557_12_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000557_4_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000557_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000557_4_1 + 7) & 127;
  }
  if ((sec_r000557_10_2 & 1) != 0)
  {
    if ((sec_r000557_12_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000557_4_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000557_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000557_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000557_21_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000557_12_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000557_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000557_12_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000557_21_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000557_12_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000557_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000557_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000557_16_1 & 1) != 0)
  {
    if ((sec_r000557_13_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000557_5_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000557_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000557_5_1 + 7) & 127;
  }
  if ((sec_r000557_16_2 & 1) != 0)
  {
    if ((sec_r000557_13_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000557_5_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000557_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000557_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000557_19_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000557_15_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000557_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000557_15_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000557_19_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000557_15_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000557_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000557_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000557_5_1 & 1) != 0)
  {
    if ((sec_r000557_12_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000557_3_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000557_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000557_3_1 + 7) & 127;
  }
  if ((sec_r000557_5_2 & 1) != 0)
  {
    if ((sec_r000557_12_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000557_3_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000557_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000557_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000557_12_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000557_18_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000557_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000557_18_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000557_12_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000557_18_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000557_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000557_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000557_10_1 & 1) != 0)
  {
    if ((sec_r000557_9_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000557_3_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000557_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000557_3_1 + 7) & 127;
  }
  if ((sec_r000557_10_2 & 1) != 0)
  {
    if ((sec_r000557_9_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000557_3_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000557_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000557_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000557_21_1 & 1) != 0)
  {
    if ((sec_r000557_20_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000557_15_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000557_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000557_15_1 + 7) & 127;
  }
  if ((sec_r000557_21_2 & 1) != 0)
  {
    if ((sec_r000557_20_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000557_15_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000557_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000557_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000557_13_1 & 1) != 0)
  {
    if ((sec_r000557_16_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000557_12_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000557_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000557_12_1 + 7) & 127;
  }
  if ((sec_r000557_13_2 & 1) != 0)
  {
    if ((sec_r000557_16_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000557_12_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000557_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000557_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000557_9_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000557_15_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000557_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000557_15_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000557_9_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000557_15_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000557_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000557_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000557_8_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000557_18_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000557_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000557_18_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000557_8_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000557_18_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000557_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000557_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000557_1_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000557_7_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000557_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000557_7_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000557_1_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000557_7_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000557_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000557_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000557_0_1 & 1) != 0)
  {
    if ((sec_r000557_14_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000557_10_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000557_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000557_10_1 + 7) & 127;
  }
  if ((sec_r000557_0_2 & 1) != 0)
  {
    if ((sec_r000557_14_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000557_10_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000557_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000557_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000557_1_1 != sec_r000557_1_2);
  __CPROVER_assume(pub_r000557_0_1 == pub_r000557_0_2);
  __CPROVER_assume(sec_r000557_3_1 != sec_r000557_3_2);
  __CPROVER_assume(pub_r000557_17_1 == pub_r000557_17_2);
  __CPROVER_assume(pub_r000557_5_1 == pub_r000557_5_2);
  __CPROVER_assume(sec_r000557_17_1 != sec_r000557_17_2);
  __CPROVER_assume(sec_r000557_11_1 != sec_r000557_11_2);
  __CPROVER_assume(sec_r000557_10_1 != sec_r000557_10_2);
  __CPROVER_assume(sec_r000557_14_1 != sec_r000557_14_2);
  __CPROVER_assume(pub_r000557_2_1 == pub_r000557_2_2);
  __CPROVER_assume(sec_r000557_0_1 != sec_r000557_0_2);
  __CPROVER_assume(pub_r000557_9_1 == pub_r000557_9_2);
  __CPROVER_assume(sec_r000557_2_1 != sec_r000557_2_2);
  __CPROVER_assume(pub_r000557_13_1 == pub_r000557_13_2);
  __CPROVER_assume(pub_r000557_16_1 == pub_r000557_16_2);
  __CPROVER_assume(pub_r000557_18_1 == pub_r000557_18_2);
  __CPROVER_assume(sec_r000557_7_1 != sec_r000557_7_2);
  __CPROVER_assume(sec_r000557_16_1 != sec_r000557_16_2);
  __CPROVER_assume(sec_r000557_18_1 != sec_r000557_18_2);
  __CPROVER_assume(sec_r000557_4_1 != sec_r000557_4_2);
  __CPROVER_assume(sec_r000557_20_1 != sec_r000557_20_2);
  __CPROVER_assume(sec_r000557_12_1 != sec_r000557_12_2);
  __CPROVER_assume(pub_r000557_6_1 == pub_r000557_6_2);
  __CPROVER_assume(pub_r000557_11_1 == pub_r000557_11_2);
  __CPROVER_assume(pub_r000557_12_1 == pub_r000557_12_2);
  __CPROVER_assume(sec_r000557_15_1 != sec_r000557_15_2);
  __CPROVER_assume(sec_r000557_13_1 != sec_r000557_13_2);
  __CPROVER_assume(sec_r000557_21_1 != sec_r000557_21_2);
  __CPROVER_assume(pub_r000557_4_1 == pub_r000557_4_2);
  __CPROVER_assume(pub_r000557_10_1 == pub_r000557_10_2);
  __CPROVER_assume(pub_r000557_1_1 == pub_r000557_1_2);
  __CPROVER_assume(pub_r000557_3_1 == pub_r000557_3_2);
  __CPROVER_assume(pub_r000557_15_1 == pub_r000557_15_2);
  __CPROVER_assume(sec_r000557_5_1 != sec_r000557_5_2);
  __CPROVER_assume(sec_r000557_9_1 != sec_r000557_9_2);
  __CPROVER_assume(pub_r000557_7_1 == pub_r000557_7_2);
  __CPROVER_assume(pub_r000557_14_1 == pub_r000557_14_2);
  __CPROVER_assume(sec_r000557_6_1 != sec_r000557_6_2);
  __CPROVER_assume(pub_r000557_8_1 == pub_r000557_8_2);
  __CPROVER_assume(sec_r000557_19_1 != sec_r000557_19_2);
  __CPROVER_assume(sec_r000557_8_1 != sec_r000557_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
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
}


