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
struct CipherContext_R001515_1513_0
{
  unsigned char counter;
  int round_key;
  int tag;
  int iv;
  int flags;
  int buffer[3];
};
struct SensorNode_R001515_1513_1
{
  unsigned char status;
  short threshold;
  unsigned char reading;
  int calib;
  int buffer[3];
};
struct EventLog_R001515_1513_2
{
  int signature;
  short seq;
  unsigned char severity;
  int facility;
  short code;
  int buffer[3];
};
union ColorPixel_R001515_1513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001515_1513_1
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
void fn_R001515_1513_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int threshold_50_1 = 0;
  int threshold_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_50_1 = ((threshold_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_50_2 = ((threshold_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_50_1) & 127;
    acc_2 = (acc_2 + threshold_50_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_56_1 = local_arr_1[aux_1 % 3];
  int phase_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_56_2 * 2)) & 127;
  int phase_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_49_1 > 50)
  {
    acc_1 = ((acc_1 + (phase_49_1 * 2)) + 5) & 127;
    aux_1 ^= phase_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_49_2 > 50)
  {
    acc_2 = ((acc_2 + (phase_49_2 * 2)) + 5) & 127;
    aux_2 ^= phase_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_75_1)
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

  switch (weight_75_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_50_1 == threshold_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_56_1 == phase_56_2);
  assert(phase_49_1 == phase_49_2);
  assert(weight_75_1 == weight_75_2);
}

int fn_R001515_1513_0(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int threshold_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_50 = ((threshold_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_50) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_56 = local_arr[aux % 3];
  acc = (acc + (phase_56 * 2)) & 127;
  int phase_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_49 > 50)
  {
    acc = ((acc + (phase_49 * 2)) + 5) & 127;
    aux ^= phase_49 & 15;
  }
  else
  {
    acc = ((acc - phase_49) + 11) & 127;
    aux += 3;
  }
  int weight_75 = (aux + st.buffer[1]) & 3;
  switch (weight_75)
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

void fn_R001515_1513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st_1 = {0};
  struct CipherContext_R001515_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int offset_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_98_1 > 45)
  {
    acc_1 = ((acc_1 + (offset_98_1 * 2)) + 5) & 127;
    aux_1 ^= offset_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_98_2 > 45)
  {
    acc_2 = ((acc_2 + (offset_98_2 * 2)) + 5) & 127;
    aux_2 ^= offset_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_98_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_10_1)
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

  switch (quantum_10_2)
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

  int quantum_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_70_1) & 63;
  aux_2 = (aux_2 + quantum_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_98_1 == offset_98_2);
  assert(quantum_10_1 == quantum_10_2);
  assert(quantum_70_1 == quantum_70_2);
}

int fn_R001515_1513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int offset_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_98 > 45)
  {
    acc = ((acc + (offset_98 * 2)) + 5) & 127;
    aux ^= offset_98 & 15;
  }
  else
  {
    acc = ((acc - offset_98) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_10 = (aux + st.buffer[1]) & 3;
  switch (quantum_10)
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

  int quantum_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001515_1513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_67_1 = 0;
  int quotient_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_67_1 = ((quotient_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_67_2 = ((quotient_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_67_1) & 127;
    acc_2 = (acc_2 + quotient_67_2) & 127;
  }

  int parity_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_27_1) & 63;
  aux_2 = (aux_2 + parity_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_67_1 == quotient_67_2);
  assert(parity_27_1 == parity_27_2);
}

int fn_R001515_1513_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_67 = ((quotient_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_67) & 127;
  }

  int parity_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001515_1513_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st_1 = {0};
  struct EventLog_R001515_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_20_1) & 63;
  aux_2 = (aux_2 + tracker_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_20_1 == tracker_20_2);
}

int fn_R001515_1513_3(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_20) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001515_1513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st_1 = {0};
  struct CipherContext_R001515_1513_0 st_2 = {0};
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
  int vector_34_1 = local_arr_1[aux_1 % 3];
  int vector_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_34_1 == vector_34_2);
}

int fn_R001515_1513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_34 = local_arr[aux % 3];
  acc = (acc + (vector_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001515_1513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_84_1 = local_arr_1[aux_1 % 3];
  int weight_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_84_2 * 2)) & 127;
  int parity_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_33_1)
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

  switch (parity_33_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_84_1 == weight_84_2);
  assert(parity_33_1 == parity_33_2);
}

int fn_R001515_1513_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int weight_84 = local_arr[aux % 3];
  acc = (acc + (weight_84 * 2)) & 127;
  int parity_33 = (aux + st.buffer[1]) & 3;
  switch (parity_33)
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

void fn_R001515_1513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st_1 = {0};
  struct EventLog_R001515_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int cursor_74_1 = 0;
  int cursor_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_74_1 = ((cursor_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_74_2 = ((cursor_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_74_1) & 127;
    acc_2 = (acc_2 + cursor_74_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_32_1 > 21)
  {
    acc_1 = ((acc_1 + (delta_32_1 * 2)) + 5) & 127;
    aux_1 ^= delta_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_32_2 > 21)
  {
    acc_2 = ((acc_2 + (delta_32_2 * 2)) + 5) & 127;
    aux_2 ^= delta_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_60_1) & 63;
  aux_2 = (aux_2 + margin_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_74_1 == cursor_74_2);
  assert(delta_32_1 == delta_32_2);
  assert(margin_60_1 == margin_60_2);
}

int fn_R001515_1513_6(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int cursor_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_74 = ((cursor_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_74) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_32 > 21)
  {
    acc = ((acc + (delta_32 * 2)) + 5) & 127;
    aux ^= delta_32 & 15;
  }
  else
  {
    acc = ((acc - delta_32) + 11) & 127;
    aux += 3;
  }
  int margin_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001515_1513_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_41_1 > 39)
  {
    acc_1 = ((acc_1 + (margin_41_1 * 2)) + 5) & 127;
    aux_1 ^= margin_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_41_2 > 39)
  {
    acc_2 = ((acc_2 + (margin_41_2 * 2)) + 5) & 127;
    aux_2 ^= margin_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_68_1 = local_arr_1[aux_1 % 3];
  int metric_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_41_1 == margin_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_68_1 == metric_68_2);
}

int fn_R001515_1513_7(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_41 > 39)
  {
    acc = ((acc + (margin_41 * 2)) + 5) & 127;
    aux ^= margin_41 & 15;
  }
  else
  {
    acc = ((acc - margin_41) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_68 = local_arr[aux % 3];
  acc = (acc + (metric_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001515_1513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st_1 = {0};
  struct EventLog_R001515_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_15_1) & 63;
  aux_2 = (aux_2 + offset_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_16_1 = 0;
  int factor_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_16_1 = ((factor_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_16_2 = ((factor_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_16_1) & 127;
    acc_2 = (acc_2 + factor_16_2) & 127;
  }

  int tally_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_12_1)
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

  switch (tally_12_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_15_1 == offset_15_2);
  assert(factor_16_1 == factor_16_2);
  assert(tally_12_1 == tally_12_2);
}

int fn_R001515_1513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_15) & 63;
  acc ^= aux;
  int factor_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_16 = ((factor_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_16) & 127;
  }

  int tally_12 = (aux + st.buffer[1]) & 3;
  switch (tally_12)
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

void fn_R001515_1513_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int weight_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_54_1) & 63;
  aux_2 = (aux_2 + weight_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_59_1)
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

  switch (checksum_59_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_40_1 = local_arr_1[aux_1 % 3];
  int tally_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_54_1 == weight_54_2);
  assert(checksum_59_1 == checksum_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_40_1 == tally_40_2);
}

int fn_R001515_1513_9(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int weight_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_54) & 63;
  acc ^= aux;
  int checksum_59 = (aux + st.buffer[1]) & 3;
  switch (checksum_59)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_40 = local_arr[aux % 3];
  acc = (acc + (tally_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001515_1513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st_1 = {0};
  struct CipherContext_R001515_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int pivot_12_1 = 0;
  int pivot_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_12_1 = ((pivot_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_12_2 = ((pivot_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_12_1) & 127;
    acc_2 = (acc_2 + pivot_12_2) & 127;
  }

  int bound_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_70_1) & 63;
  aux_2 = (aux_2 + bound_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_38_1 > 13)
  {
    acc_1 = ((acc_1 + (stride_38_1 * 2)) + 5) & 127;
    aux_1 ^= stride_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_38_2 > 13)
  {
    acc_2 = ((acc_2 + (stride_38_2 * 2)) + 5) & 127;
    aux_2 ^= stride_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_19_1)
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

  switch (metric_19_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_12_1 == pivot_12_2);
  assert(bound_70_1 == bound_70_2);
  assert(stride_38_1 == stride_38_2);
  assert(metric_19_1 == metric_19_2);
}

int fn_R001515_1513_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int pivot_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_12 = ((pivot_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_12) & 127;
  }

  int bound_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_70) & 63;
  acc ^= aux;
  int stride_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_38 > 13)
  {
    acc = ((acc + (stride_38 * 2)) + 5) & 127;
    aux ^= stride_38 & 15;
  }
  else
  {
    acc = ((acc - stride_38) + 11) & 127;
    aux += 3;
  }
  int metric_19 = (aux + st.buffer[1]) & 3;
  switch (metric_19)
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

void fn_R001515_1513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int bound_56_1 = 0;
  int bound_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_56_1 = ((bound_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_56_2 = ((bound_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_56_1) & 127;
    acc_2 = (acc_2 + bound_56_2) & 127;
  }

  int mask_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_70_1) & 63;
  aux_2 = (aux_2 + mask_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_56_1 == bound_56_2);
  assert(mask_70_1 == mask_70_2);
}

int fn_R001515_1513_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int bound_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_56 = ((bound_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_56) & 127;
  }

  int mask_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001515_1513_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st_1 = {0};
  struct EventLog_R001515_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int phase_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_27_1) & 63;
  aux_2 = (aux_2 + phase_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_67_1)
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

  switch (margin_67_2)
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
  int coefficient_11_1 = local_arr_1[aux_1 % 3];
  int coefficient_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_27_1 == phase_27_2);
  assert(margin_67_1 == margin_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_11_1 == coefficient_11_2);
}

int fn_R001515_1513_12(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int phase_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_27) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_67 = (aux + st.buffer[1]) & 3;
  switch (margin_67)
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
  int coefficient_11 = local_arr[aux % 3];
  acc = (acc + (coefficient_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001515_1513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st_1 = {0};
  struct EventLog_R001515_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int phase_34_1 = 0;
  int phase_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_34_1 = ((phase_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_34_2 = ((phase_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_34_1) & 127;
    acc_2 = (acc_2 + phase_34_2) & 127;
  }

  int tally_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_19_1) & 63;
  aux_2 = (aux_2 + tally_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_34_1 == phase_34_2);
  assert(tally_19_1 == tally_19_2);
}

int fn_R001515_1513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int phase_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_34 = ((phase_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_34) & 127;
  }

  int tally_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_19) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001515_1513_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_77_1 > 10)
  {
    acc_1 = ((acc_1 + (anchor_77_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_77_2 > 10)
  {
    acc_2 = ((acc_2 + (anchor_77_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_97_1 = local_arr_1[aux_1 % 3];
  int tally_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_97_2 * 2)) & 127;
  int index_reg_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_95_1) & 63;
  aux_2 = (aux_2 + index_reg_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_77_1 == anchor_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_97_1 == tally_97_2);
  assert(index_reg_95_1 == index_reg_95_2);
}

int fn_R001515_1513_14(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_77 > 10)
  {
    acc = ((acc + (anchor_77 * 2)) + 5) & 127;
    aux ^= anchor_77 & 15;
  }
  else
  {
    acc = ((acc - anchor_77) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_97 = local_arr[aux % 3];
  acc = (acc + (tally_97 * 2)) & 127;
  int index_reg_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_95) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001515_1513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st_1 = {0};
  struct CipherContext_R001515_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_55_1 = local_arr_1[aux_1 % 3];
  int cursor_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_55_2 * 2)) & 127;
  int parity_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_28_1)
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

  switch (parity_28_2)
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

  int window_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_63_1) & 63;
  aux_2 = (aux_2 + window_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_47_1 > 12)
  {
    acc_1 = ((acc_1 + (tracker_47_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_47_2 > 12)
  {
    acc_2 = ((acc_2 + (tracker_47_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_47_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_55_1 == cursor_55_2);
  assert(parity_28_1 == parity_28_2);
  assert(window_63_1 == window_63_2);
  assert(tracker_47_1 == tracker_47_2);
}

int fn_R001515_1513_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int cursor_55 = local_arr[aux % 3];
  acc = (acc + (cursor_55 * 2)) & 127;
  int parity_28 = (aux + st.buffer[1]) & 3;
  switch (parity_28)
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

  int window_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_63) & 63;
  acc ^= aux;
  int tracker_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_47 > 12)
  {
    acc = ((acc + (tracker_47 * 2)) + 5) & 127;
    aux ^= tracker_47 & 15;
  }
  else
  {
    acc = ((acc - tracker_47) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001515_1513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st_1 = {0};
  struct CipherContext_R001515_1513_0 st_2 = {0};
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
  int delta_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_93_1)
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

  switch (delta_93_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_93_1 == delta_93_2);
}

int fn_R001515_1513_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001515_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_93 = (aux + st.buffer[1]) & 3;
  switch (delta_93)
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

void fn_R001515_1513_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_96_1 = local_arr_1[aux_1 % 3];
  int offset_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_96_2 * 2)) & 127;
  int coefficient_85_1 = 0;
  int coefficient_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_85_1 = ((coefficient_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_85_2 = ((coefficient_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_85_1) & 127;
    acc_2 = (acc_2 + coefficient_85_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_96_1 == offset_96_2);
  assert(coefficient_85_1 == coefficient_85_2);
}

int fn_R001515_1513_17(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int offset_96 = local_arr[aux % 3];
  acc = (acc + (offset_96 * 2)) & 127;
  int coefficient_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_85 = ((coefficient_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_85) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001515_1513_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int window_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_33_1 > 48)
  {
    acc_1 = ((acc_1 + (window_33_1 * 2)) + 5) & 127;
    aux_1 ^= window_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_33_2 > 48)
  {
    acc_2 = ((acc_2 + (window_33_2 * 2)) + 5) & 127;
    aux_2 ^= window_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_18_1) & 63;
  aux_2 = (aux_2 + threshold_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_33_1 == window_33_2);
  assert(threshold_18_1 == threshold_18_2);
}

int fn_R001515_1513_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int window_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_33 > 48)
  {
    acc = ((acc + (window_33 * 2)) + 5) & 127;
    aux ^= window_33 & 15;
  }
  else
  {
    acc = ((acc - window_33) + 11) & 127;
    aux += 3;
  }
  int threshold_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_18) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001515_1513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_39_1 = 0;
  int delta_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_39_1 = ((delta_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_39_2 = ((delta_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_39_1) & 127;
    acc_2 = (acc_2 + delta_39_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_39_1 == delta_39_2);
}

int fn_R001515_1513_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_39 = ((delta_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_39) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001515_1513_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st_1 = {0};
  struct EventLog_R001515_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int cursor_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_32_1 > 13)
  {
    acc_1 = ((acc_1 + (cursor_32_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_32_2 > 13)
  {
    acc_2 = ((acc_2 + (cursor_32_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_11_1) & 63;
  aux_2 = (aux_2 + margin_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_59_1 = local_arr_1[aux_1 % 3];
  int anchor_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_32_1 == cursor_32_2);
  assert(margin_11_1 == margin_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_59_1 == anchor_59_2);
}

int fn_R001515_1513_20(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int cursor_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_32 > 13)
  {
    acc = ((acc + (cursor_32 * 2)) + 5) & 127;
    aux ^= cursor_32 & 15;
  }
  else
  {
    acc = ((acc - cursor_32) + 11) & 127;
    aux += 3;
  }
  int margin_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_11) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_59 = local_arr[aux % 3];
  acc = (acc + (anchor_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001515_1513_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st_1 = {0};
  struct EventLog_R001515_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int parity_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_26_1 > 16)
  {
    acc_1 = ((acc_1 + (parity_26_1 * 2)) + 5) & 127;
    aux_1 ^= parity_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_26_2 > 16)
  {
    acc_2 = ((acc_2 + (parity_26_2 * 2)) + 5) & 127;
    aux_2 ^= parity_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_45_1)
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

  switch (sample_45_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_26_1 == parity_26_2);
  assert(sample_45_1 == sample_45_2);
}

int fn_R001515_1513_21(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int parity_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_26 > 16)
  {
    acc = ((acc + (parity_26 * 2)) + 5) & 127;
    aux ^= parity_26 & 15;
  }
  else
  {
    acc = ((acc - parity_26) + 11) & 127;
    aux += 3;
  }
  int sample_45 = (aux + st.buffer[1]) & 3;
  switch (sample_45)
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

void fn_R001515_1513_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st_1 = {0};
  struct EventLog_R001515_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tracker_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_76_1)
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

  switch (tracker_76_2)
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

  int damping_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_62_1 > 47)
  {
    acc_1 = ((acc_1 + (damping_62_1 * 2)) + 5) & 127;
    aux_1 ^= damping_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_62_2 > 47)
  {
    acc_2 = ((acc_2 + (damping_62_2 * 2)) + 5) & 127;
    aux_2 ^= damping_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_83_1 = 0;
  int threshold_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_83_1 = ((threshold_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_83_2 = ((threshold_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_83_1) & 127;
    acc_2 = (acc_2 + threshold_83_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_76_1 == tracker_76_2);
  assert(damping_62_1 == damping_62_2);
  assert(threshold_83_1 == threshold_83_2);
}

int fn_R001515_1513_22(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001515_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tracker_76 = (aux + st.buffer[1]) & 3;
  switch (tracker_76)
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

  int damping_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_62 > 47)
  {
    acc = ((acc + (damping_62 * 2)) + 5) & 127;
    aux ^= damping_62 & 15;
  }
  else
  {
    acc = ((acc - damping_62) + 11) & 127;
    aux += 3;
  }
  int threshold_83 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_83 = ((threshold_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_83) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001515_1513_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st_1 = {0};
  struct SensorNode_R001515_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quotient_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_49_1 > 16)
  {
    acc_1 = ((acc_1 + (quotient_49_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_49_2 > 16)
  {
    acc_2 = ((acc_2 + (quotient_49_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_86_1 = 0;
  int sample_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_86_1 = ((sample_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_86_2 = ((sample_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_86_1) & 127;
    acc_2 = (acc_2 + sample_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_49_1 == quotient_49_2);
  assert(sample_86_1 == sample_86_2);
}

int fn_R001515_1513_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001515_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quotient_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_49 > 16)
  {
    acc = ((acc + (quotient_49 * 2)) + 5) & 127;
    aux ^= quotient_49 & 15;
  }
  else
  {
    acc = ((acc - quotient_49) + 11) & 127;
    aux += 3;
  }
  int sample_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_86 = ((sample_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_86) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001515_0_1;
  int sec_r001515_0_2;
  int sec_r001515_1_1;
  int sec_r001515_1_2;
  int sec_r001515_2_1;
  int sec_r001515_2_2;
  int sec_r001515_3_1;
  int sec_r001515_3_2;
  int sec_r001515_4_1;
  int sec_r001515_4_2;
  int sec_r001515_5_1;
  int sec_r001515_5_2;
  int sec_r001515_6_1;
  int sec_r001515_6_2;
  int sec_r001515_7_1;
  int sec_r001515_7_2;
  int sec_r001515_8_1;
  int sec_r001515_8_2;
  int sec_r001515_9_1;
  int sec_r001515_9_2;
  int sec_r001515_10_1;
  int sec_r001515_10_2;
  int sec_r001515_11_1;
  int sec_r001515_11_2;
  int sec_r001515_12_1;
  int sec_r001515_12_2;
  int sec_r001515_13_1;
  int sec_r001515_13_2;
  int sec_r001515_14_1;
  int sec_r001515_14_2;
  int sec_r001515_15_1;
  int sec_r001515_15_2;
  int sec_r001515_16_1;
  int sec_r001515_16_2;
  int sec_r001515_17_1;
  int sec_r001515_17_2;
  int sec_r001515_18_1;
  int sec_r001515_18_2;
  int pub_r001515_0_1;
  int pub_r001515_0_2;
  int pub_r001515_1_1;
  int pub_r001515_1_2;
  int pub_r001515_2_1;
  int pub_r001515_2_2;
  int pub_r001515_3_1;
  int pub_r001515_3_2;
  int pub_r001515_4_1;
  int pub_r001515_4_2;
  int pub_r001515_5_1;
  int pub_r001515_5_2;
  int pub_r001515_6_1;
  int pub_r001515_6_2;
  int pub_r001515_7_1;
  int pub_r001515_7_2;
  int pub_r001515_8_1;
  int pub_r001515_8_2;
  int pub_r001515_9_1;
  int pub_r001515_9_2;
  int pub_r001515_10_1;
  int pub_r001515_10_2;
  int pub_r001515_11_1;
  int pub_r001515_11_2;
  int pub_r001515_12_1;
  int pub_r001515_12_2;
  int pub_r001515_13_1;
  int pub_r001515_13_2;
  int pub_r001515_14_1;
  int pub_r001515_14_2;
  int pub_r001515_15_1;
  int pub_r001515_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001515_0_1 >= (-100)) && (pub_r001515_0_1 <= 100));
  __CPROVER_assume((pub_r001515_0_2 >= (-100)) && (pub_r001515_0_2 <= 100));
  __CPROVER_assume((pub_r001515_1_1 >= (-100)) && (pub_r001515_1_1 <= 100));
  __CPROVER_assume((pub_r001515_1_2 >= (-100)) && (pub_r001515_1_2 <= 100));
  __CPROVER_assume((pub_r001515_2_1 >= (-100)) && (pub_r001515_2_1 <= 100));
  __CPROVER_assume((pub_r001515_2_2 >= (-100)) && (pub_r001515_2_2 <= 100));
  __CPROVER_assume((pub_r001515_3_1 >= (-100)) && (pub_r001515_3_1 <= 100));
  __CPROVER_assume((pub_r001515_3_2 >= (-100)) && (pub_r001515_3_2 <= 100));
  __CPROVER_assume((pub_r001515_4_1 >= (-100)) && (pub_r001515_4_1 <= 100));
  __CPROVER_assume((pub_r001515_4_2 >= (-100)) && (pub_r001515_4_2 <= 100));
  __CPROVER_assume((pub_r001515_5_1 >= (-100)) && (pub_r001515_5_1 <= 100));
  __CPROVER_assume((pub_r001515_5_2 >= (-100)) && (pub_r001515_5_2 <= 100));
  __CPROVER_assume((pub_r001515_6_1 >= (-100)) && (pub_r001515_6_1 <= 100));
  __CPROVER_assume((pub_r001515_6_2 >= (-100)) && (pub_r001515_6_2 <= 100));
  __CPROVER_assume((pub_r001515_7_1 >= (-100)) && (pub_r001515_7_1 <= 100));
  __CPROVER_assume((pub_r001515_7_2 >= (-100)) && (pub_r001515_7_2 <= 100));
  __CPROVER_assume((pub_r001515_8_1 >= (-100)) && (pub_r001515_8_1 <= 100));
  __CPROVER_assume((pub_r001515_8_2 >= (-100)) && (pub_r001515_8_2 <= 100));
  __CPROVER_assume((pub_r001515_9_1 >= (-100)) && (pub_r001515_9_1 <= 100));
  __CPROVER_assume((pub_r001515_9_2 >= (-100)) && (pub_r001515_9_2 <= 100));
  __CPROVER_assume((pub_r001515_10_1 >= (-100)) && (pub_r001515_10_1 <= 100));
  __CPROVER_assume((pub_r001515_10_2 >= (-100)) && (pub_r001515_10_2 <= 100));
  __CPROVER_assume((pub_r001515_11_1 >= (-100)) && (pub_r001515_11_1 <= 100));
  __CPROVER_assume((pub_r001515_11_2 >= (-100)) && (pub_r001515_11_2 <= 100));
  __CPROVER_assume((pub_r001515_12_1 >= (-100)) && (pub_r001515_12_1 <= 100));
  __CPROVER_assume((pub_r001515_12_2 >= (-100)) && (pub_r001515_12_2 <= 100));
  __CPROVER_assume((pub_r001515_13_1 >= (-100)) && (pub_r001515_13_1 <= 100));
  __CPROVER_assume((pub_r001515_13_2 >= (-100)) && (pub_r001515_13_2 <= 100));
  __CPROVER_assume((pub_r001515_14_1 >= (-100)) && (pub_r001515_14_1 <= 100));
  __CPROVER_assume((pub_r001515_14_2 >= (-100)) && (pub_r001515_14_2 <= 100));
  __CPROVER_assume((pub_r001515_15_1 >= (-100)) && (pub_r001515_15_1 <= 100));
  __CPROVER_assume((pub_r001515_15_2 >= (-100)) && (pub_r001515_15_2 <= 100));
  __CPROVER_assume((sec_r001515_0_1 >= 0) && (sec_r001515_0_1 <= 255));
  __CPROVER_assume((sec_r001515_0_2 >= 0) && (sec_r001515_0_2 <= 255));
  __CPROVER_assume((sec_r001515_1_1 >= 0) && (sec_r001515_1_1 <= 255));
  __CPROVER_assume((sec_r001515_1_2 >= 0) && (sec_r001515_1_2 <= 255));
  __CPROVER_assume((sec_r001515_2_1 >= 0) && (sec_r001515_2_1 <= 255));
  __CPROVER_assume((sec_r001515_2_2 >= 0) && (sec_r001515_2_2 <= 255));
  __CPROVER_assume((sec_r001515_3_1 >= 0) && (sec_r001515_3_1 <= 255));
  __CPROVER_assume((sec_r001515_3_2 >= 0) && (sec_r001515_3_2 <= 255));
  __CPROVER_assume((sec_r001515_4_1 >= 0) && (sec_r001515_4_1 <= 255));
  __CPROVER_assume((sec_r001515_4_2 >= 0) && (sec_r001515_4_2 <= 255));
  __CPROVER_assume((sec_r001515_5_1 >= 0) && (sec_r001515_5_1 <= 255));
  __CPROVER_assume((sec_r001515_5_2 >= 0) && (sec_r001515_5_2 <= 255));
  __CPROVER_assume((sec_r001515_6_1 >= 0) && (sec_r001515_6_1 <= 255));
  __CPROVER_assume((sec_r001515_6_2 >= 0) && (sec_r001515_6_2 <= 255));
  __CPROVER_assume((sec_r001515_7_1 >= 0) && (sec_r001515_7_1 <= 255));
  __CPROVER_assume((sec_r001515_7_2 >= 0) && (sec_r001515_7_2 <= 255));
  __CPROVER_assume((sec_r001515_8_1 >= 0) && (sec_r001515_8_1 <= 255));
  __CPROVER_assume((sec_r001515_8_2 >= 0) && (sec_r001515_8_2 <= 255));
  __CPROVER_assume((sec_r001515_9_1 >= 0) && (sec_r001515_9_1 <= 255));
  __CPROVER_assume((sec_r001515_9_2 >= 0) && (sec_r001515_9_2 <= 255));
  __CPROVER_assume((sec_r001515_10_1 >= 0) && (sec_r001515_10_1 <= 255));
  __CPROVER_assume((sec_r001515_10_2 >= 0) && (sec_r001515_10_2 <= 255));
  __CPROVER_assume((sec_r001515_11_1 >= 0) && (sec_r001515_11_1 <= 255));
  __CPROVER_assume((sec_r001515_11_2 >= 0) && (sec_r001515_11_2 <= 255));
  __CPROVER_assume((sec_r001515_12_1 >= 0) && (sec_r001515_12_1 <= 255));
  __CPROVER_assume((sec_r001515_12_2 >= 0) && (sec_r001515_12_2 <= 255));
  __CPROVER_assume((sec_r001515_13_1 >= 0) && (sec_r001515_13_1 <= 255));
  __CPROVER_assume((sec_r001515_13_2 >= 0) && (sec_r001515_13_2 <= 255));
  __CPROVER_assume((sec_r001515_14_1 >= 0) && (sec_r001515_14_1 <= 255));
  __CPROVER_assume((sec_r001515_14_2 >= 0) && (sec_r001515_14_2 <= 255));
  __CPROVER_assume((sec_r001515_15_1 >= 0) && (sec_r001515_15_1 <= 255));
  __CPROVER_assume((sec_r001515_15_2 >= 0) && (sec_r001515_15_2 <= 255));
  __CPROVER_assume((sec_r001515_16_1 >= 0) && (sec_r001515_16_1 <= 255));
  __CPROVER_assume((sec_r001515_16_2 >= 0) && (sec_r001515_16_2 <= 255));
  __CPROVER_assume((sec_r001515_17_1 >= 0) && (sec_r001515_17_1 <= 255));
  __CPROVER_assume((sec_r001515_17_2 >= 0) && (sec_r001515_17_2 <= 255));
  __CPROVER_assume((sec_r001515_18_1 >= 0) && (sec_r001515_18_1 <= 255));
  __CPROVER_assume((sec_r001515_18_2 >= 0) && (sec_r001515_18_2 <= 255));
  struct CipherContext_R001515_1513_0 st_var_0_1 = {0};
  struct CipherContext_R001515_1513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001515_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001515_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001515_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001515_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001515_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001515_0_2 + 7) & 15;
  struct SensorNode_R001515_1513_1 st_var_1_1 = {0};
  struct SensorNode_R001515_1513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001515_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001515_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001515_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001515_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001515_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001515_0_2 + 9) & 15;
  struct EventLog_R001515_1513_2 st_var_2_1 = {0};
  struct EventLog_R001515_1513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001515_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001515_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001515_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001515_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001515_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001515_0_2 + 11) & 15;
  union ColorPixel_R001515_1513_0 u_var_1;
  union ColorPixel_R001515_1513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001515_1513_0(sec_r001515_0_1, sec_r001515_1_1);
  int helper_flow_0_2 = fn_R001515_1513_0(sec_r001515_0_2, sec_r001515_1_2);
  fn_R001515_1513_0_2(sec_r001515_0_1, sec_r001515_1_1, sec_r001515_0_2, sec_r001515_1_2);
  int helper_flow_1_1 = fn_R001515_1513_1(sec_r001515_1_1, pub_r001515_2_1, pub_r001515_3_1);
  int helper_flow_1_2 = fn_R001515_1513_1(sec_r001515_1_2, pub_r001515_2_2, pub_r001515_3_2);
  fn_R001515_1513_1_2(sec_r001515_1_1, pub_r001515_2_1, pub_r001515_3_1, sec_r001515_1_2, pub_r001515_2_2, pub_r001515_3_2);
  int helper_flow_2_1 = fn_R001515_1513_2(sec_r001515_2_1, sec_r001515_3_1, pub_r001515_4_1, pub_r001515_5_1);
  int helper_flow_2_2 = fn_R001515_1513_2(sec_r001515_2_2, sec_r001515_3_2, pub_r001515_4_2, pub_r001515_5_2);
  fn_R001515_1513_2_2(sec_r001515_2_1, sec_r001515_3_1, pub_r001515_4_1, pub_r001515_5_1, sec_r001515_2_2, sec_r001515_3_2, pub_r001515_4_2, pub_r001515_5_2);
  int helper_flow_3_1 = fn_R001515_1513_3(sec_r001515_3_1, sec_r001515_4_1, pub_r001515_5_1);
  int helper_flow_3_2 = fn_R001515_1513_3(sec_r001515_3_2, sec_r001515_4_2, pub_r001515_5_2);
  fn_R001515_1513_3_2(sec_r001515_3_1, sec_r001515_4_1, pub_r001515_5_1, sec_r001515_3_2, sec_r001515_4_2, pub_r001515_5_2);
  int helper_flow_4_1 = fn_R001515_1513_4(sec_r001515_4_1, pub_r001515_5_1, pub_r001515_6_1, pub_r001515_7_1, pub_r001515_8_1);
  int helper_flow_4_2 = fn_R001515_1513_4(sec_r001515_4_2, pub_r001515_5_2, pub_r001515_6_2, pub_r001515_7_2, pub_r001515_8_2);
  fn_R001515_1513_4_2(sec_r001515_4_1, pub_r001515_5_1, pub_r001515_6_1, pub_r001515_7_1, pub_r001515_8_1, sec_r001515_4_2, pub_r001515_5_2, pub_r001515_6_2, pub_r001515_7_2, pub_r001515_8_2);
  int helper_flow_5_1 = fn_R001515_1513_5(sec_r001515_5_1, sec_r001515_6_1, pub_r001515_7_1, pub_r001515_8_1);
  int helper_flow_5_2 = fn_R001515_1513_5(sec_r001515_5_2, sec_r001515_6_2, pub_r001515_7_2, pub_r001515_8_2);
  fn_R001515_1513_5_2(sec_r001515_5_1, sec_r001515_6_1, pub_r001515_7_1, pub_r001515_8_1, sec_r001515_5_2, sec_r001515_6_2, pub_r001515_7_2, pub_r001515_8_2);
  int helper_flow_6_1 = fn_R001515_1513_6(sec_r001515_6_1, sec_r001515_7_1);
  int helper_flow_6_2 = fn_R001515_1513_6(sec_r001515_6_2, sec_r001515_7_2);
  fn_R001515_1513_6_2(sec_r001515_6_1, sec_r001515_7_1, sec_r001515_6_2, sec_r001515_7_2);
  int helper_flow_7_1 = fn_R001515_1513_7(sec_r001515_7_1, sec_r001515_8_1, pub_r001515_9_1);
  int helper_flow_7_2 = fn_R001515_1513_7(sec_r001515_7_2, sec_r001515_8_2, pub_r001515_9_2);
  fn_R001515_1513_7_2(sec_r001515_7_1, sec_r001515_8_1, pub_r001515_9_1, sec_r001515_7_2, sec_r001515_8_2, pub_r001515_9_2);
  int stage_v_0_1 = ((sec_r001515_9_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001515_9_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((sec_r001515_16_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_1_2 = ((sec_r001515_16_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((sec_r001515_6_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_2_2 = ((sec_r001515_6_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((pub_r001515_6_1 * 2) + 17) & 63;
  int stage_v_3_2 = ((pub_r001515_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001515_14_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_4_2 = ((sec_r001515_14_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((pub_r001515_11_1 * 2) + 9) & 63;
  int stage_v_5_2 = ((pub_r001515_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((helper_flow_7_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_6_2 = ((helper_flow_7_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((pub_r001515_1_1 * 2) + 45) & 63;
  int stage_v_7_2 = ((pub_r001515_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001515_6_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_8_2 = ((sec_r001515_6_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((sec_r001515_12_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_9_2 = ((sec_r001515_12_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((helper_flow_3_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_10_2 = ((helper_flow_3_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((sec_r001515_15_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_11_2 = ((sec_r001515_15_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((pub_r001515_2_1 * 2) + 25) & 63;
  int stage_v_12_2 = ((pub_r001515_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001515_13_1 * 2) + 31) & 63;
  int stage_v_13_2 = ((pub_r001515_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001515_8_1 * 2) + 34) & 63;
  int stage_v_14_2 = ((pub_r001515_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((sec_r001515_9_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_15_2 = ((sec_r001515_9_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((stage_v_2_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_16_2 = ((stage_v_2_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_16_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_16_2 + 1) & 15;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = ((stage_v_16_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_17_2 = ((stage_v_16_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_17_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_17_2 + 1) & 15;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = ((stage_v_2_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_18_2 = ((stage_v_2_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((sec_r001515_15_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_19_2 = ((sec_r001515_15_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((stage_v_6_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_20_2 = ((stage_v_6_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((stage_v_1_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_21_2 = ((stage_v_1_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_21_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_21_2 + 1) & 15;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = ((pub_r001515_0_1 * 2) + 11) & 63;
  int stage_v_22_2 = ((pub_r001515_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((stage_v_4_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_23_2 = ((stage_v_4_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((helper_flow_1_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_24_2 = ((helper_flow_1_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((stage_v_1_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_25_2 = ((stage_v_1_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((helper_flow_1_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_26_2 = ((helper_flow_1_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_26_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_26_2 + 1) & 15;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = ((stage_v_10_1 << 1) ^ (pub_r001515_2_1 >> 1)) & 127;
  int stage_v_27_2 = ((stage_v_10_2 << 1) ^ (pub_r001515_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((pub_r001515_5_1 * 2) + 5) & 63;
  int stage_v_28_2 = ((pub_r001515_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001515_6_1 * 2) + 23) & 63;
  int stage_v_29_2 = ((pub_r001515_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001515_6_1 * 2) + 40) & 63;
  int stage_v_30_2 = ((pub_r001515_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001515_11_1 * 2) + 13) & 63;
  int stage_v_31_2 = ((pub_r001515_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((stage_v_16_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_32_2 = ((stage_v_16_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((pub_r001515_15_1 * 2) + 43) & 63;
  int stage_v_33_2 = ((pub_r001515_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001515_14_1 * 2) + 17) & 63;
  int stage_v_34_2 = ((pub_r001515_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001515_4_1 * 2) + 29) & 63;
  int stage_v_35_2 = ((pub_r001515_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((stage_v_4_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_36_2 = ((stage_v_4_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((stage_v_4_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_37_2 = ((stage_v_4_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_37_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_37_2 + 1) & 15;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = ((helper_flow_6_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_38_2 = ((helper_flow_6_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((stage_v_4_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_4_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((pub_r001515_7_1 * 2) + 34) & 63;
  int stage_v_40_2 = ((pub_r001515_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((stage_v_37_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_41_2 = ((stage_v_37_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((stage_v_24_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_42_2 = ((stage_v_24_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((stage_v_21_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_43_2 = ((stage_v_21_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((pub_r001515_9_1 * 2) + 12) & 63;
  int stage_v_44_2 = ((pub_r001515_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((stage_v_8_1 << 1) ^ (pub_r001515_15_1 >> 1)) & 127;
  int stage_v_45_2 = ((stage_v_8_2 << 1) ^ (pub_r001515_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_45_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_45_2 + 1) & 15;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = ((helper_flow_3_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_46_2 = ((helper_flow_3_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((helper_flow_6_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_47_2 = ((helper_flow_6_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_47_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_47_2 + 1) & 15;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = ((helper_flow_0_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_48_2 = ((helper_flow_0_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_48_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_48_2 + 1) & 15;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = ((helper_flow_7_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_49_2 = ((helper_flow_7_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((stage_v_9_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_50_2 = ((stage_v_9_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_50_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_50_2 + 1) & 15;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = ((stage_v_45_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_51_2 = ((stage_v_45_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_51_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_51_2 + 1) & 15;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = ((sec_r001515_15_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_52_2 = ((sec_r001515_15_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((pub_r001515_2_1 * 2) + 13) & 63;
  int stage_v_53_2 = ((pub_r001515_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001515_0_1 * 2) + 32) & 63;
  int stage_v_54_2 = ((pub_r001515_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001515_15_1 * 2) + 48) & 63;
  int stage_v_55_2 = ((pub_r001515_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((sec_r001515_12_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_56_2 = ((sec_r001515_12_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((stage_v_36_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_57_2 = ((stage_v_36_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((pub_r001515_12_1 * 2) + 46) & 63;
  int stage_v_58_2 = ((pub_r001515_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((sec_r001515_3_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_59_2 = ((sec_r001515_3_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((stage_v_51_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_60_2 = ((stage_v_51_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((stage_v_18_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_61_2 = ((stage_v_18_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((pub_r001515_4_1 * 2) + 26) & 63;
  int stage_v_62_2 = ((pub_r001515_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((stage_v_25_1 << 1) ^ (pub_r001515_2_1 >> 1)) & 127;
  int stage_v_63_2 = ((stage_v_25_2 << 1) ^ (pub_r001515_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((sec_r001515_10_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_64_2 = ((sec_r001515_10_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_64_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_64_2 + 1) & 15;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = ((stage_v_6_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_65_2 = ((stage_v_6_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((pub_r001515_1_1 * 2) + 47) & 63;
  int stage_v_66_2 = ((pub_r001515_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((sec_r001515_12_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_67_2 = ((sec_r001515_12_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((stage_v_52_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_68_2 = ((stage_v_52_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_68_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_68_2 + 1) & 15;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = ((sec_r001515_12_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_69_2 = ((sec_r001515_12_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((pub_r001515_2_1 * 2) + 31) & 63;
  int stage_v_70_2 = ((pub_r001515_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001515_3_1 * 2) + 31) & 63;
  int stage_v_71_2 = ((pub_r001515_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((sec_r001515_10_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_72_2 = ((sec_r001515_10_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((pub_r001515_15_1 * 2) + 49) & 63;
  int stage_v_73_2 = ((pub_r001515_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((stage_v_19_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_74_2 = ((stage_v_19_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_74_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_74_2 + 1) & 15;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = ((pub_r001515_3_1 * 2) + 45) & 63;
  int stage_v_75_2 = ((pub_r001515_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001515_10_1 * 2) + 43) & 63;
  int stage_v_76_2 = ((pub_r001515_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((stage_v_59_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_77_2 = ((stage_v_59_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((stage_v_23_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_78_2 = ((stage_v_23_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_78_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_78_2 + 1) & 15;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = ((pub_r001515_2_1 * 2) + 9) & 63;
  int stage_v_79_2 = ((pub_r001515_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001515_2_1 * 2) + 5) & 63;
  int stage_v_80_2 = ((pub_r001515_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((stage_v_20_1 << 1) ^ (pub_r001515_15_1 >> 1)) & 127;
  int stage_v_81_2 = ((stage_v_20_2 << 1) ^ (pub_r001515_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((pub_r001515_15_1 * 2) + 40) & 63;
  int stage_v_82_2 = ((pub_r001515_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001515_12_1 * 2) + 22) & 63;
  int stage_v_83_2 = ((pub_r001515_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001515_7_1 * 2) + 28) & 63;
  int stage_v_84_2 = ((pub_r001515_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((sec_r001515_16_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_85_2 = ((sec_r001515_16_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_85_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_85_2 + 1) & 15;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = ((stage_v_78_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_86_2 = ((stage_v_78_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((pub_r001515_11_1 * 2) + 8) & 63;
  int stage_v_87_2 = ((pub_r001515_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((stage_v_1_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_88_2 = ((stage_v_1_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_88_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_88_2 + 1) & 15;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = ((stage_v_67_1 << 1) ^ (pub_r001515_14_1 >> 1)) & 127;
  int stage_v_89_2 = ((stage_v_67_2 << 1) ^ (pub_r001515_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((stage_v_86_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_90_2 = ((stage_v_86_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_90_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_90_2 + 1) & 15;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = ((stage_v_41_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_91_2 = ((stage_v_41_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_91_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_91_2 + 1) & 15;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = ((helper_flow_7_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_92_2 = ((helper_flow_7_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((pub_r001515_5_1 * 2) + 43) & 63;
  int stage_v_93_2 = ((pub_r001515_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((stage_v_18_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_94_2 = ((stage_v_18_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((stage_v_46_1 << 1) ^ (pub_r001515_2_1 >> 1)) & 127;
  int stage_v_95_2 = ((stage_v_46_2 << 1) ^ (pub_r001515_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((sec_r001515_13_1 << 1) ^ (pub_r001515_2_1 >> 1)) & 127;
  int stage_v_96_2 = ((sec_r001515_13_2 << 1) ^ (pub_r001515_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((pub_r001515_7_1 * 2) + 32) & 63;
  int stage_v_97_2 = ((pub_r001515_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001515_1_1 * 2) + 20) & 63;
  int stage_v_98_2 = ((pub_r001515_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001515_11_1 * 2) + 26) & 63;
  int stage_v_99_2 = ((pub_r001515_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((stage_v_91_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_100_2 = ((stage_v_91_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((pub_r001515_8_1 * 2) + 29) & 63;
  int stage_v_101_2 = ((pub_r001515_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001515_4_1 * 2) + 44) & 63;
  int stage_v_102_2 = ((pub_r001515_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_23_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_103_2 = ((stage_v_23_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((pub_r001515_5_1 * 2) + 39) & 63;
  int stage_v_104_2 = ((pub_r001515_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_65_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_105_2 = ((stage_v_65_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_105_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_105_2 + 1) & 15;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = ((sec_r001515_5_1 << 1) ^ (pub_r001515_14_1 >> 1)) & 127;
  int stage_v_106_2 = ((sec_r001515_5_2 << 1) ^ (pub_r001515_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_106_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_106_2 + 1) & 15;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = ((stage_v_11_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_107_2 = ((stage_v_11_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_107_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_107_2 + 1) & 15;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = ((pub_r001515_6_1 * 2) + 48) & 63;
  int stage_v_108_2 = ((pub_r001515_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_4_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_109_2 = ((stage_v_4_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((stage_v_109_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_110_2 = ((stage_v_109_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((pub_r001515_15_1 * 2) + 50) & 63;
  int stage_v_111_2 = ((pub_r001515_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001515_5_1 * 2) + 29) & 63;
  int stage_v_112_2 = ((pub_r001515_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001515_14_1 * 2) + 35) & 63;
  int stage_v_113_2 = ((pub_r001515_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((helper_flow_2_1 << 1) ^ (pub_r001515_15_1 >> 1)) & 127;
  int stage_v_114_2 = ((helper_flow_2_2 << 1) ^ (pub_r001515_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_114_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_114_2 + 1) & 15;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = ((stage_v_105_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_105_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((pub_r001515_3_1 * 2) + 10) & 63;
  int stage_v_116_2 = ((pub_r001515_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001515_12_1 * 2) + 32) & 63;
  int stage_v_117_2 = ((pub_r001515_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001515_4_1 * 2) + 22) & 63;
  int stage_v_118_2 = ((pub_r001515_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((sec_r001515_1_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_119_2 = ((sec_r001515_1_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((pub_r001515_8_1 * 2) + 14) & 63;
  int stage_v_120_2 = ((pub_r001515_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001515_12_1 * 2) + 10) & 63;
  int stage_v_121_2 = ((pub_r001515_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((sec_r001515_3_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_122_2 = ((sec_r001515_3_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((pub_r001515_7_1 * 2) + 32) & 63;
  int stage_v_123_2 = ((pub_r001515_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((stage_v_74_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_124_2 = ((stage_v_74_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_124_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_124_2 + 1) & 15;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = ((pub_r001515_9_1 * 2) + 39) & 63;
  int stage_v_125_2 = ((pub_r001515_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_26_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_26_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((stage_v_86_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_86_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((pub_r001515_1_1 * 2) + 32) & 63;
  int stage_v_128_2 = ((pub_r001515_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((stage_v_61_1 << 1) ^ (pub_r001515_14_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_61_2 << 1) ^ (pub_r001515_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((stage_v_114_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_130_2 = ((stage_v_114_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((stage_v_60_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_131_2 = ((stage_v_60_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((pub_r001515_12_1 * 2) + 6) & 63;
  int stage_v_132_2 = ((pub_r001515_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001515_15_1 * 2) + 11) & 63;
  int stage_v_133_2 = ((pub_r001515_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_103_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_134_2 = ((stage_v_103_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_134_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_134_2 + 1) & 15;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = ((pub_r001515_14_1 * 2) + 35) & 63;
  int stage_v_135_2 = ((pub_r001515_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001515_0_1 * 2) + 20) & 63;
  int stage_v_136_2 = ((pub_r001515_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((stage_v_46_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_137_2 = ((stage_v_46_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((stage_v_32_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_138_2 = ((stage_v_32_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_138_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_138_2 + 1) & 15;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = ((pub_r001515_7_1 * 2) + 16) & 63;
  int stage_v_139_2 = ((pub_r001515_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001515_9_1 * 2) + 49) & 63;
  int stage_v_140_2 = ((pub_r001515_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001515_9_1 * 2) + 48) & 63;
  int stage_v_141_2 = ((pub_r001515_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001515_0_1 * 2) + 21) & 63;
  int stage_v_142_2 = ((pub_r001515_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001515_6_1 * 2) + 18) & 63;
  int stage_v_143_2 = ((pub_r001515_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001515_5_1 * 2) + 31) & 63;
  int stage_v_144_2 = ((pub_r001515_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_138_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_138_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((stage_v_68_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_146_2 = ((stage_v_68_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((stage_v_10_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_147_2 = ((stage_v_10_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((sec_r001515_17_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_148_2 = ((sec_r001515_17_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_148_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_148_2 + 1) & 15;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = ((pub_r001515_10_1 * 2) + 38) & 63;
  int stage_v_149_2 = ((pub_r001515_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_16_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_150_2 = ((stage_v_16_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((pub_r001515_10_1 * 2) + 27) & 63;
  int stage_v_151_2 = ((pub_r001515_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_21_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_152_2 = ((stage_v_21_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((pub_r001515_14_1 * 2) + 32) & 63;
  int stage_v_153_2 = ((pub_r001515_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001515_12_1 * 2) + 11) & 63;
  int stage_v_154_2 = ((pub_r001515_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_48_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_48_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((stage_v_0_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_156_2 = ((stage_v_0_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((stage_v_41_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_157_2 = ((stage_v_41_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_157_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_157_2 + 1) & 15;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = ((stage_v_147_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_147_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((stage_v_47_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_47_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((pub_r001515_12_1 * 2) + 48) & 63;
  int stage_v_160_2 = ((pub_r001515_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_72_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_161_2 = ((stage_v_72_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_161_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_161_2 + 1) & 15;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = ((stage_v_24_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_24_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((stage_v_138_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_163_2 = ((stage_v_138_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_163_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_163_2 + 1) & 15;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = ((pub_r001515_2_1 * 2) + 43) & 63;
  int stage_v_164_2 = ((pub_r001515_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_152_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_165_2 = ((stage_v_152_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((stage_v_9_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_9_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((stage_v_78_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_167_2 = ((stage_v_78_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((pub_r001515_13_1 * 2) + 40) & 63;
  int stage_v_168_2 = ((pub_r001515_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((stage_v_21_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_169_2 = ((stage_v_21_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_169_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_169_2 + 1) & 15;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = ((stage_v_146_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_146_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((pub_r001515_11_1 * 2) + 36) & 63;
  int stage_v_171_2 = ((pub_r001515_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001515_12_1 * 2) + 33) & 63;
  int stage_v_172_2 = ((pub_r001515_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001515_4_1 * 2) + 49) & 63;
  int stage_v_173_2 = ((pub_r001515_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001515_15_1 * 2) + 7) & 63;
  int stage_v_174_2 = ((pub_r001515_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_138_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_175_2 = ((stage_v_138_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((stage_v_41_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_176_2 = ((stage_v_41_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_176_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_176_2 + 1) & 15;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = ((sec_r001515_4_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_177_2 = ((sec_r001515_4_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_177_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_177_2 + 1) & 15;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = ((stage_v_88_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_178_2 = ((stage_v_88_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((stage_v_50_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_179_2 = ((stage_v_50_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((stage_v_90_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_180_2 = ((stage_v_90_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_180_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_180_2 + 1) & 15;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = ((sec_r001515_4_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_181_2 = ((sec_r001515_4_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_181_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_181_2 + 1) & 15;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = ((pub_r001515_3_1 * 2) + 45) & 63;
  int stage_v_182_2 = ((pub_r001515_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_85_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_85_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((pub_r001515_12_1 * 2) + 8) & 63;
  int stage_v_184_2 = ((pub_r001515_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((stage_v_23_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_23_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((stage_v_96_1 << 1) ^ (pub_r001515_14_1 >> 1)) & 127;
  int stage_v_186_2 = ((stage_v_96_2 << 1) ^ (pub_r001515_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_186_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_186_2 + 1) & 15;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = ((stage_v_115_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_115_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((stage_v_85_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_188_2 = ((stage_v_85_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_188_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_188_2 + 1) & 15;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = ((pub_r001515_7_1 * 2) + 40) & 63;
  int stage_v_189_2 = ((pub_r001515_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001515_7_1 * 2) + 18) & 63;
  int stage_v_190_2 = ((pub_r001515_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((stage_v_21_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_21_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((sec_r001515_3_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_192_2 = ((sec_r001515_3_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((pub_r001515_12_1 * 2) + 17) & 63;
  int stage_v_193_2 = ((pub_r001515_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_9_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_194_2 = ((stage_v_9_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((stage_v_95_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_195_2 = ((stage_v_95_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_195_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_195_2 + 1) & 15;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = ((stage_v_191_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_191_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((stage_v_159_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_159_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((pub_r001515_2_1 * 2) + 18) & 63;
  int stage_v_198_2 = ((pub_r001515_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001515_5_1 * 2) + 30) & 63;
  int stage_v_199_2 = ((pub_r001515_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_175_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_200_2 = ((stage_v_175_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((pub_r001515_4_1 * 2) + 30) & 63;
  int stage_v_201_2 = ((pub_r001515_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001515_8_1 * 2) + 17) & 63;
  int stage_v_202_2 = ((pub_r001515_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001515_5_1 * 2) + 43) & 63;
  int stage_v_203_2 = ((pub_r001515_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_192_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_204_2 = ((stage_v_192_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_204_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_204_2 + 1) & 15;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = ((stage_v_109_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_205_2 = ((stage_v_109_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((stage_v_188_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_206_2 = ((stage_v_188_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_206_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_206_2 + 1) & 15;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = ((pub_r001515_11_1 * 2) + 50) & 63;
  int stage_v_207_2 = ((pub_r001515_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_32_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_32_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((pub_r001515_3_1 * 2) + 28) & 63;
  int stage_v_209_2 = ((pub_r001515_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001515_3_1 * 2) + 31) & 63;
  int stage_v_210_2 = ((pub_r001515_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001515_4_1 * 2) + 20) & 63;
  int stage_v_211_2 = ((pub_r001515_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001515_6_1 * 2) + 30) & 63;
  int stage_v_212_2 = ((pub_r001515_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((sec_r001515_2_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_213_2 = ((sec_r001515_2_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((stage_v_11_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_11_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((pub_r001515_3_1 * 2) + 9) & 63;
  int stage_v_215_2 = ((pub_r001515_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001515_2_1 * 2) + 17) & 63;
  int stage_v_216_2 = ((pub_r001515_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001515_1_1 * 2) + 9) & 63;
  int stage_v_217_2 = ((pub_r001515_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_115_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_218_2 = ((stage_v_115_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_218_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_218_2 + 1) & 15;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = ((stage_v_10_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_219_2 = ((stage_v_10_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((sec_r001515_0_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_220_2 = ((sec_r001515_0_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((stage_v_24_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_221_2 = ((stage_v_24_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((pub_r001515_14_1 * 2) + 42) & 63;
  int stage_v_222_2 = ((pub_r001515_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((stage_v_57_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_223_2 = ((stage_v_57_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_223_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_223_2 + 1) & 15;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = ((sec_r001515_0_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_224_2 = ((sec_r001515_0_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_224_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_224_2 + 1) & 15;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = ((pub_r001515_7_1 * 2) + 24) & 63;
  int stage_v_225_2 = ((pub_r001515_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001515_13_1 * 2) + 44) & 63;
  int stage_v_226_2 = ((pub_r001515_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_146_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_227_2 = ((stage_v_146_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((pub_r001515_3_1 * 2) + 41) & 63;
  int stage_v_228_2 = ((pub_r001515_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001515_3_1 * 2) + 23) & 63;
  int stage_v_229_2 = ((pub_r001515_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((helper_flow_1_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_230_2 = ((helper_flow_1_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((stage_v_57_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_231_2 = ((stage_v_57_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_231_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_231_2 + 1) & 15;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = ((pub_r001515_4_1 * 2) + 43) & 63;
  int stage_v_232_2 = ((pub_r001515_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((stage_v_9_1 << 1) ^ (pub_r001515_15_1 >> 1)) & 127;
  int stage_v_233_2 = ((stage_v_9_2 << 1) ^ (pub_r001515_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_233_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_233_2 + 1) & 15;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = ((sec_r001515_9_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_234_2 = ((sec_r001515_9_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((pub_r001515_9_1 * 2) + 6) & 63;
  int stage_v_235_2 = ((pub_r001515_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((stage_v_205_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_236_2 = ((stage_v_205_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((pub_r001515_7_1 * 2) + 46) & 63;
  int stage_v_237_2 = ((pub_r001515_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((helper_flow_0_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_238_2 = ((helper_flow_0_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_238_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_238_2 + 1) & 15;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = ((stage_v_106_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_106_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((pub_r001515_4_1 * 2) + 45) & 63;
  int stage_v_240_2 = ((pub_r001515_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((stage_v_181_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_241_2 = ((stage_v_181_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((pub_r001515_10_1 * 2) + 34) & 63;
  int stage_v_242_2 = ((pub_r001515_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001515_14_1 * 2) + 44) & 63;
  int stage_v_243_2 = ((pub_r001515_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((stage_v_181_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_244_2 = ((stage_v_181_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_244_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_244_2 + 1) & 15;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = ((pub_r001515_9_1 * 2) + 35) & 63;
  int stage_v_245_2 = ((pub_r001515_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_85_1 << 1) ^ (pub_r001515_15_1 >> 1)) & 127;
  int stage_v_246_2 = ((stage_v_85_2 << 1) ^ (pub_r001515_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_246_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_246_2 + 1) & 15;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = ((pub_r001515_15_1 * 2) + 33) & 63;
  int stage_v_247_2 = ((pub_r001515_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((stage_v_194_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_248_2 = ((stage_v_194_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((pub_r001515_6_1 * 2) + 7) & 63;
  int stage_v_249_2 = ((pub_r001515_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001515_8_1 * 2) + 20) & 63;
  int stage_v_250_2 = ((pub_r001515_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((stage_v_186_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_251_2 = ((stage_v_186_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_251_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_251_2 + 1) & 15;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = ((stage_v_2_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_252_2 = ((stage_v_2_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((stage_v_50_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_50_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((pub_r001515_2_1 * 2) + 38) & 63;
  int stage_v_254_2 = ((pub_r001515_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001515_3_1 * 2) + 45) & 63;
  int stage_v_255_2 = ((pub_r001515_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((sec_r001515_1_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_256_2 = ((sec_r001515_1_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((pub_r001515_2_1 * 2) + 17) & 63;
  int stage_v_257_2 = ((pub_r001515_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((helper_flow_5_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_258_2 = ((helper_flow_5_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_258_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_258_2 + 1) & 15;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = ((stage_v_178_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_259_2 = ((stage_v_178_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((pub_r001515_5_1 * 2) + 22) & 63;
  int stage_v_260_2 = ((pub_r001515_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((stage_v_95_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_261_2 = ((stage_v_95_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_261_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_261_2 + 1) & 15;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = ((stage_v_252_1 << 1) ^ (pub_r001515_15_1 >> 1)) & 127;
  int stage_v_262_2 = ((stage_v_252_2 << 1) ^ (pub_r001515_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((stage_v_233_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_263_2 = ((stage_v_233_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_263_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_263_2 + 1) & 15;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = ((stage_v_94_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_264_2 = ((stage_v_94_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((pub_r001515_10_1 * 2) + 5) & 63;
  int stage_v_265_2 = ((pub_r001515_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001515_12_1 * 2) + 37) & 63;
  int stage_v_266_2 = ((pub_r001515_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((stage_v_177_1 << 1) ^ (pub_r001515_2_1 >> 1)) & 127;
  int stage_v_267_2 = ((stage_v_177_2 << 1) ^ (pub_r001515_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_267_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_267_2 + 1) & 15;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = ((pub_r001515_15_1 * 2) + 21) & 63;
  int stage_v_268_2 = ((pub_r001515_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((stage_v_86_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_86_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((stage_v_86_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_270_2 = ((stage_v_86_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((stage_v_74_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_271_2 = ((stage_v_74_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_271_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_271_2 + 1) & 15;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = ((sec_r001515_8_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_272_2 = ((sec_r001515_8_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_214_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_214_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((stage_v_51_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_274_2 = ((stage_v_51_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_274_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_274_2 + 1) & 15;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = ((stage_v_155_1 << 1) ^ (pub_r001515_14_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_155_2 << 1) ^ (pub_r001515_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((stage_v_67_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_276_2 = ((stage_v_67_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((stage_v_146_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_146_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((pub_r001515_4_1 * 2) + 38) & 63;
  int stage_v_278_2 = ((pub_r001515_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((stage_v_32_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_279_2 = ((stage_v_32_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_279_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_279_2 + 1) & 15;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = ((stage_v_246_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_280_2 = ((stage_v_246_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((stage_v_205_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_281_2 = ((stage_v_205_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_281_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_281_2 + 1) & 15;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = ((stage_v_263_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_263_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((stage_v_131_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_283_2 = ((stage_v_131_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((stage_v_194_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_194_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((pub_r001515_2_1 * 2) + 43) & 63;
  int stage_v_285_2 = ((pub_r001515_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((stage_v_114_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_286_2 = ((stage_v_114_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_286_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_286_2 + 1) & 15;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = ((pub_r001515_12_1 * 2) + 29) & 63;
  int stage_v_287_2 = ((pub_r001515_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((stage_v_47_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_288_2 = ((stage_v_47_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_288_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_288_2 + 1) & 15;
  out_sink_1 ^= stage_v_288_1 & 63;
  out_sink_2 ^= stage_v_288_2 & 63;
  int stage_v_289_1 = ((pub_r001515_12_1 * 2) + 29) & 63;
  int stage_v_289_2 = ((pub_r001515_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((helper_flow_4_1 << 1) ^ (pub_r001515_11_1 >> 1)) & 127;
  int stage_v_290_2 = ((helper_flow_4_2 << 1) ^ (pub_r001515_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((pub_r001515_6_1 * 2) + 16) & 63;
  int stage_v_291_2 = ((pub_r001515_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001515_5_1 * 2) + 40) & 63;
  int stage_v_292_2 = ((pub_r001515_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001515_10_1 * 2) + 46) & 63;
  int stage_v_293_2 = ((pub_r001515_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((stage_v_137_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_294_2 = ((stage_v_137_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_294_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_294_2 + 1) & 15;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = ((stage_v_41_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_295_2 = ((stage_v_41_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_295_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_295_2 + 1) & 15;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = ((pub_r001515_5_1 * 2) + 40) & 63;
  int stage_v_296_2 = ((pub_r001515_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((stage_v_280_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_297_2 = ((stage_v_280_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_297_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_297_2 + 1) & 15;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = ((stage_v_41_1 << 1) ^ (pub_r001515_2_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_41_2 << 1) ^ (pub_r001515_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((pub_r001515_2_1 * 2) + 42) & 63;
  int stage_v_299_2 = ((pub_r001515_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001515_13_1 * 2) + 15) & 63;
  int stage_v_300_2 = ((pub_r001515_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((stage_v_234_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_301_2 = ((stage_v_234_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_301_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_301_2 + 1) & 15;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = ((pub_r001515_8_1 * 2) + 13) & 63;
  int stage_v_302_2 = ((pub_r001515_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001515_8_1 * 2) + 18) & 63;
  int stage_v_303_2 = ((pub_r001515_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001515_0_1 * 2) + 21) & 63;
  int stage_v_304_2 = ((pub_r001515_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001515_5_1 * 2) + 29) & 63;
  int stage_v_305_2 = ((pub_r001515_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((stage_v_192_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_192_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((stage_v_234_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_307_2 = ((stage_v_234_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_307_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_307_2 + 1) & 15;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = ((sec_r001515_2_1 << 1) ^ (pub_r001515_2_1 >> 1)) & 127;
  int stage_v_308_2 = ((sec_r001515_2_2 << 1) ^ (pub_r001515_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((stage_v_275_1 << 1) ^ (pub_r001515_14_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_275_2 << 1) ^ (pub_r001515_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((stage_v_16_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_310_2 = ((stage_v_16_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((stage_v_205_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_205_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((stage_v_46_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_46_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((stage_v_100_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_100_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((pub_r001515_10_1 * 2) + 35) & 63;
  int stage_v_314_2 = ((pub_r001515_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((helper_flow_6_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_315_2 = ((helper_flow_6_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((pub_r001515_0_1 * 2) + 16) & 63;
  int stage_v_316_2 = ((pub_r001515_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001515_13_1 * 2) + 35) & 63;
  int stage_v_317_2 = ((pub_r001515_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((stage_v_183_1 << 1) ^ (pub_r001515_2_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_183_2 << 1) ^ (pub_r001515_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((stage_v_236_1 << 1) ^ (pub_r001515_14_1 >> 1)) & 127;
  int stage_v_319_2 = ((stage_v_236_2 << 1) ^ (pub_r001515_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((stage_v_67_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_320_2 = ((stage_v_67_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((pub_r001515_1_1 * 2) + 18) & 63;
  int stage_v_321_2 = ((pub_r001515_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001515_0_1 * 2) + 16) & 63;
  int stage_v_322_2 = ((pub_r001515_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((stage_v_60_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_60_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((pub_r001515_14_1 * 2) + 6) & 63;
  int stage_v_324_2 = ((pub_r001515_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((stage_v_219_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_219_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((stage_v_175_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_175_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((stage_v_17_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_327_2 = ((stage_v_17_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((pub_r001515_12_1 * 2) + 10) & 63;
  int stage_v_328_2 = ((pub_r001515_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001515_1_1 * 2) + 16) & 63;
  int stage_v_329_2 = ((pub_r001515_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001515_9_1 * 2) + 49) & 63;
  int stage_v_330_2 = ((pub_r001515_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((stage_v_115_1 << 1) ^ (pub_r001515_2_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_115_2 << 1) ^ (pub_r001515_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((stage_v_272_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_332_2 = ((stage_v_272_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((pub_r001515_0_1 * 2) + 15) & 63;
  int stage_v_333_2 = ((pub_r001515_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((stage_v_231_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_334_2 = ((stage_v_231_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_334_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_334_2 + 1) & 15;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = ((pub_r001515_15_1 * 2) + 13) & 63;
  int stage_v_335_2 = ((pub_r001515_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((sec_r001515_4_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_336_2 = ((sec_r001515_4_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((sec_r001515_12_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_337_2 = ((sec_r001515_12_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_337_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_337_2 + 1) & 15;
  out_sink_1 ^= stage_v_337_1 & 63;
  out_sink_2 ^= stage_v_337_2 & 63;
  int stage_v_338_1 = ((pub_r001515_0_1 * 2) + 8) & 63;
  int stage_v_338_2 = ((pub_r001515_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((stage_v_256_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_339_2 = ((stage_v_256_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_339_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_339_2 + 1) & 15;
  out_sink_1 ^= stage_v_339_1 & 63;
  out_sink_2 ^= stage_v_339_2 & 63;
  int stage_v_340_1 = ((pub_r001515_7_1 * 2) + 12) & 63;
  int stage_v_340_2 = ((pub_r001515_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001515_4_1 * 2) + 27) & 63;
  int stage_v_341_2 = ((pub_r001515_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((stage_v_9_1 << 1) ^ (pub_r001515_15_1 >> 1)) & 127;
  int stage_v_342_2 = ((stage_v_9_2 << 1) ^ (pub_r001515_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((stage_v_218_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_343_2 = ((stage_v_218_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((pub_r001515_8_1 * 2) + 8) & 63;
  int stage_v_344_2 = ((pub_r001515_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001515_12_1 * 2) + 16) & 63;
  int stage_v_345_2 = ((pub_r001515_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((sec_r001515_16_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_346_2 = ((sec_r001515_16_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((pub_r001515_14_1 * 2) + 37) & 63;
  int stage_v_347_2 = ((pub_r001515_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((stage_v_309_1 << 1) ^ (pub_r001515_7_1 >> 1)) & 127;
  int stage_v_348_2 = ((stage_v_309_2 << 1) ^ (pub_r001515_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((stage_v_4_1 << 1) ^ (pub_r001515_15_1 >> 1)) & 127;
  int stage_v_349_2 = ((stage_v_4_2 << 1) ^ (pub_r001515_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((pub_r001515_4_1 * 2) + 49) & 63;
  int stage_v_350_2 = ((pub_r001515_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001515_5_1 * 2) + 49) & 63;
  int stage_v_351_2 = ((pub_r001515_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((stage_v_0_1 << 1) ^ (pub_r001515_1_1 >> 1)) & 127;
  int stage_v_352_2 = ((stage_v_0_2 << 1) ^ (pub_r001515_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((stage_v_86_1 << 1) ^ (pub_r001515_4_1 >> 1)) & 127;
  int stage_v_353_2 = ((stage_v_86_2 << 1) ^ (pub_r001515_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_353_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_353_2 + 1) & 15;
  out_sink_1 ^= stage_v_353_1 & 63;
  out_sink_2 ^= stage_v_353_2 & 63;
  int stage_v_354_1 = ((pub_r001515_14_1 * 2) + 48) & 63;
  int stage_v_354_2 = ((pub_r001515_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001515_12_1 * 2) + 16) & 63;
  int stage_v_355_2 = ((pub_r001515_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((stage_v_103_1 << 1) ^ (pub_r001515_5_1 >> 1)) & 127;
  int stage_v_356_2 = ((stage_v_103_2 << 1) ^ (pub_r001515_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((pub_r001515_1_1 * 2) + 25) & 63;
  int stage_v_357_2 = ((pub_r001515_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((stage_v_241_1 << 1) ^ (pub_r001515_8_1 >> 1)) & 127;
  int stage_v_358_2 = ((stage_v_241_2 << 1) ^ (pub_r001515_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_358_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_358_2 + 1) & 15;
  out_sink_1 ^= stage_v_358_1 & 63;
  out_sink_2 ^= stage_v_358_2 & 63;
  int stage_v_359_1 = ((stage_v_165_1 << 1) ^ (pub_r001515_0_1 >> 1)) & 127;
  int stage_v_359_2 = ((stage_v_165_2 << 1) ^ (pub_r001515_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_359_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_359_2 + 1) & 15;
  out_sink_1 ^= stage_v_359_1 & 63;
  out_sink_2 ^= stage_v_359_2 & 63;
  int stage_v_360_1 = ((stage_v_181_1 << 1) ^ (pub_r001515_15_1 >> 1)) & 127;
  int stage_v_360_2 = ((stage_v_181_2 << 1) ^ (pub_r001515_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001515_9_1 * 2) + 6) & 63;
  int stage_v_361_2 = ((pub_r001515_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001515_9_1 * 2) + 5) & 63;
  int stage_v_362_2 = ((pub_r001515_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001515_12_1 * 2) + 22) & 63;
  int stage_v_363_2 = ((pub_r001515_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((stage_v_150_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_150_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_39_1 << 1) ^ (pub_r001515_12_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_39_2 << 1) ^ (pub_r001515_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((stage_v_162_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_162_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((pub_r001515_5_1 * 2) + 39) & 63;
  int stage_v_367_2 = ((pub_r001515_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((stage_v_334_1 << 1) ^ (pub_r001515_9_1 >> 1)) & 127;
  int stage_v_368_2 = ((stage_v_334_2 << 1) ^ (pub_r001515_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((pub_r001515_1_1 * 2) + 25) & 63;
  int stage_v_369_2 = ((pub_r001515_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((stage_v_170_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_170_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((stage_v_162_1 << 1) ^ (pub_r001515_3_1 >> 1)) & 127;
  int stage_v_371_2 = ((stage_v_162_2 << 1) ^ (pub_r001515_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((stage_v_39_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_39_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((pub_r001515_12_1 * 2) + 30) & 63;
  int stage_v_373_2 = ((pub_r001515_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((stage_v_185_1 << 1) ^ (pub_r001515_10_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_185_2 << 1) ^ (pub_r001515_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((pub_r001515_0_1 * 2) + 44) & 63;
  int stage_v_375_2 = ((pub_r001515_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((stage_v_349_1 << 1) ^ (pub_r001515_6_1 >> 1)) & 127;
  int stage_v_376_2 = ((stage_v_349_2 << 1) ^ (pub_r001515_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_376_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_376_2 + 1) & 15;
  out_sink_1 ^= stage_v_376_1 & 63;
  out_sink_2 ^= stage_v_376_2 & 63;
  int stage_v_377_1 = ((stage_v_206_1 << 1) ^ (pub_r001515_13_1 >> 1)) & 127;
  int stage_v_377_2 = ((stage_v_206_2 << 1) ^ (pub_r001515_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001515_8_1 == pub_r001515_8_2);
  __CPROVER_assume(pub_r001515_2_1 == pub_r001515_2_2);
  __CPROVER_assume(sec_r001515_9_1 != sec_r001515_9_2);
  __CPROVER_assume(sec_r001515_5_1 != sec_r001515_5_2);
  __CPROVER_assume(sec_r001515_10_1 != sec_r001515_10_2);
  __CPROVER_assume(pub_r001515_14_1 == pub_r001515_14_2);
  __CPROVER_assume(sec_r001515_0_1 != sec_r001515_0_2);
  __CPROVER_assume(sec_r001515_14_1 != sec_r001515_14_2);
  __CPROVER_assume(sec_r001515_4_1 != sec_r001515_4_2);
  __CPROVER_assume(pub_r001515_6_1 == pub_r001515_6_2);
  __CPROVER_assume(pub_r001515_15_1 == pub_r001515_15_2);
  __CPROVER_assume(sec_r001515_1_1 != sec_r001515_1_2);
  __CPROVER_assume(pub_r001515_4_1 == pub_r001515_4_2);
  __CPROVER_assume(pub_r001515_11_1 == pub_r001515_11_2);
  __CPROVER_assume(sec_r001515_6_1 != sec_r001515_6_2);
  __CPROVER_assume(pub_r001515_0_1 == pub_r001515_0_2);
  __CPROVER_assume(pub_r001515_3_1 == pub_r001515_3_2);
  __CPROVER_assume(sec_r001515_8_1 != sec_r001515_8_2);
  __CPROVER_assume(pub_r001515_9_1 == pub_r001515_9_2);
  __CPROVER_assume(sec_r001515_11_1 != sec_r001515_11_2);
  __CPROVER_assume(sec_r001515_18_1 != sec_r001515_18_2);
  __CPROVER_assume(sec_r001515_17_1 != sec_r001515_17_2);
  __CPROVER_assume(sec_r001515_16_1 != sec_r001515_16_2);
  __CPROVER_assume(pub_r001515_13_1 == pub_r001515_13_2);
  __CPROVER_assume(pub_r001515_10_1 == pub_r001515_10_2);
  __CPROVER_assume(sec_r001515_2_1 != sec_r001515_2_2);
  __CPROVER_assume(sec_r001515_13_1 != sec_r001515_13_2);
  __CPROVER_assume(sec_r001515_15_1 != sec_r001515_15_2);
  __CPROVER_assume(pub_r001515_7_1 == pub_r001515_7_2);
  __CPROVER_assume(pub_r001515_12_1 == pub_r001515_12_2);
  __CPROVER_assume(sec_r001515_12_1 != sec_r001515_12_2);
  __CPROVER_assume(pub_r001515_5_1 == pub_r001515_5_2);
  __CPROVER_assume(sec_r001515_3_1 != sec_r001515_3_2);
  __CPROVER_assume(sec_r001515_7_1 != sec_r001515_7_2);
  __CPROVER_assume(pub_r001515_1_1 == pub_r001515_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.code == st_var_2_2.code);
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
  assert(stage_v_306_1 == stage_v_306_2);
  assert(stage_v_307_1 == stage_v_307_2);
  assert(stage_v_308_1 == stage_v_308_2);
  assert(stage_v_309_1 == stage_v_309_2);
  assert(stage_v_310_1 == stage_v_310_2);
  assert(stage_v_311_1 == stage_v_311_2);
  assert(stage_v_312_1 == stage_v_312_2);
  assert(stage_v_313_1 == stage_v_313_2);
  assert(stage_v_314_1 == stage_v_314_2);
  assert(stage_v_315_1 == stage_v_315_2);
  assert(stage_v_316_1 == stage_v_316_2);
  assert(stage_v_317_1 == stage_v_317_2);
  assert(stage_v_318_1 == stage_v_318_2);
  assert(stage_v_319_1 == stage_v_319_2);
  assert(stage_v_320_1 == stage_v_320_2);
  assert(stage_v_321_1 == stage_v_321_2);
  assert(stage_v_322_1 == stage_v_322_2);
  assert(stage_v_323_1 == stage_v_323_2);
  assert(stage_v_324_1 == stage_v_324_2);
  assert(stage_v_325_1 == stage_v_325_2);
  assert(stage_v_326_1 == stage_v_326_2);
  assert(stage_v_327_1 == stage_v_327_2);
  assert(stage_v_328_1 == stage_v_328_2);
  assert(stage_v_329_1 == stage_v_329_2);
  assert(stage_v_330_1 == stage_v_330_2);
  assert(stage_v_331_1 == stage_v_331_2);
  assert(stage_v_332_1 == stage_v_332_2);
  assert(stage_v_333_1 == stage_v_333_2);
  assert(stage_v_334_1 == stage_v_334_2);
  assert(stage_v_335_1 == stage_v_335_2);
  assert(stage_v_336_1 == stage_v_336_2);
  assert(stage_v_337_1 == stage_v_337_2);
  assert(stage_v_338_1 == stage_v_338_2);
  assert(stage_v_339_1 == stage_v_339_2);
  assert(stage_v_340_1 == stage_v_340_2);
  assert(stage_v_341_1 == stage_v_341_2);
  assert(stage_v_342_1 == stage_v_342_2);
  assert(stage_v_343_1 == stage_v_343_2);
  assert(stage_v_344_1 == stage_v_344_2);
  assert(stage_v_345_1 == stage_v_345_2);
  assert(stage_v_346_1 == stage_v_346_2);
  assert(stage_v_347_1 == stage_v_347_2);
  assert(stage_v_348_1 == stage_v_348_2);
  assert(stage_v_349_1 == stage_v_349_2);
  assert(stage_v_350_1 == stage_v_350_2);
  assert(stage_v_351_1 == stage_v_351_2);
  assert(stage_v_352_1 == stage_v_352_2);
  assert(stage_v_353_1 == stage_v_353_2);
  assert(stage_v_354_1 == stage_v_354_2);
  assert(stage_v_355_1 == stage_v_355_2);
  assert(stage_v_356_1 == stage_v_356_2);
  assert(stage_v_357_1 == stage_v_357_2);
  assert(stage_v_358_1 == stage_v_358_2);
  assert(stage_v_359_1 == stage_v_359_2);
  assert(stage_v_360_1 == stage_v_360_2);
  assert(stage_v_361_1 == stage_v_361_2);
  assert(stage_v_362_1 == stage_v_362_2);
  assert(stage_v_363_1 == stage_v_363_2);
  assert(stage_v_364_1 == stage_v_364_2);
  assert(stage_v_365_1 == stage_v_365_2);
  assert(stage_v_366_1 == stage_v_366_2);
  assert(stage_v_367_1 == stage_v_367_2);
  assert(stage_v_368_1 == stage_v_368_2);
  assert(stage_v_369_1 == stage_v_369_2);
  assert(stage_v_370_1 == stage_v_370_2);
  assert(stage_v_371_1 == stage_v_371_2);
  assert(stage_v_372_1 == stage_v_372_2);
  assert(stage_v_373_1 == stage_v_373_2);
  assert(stage_v_374_1 == stage_v_374_2);
  assert(stage_v_375_1 == stage_v_375_2);
  assert(stage_v_376_1 == stage_v_376_2);
  assert(stage_v_377_1 == stage_v_377_2);
}


