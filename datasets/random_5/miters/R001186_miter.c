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
struct MatrixBlock_R001186_8613_0
{
  unsigned char density;
  int scale;
  unsigned char trace;
  int buffer[3];
};
struct EventLog_R001186_8613_1
{
  int signature;
  int severity;
  int seq;
  int buffer[3];
};
struct SensorNode_R001186_8613_2
{
  int offset;
  int calib;
  unsigned char gain;
  short threshold;
  int buffer[3];
};
struct Transaction_R001186_8613_3
{
  unsigned char rate;
  int balance;
  int fee;
  int auth_code;
  int status;
  short account_id;
  int buffer[3];
};
union ColorPixel_R001186_8613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001186_8613_1
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
void fn_R001186_8613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st_1 = {0};
  struct SensorNode_R001186_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int damping_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_62_1) & 63;
  aux_2 = (aux_2 + damping_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_49_1 = local_arr_1[aux_1 % 3];
  int quantum_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_49_2 * 2)) & 127;
  int factor_87_1 = 0;
  int factor_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_87_1 = ((factor_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_87_2 = ((factor_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_87_1) & 127;
    acc_2 = (acc_2 + factor_87_2) & 127;
  }

  int coefficient_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_62_1 > 11)
  {
    acc_1 = ((acc_1 + (coefficient_62_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_62_2 > 11)
  {
    acc_2 = ((acc_2 + (coefficient_62_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_62_1 == damping_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_49_1 == quantum_49_2);
  assert(factor_87_1 == factor_87_2);
  assert(coefficient_62_1 == coefficient_62_2);
}

int fn_R001186_8613_0(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int damping_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_62) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_49 = local_arr[aux % 3];
  acc = (acc + (quantum_49 * 2)) & 127;
  int factor_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_87 = ((factor_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_87) & 127;
  }

  int coefficient_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_62 > 11)
  {
    acc = ((acc + (coefficient_62 * 2)) + 5) & 127;
    aux ^= coefficient_62 & 15;
  }
  else
  {
    acc = ((acc - coefficient_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001186_8613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st_1 = {0};
  struct SensorNode_R001186_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int residue_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_93_1)
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

  switch (residue_93_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_93_1 == residue_93_2);
}

int fn_R001186_8613_1(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int residue_93 = (aux + st.buffer[1]) & 3;
  switch (residue_93)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001186_8613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001186_8613_3 st_1 = {0};
  struct Transaction_R001186_8613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int parity_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_37_1) & 63;
  aux_2 = (aux_2 + parity_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_57_1 = 0;
  int damping_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_57_1 = ((damping_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_57_2 = ((damping_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_57_1) & 127;
    acc_2 = (acc_2 + damping_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_37_1 == parity_37_2);
  assert(damping_57_1 == damping_57_2);
}

int fn_R001186_8613_2(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001186_8613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int parity_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_37) & 63;
  acc ^= aux;
  int damping_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_57 = ((damping_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001186_8613_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st_1 = {0};
  struct SensorNode_R001186_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int pivot_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_54_1 > 42)
  {
    acc_1 = ((acc_1 + (pivot_54_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_54_2 > 42)
  {
    acc_2 = ((acc_2 + (pivot_54_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_87_1 = 0;
  int tracker_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_87_1 = ((tracker_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_87_2 = ((tracker_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_87_1) & 127;
    acc_2 = (acc_2 + tracker_87_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_24_1 = local_arr_1[aux_1 % 3];
  int delta_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_24_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_54_1 == pivot_54_2);
  assert(tracker_87_1 == tracker_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_24_1 == delta_24_2);
}

int fn_R001186_8613_3(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int pivot_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_54 > 42)
  {
    acc = ((acc + (pivot_54 * 2)) + 5) & 127;
    aux ^= pivot_54 & 15;
  }
  else
  {
    acc = ((acc - pivot_54) + 11) & 127;
    aux += 3;
  }
  int tracker_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_87 = ((tracker_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_87) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int delta_24 = local_arr[aux % 3];
  acc = (acc + (delta_24 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001186_8613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st_1 = {0};
  struct SensorNode_R001186_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_37_1)
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

  switch (index_reg_37_2)
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

  int tally_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_84_1) & 63;
  aux_2 = (aux_2 + tally_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_37_1 == index_reg_37_2);
  assert(tally_84_1 == tally_84_2);
}

int fn_R001186_8613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_37 = (aux + st.buffer[1]) & 3;
  switch (index_reg_37)
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

  int tally_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001186_8613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st_1 = {0};
  struct SensorNode_R001186_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int metric_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_97_1 > 35)
  {
    acc_1 = ((acc_1 + (metric_97_1 * 2)) + 5) & 127;
    aux_1 ^= metric_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_97_2 > 35)
  {
    acc_2 = ((acc_2 + (metric_97_2 * 2)) + 5) & 127;
    aux_2 ^= metric_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_93_1) & 63;
  aux_2 = (aux_2 + tally_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_96_1)
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

  switch (bound_96_2)
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
  int offset_21_1 = local_arr_1[aux_1 % 3];
  int offset_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_97_1 == metric_97_2);
  assert(tally_93_1 == tally_93_2);
  assert(bound_96_1 == bound_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_21_1 == offset_21_2);
}

int fn_R001186_8613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int metric_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_97 > 35)
  {
    acc = ((acc + (metric_97 * 2)) + 5) & 127;
    aux ^= metric_97 & 15;
  }
  else
  {
    acc = ((acc - metric_97) + 11) & 127;
    aux += 3;
  }
  int tally_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_93) & 63;
  acc ^= aux;
  int bound_96 = (aux + st.buffer[1]) & 3;
  switch (bound_96)
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
  int offset_21 = local_arr[aux % 3];
  acc = (acc + (offset_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001186_8613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001186_8613_3 st_1 = {0};
  struct Transaction_R001186_8613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_38_1 = 0;
  int margin_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_38_1 = ((margin_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_38_2 = ((margin_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_38_1) & 127;
    acc_2 = (acc_2 + margin_38_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_38_1 == margin_38_2);
}

int fn_R001186_8613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001186_8613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_38 = ((margin_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_38) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001186_8613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st_1 = {0};
  struct MatrixBlock_R001186_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quotient_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_35_1)
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

  switch (quotient_35_2)
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

  int cursor_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_17_1 > 30)
  {
    acc_1 = ((acc_1 + (cursor_17_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_17_2 > 30)
  {
    acc_2 = ((acc_2 + (cursor_17_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_17_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_35_1 == quotient_35_2);
  assert(cursor_17_1 == cursor_17_2);
}

int fn_R001186_8613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quotient_35 = (aux + st.buffer[1]) & 3;
  switch (quotient_35)
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

  int cursor_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_17 > 30)
  {
    acc = ((acc + (cursor_17 * 2)) + 5) & 127;
    aux ^= cursor_17 & 15;
  }
  else
  {
    acc = ((acc - cursor_17) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001186_8613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001186_8613_1 st_1 = {0};
  struct EventLog_R001186_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int anchor_50_1 = 0;
  int anchor_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_50_1 = ((anchor_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_50_2 = ((anchor_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_50_1) & 127;
    acc_2 = (acc_2 + anchor_50_2) & 127;
  }

  int parity_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_37_1) & 63;
  aux_2 = (aux_2 + parity_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_29_1 = local_arr_1[aux_1 % 3];
  int delta_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_50_1 == anchor_50_2);
  assert(parity_37_1 == parity_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_29_1 == delta_29_2);
}

int fn_R001186_8613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001186_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int anchor_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_50 = ((anchor_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_50) & 127;
  }

  int parity_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_37) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_29 = local_arr[aux % 3];
  acc = (acc + (delta_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001186_8613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001186_8613_1 st_1 = {0};
  struct EventLog_R001186_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_31_1 = local_arr_1[aux_1 % 3];
  int threshold_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_31_2 * 2)) & 127;
  int segment_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_37_1 > 30)
  {
    acc_1 = ((acc_1 + (segment_37_1 * 2)) + 5) & 127;
    aux_1 ^= segment_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_37_2 > 30)
  {
    acc_2 = ((acc_2 + (segment_37_2 * 2)) + 5) & 127;
    aux_2 ^= segment_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
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

  assert(threshold_31_1 == threshold_31_2);
  assert(segment_37_1 == segment_37_2);
}

int fn_R001186_8613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001186_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int threshold_31 = local_arr[aux % 3];
  acc = (acc + (threshold_31 * 2)) & 127;
  int segment_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_37 > 30)
  {
    acc = ((acc + (segment_37 * 2)) + 5) & 127;
    aux ^= segment_37 & 15;
  }
  else
  {
    acc = ((acc - segment_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001186_8613_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001186_8613_3 st_1 = {0};
  struct Transaction_R001186_8613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_89_1 = local_arr_1[aux_1 % 3];
  int cursor_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_89_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_44_1)
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

  switch (margin_44_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
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

  assert(cursor_89_1 == cursor_89_2);
  assert(margin_44_1 == margin_44_2);
}

int fn_R001186_8613_10(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001186_8613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int cursor_89 = local_arr[aux % 3];
  acc = (acc + (cursor_89 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_44 = (aux + st.buffer[1]) & 3;
  switch (margin_44)
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

void fn_R001186_8613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st_1 = {0};
  struct MatrixBlock_R001186_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_18_1 > 25)
  {
    acc_1 = ((acc_1 + (vector_18_1 * 2)) + 5) & 127;
    aux_1 ^= vector_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_18_2 > 25)
  {
    acc_2 = ((acc_2 + (vector_18_2 * 2)) + 5) & 127;
    aux_2 ^= vector_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_18_1 == vector_18_2);
}

int fn_R001186_8613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_18 > 25)
  {
    acc = ((acc + (vector_18 * 2)) + 5) & 127;
    aux ^= vector_18 & 15;
  }
  else
  {
    acc = ((acc - vector_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001186_8613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001186_8613_1 st_1 = {0};
  struct EventLog_R001186_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_33_1 > 25)
  {
    acc_1 = ((acc_1 + (metric_33_1 * 2)) + 5) & 127;
    aux_1 ^= metric_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_33_2 > 25)
  {
    acc_2 = ((acc_2 + (metric_33_2 * 2)) + 5) & 127;
    aux_2 ^= metric_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_62_1) & 63;
  aux_2 = (aux_2 + vector_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_29_1)
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

  switch (offset_29_2)
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
  int mask_98_1 = local_arr_1[aux_1 % 3];
  int mask_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_33_1 == metric_33_2);
  assert(vector_62_1 == vector_62_2);
  assert(offset_29_1 == offset_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_98_1 == mask_98_2);
}

int fn_R001186_8613_12(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001186_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_33 > 25)
  {
    acc = ((acc + (metric_33 * 2)) + 5) & 127;
    aux ^= metric_33 & 15;
  }
  else
  {
    acc = ((acc - metric_33) + 11) & 127;
    aux += 3;
  }
  int vector_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_62) & 63;
  acc ^= aux;
  int offset_29 = (aux + st.buffer[1]) & 3;
  switch (offset_29)
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
  int mask_98 = local_arr[aux % 3];
  acc = (acc + (mask_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001186_8613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st_1 = {0};
  struct SensorNode_R001186_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quotient_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_12_1) & 63;
  aux_2 = (aux_2 + quotient_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_28_1)
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

  switch (damping_28_2)
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

  int weight_88_1 = 0;
  int weight_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_88_1 = ((weight_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_88_2 = ((weight_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_88_1) & 127;
    acc_2 = (acc_2 + weight_88_2) & 127;
  }

  int stride_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_30_1 > 36)
  {
    acc_1 = ((acc_1 + (stride_30_1 * 2)) + 5) & 127;
    aux_1 ^= stride_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_30_2 > 36)
  {
    acc_2 = ((acc_2 + (stride_30_2 * 2)) + 5) & 127;
    aux_2 ^= stride_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_12_1 == quotient_12_2);
  assert(damping_28_1 == damping_28_2);
  assert(weight_88_1 == weight_88_2);
  assert(stride_30_1 == stride_30_2);
}

int fn_R001186_8613_13(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001186_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quotient_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_12) & 63;
  acc ^= aux;
  int damping_28 = (aux + st.buffer[1]) & 3;
  switch (damping_28)
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

  int weight_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_88 = ((weight_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_88) & 127;
  }

  int stride_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_30 > 36)
  {
    acc = ((acc + (stride_30 * 2)) + 5) & 127;
    aux ^= stride_30 & 15;
  }
  else
  {
    acc = ((acc - stride_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001186_8613_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st_1 = {0};
  struct MatrixBlock_R001186_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quotient_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_78_1 > 10)
  {
    acc_1 = ((acc_1 + (quotient_78_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_78_2 > 10)
  {
    acc_2 = ((acc_2 + (quotient_78_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_30_1)
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

  switch (window_30_2)
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
  int damping_55_1 = local_arr_1[aux_1 % 3];
  int damping_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_78_1 == quotient_78_2);
  assert(window_30_1 == window_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_55_1 == damping_55_2);
}

int fn_R001186_8613_14(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quotient_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_78 > 10)
  {
    acc = ((acc + (quotient_78 * 2)) + 5) & 127;
    aux ^= quotient_78 & 15;
  }
  else
  {
    acc = ((acc - quotient_78) + 11) & 127;
    aux += 3;
  }
  int window_30 = (aux + st.buffer[1]) & 3;
  switch (window_30)
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
  int damping_55 = local_arr[aux % 3];
  acc = (acc + (damping_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001186_8613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st_1 = {0};
  struct MatrixBlock_R001186_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int weight_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_76_1 > 43)
  {
    acc_1 = ((acc_1 + (weight_76_1 * 2)) + 5) & 127;
    aux_1 ^= weight_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_76_2 > 43)
  {
    acc_2 = ((acc_2 + (weight_76_2 * 2)) + 5) & 127;
    aux_2 ^= weight_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_13_1 = local_arr_1[aux_1 % 3];
  int mask_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_76_1 == weight_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_13_1 == mask_13_2);
}

int fn_R001186_8613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int weight_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_76 > 43)
  {
    acc = ((acc + (weight_76 * 2)) + 5) & 127;
    aux ^= weight_76 & 15;
  }
  else
  {
    acc = ((acc - weight_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_13 = local_arr[aux % 3];
  acc = (acc + (mask_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001186_8613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001186_8613_1 st_1 = {0};
  struct EventLog_R001186_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int margin_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_41_1)
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

  switch (margin_41_2)
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

  int weight_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_23_1) & 63;
  aux_2 = (aux_2 + weight_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_41_1 == margin_41_2);
  assert(weight_23_1 == weight_23_2);
}

int fn_R001186_8613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001186_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int margin_41 = (aux + st.buffer[1]) & 3;
  switch (margin_41)
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

  int weight_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001186_8613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st_1 = {0};
  struct MatrixBlock_R001186_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quantum_82_1 = 0;
  int quantum_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_82_1 = ((quantum_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_82_2 = ((quantum_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_82_1) & 127;
    acc_2 = (acc_2 + quantum_82_2) & 127;
  }

  int mask_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_55_1 > 47)
  {
    acc_1 = ((acc_1 + (mask_55_1 * 2)) + 5) & 127;
    aux_1 ^= mask_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_55_2 > 47)
  {
    acc_2 = ((acc_2 + (mask_55_2 * 2)) + 5) & 127;
    aux_2 ^= mask_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_82_1 == quantum_82_2);
  assert(mask_55_1 == mask_55_2);
}

int fn_R001186_8613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quantum_82 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_82 = ((quantum_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_82) & 127;
  }

  int mask_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_55 > 47)
  {
    acc = ((acc + (mask_55 * 2)) + 5) & 127;
    aux ^= mask_55 & 15;
  }
  else
  {
    acc = ((acc - mask_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001186_8613_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st_1 = {0};
  struct MatrixBlock_R001186_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tracker_68_1 = 0;
  int tracker_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_68_1 = ((tracker_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_68_2 = ((tracker_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_68_1) & 127;
    acc_2 = (acc_2 + tracker_68_2) & 127;
  }

  int tally_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_78_1 > 38)
  {
    acc_1 = ((acc_1 + (tally_78_1 * 2)) + 5) & 127;
    aux_1 ^= tally_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_78_2 > 38)
  {
    acc_2 = ((acc_2 + (tally_78_2 * 2)) + 5) & 127;
    aux_2 ^= tally_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_20_1)
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

  switch (sample_20_2)
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
  int sample_41_1 = local_arr_1[aux_1 % 3];
  int sample_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_41_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_68_1 == tracker_68_2);
  assert(tally_78_1 == tally_78_2);
  assert(sample_20_1 == sample_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_41_1 == sample_41_2);
}

int fn_R001186_8613_18(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001186_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tracker_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_68 = ((tracker_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_68) & 127;
  }

  int tally_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_78 > 38)
  {
    acc = ((acc + (tally_78 * 2)) + 5) & 127;
    aux ^= tally_78 & 15;
  }
  else
  {
    acc = ((acc - tally_78) + 11) & 127;
    aux += 3;
  }
  int sample_20 = (aux + st.buffer[1]) & 3;
  switch (sample_20)
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
  int sample_41 = local_arr[aux % 3];
  acc = (acc + (sample_41 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001186_8613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001186_8613_3 st_1 = {0};
  struct Transaction_R001186_8613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_27_1 = local_arr_1[aux_1 % 3];
  int window_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_27_2 * 2)) & 127;
  int threshold_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_99_1) & 63;
  aux_2 = (aux_2 + threshold_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_92_1)
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

  switch (phase_92_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
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

  assert(window_27_1 == window_27_2);
  assert(threshold_99_1 == threshold_99_2);
  assert(phase_92_1 == phase_92_2);
}

int fn_R001186_8613_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001186_8613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int window_27 = local_arr[aux % 3];
  acc = (acc + (window_27 * 2)) & 127;
  int threshold_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_99) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_92 = (aux + st.buffer[1]) & 3;
  switch (phase_92)
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

void main()
{
  int sec_r001186_0_1;
  int sec_r001186_0_2;
  int sec_r001186_1_1;
  int sec_r001186_1_2;
  int sec_r001186_2_1;
  int sec_r001186_2_2;
  int sec_r001186_3_1;
  int sec_r001186_3_2;
  int sec_r001186_4_1;
  int sec_r001186_4_2;
  int sec_r001186_5_1;
  int sec_r001186_5_2;
  int sec_r001186_6_1;
  int sec_r001186_6_2;
  int sec_r001186_7_1;
  int sec_r001186_7_2;
  int sec_r001186_8_1;
  int sec_r001186_8_2;
  int sec_r001186_9_1;
  int sec_r001186_9_2;
  int sec_r001186_10_1;
  int sec_r001186_10_2;
  int sec_r001186_11_1;
  int sec_r001186_11_2;
  int sec_r001186_12_1;
  int sec_r001186_12_2;
  int sec_r001186_13_1;
  int sec_r001186_13_2;
  int sec_r001186_14_1;
  int sec_r001186_14_2;
  int sec_r001186_15_1;
  int sec_r001186_15_2;
  int sec_r001186_16_1;
  int sec_r001186_16_2;
  int sec_r001186_17_1;
  int sec_r001186_17_2;
  int pub_r001186_0_1;
  int pub_r001186_0_2;
  int pub_r001186_1_1;
  int pub_r001186_1_2;
  int pub_r001186_2_1;
  int pub_r001186_2_2;
  int pub_r001186_3_1;
  int pub_r001186_3_2;
  int pub_r001186_4_1;
  int pub_r001186_4_2;
  int pub_r001186_5_1;
  int pub_r001186_5_2;
  int pub_r001186_6_1;
  int pub_r001186_6_2;
  int pub_r001186_7_1;
  int pub_r001186_7_2;
  int pub_r001186_8_1;
  int pub_r001186_8_2;
  int pub_r001186_9_1;
  int pub_r001186_9_2;
  int pub_r001186_10_1;
  int pub_r001186_10_2;
  int pub_r001186_11_1;
  int pub_r001186_11_2;
  int pub_r001186_12_1;
  int pub_r001186_12_2;
  int pub_r001186_13_1;
  int pub_r001186_13_2;
  int pub_r001186_14_1;
  int pub_r001186_14_2;
  int pub_r001186_15_1;
  int pub_r001186_15_2;
  int pub_r001186_16_1;
  int pub_r001186_16_2;
  int pub_r001186_17_1;
  int pub_r001186_17_2;
  int pub_r001186_18_1;
  int pub_r001186_18_2;
  int pub_r001186_19_1;
  int pub_r001186_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001186_0_1 >= (-100)) && (pub_r001186_0_1 <= 100));
  __CPROVER_assume((pub_r001186_0_2 >= (-100)) && (pub_r001186_0_2 <= 100));
  __CPROVER_assume((pub_r001186_1_1 >= (-100)) && (pub_r001186_1_1 <= 100));
  __CPROVER_assume((pub_r001186_1_2 >= (-100)) && (pub_r001186_1_2 <= 100));
  __CPROVER_assume((pub_r001186_2_1 >= (-100)) && (pub_r001186_2_1 <= 100));
  __CPROVER_assume((pub_r001186_2_2 >= (-100)) && (pub_r001186_2_2 <= 100));
  __CPROVER_assume((pub_r001186_3_1 >= (-100)) && (pub_r001186_3_1 <= 100));
  __CPROVER_assume((pub_r001186_3_2 >= (-100)) && (pub_r001186_3_2 <= 100));
  __CPROVER_assume((pub_r001186_4_1 >= (-100)) && (pub_r001186_4_1 <= 100));
  __CPROVER_assume((pub_r001186_4_2 >= (-100)) && (pub_r001186_4_2 <= 100));
  __CPROVER_assume((pub_r001186_5_1 >= (-100)) && (pub_r001186_5_1 <= 100));
  __CPROVER_assume((pub_r001186_5_2 >= (-100)) && (pub_r001186_5_2 <= 100));
  __CPROVER_assume((pub_r001186_6_1 >= (-100)) && (pub_r001186_6_1 <= 100));
  __CPROVER_assume((pub_r001186_6_2 >= (-100)) && (pub_r001186_6_2 <= 100));
  __CPROVER_assume((pub_r001186_7_1 >= (-100)) && (pub_r001186_7_1 <= 100));
  __CPROVER_assume((pub_r001186_7_2 >= (-100)) && (pub_r001186_7_2 <= 100));
  __CPROVER_assume((pub_r001186_8_1 >= (-100)) && (pub_r001186_8_1 <= 100));
  __CPROVER_assume((pub_r001186_8_2 >= (-100)) && (pub_r001186_8_2 <= 100));
  __CPROVER_assume((pub_r001186_9_1 >= (-100)) && (pub_r001186_9_1 <= 100));
  __CPROVER_assume((pub_r001186_9_2 >= (-100)) && (pub_r001186_9_2 <= 100));
  __CPROVER_assume((pub_r001186_10_1 >= (-100)) && (pub_r001186_10_1 <= 100));
  __CPROVER_assume((pub_r001186_10_2 >= (-100)) && (pub_r001186_10_2 <= 100));
  __CPROVER_assume((pub_r001186_11_1 >= (-100)) && (pub_r001186_11_1 <= 100));
  __CPROVER_assume((pub_r001186_11_2 >= (-100)) && (pub_r001186_11_2 <= 100));
  __CPROVER_assume((pub_r001186_12_1 >= (-100)) && (pub_r001186_12_1 <= 100));
  __CPROVER_assume((pub_r001186_12_2 >= (-100)) && (pub_r001186_12_2 <= 100));
  __CPROVER_assume((pub_r001186_13_1 >= (-100)) && (pub_r001186_13_1 <= 100));
  __CPROVER_assume((pub_r001186_13_2 >= (-100)) && (pub_r001186_13_2 <= 100));
  __CPROVER_assume((pub_r001186_14_1 >= (-100)) && (pub_r001186_14_1 <= 100));
  __CPROVER_assume((pub_r001186_14_2 >= (-100)) && (pub_r001186_14_2 <= 100));
  __CPROVER_assume((pub_r001186_15_1 >= (-100)) && (pub_r001186_15_1 <= 100));
  __CPROVER_assume((pub_r001186_15_2 >= (-100)) && (pub_r001186_15_2 <= 100));
  __CPROVER_assume((pub_r001186_16_1 >= (-100)) && (pub_r001186_16_1 <= 100));
  __CPROVER_assume((pub_r001186_16_2 >= (-100)) && (pub_r001186_16_2 <= 100));
  __CPROVER_assume((pub_r001186_17_1 >= (-100)) && (pub_r001186_17_1 <= 100));
  __CPROVER_assume((pub_r001186_17_2 >= (-100)) && (pub_r001186_17_2 <= 100));
  __CPROVER_assume((pub_r001186_18_1 >= (-100)) && (pub_r001186_18_1 <= 100));
  __CPROVER_assume((pub_r001186_18_2 >= (-100)) && (pub_r001186_18_2 <= 100));
  __CPROVER_assume((pub_r001186_19_1 >= (-100)) && (pub_r001186_19_1 <= 100));
  __CPROVER_assume((pub_r001186_19_2 >= (-100)) && (pub_r001186_19_2 <= 100));
  __CPROVER_assume((sec_r001186_0_1 >= 0) && (sec_r001186_0_1 <= 255));
  __CPROVER_assume((sec_r001186_0_2 >= 0) && (sec_r001186_0_2 <= 255));
  __CPROVER_assume((sec_r001186_1_1 >= 0) && (sec_r001186_1_1 <= 255));
  __CPROVER_assume((sec_r001186_1_2 >= 0) && (sec_r001186_1_2 <= 255));
  __CPROVER_assume((sec_r001186_2_1 >= 0) && (sec_r001186_2_1 <= 255));
  __CPROVER_assume((sec_r001186_2_2 >= 0) && (sec_r001186_2_2 <= 255));
  __CPROVER_assume((sec_r001186_3_1 >= 0) && (sec_r001186_3_1 <= 255));
  __CPROVER_assume((sec_r001186_3_2 >= 0) && (sec_r001186_3_2 <= 255));
  __CPROVER_assume((sec_r001186_4_1 >= 0) && (sec_r001186_4_1 <= 255));
  __CPROVER_assume((sec_r001186_4_2 >= 0) && (sec_r001186_4_2 <= 255));
  __CPROVER_assume((sec_r001186_5_1 >= 0) && (sec_r001186_5_1 <= 255));
  __CPROVER_assume((sec_r001186_5_2 >= 0) && (sec_r001186_5_2 <= 255));
  __CPROVER_assume((sec_r001186_6_1 >= 0) && (sec_r001186_6_1 <= 255));
  __CPROVER_assume((sec_r001186_6_2 >= 0) && (sec_r001186_6_2 <= 255));
  __CPROVER_assume((sec_r001186_7_1 >= 0) && (sec_r001186_7_1 <= 255));
  __CPROVER_assume((sec_r001186_7_2 >= 0) && (sec_r001186_7_2 <= 255));
  __CPROVER_assume((sec_r001186_8_1 >= 0) && (sec_r001186_8_1 <= 255));
  __CPROVER_assume((sec_r001186_8_2 >= 0) && (sec_r001186_8_2 <= 255));
  __CPROVER_assume((sec_r001186_9_1 >= 0) && (sec_r001186_9_1 <= 255));
  __CPROVER_assume((sec_r001186_9_2 >= 0) && (sec_r001186_9_2 <= 255));
  __CPROVER_assume((sec_r001186_10_1 >= 0) && (sec_r001186_10_1 <= 255));
  __CPROVER_assume((sec_r001186_10_2 >= 0) && (sec_r001186_10_2 <= 255));
  __CPROVER_assume((sec_r001186_11_1 >= 0) && (sec_r001186_11_1 <= 255));
  __CPROVER_assume((sec_r001186_11_2 >= 0) && (sec_r001186_11_2 <= 255));
  __CPROVER_assume((sec_r001186_12_1 >= 0) && (sec_r001186_12_1 <= 255));
  __CPROVER_assume((sec_r001186_12_2 >= 0) && (sec_r001186_12_2 <= 255));
  __CPROVER_assume((sec_r001186_13_1 >= 0) && (sec_r001186_13_1 <= 255));
  __CPROVER_assume((sec_r001186_13_2 >= 0) && (sec_r001186_13_2 <= 255));
  __CPROVER_assume((sec_r001186_14_1 >= 0) && (sec_r001186_14_1 <= 255));
  __CPROVER_assume((sec_r001186_14_2 >= 0) && (sec_r001186_14_2 <= 255));
  __CPROVER_assume((sec_r001186_15_1 >= 0) && (sec_r001186_15_1 <= 255));
  __CPROVER_assume((sec_r001186_15_2 >= 0) && (sec_r001186_15_2 <= 255));
  __CPROVER_assume((sec_r001186_16_1 >= 0) && (sec_r001186_16_1 <= 255));
  __CPROVER_assume((sec_r001186_16_2 >= 0) && (sec_r001186_16_2 <= 255));
  __CPROVER_assume((sec_r001186_17_1 >= 0) && (sec_r001186_17_1 <= 255));
  __CPROVER_assume((sec_r001186_17_2 >= 0) && (sec_r001186_17_2 <= 255));
  struct MatrixBlock_R001186_8613_0 st_var_0_1 = {0};
  struct MatrixBlock_R001186_8613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001186_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001186_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001186_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001186_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001186_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001186_0_2 + 7) & 15;
  struct EventLog_R001186_8613_1 st_var_1_1 = {0};
  struct EventLog_R001186_8613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001186_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001186_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001186_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001186_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001186_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001186_0_2 + 9) & 15;
  struct SensorNode_R001186_8613_2 st_var_2_1 = {0};
  struct SensorNode_R001186_8613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001186_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001186_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001186_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001186_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001186_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001186_0_2 + 11) & 15;
  struct Transaction_R001186_8613_3 st_var_3_1 = {0};
  struct Transaction_R001186_8613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001186_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001186_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001186_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001186_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001186_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001186_0_2 + 13) & 15;
  union ColorPixel_R001186_8613_0 u_var_1;
  union ColorPixel_R001186_8613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001186_8613_0(sec_r001186_0_1, sec_r001186_1_1);
  int helper_flow_0_2 = fn_R001186_8613_0(sec_r001186_0_2, sec_r001186_1_2);
  fn_R001186_8613_0_2(sec_r001186_0_1, sec_r001186_1_1, sec_r001186_0_2, sec_r001186_1_2);
  int helper_flow_1_1 = fn_R001186_8613_1(sec_r001186_1_1, sec_r001186_2_1);
  int helper_flow_1_2 = fn_R001186_8613_1(sec_r001186_1_2, sec_r001186_2_2);
  fn_R001186_8613_1_2(sec_r001186_1_1, sec_r001186_2_1, sec_r001186_1_2, sec_r001186_2_2);
  int helper_flow_2_1 = fn_R001186_8613_2(sec_r001186_2_1, sec_r001186_3_1);
  int helper_flow_2_2 = fn_R001186_8613_2(sec_r001186_2_2, sec_r001186_3_2);
  fn_R001186_8613_2_2(sec_r001186_2_1, sec_r001186_3_1, sec_r001186_2_2, sec_r001186_3_2);
  int helper_flow_3_1 = fn_R001186_8613_3(sec_r001186_3_1, sec_r001186_4_1);
  int helper_flow_3_2 = fn_R001186_8613_3(sec_r001186_3_2, sec_r001186_4_2);
  fn_R001186_8613_3_2(sec_r001186_3_1, sec_r001186_4_1, sec_r001186_3_2, sec_r001186_4_2);
  int helper_flow_4_1 = fn_R001186_8613_4(sec_r001186_4_1, pub_r001186_5_1, pub_r001186_6_1, pub_r001186_7_1);
  int helper_flow_4_2 = fn_R001186_8613_4(sec_r001186_4_2, pub_r001186_5_2, pub_r001186_6_2, pub_r001186_7_2);
  fn_R001186_8613_4_2(sec_r001186_4_1, pub_r001186_5_1, pub_r001186_6_1, pub_r001186_7_1, sec_r001186_4_2, pub_r001186_5_2, pub_r001186_6_2, pub_r001186_7_2);
  int helper_flow_5_1 = fn_R001186_8613_5(sec_r001186_5_1, sec_r001186_6_1, pub_r001186_7_1, pub_r001186_8_1, pub_r001186_9_1);
  int helper_flow_5_2 = fn_R001186_8613_5(sec_r001186_5_2, sec_r001186_6_2, pub_r001186_7_2, pub_r001186_8_2, pub_r001186_9_2);
  fn_R001186_8613_5_2(sec_r001186_5_1, sec_r001186_6_1, pub_r001186_7_1, pub_r001186_8_1, pub_r001186_9_1, sec_r001186_5_2, sec_r001186_6_2, pub_r001186_7_2, pub_r001186_8_2, pub_r001186_9_2);
  int helper_flow_6_1 = fn_R001186_8613_6(sec_r001186_6_1, pub_r001186_7_1, pub_r001186_8_1, pub_r001186_9_1);
  int helper_flow_6_2 = fn_R001186_8613_6(sec_r001186_6_2, pub_r001186_7_2, pub_r001186_8_2, pub_r001186_9_2);
  fn_R001186_8613_6_2(sec_r001186_6_1, pub_r001186_7_1, pub_r001186_8_1, pub_r001186_9_1, sec_r001186_6_2, pub_r001186_7_2, pub_r001186_8_2, pub_r001186_9_2);
  int helper_flow_7_1 = fn_R001186_8613_7(sec_r001186_7_1, pub_r001186_8_1, pub_r001186_9_1, pub_r001186_10_1);
  int helper_flow_7_2 = fn_R001186_8613_7(sec_r001186_7_2, pub_r001186_8_2, pub_r001186_9_2, pub_r001186_10_2);
  fn_R001186_8613_7_2(sec_r001186_7_1, pub_r001186_8_1, pub_r001186_9_1, pub_r001186_10_1, sec_r001186_7_2, pub_r001186_8_2, pub_r001186_9_2, pub_r001186_10_2);
  int helper_flow_8_1 = fn_R001186_8613_8(sec_r001186_8_1, pub_r001186_9_1, pub_r001186_10_1);
  int helper_flow_8_2 = fn_R001186_8613_8(sec_r001186_8_2, pub_r001186_9_2, pub_r001186_10_2);
  fn_R001186_8613_8_2(sec_r001186_8_1, pub_r001186_9_1, pub_r001186_10_1, sec_r001186_8_2, pub_r001186_9_2, pub_r001186_10_2);
  int helper_flow_9_1 = fn_R001186_8613_9(sec_r001186_9_1, sec_r001186_10_1, pub_r001186_11_1, pub_r001186_12_1);
  int helper_flow_9_2 = fn_R001186_8613_9(sec_r001186_9_2, sec_r001186_10_2, pub_r001186_11_2, pub_r001186_12_2);
  fn_R001186_8613_9_2(sec_r001186_9_1, sec_r001186_10_1, pub_r001186_11_1, pub_r001186_12_1, sec_r001186_9_2, sec_r001186_10_2, pub_r001186_11_2, pub_r001186_12_2);
  int stage_v_0_1 = ((helper_flow_4_1 + (pub_r001186_3_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_4_2 + (pub_r001186_3_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((helper_flow_3_1 + (pub_r001186_5_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((helper_flow_3_2 + (pub_r001186_5_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001186_0_1 + (pub_r001186_6_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001186_0_2 + (pub_r001186_6_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((pub_r001186_10_1 * 2) + 5) & 63;
  int stage_v_3_2 = ((pub_r001186_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001186_11_1 + (pub_r001186_3_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((sec_r001186_11_2 + (pub_r001186_3_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((sec_r001186_1_1 + (pub_r001186_16_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001186_1_2 + (pub_r001186_16_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001186_14_1 * 2) + 42) & 63;
  int stage_v_6_2 = ((pub_r001186_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((helper_flow_1_1 + (pub_r001186_9_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((helper_flow_1_2 + (pub_r001186_9_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((sec_r001186_6_1 + (pub_r001186_13_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001186_6_2 + (pub_r001186_13_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001186_1_1 * 2) + 16) & 63;
  int stage_v_9_2 = ((pub_r001186_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001186_15_1 * 2) + 28) & 63;
  int stage_v_10_2 = ((pub_r001186_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001186_3_1 * 2) + 18) & 63;
  int stage_v_11_2 = ((pub_r001186_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((stage_v_7_1 + (pub_r001186_6_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((stage_v_7_2 + (pub_r001186_6_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((pub_r001186_11_1 * 2) + 14) & 63;
  int stage_v_13_2 = ((pub_r001186_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001186_18_1 * 2) + 10) & 63;
  int stage_v_14_2 = ((pub_r001186_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001186_5_1 * 2) + 49) & 63;
  int stage_v_15_2 = ((pub_r001186_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001186_3_1 * 2) + 31) & 63;
  int stage_v_16_2 = ((pub_r001186_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((helper_flow_5_1 + (pub_r001186_9_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((helper_flow_5_2 + (pub_r001186_9_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((sec_r001186_16_1 + (pub_r001186_19_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001186_16_2 + (pub_r001186_19_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001186_3_1 * 2) + 48) & 63;
  int stage_v_19_2 = ((pub_r001186_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((stage_v_12_1 + (pub_r001186_16_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_12_2 + (pub_r001186_16_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_5_1 + (pub_r001186_8_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_5_2 + (pub_r001186_8_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((stage_v_4_1 + (pub_r001186_16_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_4_2 + (pub_r001186_16_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((stage_v_0_1 + (pub_r001186_11_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((stage_v_0_2 + (pub_r001186_11_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((stage_v_21_1 + (pub_r001186_6_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_21_2 + (pub_r001186_6_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001186_1_1 * 2) + 26) & 63;
  int stage_v_25_2 = ((pub_r001186_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((sec_r001186_13_1 + (pub_r001186_10_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001186_13_2 + (pub_r001186_10_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((pub_r001186_7_1 * 2) + 24) & 63;
  int stage_v_27_2 = ((pub_r001186_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001186_7_1 * 2) + 20) & 63;
  int stage_v_28_2 = ((pub_r001186_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001186_14_1 + (pub_r001186_0_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001186_14_2 + (pub_r001186_0_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((stage_v_4_1 + (pub_r001186_2_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_4_2 + (pub_r001186_2_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001186_2_1 * 2) + 12) & 63;
  int stage_v_31_2 = ((pub_r001186_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((sec_r001186_10_1 + (pub_r001186_12_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((sec_r001186_10_2 + (pub_r001186_12_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((stage_v_12_1 + (pub_r001186_2_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_12_2 + (pub_r001186_2_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((sec_r001186_4_1 + (pub_r001186_11_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((sec_r001186_4_2 + (pub_r001186_11_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001186_16_1 + (pub_r001186_19_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001186_16_2 + (pub_r001186_19_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((stage_v_29_1 + (pub_r001186_2_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_29_2 + (pub_r001186_2_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((helper_flow_3_1 + (pub_r001186_18_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((helper_flow_3_2 + (pub_r001186_18_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((sec_r001186_3_1 + (pub_r001186_6_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001186_3_2 + (pub_r001186_6_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((sec_r001186_4_1 + (pub_r001186_0_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001186_4_2 + (pub_r001186_0_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((helper_flow_6_1 + (pub_r001186_0_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((helper_flow_6_2 + (pub_r001186_0_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001186_0_1 * 2) + 39) & 63;
  int stage_v_41_2 = ((pub_r001186_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((stage_v_18_1 + (pub_r001186_10_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_18_2 + (pub_r001186_10_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((helper_flow_2_1 + (pub_r001186_4_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((helper_flow_2_2 + (pub_r001186_4_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((pub_r001186_8_1 * 2) + 5) & 63;
  int stage_v_44_2 = ((pub_r001186_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((sec_r001186_16_1 + (pub_r001186_8_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001186_16_2 + (pub_r001186_8_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_8_1 + (pub_r001186_19_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_8_2 + (pub_r001186_19_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((stage_v_7_1 + (pub_r001186_6_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_7_2 + (pub_r001186_6_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((helper_flow_7_1 + (pub_r001186_7_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((helper_flow_7_2 + (pub_r001186_7_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((helper_flow_1_1 + (pub_r001186_7_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((helper_flow_1_2 + (pub_r001186_7_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((stage_v_12_1 + (pub_r001186_17_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_12_2 + (pub_r001186_17_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((pub_r001186_12_1 * 2) + 26) & 63;
  int stage_v_51_2 = ((pub_r001186_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001186_9_1 * 2) + 36) & 63;
  int stage_v_52_2 = ((pub_r001186_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((stage_v_2_1 + (pub_r001186_15_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_2_2 + (pub_r001186_15_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((sec_r001186_4_1 + (pub_r001186_5_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001186_4_2 + (pub_r001186_5_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((helper_flow_8_1 + (pub_r001186_7_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((helper_flow_8_2 + (pub_r001186_7_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001186_8_1 * 2) + 48) & 63;
  int stage_v_56_2 = ((pub_r001186_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((helper_flow_0_1 + (pub_r001186_8_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((helper_flow_0_2 + (pub_r001186_8_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001186_11_1 * 2) + 32) & 63;
  int stage_v_58_2 = ((pub_r001186_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001186_18_1 * 2) + 11) & 63;
  int stage_v_59_2 = ((pub_r001186_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((stage_v_18_1 + (pub_r001186_3_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_18_2 + (pub_r001186_3_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((sec_r001186_7_1 + (pub_r001186_8_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((sec_r001186_7_2 + (pub_r001186_8_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_39_1 + (pub_r001186_18_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_39_2 + (pub_r001186_18_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_12_1 + (pub_r001186_13_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_12_2 + (pub_r001186_13_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_33_1 + (pub_r001186_1_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_33_2 + (pub_r001186_1_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_54_1 + (pub_r001186_12_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_54_2 + (pub_r001186_12_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((stage_v_50_1 + (pub_r001186_5_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_50_2 + (pub_r001186_5_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((pub_r001186_10_1 * 2) + 29) & 63;
  int stage_v_67_2 = ((pub_r001186_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((stage_v_30_1 + (pub_r001186_13_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_30_2 + (pub_r001186_13_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((stage_v_18_1 + (pub_r001186_2_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_18_2 + (pub_r001186_2_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((pub_r001186_1_1 * 2) + 26) & 63;
  int stage_v_70_2 = ((pub_r001186_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001186_0_1 * 2) + 29) & 63;
  int stage_v_71_2 = ((pub_r001186_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001186_12_1 * 2) + 34) & 63;
  int stage_v_72_2 = ((pub_r001186_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((sec_r001186_13_1 + (pub_r001186_4_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((sec_r001186_13_2 + (pub_r001186_4_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_47_1 + (pub_r001186_7_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_47_2 + (pub_r001186_7_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((stage_v_17_1 + (pub_r001186_4_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_17_2 + (pub_r001186_4_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((pub_r001186_19_1 * 2) + 29) & 63;
  int stage_v_76_2 = ((pub_r001186_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001186_16_1 * 2) + 33) & 63;
  int stage_v_77_2 = ((pub_r001186_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((sec_r001186_12_1 + (pub_r001186_19_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((sec_r001186_12_2 + (pub_r001186_19_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_34_1 + (pub_r001186_1_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_34_2 + (pub_r001186_1_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((stage_v_1_1 + (pub_r001186_0_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_1_2 + (pub_r001186_0_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_65_1 + (pub_r001186_9_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_65_2 + (pub_r001186_9_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((stage_v_69_1 + (pub_r001186_2_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_69_2 + (pub_r001186_2_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((sec_r001186_8_1 + (pub_r001186_19_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((sec_r001186_8_2 + (pub_r001186_19_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((helper_flow_0_1 + (pub_r001186_17_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((helper_flow_0_2 + (pub_r001186_17_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((pub_r001186_14_1 * 2) + 41) & 63;
  int stage_v_85_2 = ((pub_r001186_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((stage_v_0_1 + (pub_r001186_9_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_0_2 + (pub_r001186_9_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_46_1 + (pub_r001186_14_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_46_2 + (pub_r001186_14_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_83_1 + (pub_r001186_3_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_83_2 + (pub_r001186_3_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((pub_r001186_9_1 * 2) + 24) & 63;
  int stage_v_89_2 = ((pub_r001186_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001186_7_1 * 2) + 19) & 63;
  int stage_v_90_2 = ((pub_r001186_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((sec_r001186_10_1 + (pub_r001186_18_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((sec_r001186_10_2 + (pub_r001186_18_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_12_1 + (pub_r001186_12_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_12_2 + (pub_r001186_12_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((pub_r001186_16_1 * 2) + 9) & 63;
  int stage_v_93_2 = ((pub_r001186_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001186_2_1 * 2) + 45) & 63;
  int stage_v_94_2 = ((pub_r001186_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001186_19_1 * 2) + 17) & 63;
  int stage_v_95_2 = ((pub_r001186_19_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((stage_v_92_1 + (pub_r001186_13_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_92_2 + (pub_r001186_13_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((helper_flow_6_1 + (pub_r001186_19_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((helper_flow_6_2 + (pub_r001186_19_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_35_1 + (pub_r001186_13_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_35_2 + (pub_r001186_13_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_86_1 + (pub_r001186_3_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_86_2 + (pub_r001186_3_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_48_1 + (pub_r001186_19_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_48_2 + (pub_r001186_19_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((helper_flow_6_1 + (pub_r001186_11_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((helper_flow_6_2 + (pub_r001186_11_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001186_19_1 * 2) + 25) & 63;
  int stage_v_102_2 = ((pub_r001186_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001186_10_1 * 2) + 48) & 63;
  int stage_v_103_2 = ((pub_r001186_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001186_3_1 * 2) + 22) & 63;
  int stage_v_104_2 = ((pub_r001186_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_34_1 + (pub_r001186_19_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_34_2 + (pub_r001186_19_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((pub_r001186_9_1 * 2) + 29) & 63;
  int stage_v_106_2 = ((pub_r001186_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((stage_v_92_1 + (pub_r001186_17_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_92_2 + (pub_r001186_17_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_43_1 + (pub_r001186_13_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_43_2 + (pub_r001186_13_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((pub_r001186_0_1 * 2) + 45) & 63;
  int stage_v_109_2 = ((pub_r001186_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001186_0_1 * 2) + 44) & 63;
  int stage_v_110_2 = ((pub_r001186_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001186_6_1 * 2) + 26) & 63;
  int stage_v_111_2 = ((pub_r001186_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((sec_r001186_3_1 + (pub_r001186_17_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((sec_r001186_3_2 + (pub_r001186_17_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((stage_v_40_1 + (pub_r001186_17_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_40_2 + (pub_r001186_17_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((stage_v_34_1 + (pub_r001186_1_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_34_2 + (pub_r001186_1_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((pub_r001186_15_1 * 2) + 7) & 63;
  int stage_v_115_2 = ((pub_r001186_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001186_15_1 * 2) + 33) & 63;
  int stage_v_116_2 = ((pub_r001186_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((sec_r001186_7_1 + (pub_r001186_13_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((sec_r001186_7_2 + (pub_r001186_13_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_100_1 + (pub_r001186_18_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_100_2 + (pub_r001186_18_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((pub_r001186_11_1 * 2) + 18) & 63;
  int stage_v_119_2 = ((pub_r001186_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_88_1 + (pub_r001186_14_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_88_2 + (pub_r001186_14_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001186_8_1 * 2) + 23) & 63;
  int stage_v_121_2 = ((pub_r001186_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((sec_r001186_14_1 + (pub_r001186_2_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((sec_r001186_14_2 + (pub_r001186_2_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((pub_r001186_8_1 * 2) + 21) & 63;
  int stage_v_123_2 = ((pub_r001186_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((stage_v_0_1 + (pub_r001186_8_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((stage_v_0_2 + (pub_r001186_8_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((stage_v_53_1 + (pub_r001186_10_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_53_2 + (pub_r001186_10_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((pub_r001186_10_1 * 2) + 10) & 63;
  int stage_v_126_2 = ((pub_r001186_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_64_1 + (pub_r001186_1_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_64_2 + (pub_r001186_1_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((pub_r001186_16_1 * 2) + 25) & 63;
  int stage_v_128_2 = ((pub_r001186_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001186_10_1 * 2) + 33) & 63;
  int stage_v_129_2 = ((pub_r001186_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((helper_flow_3_1 + (pub_r001186_6_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((helper_flow_3_2 + (pub_r001186_6_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001186_6_1 * 2) + 42) & 63;
  int stage_v_131_2 = ((pub_r001186_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_81_1 + (pub_r001186_3_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_81_2 + (pub_r001186_3_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001186_2_1 * 2) + 26) & 63;
  int stage_v_133_2 = ((pub_r001186_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_91_1 + (pub_r001186_16_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_91_2 + (pub_r001186_16_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_46_1 + (pub_r001186_16_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_46_2 + (pub_r001186_16_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((pub_r001186_16_1 * 2) + 13) & 63;
  int stage_v_136_2 = ((pub_r001186_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001186_2_1 * 2) + 37) & 63;
  int stage_v_137_2 = ((pub_r001186_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_5_1 + (pub_r001186_17_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_5_2 + (pub_r001186_17_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((helper_flow_0_1 + (pub_r001186_0_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((helper_flow_0_2 + (pub_r001186_0_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_50_1 + (pub_r001186_9_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_50_2 + (pub_r001186_9_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((sec_r001186_9_1 + (pub_r001186_9_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((sec_r001186_9_2 + (pub_r001186_9_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((pub_r001186_15_1 * 2) + 46) & 63;
  int stage_v_142_2 = ((pub_r001186_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_63_1 + (pub_r001186_11_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_63_2 + (pub_r001186_11_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001186_11_1 * 2) + 22) & 63;
  int stage_v_144_2 = ((pub_r001186_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001186_19_1 * 2) + 15) & 63;
  int stage_v_145_2 = ((pub_r001186_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001186_4_1 * 2) + 26) & 63;
  int stage_v_146_2 = ((pub_r001186_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001186_0_1 * 2) + 9) & 63;
  int stage_v_147_2 = ((pub_r001186_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((stage_v_40_1 + (pub_r001186_6_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_40_2 + (pub_r001186_6_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_64_1 + (pub_r001186_12_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_64_2 + (pub_r001186_12_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((pub_r001186_10_1 * 2) + 20) & 63;
  int stage_v_150_2 = ((pub_r001186_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_99_1 + (pub_r001186_0_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_99_2 + (pub_r001186_0_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_48_1 + (pub_r001186_18_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_48_2 + (pub_r001186_18_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001186_9_1 * 2) + 41) & 63;
  int stage_v_153_2 = ((pub_r001186_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001186_19_1 * 2) + 26) & 63;
  int stage_v_154_2 = ((pub_r001186_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_29_1 + (pub_r001186_3_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_29_2 + (pub_r001186_3_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001186_13_1 * 2) + 5) & 63;
  int stage_v_156_2 = ((pub_r001186_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001186_11_1 * 2) + 20) & 63;
  int stage_v_157_2 = ((pub_r001186_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_48_1 + (pub_r001186_4_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_48_2 + (pub_r001186_4_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_100_1 + (pub_r001186_2_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_100_2 + (pub_r001186_2_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((helper_flow_3_1 + (pub_r001186_16_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((helper_flow_3_2 + (pub_r001186_16_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001186_2_1 * 2) + 27) & 63;
  int stage_v_161_2 = ((pub_r001186_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_63_1 + (pub_r001186_9_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_63_2 + (pub_r001186_9_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((sec_r001186_6_1 + (pub_r001186_6_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((sec_r001186_6_2 + (pub_r001186_6_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_158_1 + (pub_r001186_3_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_158_2 + (pub_r001186_3_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((pub_r001186_9_1 * 2) + 50) & 63;
  int stage_v_165_2 = ((pub_r001186_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001186_2_1 * 2) + 9) & 63;
  int stage_v_166_2 = ((pub_r001186_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_63_1 + (pub_r001186_18_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_63_2 + (pub_r001186_18_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_42_1 + (pub_r001186_9_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_42_2 + (pub_r001186_9_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((pub_r001186_17_1 * 2) + 9) & 63;
  int stage_v_169_2 = ((pub_r001186_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_98_1 + (pub_r001186_10_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_98_2 + (pub_r001186_10_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((pub_r001186_8_1 * 2) + 28) & 63;
  int stage_v_171_2 = ((pub_r001186_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_148_1 + (pub_r001186_14_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_148_2 + (pub_r001186_14_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_73_1 + (pub_r001186_18_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_73_2 + (pub_r001186_18_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((pub_r001186_13_1 * 2) + 35) & 63;
  int stage_v_174_2 = ((pub_r001186_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_134_1 + (pub_r001186_9_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_134_2 + (pub_r001186_9_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001186_15_1 * 2) + 11) & 63;
  int stage_v_176_2 = ((pub_r001186_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_29_1 + (pub_r001186_2_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_29_2 + (pub_r001186_2_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((pub_r001186_1_1 * 2) + 7) & 63;
  int stage_v_178_2 = ((pub_r001186_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001186_16_1 * 2) + 50) & 63;
  int stage_v_179_2 = ((pub_r001186_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001186_10_1 * 2) + 9) & 63;
  int stage_v_180_2 = ((pub_r001186_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_152_1 + (pub_r001186_13_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_152_2 + (pub_r001186_13_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((sec_r001186_7_1 + (pub_r001186_18_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((sec_r001186_7_2 + (pub_r001186_18_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_8_1 + (pub_r001186_0_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_8_2 + (pub_r001186_0_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_42_1 + (pub_r001186_5_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_42_2 + (pub_r001186_5_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001186_12_1 * 2) + 23) & 63;
  int stage_v_185_2 = ((pub_r001186_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_98_1 + (pub_r001186_15_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_98_2 + (pub_r001186_15_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_114_1 + (pub_r001186_16_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_114_2 + (pub_r001186_16_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((stage_v_170_1 + (pub_r001186_17_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_170_2 + (pub_r001186_17_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((pub_r001186_17_1 * 2) + 18) & 63;
  int stage_v_189_2 = ((pub_r001186_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001186_4_1 * 2) + 49) & 63;
  int stage_v_190_2 = ((pub_r001186_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001186_9_1 * 2) + 25) & 63;
  int stage_v_191_2 = ((pub_r001186_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_162_1 + (pub_r001186_2_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_162_2 + (pub_r001186_2_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001186_19_1 * 2) + 48) & 63;
  int stage_v_193_2 = ((pub_r001186_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_177_1 + (pub_r001186_11_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_177_2 + (pub_r001186_11_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((pub_r001186_18_1 * 2) + 24) & 63;
  int stage_v_195_2 = ((pub_r001186_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_138_1 + (pub_r001186_12_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_138_2 + (pub_r001186_12_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((sec_r001186_5_1 + (pub_r001186_18_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((sec_r001186_5_2 + (pub_r001186_18_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_50_1 + (pub_r001186_19_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_50_2 + (pub_r001186_19_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((helper_flow_9_1 + (pub_r001186_15_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((helper_flow_9_2 + (pub_r001186_15_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001186_19_1 * 2) + 10) & 63;
  int stage_v_200_2 = ((pub_r001186_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_164_1 + (pub_r001186_19_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_164_2 + (pub_r001186_19_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((pub_r001186_19_1 * 2) + 46) & 63;
  int stage_v_202_2 = ((pub_r001186_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((stage_v_78_1 + (pub_r001186_0_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_78_2 + (pub_r001186_0_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((pub_r001186_13_1 * 2) + 41) & 63;
  int stage_v_204_2 = ((pub_r001186_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001186_2_1 * 2) + 15) & 63;
  int stage_v_205_2 = ((pub_r001186_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001186_7_1 * 2) + 13) & 63;
  int stage_v_206_2 = ((pub_r001186_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((helper_flow_9_1 + (pub_r001186_0_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((helper_flow_9_2 + (pub_r001186_0_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((sec_r001186_4_1 + (pub_r001186_19_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((sec_r001186_4_2 + (pub_r001186_19_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_188_1 + (pub_r001186_15_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_188_2 + (pub_r001186_15_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((pub_r001186_12_1 * 2) + 48) & 63;
  int stage_v_210_2 = ((pub_r001186_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001186_7_1 * 2) + 16) & 63;
  int stage_v_211_2 = ((pub_r001186_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_120_1 + (pub_r001186_12_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_120_2 + (pub_r001186_12_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((pub_r001186_16_1 * 2) + 34) & 63;
  int stage_v_213_2 = ((pub_r001186_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_30_1 + (pub_r001186_2_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_30_2 + (pub_r001186_2_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001186_8_1 * 2) + 45) & 63;
  int stage_v_215_2 = ((pub_r001186_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_192_1 + (pub_r001186_10_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_192_2 + (pub_r001186_10_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_158_1 + (pub_r001186_13_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_158_2 + (pub_r001186_13_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_184_1 + (pub_r001186_14_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_184_2 + (pub_r001186_14_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((pub_r001186_10_1 * 2) + 26) & 63;
  int stage_v_219_2 = ((pub_r001186_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001186_14_1 * 2) + 44) & 63;
  int stage_v_220_2 = ((pub_r001186_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((sec_r001186_6_1 + (pub_r001186_11_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((sec_r001186_6_2 + (pub_r001186_11_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_199_1 + (pub_r001186_7_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_199_2 + (pub_r001186_7_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_170_1 + (pub_r001186_8_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_170_2 + (pub_r001186_8_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((pub_r001186_11_1 * 2) + 46) & 63;
  int stage_v_224_2 = ((pub_r001186_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001186_6_1 * 2) + 10) & 63;
  int stage_v_225_2 = ((pub_r001186_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((stage_v_173_1 + (pub_r001186_16_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_173_2 + (pub_r001186_16_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((stage_v_196_1 + (pub_r001186_14_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_196_2 + (pub_r001186_14_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((stage_v_68_1 + (pub_r001186_16_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_68_2 + (pub_r001186_16_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((stage_v_42_1 + (pub_r001186_18_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((stage_v_42_2 + (pub_r001186_18_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((stage_v_78_1 + (pub_r001186_17_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_78_2 + (pub_r001186_17_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_86_1 + (pub_r001186_15_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_86_2 + (pub_r001186_15_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((pub_r001186_19_1 * 2) + 34) & 63;
  int stage_v_232_2 = ((pub_r001186_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((stage_v_160_1 + (pub_r001186_9_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_160_2 + (pub_r001186_9_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((pub_r001186_13_1 * 2) + 48) & 63;
  int stage_v_234_2 = ((pub_r001186_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((sec_r001186_2_1 + (pub_r001186_16_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((sec_r001186_2_2 + (pub_r001186_16_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((stage_v_83_1 + (pub_r001186_8_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((stage_v_83_2 + (pub_r001186_8_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_237_1 = ((stage_v_236_1 + (pub_r001186_17_1 * 2)) + 716) & 127;
  int stage_v_237_2 = ((stage_v_236_2 + (pub_r001186_17_2 * 2)) + 716) & 127;
  if (stage_v_237_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_237_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_237_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_237_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_238_1 = ((pub_r001186_9_1 * 2) + 13) & 63;
  int stage_v_238_2 = ((pub_r001186_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((stage_v_100_1 + (pub_r001186_6_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((stage_v_100_2 + (pub_r001186_6_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((stage_v_105_1 + (pub_r001186_15_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((stage_v_105_2 + (pub_r001186_15_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((sec_r001186_4_1 + (pub_r001186_19_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((sec_r001186_4_2 + (pub_r001186_19_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((stage_v_75_1 + (pub_r001186_9_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((stage_v_75_2 + (pub_r001186_9_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((pub_r001186_16_1 * 2) + 39) & 63;
  int stage_v_243_2 = ((pub_r001186_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((stage_v_184_1 + (pub_r001186_0_1 * 2)) + 737) & 127;
  int stage_v_244_2 = ((stage_v_184_2 + (pub_r001186_0_2 * 2)) + 737) & 127;
  if (stage_v_244_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_244_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_244_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_244_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_245_1 = ((sec_r001186_13_1 + (pub_r001186_2_1 * 2)) + 740) & 127;
  int stage_v_245_2 = ((sec_r001186_13_2 + (pub_r001186_2_2 * 2)) + 740) & 127;
  if (stage_v_245_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_245_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_245_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_245_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_245_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_245_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_245_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_245_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_246_1 = ((stage_v_201_1 + (pub_r001186_19_1 * 2)) + 743) & 127;
  int stage_v_246_2 = ((stage_v_201_2 + (pub_r001186_19_2 * 2)) + 743) & 127;
  if (stage_v_246_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_246_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_246_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_246_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_247_1 = ((stage_v_54_1 + (pub_r001186_17_1 * 2)) + 746) & 127;
  int stage_v_247_2 = ((stage_v_54_2 + (pub_r001186_17_2 * 2)) + 746) & 127;
  if (stage_v_247_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_247_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_247_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_247_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001186_2_1 != sec_r001186_2_2);
  __CPROVER_assume(pub_r001186_12_1 == pub_r001186_12_2);
  __CPROVER_assume(pub_r001186_18_1 == pub_r001186_18_2);
  __CPROVER_assume(pub_r001186_14_1 == pub_r001186_14_2);
  __CPROVER_assume(sec_r001186_8_1 != sec_r001186_8_2);
  __CPROVER_assume(pub_r001186_8_1 == pub_r001186_8_2);
  __CPROVER_assume(pub_r001186_6_1 == pub_r001186_6_2);
  __CPROVER_assume(pub_r001186_0_1 == pub_r001186_0_2);
  __CPROVER_assume(sec_r001186_11_1 != sec_r001186_11_2);
  __CPROVER_assume(sec_r001186_5_1 != sec_r001186_5_2);
  __CPROVER_assume(pub_r001186_4_1 == pub_r001186_4_2);
  __CPROVER_assume(pub_r001186_9_1 == pub_r001186_9_2);
  __CPROVER_assume(pub_r001186_1_1 == pub_r001186_1_2);
  __CPROVER_assume(pub_r001186_13_1 == pub_r001186_13_2);
  __CPROVER_assume(sec_r001186_1_1 != sec_r001186_1_2);
  __CPROVER_assume(pub_r001186_19_1 == pub_r001186_19_2);
  __CPROVER_assume(sec_r001186_7_1 != sec_r001186_7_2);
  __CPROVER_assume(sec_r001186_15_1 != sec_r001186_15_2);
  __CPROVER_assume(pub_r001186_3_1 == pub_r001186_3_2);
  __CPROVER_assume(pub_r001186_17_1 == pub_r001186_17_2);
  __CPROVER_assume(sec_r001186_17_1 != sec_r001186_17_2);
  __CPROVER_assume(sec_r001186_6_1 != sec_r001186_6_2);
  __CPROVER_assume(sec_r001186_12_1 != sec_r001186_12_2);
  __CPROVER_assume(sec_r001186_13_1 != sec_r001186_13_2);
  __CPROVER_assume(pub_r001186_10_1 == pub_r001186_10_2);
  __CPROVER_assume(pub_r001186_5_1 == pub_r001186_5_2);
  __CPROVER_assume(pub_r001186_15_1 == pub_r001186_15_2);
  __CPROVER_assume(sec_r001186_10_1 != sec_r001186_10_2);
  __CPROVER_assume(pub_r001186_7_1 == pub_r001186_7_2);
  __CPROVER_assume(sec_r001186_14_1 != sec_r001186_14_2);
  __CPROVER_assume(pub_r001186_2_1 == pub_r001186_2_2);
  __CPROVER_assume(sec_r001186_16_1 != sec_r001186_16_2);
  __CPROVER_assume(sec_r001186_0_1 != sec_r001186_0_2);
  __CPROVER_assume(pub_r001186_11_1 == pub_r001186_11_2);
  __CPROVER_assume(sec_r001186_3_1 != sec_r001186_3_2);
  __CPROVER_assume(sec_r001186_9_1 != sec_r001186_9_2);
  __CPROVER_assume(pub_r001186_16_1 == pub_r001186_16_2);
  __CPROVER_assume(sec_r001186_4_1 != sec_r001186_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.rate == st_var_3_2.rate);
  assert(st_var_3_1.balance == st_var_3_2.balance);
  assert(st_var_3_1.fee == st_var_3_2.fee);
  assert(st_var_3_1.auth_code == st_var_3_2.auth_code);
  assert(st_var_3_1.status == st_var_3_2.status);
  assert(st_var_3_1.account_id == st_var_3_2.account_id);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
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
}


