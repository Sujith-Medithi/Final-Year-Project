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
struct Transaction_R000167_6713_0
{
  short account_id;
  int rate;
  int status;
  unsigned char fee;
  short auth_code;
  int balance;
  int buffer[3];
};
struct EventLog_R000167_6713_1
{
  int signature;
  unsigned char facility;
  int severity;
  int seq;
  int buffer[3];
};
struct FilterState_R000167_6713_2
{
  int prev_out;
  int gain_db;
  int damping;
  int buffer[3];
};
struct SensorNode_R000167_6713_3
{
  short calib;
  int gain;
  short threshold;
  unsigned char offset;
  int reading;
  short status;
  int buffer[3];
};
union PacketPayload_R000167_6713_0
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
void fn_R000167_6713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000167_6713_3 st_1 = {0};
  struct SensorNode_R000167_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int accumulator_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_69_1 > 44)
  {
    acc_1 = ((acc_1 + (accumulator_69_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_69_2 > 44)
  {
    acc_2 = ((acc_2 + (accumulator_69_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_67_1)
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

  switch (tracker_67_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_56_1 = local_arr_1[aux_1 % 3];
  int margin_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_69_1 == accumulator_69_2);
  assert(tracker_67_1 == tracker_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_56_1 == margin_56_2);
}

int fn_R000167_6713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000167_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int accumulator_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_69 > 44)
  {
    acc = ((acc + (accumulator_69 * 2)) + 5) & 127;
    aux ^= accumulator_69 & 15;
  }
  else
  {
    acc = ((acc - accumulator_69) + 11) & 127;
    aux += 3;
  }
  int tracker_67 = (aux + st.buffer[1]) & 3;
  switch (tracker_67)
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
  int local_arr[3] = {4, 9, 15};
  int margin_56 = local_arr[aux % 3];
  acc = (acc + (margin_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000167_6713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000167_6713_3 st_1 = {0};
  struct SensorNode_R000167_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_56_1 = local_arr_1[aux_1 % 3];
  int segment_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_56_2 * 2)) & 127;
  int tracker_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_57_1)
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

  switch (tracker_57_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_56_1 == segment_56_2);
  assert(tracker_57_1 == tracker_57_2);
}

int fn_R000167_6713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000167_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int segment_56 = local_arr[aux % 3];
  acc = (acc + (segment_56 * 2)) & 127;
  int tracker_57 = (aux + st.buffer[1]) & 3;
  switch (tracker_57)
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

void fn_R000167_6713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000167_6713_2 st_1 = {0};
  struct FilterState_R000167_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_33_1 = local_arr_1[aux_1 % 3];
  int residue_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_33_2 * 2)) & 127;
  int parity_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_53_1 > 14)
  {
    acc_1 = ((acc_1 + (parity_53_1 * 2)) + 5) & 127;
    aux_1 ^= parity_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_53_2 > 14)
  {
    acc_2 = ((acc_2 + (parity_53_2 * 2)) + 5) & 127;
    aux_2 ^= parity_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_97_1) & 63;
  aux_2 = (aux_2 + coefficient_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_33_1 == residue_33_2);
  assert(parity_53_1 == parity_53_2);
  assert(coefficient_97_1 == coefficient_97_2);
}

int fn_R000167_6713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000167_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int residue_33 = local_arr[aux % 3];
  acc = (acc + (residue_33 * 2)) & 127;
  int parity_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_53 > 14)
  {
    acc = ((acc + (parity_53 * 2)) + 5) & 127;
    aux ^= parity_53 & 15;
  }
  else
  {
    acc = ((acc - parity_53) + 11) & 127;
    aux += 3;
  }
  int coefficient_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000167_6713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st_1 = {0};
  struct EventLog_R000167_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int damping_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_48_1 > 43)
  {
    acc_1 = ((acc_1 + (damping_48_1 * 2)) + 5) & 127;
    aux_1 ^= damping_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_48_2 > 43)
  {
    acc_2 = ((acc_2 + (damping_48_2 * 2)) + 5) & 127;
    aux_2 ^= damping_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_48_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_48_1 == damping_48_2);
}

int fn_R000167_6713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int damping_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_48 > 43)
  {
    acc = ((acc + (damping_48 * 2)) + 5) & 127;
    aux ^= damping_48 & 15;
  }
  else
  {
    acc = ((acc - damping_48) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000167_6713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st_1 = {0};
  struct EventLog_R000167_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_72_1 = local_arr_1[aux_1 % 3];
  int residue_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_72_2 * 2)) & 127;
  int quantum_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_55_1 > 37)
  {
    acc_1 = ((acc_1 + (quantum_55_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_55_2 > 37)
  {
    acc_2 = ((acc_2 + (quantum_55_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_99_1)
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

  switch (phase_99_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_72_1 == residue_72_2);
  assert(quantum_55_1 == quantum_55_2);
  assert(phase_99_1 == phase_99_2);
}

int fn_R000167_6713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int residue_72 = local_arr[aux % 3];
  acc = (acc + (residue_72 * 2)) & 127;
  int quantum_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_55 > 37)
  {
    acc = ((acc + (quantum_55 * 2)) + 5) & 127;
    aux ^= quantum_55 & 15;
  }
  else
  {
    acc = ((acc - quantum_55) + 11) & 127;
    aux += 3;
  }
  int phase_99 = (aux + st.buffer[1]) & 3;
  switch (phase_99)
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

void fn_R000167_6713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st_1 = {0};
  struct Transaction_R000167_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int metric_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_34_1) & 63;
  aux_2 = (aux_2 + metric_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_40_1 > 33)
  {
    acc_1 = ((acc_1 + (tally_40_1 * 2)) + 5) & 127;
    aux_1 ^= tally_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_40_2 > 33)
  {
    acc_2 = ((acc_2 + (tally_40_2 * 2)) + 5) & 127;
    aux_2 ^= tally_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_57_1 = local_arr_1[aux_1 % 3];
  int stride_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_57_2 * 2)) & 127;
  int parity_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_90_1)
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

  switch (parity_90_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_34_1 == metric_34_2);
  assert(tally_40_1 == tally_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_57_1 == stride_57_2);
  assert(parity_90_1 == parity_90_2);
}

int fn_R000167_6713_5(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int metric_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_34) & 63;
  acc ^= aux;
  int tally_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_40 > 33)
  {
    acc = ((acc + (tally_40 * 2)) + 5) & 127;
    aux ^= tally_40 & 15;
  }
  else
  {
    acc = ((acc - tally_40) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_57 = local_arr[aux % 3];
  acc = (acc + (stride_57 * 2)) & 127;
  int parity_90 = (aux + st.buffer[1]) & 3;
  switch (parity_90)
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

void fn_R000167_6713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st_1 = {0};
  struct Transaction_R000167_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_58_1 = local_arr_1[aux_1 % 3];
  int vector_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_58_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_24_1)
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

  switch (factor_24_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
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

  assert(vector_58_1 == vector_58_2);
  assert(factor_24_1 == factor_24_2);
}

int fn_R000167_6713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int vector_58 = local_arr[aux % 3];
  acc = (acc + (vector_58 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_24 = (aux + st.buffer[1]) & 3;
  switch (factor_24)
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

void fn_R000167_6713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st_1 = {0};
  struct Transaction_R000167_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_41_1)
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

  switch (metric_41_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_41_1 == metric_41_2);
}

int fn_R000167_6713_7(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_41 = (aux + st.buffer[1]) & 3;
  switch (metric_41)
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

void fn_R000167_6713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st_1 = {0};
  struct Transaction_R000167_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int segment_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_32_1)
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

  switch (segment_32_2)
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
  int tracker_15_1 = local_arr_1[aux_1 % 3];
  int tracker_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_15_2 * 2)) & 127;
  int parity_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_72_1) & 63;
  aux_2 = (aux_2 + parity_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_79_1 > 50)
  {
    acc_1 = ((acc_1 + (margin_79_1 * 2)) + 5) & 127;
    aux_1 ^= margin_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_79_2 > 50)
  {
    acc_2 = ((acc_2 + (margin_79_2 * 2)) + 5) & 127;
    aux_2 ^= margin_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_32_1 == segment_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_15_1 == tracker_15_2);
  assert(parity_72_1 == parity_72_2);
  assert(margin_79_1 == margin_79_2);
}

int fn_R000167_6713_8(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int segment_32 = (aux + st.buffer[1]) & 3;
  switch (segment_32)
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
  int tracker_15 = local_arr[aux % 3];
  acc = (acc + (tracker_15 * 2)) & 127;
  int parity_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_72) & 63;
  acc ^= aux;
  int margin_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_79 > 50)
  {
    acc = ((acc + (margin_79 * 2)) + 5) & 127;
    aux ^= margin_79 & 15;
  }
  else
  {
    acc = ((acc - margin_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000167_6713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000167_6713_2 st_1 = {0};
  struct FilterState_R000167_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_77_1)
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

  switch (checksum_77_2)
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
  int metric_12_1 = local_arr_1[aux_1 % 3];
  int metric_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_77_1 == checksum_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_12_1 == metric_12_2);
}

int fn_R000167_6713_9(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000167_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_77 = (aux + st.buffer[1]) & 3;
  switch (checksum_77)
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
  int metric_12 = local_arr[aux % 3];
  acc = (acc + (metric_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000167_6713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st_1 = {0};
  struct EventLog_R000167_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int window_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_54_1 > 32)
  {
    acc_1 = ((acc_1 + (window_54_1 * 2)) + 5) & 127;
    aux_1 ^= window_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_54_2 > 32)
  {
    acc_2 = ((acc_2 + (window_54_2 * 2)) + 5) & 127;
    aux_2 ^= window_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_55_1) & 63;
  aux_2 = (aux_2 + vector_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_25_1 = local_arr_1[aux_1 % 3];
  int tracker_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_25_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_54_1 == window_54_2);
  assert(vector_55_1 == vector_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_25_1 == tracker_25_2);
}

int fn_R000167_6713_10(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int window_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_54 > 32)
  {
    acc = ((acc + (window_54 * 2)) + 5) & 127;
    aux ^= window_54 & 15;
  }
  else
  {
    acc = ((acc - window_54) + 11) & 127;
    aux += 3;
  }
  int vector_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_55) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_25 = local_arr[aux % 3];
  acc = (acc + (tracker_25 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000167_6713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st_1 = {0};
  struct EventLog_R000167_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_29_1 = local_arr_1[aux_1 % 3];
  int window_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_29_2 * 2)) & 127;
  int tally_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_80_1) & 63;
  aux_2 = (aux_2 + tally_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_93_1 > 32)
  {
    acc_1 = ((acc_1 + (index_reg_93_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_93_2 > 32)
  {
    acc_2 = ((acc_2 + (index_reg_93_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_29_1 == window_29_2);
  assert(tally_80_1 == tally_80_2);
  assert(index_reg_93_1 == index_reg_93_2);
}

int fn_R000167_6713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int window_29 = local_arr[aux % 3];
  acc = (acc + (window_29 * 2)) & 127;
  int tally_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_80) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_93 > 32)
  {
    acc = ((acc + (index_reg_93 * 2)) + 5) & 127;
    aux ^= index_reg_93 & 15;
  }
  else
  {
    acc = ((acc - index_reg_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000167_6713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000167_6713_2 st_1 = {0};
  struct FilterState_R000167_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int vector_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_85_1 > 11)
  {
    acc_1 = ((acc_1 + (vector_85_1 * 2)) + 5) & 127;
    aux_1 ^= vector_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_85_2 > 11)
  {
    acc_2 = ((acc_2 + (vector_85_2 * 2)) + 5) & 127;
    aux_2 ^= vector_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_76_1 = local_arr_1[aux_1 % 3];
  int quantum_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_76_2 * 2)) & 127;
  int cursor_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_40_1)
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

  switch (cursor_40_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_85_1 == vector_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_76_1 == quantum_76_2);
  assert(cursor_40_1 == cursor_40_2);
}

int fn_R000167_6713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000167_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int vector_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_85 > 11)
  {
    acc = ((acc + (vector_85 * 2)) + 5) & 127;
    aux ^= vector_85 & 15;
  }
  else
  {
    acc = ((acc - vector_85) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_76 = local_arr[aux % 3];
  acc = (acc + (quantum_76 * 2)) & 127;
  int cursor_40 = (aux + st.buffer[1]) & 3;
  switch (cursor_40)
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

void fn_R000167_6713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st_1 = {0};
  struct Transaction_R000167_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tracker_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_62_1)
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

  switch (tracker_62_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_30_1) & 63;
  aux_2 = (aux_2 + accumulator_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_53_1 = local_arr_1[aux_1 % 3];
  int tally_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_62_1 == tracker_62_2);
  assert(accumulator_30_1 == accumulator_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_53_1 == tally_53_2);
}

int fn_R000167_6713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tracker_62 = (aux + st.buffer[1]) & 3;
  switch (tracker_62)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_53 = local_arr[aux % 3];
  acc = (acc + (tally_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000167_6713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st_1 = {0};
  struct Transaction_R000167_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int checksum_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_98_1)
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

  switch (checksum_98_2)
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

  int metric_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_76_1 > 17)
  {
    acc_1 = ((acc_1 + (metric_76_1 * 2)) + 5) & 127;
    aux_1 ^= metric_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_76_2 > 17)
  {
    acc_2 = ((acc_2 + (metric_76_2 * 2)) + 5) & 127;
    aux_2 ^= metric_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_76_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_98_1 == checksum_98_2);
  assert(metric_76_1 == metric_76_2);
}

int fn_R000167_6713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000167_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int checksum_98 = (aux + st.buffer[1]) & 3;
  switch (checksum_98)
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

  int metric_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_76 > 17)
  {
    acc = ((acc + (metric_76 * 2)) + 5) & 127;
    aux ^= metric_76 & 15;
  }
  else
  {
    acc = ((acc - metric_76) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000167_6713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st_1 = {0};
  struct EventLog_R000167_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int tracker_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_42_1) & 63;
  aux_2 = (aux_2 + tracker_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_45_1 > 43)
  {
    acc_1 = ((acc_1 + (threshold_45_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_45_2 > 43)
  {
    acc_2 = ((acc_2 + (threshold_45_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_42_1 == tracker_42_2);
  assert(threshold_45_1 == threshold_45_2);
}

int fn_R000167_6713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000167_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int tracker_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_42) & 63;
  acc ^= aux;
  int threshold_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_45 > 43)
  {
    acc = ((acc + (threshold_45 * 2)) + 5) & 127;
    aux ^= threshold_45 & 15;
  }
  else
  {
    acc = ((acc - threshold_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000167_6713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000167_6713_2 st_1 = {0};
  struct FilterState_R000167_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_75_1 = local_arr_1[aux_1 % 3];
  int margin_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_99_1)
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

  switch (phase_99_2)
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

  int cursor_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_69_1) & 63;
  aux_2 = (aux_2 + cursor_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_75_1 == margin_75_2);
  assert(phase_99_1 == phase_99_2);
  assert(cursor_69_1 == cursor_69_2);
}

int fn_R000167_6713_16(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000167_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int margin_75 = local_arr[aux % 3];
  acc = (acc + (margin_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_99 = (aux + st.buffer[1]) & 3;
  switch (phase_99)
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

  int cursor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000167_0_1;
  int sec_r000167_0_2;
  int sec_r000167_1_1;
  int sec_r000167_1_2;
  int sec_r000167_2_1;
  int sec_r000167_2_2;
  int sec_r000167_3_1;
  int sec_r000167_3_2;
  int sec_r000167_4_1;
  int sec_r000167_4_2;
  int sec_r000167_5_1;
  int sec_r000167_5_2;
  int sec_r000167_6_1;
  int sec_r000167_6_2;
  int sec_r000167_7_1;
  int sec_r000167_7_2;
  int sec_r000167_8_1;
  int sec_r000167_8_2;
  int sec_r000167_9_1;
  int sec_r000167_9_2;
  int sec_r000167_10_1;
  int sec_r000167_10_2;
  int sec_r000167_11_1;
  int sec_r000167_11_2;
  int sec_r000167_12_1;
  int sec_r000167_12_2;
  int sec_r000167_13_1;
  int sec_r000167_13_2;
  int sec_r000167_14_1;
  int sec_r000167_14_2;
  int sec_r000167_15_1;
  int sec_r000167_15_2;
  int sec_r000167_16_1;
  int sec_r000167_16_2;
  int sec_r000167_17_1;
  int sec_r000167_17_2;
  int sec_r000167_18_1;
  int sec_r000167_18_2;
  int sec_r000167_19_1;
  int sec_r000167_19_2;
  int sec_r000167_20_1;
  int sec_r000167_20_2;
  int pub_r000167_0_1;
  int pub_r000167_0_2;
  int pub_r000167_1_1;
  int pub_r000167_1_2;
  int pub_r000167_2_1;
  int pub_r000167_2_2;
  int pub_r000167_3_1;
  int pub_r000167_3_2;
  int pub_r000167_4_1;
  int pub_r000167_4_2;
  int pub_r000167_5_1;
  int pub_r000167_5_2;
  int pub_r000167_6_1;
  int pub_r000167_6_2;
  int pub_r000167_7_1;
  int pub_r000167_7_2;
  int pub_r000167_8_1;
  int pub_r000167_8_2;
  int pub_r000167_9_1;
  int pub_r000167_9_2;
  int pub_r000167_10_1;
  int pub_r000167_10_2;
  int pub_r000167_11_1;
  int pub_r000167_11_2;
  int pub_r000167_12_1;
  int pub_r000167_12_2;
  int pub_r000167_13_1;
  int pub_r000167_13_2;
  int pub_r000167_14_1;
  int pub_r000167_14_2;
  int pub_r000167_15_1;
  int pub_r000167_15_2;
  int pub_r000167_16_1;
  int pub_r000167_16_2;
  int pub_r000167_17_1;
  int pub_r000167_17_2;
  int pub_r000167_18_1;
  int pub_r000167_18_2;
  int pub_r000167_19_1;
  int pub_r000167_19_2;
  int pub_r000167_20_1;
  int pub_r000167_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000167_0_1 >= (-100)) && (pub_r000167_0_1 <= 100));
  __CPROVER_assume((pub_r000167_0_2 >= (-100)) && (pub_r000167_0_2 <= 100));
  __CPROVER_assume((pub_r000167_1_1 >= (-100)) && (pub_r000167_1_1 <= 100));
  __CPROVER_assume((pub_r000167_1_2 >= (-100)) && (pub_r000167_1_2 <= 100));
  __CPROVER_assume((pub_r000167_2_1 >= (-100)) && (pub_r000167_2_1 <= 100));
  __CPROVER_assume((pub_r000167_2_2 >= (-100)) && (pub_r000167_2_2 <= 100));
  __CPROVER_assume((pub_r000167_3_1 >= (-100)) && (pub_r000167_3_1 <= 100));
  __CPROVER_assume((pub_r000167_3_2 >= (-100)) && (pub_r000167_3_2 <= 100));
  __CPROVER_assume((pub_r000167_4_1 >= (-100)) && (pub_r000167_4_1 <= 100));
  __CPROVER_assume((pub_r000167_4_2 >= (-100)) && (pub_r000167_4_2 <= 100));
  __CPROVER_assume((pub_r000167_5_1 >= (-100)) && (pub_r000167_5_1 <= 100));
  __CPROVER_assume((pub_r000167_5_2 >= (-100)) && (pub_r000167_5_2 <= 100));
  __CPROVER_assume((pub_r000167_6_1 >= (-100)) && (pub_r000167_6_1 <= 100));
  __CPROVER_assume((pub_r000167_6_2 >= (-100)) && (pub_r000167_6_2 <= 100));
  __CPROVER_assume((pub_r000167_7_1 >= (-100)) && (pub_r000167_7_1 <= 100));
  __CPROVER_assume((pub_r000167_7_2 >= (-100)) && (pub_r000167_7_2 <= 100));
  __CPROVER_assume((pub_r000167_8_1 >= (-100)) && (pub_r000167_8_1 <= 100));
  __CPROVER_assume((pub_r000167_8_2 >= (-100)) && (pub_r000167_8_2 <= 100));
  __CPROVER_assume((pub_r000167_9_1 >= (-100)) && (pub_r000167_9_1 <= 100));
  __CPROVER_assume((pub_r000167_9_2 >= (-100)) && (pub_r000167_9_2 <= 100));
  __CPROVER_assume((pub_r000167_10_1 >= (-100)) && (pub_r000167_10_1 <= 100));
  __CPROVER_assume((pub_r000167_10_2 >= (-100)) && (pub_r000167_10_2 <= 100));
  __CPROVER_assume((pub_r000167_11_1 >= (-100)) && (pub_r000167_11_1 <= 100));
  __CPROVER_assume((pub_r000167_11_2 >= (-100)) && (pub_r000167_11_2 <= 100));
  __CPROVER_assume((pub_r000167_12_1 >= (-100)) && (pub_r000167_12_1 <= 100));
  __CPROVER_assume((pub_r000167_12_2 >= (-100)) && (pub_r000167_12_2 <= 100));
  __CPROVER_assume((pub_r000167_13_1 >= (-100)) && (pub_r000167_13_1 <= 100));
  __CPROVER_assume((pub_r000167_13_2 >= (-100)) && (pub_r000167_13_2 <= 100));
  __CPROVER_assume((pub_r000167_14_1 >= (-100)) && (pub_r000167_14_1 <= 100));
  __CPROVER_assume((pub_r000167_14_2 >= (-100)) && (pub_r000167_14_2 <= 100));
  __CPROVER_assume((pub_r000167_15_1 >= (-100)) && (pub_r000167_15_1 <= 100));
  __CPROVER_assume((pub_r000167_15_2 >= (-100)) && (pub_r000167_15_2 <= 100));
  __CPROVER_assume((pub_r000167_16_1 >= (-100)) && (pub_r000167_16_1 <= 100));
  __CPROVER_assume((pub_r000167_16_2 >= (-100)) && (pub_r000167_16_2 <= 100));
  __CPROVER_assume((pub_r000167_17_1 >= (-100)) && (pub_r000167_17_1 <= 100));
  __CPROVER_assume((pub_r000167_17_2 >= (-100)) && (pub_r000167_17_2 <= 100));
  __CPROVER_assume((pub_r000167_18_1 >= (-100)) && (pub_r000167_18_1 <= 100));
  __CPROVER_assume((pub_r000167_18_2 >= (-100)) && (pub_r000167_18_2 <= 100));
  __CPROVER_assume((pub_r000167_19_1 >= (-100)) && (pub_r000167_19_1 <= 100));
  __CPROVER_assume((pub_r000167_19_2 >= (-100)) && (pub_r000167_19_2 <= 100));
  __CPROVER_assume((pub_r000167_20_1 >= (-100)) && (pub_r000167_20_1 <= 100));
  __CPROVER_assume((pub_r000167_20_2 >= (-100)) && (pub_r000167_20_2 <= 100));
  __CPROVER_assume((sec_r000167_0_1 >= 0) && (sec_r000167_0_1 <= 255));
  __CPROVER_assume((sec_r000167_0_2 >= 0) && (sec_r000167_0_2 <= 255));
  __CPROVER_assume((sec_r000167_1_1 >= 0) && (sec_r000167_1_1 <= 255));
  __CPROVER_assume((sec_r000167_1_2 >= 0) && (sec_r000167_1_2 <= 255));
  __CPROVER_assume((sec_r000167_2_1 >= 0) && (sec_r000167_2_1 <= 255));
  __CPROVER_assume((sec_r000167_2_2 >= 0) && (sec_r000167_2_2 <= 255));
  __CPROVER_assume((sec_r000167_3_1 >= 0) && (sec_r000167_3_1 <= 255));
  __CPROVER_assume((sec_r000167_3_2 >= 0) && (sec_r000167_3_2 <= 255));
  __CPROVER_assume((sec_r000167_4_1 >= 0) && (sec_r000167_4_1 <= 255));
  __CPROVER_assume((sec_r000167_4_2 >= 0) && (sec_r000167_4_2 <= 255));
  __CPROVER_assume((sec_r000167_5_1 >= 0) && (sec_r000167_5_1 <= 255));
  __CPROVER_assume((sec_r000167_5_2 >= 0) && (sec_r000167_5_2 <= 255));
  __CPROVER_assume((sec_r000167_6_1 >= 0) && (sec_r000167_6_1 <= 255));
  __CPROVER_assume((sec_r000167_6_2 >= 0) && (sec_r000167_6_2 <= 255));
  __CPROVER_assume((sec_r000167_7_1 >= 0) && (sec_r000167_7_1 <= 255));
  __CPROVER_assume((sec_r000167_7_2 >= 0) && (sec_r000167_7_2 <= 255));
  __CPROVER_assume((sec_r000167_8_1 >= 0) && (sec_r000167_8_1 <= 255));
  __CPROVER_assume((sec_r000167_8_2 >= 0) && (sec_r000167_8_2 <= 255));
  __CPROVER_assume((sec_r000167_9_1 >= 0) && (sec_r000167_9_1 <= 255));
  __CPROVER_assume((sec_r000167_9_2 >= 0) && (sec_r000167_9_2 <= 255));
  __CPROVER_assume((sec_r000167_10_1 >= 0) && (sec_r000167_10_1 <= 255));
  __CPROVER_assume((sec_r000167_10_2 >= 0) && (sec_r000167_10_2 <= 255));
  __CPROVER_assume((sec_r000167_11_1 >= 0) && (sec_r000167_11_1 <= 255));
  __CPROVER_assume((sec_r000167_11_2 >= 0) && (sec_r000167_11_2 <= 255));
  __CPROVER_assume((sec_r000167_12_1 >= 0) && (sec_r000167_12_1 <= 255));
  __CPROVER_assume((sec_r000167_12_2 >= 0) && (sec_r000167_12_2 <= 255));
  __CPROVER_assume((sec_r000167_13_1 >= 0) && (sec_r000167_13_1 <= 255));
  __CPROVER_assume((sec_r000167_13_2 >= 0) && (sec_r000167_13_2 <= 255));
  __CPROVER_assume((sec_r000167_14_1 >= 0) && (sec_r000167_14_1 <= 255));
  __CPROVER_assume((sec_r000167_14_2 >= 0) && (sec_r000167_14_2 <= 255));
  __CPROVER_assume((sec_r000167_15_1 >= 0) && (sec_r000167_15_1 <= 255));
  __CPROVER_assume((sec_r000167_15_2 >= 0) && (sec_r000167_15_2 <= 255));
  __CPROVER_assume((sec_r000167_16_1 >= 0) && (sec_r000167_16_1 <= 255));
  __CPROVER_assume((sec_r000167_16_2 >= 0) && (sec_r000167_16_2 <= 255));
  __CPROVER_assume((sec_r000167_17_1 >= 0) && (sec_r000167_17_1 <= 255));
  __CPROVER_assume((sec_r000167_17_2 >= 0) && (sec_r000167_17_2 <= 255));
  __CPROVER_assume((sec_r000167_18_1 >= 0) && (sec_r000167_18_1 <= 255));
  __CPROVER_assume((sec_r000167_18_2 >= 0) && (sec_r000167_18_2 <= 255));
  __CPROVER_assume((sec_r000167_19_1 >= 0) && (sec_r000167_19_1 <= 255));
  __CPROVER_assume((sec_r000167_19_2 >= 0) && (sec_r000167_19_2 <= 255));
  __CPROVER_assume((sec_r000167_20_1 >= 0) && (sec_r000167_20_1 <= 255));
  __CPROVER_assume((sec_r000167_20_2 >= 0) && (sec_r000167_20_2 <= 255));
  struct Transaction_R000167_6713_0 st_var_0_1 = {0};
  struct Transaction_R000167_6713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000167_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000167_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000167_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000167_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000167_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000167_0_2 + 7) & 15;
  struct EventLog_R000167_6713_1 st_var_1_1 = {0};
  struct EventLog_R000167_6713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000167_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000167_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000167_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000167_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000167_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000167_0_2 + 9) & 15;
  struct FilterState_R000167_6713_2 st_var_2_1 = {0};
  struct FilterState_R000167_6713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000167_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000167_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000167_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000167_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000167_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000167_0_2 + 11) & 15;
  struct SensorNode_R000167_6713_3 st_var_3_1 = {0};
  struct SensorNode_R000167_6713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000167_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000167_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000167_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000167_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000167_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000167_0_2 + 13) & 15;
  union PacketPayload_R000167_6713_0 u_var_1;
  union PacketPayload_R000167_6713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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
  int stage_v_7_1 = ((st_var_3_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_3_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 42)
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
  if (stage_v_7_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 42)
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
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 49)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 49)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_10_1 = (st_var_2_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_2_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 35)
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
  if (stage_v_17_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 35)
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
  int stage_v_18_1 = ((st_var_2_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_2_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 39)
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
  if (stage_v_18_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 39)
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
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
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
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (st_var_2_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_2_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 37)
    {
      chk_sum_1 ^= stage_v_24_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_24_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 37)
    {
      chk_sum_2 ^= stage_v_24_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
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
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

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
  if (stage_v_32_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 25)
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
  if (stage_v_32_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 25)
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
  int stage_v_33_1 = ((st_var_1_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_1_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 48)
    {
      chk_sum_1 ^= stage_v_33_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_33_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 48)
    {
      chk_sum_2 ^= stage_v_33_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = (st_var_3_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_3_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = ((st_var_2_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_2_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 26)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 26)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
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
  if (stage_v_47_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 40)
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
  if (stage_v_47_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 40)
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
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = (st_var_2_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_2_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = ((st_var_3_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_3_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 41)
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
  if (stage_v_59_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 41)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (st_var_3_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_3_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
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

  switch (stage_v_63_2)
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

  int stage_v_64_1 = (st_var_0_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_0_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000167_8_1 & 1) != 0)
  {
    if ((sec_r000167_1_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000167_5_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000167_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000167_5_1 + 7) & 127;
  }
  if ((sec_r000167_8_2 & 1) != 0)
  {
    if ((sec_r000167_1_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000167_5_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000167_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000167_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000167_17_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000167_3_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000167_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000167_3_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000167_17_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000167_3_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000167_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000167_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000167_18_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000167_6_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000167_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000167_6_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000167_18_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000167_6_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000167_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000167_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000167_15_1 & 1) != 0)
  {
    if ((sec_r000167_19_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000167_20_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000167_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000167_20_1 + 7) & 127;
  }
  if ((sec_r000167_15_2 & 1) != 0)
  {
    if ((sec_r000167_19_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000167_20_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000167_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000167_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000167_1_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000167_6_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000167_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000167_6_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000167_1_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000167_6_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000167_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000167_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000167_11_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000167_3_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000167_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000167_3_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000167_11_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000167_3_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000167_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000167_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000167_1_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000167_16_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000167_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000167_16_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000167_1_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000167_16_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000167_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000167_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000167_20_1 & 1) != 0)
  {
    if ((sec_r000167_16_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000167_11_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000167_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000167_11_1 + 7) & 127;
  }
  if ((sec_r000167_20_2 & 1) != 0)
  {
    if ((sec_r000167_16_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000167_11_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000167_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000167_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000167_15_1 & 1) != 0)
  {
    if ((sec_r000167_14_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000167_7_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000167_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000167_7_1 + 7) & 127;
  }
  if ((sec_r000167_15_2 & 1) != 0)
  {
    if ((sec_r000167_14_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000167_7_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000167_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000167_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000167_8_1 & 1) != 0)
  {
    if ((sec_r000167_8_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000167_4_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000167_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000167_4_1 + 7) & 127;
  }
  if ((sec_r000167_8_2 & 1) != 0)
  {
    if ((sec_r000167_8_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000167_4_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000167_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000167_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000167_1_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000167_13_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000167_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000167_13_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000167_1_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000167_13_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000167_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000167_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000167_13_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000167_15_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000167_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000167_15_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000167_13_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000167_15_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000167_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000167_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000167_12_1 & 1) != 0)
  {
    if ((sec_r000167_14_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000167_9_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000167_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000167_9_1 + 7) & 127;
  }
  if ((sec_r000167_12_2 & 1) != 0)
  {
    if ((sec_r000167_14_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000167_9_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000167_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000167_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000167_3_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000167_14_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000167_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000167_14_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000167_3_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000167_14_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000167_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000167_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000167_5_1 & 1) != 0)
  {
    if ((sec_r000167_20_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000167_0_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000167_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000167_0_1 + 7) & 127;
  }
  if ((sec_r000167_5_2 & 1) != 0)
  {
    if ((sec_r000167_20_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000167_0_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000167_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000167_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000167_12_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000167_8_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000167_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000167_8_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000167_12_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000167_8_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000167_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000167_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000167_7_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000167_10_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000167_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000167_10_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000167_7_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000167_10_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000167_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000167_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000167_16_1 & 1) != 0)
  {
    if ((sec_r000167_8_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000167_9_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000167_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000167_9_1 + 7) & 127;
  }
  if ((sec_r000167_16_2 & 1) != 0)
  {
    if ((sec_r000167_8_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000167_9_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000167_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000167_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000167_5_1 & 1) != 0)
  {
    if ((sec_r000167_13_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000167_6_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000167_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000167_6_1 + 7) & 127;
  }
  if ((sec_r000167_5_2 & 1) != 0)
  {
    if ((sec_r000167_13_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000167_6_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000167_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000167_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000167_10_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000167_16_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000167_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000167_16_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000167_10_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000167_16_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000167_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000167_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000167_10_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000167_2_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000167_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000167_2_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000167_10_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000167_2_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000167_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000167_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000167_6_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000167_0_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000167_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000167_0_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000167_6_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000167_0_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000167_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000167_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000167_2_1 & 1) != 0)
  {
    if ((sec_r000167_18_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000167_16_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000167_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000167_16_1 + 7) & 127;
  }
  if ((sec_r000167_2_2 & 1) != 0)
  {
    if ((sec_r000167_18_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000167_16_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000167_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000167_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000167_7_1 & 1) != 0)
  {
    if ((sec_r000167_9_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000167_9_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000167_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000167_9_1 + 7) & 127;
  }
  if ((sec_r000167_7_2 & 1) != 0)
  {
    if ((sec_r000167_9_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000167_9_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000167_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000167_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000167_19_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000167_11_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000167_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000167_11_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000167_19_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000167_11_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000167_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000167_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000167_6_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000167_13_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000167_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000167_13_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000167_6_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000167_13_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000167_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000167_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000167_11_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000167_17_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000167_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000167_17_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000167_11_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000167_17_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000167_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000167_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000167_2_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000167_4_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000167_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000167_4_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000167_2_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000167_4_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000167_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000167_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000167_7_1 & 1) != 0)
  {
    if ((sec_r000167_13_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000167_4_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000167_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000167_4_1 + 7) & 127;
  }
  if ((sec_r000167_7_2 & 1) != 0)
  {
    if ((sec_r000167_13_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000167_4_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000167_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000167_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000167_13_1 & 1) != 0)
  {
    if ((sec_r000167_15_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000167_4_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000167_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000167_4_1 + 7) & 127;
  }
  if ((sec_r000167_13_2 & 1) != 0)
  {
    if ((sec_r000167_15_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000167_4_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000167_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000167_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000167_14_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000167_0_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000167_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000167_0_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000167_14_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000167_0_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000167_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000167_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000167_13_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000167_18_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000167_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000167_18_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000167_13_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000167_18_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000167_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000167_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000167_1_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000167_5_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000167_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000167_5_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000167_1_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000167_5_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000167_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000167_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000167_15_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000167_1_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000167_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000167_1_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000167_15_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000167_1_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000167_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000167_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000167_9_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000167_19_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000167_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000167_19_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000167_9_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000167_19_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000167_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000167_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000167_10_1 & 1) != 0)
  {
    if ((sec_r000167_12_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000167_16_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000167_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000167_16_1 + 7) & 127;
  }
  if ((sec_r000167_10_2 & 1) != 0)
  {
    if ((sec_r000167_12_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000167_16_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000167_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000167_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000167_19_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000167_1_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000167_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000167_1_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000167_19_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000167_1_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000167_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000167_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000167_2_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000167_6_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000167_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000167_6_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000167_2_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000167_6_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000167_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000167_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000167_6_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000167_15_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000167_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000167_15_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000167_6_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000167_15_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000167_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000167_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000167_5_1 & 1) != 0)
  {
    if ((sec_r000167_14_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000167_13_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000167_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000167_13_1 + 7) & 127;
  }
  if ((sec_r000167_5_2 & 1) != 0)
  {
    if ((sec_r000167_14_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000167_13_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000167_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000167_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000167_18_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000167_20_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000167_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000167_20_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000167_18_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000167_20_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000167_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000167_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000167_18_1 & 1) != 0)
  {
    if ((sec_r000167_7_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000167_8_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000167_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000167_8_1 + 7) & 127;
  }
  if ((sec_r000167_18_2 & 1) != 0)
  {
    if ((sec_r000167_7_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000167_8_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000167_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000167_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000167_20_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000167_9_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000167_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000167_9_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000167_20_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000167_9_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000167_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000167_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000167_14_1 & 1) != 0)
  {
    if ((sec_r000167_12_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000167_16_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000167_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000167_16_1 + 7) & 127;
  }
  if ((sec_r000167_14_2 & 1) != 0)
  {
    if ((sec_r000167_12_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000167_16_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000167_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000167_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000167_14_1 & 1) != 0)
  {
    if ((sec_r000167_3_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000167_13_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000167_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000167_13_1 + 7) & 127;
  }
  if ((sec_r000167_14_2 & 1) != 0)
  {
    if ((sec_r000167_3_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000167_13_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000167_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000167_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000167_9_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000167_13_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000167_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000167_13_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000167_9_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000167_13_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000167_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000167_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000167_8_1 & 1) != 0)
  {
    if ((sec_r000167_20_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000167_11_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000167_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000167_11_1 + 7) & 127;
  }
  if ((sec_r000167_8_2 & 1) != 0)
  {
    if ((sec_r000167_20_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000167_11_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000167_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000167_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000167_5_1 & 1) != 0)
  {
    if ((sec_r000167_7_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000167_16_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000167_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000167_16_1 + 7) & 127;
  }
  if ((sec_r000167_5_2 & 1) != 0)
  {
    if ((sec_r000167_7_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000167_16_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000167_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000167_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000167_15_1 & 1) != 0)
  {
    if ((sec_r000167_17_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000167_14_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000167_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000167_14_1 + 7) & 127;
  }
  if ((sec_r000167_15_2 & 1) != 0)
  {
    if ((sec_r000167_17_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000167_14_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000167_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000167_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000167_11_1 & 1) != 0)
  {
    if ((sec_r000167_0_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000167_20_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000167_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000167_20_1 + 7) & 127;
  }
  if ((sec_r000167_11_2 & 1) != 0)
  {
    if ((sec_r000167_0_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000167_20_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000167_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000167_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000167_11_1 & 1) != 0)
  {
    if ((sec_r000167_7_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000167_0_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000167_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000167_0_1 + 7) & 127;
  }
  if ((sec_r000167_11_2 & 1) != 0)
  {
    if ((sec_r000167_7_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000167_0_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000167_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000167_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000167_0_1 & 1) != 0)
  {
    if ((sec_r000167_11_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000167_7_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000167_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000167_7_1 + 7) & 127;
  }
  if ((sec_r000167_0_2 & 1) != 0)
  {
    if ((sec_r000167_11_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000167_7_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000167_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000167_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000167_3_1 & 1) != 0)
  {
    if ((sec_r000167_11_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000167_9_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000167_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000167_9_1 + 7) & 127;
  }
  if ((sec_r000167_3_2 & 1) != 0)
  {
    if ((sec_r000167_11_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000167_9_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000167_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000167_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000167_8_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000167_14_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000167_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000167_14_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000167_8_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000167_14_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000167_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000167_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000167_7_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000167_6_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000167_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000167_6_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000167_7_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000167_6_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000167_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000167_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000167_13_1 & 1) != 0)
  {
    if ((sec_r000167_8_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000167_17_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000167_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000167_17_1 + 7) & 127;
  }
  if ((sec_r000167_13_2 & 1) != 0)
  {
    if ((sec_r000167_8_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000167_17_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000167_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000167_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000167_19_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000167_13_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000167_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000167_13_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000167_19_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000167_13_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000167_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000167_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000167_7_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000167_2_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000167_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000167_2_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000167_7_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000167_2_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000167_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000167_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000167_16_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000167_11_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000167_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000167_11_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000167_16_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000167_11_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000167_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000167_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000167_3_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000167_11_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000167_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000167_11_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000167_3_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000167_11_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000167_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000167_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000167_18_1 & 1) != 0)
  {
    if ((sec_r000167_3_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000167_12_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000167_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000167_12_1 + 7) & 127;
  }
  if ((sec_r000167_18_2 & 1) != 0)
  {
    if ((sec_r000167_3_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000167_12_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000167_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000167_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000167_11_1 & 1) != 0)
  {
    if ((sec_r000167_6_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000167_2_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000167_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000167_2_1 + 7) & 127;
  }
  if ((sec_r000167_11_2 & 1) != 0)
  {
    if ((sec_r000167_6_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000167_2_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000167_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000167_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000167_14_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000167_3_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000167_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000167_3_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000167_14_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000167_3_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000167_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000167_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000167_20_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000167_15_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000167_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000167_15_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000167_20_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000167_15_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000167_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000167_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000167_17_1 & 1) != 0)
  {
    if ((sec_r000167_0_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000167_10_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000167_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000167_10_1 + 7) & 127;
  }
  if ((sec_r000167_17_2 & 1) != 0)
  {
    if ((sec_r000167_0_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000167_10_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000167_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000167_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r000167_6_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000167_2_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000167_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000167_2_1 + 7) & 127;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((sec_r000167_6_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000167_2_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000167_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000167_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000167_3_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000167_4_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000167_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000167_4_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000167_3_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000167_4_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000167_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000167_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000167_1_1 & 1) != 0)
  {
    if ((sec_r000167_20_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000167_18_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000167_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000167_18_1 + 7) & 127;
  }
  if ((sec_r000167_1_2 & 1) != 0)
  {
    if ((sec_r000167_20_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000167_18_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000167_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000167_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000167_11_1 & 1) != 0)
  {
    if ((sec_r000167_20_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000167_20_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000167_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000167_20_1 + 7) & 127;
  }
  if ((sec_r000167_11_2 & 1) != 0)
  {
    if ((sec_r000167_20_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000167_20_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000167_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000167_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000167_20_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000167_14_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000167_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000167_14_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000167_20_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000167_14_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000167_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000167_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000167_2_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000167_4_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000167_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000167_4_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000167_2_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000167_4_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000167_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000167_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000167_18_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000167_7_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000167_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000167_7_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000167_18_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000167_7_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000167_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000167_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000167_11_1 & 1) != 0)
  {
    if ((sec_r000167_19_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000167_11_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000167_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000167_11_1 + 7) & 127;
  }
  if ((sec_r000167_11_2 & 1) != 0)
  {
    if ((sec_r000167_19_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000167_11_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000167_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000167_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000167_20_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000167_20_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000167_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000167_20_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000167_20_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000167_20_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000167_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000167_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000167_14_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000167_2_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000167_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000167_2_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000167_14_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000167_2_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000167_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000167_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000167_5_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000167_1_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000167_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000167_1_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000167_5_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000167_1_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000167_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000167_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((sec_r000167_2_1 & 1) != 0)
  {
    if ((sec_r000167_4_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000167_16_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000167_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000167_16_1 + 7) & 127;
  }
  if ((sec_r000167_2_2 & 1) != 0)
  {
    if ((sec_r000167_4_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000167_16_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000167_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000167_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000167_12_1 & 1) != 0)
  {
    if ((sec_r000167_17_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000167_5_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000167_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000167_5_1 + 7) & 127;
  }
  if ((sec_r000167_12_2 & 1) != 0)
  {
    if ((sec_r000167_17_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000167_5_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000167_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000167_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((sec_r000167_8_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000167_8_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000167_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000167_8_1 + 7) & 127;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((sec_r000167_8_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000167_8_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000167_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000167_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000167_6_1 & 1) != 0)
  {
    if ((sec_r000167_19_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000167_15_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000167_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000167_15_1 + 7) & 127;
  }
  if ((sec_r000167_6_2 & 1) != 0)
  {
    if ((sec_r000167_19_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000167_15_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000167_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000167_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000167_18_1 & 1) != 0)
  {
    if ((sec_r000167_14_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000167_0_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000167_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000167_0_1 + 7) & 127;
  }
  if ((sec_r000167_18_2 & 1) != 0)
  {
    if ((sec_r000167_14_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000167_0_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000167_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000167_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000167_5_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000167_1_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000167_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000167_1_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000167_5_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000167_1_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000167_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000167_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000167_15_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000167_15_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000167_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000167_15_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000167_15_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000167_15_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000167_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000167_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000167_20_1 & 1) != 0)
  {
    if ((sec_r000167_8_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000167_15_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000167_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000167_15_1 + 7) & 127;
  }
  if ((sec_r000167_20_2 & 1) != 0)
  {
    if ((sec_r000167_8_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000167_15_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000167_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000167_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000167_13_1 & 1) != 0)
  {
    if ((sec_r000167_10_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000167_11_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000167_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000167_11_1 + 7) & 127;
  }
  if ((sec_r000167_13_2 & 1) != 0)
  {
    if ((sec_r000167_10_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000167_11_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000167_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000167_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000167_12_1 & 1) != 0)
  {
    if ((sec_r000167_20_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000167_5_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000167_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000167_5_1 + 7) & 127;
  }
  if ((sec_r000167_12_2 & 1) != 0)
  {
    if ((sec_r000167_20_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000167_5_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000167_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000167_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((sec_r000167_18_1 & 1) != 0)
  {
    if ((sec_r000167_1_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000167_6_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000167_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000167_6_1 + 7) & 127;
  }
  if ((sec_r000167_18_2 & 1) != 0)
  {
    if ((sec_r000167_1_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000167_6_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000167_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000167_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((sec_r000167_2_1 & 1) != 0)
  {
    if ((sec_r000167_2_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000167_19_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000167_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000167_19_1 + 7) & 127;
  }
  if ((sec_r000167_2_2 & 1) != 0)
  {
    if ((sec_r000167_2_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000167_19_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000167_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000167_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000167_19_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000167_16_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000167_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000167_16_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000167_19_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000167_16_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000167_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000167_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000167_18_1 & 1) != 0)
  {
    if ((sec_r000167_1_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000167_11_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000167_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000167_11_1 + 7) & 127;
  }
  if ((sec_r000167_18_2 & 1) != 0)
  {
    if ((sec_r000167_1_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000167_11_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000167_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000167_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000167_4_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000167_5_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000167_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000167_5_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000167_4_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000167_5_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000167_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000167_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((sec_r000167_0_1 & 1) != 0)
  {
    if ((sec_r000167_2_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000167_6_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000167_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000167_6_1 + 7) & 127;
  }
  if ((sec_r000167_0_2 & 1) != 0)
  {
    if ((sec_r000167_2_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000167_6_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000167_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000167_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((sec_r000167_7_1 & 1) != 0)
  {
    if ((sec_r000167_15_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000167_11_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000167_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000167_11_1 + 7) & 127;
  }
  if ((sec_r000167_7_2 & 1) != 0)
  {
    if ((sec_r000167_15_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000167_11_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000167_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000167_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r000167_19_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000167_6_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000167_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000167_6_1 + 7) & 127;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r000167_19_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000167_6_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000167_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000167_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000167_15_1 & 1) != 0)
  {
    if ((sec_r000167_18_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000167_20_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000167_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000167_20_1 + 7) & 127;
  }
  if ((sec_r000167_15_2 & 1) != 0)
  {
    if ((sec_r000167_18_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000167_20_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000167_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000167_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000167_15_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000167_9_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000167_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000167_9_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000167_15_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000167_9_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000167_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000167_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000167_13_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000167_12_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000167_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000167_12_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000167_13_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000167_12_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000167_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000167_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((sec_r000167_1_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000167_17_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000167_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000167_17_1 + 7) & 127;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((sec_r000167_1_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000167_17_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000167_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000167_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((sec_r000167_6_1 & 1) != 0)
  {
    if ((sec_r000167_13_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000167_16_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000167_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000167_16_1 + 7) & 127;
  }
  if ((sec_r000167_6_2 & 1) != 0)
  {
    if ((sec_r000167_13_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000167_16_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000167_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000167_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((sec_r000167_19_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000167_20_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000167_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000167_20_1 + 7) & 127;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((sec_r000167_19_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000167_20_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000167_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000167_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000167_5_1 & 2) != 0)
    {
      stage_v_166_1 = (pub_r000167_12_1 + 31) & 127;
    }
    else
    {
      stage_v_166_1 = (pub_r000167_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_1 = (pub_r000167_12_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000167_5_2 & 2) != 0)
    {
      stage_v_166_2 = (pub_r000167_12_2 + 31) & 127;
    }
    else
    {
      stage_v_166_2 = (pub_r000167_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_166_2 = (pub_r000167_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  if ((sec_r000167_4_1 & 1) != 0)
  {
    if ((sec_r000167_6_1 & 2) != 0)
    {
      stage_v_167_1 = (pub_r000167_15_1 + 31) & 127;
    }
    else
    {
      stage_v_167_1 = (pub_r000167_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_1 = (pub_r000167_15_1 + 7) & 127;
  }
  if ((sec_r000167_4_2 & 1) != 0)
  {
    if ((sec_r000167_6_2 & 2) != 0)
    {
      stage_v_167_2 = (pub_r000167_15_2 + 31) & 127;
    }
    else
    {
      stage_v_167_2 = (pub_r000167_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_167_2 = (pub_r000167_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000167_4_1 == pub_r000167_4_2);
  __CPROVER_assume(pub_r000167_1_1 == pub_r000167_1_2);
  __CPROVER_assume(pub_r000167_17_1 == pub_r000167_17_2);
  __CPROVER_assume(sec_r000167_3_1 != sec_r000167_3_2);
  __CPROVER_assume(sec_r000167_7_1 != sec_r000167_7_2);
  __CPROVER_assume(sec_r000167_18_1 != sec_r000167_18_2);
  __CPROVER_assume(pub_r000167_19_1 == pub_r000167_19_2);
  __CPROVER_assume(pub_r000167_10_1 == pub_r000167_10_2);
  __CPROVER_assume(pub_r000167_0_1 == pub_r000167_0_2);
  __CPROVER_assume(pub_r000167_8_1 == pub_r000167_8_2);
  __CPROVER_assume(sec_r000167_4_1 != sec_r000167_4_2);
  __CPROVER_assume(sec_r000167_12_1 != sec_r000167_12_2);
  __CPROVER_assume(sec_r000167_20_1 != sec_r000167_20_2);
  __CPROVER_assume(pub_r000167_16_1 == pub_r000167_16_2);
  __CPROVER_assume(pub_r000167_9_1 == pub_r000167_9_2);
  __CPROVER_assume(pub_r000167_11_1 == pub_r000167_11_2);
  __CPROVER_assume(sec_r000167_19_1 != sec_r000167_19_2);
  __CPROVER_assume(pub_r000167_3_1 == pub_r000167_3_2);
  __CPROVER_assume(sec_r000167_6_1 != sec_r000167_6_2);
  __CPROVER_assume(sec_r000167_13_1 != sec_r000167_13_2);
  __CPROVER_assume(sec_r000167_8_1 != sec_r000167_8_2);
  __CPROVER_assume(sec_r000167_2_1 != sec_r000167_2_2);
  __CPROVER_assume(sec_r000167_1_1 != sec_r000167_1_2);
  __CPROVER_assume(sec_r000167_14_1 != sec_r000167_14_2);
  __CPROVER_assume(sec_r000167_16_1 != sec_r000167_16_2);
  __CPROVER_assume(pub_r000167_7_1 == pub_r000167_7_2);
  __CPROVER_assume(sec_r000167_17_1 != sec_r000167_17_2);
  __CPROVER_assume(pub_r000167_13_1 == pub_r000167_13_2);
  __CPROVER_assume(pub_r000167_15_1 == pub_r000167_15_2);
  __CPROVER_assume(pub_r000167_18_1 == pub_r000167_18_2);
  __CPROVER_assume(sec_r000167_11_1 != sec_r000167_11_2);
  __CPROVER_assume(sec_r000167_10_1 != sec_r000167_10_2);
  __CPROVER_assume(pub_r000167_5_1 == pub_r000167_5_2);
  __CPROVER_assume(pub_r000167_6_1 == pub_r000167_6_2);
  __CPROVER_assume(sec_r000167_5_1 != sec_r000167_5_2);
  __CPROVER_assume(sec_r000167_0_1 != sec_r000167_0_2);
  __CPROVER_assume(sec_r000167_15_1 != sec_r000167_15_2);
  __CPROVER_assume(pub_r000167_14_1 == pub_r000167_14_2);
  __CPROVER_assume(sec_r000167_9_1 != sec_r000167_9_2);
  __CPROVER_assume(pub_r000167_20_1 == pub_r000167_20_2);
  __CPROVER_assume(pub_r000167_12_1 == pub_r000167_12_2);
  __CPROVER_assume(pub_r000167_2_1 == pub_r000167_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.calib == st_var_3_2.calib);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.threshold == st_var_3_2.threshold);
  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.reading == st_var_3_2.reading);
  assert(st_var_3_1.status == st_var_3_2.status);
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
}


