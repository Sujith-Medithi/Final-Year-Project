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
struct Transaction_R000122_2213_0
{
  int balance;
  unsigned char rate;
  int fee;
  int status;
  unsigned char account_id;
  int buffer[3];
};
struct EventLog_R000122_2213_1
{
  int seq;
  unsigned char signature;
  int timestamp;
  int severity;
  int buffer[3];
};
struct SensorNode_R000122_2213_2
{
  int calib;
  short reading;
  int gain;
  int buffer[3];
};
struct StreamBuffer_R000122_2213_3
{
  int head;
  unsigned char tail;
  unsigned char state;
  short checksum;
  short capacity;
  int buffer[3];
};
union TelemetryField_R000122_2213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000122_2213_1
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
void fn_R000122_2213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st_1 = {0};
  struct SensorNode_R000122_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quantum_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_65_1)
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

  switch (quantum_65_2)
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
  int phase_83_1 = local_arr_1[aux_1 % 3];
  int phase_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_83_2 * 2)) & 127;
  int coefficient_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_85_1) & 63;
  aux_2 = (aux_2 + coefficient_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_65_1 == quantum_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_83_1 == phase_83_2);
  assert(coefficient_85_1 == coefficient_85_2);
}

int fn_R000122_2213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quantum_65 = (aux + st.buffer[1]) & 3;
  switch (quantum_65)
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
  int phase_83 = local_arr[aux % 3];
  acc = (acc + (phase_83 * 2)) & 127;
  int coefficient_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_85) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000122_2213_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st_1 = {0};
  struct Transaction_R000122_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_78_1 = local_arr_1[aux_1 % 3];
  int parity_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_78_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_94_1) & 63;
  aux_2 = (aux_2 + sample_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_78_1 == parity_78_2);
  assert(sample_94_1 == sample_94_2);
}

int fn_R000122_2213_1(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int parity_78 = local_arr[aux % 3];
  acc = (acc + (parity_78 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000122_2213_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st_1 = {0};
  struct SensorNode_R000122_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tally_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_84_1)
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

  switch (tally_84_2)
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
  int weight_30_1 = local_arr_1[aux_1 % 3];
  int weight_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_30_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_37_1) & 63;
  aux_2 = (aux_2 + coefficient_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_84_1 == tally_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_30_1 == weight_30_2);
  assert(coefficient_37_1 == coefficient_37_2);
}

int fn_R000122_2213_2(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tally_84 = (aux + st.buffer[1]) & 3;
  switch (tally_84)
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
  int weight_30 = local_arr[aux % 3];
  acc = (acc + (weight_30 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000122_2213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st_1 = {0};
  struct SensorNode_R000122_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_89_1)
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

  switch (accumulator_89_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_89_1 == accumulator_89_2);
}

int fn_R000122_2213_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_89 = (aux + st.buffer[1]) & 3;
  switch (accumulator_89)
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

void fn_R000122_2213_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000122_2213_3 st_1 = {0};
  struct StreamBuffer_R000122_2213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int mask_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_51_1)
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

  switch (mask_51_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_21_1 > 50)
  {
    acc_1 = ((acc_1 + (scale_21_1 * 2)) + 5) & 127;
    aux_1 ^= scale_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_21_2 > 50)
  {
    acc_2 = ((acc_2 + (scale_21_2 * 2)) + 5) & 127;
    aux_2 ^= scale_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_51_1 == mask_51_2);
  assert(scale_21_1 == scale_21_2);
}

int fn_R000122_2213_4(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000122_2213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int mask_51 = (aux + st.buffer[1]) & 3;
  switch (mask_51)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_21 > 50)
  {
    acc = ((acc + (scale_21 * 2)) + 5) & 127;
    aux ^= scale_21 & 15;
  }
  else
  {
    acc = ((acc - scale_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000122_2213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st_1 = {0};
  struct Transaction_R000122_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int index_reg_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_28_1)
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

  switch (index_reg_28_2)
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

  int accumulator_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_25_1) & 63;
  aux_2 = (aux_2 + accumulator_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_60_1 = local_arr_1[aux_1 % 3];
  int pivot_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_28_1 == index_reg_28_2);
  assert(accumulator_25_1 == accumulator_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_60_1 == pivot_60_2);
}

int fn_R000122_2213_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int index_reg_28 = (aux + st.buffer[1]) & 3;
  switch (index_reg_28)
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

  int accumulator_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_25) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_60 = local_arr[aux % 3];
  acc = (acc + (pivot_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000122_2213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st_1 = {0};
  struct SensorNode_R000122_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int anchor_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_25_1 > 41)
  {
    acc_1 = ((acc_1 + (anchor_25_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_25_2 > 41)
  {
    acc_2 = ((acc_2 + (anchor_25_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_25_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_25_1 == anchor_25_2);
}

int fn_R000122_2213_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int anchor_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_25 > 41)
  {
    acc = ((acc + (anchor_25 * 2)) + 5) & 127;
    aux ^= anchor_25 & 15;
  }
  else
  {
    acc = ((acc - anchor_25) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000122_2213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st_1 = {0};
  struct Transaction_R000122_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int damping_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_23_1) & 63;
  aux_2 = (aux_2 + damping_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_74_1)
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

  switch (bound_74_2)
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

  int anchor_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_97_1 > 28)
  {
    acc_1 = ((acc_1 + (anchor_97_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_97_2 > 28)
  {
    acc_2 = ((acc_2 + (anchor_97_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_23_1 == damping_23_2);
  assert(bound_74_1 == bound_74_2);
  assert(anchor_97_1 == anchor_97_2);
}

int fn_R000122_2213_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int damping_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_23) & 63;
  acc ^= aux;
  int bound_74 = (aux + st.buffer[1]) & 3;
  switch (bound_74)
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

  int anchor_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_97 > 28)
  {
    acc = ((acc + (anchor_97 * 2)) + 5) & 127;
    aux ^= anchor_97 & 15;
  }
  else
  {
    acc = ((acc - anchor_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000122_2213_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st_1 = {0};
  struct SensorNode_R000122_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_54_1 = local_arr_1[aux_1 % 3];
  int tally_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_54_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_21_1)
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

  switch (offset_21_2)
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

  int mask_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_41_1 > 32)
  {
    acc_1 = ((acc_1 + (mask_41_1 * 2)) + 5) & 127;
    aux_1 ^= mask_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_41_2 > 32)
  {
    acc_2 = ((acc_2 + (mask_41_2 * 2)) + 5) & 127;
    aux_2 ^= mask_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_54_1 == tally_54_2);
  assert(offset_21_1 == offset_21_2);
  assert(mask_41_1 == mask_41_2);
}

int fn_R000122_2213_8(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int tally_54 = local_arr[aux % 3];
  acc = (acc + (tally_54 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_21 = (aux + st.buffer[1]) & 3;
  switch (offset_21)
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

  int mask_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_41 > 32)
  {
    acc = ((acc + (mask_41 * 2)) + 5) & 127;
    aux ^= mask_41 & 15;
  }
  else
  {
    acc = ((acc - mask_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000122_2213_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st_1 = {0};
  struct Transaction_R000122_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_92_1 > 50)
  {
    acc_1 = ((acc_1 + (accumulator_92_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_92_2 > 50)
  {
    acc_2 = ((acc_2 + (accumulator_92_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_92_1 == accumulator_92_2);
}

int fn_R000122_2213_9(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_92 > 50)
  {
    acc = ((acc + (accumulator_92 * 2)) + 5) & 127;
    aux ^= accumulator_92 & 15;
  }
  else
  {
    acc = ((acc - accumulator_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000122_2213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st_1 = {0};
  struct EventLog_R000122_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int damping_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_40_1) & 63;
  aux_2 = (aux_2 + damping_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_44_1 > 28)
  {
    acc_1 = ((acc_1 + (window_44_1 * 2)) + 5) & 127;
    aux_1 ^= window_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_44_2 > 28)
  {
    acc_2 = ((acc_2 + (window_44_2 * 2)) + 5) & 127;
    aux_2 ^= window_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_40_1 == damping_40_2);
  assert(window_44_1 == window_44_2);
}

int fn_R000122_2213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int damping_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_40) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_44 > 28)
  {
    acc = ((acc + (window_44 * 2)) + 5) & 127;
    aux ^= window_44 & 15;
  }
  else
  {
    acc = ((acc - window_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000122_2213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st_1 = {0};
  struct EventLog_R000122_2213_1 st_2 = {0};
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
  int vector_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_72_1) & 63;
  aux_2 = (aux_2 + vector_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_72_1 == vector_72_2);
}

int fn_R000122_2213_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_72) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000122_2213_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000122_2213_3 st_1 = {0};
  struct StreamBuffer_R000122_2213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int stride_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_25_1 > 12)
  {
    acc_1 = ((acc_1 + (stride_25_1 * 2)) + 5) & 127;
    aux_1 ^= stride_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_25_2 > 12)
  {
    acc_2 = ((acc_2 + (stride_25_2 * 2)) + 5) & 127;
    aux_2 ^= stride_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_42_1) & 63;
  aux_2 = (aux_2 + window_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_18_1)
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

  switch (delta_18_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_25_1 == stride_25_2);
  assert(window_42_1 == window_42_2);
  assert(delta_18_1 == delta_18_2);
}

int fn_R000122_2213_12(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000122_2213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int stride_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_25 > 12)
  {
    acc = ((acc + (stride_25 * 2)) + 5) & 127;
    aux ^= stride_25 & 15;
  }
  else
  {
    acc = ((acc - stride_25) + 11) & 127;
    aux += 3;
  }
  int window_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_42) & 63;
  acc ^= aux;
  int delta_18 = (aux + st.buffer[1]) & 3;
  switch (delta_18)
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
  return (acc + aux) & 255;
}

void fn_R000122_2213_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000122_2213_3 st_1 = {0};
  struct StreamBuffer_R000122_2213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int cursor_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_90_1)
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

  switch (cursor_90_2)
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
  int accumulator_19_1 = local_arr_1[aux_1 % 3];
  int accumulator_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_90_1 == cursor_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_19_1 == accumulator_19_2);
}

int fn_R000122_2213_13(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000122_2213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int cursor_90 = (aux + st.buffer[1]) & 3;
  switch (cursor_90)
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
  int accumulator_19 = local_arr[aux % 3];
  acc = (acc + (accumulator_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000122_2213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st_1 = {0};
  struct SensorNode_R000122_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_53_1)
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

  switch (damping_53_2)
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

  int stride_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_15_1) & 63;
  aux_2 = (aux_2 + stride_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_10_1 > 16)
  {
    acc_1 = ((acc_1 + (window_10_1 * 2)) + 5) & 127;
    aux_1 ^= window_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_10_2 > 16)
  {
    acc_2 = ((acc_2 + (window_10_2 * 2)) + 5) & 127;
    aux_2 ^= window_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_53_1 == damping_53_2);
  assert(stride_15_1 == stride_15_2);
  assert(window_10_1 == window_10_2);
}

int fn_R000122_2213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_53 = (aux + st.buffer[1]) & 3;
  switch (damping_53)
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

  int stride_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_15) & 63;
  acc ^= aux;
  int window_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_10 > 16)
  {
    acc = ((acc + (window_10 * 2)) + 5) & 127;
    aux ^= window_10 & 15;
  }
  else
  {
    acc = ((acc - window_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000122_2213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st_1 = {0};
  struct EventLog_R000122_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int phase_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_88_1)
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

  switch (phase_88_2)
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

  int quantum_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_78_1 > 19)
  {
    acc_1 = ((acc_1 + (quantum_78_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_78_2 > 19)
  {
    acc_2 = ((acc_2 + (quantum_78_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_78_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_58_1 = local_arr_1[aux_1 % 3];
  int scale_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_88_1 == phase_88_2);
  assert(quantum_78_1 == quantum_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_58_1 == scale_58_2);
}

int fn_R000122_2213_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int phase_88 = (aux + st.buffer[1]) & 3;
  switch (phase_88)
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

  int quantum_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_78 > 19)
  {
    acc = ((acc + (quantum_78 * 2)) + 5) & 127;
    aux ^= quantum_78 & 15;
  }
  else
  {
    acc = ((acc - quantum_78) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_58 = local_arr[aux % 3];
  acc = (acc + (scale_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000122_2213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st_1 = {0};
  struct EventLog_R000122_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_78_1 = local_arr_1[aux_1 % 3];
  int mask_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_78_2 * 2)) & 127;
  int factor_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_45_1) & 63;
  aux_2 = (aux_2 + factor_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_64_1 > 29)
  {
    acc_1 = ((acc_1 + (quotient_64_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_64_2 > 29)
  {
    acc_2 = ((acc_2 + (quotient_64_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_78_1 == mask_78_2);
  assert(factor_45_1 == factor_45_2);
  assert(quotient_64_1 == quotient_64_2);
}

int fn_R000122_2213_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int mask_78 = local_arr[aux % 3];
  acc = (acc + (mask_78 * 2)) & 127;
  int factor_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_45) & 63;
  acc ^= aux;
  int quotient_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_64 > 29)
  {
    acc = ((acc + (quotient_64 * 2)) + 5) & 127;
    aux ^= quotient_64 & 15;
  }
  else
  {
    acc = ((acc - quotient_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000122_2213_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st_1 = {0};
  struct SensorNode_R000122_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int window_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_53_1) & 63;
  aux_2 = (aux_2 + window_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_65_1)
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

  switch (residue_65_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_53_1 == window_53_2);
  assert(residue_65_1 == residue_65_2);
}

int fn_R000122_2213_17(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int window_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_53) & 63;
  acc ^= aux;
  int residue_65 = (aux + st.buffer[1]) & 3;
  switch (residue_65)
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

void fn_R000122_2213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st_1 = {0};
  struct Transaction_R000122_2213_0 st_2 = {0};
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
  int index_reg_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_86_1 > 24)
  {
    acc_1 = ((acc_1 + (index_reg_86_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_86_2 > 24)
  {
    acc_2 = ((acc_2 + (index_reg_86_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_86_1 == index_reg_86_2);
}

int fn_R000122_2213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_86 > 24)
  {
    acc = ((acc + (index_reg_86 * 2)) + 5) & 127;
    aux ^= index_reg_86 & 15;
  }
  else
  {
    acc = ((acc - index_reg_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000122_2213_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st_1 = {0};
  struct SensorNode_R000122_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int offset_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_89_1 > 48)
  {
    acc_1 = ((acc_1 + (offset_89_1 * 2)) + 5) & 127;
    aux_1 ^= offset_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_89_2 > 48)
  {
    acc_2 = ((acc_2 + (offset_89_2 * 2)) + 5) & 127;
    aux_2 ^= offset_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_50_1 = local_arr_1[aux_1 % 3];
  int scale_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_89_1 == offset_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_50_1 == scale_50_2);
}

int fn_R000122_2213_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000122_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int offset_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_89 > 48)
  {
    acc = ((acc + (offset_89 * 2)) + 5) & 127;
    aux ^= offset_89 & 15;
  }
  else
  {
    acc = ((acc - offset_89) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_50 = local_arr[aux % 3];
  acc = (acc + (scale_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000122_2213_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st_1 = {0};
  struct Transaction_R000122_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_97_1 = local_arr_1[aux_1 % 3];
  int factor_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_97_2 * 2)) & 127;
  int weight_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_15_1 > 37)
  {
    acc_1 = ((acc_1 + (weight_15_1 * 2)) + 5) & 127;
    aux_1 ^= weight_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_15_2 > 37)
  {
    acc_2 = ((acc_2 + (weight_15_2 * 2)) + 5) & 127;
    aux_2 ^= weight_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_97_1 == factor_97_2);
  assert(weight_15_1 == weight_15_2);
}

int fn_R000122_2213_20(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000122_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int factor_97 = local_arr[aux % 3];
  acc = (acc + (factor_97 * 2)) & 127;
  int weight_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_15 > 37)
  {
    acc = ((acc + (weight_15 * 2)) + 5) & 127;
    aux ^= weight_15 & 15;
  }
  else
  {
    acc = ((acc - weight_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000122_2213_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000122_2213_3 st_1 = {0};
  struct StreamBuffer_R000122_2213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_71_1) & 63;
  aux_2 = (aux_2 + scale_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_71_1 == scale_71_2);
}

int fn_R000122_2213_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000122_2213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000122_2213_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st_1 = {0};
  struct EventLog_R000122_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_14_1 = local_arr_1[aux_1 % 3];
  int quantum_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_14_2 * 2)) & 127;
  int offset_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_45_1)
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

  switch (offset_45_2)
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

  int margin_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_44_1) & 63;
  aux_2 = (aux_2 + margin_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_14_1 == quantum_14_2);
  assert(offset_45_1 == offset_45_2);
  assert(margin_44_1 == margin_44_2);
}

int fn_R000122_2213_22(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int quantum_14 = local_arr[aux % 3];
  acc = (acc + (quantum_14 * 2)) & 127;
  int offset_45 = (aux + st.buffer[1]) & 3;
  switch (offset_45)
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

  int margin_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_44) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000122_2213_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st_1 = {0};
  struct EventLog_R000122_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int quantum_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_77_1)
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

  switch (quantum_77_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_77_1 == quantum_77_2);
}

int fn_R000122_2213_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000122_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int quantum_77 = (aux + st.buffer[1]) & 3;
  switch (quantum_77)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000122_0_1;
  int sec_r000122_0_2;
  int sec_r000122_1_1;
  int sec_r000122_1_2;
  int sec_r000122_2_1;
  int sec_r000122_2_2;
  int sec_r000122_3_1;
  int sec_r000122_3_2;
  int sec_r000122_4_1;
  int sec_r000122_4_2;
  int sec_r000122_5_1;
  int sec_r000122_5_2;
  int sec_r000122_6_1;
  int sec_r000122_6_2;
  int sec_r000122_7_1;
  int sec_r000122_7_2;
  int sec_r000122_8_1;
  int sec_r000122_8_2;
  int sec_r000122_9_1;
  int sec_r000122_9_2;
  int sec_r000122_10_1;
  int sec_r000122_10_2;
  int sec_r000122_11_1;
  int sec_r000122_11_2;
  int sec_r000122_12_1;
  int sec_r000122_12_2;
  int sec_r000122_13_1;
  int sec_r000122_13_2;
  int sec_r000122_14_1;
  int sec_r000122_14_2;
  int sec_r000122_15_1;
  int sec_r000122_15_2;
  int sec_r000122_16_1;
  int sec_r000122_16_2;
  int sec_r000122_17_1;
  int sec_r000122_17_2;
  int sec_r000122_18_1;
  int sec_r000122_18_2;
  int sec_r000122_19_1;
  int sec_r000122_19_2;
  int sec_r000122_20_1;
  int sec_r000122_20_2;
  int sec_r000122_21_1;
  int sec_r000122_21_2;
  int sec_r000122_22_1;
  int sec_r000122_22_2;
  int pub_r000122_0_1;
  int pub_r000122_0_2;
  int pub_r000122_1_1;
  int pub_r000122_1_2;
  int pub_r000122_2_1;
  int pub_r000122_2_2;
  int pub_r000122_3_1;
  int pub_r000122_3_2;
  int pub_r000122_4_1;
  int pub_r000122_4_2;
  int pub_r000122_5_1;
  int pub_r000122_5_2;
  int pub_r000122_6_1;
  int pub_r000122_6_2;
  int pub_r000122_7_1;
  int pub_r000122_7_2;
  int pub_r000122_8_1;
  int pub_r000122_8_2;
  int pub_r000122_9_1;
  int pub_r000122_9_2;
  int pub_r000122_10_1;
  int pub_r000122_10_2;
  int pub_r000122_11_1;
  int pub_r000122_11_2;
  int pub_r000122_12_1;
  int pub_r000122_12_2;
  int pub_r000122_13_1;
  int pub_r000122_13_2;
  int pub_r000122_14_1;
  int pub_r000122_14_2;
  int pub_r000122_15_1;
  int pub_r000122_15_2;
  int pub_r000122_16_1;
  int pub_r000122_16_2;
  int pub_r000122_17_1;
  int pub_r000122_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000122_0_1 >= (-100)) && (pub_r000122_0_1 <= 100));
  __CPROVER_assume((pub_r000122_0_2 >= (-100)) && (pub_r000122_0_2 <= 100));
  __CPROVER_assume((pub_r000122_1_1 >= (-100)) && (pub_r000122_1_1 <= 100));
  __CPROVER_assume((pub_r000122_1_2 >= (-100)) && (pub_r000122_1_2 <= 100));
  __CPROVER_assume((pub_r000122_2_1 >= (-100)) && (pub_r000122_2_1 <= 100));
  __CPROVER_assume((pub_r000122_2_2 >= (-100)) && (pub_r000122_2_2 <= 100));
  __CPROVER_assume((pub_r000122_3_1 >= (-100)) && (pub_r000122_3_1 <= 100));
  __CPROVER_assume((pub_r000122_3_2 >= (-100)) && (pub_r000122_3_2 <= 100));
  __CPROVER_assume((pub_r000122_4_1 >= (-100)) && (pub_r000122_4_1 <= 100));
  __CPROVER_assume((pub_r000122_4_2 >= (-100)) && (pub_r000122_4_2 <= 100));
  __CPROVER_assume((pub_r000122_5_1 >= (-100)) && (pub_r000122_5_1 <= 100));
  __CPROVER_assume((pub_r000122_5_2 >= (-100)) && (pub_r000122_5_2 <= 100));
  __CPROVER_assume((pub_r000122_6_1 >= (-100)) && (pub_r000122_6_1 <= 100));
  __CPROVER_assume((pub_r000122_6_2 >= (-100)) && (pub_r000122_6_2 <= 100));
  __CPROVER_assume((pub_r000122_7_1 >= (-100)) && (pub_r000122_7_1 <= 100));
  __CPROVER_assume((pub_r000122_7_2 >= (-100)) && (pub_r000122_7_2 <= 100));
  __CPROVER_assume((pub_r000122_8_1 >= (-100)) && (pub_r000122_8_1 <= 100));
  __CPROVER_assume((pub_r000122_8_2 >= (-100)) && (pub_r000122_8_2 <= 100));
  __CPROVER_assume((pub_r000122_9_1 >= (-100)) && (pub_r000122_9_1 <= 100));
  __CPROVER_assume((pub_r000122_9_2 >= (-100)) && (pub_r000122_9_2 <= 100));
  __CPROVER_assume((pub_r000122_10_1 >= (-100)) && (pub_r000122_10_1 <= 100));
  __CPROVER_assume((pub_r000122_10_2 >= (-100)) && (pub_r000122_10_2 <= 100));
  __CPROVER_assume((pub_r000122_11_1 >= (-100)) && (pub_r000122_11_1 <= 100));
  __CPROVER_assume((pub_r000122_11_2 >= (-100)) && (pub_r000122_11_2 <= 100));
  __CPROVER_assume((pub_r000122_12_1 >= (-100)) && (pub_r000122_12_1 <= 100));
  __CPROVER_assume((pub_r000122_12_2 >= (-100)) && (pub_r000122_12_2 <= 100));
  __CPROVER_assume((pub_r000122_13_1 >= (-100)) && (pub_r000122_13_1 <= 100));
  __CPROVER_assume((pub_r000122_13_2 >= (-100)) && (pub_r000122_13_2 <= 100));
  __CPROVER_assume((pub_r000122_14_1 >= (-100)) && (pub_r000122_14_1 <= 100));
  __CPROVER_assume((pub_r000122_14_2 >= (-100)) && (pub_r000122_14_2 <= 100));
  __CPROVER_assume((pub_r000122_15_1 >= (-100)) && (pub_r000122_15_1 <= 100));
  __CPROVER_assume((pub_r000122_15_2 >= (-100)) && (pub_r000122_15_2 <= 100));
  __CPROVER_assume((pub_r000122_16_1 >= (-100)) && (pub_r000122_16_1 <= 100));
  __CPROVER_assume((pub_r000122_16_2 >= (-100)) && (pub_r000122_16_2 <= 100));
  __CPROVER_assume((pub_r000122_17_1 >= (-100)) && (pub_r000122_17_1 <= 100));
  __CPROVER_assume((pub_r000122_17_2 >= (-100)) && (pub_r000122_17_2 <= 100));
  __CPROVER_assume((sec_r000122_0_1 >= 0) && (sec_r000122_0_1 <= 255));
  __CPROVER_assume((sec_r000122_0_2 >= 0) && (sec_r000122_0_2 <= 255));
  __CPROVER_assume((sec_r000122_1_1 >= 0) && (sec_r000122_1_1 <= 255));
  __CPROVER_assume((sec_r000122_1_2 >= 0) && (sec_r000122_1_2 <= 255));
  __CPROVER_assume((sec_r000122_2_1 >= 0) && (sec_r000122_2_1 <= 255));
  __CPROVER_assume((sec_r000122_2_2 >= 0) && (sec_r000122_2_2 <= 255));
  __CPROVER_assume((sec_r000122_3_1 >= 0) && (sec_r000122_3_1 <= 255));
  __CPROVER_assume((sec_r000122_3_2 >= 0) && (sec_r000122_3_2 <= 255));
  __CPROVER_assume((sec_r000122_4_1 >= 0) && (sec_r000122_4_1 <= 255));
  __CPROVER_assume((sec_r000122_4_2 >= 0) && (sec_r000122_4_2 <= 255));
  __CPROVER_assume((sec_r000122_5_1 >= 0) && (sec_r000122_5_1 <= 255));
  __CPROVER_assume((sec_r000122_5_2 >= 0) && (sec_r000122_5_2 <= 255));
  __CPROVER_assume((sec_r000122_6_1 >= 0) && (sec_r000122_6_1 <= 255));
  __CPROVER_assume((sec_r000122_6_2 >= 0) && (sec_r000122_6_2 <= 255));
  __CPROVER_assume((sec_r000122_7_1 >= 0) && (sec_r000122_7_1 <= 255));
  __CPROVER_assume((sec_r000122_7_2 >= 0) && (sec_r000122_7_2 <= 255));
  __CPROVER_assume((sec_r000122_8_1 >= 0) && (sec_r000122_8_1 <= 255));
  __CPROVER_assume((sec_r000122_8_2 >= 0) && (sec_r000122_8_2 <= 255));
  __CPROVER_assume((sec_r000122_9_1 >= 0) && (sec_r000122_9_1 <= 255));
  __CPROVER_assume((sec_r000122_9_2 >= 0) && (sec_r000122_9_2 <= 255));
  __CPROVER_assume((sec_r000122_10_1 >= 0) && (sec_r000122_10_1 <= 255));
  __CPROVER_assume((sec_r000122_10_2 >= 0) && (sec_r000122_10_2 <= 255));
  __CPROVER_assume((sec_r000122_11_1 >= 0) && (sec_r000122_11_1 <= 255));
  __CPROVER_assume((sec_r000122_11_2 >= 0) && (sec_r000122_11_2 <= 255));
  __CPROVER_assume((sec_r000122_12_1 >= 0) && (sec_r000122_12_1 <= 255));
  __CPROVER_assume((sec_r000122_12_2 >= 0) && (sec_r000122_12_2 <= 255));
  __CPROVER_assume((sec_r000122_13_1 >= 0) && (sec_r000122_13_1 <= 255));
  __CPROVER_assume((sec_r000122_13_2 >= 0) && (sec_r000122_13_2 <= 255));
  __CPROVER_assume((sec_r000122_14_1 >= 0) && (sec_r000122_14_1 <= 255));
  __CPROVER_assume((sec_r000122_14_2 >= 0) && (sec_r000122_14_2 <= 255));
  __CPROVER_assume((sec_r000122_15_1 >= 0) && (sec_r000122_15_1 <= 255));
  __CPROVER_assume((sec_r000122_15_2 >= 0) && (sec_r000122_15_2 <= 255));
  __CPROVER_assume((sec_r000122_16_1 >= 0) && (sec_r000122_16_1 <= 255));
  __CPROVER_assume((sec_r000122_16_2 >= 0) && (sec_r000122_16_2 <= 255));
  __CPROVER_assume((sec_r000122_17_1 >= 0) && (sec_r000122_17_1 <= 255));
  __CPROVER_assume((sec_r000122_17_2 >= 0) && (sec_r000122_17_2 <= 255));
  __CPROVER_assume((sec_r000122_18_1 >= 0) && (sec_r000122_18_1 <= 255));
  __CPROVER_assume((sec_r000122_18_2 >= 0) && (sec_r000122_18_2 <= 255));
  __CPROVER_assume((sec_r000122_19_1 >= 0) && (sec_r000122_19_1 <= 255));
  __CPROVER_assume((sec_r000122_19_2 >= 0) && (sec_r000122_19_2 <= 255));
  __CPROVER_assume((sec_r000122_20_1 >= 0) && (sec_r000122_20_1 <= 255));
  __CPROVER_assume((sec_r000122_20_2 >= 0) && (sec_r000122_20_2 <= 255));
  __CPROVER_assume((sec_r000122_21_1 >= 0) && (sec_r000122_21_1 <= 255));
  __CPROVER_assume((sec_r000122_21_2 >= 0) && (sec_r000122_21_2 <= 255));
  __CPROVER_assume((sec_r000122_22_1 >= 0) && (sec_r000122_22_1 <= 255));
  __CPROVER_assume((sec_r000122_22_2 >= 0) && (sec_r000122_22_2 <= 255));
  struct Transaction_R000122_2213_0 st_var_0_1 = {0};
  struct Transaction_R000122_2213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000122_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000122_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000122_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000122_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000122_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000122_0_2 + 7) & 15;
  struct EventLog_R000122_2213_1 st_var_1_1 = {0};
  struct EventLog_R000122_2213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000122_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000122_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000122_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000122_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000122_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000122_0_2 + 9) & 15;
  struct SensorNode_R000122_2213_2 st_var_2_1 = {0};
  struct SensorNode_R000122_2213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000122_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000122_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000122_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000122_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000122_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000122_0_2 + 11) & 15;
  struct StreamBuffer_R000122_2213_3 st_var_3_1 = {0};
  struct StreamBuffer_R000122_2213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000122_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000122_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000122_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000122_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000122_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000122_0_2 + 13) & 15;
  union TelemetryField_R000122_2213_0 u_var_1;
  union TelemetryField_R000122_2213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 55)
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
  if (stage_v_2_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 55)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
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
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 12) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 52)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 52)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 30)
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
  if (stage_v_14_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 30)
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
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 18) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 18) & 15;
  int stage_v_17_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_17_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= stage_v_17_1;
  chk_sum_2 ^= stage_v_17_2;
  int stage_v_18_1 = (st_var_2_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_2_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
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
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 53)
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
  if (stage_v_26_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 53)
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
  int stage_v_27_1 = (st_var_3_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_3_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((st_var_0_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_0_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 43)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 43)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = (st_var_2_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_2_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (st_var_3_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_3_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = ((st_var_0_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_0_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 29)
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
  if (stage_v_44_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 29)
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
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((st_var_3_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_3_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 34)
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
  if (stage_v_47_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 34)
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
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 39)
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
  if (stage_v_49_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 39)
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
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 52) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (st_var_1_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_1_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 56) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 58) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = ((st_var_2_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_2_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 39)
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
  if (stage_v_58_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 39)
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
  int stage_v_59_1 = ((st_var_3_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_3_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 32)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 32)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = ((st_var_3_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_3_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 33)
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
  if (stage_v_63_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 33)
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
  int stage_v_64_1 = (st_var_0_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_0_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  int stage_v_65_1 = ((st_var_1_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_1_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 29)
    {
      chk_sum_1 ^= stage_v_65_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_65_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 29)
    {
      chk_sum_2 ^= stage_v_65_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_66_1 = (st_var_2_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_2_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (73 & 31);
  int stage_v_68_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (73 & 31);
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= (stage_v_68_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_68_2 << 1) & 127;
  int stage_v_69_1 = table_1[1];
  int stage_v_69_2 = table_2[1];
  table_1[1] = (table_1[2] + 139) & 63;
  table_2[1] = (table_2[2] + 139) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 76) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 76) & 15;
  int stage_v_75_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_75_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= stage_v_75_1;
  chk_sum_2 ^= stage_v_75_2;
  int stage_v_76_1 = (st_var_0_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_0_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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

  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_78_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_79_1 = table_1[3];
  int stage_v_79_2 = table_2[3];
  table_1[3] = (table_1[0] + 159) & 63;
  table_2[3] = (table_2[0] + 159) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_81_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((st_var_3_1.buffer[2] * 2) + 256) & 63;
  int stage_v_83_2 = ((st_var_3_2.buffer[2] * 2) + 256) & 63;
  if (stage_v_83_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_83_1) - 5) & 255;
    if (stage_v_83_1 > 48)
    {
      chk_sum_1 ^= stage_v_83_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_83_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_83_2) - 5) & 255;
    if (stage_v_83_2 > 48)
    {
      chk_sum_2 ^= stage_v_83_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = table_1[1];
  int stage_v_85_2 = table_2[1];
  table_1[1] = (table_1[2] + 171) & 63;
  table_2[1] = (table_2[2] + 171) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = ((sec_r000122_9_1 + pub_r000122_15_1) + 39) & 127;
  int stage_v_87_2 = ((sec_r000122_9_2 + pub_r000122_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((stage_v_87_1 + pub_r000122_14_1) + 9) & 127;
  int stage_v_88_2 = ((stage_v_87_2 + pub_r000122_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((stage_v_87_1 + pub_r000122_4_1) + 15) & 127;
  int stage_v_89_2 = ((stage_v_87_2 + pub_r000122_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((stage_v_87_1 + pub_r000122_5_1) + 17) & 127;
  int stage_v_90_2 = ((stage_v_87_2 + pub_r000122_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((stage_v_88_1 + pub_r000122_2_1) + 7) & 127;
  int stage_v_91_2 = ((stage_v_88_2 + pub_r000122_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_89_1 + pub_r000122_17_1) + 8) & 127;
  int stage_v_92_2 = ((stage_v_89_2 + pub_r000122_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((stage_v_92_1 + pub_r000122_7_1) + 44) & 127;
  int stage_v_93_2 = ((stage_v_92_2 + pub_r000122_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((stage_v_91_1 + pub_r000122_8_1) + 37) & 127;
  int stage_v_94_2 = ((stage_v_91_2 + pub_r000122_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((stage_v_90_1 + pub_r000122_9_1) + 6) & 127;
  int stage_v_95_2 = ((stage_v_90_2 + pub_r000122_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((stage_v_94_1 + pub_r000122_6_1) + 8) & 127;
  int stage_v_96_2 = ((stage_v_94_2 + pub_r000122_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_93_1 + pub_r000122_4_1) + 30) & 127;
  int stage_v_97_2 = ((stage_v_93_2 + pub_r000122_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((sec_r000122_6_1 + pub_r000122_2_1) + 34) & 127;
  int stage_v_98_2 = ((sec_r000122_6_2 + pub_r000122_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((stage_v_93_1 + pub_r000122_10_1) + 34) & 127;
  int stage_v_99_2 = ((stage_v_93_2 + pub_r000122_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_93_1 + pub_r000122_6_1) + 23) & 127;
  int stage_v_100_2 = ((stage_v_93_2 + pub_r000122_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((stage_v_93_1 + pub_r000122_10_1) + 46) & 127;
  int stage_v_101_2 = ((stage_v_93_2 + pub_r000122_10_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((stage_v_101_1 + pub_r000122_16_1) + 34) & 127;
  int stage_v_102_2 = ((stage_v_101_2 + pub_r000122_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((sec_r000122_13_1 + pub_r000122_15_1) + 22) & 127;
  int stage_v_103_2 = ((sec_r000122_13_2 + pub_r000122_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((stage_v_100_1 + pub_r000122_7_1) + 35) & 127;
  int stage_v_104_2 = ((stage_v_100_2 + pub_r000122_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((stage_v_93_1 + pub_r000122_2_1) + 21) & 127;
  int stage_v_105_2 = ((stage_v_93_2 + pub_r000122_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_88_1 + pub_r000122_6_1) + 25) & 127;
  int stage_v_106_2 = ((stage_v_88_2 + pub_r000122_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((sec_r000122_14_1 + pub_r000122_8_1) + 49) & 127;
  int stage_v_107_2 = ((sec_r000122_14_2 + pub_r000122_8_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_102_1 + pub_r000122_16_1) + 46) & 127;
  int stage_v_108_2 = ((stage_v_102_2 + pub_r000122_16_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((sec_r000122_8_1 + pub_r000122_1_1) + 21) & 127;
  int stage_v_109_2 = ((sec_r000122_8_2 + pub_r000122_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((stage_v_102_1 + pub_r000122_0_1) + 9) & 127;
  int stage_v_110_2 = ((stage_v_102_2 + pub_r000122_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((sec_r000122_5_1 + pub_r000122_7_1) + 31) & 127;
  int stage_v_111_2 = ((sec_r000122_5_2 + pub_r000122_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((stage_v_92_1 + pub_r000122_5_1) + 7) & 127;
  int stage_v_112_2 = ((stage_v_92_2 + pub_r000122_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((stage_v_108_1 + pub_r000122_15_1) + 19) & 127;
  int stage_v_113_2 = ((stage_v_108_2 + pub_r000122_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((sec_r000122_10_1 + pub_r000122_10_1) + 23) & 127;
  int stage_v_114_2 = ((sec_r000122_10_2 + pub_r000122_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((stage_v_92_1 + pub_r000122_3_1) + 23) & 127;
  int stage_v_115_2 = ((stage_v_92_2 + pub_r000122_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((stage_v_107_1 + pub_r000122_16_1) + 48) & 127;
  int stage_v_116_2 = ((stage_v_107_2 + pub_r000122_16_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_108_1 + pub_r000122_10_1) + 18) & 127;
  int stage_v_117_2 = ((stage_v_108_2 + pub_r000122_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((sec_r000122_12_1 + pub_r000122_5_1) + 47) & 127;
  int stage_v_118_2 = ((sec_r000122_12_2 + pub_r000122_5_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((stage_v_89_1 + pub_r000122_4_1) + 11) & 127;
  int stage_v_119_2 = ((stage_v_89_2 + pub_r000122_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((sec_r000122_1_1 + pub_r000122_12_1) + 28) & 127;
  int stage_v_120_2 = ((sec_r000122_1_2 + pub_r000122_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((sec_r000122_22_1 + pub_r000122_13_1) + 45) & 127;
  int stage_v_121_2 = ((sec_r000122_22_2 + pub_r000122_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_96_1 + pub_r000122_10_1) + 18) & 127;
  int stage_v_122_2 = ((stage_v_96_2 + pub_r000122_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_101_1 + pub_r000122_1_1) + 47) & 127;
  int stage_v_123_2 = ((stage_v_101_2 + pub_r000122_1_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((stage_v_117_1 + pub_r000122_3_1) + 15) & 127;
  int stage_v_124_2 = ((stage_v_117_2 + pub_r000122_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((sec_r000122_13_1 + pub_r000122_1_1) + 44) & 127;
  int stage_v_125_2 = ((sec_r000122_13_2 + pub_r000122_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((stage_v_89_1 + pub_r000122_9_1) + 3) & 127;
  int stage_v_126_2 = ((stage_v_89_2 + pub_r000122_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((sec_r000122_19_1 + pub_r000122_15_1) + 47) & 127;
  int stage_v_127_2 = ((sec_r000122_19_2 + pub_r000122_15_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((stage_v_105_1 + pub_r000122_12_1) + 37) & 127;
  int stage_v_128_2 = ((stage_v_105_2 + pub_r000122_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((stage_v_115_1 + pub_r000122_15_1) + 6) & 127;
  int stage_v_129_2 = ((stage_v_115_2 + pub_r000122_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_105_1 + pub_r000122_12_1) + 22) & 127;
  int stage_v_130_2 = ((stage_v_105_2 + pub_r000122_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((stage_v_112_1 + pub_r000122_16_1) + 17) & 127;
  int stage_v_131_2 = ((stage_v_112_2 + pub_r000122_16_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((stage_v_101_1 + pub_r000122_14_1) + 33) & 127;
  int stage_v_132_2 = ((stage_v_101_2 + pub_r000122_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((stage_v_113_1 + pub_r000122_9_1) + 46) & 127;
  int stage_v_133_2 = ((stage_v_113_2 + pub_r000122_9_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((sec_r000122_20_1 + pub_r000122_9_1) + 42) & 127;
  int stage_v_134_2 = ((sec_r000122_20_2 + pub_r000122_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((stage_v_100_1 + pub_r000122_6_1) + 17) & 127;
  int stage_v_135_2 = ((stage_v_100_2 + pub_r000122_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((stage_v_129_1 + pub_r000122_6_1) + 16) & 127;
  int stage_v_136_2 = ((stage_v_129_2 + pub_r000122_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((stage_v_120_1 + pub_r000122_2_1) + 24) & 127;
  int stage_v_137_2 = ((stage_v_120_2 + pub_r000122_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_95_1 + pub_r000122_8_1) + 27) & 127;
  int stage_v_138_2 = ((stage_v_95_2 + pub_r000122_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((stage_v_104_1 + pub_r000122_14_1) + 21) & 127;
  int stage_v_139_2 = ((stage_v_104_2 + pub_r000122_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((stage_v_116_1 + pub_r000122_15_1) + 17) & 127;
  int stage_v_140_2 = ((stage_v_116_2 + pub_r000122_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((sec_r000122_14_1 + pub_r000122_6_1) + 26) & 127;
  int stage_v_141_2 = ((sec_r000122_14_2 + pub_r000122_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_107_1 + pub_r000122_12_1) + 8) & 127;
  int stage_v_142_2 = ((stage_v_107_2 + pub_r000122_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((stage_v_114_1 + pub_r000122_14_1) + 25) & 127;
  int stage_v_143_2 = ((stage_v_114_2 + pub_r000122_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((sec_r000122_19_1 + pub_r000122_12_1) + 42) & 127;
  int stage_v_144_2 = ((sec_r000122_19_2 + pub_r000122_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_141_1 + pub_r000122_2_1) + 31) & 127;
  int stage_v_145_2 = ((stage_v_141_2 + pub_r000122_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((stage_v_115_1 + pub_r000122_11_1) + 48) & 127;
  int stage_v_146_2 = ((stage_v_115_2 + pub_r000122_11_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((sec_r000122_7_1 + pub_r000122_14_1) + 5) & 127;
  int stage_v_147_2 = ((sec_r000122_7_2 + pub_r000122_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_108_1 + pub_r000122_13_1) + 40) & 127;
  int stage_v_148_2 = ((stage_v_108_2 + pub_r000122_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((stage_v_98_1 + pub_r000122_9_1) + 14) & 127;
  int stage_v_149_2 = ((stage_v_98_2 + pub_r000122_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((stage_v_87_1 + pub_r000122_13_1) + 14) & 127;
  int stage_v_150_2 = ((stage_v_87_2 + pub_r000122_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((stage_v_138_1 + pub_r000122_16_1) + 36) & 127;
  int stage_v_151_2 = ((stage_v_138_2 + pub_r000122_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((stage_v_131_1 + pub_r000122_14_1) + 47) & 127;
  int stage_v_152_2 = ((stage_v_131_2 + pub_r000122_14_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((sec_r000122_21_1 + pub_r000122_3_1) + 13) & 127;
  int stage_v_153_2 = ((sec_r000122_21_2 + pub_r000122_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((stage_v_141_1 + pub_r000122_8_1) + 30) & 127;
  int stage_v_154_2 = ((stage_v_141_2 + pub_r000122_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((sec_r000122_4_1 + pub_r000122_10_1) + 31) & 127;
  int stage_v_155_2 = ((sec_r000122_4_2 + pub_r000122_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_99_1 + pub_r000122_5_1) + 43) & 127;
  int stage_v_156_2 = ((stage_v_99_2 + pub_r000122_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((stage_v_156_1 + pub_r000122_5_1) + 23) & 127;
  int stage_v_157_2 = ((stage_v_156_2 + pub_r000122_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((sec_r000122_6_1 + pub_r000122_10_1) + 31) & 127;
  int stage_v_158_2 = ((sec_r000122_6_2 + pub_r000122_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((stage_v_153_1 + pub_r000122_2_1) + 43) & 127;
  int stage_v_159_2 = ((stage_v_153_2 + pub_r000122_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((stage_v_109_1 + pub_r000122_7_1) + 22) & 127;
  int stage_v_160_2 = ((stage_v_109_2 + pub_r000122_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((stage_v_94_1 + pub_r000122_16_1) + 7) & 127;
  int stage_v_161_2 = ((stage_v_94_2 + pub_r000122_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((stage_v_147_1 + pub_r000122_4_1) + 45) & 127;
  int stage_v_162_2 = ((stage_v_147_2 + pub_r000122_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((sec_r000122_20_1 + pub_r000122_1_1) + 29) & 127;
  int stage_v_163_2 = ((sec_r000122_20_2 + pub_r000122_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((stage_v_152_1 + pub_r000122_7_1) + 47) & 127;
  int stage_v_164_2 = ((stage_v_152_2 + pub_r000122_7_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((sec_r000122_17_1 + pub_r000122_14_1) + 3) & 127;
  int stage_v_165_2 = ((sec_r000122_17_2 + pub_r000122_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((sec_r000122_3_1 + pub_r000122_5_1) + 7) & 127;
  int stage_v_166_2 = ((sec_r000122_3_2 + pub_r000122_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((stage_v_111_1 + pub_r000122_8_1) + 28) & 127;
  int stage_v_167_2 = ((stage_v_111_2 + pub_r000122_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((sec_r000122_10_1 + pub_r000122_12_1) + 20) & 127;
  int stage_v_168_2 = ((sec_r000122_10_2 + pub_r000122_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((sec_r000122_5_1 + pub_r000122_5_1) + 4) & 127;
  int stage_v_169_2 = ((sec_r000122_5_2 + pub_r000122_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((stage_v_139_1 + pub_r000122_3_1) + 7) & 127;
  int stage_v_170_2 = ((stage_v_139_2 + pub_r000122_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((stage_v_105_1 + pub_r000122_13_1) + 16) & 127;
  int stage_v_171_2 = ((stage_v_105_2 + pub_r000122_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_110_1 + pub_r000122_14_1) + 16) & 127;
  int stage_v_172_2 = ((stage_v_110_2 + pub_r000122_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((sec_r000122_12_1 + pub_r000122_7_1) + 29) & 127;
  int stage_v_173_2 = ((sec_r000122_12_2 + pub_r000122_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((sec_r000122_0_1 + pub_r000122_8_1) + 30) & 127;
  int stage_v_174_2 = ((sec_r000122_0_2 + pub_r000122_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((stage_v_88_1 + pub_r000122_0_1) + 23) & 127;
  int stage_v_175_2 = ((stage_v_88_2 + pub_r000122_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((stage_v_95_1 + pub_r000122_3_1) + 14) & 127;
  int stage_v_176_2 = ((stage_v_95_2 + pub_r000122_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((stage_v_173_1 + pub_r000122_3_1) + 46) & 127;
  int stage_v_177_2 = ((stage_v_173_2 + pub_r000122_3_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((stage_v_134_1 + pub_r000122_16_1) + 43) & 127;
  int stage_v_178_2 = ((stage_v_134_2 + pub_r000122_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((sec_r000122_4_1 + pub_r000122_13_1) + 26) & 127;
  int stage_v_179_2 = ((sec_r000122_4_2 + pub_r000122_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((stage_v_113_1 + pub_r000122_1_1) + 49) & 127;
  int stage_v_180_2 = ((stage_v_113_2 + pub_r000122_1_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((sec_r000122_19_1 + pub_r000122_13_1) + 4) & 127;
  int stage_v_181_2 = ((sec_r000122_19_2 + pub_r000122_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((stage_v_139_1 + pub_r000122_3_1) + 46) & 127;
  int stage_v_182_2 = ((stage_v_139_2 + pub_r000122_3_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((sec_r000122_14_1 + pub_r000122_10_1) + 20) & 127;
  int stage_v_183_2 = ((sec_r000122_14_2 + pub_r000122_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((stage_v_170_1 + pub_r000122_13_1) + 28) & 127;
  int stage_v_184_2 = ((stage_v_170_2 + pub_r000122_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((stage_v_155_1 + pub_r000122_15_1) + 34) & 127;
  int stage_v_185_2 = ((stage_v_155_2 + pub_r000122_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_102_1 + pub_r000122_11_1) + 41) & 127;
  int stage_v_186_2 = ((stage_v_102_2 + pub_r000122_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((stage_v_106_1 + pub_r000122_2_1) + 38) & 127;
  int stage_v_187_2 = ((stage_v_106_2 + pub_r000122_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((sec_r000122_12_1 + pub_r000122_16_1) + 35) & 127;
  int stage_v_188_2 = ((sec_r000122_12_2 + pub_r000122_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((sec_r000122_17_1 + pub_r000122_4_1) + 34) & 127;
  int stage_v_189_2 = ((sec_r000122_17_2 + pub_r000122_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((stage_v_140_1 + pub_r000122_15_1) + 27) & 127;
  int stage_v_190_2 = ((stage_v_140_2 + pub_r000122_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((stage_v_90_1 + pub_r000122_16_1) + 15) & 127;
  int stage_v_191_2 = ((stage_v_90_2 + pub_r000122_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((stage_v_168_1 + pub_r000122_4_1) + 16) & 127;
  int stage_v_192_2 = ((stage_v_168_2 + pub_r000122_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((sec_r000122_20_1 + pub_r000122_3_1) + 17) & 127;
  int stage_v_193_2 = ((sec_r000122_20_2 + pub_r000122_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((sec_r000122_12_1 + pub_r000122_0_1) + 35) & 127;
  int stage_v_194_2 = ((sec_r000122_12_2 + pub_r000122_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_132_1 + pub_r000122_7_1) + 17) & 127;
  int stage_v_195_2 = ((stage_v_132_2 + pub_r000122_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((stage_v_105_1 + pub_r000122_5_1) + 34) & 127;
  int stage_v_196_2 = ((stage_v_105_2 + pub_r000122_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((sec_r000122_17_1 + pub_r000122_4_1) + 18) & 127;
  int stage_v_197_2 = ((sec_r000122_17_2 + pub_r000122_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_91_1 + pub_r000122_9_1) + 34) & 127;
  int stage_v_198_2 = ((stage_v_91_2 + pub_r000122_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_114_1 + pub_r000122_0_1) + 29) & 127;
  int stage_v_199_2 = ((stage_v_114_2 + pub_r000122_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_191_1 + pub_r000122_0_1) + 40) & 127;
  int stage_v_200_2 = ((stage_v_191_2 + pub_r000122_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((stage_v_185_1 + pub_r000122_8_1) + 33) & 127;
  int stage_v_201_2 = ((stage_v_185_2 + pub_r000122_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((stage_v_165_1 + pub_r000122_15_1) + 34) & 127;
  int stage_v_202_2 = ((stage_v_165_2 + pub_r000122_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((sec_r000122_13_1 + pub_r000122_8_1) + 17) & 127;
  int stage_v_203_2 = ((sec_r000122_13_2 + pub_r000122_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((stage_v_167_1 + pub_r000122_2_1) + 47) & 127;
  int stage_v_204_2 = ((stage_v_167_2 + pub_r000122_2_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((sec_r000122_15_1 + pub_r000122_12_1) + 20) & 127;
  int stage_v_205_2 = ((sec_r000122_15_2 + pub_r000122_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((stage_v_143_1 + pub_r000122_3_1) + 10) & 127;
  int stage_v_206_2 = ((stage_v_143_2 + pub_r000122_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((stage_v_165_1 + pub_r000122_10_1) + 18) & 127;
  int stage_v_207_2 = ((stage_v_165_2 + pub_r000122_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((sec_r000122_16_1 + pub_r000122_2_1) + 47) & 127;
  int stage_v_208_2 = ((sec_r000122_16_2 + pub_r000122_2_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((stage_v_113_1 + pub_r000122_7_1) + 15) & 127;
  int stage_v_209_2 = ((stage_v_113_2 + pub_r000122_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((sec_r000122_8_1 + pub_r000122_12_1) + 12) & 127;
  int stage_v_210_2 = ((sec_r000122_8_2 + pub_r000122_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((stage_v_123_1 + pub_r000122_15_1) + 25) & 127;
  int stage_v_211_2 = ((stage_v_123_2 + pub_r000122_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((stage_v_92_1 + pub_r000122_8_1) + 11) & 127;
  int stage_v_212_2 = ((stage_v_92_2 + pub_r000122_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((sec_r000122_1_1 + pub_r000122_9_1) + 31) & 127;
  int stage_v_213_2 = ((sec_r000122_1_2 + pub_r000122_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((sec_r000122_13_1 + pub_r000122_7_1) + 38) & 127;
  int stage_v_214_2 = ((sec_r000122_13_2 + pub_r000122_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((stage_v_211_1 + pub_r000122_7_1) + 29) & 127;
  int stage_v_215_2 = ((stage_v_211_2 + pub_r000122_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((stage_v_199_1 + pub_r000122_11_1) + 21) & 127;
  int stage_v_216_2 = ((stage_v_199_2 + pub_r000122_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((stage_v_94_1 + pub_r000122_7_1) + 7) & 127;
  int stage_v_217_2 = ((stage_v_94_2 + pub_r000122_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((sec_r000122_12_1 + pub_r000122_7_1) + 28) & 127;
  int stage_v_218_2 = ((sec_r000122_12_2 + pub_r000122_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((sec_r000122_13_1 + pub_r000122_0_1) + 6) & 127;
  int stage_v_219_2 = ((sec_r000122_13_2 + pub_r000122_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((stage_v_103_1 + pub_r000122_16_1) + 45) & 127;
  int stage_v_220_2 = ((stage_v_103_2 + pub_r000122_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((sec_r000122_16_1 + pub_r000122_17_1) + 4) & 127;
  int stage_v_221_2 = ((sec_r000122_16_2 + pub_r000122_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((sec_r000122_17_1 + pub_r000122_2_1) + 47) & 127;
  int stage_v_222_2 = ((sec_r000122_17_2 + pub_r000122_2_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((stage_v_110_1 + pub_r000122_7_1) + 42) & 127;
  int stage_v_223_2 = ((stage_v_110_2 + pub_r000122_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((stage_v_122_1 + pub_r000122_13_1) + 48) & 127;
  int stage_v_224_2 = ((stage_v_122_2 + pub_r000122_13_2) + 48) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((stage_v_215_1 + pub_r000122_8_1) + 36) & 127;
  int stage_v_225_2 = ((stage_v_215_2 + pub_r000122_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_159_1 + pub_r000122_7_1) + 32) & 127;
  int stage_v_226_2 = ((stage_v_159_2 + pub_r000122_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((stage_v_202_1 + pub_r000122_7_1) + 5) & 127;
  int stage_v_227_2 = ((stage_v_202_2 + pub_r000122_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((stage_v_204_1 + pub_r000122_11_1) + 7) & 127;
  int stage_v_228_2 = ((stage_v_204_2 + pub_r000122_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((sec_r000122_13_1 + pub_r000122_3_1) + 17) & 127;
  int stage_v_229_2 = ((sec_r000122_13_2 + pub_r000122_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((sec_r000122_22_1 + pub_r000122_0_1) + 18) & 127;
  int stage_v_230_2 = ((sec_r000122_22_2 + pub_r000122_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((sec_r000122_11_1 + pub_r000122_1_1) + 7) & 127;
  int stage_v_231_2 = ((sec_r000122_11_2 + pub_r000122_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((stage_v_202_1 + pub_r000122_12_1) + 29) & 127;
  int stage_v_232_2 = ((stage_v_202_2 + pub_r000122_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((stage_v_199_1 + pub_r000122_10_1) + 36) & 127;
  int stage_v_233_2 = ((stage_v_199_2 + pub_r000122_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((stage_v_233_1 + pub_r000122_0_1) + 38) & 127;
  int stage_v_234_2 = ((stage_v_233_2 + pub_r000122_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((stage_v_170_1 + pub_r000122_0_1) + 19) & 127;
  int stage_v_235_2 = ((stage_v_170_2 + pub_r000122_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((sec_r000122_6_1 + pub_r000122_6_1) + 43) & 127;
  int stage_v_236_2 = ((sec_r000122_6_2 + pub_r000122_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((stage_v_230_1 + pub_r000122_11_1) + 15) & 127;
  int stage_v_237_2 = ((stage_v_230_2 + pub_r000122_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((stage_v_221_1 + pub_r000122_17_1) + 34) & 127;
  int stage_v_238_2 = ((stage_v_221_2 + pub_r000122_17_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((stage_v_92_1 + pub_r000122_13_1) + 39) & 127;
  int stage_v_239_2 = ((stage_v_92_2 + pub_r000122_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((stage_v_148_1 + pub_r000122_6_1) + 49) & 127;
  int stage_v_240_2 = ((stage_v_148_2 + pub_r000122_6_2) + 49) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((stage_v_216_1 + pub_r000122_9_1) + 20) & 127;
  int stage_v_241_2 = ((stage_v_216_2 + pub_r000122_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((stage_v_229_1 + pub_r000122_5_1) + 10) & 127;
  int stage_v_242_2 = ((stage_v_229_2 + pub_r000122_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((stage_v_240_1 + pub_r000122_1_1) + 31) & 127;
  int stage_v_243_2 = ((stage_v_240_2 + pub_r000122_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((sec_r000122_7_1 + pub_r000122_8_1) + 15) & 127;
  int stage_v_244_2 = ((sec_r000122_7_2 + pub_r000122_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((sec_r000122_15_1 + pub_r000122_2_1) + 18) & 127;
  int stage_v_245_2 = ((sec_r000122_15_2 + pub_r000122_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((stage_v_226_1 + pub_r000122_16_1) + 29) & 127;
  int stage_v_246_2 = ((stage_v_226_2 + pub_r000122_16_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((stage_v_156_1 + pub_r000122_8_1) + 31) & 127;
  int stage_v_247_2 = ((stage_v_156_2 + pub_r000122_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((stage_v_108_1 + pub_r000122_7_1) + 8) & 127;
  int stage_v_248_2 = ((stage_v_108_2 + pub_r000122_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((stage_v_112_1 + pub_r000122_1_1) + 4) & 127;
  int stage_v_249_2 = ((stage_v_112_2 + pub_r000122_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((stage_v_211_1 + pub_r000122_6_1) + 20) & 127;
  int stage_v_250_2 = ((stage_v_211_2 + pub_r000122_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((sec_r000122_13_1 + pub_r000122_3_1) + 16) & 127;
  int stage_v_251_2 = ((sec_r000122_13_2 + pub_r000122_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((stage_v_149_1 + pub_r000122_2_1) + 32) & 127;
  int stage_v_252_2 = ((stage_v_149_2 + pub_r000122_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((stage_v_151_1 + pub_r000122_10_1) + 6) & 127;
  int stage_v_253_2 = ((stage_v_151_2 + pub_r000122_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((stage_v_99_1 + pub_r000122_7_1) + 18) & 127;
  int stage_v_254_2 = ((stage_v_99_2 + pub_r000122_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((sec_r000122_18_1 + pub_r000122_7_1) + 11) & 127;
  int stage_v_255_2 = ((sec_r000122_18_2 + pub_r000122_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((stage_v_133_1 + pub_r000122_15_1) + 38) & 127;
  int stage_v_256_2 = ((stage_v_133_2 + pub_r000122_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((sec_r000122_12_1 + pub_r000122_2_1) + 22) & 127;
  int stage_v_257_2 = ((sec_r000122_12_2 + pub_r000122_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((sec_r000122_0_1 + pub_r000122_2_1) + 18) & 127;
  int stage_v_258_2 = ((sec_r000122_0_2 + pub_r000122_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((sec_r000122_21_1 + pub_r000122_3_1) + 23) & 127;
  int stage_v_259_2 = ((sec_r000122_21_2 + pub_r000122_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((stage_v_226_1 + pub_r000122_15_1) + 18) & 127;
  int stage_v_260_2 = ((stage_v_226_2 + pub_r000122_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((sec_r000122_18_1 + pub_r000122_16_1) + 4) & 127;
  int stage_v_261_2 = ((sec_r000122_18_2 + pub_r000122_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((stage_v_134_1 + pub_r000122_9_1) + 15) & 127;
  int stage_v_262_2 = ((stage_v_134_2 + pub_r000122_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((sec_r000122_17_1 + pub_r000122_1_1) + 23) & 127;
  int stage_v_263_2 = ((sec_r000122_17_2 + pub_r000122_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((stage_v_167_1 + pub_r000122_14_1) + 17) & 127;
  int stage_v_264_2 = ((stage_v_167_2 + pub_r000122_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((stage_v_168_1 + pub_r000122_5_1) + 18) & 127;
  int stage_v_265_2 = ((stage_v_168_2 + pub_r000122_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((sec_r000122_3_1 + pub_r000122_11_1) + 13) & 127;
  int stage_v_266_2 = ((sec_r000122_3_2 + pub_r000122_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((sec_r000122_12_1 + pub_r000122_17_1) + 41) & 127;
  int stage_v_267_2 = ((sec_r000122_12_2 + pub_r000122_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((stage_v_199_1 + pub_r000122_3_1) + 26) & 127;
  int stage_v_268_2 = ((stage_v_199_2 + pub_r000122_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((stage_v_245_1 + pub_r000122_0_1) + 22) & 127;
  int stage_v_269_2 = ((stage_v_245_2 + pub_r000122_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((stage_v_227_1 + pub_r000122_11_1) + 18) & 127;
  int stage_v_270_2 = ((stage_v_227_2 + pub_r000122_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((sec_r000122_1_1 + pub_r000122_10_1) + 42) & 127;
  int stage_v_271_2 = ((sec_r000122_1_2 + pub_r000122_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((sec_r000122_20_1 + pub_r000122_13_1) + 25) & 127;
  int stage_v_272_2 = ((sec_r000122_20_2 + pub_r000122_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((sec_r000122_20_1 + pub_r000122_3_1) + 28) & 127;
  int stage_v_273_2 = ((sec_r000122_20_2 + pub_r000122_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((stage_v_202_1 + pub_r000122_15_1) + 31) & 127;
  int stage_v_274_2 = ((stage_v_202_2 + pub_r000122_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((sec_r000122_19_1 + pub_r000122_5_1) + 31) & 127;
  int stage_v_275_2 = ((sec_r000122_19_2 + pub_r000122_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((stage_v_266_1 + pub_r000122_1_1) + 33) & 127;
  int stage_v_276_2 = ((stage_v_266_2 + pub_r000122_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((stage_v_247_1 + pub_r000122_8_1) + 38) & 127;
  int stage_v_277_2 = ((stage_v_247_2 + pub_r000122_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((sec_r000122_15_1 + pub_r000122_3_1) + 38) & 127;
  int stage_v_278_2 = ((sec_r000122_15_2 + pub_r000122_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((sec_r000122_2_1 + pub_r000122_12_1) + 19) & 127;
  int stage_v_279_2 = ((sec_r000122_2_2 + pub_r000122_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((stage_v_174_1 + pub_r000122_17_1) + 31) & 127;
  int stage_v_280_2 = ((stage_v_174_2 + pub_r000122_17_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((stage_v_91_1 + pub_r000122_7_1) + 27) & 127;
  int stage_v_281_2 = ((stage_v_91_2 + pub_r000122_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((stage_v_98_1 + pub_r000122_4_1) + 29) & 127;
  int stage_v_282_2 = ((stage_v_98_2 + pub_r000122_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((stage_v_145_1 + pub_r000122_10_1) + 35) & 127;
  int stage_v_283_2 = ((stage_v_145_2 + pub_r000122_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((stage_v_230_1 + pub_r000122_0_1) + 26) & 127;
  int stage_v_284_2 = ((stage_v_230_2 + pub_r000122_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((stage_v_254_1 + pub_r000122_5_1) + 4) & 127;
  int stage_v_285_2 = ((stage_v_254_2 + pub_r000122_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((sec_r000122_18_1 + pub_r000122_1_1) + 34) & 127;
  int stage_v_286_2 = ((sec_r000122_18_2 + pub_r000122_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((stage_v_284_1 + pub_r000122_11_1) + 4) & 127;
  int stage_v_287_2 = ((stage_v_284_2 + pub_r000122_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((stage_v_206_1 + pub_r000122_10_1) + 19) & 127;
  int stage_v_288_2 = ((stage_v_206_2 + pub_r000122_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((stage_v_180_1 + pub_r000122_4_1) + 46) & 127;
  int stage_v_289_2 = ((stage_v_180_2 + pub_r000122_4_2) + 46) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((stage_v_188_1 + pub_r000122_3_1) + 32) & 127;
  int stage_v_290_2 = ((stage_v_188_2 + pub_r000122_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((sec_r000122_12_1 + pub_r000122_10_1) + 42) & 127;
  int stage_v_291_2 = ((sec_r000122_12_2 + pub_r000122_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((stage_v_270_1 + pub_r000122_8_1) + 31) & 127;
  int stage_v_292_2 = ((stage_v_270_2 + pub_r000122_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((stage_v_279_1 + pub_r000122_12_1) + 43) & 127;
  int stage_v_293_2 = ((stage_v_279_2 + pub_r000122_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((sec_r000122_9_1 + pub_r000122_16_1) + 4) & 127;
  int stage_v_294_2 = ((sec_r000122_9_2 + pub_r000122_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((stage_v_289_1 + pub_r000122_9_1) + 9) & 127;
  int stage_v_295_2 = ((stage_v_289_2 + pub_r000122_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((stage_v_195_1 + pub_r000122_14_1) + 23) & 127;
  int stage_v_296_2 = ((stage_v_195_2 + pub_r000122_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((stage_v_209_1 + pub_r000122_3_1) + 35) & 127;
  int stage_v_297_2 = ((stage_v_209_2 + pub_r000122_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((stage_v_252_1 + pub_r000122_12_1) + 47) & 127;
  int stage_v_298_2 = ((stage_v_252_2 + pub_r000122_12_2) + 47) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((stage_v_222_1 + pub_r000122_3_1) + 8) & 127;
  int stage_v_299_2 = ((stage_v_222_2 + pub_r000122_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((sec_r000122_1_1 + pub_r000122_10_1) + 6) & 127;
  int stage_v_300_2 = ((sec_r000122_1_2 + pub_r000122_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((stage_v_219_1 + pub_r000122_14_1) + 23) & 127;
  int stage_v_301_2 = ((stage_v_219_2 + pub_r000122_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((stage_v_258_1 + pub_r000122_7_1) + 44) & 127;
  int stage_v_302_2 = ((stage_v_258_2 + pub_r000122_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((sec_r000122_16_1 + pub_r000122_10_1) + 40) & 127;
  int stage_v_303_2 = ((sec_r000122_16_2 + pub_r000122_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((stage_v_241_1 + pub_r000122_1_1) + 4) & 127;
  int stage_v_304_2 = ((stage_v_241_2 + pub_r000122_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((stage_v_151_1 + pub_r000122_8_1) + 42) & 127;
  int stage_v_305_2 = ((stage_v_151_2 + pub_r000122_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((sec_r000122_3_1 + pub_r000122_7_1) + 32) & 127;
  int stage_v_306_2 = ((sec_r000122_3_2 + pub_r000122_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((sec_r000122_21_1 + pub_r000122_5_1) + 37) & 127;
  int stage_v_307_2 = ((sec_r000122_21_2 + pub_r000122_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((stage_v_300_1 + pub_r000122_14_1) + 20) & 127;
  int stage_v_308_2 = ((stage_v_300_2 + pub_r000122_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((sec_r000122_3_1 + pub_r000122_12_1) + 39) & 127;
  int stage_v_309_2 = ((sec_r000122_3_2 + pub_r000122_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((stage_v_207_1 + pub_r000122_5_1) + 32) & 127;
  int stage_v_310_2 = ((stage_v_207_2 + pub_r000122_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((stage_v_267_1 + pub_r000122_2_1) + 31) & 127;
  int stage_v_311_2 = ((stage_v_267_2 + pub_r000122_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((stage_v_145_1 + pub_r000122_1_1) + 37) & 127;
  int stage_v_312_2 = ((stage_v_145_2 + pub_r000122_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000122_19_1 != sec_r000122_19_2);
  __CPROVER_assume(pub_r000122_8_1 == pub_r000122_8_2);
  __CPROVER_assume(sec_r000122_17_1 != sec_r000122_17_2);
  __CPROVER_assume(pub_r000122_10_1 == pub_r000122_10_2);
  __CPROVER_assume(pub_r000122_9_1 == pub_r000122_9_2);
  __CPROVER_assume(pub_r000122_14_1 == pub_r000122_14_2);
  __CPROVER_assume(sec_r000122_22_1 != sec_r000122_22_2);
  __CPROVER_assume(sec_r000122_9_1 != sec_r000122_9_2);
  __CPROVER_assume(pub_r000122_17_1 == pub_r000122_17_2);
  __CPROVER_assume(pub_r000122_16_1 == pub_r000122_16_2);
  __CPROVER_assume(sec_r000122_6_1 != sec_r000122_6_2);
  __CPROVER_assume(sec_r000122_13_1 != sec_r000122_13_2);
  __CPROVER_assume(sec_r000122_2_1 != sec_r000122_2_2);
  __CPROVER_assume(pub_r000122_1_1 == pub_r000122_1_2);
  __CPROVER_assume(sec_r000122_14_1 != sec_r000122_14_2);
  __CPROVER_assume(pub_r000122_5_1 == pub_r000122_5_2);
  __CPROVER_assume(pub_r000122_13_1 == pub_r000122_13_2);
  __CPROVER_assume(sec_r000122_12_1 != sec_r000122_12_2);
  __CPROVER_assume(pub_r000122_3_1 == pub_r000122_3_2);
  __CPROVER_assume(pub_r000122_12_1 == pub_r000122_12_2);
  __CPROVER_assume(pub_r000122_6_1 == pub_r000122_6_2);
  __CPROVER_assume(sec_r000122_21_1 != sec_r000122_21_2);
  __CPROVER_assume(sec_r000122_20_1 != sec_r000122_20_2);
  __CPROVER_assume(pub_r000122_15_1 == pub_r000122_15_2);
  __CPROVER_assume(sec_r000122_5_1 != sec_r000122_5_2);
  __CPROVER_assume(sec_r000122_8_1 != sec_r000122_8_2);
  __CPROVER_assume(pub_r000122_4_1 == pub_r000122_4_2);
  __CPROVER_assume(sec_r000122_16_1 != sec_r000122_16_2);
  __CPROVER_assume(sec_r000122_7_1 != sec_r000122_7_2);
  __CPROVER_assume(pub_r000122_7_1 == pub_r000122_7_2);
  __CPROVER_assume(sec_r000122_11_1 != sec_r000122_11_2);
  __CPROVER_assume(pub_r000122_11_1 == pub_r000122_11_2);
  __CPROVER_assume(sec_r000122_15_1 != sec_r000122_15_2);
  __CPROVER_assume(sec_r000122_4_1 != sec_r000122_4_2);
  __CPROVER_assume(pub_r000122_0_1 == pub_r000122_0_2);
  __CPROVER_assume(sec_r000122_3_1 != sec_r000122_3_2);
  __CPROVER_assume(sec_r000122_0_1 != sec_r000122_0_2);
  __CPROVER_assume(sec_r000122_18_1 != sec_r000122_18_2);
  __CPROVER_assume(sec_r000122_10_1 != sec_r000122_10_2);
  __CPROVER_assume(pub_r000122_2_1 == pub_r000122_2_2);
  __CPROVER_assume(sec_r000122_1_1 != sec_r000122_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.head == st_var_3_2.head);
  assert(st_var_3_1.tail == st_var_3_2.tail);
  assert(st_var_3_1.state == st_var_3_2.state);
  assert(st_var_3_1.checksum == st_var_3_2.checksum);
  assert(st_var_3_1.capacity == st_var_3_2.capacity);
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
}


