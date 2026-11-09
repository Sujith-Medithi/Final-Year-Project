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
struct SensorNode_R001288_8813_0
{
  unsigned char calib;
  int reading;
  int offset;
  int threshold;
  int buffer[3];
};
struct MatrixBlock_R001288_8813_1
{
  int scale;
  int density;
  unsigned char stride;
  unsigned char determinant;
  int dim;
  int buffer[3];
};
struct Transaction_R001288_8813_2
{
  unsigned char status;
  unsigned char rate;
  int fee;
  int buffer[3];
};
struct CipherContext_R001288_8813_3
{
  short counter;
  int nonce;
  short tag;
  int buffer[3];
};
union PacketPayload_R001288_8813_0
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
void fn_R001288_8813_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st_1 = {0};
  struct CipherContext_R001288_8813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int offset_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_30_1)
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

  switch (offset_30_2)
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
  int quantum_94_1 = local_arr_1[aux_1 % 3];
  int quantum_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_94_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_34_1 > 47)
  {
    acc_1 = ((acc_1 + (tracker_34_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_34_2 > 47)
  {
    acc_2 = ((acc_2 + (tracker_34_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_30_1 == offset_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_94_1 == quantum_94_2);
  assert(tracker_34_1 == tracker_34_2);
}

int fn_R001288_8813_0(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int offset_30 = (aux + st.buffer[1]) & 3;
  switch (offset_30)
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
  int quantum_94 = local_arr[aux % 3];
  acc = (acc + (quantum_94 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_34 > 47)
  {
    acc = ((acc + (tracker_34 * 2)) + 5) & 127;
    aux ^= tracker_34 & 15;
  }
  else
  {
    acc = ((acc - tracker_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001288_8813_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st_1 = {0};
  struct CipherContext_R001288_8813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int vector_83_1 = 0;
  int vector_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_83_1 = ((vector_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_83_2 = ((vector_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_83_1) & 127;
    acc_2 = (acc_2 + vector_83_2) & 127;
  }

  int margin_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_54_1) & 63;
  aux_2 = (aux_2 + margin_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_38_1 = local_arr_1[aux_1 % 3];
  int checksum_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_38_2 * 2)) & 127;
  int tracker_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_67_1)
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

  switch (tracker_67_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_83_1 == vector_83_2);
  assert(margin_54_1 == margin_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_38_1 == checksum_38_2);
  assert(tracker_67_1 == tracker_67_2);
}

int fn_R001288_8813_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int vector_83 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_83 = ((vector_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_83) & 127;
  }

  int margin_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_54) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_38 = local_arr[aux % 3];
  acc = (acc + (checksum_38 * 2)) & 127;
  int tracker_67 = (aux + st.buffer[1]) & 3;
  switch (tracker_67)
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

void fn_R001288_8813_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st_1 = {0};
  struct CipherContext_R001288_8813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int index_reg_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_94_1)
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

  switch (index_reg_94_2)
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

  int delta_81_1 = 0;
  int delta_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_81_1 = ((delta_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_81_2 = ((delta_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_81_1) & 127;
    acc_2 = (acc_2 + delta_81_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_73_1 = local_arr_1[aux_1 % 3];
  int factor_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_94_1 == index_reg_94_2);
  assert(delta_81_1 == delta_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_73_1 == factor_73_2);
}

int fn_R001288_8813_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int index_reg_94 = (aux + st.buffer[1]) & 3;
  switch (index_reg_94)
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

  int delta_81 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_81 = ((delta_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_81) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int factor_73 = local_arr[aux % 3];
  acc = (acc + (factor_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001288_8813_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st_1 = {0};
  struct SensorNode_R001288_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_14_1 = 0;
  int bound_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_14_1 = ((bound_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_14_2 = ((bound_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_14_1) & 127;
    acc_2 = (acc_2 + bound_14_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_50_1 = local_arr_1[aux_1 % 3];
  int parity_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_14_1 == bound_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_50_1 == parity_50_2);
}

int fn_R001288_8813_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_14 = ((bound_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_14) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_50 = local_arr[aux % 3];
  acc = (acc + (parity_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001288_8813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001288_8813_1 st_1 = {0};
  struct MatrixBlock_R001288_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_35_1 = local_arr_1[aux_1 % 3];
  int pivot_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_35_2 * 2)) & 127;
  int offset_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_48_1) & 63;
  aux_2 = (aux_2 + offset_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_98_1 = 0;
  int threshold_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_98_1 = ((threshold_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_98_2 = ((threshold_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_98_1) & 127;
    acc_2 = (acc_2 + threshold_98_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_35_1 == pivot_35_2);
  assert(offset_48_1 == offset_48_2);
  assert(threshold_98_1 == threshold_98_2);
}

int fn_R001288_8813_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001288_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_35 = local_arr[aux % 3];
  acc = (acc + (pivot_35 * 2)) & 127;
  int offset_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_48) & 63;
  acc ^= aux;
  int threshold_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_98 = ((threshold_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_98) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001288_8813_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001288_8813_1 st_1 = {0};
  struct MatrixBlock_R001288_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int window_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_65_1 > 10)
  {
    acc_1 = ((acc_1 + (window_65_1 * 2)) + 5) & 127;
    aux_1 ^= window_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_65_2 > 10)
  {
    acc_2 = ((acc_2 + (window_65_2 * 2)) + 5) & 127;
    aux_2 ^= window_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_99_1)
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

  switch (tracker_99_2)
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
  int delta_49_1 = local_arr_1[aux_1 % 3];
  int delta_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_49_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_65_1 == window_65_2);
  assert(tracker_99_1 == tracker_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_49_1 == delta_49_2);
}

int fn_R001288_8813_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001288_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int window_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_65 > 10)
  {
    acc = ((acc + (window_65 * 2)) + 5) & 127;
    aux ^= window_65 & 15;
  }
  else
  {
    acc = ((acc - window_65) + 11) & 127;
    aux += 3;
  }
  int tracker_99 = (aux + st.buffer[1]) & 3;
  switch (tracker_99)
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
  int delta_49 = local_arr[aux % 3];
  acc = (acc + (delta_49 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001288_8813_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st_1 = {0};
  struct SensorNode_R001288_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int delta_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_42_1)
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

  switch (delta_42_2)
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
  int mask_38_1 = local_arr_1[aux_1 % 3];
  int mask_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_38_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_42_1 == delta_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_38_1 == mask_38_2);
}

int fn_R001288_8813_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int delta_42 = (aux + st.buffer[1]) & 3;
  switch (delta_42)
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
  int mask_38 = local_arr[aux % 3];
  acc = (acc + (mask_38 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001288_8813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001288_8813_2 st_1 = {0};
  struct Transaction_R001288_8813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_77_1 = local_arr_1[aux_1 % 3];
  int quotient_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_77_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_67_1 > 16)
  {
    acc_1 = ((acc_1 + (mask_67_1 * 2)) + 5) & 127;
    aux_1 ^= mask_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_67_2 > 16)
  {
    acc_2 = ((acc_2 + (mask_67_2 * 2)) + 5) & 127;
    aux_2 ^= mask_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_77_1 == quotient_77_2);
  assert(mask_67_1 == mask_67_2);
}

int fn_R001288_8813_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001288_8813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int quotient_77 = local_arr[aux % 3];
  acc = (acc + (quotient_77 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_67 > 16)
  {
    acc = ((acc + (mask_67 * 2)) + 5) & 127;
    aux ^= mask_67 & 15;
  }
  else
  {
    acc = ((acc - mask_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001288_8813_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st_1 = {0};
  struct SensorNode_R001288_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_25_1 = local_arr_1[aux_1 % 3];
  int mask_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_25_2 * 2)) & 127;
  int accumulator_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_55_1 > 37)
  {
    acc_1 = ((acc_1 + (accumulator_55_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_55_2 > 37)
  {
    acc_2 = ((acc_2 + (accumulator_55_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_55_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_61_1)
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

  switch (mask_61_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_25_1 == mask_25_2);
  assert(accumulator_55_1 == accumulator_55_2);
  assert(mask_61_1 == mask_61_2);
}

int fn_R001288_8813_8(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int mask_25 = local_arr[aux % 3];
  acc = (acc + (mask_25 * 2)) & 127;
  int accumulator_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_55 > 37)
  {
    acc = ((acc + (accumulator_55 * 2)) + 5) & 127;
    aux ^= accumulator_55 & 15;
  }
  else
  {
    acc = ((acc - accumulator_55) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_61 = (aux + st.buffer[1]) & 3;
  switch (mask_61)
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

void fn_R001288_8813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st_1 = {0};
  struct CipherContext_R001288_8813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_99_1 = local_arr_1[aux_1 % 3];
  int tracker_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_99_2 * 2)) & 127;
  int index_reg_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_59_1 > 33)
  {
    acc_1 = ((acc_1 + (index_reg_59_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_59_2 > 33)
  {
    acc_2 = ((acc_2 + (index_reg_59_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_75_1) & 63;
  aux_2 = (aux_2 + parity_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_99_1 == tracker_99_2);
  assert(index_reg_59_1 == index_reg_59_2);
  assert(parity_75_1 == parity_75_2);
}

int fn_R001288_8813_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int tracker_99 = local_arr[aux % 3];
  acc = (acc + (tracker_99 * 2)) & 127;
  int index_reg_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_59 > 33)
  {
    acc = ((acc + (index_reg_59 * 2)) + 5) & 127;
    aux ^= index_reg_59 & 15;
  }
  else
  {
    acc = ((acc - index_reg_59) + 11) & 127;
    aux += 3;
  }
  int parity_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001288_8813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st_1 = {0};
  struct CipherContext_R001288_8813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int damping_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_30_1)
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

  switch (damping_30_2)
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

  int parity_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_86_1 > 21)
  {
    acc_1 = ((acc_1 + (parity_86_1 * 2)) + 5) & 127;
    aux_1 ^= parity_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_86_2 > 21)
  {
    acc_2 = ((acc_2 + (parity_86_2 * 2)) + 5) & 127;
    aux_2 ^= parity_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_12_1) & 63;
  aux_2 = (aux_2 + cursor_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_30_1 == damping_30_2);
  assert(parity_86_1 == parity_86_2);
  assert(cursor_12_1 == cursor_12_2);
}

int fn_R001288_8813_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int damping_30 = (aux + st.buffer[1]) & 3;
  switch (damping_30)
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

  int parity_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_86 > 21)
  {
    acc = ((acc + (parity_86 * 2)) + 5) & 127;
    aux ^= parity_86 & 15;
  }
  else
  {
    acc = ((acc - parity_86) + 11) & 127;
    aux += 3;
  }
  int cursor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001288_8813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st_1 = {0};
  struct CipherContext_R001288_8813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int residue_85_1 = 0;
  int residue_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_85_1 = ((residue_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_85_2 = ((residue_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_85_1) & 127;
    acc_2 = (acc_2 + residue_85_2) & 127;
  }

  int quantum_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_35_1) & 63;
  aux_2 = (aux_2 + quantum_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_85_1 == residue_85_2);
  assert(quantum_35_1 == quantum_35_2);
}

int fn_R001288_8813_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int residue_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_85 = ((residue_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_85) & 127;
  }

  int quantum_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001288_8813_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st_1 = {0};
  struct SensorNode_R001288_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int cursor_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_89_1) & 63;
  aux_2 = (aux_2 + cursor_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_96_1 > 25)
  {
    acc_1 = ((acc_1 + (sample_96_1 * 2)) + 5) & 127;
    aux_1 ^= sample_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_96_2 > 25)
  {
    acc_2 = ((acc_2 + (sample_96_2 * 2)) + 5) & 127;
    aux_2 ^= sample_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_67_1 = local_arr_1[aux_1 % 3];
  int window_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_67_2 * 2)) & 127;
  int quotient_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_42_1)
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

  switch (quotient_42_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_89_1 == cursor_89_2);
  assert(sample_96_1 == sample_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_67_1 == window_67_2);
  assert(quotient_42_1 == quotient_42_2);
}

int fn_R001288_8813_12(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int cursor_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_89) & 63;
  acc ^= aux;
  int sample_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_96 > 25)
  {
    acc = ((acc + (sample_96 * 2)) + 5) & 127;
    aux ^= sample_96 & 15;
  }
  else
  {
    acc = ((acc - sample_96) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_67 = local_arr[aux % 3];
  acc = (acc + (window_67 * 2)) & 127;
  int quotient_42 = (aux + st.buffer[1]) & 3;
  switch (quotient_42)
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

void fn_R001288_8813_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st_1 = {0};
  struct SensorNode_R001288_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_86_1 = local_arr_1[aux_1 % 3];
  int tally_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_86_2 * 2)) & 127;
  int vector_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_19_1 > 23)
  {
    acc_1 = ((acc_1 + (vector_19_1 * 2)) + 5) & 127;
    aux_1 ^= vector_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_19_2 > 23)
  {
    acc_2 = ((acc_2 + (vector_19_2 * 2)) + 5) & 127;
    aux_2 ^= vector_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_80_1) & 63;
  aux_2 = (aux_2 + threshold_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_70_1)
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

  switch (quantum_70_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_86_1 == tally_86_2);
  assert(vector_19_1 == vector_19_2);
  assert(threshold_80_1 == threshold_80_2);
  assert(quantum_70_1 == quantum_70_2);
}

int fn_R001288_8813_13(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int tally_86 = local_arr[aux % 3];
  acc = (acc + (tally_86 * 2)) & 127;
  int vector_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_19 > 23)
  {
    acc = ((acc + (vector_19 * 2)) + 5) & 127;
    aux ^= vector_19 & 15;
  }
  else
  {
    acc = ((acc - vector_19) + 11) & 127;
    aux += 3;
  }
  int threshold_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_80) & 63;
  acc ^= aux;
  int quantum_70 = (aux + st.buffer[1]) & 3;
  switch (quantum_70)
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

void fn_R001288_8813_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001288_8813_1 st_1 = {0};
  struct MatrixBlock_R001288_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_58_1)
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

  switch (segment_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_76_1 > 10)
  {
    acc_1 = ((acc_1 + (tracker_76_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_76_2 > 10)
  {
    acc_2 = ((acc_2 + (tracker_76_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_75_1 = 0;
  int quotient_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_75_1 = ((quotient_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_75_2 = ((quotient_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_75_1) & 127;
    acc_2 = (acc_2 + quotient_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_58_1 == segment_58_2);
  assert(tracker_76_1 == tracker_76_2);
  assert(quotient_75_1 == quotient_75_2);
}

int fn_R001288_8813_14(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001288_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_58 = (aux + st.buffer[1]) & 3;
  switch (segment_58)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_76 > 10)
  {
    acc = ((acc + (tracker_76 * 2)) + 5) & 127;
    aux ^= tracker_76 & 15;
  }
  else
  {
    acc = ((acc - tracker_76) + 11) & 127;
    aux += 3;
  }
  int quotient_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_75 = ((quotient_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001288_8813_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001288_8813_2 st_1 = {0};
  struct Transaction_R001288_8813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int bound_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_40_1)
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

  switch (bound_40_2)
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

  int damping_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_75_1) & 63;
  aux_2 = (aux_2 + damping_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_53_1 = local_arr_1[aux_1 % 3];
  int phase_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_53_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_40_1 == bound_40_2);
  assert(damping_75_1 == damping_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_53_1 == phase_53_2);
}

int fn_R001288_8813_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001288_8813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int bound_40 = (aux + st.buffer[1]) & 3;
  switch (bound_40)
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

  int damping_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_75) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_53 = local_arr[aux % 3];
  acc = (acc + (phase_53 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001288_8813_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st_1 = {0};
  struct SensorNode_R001288_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int anchor_47_1 = 0;
  int anchor_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_47_1 = ((anchor_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_47_2 = ((anchor_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_47_1) & 127;
    acc_2 = (acc_2 + anchor_47_2) & 127;
  }

  int offset_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_73_1) & 63;
  aux_2 = (aux_2 + offset_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_48_1 > 10)
  {
    acc_1 = ((acc_1 + (scale_48_1 * 2)) + 5) & 127;
    aux_1 ^= scale_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_48_2 > 10)
  {
    acc_2 = ((acc_2 + (scale_48_2 * 2)) + 5) & 127;
    aux_2 ^= scale_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_48_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_47_1 == anchor_47_2);
  assert(offset_73_1 == offset_73_2);
  assert(scale_48_1 == scale_48_2);
}

int fn_R001288_8813_16(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int anchor_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_47 = ((anchor_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_47) & 127;
  }

  int offset_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_73) & 63;
  acc ^= aux;
  int scale_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_48 > 10)
  {
    acc = ((acc + (scale_48 * 2)) + 5) & 127;
    aux ^= scale_48 & 15;
  }
  else
  {
    acc = ((acc - scale_48) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001288_8813_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st_1 = {0};
  struct SensorNode_R001288_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int margin_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_58_1)
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

  switch (margin_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_17_1 = local_arr_1[aux_1 % 3];
  int coefficient_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_58_1 == margin_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_17_1 == coefficient_17_2);
}

int fn_R001288_8813_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001288_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int margin_58 = (aux + st.buffer[1]) & 3;
  switch (margin_58)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_17 = local_arr[aux % 3];
  acc = (acc + (coefficient_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001288_8813_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001288_8813_2 st_1 = {0};
  struct Transaction_R001288_8813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_27_1 = local_arr_1[aux_1 % 3];
  int factor_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_27_2 * 2)) & 127;
  int index_reg_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_72_1) & 63;
  aux_2 = (aux_2 + index_reg_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_91_1 = 0;
  int scale_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_91_1 = ((scale_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_91_2 = ((scale_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_91_1) & 127;
    acc_2 = (acc_2 + scale_91_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_27_1 == factor_27_2);
  assert(index_reg_72_1 == index_reg_72_2);
  assert(scale_91_1 == scale_91_2);
}

int fn_R001288_8813_18(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001288_8813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int factor_27 = local_arr[aux % 3];
  acc = (acc + (factor_27 * 2)) & 127;
  int index_reg_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_72) & 63;
  acc ^= aux;
  int scale_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_91 = ((scale_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_91) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001288_8813_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st_1 = {0};
  struct CipherContext_R001288_8813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_84_1 = local_arr_1[aux_1 % 3];
  int accumulator_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_84_2 * 2)) & 127;
  int checksum_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_74_1) & 63;
  aux_2 = (aux_2 + checksum_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_84_1 == accumulator_84_2);
  assert(checksum_74_1 == checksum_74_2);
}

int fn_R001288_8813_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int accumulator_84 = local_arr[aux % 3];
  acc = (acc + (accumulator_84 * 2)) & 127;
  int checksum_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001288_8813_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st_1 = {0};
  struct CipherContext_R001288_8813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int stride_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_43_1 > 18)
  {
    acc_1 = ((acc_1 + (stride_43_1 * 2)) + 5) & 127;
    aux_1 ^= stride_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_43_2 > 18)
  {
    acc_2 = ((acc_2 + (stride_43_2 * 2)) + 5) & 127;
    aux_2 ^= stride_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_97_1 = 0;
  int parity_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_97_1 = ((parity_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_97_2 = ((parity_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_97_1) & 127;
    acc_2 = (acc_2 + parity_97_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_43_1 == stride_43_2);
  assert(parity_97_1 == parity_97_2);
}

int fn_R001288_8813_20(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int stride_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_43 > 18)
  {
    acc = ((acc + (stride_43 * 2)) + 5) & 127;
    aux ^= stride_43 & 15;
  }
  else
  {
    acc = ((acc - stride_43) + 11) & 127;
    aux += 3;
  }
  int parity_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_97 = ((parity_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_97) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001288_8813_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st_1 = {0};
  struct CipherContext_R001288_8813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_18_1 = 0;
  int accumulator_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_18_1 = ((accumulator_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_18_2 = ((accumulator_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_18_1) & 127;
    acc_2 = (acc_2 + accumulator_18_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_98_1 = local_arr_1[aux_1 % 3];
  int parity_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_98_2 * 2)) & 127;
  int bound_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_60_1)
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

  switch (bound_60_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_18_1 == accumulator_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_98_1 == parity_98_2);
  assert(bound_60_1 == bound_60_2);
}

int fn_R001288_8813_21(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001288_8813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_18 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_18 = ((accumulator_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_18) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int parity_98 = local_arr[aux % 3];
  acc = (acc + (parity_98 * 2)) & 127;
  int bound_60 = (aux + st.buffer[1]) & 3;
  switch (bound_60)
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

void main()
{
  int sec_r001288_0_1;
  int sec_r001288_0_2;
  int sec_r001288_1_1;
  int sec_r001288_1_2;
  int sec_r001288_2_1;
  int sec_r001288_2_2;
  int sec_r001288_3_1;
  int sec_r001288_3_2;
  int sec_r001288_4_1;
  int sec_r001288_4_2;
  int sec_r001288_5_1;
  int sec_r001288_5_2;
  int sec_r001288_6_1;
  int sec_r001288_6_2;
  int sec_r001288_7_1;
  int sec_r001288_7_2;
  int sec_r001288_8_1;
  int sec_r001288_8_2;
  int sec_r001288_9_1;
  int sec_r001288_9_2;
  int sec_r001288_10_1;
  int sec_r001288_10_2;
  int sec_r001288_11_1;
  int sec_r001288_11_2;
  int sec_r001288_12_1;
  int sec_r001288_12_2;
  int sec_r001288_13_1;
  int sec_r001288_13_2;
  int sec_r001288_14_1;
  int sec_r001288_14_2;
  int sec_r001288_15_1;
  int sec_r001288_15_2;
  int sec_r001288_16_1;
  int sec_r001288_16_2;
  int sec_r001288_17_1;
  int sec_r001288_17_2;
  int sec_r001288_18_1;
  int sec_r001288_18_2;
  int pub_r001288_0_1;
  int pub_r001288_0_2;
  int pub_r001288_1_1;
  int pub_r001288_1_2;
  int pub_r001288_2_1;
  int pub_r001288_2_2;
  int pub_r001288_3_1;
  int pub_r001288_3_2;
  int pub_r001288_4_1;
  int pub_r001288_4_2;
  int pub_r001288_5_1;
  int pub_r001288_5_2;
  int pub_r001288_6_1;
  int pub_r001288_6_2;
  int pub_r001288_7_1;
  int pub_r001288_7_2;
  int pub_r001288_8_1;
  int pub_r001288_8_2;
  int pub_r001288_9_1;
  int pub_r001288_9_2;
  int pub_r001288_10_1;
  int pub_r001288_10_2;
  int pub_r001288_11_1;
  int pub_r001288_11_2;
  int pub_r001288_12_1;
  int pub_r001288_12_2;
  int pub_r001288_13_1;
  int pub_r001288_13_2;
  int pub_r001288_14_1;
  int pub_r001288_14_2;
  int pub_r001288_15_1;
  int pub_r001288_15_2;
  int pub_r001288_16_1;
  int pub_r001288_16_2;
  int pub_r001288_17_1;
  int pub_r001288_17_2;
  int pub_r001288_18_1;
  int pub_r001288_18_2;
  int pub_r001288_19_1;
  int pub_r001288_19_2;
  int pub_r001288_20_1;
  int pub_r001288_20_2;
  int pub_r001288_21_1;
  int pub_r001288_21_2;
  int pub_r001288_22_1;
  int pub_r001288_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001288_0_1 >= (-100)) && (pub_r001288_0_1 <= 100));
  __CPROVER_assume((pub_r001288_0_2 >= (-100)) && (pub_r001288_0_2 <= 100));
  __CPROVER_assume((pub_r001288_1_1 >= (-100)) && (pub_r001288_1_1 <= 100));
  __CPROVER_assume((pub_r001288_1_2 >= (-100)) && (pub_r001288_1_2 <= 100));
  __CPROVER_assume((pub_r001288_2_1 >= (-100)) && (pub_r001288_2_1 <= 100));
  __CPROVER_assume((pub_r001288_2_2 >= (-100)) && (pub_r001288_2_2 <= 100));
  __CPROVER_assume((pub_r001288_3_1 >= (-100)) && (pub_r001288_3_1 <= 100));
  __CPROVER_assume((pub_r001288_3_2 >= (-100)) && (pub_r001288_3_2 <= 100));
  __CPROVER_assume((pub_r001288_4_1 >= (-100)) && (pub_r001288_4_1 <= 100));
  __CPROVER_assume((pub_r001288_4_2 >= (-100)) && (pub_r001288_4_2 <= 100));
  __CPROVER_assume((pub_r001288_5_1 >= (-100)) && (pub_r001288_5_1 <= 100));
  __CPROVER_assume((pub_r001288_5_2 >= (-100)) && (pub_r001288_5_2 <= 100));
  __CPROVER_assume((pub_r001288_6_1 >= (-100)) && (pub_r001288_6_1 <= 100));
  __CPROVER_assume((pub_r001288_6_2 >= (-100)) && (pub_r001288_6_2 <= 100));
  __CPROVER_assume((pub_r001288_7_1 >= (-100)) && (pub_r001288_7_1 <= 100));
  __CPROVER_assume((pub_r001288_7_2 >= (-100)) && (pub_r001288_7_2 <= 100));
  __CPROVER_assume((pub_r001288_8_1 >= (-100)) && (pub_r001288_8_1 <= 100));
  __CPROVER_assume((pub_r001288_8_2 >= (-100)) && (pub_r001288_8_2 <= 100));
  __CPROVER_assume((pub_r001288_9_1 >= (-100)) && (pub_r001288_9_1 <= 100));
  __CPROVER_assume((pub_r001288_9_2 >= (-100)) && (pub_r001288_9_2 <= 100));
  __CPROVER_assume((pub_r001288_10_1 >= (-100)) && (pub_r001288_10_1 <= 100));
  __CPROVER_assume((pub_r001288_10_2 >= (-100)) && (pub_r001288_10_2 <= 100));
  __CPROVER_assume((pub_r001288_11_1 >= (-100)) && (pub_r001288_11_1 <= 100));
  __CPROVER_assume((pub_r001288_11_2 >= (-100)) && (pub_r001288_11_2 <= 100));
  __CPROVER_assume((pub_r001288_12_1 >= (-100)) && (pub_r001288_12_1 <= 100));
  __CPROVER_assume((pub_r001288_12_2 >= (-100)) && (pub_r001288_12_2 <= 100));
  __CPROVER_assume((pub_r001288_13_1 >= (-100)) && (pub_r001288_13_1 <= 100));
  __CPROVER_assume((pub_r001288_13_2 >= (-100)) && (pub_r001288_13_2 <= 100));
  __CPROVER_assume((pub_r001288_14_1 >= (-100)) && (pub_r001288_14_1 <= 100));
  __CPROVER_assume((pub_r001288_14_2 >= (-100)) && (pub_r001288_14_2 <= 100));
  __CPROVER_assume((pub_r001288_15_1 >= (-100)) && (pub_r001288_15_1 <= 100));
  __CPROVER_assume((pub_r001288_15_2 >= (-100)) && (pub_r001288_15_2 <= 100));
  __CPROVER_assume((pub_r001288_16_1 >= (-100)) && (pub_r001288_16_1 <= 100));
  __CPROVER_assume((pub_r001288_16_2 >= (-100)) && (pub_r001288_16_2 <= 100));
  __CPROVER_assume((pub_r001288_17_1 >= (-100)) && (pub_r001288_17_1 <= 100));
  __CPROVER_assume((pub_r001288_17_2 >= (-100)) && (pub_r001288_17_2 <= 100));
  __CPROVER_assume((pub_r001288_18_1 >= (-100)) && (pub_r001288_18_1 <= 100));
  __CPROVER_assume((pub_r001288_18_2 >= (-100)) && (pub_r001288_18_2 <= 100));
  __CPROVER_assume((pub_r001288_19_1 >= (-100)) && (pub_r001288_19_1 <= 100));
  __CPROVER_assume((pub_r001288_19_2 >= (-100)) && (pub_r001288_19_2 <= 100));
  __CPROVER_assume((pub_r001288_20_1 >= (-100)) && (pub_r001288_20_1 <= 100));
  __CPROVER_assume((pub_r001288_20_2 >= (-100)) && (pub_r001288_20_2 <= 100));
  __CPROVER_assume((pub_r001288_21_1 >= (-100)) && (pub_r001288_21_1 <= 100));
  __CPROVER_assume((pub_r001288_21_2 >= (-100)) && (pub_r001288_21_2 <= 100));
  __CPROVER_assume((pub_r001288_22_1 >= (-100)) && (pub_r001288_22_1 <= 100));
  __CPROVER_assume((pub_r001288_22_2 >= (-100)) && (pub_r001288_22_2 <= 100));
  __CPROVER_assume((sec_r001288_0_1 >= 0) && (sec_r001288_0_1 <= 255));
  __CPROVER_assume((sec_r001288_0_2 >= 0) && (sec_r001288_0_2 <= 255));
  __CPROVER_assume((sec_r001288_1_1 >= 0) && (sec_r001288_1_1 <= 255));
  __CPROVER_assume((sec_r001288_1_2 >= 0) && (sec_r001288_1_2 <= 255));
  __CPROVER_assume((sec_r001288_2_1 >= 0) && (sec_r001288_2_1 <= 255));
  __CPROVER_assume((sec_r001288_2_2 >= 0) && (sec_r001288_2_2 <= 255));
  __CPROVER_assume((sec_r001288_3_1 >= 0) && (sec_r001288_3_1 <= 255));
  __CPROVER_assume((sec_r001288_3_2 >= 0) && (sec_r001288_3_2 <= 255));
  __CPROVER_assume((sec_r001288_4_1 >= 0) && (sec_r001288_4_1 <= 255));
  __CPROVER_assume((sec_r001288_4_2 >= 0) && (sec_r001288_4_2 <= 255));
  __CPROVER_assume((sec_r001288_5_1 >= 0) && (sec_r001288_5_1 <= 255));
  __CPROVER_assume((sec_r001288_5_2 >= 0) && (sec_r001288_5_2 <= 255));
  __CPROVER_assume((sec_r001288_6_1 >= 0) && (sec_r001288_6_1 <= 255));
  __CPROVER_assume((sec_r001288_6_2 >= 0) && (sec_r001288_6_2 <= 255));
  __CPROVER_assume((sec_r001288_7_1 >= 0) && (sec_r001288_7_1 <= 255));
  __CPROVER_assume((sec_r001288_7_2 >= 0) && (sec_r001288_7_2 <= 255));
  __CPROVER_assume((sec_r001288_8_1 >= 0) && (sec_r001288_8_1 <= 255));
  __CPROVER_assume((sec_r001288_8_2 >= 0) && (sec_r001288_8_2 <= 255));
  __CPROVER_assume((sec_r001288_9_1 >= 0) && (sec_r001288_9_1 <= 255));
  __CPROVER_assume((sec_r001288_9_2 >= 0) && (sec_r001288_9_2 <= 255));
  __CPROVER_assume((sec_r001288_10_1 >= 0) && (sec_r001288_10_1 <= 255));
  __CPROVER_assume((sec_r001288_10_2 >= 0) && (sec_r001288_10_2 <= 255));
  __CPROVER_assume((sec_r001288_11_1 >= 0) && (sec_r001288_11_1 <= 255));
  __CPROVER_assume((sec_r001288_11_2 >= 0) && (sec_r001288_11_2 <= 255));
  __CPROVER_assume((sec_r001288_12_1 >= 0) && (sec_r001288_12_1 <= 255));
  __CPROVER_assume((sec_r001288_12_2 >= 0) && (sec_r001288_12_2 <= 255));
  __CPROVER_assume((sec_r001288_13_1 >= 0) && (sec_r001288_13_1 <= 255));
  __CPROVER_assume((sec_r001288_13_2 >= 0) && (sec_r001288_13_2 <= 255));
  __CPROVER_assume((sec_r001288_14_1 >= 0) && (sec_r001288_14_1 <= 255));
  __CPROVER_assume((sec_r001288_14_2 >= 0) && (sec_r001288_14_2 <= 255));
  __CPROVER_assume((sec_r001288_15_1 >= 0) && (sec_r001288_15_1 <= 255));
  __CPROVER_assume((sec_r001288_15_2 >= 0) && (sec_r001288_15_2 <= 255));
  __CPROVER_assume((sec_r001288_16_1 >= 0) && (sec_r001288_16_1 <= 255));
  __CPROVER_assume((sec_r001288_16_2 >= 0) && (sec_r001288_16_2 <= 255));
  __CPROVER_assume((sec_r001288_17_1 >= 0) && (sec_r001288_17_1 <= 255));
  __CPROVER_assume((sec_r001288_17_2 >= 0) && (sec_r001288_17_2 <= 255));
  __CPROVER_assume((sec_r001288_18_1 >= 0) && (sec_r001288_18_1 <= 255));
  __CPROVER_assume((sec_r001288_18_2 >= 0) && (sec_r001288_18_2 <= 255));
  struct SensorNode_R001288_8813_0 st_var_0_1 = {0};
  struct SensorNode_R001288_8813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001288_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001288_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001288_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001288_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001288_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001288_0_2 + 7) & 15;
  struct MatrixBlock_R001288_8813_1 st_var_1_1 = {0};
  struct MatrixBlock_R001288_8813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001288_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001288_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001288_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001288_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001288_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001288_0_2 + 9) & 15;
  struct Transaction_R001288_8813_2 st_var_2_1 = {0};
  struct Transaction_R001288_8813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001288_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001288_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001288_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001288_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001288_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001288_0_2 + 11) & 15;
  struct CipherContext_R001288_8813_3 st_var_3_1 = {0};
  struct CipherContext_R001288_8813_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001288_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001288_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001288_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001288_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001288_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001288_0_2 + 13) & 15;
  union PacketPayload_R001288_8813_0 u_var_1;
  union PacketPayload_R001288_8813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001288_8813_0(sec_r001288_0_1, pub_r001288_1_1, pub_r001288_2_1);
  int helper_flow_0_2 = fn_R001288_8813_0(sec_r001288_0_2, pub_r001288_1_2, pub_r001288_2_2);
  fn_R001288_8813_0_2(sec_r001288_0_1, pub_r001288_1_1, pub_r001288_2_1, sec_r001288_0_2, pub_r001288_1_2, pub_r001288_2_2);
  int helper_flow_1_1 = fn_R001288_8813_1(sec_r001288_1_1, sec_r001288_2_1, pub_r001288_3_1, pub_r001288_4_1);
  int helper_flow_1_2 = fn_R001288_8813_1(sec_r001288_1_2, sec_r001288_2_2, pub_r001288_3_2, pub_r001288_4_2);
  fn_R001288_8813_1_2(sec_r001288_1_1, sec_r001288_2_1, pub_r001288_3_1, pub_r001288_4_1, sec_r001288_1_2, sec_r001288_2_2, pub_r001288_3_2, pub_r001288_4_2);
  int helper_flow_2_1 = fn_R001288_8813_2(sec_r001288_2_1, pub_r001288_3_1, pub_r001288_4_1, pub_r001288_5_1, pub_r001288_6_1);
  int helper_flow_2_2 = fn_R001288_8813_2(sec_r001288_2_2, pub_r001288_3_2, pub_r001288_4_2, pub_r001288_5_2, pub_r001288_6_2);
  fn_R001288_8813_2_2(sec_r001288_2_1, pub_r001288_3_1, pub_r001288_4_1, pub_r001288_5_1, pub_r001288_6_1, sec_r001288_2_2, pub_r001288_3_2, pub_r001288_4_2, pub_r001288_5_2, pub_r001288_6_2);
  int helper_flow_3_1 = fn_R001288_8813_3(sec_r001288_3_1, pub_r001288_4_1, pub_r001288_5_1, pub_r001288_6_1, pub_r001288_7_1);
  int helper_flow_3_2 = fn_R001288_8813_3(sec_r001288_3_2, pub_r001288_4_2, pub_r001288_5_2, pub_r001288_6_2, pub_r001288_7_2);
  fn_R001288_8813_3_2(sec_r001288_3_1, pub_r001288_4_1, pub_r001288_5_1, pub_r001288_6_1, pub_r001288_7_1, sec_r001288_3_2, pub_r001288_4_2, pub_r001288_5_2, pub_r001288_6_2, pub_r001288_7_2);
  int helper_flow_4_1 = fn_R001288_8813_4(sec_r001288_4_1, sec_r001288_5_1, pub_r001288_6_1, pub_r001288_7_1, pub_r001288_8_1);
  int helper_flow_4_2 = fn_R001288_8813_4(sec_r001288_4_2, sec_r001288_5_2, pub_r001288_6_2, pub_r001288_7_2, pub_r001288_8_2);
  fn_R001288_8813_4_2(sec_r001288_4_1, sec_r001288_5_1, pub_r001288_6_1, pub_r001288_7_1, pub_r001288_8_1, sec_r001288_4_2, sec_r001288_5_2, pub_r001288_6_2, pub_r001288_7_2, pub_r001288_8_2);
  int helper_flow_5_1 = fn_R001288_8813_5(sec_r001288_5_1, pub_r001288_6_1, pub_r001288_7_1, pub_r001288_8_1, pub_r001288_9_1);
  int helper_flow_5_2 = fn_R001288_8813_5(sec_r001288_5_2, pub_r001288_6_2, pub_r001288_7_2, pub_r001288_8_2, pub_r001288_9_2);
  fn_R001288_8813_5_2(sec_r001288_5_1, pub_r001288_6_1, pub_r001288_7_1, pub_r001288_8_1, pub_r001288_9_1, sec_r001288_5_2, pub_r001288_6_2, pub_r001288_7_2, pub_r001288_8_2, pub_r001288_9_2);
  int helper_flow_6_1 = fn_R001288_8813_6(sec_r001288_6_1, sec_r001288_7_1, pub_r001288_8_1, pub_r001288_9_1);
  int helper_flow_6_2 = fn_R001288_8813_6(sec_r001288_6_2, sec_r001288_7_2, pub_r001288_8_2, pub_r001288_9_2);
  fn_R001288_8813_6_2(sec_r001288_6_1, sec_r001288_7_1, pub_r001288_8_1, pub_r001288_9_1, sec_r001288_6_2, sec_r001288_7_2, pub_r001288_8_2, pub_r001288_9_2);
  int helper_flow_7_1 = fn_R001288_8813_7(sec_r001288_7_1, sec_r001288_8_1, pub_r001288_9_1, pub_r001288_10_1, pub_r001288_11_1);
  int helper_flow_7_2 = fn_R001288_8813_7(sec_r001288_7_2, sec_r001288_8_2, pub_r001288_9_2, pub_r001288_10_2, pub_r001288_11_2);
  fn_R001288_8813_7_2(sec_r001288_7_1, sec_r001288_8_1, pub_r001288_9_1, pub_r001288_10_1, pub_r001288_11_1, sec_r001288_7_2, sec_r001288_8_2, pub_r001288_9_2, pub_r001288_10_2, pub_r001288_11_2);
  int helper_flow_8_1 = fn_R001288_8813_8(sec_r001288_8_1, sec_r001288_9_1);
  int helper_flow_8_2 = fn_R001288_8813_8(sec_r001288_8_2, sec_r001288_9_2);
  fn_R001288_8813_8_2(sec_r001288_8_1, sec_r001288_9_1, sec_r001288_8_2, sec_r001288_9_2);
  int helper_flow_9_1 = fn_R001288_8813_9(sec_r001288_9_1, pub_r001288_10_1, pub_r001288_11_1, pub_r001288_12_1);
  int helper_flow_9_2 = fn_R001288_8813_9(sec_r001288_9_2, pub_r001288_10_2, pub_r001288_11_2, pub_r001288_12_2);
  fn_R001288_8813_9_2(sec_r001288_9_1, pub_r001288_10_1, pub_r001288_11_1, pub_r001288_12_1, sec_r001288_9_2, pub_r001288_10_2, pub_r001288_11_2, pub_r001288_12_2);
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (it_1 * 3)) + (sec_r001288_10_1 & 15)) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (it_2 * 3)) + (sec_r001288_10_2 & 15)) & 63;
    if ((sec_r001288_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_0_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_0_1) + 7) & 255;
    }
    if ((sec_r001288_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_0_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_0_2) + 7) & 255;
    }
  }

  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (it_1 * 3)) + (sec_r001288_11_1 & 15)) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (it_2 * 3)) + (sec_r001288_11_2 & 15)) & 63;
    if ((sec_r001288_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_1_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_1_1) + 7) & 255;
    }
    if ((sec_r001288_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_1_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_1_2) + 7) & 255;
    }
  }

  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (it_1 * 3)) + (sec_r001288_6_1 & 15)) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (it_2 * 3)) + (sec_r001288_6_2 & 15)) & 63;
    if ((sec_r001288_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_2_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_2_1) + 7) & 255;
    }
    if ((sec_r001288_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_2_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_2_2) + 7) & 255;
    }
  }

  int stage_v_3_1 = ((pub_r001288_8_1 * 2) + 34) & 63;
  int stage_v_3_2 = ((pub_r001288_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_4_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_4_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_4_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_4_2) + 7) & 255;
    }
  }

  int stage_v_5_1 = ((pub_r001288_20_1 * 2) + 42) & 63;
  int stage_v_5_2 = ((pub_r001288_20_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (it_1 * 3)) + (sec_r001288_2_1 & 15)) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (it_2 * 3)) + (sec_r001288_2_2 & 15)) & 63;
    if ((sec_r001288_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_6_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_6_1) + 7) & 255;
    }
    if ((sec_r001288_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_6_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_6_2) + 7) & 255;
    }
  }

  int stage_v_7_1 = ((pub_r001288_13_1 * 2) + 16) & 63;
  int stage_v_7_2 = ((pub_r001288_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (it_1 * 3)) + (sec_r001288_15_1 & 15)) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (it_2 * 3)) + (sec_r001288_15_2 & 15)) & 63;
    if ((sec_r001288_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_8_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_8_1) + 7) & 255;
    }
    if ((sec_r001288_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_8_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_8_2) + 7) & 255;
    }
  }

  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (it_1 * 3)) + (sec_r001288_10_1 & 15)) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (it_2 * 3)) + (sec_r001288_10_2 & 15)) & 63;
    if ((sec_r001288_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_9_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_9_1) + 7) & 255;
    }
    if ((sec_r001288_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_9_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_9_2) + 7) & 255;
    }
  }

  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (it_1 * 3)) + (sec_r001288_15_1 & 15)) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (it_2 * 3)) + (sec_r001288_15_2 & 15)) & 63;
    if ((sec_r001288_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_10_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_10_1) + 7) & 255;
    }
    if ((sec_r001288_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_10_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_10_2) + 7) & 255;
    }
  }

  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (it_1 * 3)) + (sec_r001288_3_1 & 15)) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (it_2 * 3)) + (sec_r001288_3_2 & 15)) & 63;
    if ((sec_r001288_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_11_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_11_1) + 7) & 255;
    }
    if ((sec_r001288_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_11_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_11_2) + 7) & 255;
    }
  }

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_12_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_12_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_12_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_12_2) + 7) & 255;
    }
  }

  int stage_v_13_1 = ((pub_r001288_3_1 * 2) + 44) & 63;
  int stage_v_13_2 = ((pub_r001288_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (it_1 * 3)) + (sec_r001288_11_1 & 15)) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (it_2 * 3)) + (sec_r001288_11_2 & 15)) & 63;
    if ((sec_r001288_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_14_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_14_1) + 7) & 255;
    }
    if ((sec_r001288_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_14_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_14_2) + 7) & 255;
    }
  }

  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (it_1 * 3)) + (sec_r001288_12_1 & 15)) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (it_2 * 3)) + (sec_r001288_12_2 & 15)) & 63;
    if ((sec_r001288_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_15_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_15_1) + 7) & 255;
    }
    if ((sec_r001288_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_15_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_15_2) + 7) & 255;
    }
  }

  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (it_1 * 3)) + (stage_v_6_1 & 15)) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (it_2 * 3)) + (stage_v_6_2 & 15)) & 63;
    if ((stage_v_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_16_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_16_1) + 7) & 255;
    }
    if ((stage_v_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_16_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_16_2) + 7) & 255;
    }
  }

  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (it_1 * 3)) + (sec_r001288_10_1 & 15)) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (it_2 * 3)) + (sec_r001288_10_2 & 15)) & 63;
    if ((sec_r001288_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_17_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_17_1) + 7) & 255;
    }
    if ((sec_r001288_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_17_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_17_2) + 7) & 255;
    }
  }

  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (it_1 * 3)) + (sec_r001288_6_1 & 15)) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (it_2 * 3)) + (sec_r001288_6_2 & 15)) & 63;
    if ((sec_r001288_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_18_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_18_1) + 7) & 255;
    }
    if ((sec_r001288_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_18_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_18_2) + 7) & 255;
    }
  }

  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (it_1 * 3)) + (stage_v_1_1 & 15)) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (it_2 * 3)) + (stage_v_1_2 & 15)) & 63;
    if ((stage_v_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_19_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_19_1) + 7) & 255;
    }
    if ((stage_v_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_19_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_19_2) + 7) & 255;
    }
  }

  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (it_1 * 3)) + (sec_r001288_8_1 & 15)) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (it_2 * 3)) + (sec_r001288_8_2 & 15)) & 63;
    if ((sec_r001288_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_20_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_20_1) + 7) & 255;
    }
    if ((sec_r001288_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_20_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_20_2) + 7) & 255;
    }
  }

  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (it_1 * 3)) + (sec_r001288_11_1 & 15)) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (it_2 * 3)) + (sec_r001288_11_2 & 15)) & 63;
    if ((sec_r001288_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_21_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_21_1) + 7) & 255;
    }
    if ((sec_r001288_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_21_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_21_2) + 7) & 255;
    }
  }

  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (it_1 * 3)) + (stage_v_6_1 & 15)) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (it_2 * 3)) + (stage_v_6_2 & 15)) & 63;
    if ((stage_v_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_22_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_22_1) + 7) & 255;
    }
    if ((stage_v_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_22_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_22_2) + 7) & 255;
    }
  }

  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (it_1 * 3)) + (sec_r001288_15_1 & 15)) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (it_2 * 3)) + (sec_r001288_15_2 & 15)) & 63;
    if ((sec_r001288_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_23_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_23_1) + 7) & 255;
    }
    if ((sec_r001288_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_23_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_23_2) + 7) & 255;
    }
  }

  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_24_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_24_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_24_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_24_2) + 7) & 255;
    }
  }

  int stage_v_25_1 = ((pub_r001288_7_1 * 2) + 38) & 63;
  int stage_v_25_2 = ((pub_r001288_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (it_1 * 3)) + (sec_r001288_16_1 & 15)) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (it_2 * 3)) + (sec_r001288_16_2 & 15)) & 63;
    if ((sec_r001288_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_26_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_26_1) + 7) & 255;
    }
    if ((sec_r001288_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_26_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_26_2) + 7) & 255;
    }
  }

  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (it_1 * 3)) + (stage_v_8_1 & 15)) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (it_2 * 3)) + (stage_v_8_2 & 15)) & 63;
    if ((stage_v_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_27_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_27_1) + 7) & 255;
    }
    if ((stage_v_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_27_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_27_2) + 7) & 255;
    }
  }

  int stage_v_28_1 = ((pub_r001288_17_1 * 2) + 40) & 63;
  int stage_v_28_2 = ((pub_r001288_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (it_1 * 3)) + (stage_v_26_1 & 15)) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (it_2 * 3)) + (stage_v_26_2 & 15)) & 63;
    if ((stage_v_26_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_29_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_29_1) + 7) & 255;
    }
    if ((stage_v_26_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_29_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_29_2) + 7) & 255;
    }
  }

  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (it_1 * 3)) + (sec_r001288_10_1 & 15)) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (it_2 * 3)) + (sec_r001288_10_2 & 15)) & 63;
    if ((sec_r001288_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_30_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_30_1) + 7) & 255;
    }
    if ((sec_r001288_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_30_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_30_2) + 7) & 255;
    }
  }

  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (it_1 * 3)) + (sec_r001288_2_1 & 15)) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (it_2 * 3)) + (sec_r001288_2_2 & 15)) & 63;
    if ((sec_r001288_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_31_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_31_1) + 7) & 255;
    }
    if ((sec_r001288_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_31_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_31_2) + 7) & 255;
    }
  }

  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (it_1 * 3)) + (stage_v_9_1 & 15)) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (it_2 * 3)) + (stage_v_9_2 & 15)) & 63;
    if ((stage_v_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_32_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_32_1) + 7) & 255;
    }
    if ((stage_v_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_32_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_32_2) + 7) & 255;
    }
  }

  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_33_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_33_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_33_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_33_2) + 7) & 255;
    }
  }

  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (it_1 * 3)) + (stage_v_33_1 & 15)) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (it_2 * 3)) + (stage_v_33_2 & 15)) & 63;
    if ((stage_v_33_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_34_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_34_1) + 7) & 255;
    }
    if ((stage_v_33_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_34_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_34_2) + 7) & 255;
    }
  }

  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (it_1 * 3)) + (sec_r001288_3_1 & 15)) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (it_2 * 3)) + (sec_r001288_3_2 & 15)) & 63;
    if ((sec_r001288_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_35_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_35_1) + 7) & 255;
    }
    if ((sec_r001288_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_35_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_35_2) + 7) & 255;
    }
  }

  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (it_1 * 3)) + (sec_r001288_14_1 & 15)) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (it_2 * 3)) + (sec_r001288_14_2 & 15)) & 63;
    if ((sec_r001288_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_36_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_36_1) + 7) & 255;
    }
    if ((sec_r001288_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_36_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_36_2) + 7) & 255;
    }
  }

  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (it_1 * 3)) + (stage_v_34_1 & 15)) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (it_2 * 3)) + (stage_v_34_2 & 15)) & 63;
    if ((stage_v_34_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_37_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_37_1) + 7) & 255;
    }
    if ((stage_v_34_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_37_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_37_2) + 7) & 255;
    }
  }

  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (it_1 * 3)) + (stage_v_22_1 & 15)) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (it_2 * 3)) + (stage_v_22_2 & 15)) & 63;
    if ((stage_v_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_38_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_38_1) + 7) & 255;
    }
    if ((stage_v_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_38_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_38_2) + 7) & 255;
    }
  }

  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (it_1 * 3)) + (sec_r001288_1_1 & 15)) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (it_2 * 3)) + (sec_r001288_1_2 & 15)) & 63;
    if ((sec_r001288_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_39_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_39_1) + 7) & 255;
    }
    if ((sec_r001288_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_39_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_39_2) + 7) & 255;
    }
  }

  int stage_v_40_1 = ((pub_r001288_11_1 * 2) + 11) & 63;
  int stage_v_40_2 = ((pub_r001288_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (it_1 * 3)) + (stage_v_14_1 & 15)) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (it_2 * 3)) + (stage_v_14_2 & 15)) & 63;
    if ((stage_v_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_41_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_41_1) + 7) & 255;
    }
    if ((stage_v_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_41_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_41_2) + 7) & 255;
    }
  }

  int stage_v_42_1 = ((pub_r001288_22_1 * 2) + 22) & 63;
  int stage_v_42_2 = ((pub_r001288_22_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (it_1 * 3)) + (stage_v_36_1 & 15)) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (it_2 * 3)) + (stage_v_36_2 & 15)) & 63;
    if ((stage_v_36_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_43_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_43_1) + 7) & 255;
    }
    if ((stage_v_36_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_43_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_43_2) + 7) & 255;
    }
  }

  int stage_v_44_1 = ((pub_r001288_10_1 * 2) + 41) & 63;
  int stage_v_44_2 = ((pub_r001288_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_45_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_45_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_45_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_45_2) + 7) & 255;
    }
  }

  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (it_1 * 3)) + (stage_v_17_1 & 15)) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (it_2 * 3)) + (stage_v_17_2 & 15)) & 63;
    if ((stage_v_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_46_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_46_1) + 7) & 255;
    }
    if ((stage_v_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_46_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_46_2) + 7) & 255;
    }
  }

  int stage_v_47_1 = ((pub_r001288_18_1 * 2) + 21) & 63;
  int stage_v_47_2 = ((pub_r001288_18_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (it_1 * 3)) + (stage_v_45_1 & 15)) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (it_2 * 3)) + (stage_v_45_2 & 15)) & 63;
    if ((stage_v_45_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_48_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_48_1) + 7) & 255;
    }
    if ((stage_v_45_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_48_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_48_2) + 7) & 255;
    }
  }

  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_49_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_49_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_49_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_49_2) + 7) & 255;
    }
  }

  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (it_1 * 3)) + (sec_r001288_7_1 & 15)) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (it_2 * 3)) + (sec_r001288_7_2 & 15)) & 63;
    if ((sec_r001288_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_50_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_50_1) + 7) & 255;
    }
    if ((sec_r001288_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_50_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_50_2) + 7) & 255;
    }
  }

  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (it_1 * 3)) + (stage_v_14_1 & 15)) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (it_2 * 3)) + (stage_v_14_2 & 15)) & 63;
    if ((stage_v_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_51_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_51_1) + 7) & 255;
    }
    if ((stage_v_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_51_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_51_2) + 7) & 255;
    }
  }

  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (it_1 * 3)) + (stage_v_1_1 & 15)) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (it_2 * 3)) + (stage_v_1_2 & 15)) & 63;
    if ((stage_v_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_52_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_52_1) + 7) & 255;
    }
    if ((stage_v_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_52_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_52_2) + 7) & 255;
    }
  }

  int stage_v_53_1 = ((pub_r001288_21_1 * 2) + 6) & 63;
  int stage_v_53_2 = ((pub_r001288_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (it_1 * 3)) + (sec_r001288_13_1 & 15)) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (it_2 * 3)) + (sec_r001288_13_2 & 15)) & 63;
    if ((sec_r001288_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_54_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_54_1) + 7) & 255;
    }
    if ((sec_r001288_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_54_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_54_2) + 7) & 255;
    }
  }

  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (it_1 * 3)) + (sec_r001288_3_1 & 15)) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (it_2 * 3)) + (sec_r001288_3_2 & 15)) & 63;
    if ((sec_r001288_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_55_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_55_1) + 7) & 255;
    }
    if ((sec_r001288_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_55_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_55_2) + 7) & 255;
    }
  }

  int stage_v_56_1 = ((pub_r001288_10_1 * 2) + 31) & 63;
  int stage_v_56_2 = ((pub_r001288_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001288_8_1 * 2) + 50) & 63;
  int stage_v_57_2 = ((pub_r001288_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (it_1 * 3)) + (sec_r001288_7_1 & 15)) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (it_2 * 3)) + (sec_r001288_7_2 & 15)) & 63;
    if ((sec_r001288_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_58_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_58_1) + 7) & 255;
    }
    if ((sec_r001288_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_58_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_58_2) + 7) & 255;
    }
  }

  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (it_1 * 3)) + (stage_v_46_1 & 15)) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (it_2 * 3)) + (stage_v_46_2 & 15)) & 63;
    if ((stage_v_46_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_59_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_59_1) + 7) & 255;
    }
    if ((stage_v_46_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_59_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_59_2) + 7) & 255;
    }
  }

  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (it_1 * 3)) + (stage_v_29_1 & 15)) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (it_2 * 3)) + (stage_v_29_2 & 15)) & 63;
    if ((stage_v_29_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_60_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_60_1) + 7) & 255;
    }
    if ((stage_v_29_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_60_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_60_2) + 7) & 255;
    }
  }

  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (it_1 * 3)) + (sec_r001288_14_1 & 15)) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (it_2 * 3)) + (sec_r001288_14_2 & 15)) & 63;
    if ((sec_r001288_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_61_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_61_1) + 7) & 255;
    }
    if ((sec_r001288_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_61_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_61_2) + 7) & 255;
    }
  }

  int stage_v_62_1 = ((pub_r001288_6_1 * 2) + 11) & 63;
  int stage_v_62_2 = ((pub_r001288_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001288_3_1 * 2) + 28) & 63;
  int stage_v_63_2 = ((pub_r001288_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_64_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_64_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_64_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_64_2) + 7) & 255;
    }
  }

  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (it_1 * 3)) + (stage_v_14_1 & 15)) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (it_2 * 3)) + (stage_v_14_2 & 15)) & 63;
    if ((stage_v_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_65_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_65_1) + 7) & 255;
    }
    if ((stage_v_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_65_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_65_2) + 7) & 255;
    }
  }

  int stage_v_66_1 = ((pub_r001288_16_1 * 2) + 31) & 63;
  int stage_v_66_2 = ((pub_r001288_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_67_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_67_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_67_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_67_2) + 7) & 255;
    }
  }

  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (it_1 * 3)) + (stage_v_14_1 & 15)) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (it_2 * 3)) + (stage_v_14_2 & 15)) & 63;
    if ((stage_v_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_68_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_68_1) + 7) & 255;
    }
    if ((stage_v_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_68_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_68_2) + 7) & 255;
    }
  }

  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (it_1 * 3)) + (stage_v_26_1 & 15)) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (it_2 * 3)) + (stage_v_26_2 & 15)) & 63;
    if ((stage_v_26_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_69_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_69_1) + 7) & 255;
    }
    if ((stage_v_26_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_69_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_69_2) + 7) & 255;
    }
  }

  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (it_1 * 3)) + (sec_r001288_14_1 & 15)) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (it_2 * 3)) + (sec_r001288_14_2 & 15)) & 63;
    if ((sec_r001288_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_70_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_70_1) + 7) & 255;
    }
    if ((sec_r001288_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_70_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_70_2) + 7) & 255;
    }
  }

  int stage_v_71_1 = ((pub_r001288_21_1 * 2) + 47) & 63;
  int stage_v_71_2 = ((pub_r001288_21_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (it_1 * 3)) + (sec_r001288_3_1 & 15)) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (it_2 * 3)) + (sec_r001288_3_2 & 15)) & 63;
    if ((sec_r001288_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_72_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_72_1) + 7) & 255;
    }
    if ((sec_r001288_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_72_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_72_2) + 7) & 255;
    }
  }

  int stage_v_73_1 = ((pub_r001288_11_1 * 2) + 42) & 63;
  int stage_v_73_2 = ((pub_r001288_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_74_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_74_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_74_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_74_2) + 7) & 255;
    }
  }

  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (it_1 * 3)) + (stage_v_46_1 & 15)) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (it_2 * 3)) + (stage_v_46_2 & 15)) & 63;
    if ((stage_v_46_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_75_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_75_1) + 7) & 255;
    }
    if ((stage_v_46_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_75_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_75_2) + 7) & 255;
    }
  }

  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (it_1 * 3)) + (stage_v_75_1 & 15)) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (it_2 * 3)) + (stage_v_75_2 & 15)) & 63;
    if ((stage_v_75_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_76_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_76_1) + 7) & 255;
    }
    if ((stage_v_75_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_76_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_76_2) + 7) & 255;
    }
  }

  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (it_1 * 3)) + (sec_r001288_16_1 & 15)) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (it_2 * 3)) + (sec_r001288_16_2 & 15)) & 63;
    if ((sec_r001288_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_77_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_77_1) + 7) & 255;
    }
    if ((sec_r001288_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_77_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_77_2) + 7) & 255;
    }
  }

  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (it_1 * 3)) + (stage_v_17_1 & 15)) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (it_2 * 3)) + (stage_v_17_2 & 15)) & 63;
    if ((stage_v_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_78_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_78_1) + 7) & 255;
    }
    if ((stage_v_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_78_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_78_2) + 7) & 255;
    }
  }

  int stage_v_79_1 = ((pub_r001288_2_1 * 2) + 49) & 63;
  int stage_v_79_2 = ((pub_r001288_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001288_20_1 * 2) + 23) & 63;
  int stage_v_80_2 = ((pub_r001288_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (it_1 * 3)) + (sec_r001288_2_1 & 15)) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (it_2 * 3)) + (sec_r001288_2_2 & 15)) & 63;
    if ((sec_r001288_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_81_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_81_1) + 7) & 255;
    }
    if ((sec_r001288_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_81_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_81_2) + 7) & 255;
    }
  }

  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_82_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_82_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_82_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_82_2) + 7) & 255;
    }
  }

  int stage_v_83_1 = ((pub_r001288_11_1 * 2) + 7) & 63;
  int stage_v_83_2 = ((pub_r001288_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (it_1 * 3)) + (stage_v_55_1 & 15)) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (it_2 * 3)) + (stage_v_55_2 & 15)) & 63;
    if ((stage_v_55_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_84_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_84_1) + 7) & 255;
    }
    if ((stage_v_55_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_84_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_84_2) + 7) & 255;
    }
  }

  int stage_v_85_1 = ((pub_r001288_21_1 * 2) + 49) & 63;
  int stage_v_85_2 = ((pub_r001288_21_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001288_17_1 * 2) + 25) & 63;
  int stage_v_86_2 = ((pub_r001288_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (it_1 * 3)) + (stage_v_84_1 & 15)) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (it_2 * 3)) + (stage_v_84_2 & 15)) & 63;
    if ((stage_v_84_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_87_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_87_1) + 7) & 255;
    }
    if ((stage_v_84_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_87_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_87_2) + 7) & 255;
    }
  }

  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (it_1 * 3)) + (stage_v_20_1 & 15)) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (it_2 * 3)) + (stage_v_20_2 & 15)) & 63;
    if ((stage_v_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_88_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_88_1) + 7) & 255;
    }
    if ((stage_v_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_88_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_88_2) + 7) & 255;
    }
  }

  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_89_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_89_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_89_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_89_2) + 7) & 255;
    }
  }

  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_90_1 = ((stage_v_90_1 + (it_1 * 3)) + (sec_r001288_7_1 & 15)) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (it_2 * 3)) + (sec_r001288_7_2 & 15)) & 63;
    if ((sec_r001288_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_90_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_90_1) + 7) & 255;
    }
    if ((sec_r001288_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_90_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_90_2) + 7) & 255;
    }
  }

  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (it_1 * 3)) + (helper_flow_7_1 & 15)) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (it_2 * 3)) + (helper_flow_7_2 & 15)) & 63;
    if ((helper_flow_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_91_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_91_1) + 7) & 255;
    }
    if ((helper_flow_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_91_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_91_2) + 7) & 255;
    }
  }

  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (it_1 * 3)) + (stage_v_6_1 & 15)) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (it_2 * 3)) + (stage_v_6_2 & 15)) & 63;
    if ((stage_v_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_92_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_92_1) + 7) & 255;
    }
    if ((stage_v_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_92_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_92_2) + 7) & 255;
    }
  }

  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (it_1 * 3)) + (stage_v_68_1 & 15)) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (it_2 * 3)) + (stage_v_68_2 & 15)) & 63;
    if ((stage_v_68_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_93_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_93_1) + 7) & 255;
    }
    if ((stage_v_68_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_93_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_93_2) + 7) & 255;
    }
  }

  int stage_v_94_1 = ((pub_r001288_4_1 * 2) + 50) & 63;
  int stage_v_94_2 = ((pub_r001288_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_95_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_95_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_95_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_95_2) + 7) & 255;
    }
  }

  int stage_v_96_1 = ((pub_r001288_7_1 * 2) + 47) & 63;
  int stage_v_96_2 = ((pub_r001288_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (it_1 * 3)) + (stage_v_41_1 & 15)) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (it_2 * 3)) + (stage_v_41_2 & 15)) & 63;
    if ((stage_v_41_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_97_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_97_1) + 7) & 255;
    }
    if ((stage_v_41_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_97_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_97_2) + 7) & 255;
    }
  }

  int stage_v_98_1 = ((pub_r001288_9_1 * 2) + 9) & 63;
  int stage_v_98_2 = ((pub_r001288_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (it_1 * 3)) + (sec_r001288_14_1 & 15)) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (it_2 * 3)) + (sec_r001288_14_2 & 15)) & 63;
    if ((sec_r001288_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_99_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_99_1) + 7) & 255;
    }
    if ((sec_r001288_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_99_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_99_2) + 7) & 255;
    }
  }

  int stage_v_100_1 = ((pub_r001288_3_1 * 2) + 28) & 63;
  int stage_v_100_2 = ((pub_r001288_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_101_1 = ((stage_v_101_1 + (it_1 * 3)) + (stage_v_75_1 & 15)) & 63;
    stage_v_101_2 = ((stage_v_101_2 + (it_2 * 3)) + (stage_v_75_2 & 15)) & 63;
    if ((stage_v_75_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_101_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_101_1) + 7) & 255;
    }
    if ((stage_v_75_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_101_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_101_2) + 7) & 255;
    }
  }

  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_102_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_102_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_102_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_102_2) + 7) & 255;
    }
  }

  int stage_v_103_1 = ((pub_r001288_16_1 * 2) + 18) & 63;
  int stage_v_103_2 = ((pub_r001288_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001288_9_1 * 2) + 40) & 63;
  int stage_v_104_2 = ((pub_r001288_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001288_17_1 * 2) + 5) & 63;
  int stage_v_105_2 = ((pub_r001288_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001288_18_1 * 2) + 33) & 63;
  int stage_v_106_2 = ((pub_r001288_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (it_1 * 3)) + (stage_v_37_1 & 15)) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (it_2 * 3)) + (stage_v_37_2 & 15)) & 63;
    if ((stage_v_37_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_107_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_107_1) + 7) & 255;
    }
    if ((stage_v_37_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_107_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_107_2) + 7) & 255;
    }
  }

  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_108_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_108_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_108_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_108_2) + 7) & 255;
    }
  }

  int stage_v_109_1 = ((pub_r001288_22_1 * 2) + 16) & 63;
  int stage_v_109_2 = ((pub_r001288_22_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001288_14_1 * 2) + 42) & 63;
  int stage_v_110_2 = ((pub_r001288_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_111_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_111_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_111_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_111_2) + 7) & 255;
    }
  }

  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (it_1 * 3)) + (stage_v_35_1 & 15)) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (it_2 * 3)) + (stage_v_35_2 & 15)) & 63;
    if ((stage_v_35_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_112_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_112_1) + 7) & 255;
    }
    if ((stage_v_35_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_112_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_112_2) + 7) & 255;
    }
  }

  int stage_v_113_1 = ((pub_r001288_21_1 * 2) + 29) & 63;
  int stage_v_113_2 = ((pub_r001288_21_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001288_19_1 * 2) + 28) & 63;
  int stage_v_114_2 = ((pub_r001288_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (it_1 * 3)) + (stage_v_33_1 & 15)) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (it_2 * 3)) + (stage_v_33_2 & 15)) & 63;
    if ((stage_v_33_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_115_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_115_1) + 7) & 255;
    }
    if ((stage_v_33_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_115_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_115_2) + 7) & 255;
    }
  }

  int stage_v_116_1 = ((pub_r001288_9_1 * 2) + 5) & 63;
  int stage_v_116_2 = ((pub_r001288_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_117_1 = ((stage_v_117_1 + (it_1 * 3)) + (stage_v_112_1 & 15)) & 63;
    stage_v_117_2 = ((stage_v_117_2 + (it_2 * 3)) + (stage_v_112_2 & 15)) & 63;
    if ((stage_v_112_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_117_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_117_1) + 7) & 255;
    }
    if ((stage_v_112_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_117_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_117_2) + 7) & 255;
    }
  }

  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (it_1 * 3)) + (stage_v_67_1 & 15)) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (it_2 * 3)) + (stage_v_67_2 & 15)) & 63;
    if ((stage_v_67_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_118_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_118_1) + 7) & 255;
    }
    if ((stage_v_67_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_118_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_118_2) + 7) & 255;
    }
  }

  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (it_1 * 3)) + (stage_v_75_1 & 15)) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (it_2 * 3)) + (stage_v_75_2 & 15)) & 63;
    if ((stage_v_75_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_119_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_119_1) + 7) & 255;
    }
    if ((stage_v_75_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_119_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_119_2) + 7) & 255;
    }
  }

  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_120_1 = ((stage_v_120_1 + (it_1 * 3)) + (stage_v_32_1 & 15)) & 63;
    stage_v_120_2 = ((stage_v_120_2 + (it_2 * 3)) + (stage_v_32_2 & 15)) & 63;
    if ((stage_v_32_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_120_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_120_1) + 7) & 255;
    }
    if ((stage_v_32_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_120_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_120_2) + 7) & 255;
    }
  }

  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (it_1 * 3)) + (stage_v_50_1 & 15)) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (it_2 * 3)) + (stage_v_50_2 & 15)) & 63;
    if ((stage_v_50_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_121_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_121_1) + 7) & 255;
    }
    if ((stage_v_50_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_121_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_121_2) + 7) & 255;
    }
  }

  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_122_1 = ((stage_v_122_1 + (it_1 * 3)) + (stage_v_95_1 & 15)) & 63;
    stage_v_122_2 = ((stage_v_122_2 + (it_2 * 3)) + (stage_v_95_2 & 15)) & 63;
    if ((stage_v_95_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_122_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_122_1) + 7) & 255;
    }
    if ((stage_v_95_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_122_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_122_2) + 7) & 255;
    }
  }

  int stage_v_123_1 = ((pub_r001288_19_1 * 2) + 30) & 63;
  int stage_v_123_2 = ((pub_r001288_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_124_1 = ((stage_v_124_1 + (it_1 * 3)) + (stage_v_69_1 & 15)) & 63;
    stage_v_124_2 = ((stage_v_124_2 + (it_2 * 3)) + (stage_v_69_2 & 15)) & 63;
    if ((stage_v_69_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_124_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_124_1) + 7) & 255;
    }
    if ((stage_v_69_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_124_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_124_2) + 7) & 255;
    }
  }

  int stage_v_125_1 = ((pub_r001288_20_1 * 2) + 28) & 63;
  int stage_v_125_2 = ((pub_r001288_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (it_1 * 3)) + (stage_v_93_1 & 15)) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (it_2 * 3)) + (stage_v_93_2 & 15)) & 63;
    if ((stage_v_93_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_126_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_126_1) + 7) & 255;
    }
    if ((stage_v_93_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_126_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_126_2) + 7) & 255;
    }
  }

  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_127_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_127_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_127_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_127_2) + 7) & 255;
    }
  }

  int stage_v_128_1 = ((pub_r001288_10_1 * 2) + 44) & 63;
  int stage_v_128_2 = ((pub_r001288_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (it_1 * 3)) + (stage_v_68_1 & 15)) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (it_2 * 3)) + (stage_v_68_2 & 15)) & 63;
    if ((stage_v_68_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_129_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_129_1) + 7) & 255;
    }
    if ((stage_v_68_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_129_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_129_2) + 7) & 255;
    }
  }

  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_130_1 = ((stage_v_130_1 + (it_1 * 3)) + (stage_v_102_1 & 15)) & 63;
    stage_v_130_2 = ((stage_v_130_2 + (it_2 * 3)) + (stage_v_102_2 & 15)) & 63;
    if ((stage_v_102_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_130_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_130_1) + 7) & 255;
    }
    if ((stage_v_102_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_130_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_130_2) + 7) & 255;
    }
  }

  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (it_1 * 3)) + (stage_v_16_1 & 15)) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (it_2 * 3)) + (stage_v_16_2 & 15)) & 63;
    if ((stage_v_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_131_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_131_1) + 7) & 255;
    }
    if ((stage_v_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_131_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_131_2) + 7) & 255;
    }
  }

  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_132_1 = ((stage_v_132_1 + (it_1 * 3)) + (stage_v_19_1 & 15)) & 63;
    stage_v_132_2 = ((stage_v_132_2 + (it_2 * 3)) + (stage_v_19_2 & 15)) & 63;
    if ((stage_v_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_132_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_132_1) + 7) & 255;
    }
    if ((stage_v_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_132_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_132_2) + 7) & 255;
    }
  }

  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (it_1 * 3)) + (stage_v_49_1 & 15)) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (it_2 * 3)) + (stage_v_49_2 & 15)) & 63;
    if ((stage_v_49_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_133_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_133_1) + 7) & 255;
    }
    if ((stage_v_49_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_133_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_133_2) + 7) & 255;
    }
  }

  int stage_v_134_1 = ((pub_r001288_1_1 * 2) + 5) & 63;
  int stage_v_134_2 = ((pub_r001288_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_135_1 = ((stage_v_135_1 + (it_1 * 3)) + (stage_v_89_1 & 15)) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (it_2 * 3)) + (stage_v_89_2 & 15)) & 63;
    if ((stage_v_89_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_135_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_135_1) + 7) & 255;
    }
    if ((stage_v_89_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_135_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_135_2) + 7) & 255;
    }
  }

  int stage_v_136_1 = ((pub_r001288_17_1 * 2) + 28) & 63;
  int stage_v_136_2 = ((pub_r001288_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001288_16_1 * 2) + 16) & 63;
  int stage_v_137_2 = ((pub_r001288_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_138_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_138_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_138_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_138_2) + 7) & 255;
    }
  }

  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_139_1 = ((stage_v_139_1 + (it_1 * 3)) + (stage_v_108_1 & 15)) & 63;
    stage_v_139_2 = ((stage_v_139_2 + (it_2 * 3)) + (stage_v_108_2 & 15)) & 63;
    if ((stage_v_108_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_139_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_139_1) + 7) & 255;
    }
    if ((stage_v_108_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_139_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_139_2) + 7) & 255;
    }
  }

  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (it_1 * 3)) + (stage_v_17_1 & 15)) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (it_2 * 3)) + (stage_v_17_2 & 15)) & 63;
    if ((stage_v_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_140_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_140_1) + 7) & 255;
    }
    if ((stage_v_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_140_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_140_2) + 7) & 255;
    }
  }

  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (it_1 * 3)) + (stage_v_131_1 & 15)) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (it_2 * 3)) + (stage_v_131_2 & 15)) & 63;
    if ((stage_v_131_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_141_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_141_1) + 7) & 255;
    }
    if ((stage_v_131_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_141_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_141_2) + 7) & 255;
    }
  }

  int stage_v_142_1 = ((pub_r001288_0_1 * 2) + 37) & 63;
  int stage_v_142_2 = ((pub_r001288_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001288_18_1 * 2) + 41) & 63;
  int stage_v_143_2 = ((pub_r001288_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (it_1 * 3)) + (stage_v_34_1 & 15)) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (it_2 * 3)) + (stage_v_34_2 & 15)) & 63;
    if ((stage_v_34_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_144_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_144_1) + 7) & 255;
    }
    if ((stage_v_34_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_144_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_144_2) + 7) & 255;
    }
  }

  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (it_1 * 3)) + (stage_v_102_1 & 15)) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (it_2 * 3)) + (stage_v_102_2 & 15)) & 63;
    if ((stage_v_102_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_145_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_145_1) + 7) & 255;
    }
    if ((stage_v_102_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_145_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_145_2) + 7) & 255;
    }
  }

  int stage_v_146_1 = ((pub_r001288_18_1 * 2) + 29) & 63;
  int stage_v_146_2 = ((pub_r001288_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (it_1 * 3)) + (sec_r001288_18_1 & 15)) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (it_2 * 3)) + (sec_r001288_18_2 & 15)) & 63;
    if ((sec_r001288_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_147_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_147_1) + 7) & 255;
    }
    if ((sec_r001288_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_147_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_147_2) + 7) & 255;
    }
  }

  int stage_v_148_1 = ((pub_r001288_5_1 * 2) + 47) & 63;
  int stage_v_148_2 = ((pub_r001288_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (it_1 * 3)) + (stage_v_39_1 & 15)) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (it_2 * 3)) + (stage_v_39_2 & 15)) & 63;
    if ((stage_v_39_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_149_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_149_1) + 7) & 255;
    }
    if ((stage_v_39_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_149_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_149_2) + 7) & 255;
    }
  }

  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (it_1 * 3)) + (stage_v_95_1 & 15)) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (it_2 * 3)) + (stage_v_95_2 & 15)) & 63;
    if ((stage_v_95_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_150_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_150_1) + 7) & 255;
    }
    if ((stage_v_95_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_150_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_150_2) + 7) & 255;
    }
  }

  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_151_1 = ((stage_v_151_1 + (it_1 * 3)) + (helper_flow_9_1 & 15)) & 63;
    stage_v_151_2 = ((stage_v_151_2 + (it_2 * 3)) + (helper_flow_9_2 & 15)) & 63;
    if ((helper_flow_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_151_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_151_1) + 7) & 255;
    }
    if ((helper_flow_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_151_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_151_2) + 7) & 255;
    }
  }

  int stage_v_152_1 = ((pub_r001288_21_1 * 2) + 34) & 63;
  int stage_v_152_2 = ((pub_r001288_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001288_15_1 * 2) + 31) & 63;
  int stage_v_153_2 = ((pub_r001288_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_154_1 = ((stage_v_154_1 + (it_1 * 3)) + (sec_r001288_11_1 & 15)) & 63;
    stage_v_154_2 = ((stage_v_154_2 + (it_2 * 3)) + (sec_r001288_11_2 & 15)) & 63;
    if ((sec_r001288_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_154_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_154_1) + 7) & 255;
    }
    if ((sec_r001288_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_154_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_154_2) + 7) & 255;
    }
  }

  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_155_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_155_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_155_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_155_2) + 7) & 255;
    }
  }

  int stage_v_156_1 = ((pub_r001288_4_1 * 2) + 26) & 63;
  int stage_v_156_2 = ((pub_r001288_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_157_1 = ((stage_v_157_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_157_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_157_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_157_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_157_2) + 7) & 255;
    }
  }

  int stage_v_158_1 = ((pub_r001288_7_1 * 2) + 19) & 63;
  int stage_v_158_2 = ((pub_r001288_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_159_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_159_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_159_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_159_2) + 7) & 255;
    }
  }

  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (it_1 * 3)) + (stage_v_20_1 & 15)) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (it_2 * 3)) + (stage_v_20_2 & 15)) & 63;
    if ((stage_v_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_160_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_160_1) + 7) & 255;
    }
    if ((stage_v_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_160_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_160_2) + 7) & 255;
    }
  }

  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_161_1 = ((stage_v_161_1 + (it_1 * 3)) + (stage_v_59_1 & 15)) & 63;
    stage_v_161_2 = ((stage_v_161_2 + (it_2 * 3)) + (stage_v_59_2 & 15)) & 63;
    if ((stage_v_59_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_161_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_161_1) + 7) & 255;
    }
    if ((stage_v_59_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_161_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_161_2) + 7) & 255;
    }
  }

  int stage_v_162_1 = ((pub_r001288_3_1 * 2) + 6) & 63;
  int stage_v_162_2 = ((pub_r001288_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (it_1 * 3)) + (stage_v_149_1 & 15)) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (it_2 * 3)) + (stage_v_149_2 & 15)) & 63;
    if ((stage_v_149_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_163_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_163_1) + 7) & 255;
    }
    if ((stage_v_149_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_163_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_163_2) + 7) & 255;
    }
  }

  int stage_v_164_1 = ((pub_r001288_18_1 * 2) + 10) & 63;
  int stage_v_164_2 = ((pub_r001288_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001288_1_1 * 2) + 38) & 63;
  int stage_v_165_2 = ((pub_r001288_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (it_1 * 3)) + (stage_v_127_1 & 15)) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (it_2 * 3)) + (stage_v_127_2 & 15)) & 63;
    if ((stage_v_127_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_166_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_166_1) + 7) & 255;
    }
    if ((stage_v_127_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_166_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_166_2) + 7) & 255;
    }
  }

  int stage_v_167_1 = ((pub_r001288_20_1 * 2) + 43) & 63;
  int stage_v_167_2 = ((pub_r001288_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001288_19_1 * 2) + 41) & 63;
  int stage_v_168_2 = ((pub_r001288_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_169_1 = ((stage_v_169_1 + (it_1 * 3)) + (stage_v_69_1 & 15)) & 63;
    stage_v_169_2 = ((stage_v_169_2 + (it_2 * 3)) + (stage_v_69_2 & 15)) & 63;
    if ((stage_v_69_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_169_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_169_1) + 7) & 255;
    }
    if ((stage_v_69_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_169_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_169_2) + 7) & 255;
    }
  }

  int stage_v_170_1 = ((pub_r001288_12_1 * 2) + 5) & 63;
  int stage_v_170_2 = ((pub_r001288_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (it_1 * 3)) + (stage_v_60_1 & 15)) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (it_2 * 3)) + (stage_v_60_2 & 15)) & 63;
    if ((stage_v_60_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_171_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_171_1) + 7) & 255;
    }
    if ((stage_v_60_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_171_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_171_2) + 7) & 255;
    }
  }

  int stage_v_172_1 = ((pub_r001288_15_1 * 2) + 39) & 63;
  int stage_v_172_2 = ((pub_r001288_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_173_1 = ((stage_v_173_1 + (it_1 * 3)) + (stage_v_117_1 & 15)) & 63;
    stage_v_173_2 = ((stage_v_173_2 + (it_2 * 3)) + (stage_v_117_2 & 15)) & 63;
    if ((stage_v_117_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_173_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_173_1) + 7) & 255;
    }
    if ((stage_v_117_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_173_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_173_2) + 7) & 255;
    }
  }

  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_174_1 = ((stage_v_174_1 + (it_1 * 3)) + (helper_flow_7_1 & 15)) & 63;
    stage_v_174_2 = ((stage_v_174_2 + (it_2 * 3)) + (helper_flow_7_2 & 15)) & 63;
    if ((helper_flow_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_174_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_174_1) + 7) & 255;
    }
    if ((helper_flow_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_174_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_174_2) + 7) & 255;
    }
  }

  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_175_1 = ((stage_v_175_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_175_2 = ((stage_v_175_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_175_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_175_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_175_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_175_2) + 7) & 255;
    }
  }

  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (it_1 * 3)) + (stage_v_140_1 & 15)) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (it_2 * 3)) + (stage_v_140_2 & 15)) & 63;
    if ((stage_v_140_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_176_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_176_1) + 7) & 255;
    }
    if ((stage_v_140_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_176_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_176_2) + 7) & 255;
    }
  }

  int stage_v_177_1 = ((pub_r001288_22_1 * 2) + 26) & 63;
  int stage_v_177_2 = ((pub_r001288_22_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = 0;
  int stage_v_178_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_178_1 = ((stage_v_178_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_178_2 = ((stage_v_178_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_178_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_178_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_178_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_178_2) + 7) & 255;
    }
  }

  int stage_v_179_1 = ((pub_r001288_19_1 * 2) + 8) & 63;
  int stage_v_179_2 = ((pub_r001288_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001288_3_1 * 2) + 41) & 63;
  int stage_v_180_2 = ((pub_r001288_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_181_1 = ((stage_v_181_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_181_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_181_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_181_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_181_2) + 7) & 255;
    }
  }

  int stage_v_182_1 = ((pub_r001288_15_1 * 2) + 6) & 63;
  int stage_v_182_2 = ((pub_r001288_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_183_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_183_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_183_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_183_2) + 7) & 255;
    }
  }

  int stage_v_184_1 = 0;
  int stage_v_184_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_184_1 = ((stage_v_184_1 + (it_1 * 3)) + (stage_v_31_1 & 15)) & 63;
    stage_v_184_2 = ((stage_v_184_2 + (it_2 * 3)) + (stage_v_31_2 & 15)) & 63;
    if ((stage_v_31_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_184_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_184_1) + 7) & 255;
    }
    if ((stage_v_31_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_184_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_184_2) + 7) & 255;
    }
  }

  int stage_v_185_1 = 0;
  int stage_v_185_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_185_1 = ((stage_v_185_1 + (it_1 * 3)) + (stage_v_166_1 & 15)) & 63;
    stage_v_185_2 = ((stage_v_185_2 + (it_2 * 3)) + (stage_v_166_2 & 15)) & 63;
    if ((stage_v_166_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_185_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_185_1) + 7) & 255;
    }
    if ((stage_v_166_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_185_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_185_2) + 7) & 255;
    }
  }

  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_186_1 = ((stage_v_186_1 + (it_1 * 3)) + (stage_v_171_1 & 15)) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (it_2 * 3)) + (stage_v_171_2 & 15)) & 63;
    if ((stage_v_171_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_186_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_186_1) + 7) & 255;
    }
    if ((stage_v_171_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_186_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_186_2) + 7) & 255;
    }
  }

  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_187_1 = ((stage_v_187_1 + (it_1 * 3)) + (stage_v_17_1 & 15)) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (it_2 * 3)) + (stage_v_17_2 & 15)) & 63;
    if ((stage_v_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_187_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_187_1) + 7) & 255;
    }
    if ((stage_v_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_187_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_187_2) + 7) & 255;
    }
  }

  int stage_v_188_1 = ((pub_r001288_9_1 * 2) + 18) & 63;
  int stage_v_188_2 = ((pub_r001288_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = 0;
  int stage_v_189_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_189_1 = ((stage_v_189_1 + (it_1 * 3)) + (stage_v_39_1 & 15)) & 63;
    stage_v_189_2 = ((stage_v_189_2 + (it_2 * 3)) + (stage_v_39_2 & 15)) & 63;
    if ((stage_v_39_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_189_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_189_1) + 7) & 255;
    }
    if ((stage_v_39_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_189_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_189_2) + 7) & 255;
    }
  }

  int stage_v_190_1 = 0;
  int stage_v_190_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_190_1 = ((stage_v_190_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_190_2 = ((stage_v_190_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_190_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_190_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_190_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_190_2) + 7) & 255;
    }
  }

  int stage_v_191_1 = 0;
  int stage_v_191_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_191_1 = ((stage_v_191_1 + (it_1 * 3)) + (stage_v_93_1 & 15)) & 63;
    stage_v_191_2 = ((stage_v_191_2 + (it_2 * 3)) + (stage_v_93_2 & 15)) & 63;
    if ((stage_v_93_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_191_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_191_1) + 7) & 255;
    }
    if ((stage_v_93_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_191_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_191_2) + 7) & 255;
    }
  }

  int stage_v_192_1 = 0;
  int stage_v_192_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_192_1 = ((stage_v_192_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_192_2 = ((stage_v_192_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_192_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_192_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_192_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_192_2) + 7) & 255;
    }
  }

  int stage_v_193_1 = ((pub_r001288_0_1 * 2) + 35) & 63;
  int stage_v_193_2 = ((pub_r001288_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = 0;
  int stage_v_194_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_194_1 = ((stage_v_194_1 + (it_1 * 3)) + (sec_r001288_14_1 & 15)) & 63;
    stage_v_194_2 = ((stage_v_194_2 + (it_2 * 3)) + (sec_r001288_14_2 & 15)) & 63;
    if ((sec_r001288_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_194_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_194_1) + 7) & 255;
    }
    if ((sec_r001288_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_194_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_194_2) + 7) & 255;
    }
  }

  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001288_0_1 != sec_r001288_0_2);
  __CPROVER_assume(sec_r001288_15_1 != sec_r001288_15_2);
  __CPROVER_assume(pub_r001288_12_1 == pub_r001288_12_2);
  __CPROVER_assume(sec_r001288_3_1 != sec_r001288_3_2);
  __CPROVER_assume(sec_r001288_6_1 != sec_r001288_6_2);
  __CPROVER_assume(pub_r001288_1_1 == pub_r001288_1_2);
  __CPROVER_assume(pub_r001288_17_1 == pub_r001288_17_2);
  __CPROVER_assume(pub_r001288_22_1 == pub_r001288_22_2);
  __CPROVER_assume(pub_r001288_8_1 == pub_r001288_8_2);
  __CPROVER_assume(sec_r001288_16_1 != sec_r001288_16_2);
  __CPROVER_assume(pub_r001288_9_1 == pub_r001288_9_2);
  __CPROVER_assume(pub_r001288_21_1 == pub_r001288_21_2);
  __CPROVER_assume(pub_r001288_4_1 == pub_r001288_4_2);
  __CPROVER_assume(sec_r001288_11_1 != sec_r001288_11_2);
  __CPROVER_assume(pub_r001288_10_1 == pub_r001288_10_2);
  __CPROVER_assume(sec_r001288_5_1 != sec_r001288_5_2);
  __CPROVER_assume(sec_r001288_8_1 != sec_r001288_8_2);
  __CPROVER_assume(pub_r001288_5_1 == pub_r001288_5_2);
  __CPROVER_assume(sec_r001288_13_1 != sec_r001288_13_2);
  __CPROVER_assume(pub_r001288_13_1 == pub_r001288_13_2);
  __CPROVER_assume(sec_r001288_2_1 != sec_r001288_2_2);
  __CPROVER_assume(pub_r001288_6_1 == pub_r001288_6_2);
  __CPROVER_assume(pub_r001288_20_1 == pub_r001288_20_2);
  __CPROVER_assume(sec_r001288_1_1 != sec_r001288_1_2);
  __CPROVER_assume(pub_r001288_11_1 == pub_r001288_11_2);
  __CPROVER_assume(pub_r001288_15_1 == pub_r001288_15_2);
  __CPROVER_assume(pub_r001288_14_1 == pub_r001288_14_2);
  __CPROVER_assume(pub_r001288_19_1 == pub_r001288_19_2);
  __CPROVER_assume(pub_r001288_3_1 == pub_r001288_3_2);
  __CPROVER_assume(pub_r001288_7_1 == pub_r001288_7_2);
  __CPROVER_assume(pub_r001288_18_1 == pub_r001288_18_2);
  __CPROVER_assume(sec_r001288_17_1 != sec_r001288_17_2);
  __CPROVER_assume(sec_r001288_9_1 != sec_r001288_9_2);
  __CPROVER_assume(sec_r001288_7_1 != sec_r001288_7_2);
  __CPROVER_assume(sec_r001288_14_1 != sec_r001288_14_2);
  __CPROVER_assume(pub_r001288_0_1 == pub_r001288_0_2);
  __CPROVER_assume(pub_r001288_2_1 == pub_r001288_2_2);
  __CPROVER_assume(sec_r001288_18_1 != sec_r001288_18_2);
  __CPROVER_assume(sec_r001288_4_1 != sec_r001288_4_2);
  __CPROVER_assume(sec_r001288_10_1 != sec_r001288_10_2);
  __CPROVER_assume(sec_r001288_12_1 != sec_r001288_12_2);
  __CPROVER_assume(pub_r001288_16_1 == pub_r001288_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.counter == st_var_3_2.counter);
  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.tag == st_var_3_2.tag);
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
}


