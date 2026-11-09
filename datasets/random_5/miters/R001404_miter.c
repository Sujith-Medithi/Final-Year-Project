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
struct Transaction_R001404_413_0
{
  unsigned char balance;
  int status;
  unsigned char rate;
  int buffer[3];
};
struct FilterState_R001404_413_1
{
  int gain_db;
  int cutoff;
  int damping;
  int prev_in;
  int buffer[3];
};
struct Vector3D_R001404_413_2
{
  int heading;
  int coord_x;
  unsigned char pitch;
  short coord_z;
  short norm_sq;
  unsigned char coord_y;
  int buffer[3];
};
struct StreamBuffer_R001404_413_3
{
  int state;
  unsigned char watermark;
  unsigned char tail;
  int buffer[3];
};
union PacketPayload_R001404_413_0
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
void fn_R001404_413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_43_1 = 0;
  int quotient_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_43_1 = ((quotient_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_43_2 = ((quotient_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_43_1) & 127;
    acc_2 = (acc_2 + quotient_43_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_90_1 = local_arr_1[aux_1 % 3];
  int bound_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_43_1 == quotient_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_90_1 == bound_90_2);
}

int fn_R001404_413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_43 = ((quotient_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_43) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_90 = local_arr[aux % 3];
  acc = (acc + (bound_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001404_413_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st_1 = {0};
  struct Transaction_R001404_413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int phase_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_75_1)
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

  switch (phase_75_2)
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

  int residue_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_89_1 > 31)
  {
    acc_1 = ((acc_1 + (residue_89_1 * 2)) + 5) & 127;
    aux_1 ^= residue_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_89_2 > 31)
  {
    acc_2 = ((acc_2 + (residue_89_2 * 2)) + 5) & 127;
    aux_2 ^= residue_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_13_1 = 0;
  int stride_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_13_1 = ((stride_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_13_2 = ((stride_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_13_1) & 127;
    acc_2 = (acc_2 + stride_13_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_75_1 == phase_75_2);
  assert(residue_89_1 == residue_89_2);
  assert(stride_13_1 == stride_13_2);
}

int fn_R001404_413_1(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int phase_75 = (aux + st.buffer[1]) & 3;
  switch (phase_75)
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

  int residue_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_89 > 31)
  {
    acc = ((acc + (residue_89 * 2)) + 5) & 127;
    aux ^= residue_89 & 15;
  }
  else
  {
    acc = ((acc - residue_89) + 11) & 127;
    aux += 3;
  }
  int stride_13 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_13 = ((stride_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_13) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001404_413_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quotient_73_1 = 0;
  int quotient_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_73_1 = ((quotient_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_73_2 = ((quotient_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_73_1) & 127;
    acc_2 = (acc_2 + quotient_73_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_26_1 > 26)
  {
    acc_1 = ((acc_1 + (parity_26_1 * 2)) + 5) & 127;
    aux_1 ^= parity_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_26_2 > 26)
  {
    acc_2 = ((acc_2 + (parity_26_2 * 2)) + 5) & 127;
    aux_2 ^= parity_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_99_1)
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

  switch (offset_99_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_73_1 == quotient_73_2);
  assert(parity_26_1 == parity_26_2);
  assert(offset_99_1 == offset_99_2);
}

int fn_R001404_413_2(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quotient_73 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_73 = ((quotient_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_73) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_26 > 26)
  {
    acc = ((acc + (parity_26 * 2)) + 5) & 127;
    aux ^= parity_26 & 15;
  }
  else
  {
    acc = ((acc - parity_26) + 11) & 127;
    aux += 3;
  }
  int offset_99 = (aux + st.buffer[1]) & 3;
  switch (offset_99)
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

void fn_R001404_413_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int quantum_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_10_1 > 11)
  {
    acc_1 = ((acc_1 + (quantum_10_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_10_2 > 11)
  {
    acc_2 = ((acc_2 + (quantum_10_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_37_1) & 63;
  aux_2 = (aux_2 + sample_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_17_1 = 0;
  int offset_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_17_1 = ((offset_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_17_2 = ((offset_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_17_1) & 127;
    acc_2 = (acc_2 + offset_17_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_10_1 == quantum_10_2);
  assert(sample_37_1 == sample_37_2);
  assert(offset_17_1 == offset_17_2);
}

int fn_R001404_413_3(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int quantum_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_10 > 11)
  {
    acc = ((acc + (quantum_10 * 2)) + 5) & 127;
    aux ^= quantum_10 & 15;
  }
  else
  {
    acc = ((acc - quantum_10) + 11) & 127;
    aux += 3;
  }
  int sample_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_37) & 63;
  acc ^= aux;
  int offset_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_17 = ((offset_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_17) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001404_413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st_1 = {0};
  struct Transaction_R001404_413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int weight_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_60_1)
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

  switch (weight_60_2)
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

  int margin_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_36_1 > 40)
  {
    acc_1 = ((acc_1 + (margin_36_1 * 2)) + 5) & 127;
    aux_1 ^= margin_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_36_2 > 40)
  {
    acc_2 = ((acc_2 + (margin_36_2 * 2)) + 5) & 127;
    aux_2 ^= margin_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_36_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_60_1 == weight_60_2);
  assert(margin_36_1 == margin_36_2);
}

int fn_R001404_413_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int weight_60 = (aux + st.buffer[1]) & 3;
  switch (weight_60)
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

  int margin_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_36 > 40)
  {
    acc = ((acc + (margin_36 * 2)) + 5) & 127;
    aux ^= margin_36 & 15;
  }
  else
  {
    acc = ((acc - margin_36) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001404_413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001404_413_3 st_1 = {0};
  struct StreamBuffer_R001404_413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_63_1 = local_arr_1[aux_1 % 3];
  int coefficient_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_63_2 * 2)) & 127;
  int window_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_33_1 > 33)
  {
    acc_1 = ((acc_1 + (window_33_1 * 2)) + 5) & 127;
    aux_1 ^= window_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_33_2 > 33)
  {
    acc_2 = ((acc_2 + (window_33_2 * 2)) + 5) & 127;
    aux_2 ^= window_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_74_1 = 0;
  int mask_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_74_1 = ((mask_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_74_2 = ((mask_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_74_1) & 127;
    acc_2 = (acc_2 + mask_74_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_63_1 == coefficient_63_2);
  assert(window_33_1 == window_33_2);
  assert(mask_74_1 == mask_74_2);
}

int fn_R001404_413_5(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001404_413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int coefficient_63 = local_arr[aux % 3];
  acc = (acc + (coefficient_63 * 2)) & 127;
  int window_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_33 > 33)
  {
    acc = ((acc + (window_33 * 2)) + 5) & 127;
    aux ^= window_33 & 15;
  }
  else
  {
    acc = ((acc - window_33) + 11) & 127;
    aux += 3;
  }
  int mask_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_74 = ((mask_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_74) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001404_413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st_1 = {0};
  struct Transaction_R001404_413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_99_1)
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

  switch (factor_99_2)
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

  int tally_66_1 = 0;
  int tally_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_66_1 = ((tally_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_66_2 = ((tally_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_66_1) & 127;
    acc_2 = (acc_2 + tally_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_99_1 == factor_99_2);
  assert(tally_66_1 == tally_66_2);
}

int fn_R001404_413_6(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_99 = (aux + st.buffer[1]) & 3;
  switch (factor_99)
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

  int tally_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_66 = ((tally_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001404_413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_45_1 = local_arr_1[aux_1 % 3];
  int phase_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_45_2 * 2)) & 127;
  int sample_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_83_1)
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

  switch (sample_83_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_39_1 > 39)
  {
    acc_1 = ((acc_1 + (index_reg_39_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_39_2 > 39)
  {
    acc_2 = ((acc_2 + (index_reg_39_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_45_1 == phase_45_2);
  assert(sample_83_1 == sample_83_2);
  assert(index_reg_39_1 == index_reg_39_2);
}

int fn_R001404_413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int phase_45 = local_arr[aux % 3];
  acc = (acc + (phase_45 * 2)) & 127;
  int sample_83 = (aux + st.buffer[1]) & 3;
  switch (sample_83)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_39 > 39)
  {
    acc = ((acc + (index_reg_39 * 2)) + 5) & 127;
    aux ^= index_reg_39 & 15;
  }
  else
  {
    acc = ((acc - index_reg_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001404_413_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st_1 = {0};
  struct Transaction_R001404_413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_64_1 = local_arr_1[aux_1 % 3];
  int segment_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_64_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_98_1 > 41)
  {
    acc_1 = ((acc_1 + (metric_98_1 * 2)) + 5) & 127;
    aux_1 ^= metric_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_98_2 > 41)
  {
    acc_2 = ((acc_2 + (metric_98_2 * 2)) + 5) & 127;
    aux_2 ^= metric_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_64_1 == segment_64_2);
  assert(metric_98_1 == metric_98_2);
}

int fn_R001404_413_8(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int segment_64 = local_arr[aux % 3];
  acc = (acc + (segment_64 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_98 > 41)
  {
    acc = ((acc + (metric_98 * 2)) + 5) & 127;
    aux ^= metric_98 & 15;
  }
  else
  {
    acc = ((acc - metric_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001404_413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001404_413_3 st_1 = {0};
  struct StreamBuffer_R001404_413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int vector_25_1 = 0;
  int vector_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_25_1 = ((vector_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_25_2 = ((vector_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_25_1) & 127;
    acc_2 = (acc_2 + vector_25_2) & 127;
  }

  int threshold_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_17_1 > 32)
  {
    acc_1 = ((acc_1 + (threshold_17_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_17_2 > 32)
  {
    acc_2 = ((acc_2 + (threshold_17_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_43_1 = local_arr_1[aux_1 % 3];
  int metric_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_43_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_25_1 == vector_25_2);
  assert(threshold_17_1 == threshold_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_43_1 == metric_43_2);
}

int fn_R001404_413_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001404_413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int vector_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_25 = ((vector_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_25) & 127;
  }

  int threshold_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_17 > 32)
  {
    acc = ((acc + (threshold_17 * 2)) + 5) & 127;
    aux ^= threshold_17 & 15;
  }
  else
  {
    acc = ((acc - threshold_17) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_43 = local_arr[aux % 3];
  acc = (acc + (metric_43 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001404_413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st_1 = {0};
  struct Transaction_R001404_413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int window_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_59_1) & 63;
  aux_2 = (aux_2 + window_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_24_1)
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

  switch (phase_24_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_59_1 == window_59_2);
  assert(phase_24_1 == phase_24_2);
}

int fn_R001404_413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int window_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_59) & 63;
  acc ^= aux;
  int phase_24 = (aux + st.buffer[1]) & 3;
  switch (phase_24)
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

void fn_R001404_413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_13_1 > 15)
  {
    acc_1 = ((acc_1 + (pivot_13_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_13_2 > 15)
  {
    acc_2 = ((acc_2 + (pivot_13_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_71_1 = 0;
  int sample_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_71_1 = ((sample_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_71_2 = ((sample_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_71_1) & 127;
    acc_2 = (acc_2 + sample_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_13_1 == pivot_13_2);
  assert(sample_71_1 == sample_71_2);
}

int fn_R001404_413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_13 > 15)
  {
    acc = ((acc + (pivot_13 * 2)) + 5) & 127;
    aux ^= pivot_13 & 15;
  }
  else
  {
    acc = ((acc - pivot_13) + 11) & 127;
    aux += 3;
  }
  int sample_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_71 = ((sample_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001404_413_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st_1 = {0};
  struct Transaction_R001404_413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_35_1) & 63;
  aux_2 = (aux_2 + anchor_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_72_1 = 0;
  int pivot_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_72_1 = ((pivot_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_72_2 = ((pivot_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_72_1) & 127;
    acc_2 = (acc_2 + pivot_72_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_30_1 = local_arr_1[aux_1 % 3];
  int delta_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_30_2 * 2)) & 127;
  int checksum_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_66_1)
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

  switch (checksum_66_2)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_35_1 == anchor_35_2);
  assert(pivot_72_1 == pivot_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_30_1 == delta_30_2);
  assert(checksum_66_1 == checksum_66_2);
}

int fn_R001404_413_12(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_35) & 63;
  acc ^= aux;
  int pivot_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_72 = ((pivot_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_72) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int delta_30 = local_arr[aux % 3];
  acc = (acc + (delta_30 * 2)) & 127;
  int checksum_66 = (aux + st.buffer[1]) & 3;
  switch (checksum_66)
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

void fn_R001404_413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int delta_59_1 = 0;
  int delta_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_59_1 = ((delta_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_59_2 = ((delta_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_59_1) & 127;
    acc_2 = (acc_2 + delta_59_2) & 127;
  }

  int margin_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_19_1 > 41)
  {
    acc_1 = ((acc_1 + (margin_19_1 * 2)) + 5) & 127;
    aux_1 ^= margin_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_19_2 > 41)
  {
    acc_2 = ((acc_2 + (margin_19_2 * 2)) + 5) & 127;
    aux_2 ^= margin_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_19_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_59_1 == delta_59_2);
  assert(margin_19_1 == margin_19_2);
}

int fn_R001404_413_13(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int delta_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_59 = ((delta_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_59) & 127;
  }

  int margin_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_19 > 41)
  {
    acc = ((acc + (margin_19 * 2)) + 5) & 127;
    aux ^= margin_19 & 15;
  }
  else
  {
    acc = ((acc - margin_19) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001404_413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_30_1) & 63;
  aux_2 = (aux_2 + index_reg_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_30_1 == index_reg_30_2);
}

int fn_R001404_413_14(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001404_413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_83_1 = 0;
  int checksum_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_83_1 = ((checksum_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_83_2 = ((checksum_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_83_1) & 127;
    acc_2 = (acc_2 + checksum_83_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_83_1 == checksum_83_2);
}

int fn_R001404_413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_83 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_83 = ((checksum_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_83) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001404_413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st_1 = {0};
  struct Transaction_R001404_413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_96_1 = local_arr_1[aux_1 % 3];
  int cursor_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_96_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_96_1 == cursor_96_2);
}

int fn_R001404_413_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int cursor_96 = local_arr[aux % 3];
  acc = (acc + (cursor_96 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001404_413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001404_413_3 st_1 = {0};
  struct StreamBuffer_R001404_413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int stride_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_73_1)
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

  switch (stride_73_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_73_1 == stride_73_2);
}

int fn_R001404_413_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001404_413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int stride_73 = (aux + st.buffer[1]) & 3;
  switch (stride_73)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001404_413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001404_413_2 st_1 = {0};
  struct Vector3D_R001404_413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int accumulator_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_26_1)
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

  switch (accumulator_26_2)
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

  int margin_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_21_1) & 63;
  aux_2 = (aux_2 + margin_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_26_1 == accumulator_26_2);
  assert(margin_21_1 == margin_21_2);
}

int fn_R001404_413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001404_413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int accumulator_26 = (aux + st.buffer[1]) & 3;
  switch (accumulator_26)
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

  int margin_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_21) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001404_413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001404_413_3 st_1 = {0};
  struct StreamBuffer_R001404_413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int bound_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_42_1) & 63;
  aux_2 = (aux_2 + bound_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_73_1 > 20)
  {
    acc_1 = ((acc_1 + (quantum_73_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_73_2 > 20)
  {
    acc_2 = ((acc_2 + (quantum_73_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_98_1 = local_arr_1[aux_1 % 3];
  int delta_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_42_1 == bound_42_2);
  assert(quantum_73_1 == quantum_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_98_1 == delta_98_2);
}

int fn_R001404_413_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001404_413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int bound_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_42) & 63;
  acc ^= aux;
  int quantum_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_73 > 20)
  {
    acc = ((acc + (quantum_73 * 2)) + 5) & 127;
    aux ^= quantum_73 & 15;
  }
  else
  {
    acc = ((acc - quantum_73) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_98 = local_arr[aux % 3];
  acc = (acc + (delta_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001404_413_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int factor_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_99_1) & 63;
  aux_2 = (aux_2 + factor_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_51_1 = local_arr_1[aux_1 % 3];
  int quantum_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_51_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_34_1 = 0;
  int anchor_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_34_1 = ((anchor_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_34_2 = ((anchor_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_34_1) & 127;
    acc_2 = (acc_2 + anchor_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_99_1 == factor_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_51_1 == quantum_51_2);
  assert(anchor_34_1 == anchor_34_2);
}

int fn_R001404_413_20(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int factor_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_99) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_51 = local_arr[aux % 3];
  acc = (acc + (quantum_51 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_34 = ((anchor_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001404_413_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st_1 = {0};
  struct FilterState_R001404_413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int anchor_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_86_1)
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

  switch (anchor_86_2)
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
  int sample_52_1 = local_arr_1[aux_1 % 3];
  int sample_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_52_2 * 2)) & 127;
  int index_reg_61_1 = 0;
  int index_reg_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_61_1 = ((index_reg_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_61_2 = ((index_reg_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_61_1) & 127;
    acc_2 = (acc_2 + index_reg_61_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_86_1 == anchor_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_52_1 == sample_52_2);
  assert(index_reg_61_1 == index_reg_61_2);
}

int fn_R001404_413_21(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001404_413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int anchor_86 = (aux + st.buffer[1]) & 3;
  switch (anchor_86)
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
  int sample_52 = local_arr[aux % 3];
  acc = (acc + (sample_52 * 2)) & 127;
  int index_reg_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_61 = ((index_reg_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_61) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001404_413_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001404_413_2 st_1 = {0};
  struct Vector3D_R001404_413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int pivot_16_1 = 0;
  int pivot_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_16_1 = ((pivot_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_16_2 = ((pivot_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_16_1) & 127;
    acc_2 = (acc_2 + pivot_16_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_16_1 == pivot_16_2);
}

int fn_R001404_413_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001404_413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int pivot_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_16 = ((pivot_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_16) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001404_413_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st_1 = {0};
  struct Transaction_R001404_413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int vector_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_37_1)
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

  switch (vector_37_2)
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
  int cursor_64_1 = local_arr_1[aux_1 % 3];
  int cursor_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_64_2 * 2)) & 127;
  int scale_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_31_1 > 13)
  {
    acc_1 = ((acc_1 + (scale_31_1 * 2)) + 5) & 127;
    aux_1 ^= scale_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_31_2 > 13)
  {
    acc_2 = ((acc_2 + (scale_31_2 * 2)) + 5) & 127;
    aux_2 ^= scale_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_37_1 == vector_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_64_1 == cursor_64_2);
  assert(scale_31_1 == scale_31_2);
}

int fn_R001404_413_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001404_413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int vector_37 = (aux + st.buffer[1]) & 3;
  switch (vector_37)
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
  int cursor_64 = local_arr[aux % 3];
  acc = (acc + (cursor_64 * 2)) & 127;
  int scale_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_31 > 13)
  {
    acc = ((acc + (scale_31 * 2)) + 5) & 127;
    aux ^= scale_31 & 15;
  }
  else
  {
    acc = ((acc - scale_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001404_0_1;
  int sec_r001404_0_2;
  int sec_r001404_1_1;
  int sec_r001404_1_2;
  int sec_r001404_2_1;
  int sec_r001404_2_2;
  int sec_r001404_3_1;
  int sec_r001404_3_2;
  int sec_r001404_4_1;
  int sec_r001404_4_2;
  int sec_r001404_5_1;
  int sec_r001404_5_2;
  int sec_r001404_6_1;
  int sec_r001404_6_2;
  int sec_r001404_7_1;
  int sec_r001404_7_2;
  int sec_r001404_8_1;
  int sec_r001404_8_2;
  int sec_r001404_9_1;
  int sec_r001404_9_2;
  int sec_r001404_10_1;
  int sec_r001404_10_2;
  int sec_r001404_11_1;
  int sec_r001404_11_2;
  int sec_r001404_12_1;
  int sec_r001404_12_2;
  int sec_r001404_13_1;
  int sec_r001404_13_2;
  int sec_r001404_14_1;
  int sec_r001404_14_2;
  int sec_r001404_15_1;
  int sec_r001404_15_2;
  int sec_r001404_16_1;
  int sec_r001404_16_2;
  int pub_r001404_0_1;
  int pub_r001404_0_2;
  int pub_r001404_1_1;
  int pub_r001404_1_2;
  int pub_r001404_2_1;
  int pub_r001404_2_2;
  int pub_r001404_3_1;
  int pub_r001404_3_2;
  int pub_r001404_4_1;
  int pub_r001404_4_2;
  int pub_r001404_5_1;
  int pub_r001404_5_2;
  int pub_r001404_6_1;
  int pub_r001404_6_2;
  int pub_r001404_7_1;
  int pub_r001404_7_2;
  int pub_r001404_8_1;
  int pub_r001404_8_2;
  int pub_r001404_9_1;
  int pub_r001404_9_2;
  int pub_r001404_10_1;
  int pub_r001404_10_2;
  int pub_r001404_11_1;
  int pub_r001404_11_2;
  int pub_r001404_12_1;
  int pub_r001404_12_2;
  int pub_r001404_13_1;
  int pub_r001404_13_2;
  int pub_r001404_14_1;
  int pub_r001404_14_2;
  int pub_r001404_15_1;
  int pub_r001404_15_2;
  int pub_r001404_16_1;
  int pub_r001404_16_2;
  int pub_r001404_17_1;
  int pub_r001404_17_2;
  int pub_r001404_18_1;
  int pub_r001404_18_2;
  int pub_r001404_19_1;
  int pub_r001404_19_2;
  int pub_r001404_20_1;
  int pub_r001404_20_2;
  int pub_r001404_21_1;
  int pub_r001404_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001404_0_1 >= (-100)) && (pub_r001404_0_1 <= 100));
  __CPROVER_assume((pub_r001404_0_2 >= (-100)) && (pub_r001404_0_2 <= 100));
  __CPROVER_assume((pub_r001404_1_1 >= (-100)) && (pub_r001404_1_1 <= 100));
  __CPROVER_assume((pub_r001404_1_2 >= (-100)) && (pub_r001404_1_2 <= 100));
  __CPROVER_assume((pub_r001404_2_1 >= (-100)) && (pub_r001404_2_1 <= 100));
  __CPROVER_assume((pub_r001404_2_2 >= (-100)) && (pub_r001404_2_2 <= 100));
  __CPROVER_assume((pub_r001404_3_1 >= (-100)) && (pub_r001404_3_1 <= 100));
  __CPROVER_assume((pub_r001404_3_2 >= (-100)) && (pub_r001404_3_2 <= 100));
  __CPROVER_assume((pub_r001404_4_1 >= (-100)) && (pub_r001404_4_1 <= 100));
  __CPROVER_assume((pub_r001404_4_2 >= (-100)) && (pub_r001404_4_2 <= 100));
  __CPROVER_assume((pub_r001404_5_1 >= (-100)) && (pub_r001404_5_1 <= 100));
  __CPROVER_assume((pub_r001404_5_2 >= (-100)) && (pub_r001404_5_2 <= 100));
  __CPROVER_assume((pub_r001404_6_1 >= (-100)) && (pub_r001404_6_1 <= 100));
  __CPROVER_assume((pub_r001404_6_2 >= (-100)) && (pub_r001404_6_2 <= 100));
  __CPROVER_assume((pub_r001404_7_1 >= (-100)) && (pub_r001404_7_1 <= 100));
  __CPROVER_assume((pub_r001404_7_2 >= (-100)) && (pub_r001404_7_2 <= 100));
  __CPROVER_assume((pub_r001404_8_1 >= (-100)) && (pub_r001404_8_1 <= 100));
  __CPROVER_assume((pub_r001404_8_2 >= (-100)) && (pub_r001404_8_2 <= 100));
  __CPROVER_assume((pub_r001404_9_1 >= (-100)) && (pub_r001404_9_1 <= 100));
  __CPROVER_assume((pub_r001404_9_2 >= (-100)) && (pub_r001404_9_2 <= 100));
  __CPROVER_assume((pub_r001404_10_1 >= (-100)) && (pub_r001404_10_1 <= 100));
  __CPROVER_assume((pub_r001404_10_2 >= (-100)) && (pub_r001404_10_2 <= 100));
  __CPROVER_assume((pub_r001404_11_1 >= (-100)) && (pub_r001404_11_1 <= 100));
  __CPROVER_assume((pub_r001404_11_2 >= (-100)) && (pub_r001404_11_2 <= 100));
  __CPROVER_assume((pub_r001404_12_1 >= (-100)) && (pub_r001404_12_1 <= 100));
  __CPROVER_assume((pub_r001404_12_2 >= (-100)) && (pub_r001404_12_2 <= 100));
  __CPROVER_assume((pub_r001404_13_1 >= (-100)) && (pub_r001404_13_1 <= 100));
  __CPROVER_assume((pub_r001404_13_2 >= (-100)) && (pub_r001404_13_2 <= 100));
  __CPROVER_assume((pub_r001404_14_1 >= (-100)) && (pub_r001404_14_1 <= 100));
  __CPROVER_assume((pub_r001404_14_2 >= (-100)) && (pub_r001404_14_2 <= 100));
  __CPROVER_assume((pub_r001404_15_1 >= (-100)) && (pub_r001404_15_1 <= 100));
  __CPROVER_assume((pub_r001404_15_2 >= (-100)) && (pub_r001404_15_2 <= 100));
  __CPROVER_assume((pub_r001404_16_1 >= (-100)) && (pub_r001404_16_1 <= 100));
  __CPROVER_assume((pub_r001404_16_2 >= (-100)) && (pub_r001404_16_2 <= 100));
  __CPROVER_assume((pub_r001404_17_1 >= (-100)) && (pub_r001404_17_1 <= 100));
  __CPROVER_assume((pub_r001404_17_2 >= (-100)) && (pub_r001404_17_2 <= 100));
  __CPROVER_assume((pub_r001404_18_1 >= (-100)) && (pub_r001404_18_1 <= 100));
  __CPROVER_assume((pub_r001404_18_2 >= (-100)) && (pub_r001404_18_2 <= 100));
  __CPROVER_assume((pub_r001404_19_1 >= (-100)) && (pub_r001404_19_1 <= 100));
  __CPROVER_assume((pub_r001404_19_2 >= (-100)) && (pub_r001404_19_2 <= 100));
  __CPROVER_assume((pub_r001404_20_1 >= (-100)) && (pub_r001404_20_1 <= 100));
  __CPROVER_assume((pub_r001404_20_2 >= (-100)) && (pub_r001404_20_2 <= 100));
  __CPROVER_assume((pub_r001404_21_1 >= (-100)) && (pub_r001404_21_1 <= 100));
  __CPROVER_assume((pub_r001404_21_2 >= (-100)) && (pub_r001404_21_2 <= 100));
  __CPROVER_assume((sec_r001404_0_1 >= 0) && (sec_r001404_0_1 <= 255));
  __CPROVER_assume((sec_r001404_0_2 >= 0) && (sec_r001404_0_2 <= 255));
  __CPROVER_assume((sec_r001404_1_1 >= 0) && (sec_r001404_1_1 <= 255));
  __CPROVER_assume((sec_r001404_1_2 >= 0) && (sec_r001404_1_2 <= 255));
  __CPROVER_assume((sec_r001404_2_1 >= 0) && (sec_r001404_2_1 <= 255));
  __CPROVER_assume((sec_r001404_2_2 >= 0) && (sec_r001404_2_2 <= 255));
  __CPROVER_assume((sec_r001404_3_1 >= 0) && (sec_r001404_3_1 <= 255));
  __CPROVER_assume((sec_r001404_3_2 >= 0) && (sec_r001404_3_2 <= 255));
  __CPROVER_assume((sec_r001404_4_1 >= 0) && (sec_r001404_4_1 <= 255));
  __CPROVER_assume((sec_r001404_4_2 >= 0) && (sec_r001404_4_2 <= 255));
  __CPROVER_assume((sec_r001404_5_1 >= 0) && (sec_r001404_5_1 <= 255));
  __CPROVER_assume((sec_r001404_5_2 >= 0) && (sec_r001404_5_2 <= 255));
  __CPROVER_assume((sec_r001404_6_1 >= 0) && (sec_r001404_6_1 <= 255));
  __CPROVER_assume((sec_r001404_6_2 >= 0) && (sec_r001404_6_2 <= 255));
  __CPROVER_assume((sec_r001404_7_1 >= 0) && (sec_r001404_7_1 <= 255));
  __CPROVER_assume((sec_r001404_7_2 >= 0) && (sec_r001404_7_2 <= 255));
  __CPROVER_assume((sec_r001404_8_1 >= 0) && (sec_r001404_8_1 <= 255));
  __CPROVER_assume((sec_r001404_8_2 >= 0) && (sec_r001404_8_2 <= 255));
  __CPROVER_assume((sec_r001404_9_1 >= 0) && (sec_r001404_9_1 <= 255));
  __CPROVER_assume((sec_r001404_9_2 >= 0) && (sec_r001404_9_2 <= 255));
  __CPROVER_assume((sec_r001404_10_1 >= 0) && (sec_r001404_10_1 <= 255));
  __CPROVER_assume((sec_r001404_10_2 >= 0) && (sec_r001404_10_2 <= 255));
  __CPROVER_assume((sec_r001404_11_1 >= 0) && (sec_r001404_11_1 <= 255));
  __CPROVER_assume((sec_r001404_11_2 >= 0) && (sec_r001404_11_2 <= 255));
  __CPROVER_assume((sec_r001404_12_1 >= 0) && (sec_r001404_12_1 <= 255));
  __CPROVER_assume((sec_r001404_12_2 >= 0) && (sec_r001404_12_2 <= 255));
  __CPROVER_assume((sec_r001404_13_1 >= 0) && (sec_r001404_13_1 <= 255));
  __CPROVER_assume((sec_r001404_13_2 >= 0) && (sec_r001404_13_2 <= 255));
  __CPROVER_assume((sec_r001404_14_1 >= 0) && (sec_r001404_14_1 <= 255));
  __CPROVER_assume((sec_r001404_14_2 >= 0) && (sec_r001404_14_2 <= 255));
  __CPROVER_assume((sec_r001404_15_1 >= 0) && (sec_r001404_15_1 <= 255));
  __CPROVER_assume((sec_r001404_15_2 >= 0) && (sec_r001404_15_2 <= 255));
  __CPROVER_assume((sec_r001404_16_1 >= 0) && (sec_r001404_16_1 <= 255));
  __CPROVER_assume((sec_r001404_16_2 >= 0) && (sec_r001404_16_2 <= 255));
  struct Transaction_R001404_413_0 st_var_0_1 = {0};
  struct Transaction_R001404_413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001404_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001404_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001404_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001404_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001404_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001404_0_2 + 7) & 15;
  struct FilterState_R001404_413_1 st_var_1_1 = {0};
  struct FilterState_R001404_413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001404_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001404_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001404_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001404_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001404_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001404_0_2 + 9) & 15;
  struct Vector3D_R001404_413_2 st_var_2_1 = {0};
  struct Vector3D_R001404_413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001404_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001404_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001404_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001404_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001404_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001404_0_2 + 11) & 15;
  struct StreamBuffer_R001404_413_3 st_var_3_1 = {0};
  struct StreamBuffer_R001404_413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001404_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001404_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001404_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001404_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001404_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001404_0_2 + 13) & 15;
  union PacketPayload_R001404_413_0 u_var_1;
  union PacketPayload_R001404_413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001404_413_0(sec_r001404_0_1, sec_r001404_1_1, pub_r001404_2_1, pub_r001404_3_1);
  int helper_flow_0_2 = fn_R001404_413_0(sec_r001404_0_2, sec_r001404_1_2, pub_r001404_2_2, pub_r001404_3_2);
  fn_R001404_413_0_2(sec_r001404_0_1, sec_r001404_1_1, pub_r001404_2_1, pub_r001404_3_1, sec_r001404_0_2, sec_r001404_1_2, pub_r001404_2_2, pub_r001404_3_2);
  int helper_flow_1_1 = fn_R001404_413_1(sec_r001404_1_1, pub_r001404_2_1);
  int helper_flow_1_2 = fn_R001404_413_1(sec_r001404_1_2, pub_r001404_2_2);
  fn_R001404_413_1_2(sec_r001404_1_1, pub_r001404_2_1, sec_r001404_1_2, pub_r001404_2_2);
  int helper_flow_2_1 = fn_R001404_413_2(sec_r001404_2_1, sec_r001404_3_1);
  int helper_flow_2_2 = fn_R001404_413_2(sec_r001404_2_2, sec_r001404_3_2);
  fn_R001404_413_2_2(sec_r001404_2_1, sec_r001404_3_1, sec_r001404_2_2, sec_r001404_3_2);
  int helper_flow_3_1 = fn_R001404_413_3(sec_r001404_3_1, pub_r001404_4_1, pub_r001404_5_1);
  int helper_flow_3_2 = fn_R001404_413_3(sec_r001404_3_2, pub_r001404_4_2, pub_r001404_5_2);
  fn_R001404_413_3_2(sec_r001404_3_1, pub_r001404_4_1, pub_r001404_5_1, sec_r001404_3_2, pub_r001404_4_2, pub_r001404_5_2);
  int helper_flow_4_1 = fn_R001404_413_4(sec_r001404_4_1, pub_r001404_5_1, pub_r001404_6_1, pub_r001404_7_1);
  int helper_flow_4_2 = fn_R001404_413_4(sec_r001404_4_2, pub_r001404_5_2, pub_r001404_6_2, pub_r001404_7_2);
  fn_R001404_413_4_2(sec_r001404_4_1, pub_r001404_5_1, pub_r001404_6_1, pub_r001404_7_1, sec_r001404_4_2, pub_r001404_5_2, pub_r001404_6_2, pub_r001404_7_2);
  int helper_flow_5_1 = fn_R001404_413_5(sec_r001404_5_1, pub_r001404_6_1);
  int helper_flow_5_2 = fn_R001404_413_5(sec_r001404_5_2, pub_r001404_6_2);
  fn_R001404_413_5_2(sec_r001404_5_1, pub_r001404_6_1, sec_r001404_5_2, pub_r001404_6_2);
  int helper_flow_6_1 = fn_R001404_413_6(sec_r001404_6_1, sec_r001404_7_1);
  int helper_flow_6_2 = fn_R001404_413_6(sec_r001404_6_2, sec_r001404_7_2);
  fn_R001404_413_6_2(sec_r001404_6_1, sec_r001404_7_1, sec_r001404_6_2, sec_r001404_7_2);
  int helper_flow_7_1 = fn_R001404_413_7(sec_r001404_7_1, pub_r001404_8_1, pub_r001404_9_1, pub_r001404_10_1, pub_r001404_11_1);
  int helper_flow_7_2 = fn_R001404_413_7(sec_r001404_7_2, pub_r001404_8_2, pub_r001404_9_2, pub_r001404_10_2, pub_r001404_11_2);
  fn_R001404_413_7_2(sec_r001404_7_1, pub_r001404_8_1, pub_r001404_9_1, pub_r001404_10_1, pub_r001404_11_1, sec_r001404_7_2, pub_r001404_8_2, pub_r001404_9_2, pub_r001404_10_2, pub_r001404_11_2);
  int stage_v_0_1 = (((sec_r001404_13_1 * 3) + pub_r001404_16_1) + 43) & 127;
  int stage_v_0_2 = (((sec_r001404_13_2 * 3) + pub_r001404_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001404_0_1 * 2) + 19) & 63;
  int stage_v_1_2 = ((pub_r001404_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001404_17_1 * 2) + 28) & 63;
  int stage_v_2_2 = ((pub_r001404_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001404_3_1 * 3) + pub_r001404_0_1) + 40) & 127;
  int stage_v_3_2 = (((sec_r001404_3_2 * 3) + pub_r001404_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((helper_flow_4_1 * 3) + pub_r001404_1_1) + 29) & 127;
  int stage_v_4_2 = (((helper_flow_4_2 * 3) + pub_r001404_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((sec_r001404_14_1 * 3) + pub_r001404_2_1) + 17) & 127;
  int stage_v_5_2 = (((sec_r001404_14_2 * 3) + pub_r001404_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001404_7_1 * 2) + 43) & 63;
  int stage_v_6_2 = ((pub_r001404_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((stage_v_3_1 * 3) + pub_r001404_20_1) + 15) & 127;
  int stage_v_7_2 = (((stage_v_3_2 * 3) + pub_r001404_20_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001404_11_1 * 2) + 40) & 63;
  int stage_v_8_2 = ((pub_r001404_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((sec_r001404_5_1 * 3) + pub_r001404_19_1) + 27) & 127;
  int stage_v_9_2 = (((sec_r001404_5_2 * 3) + pub_r001404_19_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((helper_flow_7_1 * 3) + pub_r001404_8_1) + 19) & 127;
  int stage_v_10_2 = (((helper_flow_7_2 * 3) + pub_r001404_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((helper_flow_7_1 * 3) + pub_r001404_12_1) + 10) & 127;
  int stage_v_11_2 = (((helper_flow_7_2 * 3) + pub_r001404_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = ((pub_r001404_10_1 * 2) + 36) & 63;
  int stage_v_12_2 = ((pub_r001404_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001404_6_1 * 2) + 10) & 63;
  int stage_v_13_2 = ((pub_r001404_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001404_9_1 * 3) + pub_r001404_14_1) + 9) & 127;
  int stage_v_14_2 = (((sec_r001404_9_2 * 3) + pub_r001404_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((stage_v_9_1 * 3) + pub_r001404_17_1) + 23) & 127;
  int stage_v_15_2 = (((stage_v_9_2 * 3) + pub_r001404_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((stage_v_15_1 * 3) + pub_r001404_8_1) + 24) & 127;
  int stage_v_16_2 = (((stage_v_15_2 * 3) + pub_r001404_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((stage_v_0_1 * 3) + pub_r001404_2_1) + 44) & 127;
  int stage_v_17_2 = (((stage_v_0_2 * 3) + pub_r001404_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((sec_r001404_15_1 * 3) + pub_r001404_21_1) + 13) & 127;
  int stage_v_18_2 = (((sec_r001404_15_2 * 3) + pub_r001404_21_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((helper_flow_3_1 * 3) + pub_r001404_6_1) + 24) & 127;
  int stage_v_19_2 = (((helper_flow_3_2 * 3) + pub_r001404_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((helper_flow_5_1 * 3) + pub_r001404_12_1) + 28) & 127;
  int stage_v_20_2 = (((helper_flow_5_2 * 3) + pub_r001404_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = (((stage_v_15_1 * 3) + pub_r001404_6_1) + 38) & 127;
  int stage_v_21_2 = (((stage_v_15_2 * 3) + pub_r001404_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((stage_v_17_1 * 3) + pub_r001404_14_1) + 40) & 127;
  int stage_v_22_2 = (((stage_v_17_2 * 3) + pub_r001404_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001404_17_1 * 2) + 5) & 63;
  int stage_v_23_2 = ((pub_r001404_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((helper_flow_0_1 * 3) + pub_r001404_1_1) + 44) & 127;
  int stage_v_24_2 = (((helper_flow_0_2 * 3) + pub_r001404_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((stage_v_17_1 * 3) + pub_r001404_17_1) + 32) & 127;
  int stage_v_25_2 = (((stage_v_17_2 * 3) + pub_r001404_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001404_15_1 * 3) + pub_r001404_4_1) + 18) & 127;
  int stage_v_26_2 = (((sec_r001404_15_2 * 3) + pub_r001404_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((stage_v_19_1 * 3) + pub_r001404_18_1) + 30) & 127;
  int stage_v_27_2 = (((stage_v_19_2 * 3) + pub_r001404_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = (((sec_r001404_2_1 * 3) + pub_r001404_3_1) + 41) & 127;
  int stage_v_28_2 = (((sec_r001404_2_2 * 3) + pub_r001404_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = ((pub_r001404_11_1 * 2) + 27) & 63;
  int stage_v_29_2 = ((pub_r001404_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001404_13_1 * 3) + pub_r001404_15_1) + 17) & 127;
  int stage_v_30_2 = (((sec_r001404_13_2 * 3) + pub_r001404_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((sec_r001404_15_1 * 3) + pub_r001404_14_1) + 17) & 127;
  int stage_v_31_2 = (((sec_r001404_15_2 * 3) + pub_r001404_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((stage_v_19_1 * 3) + pub_r001404_0_1) + 14) & 127;
  int stage_v_32_2 = (((stage_v_19_2 * 3) + pub_r001404_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001404_12_1 * 3) + pub_r001404_20_1) + 9) & 127;
  int stage_v_33_2 = (((sec_r001404_12_2 * 3) + pub_r001404_20_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001404_19_1 * 2) + 47) & 63;
  int stage_v_34_2 = ((pub_r001404_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001404_18_1 * 2) + 14) & 63;
  int stage_v_35_2 = ((pub_r001404_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((stage_v_15_1 * 3) + pub_r001404_14_1) + 22) & 127;
  int stage_v_36_2 = (((stage_v_15_2 * 3) + pub_r001404_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001404_0_1 * 2) + 31) & 63;
  int stage_v_37_2 = ((pub_r001404_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001404_21_1 * 2) + 19) & 63;
  int stage_v_38_2 = ((pub_r001404_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((sec_r001404_1_1 * 3) + pub_r001404_1_1) + 24) & 127;
  int stage_v_39_2 = (((sec_r001404_1_2 * 3) + pub_r001404_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = (((sec_r001404_7_1 * 3) + pub_r001404_20_1) + 19) & 127;
  int stage_v_40_2 = (((sec_r001404_7_2 * 3) + pub_r001404_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((stage_v_28_1 * 3) + pub_r001404_18_1) + 23) & 127;
  int stage_v_41_2 = (((stage_v_28_2 * 3) + pub_r001404_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((stage_v_15_1 * 3) + pub_r001404_6_1) + 18) & 127;
  int stage_v_42_2 = (((stage_v_15_2 * 3) + pub_r001404_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((stage_v_24_1 * 3) + pub_r001404_3_1) + 26) & 127;
  int stage_v_43_2 = (((stage_v_24_2 * 3) + pub_r001404_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((stage_v_30_1 * 3) + pub_r001404_9_1) + 42) & 127;
  int stage_v_44_2 = (((stage_v_30_2 * 3) + pub_r001404_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001404_13_1 * 2) + 26) & 63;
  int stage_v_45_2 = ((pub_r001404_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_18_1 * 3) + pub_r001404_19_1) + 23) & 127;
  int stage_v_46_2 = (((stage_v_18_2 * 3) + pub_r001404_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((stage_v_36_1 * 3) + pub_r001404_15_1) + 34) & 127;
  int stage_v_47_2 = (((stage_v_36_2 * 3) + pub_r001404_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((stage_v_42_1 * 3) + pub_r001404_19_1) + 27) & 127;
  int stage_v_48_2 = (((stage_v_42_2 * 3) + pub_r001404_19_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((sec_r001404_9_1 * 3) + pub_r001404_19_1) + 13) & 127;
  int stage_v_49_2 = (((sec_r001404_9_2 * 3) + pub_r001404_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((stage_v_18_1 * 3) + pub_r001404_21_1) + 9) & 127;
  int stage_v_50_2 = (((stage_v_18_2 * 3) + pub_r001404_21_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001404_14_1 * 2) + 5) & 63;
  int stage_v_51_2 = ((pub_r001404_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((helper_flow_7_1 * 3) + pub_r001404_10_1) + 34) & 127;
  int stage_v_52_2 = (((helper_flow_7_2 * 3) + pub_r001404_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((stage_v_26_1 * 3) + pub_r001404_11_1) + 43) & 127;
  int stage_v_53_2 = (((stage_v_26_2 * 3) + pub_r001404_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = ((pub_r001404_9_1 * 2) + 13) & 63;
  int stage_v_54_2 = ((pub_r001404_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001404_4_1 * 2) + 46) & 63;
  int stage_v_55_2 = ((pub_r001404_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((helper_flow_2_1 * 3) + pub_r001404_19_1) + 38) & 127;
  int stage_v_56_2 = (((helper_flow_2_2 * 3) + pub_r001404_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001404_3_1 * 2) + 23) & 63;
  int stage_v_57_2 = ((pub_r001404_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((helper_flow_3_1 * 3) + pub_r001404_6_1) + 45) & 127;
  int stage_v_58_2 = (((helper_flow_3_2 * 3) + pub_r001404_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((sec_r001404_14_1 * 3) + pub_r001404_13_1) + 15) & 127;
  int stage_v_59_2 = (((sec_r001404_14_2 * 3) + pub_r001404_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001404_1_1 * 2) + 48) & 63;
  int stage_v_60_2 = ((pub_r001404_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001404_15_1 * 2) + 24) & 63;
  int stage_v_61_2 = ((pub_r001404_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((stage_v_9_1 * 3) + pub_r001404_17_1) + 11) & 127;
  int stage_v_62_2 = (((stage_v_9_2 * 3) + pub_r001404_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((stage_v_36_1 * 3) + pub_r001404_0_1) + 24) & 127;
  int stage_v_63_2 = (((stage_v_36_2 * 3) + pub_r001404_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = ((pub_r001404_9_1 * 2) + 18) & 63;
  int stage_v_64_2 = ((pub_r001404_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001404_9_1 * 2) + 8) & 63;
  int stage_v_65_2 = ((pub_r001404_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_58_1 * 3) + pub_r001404_2_1) + 45) & 127;
  int stage_v_66_2 = (((stage_v_58_2 * 3) + pub_r001404_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((sec_r001404_2_1 * 3) + pub_r001404_14_1) + 21) & 127;
  int stage_v_67_2 = (((sec_r001404_2_2 * 3) + pub_r001404_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001404_19_1 * 2) + 46) & 63;
  int stage_v_68_2 = ((pub_r001404_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001404_15_1 * 2) + 7) & 63;
  int stage_v_69_2 = ((pub_r001404_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001404_7_1 * 2) + 9) & 63;
  int stage_v_70_2 = ((pub_r001404_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((stage_v_48_1 * 3) + pub_r001404_19_1) + 6) & 127;
  int stage_v_71_2 = (((stage_v_48_2 * 3) + pub_r001404_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((sec_r001404_10_1 * 3) + pub_r001404_3_1) + 10) & 127;
  int stage_v_72_2 = (((sec_r001404_10_2 * 3) + pub_r001404_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001404_15_1 * 2) + 31) & 63;
  int stage_v_73_2 = ((pub_r001404_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001404_2_1 * 2) + 37) & 63;
  int stage_v_74_2 = ((pub_r001404_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001404_11_1 * 2) + 11) & 63;
  int stage_v_75_2 = ((pub_r001404_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((sec_r001404_11_1 * 3) + pub_r001404_5_1) + 40) & 127;
  int stage_v_76_2 = (((sec_r001404_11_2 * 3) + pub_r001404_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001404_16_1 * 2) + 25) & 63;
  int stage_v_77_2 = ((pub_r001404_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001404_3_1 * 2) + 6) & 63;
  int stage_v_78_2 = ((pub_r001404_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((sec_r001404_12_1 * 3) + pub_r001404_16_1) + 41) & 127;
  int stage_v_79_2 = (((sec_r001404_12_2 * 3) + pub_r001404_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = (((sec_r001404_9_1 * 3) + pub_r001404_19_1) + 35) & 127;
  int stage_v_80_2 = (((sec_r001404_9_2 * 3) + pub_r001404_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((stage_v_48_1 * 3) + pub_r001404_19_1) + 37) & 127;
  int stage_v_81_2 = (((stage_v_48_2 * 3) + pub_r001404_19_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_7_1 * 3) + pub_r001404_21_1) + 21) & 127;
  int stage_v_82_2 = (((stage_v_7_2 * 3) + pub_r001404_21_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001404_15_1 * 2) + 43) & 63;
  int stage_v_83_2 = ((pub_r001404_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((sec_r001404_3_1 * 3) + pub_r001404_3_1) + 5) & 127;
  int stage_v_84_2 = (((sec_r001404_3_2 * 3) + pub_r001404_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_39_1 * 3) + pub_r001404_19_1) + 19) & 127;
  int stage_v_85_2 = (((stage_v_39_2 * 3) + pub_r001404_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = (((sec_r001404_7_1 * 3) + pub_r001404_6_1) + 6) & 127;
  int stage_v_86_2 = (((sec_r001404_7_2 * 3) + pub_r001404_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001404_10_1 * 2) + 50) & 63;
  int stage_v_87_2 = ((pub_r001404_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001404_3_1 * 2) + 31) & 63;
  int stage_v_88_2 = ((pub_r001404_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_15_1 * 3) + pub_r001404_5_1) + 7) & 127;
  int stage_v_89_2 = (((stage_v_15_2 * 3) + pub_r001404_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((stage_v_11_1 * 3) + pub_r001404_10_1) + 17) & 127;
  int stage_v_90_2 = (((stage_v_11_2 * 3) + pub_r001404_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_52_1 * 3) + pub_r001404_17_1) + 13) & 127;
  int stage_v_91_2 = (((stage_v_52_2 * 3) + pub_r001404_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((helper_flow_5_1 * 3) + pub_r001404_2_1) + 31) & 127;
  int stage_v_92_2 = (((helper_flow_5_2 * 3) + pub_r001404_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001404_18_1 * 2) + 15) & 63;
  int stage_v_93_2 = ((pub_r001404_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001404_21_1 * 2) + 19) & 63;
  int stage_v_94_2 = ((pub_r001404_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_89_1 * 3) + pub_r001404_2_1) + 26) & 127;
  int stage_v_95_2 = (((stage_v_89_2 * 3) + pub_r001404_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001404_18_1 * 2) + 30) & 63;
  int stage_v_96_2 = ((pub_r001404_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001404_5_1 * 2) + 23) & 63;
  int stage_v_97_2 = ((pub_r001404_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_25_1 * 3) + pub_r001404_12_1) + 8) & 127;
  int stage_v_98_2 = (((stage_v_25_2 * 3) + pub_r001404_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_92_1 * 3) + pub_r001404_14_1) + 13) & 127;
  int stage_v_99_2 = (((stage_v_92_2 * 3) + pub_r001404_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((stage_v_3_1 * 3) + pub_r001404_11_1) + 24) & 127;
  int stage_v_100_2 = (((stage_v_3_2 * 3) + pub_r001404_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = ((pub_r001404_0_1 * 2) + 16) & 63;
  int stage_v_101_2 = ((pub_r001404_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((helper_flow_4_1 * 3) + pub_r001404_20_1) + 17) & 127;
  int stage_v_102_2 = (((helper_flow_4_2 * 3) + pub_r001404_20_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001404_8_1 * 2) + 11) & 63;
  int stage_v_103_2 = ((pub_r001404_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_26_1 * 3) + pub_r001404_20_1) + 7) & 127;
  int stage_v_104_2 = (((stage_v_26_2 * 3) + pub_r001404_20_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((stage_v_67_1 * 3) + pub_r001404_7_1) + 8) & 127;
  int stage_v_105_2 = (((stage_v_67_2 * 3) + pub_r001404_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001404_15_1 * 2) + 29) & 63;
  int stage_v_106_2 = ((pub_r001404_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001404_17_1 * 2) + 25) & 63;
  int stage_v_107_2 = ((pub_r001404_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001404_4_1 * 2) + 35) & 63;
  int stage_v_108_2 = ((pub_r001404_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_62_1 * 3) + pub_r001404_14_1) + 15) & 127;
  int stage_v_109_2 = (((stage_v_62_2 * 3) + pub_r001404_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001404_2_1 * 2) + 25) & 63;
  int stage_v_110_2 = ((pub_r001404_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_89_1 * 3) + pub_r001404_3_1) + 35) & 127;
  int stage_v_111_2 = (((stage_v_89_2 * 3) + pub_r001404_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = (((stage_v_82_1 * 3) + pub_r001404_19_1) + 14) & 127;
  int stage_v_112_2 = (((stage_v_82_2 * 3) + pub_r001404_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((stage_v_46_1 * 3) + pub_r001404_10_1) + 6) & 127;
  int stage_v_113_2 = (((stage_v_46_2 * 3) + pub_r001404_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((stage_v_62_1 * 3) + pub_r001404_7_1) + 34) & 127;
  int stage_v_114_2 = (((stage_v_62_2 * 3) + pub_r001404_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001404_6_1 * 2) + 12) & 63;
  int stage_v_115_2 = ((pub_r001404_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001404_9_1 * 2) + 38) & 63;
  int stage_v_116_2 = ((pub_r001404_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001404_11_1 * 2) + 47) & 63;
  int stage_v_117_2 = ((pub_r001404_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((stage_v_62_1 * 3) + pub_r001404_19_1) + 23) & 127;
  int stage_v_118_2 = (((stage_v_62_2 * 3) + pub_r001404_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001404_0_1 * 2) + 41) & 63;
  int stage_v_119_2 = ((pub_r001404_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_111_1 * 3) + pub_r001404_13_1) + 18) & 127;
  int stage_v_120_2 = (((stage_v_111_2 * 3) + pub_r001404_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001404_2_1 * 2) + 50) & 63;
  int stage_v_121_2 = ((pub_r001404_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001404_8_1 * 2) + 24) & 63;
  int stage_v_122_2 = ((pub_r001404_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_4_1 * 3) + pub_r001404_21_1) + 43) & 127;
  int stage_v_123_2 = (((stage_v_4_2 * 3) + pub_r001404_21_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((sec_r001404_1_1 * 3) + pub_r001404_7_1) + 5) & 127;
  int stage_v_124_2 = (((sec_r001404_1_2 * 3) + pub_r001404_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001404_9_1 * 2) + 21) & 63;
  int stage_v_125_2 = ((pub_r001404_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001404_10_1 * 2) + 27) & 63;
  int stage_v_126_2 = ((pub_r001404_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001404_5_1 * 2) + 15) & 63;
  int stage_v_127_2 = ((pub_r001404_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001404_17_1 * 2) + 13) & 63;
  int stage_v_128_2 = ((pub_r001404_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_124_1 * 3) + pub_r001404_9_1) + 34) & 127;
  int stage_v_129_2 = (((stage_v_124_2 * 3) + pub_r001404_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001404_20_1 * 2) + 10) & 63;
  int stage_v_130_2 = ((pub_r001404_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001404_13_1 * 2) + 6) & 63;
  int stage_v_131_2 = ((pub_r001404_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((sec_r001404_16_1 * 3) + pub_r001404_18_1) + 44) & 127;
  int stage_v_132_2 = (((sec_r001404_16_2 * 3) + pub_r001404_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((sec_r001404_16_1 * 3) + pub_r001404_8_1) + 12) & 127;
  int stage_v_133_2 = (((sec_r001404_16_2 * 3) + pub_r001404_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_22_1 * 3) + pub_r001404_7_1) + 26) & 127;
  int stage_v_134_2 = (((stage_v_22_2 * 3) + pub_r001404_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = ((pub_r001404_8_1 * 2) + 18) & 63;
  int stage_v_135_2 = ((pub_r001404_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001404_13_1 * 2) + 37) & 63;
  int stage_v_136_2 = ((pub_r001404_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001404_16_1 * 2) + 32) & 63;
  int stage_v_137_2 = ((pub_r001404_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_102_1 * 3) + pub_r001404_15_1) + 7) & 127;
  int stage_v_138_2 = (((stage_v_102_2 * 3) + pub_r001404_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_18_1 * 3) + pub_r001404_5_1) + 8) & 127;
  int stage_v_139_2 = (((stage_v_18_2 * 3) + pub_r001404_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_40_1 * 3) + pub_r001404_16_1) + 32) & 127;
  int stage_v_140_2 = (((stage_v_40_2 * 3) + pub_r001404_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001404_7_1 * 2) + 14) & 63;
  int stage_v_141_2 = ((pub_r001404_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001404_14_1 * 2) + 36) & 63;
  int stage_v_142_2 = ((pub_r001404_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001404_13_1 * 2) + 49) & 63;
  int stage_v_143_2 = ((pub_r001404_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_118_1 * 3) + pub_r001404_6_1) + 33) & 127;
  int stage_v_144_2 = (((stage_v_118_2 * 3) + pub_r001404_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_53_1 * 3) + pub_r001404_13_1) + 18) & 127;
  int stage_v_145_2 = (((stage_v_53_2 * 3) + pub_r001404_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = (((stage_v_89_1 * 3) + pub_r001404_8_1) + 34) & 127;
  int stage_v_146_2 = (((stage_v_89_2 * 3) + pub_r001404_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = (((sec_r001404_1_1 * 3) + pub_r001404_13_1) + 39) & 127;
  int stage_v_147_2 = (((sec_r001404_1_2 * 3) + pub_r001404_13_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001404_3_1 * 2) + 26) & 63;
  int stage_v_148_2 = ((pub_r001404_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((helper_flow_6_1 * 3) + pub_r001404_21_1) + 9) & 127;
  int stage_v_149_2 = (((helper_flow_6_2 * 3) + pub_r001404_21_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_91_1 * 3) + pub_r001404_1_1) + 34) & 127;
  int stage_v_150_2 = (((stage_v_91_2 * 3) + pub_r001404_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_84_1 * 3) + pub_r001404_21_1) + 3) & 127;
  int stage_v_151_2 = (((stage_v_84_2 * 3) + pub_r001404_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001404_1_1 * 2) + 39) & 63;
  int stage_v_152_2 = ((pub_r001404_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001404_9_1 * 2) + 9) & 63;
  int stage_v_153_2 = ((pub_r001404_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001404_4_1 * 2) + 36) & 63;
  int stage_v_154_2 = ((pub_r001404_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001404_10_1 * 2) + 33) & 63;
  int stage_v_155_2 = ((pub_r001404_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_3_1 * 3) + pub_r001404_13_1) + 31) & 127;
  int stage_v_156_2 = (((stage_v_3_2 * 3) + pub_r001404_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_52_1 * 3) + pub_r001404_10_1) + 10) & 127;
  int stage_v_157_2 = (((stage_v_52_2 * 3) + pub_r001404_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((helper_flow_7_1 * 3) + pub_r001404_21_1) + 4) & 127;
  int stage_v_158_2 = (((helper_flow_7_2 * 3) + pub_r001404_21_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_27_1 * 3) + pub_r001404_16_1) + 23) & 127;
  int stage_v_159_2 = (((stage_v_27_2 * 3) + pub_r001404_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001404_16_1 * 2) + 10) & 63;
  int stage_v_160_2 = ((pub_r001404_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((helper_flow_0_1 * 3) + pub_r001404_5_1) + 28) & 127;
  int stage_v_161_2 = (((helper_flow_0_2 * 3) + pub_r001404_5_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001404_5_1 * 2) + 42) & 63;
  int stage_v_162_2 = ((pub_r001404_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_33_1 * 3) + pub_r001404_3_1) + 14) & 127;
  int stage_v_163_2 = (((stage_v_33_2 * 3) + pub_r001404_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((stage_v_86_1 * 3) + pub_r001404_4_1) + 37) & 127;
  int stage_v_164_2 = (((stage_v_86_2 * 3) + pub_r001404_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_42_1 * 3) + pub_r001404_4_1) + 16) & 127;
  int stage_v_165_2 = (((stage_v_42_2 * 3) + pub_r001404_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((stage_v_5_1 * 3) + pub_r001404_0_1) + 5) & 127;
  int stage_v_166_2 = (((stage_v_5_2 * 3) + pub_r001404_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((sec_r001404_5_1 * 3) + pub_r001404_4_1) + 42) & 127;
  int stage_v_167_2 = (((sec_r001404_5_2 * 3) + pub_r001404_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_43_1 * 3) + pub_r001404_13_1) + 10) & 127;
  int stage_v_168_2 = (((stage_v_43_2 * 3) + pub_r001404_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_32_1 * 3) + pub_r001404_9_1) + 36) & 127;
  int stage_v_169_2 = (((stage_v_32_2 * 3) + pub_r001404_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_114_1 * 3) + pub_r001404_13_1) + 15) & 127;
  int stage_v_170_2 = (((stage_v_114_2 * 3) + pub_r001404_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001404_5_1 * 2) + 15) & 63;
  int stage_v_171_2 = ((pub_r001404_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_3_1 * 3) + pub_r001404_17_1) + 20) & 127;
  int stage_v_172_2 = (((stage_v_3_2 * 3) + pub_r001404_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001404_17_1 * 2) + 44) & 63;
  int stage_v_173_2 = ((pub_r001404_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001404_9_1 * 2) + 11) & 63;
  int stage_v_174_2 = ((pub_r001404_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001404_14_1 * 2) + 12) & 63;
  int stage_v_175_2 = ((pub_r001404_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_32_1 * 3) + pub_r001404_14_1) + 41) & 127;
  int stage_v_176_2 = (((stage_v_32_2 * 3) + pub_r001404_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((stage_v_20_1 * 3) + pub_r001404_17_1) + 17) & 127;
  int stage_v_177_2 = (((stage_v_20_2 * 3) + pub_r001404_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((stage_v_147_1 * 3) + pub_r001404_4_1) + 27) & 127;
  int stage_v_178_2 = (((stage_v_147_2 * 3) + pub_r001404_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((stage_v_147_1 * 3) + pub_r001404_1_1) + 34) & 127;
  int stage_v_179_2 = (((stage_v_147_2 * 3) + pub_r001404_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = ((pub_r001404_16_1 * 2) + 47) & 63;
  int stage_v_180_2 = ((pub_r001404_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_24_1 * 3) + pub_r001404_12_1) + 28) & 127;
  int stage_v_181_2 = (((stage_v_24_2 * 3) + pub_r001404_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_27_1 * 3) + pub_r001404_14_1) + 30) & 127;
  int stage_v_182_2 = (((stage_v_27_2 * 3) + pub_r001404_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001404_19_1 * 2) + 23) & 63;
  int stage_v_183_2 = ((pub_r001404_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001404_17_1 * 2) + 49) & 63;
  int stage_v_184_2 = ((pub_r001404_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_40_1 * 3) + pub_r001404_11_1) + 26) & 127;
  int stage_v_185_2 = (((stage_v_40_2 * 3) + pub_r001404_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_159_1 * 3) + pub_r001404_20_1) + 3) & 127;
  int stage_v_186_2 = (((stage_v_159_2 * 3) + pub_r001404_20_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001404_10_1 * 2) + 28) & 63;
  int stage_v_187_2 = ((pub_r001404_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_168_1 * 3) + pub_r001404_19_1) + 14) & 127;
  int stage_v_188_2 = (((stage_v_168_2 * 3) + pub_r001404_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001404_10_1 * 2) + 47) & 63;
  int stage_v_189_2 = ((pub_r001404_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_150_1 * 3) + pub_r001404_9_1) + 33) & 127;
  int stage_v_190_2 = (((stage_v_150_2 * 3) + pub_r001404_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((sec_r001404_3_1 * 3) + pub_r001404_11_1) + 41) & 127;
  int stage_v_191_2 = (((sec_r001404_3_2 * 3) + pub_r001404_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_81_1 * 3) + pub_r001404_2_1) + 28) & 127;
  int stage_v_192_2 = (((stage_v_81_2 * 3) + pub_r001404_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_84_1 * 3) + pub_r001404_10_1) + 24) & 127;
  int stage_v_193_2 = (((stage_v_84_2 * 3) + pub_r001404_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_151_1 * 3) + pub_r001404_15_1) + 13) & 127;
  int stage_v_194_2 = (((stage_v_151_2 * 3) + pub_r001404_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_109_1 * 3) + pub_r001404_12_1) + 29) & 127;
  int stage_v_195_2 = (((stage_v_109_2 * 3) + pub_r001404_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001404_2_1 * 2) + 6) & 63;
  int stage_v_196_2 = ((pub_r001404_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_27_1 * 3) + pub_r001404_18_1) + 11) & 127;
  int stage_v_197_2 = (((stage_v_27_2 * 3) + pub_r001404_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = ((pub_r001404_16_1 * 2) + 5) & 63;
  int stage_v_198_2 = ((pub_r001404_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001404_5_1 * 2) + 19) & 63;
  int stage_v_199_2 = ((pub_r001404_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((sec_r001404_9_1 * 3) + pub_r001404_13_1) + 34) & 127;
  int stage_v_200_2 = (((sec_r001404_9_2 * 3) + pub_r001404_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001404_11_1 * 2) + 10) & 63;
  int stage_v_201_2 = ((pub_r001404_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_72_1 * 3) + pub_r001404_17_1) + 8) & 127;
  int stage_v_202_2 = (((stage_v_72_2 * 3) + pub_r001404_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001404_11_1 * 2) + 28) & 63;
  int stage_v_203_2 = ((pub_r001404_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001404_11_1 * 2) + 9) & 63;
  int stage_v_204_2 = ((pub_r001404_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_52_1 * 3) + pub_r001404_5_1) + 24) & 127;
  int stage_v_205_2 = (((stage_v_52_2 * 3) + pub_r001404_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001404_18_1 * 2) + 47) & 63;
  int stage_v_206_2 = ((pub_r001404_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((helper_flow_1_1 * 3) + pub_r001404_21_1) + 16) & 127;
  int stage_v_207_2 = (((helper_flow_1_2 * 3) + pub_r001404_21_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001404_18_1 * 2) + 5) & 63;
  int stage_v_208_2 = ((pub_r001404_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_44_1 * 3) + pub_r001404_6_1) + 29) & 127;
  int stage_v_209_2 = (((stage_v_44_2 * 3) + pub_r001404_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_149_1 * 3) + pub_r001404_7_1) + 40) & 127;
  int stage_v_210_2 = (((stage_v_149_2 * 3) + pub_r001404_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_44_1 * 3) + pub_r001404_21_1) + 39) & 127;
  int stage_v_211_2 = (((stage_v_44_2 * 3) + pub_r001404_21_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001404_16_1 * 2) + 20) & 63;
  int stage_v_212_2 = ((pub_r001404_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001404_5_1 * 2) + 7) & 63;
  int stage_v_213_2 = ((pub_r001404_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001404_11_1 * 2) + 48) & 63;
  int stage_v_214_2 = ((pub_r001404_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((sec_r001404_7_1 * 3) + pub_r001404_0_1) + 23) & 127;
  int stage_v_215_2 = (((sec_r001404_7_2 * 3) + pub_r001404_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_163_1 * 3) + pub_r001404_6_1) + 25) & 127;
  int stage_v_216_2 = (((stage_v_163_2 * 3) + pub_r001404_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = (((sec_r001404_11_1 * 3) + pub_r001404_20_1) + 14) & 127;
  int stage_v_217_2 = (((sec_r001404_11_2 * 3) + pub_r001404_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001404_14_1 * 2) + 21) & 63;
  int stage_v_218_2 = ((pub_r001404_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001404_6_1 * 2) + 43) & 63;
  int stage_v_219_2 = ((pub_r001404_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_17_1 * 3) + pub_r001404_11_1) + 41) & 127;
  int stage_v_220_2 = (((stage_v_17_2 * 3) + pub_r001404_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_32_1 * 3) + pub_r001404_5_1) + 21) & 127;
  int stage_v_221_2 = (((stage_v_32_2 * 3) + pub_r001404_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = ((pub_r001404_12_1 * 2) + 11) & 63;
  int stage_v_222_2 = ((pub_r001404_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001404_8_1 * 2) + 22) & 63;
  int stage_v_223_2 = ((pub_r001404_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001404_14_1 * 2) + 20) & 63;
  int stage_v_224_2 = ((pub_r001404_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001404_6_1 * 2) + 16) & 63;
  int stage_v_225_2 = ((pub_r001404_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_7_1 * 3) + pub_r001404_9_1) + 37) & 127;
  int stage_v_226_2 = (((stage_v_7_2 * 3) + pub_r001404_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_149_1 * 3) + pub_r001404_15_1) + 10) & 127;
  int stage_v_227_2 = (((stage_v_149_2 * 3) + pub_r001404_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001404_8_1 * 2) + 16) & 63;
  int stage_v_228_2 = ((pub_r001404_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001404_13_1 * 2) + 13) & 63;
  int stage_v_229_2 = ((pub_r001404_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((stage_v_132_1 * 3) + pub_r001404_17_1) + 10) & 127;
  int stage_v_230_2 = (((stage_v_132_2 * 3) + pub_r001404_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001404_9_1 * 2) + 32) & 63;
  int stage_v_231_2 = ((pub_r001404_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_102_1 * 3) + pub_r001404_5_1) + 7) & 127;
  int stage_v_232_2 = (((stage_v_102_2 * 3) + pub_r001404_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_17_1 * 3) + pub_r001404_16_1) + 45) & 127;
  int stage_v_233_2 = (((stage_v_17_2 * 3) + pub_r001404_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_150_1 * 3) + pub_r001404_4_1) + 36) & 127;
  int stage_v_234_2 = (((stage_v_150_2 * 3) + pub_r001404_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((sec_r001404_4_1 * 3) + pub_r001404_9_1) + 34) & 127;
  int stage_v_235_2 = (((sec_r001404_4_2 * 3) + pub_r001404_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_85_1 * 3) + pub_r001404_1_1) + 42) & 127;
  int stage_v_236_2 = (((stage_v_85_2 * 3) + pub_r001404_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001404_17_1 * 2) + 19) & 63;
  int stage_v_237_2 = ((pub_r001404_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001404_9_1 * 2) + 11) & 63;
  int stage_v_238_2 = ((pub_r001404_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001404_19_1 * 2) + 26) & 63;
  int stage_v_239_2 = ((pub_r001404_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001404_17_1 * 2) + 12) & 63;
  int stage_v_240_2 = ((pub_r001404_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((helper_flow_4_1 * 3) + pub_r001404_8_1) + 4) & 127;
  int stage_v_241_2 = (((helper_flow_4_2 * 3) + pub_r001404_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((sec_r001404_12_1 * 3) + pub_r001404_8_1) + 16) & 127;
  int stage_v_242_2 = (((sec_r001404_12_2 * 3) + pub_r001404_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001404_0_1 * 2) + 27) & 63;
  int stage_v_243_2 = ((pub_r001404_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001404_11_1 * 2) + 32) & 63;
  int stage_v_244_2 = ((pub_r001404_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((stage_v_24_1 * 3) + pub_r001404_10_1) + 42) & 127;
  int stage_v_245_2 = (((stage_v_24_2 * 3) + pub_r001404_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001404_19_1 * 2) + 5) & 63;
  int stage_v_246_2 = ((pub_r001404_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((stage_v_84_1 * 3) + pub_r001404_2_1) + 36) & 127;
  int stage_v_247_2 = (((stage_v_84_2 * 3) + pub_r001404_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001404_7_1 * 2) + 46) & 63;
  int stage_v_248_2 = ((pub_r001404_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_18_1 * 3) + pub_r001404_20_1) + 13) & 127;
  int stage_v_249_2 = (((stage_v_18_2 * 3) + pub_r001404_20_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_194_1 * 3) + pub_r001404_11_1) + 26) & 127;
  int stage_v_250_2 = (((stage_v_194_2 * 3) + pub_r001404_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = ((pub_r001404_4_1 * 2) + 5) & 63;
  int stage_v_251_2 = ((pub_r001404_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((stage_v_89_1 * 3) + pub_r001404_10_1) + 21) & 127;
  int stage_v_252_2 = (((stage_v_89_2 * 3) + pub_r001404_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001404_5_1 * 2) + 6) & 63;
  int stage_v_253_2 = ((pub_r001404_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_188_1 * 3) + pub_r001404_9_1) + 41) & 127;
  int stage_v_254_2 = (((stage_v_188_2 * 3) + pub_r001404_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((sec_r001404_7_1 * 3) + pub_r001404_16_1) + 31) & 127;
  int stage_v_255_2 = (((sec_r001404_7_2 * 3) + pub_r001404_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((helper_flow_4_1 * 3) + pub_r001404_6_1) + 16) & 127;
  int stage_v_256_2 = (((helper_flow_4_2 * 3) + pub_r001404_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001404_18_1 * 2) + 23) & 63;
  int stage_v_257_2 = ((pub_r001404_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001404_11_1 * 2) + 16) & 63;
  int stage_v_258_2 = ((pub_r001404_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001404_3_1 * 2) + 40) & 63;
  int stage_v_259_2 = ((pub_r001404_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001404_9_1 * 2) + 7) & 63;
  int stage_v_260_2 = ((pub_r001404_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_200_1 * 3) + pub_r001404_4_1) + 18) & 127;
  int stage_v_261_2 = (((stage_v_200_2 * 3) + pub_r001404_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_46_1 * 3) + pub_r001404_20_1) + 19) & 127;
  int stage_v_262_2 = (((stage_v_46_2 * 3) + pub_r001404_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((stage_v_176_1 * 3) + pub_r001404_1_1) + 12) & 127;
  int stage_v_263_2 = (((stage_v_176_2 * 3) + pub_r001404_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001404_5_1 * 2) + 33) & 63;
  int stage_v_264_2 = ((pub_r001404_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_95_1 * 3) + pub_r001404_2_1) + 43) & 127;
  int stage_v_265_2 = (((stage_v_95_2 * 3) + pub_r001404_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001404_19_1 * 2) + 31) & 63;
  int stage_v_266_2 = ((pub_r001404_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((stage_v_158_1 * 3) + pub_r001404_4_1) + 9) & 127;
  int stage_v_267_2 = (((stage_v_158_2 * 3) + pub_r001404_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001404_7_1 * 2) + 38) & 63;
  int stage_v_268_2 = ((pub_r001404_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001404_15_1 * 2) + 12) & 63;
  int stage_v_269_2 = ((pub_r001404_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001404_12_1 * 2) + 23) & 63;
  int stage_v_270_2 = ((pub_r001404_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001404_5_1 * 2) + 30) & 63;
  int stage_v_271_2 = ((pub_r001404_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_90_1 * 3) + pub_r001404_1_1) + 32) & 127;
  int stage_v_272_2 = (((stage_v_90_2 * 3) + pub_r001404_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001404_2_1 * 2) + 10) & 63;
  int stage_v_273_2 = ((pub_r001404_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001404_15_1 * 2) + 50) & 63;
  int stage_v_274_2 = ((pub_r001404_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001404_9_1 * 2) + 8) & 63;
  int stage_v_275_2 = ((pub_r001404_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_18_1 * 3) + pub_r001404_17_1) + 29) & 127;
  int stage_v_276_2 = (((stage_v_18_2 * 3) + pub_r001404_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001404_1_1 * 2) + 37) & 63;
  int stage_v_277_2 = ((pub_r001404_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001404_2_1 * 2) + 35) & 63;
  int stage_v_278_2 = ((pub_r001404_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = (((stage_v_205_1 * 3) + pub_r001404_7_1) + 20) & 127;
  int stage_v_279_2 = (((stage_v_205_2 * 3) + pub_r001404_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = ((pub_r001404_13_1 * 2) + 30) & 63;
  int stage_v_280_2 = ((pub_r001404_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001404_21_1 * 2) + 10) & 63;
  int stage_v_281_2 = ((pub_r001404_21_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001404_7_1 * 2) + 14) & 63;
  int stage_v_282_2 = ((pub_r001404_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((stage_v_178_1 * 3) + pub_r001404_9_1) + 13) & 127;
  int stage_v_283_2 = (((stage_v_178_2 * 3) + pub_r001404_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((stage_v_267_1 * 3) + pub_r001404_21_1) + 35) & 127;
  int stage_v_284_2 = (((stage_v_267_2 * 3) + pub_r001404_21_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_193_1 * 3) + pub_r001404_3_1) + 18) & 127;
  int stage_v_285_2 = (((stage_v_193_2 * 3) + pub_r001404_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001404_11_1 * 2) + 11) & 63;
  int stage_v_286_2 = ((pub_r001404_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001404_2_1 * 2) + 49) & 63;
  int stage_v_287_2 = ((pub_r001404_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001404_0_1 * 2) + 45) & 63;
  int stage_v_288_2 = ((pub_r001404_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_247_1 * 3) + pub_r001404_1_1) + 15) & 127;
  int stage_v_289_2 = (((stage_v_247_2 * 3) + pub_r001404_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_102_1 * 3) + pub_r001404_14_1) + 17) & 127;
  int stage_v_290_2 = (((stage_v_102_2 * 3) + pub_r001404_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001404_5_1 * 2) + 46) & 63;
  int stage_v_291_2 = ((pub_r001404_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_276_1 * 3) + pub_r001404_5_1) + 42) & 127;
  int stage_v_292_2 = (((stage_v_276_2 * 3) + pub_r001404_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_49_1 * 3) + pub_r001404_16_1) + 38) & 127;
  int stage_v_293_2 = (((stage_v_49_2 * 3) + pub_r001404_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = (((stage_v_190_1 * 3) + pub_r001404_8_1) + 20) & 127;
  int stage_v_294_2 = (((stage_v_190_2 * 3) + pub_r001404_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = ((pub_r001404_4_1 * 2) + 35) & 63;
  int stage_v_295_2 = ((pub_r001404_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001404_12_1 * 2) + 25) & 63;
  int stage_v_296_2 = ((pub_r001404_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001404_19_1 * 2) + 24) & 63;
  int stage_v_297_2 = ((pub_r001404_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_30_1 * 3) + pub_r001404_0_1) + 13) & 127;
  int stage_v_298_2 = (((stage_v_30_2 * 3) + pub_r001404_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001404_6_1 * 2) + 42) & 63;
  int stage_v_299_2 = ((pub_r001404_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_90_1 * 3) + pub_r001404_15_1) + 24) & 127;
  int stage_v_300_2 = (((stage_v_90_2 * 3) + pub_r001404_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_105_1 * 3) + pub_r001404_14_1) + 41) & 127;
  int stage_v_301_2 = (((stage_v_105_2 * 3) + pub_r001404_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = (((stage_v_85_1 * 3) + pub_r001404_4_1) + 5) & 127;
  int stage_v_302_2 = (((stage_v_85_2 * 3) + pub_r001404_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((stage_v_3_1 * 3) + pub_r001404_16_1) + 43) & 127;
  int stage_v_303_2 = (((stage_v_3_2 * 3) + pub_r001404_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001404_7_1 * 2) + 21) & 63;
  int stage_v_304_2 = ((pub_r001404_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001404_19_1 * 2) + 7) & 63;
  int stage_v_305_2 = ((pub_r001404_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_132_1 * 3) + pub_r001404_0_1) + 8) & 127;
  int stage_v_306_2 = (((stage_v_132_2 * 3) + pub_r001404_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_20_1 * 3) + pub_r001404_0_1) + 32) & 127;
  int stage_v_307_2 = (((stage_v_20_2 * 3) + pub_r001404_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = (((stage_v_42_1 * 3) + pub_r001404_1_1) + 19) & 127;
  int stage_v_308_2 = (((stage_v_42_2 * 3) + pub_r001404_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001404_13_1 * 2) + 30) & 63;
  int stage_v_309_2 = ((pub_r001404_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_9_1 * 3) + pub_r001404_8_1) + 42) & 127;
  int stage_v_310_2 = (((stage_v_9_2 * 3) + pub_r001404_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001404_4_1 * 2) + 44) & 63;
  int stage_v_311_2 = ((pub_r001404_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001404_15_1 * 2) + 18) & 63;
  int stage_v_312_2 = ((pub_r001404_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_132_1 * 3) + pub_r001404_8_1) + 38) & 127;
  int stage_v_313_2 = (((stage_v_132_2 * 3) + pub_r001404_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001404_3_1 * 2) + 17) & 63;
  int stage_v_314_2 = ((pub_r001404_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((stage_v_261_1 * 3) + pub_r001404_12_1) + 24) & 127;
  int stage_v_315_2 = (((stage_v_261_2 * 3) + pub_r001404_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_195_1 * 3) + pub_r001404_17_1) + 8) & 127;
  int stage_v_316_2 = (((stage_v_195_2 * 3) + pub_r001404_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_307_1 * 3) + pub_r001404_10_1) + 30) & 127;
  int stage_v_317_2 = (((stage_v_307_2 * 3) + pub_r001404_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_43_1 * 3) + pub_r001404_9_1) + 16) & 127;
  int stage_v_318_2 = (((stage_v_43_2 * 3) + pub_r001404_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001404_17_1 * 2) + 21) & 63;
  int stage_v_319_2 = ((pub_r001404_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_265_1 * 3) + pub_r001404_12_1) + 36) & 127;
  int stage_v_320_2 = (((stage_v_265_2 * 3) + pub_r001404_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001404_10_1 * 2) + 7) & 63;
  int stage_v_321_2 = ((pub_r001404_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = (((stage_v_36_1 * 3) + pub_r001404_13_1) + 28) & 127;
  int stage_v_322_2 = (((stage_v_36_2 * 3) + pub_r001404_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001404_10_1 * 2) + 44) & 63;
  int stage_v_323_2 = ((pub_r001404_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_159_1 * 3) + pub_r001404_19_1) + 4) & 127;
  int stage_v_324_2 = (((stage_v_159_2 * 3) + pub_r001404_19_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_283_1 * 3) + pub_r001404_4_1) + 27) & 127;
  int stage_v_325_2 = (((stage_v_283_2 * 3) + pub_r001404_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_294_1 * 3) + pub_r001404_2_1) + 39) & 127;
  int stage_v_326_2 = (((stage_v_294_2 * 3) + pub_r001404_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_102_1 * 3) + pub_r001404_21_1) + 40) & 127;
  int stage_v_327_2 = (((stage_v_102_2 * 3) + pub_r001404_21_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((stage_v_145_1 * 3) + pub_r001404_10_1) + 39) & 127;
  int stage_v_328_2 = (((stage_v_145_2 * 3) + pub_r001404_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_111_1 * 3) + pub_r001404_15_1) + 30) & 127;
  int stage_v_329_2 = (((stage_v_111_2 * 3) + pub_r001404_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_41_1 * 3) + pub_r001404_2_1) + 38) & 127;
  int stage_v_330_2 = (((stage_v_41_2 * 3) + pub_r001404_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = (((stage_v_91_1 * 3) + pub_r001404_17_1) + 19) & 127;
  int stage_v_331_2 = (((stage_v_91_2 * 3) + pub_r001404_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((sec_r001404_9_1 * 3) + pub_r001404_4_1) + 8) & 127;
  int stage_v_332_2 = (((sec_r001404_9_2 * 3) + pub_r001404_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001404_1_1 * 2) + 39) & 63;
  int stage_v_333_2 = ((pub_r001404_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((sec_r001404_2_1 * 3) + pub_r001404_21_1) + 30) & 127;
  int stage_v_334_2 = (((sec_r001404_2_2 * 3) + pub_r001404_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001404_5_1 * 2) + 27) & 63;
  int stage_v_335_2 = ((pub_r001404_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001404_8_1 * 2) + 35) & 63;
  int stage_v_336_2 = ((pub_r001404_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001404_12_1 * 2) + 13) & 63;
  int stage_v_337_2 = ((pub_r001404_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((stage_v_124_1 * 3) + pub_r001404_11_1) + 44) & 127;
  int stage_v_338_2 = (((stage_v_124_2 * 3) + pub_r001404_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001404_12_1 * 2) + 16) & 63;
  int stage_v_339_2 = ((pub_r001404_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001404_3_1 * 2) + 24) & 63;
  int stage_v_340_2 = ((pub_r001404_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_56_1 * 3) + pub_r001404_20_1) + 26) & 127;
  int stage_v_341_2 = (((stage_v_56_2 * 3) + pub_r001404_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_195_1 * 3) + pub_r001404_8_1) + 40) & 127;
  int stage_v_342_2 = (((stage_v_195_2 * 3) + pub_r001404_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001404_19_1 * 2) + 23) & 63;
  int stage_v_343_2 = ((pub_r001404_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((stage_v_169_1 * 3) + pub_r001404_3_1) + 42) & 127;
  int stage_v_344_2 = (((stage_v_169_2 * 3) + pub_r001404_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = (((stage_v_326_1 * 3) + pub_r001404_13_1) + 11) & 127;
  int stage_v_345_2 = (((stage_v_326_2 * 3) + pub_r001404_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001404_0_1 * 2) + 28) & 63;
  int stage_v_346_2 = ((pub_r001404_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((stage_v_62_1 * 3) + pub_r001404_11_1) + 5) & 127;
  int stage_v_347_2 = (((stage_v_62_2 * 3) + pub_r001404_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_332_1 * 3) + pub_r001404_19_1) + 32) & 127;
  int stage_v_348_2 = (((stage_v_332_2 * 3) + pub_r001404_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001404_12_1 * 2) + 32) & 63;
  int stage_v_349_2 = ((pub_r001404_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((sec_r001404_0_1 * 3) + pub_r001404_0_1) + 34) & 127;
  int stage_v_350_2 = (((sec_r001404_0_2 * 3) + pub_r001404_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001404_15_1 * 2) + 24) & 63;
  int stage_v_351_2 = ((pub_r001404_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((stage_v_3_1 * 3) + pub_r001404_0_1) + 4) & 127;
  int stage_v_352_2 = (((stage_v_3_2 * 3) + pub_r001404_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001404_4_1 * 2) + 40) & 63;
  int stage_v_353_2 = ((pub_r001404_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_112_1 * 3) + pub_r001404_21_1) + 45) & 127;
  int stage_v_354_2 = (((stage_v_112_2 * 3) + pub_r001404_21_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_163_1 * 3) + pub_r001404_6_1) + 31) & 127;
  int stage_v_355_2 = (((stage_v_163_2 * 3) + pub_r001404_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_71_1 * 3) + pub_r001404_4_1) + 4) & 127;
  int stage_v_356_2 = (((stage_v_71_2 * 3) + pub_r001404_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001404_8_1 * 2) + 48) & 63;
  int stage_v_357_2 = ((pub_r001404_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001404_17_1 * 2) + 36) & 63;
  int stage_v_358_2 = ((pub_r001404_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_226_1 * 3) + pub_r001404_20_1) + 45) & 127;
  int stage_v_359_2 = (((stage_v_226_2 * 3) + pub_r001404_20_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_9_1 * 3) + pub_r001404_11_1) + 6) & 127;
  int stage_v_360_2 = (((stage_v_9_2 * 3) + pub_r001404_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_156_1 * 3) + pub_r001404_0_1) + 14) & 127;
  int stage_v_361_2 = (((stage_v_156_2 * 3) + pub_r001404_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001404_5_1 * 2) + 26) & 63;
  int stage_v_362_2 = ((pub_r001404_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_44_1 * 3) + pub_r001404_11_1) + 21) & 127;
  int stage_v_363_2 = (((stage_v_44_2 * 3) + pub_r001404_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = ((pub_r001404_9_1 * 2) + 7) & 63;
  int stage_v_364_2 = ((pub_r001404_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = (((stage_v_215_1 * 3) + pub_r001404_17_1) + 32) & 127;
  int stage_v_365_2 = (((stage_v_215_2 * 3) + pub_r001404_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_262_1 * 3) + pub_r001404_11_1) + 23) & 127;
  int stage_v_366_2 = (((stage_v_262_2 * 3) + pub_r001404_11_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_139_1 * 3) + pub_r001404_13_1) + 45) & 127;
  int stage_v_367_2 = (((stage_v_139_2 * 3) + pub_r001404_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_167_1 * 3) + pub_r001404_19_1) + 6) & 127;
  int stage_v_368_2 = (((stage_v_167_2 * 3) + pub_r001404_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_145_1 * 3) + pub_r001404_16_1) + 36) & 127;
  int stage_v_369_2 = (((stage_v_145_2 * 3) + pub_r001404_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((stage_v_92_1 * 3) + pub_r001404_19_1) + 6) & 127;
  int stage_v_370_2 = (((stage_v_92_2 * 3) + pub_r001404_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_129_1 * 3) + pub_r001404_10_1) + 43) & 127;
  int stage_v_371_2 = (((stage_v_129_2 * 3) + pub_r001404_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001404_2_1 * 2) + 10) & 63;
  int stage_v_372_2 = ((pub_r001404_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_254_1 * 3) + pub_r001404_0_1) + 13) & 127;
  int stage_v_373_2 = (((stage_v_254_2 * 3) + pub_r001404_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001404_10_1 * 2) + 50) & 63;
  int stage_v_374_2 = ((pub_r001404_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001404_2_1 * 2) + 25) & 63;
  int stage_v_375_2 = ((pub_r001404_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001404_9_1 * 2) + 29) & 63;
  int stage_v_376_2 = ((pub_r001404_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001404_18_1 * 2) + 34) & 63;
  int stage_v_377_2 = ((pub_r001404_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001404_12_1 * 2) + 45) & 63;
  int stage_v_378_2 = ((pub_r001404_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((stage_v_355_1 * 3) + pub_r001404_3_1) + 28) & 127;
  int stage_v_379_2 = (((stage_v_355_2 * 3) + pub_r001404_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_322_1 * 3) + pub_r001404_20_1) + 40) & 127;
  int stage_v_380_2 = (((stage_v_322_2 * 3) + pub_r001404_20_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001404_2_1 * 2) + 7) & 63;
  int stage_v_381_2 = ((pub_r001404_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((sec_r001404_14_1 * 3) + pub_r001404_14_1) + 9) & 127;
  int stage_v_382_2 = (((sec_r001404_14_2 * 3) + pub_r001404_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_241_1 * 3) + pub_r001404_1_1) + 37) & 127;
  int stage_v_383_2 = (((stage_v_241_2 * 3) + pub_r001404_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((sec_r001404_3_1 * 3) + pub_r001404_14_1) + 28) & 127;
  int stage_v_384_2 = (((sec_r001404_3_2 * 3) + pub_r001404_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_31_1 * 3) + pub_r001404_16_1) + 28) & 127;
  int stage_v_385_2 = (((stage_v_31_2 * 3) + pub_r001404_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = (((stage_v_181_1 * 3) + pub_r001404_0_1) + 36) & 127;
  int stage_v_386_2 = (((stage_v_181_2 * 3) + pub_r001404_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((stage_v_138_1 * 3) + pub_r001404_6_1) + 8) & 127;
  int stage_v_387_2 = (((stage_v_138_2 * 3) + pub_r001404_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((stage_v_249_1 * 3) + pub_r001404_11_1) + 42) & 127;
  int stage_v_388_2 = (((stage_v_249_2 * 3) + pub_r001404_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = ((pub_r001404_6_1 * 2) + 10) & 63;
  int stage_v_389_2 = ((pub_r001404_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001404_15_1 * 2) + 39) & 63;
  int stage_v_390_2 = ((pub_r001404_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_85_1 * 3) + pub_r001404_4_1) + 10) & 127;
  int stage_v_391_2 = (((stage_v_85_2 * 3) + pub_r001404_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_182_1 * 3) + pub_r001404_12_1) + 12) & 127;
  int stage_v_392_2 = (((stage_v_182_2 * 3) + pub_r001404_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_207_1 * 3) + pub_r001404_2_1) + 24) & 127;
  int stage_v_393_2 = (((stage_v_207_2 * 3) + pub_r001404_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = (((stage_v_385_1 * 3) + pub_r001404_9_1) + 16) & 127;
  int stage_v_394_2 = (((stage_v_385_2 * 3) + pub_r001404_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001404_16_1 * 2) + 38) & 63;
  int stage_v_395_2 = ((pub_r001404_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_33_1 * 3) + pub_r001404_17_1) + 33) & 127;
  int stage_v_396_2 = (((stage_v_33_2 * 3) + pub_r001404_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_325_1 * 3) + pub_r001404_7_1) + 8) & 127;
  int stage_v_397_2 = (((stage_v_325_2 * 3) + pub_r001404_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = ((pub_r001404_17_1 * 2) + 28) & 63;
  int stage_v_398_2 = ((pub_r001404_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001404_10_1 != sec_r001404_10_2);
  __CPROVER_assume(pub_r001404_5_1 == pub_r001404_5_2);
  __CPROVER_assume(pub_r001404_14_1 == pub_r001404_14_2);
  __CPROVER_assume(pub_r001404_21_1 == pub_r001404_21_2);
  __CPROVER_assume(pub_r001404_8_1 == pub_r001404_8_2);
  __CPROVER_assume(sec_r001404_8_1 != sec_r001404_8_2);
  __CPROVER_assume(pub_r001404_2_1 == pub_r001404_2_2);
  __CPROVER_assume(sec_r001404_15_1 != sec_r001404_15_2);
  __CPROVER_assume(sec_r001404_9_1 != sec_r001404_9_2);
  __CPROVER_assume(sec_r001404_0_1 != sec_r001404_0_2);
  __CPROVER_assume(pub_r001404_20_1 == pub_r001404_20_2);
  __CPROVER_assume(pub_r001404_3_1 == pub_r001404_3_2);
  __CPROVER_assume(sec_r001404_6_1 != sec_r001404_6_2);
  __CPROVER_assume(pub_r001404_1_1 == pub_r001404_1_2);
  __CPROVER_assume(pub_r001404_7_1 == pub_r001404_7_2);
  __CPROVER_assume(pub_r001404_15_1 == pub_r001404_15_2);
  __CPROVER_assume(pub_r001404_6_1 == pub_r001404_6_2);
  __CPROVER_assume(sec_r001404_2_1 != sec_r001404_2_2);
  __CPROVER_assume(sec_r001404_14_1 != sec_r001404_14_2);
  __CPROVER_assume(pub_r001404_11_1 == pub_r001404_11_2);
  __CPROVER_assume(sec_r001404_7_1 != sec_r001404_7_2);
  __CPROVER_assume(sec_r001404_4_1 != sec_r001404_4_2);
  __CPROVER_assume(sec_r001404_16_1 != sec_r001404_16_2);
  __CPROVER_assume(pub_r001404_10_1 == pub_r001404_10_2);
  __CPROVER_assume(pub_r001404_18_1 == pub_r001404_18_2);
  __CPROVER_assume(sec_r001404_5_1 != sec_r001404_5_2);
  __CPROVER_assume(pub_r001404_4_1 == pub_r001404_4_2);
  __CPROVER_assume(sec_r001404_11_1 != sec_r001404_11_2);
  __CPROVER_assume(pub_r001404_9_1 == pub_r001404_9_2);
  __CPROVER_assume(pub_r001404_16_1 == pub_r001404_16_2);
  __CPROVER_assume(sec_r001404_13_1 != sec_r001404_13_2);
  __CPROVER_assume(sec_r001404_12_1 != sec_r001404_12_2);
  __CPROVER_assume(pub_r001404_0_1 == pub_r001404_0_2);
  __CPROVER_assume(pub_r001404_12_1 == pub_r001404_12_2);
  __CPROVER_assume(pub_r001404_19_1 == pub_r001404_19_2);
  __CPROVER_assume(pub_r001404_13_1 == pub_r001404_13_2);
  __CPROVER_assume(sec_r001404_3_1 != sec_r001404_3_2);
  __CPROVER_assume(pub_r001404_17_1 == pub_r001404_17_2);
  __CPROVER_assume(sec_r001404_1_1 != sec_r001404_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.state == st_var_3_2.state);
  assert(st_var_3_1.watermark == st_var_3_2.watermark);
  assert(st_var_3_1.tail == st_var_3_2.tail);
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
}


