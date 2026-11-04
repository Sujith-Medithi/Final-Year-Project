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
struct CipherContext_R000267_6713_0
{
  short round_key;
  unsigned char tag;
  int iv;
  int buffer[3];
};
struct DeviceConfig_R000267_6713_1
{
  int port;
  int baud_rate;
  short timeout;
  int stop_bits;
  int parity;
  int id;
  int buffer[3];
};
struct MatrixBlock_R000267_6713_2
{
  short stride;
  short determinant;
  int density;
  int dim;
  int trace;
  unsigned char scale;
  int buffer[3];
};
struct FilterState_R000267_6713_3
{
  int damping;
  short mode;
  unsigned char prev_out;
  int gain_db;
  int cutoff;
  int buffer[3];
};
union TelemetryField_R000267_6713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000267_6713_1
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
void fn_R000267_6713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st_1 = {0};
  struct FilterState_R000267_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_32_1 = local_arr_1[aux_1 % 3];
  int quantum_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_32_2 * 2)) & 127;
  int phase_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_88_1) & 63;
  aux_2 = (aux_2 + phase_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_32_1 == quantum_32_2);
  assert(phase_88_1 == phase_88_2);
}

int fn_R000267_6713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int quantum_32 = local_arr[aux % 3];
  acc = (acc + (quantum_32 * 2)) & 127;
  int phase_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000267_6713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st_1 = {0};
  struct FilterState_R000267_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quantum_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_94_1) & 63;
  aux_2 = (aux_2 + quantum_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_16_1 > 45)
  {
    acc_1 = ((acc_1 + (pivot_16_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_16_2 > 45)
  {
    acc_2 = ((acc_2 + (pivot_16_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_12_1 = 0;
  int segment_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_12_1 = ((segment_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_12_2 = ((segment_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_12_1) & 127;
    acc_2 = (acc_2 + segment_12_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_94_1 == quantum_94_2);
  assert(pivot_16_1 == pivot_16_2);
  assert(segment_12_1 == segment_12_2);
}

int fn_R000267_6713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quantum_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_94) & 63;
  acc ^= aux;
  int pivot_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_16 > 45)
  {
    acc = ((acc + (pivot_16 * 2)) + 5) & 127;
    aux ^= pivot_16 & 15;
  }
  else
  {
    acc = ((acc - pivot_16) + 11) & 127;
    aux += 3;
  }
  int segment_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_12 = ((segment_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_12) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000267_6713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st_1 = {0};
  struct FilterState_R000267_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int residue_25_1 = 0;
  int residue_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_25_1 = ((residue_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_25_2 = ((residue_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_25_1) & 127;
    acc_2 = (acc_2 + residue_25_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_65_1 = local_arr_1[aux_1 % 3];
  int anchor_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_65_2 * 2)) & 127;
  int sample_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_93_1 > 42)
  {
    acc_1 = ((acc_1 + (sample_93_1 * 2)) + 5) & 127;
    aux_1 ^= sample_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_93_2 > 42)
  {
    acc_2 = ((acc_2 + (sample_93_2 * 2)) + 5) & 127;
    aux_2 ^= sample_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_25_1 == residue_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_65_1 == anchor_65_2);
  assert(sample_93_1 == sample_93_2);
}

int fn_R000267_6713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int residue_25 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_25 = ((residue_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_25) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_65 = local_arr[aux % 3];
  acc = (acc + (anchor_65 * 2)) & 127;
  int sample_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_93 > 42)
  {
    acc = ((acc + (sample_93 * 2)) + 5) & 127;
    aux ^= sample_93 & 15;
  }
  else
  {
    acc = ((acc - sample_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000267_6713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st_1 = {0};
  struct FilterState_R000267_6713_3 st_2 = {0};
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
  int window_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_97_1 > 50)
  {
    acc_1 = ((acc_1 + (window_97_1 * 2)) + 5) & 127;
    aux_1 ^= window_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_97_2 > 50)
  {
    acc_2 = ((acc_2 + (window_97_2 * 2)) + 5) & 127;
    aux_2 ^= window_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_71_1 = local_arr_1[aux_1 % 3];
  int offset_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_71_2 * 2)) & 127;
  int index_reg_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_71_1) & 63;
  aux_2 = (aux_2 + index_reg_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_97_1 == window_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_71_1 == offset_71_2);
  assert(index_reg_71_1 == index_reg_71_2);
}

int fn_R000267_6713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_97 > 50)
  {
    acc = ((acc + (window_97 * 2)) + 5) & 127;
    aux ^= window_97 & 15;
  }
  else
  {
    acc = ((acc - window_97) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_71 = local_arr[aux % 3];
  acc = (acc + (offset_71 * 2)) & 127;
  int index_reg_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000267_6713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st_1 = {0};
  struct DeviceConfig_R000267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int accumulator_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_81_1)
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

  switch (accumulator_81_2)
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

  int threshold_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_52_1 > 24)
  {
    acc_1 = ((acc_1 + (threshold_52_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_52_2 > 24)
  {
    acc_2 = ((acc_2 + (threshold_52_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_52_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_37_1 = 0;
  int index_reg_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_37_1 = ((index_reg_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_37_2 = ((index_reg_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_37_1) & 127;
    acc_2 = (acc_2 + index_reg_37_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_83_1 = local_arr_1[aux_1 % 3];
  int phase_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_81_1 == accumulator_81_2);
  assert(threshold_52_1 == threshold_52_2);
  assert(index_reg_37_1 == index_reg_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_83_1 == phase_83_2);
}

int fn_R000267_6713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int accumulator_81 = (aux + st.buffer[1]) & 3;
  switch (accumulator_81)
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

  int threshold_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_52 > 24)
  {
    acc = ((acc + (threshold_52 * 2)) + 5) & 127;
    aux ^= threshold_52 & 15;
  }
  else
  {
    acc = ((acc - threshold_52) + 11) & 127;
    aux += 3;
  }
  int index_reg_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_37 = ((index_reg_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_37) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_83 = local_arr[aux % 3];
  acc = (acc + (phase_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st_1 = {0};
  struct FilterState_R000267_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_85_1) & 63;
  aux_2 = (aux_2 + metric_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_61_1 > 49)
  {
    acc_1 = ((acc_1 + (stride_61_1 * 2)) + 5) & 127;
    aux_1 ^= stride_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_61_2 > 49)
  {
    acc_2 = ((acc_2 + (stride_61_2 * 2)) + 5) & 127;
    aux_2 ^= stride_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_16_1 = 0;
  int damping_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_16_1 = ((damping_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_16_2 = ((damping_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_16_1) & 127;
    acc_2 = (acc_2 + damping_16_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_85_1 == metric_85_2);
  assert(stride_61_1 == stride_61_2);
  assert(damping_16_1 == damping_16_2);
}

int fn_R000267_6713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_85) & 63;
  acc ^= aux;
  int stride_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_61 > 49)
  {
    acc = ((acc + (stride_61 * 2)) + 5) & 127;
    aux ^= stride_61 & 15;
  }
  else
  {
    acc = ((acc - stride_61) + 11) & 127;
    aux += 3;
  }
  int damping_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_16 = ((damping_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_16) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st_1 = {0};
  struct CipherContext_R000267_6713_0 st_2 = {0};
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
  int delta_88_1 = 0;
  int delta_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_88_1 = ((delta_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_88_2 = ((delta_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_88_1) & 127;
    acc_2 = (acc_2 + delta_88_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_88_1 == delta_88_2);
}

int fn_R000267_6713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_88 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_88 = ((delta_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_88) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000267_6713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st_1 = {0};
  struct DeviceConfig_R000267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int metric_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_70_1)
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

  switch (metric_70_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_70_1 == metric_70_2);
}

int fn_R000267_6713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int metric_70 = (aux + st.buffer[1]) & 3;
  switch (metric_70)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st_1 = {0};
  struct FilterState_R000267_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_48_1) & 63;
  aux_2 = (aux_2 + segment_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_64_1 = local_arr_1[aux_1 % 3];
  int delta_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_64_2 * 2)) & 127;
  int mask_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_20_1 > 25)
  {
    acc_1 = ((acc_1 + (mask_20_1 * 2)) + 5) & 127;
    aux_1 ^= mask_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_20_2 > 25)
  {
    acc_2 = ((acc_2 + (mask_20_2 * 2)) + 5) & 127;
    aux_2 ^= mask_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_48_1 == segment_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_64_1 == delta_64_2);
  assert(mask_20_1 == mask_20_2);
}

int fn_R000267_6713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_64 = local_arr[aux % 3];
  acc = (acc + (delta_64 * 2)) & 127;
  int mask_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_20 > 25)
  {
    acc = ((acc + (mask_20 * 2)) + 5) & 127;
    aux ^= mask_20 & 15;
  }
  else
  {
    acc = ((acc - mask_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000267_6713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st_1 = {0};
  struct CipherContext_R000267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_75_1 = local_arr_1[aux_1 % 3];
  int delta_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_75_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
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

  assert(delta_75_1 == delta_75_2);
}

int fn_R000267_6713_9(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_75 = local_arr[aux % 3];
  acc = (acc + (delta_75 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st_1 = {0};
  struct CipherContext_R000267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int stride_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_61_1) & 63;
  aux_2 = (aux_2 + stride_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_27_1 > 29)
  {
    acc_1 = ((acc_1 + (quotient_27_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_27_2 > 29)
  {
    acc_2 = ((acc_2 + (quotient_27_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_92_1)
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

  switch (factor_92_2)
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
  int vector_27_1 = local_arr_1[aux_1 % 3];
  int vector_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_27_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_61_1 == stride_61_2);
  assert(quotient_27_1 == quotient_27_2);
  assert(factor_92_1 == factor_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_27_1 == vector_27_2);
}

int fn_R000267_6713_10(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int stride_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_61) & 63;
  acc ^= aux;
  int quotient_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_27 > 29)
  {
    acc = ((acc + (quotient_27 * 2)) + 5) & 127;
    aux ^= quotient_27 & 15;
  }
  else
  {
    acc = ((acc - quotient_27) + 11) & 127;
    aux += 3;
  }
  int factor_92 = (aux + st.buffer[1]) & 3;
  switch (factor_92)
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
  int vector_27 = local_arr[aux % 3];
  acc = (acc + (vector_27 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st_1 = {0};
  struct CipherContext_R000267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_79_1) & 63;
  aux_2 = (aux_2 + delta_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_14_1 = local_arr_1[aux_1 % 3];
  int window_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_79_1 == delta_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_14_1 == window_14_2);
}

int fn_R000267_6713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_79) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_14 = local_arr[aux % 3];
  acc = (acc + (window_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st_1 = {0};
  struct CipherContext_R000267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_14_1) & 63;
  aux_2 = (aux_2 + margin_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_14_1 == margin_14_2);
}

int fn_R000267_6713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000267_6713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st_1 = {0};
  struct DeviceConfig_R000267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_36_1 = 0;
  int bound_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_36_1 = ((bound_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_36_2 = ((bound_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_36_1) & 127;
    acc_2 = (acc_2 + bound_36_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_80_1 = local_arr_1[aux_1 % 3];
  int bound_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_36_1 == bound_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_80_1 == bound_80_2);
}

int fn_R000267_6713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_36 = ((bound_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_36) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_80 = local_arr[aux % 3];
  acc = (acc + (bound_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st_1 = {0};
  struct FilterState_R000267_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int coefficient_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_19_1 > 31)
  {
    acc_1 = ((acc_1 + (coefficient_19_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_19_2 > 31)
  {
    acc_2 = ((acc_2 + (coefficient_19_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_97_1 = 0;
  int tracker_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_97_1 = ((tracker_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_97_2 = ((tracker_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_97_1) & 127;
    acc_2 = (acc_2 + tracker_97_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_19_1 == coefficient_19_2);
  assert(tracker_97_1 == tracker_97_2);
}

int fn_R000267_6713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int coefficient_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_19 > 31)
  {
    acc = ((acc + (coefficient_19 * 2)) + 5) & 127;
    aux ^= coefficient_19 & 15;
  }
  else
  {
    acc = ((acc - coefficient_19) + 11) & 127;
    aux += 3;
  }
  int tracker_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_97 = ((tracker_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_97) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st_1 = {0};
  struct FilterState_R000267_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int quotient_52_1 = 0;
  int quotient_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_52_1 = ((quotient_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_52_2 = ((quotient_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_52_1) & 127;
    acc_2 = (acc_2 + quotient_52_2) & 127;
  }

  int tally_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_59_1) & 63;
  aux_2 = (aux_2 + tally_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_66_1 = local_arr_1[aux_1 % 3];
  int scale_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_66_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_52_1 == quotient_52_2);
  assert(tally_59_1 == tally_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_66_1 == scale_66_2);
}

int fn_R000267_6713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int quotient_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_52 = ((quotient_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_52) & 127;
  }

  int tally_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_59) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_66 = local_arr[aux % 3];
  acc = (acc + (scale_66 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st_1 = {0};
  struct CipherContext_R000267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_75_1)
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

  switch (phase_75_2)
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

  int residue_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_21_1) & 63;
  aux_2 = (aux_2 + residue_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_75_1 == phase_75_2);
  assert(residue_21_1 == residue_21_2);
}

int fn_R000267_6713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_75 = (aux + st.buffer[1]) & 3;
  switch (phase_75)
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

  int residue_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000267_6713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st_1 = {0};
  struct CipherContext_R000267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_17_1 > 28)
  {
    acc_1 = ((acc_1 + (offset_17_1 * 2)) + 5) & 127;
    aux_1 ^= offset_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_17_2 > 28)
  {
    acc_2 = ((acc_2 + (offset_17_2 * 2)) + 5) & 127;
    aux_2 ^= offset_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_55_1)
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

  switch (residue_55_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_17_1 == offset_17_2);
  assert(residue_55_1 == residue_55_2);
}

int fn_R000267_6713_17(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_17 > 28)
  {
    acc = ((acc + (offset_17 * 2)) + 5) & 127;
    aux ^= offset_17 & 15;
  }
  else
  {
    acc = ((acc - offset_17) + 11) & 127;
    aux += 3;
  }
  int residue_55 = (aux + st.buffer[1]) & 3;
  switch (residue_55)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st_1 = {0};
  struct CipherContext_R000267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_19_1 = local_arr_1[aux_1 % 3];
  int offset_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_19_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
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

  assert(offset_19_1 == offset_19_2);
}

int fn_R000267_6713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int offset_19 = local_arr[aux % 3];
  acc = (acc + (offset_19 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st_1 = {0};
  struct FilterState_R000267_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_99_1 = local_arr_1[aux_1 % 3];
  int parity_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_99_2 * 2)) & 127;
  int coefficient_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_68_1 > 50)
  {
    acc_1 = ((acc_1 + (coefficient_68_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_68_2 > 50)
  {
    acc_2 = ((acc_2 + (coefficient_68_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_64_1) & 63;
  aux_2 = (aux_2 + pivot_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_99_1 == parity_99_2);
  assert(coefficient_68_1 == coefficient_68_2);
  assert(pivot_64_1 == pivot_64_2);
}

int fn_R000267_6713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000267_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int parity_99 = local_arr[aux % 3];
  acc = (acc + (parity_99 * 2)) & 127;
  int coefficient_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_68 > 50)
  {
    acc = ((acc + (coefficient_68 * 2)) + 5) & 127;
    aux ^= coefficient_68 & 15;
  }
  else
  {
    acc = ((acc - coefficient_68) + 11) & 127;
    aux += 3;
  }
  int pivot_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_64) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000267_6713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000267_6713_2 st_1 = {0};
  struct MatrixBlock_R000267_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_64_1 > 35)
  {
    acc_1 = ((acc_1 + (anchor_64_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_64_2 > 35)
  {
    acc_2 = ((acc_2 + (anchor_64_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_74_1 = local_arr_1[aux_1 % 3];
  int sample_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_74_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_90_1)
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

  switch (offset_90_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_64_1 == anchor_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_74_1 == sample_74_2);
  assert(offset_90_1 == offset_90_2);
}

int fn_R000267_6713_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000267_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_64 > 35)
  {
    acc = ((acc + (anchor_64 * 2)) + 5) & 127;
    aux ^= anchor_64 & 15;
  }
  else
  {
    acc = ((acc - anchor_64) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_74 = local_arr[aux % 3];
  acc = (acc + (sample_74 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_90 = (aux + st.buffer[1]) & 3;
  switch (offset_90)
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

void fn_R000267_6713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st_1 = {0};
  struct DeviceConfig_R000267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_48_1 = 0;
  int window_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_48_1 = ((window_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_48_2 = ((window_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_48_1) & 127;
    acc_2 = (acc_2 + window_48_2) & 127;
  }

  int scale_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_55_1) & 63;
  aux_2 = (aux_2 + scale_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_64_1 = local_arr_1[aux_1 % 3];
  int damping_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_48_1 == window_48_2);
  assert(scale_55_1 == scale_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_64_1 == damping_64_2);
}

int fn_R000267_6713_21(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_48 = ((window_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_48) & 127;
  }

  int scale_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_55) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int damping_64 = local_arr[aux % 3];
  acc = (acc + (damping_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000267_6713_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st_1 = {0};
  struct DeviceConfig_R000267_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_27_1 = local_arr_1[aux_1 % 3];
  int accumulator_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_27_2 * 2)) & 127;
  int mask_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_51_1) & 63;
  aux_2 = (aux_2 + mask_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_88_1 = 0;
  int vector_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_88_1 = ((vector_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_88_2 = ((vector_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_88_1) & 127;
    acc_2 = (acc_2 + vector_88_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_27_1 == accumulator_27_2);
  assert(mask_51_1 == mask_51_2);
  assert(vector_88_1 == vector_88_2);
}

int fn_R000267_6713_22(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000267_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int accumulator_27 = local_arr[aux % 3];
  acc = (acc + (accumulator_27 * 2)) & 127;
  int mask_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_51) & 63;
  acc ^= aux;
  int vector_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_88 = ((vector_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_88) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000267_6713_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st_1 = {0};
  struct CipherContext_R000267_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int bound_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_22_1 > 42)
  {
    acc_1 = ((acc_1 + (bound_22_1 * 2)) + 5) & 127;
    aux_1 ^= bound_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_22_2 > 42)
  {
    acc_2 = ((acc_2 + (bound_22_2 * 2)) + 5) & 127;
    aux_2 ^= bound_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_22_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_43_1 = local_arr_1[aux_1 % 3];
  int vector_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_43_2 * 2)) & 127;
  int mask_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_16_1) & 63;
  aux_2 = (aux_2 + mask_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_22_1 == bound_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_43_1 == vector_43_2);
  assert(mask_16_1 == mask_16_2);
}

int fn_R000267_6713_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000267_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int bound_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_22 > 42)
  {
    acc = ((acc + (bound_22 * 2)) + 5) & 127;
    aux ^= bound_22 & 15;
  }
  else
  {
    acc = ((acc - bound_22) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_43 = local_arr[aux % 3];
  acc = (acc + (vector_43 * 2)) & 127;
  int mask_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000267_0_1;
  int sec_r000267_0_2;
  int sec_r000267_1_1;
  int sec_r000267_1_2;
  int sec_r000267_2_1;
  int sec_r000267_2_2;
  int sec_r000267_3_1;
  int sec_r000267_3_2;
  int sec_r000267_4_1;
  int sec_r000267_4_2;
  int sec_r000267_5_1;
  int sec_r000267_5_2;
  int sec_r000267_6_1;
  int sec_r000267_6_2;
  int sec_r000267_7_1;
  int sec_r000267_7_2;
  int sec_r000267_8_1;
  int sec_r000267_8_2;
  int sec_r000267_9_1;
  int sec_r000267_9_2;
  int sec_r000267_10_1;
  int sec_r000267_10_2;
  int sec_r000267_11_1;
  int sec_r000267_11_2;
  int sec_r000267_12_1;
  int sec_r000267_12_2;
  int sec_r000267_13_1;
  int sec_r000267_13_2;
  int sec_r000267_14_1;
  int sec_r000267_14_2;
  int sec_r000267_15_1;
  int sec_r000267_15_2;
  int sec_r000267_16_1;
  int sec_r000267_16_2;
  int sec_r000267_17_1;
  int sec_r000267_17_2;
  int pub_r000267_0_1;
  int pub_r000267_0_2;
  int pub_r000267_1_1;
  int pub_r000267_1_2;
  int pub_r000267_2_1;
  int pub_r000267_2_2;
  int pub_r000267_3_1;
  int pub_r000267_3_2;
  int pub_r000267_4_1;
  int pub_r000267_4_2;
  int pub_r000267_5_1;
  int pub_r000267_5_2;
  int pub_r000267_6_1;
  int pub_r000267_6_2;
  int pub_r000267_7_1;
  int pub_r000267_7_2;
  int pub_r000267_8_1;
  int pub_r000267_8_2;
  int pub_r000267_9_1;
  int pub_r000267_9_2;
  int pub_r000267_10_1;
  int pub_r000267_10_2;
  int pub_r000267_11_1;
  int pub_r000267_11_2;
  int pub_r000267_12_1;
  int pub_r000267_12_2;
  int pub_r000267_13_1;
  int pub_r000267_13_2;
  int pub_r000267_14_1;
  int pub_r000267_14_2;
  int pub_r000267_15_1;
  int pub_r000267_15_2;
  int pub_r000267_16_1;
  int pub_r000267_16_2;
  int pub_r000267_17_1;
  int pub_r000267_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000267_0_1 >= (-100)) && (pub_r000267_0_1 <= 100));
  __CPROVER_assume((pub_r000267_0_2 >= (-100)) && (pub_r000267_0_2 <= 100));
  __CPROVER_assume((pub_r000267_1_1 >= (-100)) && (pub_r000267_1_1 <= 100));
  __CPROVER_assume((pub_r000267_1_2 >= (-100)) && (pub_r000267_1_2 <= 100));
  __CPROVER_assume((pub_r000267_2_1 >= (-100)) && (pub_r000267_2_1 <= 100));
  __CPROVER_assume((pub_r000267_2_2 >= (-100)) && (pub_r000267_2_2 <= 100));
  __CPROVER_assume((pub_r000267_3_1 >= (-100)) && (pub_r000267_3_1 <= 100));
  __CPROVER_assume((pub_r000267_3_2 >= (-100)) && (pub_r000267_3_2 <= 100));
  __CPROVER_assume((pub_r000267_4_1 >= (-100)) && (pub_r000267_4_1 <= 100));
  __CPROVER_assume((pub_r000267_4_2 >= (-100)) && (pub_r000267_4_2 <= 100));
  __CPROVER_assume((pub_r000267_5_1 >= (-100)) && (pub_r000267_5_1 <= 100));
  __CPROVER_assume((pub_r000267_5_2 >= (-100)) && (pub_r000267_5_2 <= 100));
  __CPROVER_assume((pub_r000267_6_1 >= (-100)) && (pub_r000267_6_1 <= 100));
  __CPROVER_assume((pub_r000267_6_2 >= (-100)) && (pub_r000267_6_2 <= 100));
  __CPROVER_assume((pub_r000267_7_1 >= (-100)) && (pub_r000267_7_1 <= 100));
  __CPROVER_assume((pub_r000267_7_2 >= (-100)) && (pub_r000267_7_2 <= 100));
  __CPROVER_assume((pub_r000267_8_1 >= (-100)) && (pub_r000267_8_1 <= 100));
  __CPROVER_assume((pub_r000267_8_2 >= (-100)) && (pub_r000267_8_2 <= 100));
  __CPROVER_assume((pub_r000267_9_1 >= (-100)) && (pub_r000267_9_1 <= 100));
  __CPROVER_assume((pub_r000267_9_2 >= (-100)) && (pub_r000267_9_2 <= 100));
  __CPROVER_assume((pub_r000267_10_1 >= (-100)) && (pub_r000267_10_1 <= 100));
  __CPROVER_assume((pub_r000267_10_2 >= (-100)) && (pub_r000267_10_2 <= 100));
  __CPROVER_assume((pub_r000267_11_1 >= (-100)) && (pub_r000267_11_1 <= 100));
  __CPROVER_assume((pub_r000267_11_2 >= (-100)) && (pub_r000267_11_2 <= 100));
  __CPROVER_assume((pub_r000267_12_1 >= (-100)) && (pub_r000267_12_1 <= 100));
  __CPROVER_assume((pub_r000267_12_2 >= (-100)) && (pub_r000267_12_2 <= 100));
  __CPROVER_assume((pub_r000267_13_1 >= (-100)) && (pub_r000267_13_1 <= 100));
  __CPROVER_assume((pub_r000267_13_2 >= (-100)) && (pub_r000267_13_2 <= 100));
  __CPROVER_assume((pub_r000267_14_1 >= (-100)) && (pub_r000267_14_1 <= 100));
  __CPROVER_assume((pub_r000267_14_2 >= (-100)) && (pub_r000267_14_2 <= 100));
  __CPROVER_assume((pub_r000267_15_1 >= (-100)) && (pub_r000267_15_1 <= 100));
  __CPROVER_assume((pub_r000267_15_2 >= (-100)) && (pub_r000267_15_2 <= 100));
  __CPROVER_assume((pub_r000267_16_1 >= (-100)) && (pub_r000267_16_1 <= 100));
  __CPROVER_assume((pub_r000267_16_2 >= (-100)) && (pub_r000267_16_2 <= 100));
  __CPROVER_assume((pub_r000267_17_1 >= (-100)) && (pub_r000267_17_1 <= 100));
  __CPROVER_assume((pub_r000267_17_2 >= (-100)) && (pub_r000267_17_2 <= 100));
  __CPROVER_assume((sec_r000267_0_1 >= 0) && (sec_r000267_0_1 <= 255));
  __CPROVER_assume((sec_r000267_0_2 >= 0) && (sec_r000267_0_2 <= 255));
  __CPROVER_assume((sec_r000267_1_1 >= 0) && (sec_r000267_1_1 <= 255));
  __CPROVER_assume((sec_r000267_1_2 >= 0) && (sec_r000267_1_2 <= 255));
  __CPROVER_assume((sec_r000267_2_1 >= 0) && (sec_r000267_2_1 <= 255));
  __CPROVER_assume((sec_r000267_2_2 >= 0) && (sec_r000267_2_2 <= 255));
  __CPROVER_assume((sec_r000267_3_1 >= 0) && (sec_r000267_3_1 <= 255));
  __CPROVER_assume((sec_r000267_3_2 >= 0) && (sec_r000267_3_2 <= 255));
  __CPROVER_assume((sec_r000267_4_1 >= 0) && (sec_r000267_4_1 <= 255));
  __CPROVER_assume((sec_r000267_4_2 >= 0) && (sec_r000267_4_2 <= 255));
  __CPROVER_assume((sec_r000267_5_1 >= 0) && (sec_r000267_5_1 <= 255));
  __CPROVER_assume((sec_r000267_5_2 >= 0) && (sec_r000267_5_2 <= 255));
  __CPROVER_assume((sec_r000267_6_1 >= 0) && (sec_r000267_6_1 <= 255));
  __CPROVER_assume((sec_r000267_6_2 >= 0) && (sec_r000267_6_2 <= 255));
  __CPROVER_assume((sec_r000267_7_1 >= 0) && (sec_r000267_7_1 <= 255));
  __CPROVER_assume((sec_r000267_7_2 >= 0) && (sec_r000267_7_2 <= 255));
  __CPROVER_assume((sec_r000267_8_1 >= 0) && (sec_r000267_8_1 <= 255));
  __CPROVER_assume((sec_r000267_8_2 >= 0) && (sec_r000267_8_2 <= 255));
  __CPROVER_assume((sec_r000267_9_1 >= 0) && (sec_r000267_9_1 <= 255));
  __CPROVER_assume((sec_r000267_9_2 >= 0) && (sec_r000267_9_2 <= 255));
  __CPROVER_assume((sec_r000267_10_1 >= 0) && (sec_r000267_10_1 <= 255));
  __CPROVER_assume((sec_r000267_10_2 >= 0) && (sec_r000267_10_2 <= 255));
  __CPROVER_assume((sec_r000267_11_1 >= 0) && (sec_r000267_11_1 <= 255));
  __CPROVER_assume((sec_r000267_11_2 >= 0) && (sec_r000267_11_2 <= 255));
  __CPROVER_assume((sec_r000267_12_1 >= 0) && (sec_r000267_12_1 <= 255));
  __CPROVER_assume((sec_r000267_12_2 >= 0) && (sec_r000267_12_2 <= 255));
  __CPROVER_assume((sec_r000267_13_1 >= 0) && (sec_r000267_13_1 <= 255));
  __CPROVER_assume((sec_r000267_13_2 >= 0) && (sec_r000267_13_2 <= 255));
  __CPROVER_assume((sec_r000267_14_1 >= 0) && (sec_r000267_14_1 <= 255));
  __CPROVER_assume((sec_r000267_14_2 >= 0) && (sec_r000267_14_2 <= 255));
  __CPROVER_assume((sec_r000267_15_1 >= 0) && (sec_r000267_15_1 <= 255));
  __CPROVER_assume((sec_r000267_15_2 >= 0) && (sec_r000267_15_2 <= 255));
  __CPROVER_assume((sec_r000267_16_1 >= 0) && (sec_r000267_16_1 <= 255));
  __CPROVER_assume((sec_r000267_16_2 >= 0) && (sec_r000267_16_2 <= 255));
  __CPROVER_assume((sec_r000267_17_1 >= 0) && (sec_r000267_17_1 <= 255));
  __CPROVER_assume((sec_r000267_17_2 >= 0) && (sec_r000267_17_2 <= 255));
  struct CipherContext_R000267_6713_0 st_var_0_1 = {0};
  struct CipherContext_R000267_6713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000267_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000267_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000267_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000267_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000267_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000267_0_2 + 7) & 15;
  struct DeviceConfig_R000267_6713_1 st_var_1_1 = {0};
  struct DeviceConfig_R000267_6713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000267_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000267_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000267_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000267_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000267_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000267_0_2 + 9) & 15;
  struct MatrixBlock_R000267_6713_2 st_var_2_1 = {0};
  struct MatrixBlock_R000267_6713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000267_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000267_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000267_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000267_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000267_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000267_0_2 + 11) & 15;
  struct FilterState_R000267_6713_3 st_var_3_1 = {0};
  struct FilterState_R000267_6713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000267_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000267_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000267_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000267_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000267_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000267_0_2 + 13) & 15;
  union TelemetryField_R000267_6713_0 u_var_1;
  union TelemetryField_R000267_6713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 16) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = ((st_var_0_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_0_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 31)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 31)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_27_1 = ((st_var_3_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_3_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 40)
    {
      chk_sum_1 ^= stage_v_27_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_27_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 40)
    {
      chk_sum_2 ^= stage_v_27_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 41)
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
  if (stage_v_29_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 41)
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
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((st_var_3_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_3_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 25)
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
  if (stage_v_31_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 25)
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
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 36) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
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
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (st_var_0_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_0_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = ((st_var_2_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_2_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 49)
    {
      chk_sum_1 ^= stage_v_46_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_46_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 49)
    {
      chk_sum_2 ^= stage_v_46_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 30)
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
  if (stage_v_49_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 30)
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
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 50)
    {
      chk_sum_1 ^= stage_v_50_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_50_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 50)
    {
      chk_sum_2 ^= stage_v_50_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 52) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 49)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 49)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 54) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 54) & 15;
  int stage_v_53_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_53_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= stage_v_53_1;
  chk_sum_2 ^= stage_v_53_2;
  int stage_v_54_1 = (st_var_2_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_2_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (st_var_0_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_0_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 60) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 63) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 64) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_65_1 = ((st_var_1_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_1_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 47)
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
  if (stage_v_65_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 47)
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
  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  int stage_v_67_1 = (st_var_3_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_3_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 69) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 72) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = ((st_var_2_1.buffer[2] * 2) + 229) & 63;
  int stage_v_74_2 = ((st_var_2_2.buffer[2] * 2) + 229) & 63;
  if (stage_v_74_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_74_1) - 5) & 255;
    if (stage_v_74_1 > 44)
    {
      chk_sum_1 ^= stage_v_74_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_74_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_74_2) - 5) & 255;
    if (stage_v_74_2 > 44)
    {
      chk_sum_2 ^= stage_v_74_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_75_1 = ((st_var_3_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_3_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 30)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 30)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_76_1 = table_1[0];
  int stage_v_76_2 = table_2[0];
  table_1[0] = (table_1[1] + 153) & 63;
  table_2[0] = (table_2[1] + 153) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 78) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 79) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 79) & 15;
  int stage_v_78_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_78_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= stage_v_78_1;
  chk_sum_2 ^= stage_v_78_2;
  int stage_v_79_1 = (st_var_3_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_3_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
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

  switch (stage_v_79_2)
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

  int stage_v_80_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_80_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_81_1 = (st_var_1_1.buffer[0] ^ 84) & 3;
  int stage_v_81_2 = (st_var_1_2.buffer[0] ^ 84) & 3;
  switch (stage_v_81_1)
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

  switch (stage_v_81_2)
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

  int stage_v_82_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (87 & 31);
  int stage_v_82_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (87 & 31);
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= (stage_v_82_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_82_2 << 1) & 127;
  int stage_v_83_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_83_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_83_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_83_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_84_1 = ((st_var_0_1.buffer[0] * 2) + 259) & 63;
  int stage_v_84_2 = ((st_var_0_2.buffer[0] * 2) + 259) & 63;
  if (stage_v_84_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_84_1) - 5) & 255;
    if (stage_v_84_1 > 54)
    {
      chk_sum_1 ^= stage_v_84_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_84_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_84_2) - 5) & 255;
    if (stage_v_84_2 > 54)
    {
      chk_sum_2 ^= stage_v_84_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = table_1[2];
  int stage_v_86_2 = table_2[2];
  table_1[2] = (table_1[3] + 173) & 63;
  table_2[2] = (table_2[3] + 173) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = table_1[3];
  int stage_v_87_2 = table_2[3];
  table_1[3] = (table_1[0] + 175) & 63;
  table_2[3] = (table_2[0] + 175) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 89) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 89) & 15;
  int stage_v_88_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_88_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= stage_v_88_1;
  chk_sum_2 ^= stage_v_88_2;
  int stage_v_89_1 = ((st_var_1_1.buffer[2] * 2) + 274) & 63;
  int stage_v_89_2 = ((st_var_1_2.buffer[2] * 2) + 274) & 63;
  if (stage_v_89_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_89_1) - 5) & 255;
    if (stage_v_89_1 > 29)
    {
      chk_sum_1 ^= stage_v_89_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_89_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_89_2) - 5) & 255;
    if (stage_v_89_2 > 29)
    {
      chk_sum_2 ^= stage_v_89_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_90_1 = table_1[2];
  int stage_v_90_2 = table_2[2];
  table_1[2] = (table_1[3] + 181) & 63;
  table_2[2] = (table_2[3] + 181) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (96 & 31);
  int stage_v_91_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (96 & 31);
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= (stage_v_91_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_91_2 << 1) & 127;
  int stage_v_92_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (97 & 31);
  int stage_v_92_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (97 & 31);
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  chk_sum_1 ^= (stage_v_92_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_92_2 << 1) & 127;
  int stage_v_93_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (98 & 31);
  int stage_v_93_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (98 & 31);
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= (stage_v_93_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_93_2 << 1) & 127;
  int stage_v_94_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_94_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((st_var_0_1.buffer[0] * 2) + 295) & 63;
  int stage_v_96_2 = ((st_var_0_2.buffer[0] * 2) + 295) & 63;
  if (stage_v_96_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_96_1) - 5) & 255;
    if (stage_v_96_1 > 52)
    {
      chk_sum_1 ^= stage_v_96_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_96_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_96_2) - 5) & 255;
    if (stage_v_96_2 > 52)
    {
      chk_sum_2 ^= stage_v_96_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_97_1 = table_1[1];
  int stage_v_97_2 = table_2[1];
  table_1[1] = (table_1[2] + 195) & 63;
  table_2[1] = (table_2[2] + 195) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (103 & 31);
  int stage_v_98_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (103 & 31);
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  chk_sum_1 ^= (stage_v_98_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_98_2 << 1) & 127;
  int stage_v_99_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_99_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_100_1 = ((st_var_0_1.buffer[1] * 2) + 307) & 63;
  int stage_v_100_2 = ((st_var_0_2.buffer[1] * 2) + 307) & 63;
  if (stage_v_100_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_100_1) - 5) & 255;
    if (stage_v_100_1 > 28)
    {
      chk_sum_1 ^= stage_v_100_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_100_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_100_2) - 5) & 255;
    if (stage_v_100_2 > 28)
    {
      chk_sum_2 ^= stage_v_100_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_101_1 = table_1[1];
  int stage_v_101_2 = table_2[1];
  table_1[1] = (table_1[2] + 203) & 63;
  table_2[1] = (table_2[2] + 203) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (st_var_2_1.buffer[0] ^ 105) & 3;
  int stage_v_102_2 = (st_var_2_2.buffer[0] ^ 105) & 3;
  switch (stage_v_102_1)
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

  switch (stage_v_102_2)
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

  int stage_v_103_1 = table_1[3];
  int stage_v_103_2 = table_2[3];
  table_1[3] = (table_1[0] + 207) & 63;
  table_2[3] = (table_2[0] + 207) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((st_var_0_1.buffer[2] * 2) + 319) & 63;
  int stage_v_104_2 = ((st_var_0_2.buffer[2] * 2) + 319) & 63;
  if (stage_v_104_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_104_1) - 5) & 255;
    if (stage_v_104_1 > 53)
    {
      chk_sum_1 ^= stage_v_104_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_104_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_104_2) - 5) & 255;
    if (stage_v_104_2 > 53)
    {
      chk_sum_2 ^= stage_v_104_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_105_1 = table_1[1];
  int stage_v_105_2 = table_2[1];
  table_1[1] = (table_1[2] + 211) & 63;
  table_2[1] = (table_2[2] + 211) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_107_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((st_var_1_1.buffer[1] * 2) + 334) & 63;
  int stage_v_109_2 = ((st_var_1_2.buffer[1] * 2) + 334) & 63;
  if (stage_v_109_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_109_1) - 5) & 255;
    if (stage_v_109_1 > 49)
    {
      chk_sum_1 ^= stage_v_109_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_109_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_109_2) - 5) & 255;
    if (stage_v_109_2 > 49)
    {
      chk_sum_2 ^= stage_v_109_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (st_var_3_1.buffer[0] ^ 114) & 3;
  int stage_v_111_2 = (st_var_3_2.buffer[0] ^ 114) & 3;
  switch (stage_v_111_1)
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

  switch (stage_v_111_2)
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

  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_113_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_114_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (119 & 31);
  int stage_v_114_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (119 & 31);
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= (stage_v_114_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_114_2 << 1) & 127;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 117) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 117) & 15;
  int stage_v_116_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_116_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= stage_v_116_1;
  chk_sum_2 ^= stage_v_116_2;
  int stage_v_117_1 = ((st_var_1_1.buffer[0] * 2) + 358) & 63;
  int stage_v_117_2 = ((st_var_1_2.buffer[0] * 2) + 358) & 63;
  if (stage_v_117_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_117_1) - 5) & 255;
    if (stage_v_117_1 > 34)
    {
      chk_sum_1 ^= stage_v_117_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_117_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_117_2) - 5) & 255;
    if (stage_v_117_2 > 34)
    {
      chk_sum_2 ^= stage_v_117_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_118_1 = (st_var_2_1.buffer[0] ^ 121) & 3;
  int stage_v_118_2 = (st_var_2_2.buffer[0] ^ 121) & 3;
  switch (stage_v_118_1)
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

  switch (stage_v_118_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 120) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 120) & 15;
  int stage_v_119_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_119_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= stage_v_119_1;
  chk_sum_2 ^= stage_v_119_2;
  int stage_v_120_1 = table_1[0];
  int stage_v_120_2 = table_2[0];
  table_1[0] = (table_1[1] + 241) & 63;
  table_2[0] = (table_2[1] + 241) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (st_var_1_1.buffer[0] ^ 124) & 3;
  int stage_v_121_2 = (st_var_1_2.buffer[0] ^ 124) & 3;
  switch (stage_v_121_1)
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

  switch (stage_v_121_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 123) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 123) & 15;
  int stage_v_122_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_122_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= stage_v_122_1;
  chk_sum_2 ^= stage_v_122_2;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 124) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 124) & 15;
  int stage_v_123_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_123_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= stage_v_123_1;
  chk_sum_2 ^= stage_v_123_2;
  int stage_v_124_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_124_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_125_1 = ((st_var_1_1.buffer[2] * 2) + 382) & 63;
  int stage_v_125_2 = ((st_var_1_2.buffer[2] * 2) + 382) & 63;
  if (stage_v_125_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_125_1) - 5) & 255;
    if (stage_v_125_1 > 39)
    {
      chk_sum_1 ^= stage_v_125_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_125_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_125_2) - 5) & 255;
    if (stage_v_125_2 > 39)
    {
      chk_sum_2 ^= stage_v_125_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_126_1 = (st_var_2_1.buffer[0] ^ 129) & 3;
  int stage_v_126_2 = (st_var_2_2.buffer[0] ^ 129) & 3;
  switch (stage_v_126_1)
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

  switch (stage_v_126_2)
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

  int stage_v_127_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_127_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_128_1 = (st_var_0_1.buffer[0] ^ 131) & 3;
  int stage_v_128_2 = (st_var_0_2.buffer[0] ^ 131) & 3;
  switch (stage_v_128_1)
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

  switch (stage_v_128_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 130) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 130) & 15;
  int stage_v_129_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_129_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= stage_v_129_1;
  chk_sum_2 ^= stage_v_129_2;
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = (st_var_3_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_3_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
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

  switch (stage_v_131_2)
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

  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_132_1 = ((stage_v_132_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_132_2 = ((stage_v_132_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (138 & 31);
  int stage_v_133_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (138 & 31);
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= (stage_v_133_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_133_2 << 1) & 127;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_135_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((st_var_1_1.buffer[2] * 2) + 418) & 63;
  int stage_v_137_2 = ((st_var_1_2.buffer[2] * 2) + 418) & 63;
  if (stage_v_137_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_137_1) - 5) & 255;
    if (stage_v_137_1 > 27)
    {
      chk_sum_1 ^= stage_v_137_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_137_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_137_2) - 5) & 255;
    if (stage_v_137_2 > 27)
    {
      chk_sum_2 ^= stage_v_137_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_138_1 = ((st_var_2_1.buffer[0] * 2) + 421) & 63;
  int stage_v_138_2 = ((st_var_2_2.buffer[0] * 2) + 421) & 63;
  if (stage_v_138_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_138_1) - 5) & 255;
    if (stage_v_138_1 > 54)
    {
      chk_sum_1 ^= stage_v_138_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_138_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_138_2) - 5) & 255;
    if (stage_v_138_2 > 54)
    {
      chk_sum_2 ^= stage_v_138_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_139_1 = ((st_var_3_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_3_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 38)
    {
      chk_sum_1 ^= stage_v_139_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_139_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 38)
    {
      chk_sum_2 ^= stage_v_139_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_140_1 = ((st_var_0_1.buffer[2] * 2) + 427) & 63;
  int stage_v_140_2 = ((st_var_0_2.buffer[2] * 2) + 427) & 63;
  if (stage_v_140_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_140_1) - 5) & 255;
    if (stage_v_140_1 > 41)
    {
      chk_sum_1 ^= stage_v_140_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_140_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_140_2) - 5) & 255;
    if (stage_v_140_2 > 41)
    {
      chk_sum_2 ^= stage_v_140_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_141_1 = (st_var_1_1.buffer[0] ^ 144) & 3;
  int stage_v_141_2 = (st_var_1_2.buffer[0] ^ 144) & 3;
  switch (stage_v_141_1)
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

  switch (stage_v_141_2)
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

  int stage_v_142_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (147 & 31);
  int stage_v_142_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (147 & 31);
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= (stage_v_142_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_142_2 << 1) & 127;
  int stage_v_143_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (148 & 31);
  int stage_v_143_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (148 & 31);
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  chk_sum_1 ^= (stage_v_143_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_143_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 145) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 145) & 15;
  int stage_v_144_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_144_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= stage_v_144_1;
  chk_sum_2 ^= stage_v_144_2;
  int stage_v_145_1 = (st_var_1_1.buffer[0] ^ 148) & 3;
  int stage_v_145_2 = (st_var_1_2.buffer[0] ^ 148) & 3;
  switch (stage_v_145_1)
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

  switch (stage_v_145_2)
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

  int stage_v_146_1 = table_1[2];
  int stage_v_146_2 = table_2[2];
  table_1[2] = (table_1[3] + 293) & 63;
  table_2[2] = (table_2[3] + 293) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (152 & 31);
  int stage_v_147_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (152 & 31);
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= (stage_v_147_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_147_2 << 1) & 127;
  int stage_v_148_1 = table_1[0];
  int stage_v_148_2 = table_2[0];
  table_1[0] = (table_1[1] + 297) & 63;
  table_2[0] = (table_2[1] + 297) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 151) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 151) & 15;
  int stage_v_150_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_150_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= stage_v_150_1;
  chk_sum_2 ^= stage_v_150_2;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_151_1 = ((stage_v_151_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_151_2 = ((stage_v_151_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (157 & 31);
  int stage_v_152_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (157 & 31);
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  chk_sum_1 ^= (stage_v_152_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_152_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 154) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 154) & 15;
  int stage_v_153_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_153_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= stage_v_153_1;
  chk_sum_2 ^= stage_v_153_2;
  int stage_v_154_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (159 & 31);
  int stage_v_154_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (159 & 31);
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= (stage_v_154_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_154_2 << 1) & 127;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = table_1[0];
  int stage_v_156_2 = table_2[0];
  table_1[0] = (table_1[1] + 313) & 63;
  table_2[0] = (table_2[1] + 313) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_157_1 = ((stage_v_157_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_158_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_159_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (164 & 31);
  int stage_v_159_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (164 & 31);
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  chk_sum_1 ^= (stage_v_159_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_159_2 << 1) & 127;
  int stage_v_160_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_160_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_161_1 = ((stage_v_161_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_161_2 = ((stage_v_161_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (167 & 31);
  int stage_v_162_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (167 & 31);
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= (stage_v_162_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_162_2 << 1) & 127;
  int stage_v_163_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (168 & 31);
  int stage_v_163_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (168 & 31);
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  chk_sum_1 ^= (stage_v_163_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_163_2 << 1) & 127;
  int stage_v_164_1 = (st_var_0_1.buffer[0] ^ 167) & 3;
  int stage_v_164_2 = (st_var_0_2.buffer[0] ^ 167) & 3;
  switch (stage_v_164_1)
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

  switch (stage_v_164_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 166) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 166) & 15;
  int stage_v_165_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_165_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= stage_v_165_1;
  chk_sum_2 ^= stage_v_165_2;
  int stage_v_166_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_166_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((st_var_0_1.buffer[0] * 2) + 511) & 63;
  int stage_v_168_2 = ((st_var_0_2.buffer[0] * 2) + 511) & 63;
  if (stage_v_168_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_168_1) - 5) & 255;
    if (stage_v_168_1 > 28)
    {
      chk_sum_1 ^= stage_v_168_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_168_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_168_2) - 5) & 255;
    if (stage_v_168_2 > 28)
    {
      chk_sum_2 ^= stage_v_168_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_169_1 = ((stage_v_169_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_169_2 = ((stage_v_169_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = table_1[2];
  int stage_v_170_2 = table_2[2];
  table_1[2] = (table_1[3] + 341) & 63;
  table_2[2] = (table_2[3] + 341) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((st_var_3_1.buffer[0] * 2) + 520) & 63;
  int stage_v_171_2 = ((st_var_3_2.buffer[0] * 2) + 520) & 63;
  if (stage_v_171_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_171_1) - 5) & 255;
    if (stage_v_171_1 > 26)
    {
      chk_sum_1 ^= stage_v_171_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_171_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_171_2) - 5) & 255;
    if (stage_v_171_2 > 26)
    {
      chk_sum_2 ^= stage_v_171_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_172_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_172_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_173_1 = (st_var_1_1.buffer[0] ^ 176) & 3;
  int stage_v_173_2 = (st_var_1_2.buffer[0] ^ 176) & 3;
  switch (stage_v_173_1)
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

  switch (stage_v_173_2)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 175) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 175) & 15;
  int stage_v_174_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_174_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  chk_sum_1 ^= stage_v_174_1;
  chk_sum_2 ^= stage_v_174_2;
  int stage_v_175_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (180 & 31);
  int stage_v_175_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (180 & 31);
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  chk_sum_1 ^= (stage_v_175_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_175_2 << 1) & 127;
  int stage_v_176_1 = table_1[0];
  int stage_v_176_2 = table_2[0];
  table_1[0] = (table_1[1] + 353) & 63;
  table_2[0] = (table_2[1] + 353) & 63;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_177_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_178_1 = 0;
  int stage_v_178_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_178_1 = ((stage_v_178_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_178_2 = ((stage_v_178_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (184 & 31);
  int stage_v_179_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (184 & 31);
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  chk_sum_1 ^= (stage_v_179_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_179_2 << 1) & 127;
  int stage_v_180_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_180_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_180_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_180_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_181_1 = table_1[1];
  int stage_v_181_2 = table_2[1];
  table_1[1] = (table_1[2] + 363) & 63;
  table_2[1] = (table_2[2] + 363) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (st_var_2_1.buffer[0] ^ 185) & 3;
  int stage_v_182_2 = (st_var_2_2.buffer[0] ^ 185) & 3;
  switch (stage_v_182_1)
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

  switch (stage_v_182_2)
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

  int stage_v_183_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (188 & 31);
  int stage_v_183_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (188 & 31);
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  chk_sum_1 ^= (stage_v_183_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_183_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 185) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 185) & 15;
  int stage_v_184_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_184_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  chk_sum_1 ^= stage_v_184_1;
  chk_sum_2 ^= stage_v_184_2;
  int stage_v_185_1 = table_1[1];
  int stage_v_185_2 = table_2[1];
  table_1[1] = (table_1[2] + 371) & 63;
  table_2[1] = (table_2[2] + 371) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_186_1 = ((stage_v_186_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int m_step_0_1 = ((sec_r000267_14_1 + pub_r000267_6_1) + 14) & 127;
  int m_step_0_2 = ((sec_r000267_14_2 + pub_r000267_6_2) + 14) & 127;
  int m_step_1_1 = ((m_step_0_1 + pub_r000267_11_1) + 10) & 127;
  int m_step_1_2 = ((m_step_0_2 + pub_r000267_11_2) + 10) & 127;
  int m_step_2_1 = ((m_step_1_1 + pub_r000267_9_1) + 24) & 127;
  int m_step_2_2 = ((m_step_1_2 + pub_r000267_9_2) + 24) & 127;
  out_sink_1 = (out_sink_1 + m_step_2_1) & 255;
  out_sink_2 = (out_sink_2 + m_step_2_2) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000267_11_1 == pub_r000267_11_2);
  __CPROVER_assume(sec_r000267_11_1 != sec_r000267_11_2);
  __CPROVER_assume(pub_r000267_6_1 == pub_r000267_6_2);
  __CPROVER_assume(sec_r000267_12_1 != sec_r000267_12_2);
  __CPROVER_assume(pub_r000267_1_1 == pub_r000267_1_2);
  __CPROVER_assume(sec_r000267_9_1 != sec_r000267_9_2);
  __CPROVER_assume(pub_r000267_9_1 == pub_r000267_9_2);
  __CPROVER_assume(pub_r000267_10_1 == pub_r000267_10_2);
  __CPROVER_assume(sec_r000267_16_1 != sec_r000267_16_2);
  __CPROVER_assume(pub_r000267_14_1 == pub_r000267_14_2);
  __CPROVER_assume(sec_r000267_17_1 != sec_r000267_17_2);
  __CPROVER_assume(pub_r000267_5_1 == pub_r000267_5_2);
  __CPROVER_assume(pub_r000267_13_1 == pub_r000267_13_2);
  __CPROVER_assume(sec_r000267_1_1 != sec_r000267_1_2);
  __CPROVER_assume(sec_r000267_8_1 != sec_r000267_8_2);
  __CPROVER_assume(sec_r000267_0_1 != sec_r000267_0_2);
  __CPROVER_assume(pub_r000267_2_1 == pub_r000267_2_2);
  __CPROVER_assume(pub_r000267_4_1 == pub_r000267_4_2);
  __CPROVER_assume(pub_r000267_8_1 == pub_r000267_8_2);
  __CPROVER_assume(sec_r000267_15_1 != sec_r000267_15_2);
  __CPROVER_assume(pub_r000267_17_1 == pub_r000267_17_2);
  __CPROVER_assume(sec_r000267_4_1 != sec_r000267_4_2);
  __CPROVER_assume(pub_r000267_12_1 == pub_r000267_12_2);
  __CPROVER_assume(pub_r000267_7_1 == pub_r000267_7_2);
  __CPROVER_assume(sec_r000267_3_1 != sec_r000267_3_2);
  __CPROVER_assume(pub_r000267_3_1 == pub_r000267_3_2);
  __CPROVER_assume(sec_r000267_2_1 != sec_r000267_2_2);
  __CPROVER_assume(pub_r000267_0_1 == pub_r000267_0_2);
  __CPROVER_assume(sec_r000267_5_1 != sec_r000267_5_2);
  __CPROVER_assume(sec_r000267_10_1 != sec_r000267_10_2);
  __CPROVER_assume(pub_r000267_16_1 == pub_r000267_16_2);
  __CPROVER_assume(sec_r000267_7_1 != sec_r000267_7_2);
  __CPROVER_assume(sec_r000267_14_1 != sec_r000267_14_2);
  __CPROVER_assume(sec_r000267_13_1 != sec_r000267_13_2);
  __CPROVER_assume(pub_r000267_15_1 == pub_r000267_15_2);
  __CPROVER_assume(sec_r000267_6_1 != sec_r000267_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.id == st_var_1_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.damping == st_var_3_2.damping);
  assert(st_var_3_1.mode == st_var_3_2.mode);
  assert(st_var_3_1.prev_out == st_var_3_2.prev_out);
  assert(st_var_3_1.gain_db == st_var_3_2.gain_db);
  assert(st_var_3_1.cutoff == st_var_3_2.cutoff);
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
  assert(m_step_0_1 == m_step_0_2);
  assert(m_step_1_1 == m_step_1_2);
  assert(m_step_2_1 == m_step_2_2);
}


