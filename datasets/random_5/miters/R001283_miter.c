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
struct SensorNode_R001283_8313_0
{
  unsigned char calib;
  int status;
  int gain;
  short reading;
  int buffer[3];
};
struct Transaction_R001283_8313_1
{
  unsigned char rate;
  unsigned char status;
  short account_id;
  int auth_code;
  int balance;
  int fee;
  int buffer[3];
};
struct EventLog_R001283_8313_2
{
  unsigned char code;
  int severity;
  short signature;
  short seq;
  int buffer[3];
};
union ColorPixel_R001283_8313_0
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
void fn_R001283_8313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st_1 = {0};
  struct Transaction_R001283_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int delta_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_67_1 > 20)
  {
    acc_1 = ((acc_1 + (delta_67_1 * 2)) + 5) & 127;
    aux_1 ^= delta_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_67_2 > 20)
  {
    acc_2 = ((acc_2 + (delta_67_2 * 2)) + 5) & 127;
    aux_2 ^= delta_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_28_1) & 63;
  aux_2 = (aux_2 + scale_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_67_1 == delta_67_2);
  assert(scale_28_1 == scale_28_2);
}

int fn_R001283_8313_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int delta_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_67 > 20)
  {
    acc = ((acc + (delta_67 * 2)) + 5) & 127;
    aux ^= delta_67 & 15;
  }
  else
  {
    acc = ((acc - delta_67) + 11) & 127;
    aux += 3;
  }
  int scale_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001283_8313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st_1 = {0};
  struct Transaction_R001283_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int scale_17_1 = 0;
  int scale_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_17_1 = ((scale_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_17_2 = ((scale_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_17_1) & 127;
    acc_2 = (acc_2 + scale_17_2) & 127;
  }

  int mask_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_75_1 > 26)
  {
    acc_1 = ((acc_1 + (mask_75_1 * 2)) + 5) & 127;
    aux_1 ^= mask_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_75_2 > 26)
  {
    acc_2 = ((acc_2 + (mask_75_2 * 2)) + 5) & 127;
    aux_2 ^= mask_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_17_1 == scale_17_2);
  assert(mask_75_1 == mask_75_2);
}

int fn_R001283_8313_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int scale_17 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_17 = ((scale_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_17) & 127;
  }

  int mask_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_75 > 26)
  {
    acc = ((acc + (mask_75 * 2)) + 5) & 127;
    aux ^= mask_75 & 15;
  }
  else
  {
    acc = ((acc - mask_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001283_8313_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st_1 = {0};
  struct SensorNode_R001283_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_65_1 = local_arr_1[aux_1 % 3];
  int phase_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_65_2 * 2)) & 127;
  int accumulator_57_1 = 0;
  int accumulator_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_57_1 = ((accumulator_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_57_2 = ((accumulator_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_57_1) & 127;
    acc_2 = (acc_2 + accumulator_57_2) & 127;
  }

  int tracker_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_20_1 > 15)
  {
    acc_1 = ((acc_1 + (tracker_20_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_20_2 > 15)
  {
    acc_2 = ((acc_2 + (tracker_20_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_65_1 == phase_65_2);
  assert(accumulator_57_1 == accumulator_57_2);
  assert(tracker_20_1 == tracker_20_2);
}

int fn_R001283_8313_2(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int phase_65 = local_arr[aux % 3];
  acc = (acc + (phase_65 * 2)) & 127;
  int accumulator_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_57 = ((accumulator_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_57) & 127;
  }

  int tracker_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_20 > 15)
  {
    acc = ((acc + (tracker_20 * 2)) + 5) & 127;
    aux ^= tracker_20 & 15;
  }
  else
  {
    acc = ((acc - tracker_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001283_8313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st_1 = {0};
  struct SensorNode_R001283_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int quantum_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_99_1)
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

  switch (quantum_99_2)
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
  int mask_58_1 = local_arr_1[aux_1 % 3];
  int mask_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_99_1 == quantum_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_58_1 == mask_58_2);
}

int fn_R001283_8313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int quantum_99 = (aux + st.buffer[1]) & 3;
  switch (quantum_99)
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
  int mask_58 = local_arr[aux % 3];
  acc = (acc + (mask_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001283_8313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st_1 = {0};
  struct Transaction_R001283_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int margin_44_1 = 0;
  int margin_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_44_1 = ((margin_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_44_2 = ((margin_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_44_1) & 127;
    acc_2 = (acc_2 + margin_44_2) & 127;
  }

  int stride_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_35_1)
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

  switch (stride_35_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_44_1 == margin_44_2);
  assert(stride_35_1 == stride_35_2);
}

int fn_R001283_8313_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int margin_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_44 = ((margin_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_44) & 127;
  }

  int stride_35 = (aux + st.buffer[1]) & 3;
  switch (stride_35)
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

void fn_R001283_8313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st_1 = {0};
  struct SensorNode_R001283_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int tally_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_87_1 > 28)
  {
    acc_1 = ((acc_1 + (tally_87_1 * 2)) + 5) & 127;
    aux_1 ^= tally_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_87_2 > 28)
  {
    acc_2 = ((acc_2 + (tally_87_2 * 2)) + 5) & 127;
    aux_2 ^= tally_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_87_1 = 0;
  int tally_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_87_1 = ((tally_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_87_2 = ((tally_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_87_1) & 127;
    acc_2 = (acc_2 + tally_87_2) & 127;
  }

  int threshold_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_84_1)
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

  switch (threshold_84_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_87_1 == tally_87_2);
  assert(threshold_84_1 == threshold_84_2);
}

int fn_R001283_8313_5(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int tally_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_87 > 28)
  {
    acc = ((acc + (tally_87 * 2)) + 5) & 127;
    aux ^= tally_87 & 15;
  }
  else
  {
    acc = ((acc - tally_87) + 11) & 127;
    aux += 3;
  }
  int tally_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_87 = ((tally_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_87) & 127;
  }

  int threshold_84 = (aux + st.buffer[1]) & 3;
  switch (threshold_84)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001283_8313_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st_1 = {0};
  struct Transaction_R001283_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int mask_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_75_1 > 38)
  {
    acc_1 = ((acc_1 + (mask_75_1 * 2)) + 5) & 127;
    aux_1 ^= mask_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_75_2 > 38)
  {
    acc_2 = ((acc_2 + (mask_75_2 * 2)) + 5) & 127;
    aux_2 ^= mask_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_10_1)
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

  switch (phase_10_2)
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
  int segment_68_1 = local_arr_1[aux_1 % 3];
  int segment_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_68_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_75_1 == mask_75_2);
  assert(phase_10_1 == phase_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_68_1 == segment_68_2);
}

int fn_R001283_8313_6(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int mask_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_75 > 38)
  {
    acc = ((acc + (mask_75 * 2)) + 5) & 127;
    aux ^= mask_75 & 15;
  }
  else
  {
    acc = ((acc - mask_75) + 11) & 127;
    aux += 3;
  }
  int phase_10 = (aux + st.buffer[1]) & 3;
  switch (phase_10)
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
  int segment_68 = local_arr[aux % 3];
  acc = (acc + (segment_68 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001283_8313_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st_1 = {0};
  struct SensorNode_R001283_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int delta_60_1 = 0;
  int delta_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_60_1 = ((delta_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_60_2 = ((delta_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_60_1) & 127;
    acc_2 = (acc_2 + delta_60_2) & 127;
  }

  int pivot_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_72_1 > 13)
  {
    acc_1 = ((acc_1 + (pivot_72_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_72_2 > 13)
  {
    acc_2 = ((acc_2 + (pivot_72_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_81_1)
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

  switch (tracker_81_2)
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

  int segment_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_28_1) & 63;
  aux_2 = (aux_2 + segment_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_60_1 == delta_60_2);
  assert(pivot_72_1 == pivot_72_2);
  assert(tracker_81_1 == tracker_81_2);
  assert(segment_28_1 == segment_28_2);
}

int fn_R001283_8313_7(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int delta_60 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_60 = ((delta_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_60) & 127;
  }

  int pivot_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_72 > 13)
  {
    acc = ((acc + (pivot_72 * 2)) + 5) & 127;
    aux ^= pivot_72 & 15;
  }
  else
  {
    acc = ((acc - pivot_72) + 11) & 127;
    aux += 3;
  }
  int tracker_81 = (aux + st.buffer[1]) & 3;
  switch (tracker_81)
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

  int segment_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001283_8313_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st_1 = {0};
  struct SensorNode_R001283_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int phase_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_68_1 > 24)
  {
    acc_1 = ((acc_1 + (phase_68_1 * 2)) + 5) & 127;
    aux_1 ^= phase_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_68_2 > 24)
  {
    acc_2 = ((acc_2 + (phase_68_2 * 2)) + 5) & 127;
    aux_2 ^= phase_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_91_1 = local_arr_1[aux_1 % 3];
  int quotient_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_91_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_94_1)
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

  switch (phase_94_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_68_1 == phase_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_91_1 == quotient_91_2);
  assert(phase_94_1 == phase_94_2);
}

int fn_R001283_8313_8(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int phase_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_68 > 24)
  {
    acc = ((acc + (phase_68 * 2)) + 5) & 127;
    aux ^= phase_68 & 15;
  }
  else
  {
    acc = ((acc - phase_68) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_91 = local_arr[aux % 3];
  acc = (acc + (quotient_91 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_94 = (aux + st.buffer[1]) & 3;
  switch (phase_94)
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

void fn_R001283_8313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st_1 = {0};
  struct Transaction_R001283_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int metric_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_46_1 > 49)
  {
    acc_1 = ((acc_1 + (metric_46_1 * 2)) + 5) & 127;
    aux_1 ^= metric_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_46_2 > 49)
  {
    acc_2 = ((acc_2 + (metric_46_2 * 2)) + 5) & 127;
    aux_2 ^= metric_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_28_1)
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

  switch (metric_28_2)
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
  int phase_91_1 = local_arr_1[aux_1 % 3];
  int phase_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_91_2 * 2)) & 127;
  int window_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_12_1) & 63;
  aux_2 = (aux_2 + window_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_46_1 == metric_46_2);
  assert(metric_28_1 == metric_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_91_1 == phase_91_2);
  assert(window_12_1 == window_12_2);
}

int fn_R001283_8313_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int metric_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_46 > 49)
  {
    acc = ((acc + (metric_46 * 2)) + 5) & 127;
    aux ^= metric_46 & 15;
  }
  else
  {
    acc = ((acc - metric_46) + 11) & 127;
    aux += 3;
  }
  int metric_28 = (aux + st.buffer[1]) & 3;
  switch (metric_28)
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
  int phase_91 = local_arr[aux % 3];
  acc = (acc + (phase_91 * 2)) & 127;
  int window_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001283_8313_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st_1 = {0};
  struct EventLog_R001283_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int damping_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_52_1 > 17)
  {
    acc_1 = ((acc_1 + (damping_52_1 * 2)) + 5) & 127;
    aux_1 ^= damping_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_52_2 > 17)
  {
    acc_2 = ((acc_2 + (damping_52_2 * 2)) + 5) & 127;
    aux_2 ^= damping_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_95_1) & 63;
  aux_2 = (aux_2 + cursor_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_93_1 = local_arr_1[aux_1 % 3];
  int checksum_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_93_2 * 2)) & 127;
  int sample_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_34_1)
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

  switch (sample_34_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_52_1 == damping_52_2);
  assert(cursor_95_1 == cursor_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_93_1 == checksum_93_2);
  assert(sample_34_1 == sample_34_2);
}

int fn_R001283_8313_10(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int damping_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_52 > 17)
  {
    acc = ((acc + (damping_52 * 2)) + 5) & 127;
    aux ^= damping_52 & 15;
  }
  else
  {
    acc = ((acc - damping_52) + 11) & 127;
    aux += 3;
  }
  int cursor_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_95) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_93 = local_arr[aux % 3];
  acc = (acc + (checksum_93 * 2)) & 127;
  int sample_34 = (aux + st.buffer[1]) & 3;
  switch (sample_34)
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

void fn_R001283_8313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st_1 = {0};
  struct SensorNode_R001283_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int cursor_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_98_1 > 41)
  {
    acc_1 = ((acc_1 + (cursor_98_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_98_2 > 41)
  {
    acc_2 = ((acc_2 + (cursor_98_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_32_1 = 0;
  int margin_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_32_1 = ((margin_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_32_2 = ((margin_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_32_1) & 127;
    acc_2 = (acc_2 + margin_32_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_98_1 == cursor_98_2);
  assert(margin_32_1 == margin_32_2);
}

int fn_R001283_8313_11(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int cursor_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_98 > 41)
  {
    acc = ((acc + (cursor_98 * 2)) + 5) & 127;
    aux ^= cursor_98 & 15;
  }
  else
  {
    acc = ((acc - cursor_98) + 11) & 127;
    aux += 3;
  }
  int margin_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_32 = ((margin_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_32) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001283_8313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st_1 = {0};
  struct EventLog_R001283_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int accumulator_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_80_1) & 63;
  aux_2 = (aux_2 + accumulator_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_47_1 = local_arr_1[aux_1 % 3];
  int quotient_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_47_2 * 2)) & 127;
  int stride_87_1 = 0;
  int stride_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_87_1 = ((stride_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_87_2 = ((stride_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_87_1) & 127;
    acc_2 = (acc_2 + stride_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_80_1 == accumulator_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_47_1 == quotient_47_2);
  assert(stride_87_1 == stride_87_2);
}

int fn_R001283_8313_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int accumulator_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_47 = local_arr[aux % 3];
  acc = (acc + (quotient_47 * 2)) & 127;
  int stride_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_87 = ((stride_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001283_8313_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st_1 = {0};
  struct Transaction_R001283_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int offset_76_1 = 0;
  int offset_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_76_1 = ((offset_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_76_2 = ((offset_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_76_1) & 127;
    acc_2 = (acc_2 + offset_76_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_85_1 = local_arr_1[aux_1 % 3];
  int tracker_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_85_2 * 2)) & 127;
  int accumulator_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_26_1) & 63;
  aux_2 = (aux_2 + accumulator_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_76_1 == offset_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_85_1 == tracker_85_2);
  assert(accumulator_26_1 == accumulator_26_2);
}

int fn_R001283_8313_13(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int offset_76 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_76 = ((offset_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_76) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_85 = local_arr[aux % 3];
  acc = (acc + (tracker_85 * 2)) & 127;
  int accumulator_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001283_8313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st_1 = {0};
  struct SensorNode_R001283_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_43_1 = 0;
  int checksum_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_43_1 = ((checksum_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_43_2 = ((checksum_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_43_1) & 127;
    acc_2 = (acc_2 + checksum_43_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_36_1 = local_arr_1[aux_1 % 3];
  int scale_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_36_2 * 2)) & 127;
  int anchor_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_36_1)
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

  switch (anchor_36_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_43_1 == checksum_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_36_1 == scale_36_2);
  assert(anchor_36_1 == anchor_36_2);
}

int fn_R001283_8313_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_43 = ((checksum_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_43) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_36 = local_arr[aux % 3];
  acc = (acc + (scale_36 * 2)) & 127;
  int anchor_36 = (aux + st.buffer[1]) & 3;
  switch (anchor_36)
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

void fn_R001283_8313_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st_1 = {0};
  struct Transaction_R001283_8313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int offset_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_91_1)
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

  switch (offset_91_2)
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

  int checksum_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_77_1 > 35)
  {
    acc_1 = ((acc_1 + (checksum_77_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_77_2 > 35)
  {
    acc_2 = ((acc_2 + (checksum_77_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_78_1 = 0;
  int damping_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_78_1 = ((damping_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_78_2 = ((damping_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_78_1) & 127;
    acc_2 = (acc_2 + damping_78_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_38_1 = local_arr_1[aux_1 % 3];
  int accumulator_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_91_1 == offset_91_2);
  assert(checksum_77_1 == checksum_77_2);
  assert(damping_78_1 == damping_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_38_1 == accumulator_38_2);
}

int fn_R001283_8313_15(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001283_8313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int offset_91 = (aux + st.buffer[1]) & 3;
  switch (offset_91)
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

  int checksum_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_77 > 35)
  {
    acc = ((acc + (checksum_77 * 2)) + 5) & 127;
    aux ^= checksum_77 & 15;
  }
  else
  {
    acc = ((acc - checksum_77) + 11) & 127;
    aux += 3;
  }
  int damping_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_78 = ((damping_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_78) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int accumulator_38 = local_arr[aux % 3];
  acc = (acc + (accumulator_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001283_8313_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st_1 = {0};
  struct EventLog_R001283_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int threshold_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_86_1 > 31)
  {
    acc_1 = ((acc_1 + (threshold_86_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_86_2 > 31)
  {
    acc_2 = ((acc_2 + (threshold_86_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_86_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_71_1 = local_arr_1[aux_1 % 3];
  int checksum_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_86_1 == threshold_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_71_1 == checksum_71_2);
}

int fn_R001283_8313_16(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int threshold_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_86 > 31)
  {
    acc = ((acc + (threshold_86 * 2)) + 5) & 127;
    aux ^= threshold_86 & 15;
  }
  else
  {
    acc = ((acc - threshold_86) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_71 = local_arr[aux % 3];
  acc = (acc + (checksum_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001283_8313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st_1 = {0};
  struct SensorNode_R001283_8313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int checksum_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_68_1) & 63;
  aux_2 = (aux_2 + checksum_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_37_1 = local_arr_1[aux_1 % 3];
  int bound_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_68_1 == checksum_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_37_1 == bound_37_2);
}

int fn_R001283_8313_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001283_8313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int checksum_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_68) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_37 = local_arr[aux % 3];
  acc = (acc + (bound_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001283_8313_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st_1 = {0};
  struct EventLog_R001283_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_84_1 = local_arr_1[aux_1 % 3];
  int offset_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_84_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_71_1) & 63;
  aux_2 = (aux_2 + accumulator_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_84_1 == offset_84_2);
  assert(accumulator_71_1 == accumulator_71_2);
}

int fn_R001283_8313_18(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int offset_84 = local_arr[aux % 3];
  acc = (acc + (offset_84 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001283_8313_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st_1 = {0};
  struct EventLog_R001283_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int anchor_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_71_1 > 49)
  {
    acc_1 = ((acc_1 + (anchor_71_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_71_2 > 49)
  {
    acc_2 = ((acc_2 + (anchor_71_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_86_1 = 0;
  int cursor_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_86_1 = ((cursor_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_86_2 = ((cursor_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_86_1) & 127;
    acc_2 = (acc_2 + cursor_86_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_74_1)
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

  switch (phase_74_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_71_1 == anchor_71_2);
  assert(cursor_86_1 == cursor_86_2);
  assert(phase_74_1 == phase_74_2);
}

int fn_R001283_8313_19(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int anchor_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_71 > 49)
  {
    acc = ((acc + (anchor_71 * 2)) + 5) & 127;
    aux ^= anchor_71 & 15;
  }
  else
  {
    acc = ((acc - anchor_71) + 11) & 127;
    aux += 3;
  }
  int cursor_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_86 = ((cursor_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_86) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_74 = (aux + st.buffer[1]) & 3;
  switch (phase_74)
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

void fn_R001283_8313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st_1 = {0};
  struct EventLog_R001283_8313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_12_1 = local_arr_1[aux_1 % 3];
  int vector_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_12_2 * 2)) & 127;
  int cursor_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_19_1 > 28)
  {
    acc_1 = ((acc_1 + (cursor_19_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_19_2 > 28)
  {
    acc_2 = ((acc_2 + (cursor_19_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_12_1 == vector_12_2);
  assert(cursor_19_1 == cursor_19_2);
}

int fn_R001283_8313_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001283_8313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int vector_12 = local_arr[aux % 3];
  acc = (acc + (vector_12 * 2)) & 127;
  int cursor_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_19 > 28)
  {
    acc = ((acc + (cursor_19 * 2)) + 5) & 127;
    aux ^= cursor_19 & 15;
  }
  else
  {
    acc = ((acc - cursor_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001283_0_1;
  int sec_r001283_0_2;
  int sec_r001283_1_1;
  int sec_r001283_1_2;
  int sec_r001283_2_1;
  int sec_r001283_2_2;
  int sec_r001283_3_1;
  int sec_r001283_3_2;
  int sec_r001283_4_1;
  int sec_r001283_4_2;
  int sec_r001283_5_1;
  int sec_r001283_5_2;
  int sec_r001283_6_1;
  int sec_r001283_6_2;
  int sec_r001283_7_1;
  int sec_r001283_7_2;
  int sec_r001283_8_1;
  int sec_r001283_8_2;
  int sec_r001283_9_1;
  int sec_r001283_9_2;
  int sec_r001283_10_1;
  int sec_r001283_10_2;
  int sec_r001283_11_1;
  int sec_r001283_11_2;
  int sec_r001283_12_1;
  int sec_r001283_12_2;
  int sec_r001283_13_1;
  int sec_r001283_13_2;
  int sec_r001283_14_1;
  int sec_r001283_14_2;
  int sec_r001283_15_1;
  int sec_r001283_15_2;
  int sec_r001283_16_1;
  int sec_r001283_16_2;
  int sec_r001283_17_1;
  int sec_r001283_17_2;
  int sec_r001283_18_1;
  int sec_r001283_18_2;
  int sec_r001283_19_1;
  int sec_r001283_19_2;
  int sec_r001283_20_1;
  int sec_r001283_20_2;
  int pub_r001283_0_1;
  int pub_r001283_0_2;
  int pub_r001283_1_1;
  int pub_r001283_1_2;
  int pub_r001283_2_1;
  int pub_r001283_2_2;
  int pub_r001283_3_1;
  int pub_r001283_3_2;
  int pub_r001283_4_1;
  int pub_r001283_4_2;
  int pub_r001283_5_1;
  int pub_r001283_5_2;
  int pub_r001283_6_1;
  int pub_r001283_6_2;
  int pub_r001283_7_1;
  int pub_r001283_7_2;
  int pub_r001283_8_1;
  int pub_r001283_8_2;
  int pub_r001283_9_1;
  int pub_r001283_9_2;
  int pub_r001283_10_1;
  int pub_r001283_10_2;
  int pub_r001283_11_1;
  int pub_r001283_11_2;
  int pub_r001283_12_1;
  int pub_r001283_12_2;
  int pub_r001283_13_1;
  int pub_r001283_13_2;
  int pub_r001283_14_1;
  int pub_r001283_14_2;
  int pub_r001283_15_1;
  int pub_r001283_15_2;
  int pub_r001283_16_1;
  int pub_r001283_16_2;
  int pub_r001283_17_1;
  int pub_r001283_17_2;
  int pub_r001283_18_1;
  int pub_r001283_18_2;
  int pub_r001283_19_1;
  int pub_r001283_19_2;
  int pub_r001283_20_1;
  int pub_r001283_20_2;
  int pub_r001283_21_1;
  int pub_r001283_21_2;
  int pub_r001283_22_1;
  int pub_r001283_22_2;
  int pub_r001283_23_1;
  int pub_r001283_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001283_0_1 >= (-100)) && (pub_r001283_0_1 <= 100));
  __CPROVER_assume((pub_r001283_0_2 >= (-100)) && (pub_r001283_0_2 <= 100));
  __CPROVER_assume((pub_r001283_1_1 >= (-100)) && (pub_r001283_1_1 <= 100));
  __CPROVER_assume((pub_r001283_1_2 >= (-100)) && (pub_r001283_1_2 <= 100));
  __CPROVER_assume((pub_r001283_2_1 >= (-100)) && (pub_r001283_2_1 <= 100));
  __CPROVER_assume((pub_r001283_2_2 >= (-100)) && (pub_r001283_2_2 <= 100));
  __CPROVER_assume((pub_r001283_3_1 >= (-100)) && (pub_r001283_3_1 <= 100));
  __CPROVER_assume((pub_r001283_3_2 >= (-100)) && (pub_r001283_3_2 <= 100));
  __CPROVER_assume((pub_r001283_4_1 >= (-100)) && (pub_r001283_4_1 <= 100));
  __CPROVER_assume((pub_r001283_4_2 >= (-100)) && (pub_r001283_4_2 <= 100));
  __CPROVER_assume((pub_r001283_5_1 >= (-100)) && (pub_r001283_5_1 <= 100));
  __CPROVER_assume((pub_r001283_5_2 >= (-100)) && (pub_r001283_5_2 <= 100));
  __CPROVER_assume((pub_r001283_6_1 >= (-100)) && (pub_r001283_6_1 <= 100));
  __CPROVER_assume((pub_r001283_6_2 >= (-100)) && (pub_r001283_6_2 <= 100));
  __CPROVER_assume((pub_r001283_7_1 >= (-100)) && (pub_r001283_7_1 <= 100));
  __CPROVER_assume((pub_r001283_7_2 >= (-100)) && (pub_r001283_7_2 <= 100));
  __CPROVER_assume((pub_r001283_8_1 >= (-100)) && (pub_r001283_8_1 <= 100));
  __CPROVER_assume((pub_r001283_8_2 >= (-100)) && (pub_r001283_8_2 <= 100));
  __CPROVER_assume((pub_r001283_9_1 >= (-100)) && (pub_r001283_9_1 <= 100));
  __CPROVER_assume((pub_r001283_9_2 >= (-100)) && (pub_r001283_9_2 <= 100));
  __CPROVER_assume((pub_r001283_10_1 >= (-100)) && (pub_r001283_10_1 <= 100));
  __CPROVER_assume((pub_r001283_10_2 >= (-100)) && (pub_r001283_10_2 <= 100));
  __CPROVER_assume((pub_r001283_11_1 >= (-100)) && (pub_r001283_11_1 <= 100));
  __CPROVER_assume((pub_r001283_11_2 >= (-100)) && (pub_r001283_11_2 <= 100));
  __CPROVER_assume((pub_r001283_12_1 >= (-100)) && (pub_r001283_12_1 <= 100));
  __CPROVER_assume((pub_r001283_12_2 >= (-100)) && (pub_r001283_12_2 <= 100));
  __CPROVER_assume((pub_r001283_13_1 >= (-100)) && (pub_r001283_13_1 <= 100));
  __CPROVER_assume((pub_r001283_13_2 >= (-100)) && (pub_r001283_13_2 <= 100));
  __CPROVER_assume((pub_r001283_14_1 >= (-100)) && (pub_r001283_14_1 <= 100));
  __CPROVER_assume((pub_r001283_14_2 >= (-100)) && (pub_r001283_14_2 <= 100));
  __CPROVER_assume((pub_r001283_15_1 >= (-100)) && (pub_r001283_15_1 <= 100));
  __CPROVER_assume((pub_r001283_15_2 >= (-100)) && (pub_r001283_15_2 <= 100));
  __CPROVER_assume((pub_r001283_16_1 >= (-100)) && (pub_r001283_16_1 <= 100));
  __CPROVER_assume((pub_r001283_16_2 >= (-100)) && (pub_r001283_16_2 <= 100));
  __CPROVER_assume((pub_r001283_17_1 >= (-100)) && (pub_r001283_17_1 <= 100));
  __CPROVER_assume((pub_r001283_17_2 >= (-100)) && (pub_r001283_17_2 <= 100));
  __CPROVER_assume((pub_r001283_18_1 >= (-100)) && (pub_r001283_18_1 <= 100));
  __CPROVER_assume((pub_r001283_18_2 >= (-100)) && (pub_r001283_18_2 <= 100));
  __CPROVER_assume((pub_r001283_19_1 >= (-100)) && (pub_r001283_19_1 <= 100));
  __CPROVER_assume((pub_r001283_19_2 >= (-100)) && (pub_r001283_19_2 <= 100));
  __CPROVER_assume((pub_r001283_20_1 >= (-100)) && (pub_r001283_20_1 <= 100));
  __CPROVER_assume((pub_r001283_20_2 >= (-100)) && (pub_r001283_20_2 <= 100));
  __CPROVER_assume((pub_r001283_21_1 >= (-100)) && (pub_r001283_21_1 <= 100));
  __CPROVER_assume((pub_r001283_21_2 >= (-100)) && (pub_r001283_21_2 <= 100));
  __CPROVER_assume((pub_r001283_22_1 >= (-100)) && (pub_r001283_22_1 <= 100));
  __CPROVER_assume((pub_r001283_22_2 >= (-100)) && (pub_r001283_22_2 <= 100));
  __CPROVER_assume((pub_r001283_23_1 >= (-100)) && (pub_r001283_23_1 <= 100));
  __CPROVER_assume((pub_r001283_23_2 >= (-100)) && (pub_r001283_23_2 <= 100));
  __CPROVER_assume((sec_r001283_0_1 >= 0) && (sec_r001283_0_1 <= 255));
  __CPROVER_assume((sec_r001283_0_2 >= 0) && (sec_r001283_0_2 <= 255));
  __CPROVER_assume((sec_r001283_1_1 >= 0) && (sec_r001283_1_1 <= 255));
  __CPROVER_assume((sec_r001283_1_2 >= 0) && (sec_r001283_1_2 <= 255));
  __CPROVER_assume((sec_r001283_2_1 >= 0) && (sec_r001283_2_1 <= 255));
  __CPROVER_assume((sec_r001283_2_2 >= 0) && (sec_r001283_2_2 <= 255));
  __CPROVER_assume((sec_r001283_3_1 >= 0) && (sec_r001283_3_1 <= 255));
  __CPROVER_assume((sec_r001283_3_2 >= 0) && (sec_r001283_3_2 <= 255));
  __CPROVER_assume((sec_r001283_4_1 >= 0) && (sec_r001283_4_1 <= 255));
  __CPROVER_assume((sec_r001283_4_2 >= 0) && (sec_r001283_4_2 <= 255));
  __CPROVER_assume((sec_r001283_5_1 >= 0) && (sec_r001283_5_1 <= 255));
  __CPROVER_assume((sec_r001283_5_2 >= 0) && (sec_r001283_5_2 <= 255));
  __CPROVER_assume((sec_r001283_6_1 >= 0) && (sec_r001283_6_1 <= 255));
  __CPROVER_assume((sec_r001283_6_2 >= 0) && (sec_r001283_6_2 <= 255));
  __CPROVER_assume((sec_r001283_7_1 >= 0) && (sec_r001283_7_1 <= 255));
  __CPROVER_assume((sec_r001283_7_2 >= 0) && (sec_r001283_7_2 <= 255));
  __CPROVER_assume((sec_r001283_8_1 >= 0) && (sec_r001283_8_1 <= 255));
  __CPROVER_assume((sec_r001283_8_2 >= 0) && (sec_r001283_8_2 <= 255));
  __CPROVER_assume((sec_r001283_9_1 >= 0) && (sec_r001283_9_1 <= 255));
  __CPROVER_assume((sec_r001283_9_2 >= 0) && (sec_r001283_9_2 <= 255));
  __CPROVER_assume((sec_r001283_10_1 >= 0) && (sec_r001283_10_1 <= 255));
  __CPROVER_assume((sec_r001283_10_2 >= 0) && (sec_r001283_10_2 <= 255));
  __CPROVER_assume((sec_r001283_11_1 >= 0) && (sec_r001283_11_1 <= 255));
  __CPROVER_assume((sec_r001283_11_2 >= 0) && (sec_r001283_11_2 <= 255));
  __CPROVER_assume((sec_r001283_12_1 >= 0) && (sec_r001283_12_1 <= 255));
  __CPROVER_assume((sec_r001283_12_2 >= 0) && (sec_r001283_12_2 <= 255));
  __CPROVER_assume((sec_r001283_13_1 >= 0) && (sec_r001283_13_1 <= 255));
  __CPROVER_assume((sec_r001283_13_2 >= 0) && (sec_r001283_13_2 <= 255));
  __CPROVER_assume((sec_r001283_14_1 >= 0) && (sec_r001283_14_1 <= 255));
  __CPROVER_assume((sec_r001283_14_2 >= 0) && (sec_r001283_14_2 <= 255));
  __CPROVER_assume((sec_r001283_15_1 >= 0) && (sec_r001283_15_1 <= 255));
  __CPROVER_assume((sec_r001283_15_2 >= 0) && (sec_r001283_15_2 <= 255));
  __CPROVER_assume((sec_r001283_16_1 >= 0) && (sec_r001283_16_1 <= 255));
  __CPROVER_assume((sec_r001283_16_2 >= 0) && (sec_r001283_16_2 <= 255));
  __CPROVER_assume((sec_r001283_17_1 >= 0) && (sec_r001283_17_1 <= 255));
  __CPROVER_assume((sec_r001283_17_2 >= 0) && (sec_r001283_17_2 <= 255));
  __CPROVER_assume((sec_r001283_18_1 >= 0) && (sec_r001283_18_1 <= 255));
  __CPROVER_assume((sec_r001283_18_2 >= 0) && (sec_r001283_18_2 <= 255));
  __CPROVER_assume((sec_r001283_19_1 >= 0) && (sec_r001283_19_1 <= 255));
  __CPROVER_assume((sec_r001283_19_2 >= 0) && (sec_r001283_19_2 <= 255));
  __CPROVER_assume((sec_r001283_20_1 >= 0) && (sec_r001283_20_1 <= 255));
  __CPROVER_assume((sec_r001283_20_2 >= 0) && (sec_r001283_20_2 <= 255));
  struct SensorNode_R001283_8313_0 st_var_0_1 = {0};
  struct SensorNode_R001283_8313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001283_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001283_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001283_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001283_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001283_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001283_0_2 + 7) & 15;
  struct Transaction_R001283_8313_1 st_var_1_1 = {0};
  struct Transaction_R001283_8313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001283_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001283_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001283_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001283_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001283_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001283_0_2 + 9) & 15;
  struct EventLog_R001283_8313_2 st_var_2_1 = {0};
  struct EventLog_R001283_8313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001283_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001283_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001283_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001283_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001283_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001283_0_2 + 11) & 15;
  union ColorPixel_R001283_8313_0 u_var_1;
  union ColorPixel_R001283_8313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001283_8313_0(sec_r001283_0_1, sec_r001283_1_1, pub_r001283_2_1, pub_r001283_3_1, pub_r001283_4_1);
  int helper_flow_0_2 = fn_R001283_8313_0(sec_r001283_0_2, sec_r001283_1_2, pub_r001283_2_2, pub_r001283_3_2, pub_r001283_4_2);
  fn_R001283_8313_0_2(sec_r001283_0_1, sec_r001283_1_1, pub_r001283_2_1, pub_r001283_3_1, pub_r001283_4_1, sec_r001283_0_2, sec_r001283_1_2, pub_r001283_2_2, pub_r001283_3_2, pub_r001283_4_2);
  int helper_flow_1_1 = fn_R001283_8313_1(sec_r001283_1_1, sec_r001283_2_1, pub_r001283_3_1, pub_r001283_4_1, pub_r001283_5_1);
  int helper_flow_1_2 = fn_R001283_8313_1(sec_r001283_1_2, sec_r001283_2_2, pub_r001283_3_2, pub_r001283_4_2, pub_r001283_5_2);
  fn_R001283_8313_1_2(sec_r001283_1_1, sec_r001283_2_1, pub_r001283_3_1, pub_r001283_4_1, pub_r001283_5_1, sec_r001283_1_2, sec_r001283_2_2, pub_r001283_3_2, pub_r001283_4_2, pub_r001283_5_2);
  int helper_flow_2_1 = fn_R001283_8313_2(sec_r001283_2_1, sec_r001283_3_1, pub_r001283_4_1);
  int helper_flow_2_2 = fn_R001283_8313_2(sec_r001283_2_2, sec_r001283_3_2, pub_r001283_4_2);
  fn_R001283_8313_2_2(sec_r001283_2_1, sec_r001283_3_1, pub_r001283_4_1, sec_r001283_2_2, sec_r001283_3_2, pub_r001283_4_2);
  int helper_flow_3_1 = fn_R001283_8313_3(sec_r001283_3_1, sec_r001283_4_1, pub_r001283_5_1);
  int helper_flow_3_2 = fn_R001283_8313_3(sec_r001283_3_2, sec_r001283_4_2, pub_r001283_5_2);
  fn_R001283_8313_3_2(sec_r001283_3_1, sec_r001283_4_1, pub_r001283_5_1, sec_r001283_3_2, sec_r001283_4_2, pub_r001283_5_2);
  int helper_flow_4_1 = fn_R001283_8313_4(sec_r001283_4_1, pub_r001283_5_1, pub_r001283_6_1, pub_r001283_7_1);
  int helper_flow_4_2 = fn_R001283_8313_4(sec_r001283_4_2, pub_r001283_5_2, pub_r001283_6_2, pub_r001283_7_2);
  fn_R001283_8313_4_2(sec_r001283_4_1, pub_r001283_5_1, pub_r001283_6_1, pub_r001283_7_1, sec_r001283_4_2, pub_r001283_5_2, pub_r001283_6_2, pub_r001283_7_2);
  int helper_flow_5_1 = fn_R001283_8313_5(sec_r001283_5_1, sec_r001283_6_1);
  int helper_flow_5_2 = fn_R001283_8313_5(sec_r001283_5_2, sec_r001283_6_2);
  fn_R001283_8313_5_2(sec_r001283_5_1, sec_r001283_6_1, sec_r001283_5_2, sec_r001283_6_2);
  int stage_v_0_1 = ((pub_r001283_22_1 * 2) + 50) & 63;
  int stage_v_0_2 = ((pub_r001283_22_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001283_18_1 * 3) + pub_r001283_6_1) + 23) & 127;
  int stage_v_1_2 = (((sec_r001283_18_2 * 3) + pub_r001283_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001283_11_1 * 2) + 26) & 63;
  int stage_v_2_2 = ((pub_r001283_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001283_0_1 * 2) + 10) & 63;
  int stage_v_3_2 = ((pub_r001283_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001283_12_1 * 2) + 30) & 63;
  int stage_v_4_2 = ((pub_r001283_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001283_5_1 * 2) + 50) & 63;
  int stage_v_5_2 = ((pub_r001283_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((sec_r001283_11_1 * 3) + pub_r001283_23_1) + 32) & 127;
  int stage_v_6_2 = (((sec_r001283_11_2 * 3) + pub_r001283_23_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((sec_r001283_9_1 * 3) + pub_r001283_23_1) + 33) & 127;
  int stage_v_7_2 = (((sec_r001283_9_2 * 3) + pub_r001283_23_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = (((sec_r001283_14_1 * 3) + pub_r001283_10_1) + 12) & 127;
  int stage_v_8_2 = (((sec_r001283_14_2 * 3) + pub_r001283_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((sec_r001283_9_1 * 3) + pub_r001283_19_1) + 8) & 127;
  int stage_v_9_2 = (((sec_r001283_9_2 * 3) + pub_r001283_19_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = ((pub_r001283_5_1 * 2) + 25) & 63;
  int stage_v_10_2 = ((pub_r001283_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001283_20_1 * 2) + 22) & 63;
  int stage_v_11_2 = ((pub_r001283_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001283_9_1 * 2) + 41) & 63;
  int stage_v_12_2 = ((pub_r001283_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001283_16_1 * 2) + 7) & 63;
  int stage_v_13_2 = ((pub_r001283_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001283_23_1 * 2) + 27) & 63;
  int stage_v_14_2 = ((pub_r001283_23_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001283_22_1 * 2) + 15) & 63;
  int stage_v_15_2 = ((pub_r001283_22_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001283_9_1 * 2) + 6) & 63;
  int stage_v_16_2 = ((pub_r001283_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((sec_r001283_2_1 * 3) + pub_r001283_7_1) + 23) & 127;
  int stage_v_17_2 = (((sec_r001283_2_2 * 3) + pub_r001283_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((helper_flow_4_1 * 3) + pub_r001283_22_1) + 21) & 127;
  int stage_v_18_2 = (((helper_flow_4_2 * 3) + pub_r001283_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001283_19_1 * 2) + 35) & 63;
  int stage_v_19_2 = ((pub_r001283_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001283_22_1 * 2) + 38) & 63;
  int stage_v_20_2 = ((pub_r001283_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001283_20_1 * 2) + 39) & 63;
  int stage_v_21_2 = ((pub_r001283_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001283_18_1 * 2) + 30) & 63;
  int stage_v_22_2 = ((pub_r001283_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001283_3_1 * 3) + pub_r001283_3_1) + 36) & 127;
  int stage_v_23_2 = (((sec_r001283_3_2 * 3) + pub_r001283_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001283_10_1 * 3) + pub_r001283_20_1) + 42) & 127;
  int stage_v_24_2 = (((sec_r001283_10_2 * 3) + pub_r001283_20_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001283_11_1 * 3) + pub_r001283_19_1) + 9) & 127;
  int stage_v_25_2 = (((sec_r001283_11_2 * 3) + pub_r001283_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = ((pub_r001283_8_1 * 2) + 43) & 63;
  int stage_v_26_2 = ((pub_r001283_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001283_8_1 * 2) + 38) & 63;
  int stage_v_27_2 = ((pub_r001283_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001283_20_1 * 2) + 29) & 63;
  int stage_v_28_2 = ((pub_r001283_20_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001283_19_1 * 2) + 11) & 63;
  int stage_v_29_2 = ((pub_r001283_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001283_10_1 * 3) + pub_r001283_17_1) + 21) & 127;
  int stage_v_30_2 = (((sec_r001283_10_2 * 3) + pub_r001283_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001283_18_1 * 2) + 32) & 63;
  int stage_v_31_2 = ((pub_r001283_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001283_10_1 * 2) + 49) & 63;
  int stage_v_32_2 = ((pub_r001283_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((helper_flow_0_1 * 3) + pub_r001283_15_1) + 10) & 127;
  int stage_v_33_2 = (((helper_flow_0_2 * 3) + pub_r001283_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((stage_v_8_1 * 3) + pub_r001283_16_1) + 36) & 127;
  int stage_v_34_2 = (((stage_v_8_2 * 3) + pub_r001283_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((sec_r001283_4_1 * 3) + pub_r001283_12_1) + 30) & 127;
  int stage_v_35_2 = (((sec_r001283_4_2 * 3) + pub_r001283_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((sec_r001283_2_1 * 3) + pub_r001283_17_1) + 11) & 127;
  int stage_v_36_2 = (((sec_r001283_2_2 * 3) + pub_r001283_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((stage_v_33_1 * 3) + pub_r001283_10_1) + 36) & 127;
  int stage_v_37_2 = (((stage_v_33_2 * 3) + pub_r001283_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001283_1_1 * 2) + 48) & 63;
  int stage_v_38_2 = ((pub_r001283_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001283_21_1 * 2) + 22) & 63;
  int stage_v_39_2 = ((pub_r001283_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((sec_r001283_10_1 * 3) + pub_r001283_19_1) + 11) & 127;
  int stage_v_40_2 = (((sec_r001283_10_2 * 3) + pub_r001283_19_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((stage_v_34_1 * 3) + pub_r001283_20_1) + 8) & 127;
  int stage_v_41_2 = (((stage_v_34_2 * 3) + pub_r001283_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001283_18_1 * 2) + 20) & 63;
  int stage_v_42_2 = ((pub_r001283_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_40_1 * 3) + pub_r001283_10_1) + 43) & 127;
  int stage_v_43_2 = (((stage_v_40_2 * 3) + pub_r001283_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001283_4_1 * 2) + 46) & 63;
  int stage_v_44_2 = ((pub_r001283_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001283_19_1 * 2) + 35) & 63;
  int stage_v_45_2 = ((pub_r001283_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((sec_r001283_18_1 * 3) + pub_r001283_17_1) + 22) & 127;
  int stage_v_46_2 = (((sec_r001283_18_2 * 3) + pub_r001283_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001283_3_1 * 2) + 16) & 63;
  int stage_v_47_2 = ((pub_r001283_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001283_11_1 * 2) + 42) & 63;
  int stage_v_48_2 = ((pub_r001283_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001283_18_1 * 2) + 44) & 63;
  int stage_v_49_2 = ((pub_r001283_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((helper_flow_0_1 * 3) + pub_r001283_19_1) + 14) & 127;
  int stage_v_50_2 = (((helper_flow_0_2 * 3) + pub_r001283_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001283_4_1 * 2) + 27) & 63;
  int stage_v_51_2 = ((pub_r001283_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001283_3_1 * 2) + 28) & 63;
  int stage_v_52_2 = ((pub_r001283_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((stage_v_43_1 * 3) + pub_r001283_7_1) + 21) & 127;
  int stage_v_53_2 = (((stage_v_43_2 * 3) + pub_r001283_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((sec_r001283_13_1 * 3) + pub_r001283_18_1) + 45) & 127;
  int stage_v_54_2 = (((sec_r001283_13_2 * 3) + pub_r001283_18_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = ((pub_r001283_9_1 * 2) + 50) & 63;
  int stage_v_55_2 = ((pub_r001283_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001283_7_1 * 2) + 18) & 63;
  int stage_v_56_2 = ((pub_r001283_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((stage_v_37_1 * 3) + pub_r001283_23_1) + 11) & 127;
  int stage_v_57_2 = (((stage_v_37_2 * 3) + pub_r001283_23_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((stage_v_40_1 * 3) + pub_r001283_6_1) + 21) & 127;
  int stage_v_58_2 = (((stage_v_40_2 * 3) + pub_r001283_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001283_22_1 * 2) + 19) & 63;
  int stage_v_59_2 = ((pub_r001283_22_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((helper_flow_4_1 * 3) + pub_r001283_22_1) + 18) & 127;
  int stage_v_60_2 = (((helper_flow_4_2 * 3) + pub_r001283_22_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = ((pub_r001283_5_1 * 2) + 7) & 63;
  int stage_v_61_2 = ((pub_r001283_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001283_9_1 * 2) + 9) & 63;
  int stage_v_62_2 = ((pub_r001283_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001283_10_1 * 2) + 6) & 63;
  int stage_v_63_2 = ((pub_r001283_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((sec_r001283_4_1 * 3) + pub_r001283_17_1) + 21) & 127;
  int stage_v_64_2 = (((sec_r001283_4_2 * 3) + pub_r001283_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001283_10_1 * 2) + 33) & 63;
  int stage_v_65_2 = ((pub_r001283_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001283_21_1 * 2) + 24) & 63;
  int stage_v_66_2 = ((pub_r001283_21_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((stage_v_23_1 * 3) + pub_r001283_22_1) + 37) & 127;
  int stage_v_67_2 = (((stage_v_23_2 * 3) + pub_r001283_22_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001283_11_1 * 2) + 28) & 63;
  int stage_v_68_2 = ((pub_r001283_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((stage_v_57_1 * 3) + pub_r001283_14_1) + 5) & 127;
  int stage_v_69_2 = (((stage_v_57_2 * 3) + pub_r001283_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((helper_flow_1_1 * 3) + pub_r001283_9_1) + 41) & 127;
  int stage_v_70_2 = (((helper_flow_1_2 * 3) + pub_r001283_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((sec_r001283_2_1 * 3) + pub_r001283_13_1) + 15) & 127;
  int stage_v_71_2 = (((sec_r001283_2_2 * 3) + pub_r001283_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((stage_v_57_1 * 3) + pub_r001283_18_1) + 11) & 127;
  int stage_v_72_2 = (((stage_v_57_2 * 3) + pub_r001283_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((stage_v_41_1 * 3) + pub_r001283_3_1) + 24) & 127;
  int stage_v_73_2 = (((stage_v_41_2 * 3) + pub_r001283_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((stage_v_41_1 * 3) + pub_r001283_8_1) + 13) & 127;
  int stage_v_74_2 = (((stage_v_41_2 * 3) + pub_r001283_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_58_1 * 3) + pub_r001283_20_1) + 18) & 127;
  int stage_v_75_2 = (((stage_v_58_2 * 3) + pub_r001283_20_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001283_8_1 * 2) + 24) & 63;
  int stage_v_76_2 = ((pub_r001283_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_74_1 * 3) + pub_r001283_10_1) + 24) & 127;
  int stage_v_77_2 = (((stage_v_74_2 * 3) + pub_r001283_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001283_6_1 * 2) + 30) & 63;
  int stage_v_78_2 = ((pub_r001283_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001283_3_1 * 2) + 13) & 63;
  int stage_v_79_2 = ((pub_r001283_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((helper_flow_5_1 * 3) + pub_r001283_23_1) + 3) & 127;
  int stage_v_80_2 = (((helper_flow_5_2 * 3) + pub_r001283_23_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((stage_v_23_1 * 3) + pub_r001283_5_1) + 18) & 127;
  int stage_v_81_2 = (((stage_v_23_2 * 3) + pub_r001283_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_69_1 * 3) + pub_r001283_13_1) + 17) & 127;
  int stage_v_82_2 = (((stage_v_69_2 * 3) + pub_r001283_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = (((stage_v_81_1 * 3) + pub_r001283_11_1) + 4) & 127;
  int stage_v_83_2 = (((stage_v_81_2 * 3) + pub_r001283_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((stage_v_40_1 * 3) + pub_r001283_8_1) + 25) & 127;
  int stage_v_84_2 = (((stage_v_40_2 * 3) + pub_r001283_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_80_1 * 3) + pub_r001283_15_1) + 38) & 127;
  int stage_v_85_2 = (((stage_v_80_2 * 3) + pub_r001283_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001283_8_1 * 2) + 17) & 63;
  int stage_v_86_2 = ((pub_r001283_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_1_1 * 3) + pub_r001283_1_1) + 26) & 127;
  int stage_v_87_2 = (((stage_v_1_2 * 3) + pub_r001283_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001283_23_1 * 2) + 9) & 63;
  int stage_v_88_2 = ((pub_r001283_23_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001283_12_1 * 2) + 10) & 63;
  int stage_v_89_2 = ((pub_r001283_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((sec_r001283_5_1 * 3) + pub_r001283_12_1) + 26) & 127;
  int stage_v_90_2 = (((sec_r001283_5_2 * 3) + pub_r001283_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_53_1 * 3) + pub_r001283_13_1) + 41) & 127;
  int stage_v_91_2 = (((stage_v_53_2 * 3) + pub_r001283_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((stage_v_36_1 * 3) + pub_r001283_4_1) + 10) & 127;
  int stage_v_92_2 = (((stage_v_36_2 * 3) + pub_r001283_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((stage_v_70_1 * 3) + pub_r001283_0_1) + 44) & 127;
  int stage_v_93_2 = (((stage_v_70_2 * 3) + pub_r001283_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((stage_v_53_1 * 3) + pub_r001283_15_1) + 9) & 127;
  int stage_v_94_2 = (((stage_v_53_2 * 3) + pub_r001283_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((sec_r001283_13_1 * 3) + pub_r001283_18_1) + 20) & 127;
  int stage_v_95_2 = (((sec_r001283_13_2 * 3) + pub_r001283_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((sec_r001283_18_1 * 3) + pub_r001283_19_1) + 9) & 127;
  int stage_v_96_2 = (((sec_r001283_18_2 * 3) + pub_r001283_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = (((sec_r001283_10_1 * 3) + pub_r001283_10_1) + 22) & 127;
  int stage_v_97_2 = (((sec_r001283_10_2 * 3) + pub_r001283_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((stage_v_84_1 * 3) + pub_r001283_20_1) + 13) & 127;
  int stage_v_98_2 = (((stage_v_84_2 * 3) + pub_r001283_20_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001283_0_1 * 2) + 42) & 63;
  int stage_v_99_2 = ((pub_r001283_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001283_23_1 * 2) + 40) & 63;
  int stage_v_100_2 = ((pub_r001283_23_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_40_1 * 3) + pub_r001283_7_1) + 15) & 127;
  int stage_v_101_2 = (((stage_v_40_2 * 3) + pub_r001283_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001283_14_1 * 2) + 18) & 63;
  int stage_v_102_2 = ((pub_r001283_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001283_18_1 * 2) + 38) & 63;
  int stage_v_103_2 = ((pub_r001283_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_74_1 * 3) + pub_r001283_3_1) + 4) & 127;
  int stage_v_104_2 = (((stage_v_74_2 * 3) + pub_r001283_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((stage_v_23_1 * 3) + pub_r001283_11_1) + 14) & 127;
  int stage_v_105_2 = (((stage_v_23_2 * 3) + pub_r001283_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((sec_r001283_4_1 * 3) + pub_r001283_11_1) + 12) & 127;
  int stage_v_106_2 = (((sec_r001283_4_2 * 3) + pub_r001283_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001283_8_1 * 2) + 37) & 63;
  int stage_v_107_2 = ((pub_r001283_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001283_2_1 * 2) + 46) & 63;
  int stage_v_108_2 = ((pub_r001283_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001283_12_1 * 2) + 39) & 63;
  int stage_v_109_2 = ((pub_r001283_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_101_1 * 3) + pub_r001283_15_1) + 14) & 127;
  int stage_v_110_2 = (((stage_v_101_2 * 3) + pub_r001283_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((sec_r001283_16_1 * 3) + pub_r001283_6_1) + 30) & 127;
  int stage_v_111_2 = (((sec_r001283_16_2 * 3) + pub_r001283_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = (((sec_r001283_14_1 * 3) + pub_r001283_12_1) + 29) & 127;
  int stage_v_112_2 = (((sec_r001283_14_2 * 3) + pub_r001283_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((stage_v_46_1 * 3) + pub_r001283_6_1) + 28) & 127;
  int stage_v_113_2 = (((stage_v_46_2 * 3) + pub_r001283_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001283_2_1 * 2) + 6) & 63;
  int stage_v_114_2 = ((pub_r001283_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001283_20_1 * 2) + 15) & 63;
  int stage_v_115_2 = ((pub_r001283_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_93_1 * 3) + pub_r001283_17_1) + 21) & 127;
  int stage_v_116_2 = (((stage_v_93_2 * 3) + pub_r001283_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = (((stage_v_70_1 * 3) + pub_r001283_16_1) + 33) & 127;
  int stage_v_117_2 = (((stage_v_70_2 * 3) + pub_r001283_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = ((pub_r001283_20_1 * 2) + 38) & 63;
  int stage_v_118_2 = ((pub_r001283_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_105_1 * 3) + pub_r001283_9_1) + 41) & 127;
  int stage_v_119_2 = (((stage_v_105_2 * 3) + pub_r001283_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((stage_v_67_1 * 3) + pub_r001283_16_1) + 28) & 127;
  int stage_v_120_2 = (((stage_v_67_2 * 3) + pub_r001283_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001283_22_1 * 2) + 17) & 63;
  int stage_v_121_2 = ((pub_r001283_22_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001283_0_1 * 2) + 18) & 63;
  int stage_v_122_2 = ((pub_r001283_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001283_4_1 * 2) + 50) & 63;
  int stage_v_123_2 = ((pub_r001283_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001283_23_1 * 2) + 5) & 63;
  int stage_v_124_2 = ((pub_r001283_23_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001283_11_1 * 2) + 21) & 63;
  int stage_v_125_2 = ((pub_r001283_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001283_7_1 * 2) + 37) & 63;
  int stage_v_126_2 = ((pub_r001283_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001283_1_1 * 2) + 11) & 63;
  int stage_v_127_2 = ((pub_r001283_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001283_8_1 * 2) + 16) & 63;
  int stage_v_128_2 = ((pub_r001283_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((helper_flow_1_1 * 3) + pub_r001283_16_1) + 6) & 127;
  int stage_v_129_2 = (((helper_flow_1_2 * 3) + pub_r001283_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001283_21_1 * 2) + 24) & 63;
  int stage_v_130_2 = ((pub_r001283_21_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((sec_r001283_10_1 * 3) + pub_r001283_15_1) + 42) & 127;
  int stage_v_131_2 = (((sec_r001283_10_2 * 3) + pub_r001283_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = (((sec_r001283_4_1 * 3) + pub_r001283_18_1) + 29) & 127;
  int stage_v_132_2 = (((sec_r001283_4_2 * 3) + pub_r001283_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_81_1 * 3) + pub_r001283_6_1) + 27) & 127;
  int stage_v_133_2 = (((stage_v_81_2 * 3) + pub_r001283_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001283_20_1 * 2) + 50) & 63;
  int stage_v_134_2 = ((pub_r001283_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((sec_r001283_2_1 * 3) + pub_r001283_14_1) + 21) & 127;
  int stage_v_135_2 = (((sec_r001283_2_2 * 3) + pub_r001283_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001283_6_1 * 2) + 27) & 63;
  int stage_v_136_2 = ((pub_r001283_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((stage_v_37_1 * 3) + pub_r001283_17_1) + 23) & 127;
  int stage_v_137_2 = (((stage_v_37_2 * 3) + pub_r001283_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((stage_v_82_1 * 3) + pub_r001283_7_1) + 17) & 127;
  int stage_v_138_2 = (((stage_v_82_2 * 3) + pub_r001283_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001283_2_1 * 2) + 26) & 63;
  int stage_v_139_2 = ((pub_r001283_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001283_16_1 * 2) + 44) & 63;
  int stage_v_140_2 = ((pub_r001283_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001283_7_1 * 2) + 22) & 63;
  int stage_v_141_2 = ((pub_r001283_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_85_1 * 3) + pub_r001283_1_1) + 41) & 127;
  int stage_v_142_2 = (((stage_v_85_2 * 3) + pub_r001283_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_35_1 * 3) + pub_r001283_15_1) + 37) & 127;
  int stage_v_143_2 = (((stage_v_35_2 * 3) + pub_r001283_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001283_9_1 * 2) + 39) & 63;
  int stage_v_144_2 = ((pub_r001283_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_30_1 * 3) + pub_r001283_6_1) + 27) & 127;
  int stage_v_145_2 = (((stage_v_30_2 * 3) + pub_r001283_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001283_10_1 * 2) + 38) & 63;
  int stage_v_146_2 = ((pub_r001283_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((sec_r001283_15_1 * 3) + pub_r001283_22_1) + 45) & 127;
  int stage_v_147_2 = (((sec_r001283_15_2 * 3) + pub_r001283_22_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = (((stage_v_60_1 * 3) + pub_r001283_1_1) + 39) & 127;
  int stage_v_148_2 = (((stage_v_60_2 * 3) + pub_r001283_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((sec_r001283_1_1 * 3) + pub_r001283_15_1) + 31) & 127;
  int stage_v_149_2 = (((sec_r001283_1_2 * 3) + pub_r001283_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001283_9_1 * 2) + 20) & 63;
  int stage_v_150_2 = ((pub_r001283_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001283_18_1 * 2) + 24) & 63;
  int stage_v_151_2 = ((pub_r001283_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001283_3_1 * 2) + 26) & 63;
  int stage_v_152_2 = ((pub_r001283_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_142_1 * 3) + pub_r001283_16_1) + 37) & 127;
  int stage_v_153_2 = (((stage_v_142_2 * 3) + pub_r001283_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((sec_r001283_4_1 * 3) + pub_r001283_10_1) + 18) & 127;
  int stage_v_154_2 = (((sec_r001283_4_2 * 3) + pub_r001283_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((stage_v_101_1 * 3) + pub_r001283_3_1) + 35) & 127;
  int stage_v_155_2 = (((stage_v_101_2 * 3) + pub_r001283_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_69_1 * 3) + pub_r001283_14_1) + 15) & 127;
  int stage_v_156_2 = (((stage_v_69_2 * 3) + pub_r001283_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((sec_r001283_10_1 * 3) + pub_r001283_10_1) + 11) & 127;
  int stage_v_157_2 = (((sec_r001283_10_2 * 3) + pub_r001283_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((sec_r001283_17_1 * 3) + pub_r001283_23_1) + 31) & 127;
  int stage_v_158_2 = (((sec_r001283_17_2 * 3) + pub_r001283_23_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_70_1 * 3) + pub_r001283_0_1) + 20) & 127;
  int stage_v_159_2 = (((stage_v_70_2 * 3) + pub_r001283_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((sec_r001283_19_1 * 3) + pub_r001283_2_1) + 37) & 127;
  int stage_v_160_2 = (((sec_r001283_19_2 * 3) + pub_r001283_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_117_1 * 3) + pub_r001283_10_1) + 22) & 127;
  int stage_v_161_2 = (((stage_v_117_2 * 3) + pub_r001283_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001283_4_1 * 2) + 32) & 63;
  int stage_v_162_2 = ((pub_r001283_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_18_1 * 3) + pub_r001283_19_1) + 9) & 127;
  int stage_v_163_2 = (((stage_v_18_2 * 3) + pub_r001283_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = ((pub_r001283_4_1 * 2) + 44) & 63;
  int stage_v_164_2 = ((pub_r001283_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_159_1 * 3) + pub_r001283_5_1) + 4) & 127;
  int stage_v_165_2 = (((stage_v_159_2 * 3) + pub_r001283_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001283_5_1 * 2) + 33) & 63;
  int stage_v_166_2 = ((pub_r001283_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((sec_r001283_9_1 * 3) + pub_r001283_9_1) + 12) & 127;
  int stage_v_167_2 = (((sec_r001283_9_2 * 3) + pub_r001283_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((sec_r001283_14_1 * 3) + pub_r001283_14_1) + 35) & 127;
  int stage_v_168_2 = (((sec_r001283_14_2 * 3) + pub_r001283_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001283_8_1 * 2) + 44) & 63;
  int stage_v_169_2 = ((pub_r001283_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_142_1 * 3) + pub_r001283_4_1) + 42) & 127;
  int stage_v_170_2 = (((stage_v_142_2 * 3) + pub_r001283_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((stage_v_71_1 * 3) + pub_r001283_17_1) + 20) & 127;
  int stage_v_171_2 = (((stage_v_71_2 * 3) + pub_r001283_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_145_1 * 3) + pub_r001283_8_1) + 26) & 127;
  int stage_v_172_2 = (((stage_v_145_2 * 3) + pub_r001283_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001283_0_1 * 2) + 8) & 63;
  int stage_v_173_2 = ((pub_r001283_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001283_9_1 * 2) + 33) & 63;
  int stage_v_174_2 = ((pub_r001283_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001283_9_1 * 2) + 44) & 63;
  int stage_v_175_2 = ((pub_r001283_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((sec_r001283_15_1 * 3) + pub_r001283_0_1) + 10) & 127;
  int stage_v_176_2 = (((sec_r001283_15_2 * 3) + pub_r001283_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001283_11_1 * 2) + 22) & 63;
  int stage_v_177_2 = ((pub_r001283_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001283_17_1 * 2) + 19) & 63;
  int stage_v_178_2 = ((pub_r001283_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001283_21_1 * 2) + 18) & 63;
  int stage_v_179_2 = ((pub_r001283_21_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((sec_r001283_17_1 * 3) + pub_r001283_5_1) + 27) & 127;
  int stage_v_180_2 = (((sec_r001283_17_2 * 3) + pub_r001283_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001283_3_1 * 2) + 15) & 63;
  int stage_v_181_2 = ((pub_r001283_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((sec_r001283_12_1 * 3) + pub_r001283_7_1) + 14) & 127;
  int stage_v_182_2 = (((sec_r001283_12_2 * 3) + pub_r001283_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((stage_v_142_1 * 3) + pub_r001283_0_1) + 26) & 127;
  int stage_v_183_2 = (((stage_v_142_2 * 3) + pub_r001283_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_9_1 * 3) + pub_r001283_10_1) + 14) & 127;
  int stage_v_184_2 = (((stage_v_9_2 * 3) + pub_r001283_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = ((pub_r001283_4_1 * 2) + 10) & 63;
  int stage_v_185_2 = ((pub_r001283_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_82_1 * 3) + pub_r001283_17_1) + 4) & 127;
  int stage_v_186_2 = (((stage_v_82_2 * 3) + pub_r001283_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001283_7_1 * 2) + 44) & 63;
  int stage_v_187_2 = ((pub_r001283_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001283_20_1 * 2) + 24) & 63;
  int stage_v_188_2 = ((pub_r001283_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((sec_r001283_6_1 * 3) + pub_r001283_20_1) + 24) & 127;
  int stage_v_189_2 = (((sec_r001283_6_2 * 3) + pub_r001283_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001283_2_1 * 2) + 30) & 63;
  int stage_v_190_2 = ((pub_r001283_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((sec_r001283_8_1 * 3) + pub_r001283_7_1) + 44) & 127;
  int stage_v_191_2 = (((sec_r001283_8_2 * 3) + pub_r001283_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_153_1 * 3) + pub_r001283_12_1) + 12) & 127;
  int stage_v_192_2 = (((stage_v_153_2 * 3) + pub_r001283_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = ((pub_r001283_23_1 * 2) + 47) & 63;
  int stage_v_193_2 = ((pub_r001283_23_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001283_8_1 * 2) + 13) & 63;
  int stage_v_194_2 = ((pub_r001283_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001283_3_1 * 2) + 14) & 63;
  int stage_v_195_2 = ((pub_r001283_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_70_1 * 3) + pub_r001283_16_1) + 6) & 127;
  int stage_v_196_2 = (((stage_v_70_2 * 3) + pub_r001283_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001283_7_1 * 2) + 34) & 63;
  int stage_v_197_2 = ((pub_r001283_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001283_0_1 * 2) + 30) & 63;
  int stage_v_198_2 = ((pub_r001283_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001283_11_1 * 2) + 29) & 63;
  int stage_v_199_2 = ((pub_r001283_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001283_10_1 * 2) + 22) & 63;
  int stage_v_200_2 = ((pub_r001283_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001283_23_1 * 2) + 33) & 63;
  int stage_v_201_2 = ((pub_r001283_23_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_90_1 * 3) + pub_r001283_2_1) + 42) & 127;
  int stage_v_202_2 = (((stage_v_90_2 * 3) + pub_r001283_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((sec_r001283_2_1 * 3) + pub_r001283_10_1) + 26) & 127;
  int stage_v_203_2 = (((sec_r001283_2_2 * 3) + pub_r001283_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_160_1 * 3) + pub_r001283_5_1) + 23) & 127;
  int stage_v_204_2 = (((stage_v_160_2 * 3) + pub_r001283_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((sec_r001283_0_1 * 3) + pub_r001283_6_1) + 7) & 127;
  int stage_v_205_2 = (((sec_r001283_0_2 * 3) + pub_r001283_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_41_1 * 3) + pub_r001283_14_1) + 12) & 127;
  int stage_v_206_2 = (((stage_v_41_2 * 3) + pub_r001283_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((stage_v_87_1 * 3) + pub_r001283_3_1) + 17) & 127;
  int stage_v_207_2 = (((stage_v_87_2 * 3) + pub_r001283_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001283_4_1 * 2) + 19) & 63;
  int stage_v_208_2 = ((pub_r001283_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001283_18_1 * 2) + 8) & 63;
  int stage_v_209_2 = ((pub_r001283_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001283_21_1 * 2) + 22) & 63;
  int stage_v_210_2 = ((pub_r001283_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_72_1 * 3) + pub_r001283_7_1) + 4) & 127;
  int stage_v_211_2 = (((stage_v_72_2 * 3) + pub_r001283_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_172_1 * 3) + pub_r001283_21_1) + 18) & 127;
  int stage_v_212_2 = (((stage_v_172_2 * 3) + pub_r001283_21_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_203_1 * 3) + pub_r001283_0_1) + 30) & 127;
  int stage_v_213_2 = (((stage_v_203_2 * 3) + pub_r001283_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((sec_r001283_18_1 * 3) + pub_r001283_23_1) + 33) & 127;
  int stage_v_214_2 = (((sec_r001283_18_2 * 3) + pub_r001283_23_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_157_1 * 3) + pub_r001283_0_1) + 22) & 127;
  int stage_v_215_2 = (((stage_v_157_2 * 3) + pub_r001283_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_137_1 * 3) + pub_r001283_8_1) + 40) & 127;
  int stage_v_216_2 = (((stage_v_137_2 * 3) + pub_r001283_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001283_20_1 * 2) + 25) & 63;
  int stage_v_217_2 = ((pub_r001283_20_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001283_11_1 * 2) + 29) & 63;
  int stage_v_218_2 = ((pub_r001283_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_110_1 * 3) + pub_r001283_17_1) + 39) & 127;
  int stage_v_219_2 = (((stage_v_110_2 * 3) + pub_r001283_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001283_0_1 * 2) + 28) & 63;
  int stage_v_220_2 = ((pub_r001283_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_70_1 * 3) + pub_r001283_15_1) + 15) & 127;
  int stage_v_221_2 = (((stage_v_70_2 * 3) + pub_r001283_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((sec_r001283_5_1 * 3) + pub_r001283_8_1) + 6) & 127;
  int stage_v_222_2 = (((sec_r001283_5_2 * 3) + pub_r001283_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001283_11_1 * 2) + 6) & 63;
  int stage_v_223_2 = ((pub_r001283_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001283_14_1 * 2) + 49) & 63;
  int stage_v_224_2 = ((pub_r001283_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001283_14_1 * 2) + 47) & 63;
  int stage_v_225_2 = ((pub_r001283_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001283_7_1 * 2) + 18) & 63;
  int stage_v_226_2 = ((pub_r001283_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((helper_flow_2_1 * 3) + pub_r001283_17_1) + 43) & 127;
  int stage_v_227_2 = (((helper_flow_2_2 * 3) + pub_r001283_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001283_6_1 * 2) + 45) & 63;
  int stage_v_228_2 = ((pub_r001283_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_182_1 * 3) + pub_r001283_19_1) + 37) & 127;
  int stage_v_229_2 = (((stage_v_182_2 * 3) + pub_r001283_19_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((stage_v_117_1 * 3) + pub_r001283_3_1) + 17) & 127;
  int stage_v_230_2 = (((stage_v_117_2 * 3) + pub_r001283_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001283_14_1 * 2) + 42) & 63;
  int stage_v_231_2 = ((pub_r001283_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001283_8_1 * 2) + 9) & 63;
  int stage_v_232_2 = ((pub_r001283_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_34_1 * 3) + pub_r001283_7_1) + 42) & 127;
  int stage_v_233_2 = (((stage_v_34_2 * 3) + pub_r001283_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_7_1 * 3) + pub_r001283_3_1) + 45) & 127;
  int stage_v_234_2 = (((stage_v_7_2 * 3) + pub_r001283_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = ((pub_r001283_1_1 * 2) + 16) & 63;
  int stage_v_235_2 = ((pub_r001283_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001283_5_1 * 2) + 40) & 63;
  int stage_v_236_2 = ((pub_r001283_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_80_1 * 3) + pub_r001283_1_1) + 20) & 127;
  int stage_v_237_2 = (((stage_v_80_2 * 3) + pub_r001283_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_18_1 * 3) + pub_r001283_8_1) + 24) & 127;
  int stage_v_238_2 = (((stage_v_18_2 * 3) + pub_r001283_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = (((helper_flow_5_1 * 3) + pub_r001283_21_1) + 44) & 127;
  int stage_v_239_2 = (((helper_flow_5_2 * 3) + pub_r001283_21_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_25_1 * 3) + pub_r001283_19_1) + 28) & 127;
  int stage_v_240_2 = (((stage_v_25_2 * 3) + pub_r001283_19_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_160_1 * 3) + pub_r001283_22_1) + 31) & 127;
  int stage_v_241_2 = (((stage_v_160_2 * 3) + pub_r001283_22_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001283_7_1 * 2) + 6) & 63;
  int stage_v_242_2 = ((pub_r001283_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_159_1 * 3) + pub_r001283_12_1) + 22) & 127;
  int stage_v_243_2 = (((stage_v_159_2 * 3) + pub_r001283_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_221_1 * 3) + pub_r001283_23_1) + 30) & 127;
  int stage_v_244_2 = (((stage_v_221_2 * 3) + pub_r001283_23_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_244_1 * 3) + pub_r001283_20_1) + 7) & 127;
  int stage_v_245_2 = (((stage_v_244_2 * 3) + pub_r001283_20_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001283_6_1 * 2) + 24) & 63;
  int stage_v_246_2 = ((pub_r001283_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((sec_r001283_9_1 * 3) + pub_r001283_19_1) + 33) & 127;
  int stage_v_247_2 = (((sec_r001283_9_2 * 3) + pub_r001283_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001283_1_1 * 2) + 18) & 63;
  int stage_v_248_2 = ((pub_r001283_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_167_1 * 3) + pub_r001283_7_1) + 26) & 127;
  int stage_v_249_2 = (((stage_v_167_2 * 3) + pub_r001283_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001283_15_1 * 2) + 46) & 63;
  int stage_v_250_2 = ((pub_r001283_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001283_23_1 * 2) + 21) & 63;
  int stage_v_251_2 = ((pub_r001283_23_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001283_8_1 * 2) + 43) & 63;
  int stage_v_252_2 = ((pub_r001283_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((helper_flow_5_1 * 3) + pub_r001283_2_1) + 13) & 127;
  int stage_v_253_2 = (((helper_flow_5_2 * 3) + pub_r001283_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001283_10_1 * 2) + 9) & 63;
  int stage_v_254_2 = ((pub_r001283_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((stage_v_192_1 * 3) + pub_r001283_0_1) + 32) & 127;
  int stage_v_255_2 = (((stage_v_192_2 * 3) + pub_r001283_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((stage_v_98_1 * 3) + pub_r001283_9_1) + 7) & 127;
  int stage_v_256_2 = (((stage_v_98_2 * 3) + pub_r001283_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001283_13_1 * 2) + 34) & 63;
  int stage_v_257_2 = ((pub_r001283_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_165_1 * 3) + pub_r001283_16_1) + 8) & 127;
  int stage_v_258_2 = (((stage_v_165_2 * 3) + pub_r001283_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((stage_v_170_1 * 3) + pub_r001283_7_1) + 40) & 127;
  int stage_v_259_2 = (((stage_v_170_2 * 3) + pub_r001283_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001283_10_1 * 2) + 14) & 63;
  int stage_v_260_2 = ((pub_r001283_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_182_1 * 3) + pub_r001283_15_1) + 29) & 127;
  int stage_v_261_2 = (((stage_v_182_2 * 3) + pub_r001283_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001283_10_1 * 2) + 13) & 63;
  int stage_v_262_2 = ((pub_r001283_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_155_1 * 3) + pub_r001283_0_1) + 27) & 127;
  int stage_v_263_2 = (((stage_v_155_2 * 3) + pub_r001283_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((stage_v_222_1 * 3) + pub_r001283_0_1) + 28) & 127;
  int stage_v_264_2 = (((stage_v_222_2 * 3) + pub_r001283_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_158_1 * 3) + pub_r001283_2_1) + 6) & 127;
  int stage_v_265_2 = (((stage_v_158_2 * 3) + pub_r001283_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_33_1 * 3) + pub_r001283_7_1) + 42) & 127;
  int stage_v_266_2 = (((stage_v_33_2 * 3) + pub_r001283_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001283_18_1 * 2) + 39) & 63;
  int stage_v_267_2 = ((pub_r001283_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((stage_v_205_1 * 3) + pub_r001283_20_1) + 5) & 127;
  int stage_v_268_2 = (((stage_v_205_2 * 3) + pub_r001283_20_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001283_8_1 * 2) + 36) & 63;
  int stage_v_269_2 = ((pub_r001283_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((sec_r001283_15_1 * 3) + pub_r001283_12_1) + 26) & 127;
  int stage_v_270_2 = (((sec_r001283_15_2 * 3) + pub_r001283_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((sec_r001283_18_1 * 3) + pub_r001283_17_1) + 22) & 127;
  int stage_v_271_2 = (((sec_r001283_18_2 * 3) + pub_r001283_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((stage_v_58_1 * 3) + pub_r001283_17_1) + 10) & 127;
  int stage_v_272_2 = (((stage_v_58_2 * 3) + pub_r001283_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001283_9_1 * 2) + 32) & 63;
  int stage_v_273_2 = ((pub_r001283_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_186_1 * 3) + pub_r001283_4_1) + 9) & 127;
  int stage_v_274_2 = (((stage_v_186_2 * 3) + pub_r001283_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_203_1 * 3) + pub_r001283_21_1) + 24) & 127;
  int stage_v_275_2 = (((stage_v_203_2 * 3) + pub_r001283_21_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001283_3_1 * 2) + 19) & 63;
  int stage_v_276_2 = ((pub_r001283_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001283_18_1 * 2) + 27) & 63;
  int stage_v_277_2 = ((pub_r001283_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_35_1 * 3) + pub_r001283_16_1) + 9) & 127;
  int stage_v_278_2 = (((stage_v_35_2 * 3) + pub_r001283_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_171_1 * 3) + pub_r001283_4_1) + 39) & 127;
  int stage_v_279_2 = (((stage_v_171_2 * 3) + pub_r001283_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_229_1 * 3) + pub_r001283_14_1) + 12) & 127;
  int stage_v_280_2 = (((stage_v_229_2 * 3) + pub_r001283_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001283_12_1 * 2) + 48) & 63;
  int stage_v_281_2 = ((pub_r001283_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_129_1 * 3) + pub_r001283_6_1) + 6) & 127;
  int stage_v_282_2 = (((stage_v_129_2 * 3) + pub_r001283_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001283_21_1 * 2) + 42) & 63;
  int stage_v_283_2 = ((pub_r001283_21_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001283_20_1 * 2) + 43) & 63;
  int stage_v_284_2 = ((pub_r001283_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_264_1 * 3) + pub_r001283_10_1) + 44) & 127;
  int stage_v_285_2 = (((stage_v_264_2 * 3) + pub_r001283_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001283_17_1 * 2) + 16) & 63;
  int stage_v_286_2 = ((pub_r001283_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001283_14_1 * 2) + 40) & 63;
  int stage_v_287_2 = ((pub_r001283_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = (((stage_v_265_1 * 3) + pub_r001283_10_1) + 43) & 127;
  int stage_v_288_2 = (((stage_v_265_2 * 3) + pub_r001283_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((stage_v_138_1 * 3) + pub_r001283_17_1) + 10) & 127;
  int stage_v_289_2 = (((stage_v_138_2 * 3) + pub_r001283_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_271_1 * 3) + pub_r001283_13_1) + 24) & 127;
  int stage_v_290_2 = (((stage_v_271_2 * 3) + pub_r001283_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_158_1 * 3) + pub_r001283_13_1) + 6) & 127;
  int stage_v_291_2 = (((stage_v_158_2 * 3) + pub_r001283_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = (((stage_v_60_1 * 3) + pub_r001283_1_1) + 9) & 127;
  int stage_v_292_2 = (((stage_v_60_2 * 3) + pub_r001283_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_135_1 * 3) + pub_r001283_10_1) + 20) & 127;
  int stage_v_293_2 = (((stage_v_135_2 * 3) + pub_r001283_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001283_4_1 * 2) + 37) & 63;
  int stage_v_294_2 = ((pub_r001283_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001283_13_1 * 2) + 36) & 63;
  int stage_v_295_2 = ((pub_r001283_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_80_1 * 3) + pub_r001283_9_1) + 24) & 127;
  int stage_v_296_2 = (((stage_v_80_2 * 3) + pub_r001283_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((stage_v_230_1 * 3) + pub_r001283_12_1) + 41) & 127;
  int stage_v_297_2 = (((stage_v_230_2 * 3) + pub_r001283_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = ((pub_r001283_18_1 * 2) + 29) & 63;
  int stage_v_298_2 = ((pub_r001283_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = (((stage_v_268_1 * 3) + pub_r001283_12_1) + 15) & 127;
  int stage_v_299_2 = (((stage_v_268_2 * 3) + pub_r001283_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = (((stage_v_238_1 * 3) + pub_r001283_14_1) + 23) & 127;
  int stage_v_300_2 = (((stage_v_238_2 * 3) + pub_r001283_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001283_20_1 * 2) + 11) & 63;
  int stage_v_301_2 = ((pub_r001283_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_192_1 * 3) + pub_r001283_8_1) + 33) & 127;
  int stage_v_302_2 = (((stage_v_192_2 * 3) + pub_r001283_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((stage_v_229_1 * 3) + pub_r001283_12_1) + 8) & 127;
  int stage_v_303_2 = (((stage_v_229_2 * 3) + pub_r001283_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = (((stage_v_268_1 * 3) + pub_r001283_4_1) + 21) & 127;
  int stage_v_304_2 = (((stage_v_268_2 * 3) + pub_r001283_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001283_23_1 * 2) + 20) & 63;
  int stage_v_305_2 = ((pub_r001283_23_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_75_1 * 3) + pub_r001283_7_1) + 4) & 127;
  int stage_v_306_2 = (((stage_v_75_2 * 3) + pub_r001283_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001283_3_1 * 2) + 44) & 63;
  int stage_v_307_2 = ((pub_r001283_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((stage_v_282_1 * 3) + pub_r001283_5_1) + 28) & 127;
  int stage_v_308_2 = (((stage_v_282_2 * 3) + pub_r001283_5_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001283_19_1 * 2) + 12) & 63;
  int stage_v_309_2 = ((pub_r001283_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001283_2_1 * 2) + 26) & 63;
  int stage_v_310_2 = ((pub_r001283_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_216_1 * 3) + pub_r001283_11_1) + 14) & 127;
  int stage_v_311_2 = (((stage_v_216_2 * 3) + pub_r001283_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001283_0_1 * 2) + 14) & 63;
  int stage_v_312_2 = ((pub_r001283_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_184_1 * 3) + pub_r001283_14_1) + 32) & 127;
  int stage_v_313_2 = (((stage_v_184_2 * 3) + pub_r001283_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001283_19_1 * 2) + 43) & 63;
  int stage_v_314_2 = ((pub_r001283_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001283_3_1 * 2) + 46) & 63;
  int stage_v_315_2 = ((pub_r001283_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((sec_r001283_10_1 * 3) + pub_r001283_23_1) + 14) & 127;
  int stage_v_316_2 = (((sec_r001283_10_2 * 3) + pub_r001283_23_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((sec_r001283_11_1 * 3) + pub_r001283_8_1) + 45) & 127;
  int stage_v_317_2 = (((sec_r001283_11_2 * 3) + pub_r001283_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_291_1 * 3) + pub_r001283_10_1) + 4) & 127;
  int stage_v_318_2 = (((stage_v_291_2 * 3) + pub_r001283_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001283_14_1 * 2) + 44) & 63;
  int stage_v_319_2 = ((pub_r001283_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001283_17_1 * 2) + 24) & 63;
  int stage_v_320_2 = ((pub_r001283_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_192_1 * 3) + pub_r001283_11_1) + 44) & 127;
  int stage_v_321_2 = (((stage_v_192_2 * 3) + pub_r001283_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001283_14_1 * 2) + 13) & 63;
  int stage_v_322_2 = ((pub_r001283_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001283_16_1 * 2) + 43) & 63;
  int stage_v_323_2 = ((pub_r001283_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_239_1 * 3) + pub_r001283_16_1) + 6) & 127;
  int stage_v_324_2 = (((stage_v_239_2 * 3) + pub_r001283_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((helper_flow_5_1 * 3) + pub_r001283_7_1) + 44) & 127;
  int stage_v_325_2 = (((helper_flow_5_2 * 3) + pub_r001283_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001283_6_1 * 2) + 18) & 63;
  int stage_v_326_2 = ((pub_r001283_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = (((stage_v_300_1 * 3) + pub_r001283_2_1) + 7) & 127;
  int stage_v_327_2 = (((stage_v_300_2 * 3) + pub_r001283_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((stage_v_23_1 * 3) + pub_r001283_8_1) + 38) & 127;
  int stage_v_328_2 = (((stage_v_23_2 * 3) + pub_r001283_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_98_1 * 3) + pub_r001283_0_1) + 12) & 127;
  int stage_v_329_2 = (((stage_v_98_2 * 3) + pub_r001283_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((helper_flow_4_1 * 3) + pub_r001283_16_1) + 29) & 127;
  int stage_v_330_2 = (((helper_flow_4_2 * 3) + pub_r001283_16_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = (((stage_v_70_1 * 3) + pub_r001283_19_1) + 19) & 127;
  int stage_v_331_2 = (((stage_v_70_2 * 3) + pub_r001283_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((stage_v_249_1 * 3) + pub_r001283_3_1) + 35) & 127;
  int stage_v_332_2 = (((stage_v_249_2 * 3) + pub_r001283_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((sec_r001283_9_1 * 3) + pub_r001283_19_1) + 18) & 127;
  int stage_v_333_2 = (((sec_r001283_9_2 * 3) + pub_r001283_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001283_4_1 * 2) + 7) & 63;
  int stage_v_334_2 = ((pub_r001283_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((stage_v_189_1 * 3) + pub_r001283_15_1) + 35) & 127;
  int stage_v_335_2 = (((stage_v_189_2 * 3) + pub_r001283_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_64_1 * 3) + pub_r001283_22_1) + 39) & 127;
  int stage_v_336_2 = (((stage_v_64_2 * 3) + pub_r001283_22_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_336_1 * 3) + pub_r001283_0_1) + 30) & 127;
  int stage_v_337_2 = (((stage_v_336_2 * 3) + pub_r001283_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_104_1 * 3) + pub_r001283_17_1) + 10) & 127;
  int stage_v_338_2 = (((stage_v_104_2 * 3) + pub_r001283_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001283_17_1 * 2) + 35) & 63;
  int stage_v_339_2 = ((pub_r001283_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_329_1 * 3) + pub_r001283_10_1) + 23) & 127;
  int stage_v_340_2 = (((stage_v_329_2 * 3) + pub_r001283_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_256_1 * 3) + pub_r001283_13_1) + 40) & 127;
  int stage_v_341_2 = (((stage_v_256_2 * 3) + pub_r001283_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_33_1 * 3) + pub_r001283_22_1) + 15) & 127;
  int stage_v_342_2 = (((stage_v_33_2 * 3) + pub_r001283_22_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001283_20_1 * 2) + 32) & 63;
  int stage_v_343_2 = ((pub_r001283_20_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((stage_v_341_1 * 3) + pub_r001283_17_1) + 4) & 127;
  int stage_v_344_2 = (((stage_v_341_2 * 3) + pub_r001283_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = (((stage_v_268_1 * 3) + pub_r001283_3_1) + 4) & 127;
  int stage_v_345_2 = (((stage_v_268_2 * 3) + pub_r001283_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001283_10_1 * 2) + 20) & 63;
  int stage_v_346_2 = ((pub_r001283_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001283_20_1 * 2) + 37) & 63;
  int stage_v_347_2 = ((pub_r001283_20_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001283_23_1 * 2) + 7) & 63;
  int stage_v_348_2 = ((pub_r001283_23_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((stage_v_221_1 * 3) + pub_r001283_19_1) + 20) & 127;
  int stage_v_349_2 = (((stage_v_221_2 * 3) + pub_r001283_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((sec_r001283_10_1 * 3) + pub_r001283_4_1) + 45) & 127;
  int stage_v_350_2 = (((sec_r001283_10_2 * 3) + pub_r001283_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001283_23_1 * 2) + 44) & 63;
  int stage_v_351_2 = ((pub_r001283_23_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((stage_v_272_1 * 3) + pub_r001283_3_1) + 29) & 127;
  int stage_v_352_2 = (((stage_v_272_2 * 3) + pub_r001283_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_313_1 * 3) + pub_r001283_3_1) + 43) & 127;
  int stage_v_353_2 = (((stage_v_313_2 * 3) + pub_r001283_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001283_1_1 * 2) + 30) & 63;
  int stage_v_354_2 = ((pub_r001283_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((sec_r001283_14_1 * 3) + pub_r001283_6_1) + 32) & 127;
  int stage_v_355_2 = (((sec_r001283_14_2 * 3) + pub_r001283_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_202_1 * 3) + pub_r001283_11_1) + 26) & 127;
  int stage_v_356_2 = (((stage_v_202_2 * 3) + pub_r001283_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_133_1 * 3) + pub_r001283_15_1) + 32) & 127;
  int stage_v_357_2 = (((stage_v_133_2 * 3) + pub_r001283_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = ((pub_r001283_11_1 * 2) + 49) & 63;
  int stage_v_358_2 = ((pub_r001283_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_142_1 * 3) + pub_r001283_19_1) + 8) & 127;
  int stage_v_359_2 = (((stage_v_142_2 * 3) + pub_r001283_19_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001283_10_1 * 2) + 34) & 63;
  int stage_v_360_2 = ((pub_r001283_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_324_1 * 3) + pub_r001283_17_1) + 16) & 127;
  int stage_v_361_2 = (((stage_v_324_2 * 3) + pub_r001283_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001283_3_1 * 2) + 34) & 63;
  int stage_v_362_2 = ((pub_r001283_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001283_10_1 * 2) + 32) & 63;
  int stage_v_363_2 = ((pub_r001283_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001283_14_1 * 2) + 13) & 63;
  int stage_v_364_2 = ((pub_r001283_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001283_18_1 * 2) + 15) & 63;
  int stage_v_365_2 = ((pub_r001283_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001283_22_1 * 2) + 28) & 63;
  int stage_v_366_2 = ((pub_r001283_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001283_10_1 * 2) + 30) & 63;
  int stage_v_367_2 = ((pub_r001283_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001283_6_1 * 2) + 7) & 63;
  int stage_v_368_2 = ((pub_r001283_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_104_1 * 3) + pub_r001283_20_1) + 5) & 127;
  int stage_v_369_2 = (((stage_v_104_2 * 3) + pub_r001283_20_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((stage_v_36_1 * 3) + pub_r001283_4_1) + 31) & 127;
  int stage_v_370_2 = (((stage_v_36_2 * 3) + pub_r001283_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_356_1 * 3) + pub_r001283_4_1) + 19) & 127;
  int stage_v_371_2 = (((stage_v_356_2 * 3) + pub_r001283_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001283_11_1 * 2) + 27) & 63;
  int stage_v_372_2 = ((pub_r001283_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001283_5_1 * 2) + 7) & 63;
  int stage_v_373_2 = ((pub_r001283_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001283_11_1 * 2) + 37) & 63;
  int stage_v_374_2 = ((pub_r001283_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((stage_v_271_1 * 3) + pub_r001283_20_1) + 35) & 127;
  int stage_v_375_2 = (((stage_v_271_2 * 3) + pub_r001283_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_300_1 * 3) + pub_r001283_9_1) + 28) & 127;
  int stage_v_376_2 = (((stage_v_300_2 * 3) + pub_r001283_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((helper_flow_1_1 * 3) + pub_r001283_23_1) + 18) & 127;
  int stage_v_377_2 = (((helper_flow_1_2 * 3) + pub_r001283_23_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001283_6_1 * 2) + 13) & 63;
  int stage_v_378_2 = ((pub_r001283_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001283_0_1 * 2) + 31) & 63;
  int stage_v_379_2 = ((pub_r001283_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((stage_v_371_1 * 3) + pub_r001283_9_1) + 36) & 127;
  int stage_v_380_2 = (((stage_v_371_2 * 3) + pub_r001283_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_133_1 * 3) + pub_r001283_22_1) + 18) & 127;
  int stage_v_381_2 = (((stage_v_133_2 * 3) + pub_r001283_22_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_341_1 * 3) + pub_r001283_10_1) + 40) & 127;
  int stage_v_382_2 = (((stage_v_341_2 * 3) + pub_r001283_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_268_1 * 3) + pub_r001283_18_1) + 22) & 127;
  int stage_v_383_2 = (((stage_v_268_2 * 3) + pub_r001283_18_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = ((pub_r001283_9_1 * 2) + 23) & 63;
  int stage_v_384_2 = ((pub_r001283_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001283_1_1 * 2) + 25) & 63;
  int stage_v_385_2 = ((pub_r001283_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001283_15_1 * 2) + 15) & 63;
  int stage_v_386_2 = ((pub_r001283_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((helper_flow_1_1 * 3) + pub_r001283_1_1) + 14) & 127;
  int stage_v_387_2 = (((helper_flow_1_2 * 3) + pub_r001283_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001283_7_1 * 2) + 13) & 63;
  int stage_v_388_2 = ((pub_r001283_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_91_1 * 3) + pub_r001283_5_1) + 4) & 127;
  int stage_v_389_2 = (((stage_v_91_2 * 3) + pub_r001283_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001283_22_1 * 2) + 38) & 63;
  int stage_v_390_2 = ((pub_r001283_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001283_19_1 * 2) + 28) & 63;
  int stage_v_391_2 = ((pub_r001283_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001283_6_1 * 2) + 48) & 63;
  int stage_v_392_2 = ((pub_r001283_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((stage_v_92_1 * 3) + pub_r001283_22_1) + 8) & 127;
  int stage_v_393_2 = (((stage_v_92_2 * 3) + pub_r001283_22_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001283_18_1 * 2) + 44) & 63;
  int stage_v_394_2 = ((pub_r001283_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_23_1 * 3) + pub_r001283_17_1) + 24) & 127;
  int stage_v_395_2 = (((stage_v_23_2 * 3) + pub_r001283_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = (((stage_v_113_1 * 3) + pub_r001283_6_1) + 34) & 127;
  int stage_v_396_2 = (((stage_v_113_2 * 3) + pub_r001283_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001283_10_1 * 2) + 49) & 63;
  int stage_v_397_2 = ((pub_r001283_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((helper_flow_1_1 * 3) + pub_r001283_5_1) + 25) & 127;
  int stage_v_398_2 = (((helper_flow_1_2 * 3) + pub_r001283_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = ((pub_r001283_20_1 * 2) + 13) & 63;
  int stage_v_399_2 = ((pub_r001283_20_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001283_15_1 * 2) + 26) & 63;
  int stage_v_400_2 = ((pub_r001283_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001283_14_1 * 2) + 23) & 63;
  int stage_v_401_2 = ((pub_r001283_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001283_1_1 * 2) + 29) & 63;
  int stage_v_402_2 = ((pub_r001283_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001283_16_1 * 2) + 40) & 63;
  int stage_v_403_2 = ((pub_r001283_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((sec_r001283_1_1 * 3) + pub_r001283_4_1) + 7) & 127;
  int stage_v_404_2 = (((sec_r001283_1_2 * 3) + pub_r001283_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_282_1 * 3) + pub_r001283_7_1) + 30) & 127;
  int stage_v_405_2 = (((stage_v_282_2 * 3) + pub_r001283_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((sec_r001283_20_1 * 3) + pub_r001283_9_1) + 33) & 127;
  int stage_v_406_2 = (((sec_r001283_20_2 * 3) + pub_r001283_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001283_10_1 * 2) + 13) & 63;
  int stage_v_407_2 = ((pub_r001283_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_318_1 * 3) + pub_r001283_15_1) + 22) & 127;
  int stage_v_408_2 = (((stage_v_318_2 * 3) + pub_r001283_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = (((sec_r001283_0_1 * 3) + pub_r001283_4_1) + 38) & 127;
  int stage_v_409_2 = (((sec_r001283_0_2 * 3) + pub_r001283_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001283_12_1 * 2) + 42) & 63;
  int stage_v_410_2 = ((pub_r001283_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001283_11_1 * 2) + 47) & 63;
  int stage_v_411_2 = ((pub_r001283_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_142_1 * 3) + pub_r001283_21_1) + 5) & 127;
  int stage_v_412_2 = (((stage_v_142_2 * 3) + pub_r001283_21_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = (((stage_v_406_1 * 3) + pub_r001283_15_1) + 28) & 127;
  int stage_v_413_2 = (((stage_v_406_2 * 3) + pub_r001283_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = ((pub_r001283_12_1 * 2) + 23) & 63;
  int stage_v_414_2 = ((pub_r001283_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_311_1 * 3) + pub_r001283_8_1) + 18) & 127;
  int stage_v_415_2 = (((stage_v_311_2 * 3) + pub_r001283_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001283_13_1 * 2) + 41) & 63;
  int stage_v_416_2 = ((pub_r001283_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_170_1 * 3) + pub_r001283_6_1) + 4) & 127;
  int stage_v_417_2 = (((stage_v_170_2 * 3) + pub_r001283_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = (((stage_v_413_1 * 3) + pub_r001283_21_1) + 11) & 127;
  int stage_v_418_2 = (((stage_v_413_2 * 3) + pub_r001283_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = ((pub_r001283_7_1 * 2) + 29) & 63;
  int stage_v_419_2 = ((pub_r001283_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001283_8_1 * 2) + 9) & 63;
  int stage_v_420_2 = ((pub_r001283_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = (((stage_v_316_1 * 3) + pub_r001283_12_1) + 19) & 127;
  int stage_v_421_2 = (((stage_v_316_2 * 3) + pub_r001283_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = (((helper_flow_2_1 * 3) + pub_r001283_17_1) + 33) & 127;
  int stage_v_422_2 = (((helper_flow_2_2 * 3) + pub_r001283_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = (((stage_v_176_1 * 3) + pub_r001283_18_1) + 4) & 127;
  int stage_v_423_2 = (((stage_v_176_2 * 3) + pub_r001283_18_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = ((pub_r001283_7_1 * 2) + 49) & 63;
  int stage_v_424_2 = ((pub_r001283_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001283_8_1 * 2) + 41) & 63;
  int stage_v_425_2 = ((pub_r001283_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001283_2_1 * 2) + 30) & 63;
  int stage_v_426_2 = ((pub_r001283_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001283_13_1 * 2) + 32) & 63;
  int stage_v_427_2 = ((pub_r001283_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = (((stage_v_91_1 * 3) + pub_r001283_8_1) + 9) & 127;
  int stage_v_428_2 = (((stage_v_91_2 * 3) + pub_r001283_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = ((pub_r001283_1_1 * 2) + 31) & 63;
  int stage_v_429_2 = ((pub_r001283_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = (((stage_v_350_1 * 3) + pub_r001283_5_1) + 19) & 127;
  int stage_v_430_2 = (((stage_v_350_2 * 3) + pub_r001283_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = ((pub_r001283_11_1 * 2) + 14) & 63;
  int stage_v_431_2 = ((pub_r001283_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = (((stage_v_214_1 * 3) + pub_r001283_19_1) + 41) & 127;
  int stage_v_432_2 = (((stage_v_214_2 * 3) + pub_r001283_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = ((pub_r001283_12_1 * 2) + 11) & 63;
  int stage_v_433_2 = ((pub_r001283_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = (((stage_v_256_1 * 3) + pub_r001283_10_1) + 5) & 127;
  int stage_v_434_2 = (((stage_v_256_2 * 3) + pub_r001283_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001283_9_1 * 2) + 47) & 63;
  int stage_v_435_2 = ((pub_r001283_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_80_1 * 3) + pub_r001283_17_1) + 40) & 127;
  int stage_v_436_2 = (((stage_v_80_2 * 3) + pub_r001283_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = (((stage_v_53_1 * 3) + pub_r001283_12_1) + 38) & 127;
  int stage_v_437_2 = (((stage_v_53_2 * 3) + pub_r001283_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001283_8_1 != sec_r001283_8_2);
  __CPROVER_assume(sec_r001283_11_1 != sec_r001283_11_2);
  __CPROVER_assume(pub_r001283_14_1 == pub_r001283_14_2);
  __CPROVER_assume(sec_r001283_17_1 != sec_r001283_17_2);
  __CPROVER_assume(pub_r001283_0_1 == pub_r001283_0_2);
  __CPROVER_assume(sec_r001283_16_1 != sec_r001283_16_2);
  __CPROVER_assume(pub_r001283_19_1 == pub_r001283_19_2);
  __CPROVER_assume(sec_r001283_7_1 != sec_r001283_7_2);
  __CPROVER_assume(sec_r001283_18_1 != sec_r001283_18_2);
  __CPROVER_assume(pub_r001283_2_1 == pub_r001283_2_2);
  __CPROVER_assume(sec_r001283_1_1 != sec_r001283_1_2);
  __CPROVER_assume(pub_r001283_6_1 == pub_r001283_6_2);
  __CPROVER_assume(sec_r001283_10_1 != sec_r001283_10_2);
  __CPROVER_assume(sec_r001283_9_1 != sec_r001283_9_2);
  __CPROVER_assume(sec_r001283_3_1 != sec_r001283_3_2);
  __CPROVER_assume(sec_r001283_15_1 != sec_r001283_15_2);
  __CPROVER_assume(sec_r001283_20_1 != sec_r001283_20_2);
  __CPROVER_assume(pub_r001283_3_1 == pub_r001283_3_2);
  __CPROVER_assume(pub_r001283_21_1 == pub_r001283_21_2);
  __CPROVER_assume(pub_r001283_22_1 == pub_r001283_22_2);
  __CPROVER_assume(pub_r001283_13_1 == pub_r001283_13_2);
  __CPROVER_assume(pub_r001283_11_1 == pub_r001283_11_2);
  __CPROVER_assume(pub_r001283_1_1 == pub_r001283_1_2);
  __CPROVER_assume(pub_r001283_10_1 == pub_r001283_10_2);
  __CPROVER_assume(pub_r001283_5_1 == pub_r001283_5_2);
  __CPROVER_assume(pub_r001283_23_1 == pub_r001283_23_2);
  __CPROVER_assume(pub_r001283_15_1 == pub_r001283_15_2);
  __CPROVER_assume(sec_r001283_2_1 != sec_r001283_2_2);
  __CPROVER_assume(sec_r001283_5_1 != sec_r001283_5_2);
  __CPROVER_assume(sec_r001283_12_1 != sec_r001283_12_2);
  __CPROVER_assume(pub_r001283_7_1 == pub_r001283_7_2);
  __CPROVER_assume(pub_r001283_18_1 == pub_r001283_18_2);
  __CPROVER_assume(sec_r001283_6_1 != sec_r001283_6_2);
  __CPROVER_assume(pub_r001283_4_1 == pub_r001283_4_2);
  __CPROVER_assume(pub_r001283_20_1 == pub_r001283_20_2);
  __CPROVER_assume(sec_r001283_4_1 != sec_r001283_4_2);
  __CPROVER_assume(sec_r001283_0_1 != sec_r001283_0_2);
  __CPROVER_assume(pub_r001283_17_1 == pub_r001283_17_2);
  __CPROVER_assume(pub_r001283_9_1 == pub_r001283_9_2);
  __CPROVER_assume(pub_r001283_16_1 == pub_r001283_16_2);
  __CPROVER_assume(pub_r001283_8_1 == pub_r001283_8_2);
  __CPROVER_assume(sec_r001283_13_1 != sec_r001283_13_2);
  __CPROVER_assume(sec_r001283_14_1 != sec_r001283_14_2);
  __CPROVER_assume(pub_r001283_12_1 == pub_r001283_12_2);
  __CPROVER_assume(sec_r001283_19_1 != sec_r001283_19_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.seq == st_var_2_2.seq);
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
  assert(stage_v_378_1 == stage_v_378_2);
  assert(stage_v_379_1 == stage_v_379_2);
  assert(stage_v_380_1 == stage_v_380_2);
  assert(stage_v_381_1 == stage_v_381_2);
  assert(stage_v_382_1 == stage_v_382_2);
  assert(stage_v_383_1 == stage_v_383_2);
  assert(stage_v_384_1 == stage_v_384_2);
  assert(stage_v_385_1 == stage_v_385_2);
  assert(stage_v_386_1 == stage_v_386_2);
  assert(stage_v_387_1 == stage_v_387_2);
  assert(stage_v_388_1 == stage_v_388_2);
  assert(stage_v_389_1 == stage_v_389_2);
  assert(stage_v_390_1 == stage_v_390_2);
  assert(stage_v_391_1 == stage_v_391_2);
  assert(stage_v_392_1 == stage_v_392_2);
  assert(stage_v_393_1 == stage_v_393_2);
  assert(stage_v_394_1 == stage_v_394_2);
  assert(stage_v_395_1 == stage_v_395_2);
  assert(stage_v_396_1 == stage_v_396_2);
  assert(stage_v_397_1 == stage_v_397_2);
  assert(stage_v_398_1 == stage_v_398_2);
  assert(stage_v_399_1 == stage_v_399_2);
  assert(stage_v_400_1 == stage_v_400_2);
  assert(stage_v_401_1 == stage_v_401_2);
  assert(stage_v_402_1 == stage_v_402_2);
  assert(stage_v_403_1 == stage_v_403_2);
  assert(stage_v_404_1 == stage_v_404_2);
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
  assert(stage_v_416_1 == stage_v_416_2);
  assert(stage_v_417_1 == stage_v_417_2);
  assert(stage_v_418_1 == stage_v_418_2);
  assert(stage_v_419_1 == stage_v_419_2);
  assert(stage_v_420_1 == stage_v_420_2);
  assert(stage_v_421_1 == stage_v_421_2);
  assert(stage_v_422_1 == stage_v_422_2);
  assert(stage_v_423_1 == stage_v_423_2);
  assert(stage_v_424_1 == stage_v_424_2);
  assert(stage_v_425_1 == stage_v_425_2);
  assert(stage_v_426_1 == stage_v_426_2);
  assert(stage_v_427_1 == stage_v_427_2);
  assert(stage_v_428_1 == stage_v_428_2);
  assert(stage_v_429_1 == stage_v_429_2);
  assert(stage_v_430_1 == stage_v_430_2);
  assert(stage_v_431_1 == stage_v_431_2);
  assert(stage_v_432_1 == stage_v_432_2);
  assert(stage_v_433_1 == stage_v_433_2);
  assert(stage_v_434_1 == stage_v_434_2);
  assert(stage_v_435_1 == stage_v_435_2);
  assert(stage_v_436_1 == stage_v_436_2);
  assert(stage_v_437_1 == stage_v_437_2);
}


