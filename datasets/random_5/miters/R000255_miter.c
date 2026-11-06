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
struct CipherContext_R000255_5513_0
{
  unsigned char nonce;
  short counter;
  int round_key;
  int flags;
  unsigned char tag;
  short iv;
  int buffer[3];
};
struct SensorNode_R000255_5513_1
{
  int reading;
  int threshold;
  short status;
  unsigned char gain;
  int calib;
  int buffer[3];
};
struct Transaction_R000255_5513_2
{
  int rate;
  short fee;
  unsigned char auth_code;
  unsigned char account_id;
  int buffer[3];
};
struct StreamBuffer_R000255_5513_3
{
  int tail;
  int checksum;
  int capacity;
  int buffer[3];
};
union ColorPixel_R000255_5513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000255_5513_1
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
void fn_R000255_5513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st_1 = {0};
  struct Transaction_R000255_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_70_1) & 63;
  aux_2 = (aux_2 + anchor_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_95_1 > 39)
  {
    acc_1 = ((acc_1 + (index_reg_95_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_95_2 > 39)
  {
    acc_2 = ((acc_2 + (index_reg_95_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_95_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_72_1 = local_arr_1[aux_1 % 3];
  int damping_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_70_1 == anchor_70_2);
  assert(index_reg_95_1 == index_reg_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_72_1 == damping_72_2);
}

int fn_R000255_5513_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_70) & 63;
  acc ^= aux;
  int index_reg_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_95 > 39)
  {
    acc = ((acc + (index_reg_95 * 2)) + 5) & 127;
    aux ^= index_reg_95 & 15;
  }
  else
  {
    acc = ((acc - index_reg_95) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_72 = local_arr[aux % 3];
  acc = (acc + (damping_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000255_5513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st_1 = {0};
  struct CipherContext_R000255_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int delta_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_12_1 > 31)
  {
    acc_1 = ((acc_1 + (delta_12_1 * 2)) + 5) & 127;
    aux_1 ^= delta_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_12_2 > 31)
  {
    acc_2 = ((acc_2 + (delta_12_2 * 2)) + 5) & 127;
    aux_2 ^= delta_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_78_1)
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

  switch (phase_78_2)
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

  int anchor_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_51_1) & 63;
  aux_2 = (aux_2 + anchor_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_12_1 == delta_12_2);
  assert(phase_78_1 == phase_78_2);
  assert(anchor_51_1 == anchor_51_2);
}

int fn_R000255_5513_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int delta_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_12 > 31)
  {
    acc = ((acc + (delta_12 * 2)) + 5) & 127;
    aux ^= delta_12 & 15;
  }
  else
  {
    acc = ((acc - delta_12) + 11) & 127;
    aux += 3;
  }
  int phase_78 = (aux + st.buffer[1]) & 3;
  switch (phase_78)
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

  int anchor_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_51) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000255_5513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st_1 = {0};
  struct SensorNode_R000255_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_26_1)
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

  switch (accumulator_26_2)
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

  int vector_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_57_1 > 35)
  {
    acc_1 = ((acc_1 + (vector_57_1 * 2)) + 5) & 127;
    aux_1 ^= vector_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_57_2 > 35)
  {
    acc_2 = ((acc_2 + (vector_57_2 * 2)) + 5) & 127;
    aux_2 ^= vector_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_58_1) & 63;
  aux_2 = (aux_2 + anchor_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_26_1 == accumulator_26_2);
  assert(vector_57_1 == vector_57_2);
  assert(anchor_58_1 == anchor_58_2);
}

int fn_R000255_5513_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_26 = (aux + st.buffer[1]) & 3;
  switch (accumulator_26)
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

  int vector_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_57 > 35)
  {
    acc = ((acc + (vector_57 * 2)) + 5) & 127;
    aux ^= vector_57 & 15;
  }
  else
  {
    acc = ((acc - vector_57) + 11) & 127;
    aux += 3;
  }
  int anchor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000255_5513_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st_1 = {0};
  struct CipherContext_R000255_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int pivot_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_62_1) & 63;
  aux_2 = (aux_2 + pivot_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_55_1 > 32)
  {
    acc_1 = ((acc_1 + (scale_55_1 * 2)) + 5) & 127;
    aux_1 ^= scale_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_55_2 > 32)
  {
    acc_2 = ((acc_2 + (scale_55_2 * 2)) + 5) & 127;
    aux_2 ^= scale_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_72_1)
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

  switch (residue_72_2)
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
  int phase_80_1 = local_arr_1[aux_1 % 3];
  int phase_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_62_1 == pivot_62_2);
  assert(scale_55_1 == scale_55_2);
  assert(residue_72_1 == residue_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_80_1 == phase_80_2);
}

int fn_R000255_5513_3(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int pivot_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_62) & 63;
  acc ^= aux;
  int scale_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_55 > 32)
  {
    acc = ((acc + (scale_55 * 2)) + 5) & 127;
    aux ^= scale_55 & 15;
  }
  else
  {
    acc = ((acc - scale_55) + 11) & 127;
    aux += 3;
  }
  int residue_72 = (aux + st.buffer[1]) & 3;
  switch (residue_72)
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
  int phase_80 = local_arr[aux % 3];
  acc = (acc + (phase_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000255_5513_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st_1 = {0};
  struct CipherContext_R000255_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int pivot_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_36_1 > 17)
  {
    acc_1 = ((acc_1 + (pivot_36_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_36_2 > 17)
  {
    acc_2 = ((acc_2 + (pivot_36_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_98_1) & 63;
  aux_2 = (aux_2 + segment_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_36_1 == pivot_36_2);
  assert(segment_98_1 == segment_98_2);
}

int fn_R000255_5513_4(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int pivot_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_36 > 17)
  {
    acc = ((acc + (pivot_36 * 2)) + 5) & 127;
    aux ^= pivot_36 & 15;
  }
  else
  {
    acc = ((acc - pivot_36) + 11) & 127;
    aux += 3;
  }
  int segment_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000255_5513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st_1 = {0};
  struct StreamBuffer_R000255_5513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int mask_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_27_1) & 63;
  aux_2 = (aux_2 + mask_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_79_1 = local_arr_1[aux_1 % 3];
  int residue_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_79_2 * 2)) & 127;
  int anchor_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_42_1 > 27)
  {
    acc_1 = ((acc_1 + (anchor_42_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_42_2 > 27)
  {
    acc_2 = ((acc_2 + (anchor_42_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_27_1 == mask_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_79_1 == residue_79_2);
  assert(anchor_42_1 == anchor_42_2);
}

int fn_R000255_5513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int mask_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_27) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_79 = local_arr[aux % 3];
  acc = (acc + (residue_79 * 2)) & 127;
  int anchor_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_42 > 27)
  {
    acc = ((acc + (anchor_42 * 2)) + 5) & 127;
    aux ^= anchor_42 & 15;
  }
  else
  {
    acc = ((acc - anchor_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000255_5513_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st_1 = {0};
  struct Transaction_R000255_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int margin_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_87_1 > 35)
  {
    acc_1 = ((acc_1 + (margin_87_1 * 2)) + 5) & 127;
    aux_1 ^= margin_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_87_2 > 35)
  {
    acc_2 = ((acc_2 + (margin_87_2 * 2)) + 5) & 127;
    aux_2 ^= margin_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_67_1) & 63;
  aux_2 = (aux_2 + residue_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_58_1 = local_arr_1[aux_1 % 3];
  int segment_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_58_2 * 2)) & 127;
  int phase_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_91_1)
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

  switch (phase_91_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_87_1 == margin_87_2);
  assert(residue_67_1 == residue_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_58_1 == segment_58_2);
  assert(phase_91_1 == phase_91_2);
}

int fn_R000255_5513_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int margin_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_87 > 35)
  {
    acc = ((acc + (margin_87 * 2)) + 5) & 127;
    aux ^= margin_87 & 15;
  }
  else
  {
    acc = ((acc - margin_87) + 11) & 127;
    aux += 3;
  }
  int residue_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_58 = local_arr[aux % 3];
  acc = (acc + (segment_58 * 2)) & 127;
  int phase_91 = (aux + st.buffer[1]) & 3;
  switch (phase_91)
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

void fn_R000255_5513_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st_1 = {0};
  struct StreamBuffer_R000255_5513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int accumulator_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_33_1 > 24)
  {
    acc_1 = ((acc_1 + (accumulator_33_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_33_2 > 24)
  {
    acc_2 = ((acc_2 + (accumulator_33_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_22_1 = local_arr_1[aux_1 % 3];
  int window_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_22_2 * 2)) & 127;
  int delta_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_22_1) & 63;
  aux_2 = (aux_2 + delta_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_33_1 == accumulator_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_22_1 == window_22_2);
  assert(delta_22_1 == delta_22_2);
}

int fn_R000255_5513_7(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int accumulator_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_33 > 24)
  {
    acc = ((acc + (accumulator_33 * 2)) + 5) & 127;
    aux ^= accumulator_33 & 15;
  }
  else
  {
    acc = ((acc - accumulator_33) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_22 = local_arr[aux % 3];
  acc = (acc + (window_22 * 2)) & 127;
  int delta_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000255_5513_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st_1 = {0};
  struct CipherContext_R000255_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int scale_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_50_1)
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

  switch (scale_50_2)
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
  int phase_25_1 = local_arr_1[aux_1 % 3];
  int phase_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_25_2 * 2)) & 127;
  int bound_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_83_1) & 63;
  aux_2 = (aux_2 + bound_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_50_1 == scale_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_25_1 == phase_25_2);
  assert(bound_83_1 == bound_83_2);
}

int fn_R000255_5513_8(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int scale_50 = (aux + st.buffer[1]) & 3;
  switch (scale_50)
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
  int phase_25 = local_arr[aux % 3];
  acc = (acc + (phase_25 * 2)) & 127;
  int bound_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000255_5513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st_1 = {0};
  struct CipherContext_R000255_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int scale_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_29_1) & 63;
  aux_2 = (aux_2 + scale_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_92_1 = local_arr_1[aux_1 % 3];
  int delta_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_92_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_66_1 > 11)
  {
    acc_1 = ((acc_1 + (accumulator_66_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_66_2 > 11)
  {
    acc_2 = ((acc_2 + (accumulator_66_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_29_1 == scale_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_92_1 == delta_92_2);
  assert(accumulator_66_1 == accumulator_66_2);
}

int fn_R000255_5513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int scale_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_29) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_92 = local_arr[aux % 3];
  acc = (acc + (delta_92 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_66 > 11)
  {
    acc = ((acc + (accumulator_66 * 2)) + 5) & 127;
    aux ^= accumulator_66 & 15;
  }
  else
  {
    acc = ((acc - accumulator_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000255_5513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st_1 = {0};
  struct CipherContext_R000255_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int mask_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_58_1)
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

  switch (mask_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_42_1 > 25)
  {
    acc_1 = ((acc_1 + (sample_42_1 * 2)) + 5) & 127;
    aux_1 ^= sample_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_42_2 > 25)
  {
    acc_2 = ((acc_2 + (sample_42_2 * 2)) + 5) & 127;
    aux_2 ^= sample_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_58_1 == mask_58_2);
  assert(sample_42_1 == sample_42_2);
}

int fn_R000255_5513_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int mask_58 = (aux + st.buffer[1]) & 3;
  switch (mask_58)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_42 > 25)
  {
    acc = ((acc + (sample_42 * 2)) + 5) & 127;
    aux ^= sample_42 & 15;
  }
  else
  {
    acc = ((acc - sample_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000255_5513_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st_1 = {0};
  struct StreamBuffer_R000255_5513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_94_1 > 22)
  {
    acc_1 = ((acc_1 + (scale_94_1 * 2)) + 5) & 127;
    aux_1 ^= scale_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_94_2 > 22)
  {
    acc_2 = ((acc_2 + (scale_94_2 * 2)) + 5) & 127;
    aux_2 ^= scale_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_94_1 == scale_94_2);
}

int fn_R000255_5513_11(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_94 > 22)
  {
    acc = ((acc + (scale_94 * 2)) + 5) & 127;
    aux ^= scale_94 & 15;
  }
  else
  {
    acc = ((acc - scale_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000255_5513_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st_1 = {0};
  struct StreamBuffer_R000255_5513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_68_1 > 41)
  {
    acc_1 = ((acc_1 + (threshold_68_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_68_2 > 41)
  {
    acc_2 = ((acc_2 + (threshold_68_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_69_1 = local_arr_1[aux_1 % 3];
  int threshold_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_68_1 == threshold_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_69_1 == threshold_69_2);
}

int fn_R000255_5513_12(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_68 > 41)
  {
    acc = ((acc + (threshold_68 * 2)) + 5) & 127;
    aux ^= threshold_68 & 15;
  }
  else
  {
    acc = ((acc - threshold_68) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_69 = local_arr[aux % 3];
  acc = (acc + (threshold_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000255_5513_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st_1 = {0};
  struct Transaction_R000255_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_19_1 = local_arr_1[aux_1 % 3];
  int accumulator_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_19_2 * 2)) & 127;
  int tracker_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_89_1 > 21)
  {
    acc_1 = ((acc_1 + (tracker_89_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_89_2 > 21)
  {
    acc_2 = ((acc_2 + (tracker_89_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_19_1 == accumulator_19_2);
  assert(tracker_89_1 == tracker_89_2);
}

int fn_R000255_5513_13(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int accumulator_19 = local_arr[aux % 3];
  acc = (acc + (accumulator_19 * 2)) & 127;
  int tracker_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_89 > 21)
  {
    acc = ((acc + (tracker_89 * 2)) + 5) & 127;
    aux ^= tracker_89 & 15;
  }
  else
  {
    acc = ((acc - tracker_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000255_5513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st_1 = {0};
  struct SensorNode_R000255_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int offset_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_25_1)
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

  switch (offset_25_2)
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
  int factor_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_93_1) & 63;
  aux_2 = (aux_2 + factor_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_81_1 = local_arr_1[aux_1 % 3];
  int delta_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_25_1 == offset_25_2);
  assert(factor_93_1 == factor_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_81_1 == delta_81_2);
}

int fn_R000255_5513_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int offset_25 = (aux + st.buffer[1]) & 3;
  switch (offset_25)
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
  int factor_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_93) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_81 = local_arr[aux % 3];
  acc = (acc + (delta_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000255_5513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st_1 = {0};
  struct SensorNode_R000255_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_50_1 = local_arr_1[aux_1 % 3];
  int offset_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_50_1 == offset_50_2);
}

int fn_R000255_5513_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_50 = local_arr[aux % 3];
  acc = (acc + (offset_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000255_5513_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st_1 = {0};
  struct SensorNode_R000255_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int coefficient_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_27_1) & 63;
  aux_2 = (aux_2 + coefficient_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_53_1 > 49)
  {
    acc_1 = ((acc_1 + (tracker_53_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_53_2 > 49)
  {
    acc_2 = ((acc_2 + (tracker_53_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_77_1)
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

  switch (tracker_77_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_27_1 == coefficient_27_2);
  assert(tracker_53_1 == tracker_53_2);
  assert(tracker_77_1 == tracker_77_2);
}

int fn_R000255_5513_16(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int coefficient_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_27) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_53 > 49)
  {
    acc = ((acc + (tracker_53 * 2)) + 5) & 127;
    aux ^= tracker_53 & 15;
  }
  else
  {
    acc = ((acc - tracker_53) + 11) & 127;
    aux += 3;
  }
  int tracker_77 = (aux + st.buffer[1]) & 3;
  switch (tracker_77)
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

void fn_R000255_5513_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st_1 = {0};
  struct CipherContext_R000255_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_57_1 = local_arr_1[aux_1 % 3];
  int coefficient_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_57_2 * 2)) & 127;
  int quotient_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_65_1) & 63;
  aux_2 = (aux_2 + quotient_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_57_1 == coefficient_57_2);
  assert(quotient_65_1 == quotient_65_2);
}

int fn_R000255_5513_17(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int coefficient_57 = local_arr[aux % 3];
  acc = (acc + (coefficient_57 * 2)) & 127;
  int quotient_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000255_5513_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st_1 = {0};
  struct Transaction_R000255_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_27_1 = local_arr_1[aux_1 % 3];
  int tally_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_27_2 * 2)) & 127;
  int stride_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_59_1 > 29)
  {
    acc_1 = ((acc_1 + (stride_59_1 * 2)) + 5) & 127;
    aux_1 ^= stride_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_59_2 > 29)
  {
    acc_2 = ((acc_2 + (stride_59_2 * 2)) + 5) & 127;
    aux_2 ^= stride_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_27_1 == tally_27_2);
  assert(stride_59_1 == stride_59_2);
}

int fn_R000255_5513_18(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int tally_27 = local_arr[aux % 3];
  acc = (acc + (tally_27 * 2)) & 127;
  int stride_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_59 > 29)
  {
    acc = ((acc + (stride_59 * 2)) + 5) & 127;
    aux ^= stride_59 & 15;
  }
  else
  {
    acc = ((acc - stride_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000255_5513_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st_1 = {0};
  struct SensorNode_R000255_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int tracker_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_41_1)
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

  switch (tracker_41_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_96_1 = local_arr_1[aux_1 % 3];
  int quantum_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_96_2 * 2)) & 127;
  int quotient_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_39_1 > 18)
  {
    acc_1 = ((acc_1 + (quotient_39_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_39_2 > 18)
  {
    acc_2 = ((acc_2 + (quotient_39_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_41_1 == tracker_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_96_1 == quantum_96_2);
  assert(quotient_39_1 == quotient_39_2);
}

int fn_R000255_5513_19(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000255_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int tracker_41 = (aux + st.buffer[1]) & 3;
  switch (tracker_41)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quantum_96 = local_arr[aux % 3];
  acc = (acc + (quantum_96 * 2)) & 127;
  int quotient_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_39 > 18)
  {
    acc = ((acc + (quotient_39 * 2)) + 5) & 127;
    aux ^= quotient_39 & 15;
  }
  else
  {
    acc = ((acc - quotient_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000255_5513_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st_1 = {0};
  struct StreamBuffer_R000255_5513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_55_1) & 63;
  aux_2 = (aux_2 + quantum_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_48_1 > 44)
  {
    acc_1 = ((acc_1 + (weight_48_1 * 2)) + 5) & 127;
    aux_1 ^= weight_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_48_2 > 44)
  {
    acc_2 = ((acc_2 + (weight_48_2 * 2)) + 5) & 127;
    aux_2 ^= weight_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_55_1 == quantum_55_2);
  assert(weight_48_1 == weight_48_2);
}

int fn_R000255_5513_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000255_5513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_55) & 63;
  acc ^= aux;
  int weight_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_48 > 44)
  {
    acc = ((acc + (weight_48 * 2)) + 5) & 127;
    aux ^= weight_48 & 15;
  }
  else
  {
    acc = ((acc - weight_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000255_5513_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st_1 = {0};
  struct CipherContext_R000255_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int bound_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_69_1)
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

  switch (bound_69_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_24_1) & 63;
  aux_2 = (aux_2 + scale_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_69_1 == bound_69_2);
  assert(scale_24_1 == scale_24_2);
}

int fn_R000255_5513_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int bound_69 = (aux + st.buffer[1]) & 3;
  switch (bound_69)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000255_5513_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st_1 = {0};
  struct Transaction_R000255_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_66_1 = local_arr_1[aux_1 % 3];
  int phase_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_66_2 * 2)) & 127;
  int cursor_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_59_1 > 15)
  {
    acc_1 = ((acc_1 + (cursor_59_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_59_2 > 15)
  {
    acc_2 = ((acc_2 + (cursor_59_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_66_1 == phase_66_2);
  assert(cursor_59_1 == cursor_59_2);
}

int fn_R000255_5513_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000255_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_66 = local_arr[aux % 3];
  acc = (acc + (phase_66 * 2)) & 127;
  int cursor_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_59 > 15)
  {
    acc = ((acc + (cursor_59 * 2)) + 5) & 127;
    aux ^= cursor_59 & 15;
  }
  else
  {
    acc = ((acc - cursor_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000255_5513_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st_1 = {0};
  struct CipherContext_R000255_5513_0 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_70_1 = local_arr_1[aux_1 % 3];
  int vector_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_70_2 * 2)) & 127;
  int pivot_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_15_1)
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

  switch (pivot_15_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_70_1 == vector_70_2);
  assert(pivot_15_1 == pivot_15_2);
}

int fn_R000255_5513_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000255_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_70 = local_arr[aux % 3];
  acc = (acc + (vector_70 * 2)) & 127;
  int pivot_15 = (aux + st.buffer[1]) & 3;
  switch (pivot_15)
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
  int sec_r000255_0_1;
  int sec_r000255_0_2;
  int sec_r000255_1_1;
  int sec_r000255_1_2;
  int sec_r000255_2_1;
  int sec_r000255_2_2;
  int sec_r000255_3_1;
  int sec_r000255_3_2;
  int sec_r000255_4_1;
  int sec_r000255_4_2;
  int sec_r000255_5_1;
  int sec_r000255_5_2;
  int sec_r000255_6_1;
  int sec_r000255_6_2;
  int sec_r000255_7_1;
  int sec_r000255_7_2;
  int sec_r000255_8_1;
  int sec_r000255_8_2;
  int sec_r000255_9_1;
  int sec_r000255_9_2;
  int sec_r000255_10_1;
  int sec_r000255_10_2;
  int sec_r000255_11_1;
  int sec_r000255_11_2;
  int sec_r000255_12_1;
  int sec_r000255_12_2;
  int sec_r000255_13_1;
  int sec_r000255_13_2;
  int sec_r000255_14_1;
  int sec_r000255_14_2;
  int sec_r000255_15_1;
  int sec_r000255_15_2;
  int sec_r000255_16_1;
  int sec_r000255_16_2;
  int sec_r000255_17_1;
  int sec_r000255_17_2;
  int sec_r000255_18_1;
  int sec_r000255_18_2;
  int sec_r000255_19_1;
  int sec_r000255_19_2;
  int sec_r000255_20_1;
  int sec_r000255_20_2;
  int sec_r000255_21_1;
  int sec_r000255_21_2;
  int sec_r000255_22_1;
  int sec_r000255_22_2;
  int pub_r000255_0_1;
  int pub_r000255_0_2;
  int pub_r000255_1_1;
  int pub_r000255_1_2;
  int pub_r000255_2_1;
  int pub_r000255_2_2;
  int pub_r000255_3_1;
  int pub_r000255_3_2;
  int pub_r000255_4_1;
  int pub_r000255_4_2;
  int pub_r000255_5_1;
  int pub_r000255_5_2;
  int pub_r000255_6_1;
  int pub_r000255_6_2;
  int pub_r000255_7_1;
  int pub_r000255_7_2;
  int pub_r000255_8_1;
  int pub_r000255_8_2;
  int pub_r000255_9_1;
  int pub_r000255_9_2;
  int pub_r000255_10_1;
  int pub_r000255_10_2;
  int pub_r000255_11_1;
  int pub_r000255_11_2;
  int pub_r000255_12_1;
  int pub_r000255_12_2;
  int pub_r000255_13_1;
  int pub_r000255_13_2;
  int pub_r000255_14_1;
  int pub_r000255_14_2;
  int pub_r000255_15_1;
  int pub_r000255_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000255_0_1 >= (-100)) && (pub_r000255_0_1 <= 100));
  __CPROVER_assume((pub_r000255_0_2 >= (-100)) && (pub_r000255_0_2 <= 100));
  __CPROVER_assume((pub_r000255_1_1 >= (-100)) && (pub_r000255_1_1 <= 100));
  __CPROVER_assume((pub_r000255_1_2 >= (-100)) && (pub_r000255_1_2 <= 100));
  __CPROVER_assume((pub_r000255_2_1 >= (-100)) && (pub_r000255_2_1 <= 100));
  __CPROVER_assume((pub_r000255_2_2 >= (-100)) && (pub_r000255_2_2 <= 100));
  __CPROVER_assume((pub_r000255_3_1 >= (-100)) && (pub_r000255_3_1 <= 100));
  __CPROVER_assume((pub_r000255_3_2 >= (-100)) && (pub_r000255_3_2 <= 100));
  __CPROVER_assume((pub_r000255_4_1 >= (-100)) && (pub_r000255_4_1 <= 100));
  __CPROVER_assume((pub_r000255_4_2 >= (-100)) && (pub_r000255_4_2 <= 100));
  __CPROVER_assume((pub_r000255_5_1 >= (-100)) && (pub_r000255_5_1 <= 100));
  __CPROVER_assume((pub_r000255_5_2 >= (-100)) && (pub_r000255_5_2 <= 100));
  __CPROVER_assume((pub_r000255_6_1 >= (-100)) && (pub_r000255_6_1 <= 100));
  __CPROVER_assume((pub_r000255_6_2 >= (-100)) && (pub_r000255_6_2 <= 100));
  __CPROVER_assume((pub_r000255_7_1 >= (-100)) && (pub_r000255_7_1 <= 100));
  __CPROVER_assume((pub_r000255_7_2 >= (-100)) && (pub_r000255_7_2 <= 100));
  __CPROVER_assume((pub_r000255_8_1 >= (-100)) && (pub_r000255_8_1 <= 100));
  __CPROVER_assume((pub_r000255_8_2 >= (-100)) && (pub_r000255_8_2 <= 100));
  __CPROVER_assume((pub_r000255_9_1 >= (-100)) && (pub_r000255_9_1 <= 100));
  __CPROVER_assume((pub_r000255_9_2 >= (-100)) && (pub_r000255_9_2 <= 100));
  __CPROVER_assume((pub_r000255_10_1 >= (-100)) && (pub_r000255_10_1 <= 100));
  __CPROVER_assume((pub_r000255_10_2 >= (-100)) && (pub_r000255_10_2 <= 100));
  __CPROVER_assume((pub_r000255_11_1 >= (-100)) && (pub_r000255_11_1 <= 100));
  __CPROVER_assume((pub_r000255_11_2 >= (-100)) && (pub_r000255_11_2 <= 100));
  __CPROVER_assume((pub_r000255_12_1 >= (-100)) && (pub_r000255_12_1 <= 100));
  __CPROVER_assume((pub_r000255_12_2 >= (-100)) && (pub_r000255_12_2 <= 100));
  __CPROVER_assume((pub_r000255_13_1 >= (-100)) && (pub_r000255_13_1 <= 100));
  __CPROVER_assume((pub_r000255_13_2 >= (-100)) && (pub_r000255_13_2 <= 100));
  __CPROVER_assume((pub_r000255_14_1 >= (-100)) && (pub_r000255_14_1 <= 100));
  __CPROVER_assume((pub_r000255_14_2 >= (-100)) && (pub_r000255_14_2 <= 100));
  __CPROVER_assume((pub_r000255_15_1 >= (-100)) && (pub_r000255_15_1 <= 100));
  __CPROVER_assume((pub_r000255_15_2 >= (-100)) && (pub_r000255_15_2 <= 100));
  __CPROVER_assume((sec_r000255_0_1 >= 0) && (sec_r000255_0_1 <= 255));
  __CPROVER_assume((sec_r000255_0_2 >= 0) && (sec_r000255_0_2 <= 255));
  __CPROVER_assume((sec_r000255_1_1 >= 0) && (sec_r000255_1_1 <= 255));
  __CPROVER_assume((sec_r000255_1_2 >= 0) && (sec_r000255_1_2 <= 255));
  __CPROVER_assume((sec_r000255_2_1 >= 0) && (sec_r000255_2_1 <= 255));
  __CPROVER_assume((sec_r000255_2_2 >= 0) && (sec_r000255_2_2 <= 255));
  __CPROVER_assume((sec_r000255_3_1 >= 0) && (sec_r000255_3_1 <= 255));
  __CPROVER_assume((sec_r000255_3_2 >= 0) && (sec_r000255_3_2 <= 255));
  __CPROVER_assume((sec_r000255_4_1 >= 0) && (sec_r000255_4_1 <= 255));
  __CPROVER_assume((sec_r000255_4_2 >= 0) && (sec_r000255_4_2 <= 255));
  __CPROVER_assume((sec_r000255_5_1 >= 0) && (sec_r000255_5_1 <= 255));
  __CPROVER_assume((sec_r000255_5_2 >= 0) && (sec_r000255_5_2 <= 255));
  __CPROVER_assume((sec_r000255_6_1 >= 0) && (sec_r000255_6_1 <= 255));
  __CPROVER_assume((sec_r000255_6_2 >= 0) && (sec_r000255_6_2 <= 255));
  __CPROVER_assume((sec_r000255_7_1 >= 0) && (sec_r000255_7_1 <= 255));
  __CPROVER_assume((sec_r000255_7_2 >= 0) && (sec_r000255_7_2 <= 255));
  __CPROVER_assume((sec_r000255_8_1 >= 0) && (sec_r000255_8_1 <= 255));
  __CPROVER_assume((sec_r000255_8_2 >= 0) && (sec_r000255_8_2 <= 255));
  __CPROVER_assume((sec_r000255_9_1 >= 0) && (sec_r000255_9_1 <= 255));
  __CPROVER_assume((sec_r000255_9_2 >= 0) && (sec_r000255_9_2 <= 255));
  __CPROVER_assume((sec_r000255_10_1 >= 0) && (sec_r000255_10_1 <= 255));
  __CPROVER_assume((sec_r000255_10_2 >= 0) && (sec_r000255_10_2 <= 255));
  __CPROVER_assume((sec_r000255_11_1 >= 0) && (sec_r000255_11_1 <= 255));
  __CPROVER_assume((sec_r000255_11_2 >= 0) && (sec_r000255_11_2 <= 255));
  __CPROVER_assume((sec_r000255_12_1 >= 0) && (sec_r000255_12_1 <= 255));
  __CPROVER_assume((sec_r000255_12_2 >= 0) && (sec_r000255_12_2 <= 255));
  __CPROVER_assume((sec_r000255_13_1 >= 0) && (sec_r000255_13_1 <= 255));
  __CPROVER_assume((sec_r000255_13_2 >= 0) && (sec_r000255_13_2 <= 255));
  __CPROVER_assume((sec_r000255_14_1 >= 0) && (sec_r000255_14_1 <= 255));
  __CPROVER_assume((sec_r000255_14_2 >= 0) && (sec_r000255_14_2 <= 255));
  __CPROVER_assume((sec_r000255_15_1 >= 0) && (sec_r000255_15_1 <= 255));
  __CPROVER_assume((sec_r000255_15_2 >= 0) && (sec_r000255_15_2 <= 255));
  __CPROVER_assume((sec_r000255_16_1 >= 0) && (sec_r000255_16_1 <= 255));
  __CPROVER_assume((sec_r000255_16_2 >= 0) && (sec_r000255_16_2 <= 255));
  __CPROVER_assume((sec_r000255_17_1 >= 0) && (sec_r000255_17_1 <= 255));
  __CPROVER_assume((sec_r000255_17_2 >= 0) && (sec_r000255_17_2 <= 255));
  __CPROVER_assume((sec_r000255_18_1 >= 0) && (sec_r000255_18_1 <= 255));
  __CPROVER_assume((sec_r000255_18_2 >= 0) && (sec_r000255_18_2 <= 255));
  __CPROVER_assume((sec_r000255_19_1 >= 0) && (sec_r000255_19_1 <= 255));
  __CPROVER_assume((sec_r000255_19_2 >= 0) && (sec_r000255_19_2 <= 255));
  __CPROVER_assume((sec_r000255_20_1 >= 0) && (sec_r000255_20_1 <= 255));
  __CPROVER_assume((sec_r000255_20_2 >= 0) && (sec_r000255_20_2 <= 255));
  __CPROVER_assume((sec_r000255_21_1 >= 0) && (sec_r000255_21_1 <= 255));
  __CPROVER_assume((sec_r000255_21_2 >= 0) && (sec_r000255_21_2 <= 255));
  __CPROVER_assume((sec_r000255_22_1 >= 0) && (sec_r000255_22_1 <= 255));
  __CPROVER_assume((sec_r000255_22_2 >= 0) && (sec_r000255_22_2 <= 255));
  struct CipherContext_R000255_5513_0 st_var_0_1 = {0};
  struct CipherContext_R000255_5513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000255_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000255_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000255_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000255_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000255_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000255_0_2 + 7) & 15;
  struct SensorNode_R000255_5513_1 st_var_1_1 = {0};
  struct SensorNode_R000255_5513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000255_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000255_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000255_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000255_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000255_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000255_0_2 + 9) & 15;
  struct Transaction_R000255_5513_2 st_var_2_1 = {0};
  struct Transaction_R000255_5513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000255_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000255_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000255_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000255_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000255_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000255_0_2 + 11) & 15;
  struct StreamBuffer_R000255_5513_3 st_var_3_1 = {0};
  struct StreamBuffer_R000255_5513_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000255_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000255_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000255_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000255_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000255_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000255_0_2 + 13) & 15;
  union ColorPixel_R000255_5513_0 u_var_1;
  union ColorPixel_R000255_5513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 27)
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
  if (stage_v_0_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 27)
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

  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 52)
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
  if (stage_v_12_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 52)
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
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((sec_r000255_20_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_19_2 = (((sec_r000255_20_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = (((sec_r000255_0_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_20_2 = (((sec_r000255_0_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = (((stage_v_20_1 << 1) ^ (sec_r000255_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_21_2 = (((stage_v_20_2 << 1) ^ (sec_r000255_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = (((sec_r000255_7_1 << 1) ^ (sec_r000255_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_22_2 = (((sec_r000255_7_2 << 1) ^ (sec_r000255_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = (((stage_v_19_1 << 1) ^ (sec_r000255_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_23_2 = (((stage_v_19_2 << 1) ^ (sec_r000255_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = (((stage_v_19_1 << 1) ^ (sec_r000255_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_24_2 = (((stage_v_19_2 << 1) ^ (sec_r000255_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = (((sec_r000255_22_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_25_2 = (((sec_r000255_22_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = (((stage_v_22_1 << 1) ^ (sec_r000255_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_26_2 = (((stage_v_22_2 << 1) ^ (sec_r000255_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = (((sec_r000255_11_1 << 2) ^ (sec_r000255_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_27_2 = (((sec_r000255_11_2 << 2) ^ (sec_r000255_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = (((stage_v_19_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_28_2 = (((stage_v_19_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = (((stage_v_25_1 << 1) ^ (sec_r000255_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_29_2 = (((stage_v_25_2 << 1) ^ (sec_r000255_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = (((sec_r000255_4_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_30_2 = (((sec_r000255_4_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = (((stage_v_26_1 << 2) ^ (sec_r000255_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_31_2 = (((stage_v_26_2 << 2) ^ (sec_r000255_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = (((stage_v_22_1 << 1) ^ (sec_r000255_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_32_2 = (((stage_v_22_2 << 1) ^ (sec_r000255_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = (((sec_r000255_14_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_33_2 = (((sec_r000255_14_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = (((stage_v_25_1 << 1) ^ (sec_r000255_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_34_2 = (((stage_v_25_2 << 1) ^ (sec_r000255_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = (((stage_v_34_1 << 2) ^ (sec_r000255_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_35_2 = (((stage_v_34_2 << 2) ^ (sec_r000255_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = (((sec_r000255_10_1 << 1) ^ (sec_r000255_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_36_2 = (((sec_r000255_10_2 << 1) ^ (sec_r000255_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = (((stage_v_23_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_37_2 = (((stage_v_23_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = (((sec_r000255_9_1 << 1) ^ (sec_r000255_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_38_2 = (((sec_r000255_9_2 << 1) ^ (sec_r000255_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = (((stage_v_32_1 << 2) ^ (sec_r000255_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_39_2 = (((stage_v_32_2 << 2) ^ (sec_r000255_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = (((stage_v_19_1 << 2) ^ (sec_r000255_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_40_2 = (((stage_v_19_2 << 2) ^ (sec_r000255_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = (((stage_v_36_1 << 1) ^ (sec_r000255_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_41_2 = (((stage_v_36_2 << 1) ^ (sec_r000255_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = (((sec_r000255_7_1 << 1) ^ (sec_r000255_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_42_2 = (((sec_r000255_7_2 << 1) ^ (sec_r000255_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = (((stage_v_22_1 << 1) ^ (sec_r000255_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_43_2 = (((stage_v_22_2 << 1) ^ (sec_r000255_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = (((sec_r000255_4_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_44_2 = (((sec_r000255_4_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = (((sec_r000255_2_1 << 1) ^ (sec_r000255_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_45_2 = (((sec_r000255_2_2 << 1) ^ (sec_r000255_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = (((stage_v_34_1 << 1) ^ (sec_r000255_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_46_2 = (((stage_v_34_2 << 1) ^ (sec_r000255_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = (((stage_v_20_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_47_2 = (((stage_v_20_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = (((sec_r000255_17_1 << 2) ^ (sec_r000255_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_48_2 = (((sec_r000255_17_2 << 2) ^ (sec_r000255_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = (((stage_v_22_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_49_2 = (((stage_v_22_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = (((stage_v_47_1 << 1) ^ (sec_r000255_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_50_2 = (((stage_v_47_2 << 1) ^ (sec_r000255_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = (((stage_v_24_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_51_2 = (((stage_v_24_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = (((sec_r000255_13_1 << 1) ^ (sec_r000255_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_52_2 = (((sec_r000255_13_2 << 1) ^ (sec_r000255_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = (((stage_v_37_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_53_2 = (((stage_v_37_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = (((sec_r000255_12_1 << 1) ^ (sec_r000255_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_54_2 = (((sec_r000255_12_2 << 1) ^ (sec_r000255_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = (((stage_v_26_1 << 2) ^ (sec_r000255_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_55_2 = (((stage_v_26_2 << 2) ^ (sec_r000255_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = (((sec_r000255_5_1 << 1) ^ (sec_r000255_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_56_2 = (((sec_r000255_5_2 << 1) ^ (sec_r000255_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = (((stage_v_56_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_57_2 = (((stage_v_56_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = (((sec_r000255_12_1 << 2) ^ (sec_r000255_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_58_2 = (((sec_r000255_12_2 << 2) ^ (sec_r000255_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = (((stage_v_38_1 << 1) ^ (sec_r000255_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_59_2 = (((stage_v_38_2 << 1) ^ (sec_r000255_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = (((stage_v_37_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_60_2 = (((stage_v_37_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = (((stage_v_56_1 << 1) ^ (sec_r000255_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_61_2 = (((stage_v_56_2 << 1) ^ (sec_r000255_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = (((sec_r000255_1_1 << 2) ^ (sec_r000255_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_62_2 = (((sec_r000255_1_2 << 2) ^ (sec_r000255_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = (((sec_r000255_6_1 << 1) ^ (sec_r000255_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_63_2 = (((sec_r000255_6_2 << 1) ^ (sec_r000255_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = (((stage_v_20_1 << 2) ^ (sec_r000255_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_64_2 = (((stage_v_20_2 << 2) ^ (sec_r000255_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = (((sec_r000255_0_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_65_2 = (((sec_r000255_0_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = (((sec_r000255_7_1 << 2) ^ (sec_r000255_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_66_2 = (((sec_r000255_7_2 << 2) ^ (sec_r000255_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = (((sec_r000255_8_1 << 2) ^ (sec_r000255_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_67_2 = (((sec_r000255_8_2 << 2) ^ (sec_r000255_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = (((sec_r000255_20_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_68_2 = (((sec_r000255_20_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = (((stage_v_35_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_69_2 = (((stage_v_35_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = (((stage_v_20_1 << 1) ^ (sec_r000255_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_70_2 = (((stage_v_20_2 << 1) ^ (sec_r000255_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = (((stage_v_59_1 << 1) ^ (sec_r000255_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_71_2 = (((stage_v_59_2 << 1) ^ (sec_r000255_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = (((stage_v_34_1 << 1) ^ (sec_r000255_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_72_2 = (((stage_v_34_2 << 1) ^ (sec_r000255_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = (((stage_v_32_1 << 1) ^ (sec_r000255_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_73_2 = (((stage_v_32_2 << 1) ^ (sec_r000255_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = (((stage_v_61_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_74_2 = (((stage_v_61_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = (((sec_r000255_20_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_75_2 = (((sec_r000255_20_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = (((stage_v_35_1 << 2) ^ (sec_r000255_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_76_2 = (((stage_v_35_2 << 2) ^ (sec_r000255_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = (((sec_r000255_19_1 << 1) ^ (sec_r000255_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_77_2 = (((sec_r000255_19_2 << 1) ^ (sec_r000255_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = (((sec_r000255_6_1 << 2) ^ (sec_r000255_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_78_2 = (((sec_r000255_6_2 << 2) ^ (sec_r000255_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = (((stage_v_74_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_79_2 = (((stage_v_74_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = (((stage_v_51_1 << 2) ^ (sec_r000255_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_80_2 = (((stage_v_51_2 << 2) ^ (sec_r000255_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = (((stage_v_73_1 << 1) ^ (sec_r000255_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_81_2 = (((stage_v_73_2 << 1) ^ (sec_r000255_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = (((sec_r000255_7_1 << 2) ^ (sec_r000255_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_82_2 = (((sec_r000255_7_2 << 2) ^ (sec_r000255_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = (((sec_r000255_3_1 << 2) ^ (sec_r000255_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_83_2 = (((sec_r000255_3_2 << 2) ^ (sec_r000255_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_83_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_83_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = (((stage_v_52_1 << 2) ^ (sec_r000255_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_84_2 = (((stage_v_52_2 << 2) ^ (sec_r000255_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = (((sec_r000255_6_1 << 2) ^ (sec_r000255_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_85_2 = (((sec_r000255_6_2 << 2) ^ (sec_r000255_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = (((stage_v_41_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_86_2 = (((stage_v_41_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = (((stage_v_50_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_87_2 = (((stage_v_50_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = (((stage_v_50_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_88_2 = (((stage_v_50_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = (((stage_v_85_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_89_2 = (((stage_v_85_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = (((stage_v_60_1 << 2) ^ (sec_r000255_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_90_2 = (((stage_v_60_2 << 2) ^ (sec_r000255_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = (((stage_v_50_1 << 2) ^ (sec_r000255_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_91_2 = (((stage_v_50_2 << 2) ^ (sec_r000255_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = (((sec_r000255_17_1 << 2) ^ (sec_r000255_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_92_2 = (((sec_r000255_17_2 << 2) ^ (sec_r000255_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_92_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_92_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = (((stage_v_62_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_93_2 = (((stage_v_62_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = (((sec_r000255_13_1 << 2) ^ (sec_r000255_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_94_2 = (((sec_r000255_13_2 << 2) ^ (sec_r000255_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = (((stage_v_34_1 << 1) ^ (sec_r000255_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_95_2 = (((stage_v_34_2 << 1) ^ (sec_r000255_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = (((stage_v_62_1 << 2) ^ (sec_r000255_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_96_2 = (((stage_v_62_2 << 2) ^ (sec_r000255_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = (((stage_v_87_1 << 2) ^ (sec_r000255_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_97_2 = (((stage_v_87_2 << 2) ^ (sec_r000255_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = (((sec_r000255_10_1 << 2) ^ (sec_r000255_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_98_2 = (((sec_r000255_10_2 << 2) ^ (sec_r000255_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = (((sec_r000255_1_1 << 2) ^ (sec_r000255_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_99_2 = (((sec_r000255_1_2 << 2) ^ (sec_r000255_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = (((stage_v_29_1 << 1) ^ (sec_r000255_22_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_100_2 = (((stage_v_29_2 << 1) ^ (sec_r000255_22_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = (((stage_v_84_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_101_2 = (((stage_v_84_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = (((stage_v_81_1 << 1) ^ (sec_r000255_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_102_2 = (((stage_v_81_2 << 1) ^ (sec_r000255_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = (((stage_v_56_1 << 1) ^ (sec_r000255_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_103_2 = (((stage_v_56_2 << 1) ^ (sec_r000255_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = (((stage_v_63_1 << 2) ^ (sec_r000255_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_104_2 = (((stage_v_63_2 << 2) ^ (sec_r000255_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = (((stage_v_22_1 << 1) ^ (sec_r000255_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_105_2 = (((stage_v_22_2 << 1) ^ (sec_r000255_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_105_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_105_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = (((stage_v_65_1 << 1) ^ (sec_r000255_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_106_2 = (((stage_v_65_2 << 1) ^ (sec_r000255_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = (((sec_r000255_13_1 << 1) ^ (sec_r000255_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_107_2 = (((sec_r000255_13_2 << 1) ^ (sec_r000255_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = (((sec_r000255_6_1 << 2) ^ (sec_r000255_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_108_2 = (((sec_r000255_6_2 << 2) ^ (sec_r000255_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = (((stage_v_59_1 << 2) ^ (sec_r000255_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_109_2 = (((stage_v_59_2 << 2) ^ (sec_r000255_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = (((stage_v_91_1 << 1) ^ (sec_r000255_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_110_2 = (((stage_v_91_2 << 1) ^ (sec_r000255_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = (((stage_v_35_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_111_2 = (((stage_v_35_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = (((stage_v_87_1 << 1) ^ (sec_r000255_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_112_2 = (((stage_v_87_2 << 1) ^ (sec_r000255_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = (((sec_r000255_21_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_113_2 = (((sec_r000255_21_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = (((sec_r000255_20_1 << 2) ^ (sec_r000255_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_114_2 = (((sec_r000255_20_2 << 2) ^ (sec_r000255_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = (((stage_v_107_1 << 2) ^ (sec_r000255_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_115_2 = (((stage_v_107_2 << 2) ^ (sec_r000255_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = (((stage_v_23_1 << 1) ^ (sec_r000255_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_116_2 = (((stage_v_23_2 << 1) ^ (sec_r000255_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = (((stage_v_51_1 << 1) ^ (sec_r000255_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_117_2 = (((stage_v_51_2 << 1) ^ (sec_r000255_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = (((stage_v_106_1 << 1) ^ (sec_r000255_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_118_2 = (((stage_v_106_2 << 1) ^ (sec_r000255_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = (((sec_r000255_0_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_119_2 = (((sec_r000255_0_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = (((stage_v_80_1 << 1) ^ (sec_r000255_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_120_2 = (((stage_v_80_2 << 1) ^ (sec_r000255_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = (((sec_r000255_8_1 << 1) ^ (sec_r000255_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_121_2 = (((sec_r000255_8_2 << 1) ^ (sec_r000255_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = (((stage_v_67_1 << 1) ^ (sec_r000255_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_122_2 = (((stage_v_67_2 << 1) ^ (sec_r000255_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = (((sec_r000255_7_1 << 1) ^ (sec_r000255_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_123_2 = (((sec_r000255_7_2 << 1) ^ (sec_r000255_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = (((stage_v_71_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_124_2 = (((stage_v_71_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = (((sec_r000255_0_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_125_2 = (((sec_r000255_0_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = (((stage_v_116_1 << 1) ^ (sec_r000255_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_126_2 = (((stage_v_116_2 << 1) ^ (sec_r000255_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = (((stage_v_99_1 << 2) ^ (sec_r000255_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_127_2 = (((stage_v_99_2 << 2) ^ (sec_r000255_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = (((stage_v_62_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_128_2 = (((stage_v_62_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = (((sec_r000255_21_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_129_2 = (((sec_r000255_21_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = (((sec_r000255_5_1 << 1) ^ (sec_r000255_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_130_2 = (((sec_r000255_5_2 << 1) ^ (sec_r000255_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = (((sec_r000255_1_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_131_2 = (((sec_r000255_1_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = (((stage_v_69_1 << 2) ^ (sec_r000255_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_132_2 = (((stage_v_69_2 << 2) ^ (sec_r000255_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = (((stage_v_120_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_133_2 = (((stage_v_120_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = (((stage_v_88_1 << 1) ^ (sec_r000255_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_134_2 = (((stage_v_88_2 << 1) ^ (sec_r000255_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_134_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_134_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = (((stage_v_96_1 << 1) ^ (sec_r000255_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_135_2 = (((stage_v_96_2 << 1) ^ (sec_r000255_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = (((stage_v_123_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_136_2 = (((stage_v_123_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = (((sec_r000255_4_1 << 2) ^ (sec_r000255_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_137_2 = (((sec_r000255_4_2 << 2) ^ (sec_r000255_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = (((sec_r000255_22_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_138_2 = (((sec_r000255_22_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = (((stage_v_83_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_139_2 = (((stage_v_83_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = (((stage_v_91_1 << 2) ^ (sec_r000255_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_140_2 = (((stage_v_91_2 << 2) ^ (sec_r000255_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = (((stage_v_54_1 << 2) ^ (sec_r000255_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_141_2 = (((stage_v_54_2 << 2) ^ (sec_r000255_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_141_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_141_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = (((sec_r000255_1_1 << 2) ^ (sec_r000255_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_142_2 = (((sec_r000255_1_2 << 2) ^ (sec_r000255_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_142_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_142_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = (((sec_r000255_20_1 << 2) ^ (sec_r000255_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_143_2 = (((sec_r000255_20_2 << 2) ^ (sec_r000255_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = (((sec_r000255_19_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_144_2 = (((sec_r000255_19_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = (((stage_v_110_1 << 2) ^ (sec_r000255_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_145_2 = (((stage_v_110_2 << 2) ^ (sec_r000255_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = (((stage_v_63_1 << 1) ^ (sec_r000255_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_146_2 = (((stage_v_63_2 << 1) ^ (sec_r000255_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = (((stage_v_78_1 << 2) ^ (sec_r000255_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_147_2 = (((stage_v_78_2 << 2) ^ (sec_r000255_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = (((stage_v_69_1 << 1) ^ (sec_r000255_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_148_2 = (((stage_v_69_2 << 1) ^ (sec_r000255_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = (((stage_v_48_1 << 1) ^ (sec_r000255_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_149_2 = (((stage_v_48_2 << 1) ^ (sec_r000255_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = (((sec_r000255_8_1 << 1) ^ (sec_r000255_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_150_2 = (((sec_r000255_8_2 << 1) ^ (sec_r000255_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = (((sec_r000255_12_1 << 2) ^ (sec_r000255_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_151_2 = (((sec_r000255_12_2 << 2) ^ (sec_r000255_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = (((sec_r000255_5_1 << 2) ^ (sec_r000255_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_152_2 = (((sec_r000255_5_2 << 2) ^ (sec_r000255_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = (((stage_v_61_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_153_2 = (((stage_v_61_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = (((stage_v_71_1 << 2) ^ (sec_r000255_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_154_2 = (((stage_v_71_2 << 2) ^ (sec_r000255_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_154_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_154_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = (((stage_v_126_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_155_2 = (((stage_v_126_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = (((sec_r000255_14_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_156_2 = (((sec_r000255_14_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = (((stage_v_75_1 << 1) ^ (sec_r000255_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_157_2 = (((stage_v_75_2 << 1) ^ (sec_r000255_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = (((stage_v_91_1 << 2) ^ (sec_r000255_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_158_2 = (((stage_v_91_2 << 2) ^ (sec_r000255_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = (((stage_v_141_1 << 1) ^ (sec_r000255_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_159_2 = (((stage_v_141_2 << 1) ^ (sec_r000255_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = (((sec_r000255_20_1 << 2) ^ (sec_r000255_20_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_160_2 = (((sec_r000255_20_2 << 2) ^ (sec_r000255_20_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = (((stage_v_101_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_161_2 = (((stage_v_101_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = (((stage_v_151_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_162_2 = (((stage_v_151_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_162_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_162_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = (((sec_r000255_11_1 << 1) ^ (sec_r000255_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_163_2 = (((sec_r000255_11_2 << 1) ^ (sec_r000255_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = (((stage_v_100_1 << 1) ^ (sec_r000255_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_164_2 = (((stage_v_100_2 << 1) ^ (sec_r000255_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_164_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_164_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = (((stage_v_102_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_165_2 = (((stage_v_102_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = (((sec_r000255_2_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_166_2 = (((sec_r000255_2_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = (((sec_r000255_2_1 << 1) ^ (sec_r000255_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_167_2 = (((sec_r000255_2_2 << 1) ^ (sec_r000255_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = (((sec_r000255_7_1 << 1) ^ (sec_r000255_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_168_2 = (((sec_r000255_7_2 << 1) ^ (sec_r000255_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = (((stage_v_158_1 << 2) ^ (sec_r000255_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_169_2 = (((stage_v_158_2 << 2) ^ (sec_r000255_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = (((stage_v_69_1 << 1) ^ (sec_r000255_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_170_2 = (((stage_v_69_2 << 1) ^ (sec_r000255_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_170_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_170_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = (((stage_v_94_1 << 1) ^ (sec_r000255_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_171_2 = (((stage_v_94_2 << 1) ^ (sec_r000255_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = (((sec_r000255_5_1 << 1) ^ (sec_r000255_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_172_2 = (((sec_r000255_5_2 << 1) ^ (sec_r000255_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = (((stage_v_111_1 << 1) ^ (sec_r000255_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_173_2 = (((stage_v_111_2 << 1) ^ (sec_r000255_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = (((sec_r000255_18_1 << 1) ^ (sec_r000255_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_174_2 = (((sec_r000255_18_2 << 1) ^ (sec_r000255_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_174_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_174_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = (((stage_v_146_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_175_2 = (((stage_v_146_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = (((sec_r000255_4_1 << 2) ^ (sec_r000255_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_176_2 = (((sec_r000255_4_2 << 2) ^ (sec_r000255_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_176_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_176_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = (((sec_r000255_21_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_177_2 = (((sec_r000255_21_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = (((sec_r000255_14_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_178_2 = (((sec_r000255_14_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_178_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_178_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = (((sec_r000255_1_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_179_2 = (((sec_r000255_1_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_179_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_179_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = (((stage_v_148_1 << 2) ^ (sec_r000255_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_180_2 = (((stage_v_148_2 << 2) ^ (sec_r000255_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_180_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_180_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = (((stage_v_41_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_181_2 = (((stage_v_41_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = (((sec_r000255_2_1 << 1) ^ (sec_r000255_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_182_2 = (((sec_r000255_2_2 << 1) ^ (sec_r000255_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_182_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_182_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = (((sec_r000255_7_1 << 2) ^ (sec_r000255_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_183_2 = (((sec_r000255_7_2 << 2) ^ (sec_r000255_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_183_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_183_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = (((stage_v_57_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_184_2 = (((stage_v_57_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = (((stage_v_63_1 << 2) ^ (sec_r000255_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_185_2 = (((stage_v_63_2 << 2) ^ (sec_r000255_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_185_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_185_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = (((sec_r000255_6_1 << 1) ^ (sec_r000255_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_186_2 = (((sec_r000255_6_2 << 1) ^ (sec_r000255_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_186_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_186_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = (((sec_r000255_18_1 << 2) ^ (sec_r000255_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_187_2 = (((sec_r000255_18_2 << 2) ^ (sec_r000255_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_187_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_187_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = (((sec_r000255_3_1 << 1) ^ (sec_r000255_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_188_2 = (((sec_r000255_3_2 << 1) ^ (sec_r000255_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_188_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_188_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = (((stage_v_85_1 << 2) ^ (sec_r000255_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_189_2 = (((stage_v_85_2 << 2) ^ (sec_r000255_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_189_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_189_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = (((stage_v_77_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_190_2 = (((stage_v_77_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_190_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_190_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = (((sec_r000255_15_1 << 1) ^ (sec_r000255_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_191_2 = (((sec_r000255_15_2 << 1) ^ (sec_r000255_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_191_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_191_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = (((stage_v_72_1 << 1) ^ (sec_r000255_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_192_2 = (((stage_v_72_2 << 1) ^ (sec_r000255_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_192_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_192_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = (((stage_v_169_1 << 2) ^ (sec_r000255_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_193_2 = (((stage_v_169_2 << 2) ^ (sec_r000255_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_193_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_193_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = (((stage_v_68_1 << 2) ^ (sec_r000255_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_194_2 = (((stage_v_68_2 << 2) ^ (sec_r000255_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_194_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_194_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = (((stage_v_66_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_195_2 = (((stage_v_66_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_195_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_195_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = (((stage_v_148_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_196_2 = (((stage_v_148_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_196_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_196_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = (((stage_v_26_1 << 1) ^ (sec_r000255_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_197_2 = (((stage_v_26_2 << 1) ^ (sec_r000255_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_197_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_197_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = (((stage_v_61_1 << 1) ^ (sec_r000255_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_198_2 = (((stage_v_61_2 << 1) ^ (sec_r000255_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_198_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_198_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = (((sec_r000255_22_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_199_2 = (((sec_r000255_22_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_199_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_199_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = (((stage_v_147_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_200_2 = (((stage_v_147_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_200_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_200_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = (((stage_v_111_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_201_2 = (((stage_v_111_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_201_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_201_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = (((stage_v_85_1 << 2) ^ (sec_r000255_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_202_2 = (((stage_v_85_2 << 2) ^ (sec_r000255_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_202_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_202_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = (((stage_v_137_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_203_2 = (((stage_v_137_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_203_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_203_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = (((stage_v_191_1 << 2) ^ (sec_r000255_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_204_2 = (((stage_v_191_2 << 2) ^ (sec_r000255_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_204_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_204_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = (((stage_v_179_1 << 1) ^ (sec_r000255_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_205_2 = (((stage_v_179_2 << 1) ^ (sec_r000255_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_205_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_205_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = (((stage_v_203_1 << 1) ^ (sec_r000255_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_206_2 = (((stage_v_203_2 << 1) ^ (sec_r000255_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_206_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_206_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = (((stage_v_187_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_207_2 = (((stage_v_187_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_207_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_207_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = (((stage_v_108_1 << 2) ^ (sec_r000255_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_208_2 = (((stage_v_108_2 << 2) ^ (sec_r000255_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_208_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_208_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = (((sec_r000255_4_1 << 2) ^ (sec_r000255_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_209_2 = (((sec_r000255_4_2 << 2) ^ (sec_r000255_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_209_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_209_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = (((stage_v_111_1 << 1) ^ (sec_r000255_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_210_2 = (((stage_v_111_2 << 1) ^ (sec_r000255_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_210_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_210_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = (((stage_v_194_1 << 1) ^ (sec_r000255_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_211_2 = (((stage_v_194_2 << 1) ^ (sec_r000255_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_211_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_211_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = (((stage_v_80_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_212_2 = (((stage_v_80_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_212_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_212_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = (((stage_v_96_1 << 2) ^ (sec_r000255_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_213_2 = (((stage_v_96_2 << 2) ^ (sec_r000255_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_213_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_213_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = (((stage_v_125_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_214_2 = (((stage_v_125_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_214_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_214_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = (((stage_v_70_1 << 2) ^ (sec_r000255_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_215_2 = (((stage_v_70_2 << 2) ^ (sec_r000255_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_215_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_215_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = (((stage_v_162_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_216_2 = (((stage_v_162_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_216_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_216_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = (((stage_v_200_1 << 1) ^ (sec_r000255_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_217_2 = (((stage_v_200_2 << 1) ^ (sec_r000255_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_217_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_217_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = (((sec_r000255_1_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_218_2 = (((sec_r000255_1_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_218_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_218_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = (((stage_v_134_1 << 1) ^ (sec_r000255_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_219_2 = (((stage_v_134_2 << 1) ^ (sec_r000255_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_219_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_219_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = (((stage_v_126_1 << 2) ^ (sec_r000255_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_220_2 = (((stage_v_126_2 << 2) ^ (sec_r000255_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_220_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_220_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = (((stage_v_24_1 << 1) ^ (sec_r000255_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_221_2 = (((stage_v_24_2 << 1) ^ (sec_r000255_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_221_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_221_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = (((stage_v_93_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_222_2 = (((stage_v_93_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_222_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_222_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = (((stage_v_143_1 << 1) ^ (sec_r000255_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_223_2 = (((stage_v_143_2 << 1) ^ (sec_r000255_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_223_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_223_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = (((sec_r000255_22_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_224_2 = (((sec_r000255_22_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_224_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_224_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = (((stage_v_157_1 << 1) ^ (sec_r000255_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_225_2 = (((stage_v_157_2 << 1) ^ (sec_r000255_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_225_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_225_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = (((stage_v_107_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_226_2 = (((stage_v_107_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_226_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_226_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = (((stage_v_194_1 << 2) ^ (sec_r000255_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_227_2 = (((stage_v_194_2 << 2) ^ (sec_r000255_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_227_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_227_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = (((stage_v_139_1 << 2) ^ (sec_r000255_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_228_2 = (((stage_v_139_2 << 2) ^ (sec_r000255_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_228_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_228_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = (((sec_r000255_20_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_229_2 = (((sec_r000255_20_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_229_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_229_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = (((stage_v_161_1 << 2) ^ (sec_r000255_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_230_2 = (((stage_v_161_2 << 2) ^ (sec_r000255_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_230_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_230_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = (((stage_v_187_1 << 2) ^ (sec_r000255_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_231_2 = (((stage_v_187_2 << 2) ^ (sec_r000255_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_231_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_231_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = (((stage_v_137_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_232_2 = (((stage_v_137_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_232_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_232_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = (((sec_r000255_3_1 << 2) ^ (sec_r000255_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_233_2 = (((sec_r000255_3_2 << 2) ^ (sec_r000255_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_233_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_233_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = (((sec_r000255_14_1 << 2) ^ (sec_r000255_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_234_2 = (((sec_r000255_14_2 << 2) ^ (sec_r000255_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_234_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_234_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = (((sec_r000255_10_1 << 1) ^ (sec_r000255_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_235_2 = (((sec_r000255_10_2 << 1) ^ (sec_r000255_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_235_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_235_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = (((stage_v_199_1 << 2) ^ (sec_r000255_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_236_2 = (((stage_v_199_2 << 2) ^ (sec_r000255_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_236_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_236_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = (((sec_r000255_6_1 << 1) ^ (sec_r000255_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_237_2 = (((sec_r000255_6_2 << 1) ^ (sec_r000255_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_237_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_237_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = (((stage_v_172_1 << 1) ^ (sec_r000255_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_238_2 = (((stage_v_172_2 << 1) ^ (sec_r000255_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_238_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_238_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = (((sec_r000255_10_1 << 2) ^ (sec_r000255_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_239_2 = (((sec_r000255_10_2 << 2) ^ (sec_r000255_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_239_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_239_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = (((stage_v_196_1 << 1) ^ (sec_r000255_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_240_2 = (((stage_v_196_2 << 1) ^ (sec_r000255_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_240_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_240_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = (((sec_r000255_14_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_241_2 = (((sec_r000255_14_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_241_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_241_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = (((stage_v_121_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_242_2 = (((stage_v_121_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_242_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_242_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = (((stage_v_143_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_243_2 = (((stage_v_143_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_243_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_243_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = (((sec_r000255_12_1 << 1) ^ (sec_r000255_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_244_2 = (((sec_r000255_12_2 << 1) ^ (sec_r000255_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_244_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_244_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = (((sec_r000255_18_1 << 1) ^ (sec_r000255_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_245_2 = (((sec_r000255_18_2 << 1) ^ (sec_r000255_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_245_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_245_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = (((stage_v_55_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_246_2 = (((stage_v_55_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_246_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_246_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = (((stage_v_144_1 << 2) ^ (sec_r000255_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_247_2 = (((stage_v_144_2 << 2) ^ (sec_r000255_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_247_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_247_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = (((sec_r000255_7_1 << 1) ^ (sec_r000255_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_248_2 = (((sec_r000255_7_2 << 1) ^ (sec_r000255_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_248_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_248_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = (((sec_r000255_2_1 << 1) ^ (sec_r000255_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_249_2 = (((sec_r000255_2_2 << 1) ^ (sec_r000255_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_249_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_249_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = (((sec_r000255_11_1 << 2) ^ (sec_r000255_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_250_2 = (((sec_r000255_11_2 << 2) ^ (sec_r000255_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_250_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_250_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = (((stage_v_184_1 << 1) ^ (sec_r000255_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_251_2 = (((stage_v_184_2 << 1) ^ (sec_r000255_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_251_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_251_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = (((sec_r000255_2_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_252_2 = (((sec_r000255_2_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_252_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_252_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = (((stage_v_208_1 << 1) ^ (sec_r000255_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_253_2 = (((stage_v_208_2 << 1) ^ (sec_r000255_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_253_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_253_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = (((sec_r000255_19_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_254_2 = (((sec_r000255_19_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_254_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_254_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = (((stage_v_111_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_255_2 = (((stage_v_111_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_255_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_255_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = (((stage_v_219_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_256_2 = (((stage_v_219_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_256_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_256_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = (((stage_v_215_1 << 1) ^ (sec_r000255_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_257_2 = (((stage_v_215_2 << 1) ^ (sec_r000255_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_257_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_257_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = (((stage_v_249_1 << 2) ^ (sec_r000255_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_258_2 = (((stage_v_249_2 << 2) ^ (sec_r000255_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_258_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_258_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = (((stage_v_257_1 << 2) ^ (sec_r000255_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_259_2 = (((stage_v_257_2 << 2) ^ (sec_r000255_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_259_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_259_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = (((stage_v_45_1 << 1) ^ (sec_r000255_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_260_2 = (((stage_v_45_2 << 1) ^ (sec_r000255_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_260_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_260_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = (((sec_r000255_21_1 << 1) ^ (sec_r000255_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_261_2 = (((sec_r000255_21_2 << 1) ^ (sec_r000255_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_261_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_261_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = (((stage_v_47_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_262_2 = (((stage_v_47_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_262_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_262_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = (((stage_v_34_1 << 1) ^ (sec_r000255_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_263_2 = (((stage_v_34_2 << 1) ^ (sec_r000255_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_263_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_263_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = (((sec_r000255_17_1 << 2) ^ (sec_r000255_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_264_2 = (((sec_r000255_17_2 << 2) ^ (sec_r000255_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_264_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_264_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = (((stage_v_111_1 << 2) ^ (sec_r000255_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_265_2 = (((stage_v_111_2 << 2) ^ (sec_r000255_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_265_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_265_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = (((stage_v_195_1 << 2) ^ (sec_r000255_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_266_2 = (((stage_v_195_2 << 2) ^ (sec_r000255_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_266_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_266_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = (((sec_r000255_4_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_267_2 = (((sec_r000255_4_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_267_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_267_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = (((stage_v_38_1 << 1) ^ (sec_r000255_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_268_2 = (((stage_v_38_2 << 1) ^ (sec_r000255_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_268_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_268_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_268_1 & 63;
  out_sink_2 ^= stage_v_268_2 & 63;
  int stage_v_269_1 = (((stage_v_240_1 << 2) ^ (sec_r000255_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_269_2 = (((stage_v_240_2 << 2) ^ (sec_r000255_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_269_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_269_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = (((stage_v_262_1 << 1) ^ (sec_r000255_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_270_2 = (((stage_v_262_2 << 1) ^ (sec_r000255_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_270_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_270_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = (((sec_r000255_0_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_271_2 = (((sec_r000255_0_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_271_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_271_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = (((stage_v_260_1 << 1) ^ (sec_r000255_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_272_2 = (((stage_v_260_2 << 1) ^ (sec_r000255_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_272_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_272_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = (((stage_v_167_1 << 1) ^ (sec_r000255_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_273_2 = (((stage_v_167_2 << 1) ^ (sec_r000255_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_273_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_273_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = (((stage_v_95_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_274_2 = (((stage_v_95_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_274_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_274_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = (((stage_v_184_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_275_2 = (((stage_v_184_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_275_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_275_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = (((sec_r000255_12_1 << 1) ^ (sec_r000255_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_276_2 = (((sec_r000255_12_2 << 1) ^ (sec_r000255_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_276_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_276_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = (((stage_v_244_1 << 1) ^ (sec_r000255_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_277_2 = (((stage_v_244_2 << 1) ^ (sec_r000255_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_277_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_277_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = (((stage_v_172_1 << 1) ^ (sec_r000255_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_278_2 = (((stage_v_172_2 << 1) ^ (sec_r000255_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_278_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_278_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = (((sec_r000255_22_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_279_2 = (((sec_r000255_22_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_279_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_279_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = (((stage_v_206_1 << 1) ^ (sec_r000255_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_280_2 = (((stage_v_206_2 << 1) ^ (sec_r000255_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_280_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_280_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = (((stage_v_36_1 << 2) ^ (sec_r000255_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_281_2 = (((stage_v_36_2 << 2) ^ (sec_r000255_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_281_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_281_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = (((stage_v_214_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_282_2 = (((stage_v_214_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_282_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_282_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = (((stage_v_33_1 << 2) ^ (sec_r000255_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_283_2 = (((stage_v_33_2 << 2) ^ (sec_r000255_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_283_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_283_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = (((sec_r000255_20_1 << 1) ^ (sec_r000255_20_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_284_2 = (((sec_r000255_20_2 << 1) ^ (sec_r000255_20_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_284_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_284_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = (((stage_v_93_1 << 2) ^ (sec_r000255_6_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_285_2 = (((stage_v_93_2 << 2) ^ (sec_r000255_6_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_285_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_285_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = (((stage_v_208_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_286_2 = (((stage_v_208_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_286_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_286_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = (((stage_v_275_1 << 2) ^ (sec_r000255_21_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_287_2 = (((stage_v_275_2 << 2) ^ (sec_r000255_21_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_287_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_287_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = (((stage_v_256_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_288_2 = (((stage_v_256_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_288_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_288_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_288_1 & 63;
  out_sink_2 ^= stage_v_288_2 & 63;
  int stage_v_289_1 = (((stage_v_115_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_289_2 = (((stage_v_115_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_289_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_289_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = (((stage_v_151_1 << 2) ^ (sec_r000255_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_290_2 = (((stage_v_151_2 << 2) ^ (sec_r000255_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_290_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_290_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = (((stage_v_116_1 << 1) ^ (sec_r000255_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_291_2 = (((stage_v_116_2 << 1) ^ (sec_r000255_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_291_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_291_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = (((stage_v_277_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_292_2 = (((stage_v_277_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_292_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_292_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = (((sec_r000255_19_1 << 1) ^ (sec_r000255_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_293_2 = (((sec_r000255_19_2 << 1) ^ (sec_r000255_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_293_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_293_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = (((sec_r000255_4_1 << 2) ^ (sec_r000255_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_294_2 = (((sec_r000255_4_2 << 2) ^ (sec_r000255_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_294_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_294_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = (((sec_r000255_8_1 << 1) ^ (sec_r000255_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_295_2 = (((sec_r000255_8_2 << 1) ^ (sec_r000255_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_295_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_295_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = (((stage_v_252_1 << 1) ^ (sec_r000255_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_296_2 = (((stage_v_252_2 << 1) ^ (sec_r000255_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_296_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_296_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = (((stage_v_223_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_297_2 = (((stage_v_223_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_297_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_297_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = (((sec_r000255_19_1 << 1) ^ (sec_r000255_19_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_298_2 = (((sec_r000255_19_2 << 1) ^ (sec_r000255_19_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_298_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_298_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = (((stage_v_268_1 << 1) ^ (sec_r000255_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_299_2 = (((stage_v_268_2 << 1) ^ (sec_r000255_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_299_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_299_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = (((sec_r000255_4_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_300_2 = (((sec_r000255_4_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_300_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_300_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = (((stage_v_222_1 << 1) ^ (sec_r000255_21_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_301_2 = (((stage_v_222_2 << 1) ^ (sec_r000255_21_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_301_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_301_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = (((sec_r000255_12_1 << 1) ^ (sec_r000255_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_302_2 = (((sec_r000255_12_2 << 1) ^ (sec_r000255_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_302_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_302_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = (((stage_v_58_1 << 1) ^ (sec_r000255_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_303_2 = (((stage_v_58_2 << 1) ^ (sec_r000255_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_303_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_303_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = (((stage_v_73_1 << 2) ^ (sec_r000255_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_304_2 = (((stage_v_73_2 << 2) ^ (sec_r000255_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_304_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_304_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = (((stage_v_204_1 << 1) ^ (sec_r000255_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_305_2 = (((stage_v_204_2 << 1) ^ (sec_r000255_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_305_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_305_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = (((stage_v_265_1 << 1) ^ (sec_r000255_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_306_2 = (((stage_v_265_2 << 1) ^ (sec_r000255_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_306_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_306_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = (((stage_v_205_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_307_2 = (((stage_v_205_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_307_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_307_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = (((stage_v_125_1 << 2) ^ (sec_r000255_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_308_2 = (((stage_v_125_2 << 2) ^ (sec_r000255_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_308_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_308_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = (((stage_v_53_1 << 2) ^ (sec_r000255_22_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_309_2 = (((stage_v_53_2 << 2) ^ (sec_r000255_22_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_309_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_309_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = (((stage_v_63_1 << 1) ^ (sec_r000255_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_310_2 = (((stage_v_63_2 << 1) ^ (sec_r000255_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_310_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_310_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = (((stage_v_255_1 << 1) ^ (sec_r000255_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_311_2 = (((stage_v_255_2 << 1) ^ (sec_r000255_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_311_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_311_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = (((stage_v_172_1 << 1) ^ (sec_r000255_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_312_2 = (((stage_v_172_2 << 1) ^ (sec_r000255_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_312_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_312_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = (((sec_r000255_16_1 << 2) ^ (sec_r000255_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_313_2 = (((sec_r000255_16_2 << 2) ^ (sec_r000255_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_313_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_313_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = (((sec_r000255_18_1 << 2) ^ (sec_r000255_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_314_2 = (((sec_r000255_18_2 << 2) ^ (sec_r000255_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_314_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_314_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_314_1 & 63;
  out_sink_2 ^= stage_v_314_2 & 63;
  int stage_v_315_1 = (((stage_v_150_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_315_2 = (((stage_v_150_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_315_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_315_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = (((sec_r000255_6_1 << 1) ^ (sec_r000255_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_316_2 = (((sec_r000255_6_2 << 1) ^ (sec_r000255_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_316_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_316_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = (((sec_r000255_3_1 << 2) ^ (sec_r000255_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_317_2 = (((sec_r000255_3_2 << 2) ^ (sec_r000255_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_317_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_317_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = (((sec_r000255_4_1 << 2) ^ (sec_r000255_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_318_2 = (((sec_r000255_4_2 << 2) ^ (sec_r000255_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_318_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_318_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = (((sec_r000255_19_1 << 2) ^ (sec_r000255_19_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_319_2 = (((sec_r000255_19_2 << 2) ^ (sec_r000255_19_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_319_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_319_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = (((stage_v_155_1 << 1) ^ (sec_r000255_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_320_2 = (((stage_v_155_2 << 1) ^ (sec_r000255_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_320_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_320_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = (((sec_r000255_18_1 << 2) ^ (sec_r000255_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_321_2 = (((sec_r000255_18_2 << 2) ^ (sec_r000255_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_321_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_321_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000255_2_1 != sec_r000255_2_2);
  __CPROVER_assume(sec_r000255_8_1 != sec_r000255_8_2);
  __CPROVER_assume(pub_r000255_2_1 == pub_r000255_2_2);
  __CPROVER_assume(sec_r000255_11_1 != sec_r000255_11_2);
  __CPROVER_assume(pub_r000255_1_1 == pub_r000255_1_2);
  __CPROVER_assume(pub_r000255_15_1 == pub_r000255_15_2);
  __CPROVER_assume(pub_r000255_11_1 == pub_r000255_11_2);
  __CPROVER_assume(sec_r000255_20_1 != sec_r000255_20_2);
  __CPROVER_assume(sec_r000255_0_1 != sec_r000255_0_2);
  __CPROVER_assume(sec_r000255_6_1 != sec_r000255_6_2);
  __CPROVER_assume(sec_r000255_7_1 != sec_r000255_7_2);
  __CPROVER_assume(sec_r000255_10_1 != sec_r000255_10_2);
  __CPROVER_assume(sec_r000255_18_1 != sec_r000255_18_2);
  __CPROVER_assume(sec_r000255_5_1 != sec_r000255_5_2);
  __CPROVER_assume(sec_r000255_21_1 != sec_r000255_21_2);
  __CPROVER_assume(sec_r000255_14_1 != sec_r000255_14_2);
  __CPROVER_assume(pub_r000255_8_1 == pub_r000255_8_2);
  __CPROVER_assume(pub_r000255_6_1 == pub_r000255_6_2);
  __CPROVER_assume(sec_r000255_15_1 != sec_r000255_15_2);
  __CPROVER_assume(pub_r000255_9_1 == pub_r000255_9_2);
  __CPROVER_assume(pub_r000255_12_1 == pub_r000255_12_2);
  __CPROVER_assume(sec_r000255_4_1 != sec_r000255_4_2);
  __CPROVER_assume(pub_r000255_3_1 == pub_r000255_3_2);
  __CPROVER_assume(pub_r000255_5_1 == pub_r000255_5_2);
  __CPROVER_assume(sec_r000255_12_1 != sec_r000255_12_2);
  __CPROVER_assume(pub_r000255_7_1 == pub_r000255_7_2);
  __CPROVER_assume(sec_r000255_9_1 != sec_r000255_9_2);
  __CPROVER_assume(sec_r000255_3_1 != sec_r000255_3_2);
  __CPROVER_assume(pub_r000255_0_1 == pub_r000255_0_2);
  __CPROVER_assume(pub_r000255_13_1 == pub_r000255_13_2);
  __CPROVER_assume(pub_r000255_14_1 == pub_r000255_14_2);
  __CPROVER_assume(pub_r000255_4_1 == pub_r000255_4_2);
  __CPROVER_assume(sec_r000255_13_1 != sec_r000255_13_2);
  __CPROVER_assume(sec_r000255_22_1 != sec_r000255_22_2);
  __CPROVER_assume(sec_r000255_17_1 != sec_r000255_17_2);
  __CPROVER_assume(sec_r000255_19_1 != sec_r000255_19_2);
  __CPROVER_assume(sec_r000255_1_1 != sec_r000255_1_2);
  __CPROVER_assume(pub_r000255_10_1 == pub_r000255_10_2);
  __CPROVER_assume(sec_r000255_16_1 != sec_r000255_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.tail == st_var_3_2.tail);
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
  assert(stage_v_313_1 == stage_v_313_2);
  assert(stage_v_314_1 == stage_v_314_2);
  assert(stage_v_315_1 == stage_v_315_2);
  assert(stage_v_316_1 == stage_v_316_2);
  assert(stage_v_317_1 == stage_v_317_2);
  assert(stage_v_318_1 == stage_v_318_2);
  assert(stage_v_319_1 == stage_v_319_2);
  assert(stage_v_320_1 == stage_v_320_2);
  assert(stage_v_321_1 == stage_v_321_2);
}


