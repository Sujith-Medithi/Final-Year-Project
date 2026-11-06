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
struct MatrixBlock_R000547_4713_0
{
  short dim;
  short trace;
  short determinant;
  short density;
  int buffer[3];
};
struct FilterState_R000547_4713_1
{
  unsigned char prev_out;
  int prev_in;
  unsigned char cutoff;
  unsigned char damping;
  unsigned char gain_db;
  int buffer[3];
};
struct EventLog_R000547_4713_2
{
  int seq;
  int severity;
  short code;
  int timestamp;
  int buffer[3];
};
struct Transaction_R000547_4713_3
{
  unsigned char fee;
  unsigned char status;
  int balance;
  int buffer[3];
};
union ColorPixel_R000547_4713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000547_4713_1
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
void fn_R000547_4713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int stride_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_78_1 > 25)
  {
    acc_1 = ((acc_1 + (stride_78_1 * 2)) + 5) & 127;
    aux_1 ^= stride_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_78_2 > 25)
  {
    acc_2 = ((acc_2 + (stride_78_2 * 2)) + 5) & 127;
    aux_2 ^= stride_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_78_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_95_1) & 63;
  aux_2 = (aux_2 + factor_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_78_1 == stride_78_2);
  assert(factor_95_1 == factor_95_2);
}

int fn_R000547_4713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int stride_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_78 > 25)
  {
    acc = ((acc + (stride_78 * 2)) + 5) & 127;
    aux ^= stride_78 & 15;
  }
  else
  {
    acc = ((acc - stride_78) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_95) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000547_4713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st_1 = {0};
  struct FilterState_R000547_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_56_1)
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

  switch (vector_56_2)
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

  int quantum_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_88_1) & 63;
  aux_2 = (aux_2 + quantum_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_10_1 > 27)
  {
    acc_1 = ((acc_1 + (phase_10_1 * 2)) + 5) & 127;
    aux_1 ^= phase_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_10_2 > 27)
  {
    acc_2 = ((acc_2 + (phase_10_2 * 2)) + 5) & 127;
    aux_2 ^= phase_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_56_1 == vector_56_2);
  assert(quantum_88_1 == quantum_88_2);
  assert(phase_10_1 == phase_10_2);
}

int fn_R000547_4713_1(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_56 = (aux + st.buffer[1]) & 3;
  switch (vector_56)
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

  int quantum_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_88) & 63;
  acc ^= aux;
  int phase_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_10 > 27)
  {
    acc = ((acc + (phase_10 * 2)) + 5) & 127;
    aux ^= phase_10 & 15;
  }
  else
  {
    acc = ((acc - phase_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000547_4713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st_1 = {0};
  struct Transaction_R000547_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_70_1 = local_arr_1[aux_1 % 3];
  int vector_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_70_2 * 2)) & 127;
  int tracker_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_51_1 > 45)
  {
    acc_1 = ((acc_1 + (tracker_51_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_51_2 > 45)
  {
    acc_2 = ((acc_2 + (tracker_51_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_70_1 == vector_70_2);
  assert(tracker_51_1 == tracker_51_2);
}

int fn_R000547_4713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int vector_70 = local_arr[aux % 3];
  acc = (acc + (vector_70 * 2)) & 127;
  int tracker_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_51 > 45)
  {
    acc = ((acc + (tracker_51 * 2)) + 5) & 127;
    aux ^= tracker_51 & 15;
  }
  else
  {
    acc = ((acc - tracker_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000547_4713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int mask_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_48_1)
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

  switch (mask_48_2)
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

  int metric_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_66_1) & 63;
  aux_2 = (aux_2 + metric_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_80_1 = local_arr_1[aux_1 % 3];
  int quantum_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_48_1 == mask_48_2);
  assert(metric_66_1 == metric_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_80_1 == quantum_80_2);
}

int fn_R000547_4713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int mask_48 = (aux + st.buffer[1]) & 3;
  switch (mask_48)
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

  int metric_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_66) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_80 = local_arr[aux % 3];
  acc = (acc + (quantum_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st_1 = {0};
  struct Transaction_R000547_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_72_1) & 63;
  aux_2 = (aux_2 + factor_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_97_1 > 13)
  {
    acc_1 = ((acc_1 + (tracker_97_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_97_2 > 13)
  {
    acc_2 = ((acc_2 + (tracker_97_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_16_1)
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

  switch (phase_16_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_72_1 == factor_72_2);
  assert(tracker_97_1 == tracker_97_2);
  assert(phase_16_1 == phase_16_2);
}

int fn_R000547_4713_4(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_72) & 63;
  acc ^= aux;
  int tracker_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_97 > 13)
  {
    acc = ((acc + (tracker_97 * 2)) + 5) & 127;
    aux ^= tracker_97 & 15;
  }
  else
  {
    acc = ((acc - tracker_97) + 11) & 127;
    aux += 3;
  }
  int phase_16 = (aux + st.buffer[1]) & 3;
  switch (phase_16)
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

void fn_R000547_4713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_84_1 > 32)
  {
    acc_1 = ((acc_1 + (quantum_84_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_84_2 > 32)
  {
    acc_2 = ((acc_2 + (quantum_84_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_84_1 == quantum_84_2);
}

int fn_R000547_4713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_84 > 32)
  {
    acc = ((acc + (quantum_84 * 2)) + 5) & 127;
    aux ^= quantum_84 & 15;
  }
  else
  {
    acc = ((acc - quantum_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000547_4713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st_1 = {0};
  struct FilterState_R000547_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_28_1) & 63;
  aux_2 = (aux_2 + tracker_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_75_1 > 13)
  {
    acc_1 = ((acc_1 + (quotient_75_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_75_2 > 13)
  {
    acc_2 = ((acc_2 + (quotient_75_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_75_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_76_1)
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

  switch (threshold_76_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_28_1 == tracker_28_2);
  assert(quotient_75_1 == quotient_75_2);
  assert(threshold_76_1 == threshold_76_2);
}

int fn_R000547_4713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_28) & 63;
  acc ^= aux;
  int quotient_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_75 > 13)
  {
    acc = ((acc + (quotient_75 * 2)) + 5) & 127;
    aux ^= quotient_75 & 15;
  }
  else
  {
    acc = ((acc - quotient_75) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_76 = (aux + st.buffer[1]) & 3;
  switch (threshold_76)
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

void fn_R000547_4713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_24_1 > 25)
  {
    acc_1 = ((acc_1 + (offset_24_1 * 2)) + 5) & 127;
    aux_1 ^= offset_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_24_2 > 25)
  {
    acc_2 = ((acc_2 + (offset_24_2 * 2)) + 5) & 127;
    aux_2 ^= offset_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_38_1)
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

  switch (bound_38_2)
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
  int margin_63_1 = local_arr_1[aux_1 % 3];
  int margin_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_24_1 == offset_24_2);
  assert(bound_38_1 == bound_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_63_1 == margin_63_2);
}

int fn_R000547_4713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_24 > 25)
  {
    acc = ((acc + (offset_24 * 2)) + 5) & 127;
    aux ^= offset_24 & 15;
  }
  else
  {
    acc = ((acc - offset_24) + 11) & 127;
    aux += 3;
  }
  int bound_38 = (aux + st.buffer[1]) & 3;
  switch (bound_38)
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
  int margin_63 = local_arr[aux % 3];
  acc = (acc + (margin_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int delta_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_91_1)
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

  switch (delta_91_2)
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
  int vector_20_1 = local_arr_1[aux_1 % 3];
  int vector_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_91_1 == delta_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_20_1 == vector_20_2);
}

int fn_R000547_4713_8(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int delta_91 = (aux + st.buffer[1]) & 3;
  switch (delta_91)
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
  int vector_20 = local_arr[aux % 3];
  acc = (acc + (vector_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st_1 = {0};
  struct FilterState_R000547_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int window_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_37_1) & 63;
  aux_2 = (aux_2 + window_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_66_1)
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

  switch (tracker_66_2)
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
  int tally_80_1 = local_arr_1[aux_1 % 3];
  int tally_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_37_1 == window_37_2);
  assert(tracker_66_1 == tracker_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_80_1 == tally_80_2);
}

int fn_R000547_4713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int window_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_37) & 63;
  acc ^= aux;
  int tracker_66 = (aux + st.buffer[1]) & 3;
  switch (tracker_66)
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
  int tally_80 = local_arr[aux % 3];
  acc = (acc + (tally_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int vector_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_84_1)
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

  switch (vector_84_2)
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

  int segment_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_49_1 > 22)
  {
    acc_1 = ((acc_1 + (segment_49_1 * 2)) + 5) & 127;
    aux_1 ^= segment_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_49_2 > 22)
  {
    acc_2 = ((acc_2 + (segment_49_2 * 2)) + 5) & 127;
    aux_2 ^= segment_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_49_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_84_1 == vector_84_2);
  assert(segment_49_1 == segment_49_2);
}

int fn_R000547_4713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int vector_84 = (aux + st.buffer[1]) & 3;
  switch (vector_84)
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

  int segment_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_49 > 22)
  {
    acc = ((acc + (segment_49 * 2)) + 5) & 127;
    aux ^= segment_49 & 15;
  }
  else
  {
    acc = ((acc - segment_49) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st_1 = {0};
  struct FilterState_R000547_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_64_1 = local_arr_1[aux_1 % 3];
  int coefficient_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_64_1 == coefficient_64_2);
}

int fn_R000547_4713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_64 = local_arr[aux % 3];
  acc = (acc + (coefficient_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st_1 = {0};
  struct Transaction_R000547_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int parity_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_90_1) & 63;
  aux_2 = (aux_2 + parity_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_56_1 = local_arr_1[aux_1 % 3];
  int index_reg_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_90_1 == parity_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_56_1 == index_reg_56_2);
}

int fn_R000547_4713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int parity_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_56 = local_arr[aux % 3];
  acc = (acc + (index_reg_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000547_4713_0 st_1 = {0};
  struct MatrixBlock_R000547_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quotient_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_48_1 > 37)
  {
    acc_1 = ((acc_1 + (quotient_48_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_48_2 > 37)
  {
    acc_2 = ((acc_2 + (quotient_48_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_96_1) & 63;
  aux_2 = (aux_2 + checksum_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_57_1)
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

  switch (margin_57_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_48_1 == quotient_48_2);
  assert(checksum_96_1 == checksum_96_2);
  assert(margin_57_1 == margin_57_2);
}

int fn_R000547_4713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000547_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quotient_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_48 > 37)
  {
    acc = ((acc + (quotient_48 * 2)) + 5) & 127;
    aux ^= quotient_48 & 15;
  }
  else
  {
    acc = ((acc - quotient_48) + 11) & 127;
    aux += 3;
  }
  int checksum_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_96) & 63;
  acc ^= aux;
  int margin_57 = (aux + st.buffer[1]) & 3;
  switch (margin_57)
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

void fn_R000547_4713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int mask_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_57_1)
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

  switch (mask_57_2)
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

  int quantum_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_45_1 > 29)
  {
    acc_1 = ((acc_1 + (quantum_45_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_45_2 > 29)
  {
    acc_2 = ((acc_2 + (quantum_45_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_93_1 = local_arr_1[aux_1 % 3];
  int parity_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_57_1 == mask_57_2);
  assert(quantum_45_1 == quantum_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_93_1 == parity_93_2);
}

int fn_R000547_4713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int mask_57 = (aux + st.buffer[1]) & 3;
  switch (mask_57)
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

  int quantum_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_45 > 29)
  {
    acc = ((acc + (quantum_45 * 2)) + 5) & 127;
    aux ^= quantum_45 & 15;
  }
  else
  {
    acc = ((acc - quantum_45) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_93 = local_arr[aux % 3];
  acc = (acc + (parity_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st_1 = {0};
  struct FilterState_R000547_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int cursor_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_50_1 > 39)
  {
    acc_1 = ((acc_1 + (cursor_50_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_50_2 > 39)
  {
    acc_2 = ((acc_2 + (cursor_50_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_50_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_50_1 == cursor_50_2);
}

int fn_R000547_4713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int cursor_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_50 > 39)
  {
    acc = ((acc + (cursor_50 * 2)) + 5) & 127;
    aux ^= cursor_50 & 15;
  }
  else
  {
    acc = ((acc - cursor_50) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int tally_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_19_1 > 44)
  {
    acc_1 = ((acc_1 + (tally_19_1 * 2)) + 5) & 127;
    aux_1 ^= tally_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_19_2 > 44)
  {
    acc_2 = ((acc_2 + (tally_19_2 * 2)) + 5) & 127;
    aux_2 ^= tally_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_19_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_11_1) & 63;
  aux_2 = (aux_2 + vector_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_64_1)
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

  switch (coefficient_64_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_19_1 == tally_19_2);
  assert(vector_11_1 == vector_11_2);
  assert(coefficient_64_1 == coefficient_64_2);
}

int fn_R000547_4713_16(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int tally_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_19 > 44)
  {
    acc = ((acc + (tally_19 * 2)) + 5) & 127;
    aux ^= tally_19 & 15;
  }
  else
  {
    acc = ((acc - tally_19) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_11) & 63;
  acc ^= aux;
  int coefficient_64 = (aux + st.buffer[1]) & 3;
  switch (coefficient_64)
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

void fn_R000547_4713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int parity_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_19_1)
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

  switch (parity_19_2)
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

  int delta_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_14_1 > 20)
  {
    acc_1 = ((acc_1 + (delta_14_1 * 2)) + 5) & 127;
    aux_1 ^= delta_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_14_2 > 20)
  {
    acc_2 = ((acc_2 + (delta_14_2 * 2)) + 5) & 127;
    aux_2 ^= delta_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_93_1 = local_arr_1[aux_1 % 3];
  int stride_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_19_1 == parity_19_2);
  assert(delta_14_1 == delta_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_93_1 == stride_93_2);
}

int fn_R000547_4713_17(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int parity_19 = (aux + st.buffer[1]) & 3;
  switch (parity_19)
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

  int delta_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_14 > 20)
  {
    acc = ((acc + (delta_14 * 2)) + 5) & 127;
    aux ^= delta_14 & 15;
  }
  else
  {
    acc = ((acc - delta_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_93 = local_arr[aux % 3];
  acc = (acc + (stride_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st_1 = {0};
  struct Transaction_R000547_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_76_1 > 20)
  {
    acc_1 = ((acc_1 + (window_76_1 * 2)) + 5) & 127;
    aux_1 ^= window_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_76_2 > 20)
  {
    acc_2 = ((acc_2 + (window_76_2 * 2)) + 5) & 127;
    aux_2 ^= window_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_10_1)
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

  switch (quantum_10_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_76_1 == window_76_2);
  assert(quantum_10_1 == quantum_10_2);
}

int fn_R000547_4713_18(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_76 > 20)
  {
    acc = ((acc + (window_76 * 2)) + 5) & 127;
    aux ^= window_76 & 15;
  }
  else
  {
    acc = ((acc - window_76) + 11) & 127;
    aux += 3;
  }
  int quantum_10 = (aux + st.buffer[1]) & 3;
  switch (quantum_10)
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

void fn_R000547_4713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st_1 = {0};
  struct Transaction_R000547_4713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_12_1) & 63;
  aux_2 = (aux_2 + tally_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_48_1 = local_arr_1[aux_1 % 3];
  int bound_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_12_1 == tally_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_48_1 == bound_48_2);
}

int fn_R000547_4713_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000547_4713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_12) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_48 = local_arr[aux % 3];
  acc = (acc + (bound_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000547_4713_0 st_1 = {0};
  struct MatrixBlock_R000547_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_55_1)
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

  switch (window_55_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_55_1 == window_55_2);
}

int fn_R000547_4713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000547_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_55 = (aux + st.buffer[1]) & 3;
  switch (window_55)
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

void fn_R000547_4713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000547_4713_0 st_1 = {0};
  struct MatrixBlock_R000547_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int anchor_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_92_1)
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

  switch (anchor_92_2)
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
  int quotient_92_1 = local_arr_1[aux_1 % 3];
  int quotient_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_92_2 * 2)) & 127;
  int weight_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_22_1) & 63;
  aux_2 = (aux_2 + weight_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_92_1 == anchor_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_92_1 == quotient_92_2);
  assert(weight_22_1 == weight_22_2);
}

int fn_R000547_4713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000547_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int anchor_92 = (aux + st.buffer[1]) & 3;
  switch (anchor_92)
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
  int quotient_92 = local_arr[aux % 3];
  acc = (acc + (quotient_92 * 2)) & 127;
  int weight_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000547_4713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st_1 = {0};
  struct FilterState_R000547_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int stride_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_69_1 > 28)
  {
    acc_1 = ((acc_1 + (stride_69_1 * 2)) + 5) & 127;
    aux_1 ^= stride_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_69_2 > 28)
  {
    acc_2 = ((acc_2 + (stride_69_2 * 2)) + 5) & 127;
    aux_2 ^= stride_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_65_1)
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

  switch (segment_65_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_69_1 == stride_69_2);
  assert(segment_65_1 == segment_65_2);
}

int fn_R000547_4713_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000547_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int stride_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_69 > 28)
  {
    acc = ((acc + (stride_69 * 2)) + 5) & 127;
    aux ^= stride_69 & 15;
  }
  else
  {
    acc = ((acc - stride_69) + 11) & 127;
    aux += 3;
  }
  int segment_65 = (aux + st.buffer[1]) & 3;
  switch (segment_65)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000547_4713_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st_1 = {0};
  struct EventLog_R000547_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int index_reg_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_56_1) & 63;
  aux_2 = (aux_2 + index_reg_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_19_1 = local_arr_1[aux_1 % 3];
  int cursor_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_19_2 * 2)) & 127;
  int weight_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_70_1 > 20)
  {
    acc_1 = ((acc_1 + (weight_70_1 * 2)) + 5) & 127;
    aux_1 ^= weight_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_70_2 > 20)
  {
    acc_2 = ((acc_2 + (weight_70_2 * 2)) + 5) & 127;
    aux_2 ^= weight_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_81_1)
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

  switch (segment_81_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_56_1 == index_reg_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_19_1 == cursor_19_2);
  assert(weight_70_1 == weight_70_2);
  assert(segment_81_1 == segment_81_2);
}

int fn_R000547_4713_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000547_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int index_reg_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_56) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_19 = local_arr[aux % 3];
  acc = (acc + (cursor_19 * 2)) & 127;
  int weight_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_70 > 20)
  {
    acc = ((acc + (weight_70 * 2)) + 5) & 127;
    aux ^= weight_70 & 15;
  }
  else
  {
    acc = ((acc - weight_70) + 11) & 127;
    aux += 3;
  }
  int segment_81 = (aux + st.buffer[1]) & 3;
  switch (segment_81)
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

void main()
{
  int sec_r000547_0_1;
  int sec_r000547_0_2;
  int sec_r000547_1_1;
  int sec_r000547_1_2;
  int sec_r000547_2_1;
  int sec_r000547_2_2;
  int sec_r000547_3_1;
  int sec_r000547_3_2;
  int sec_r000547_4_1;
  int sec_r000547_4_2;
  int sec_r000547_5_1;
  int sec_r000547_5_2;
  int sec_r000547_6_1;
  int sec_r000547_6_2;
  int sec_r000547_7_1;
  int sec_r000547_7_2;
  int sec_r000547_8_1;
  int sec_r000547_8_2;
  int sec_r000547_9_1;
  int sec_r000547_9_2;
  int sec_r000547_10_1;
  int sec_r000547_10_2;
  int sec_r000547_11_1;
  int sec_r000547_11_2;
  int sec_r000547_12_1;
  int sec_r000547_12_2;
  int sec_r000547_13_1;
  int sec_r000547_13_2;
  int sec_r000547_14_1;
  int sec_r000547_14_2;
  int sec_r000547_15_1;
  int sec_r000547_15_2;
  int sec_r000547_16_1;
  int sec_r000547_16_2;
  int sec_r000547_17_1;
  int sec_r000547_17_2;
  int sec_r000547_18_1;
  int sec_r000547_18_2;
  int sec_r000547_19_1;
  int sec_r000547_19_2;
  int pub_r000547_0_1;
  int pub_r000547_0_2;
  int pub_r000547_1_1;
  int pub_r000547_1_2;
  int pub_r000547_2_1;
  int pub_r000547_2_2;
  int pub_r000547_3_1;
  int pub_r000547_3_2;
  int pub_r000547_4_1;
  int pub_r000547_4_2;
  int pub_r000547_5_1;
  int pub_r000547_5_2;
  int pub_r000547_6_1;
  int pub_r000547_6_2;
  int pub_r000547_7_1;
  int pub_r000547_7_2;
  int pub_r000547_8_1;
  int pub_r000547_8_2;
  int pub_r000547_9_1;
  int pub_r000547_9_2;
  int pub_r000547_10_1;
  int pub_r000547_10_2;
  int pub_r000547_11_1;
  int pub_r000547_11_2;
  int pub_r000547_12_1;
  int pub_r000547_12_2;
  int pub_r000547_13_1;
  int pub_r000547_13_2;
  int pub_r000547_14_1;
  int pub_r000547_14_2;
  int pub_r000547_15_1;
  int pub_r000547_15_2;
  int pub_r000547_16_1;
  int pub_r000547_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000547_0_1 >= (-100)) && (pub_r000547_0_1 <= 100));
  __CPROVER_assume((pub_r000547_0_2 >= (-100)) && (pub_r000547_0_2 <= 100));
  __CPROVER_assume((pub_r000547_1_1 >= (-100)) && (pub_r000547_1_1 <= 100));
  __CPROVER_assume((pub_r000547_1_2 >= (-100)) && (pub_r000547_1_2 <= 100));
  __CPROVER_assume((pub_r000547_2_1 >= (-100)) && (pub_r000547_2_1 <= 100));
  __CPROVER_assume((pub_r000547_2_2 >= (-100)) && (pub_r000547_2_2 <= 100));
  __CPROVER_assume((pub_r000547_3_1 >= (-100)) && (pub_r000547_3_1 <= 100));
  __CPROVER_assume((pub_r000547_3_2 >= (-100)) && (pub_r000547_3_2 <= 100));
  __CPROVER_assume((pub_r000547_4_1 >= (-100)) && (pub_r000547_4_1 <= 100));
  __CPROVER_assume((pub_r000547_4_2 >= (-100)) && (pub_r000547_4_2 <= 100));
  __CPROVER_assume((pub_r000547_5_1 >= (-100)) && (pub_r000547_5_1 <= 100));
  __CPROVER_assume((pub_r000547_5_2 >= (-100)) && (pub_r000547_5_2 <= 100));
  __CPROVER_assume((pub_r000547_6_1 >= (-100)) && (pub_r000547_6_1 <= 100));
  __CPROVER_assume((pub_r000547_6_2 >= (-100)) && (pub_r000547_6_2 <= 100));
  __CPROVER_assume((pub_r000547_7_1 >= (-100)) && (pub_r000547_7_1 <= 100));
  __CPROVER_assume((pub_r000547_7_2 >= (-100)) && (pub_r000547_7_2 <= 100));
  __CPROVER_assume((pub_r000547_8_1 >= (-100)) && (pub_r000547_8_1 <= 100));
  __CPROVER_assume((pub_r000547_8_2 >= (-100)) && (pub_r000547_8_2 <= 100));
  __CPROVER_assume((pub_r000547_9_1 >= (-100)) && (pub_r000547_9_1 <= 100));
  __CPROVER_assume((pub_r000547_9_2 >= (-100)) && (pub_r000547_9_2 <= 100));
  __CPROVER_assume((pub_r000547_10_1 >= (-100)) && (pub_r000547_10_1 <= 100));
  __CPROVER_assume((pub_r000547_10_2 >= (-100)) && (pub_r000547_10_2 <= 100));
  __CPROVER_assume((pub_r000547_11_1 >= (-100)) && (pub_r000547_11_1 <= 100));
  __CPROVER_assume((pub_r000547_11_2 >= (-100)) && (pub_r000547_11_2 <= 100));
  __CPROVER_assume((pub_r000547_12_1 >= (-100)) && (pub_r000547_12_1 <= 100));
  __CPROVER_assume((pub_r000547_12_2 >= (-100)) && (pub_r000547_12_2 <= 100));
  __CPROVER_assume((pub_r000547_13_1 >= (-100)) && (pub_r000547_13_1 <= 100));
  __CPROVER_assume((pub_r000547_13_2 >= (-100)) && (pub_r000547_13_2 <= 100));
  __CPROVER_assume((pub_r000547_14_1 >= (-100)) && (pub_r000547_14_1 <= 100));
  __CPROVER_assume((pub_r000547_14_2 >= (-100)) && (pub_r000547_14_2 <= 100));
  __CPROVER_assume((pub_r000547_15_1 >= (-100)) && (pub_r000547_15_1 <= 100));
  __CPROVER_assume((pub_r000547_15_2 >= (-100)) && (pub_r000547_15_2 <= 100));
  __CPROVER_assume((pub_r000547_16_1 >= (-100)) && (pub_r000547_16_1 <= 100));
  __CPROVER_assume((pub_r000547_16_2 >= (-100)) && (pub_r000547_16_2 <= 100));
  __CPROVER_assume((sec_r000547_0_1 >= 0) && (sec_r000547_0_1 <= 255));
  __CPROVER_assume((sec_r000547_0_2 >= 0) && (sec_r000547_0_2 <= 255));
  __CPROVER_assume((sec_r000547_1_1 >= 0) && (sec_r000547_1_1 <= 255));
  __CPROVER_assume((sec_r000547_1_2 >= 0) && (sec_r000547_1_2 <= 255));
  __CPROVER_assume((sec_r000547_2_1 >= 0) && (sec_r000547_2_1 <= 255));
  __CPROVER_assume((sec_r000547_2_2 >= 0) && (sec_r000547_2_2 <= 255));
  __CPROVER_assume((sec_r000547_3_1 >= 0) && (sec_r000547_3_1 <= 255));
  __CPROVER_assume((sec_r000547_3_2 >= 0) && (sec_r000547_3_2 <= 255));
  __CPROVER_assume((sec_r000547_4_1 >= 0) && (sec_r000547_4_1 <= 255));
  __CPROVER_assume((sec_r000547_4_2 >= 0) && (sec_r000547_4_2 <= 255));
  __CPROVER_assume((sec_r000547_5_1 >= 0) && (sec_r000547_5_1 <= 255));
  __CPROVER_assume((sec_r000547_5_2 >= 0) && (sec_r000547_5_2 <= 255));
  __CPROVER_assume((sec_r000547_6_1 >= 0) && (sec_r000547_6_1 <= 255));
  __CPROVER_assume((sec_r000547_6_2 >= 0) && (sec_r000547_6_2 <= 255));
  __CPROVER_assume((sec_r000547_7_1 >= 0) && (sec_r000547_7_1 <= 255));
  __CPROVER_assume((sec_r000547_7_2 >= 0) && (sec_r000547_7_2 <= 255));
  __CPROVER_assume((sec_r000547_8_1 >= 0) && (sec_r000547_8_1 <= 255));
  __CPROVER_assume((sec_r000547_8_2 >= 0) && (sec_r000547_8_2 <= 255));
  __CPROVER_assume((sec_r000547_9_1 >= 0) && (sec_r000547_9_1 <= 255));
  __CPROVER_assume((sec_r000547_9_2 >= 0) && (sec_r000547_9_2 <= 255));
  __CPROVER_assume((sec_r000547_10_1 >= 0) && (sec_r000547_10_1 <= 255));
  __CPROVER_assume((sec_r000547_10_2 >= 0) && (sec_r000547_10_2 <= 255));
  __CPROVER_assume((sec_r000547_11_1 >= 0) && (sec_r000547_11_1 <= 255));
  __CPROVER_assume((sec_r000547_11_2 >= 0) && (sec_r000547_11_2 <= 255));
  __CPROVER_assume((sec_r000547_12_1 >= 0) && (sec_r000547_12_1 <= 255));
  __CPROVER_assume((sec_r000547_12_2 >= 0) && (sec_r000547_12_2 <= 255));
  __CPROVER_assume((sec_r000547_13_1 >= 0) && (sec_r000547_13_1 <= 255));
  __CPROVER_assume((sec_r000547_13_2 >= 0) && (sec_r000547_13_2 <= 255));
  __CPROVER_assume((sec_r000547_14_1 >= 0) && (sec_r000547_14_1 <= 255));
  __CPROVER_assume((sec_r000547_14_2 >= 0) && (sec_r000547_14_2 <= 255));
  __CPROVER_assume((sec_r000547_15_1 >= 0) && (sec_r000547_15_1 <= 255));
  __CPROVER_assume((sec_r000547_15_2 >= 0) && (sec_r000547_15_2 <= 255));
  __CPROVER_assume((sec_r000547_16_1 >= 0) && (sec_r000547_16_1 <= 255));
  __CPROVER_assume((sec_r000547_16_2 >= 0) && (sec_r000547_16_2 <= 255));
  __CPROVER_assume((sec_r000547_17_1 >= 0) && (sec_r000547_17_1 <= 255));
  __CPROVER_assume((sec_r000547_17_2 >= 0) && (sec_r000547_17_2 <= 255));
  __CPROVER_assume((sec_r000547_18_1 >= 0) && (sec_r000547_18_1 <= 255));
  __CPROVER_assume((sec_r000547_18_2 >= 0) && (sec_r000547_18_2 <= 255));
  __CPROVER_assume((sec_r000547_19_1 >= 0) && (sec_r000547_19_1 <= 255));
  __CPROVER_assume((sec_r000547_19_2 >= 0) && (sec_r000547_19_2 <= 255));
  struct MatrixBlock_R000547_4713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000547_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000547_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000547_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000547_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000547_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000547_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000547_0_2 + 7) & 15;
  struct FilterState_R000547_4713_1 st_var_1_1 = {0};
  struct FilterState_R000547_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000547_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000547_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000547_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000547_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000547_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000547_0_2 + 9) & 15;
  struct EventLog_R000547_4713_2 st_var_2_1 = {0};
  struct EventLog_R000547_4713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000547_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000547_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000547_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000547_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000547_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000547_0_2 + 11) & 15;
  struct Transaction_R000547_4713_3 st_var_3_1 = {0};
  struct Transaction_R000547_4713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000547_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000547_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000547_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000547_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000547_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000547_0_2 + 13) & 15;
  union ColorPixel_R000547_4713_0 u_var_1;
  union ColorPixel_R000547_4713_0 u_var_2;
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
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 45)
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
  if (stage_v_3_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 45)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
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
  int stage_v_10_1 = ((st_var_2_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_2_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 41)
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
  if (stage_v_10_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 41)
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
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = ((st_var_3_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_3_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 41)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 41)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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
  int stage_v_22_1 = (st_var_2_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_2_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 35)
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
  if (stage_v_25_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 35)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 43)
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
  if (stage_v_29_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 43)
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
  int stage_v_30_1 = (st_var_2_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_2_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((st_var_3_1.buffer[2] * 2) + 112) & 63;
  int stage_v_35_2 = ((st_var_3_2.buffer[2] * 2) + 112) & 63;
  if (stage_v_35_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_35_1) - 5) & 255;
    if (stage_v_35_1 > 33)
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
  if (stage_v_35_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_35_2) - 5) & 255;
    if (stage_v_35_2 > 33)
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
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 40) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
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
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 44) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((st_var_3_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_3_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 36)
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
  if (stage_v_47_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 36)
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
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((sec_r000547_7_1 & 1) != 0)
  {
    if ((sec_r000547_10_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000547_9_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000547_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000547_9_1 + 7) & 127;
  }
  if ((sec_r000547_7_2 & 1) != 0)
  {
    if ((sec_r000547_10_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000547_9_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000547_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000547_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000547_13_1 & 1) != 0)
  {
    if ((sec_r000547_9_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000547_14_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000547_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000547_14_1 + 7) & 127;
  }
  if ((sec_r000547_13_2 & 1) != 0)
  {
    if ((sec_r000547_9_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000547_14_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000547_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000547_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000547_1_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000547_11_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000547_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000547_11_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000547_1_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000547_11_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000547_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000547_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000547_11_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000547_5_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000547_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000547_5_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000547_11_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000547_5_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000547_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000547_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000547_7_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000547_13_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000547_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000547_13_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000547_7_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000547_13_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000547_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000547_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000547_16_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000547_4_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000547_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000547_4_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000547_16_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000547_4_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000547_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000547_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000547_17_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000547_11_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000547_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000547_11_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000547_17_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000547_11_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000547_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000547_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000547_10_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000547_12_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000547_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000547_12_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000547_10_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000547_12_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000547_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000547_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000547_14_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000547_9_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000547_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000547_9_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000547_14_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000547_9_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000547_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000547_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000547_16_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000547_9_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000547_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000547_9_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000547_16_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000547_9_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000547_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000547_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000547_14_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000547_5_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000547_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000547_5_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000547_14_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000547_5_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000547_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000547_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000547_18_1 & 1) != 0)
  {
    if ((sec_r000547_4_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000547_5_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000547_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000547_5_1 + 7) & 127;
  }
  if ((sec_r000547_18_2 & 1) != 0)
  {
    if ((sec_r000547_4_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000547_5_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000547_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000547_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000547_3_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000547_6_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000547_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000547_6_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000547_3_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000547_6_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000547_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000547_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000547_7_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000547_14_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000547_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000547_14_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000547_7_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000547_14_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000547_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000547_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000547_14_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000547_4_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000547_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000547_4_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000547_14_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000547_4_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000547_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000547_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000547_6_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000547_14_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000547_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000547_14_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000547_6_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000547_14_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000547_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000547_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000547_9_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000547_10_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000547_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000547_10_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000547_9_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000547_10_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000547_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000547_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000547_16_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000547_12_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000547_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000547_12_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000547_16_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000547_12_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000547_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000547_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000547_17_1 & 1) != 0)
  {
    if ((sec_r000547_17_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000547_3_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000547_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000547_3_1 + 7) & 127;
  }
  if ((sec_r000547_17_2 & 1) != 0)
  {
    if ((sec_r000547_17_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000547_3_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000547_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000547_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000547_14_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000547_5_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000547_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000547_5_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000547_14_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000547_5_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000547_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000547_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000547_1_1 & 1) != 0)
  {
    if ((sec_r000547_17_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000547_3_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000547_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000547_3_1 + 7) & 127;
  }
  if ((sec_r000547_1_2 & 1) != 0)
  {
    if ((sec_r000547_17_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000547_3_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000547_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000547_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000547_11_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000547_13_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000547_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000547_13_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000547_11_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000547_13_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000547_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000547_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000547_6_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000547_9_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000547_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000547_9_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000547_6_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000547_9_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000547_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000547_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000547_10_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000547_13_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000547_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000547_13_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000547_10_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000547_13_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000547_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000547_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000547_3_1 & 1) != 0)
  {
    if ((sec_r000547_4_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000547_13_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000547_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000547_13_1 + 7) & 127;
  }
  if ((sec_r000547_3_2 & 1) != 0)
  {
    if ((sec_r000547_4_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000547_13_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000547_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000547_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000547_14_1 & 1) != 0)
  {
    if ((sec_r000547_14_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000547_9_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000547_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000547_9_1 + 7) & 127;
  }
  if ((sec_r000547_14_2 & 1) != 0)
  {
    if ((sec_r000547_14_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000547_9_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000547_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000547_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000547_1_1 & 1) != 0)
  {
    if ((sec_r000547_9_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000547_15_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000547_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000547_15_1 + 7) & 127;
  }
  if ((sec_r000547_1_2 & 1) != 0)
  {
    if ((sec_r000547_9_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000547_15_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000547_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000547_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000547_6_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000547_16_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000547_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000547_16_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000547_6_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000547_16_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000547_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000547_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000547_15_1 & 1) != 0)
  {
    if ((sec_r000547_1_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000547_7_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000547_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000547_7_1 + 7) & 127;
  }
  if ((sec_r000547_15_2 & 1) != 0)
  {
    if ((sec_r000547_1_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000547_7_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000547_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000547_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000547_13_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000547_8_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000547_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000547_8_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000547_13_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000547_8_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000547_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000547_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000547_17_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000547_0_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000547_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000547_0_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000547_17_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000547_0_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000547_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000547_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000547_16_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000547_12_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000547_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000547_12_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000547_16_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000547_12_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000547_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000547_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000547_18_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000547_3_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000547_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000547_3_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000547_18_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000547_3_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000547_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000547_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000547_9_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000547_11_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000547_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000547_11_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000547_9_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000547_11_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000547_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000547_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000547_10_1 & 1) != 0)
  {
    if ((sec_r000547_1_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000547_14_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000547_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000547_14_1 + 7) & 127;
  }
  if ((sec_r000547_10_2 & 1) != 0)
  {
    if ((sec_r000547_1_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000547_14_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000547_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000547_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000547_15_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000547_1_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000547_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000547_1_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000547_15_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000547_1_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000547_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000547_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000547_4_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000547_11_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000547_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000547_11_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000547_4_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000547_11_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000547_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000547_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000547_7_1 & 1) != 0)
  {
    if ((sec_r000547_12_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000547_5_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000547_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000547_5_1 + 7) & 127;
  }
  if ((sec_r000547_7_2 & 1) != 0)
  {
    if ((sec_r000547_12_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000547_5_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000547_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000547_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000547_16_1 & 1) != 0)
  {
    if ((sec_r000547_10_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000547_4_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000547_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000547_4_1 + 7) & 127;
  }
  if ((sec_r000547_16_2 & 1) != 0)
  {
    if ((sec_r000547_10_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000547_4_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000547_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000547_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000547_19_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000547_5_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000547_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000547_5_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000547_19_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000547_5_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000547_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000547_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000547_15_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000547_11_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000547_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000547_11_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000547_15_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000547_11_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000547_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000547_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000547_13_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000547_3_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000547_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000547_3_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000547_13_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000547_3_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000547_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000547_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000547_5_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000547_1_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000547_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000547_1_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000547_5_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000547_1_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000547_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000547_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000547_18_1 & 1) != 0)
  {
    if ((sec_r000547_12_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000547_4_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000547_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000547_4_1 + 7) & 127;
  }
  if ((sec_r000547_18_2 & 1) != 0)
  {
    if ((sec_r000547_12_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000547_4_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000547_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000547_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000547_2_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000547_3_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000547_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000547_3_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000547_2_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000547_3_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000547_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000547_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000547_14_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000547_15_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000547_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000547_15_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000547_14_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000547_15_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000547_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000547_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000547_19_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000547_4_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000547_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000547_4_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000547_19_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000547_4_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000547_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000547_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000547_3_1 & 1) != 0)
  {
    if ((sec_r000547_16_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000547_3_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000547_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000547_3_1 + 7) & 127;
  }
  if ((sec_r000547_3_2 & 1) != 0)
  {
    if ((sec_r000547_16_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000547_3_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000547_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000547_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000547_12_1 & 1) != 0)
  {
    if ((sec_r000547_1_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000547_6_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000547_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000547_6_1 + 7) & 127;
  }
  if ((sec_r000547_12_2 & 1) != 0)
  {
    if ((sec_r000547_1_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000547_6_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000547_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000547_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000547_9_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000547_8_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000547_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000547_8_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000547_9_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000547_8_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000547_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000547_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000547_12_1 & 1) != 0)
  {
    if ((sec_r000547_8_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000547_16_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000547_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000547_16_1 + 7) & 127;
  }
  if ((sec_r000547_12_2 & 1) != 0)
  {
    if ((sec_r000547_8_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000547_16_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000547_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000547_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000547_19_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000547_15_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000547_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000547_15_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000547_19_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000547_15_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000547_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000547_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000547_1_1 & 1) != 0)
  {
    if ((sec_r000547_6_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000547_15_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000547_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000547_15_1 + 7) & 127;
  }
  if ((sec_r000547_1_2 & 1) != 0)
  {
    if ((sec_r000547_6_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000547_15_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000547_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000547_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000547_16_1 & 1) != 0)
  {
    if ((sec_r000547_2_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000547_10_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000547_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000547_10_1 + 7) & 127;
  }
  if ((sec_r000547_16_2 & 1) != 0)
  {
    if ((sec_r000547_2_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000547_10_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000547_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000547_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000547_8_1 & 1) != 0)
  {
    if ((sec_r000547_16_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000547_14_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000547_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000547_14_1 + 7) & 127;
  }
  if ((sec_r000547_8_2 & 1) != 0)
  {
    if ((sec_r000547_16_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000547_14_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000547_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000547_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000547_11_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000547_8_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000547_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000547_8_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000547_11_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000547_8_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000547_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000547_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000547_9_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000547_1_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000547_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000547_1_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000547_9_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000547_1_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000547_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000547_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000547_11_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000547_12_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000547_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000547_12_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000547_11_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000547_12_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000547_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000547_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000547_2_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000547_11_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000547_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000547_11_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000547_2_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000547_11_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000547_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000547_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000547_19_1 & 1) != 0)
  {
    if ((sec_r000547_1_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000547_3_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000547_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000547_3_1 + 7) & 127;
  }
  if ((sec_r000547_19_2 & 1) != 0)
  {
    if ((sec_r000547_1_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000547_3_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000547_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000547_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000547_15_1 & 1) != 0)
  {
    if ((sec_r000547_19_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000547_16_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000547_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000547_16_1 + 7) & 127;
  }
  if ((sec_r000547_15_2 & 1) != 0)
  {
    if ((sec_r000547_19_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000547_16_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000547_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000547_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000547_13_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000547_15_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000547_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000547_15_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000547_13_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000547_15_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000547_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000547_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000547_3_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000547_1_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000547_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000547_1_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000547_3_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000547_1_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000547_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000547_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000547_2_1 & 1) != 0)
  {
    if ((sec_r000547_8_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000547_10_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000547_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000547_10_1 + 7) & 127;
  }
  if ((sec_r000547_2_2 & 1) != 0)
  {
    if ((sec_r000547_8_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000547_10_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000547_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000547_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000547_17_1 & 1) != 0)
  {
    if ((sec_r000547_9_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000547_11_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000547_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000547_11_1 + 7) & 127;
  }
  if ((sec_r000547_17_2 & 1) != 0)
  {
    if ((sec_r000547_9_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000547_11_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000547_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000547_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000547_18_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000547_10_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000547_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000547_10_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000547_18_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000547_10_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000547_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000547_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000547_19_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000547_12_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000547_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000547_12_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000547_19_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000547_12_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000547_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000547_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000547_0_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000547_12_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000547_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000547_12_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000547_0_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000547_12_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000547_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000547_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000547_14_1 & 1) != 0)
  {
    if ((sec_r000547_5_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000547_13_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000547_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000547_13_1 + 7) & 127;
  }
  if ((sec_r000547_14_2 & 1) != 0)
  {
    if ((sec_r000547_5_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000547_13_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000547_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000547_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000547_9_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000547_11_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000547_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000547_11_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000547_9_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000547_11_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000547_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000547_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000547_12_1 & 1) != 0)
  {
    if ((sec_r000547_2_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000547_13_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000547_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000547_13_1 + 7) & 127;
  }
  if ((sec_r000547_12_2 & 1) != 0)
  {
    if ((sec_r000547_2_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000547_13_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000547_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000547_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000547_2_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000547_10_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000547_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000547_10_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000547_2_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000547_10_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000547_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000547_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000547_15_1 & 1) != 0)
  {
    if ((sec_r000547_13_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000547_13_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000547_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000547_13_1 + 7) & 127;
  }
  if ((sec_r000547_15_2 & 1) != 0)
  {
    if ((sec_r000547_13_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000547_13_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000547_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000547_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000547_10_1 != sec_r000547_10_2);
  __CPROVER_assume(pub_r000547_2_1 == pub_r000547_2_2);
  __CPROVER_assume(sec_r000547_11_1 != sec_r000547_11_2);
  __CPROVER_assume(sec_r000547_15_1 != sec_r000547_15_2);
  __CPROVER_assume(sec_r000547_5_1 != sec_r000547_5_2);
  __CPROVER_assume(pub_r000547_1_1 == pub_r000547_1_2);
  __CPROVER_assume(sec_r000547_4_1 != sec_r000547_4_2);
  __CPROVER_assume(pub_r000547_4_1 == pub_r000547_4_2);
  __CPROVER_assume(pub_r000547_10_1 == pub_r000547_10_2);
  __CPROVER_assume(pub_r000547_7_1 == pub_r000547_7_2);
  __CPROVER_assume(sec_r000547_1_1 != sec_r000547_1_2);
  __CPROVER_assume(pub_r000547_8_1 == pub_r000547_8_2);
  __CPROVER_assume(sec_r000547_18_1 != sec_r000547_18_2);
  __CPROVER_assume(pub_r000547_6_1 == pub_r000547_6_2);
  __CPROVER_assume(pub_r000547_13_1 == pub_r000547_13_2);
  __CPROVER_assume(pub_r000547_14_1 == pub_r000547_14_2);
  __CPROVER_assume(sec_r000547_12_1 != sec_r000547_12_2);
  __CPROVER_assume(pub_r000547_15_1 == pub_r000547_15_2);
  __CPROVER_assume(sec_r000547_17_1 != sec_r000547_17_2);
  __CPROVER_assume(sec_r000547_13_1 != sec_r000547_13_2);
  __CPROVER_assume(sec_r000547_3_1 != sec_r000547_3_2);
  __CPROVER_assume(pub_r000547_16_1 == pub_r000547_16_2);
  __CPROVER_assume(sec_r000547_0_1 != sec_r000547_0_2);
  __CPROVER_assume(pub_r000547_12_1 == pub_r000547_12_2);
  __CPROVER_assume(pub_r000547_5_1 == pub_r000547_5_2);
  __CPROVER_assume(pub_r000547_11_1 == pub_r000547_11_2);
  __CPROVER_assume(pub_r000547_9_1 == pub_r000547_9_2);
  __CPROVER_assume(sec_r000547_6_1 != sec_r000547_6_2);
  __CPROVER_assume(pub_r000547_3_1 == pub_r000547_3_2);
  __CPROVER_assume(sec_r000547_9_1 != sec_r000547_9_2);
  __CPROVER_assume(pub_r000547_0_1 == pub_r000547_0_2);
  __CPROVER_assume(sec_r000547_7_1 != sec_r000547_7_2);
  __CPROVER_assume(sec_r000547_8_1 != sec_r000547_8_2);
  __CPROVER_assume(sec_r000547_16_1 != sec_r000547_16_2);
  __CPROVER_assume(sec_r000547_19_1 != sec_r000547_19_2);
  __CPROVER_assume(sec_r000547_14_1 != sec_r000547_14_2);
  __CPROVER_assume(sec_r000547_2_1 != sec_r000547_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.density == st_var_0_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.fee == st_var_3_2.fee);
  assert(st_var_3_1.status == st_var_3_2.status);
  assert(st_var_3_1.balance == st_var_3_2.balance);
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
  assert(stage_v_122_1 == stage_v_122_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(stage_v_125_1 == stage_v_125_2);
}


