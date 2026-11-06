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
struct Transaction_R000538_3813_0
{
  unsigned char auth_code;
  int account_id;
  short balance;
  int status;
  int buffer[3];
};
struct SensorNode_R000538_3813_1
{
  short reading;
  unsigned char calib;
  short gain;
  int buffer[3];
};
struct MatrixBlock_R000538_3813_2
{
  short trace;
  unsigned char determinant;
  int scale;
  int density;
  int stride;
  short dim;
  int buffer[3];
};
struct EventLog_R000538_3813_3
{
  unsigned char timestamp;
  int code;
  int severity;
  short facility;
  int buffer[3];
};
union PacketPayload_R000538_3813_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000538_3813_1
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
void fn_R000538_3813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st_1 = {0};
  struct EventLog_R000538_3813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int residue_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_90_1) & 63;
  aux_2 = (aux_2 + residue_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_76_1 = local_arr_1[aux_1 % 3];
  int pivot_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_76_2 * 2)) & 127;
  int checksum_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_97_1)
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

  switch (checksum_97_2)
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

  int parity_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_98_1 > 49)
  {
    acc_1 = ((acc_1 + (parity_98_1 * 2)) + 5) & 127;
    aux_1 ^= parity_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_98_2 > 49)
  {
    acc_2 = ((acc_2 + (parity_98_2 * 2)) + 5) & 127;
    aux_2 ^= parity_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_90_1 == residue_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_76_1 == pivot_76_2);
  assert(checksum_97_1 == checksum_97_2);
  assert(parity_98_1 == parity_98_2);
}

int fn_R000538_3813_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int residue_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_76 = local_arr[aux % 3];
  acc = (acc + (pivot_76 * 2)) & 127;
  int checksum_97 = (aux + st.buffer[1]) & 3;
  switch (checksum_97)
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

  int parity_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_98 > 49)
  {
    acc = ((acc + (parity_98 * 2)) + 5) & 127;
    aux ^= parity_98 & 15;
  }
  else
  {
    acc = ((acc - parity_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000538_3813_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000538_3813_2 st_1 = {0};
  struct MatrixBlock_R000538_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_74_1)
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

  switch (sample_74_2)
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

  int offset_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_58_1) & 63;
  aux_2 = (aux_2 + offset_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_74_1 == sample_74_2);
  assert(offset_58_1 == offset_58_2);
}

int fn_R000538_3813_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000538_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_74 = (aux + st.buffer[1]) & 3;
  switch (sample_74)
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

  int offset_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000538_3813_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st_1 = {0};
  struct EventLog_R000538_3813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_43_1 = local_arr_1[aux_1 % 3];
  int anchor_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_43_2 * 2)) & 127;
  int weight_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_41_1)
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

  switch (weight_41_2)
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

  int mask_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_46_1 > 48)
  {
    acc_1 = ((acc_1 + (mask_46_1 * 2)) + 5) & 127;
    aux_1 ^= mask_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_46_2 > 48)
  {
    acc_2 = ((acc_2 + (mask_46_2 * 2)) + 5) & 127;
    aux_2 ^= mask_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_43_1 == anchor_43_2);
  assert(weight_41_1 == weight_41_2);
  assert(mask_46_1 == mask_46_2);
}

int fn_R000538_3813_2(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_43 = local_arr[aux % 3];
  acc = (acc + (anchor_43 * 2)) & 127;
  int weight_41 = (aux + st.buffer[1]) & 3;
  switch (weight_41)
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

  int mask_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_46 > 48)
  {
    acc = ((acc + (mask_46 * 2)) + 5) & 127;
    aux ^= mask_46 & 15;
  }
  else
  {
    acc = ((acc - mask_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000538_3813_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st_1 = {0};
  struct Transaction_R000538_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int accumulator_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_95_1) & 63;
  aux_2 = (aux_2 + accumulator_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_10_1)
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

  switch (stride_10_2)
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
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_95_1 == accumulator_95_2);
  assert(stride_10_1 == stride_10_2);
}

int fn_R000538_3813_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int accumulator_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_95) & 63;
  acc ^= aux;
  int stride_10 = (aux + st.buffer[1]) & 3;
  switch (stride_10)
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

void fn_R000538_3813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000538_3813_1 st_1 = {0};
  struct SensorNode_R000538_3813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int coefficient_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_78_1 > 36)
  {
    acc_1 = ((acc_1 + (coefficient_78_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_78_2 > 36)
  {
    acc_2 = ((acc_2 + (coefficient_78_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_12_1) & 63;
  aux_2 = (aux_2 + index_reg_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_78_1 == coefficient_78_2);
  assert(index_reg_12_1 == index_reg_12_2);
}

int fn_R000538_3813_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000538_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int coefficient_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_78 > 36)
  {
    acc = ((acc + (coefficient_78 * 2)) + 5) & 127;
    aux ^= coefficient_78 & 15;
  }
  else
  {
    acc = ((acc - coefficient_78) + 11) & 127;
    aux += 3;
  }
  int index_reg_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_12) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000538_3813_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st_1 = {0};
  struct EventLog_R000538_3813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_64_1) & 63;
  aux_2 = (aux_2 + vector_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_98_1)
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

  switch (segment_98_2)
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

  int metric_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_94_1 > 26)
  {
    acc_1 = ((acc_1 + (metric_94_1 * 2)) + 5) & 127;
    aux_1 ^= metric_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_94_2 > 26)
  {
    acc_2 = ((acc_2 + (metric_94_2 * 2)) + 5) & 127;
    aux_2 ^= metric_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_64_1 == vector_64_2);
  assert(segment_98_1 == segment_98_2);
  assert(metric_94_1 == metric_94_2);
}

int fn_R000538_3813_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_64) & 63;
  acc ^= aux;
  int segment_98 = (aux + st.buffer[1]) & 3;
  switch (segment_98)
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

  int metric_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_94 > 26)
  {
    acc = ((acc + (metric_94 * 2)) + 5) & 127;
    aux ^= metric_94 & 15;
  }
  else
  {
    acc = ((acc - metric_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000538_3813_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000538_3813_1 st_1 = {0};
  struct SensorNode_R000538_3813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_18_1 = local_arr_1[aux_1 % 3];
  int stride_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_18_2 * 2)) & 127;
  int quantum_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_91_1 > 42)
  {
    acc_1 = ((acc_1 + (quantum_91_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_91_2 > 42)
  {
    acc_2 = ((acc_2 + (quantum_91_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_10_1)
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

  switch (segment_10_2)
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

  int threshold_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_89_1) & 63;
  aux_2 = (aux_2 + threshold_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_18_1 == stride_18_2);
  assert(quantum_91_1 == quantum_91_2);
  assert(segment_10_1 == segment_10_2);
  assert(threshold_89_1 == threshold_89_2);
}

int fn_R000538_3813_6(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000538_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int stride_18 = local_arr[aux % 3];
  acc = (acc + (stride_18 * 2)) & 127;
  int quantum_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_91 > 42)
  {
    acc = ((acc + (quantum_91 * 2)) + 5) & 127;
    aux ^= quantum_91 & 15;
  }
  else
  {
    acc = ((acc - quantum_91) + 11) & 127;
    aux += 3;
  }
  int segment_10 = (aux + st.buffer[1]) & 3;
  switch (segment_10)
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

  int threshold_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000538_3813_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st_1 = {0};
  struct EventLog_R000538_3813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_66_1 = local_arr_1[aux_1 % 3];
  int offset_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_66_1 == offset_66_2);
}

int fn_R000538_3813_7(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_66 = local_arr[aux % 3];
  acc = (acc + (offset_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000538_3813_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st_1 = {0};
  struct Transaction_R000538_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_63_1 = local_arr_1[aux_1 % 3];
  int phase_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_63_2 * 2)) & 127;
  int damping_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_57_1 > 31)
  {
    acc_1 = ((acc_1 + (damping_57_1 * 2)) + 5) & 127;
    aux_1 ^= damping_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_57_2 > 31)
  {
    acc_2 = ((acc_2 + (damping_57_2 * 2)) + 5) & 127;
    aux_2 ^= damping_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_63_1 == phase_63_2);
  assert(damping_57_1 == damping_57_2);
}

int fn_R000538_3813_8(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int phase_63 = local_arr[aux % 3];
  acc = (acc + (phase_63 * 2)) & 127;
  int damping_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_57 > 31)
  {
    acc = ((acc + (damping_57 * 2)) + 5) & 127;
    aux ^= damping_57 & 15;
  }
  else
  {
    acc = ((acc - damping_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000538_3813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000538_3813_1 st_1 = {0};
  struct SensorNode_R000538_3813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int scale_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_48_1) & 63;
  aux_2 = (aux_2 + scale_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_21_1 = local_arr_1[aux_1 % 3];
  int stride_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_21_2 * 2)) & 127;
  int mask_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_51_1 > 50)
  {
    acc_1 = ((acc_1 + (mask_51_1 * 2)) + 5) & 127;
    aux_1 ^= mask_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_51_2 > 50)
  {
    acc_2 = ((acc_2 + (mask_51_2 * 2)) + 5) & 127;
    aux_2 ^= mask_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_48_1 == scale_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_21_1 == stride_21_2);
  assert(mask_51_1 == mask_51_2);
}

int fn_R000538_3813_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000538_3813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int scale_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_21 = local_arr[aux % 3];
  acc = (acc + (stride_21 * 2)) & 127;
  int mask_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_51 > 50)
  {
    acc = ((acc + (mask_51 * 2)) + 5) & 127;
    aux ^= mask_51 & 15;
  }
  else
  {
    acc = ((acc - mask_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000538_3813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000538_3813_2 st_1 = {0};
  struct MatrixBlock_R000538_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_38_1 = local_arr_1[aux_1 % 3];
  int scale_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_38_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_43_1)
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

  switch (coefficient_43_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_38_1 == scale_38_2);
  assert(coefficient_43_1 == coefficient_43_2);
}

int fn_R000538_3813_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000538_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int scale_38 = local_arr[aux % 3];
  acc = (acc + (scale_38 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_43 = (aux + st.buffer[1]) & 3;
  switch (coefficient_43)
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

void fn_R000538_3813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st_1 = {0};
  struct Transaction_R000538_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int scale_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_36_1 > 12)
  {
    acc_1 = ((acc_1 + (scale_36_1 * 2)) + 5) & 127;
    aux_1 ^= scale_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_36_2 > 12)
  {
    acc_2 = ((acc_2 + (scale_36_2 * 2)) + 5) & 127;
    aux_2 ^= scale_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_36_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_22_1 = local_arr_1[aux_1 % 3];
  int phase_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_36_1 == scale_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_22_1 == phase_22_2);
}

int fn_R000538_3813_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int scale_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_36 > 12)
  {
    acc = ((acc + (scale_36 * 2)) + 5) & 127;
    aux ^= scale_36 & 15;
  }
  else
  {
    acc = ((acc - scale_36) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_22 = local_arr[aux % 3];
  acc = (acc + (phase_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000538_3813_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st_1 = {0};
  struct Transaction_R000538_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int metric_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_14_1) & 63;
  aux_2 = (aux_2 + metric_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_95_1 = local_arr_1[aux_1 % 3];
  int cursor_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_14_1 == metric_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_95_1 == cursor_95_2);
}

int fn_R000538_3813_12(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int metric_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_14) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_95 = local_arr[aux % 3];
  acc = (acc + (cursor_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000538_3813_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000538_3813_2 st_1 = {0};
  struct MatrixBlock_R000538_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_22_1) & 63;
  aux_2 = (aux_2 + phase_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_48_1)
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

  switch (cursor_48_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_95_1 = local_arr_1[aux_1 % 3];
  int metric_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_22_1 == phase_22_2);
  assert(cursor_48_1 == cursor_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_95_1 == metric_95_2);
}

int fn_R000538_3813_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000538_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_22) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_48 = (aux + st.buffer[1]) & 3;
  switch (cursor_48)
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

  int local_arr[3] = {4, 9, 15};
  int metric_95 = local_arr[aux % 3];
  acc = (acc + (metric_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000538_3813_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st_1 = {0};
  struct EventLog_R000538_3813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_63_1 = local_arr_1[aux_1 % 3];
  int checksum_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_63_2 * 2)) & 127;
  int stride_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_67_1 > 30)
  {
    acc_1 = ((acc_1 + (stride_67_1 * 2)) + 5) & 127;
    aux_1 ^= stride_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_67_2 > 30)
  {
    acc_2 = ((acc_2 + (stride_67_2 * 2)) + 5) & 127;
    aux_2 ^= stride_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_63_1 == checksum_63_2);
  assert(stride_67_1 == stride_67_2);
}

int fn_R000538_3813_14(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int checksum_63 = local_arr[aux % 3];
  acc = (acc + (checksum_63 * 2)) & 127;
  int stride_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_67 > 30)
  {
    acc = ((acc + (stride_67 * 2)) + 5) & 127;
    aux ^= stride_67 & 15;
  }
  else
  {
    acc = ((acc - stride_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000538_3813_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st_1 = {0};
  struct EventLog_R000538_3813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_24_1 = local_arr_1[aux_1 % 3];
  int pivot_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_24_2 * 2)) & 127;
  int tracker_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_97_1 > 47)
  {
    acc_1 = ((acc_1 + (tracker_97_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_97_2 > 47)
  {
    acc_2 = ((acc_2 + (tracker_97_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_52_1)
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

  switch (scale_52_2)
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

  int accumulator_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_44_1) & 63;
  aux_2 = (aux_2 + accumulator_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_24_1 == pivot_24_2);
  assert(tracker_97_1 == tracker_97_2);
  assert(scale_52_1 == scale_52_2);
  assert(accumulator_44_1 == accumulator_44_2);
}

int fn_R000538_3813_15(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int pivot_24 = local_arr[aux % 3];
  acc = (acc + (pivot_24 * 2)) & 127;
  int tracker_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_97 > 47)
  {
    acc = ((acc + (tracker_97 * 2)) + 5) & 127;
    aux ^= tracker_97 & 15;
  }
  else
  {
    acc = ((acc - tracker_97) + 11) & 127;
    aux += 3;
  }
  int scale_52 = (aux + st.buffer[1]) & 3;
  switch (scale_52)
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

  int accumulator_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000538_3813_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000538_3813_2 st_1 = {0};
  struct MatrixBlock_R000538_3813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int segment_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_48_1 > 38)
  {
    acc_1 = ((acc_1 + (segment_48_1 * 2)) + 5) & 127;
    aux_1 ^= segment_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_48_2 > 38)
  {
    acc_2 = ((acc_2 + (segment_48_2 * 2)) + 5) & 127;
    aux_2 ^= segment_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_31_1) & 63;
  aux_2 = (aux_2 + residue_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_48_1 == segment_48_2);
  assert(residue_31_1 == residue_31_2);
}

int fn_R000538_3813_16(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000538_3813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int segment_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_48 > 38)
  {
    acc = ((acc + (segment_48 * 2)) + 5) & 127;
    aux ^= segment_48 & 15;
  }
  else
  {
    acc = ((acc - segment_48) + 11) & 127;
    aux += 3;
  }
  int residue_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000538_3813_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st_1 = {0};
  struct Transaction_R000538_3813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int phase_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_89_1) & 63;
  aux_2 = (aux_2 + phase_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_72_1 = local_arr_1[aux_1 % 3];
  int scale_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_89_1 == phase_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_72_1 == scale_72_2);
}

int fn_R000538_3813_17(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000538_3813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int phase_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_89) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_72 = local_arr[aux % 3];
  acc = (acc + (scale_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000538_3813_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st_1 = {0};
  struct EventLog_R000538_3813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int segment_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_72_1) & 63;
  aux_2 = (aux_2 + segment_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_72_1 == segment_72_2);
}

int fn_R000538_3813_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000538_3813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int segment_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_72) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000538_0_1;
  int sec_r000538_0_2;
  int sec_r000538_1_1;
  int sec_r000538_1_2;
  int sec_r000538_2_1;
  int sec_r000538_2_2;
  int sec_r000538_3_1;
  int sec_r000538_3_2;
  int sec_r000538_4_1;
  int sec_r000538_4_2;
  int sec_r000538_5_1;
  int sec_r000538_5_2;
  int sec_r000538_6_1;
  int sec_r000538_6_2;
  int sec_r000538_7_1;
  int sec_r000538_7_2;
  int sec_r000538_8_1;
  int sec_r000538_8_2;
  int sec_r000538_9_1;
  int sec_r000538_9_2;
  int sec_r000538_10_1;
  int sec_r000538_10_2;
  int sec_r000538_11_1;
  int sec_r000538_11_2;
  int sec_r000538_12_1;
  int sec_r000538_12_2;
  int sec_r000538_13_1;
  int sec_r000538_13_2;
  int sec_r000538_14_1;
  int sec_r000538_14_2;
  int sec_r000538_15_1;
  int sec_r000538_15_2;
  int pub_r000538_0_1;
  int pub_r000538_0_2;
  int pub_r000538_1_1;
  int pub_r000538_1_2;
  int pub_r000538_2_1;
  int pub_r000538_2_2;
  int pub_r000538_3_1;
  int pub_r000538_3_2;
  int pub_r000538_4_1;
  int pub_r000538_4_2;
  int pub_r000538_5_1;
  int pub_r000538_5_2;
  int pub_r000538_6_1;
  int pub_r000538_6_2;
  int pub_r000538_7_1;
  int pub_r000538_7_2;
  int pub_r000538_8_1;
  int pub_r000538_8_2;
  int pub_r000538_9_1;
  int pub_r000538_9_2;
  int pub_r000538_10_1;
  int pub_r000538_10_2;
  int pub_r000538_11_1;
  int pub_r000538_11_2;
  int pub_r000538_12_1;
  int pub_r000538_12_2;
  int pub_r000538_13_1;
  int pub_r000538_13_2;
  int pub_r000538_14_1;
  int pub_r000538_14_2;
  int pub_r000538_15_1;
  int pub_r000538_15_2;
  int pub_r000538_16_1;
  int pub_r000538_16_2;
  int pub_r000538_17_1;
  int pub_r000538_17_2;
  int pub_r000538_18_1;
  int pub_r000538_18_2;
  int pub_r000538_19_1;
  int pub_r000538_19_2;
  int pub_r000538_20_1;
  int pub_r000538_20_2;
  int pub_r000538_21_1;
  int pub_r000538_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000538_0_1 >= (-100)) && (pub_r000538_0_1 <= 100));
  __CPROVER_assume((pub_r000538_0_2 >= (-100)) && (pub_r000538_0_2 <= 100));
  __CPROVER_assume((pub_r000538_1_1 >= (-100)) && (pub_r000538_1_1 <= 100));
  __CPROVER_assume((pub_r000538_1_2 >= (-100)) && (pub_r000538_1_2 <= 100));
  __CPROVER_assume((pub_r000538_2_1 >= (-100)) && (pub_r000538_2_1 <= 100));
  __CPROVER_assume((pub_r000538_2_2 >= (-100)) && (pub_r000538_2_2 <= 100));
  __CPROVER_assume((pub_r000538_3_1 >= (-100)) && (pub_r000538_3_1 <= 100));
  __CPROVER_assume((pub_r000538_3_2 >= (-100)) && (pub_r000538_3_2 <= 100));
  __CPROVER_assume((pub_r000538_4_1 >= (-100)) && (pub_r000538_4_1 <= 100));
  __CPROVER_assume((pub_r000538_4_2 >= (-100)) && (pub_r000538_4_2 <= 100));
  __CPROVER_assume((pub_r000538_5_1 >= (-100)) && (pub_r000538_5_1 <= 100));
  __CPROVER_assume((pub_r000538_5_2 >= (-100)) && (pub_r000538_5_2 <= 100));
  __CPROVER_assume((pub_r000538_6_1 >= (-100)) && (pub_r000538_6_1 <= 100));
  __CPROVER_assume((pub_r000538_6_2 >= (-100)) && (pub_r000538_6_2 <= 100));
  __CPROVER_assume((pub_r000538_7_1 >= (-100)) && (pub_r000538_7_1 <= 100));
  __CPROVER_assume((pub_r000538_7_2 >= (-100)) && (pub_r000538_7_2 <= 100));
  __CPROVER_assume((pub_r000538_8_1 >= (-100)) && (pub_r000538_8_1 <= 100));
  __CPROVER_assume((pub_r000538_8_2 >= (-100)) && (pub_r000538_8_2 <= 100));
  __CPROVER_assume((pub_r000538_9_1 >= (-100)) && (pub_r000538_9_1 <= 100));
  __CPROVER_assume((pub_r000538_9_2 >= (-100)) && (pub_r000538_9_2 <= 100));
  __CPROVER_assume((pub_r000538_10_1 >= (-100)) && (pub_r000538_10_1 <= 100));
  __CPROVER_assume((pub_r000538_10_2 >= (-100)) && (pub_r000538_10_2 <= 100));
  __CPROVER_assume((pub_r000538_11_1 >= (-100)) && (pub_r000538_11_1 <= 100));
  __CPROVER_assume((pub_r000538_11_2 >= (-100)) && (pub_r000538_11_2 <= 100));
  __CPROVER_assume((pub_r000538_12_1 >= (-100)) && (pub_r000538_12_1 <= 100));
  __CPROVER_assume((pub_r000538_12_2 >= (-100)) && (pub_r000538_12_2 <= 100));
  __CPROVER_assume((pub_r000538_13_1 >= (-100)) && (pub_r000538_13_1 <= 100));
  __CPROVER_assume((pub_r000538_13_2 >= (-100)) && (pub_r000538_13_2 <= 100));
  __CPROVER_assume((pub_r000538_14_1 >= (-100)) && (pub_r000538_14_1 <= 100));
  __CPROVER_assume((pub_r000538_14_2 >= (-100)) && (pub_r000538_14_2 <= 100));
  __CPROVER_assume((pub_r000538_15_1 >= (-100)) && (pub_r000538_15_1 <= 100));
  __CPROVER_assume((pub_r000538_15_2 >= (-100)) && (pub_r000538_15_2 <= 100));
  __CPROVER_assume((pub_r000538_16_1 >= (-100)) && (pub_r000538_16_1 <= 100));
  __CPROVER_assume((pub_r000538_16_2 >= (-100)) && (pub_r000538_16_2 <= 100));
  __CPROVER_assume((pub_r000538_17_1 >= (-100)) && (pub_r000538_17_1 <= 100));
  __CPROVER_assume((pub_r000538_17_2 >= (-100)) && (pub_r000538_17_2 <= 100));
  __CPROVER_assume((pub_r000538_18_1 >= (-100)) && (pub_r000538_18_1 <= 100));
  __CPROVER_assume((pub_r000538_18_2 >= (-100)) && (pub_r000538_18_2 <= 100));
  __CPROVER_assume((pub_r000538_19_1 >= (-100)) && (pub_r000538_19_1 <= 100));
  __CPROVER_assume((pub_r000538_19_2 >= (-100)) && (pub_r000538_19_2 <= 100));
  __CPROVER_assume((pub_r000538_20_1 >= (-100)) && (pub_r000538_20_1 <= 100));
  __CPROVER_assume((pub_r000538_20_2 >= (-100)) && (pub_r000538_20_2 <= 100));
  __CPROVER_assume((pub_r000538_21_1 >= (-100)) && (pub_r000538_21_1 <= 100));
  __CPROVER_assume((pub_r000538_21_2 >= (-100)) && (pub_r000538_21_2 <= 100));
  __CPROVER_assume((sec_r000538_0_1 >= 0) && (sec_r000538_0_1 <= 255));
  __CPROVER_assume((sec_r000538_0_2 >= 0) && (sec_r000538_0_2 <= 255));
  __CPROVER_assume((sec_r000538_1_1 >= 0) && (sec_r000538_1_1 <= 255));
  __CPROVER_assume((sec_r000538_1_2 >= 0) && (sec_r000538_1_2 <= 255));
  __CPROVER_assume((sec_r000538_2_1 >= 0) && (sec_r000538_2_1 <= 255));
  __CPROVER_assume((sec_r000538_2_2 >= 0) && (sec_r000538_2_2 <= 255));
  __CPROVER_assume((sec_r000538_3_1 >= 0) && (sec_r000538_3_1 <= 255));
  __CPROVER_assume((sec_r000538_3_2 >= 0) && (sec_r000538_3_2 <= 255));
  __CPROVER_assume((sec_r000538_4_1 >= 0) && (sec_r000538_4_1 <= 255));
  __CPROVER_assume((sec_r000538_4_2 >= 0) && (sec_r000538_4_2 <= 255));
  __CPROVER_assume((sec_r000538_5_1 >= 0) && (sec_r000538_5_1 <= 255));
  __CPROVER_assume((sec_r000538_5_2 >= 0) && (sec_r000538_5_2 <= 255));
  __CPROVER_assume((sec_r000538_6_1 >= 0) && (sec_r000538_6_1 <= 255));
  __CPROVER_assume((sec_r000538_6_2 >= 0) && (sec_r000538_6_2 <= 255));
  __CPROVER_assume((sec_r000538_7_1 >= 0) && (sec_r000538_7_1 <= 255));
  __CPROVER_assume((sec_r000538_7_2 >= 0) && (sec_r000538_7_2 <= 255));
  __CPROVER_assume((sec_r000538_8_1 >= 0) && (sec_r000538_8_1 <= 255));
  __CPROVER_assume((sec_r000538_8_2 >= 0) && (sec_r000538_8_2 <= 255));
  __CPROVER_assume((sec_r000538_9_1 >= 0) && (sec_r000538_9_1 <= 255));
  __CPROVER_assume((sec_r000538_9_2 >= 0) && (sec_r000538_9_2 <= 255));
  __CPROVER_assume((sec_r000538_10_1 >= 0) && (sec_r000538_10_1 <= 255));
  __CPROVER_assume((sec_r000538_10_2 >= 0) && (sec_r000538_10_2 <= 255));
  __CPROVER_assume((sec_r000538_11_1 >= 0) && (sec_r000538_11_1 <= 255));
  __CPROVER_assume((sec_r000538_11_2 >= 0) && (sec_r000538_11_2 <= 255));
  __CPROVER_assume((sec_r000538_12_1 >= 0) && (sec_r000538_12_1 <= 255));
  __CPROVER_assume((sec_r000538_12_2 >= 0) && (sec_r000538_12_2 <= 255));
  __CPROVER_assume((sec_r000538_13_1 >= 0) && (sec_r000538_13_1 <= 255));
  __CPROVER_assume((sec_r000538_13_2 >= 0) && (sec_r000538_13_2 <= 255));
  __CPROVER_assume((sec_r000538_14_1 >= 0) && (sec_r000538_14_1 <= 255));
  __CPROVER_assume((sec_r000538_14_2 >= 0) && (sec_r000538_14_2 <= 255));
  __CPROVER_assume((sec_r000538_15_1 >= 0) && (sec_r000538_15_1 <= 255));
  __CPROVER_assume((sec_r000538_15_2 >= 0) && (sec_r000538_15_2 <= 255));
  struct Transaction_R000538_3813_0 st_var_0_1 = {0};
  struct Transaction_R000538_3813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000538_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000538_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000538_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000538_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000538_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000538_0_2 + 7) & 15;
  struct SensorNode_R000538_3813_1 st_var_1_1 = {0};
  struct SensorNode_R000538_3813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000538_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000538_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000538_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000538_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000538_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000538_0_2 + 9) & 15;
  struct MatrixBlock_R000538_3813_2 st_var_2_1 = {0};
  struct MatrixBlock_R000538_3813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000538_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000538_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000538_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000538_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000538_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000538_0_2 + 11) & 15;
  struct EventLog_R000538_3813_3 st_var_3_1 = {0};
  struct EventLog_R000538_3813_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000538_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000538_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000538_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000538_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000538_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000538_0_2 + 13) & 15;
  union PacketPayload_R000538_3813_0 u_var_1;
  union PacketPayload_R000538_3813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
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
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
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
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
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
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = (st_var_3_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_3_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 30) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 30) & 15;
  int stage_v_29_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_29_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= stage_v_29_1;
  chk_sum_2 ^= stage_v_29_2;
  int stage_v_30_1 = (st_var_2_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_2_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = ((st_var_3_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_3_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 36)
    {
      chk_sum_1 ^= stage_v_31_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_31_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 36)
    {
      chk_sum_2 ^= stage_v_31_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000538_14_1 & 1) == step_1)
    {
      stage_v_33_1 = ((stage_v_33_1 + (step_1 * 4)) + pub_r000538_0_1) & 63;
    }
    else
    {
      stage_v_33_1 = ((stage_v_33_1 + pub_r000538_4_1) + 5) & 63;
    }
    if ((sec_r000538_14_2 & 1) == step_2)
    {
      stage_v_33_2 = ((stage_v_33_2 + (step_2 * 4)) + pub_r000538_0_2) & 63;
    }
    else
    {
      stage_v_33_2 = ((stage_v_33_2 + pub_r000538_4_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000538_15_1 & 1) == step_1)
    {
      stage_v_34_1 = ((stage_v_34_1 + (step_1 * 4)) + pub_r000538_20_1) & 63;
    }
    else
    {
      stage_v_34_1 = ((stage_v_34_1 + pub_r000538_19_1) + 5) & 63;
    }
    if ((sec_r000538_15_2 & 1) == step_2)
    {
      stage_v_34_2 = ((stage_v_34_2 + (step_2 * 4)) + pub_r000538_20_2) & 63;
    }
    else
    {
      stage_v_34_2 = ((stage_v_34_2 + pub_r000538_19_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_34_1 & 1) == step_1)
    {
      stage_v_35_1 = ((stage_v_35_1 + (step_1 * 4)) + pub_r000538_14_1) & 63;
    }
    else
    {
      stage_v_35_1 = ((stage_v_35_1 + pub_r000538_16_1) + 5) & 63;
    }
    if ((stage_v_34_2 & 1) == step_2)
    {
      stage_v_35_2 = ((stage_v_35_2 + (step_2 * 4)) + pub_r000538_14_2) & 63;
    }
    else
    {
      stage_v_35_2 = ((stage_v_35_2 + pub_r000538_16_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_36_1 = ((stage_v_36_1 + (step_1 * 4)) + pub_r000538_11_1) & 63;
    }
    else
    {
      stage_v_36_1 = ((stage_v_36_1 + pub_r000538_10_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_36_2 = ((stage_v_36_2 + (step_2 * 4)) + pub_r000538_11_2) & 63;
    }
    else
    {
      stage_v_36_2 = ((stage_v_36_2 + pub_r000538_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_33_1 & 1) == step_1)
    {
      stage_v_37_1 = ((stage_v_37_1 + (step_1 * 4)) + pub_r000538_8_1) & 63;
    }
    else
    {
      stage_v_37_1 = ((stage_v_37_1 + pub_r000538_12_1) + 5) & 63;
    }
    if ((stage_v_33_2 & 1) == step_2)
    {
      stage_v_37_2 = ((stage_v_37_2 + (step_2 * 4)) + pub_r000538_8_2) & 63;
    }
    else
    {
      stage_v_37_2 = ((stage_v_37_2 + pub_r000538_12_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000538_13_1 & 1) == step_1)
    {
      stage_v_38_1 = ((stage_v_38_1 + (step_1 * 4)) + pub_r000538_16_1) & 63;
    }
    else
    {
      stage_v_38_1 = ((stage_v_38_1 + pub_r000538_10_1) + 5) & 63;
    }
    if ((sec_r000538_13_2 & 1) == step_2)
    {
      stage_v_38_2 = ((stage_v_38_2 + (step_2 * 4)) + pub_r000538_16_2) & 63;
    }
    else
    {
      stage_v_38_2 = ((stage_v_38_2 + pub_r000538_10_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000538_14_1 & 1) == step_1)
    {
      stage_v_39_1 = ((stage_v_39_1 + (step_1 * 4)) + pub_r000538_13_1) & 63;
    }
    else
    {
      stage_v_39_1 = ((stage_v_39_1 + pub_r000538_1_1) + 5) & 63;
    }
    if ((sec_r000538_14_2 & 1) == step_2)
    {
      stage_v_39_2 = ((stage_v_39_2 + (step_2 * 4)) + pub_r000538_13_2) & 63;
    }
    else
    {
      stage_v_39_2 = ((stage_v_39_2 + pub_r000538_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((sec_r000538_8_1 & 1) == step_1)
    {
      stage_v_40_1 = ((stage_v_40_1 + (step_1 * 4)) + pub_r000538_9_1) & 63;
    }
    else
    {
      stage_v_40_1 = ((stage_v_40_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((sec_r000538_8_2 & 1) == step_2)
    {
      stage_v_40_2 = ((stage_v_40_2 + (step_2 * 4)) + pub_r000538_9_2) & 63;
    }
    else
    {
      stage_v_40_2 = ((stage_v_40_2 + pub_r000538_9_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_37_1 & 1) == step_1)
    {
      stage_v_41_1 = ((stage_v_41_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_41_1 = ((stage_v_41_1 + pub_r000538_14_1) + 5) & 63;
    }
    if ((stage_v_37_2 & 1) == step_2)
    {
      stage_v_41_2 = ((stage_v_41_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_41_2 = ((stage_v_41_2 + pub_r000538_14_2) + 5) & 63;
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
    if ((stage_v_41_1 & 1) == step_1)
    {
      stage_v_42_1 = ((stage_v_42_1 + (step_1 * 4)) + pub_r000538_20_1) & 63;
    }
    else
    {
      stage_v_42_1 = ((stage_v_42_1 + pub_r000538_17_1) + 5) & 63;
    }
    if ((stage_v_41_2 & 1) == step_2)
    {
      stage_v_42_2 = ((stage_v_42_2 + (step_2 * 4)) + pub_r000538_20_2) & 63;
    }
    else
    {
      stage_v_42_2 = ((stage_v_42_2 + pub_r000538_17_2) + 5) & 63;
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
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_43_1 = ((stage_v_43_1 + (step_1 * 4)) + pub_r000538_6_1) & 63;
    }
    else
    {
      stage_v_43_1 = ((stage_v_43_1 + pub_r000538_6_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_43_2 = ((stage_v_43_2 + (step_2 * 4)) + pub_r000538_6_2) & 63;
    }
    else
    {
      stage_v_43_2 = ((stage_v_43_2 + pub_r000538_6_2) + 5) & 63;
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
    if ((stage_v_33_1 & 1) == step_1)
    {
      stage_v_44_1 = ((stage_v_44_1 + (step_1 * 4)) + pub_r000538_5_1) & 63;
    }
    else
    {
      stage_v_44_1 = ((stage_v_44_1 + pub_r000538_0_1) + 5) & 63;
    }
    if ((stage_v_33_2 & 1) == step_2)
    {
      stage_v_44_2 = ((stage_v_44_2 + (step_2 * 4)) + pub_r000538_5_2) & 63;
    }
    else
    {
      stage_v_44_2 = ((stage_v_44_2 + pub_r000538_0_2) + 5) & 63;
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
    if ((stage_v_43_1 & 1) == step_1)
    {
      stage_v_45_1 = ((stage_v_45_1 + (step_1 * 4)) + pub_r000538_2_1) & 63;
    }
    else
    {
      stage_v_45_1 = ((stage_v_45_1 + pub_r000538_2_1) + 5) & 63;
    }
    if ((stage_v_43_2 & 1) == step_2)
    {
      stage_v_45_2 = ((stage_v_45_2 + (step_2 * 4)) + pub_r000538_2_2) & 63;
    }
    else
    {
      stage_v_45_2 = ((stage_v_45_2 + pub_r000538_2_2) + 5) & 63;
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
    if ((sec_r000538_7_1 & 1) == step_1)
    {
      stage_v_46_1 = ((stage_v_46_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_46_1 = ((stage_v_46_1 + pub_r000538_19_1) + 5) & 63;
    }
    if ((sec_r000538_7_2 & 1) == step_2)
    {
      stage_v_46_2 = ((stage_v_46_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_46_2 = ((stage_v_46_2 + pub_r000538_19_2) + 5) & 63;
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
    if ((sec_r000538_11_1 & 1) == step_1)
    {
      stage_v_47_1 = ((stage_v_47_1 + (step_1 * 4)) + pub_r000538_19_1) & 63;
    }
    else
    {
      stage_v_47_1 = ((stage_v_47_1 + pub_r000538_6_1) + 5) & 63;
    }
    if ((sec_r000538_11_2 & 1) == step_2)
    {
      stage_v_47_2 = ((stage_v_47_2 + (step_2 * 4)) + pub_r000538_19_2) & 63;
    }
    else
    {
      stage_v_47_2 = ((stage_v_47_2 + pub_r000538_6_2) + 5) & 63;
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
    if ((stage_v_45_1 & 1) == step_1)
    {
      stage_v_48_1 = ((stage_v_48_1 + (step_1 * 4)) + pub_r000538_9_1) & 63;
    }
    else
    {
      stage_v_48_1 = ((stage_v_48_1 + pub_r000538_10_1) + 5) & 63;
    }
    if ((stage_v_45_2 & 1) == step_2)
    {
      stage_v_48_2 = ((stage_v_48_2 + (step_2 * 4)) + pub_r000538_9_2) & 63;
    }
    else
    {
      stage_v_48_2 = ((stage_v_48_2 + pub_r000538_10_2) + 5) & 63;
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
    if ((stage_v_35_1 & 1) == step_1)
    {
      stage_v_49_1 = ((stage_v_49_1 + (step_1 * 4)) + pub_r000538_14_1) & 63;
    }
    else
    {
      stage_v_49_1 = ((stage_v_49_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((stage_v_35_2 & 1) == step_2)
    {
      stage_v_49_2 = ((stage_v_49_2 + (step_2 * 4)) + pub_r000538_14_2) & 63;
    }
    else
    {
      stage_v_49_2 = ((stage_v_49_2 + pub_r000538_9_2) + 5) & 63;
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
    if ((stage_v_49_1 & 1) == step_1)
    {
      stage_v_50_1 = ((stage_v_50_1 + (step_1 * 4)) + pub_r000538_0_1) & 63;
    }
    else
    {
      stage_v_50_1 = ((stage_v_50_1 + pub_r000538_7_1) + 5) & 63;
    }
    if ((stage_v_49_2 & 1) == step_2)
    {
      stage_v_50_2 = ((stage_v_50_2 + (step_2 * 4)) + pub_r000538_0_2) & 63;
    }
    else
    {
      stage_v_50_2 = ((stage_v_50_2 + pub_r000538_7_2) + 5) & 63;
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
    if ((stage_v_36_1 & 1) == step_1)
    {
      stage_v_51_1 = ((stage_v_51_1 + (step_1 * 4)) + pub_r000538_14_1) & 63;
    }
    else
    {
      stage_v_51_1 = ((stage_v_51_1 + pub_r000538_5_1) + 5) & 63;
    }
    if ((stage_v_36_2 & 1) == step_2)
    {
      stage_v_51_2 = ((stage_v_51_2 + (step_2 * 4)) + pub_r000538_14_2) & 63;
    }
    else
    {
      stage_v_51_2 = ((stage_v_51_2 + pub_r000538_5_2) + 5) & 63;
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
      stage_v_52_1 = ((stage_v_52_1 + (step_1 * 4)) + pub_r000538_4_1) & 63;
    }
    else
    {
      stage_v_52_1 = ((stage_v_52_1 + pub_r000538_8_1) + 5) & 63;
    }
    if ((stage_v_45_2 & 1) == step_2)
    {
      stage_v_52_2 = ((stage_v_52_2 + (step_2 * 4)) + pub_r000538_4_2) & 63;
    }
    else
    {
      stage_v_52_2 = ((stage_v_52_2 + pub_r000538_8_2) + 5) & 63;
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
    if ((stage_v_34_1 & 1) == step_1)
    {
      stage_v_53_1 = ((stage_v_53_1 + (step_1 * 4)) + pub_r000538_14_1) & 63;
    }
    else
    {
      stage_v_53_1 = ((stage_v_53_1 + pub_r000538_7_1) + 5) & 63;
    }
    if ((stage_v_34_2 & 1) == step_2)
    {
      stage_v_53_2 = ((stage_v_53_2 + (step_2 * 4)) + pub_r000538_14_2) & 63;
    }
    else
    {
      stage_v_53_2 = ((stage_v_53_2 + pub_r000538_7_2) + 5) & 63;
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
    if ((stage_v_50_1 & 1) == step_1)
    {
      stage_v_54_1 = ((stage_v_54_1 + (step_1 * 4)) + pub_r000538_11_1) & 63;
    }
    else
    {
      stage_v_54_1 = ((stage_v_54_1 + pub_r000538_14_1) + 5) & 63;
    }
    if ((stage_v_50_2 & 1) == step_2)
    {
      stage_v_54_2 = ((stage_v_54_2 + (step_2 * 4)) + pub_r000538_11_2) & 63;
    }
    else
    {
      stage_v_54_2 = ((stage_v_54_2 + pub_r000538_14_2) + 5) & 63;
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
    if ((stage_v_47_1 & 1) == step_1)
    {
      stage_v_55_1 = ((stage_v_55_1 + (step_1 * 4)) + pub_r000538_16_1) & 63;
    }
    else
    {
      stage_v_55_1 = ((stage_v_55_1 + pub_r000538_18_1) + 5) & 63;
    }
    if ((stage_v_47_2 & 1) == step_2)
    {
      stage_v_55_2 = ((stage_v_55_2 + (step_2 * 4)) + pub_r000538_16_2) & 63;
    }
    else
    {
      stage_v_55_2 = ((stage_v_55_2 + pub_r000538_18_2) + 5) & 63;
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
    if ((stage_v_45_1 & 1) == step_1)
    {
      stage_v_56_1 = ((stage_v_56_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_56_1 = ((stage_v_56_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((stage_v_45_2 & 1) == step_2)
    {
      stage_v_56_2 = ((stage_v_56_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_56_2 = ((stage_v_56_2 + pub_r000538_9_2) + 5) & 63;
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
    if ((sec_r000538_15_1 & 1) == step_1)
    {
      stage_v_57_1 = ((stage_v_57_1 + (step_1 * 4)) + pub_r000538_4_1) & 63;
    }
    else
    {
      stage_v_57_1 = ((stage_v_57_1 + pub_r000538_1_1) + 5) & 63;
    }
    if ((sec_r000538_15_2 & 1) == step_2)
    {
      stage_v_57_2 = ((stage_v_57_2 + (step_2 * 4)) + pub_r000538_4_2) & 63;
    }
    else
    {
      stage_v_57_2 = ((stage_v_57_2 + pub_r000538_1_2) + 5) & 63;
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
    if ((sec_r000538_4_1 & 1) == step_1)
    {
      stage_v_58_1 = ((stage_v_58_1 + (step_1 * 4)) + pub_r000538_8_1) & 63;
    }
    else
    {
      stage_v_58_1 = ((stage_v_58_1 + pub_r000538_4_1) + 5) & 63;
    }
    if ((sec_r000538_4_2 & 1) == step_2)
    {
      stage_v_58_2 = ((stage_v_58_2 + (step_2 * 4)) + pub_r000538_8_2) & 63;
    }
    else
    {
      stage_v_58_2 = ((stage_v_58_2 + pub_r000538_4_2) + 5) & 63;
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
    if ((stage_v_43_1 & 1) == step_1)
    {
      stage_v_59_1 = ((stage_v_59_1 + (step_1 * 4)) + pub_r000538_19_1) & 63;
    }
    else
    {
      stage_v_59_1 = ((stage_v_59_1 + pub_r000538_7_1) + 5) & 63;
    }
    if ((stage_v_43_2 & 1) == step_2)
    {
      stage_v_59_2 = ((stage_v_59_2 + (step_2 * 4)) + pub_r000538_19_2) & 63;
    }
    else
    {
      stage_v_59_2 = ((stage_v_59_2 + pub_r000538_7_2) + 5) & 63;
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
    if ((stage_v_40_1 & 1) == step_1)
    {
      stage_v_60_1 = ((stage_v_60_1 + (step_1 * 4)) + pub_r000538_19_1) & 63;
    }
    else
    {
      stage_v_60_1 = ((stage_v_60_1 + pub_r000538_10_1) + 5) & 63;
    }
    if ((stage_v_40_2 & 1) == step_2)
    {
      stage_v_60_2 = ((stage_v_60_2 + (step_2 * 4)) + pub_r000538_19_2) & 63;
    }
    else
    {
      stage_v_60_2 = ((stage_v_60_2 + pub_r000538_10_2) + 5) & 63;
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
    if ((sec_r000538_2_1 & 1) == step_1)
    {
      stage_v_61_1 = ((stage_v_61_1 + (step_1 * 4)) + pub_r000538_4_1) & 63;
    }
    else
    {
      stage_v_61_1 = ((stage_v_61_1 + pub_r000538_3_1) + 5) & 63;
    }
    if ((sec_r000538_2_2 & 1) == step_2)
    {
      stage_v_61_2 = ((stage_v_61_2 + (step_2 * 4)) + pub_r000538_4_2) & 63;
    }
    else
    {
      stage_v_61_2 = ((stage_v_61_2 + pub_r000538_3_2) + 5) & 63;
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
    if ((sec_r000538_14_1 & 1) == step_1)
    {
      stage_v_62_1 = ((stage_v_62_1 + (step_1 * 4)) + pub_r000538_0_1) & 63;
    }
    else
    {
      stage_v_62_1 = ((stage_v_62_1 + pub_r000538_1_1) + 5) & 63;
    }
    if ((sec_r000538_14_2 & 1) == step_2)
    {
      stage_v_62_2 = ((stage_v_62_2 + (step_2 * 4)) + pub_r000538_0_2) & 63;
    }
    else
    {
      stage_v_62_2 = ((stage_v_62_2 + pub_r000538_1_2) + 5) & 63;
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
    if ((stage_v_45_1 & 1) == step_1)
    {
      stage_v_63_1 = ((stage_v_63_1 + (step_1 * 4)) + pub_r000538_8_1) & 63;
    }
    else
    {
      stage_v_63_1 = ((stage_v_63_1 + pub_r000538_7_1) + 5) & 63;
    }
    if ((stage_v_45_2 & 1) == step_2)
    {
      stage_v_63_2 = ((stage_v_63_2 + (step_2 * 4)) + pub_r000538_8_2) & 63;
    }
    else
    {
      stage_v_63_2 = ((stage_v_63_2 + pub_r000538_7_2) + 5) & 63;
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
    if ((stage_v_34_1 & 1) == step_1)
    {
      stage_v_64_1 = ((stage_v_64_1 + (step_1 * 4)) + pub_r000538_20_1) & 63;
    }
    else
    {
      stage_v_64_1 = ((stage_v_64_1 + pub_r000538_7_1) + 5) & 63;
    }
    if ((stage_v_34_2 & 1) == step_2)
    {
      stage_v_64_2 = ((stage_v_64_2 + (step_2 * 4)) + pub_r000538_20_2) & 63;
    }
    else
    {
      stage_v_64_2 = ((stage_v_64_2 + pub_r000538_7_2) + 5) & 63;
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
    if ((stage_v_44_1 & 1) == step_1)
    {
      stage_v_65_1 = ((stage_v_65_1 + (step_1 * 4)) + pub_r000538_4_1) & 63;
    }
    else
    {
      stage_v_65_1 = ((stage_v_65_1 + pub_r000538_12_1) + 5) & 63;
    }
    if ((stage_v_44_2 & 1) == step_2)
    {
      stage_v_65_2 = ((stage_v_65_2 + (step_2 * 4)) + pub_r000538_4_2) & 63;
    }
    else
    {
      stage_v_65_2 = ((stage_v_65_2 + pub_r000538_12_2) + 5) & 63;
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
    if ((stage_v_52_1 & 1) == step_1)
    {
      stage_v_66_1 = ((stage_v_66_1 + (step_1 * 4)) + pub_r000538_9_1) & 63;
    }
    else
    {
      stage_v_66_1 = ((stage_v_66_1 + pub_r000538_18_1) + 5) & 63;
    }
    if ((stage_v_52_2 & 1) == step_2)
    {
      stage_v_66_2 = ((stage_v_66_2 + (step_2 * 4)) + pub_r000538_9_2) & 63;
    }
    else
    {
      stage_v_66_2 = ((stage_v_66_2 + pub_r000538_18_2) + 5) & 63;
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
    if ((stage_v_55_1 & 1) == step_1)
    {
      stage_v_67_1 = ((stage_v_67_1 + (step_1 * 4)) + pub_r000538_20_1) & 63;
    }
    else
    {
      stage_v_67_1 = ((stage_v_67_1 + pub_r000538_15_1) + 5) & 63;
    }
    if ((stage_v_55_2 & 1) == step_2)
    {
      stage_v_67_2 = ((stage_v_67_2 + (step_2 * 4)) + pub_r000538_20_2) & 63;
    }
    else
    {
      stage_v_67_2 = ((stage_v_67_2 + pub_r000538_15_2) + 5) & 63;
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
    if ((stage_v_67_1 & 1) == step_1)
    {
      stage_v_68_1 = ((stage_v_68_1 + (step_1 * 4)) + pub_r000538_3_1) & 63;
    }
    else
    {
      stage_v_68_1 = ((stage_v_68_1 + pub_r000538_20_1) + 5) & 63;
    }
    if ((stage_v_67_2 & 1) == step_2)
    {
      stage_v_68_2 = ((stage_v_68_2 + (step_2 * 4)) + pub_r000538_3_2) & 63;
    }
    else
    {
      stage_v_68_2 = ((stage_v_68_2 + pub_r000538_20_2) + 5) & 63;
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
    if ((stage_v_48_1 & 1) == step_1)
    {
      stage_v_69_1 = ((stage_v_69_1 + (step_1 * 4)) + pub_r000538_10_1) & 63;
    }
    else
    {
      stage_v_69_1 = ((stage_v_69_1 + pub_r000538_11_1) + 5) & 63;
    }
    if ((stage_v_48_2 & 1) == step_2)
    {
      stage_v_69_2 = ((stage_v_69_2 + (step_2 * 4)) + pub_r000538_10_2) & 63;
    }
    else
    {
      stage_v_69_2 = ((stage_v_69_2 + pub_r000538_11_2) + 5) & 63;
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
    if ((stage_v_53_1 & 1) == step_1)
    {
      stage_v_70_1 = ((stage_v_70_1 + (step_1 * 4)) + pub_r000538_3_1) & 63;
    }
    else
    {
      stage_v_70_1 = ((stage_v_70_1 + pub_r000538_15_1) + 5) & 63;
    }
    if ((stage_v_53_2 & 1) == step_2)
    {
      stage_v_70_2 = ((stage_v_70_2 + (step_2 * 4)) + pub_r000538_3_2) & 63;
    }
    else
    {
      stage_v_70_2 = ((stage_v_70_2 + pub_r000538_15_2) + 5) & 63;
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
    if ((stage_v_40_1 & 1) == step_1)
    {
      stage_v_71_1 = ((stage_v_71_1 + (step_1 * 4)) + pub_r000538_0_1) & 63;
    }
    else
    {
      stage_v_71_1 = ((stage_v_71_1 + pub_r000538_17_1) + 5) & 63;
    }
    if ((stage_v_40_2 & 1) == step_2)
    {
      stage_v_71_2 = ((stage_v_71_2 + (step_2 * 4)) + pub_r000538_0_2) & 63;
    }
    else
    {
      stage_v_71_2 = ((stage_v_71_2 + pub_r000538_17_2) + 5) & 63;
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
    if ((stage_v_34_1 & 1) == step_1)
    {
      stage_v_72_1 = ((stage_v_72_1 + (step_1 * 4)) + pub_r000538_16_1) & 63;
    }
    else
    {
      stage_v_72_1 = ((stage_v_72_1 + pub_r000538_6_1) + 5) & 63;
    }
    if ((stage_v_34_2 & 1) == step_2)
    {
      stage_v_72_2 = ((stage_v_72_2 + (step_2 * 4)) + pub_r000538_16_2) & 63;
    }
    else
    {
      stage_v_72_2 = ((stage_v_72_2 + pub_r000538_6_2) + 5) & 63;
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
    if ((stage_v_61_1 & 1) == step_1)
    {
      stage_v_73_1 = ((stage_v_73_1 + (step_1 * 4)) + pub_r000538_13_1) & 63;
    }
    else
    {
      stage_v_73_1 = ((stage_v_73_1 + pub_r000538_2_1) + 5) & 63;
    }
    if ((stage_v_61_2 & 1) == step_2)
    {
      stage_v_73_2 = ((stage_v_73_2 + (step_2 * 4)) + pub_r000538_13_2) & 63;
    }
    else
    {
      stage_v_73_2 = ((stage_v_73_2 + pub_r000538_2_2) + 5) & 63;
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
    if ((stage_v_73_1 & 1) == step_1)
    {
      stage_v_74_1 = ((stage_v_74_1 + (step_1 * 4)) + pub_r000538_12_1) & 63;
    }
    else
    {
      stage_v_74_1 = ((stage_v_74_1 + pub_r000538_19_1) + 5) & 63;
    }
    if ((stage_v_73_2 & 1) == step_2)
    {
      stage_v_74_2 = ((stage_v_74_2 + (step_2 * 4)) + pub_r000538_12_2) & 63;
    }
    else
    {
      stage_v_74_2 = ((stage_v_74_2 + pub_r000538_19_2) + 5) & 63;
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
    if ((stage_v_37_1 & 1) == step_1)
    {
      stage_v_75_1 = ((stage_v_75_1 + (step_1 * 4)) + pub_r000538_5_1) & 63;
    }
    else
    {
      stage_v_75_1 = ((stage_v_75_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((stage_v_37_2 & 1) == step_2)
    {
      stage_v_75_2 = ((stage_v_75_2 + (step_2 * 4)) + pub_r000538_5_2) & 63;
    }
    else
    {
      stage_v_75_2 = ((stage_v_75_2 + pub_r000538_9_2) + 5) & 63;
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
    if ((stage_v_33_1 & 1) == step_1)
    {
      stage_v_76_1 = ((stage_v_76_1 + (step_1 * 4)) + pub_r000538_20_1) & 63;
    }
    else
    {
      stage_v_76_1 = ((stage_v_76_1 + pub_r000538_19_1) + 5) & 63;
    }
    if ((stage_v_33_2 & 1) == step_2)
    {
      stage_v_76_2 = ((stage_v_76_2 + (step_2 * 4)) + pub_r000538_20_2) & 63;
    }
    else
    {
      stage_v_76_2 = ((stage_v_76_2 + pub_r000538_19_2) + 5) & 63;
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
    if ((stage_v_68_1 & 1) == step_1)
    {
      stage_v_77_1 = ((stage_v_77_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_77_1 = ((stage_v_77_1 + pub_r000538_13_1) + 5) & 63;
    }
    if ((stage_v_68_2 & 1) == step_2)
    {
      stage_v_77_2 = ((stage_v_77_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_77_2 = ((stage_v_77_2 + pub_r000538_13_2) + 5) & 63;
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
    if ((stage_v_67_1 & 1) == step_1)
    {
      stage_v_78_1 = ((stage_v_78_1 + (step_1 * 4)) + pub_r000538_21_1) & 63;
    }
    else
    {
      stage_v_78_1 = ((stage_v_78_1 + pub_r000538_16_1) + 5) & 63;
    }
    if ((stage_v_67_2 & 1) == step_2)
    {
      stage_v_78_2 = ((stage_v_78_2 + (step_2 * 4)) + pub_r000538_21_2) & 63;
    }
    else
    {
      stage_v_78_2 = ((stage_v_78_2 + pub_r000538_16_2) + 5) & 63;
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
    if ((sec_r000538_7_1 & 1) == step_1)
    {
      stage_v_79_1 = ((stage_v_79_1 + (step_1 * 4)) + pub_r000538_9_1) & 63;
    }
    else
    {
      stage_v_79_1 = ((stage_v_79_1 + pub_r000538_12_1) + 5) & 63;
    }
    if ((sec_r000538_7_2 & 1) == step_2)
    {
      stage_v_79_2 = ((stage_v_79_2 + (step_2 * 4)) + pub_r000538_9_2) & 63;
    }
    else
    {
      stage_v_79_2 = ((stage_v_79_2 + pub_r000538_12_2) + 5) & 63;
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
    if ((stage_v_40_1 & 1) == step_1)
    {
      stage_v_80_1 = ((stage_v_80_1 + (step_1 * 4)) + pub_r000538_16_1) & 63;
    }
    else
    {
      stage_v_80_1 = ((stage_v_80_1 + pub_r000538_5_1) + 5) & 63;
    }
    if ((stage_v_40_2 & 1) == step_2)
    {
      stage_v_80_2 = ((stage_v_80_2 + (step_2 * 4)) + pub_r000538_16_2) & 63;
    }
    else
    {
      stage_v_80_2 = ((stage_v_80_2 + pub_r000538_5_2) + 5) & 63;
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
    if ((sec_r000538_14_1 & 1) == step_1)
    {
      stage_v_81_1 = ((stage_v_81_1 + (step_1 * 4)) + pub_r000538_2_1) & 63;
    }
    else
    {
      stage_v_81_1 = ((stage_v_81_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((sec_r000538_14_2 & 1) == step_2)
    {
      stage_v_81_2 = ((stage_v_81_2 + (step_2 * 4)) + pub_r000538_2_2) & 63;
    }
    else
    {
      stage_v_81_2 = ((stage_v_81_2 + pub_r000538_9_2) + 5) & 63;
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
    if ((stage_v_39_1 & 1) == step_1)
    {
      stage_v_82_1 = ((stage_v_82_1 + (step_1 * 4)) + pub_r000538_3_1) & 63;
    }
    else
    {
      stage_v_82_1 = ((stage_v_82_1 + pub_r000538_4_1) + 5) & 63;
    }
    if ((stage_v_39_2 & 1) == step_2)
    {
      stage_v_82_2 = ((stage_v_82_2 + (step_2 * 4)) + pub_r000538_3_2) & 63;
    }
    else
    {
      stage_v_82_2 = ((stage_v_82_2 + pub_r000538_4_2) + 5) & 63;
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
    if ((stage_v_64_1 & 1) == step_1)
    {
      stage_v_83_1 = ((stage_v_83_1 + (step_1 * 4)) + pub_r000538_13_1) & 63;
    }
    else
    {
      stage_v_83_1 = ((stage_v_83_1 + pub_r000538_14_1) + 5) & 63;
    }
    if ((stage_v_64_2 & 1) == step_2)
    {
      stage_v_83_2 = ((stage_v_83_2 + (step_2 * 4)) + pub_r000538_13_2) & 63;
    }
    else
    {
      stage_v_83_2 = ((stage_v_83_2 + pub_r000538_14_2) + 5) & 63;
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
    if ((sec_r000538_13_1 & 1) == step_1)
    {
      stage_v_84_1 = ((stage_v_84_1 + (step_1 * 4)) + pub_r000538_20_1) & 63;
    }
    else
    {
      stage_v_84_1 = ((stage_v_84_1 + pub_r000538_20_1) + 5) & 63;
    }
    if ((sec_r000538_13_2 & 1) == step_2)
    {
      stage_v_84_2 = ((stage_v_84_2 + (step_2 * 4)) + pub_r000538_20_2) & 63;
    }
    else
    {
      stage_v_84_2 = ((stage_v_84_2 + pub_r000538_20_2) + 5) & 63;
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
    if ((stage_v_66_1 & 1) == step_1)
    {
      stage_v_85_1 = ((stage_v_85_1 + (step_1 * 4)) + pub_r000538_14_1) & 63;
    }
    else
    {
      stage_v_85_1 = ((stage_v_85_1 + pub_r000538_5_1) + 5) & 63;
    }
    if ((stage_v_66_2 & 1) == step_2)
    {
      stage_v_85_2 = ((stage_v_85_2 + (step_2 * 4)) + pub_r000538_14_2) & 63;
    }
    else
    {
      stage_v_85_2 = ((stage_v_85_2 + pub_r000538_5_2) + 5) & 63;
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
    if ((stage_v_66_1 & 1) == step_1)
    {
      stage_v_86_1 = ((stage_v_86_1 + (step_1 * 4)) + pub_r000538_14_1) & 63;
    }
    else
    {
      stage_v_86_1 = ((stage_v_86_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((stage_v_66_2 & 1) == step_2)
    {
      stage_v_86_2 = ((stage_v_86_2 + (step_2 * 4)) + pub_r000538_14_2) & 63;
    }
    else
    {
      stage_v_86_2 = ((stage_v_86_2 + pub_r000538_9_2) + 5) & 63;
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
    if ((stage_v_70_1 & 1) == step_1)
    {
      stage_v_87_1 = ((stage_v_87_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_87_1 = ((stage_v_87_1 + pub_r000538_11_1) + 5) & 63;
    }
    if ((stage_v_70_2 & 1) == step_2)
    {
      stage_v_87_2 = ((stage_v_87_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_87_2 = ((stage_v_87_2 + pub_r000538_11_2) + 5) & 63;
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
    if ((sec_r000538_2_1 & 1) == step_1)
    {
      stage_v_88_1 = ((stage_v_88_1 + (step_1 * 4)) + pub_r000538_9_1) & 63;
    }
    else
    {
      stage_v_88_1 = ((stage_v_88_1 + pub_r000538_17_1) + 5) & 63;
    }
    if ((sec_r000538_2_2 & 1) == step_2)
    {
      stage_v_88_2 = ((stage_v_88_2 + (step_2 * 4)) + pub_r000538_9_2) & 63;
    }
    else
    {
      stage_v_88_2 = ((stage_v_88_2 + pub_r000538_17_2) + 5) & 63;
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
    if ((stage_v_38_1 & 1) == step_1)
    {
      stage_v_89_1 = ((stage_v_89_1 + (step_1 * 4)) + pub_r000538_20_1) & 63;
    }
    else
    {
      stage_v_89_1 = ((stage_v_89_1 + pub_r000538_10_1) + 5) & 63;
    }
    if ((stage_v_38_2 & 1) == step_2)
    {
      stage_v_89_2 = ((stage_v_89_2 + (step_2 * 4)) + pub_r000538_20_2) & 63;
    }
    else
    {
      stage_v_89_2 = ((stage_v_89_2 + pub_r000538_10_2) + 5) & 63;
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
    if ((sec_r000538_4_1 & 1) == step_1)
    {
      stage_v_90_1 = ((stage_v_90_1 + (step_1 * 4)) + pub_r000538_4_1) & 63;
    }
    else
    {
      stage_v_90_1 = ((stage_v_90_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((sec_r000538_4_2 & 1) == step_2)
    {
      stage_v_90_2 = ((stage_v_90_2 + (step_2 * 4)) + pub_r000538_4_2) & 63;
    }
    else
    {
      stage_v_90_2 = ((stage_v_90_2 + pub_r000538_9_2) + 5) & 63;
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
    if ((stage_v_66_1 & 1) == step_1)
    {
      stage_v_91_1 = ((stage_v_91_1 + (step_1 * 4)) + pub_r000538_19_1) & 63;
    }
    else
    {
      stage_v_91_1 = ((stage_v_91_1 + pub_r000538_14_1) + 5) & 63;
    }
    if ((stage_v_66_2 & 1) == step_2)
    {
      stage_v_91_2 = ((stage_v_91_2 + (step_2 * 4)) + pub_r000538_19_2) & 63;
    }
    else
    {
      stage_v_91_2 = ((stage_v_91_2 + pub_r000538_14_2) + 5) & 63;
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
    if ((stage_v_52_1 & 1) == step_1)
    {
      stage_v_92_1 = ((stage_v_92_1 + (step_1 * 4)) + pub_r000538_9_1) & 63;
    }
    else
    {
      stage_v_92_1 = ((stage_v_92_1 + pub_r000538_4_1) + 5) & 63;
    }
    if ((stage_v_52_2 & 1) == step_2)
    {
      stage_v_92_2 = ((stage_v_92_2 + (step_2 * 4)) + pub_r000538_9_2) & 63;
    }
    else
    {
      stage_v_92_2 = ((stage_v_92_2 + pub_r000538_4_2) + 5) & 63;
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
    if ((sec_r000538_8_1 & 1) == step_1)
    {
      stage_v_93_1 = ((stage_v_93_1 + (step_1 * 4)) + pub_r000538_21_1) & 63;
    }
    else
    {
      stage_v_93_1 = ((stage_v_93_1 + pub_r000538_18_1) + 5) & 63;
    }
    if ((sec_r000538_8_2 & 1) == step_2)
    {
      stage_v_93_2 = ((stage_v_93_2 + (step_2 * 4)) + pub_r000538_21_2) & 63;
    }
    else
    {
      stage_v_93_2 = ((stage_v_93_2 + pub_r000538_18_2) + 5) & 63;
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
    if ((stage_v_40_1 & 1) == step_1)
    {
      stage_v_94_1 = ((stage_v_94_1 + (step_1 * 4)) + pub_r000538_15_1) & 63;
    }
    else
    {
      stage_v_94_1 = ((stage_v_94_1 + pub_r000538_18_1) + 5) & 63;
    }
    if ((stage_v_40_2 & 1) == step_2)
    {
      stage_v_94_2 = ((stage_v_94_2 + (step_2 * 4)) + pub_r000538_15_2) & 63;
    }
    else
    {
      stage_v_94_2 = ((stage_v_94_2 + pub_r000538_18_2) + 5) & 63;
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
    if ((stage_v_57_1 & 1) == step_1)
    {
      stage_v_95_1 = ((stage_v_95_1 + (step_1 * 4)) + pub_r000538_9_1) & 63;
    }
    else
    {
      stage_v_95_1 = ((stage_v_95_1 + pub_r000538_12_1) + 5) & 63;
    }
    if ((stage_v_57_2 & 1) == step_2)
    {
      stage_v_95_2 = ((stage_v_95_2 + (step_2 * 4)) + pub_r000538_9_2) & 63;
    }
    else
    {
      stage_v_95_2 = ((stage_v_95_2 + pub_r000538_12_2) + 5) & 63;
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
    if ((stage_v_63_1 & 1) == step_1)
    {
      stage_v_96_1 = ((stage_v_96_1 + (step_1 * 4)) + pub_r000538_1_1) & 63;
    }
    else
    {
      stage_v_96_1 = ((stage_v_96_1 + pub_r000538_17_1) + 5) & 63;
    }
    if ((stage_v_63_2 & 1) == step_2)
    {
      stage_v_96_2 = ((stage_v_96_2 + (step_2 * 4)) + pub_r000538_1_2) & 63;
    }
    else
    {
      stage_v_96_2 = ((stage_v_96_2 + pub_r000538_17_2) + 5) & 63;
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
    if ((stage_v_50_1 & 1) == step_1)
    {
      stage_v_97_1 = ((stage_v_97_1 + (step_1 * 4)) + pub_r000538_16_1) & 63;
    }
    else
    {
      stage_v_97_1 = ((stage_v_97_1 + pub_r000538_0_1) + 5) & 63;
    }
    if ((stage_v_50_2 & 1) == step_2)
    {
      stage_v_97_2 = ((stage_v_97_2 + (step_2 * 4)) + pub_r000538_16_2) & 63;
    }
    else
    {
      stage_v_97_2 = ((stage_v_97_2 + pub_r000538_0_2) + 5) & 63;
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
    if ((stage_v_65_1 & 1) == step_1)
    {
      stage_v_98_1 = ((stage_v_98_1 + (step_1 * 4)) + pub_r000538_8_1) & 63;
    }
    else
    {
      stage_v_98_1 = ((stage_v_98_1 + pub_r000538_12_1) + 5) & 63;
    }
    if ((stage_v_65_2 & 1) == step_2)
    {
      stage_v_98_2 = ((stage_v_98_2 + (step_2 * 4)) + pub_r000538_8_2) & 63;
    }
    else
    {
      stage_v_98_2 = ((stage_v_98_2 + pub_r000538_12_2) + 5) & 63;
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
    if ((sec_r000538_11_1 & 1) == step_1)
    {
      stage_v_99_1 = ((stage_v_99_1 + (step_1 * 4)) + pub_r000538_10_1) & 63;
    }
    else
    {
      stage_v_99_1 = ((stage_v_99_1 + pub_r000538_3_1) + 5) & 63;
    }
    if ((sec_r000538_11_2 & 1) == step_2)
    {
      stage_v_99_2 = ((stage_v_99_2 + (step_2 * 4)) + pub_r000538_10_2) & 63;
    }
    else
    {
      stage_v_99_2 = ((stage_v_99_2 + pub_r000538_3_2) + 5) & 63;
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
    if ((sec_r000538_12_1 & 1) == step_1)
    {
      stage_v_100_1 = ((stage_v_100_1 + (step_1 * 4)) + pub_r000538_6_1) & 63;
    }
    else
    {
      stage_v_100_1 = ((stage_v_100_1 + pub_r000538_16_1) + 5) & 63;
    }
    if ((sec_r000538_12_2 & 1) == step_2)
    {
      stage_v_100_2 = ((stage_v_100_2 + (step_2 * 4)) + pub_r000538_6_2) & 63;
    }
    else
    {
      stage_v_100_2 = ((stage_v_100_2 + pub_r000538_16_2) + 5) & 63;
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
    if ((sec_r000538_6_1 & 1) == step_1)
    {
      stage_v_101_1 = ((stage_v_101_1 + (step_1 * 4)) + pub_r000538_13_1) & 63;
    }
    else
    {
      stage_v_101_1 = ((stage_v_101_1 + pub_r000538_18_1) + 5) & 63;
    }
    if ((sec_r000538_6_2 & 1) == step_2)
    {
      stage_v_101_2 = ((stage_v_101_2 + (step_2 * 4)) + pub_r000538_13_2) & 63;
    }
    else
    {
      stage_v_101_2 = ((stage_v_101_2 + pub_r000538_18_2) + 5) & 63;
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
    if ((stage_v_49_1 & 1) == step_1)
    {
      stage_v_102_1 = ((stage_v_102_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_102_1 = ((stage_v_102_1 + pub_r000538_20_1) + 5) & 63;
    }
    if ((stage_v_49_2 & 1) == step_2)
    {
      stage_v_102_2 = ((stage_v_102_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_102_2 = ((stage_v_102_2 + pub_r000538_20_2) + 5) & 63;
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
    if ((stage_v_100_1 & 1) == step_1)
    {
      stage_v_103_1 = ((stage_v_103_1 + (step_1 * 4)) + pub_r000538_12_1) & 63;
    }
    else
    {
      stage_v_103_1 = ((stage_v_103_1 + pub_r000538_8_1) + 5) & 63;
    }
    if ((stage_v_100_2 & 1) == step_2)
    {
      stage_v_103_2 = ((stage_v_103_2 + (step_2 * 4)) + pub_r000538_12_2) & 63;
    }
    else
    {
      stage_v_103_2 = ((stage_v_103_2 + pub_r000538_8_2) + 5) & 63;
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
    if ((sec_r000538_0_1 & 1) == step_1)
    {
      stage_v_104_1 = ((stage_v_104_1 + (step_1 * 4)) + pub_r000538_17_1) & 63;
    }
    else
    {
      stage_v_104_1 = ((stage_v_104_1 + pub_r000538_19_1) + 5) & 63;
    }
    if ((sec_r000538_0_2 & 1) == step_2)
    {
      stage_v_104_2 = ((stage_v_104_2 + (step_2 * 4)) + pub_r000538_17_2) & 63;
    }
    else
    {
      stage_v_104_2 = ((stage_v_104_2 + pub_r000538_19_2) + 5) & 63;
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
    if ((stage_v_61_1 & 1) == step_1)
    {
      stage_v_105_1 = ((stage_v_105_1 + (step_1 * 4)) + pub_r000538_18_1) & 63;
    }
    else
    {
      stage_v_105_1 = ((stage_v_105_1 + pub_r000538_8_1) + 5) & 63;
    }
    if ((stage_v_61_2 & 1) == step_2)
    {
      stage_v_105_2 = ((stage_v_105_2 + (step_2 * 4)) + pub_r000538_18_2) & 63;
    }
    else
    {
      stage_v_105_2 = ((stage_v_105_2 + pub_r000538_8_2) + 5) & 63;
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
    if ((sec_r000538_13_1 & 1) == step_1)
    {
      stage_v_106_1 = ((stage_v_106_1 + (step_1 * 4)) + pub_r000538_1_1) & 63;
    }
    else
    {
      stage_v_106_1 = ((stage_v_106_1 + pub_r000538_11_1) + 5) & 63;
    }
    if ((sec_r000538_13_2 & 1) == step_2)
    {
      stage_v_106_2 = ((stage_v_106_2 + (step_2 * 4)) + pub_r000538_1_2) & 63;
    }
    else
    {
      stage_v_106_2 = ((stage_v_106_2 + pub_r000538_11_2) + 5) & 63;
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
    if ((stage_v_98_1 & 1) == step_1)
    {
      stage_v_107_1 = ((stage_v_107_1 + (step_1 * 4)) + pub_r000538_8_1) & 63;
    }
    else
    {
      stage_v_107_1 = ((stage_v_107_1 + pub_r000538_15_1) + 5) & 63;
    }
    if ((stage_v_98_2 & 1) == step_2)
    {
      stage_v_107_2 = ((stage_v_107_2 + (step_2 * 4)) + pub_r000538_8_2) & 63;
    }
    else
    {
      stage_v_107_2 = ((stage_v_107_2 + pub_r000538_15_2) + 5) & 63;
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
    if ((sec_r000538_10_1 & 1) == step_1)
    {
      stage_v_108_1 = ((stage_v_108_1 + (step_1 * 4)) + pub_r000538_20_1) & 63;
    }
    else
    {
      stage_v_108_1 = ((stage_v_108_1 + pub_r000538_21_1) + 5) & 63;
    }
    if ((sec_r000538_10_2 & 1) == step_2)
    {
      stage_v_108_2 = ((stage_v_108_2 + (step_2 * 4)) + pub_r000538_20_2) & 63;
    }
    else
    {
      stage_v_108_2 = ((stage_v_108_2 + pub_r000538_21_2) + 5) & 63;
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
    if ((sec_r000538_13_1 & 1) == step_1)
    {
      stage_v_109_1 = ((stage_v_109_1 + (step_1 * 4)) + pub_r000538_6_1) & 63;
    }
    else
    {
      stage_v_109_1 = ((stage_v_109_1 + pub_r000538_8_1) + 5) & 63;
    }
    if ((sec_r000538_13_2 & 1) == step_2)
    {
      stage_v_109_2 = ((stage_v_109_2 + (step_2 * 4)) + pub_r000538_6_2) & 63;
    }
    else
    {
      stage_v_109_2 = ((stage_v_109_2 + pub_r000538_8_2) + 5) & 63;
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
    if ((stage_v_107_1 & 1) == step_1)
    {
      stage_v_110_1 = ((stage_v_110_1 + (step_1 * 4)) + pub_r000538_6_1) & 63;
    }
    else
    {
      stage_v_110_1 = ((stage_v_110_1 + pub_r000538_0_1) + 5) & 63;
    }
    if ((stage_v_107_2 & 1) == step_2)
    {
      stage_v_110_2 = ((stage_v_110_2 + (step_2 * 4)) + pub_r000538_6_2) & 63;
    }
    else
    {
      stage_v_110_2 = ((stage_v_110_2 + pub_r000538_0_2) + 5) & 63;
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
    if ((stage_v_99_1 & 1) == step_1)
    {
      stage_v_111_1 = ((stage_v_111_1 + (step_1 * 4)) + pub_r000538_17_1) & 63;
    }
    else
    {
      stage_v_111_1 = ((stage_v_111_1 + pub_r000538_14_1) + 5) & 63;
    }
    if ((stage_v_99_2 & 1) == step_2)
    {
      stage_v_111_2 = ((stage_v_111_2 + (step_2 * 4)) + pub_r000538_17_2) & 63;
    }
    else
    {
      stage_v_111_2 = ((stage_v_111_2 + pub_r000538_14_2) + 5) & 63;
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
    if ((stage_v_69_1 & 1) == step_1)
    {
      stage_v_112_1 = ((stage_v_112_1 + (step_1 * 4)) + pub_r000538_16_1) & 63;
    }
    else
    {
      stage_v_112_1 = ((stage_v_112_1 + pub_r000538_10_1) + 5) & 63;
    }
    if ((stage_v_69_2 & 1) == step_2)
    {
      stage_v_112_2 = ((stage_v_112_2 + (step_2 * 4)) + pub_r000538_16_2) & 63;
    }
    else
    {
      stage_v_112_2 = ((stage_v_112_2 + pub_r000538_10_2) + 5) & 63;
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
    if ((sec_r000538_8_1 & 1) == step_1)
    {
      stage_v_113_1 = ((stage_v_113_1 + (step_1 * 4)) + pub_r000538_1_1) & 63;
    }
    else
    {
      stage_v_113_1 = ((stage_v_113_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((sec_r000538_8_2 & 1) == step_2)
    {
      stage_v_113_2 = ((stage_v_113_2 + (step_2 * 4)) + pub_r000538_1_2) & 63;
    }
    else
    {
      stage_v_113_2 = ((stage_v_113_2 + pub_r000538_9_2) + 5) & 63;
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
    if ((stage_v_88_1 & 1) == step_1)
    {
      stage_v_114_1 = ((stage_v_114_1 + (step_1 * 4)) + pub_r000538_16_1) & 63;
    }
    else
    {
      stage_v_114_1 = ((stage_v_114_1 + pub_r000538_4_1) + 5) & 63;
    }
    if ((stage_v_88_2 & 1) == step_2)
    {
      stage_v_114_2 = ((stage_v_114_2 + (step_2 * 4)) + pub_r000538_16_2) & 63;
    }
    else
    {
      stage_v_114_2 = ((stage_v_114_2 + pub_r000538_4_2) + 5) & 63;
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
    if ((stage_v_57_1 & 1) == step_1)
    {
      stage_v_115_1 = ((stage_v_115_1 + (step_1 * 4)) + pub_r000538_11_1) & 63;
    }
    else
    {
      stage_v_115_1 = ((stage_v_115_1 + pub_r000538_14_1) + 5) & 63;
    }
    if ((stage_v_57_2 & 1) == step_2)
    {
      stage_v_115_2 = ((stage_v_115_2 + (step_2 * 4)) + pub_r000538_11_2) & 63;
    }
    else
    {
      stage_v_115_2 = ((stage_v_115_2 + pub_r000538_14_2) + 5) & 63;
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
    if ((sec_r000538_7_1 & 1) == step_1)
    {
      stage_v_116_1 = ((stage_v_116_1 + (step_1 * 4)) + pub_r000538_4_1) & 63;
    }
    else
    {
      stage_v_116_1 = ((stage_v_116_1 + pub_r000538_21_1) + 5) & 63;
    }
    if ((sec_r000538_7_2 & 1) == step_2)
    {
      stage_v_116_2 = ((stage_v_116_2 + (step_2 * 4)) + pub_r000538_4_2) & 63;
    }
    else
    {
      stage_v_116_2 = ((stage_v_116_2 + pub_r000538_21_2) + 5) & 63;
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
    if ((sec_r000538_10_1 & 1) == step_1)
    {
      stage_v_117_1 = ((stage_v_117_1 + (step_1 * 4)) + pub_r000538_8_1) & 63;
    }
    else
    {
      stage_v_117_1 = ((stage_v_117_1 + pub_r000538_5_1) + 5) & 63;
    }
    if ((sec_r000538_10_2 & 1) == step_2)
    {
      stage_v_117_2 = ((stage_v_117_2 + (step_2 * 4)) + pub_r000538_8_2) & 63;
    }
    else
    {
      stage_v_117_2 = ((stage_v_117_2 + pub_r000538_5_2) + 5) & 63;
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
    if ((sec_r000538_0_1 & 1) == step_1)
    {
      stage_v_118_1 = ((stage_v_118_1 + (step_1 * 4)) + pub_r000538_15_1) & 63;
    }
    else
    {
      stage_v_118_1 = ((stage_v_118_1 + pub_r000538_5_1) + 5) & 63;
    }
    if ((sec_r000538_0_2 & 1) == step_2)
    {
      stage_v_118_2 = ((stage_v_118_2 + (step_2 * 4)) + pub_r000538_15_2) & 63;
    }
    else
    {
      stage_v_118_2 = ((stage_v_118_2 + pub_r000538_5_2) + 5) & 63;
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
    if ((stage_v_61_1 & 1) == step_1)
    {
      stage_v_119_1 = ((stage_v_119_1 + (step_1 * 4)) + pub_r000538_8_1) & 63;
    }
    else
    {
      stage_v_119_1 = ((stage_v_119_1 + pub_r000538_13_1) + 5) & 63;
    }
    if ((stage_v_61_2 & 1) == step_2)
    {
      stage_v_119_2 = ((stage_v_119_2 + (step_2 * 4)) + pub_r000538_8_2) & 63;
    }
    else
    {
      stage_v_119_2 = ((stage_v_119_2 + pub_r000538_13_2) + 5) & 63;
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
    if ((stage_v_108_1 & 1) == step_1)
    {
      stage_v_120_1 = ((stage_v_120_1 + (step_1 * 4)) + pub_r000538_11_1) & 63;
    }
    else
    {
      stage_v_120_1 = ((stage_v_120_1 + pub_r000538_12_1) + 5) & 63;
    }
    if ((stage_v_108_2 & 1) == step_2)
    {
      stage_v_120_2 = ((stage_v_120_2 + (step_2 * 4)) + pub_r000538_11_2) & 63;
    }
    else
    {
      stage_v_120_2 = ((stage_v_120_2 + pub_r000538_12_2) + 5) & 63;
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
    if ((sec_r000538_9_1 & 1) == step_1)
    {
      stage_v_121_1 = ((stage_v_121_1 + (step_1 * 4)) + pub_r000538_2_1) & 63;
    }
    else
    {
      stage_v_121_1 = ((stage_v_121_1 + pub_r000538_17_1) + 5) & 63;
    }
    if ((sec_r000538_9_2 & 1) == step_2)
    {
      stage_v_121_2 = ((stage_v_121_2 + (step_2 * 4)) + pub_r000538_2_2) & 63;
    }
    else
    {
      stage_v_121_2 = ((stage_v_121_2 + pub_r000538_17_2) + 5) & 63;
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
    if ((sec_r000538_2_1 & 1) == step_1)
    {
      stage_v_122_1 = ((stage_v_122_1 + (step_1 * 4)) + pub_r000538_3_1) & 63;
    }
    else
    {
      stage_v_122_1 = ((stage_v_122_1 + pub_r000538_19_1) + 5) & 63;
    }
    if ((sec_r000538_2_2 & 1) == step_2)
    {
      stage_v_122_2 = ((stage_v_122_2 + (step_2 * 4)) + pub_r000538_3_2) & 63;
    }
    else
    {
      stage_v_122_2 = ((stage_v_122_2 + pub_r000538_19_2) + 5) & 63;
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
    if ((stage_v_80_1 & 1) == step_1)
    {
      stage_v_123_1 = ((stage_v_123_1 + (step_1 * 4)) + pub_r000538_19_1) & 63;
    }
    else
    {
      stage_v_123_1 = ((stage_v_123_1 + pub_r000538_7_1) + 5) & 63;
    }
    if ((stage_v_80_2 & 1) == step_2)
    {
      stage_v_123_2 = ((stage_v_123_2 + (step_2 * 4)) + pub_r000538_19_2) & 63;
    }
    else
    {
      stage_v_123_2 = ((stage_v_123_2 + pub_r000538_7_2) + 5) & 63;
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
    if ((sec_r000538_9_1 & 1) == step_1)
    {
      stage_v_124_1 = ((stage_v_124_1 + (step_1 * 4)) + pub_r000538_3_1) & 63;
    }
    else
    {
      stage_v_124_1 = ((stage_v_124_1 + pub_r000538_8_1) + 5) & 63;
    }
    if ((sec_r000538_9_2 & 1) == step_2)
    {
      stage_v_124_2 = ((stage_v_124_2 + (step_2 * 4)) + pub_r000538_3_2) & 63;
    }
    else
    {
      stage_v_124_2 = ((stage_v_124_2 + pub_r000538_8_2) + 5) & 63;
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
    if ((stage_v_83_1 & 1) == step_1)
    {
      stage_v_125_1 = ((stage_v_125_1 + (step_1 * 4)) + pub_r000538_14_1) & 63;
    }
    else
    {
      stage_v_125_1 = ((stage_v_125_1 + pub_r000538_4_1) + 5) & 63;
    }
    if ((stage_v_83_2 & 1) == step_2)
    {
      stage_v_125_2 = ((stage_v_125_2 + (step_2 * 4)) + pub_r000538_14_2) & 63;
    }
    else
    {
      stage_v_125_2 = ((stage_v_125_2 + pub_r000538_4_2) + 5) & 63;
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
    if ((stage_v_100_1 & 1) == step_1)
    {
      stage_v_126_1 = ((stage_v_126_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_126_1 = ((stage_v_126_1 + pub_r000538_6_1) + 5) & 63;
    }
    if ((stage_v_100_2 & 1) == step_2)
    {
      stage_v_126_2 = ((stage_v_126_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_126_2 = ((stage_v_126_2 + pub_r000538_6_2) + 5) & 63;
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
    if ((stage_v_95_1 & 1) == step_1)
    {
      stage_v_127_1 = ((stage_v_127_1 + (step_1 * 4)) + pub_r000538_6_1) & 63;
    }
    else
    {
      stage_v_127_1 = ((stage_v_127_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((stage_v_95_2 & 1) == step_2)
    {
      stage_v_127_2 = ((stage_v_127_2 + (step_2 * 4)) + pub_r000538_6_2) & 63;
    }
    else
    {
      stage_v_127_2 = ((stage_v_127_2 + pub_r000538_9_2) + 5) & 63;
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
    if ((stage_v_83_1 & 1) == step_1)
    {
      stage_v_128_1 = ((stage_v_128_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_128_1 = ((stage_v_128_1 + pub_r000538_2_1) + 5) & 63;
    }
    if ((stage_v_83_2 & 1) == step_2)
    {
      stage_v_128_2 = ((stage_v_128_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_128_2 = ((stage_v_128_2 + pub_r000538_2_2) + 5) & 63;
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
    if ((stage_v_47_1 & 1) == step_1)
    {
      stage_v_129_1 = ((stage_v_129_1 + (step_1 * 4)) + pub_r000538_2_1) & 63;
    }
    else
    {
      stage_v_129_1 = ((stage_v_129_1 + pub_r000538_5_1) + 5) & 63;
    }
    if ((stage_v_47_2 & 1) == step_2)
    {
      stage_v_129_2 = ((stage_v_129_2 + (step_2 * 4)) + pub_r000538_2_2) & 63;
    }
    else
    {
      stage_v_129_2 = ((stage_v_129_2 + pub_r000538_5_2) + 5) & 63;
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
    if ((stage_v_76_1 & 1) == step_1)
    {
      stage_v_130_1 = ((stage_v_130_1 + (step_1 * 4)) + pub_r000538_10_1) & 63;
    }
    else
    {
      stage_v_130_1 = ((stage_v_130_1 + pub_r000538_18_1) + 5) & 63;
    }
    if ((stage_v_76_2 & 1) == step_2)
    {
      stage_v_130_2 = ((stage_v_130_2 + (step_2 * 4)) + pub_r000538_10_2) & 63;
    }
    else
    {
      stage_v_130_2 = ((stage_v_130_2 + pub_r000538_18_2) + 5) & 63;
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
    if ((stage_v_67_1 & 1) == step_1)
    {
      stage_v_131_1 = ((stage_v_131_1 + (step_1 * 4)) + pub_r000538_8_1) & 63;
    }
    else
    {
      stage_v_131_1 = ((stage_v_131_1 + pub_r000538_18_1) + 5) & 63;
    }
    if ((stage_v_67_2 & 1) == step_2)
    {
      stage_v_131_2 = ((stage_v_131_2 + (step_2 * 4)) + pub_r000538_8_2) & 63;
    }
    else
    {
      stage_v_131_2 = ((stage_v_131_2 + pub_r000538_18_2) + 5) & 63;
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
    if ((sec_r000538_11_1 & 1) == step_1)
    {
      stage_v_132_1 = ((stage_v_132_1 + (step_1 * 4)) + pub_r000538_9_1) & 63;
    }
    else
    {
      stage_v_132_1 = ((stage_v_132_1 + pub_r000538_18_1) + 5) & 63;
    }
    if ((sec_r000538_11_2 & 1) == step_2)
    {
      stage_v_132_2 = ((stage_v_132_2 + (step_2 * 4)) + pub_r000538_9_2) & 63;
    }
    else
    {
      stage_v_132_2 = ((stage_v_132_2 + pub_r000538_18_2) + 5) & 63;
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
    if ((stage_v_44_1 & 1) == step_1)
    {
      stage_v_133_1 = ((stage_v_133_1 + (step_1 * 4)) + pub_r000538_17_1) & 63;
    }
    else
    {
      stage_v_133_1 = ((stage_v_133_1 + pub_r000538_15_1) + 5) & 63;
    }
    if ((stage_v_44_2 & 1) == step_2)
    {
      stage_v_133_2 = ((stage_v_133_2 + (step_2 * 4)) + pub_r000538_17_2) & 63;
    }
    else
    {
      stage_v_133_2 = ((stage_v_133_2 + pub_r000538_15_2) + 5) & 63;
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
    if ((stage_v_91_1 & 1) == step_1)
    {
      stage_v_134_1 = ((stage_v_134_1 + (step_1 * 4)) + pub_r000538_18_1) & 63;
    }
    else
    {
      stage_v_134_1 = ((stage_v_134_1 + pub_r000538_2_1) + 5) & 63;
    }
    if ((stage_v_91_2 & 1) == step_2)
    {
      stage_v_134_2 = ((stage_v_134_2 + (step_2 * 4)) + pub_r000538_18_2) & 63;
    }
    else
    {
      stage_v_134_2 = ((stage_v_134_2 + pub_r000538_2_2) + 5) & 63;
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
    if ((sec_r000538_13_1 & 1) == step_1)
    {
      stage_v_135_1 = ((stage_v_135_1 + (step_1 * 4)) + pub_r000538_1_1) & 63;
    }
    else
    {
      stage_v_135_1 = ((stage_v_135_1 + pub_r000538_10_1) + 5) & 63;
    }
    if ((sec_r000538_13_2 & 1) == step_2)
    {
      stage_v_135_2 = ((stage_v_135_2 + (step_2 * 4)) + pub_r000538_1_2) & 63;
    }
    else
    {
      stage_v_135_2 = ((stage_v_135_2 + pub_r000538_10_2) + 5) & 63;
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
    if ((sec_r000538_8_1 & 1) == step_1)
    {
      stage_v_136_1 = ((stage_v_136_1 + (step_1 * 4)) + pub_r000538_18_1) & 63;
    }
    else
    {
      stage_v_136_1 = ((stage_v_136_1 + pub_r000538_6_1) + 5) & 63;
    }
    if ((sec_r000538_8_2 & 1) == step_2)
    {
      stage_v_136_2 = ((stage_v_136_2 + (step_2 * 4)) + pub_r000538_18_2) & 63;
    }
    else
    {
      stage_v_136_2 = ((stage_v_136_2 + pub_r000538_6_2) + 5) & 63;
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
    if ((stage_v_106_1 & 1) == step_1)
    {
      stage_v_137_1 = ((stage_v_137_1 + (step_1 * 4)) + pub_r000538_19_1) & 63;
    }
    else
    {
      stage_v_137_1 = ((stage_v_137_1 + pub_r000538_15_1) + 5) & 63;
    }
    if ((stage_v_106_2 & 1) == step_2)
    {
      stage_v_137_2 = ((stage_v_137_2 + (step_2 * 4)) + pub_r000538_19_2) & 63;
    }
    else
    {
      stage_v_137_2 = ((stage_v_137_2 + pub_r000538_15_2) + 5) & 63;
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
    if ((stage_v_54_1 & 1) == step_1)
    {
      stage_v_138_1 = ((stage_v_138_1 + (step_1 * 4)) + pub_r000538_12_1) & 63;
    }
    else
    {
      stage_v_138_1 = ((stage_v_138_1 + pub_r000538_6_1) + 5) & 63;
    }
    if ((stage_v_54_2 & 1) == step_2)
    {
      stage_v_138_2 = ((stage_v_138_2 + (step_2 * 4)) + pub_r000538_12_2) & 63;
    }
    else
    {
      stage_v_138_2 = ((stage_v_138_2 + pub_r000538_6_2) + 5) & 63;
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
    if ((stage_v_130_1 & 1) == step_1)
    {
      stage_v_139_1 = ((stage_v_139_1 + (step_1 * 4)) + pub_r000538_17_1) & 63;
    }
    else
    {
      stage_v_139_1 = ((stage_v_139_1 + pub_r000538_12_1) + 5) & 63;
    }
    if ((stage_v_130_2 & 1) == step_2)
    {
      stage_v_139_2 = ((stage_v_139_2 + (step_2 * 4)) + pub_r000538_17_2) & 63;
    }
    else
    {
      stage_v_139_2 = ((stage_v_139_2 + pub_r000538_12_2) + 5) & 63;
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
    if ((sec_r000538_1_1 & 1) == step_1)
    {
      stage_v_140_1 = ((stage_v_140_1 + (step_1 * 4)) + pub_r000538_0_1) & 63;
    }
    else
    {
      stage_v_140_1 = ((stage_v_140_1 + pub_r000538_2_1) + 5) & 63;
    }
    if ((sec_r000538_1_2 & 1) == step_2)
    {
      stage_v_140_2 = ((stage_v_140_2 + (step_2 * 4)) + pub_r000538_0_2) & 63;
    }
    else
    {
      stage_v_140_2 = ((stage_v_140_2 + pub_r000538_2_2) + 5) & 63;
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
    if ((sec_r000538_4_1 & 1) == step_1)
    {
      stage_v_141_1 = ((stage_v_141_1 + (step_1 * 4)) + pub_r000538_10_1) & 63;
    }
    else
    {
      stage_v_141_1 = ((stage_v_141_1 + pub_r000538_17_1) + 5) & 63;
    }
    if ((sec_r000538_4_2 & 1) == step_2)
    {
      stage_v_141_2 = ((stage_v_141_2 + (step_2 * 4)) + pub_r000538_10_2) & 63;
    }
    else
    {
      stage_v_141_2 = ((stage_v_141_2 + pub_r000538_17_2) + 5) & 63;
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
    if ((stage_v_97_1 & 1) == step_1)
    {
      stage_v_142_1 = ((stage_v_142_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_142_1 = ((stage_v_142_1 + pub_r000538_7_1) + 5) & 63;
    }
    if ((stage_v_97_2 & 1) == step_2)
    {
      stage_v_142_2 = ((stage_v_142_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_142_2 = ((stage_v_142_2 + pub_r000538_7_2) + 5) & 63;
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
    if ((stage_v_33_1 & 1) == step_1)
    {
      stage_v_143_1 = ((stage_v_143_1 + (step_1 * 4)) + pub_r000538_21_1) & 63;
    }
    else
    {
      stage_v_143_1 = ((stage_v_143_1 + pub_r000538_19_1) + 5) & 63;
    }
    if ((stage_v_33_2 & 1) == step_2)
    {
      stage_v_143_2 = ((stage_v_143_2 + (step_2 * 4)) + pub_r000538_21_2) & 63;
    }
    else
    {
      stage_v_143_2 = ((stage_v_143_2 + pub_r000538_19_2) + 5) & 63;
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
    if ((stage_v_85_1 & 1) == step_1)
    {
      stage_v_144_1 = ((stage_v_144_1 + (step_1 * 4)) + pub_r000538_18_1) & 63;
    }
    else
    {
      stage_v_144_1 = ((stage_v_144_1 + pub_r000538_17_1) + 5) & 63;
    }
    if ((stage_v_85_2 & 1) == step_2)
    {
      stage_v_144_2 = ((stage_v_144_2 + (step_2 * 4)) + pub_r000538_18_2) & 63;
    }
    else
    {
      stage_v_144_2 = ((stage_v_144_2 + pub_r000538_17_2) + 5) & 63;
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
    if ((stage_v_74_1 & 1) == step_1)
    {
      stage_v_145_1 = ((stage_v_145_1 + (step_1 * 4)) + pub_r000538_2_1) & 63;
    }
    else
    {
      stage_v_145_1 = ((stage_v_145_1 + pub_r000538_14_1) + 5) & 63;
    }
    if ((stage_v_74_2 & 1) == step_2)
    {
      stage_v_145_2 = ((stage_v_145_2 + (step_2 * 4)) + pub_r000538_2_2) & 63;
    }
    else
    {
      stage_v_145_2 = ((stage_v_145_2 + pub_r000538_14_2) + 5) & 63;
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
    if ((stage_v_103_1 & 1) == step_1)
    {
      stage_v_146_1 = ((stage_v_146_1 + (step_1 * 4)) + pub_r000538_1_1) & 63;
    }
    else
    {
      stage_v_146_1 = ((stage_v_146_1 + pub_r000538_21_1) + 5) & 63;
    }
    if ((stage_v_103_2 & 1) == step_2)
    {
      stage_v_146_2 = ((stage_v_146_2 + (step_2 * 4)) + pub_r000538_1_2) & 63;
    }
    else
    {
      stage_v_146_2 = ((stage_v_146_2 + pub_r000538_21_2) + 5) & 63;
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
    if ((sec_r000538_14_1 & 1) == step_1)
    {
      stage_v_147_1 = ((stage_v_147_1 + (step_1 * 4)) + pub_r000538_8_1) & 63;
    }
    else
    {
      stage_v_147_1 = ((stage_v_147_1 + pub_r000538_21_1) + 5) & 63;
    }
    if ((sec_r000538_14_2 & 1) == step_2)
    {
      stage_v_147_2 = ((stage_v_147_2 + (step_2 * 4)) + pub_r000538_8_2) & 63;
    }
    else
    {
      stage_v_147_2 = ((stage_v_147_2 + pub_r000538_21_2) + 5) & 63;
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
    if ((stage_v_110_1 & 1) == step_1)
    {
      stage_v_148_1 = ((stage_v_148_1 + (step_1 * 4)) + pub_r000538_15_1) & 63;
    }
    else
    {
      stage_v_148_1 = ((stage_v_148_1 + pub_r000538_7_1) + 5) & 63;
    }
    if ((stage_v_110_2 & 1) == step_2)
    {
      stage_v_148_2 = ((stage_v_148_2 + (step_2 * 4)) + pub_r000538_15_2) & 63;
    }
    else
    {
      stage_v_148_2 = ((stage_v_148_2 + pub_r000538_7_2) + 5) & 63;
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
    if ((sec_r000538_14_1 & 1) == step_1)
    {
      stage_v_149_1 = ((stage_v_149_1 + (step_1 * 4)) + pub_r000538_14_1) & 63;
    }
    else
    {
      stage_v_149_1 = ((stage_v_149_1 + pub_r000538_7_1) + 5) & 63;
    }
    if ((sec_r000538_14_2 & 1) == step_2)
    {
      stage_v_149_2 = ((stage_v_149_2 + (step_2 * 4)) + pub_r000538_14_2) & 63;
    }
    else
    {
      stage_v_149_2 = ((stage_v_149_2 + pub_r000538_7_2) + 5) & 63;
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
    if ((sec_r000538_14_1 & 1) == step_1)
    {
      stage_v_150_1 = ((stage_v_150_1 + (step_1 * 4)) + pub_r000538_9_1) & 63;
    }
    else
    {
      stage_v_150_1 = ((stage_v_150_1 + pub_r000538_9_1) + 5) & 63;
    }
    if ((sec_r000538_14_2 & 1) == step_2)
    {
      stage_v_150_2 = ((stage_v_150_2 + (step_2 * 4)) + pub_r000538_9_2) & 63;
    }
    else
    {
      stage_v_150_2 = ((stage_v_150_2 + pub_r000538_9_2) + 5) & 63;
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
    if ((sec_r000538_12_1 & 1) == step_1)
    {
      stage_v_151_1 = ((stage_v_151_1 + (step_1 * 4)) + pub_r000538_4_1) & 63;
    }
    else
    {
      stage_v_151_1 = ((stage_v_151_1 + pub_r000538_6_1) + 5) & 63;
    }
    if ((sec_r000538_12_2 & 1) == step_2)
    {
      stage_v_151_2 = ((stage_v_151_2 + (step_2 * 4)) + pub_r000538_4_2) & 63;
    }
    else
    {
      stage_v_151_2 = ((stage_v_151_2 + pub_r000538_6_2) + 5) & 63;
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
    if ((stage_v_56_1 & 1) == step_1)
    {
      stage_v_152_1 = ((stage_v_152_1 + (step_1 * 4)) + pub_r000538_7_1) & 63;
    }
    else
    {
      stage_v_152_1 = ((stage_v_152_1 + pub_r000538_6_1) + 5) & 63;
    }
    if ((stage_v_56_2 & 1) == step_2)
    {
      stage_v_152_2 = ((stage_v_152_2 + (step_2 * 4)) + pub_r000538_7_2) & 63;
    }
    else
    {
      stage_v_152_2 = ((stage_v_152_2 + pub_r000538_6_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_118_1 & 1) == step_1)
    {
      stage_v_153_1 = ((stage_v_153_1 + (step_1 * 4)) + pub_r000538_21_1) & 63;
    }
    else
    {
      stage_v_153_1 = ((stage_v_153_1 + pub_r000538_3_1) + 5) & 63;
    }
    if ((stage_v_118_2 & 1) == step_2)
    {
      stage_v_153_2 = ((stage_v_153_2 + (step_2 * 4)) + pub_r000538_21_2) & 63;
    }
    else
    {
      stage_v_153_2 = ((stage_v_153_2 + pub_r000538_3_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_45_1 & 1) == step_1)
    {
      stage_v_154_1 = ((stage_v_154_1 + (step_1 * 4)) + pub_r000538_2_1) & 63;
    }
    else
    {
      stage_v_154_1 = ((stage_v_154_1 + pub_r000538_1_1) + 5) & 63;
    }
    if ((stage_v_45_2 & 1) == step_2)
    {
      stage_v_154_2 = ((stage_v_154_2 + (step_2 * 4)) + pub_r000538_2_2) & 63;
    }
    else
    {
      stage_v_154_2 = ((stage_v_154_2 + pub_r000538_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_88_1 & 1) == step_1)
    {
      stage_v_155_1 = ((stage_v_155_1 + (step_1 * 4)) + pub_r000538_17_1) & 63;
    }
    else
    {
      stage_v_155_1 = ((stage_v_155_1 + pub_r000538_1_1) + 5) & 63;
    }
    if ((stage_v_88_2 & 1) == step_2)
    {
      stage_v_155_2 = ((stage_v_155_2 + (step_2 * 4)) + pub_r000538_17_2) & 63;
    }
    else
    {
      stage_v_155_2 = ((stage_v_155_2 + pub_r000538_1_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    if ((stage_v_98_1 & 1) == step_1)
    {
      stage_v_156_1 = ((stage_v_156_1 + (step_1 * 4)) + pub_r000538_17_1) & 63;
    }
    else
    {
      stage_v_156_1 = ((stage_v_156_1 + pub_r000538_20_1) + 5) & 63;
    }
    if ((stage_v_98_2 & 1) == step_2)
    {
      stage_v_156_2 = ((stage_v_156_2 + (step_2 * 4)) + pub_r000538_17_2) & 63;
    }
    else
    {
      stage_v_156_2 = ((stage_v_156_2 + pub_r000538_20_2) + 5) & 63;
    }
    chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000538_9_1 == pub_r000538_9_2);
  __CPROVER_assume(pub_r000538_0_1 == pub_r000538_0_2);
  __CPROVER_assume(sec_r000538_15_1 != sec_r000538_15_2);
  __CPROVER_assume(pub_r000538_21_1 == pub_r000538_21_2);
  __CPROVER_assume(pub_r000538_18_1 == pub_r000538_18_2);
  __CPROVER_assume(pub_r000538_19_1 == pub_r000538_19_2);
  __CPROVER_assume(pub_r000538_11_1 == pub_r000538_11_2);
  __CPROVER_assume(pub_r000538_16_1 == pub_r000538_16_2);
  __CPROVER_assume(sec_r000538_1_1 != sec_r000538_1_2);
  __CPROVER_assume(sec_r000538_6_1 != sec_r000538_6_2);
  __CPROVER_assume(pub_r000538_6_1 == pub_r000538_6_2);
  __CPROVER_assume(sec_r000538_14_1 != sec_r000538_14_2);
  __CPROVER_assume(sec_r000538_12_1 != sec_r000538_12_2);
  __CPROVER_assume(pub_r000538_15_1 == pub_r000538_15_2);
  __CPROVER_assume(sec_r000538_4_1 != sec_r000538_4_2);
  __CPROVER_assume(sec_r000538_11_1 != sec_r000538_11_2);
  __CPROVER_assume(pub_r000538_3_1 == pub_r000538_3_2);
  __CPROVER_assume(pub_r000538_4_1 == pub_r000538_4_2);
  __CPROVER_assume(pub_r000538_20_1 == pub_r000538_20_2);
  __CPROVER_assume(sec_r000538_2_1 != sec_r000538_2_2);
  __CPROVER_assume(sec_r000538_7_1 != sec_r000538_7_2);
  __CPROVER_assume(pub_r000538_5_1 == pub_r000538_5_2);
  __CPROVER_assume(sec_r000538_0_1 != sec_r000538_0_2);
  __CPROVER_assume(sec_r000538_10_1 != sec_r000538_10_2);
  __CPROVER_assume(sec_r000538_9_1 != sec_r000538_9_2);
  __CPROVER_assume(sec_r000538_13_1 != sec_r000538_13_2);
  __CPROVER_assume(sec_r000538_8_1 != sec_r000538_8_2);
  __CPROVER_assume(pub_r000538_1_1 == pub_r000538_1_2);
  __CPROVER_assume(sec_r000538_5_1 != sec_r000538_5_2);
  __CPROVER_assume(pub_r000538_10_1 == pub_r000538_10_2);
  __CPROVER_assume(pub_r000538_13_1 == pub_r000538_13_2);
  __CPROVER_assume(pub_r000538_12_1 == pub_r000538_12_2);
  __CPROVER_assume(pub_r000538_17_1 == pub_r000538_17_2);
  __CPROVER_assume(sec_r000538_3_1 != sec_r000538_3_2);
  __CPROVER_assume(pub_r000538_2_1 == pub_r000538_2_2);
  __CPROVER_assume(pub_r000538_8_1 == pub_r000538_8_2);
  __CPROVER_assume(pub_r000538_7_1 == pub_r000538_7_2);
  __CPROVER_assume(pub_r000538_14_1 == pub_r000538_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.severity == st_var_3_2.severity);
  assert(st_var_3_1.facility == st_var_3_2.facility);
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
}


