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
struct AudioFrame_R000617_1713_0
{
  int envelope;
  short rms;
  int sample_rate;
  int buffer[3];
};
struct MatrixBlock_R000617_1713_1
{
  int dim;
  int scale;
  int determinant;
  int stride;
  short density;
  int buffer[3];
};
struct SensorNode_R000617_1713_2
{
  int status;
  unsigned char offset;
  short threshold;
  short gain;
  int buffer[3];
};
union PacketPayload_R000617_1713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000617_1713_1
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
void fn_R000617_1713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st_1 = {0};
  struct SensorNode_R000617_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int vector_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_99_1) & 63;
  aux_2 = (aux_2 + vector_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_80_1 = local_arr_1[aux_1 % 3];
  int mask_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_80_2 * 2)) & 127;
  int segment_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_93_1)
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

  switch (segment_93_2)
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

  int factor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_68_1 > 21)
  {
    acc_1 = ((acc_1 + (factor_68_1 * 2)) + 5) & 127;
    aux_1 ^= factor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_68_2 > 21)
  {
    acc_2 = ((acc_2 + (factor_68_2 * 2)) + 5) & 127;
    aux_2 ^= factor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_99_1 == vector_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_80_1 == mask_80_2);
  assert(segment_93_1 == segment_93_2);
  assert(factor_68_1 == factor_68_2);
}

int fn_R000617_1713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int vector_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_99) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_80 = local_arr[aux % 3];
  acc = (acc + (mask_80 * 2)) & 127;
  int segment_93 = (aux + st.buffer[1]) & 3;
  switch (segment_93)
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

  int factor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_68 > 21)
  {
    acc = ((acc + (factor_68 * 2)) + 5) & 127;
    aux ^= factor_68 & 15;
  }
  else
  {
    acc = ((acc - factor_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000617_1713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st_1 = {0};
  struct AudioFrame_R000617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quantum_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_42_1) & 63;
  aux_2 = (aux_2 + quantum_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_53_1 > 31)
  {
    acc_1 = ((acc_1 + (segment_53_1 * 2)) + 5) & 127;
    aux_1 ^= segment_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_53_2 > 31)
  {
    acc_2 = ((acc_2 + (segment_53_2 * 2)) + 5) & 127;
    aux_2 ^= segment_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_42_1 == quantum_42_2);
  assert(segment_53_1 == segment_53_2);
}

int fn_R000617_1713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quantum_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_42) & 63;
  acc ^= aux;
  int segment_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_53 > 31)
  {
    acc = ((acc + (segment_53 * 2)) + 5) & 127;
    aux ^= segment_53 & 15;
  }
  else
  {
    acc = ((acc - segment_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000617_1713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st_1 = {0};
  struct AudioFrame_R000617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tally_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_22_1 > 43)
  {
    acc_1 = ((acc_1 + (tally_22_1 * 2)) + 5) & 127;
    aux_1 ^= tally_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_22_2 > 43)
  {
    acc_2 = ((acc_2 + (tally_22_2 * 2)) + 5) & 127;
    aux_2 ^= tally_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_22_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_22_1 == tally_22_2);
}

int fn_R000617_1713_2(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tally_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_22 > 43)
  {
    acc = ((acc + (tally_22 * 2)) + 5) & 127;
    aux ^= tally_22 & 15;
  }
  else
  {
    acc = ((acc - tally_22) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000617_1713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st_1 = {0};
  struct MatrixBlock_R000617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_79_1) & 63;
  aux_2 = (aux_2 + mask_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_29_1 = local_arr_1[aux_1 % 3];
  int tracker_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_29_2 * 2)) & 127;
  int tally_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_68_1 > 46)
  {
    acc_1 = ((acc_1 + (tally_68_1 * 2)) + 5) & 127;
    aux_1 ^= tally_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_68_2 > 46)
  {
    acc_2 = ((acc_2 + (tally_68_2 * 2)) + 5) & 127;
    aux_2 ^= tally_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_79_1 == mask_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_29_1 == tracker_29_2);
  assert(tally_68_1 == tally_68_2);
}

int fn_R000617_1713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_79) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_29 = local_arr[aux % 3];
  acc = (acc + (tracker_29 * 2)) & 127;
  int tally_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_68 > 46)
  {
    acc = ((acc + (tally_68 * 2)) + 5) & 127;
    aux ^= tally_68 & 15;
  }
  else
  {
    acc = ((acc - tally_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000617_1713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st_1 = {0};
  struct AudioFrame_R000617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_35_1 = local_arr_1[aux_1 % 3];
  int segment_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_35_2 * 2)) & 127;
  int residue_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_16_1 > 20)
  {
    acc_1 = ((acc_1 + (residue_16_1 * 2)) + 5) & 127;
    aux_1 ^= residue_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_16_2 > 20)
  {
    acc_2 = ((acc_2 + (residue_16_2 * 2)) + 5) & 127;
    aux_2 ^= residue_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_35_1 == segment_35_2);
  assert(residue_16_1 == residue_16_2);
}

int fn_R000617_1713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int segment_35 = local_arr[aux % 3];
  acc = (acc + (segment_35 * 2)) & 127;
  int residue_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_16 > 20)
  {
    acc = ((acc + (residue_16 * 2)) + 5) & 127;
    aux ^= residue_16 & 15;
  }
  else
  {
    acc = ((acc - residue_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000617_1713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st_1 = {0};
  struct MatrixBlock_R000617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_81_1 = local_arr_1[aux_1 % 3];
  int stride_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_81_1 == stride_81_2);
}

int fn_R000617_1713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int stride_81 = local_arr[aux % 3];
  acc = (acc + (stride_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000617_1713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st_1 = {0};
  struct SensorNode_R000617_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_36_1 > 38)
  {
    acc_1 = ((acc_1 + (delta_36_1 * 2)) + 5) & 127;
    aux_1 ^= delta_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_36_2 > 38)
  {
    acc_2 = ((acc_2 + (delta_36_2 * 2)) + 5) & 127;
    aux_2 ^= delta_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_33_1 = local_arr_1[aux_1 % 3];
  int anchor_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_36_1 == delta_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_33_1 == anchor_33_2);
}

int fn_R000617_1713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_36 > 38)
  {
    acc = ((acc + (delta_36 * 2)) + 5) & 127;
    aux ^= delta_36 & 15;
  }
  else
  {
    acc = ((acc - delta_36) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_33 = local_arr[aux % 3];
  acc = (acc + (anchor_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000617_1713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st_1 = {0};
  struct MatrixBlock_R000617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int threshold_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_96_1)
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

  switch (threshold_96_2)
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

  int pivot_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_76_1) & 63;
  aux_2 = (aux_2 + pivot_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_39_1 > 18)
  {
    acc_1 = ((acc_1 + (residue_39_1 * 2)) + 5) & 127;
    aux_1 ^= residue_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_39_2 > 18)
  {
    acc_2 = ((acc_2 + (residue_39_2 * 2)) + 5) & 127;
    aux_2 ^= residue_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_96_1 == threshold_96_2);
  assert(pivot_76_1 == pivot_76_2);
  assert(residue_39_1 == residue_39_2);
}

int fn_R000617_1713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int threshold_96 = (aux + st.buffer[1]) & 3;
  switch (threshold_96)
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

  int pivot_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_76) & 63;
  acc ^= aux;
  int residue_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_39 > 18)
  {
    acc = ((acc + (residue_39 * 2)) + 5) & 127;
    aux ^= residue_39 & 15;
  }
  else
  {
    acc = ((acc - residue_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000617_1713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st_1 = {0};
  struct AudioFrame_R000617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_25_1 = local_arr_1[aux_1 % 3];
  int threshold_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_25_2 * 2)) & 127;
  int residue_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_14_1) & 63;
  aux_2 = (aux_2 + residue_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_85_1)
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

  switch (window_85_2)
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

  int damping_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_69_1 > 29)
  {
    acc_1 = ((acc_1 + (damping_69_1 * 2)) + 5) & 127;
    aux_1 ^= damping_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_69_2 > 29)
  {
    acc_2 = ((acc_2 + (damping_69_2 * 2)) + 5) & 127;
    aux_2 ^= damping_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_25_1 == threshold_25_2);
  assert(residue_14_1 == residue_14_2);
  assert(window_85_1 == window_85_2);
  assert(damping_69_1 == damping_69_2);
}

int fn_R000617_1713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int threshold_25 = local_arr[aux % 3];
  acc = (acc + (threshold_25 * 2)) & 127;
  int residue_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_14) & 63;
  acc ^= aux;
  int window_85 = (aux + st.buffer[1]) & 3;
  switch (window_85)
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

  int damping_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_69 > 29)
  {
    acc = ((acc + (damping_69 * 2)) + 5) & 127;
    aux ^= damping_69 & 15;
  }
  else
  {
    acc = ((acc - damping_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000617_1713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st_1 = {0};
  struct MatrixBlock_R000617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int delta_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_51_1)
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

  switch (delta_51_2)
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

  int parity_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_51_1 > 25)
  {
    acc_1 = ((acc_1 + (parity_51_1 * 2)) + 5) & 127;
    aux_1 ^= parity_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_51_2 > 25)
  {
    acc_2 = ((acc_2 + (parity_51_2 * 2)) + 5) & 127;
    aux_2 ^= parity_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_12_1) & 63;
  aux_2 = (aux_2 + threshold_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_51_1 == delta_51_2);
  assert(parity_51_1 == parity_51_2);
  assert(threshold_12_1 == threshold_12_2);
}

int fn_R000617_1713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int delta_51 = (aux + st.buffer[1]) & 3;
  switch (delta_51)
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

  int parity_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_51 > 25)
  {
    acc = ((acc + (parity_51 * 2)) + 5) & 127;
    aux ^= parity_51 & 15;
  }
  else
  {
    acc = ((acc - parity_51) + 11) & 127;
    aux += 3;
  }
  int threshold_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000617_1713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st_1 = {0};
  struct SensorNode_R000617_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int anchor_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_29_1) & 63;
  aux_2 = (aux_2 + anchor_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_73_1 > 25)
  {
    acc_1 = ((acc_1 + (accumulator_73_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_73_2 > 25)
  {
    acc_2 = ((acc_2 + (accumulator_73_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_29_1 == anchor_29_2);
  assert(accumulator_73_1 == accumulator_73_2);
}

int fn_R000617_1713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int anchor_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_29) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_73 > 25)
  {
    acc = ((acc + (accumulator_73 * 2)) + 5) & 127;
    aux ^= accumulator_73 & 15;
  }
  else
  {
    acc = ((acc - accumulator_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000617_1713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st_1 = {0};
  struct MatrixBlock_R000617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_34_1 > 23)
  {
    acc_1 = ((acc_1 + (delta_34_1 * 2)) + 5) & 127;
    aux_1 ^= delta_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_34_2 > 23)
  {
    acc_2 = ((acc_2 + (delta_34_2 * 2)) + 5) & 127;
    aux_2 ^= delta_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_60_1)
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

  switch (checksum_60_2)
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

  int quantum_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_57_1) & 63;
  aux_2 = (aux_2 + quantum_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_34_1 == delta_34_2);
  assert(checksum_60_1 == checksum_60_2);
  assert(quantum_57_1 == quantum_57_2);
}

int fn_R000617_1713_11(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_34 > 23)
  {
    acc = ((acc + (delta_34 * 2)) + 5) & 127;
    aux ^= delta_34 & 15;
  }
  else
  {
    acc = ((acc - delta_34) + 11) & 127;
    aux += 3;
  }
  int checksum_60 = (aux + st.buffer[1]) & 3;
  switch (checksum_60)
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

  int quantum_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000617_1713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st_1 = {0};
  struct AudioFrame_R000617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int bound_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_16_1 > 28)
  {
    acc_1 = ((acc_1 + (bound_16_1 * 2)) + 5) & 127;
    aux_1 ^= bound_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_16_2 > 28)
  {
    acc_2 = ((acc_2 + (bound_16_2 * 2)) + 5) & 127;
    aux_2 ^= bound_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_33_1 = local_arr_1[aux_1 % 3];
  int quotient_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_16_1 == bound_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_33_1 == quotient_33_2);
}

int fn_R000617_1713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int bound_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_16 > 28)
  {
    acc = ((acc + (bound_16 * 2)) + 5) & 127;
    aux ^= bound_16 & 15;
  }
  else
  {
    acc = ((acc - bound_16) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_33 = local_arr[aux % 3];
  acc = (acc + (quotient_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000617_1713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st_1 = {0};
  struct SensorNode_R000617_1713_2 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_83_1 = local_arr_1[aux_1 % 3];
  int threshold_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_83_2 * 2)) & 127;
  int threshold_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_66_1 > 27)
  {
    acc_1 = ((acc_1 + (threshold_66_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_66_2 > 27)
  {
    acc_2 = ((acc_2 + (threshold_66_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_83_1 == threshold_83_2);
  assert(threshold_66_1 == threshold_66_2);
}

int fn_R000617_1713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_83 = local_arr[aux % 3];
  acc = (acc + (threshold_83 * 2)) & 127;
  int threshold_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_66 > 27)
  {
    acc = ((acc + (threshold_66 * 2)) + 5) & 127;
    aux ^= threshold_66 & 15;
  }
  else
  {
    acc = ((acc - threshold_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000617_1713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st_1 = {0};
  struct SensorNode_R000617_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_45_1 = local_arr_1[aux_1 % 3];
  int residue_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_45_2 * 2)) & 127;
  int weight_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_91_1 > 30)
  {
    acc_1 = ((acc_1 + (weight_91_1 * 2)) + 5) & 127;
    aux_1 ^= weight_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_91_2 > 30)
  {
    acc_2 = ((acc_2 + (weight_91_2 * 2)) + 5) & 127;
    aux_2 ^= weight_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_91_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_45_1 == residue_45_2);
  assert(weight_91_1 == weight_91_2);
}

int fn_R000617_1713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int residue_45 = local_arr[aux % 3];
  acc = (acc + (residue_45 * 2)) & 127;
  int weight_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_91 > 30)
  {
    acc = ((acc + (weight_91 * 2)) + 5) & 127;
    aux ^= weight_91 & 15;
  }
  else
  {
    acc = ((acc - weight_91) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000617_1713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st_1 = {0};
  struct MatrixBlock_R000617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int quantum_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_49_1)
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

  switch (quantum_49_2)
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

  int accumulator_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_62_1 > 11)
  {
    acc_1 = ((acc_1 + (accumulator_62_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_62_2 > 11)
  {
    acc_2 = ((acc_2 + (accumulator_62_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_50_1) & 63;
  aux_2 = (aux_2 + pivot_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_94_1 = local_arr_1[aux_1 % 3];
  int margin_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_94_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_49_1 == quantum_49_2);
  assert(accumulator_62_1 == accumulator_62_2);
  assert(pivot_50_1 == pivot_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_94_1 == margin_94_2);
}

int fn_R000617_1713_15(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int quantum_49 = (aux + st.buffer[1]) & 3;
  switch (quantum_49)
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

  int accumulator_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_62 > 11)
  {
    acc = ((acc + (accumulator_62 * 2)) + 5) & 127;
    aux ^= accumulator_62 & 15;
  }
  else
  {
    acc = ((acc - accumulator_62) + 11) & 127;
    aux += 3;
  }
  int pivot_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_50) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_94 = local_arr[aux % 3];
  acc = (acc + (margin_94 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000617_1713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st_1 = {0};
  struct SensorNode_R000617_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int damping_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_40_1 > 26)
  {
    acc_1 = ((acc_1 + (damping_40_1 * 2)) + 5) & 127;
    aux_1 ^= damping_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_40_2 > 26)
  {
    acc_2 = ((acc_2 + (damping_40_2 * 2)) + 5) & 127;
    aux_2 ^= damping_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_40_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_99_1 = local_arr_1[aux_1 % 3];
  int metric_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_99_2 * 2)) & 127;
  int accumulator_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_78_1) & 63;
  aux_2 = (aux_2 + accumulator_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_40_1 == damping_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_99_1 == metric_99_2);
  assert(accumulator_78_1 == accumulator_78_2);
}

int fn_R000617_1713_16(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int damping_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_40 > 26)
  {
    acc = ((acc + (damping_40 * 2)) + 5) & 127;
    aux ^= damping_40 & 15;
  }
  else
  {
    acc = ((acc - damping_40) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_99 = local_arr[aux % 3];
  acc = (acc + (metric_99 * 2)) & 127;
  int accumulator_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000617_1713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st_1 = {0};
  struct MatrixBlock_R000617_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_52_1) & 63;
  aux_2 = (aux_2 + bound_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_10_1)
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

  switch (quotient_10_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_52_1 == bound_52_2);
  assert(quotient_10_1 == quotient_10_2);
}

int fn_R000617_1713_17(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000617_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_52) & 63;
  acc ^= aux;
  int quotient_10 = (aux + st.buffer[1]) & 3;
  switch (quotient_10)
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

void fn_R000617_1713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st_1 = {0};
  struct SensorNode_R000617_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_20_1 = local_arr_1[aux_1 % 3];
  int threshold_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_20_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_80_1)
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

  switch (pivot_80_2)
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

  int cursor_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_93_1 > 43)
  {
    acc_1 = ((acc_1 + (cursor_93_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_93_2 > 43)
  {
    acc_2 = ((acc_2 + (cursor_93_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_20_1 == threshold_20_2);
  assert(pivot_80_1 == pivot_80_2);
  assert(cursor_93_1 == cursor_93_2);
}

int fn_R000617_1713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int threshold_20 = local_arr[aux % 3];
  acc = (acc + (threshold_20 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_80 = (aux + st.buffer[1]) & 3;
  switch (pivot_80)
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

  int cursor_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_93 > 43)
  {
    acc = ((acc + (cursor_93 * 2)) + 5) & 127;
    aux ^= cursor_93 & 15;
  }
  else
  {
    acc = ((acc - cursor_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000617_1713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st_1 = {0};
  struct SensorNode_R000617_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_49_1) & 63;
  aux_2 = (aux_2 + threshold_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_68_1 = local_arr_1[aux_1 % 3];
  int bound_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_49_1 == threshold_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_68_1 == bound_68_2);
}

int fn_R000617_1713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000617_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_49) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_68 = local_arr[aux % 3];
  acc = (acc + (bound_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000617_1713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st_1 = {0};
  struct AudioFrame_R000617_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_94_1) & 63;
  aux_2 = (aux_2 + offset_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_42_1)
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

  switch (factor_42_2)
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
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_94_1 == offset_94_2);
  assert(factor_42_1 == factor_42_2);
}

int fn_R000617_1713_20(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000617_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_94) & 63;
  acc ^= aux;
  int factor_42 = (aux + st.buffer[1]) & 3;
  switch (factor_42)
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

void main()
{
  int sec_r000617_0_1;
  int sec_r000617_0_2;
  int sec_r000617_1_1;
  int sec_r000617_1_2;
  int sec_r000617_2_1;
  int sec_r000617_2_2;
  int sec_r000617_3_1;
  int sec_r000617_3_2;
  int sec_r000617_4_1;
  int sec_r000617_4_2;
  int sec_r000617_5_1;
  int sec_r000617_5_2;
  int sec_r000617_6_1;
  int sec_r000617_6_2;
  int sec_r000617_7_1;
  int sec_r000617_7_2;
  int sec_r000617_8_1;
  int sec_r000617_8_2;
  int sec_r000617_9_1;
  int sec_r000617_9_2;
  int sec_r000617_10_1;
  int sec_r000617_10_2;
  int sec_r000617_11_1;
  int sec_r000617_11_2;
  int sec_r000617_12_1;
  int sec_r000617_12_2;
  int sec_r000617_13_1;
  int sec_r000617_13_2;
  int sec_r000617_14_1;
  int sec_r000617_14_2;
  int sec_r000617_15_1;
  int sec_r000617_15_2;
  int sec_r000617_16_1;
  int sec_r000617_16_2;
  int sec_r000617_17_1;
  int sec_r000617_17_2;
  int sec_r000617_18_1;
  int sec_r000617_18_2;
  int sec_r000617_19_1;
  int sec_r000617_19_2;
  int sec_r000617_20_1;
  int sec_r000617_20_2;
  int pub_r000617_0_1;
  int pub_r000617_0_2;
  int pub_r000617_1_1;
  int pub_r000617_1_2;
  int pub_r000617_2_1;
  int pub_r000617_2_2;
  int pub_r000617_3_1;
  int pub_r000617_3_2;
  int pub_r000617_4_1;
  int pub_r000617_4_2;
  int pub_r000617_5_1;
  int pub_r000617_5_2;
  int pub_r000617_6_1;
  int pub_r000617_6_2;
  int pub_r000617_7_1;
  int pub_r000617_7_2;
  int pub_r000617_8_1;
  int pub_r000617_8_2;
  int pub_r000617_9_1;
  int pub_r000617_9_2;
  int pub_r000617_10_1;
  int pub_r000617_10_2;
  int pub_r000617_11_1;
  int pub_r000617_11_2;
  int pub_r000617_12_1;
  int pub_r000617_12_2;
  int pub_r000617_13_1;
  int pub_r000617_13_2;
  int pub_r000617_14_1;
  int pub_r000617_14_2;
  int pub_r000617_15_1;
  int pub_r000617_15_2;
  int pub_r000617_16_1;
  int pub_r000617_16_2;
  int pub_r000617_17_1;
  int pub_r000617_17_2;
  int pub_r000617_18_1;
  int pub_r000617_18_2;
  int pub_r000617_19_1;
  int pub_r000617_19_2;
  int pub_r000617_20_1;
  int pub_r000617_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000617_0_1 >= (-100)) && (pub_r000617_0_1 <= 100));
  __CPROVER_assume((pub_r000617_0_2 >= (-100)) && (pub_r000617_0_2 <= 100));
  __CPROVER_assume((pub_r000617_1_1 >= (-100)) && (pub_r000617_1_1 <= 100));
  __CPROVER_assume((pub_r000617_1_2 >= (-100)) && (pub_r000617_1_2 <= 100));
  __CPROVER_assume((pub_r000617_2_1 >= (-100)) && (pub_r000617_2_1 <= 100));
  __CPROVER_assume((pub_r000617_2_2 >= (-100)) && (pub_r000617_2_2 <= 100));
  __CPROVER_assume((pub_r000617_3_1 >= (-100)) && (pub_r000617_3_1 <= 100));
  __CPROVER_assume((pub_r000617_3_2 >= (-100)) && (pub_r000617_3_2 <= 100));
  __CPROVER_assume((pub_r000617_4_1 >= (-100)) && (pub_r000617_4_1 <= 100));
  __CPROVER_assume((pub_r000617_4_2 >= (-100)) && (pub_r000617_4_2 <= 100));
  __CPROVER_assume((pub_r000617_5_1 >= (-100)) && (pub_r000617_5_1 <= 100));
  __CPROVER_assume((pub_r000617_5_2 >= (-100)) && (pub_r000617_5_2 <= 100));
  __CPROVER_assume((pub_r000617_6_1 >= (-100)) && (pub_r000617_6_1 <= 100));
  __CPROVER_assume((pub_r000617_6_2 >= (-100)) && (pub_r000617_6_2 <= 100));
  __CPROVER_assume((pub_r000617_7_1 >= (-100)) && (pub_r000617_7_1 <= 100));
  __CPROVER_assume((pub_r000617_7_2 >= (-100)) && (pub_r000617_7_2 <= 100));
  __CPROVER_assume((pub_r000617_8_1 >= (-100)) && (pub_r000617_8_1 <= 100));
  __CPROVER_assume((pub_r000617_8_2 >= (-100)) && (pub_r000617_8_2 <= 100));
  __CPROVER_assume((pub_r000617_9_1 >= (-100)) && (pub_r000617_9_1 <= 100));
  __CPROVER_assume((pub_r000617_9_2 >= (-100)) && (pub_r000617_9_2 <= 100));
  __CPROVER_assume((pub_r000617_10_1 >= (-100)) && (pub_r000617_10_1 <= 100));
  __CPROVER_assume((pub_r000617_10_2 >= (-100)) && (pub_r000617_10_2 <= 100));
  __CPROVER_assume((pub_r000617_11_1 >= (-100)) && (pub_r000617_11_1 <= 100));
  __CPROVER_assume((pub_r000617_11_2 >= (-100)) && (pub_r000617_11_2 <= 100));
  __CPROVER_assume((pub_r000617_12_1 >= (-100)) && (pub_r000617_12_1 <= 100));
  __CPROVER_assume((pub_r000617_12_2 >= (-100)) && (pub_r000617_12_2 <= 100));
  __CPROVER_assume((pub_r000617_13_1 >= (-100)) && (pub_r000617_13_1 <= 100));
  __CPROVER_assume((pub_r000617_13_2 >= (-100)) && (pub_r000617_13_2 <= 100));
  __CPROVER_assume((pub_r000617_14_1 >= (-100)) && (pub_r000617_14_1 <= 100));
  __CPROVER_assume((pub_r000617_14_2 >= (-100)) && (pub_r000617_14_2 <= 100));
  __CPROVER_assume((pub_r000617_15_1 >= (-100)) && (pub_r000617_15_1 <= 100));
  __CPROVER_assume((pub_r000617_15_2 >= (-100)) && (pub_r000617_15_2 <= 100));
  __CPROVER_assume((pub_r000617_16_1 >= (-100)) && (pub_r000617_16_1 <= 100));
  __CPROVER_assume((pub_r000617_16_2 >= (-100)) && (pub_r000617_16_2 <= 100));
  __CPROVER_assume((pub_r000617_17_1 >= (-100)) && (pub_r000617_17_1 <= 100));
  __CPROVER_assume((pub_r000617_17_2 >= (-100)) && (pub_r000617_17_2 <= 100));
  __CPROVER_assume((pub_r000617_18_1 >= (-100)) && (pub_r000617_18_1 <= 100));
  __CPROVER_assume((pub_r000617_18_2 >= (-100)) && (pub_r000617_18_2 <= 100));
  __CPROVER_assume((pub_r000617_19_1 >= (-100)) && (pub_r000617_19_1 <= 100));
  __CPROVER_assume((pub_r000617_19_2 >= (-100)) && (pub_r000617_19_2 <= 100));
  __CPROVER_assume((pub_r000617_20_1 >= (-100)) && (pub_r000617_20_1 <= 100));
  __CPROVER_assume((pub_r000617_20_2 >= (-100)) && (pub_r000617_20_2 <= 100));
  __CPROVER_assume((sec_r000617_0_1 >= 0) && (sec_r000617_0_1 <= 255));
  __CPROVER_assume((sec_r000617_0_2 >= 0) && (sec_r000617_0_2 <= 255));
  __CPROVER_assume((sec_r000617_1_1 >= 0) && (sec_r000617_1_1 <= 255));
  __CPROVER_assume((sec_r000617_1_2 >= 0) && (sec_r000617_1_2 <= 255));
  __CPROVER_assume((sec_r000617_2_1 >= 0) && (sec_r000617_2_1 <= 255));
  __CPROVER_assume((sec_r000617_2_2 >= 0) && (sec_r000617_2_2 <= 255));
  __CPROVER_assume((sec_r000617_3_1 >= 0) && (sec_r000617_3_1 <= 255));
  __CPROVER_assume((sec_r000617_3_2 >= 0) && (sec_r000617_3_2 <= 255));
  __CPROVER_assume((sec_r000617_4_1 >= 0) && (sec_r000617_4_1 <= 255));
  __CPROVER_assume((sec_r000617_4_2 >= 0) && (sec_r000617_4_2 <= 255));
  __CPROVER_assume((sec_r000617_5_1 >= 0) && (sec_r000617_5_1 <= 255));
  __CPROVER_assume((sec_r000617_5_2 >= 0) && (sec_r000617_5_2 <= 255));
  __CPROVER_assume((sec_r000617_6_1 >= 0) && (sec_r000617_6_1 <= 255));
  __CPROVER_assume((sec_r000617_6_2 >= 0) && (sec_r000617_6_2 <= 255));
  __CPROVER_assume((sec_r000617_7_1 >= 0) && (sec_r000617_7_1 <= 255));
  __CPROVER_assume((sec_r000617_7_2 >= 0) && (sec_r000617_7_2 <= 255));
  __CPROVER_assume((sec_r000617_8_1 >= 0) && (sec_r000617_8_1 <= 255));
  __CPROVER_assume((sec_r000617_8_2 >= 0) && (sec_r000617_8_2 <= 255));
  __CPROVER_assume((sec_r000617_9_1 >= 0) && (sec_r000617_9_1 <= 255));
  __CPROVER_assume((sec_r000617_9_2 >= 0) && (sec_r000617_9_2 <= 255));
  __CPROVER_assume((sec_r000617_10_1 >= 0) && (sec_r000617_10_1 <= 255));
  __CPROVER_assume((sec_r000617_10_2 >= 0) && (sec_r000617_10_2 <= 255));
  __CPROVER_assume((sec_r000617_11_1 >= 0) && (sec_r000617_11_1 <= 255));
  __CPROVER_assume((sec_r000617_11_2 >= 0) && (sec_r000617_11_2 <= 255));
  __CPROVER_assume((sec_r000617_12_1 >= 0) && (sec_r000617_12_1 <= 255));
  __CPROVER_assume((sec_r000617_12_2 >= 0) && (sec_r000617_12_2 <= 255));
  __CPROVER_assume((sec_r000617_13_1 >= 0) && (sec_r000617_13_1 <= 255));
  __CPROVER_assume((sec_r000617_13_2 >= 0) && (sec_r000617_13_2 <= 255));
  __CPROVER_assume((sec_r000617_14_1 >= 0) && (sec_r000617_14_1 <= 255));
  __CPROVER_assume((sec_r000617_14_2 >= 0) && (sec_r000617_14_2 <= 255));
  __CPROVER_assume((sec_r000617_15_1 >= 0) && (sec_r000617_15_1 <= 255));
  __CPROVER_assume((sec_r000617_15_2 >= 0) && (sec_r000617_15_2 <= 255));
  __CPROVER_assume((sec_r000617_16_1 >= 0) && (sec_r000617_16_1 <= 255));
  __CPROVER_assume((sec_r000617_16_2 >= 0) && (sec_r000617_16_2 <= 255));
  __CPROVER_assume((sec_r000617_17_1 >= 0) && (sec_r000617_17_1 <= 255));
  __CPROVER_assume((sec_r000617_17_2 >= 0) && (sec_r000617_17_2 <= 255));
  __CPROVER_assume((sec_r000617_18_1 >= 0) && (sec_r000617_18_1 <= 255));
  __CPROVER_assume((sec_r000617_18_2 >= 0) && (sec_r000617_18_2 <= 255));
  __CPROVER_assume((sec_r000617_19_1 >= 0) && (sec_r000617_19_1 <= 255));
  __CPROVER_assume((sec_r000617_19_2 >= 0) && (sec_r000617_19_2 <= 255));
  __CPROVER_assume((sec_r000617_20_1 >= 0) && (sec_r000617_20_1 <= 255));
  __CPROVER_assume((sec_r000617_20_2 >= 0) && (sec_r000617_20_2 <= 255));
  struct AudioFrame_R000617_1713_0 st_var_0_1 = {0};
  struct AudioFrame_R000617_1713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000617_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000617_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000617_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000617_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000617_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000617_0_2 + 7) & 15;
  struct MatrixBlock_R000617_1713_1 st_var_1_1 = {0};
  struct MatrixBlock_R000617_1713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000617_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000617_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000617_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000617_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000617_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000617_0_2 + 9) & 15;
  struct SensorNode_R000617_1713_2 st_var_2_1 = {0};
  struct SensorNode_R000617_1713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000617_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000617_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000617_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000617_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000617_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000617_0_2 + 11) & 15;
  union PacketPayload_R000617_1713_0 u_var_1;
  union PacketPayload_R000617_1713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 32)
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
  if (stage_v_2_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 32)
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
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 9) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 12) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 37)
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
  if (stage_v_13_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 37)
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
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
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
  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 43)
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
  if (stage_v_18_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 43)
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
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (st_var_1_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_1_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 48)
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
  if (stage_v_25_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 48)
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
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = (st_var_0_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_0_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = ((st_var_1_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_1_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 28)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 28)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
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
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = ((st_var_0_1.buffer[0] * 2) + 106) & 63;
  int stage_v_33_2 = ((st_var_0_2.buffer[0] * 2) + 106) & 63;
  if (stage_v_33_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_33_1) - 5) & 255;
    if (stage_v_33_1 > 26)
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
  if (stage_v_33_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_33_2) - 5) & 255;
    if (stage_v_33_2 > 26)
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
  int stage_v_34_1 = ((st_var_1_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_1_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 30)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 30)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 25)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 25)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 41) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = ((st_var_1_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_1_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 38)
    {
      chk_sum_1 ^= stage_v_43_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_43_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 38)
    {
      chk_sum_2 ^= stage_v_43_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
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
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000617_11_1 & 1) != 0)
  {
    if ((sec_r000617_2_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000617_8_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000617_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000617_8_1 + 7) & 127;
  }
  if ((sec_r000617_11_2 & 1) != 0)
  {
    if ((sec_r000617_2_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000617_8_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000617_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000617_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000617_15_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000617_9_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000617_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000617_9_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000617_15_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000617_9_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000617_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000617_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000617_8_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000617_1_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000617_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000617_1_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000617_8_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000617_1_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000617_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000617_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000617_12_1 & 1) != 0)
  {
    if ((sec_r000617_7_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000617_18_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000617_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000617_18_1 + 7) & 127;
  }
  if ((sec_r000617_12_2 & 1) != 0)
  {
    if ((sec_r000617_7_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000617_18_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000617_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000617_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000617_19_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000617_7_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000617_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000617_7_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000617_19_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000617_7_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000617_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000617_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000617_11_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000617_11_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000617_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000617_11_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000617_11_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000617_11_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000617_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000617_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((sec_r000617_15_1 & 1) != 0)
  {
    if ((sec_r000617_16_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000617_18_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000617_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000617_18_1 + 7) & 127;
  }
  if ((sec_r000617_15_2 & 1) != 0)
  {
    if ((sec_r000617_16_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000617_18_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000617_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000617_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000617_15_1 & 1) != 0)
  {
    if ((sec_r000617_15_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000617_13_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000617_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000617_13_1 + 7) & 127;
  }
  if ((sec_r000617_15_2 & 1) != 0)
  {
    if ((sec_r000617_15_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000617_13_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000617_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000617_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000617_4_1 & 1) != 0)
  {
    if ((sec_r000617_20_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000617_13_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000617_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000617_13_1 + 7) & 127;
  }
  if ((sec_r000617_4_2 & 1) != 0)
  {
    if ((sec_r000617_20_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000617_13_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000617_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000617_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000617_0_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000617_6_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000617_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000617_6_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000617_0_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000617_6_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000617_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000617_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000617_19_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000617_6_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000617_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000617_6_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000617_19_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000617_6_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000617_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000617_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000617_3_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000617_11_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000617_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000617_11_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000617_3_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000617_11_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000617_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000617_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000617_14_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000617_2_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000617_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000617_2_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000617_14_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000617_2_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000617_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000617_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000617_17_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000617_19_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000617_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000617_19_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000617_17_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000617_19_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000617_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000617_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000617_1_1 & 1) != 0)
  {
    if ((sec_r000617_14_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000617_13_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000617_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000617_13_1 + 7) & 127;
  }
  if ((sec_r000617_1_2 & 1) != 0)
  {
    if ((sec_r000617_14_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000617_13_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000617_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000617_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000617_14_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000617_15_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000617_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000617_15_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000617_14_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000617_15_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000617_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000617_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((sec_r000617_17_1 & 1) != 0)
  {
    if ((sec_r000617_10_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000617_15_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000617_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000617_15_1 + 7) & 127;
  }
  if ((sec_r000617_17_2 & 1) != 0)
  {
    if ((sec_r000617_10_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000617_15_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000617_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000617_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000617_1_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000617_11_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000617_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000617_11_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000617_1_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000617_11_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000617_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000617_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000617_9_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000617_18_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000617_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000617_18_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000617_9_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000617_18_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000617_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000617_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000617_16_1 & 1) != 0)
  {
    if ((sec_r000617_7_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000617_11_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000617_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000617_11_1 + 7) & 127;
  }
  if ((sec_r000617_16_2 & 1) != 0)
  {
    if ((sec_r000617_7_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000617_11_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000617_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000617_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000617_13_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000617_10_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000617_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000617_10_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000617_13_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000617_10_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000617_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000617_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000617_18_1 & 1) != 0)
  {
    if ((sec_r000617_11_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000617_6_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000617_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000617_6_1 + 7) & 127;
  }
  if ((sec_r000617_18_2 & 1) != 0)
  {
    if ((sec_r000617_11_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000617_6_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000617_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000617_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000617_12_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000617_3_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000617_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000617_3_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000617_12_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000617_3_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000617_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000617_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000617_1_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000617_12_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000617_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000617_12_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000617_1_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000617_12_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000617_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000617_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000617_0_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000617_16_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000617_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000617_16_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000617_0_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000617_16_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000617_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000617_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000617_14_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000617_12_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000617_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000617_12_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000617_14_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000617_12_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000617_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000617_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000617_18_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000617_20_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000617_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000617_20_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000617_18_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000617_20_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000617_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000617_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000617_8_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000617_12_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000617_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000617_12_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000617_8_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000617_12_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000617_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000617_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000617_1_1 & 1) != 0)
  {
    if ((sec_r000617_20_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000617_7_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000617_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000617_7_1 + 7) & 127;
  }
  if ((sec_r000617_1_2 & 1) != 0)
  {
    if ((sec_r000617_20_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000617_7_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000617_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000617_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000617_18_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000617_18_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000617_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000617_18_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000617_18_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000617_18_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000617_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000617_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000617_5_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000617_17_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000617_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000617_17_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000617_5_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000617_17_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000617_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000617_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000617_6_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000617_11_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000617_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000617_11_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000617_6_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000617_11_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000617_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000617_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000617_2_1 & 1) != 0)
  {
    if ((sec_r000617_18_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000617_14_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000617_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000617_14_1 + 7) & 127;
  }
  if ((sec_r000617_2_2 & 1) != 0)
  {
    if ((sec_r000617_18_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000617_14_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000617_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000617_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000617_8_1 & 1) != 0)
  {
    if ((sec_r000617_10_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000617_12_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000617_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000617_12_1 + 7) & 127;
  }
  if ((sec_r000617_8_2 & 1) != 0)
  {
    if ((sec_r000617_10_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000617_12_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000617_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000617_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000617_5_1 & 1) != 0)
  {
    if ((sec_r000617_9_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000617_9_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000617_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000617_9_1 + 7) & 127;
  }
  if ((sec_r000617_5_2 & 1) != 0)
  {
    if ((sec_r000617_9_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000617_9_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000617_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000617_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000617_11_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000617_14_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000617_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000617_14_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000617_11_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000617_14_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000617_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000617_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000617_3_1 & 1) != 0)
  {
    if ((sec_r000617_18_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000617_7_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000617_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000617_7_1 + 7) & 127;
  }
  if ((sec_r000617_3_2 & 1) != 0)
  {
    if ((sec_r000617_18_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000617_7_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000617_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000617_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000617_11_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000617_18_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000617_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000617_18_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000617_11_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000617_18_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000617_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000617_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000617_13_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000617_10_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000617_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000617_10_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000617_13_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000617_10_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000617_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000617_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000617_18_1 & 1) != 0)
  {
    if ((sec_r000617_6_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000617_12_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000617_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000617_12_1 + 7) & 127;
  }
  if ((sec_r000617_18_2 & 1) != 0)
  {
    if ((sec_r000617_6_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000617_12_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000617_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000617_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000617_13_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000617_6_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000617_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000617_6_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000617_13_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000617_6_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000617_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000617_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000617_10_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000617_17_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000617_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000617_17_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000617_10_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000617_17_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000617_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000617_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000617_8_1 & 1) != 0)
  {
    if ((sec_r000617_18_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000617_17_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000617_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000617_17_1 + 7) & 127;
  }
  if ((sec_r000617_8_2 & 1) != 0)
  {
    if ((sec_r000617_18_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000617_17_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000617_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000617_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000617_5_1 & 1) != 0)
  {
    if ((sec_r000617_2_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000617_10_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000617_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000617_10_1 + 7) & 127;
  }
  if ((sec_r000617_5_2 & 1) != 0)
  {
    if ((sec_r000617_2_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000617_10_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000617_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000617_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000617_5_1 & 1) != 0)
  {
    if ((sec_r000617_8_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000617_7_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000617_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000617_7_1 + 7) & 127;
  }
  if ((sec_r000617_5_2 & 1) != 0)
  {
    if ((sec_r000617_8_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000617_7_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000617_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000617_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000617_2_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000617_19_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000617_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000617_19_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000617_2_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000617_19_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000617_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000617_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000617_0_1 & 1) != 0)
  {
    if ((sec_r000617_5_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000617_17_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000617_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000617_17_1 + 7) & 127;
  }
  if ((sec_r000617_0_2 & 1) != 0)
  {
    if ((sec_r000617_5_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000617_17_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000617_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000617_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000617_2_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000617_9_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000617_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000617_9_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000617_2_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000617_9_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000617_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000617_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000617_0_1 & 1) != 0)
  {
    if ((sec_r000617_17_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000617_2_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000617_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000617_2_1 + 7) & 127;
  }
  if ((sec_r000617_0_2 & 1) != 0)
  {
    if ((sec_r000617_17_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000617_2_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000617_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000617_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000617_14_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000617_8_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000617_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000617_8_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000617_14_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000617_8_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000617_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000617_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000617_0_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000617_17_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000617_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000617_17_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000617_0_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000617_17_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000617_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000617_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000617_15_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000617_4_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000617_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000617_4_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000617_15_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000617_4_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000617_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000617_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000617_19_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000617_12_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000617_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000617_12_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000617_19_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000617_12_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000617_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000617_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000617_0_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000617_3_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000617_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000617_3_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000617_0_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000617_3_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000617_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000617_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000617_15_1 & 1) != 0)
  {
    if ((sec_r000617_12_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000617_1_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000617_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000617_1_1 + 7) & 127;
  }
  if ((sec_r000617_15_2 & 1) != 0)
  {
    if ((sec_r000617_12_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000617_1_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000617_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000617_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000617_4_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000617_16_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000617_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000617_16_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000617_4_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000617_16_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000617_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000617_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000617_16_1 & 1) != 0)
  {
    if ((sec_r000617_20_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000617_2_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000617_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000617_2_1 + 7) & 127;
  }
  if ((sec_r000617_16_2 & 1) != 0)
  {
    if ((sec_r000617_20_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000617_2_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000617_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000617_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000617_13_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000617_0_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000617_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000617_0_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000617_13_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000617_0_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000617_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000617_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000617_6_1 & 1) != 0)
  {
    if ((sec_r000617_8_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000617_0_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000617_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000617_0_1 + 7) & 127;
  }
  if ((sec_r000617_6_2 & 1) != 0)
  {
    if ((sec_r000617_8_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000617_0_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000617_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000617_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000617_11_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000617_15_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000617_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000617_15_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000617_11_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000617_15_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000617_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000617_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000617_6_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000617_4_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000617_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000617_4_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000617_6_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000617_4_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000617_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000617_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000617_2_1 & 1) != 0)
  {
    if ((sec_r000617_17_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000617_17_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000617_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000617_17_1 + 7) & 127;
  }
  if ((sec_r000617_2_2 & 1) != 0)
  {
    if ((sec_r000617_17_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000617_17_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000617_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000617_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000617_2_1 & 1) != 0)
  {
    if ((sec_r000617_17_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000617_8_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000617_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000617_8_1 + 7) & 127;
  }
  if ((sec_r000617_2_2 & 1) != 0)
  {
    if ((sec_r000617_17_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000617_8_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000617_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000617_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r000617_18_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000617_17_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000617_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000617_17_1 + 7) & 127;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r000617_18_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000617_17_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000617_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000617_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000617_0_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000617_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000617_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000617_12_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000617_0_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000617_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000617_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000617_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000617_9_1 & 1) != 0)
  {
    if ((sec_r000617_18_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000617_8_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000617_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000617_8_1 + 7) & 127;
  }
  if ((sec_r000617_9_2 & 1) != 0)
  {
    if ((sec_r000617_18_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000617_8_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000617_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000617_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000617_20_1 & 1) != 0)
  {
    if ((sec_r000617_1_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000617_13_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000617_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000617_13_1 + 7) & 127;
  }
  if ((sec_r000617_20_2 & 1) != 0)
  {
    if ((sec_r000617_1_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000617_13_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000617_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000617_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000617_15_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000617_10_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000617_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000617_10_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000617_15_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000617_10_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000617_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000617_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000617_9_1 & 1) != 0)
  {
    if ((sec_r000617_3_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000617_14_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000617_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000617_14_1 + 7) & 127;
  }
  if ((sec_r000617_9_2 & 1) != 0)
  {
    if ((sec_r000617_3_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000617_14_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000617_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000617_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000617_18_1 & 1) != 0)
  {
    if ((sec_r000617_4_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000617_12_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000617_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000617_12_1 + 7) & 127;
  }
  if ((sec_r000617_18_2 & 1) != 0)
  {
    if ((sec_r000617_4_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000617_12_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000617_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000617_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000617_11_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000617_6_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000617_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000617_6_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000617_11_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000617_6_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000617_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000617_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000617_7_1 & 1) != 0)
  {
    if ((sec_r000617_15_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000617_7_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000617_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000617_7_1 + 7) & 127;
  }
  if ((sec_r000617_7_2 & 1) != 0)
  {
    if ((sec_r000617_15_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000617_7_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000617_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000617_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000617_19_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000617_16_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000617_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000617_16_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000617_19_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000617_16_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000617_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000617_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000617_7_1 & 1) != 0)
  {
    if ((sec_r000617_14_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000617_1_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000617_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000617_1_1 + 7) & 127;
  }
  if ((sec_r000617_7_2 & 1) != 0)
  {
    if ((sec_r000617_14_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000617_1_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000617_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000617_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000617_19_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000617_2_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000617_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000617_2_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000617_19_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000617_2_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000617_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000617_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000617_11_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000617_18_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000617_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000617_18_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000617_11_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000617_18_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000617_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000617_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000617_12_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000617_10_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000617_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000617_10_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000617_12_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000617_10_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000617_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000617_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000617_3_1 & 1) != 0)
  {
    if ((sec_r000617_17_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000617_3_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000617_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000617_3_1 + 7) & 127;
  }
  if ((sec_r000617_3_2 & 1) != 0)
  {
    if ((sec_r000617_17_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000617_3_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000617_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000617_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000617_3_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000617_20_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000617_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000617_20_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000617_3_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000617_20_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000617_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000617_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000617_3_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000617_16_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000617_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000617_16_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000617_3_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000617_16_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000617_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000617_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000617_19_1 & 1) != 0)
  {
    if ((sec_r000617_18_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000617_18_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000617_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000617_18_1 + 7) & 127;
  }
  if ((sec_r000617_19_2 & 1) != 0)
  {
    if ((sec_r000617_18_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000617_18_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000617_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000617_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000617_9_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000617_18_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000617_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000617_18_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000617_9_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000617_18_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000617_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000617_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000617_13_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000617_11_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000617_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000617_11_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000617_13_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000617_11_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000617_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000617_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000617_8_1 & 1) != 0)
  {
    if ((sec_r000617_11_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000617_7_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000617_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000617_7_1 + 7) & 127;
  }
  if ((sec_r000617_8_2 & 1) != 0)
  {
    if ((sec_r000617_11_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000617_7_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000617_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000617_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000617_17_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000617_15_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000617_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000617_15_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000617_17_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000617_15_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000617_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000617_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000617_18_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000617_10_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000617_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000617_10_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000617_18_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000617_10_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000617_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000617_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000617_16_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000617_15_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000617_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000617_15_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000617_16_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000617_15_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000617_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000617_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r000617_3_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000617_12_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000617_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000617_12_1 + 7) & 127;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((sec_r000617_3_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000617_12_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000617_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000617_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000617_18_1 != sec_r000617_18_2);
  __CPROVER_assume(pub_r000617_0_1 == pub_r000617_0_2);
  __CPROVER_assume(sec_r000617_14_1 != sec_r000617_14_2);
  __CPROVER_assume(pub_r000617_9_1 == pub_r000617_9_2);
  __CPROVER_assume(pub_r000617_15_1 == pub_r000617_15_2);
  __CPROVER_assume(pub_r000617_1_1 == pub_r000617_1_2);
  __CPROVER_assume(pub_r000617_6_1 == pub_r000617_6_2);
  __CPROVER_assume(pub_r000617_7_1 == pub_r000617_7_2);
  __CPROVER_assume(pub_r000617_14_1 == pub_r000617_14_2);
  __CPROVER_assume(pub_r000617_5_1 == pub_r000617_5_2);
  __CPROVER_assume(sec_r000617_17_1 != sec_r000617_17_2);
  __CPROVER_assume(pub_r000617_4_1 == pub_r000617_4_2);
  __CPROVER_assume(sec_r000617_12_1 != sec_r000617_12_2);
  __CPROVER_assume(pub_r000617_10_1 == pub_r000617_10_2);
  __CPROVER_assume(sec_r000617_2_1 != sec_r000617_2_2);
  __CPROVER_assume(sec_r000617_11_1 != sec_r000617_11_2);
  __CPROVER_assume(pub_r000617_12_1 == pub_r000617_12_2);
  __CPROVER_assume(sec_r000617_19_1 != sec_r000617_19_2);
  __CPROVER_assume(sec_r000617_5_1 != sec_r000617_5_2);
  __CPROVER_assume(pub_r000617_18_1 == pub_r000617_18_2);
  __CPROVER_assume(pub_r000617_19_1 == pub_r000617_19_2);
  __CPROVER_assume(pub_r000617_2_1 == pub_r000617_2_2);
  __CPROVER_assume(sec_r000617_4_1 != sec_r000617_4_2);
  __CPROVER_assume(pub_r000617_3_1 == pub_r000617_3_2);
  __CPROVER_assume(sec_r000617_7_1 != sec_r000617_7_2);
  __CPROVER_assume(sec_r000617_20_1 != sec_r000617_20_2);
  __CPROVER_assume(pub_r000617_8_1 == pub_r000617_8_2);
  __CPROVER_assume(sec_r000617_8_1 != sec_r000617_8_2);
  __CPROVER_assume(pub_r000617_20_1 == pub_r000617_20_2);
  __CPROVER_assume(sec_r000617_0_1 != sec_r000617_0_2);
  __CPROVER_assume(sec_r000617_1_1 != sec_r000617_1_2);
  __CPROVER_assume(sec_r000617_15_1 != sec_r000617_15_2);
  __CPROVER_assume(pub_r000617_16_1 == pub_r000617_16_2);
  __CPROVER_assume(sec_r000617_9_1 != sec_r000617_9_2);
  __CPROVER_assume(sec_r000617_10_1 != sec_r000617_10_2);
  __CPROVER_assume(pub_r000617_13_1 == pub_r000617_13_2);
  __CPROVER_assume(sec_r000617_6_1 != sec_r000617_6_2);
  __CPROVER_assume(sec_r000617_3_1 != sec_r000617_3_2);
  __CPROVER_assume(sec_r000617_16_1 != sec_r000617_16_2);
  __CPROVER_assume(pub_r000617_17_1 == pub_r000617_17_2);
  __CPROVER_assume(pub_r000617_11_1 == pub_r000617_11_2);
  __CPROVER_assume(sec_r000617_13_1 != sec_r000617_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.density == st_var_1_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.gain == st_var_2_2.gain);
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
}


